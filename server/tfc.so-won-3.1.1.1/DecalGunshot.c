// DecalGunshot__FP11TraceResulti  @ 00123408
void DecalGunshot__FP11TraceResulti(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  undefined4 uVar5;
  
  iVar2 = UTIL_IsValidEntity__FP7edict_s(*(undefined4 *)(param_1 + 0x30));
  if (iVar2 != 0) {
    iVar3 = *(int *)(param_1 + 0x30);
    iVar2 = iVar3 + 0x80;
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    if (*(int *)(iVar2 + 0x10c) != 4) {
      iVar2 = iVar3 + 0x80;
      if (iVar3 == 0) {
        iVar2 = 0;
      }
      if (*(int *)(iVar2 + 0x108) != 0xd) {
        return;
      }
    }
    iVar2 = 0;
    bVar1 = false;
    if ((iVar3 == 0) || (iVar3 = (*DAT_0019f7b8)(iVar3), iVar3 == 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      iVar2 = *(int *)(param_1 + 0x30);
      if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(iVar2 + 0x7c);
      }
    }
    switch(param_2) {
    default:
      if (iVar2 == 0) {
        uVar5 = 4;
        iVar2 = 0;
        pcVar4 = DAT_0019f808;
      }
      else {
        uVar5 = 2;
        pcVar4 = *(code **)(*(int *)(iVar2 + 0x454) + 0x74);
      }
      (*pcVar4)(iVar2,uVar5);
      FUN_0012355a();
      return;
    case 5:
      if (iVar2 == 0) {
        uVar5 = 4;
        iVar2 = 0;
        pcVar4 = DAT_0019f808;
      }
      else {
        uVar5 = 0x80;
        pcVar4 = *(code **)(*(int *)(iVar2 + 0x454) + 0x74);
      }
      uVar5 = (*pcVar4)(iVar2,uVar5);
      UTIL_DecalTrace__FP11TraceResulti(param_1,uVar5);
      break;
    case 7:
      UTIL_GunshotDecalTrace__FP11TraceResulti(param_1,0x2a);
      break;
    case 10:
      if (iVar2 == 0) {
        uVar5 = 4;
        iVar2 = 0;
        pcVar4 = DAT_0019f808;
      }
      else {
        uVar5 = 2;
        pcVar4 = *(code **)(*(int *)(iVar2 + 0x454) + 0x74);
      }
      (*pcVar4)(iVar2,uVar5);
      FUN_0012355a();
      return;
    }
  }
  return;
}


