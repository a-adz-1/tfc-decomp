// InvokeEngine__FiPce  @ 08089b90
void InvokeEngine__FiPce(undefined4 param_1,char *param_2)

{
  int iVar1;
  char local_404 [1024];
  
  iVar1 = Eng_Load__FPCci("sw_i386.so",param_1);
  if (((iVar1 != 0) && (Eng_SetState__Fi(1), param_2 != (char *)0x0)) && (*param_2 != '\0')) {
    vsprintf(local_404,param_2,&stack0x0000000c);
    strcat(local_404,"\n");
    if (gDLLState != 3) {
      Cbuf_AddText(local_404);
    }
  }
  return;
}


