// get_int64_arg  @ 100a9ec0
/* Library Function - Single Match
    _get_int64_arg
   
   Library: Visual Studio 1998 Release */

undefined8 __cdecl get_int64_arg(int *param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)*param_1;
  *param_1 = (int)(puVar1 + 1);
  return *puVar1;
}


// get_int_arg  @ 100a9eb0
/* Library Function - Single Match
    _get_int_arg
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl get_int_arg(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  *param_1 = (int)(puVar1 + 1);
  return *puVar1;
}


// get_short_arg  @ 100a9ee0
/* Library Function - Single Match
    _get_short_arg
   
   Library: Visual Studio 1998 Release */

undefined2 __cdecl get_short_arg(undefined4 *param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)*param_1;
  *param_1 = puVar1 + 2;
  return *puVar1;
}


