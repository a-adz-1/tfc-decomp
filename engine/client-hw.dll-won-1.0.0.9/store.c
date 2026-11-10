// store_dt  @ 100a52e0
/* Library Function - Single Match
    _store_dt
   
   Library: Visual Studio 1998 Release */

char * __cdecl store_dt(char *param_1,int param_2)

{
  *param_1 = (char)(param_2 / 10) + '0';
  param_1[1] = (char)(param_2 % 10) + '0';
  return param_1 + 2;
}


