// Split__FPcT0Pii  @ 080897e0
void Split__FPcT0Pii(char *param_1,char *param_2,undefined4 *param_3,undefined4 param_4)

{
  char *pcVar1;
  
  pcVar1 = strstr(param_1,":");
  if (pcVar1 == (char *)0x0) {
    strcpy(param_2,param_1);
  }
  else {
    strncpy(param_2,param_1,(int)pcVar1 - (int)param_1);
    param_2[(int)pcVar1 - (int)param_1] = '\0';
    param_4 = __strtol_internal(pcVar1 + 1,0,10,0);
  }
  *param_3 = param_4;
  return;
}


