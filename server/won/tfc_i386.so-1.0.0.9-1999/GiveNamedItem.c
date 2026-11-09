// GiveNamedItem__11CBasePlayerPc  @ 000dd680
void GiveNamedItem__11CBasePlayerPc(int *param_1,undefined4 param_2)

{
  int iVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = (*DAT_001755cc)(param_2);
  iVar4 = (*DAT_0017551c)(uVar3);
  bVar2 = false;
  if (iVar4 != 0) {
    iVar5 = (*DAT_001755d8)(iVar4);
    if (iVar5 != 0) goto LAB_000dd6bb;
  }
  bVar2 = true;
LAB_000dd6bb:
  if (bVar2) {
    (*DAT_001755b4)(1,"NULL Ent in GiveNamedItem!\n");
  }
  else {
    if (iVar4 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = iVar4 + 0xdc;
    }
    iVar1 = *param_1;
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
    *(byte *)(iVar4 + 0x25f) = *(byte *)(iVar4 + 0x25f) | 0x40;
    DispatchSpawn__FP7edict_s(iVar4);
    DispatchTouch__FP7edict_sT0(iVar4,*(undefined4 *)(*param_1 + 0x1e8));
  }
  return;
}


