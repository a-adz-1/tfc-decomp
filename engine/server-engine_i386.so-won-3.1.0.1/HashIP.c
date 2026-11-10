// HashIP__11AuthRequestUlUsPc  @ 0009bd48
void HashIP__11AuthRequestUlUsPc
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  char *__src;
  ushort uVar1;
  short local_8;
  undefined2 local_6;
  
  uVar1 = (ushort)(param_2._1_1_ ^ (byte)param_2) + (ushort)(byte)param_2;
  uVar1 = (param_2._2_1_ ^ uVar1) + uVar1;
  uVar1 = (param_2._3_1_ ^ uVar1) + uVar1;
  uVar1 = ((ushort)param_3 & 0xff ^ uVar1) + uVar1;
  local_6._1_1_ = (byte)((uint)param_3 >> 8);
  local_8 = uVar1 + (local_6._1_1_ ^ uVar1);
  local_6 = (ushort)param_3;
  __src = (char *)HashPrint__11AuthRequestPUci(param_1,&local_8,2);
  strcpy(param_4,__src);
  param_4[4] = '\0';
  return;
}


