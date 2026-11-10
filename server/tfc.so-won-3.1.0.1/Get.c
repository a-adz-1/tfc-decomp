// Get__7EHANDLE  @ 0008667c
int Get__7EHANDLE(int *param_1)

{
  int iVar1;
  
  if ((*param_1 == 0) || (iVar1 = *param_1, *(int *)(iVar1 + 4) != param_1[1])) {
    iVar1 = 0;
  }
  return iVar1;
}


