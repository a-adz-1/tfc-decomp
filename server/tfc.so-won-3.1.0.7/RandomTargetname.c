// RandomTargetname__5CBeamPCc  @ 000a0760
int RandomTargetname__5CBeamPCc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  iVar2 = 0;
  iVar5 = 0;
  while( true ) {
    iVar3 = UTIL_FindEntityByTargetname__FP11CBaseEntityPCc(iVar3,param_2);
    if (iVar3 == 0) break;
    iVar4 = iVar5 + 1;
    iVar1 = (*DAT_001c1188)(0,iVar5);
    iVar5 = iVar4;
    if (iVar1 < 1) {
      iVar2 = iVar3;
    }
  }
  return iVar2;
}


