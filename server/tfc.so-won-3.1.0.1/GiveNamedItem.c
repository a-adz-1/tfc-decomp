// GiveNamedItem__11CBasePlayerPc  @ 000d014c
void GiveNamedItem__11CBasePlayerPc(int *param_1,undefined4 param_2)

{
  int iVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = (*DAT_001a7f4c)(param_2);
  iVar4 = (*DAT_001a7e9c)(uVar3);
  bVar2 = false;
  if (iVar4 != 0) {
    iVar5 = (*DAT_001a7f58)(iVar4);
    if (iVar5 != 0) goto LAB_000d01a7;
  }
  bVar2 = true;
LAB_000d01a7:
  if (bVar2) {
    (*DAT_001a7f34)(1,"NULL Ent in GiveNamedItem!\n");
  }
  else {
    iVar5 = iVar4 + 0x80;
    if (iVar4 == 0) {
      iVar5 = 0;
    }
    iVar1 = *param_1;
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
    *(byte *)(iVar4 + 0x223) = *(byte *)(iVar4 + 0x223) | 0x40;
    DispatchSpawn__FP7edict_s(iVar4);
    DispatchTouch__FP7edict_sT0(iVar4,*(undefined4 *)(*param_1 + 0x208));
  }
  return;
}


