// Error_Printf__11AuthRequestiPce  @ 000d12b4
void Error_Printf__11AuthRequestiPce(int param_1,uint param_2,char *param_3)

{
  *(uint *)(param_1 + 0x8200) = *(uint *)(param_1 + 0x8200) | param_2;
  vsprintf(string_540,param_3,&stack0x00000010);
  strcpy((char *)(param_1 + 0x8204),string_540);
  return;
}


