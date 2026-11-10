// Error_Printf__11AuthRequestiPce  @ 08090e70
void Error_Printf__11AuthRequestiPce(int param_1,uint param_2,char *param_3)

{
  *(uint *)(param_1 + 0x809c) = *(uint *)(param_1 + 0x809c) | param_2;
  vsprintf(string_450,param_3,&stack0x00000010);
  strcpy((char *)(param_1 + 0x80a0),string_450);
  return;
}


