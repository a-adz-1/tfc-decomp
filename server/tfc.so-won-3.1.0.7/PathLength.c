// PathLength__6CGraphiiii  @ 000c3f7c
longdouble
PathLength__6CGraphiiii(int param_1,int param_2,int param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  float local_8;
  int local_4;
  
  local_8 = 0.0;
  iVar1 = *(int *)(param_1 + 0x18);
  while( true ) {
    if (param_2 == param_3) {
      return (longdouble)local_8;
    }
    if (iVar1 < 1) {
      (*DAT_001c1114)(1,"Route Failure\n");
      return (longdouble)0.0;
    }
    iVar2 = NextNodeInRoute__6CGraphiiii(param_1,param_2,param_3,param_4,(param_5 & 0x340) != 0);
    if (param_2 == iVar2) {
      return (longdouble)0.0;
    }
    HashSearch__6CGraphiiRi(param_1,param_2,iVar2,&local_4);
    if (local_4 < 0) break;
    local_8 = local_8 + *(float *)(*(int *)(param_1 + 0x10) + 0x14 + local_4 * 0x18);
    iVar1 = iVar1 + -1;
    param_2 = iVar2;
  }
  (*DAT_001c1114)(1,FUN_001490c0,param_2,param_3);
  return (longdouble)0.0;
}


