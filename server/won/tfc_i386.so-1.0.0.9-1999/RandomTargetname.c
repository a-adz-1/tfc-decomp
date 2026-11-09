// RandomTargetname__5CBeamPCc  @ 000abcc0
int RandomTargetname__5CBeamPCc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = 0;
  iVar4 = 0;
  iVar5 = 0;
  while( true ) {
    iVar2 = UTIL_FindEntityByTargetname__FP11CBaseEntityPCc(iVar2,param_2);
    if (iVar2 == 0) break;
    iVar3 = iVar4 + 1;
    iVar1 = (*DAT_00175628)(0,iVar4);
    iVar4 = iVar3;
    if (iVar1 < 1) {
      iVar5 = iVar2;
    }
  }
  return iVar5;
}


