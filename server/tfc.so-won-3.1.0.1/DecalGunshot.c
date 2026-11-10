// DecalGunshot__FP11TraceResulti  @ 0010f3b8
void DecalGunshot__FP11TraceResulti(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = UTIL_IsValidEntity__FP7edict_s(*(undefined4 *)(param_1 + 0x30));
  if (iVar2 != 0) {
    iVar2 = *(int *)(param_1 + 0x30) + 0x80;
    if (*(int *)(param_1 + 0x30) == 0) {
      iVar2 = 0;
    }
    if (*(int *)(iVar2 + 0x10c) != 4) {
      iVar2 = *(int *)(param_1 + 0x30) + 0x80;
      if (*(int *)(param_1 + 0x30) == 0) {
        iVar2 = 0;
      }
      if (*(int *)(iVar2 + 0x108) != 0xd) {
        return;
      }
    }
    uVar3 = 0;
    bVar1 = false;
    if ((*(int *)(param_1 + 0x30) == 0) ||
       (iVar2 = (*DAT_001a7f58)(*(int *)(param_1 + 0x30)), iVar2 == 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      iVar2 = *(int *)(param_1 + 0x30);
      if ((iVar2 == 0) && (iVar2 = (*DAT_001a7f54)(0), iVar2 == 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined4 *)(iVar2 + 0x7c);
      }
    }
    switch(param_2) {
    default:
      uVar3 = DamageDecal__FP11CBaseEntityi(uVar3,2);
      UTIL_GunshotDecalTrace__FP11TraceResulti(param_1,uVar3);
      break;
    case 5:
      uVar3 = DamageDecal__FP11CBaseEntityi(uVar3,0x80);
      UTIL_DecalTrace__FP11TraceResulti(param_1,uVar3);
      break;
    case 7:
      UTIL_GunshotDecalTrace__FP11TraceResulti(param_1,0x2a);
      break;
    case 10:
      uVar3 = DamageDecal__FP11CBaseEntityi(uVar3,2);
      UTIL_GunshotDecalTrace__FP11TraceResulti(param_1,uVar3);
    }
  }
  return;
}


