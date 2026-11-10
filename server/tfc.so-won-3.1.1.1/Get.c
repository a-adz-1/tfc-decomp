// Get__7EHANDLE  @ 0008ed84
int Get__7EHANDLE(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((iVar1 == 0) || (*(int *)(iVar1 + 4) != param_1[1])) {
    iVar1 = 0;
  }
  return iVar1;
}


