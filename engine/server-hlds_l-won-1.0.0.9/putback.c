// putback__7istreamc  @ 0809ced4
int * putback__7istreamc(int *param_1,char param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    iVar1 = sputbackc__9streambufc(*(undefined4 *)*param_1,(int)param_2);
    if (iVar1 == -1) {
      iVar1 = 0;
      if (param_1 != (int *)0x0) {
        iVar1 = *param_1;
      }
      *(undefined1 *)(iVar1 + 0x12) = 4;
    }
  }
  return param_1;
}


