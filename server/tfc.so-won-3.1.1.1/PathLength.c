// PathLength__6CGraphiiii  @ 000cb7ac
longdouble
PathLength__6CGraphiiii(int param_1,int param_2,int param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  float local_c;
  int local_8;
  
  local_c = 0.0;
  iVar1 = *(int *)(param_1 + 0x18);
  while( true ) {
    if (param_2 == param_3) {
      return (longdouble)local_c;
    }
    if (iVar1 < 1) {
      (*DAT_0019f794)(1,"Route Failure\n");
      return (longdouble)0;
    }
    iVar2 = NextNodeInRoute__6CGraphiiii(param_1,param_2,param_3,param_4,(param_5 & 0x340) != 0);
    if (param_2 == iVar2) {
      return (longdouble)0;
    }
    HashSearch__6CGraphiiRi(param_1,param_2,iVar2,&local_8);
    if (local_8 < 0) break;
    local_c = local_c + *(float *)(*(int *)(param_1 + 0x10) + 0x14 + local_8 * 0x18);
    iVar1 = iVar1 + -1;
    param_2 = iVar2;
  }
  (*DAT_0019f794)(1,"HashLinks is broken from %d to %d.\n",param_2,param_3);
  return (longdouble)0;
}


