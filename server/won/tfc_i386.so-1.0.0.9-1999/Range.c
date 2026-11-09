// Range__12CTFSentrygunP11CBaseEntity  @ 000e99c0
undefined4 Range__12CTFSentrygunP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  
  iVar1 = *param_1;
  iVar2 = *param_2;
  fVar3 = (*(float *)(iVar2 + 8) + *(float *)(iVar2 + 0x154)) -
          (*(float *)(iVar1 + 8) + *(float *)(iVar1 + 0x154));
  fVar5 = (*(float *)(iVar2 + 0xc) + *(float *)(iVar2 + 0x158)) -
          (*(float *)(iVar1 + 0xc) + *(float *)(iVar1 + 0x158));
  fVar4 = (*(float *)(iVar2 + 0x10) + *(float *)(iVar2 + 0x15c)) -
          (*(float *)(iVar1 + 0x10) + *(float *)(iVar1 + 0x15c));
  iVar1 = (int)ROUND(SQRT(fVar4 * fVar4 + fVar5 * fVar5 + fVar3 * fVar3));
  if (iVar1 < 0x78) {
    uVar6 = 0;
  }
  else if (iVar1 < 500) {
    uVar6 = 1;
  }
  else if (iVar1 < 1000) {
    uVar6 = 2;
  }
  else {
    uVar6 = 3;
  }
  return uVar6;
}


