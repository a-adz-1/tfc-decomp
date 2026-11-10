// Errorf__13SystemWrapperPce  @ 00097dc0
void Errorf__13SystemWrapperPce(int *param_1,char *param_2)

{
  vsnprintf(string_189,0x400,param_2,&stack0x0000000c);
  (**(code **)(*param_1 + 0x4c))(param_1,"***** FATAL ERROR *****\n");
  (**(code **)(*param_1 + 0x4c))(param_1,&DAT_000e7ab1,string_189);
  (**(code **)(*param_1 + 0x4c))(param_1,"*** STOPPING SYSTEM ***\n");
  Stop__13SystemWrapper(param_1);
  return;
}


