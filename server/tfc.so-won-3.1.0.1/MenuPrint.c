// MenuPrint__FP11CBasePlayerPCcii  @ 000ac864
void MenuPrint__FP11CBasePlayerPCcii(int *param_1,char *param_2,int param_3,undefined4 param_4)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char acStack_34 [50];
  undefined1 uStack_2;
  
  fVar1 = (float)param_1[0x2ea];
  fVar2 = *gpGlobals;
  if (((0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) &&
      (param_3 == param_1[0x2e9])) &&
     (iVar4 = strcmp(param_2,(char *)(param_1 + 0x269)), iVar4 == 0)) {
    return;
  }
  param_1[0x2ea] = (int)(*gpGlobals + 10.0);
  strncpy((char *)(param_1 + 0x269),param_2,0x200);
  param_1[0x2e9] = param_3;
  uVar5 = 0xffffffff;
  pcVar6 = param_2;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar3 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar3 != '\0');
  if (0x31 < ~uVar5 - 1) {
    do {
      strncpy(acStack_34,param_2,0x32);
      uStack_2 = 0;
      param_2 = param_2 + 0x32;
      (*DAT_001a7ef8)(1,gmsgShowMenu,0,*(undefined4 *)(*param_1 + 0x208));
      (*DAT_001a7f08)(param_3);
      (*DAT_001a7f04)(param_4);
      (*DAT_001a7f00)(1);
      (*DAT_001a7f18)(acStack_34);
      (*DAT_001a7efc)();
      uVar5 = 0xffffffff;
      pcVar6 = param_2;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar3 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar3 != '\0');
    } while (0x31 < ~uVar5 - 1);
  }
  (*DAT_001a7ef8)(1,gmsgShowMenu,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001a7f08)(param_3);
  (*DAT_001a7f04)(param_4);
  (*DAT_001a7f00)(0);
  (*DAT_001a7f18)(param_2);
  (*DAT_001a7efc)();
  return;
}


