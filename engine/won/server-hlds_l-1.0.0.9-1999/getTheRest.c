// getTheRest__10ReadBufferPUl  @ 08090810
int getTheRest__10ReadBufferPUl(int *param_1,int *param_2)

{
  int iVar1;
  
  *param_2 = param_1[2] - param_1[1];
  iVar1 = param_1[1];
  param_1[1] = param_1[2];
  return *param_1 + iVar1;
}


