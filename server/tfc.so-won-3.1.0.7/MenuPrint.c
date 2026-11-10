// MenuPrint__FP11CBasePlayerPCcii  @ 000b79c4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MenuPrint__FP11CBasePlayerPCcii(int *param_1,char *param_2,int param_3,undefined4 param_4)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char local_34 [50];
  undefined1 local_2;
  
  fVar1 = (float)param_1[0x307];
  fVar2 = *gpGlobals;
  if (((0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) &&
      (param_3 == param_1[0x306])) &&
     (iVar4 = strcmp(param_2,(char *)(param_1 + 0x286)), iVar4 == 0)) {
    return;
  }
  param_1[0x307] = (int)(_FUN_00147810 + *gpGlobals);
  strncpy((char *)(param_1 + 0x286),param_2,0x200);
  param_1[0x306] = param_3;
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
      strncpy(local_34,param_2,0x32);
      local_2 = 0;
      param_2 = param_2 + 0x32;
      (*DAT_001c10d8)(1,gmsgShowMenu,0,*(undefined4 *)(*param_1 + 0x208));
      (*DAT_001c10e8)(param_3);
      (*DAT_001c10e4)(param_4);
      (*DAT_001c10e0)(1);
      (*DAT_001c10f8)(local_34);
      (*DAT_001c10dc)();
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
  (*DAT_001c10d8)(1,gmsgShowMenu,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001c10e8)(param_3);
  (*DAT_001c10e4)(param_4);
  (*DAT_001c10e0)(0);
  (*DAT_001c10f8)(param_2);
  (*DAT_001c10dc)();
  return;
}


