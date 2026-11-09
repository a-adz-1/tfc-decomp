cmake_minimum_required(VERSION 3.20)
project(tfc-decomp C CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# GoldSrc game libraries are 32-bit x86, built with x87 maths like the originals.
set(ARCH_FLAGS -m32 -march=pentium-m -mfpmath=387 -mno-sse)

# Flags from ref/halflife/linux/Makefile (BASE_CFLAGS), minus Valve build-farm bits.
set(BASE_DEFINES
	NDEBUG POSIX _POSIX LINUX _LINUX GNUC HL1 QUIVER QUAKE2 VALVE_DLL
	NO_MALLOC_OVERRIDE CLIENT_WEAPONS
	stricmp=strcasecmp _strnicmp=strncasecmp strnicmp=strncasecmp
	_snprintf=snprintf _vsnprintf=vsnprintf _alloca=alloca
	__m128i=uint64_t __m128d=uint64_t __m128=uint64_t)
set(BASE_OPTIONS -fno-strict-aliasing -Werror=return-type -w -g
	$<$<COMPILE_LANGUAGE:CXX>:-fpermissive>
	$<$<COMPILE_LANGUAGE:C>:-std=gnu89>)

# Server: the 91 compile units recorded in tfc.so's DWARF info.
file(STRINGS ${CMAKE_SOURCE_DIR}/../tools/tfc-sources.txt TFC_UNITS)
set(TFC_SOURCES)
set(TFC_MISSING)
foreach(unit ${TFC_UNITS})
	string(REGEX REPLACE "^\\.\\./" "" rel ${unit})
	if(EXISTS ${CMAKE_SOURCE_DIR}/${rel})
		list(APPEND TFC_SOURCES ${rel})
	else()
		list(APPEND TFC_MISSING ${rel})
	endif()
endforeach()
list(LENGTH TFC_SOURCES n_have)
list(LENGTH TFC_MISSING n_missing)
message(STATUS "tfc.so: ${n_have} units present, ${n_missing} not yet reconstructed")

add_library(tfc SHARED ${TFC_SOURCES})
set_target_properties(tfc PROPERTIES PREFIX "" OUTPUT_NAME tfc)
target_compile_definitions(tfc PRIVATE ${BASE_DEFINES})
target_compile_options(tfc PRIVATE ${ARCH_FLAGS} ${BASE_OPTIONS})
target_include_directories(tfc PRIVATE
	tfc engine common pm_shared game_shared public)
target_link_options(tfc PRIVATE ${ARCH_FLAGS} -Wl,--no-undefined)
target_link_libraries(tfc PRIVATE m dl)

# Layout checks: static_asserts generated from the original binary's DWARF
# (tools/gen_layout_checks.py). Not linked into tfc.so.
add_library(tfc_layout_checks OBJECT tfc/layout_checks.cpp)
target_compile_definitions(tfc_layout_checks PRIVATE ${BASE_DEFINES})
target_compile_options(tfc_layout_checks PRIVATE ${ARCH_FLAGS} ${BASE_OPTIONS} -fmax-errors=0)
target_include_directories(tfc_layout_checks PRIVATE
	tfc engine common pm_shared game_shared public)

# Layout checks for classes defined inside .cpp files (tools/gen_unit_checks.py
# writes one wrapper per unit into build/unit_checks/).
file(GLOB_RECURSE UNIT_CHECKS CONFIGURE_DEPENDS ${CMAKE_BINARY_DIR}/unit_checks/*.cpp)
if(UNIT_CHECKS)
	add_library(tfc_unit_checks OBJECT ${UNIT_CHECKS})
	target_compile_definitions(tfc_unit_checks PRIVATE ${BASE_DEFINES})
	target_compile_options(tfc_unit_checks PRIVATE ${ARCH_FLAGS} ${BASE_OPTIONS} -fmax-errors=0)
	target_include_directories(tfc_unit_checks PRIVATE
		tfc engine common pm_shared game_shared public)
endif()

# Client: the 83 compile units recorded in the 25th Anniversary client.so's
# DWARF info. Flags from ref/halflife/linux/Makefile.hl_cdll plus _TFC; the
# original was GCC 5.4 -std=gnu++11 -fvisibility=hidden. vgui.so and SDL2 come
# from the SDK (ref/halflife/linux), resolved at run time by the engine.
file(STRINGS ${CMAKE_SOURCE_DIR}/../tools/client-sources.txt CLIENT_UNITS)
set(CLIENT_SOURCES)
set(CLIENT_MISSING)
foreach(unit ${CLIENT_UNITS})
	string(REGEX REPLACE "^\\.\\./" "" rel ${unit})
	if(EXISTS ${CMAKE_SOURCE_DIR}/${rel})
		list(APPEND CLIENT_SOURCES ${rel})
	else()
		list(APPEND CLIENT_MISSING ${rel})
	endif()
endforeach()
list(LENGTH CLIENT_SOURCES n_have)
list(LENGTH CLIENT_MISSING n_missing)
message(STATUS "client.so: ${n_have} units present, ${n_missing} not yet reconstructed")

set(CLIENT_DEFINES ${BASE_DEFINES} CLIENT_DLL _TFC DISABLE_JUMP_ORIGIN DISABLE_VEC_ORIGIN
	_snwprintf=swprintf)
set(CLIENT_INCLUDES cl_dll tfc common public pm_shared engine vgui_include game_shared external)

add_library(client SHARED ${CLIENT_SOURCES})
set_target_properties(client PROPERTIES PREFIX "" OUTPUT_NAME client)
target_compile_definitions(client PRIVATE ${CLIENT_DEFINES})
target_compile_options(client PRIVATE ${ARCH_FLAGS} ${BASE_OPTIONS}
	$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11> -fvisibility=hidden)
target_include_directories(client PRIVATE ${CLIENT_INCLUDES})
target_link_options(client PRIVATE ${ARCH_FLAGS})
target_link_directories(client PRIVATE ${CMAKE_SOURCE_DIR}/../ref/halflife/linux/release)
target_link_libraries(client PRIVATE -l:vgui.so
	${CMAKE_SOURCE_DIR}/../ref/halflife/linux/libSDL2-2.0.so.0 dl pthread)
