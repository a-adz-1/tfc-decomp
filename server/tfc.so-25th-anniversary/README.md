# tfc.so, 25th Anniversary (server)

The TFC server game library shipped by Steam since the Half-Life 25th Anniversary Update (November 2023). This is the build with the push-field bug (`trigger_push` divided by frame time) and the `func_pushable` fudge.

- **Binary:** `tfc.so`
- **Version:** 25th Anniversary update, current Steam default (`tfc_25th.so` in the depot)
- **Built by Valve with:** GCC 5.4.1, Steam Runtime scout, -O3 -march=pentium-m -mfpmath=387 -fvisibility=hidden
- **MD5 of the original:** `f7a9b8b0921ee2baa9666d9ab29f6e07`
- **Contents:** Ghidra decompile, one file per source file where the symbols allowed it (the binaries keep function symbols).

The original binary is not included.
