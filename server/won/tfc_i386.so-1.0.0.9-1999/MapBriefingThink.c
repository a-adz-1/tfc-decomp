// MapBriefingThink__11CBasePlayer  @ 000e3c40
void MapBriefingThink__11CBasePlayer(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (param_1[0x262] != 0) {
    if ((param_1[0x18d] & 0x803U) != 0) {
      param_1[0x18d] = param_1[0x18d] & 0xfffff7fc;
      EndMapBriefing__11CBasePlayer(param_1);
      return;
    }
    if (param_1[0x262] != 0) {
      return;
    }
  }
  param_1[0x262] = 1;
  bVar1 = true;
  uVar2 = (*DAT_00175668)(*(undefined4 *)(*param_1 + 0x1e8));
  pcVar3 = (char *)(*DAT_0017566c)(uVar2,&DAT_0013ac6c);
  if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
    iVar4 = 2;
    bVar7 = true;
    pcVar5 = pcVar3;
    pcVar6 = "0";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar7 = *pcVar5 == *pcVar6;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (!bVar7) {
      iVar4 = 4;
      bVar7 = true;
      pcVar5 = "off";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar7 = *pcVar3 == *pcVar5;
        pcVar3 = pcVar3 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar7);
      if (!bVar7) goto LAB_000e3cf4;
    }
    bVar1 = false;
  }
LAB_000e3cf4:
  if (bVar1) {
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    UTIL_ScreenFade__FP7edict_sRC6Vectorffii
              (*(undefined4 *)(*param_1 + 0x1e8),&local_10,0x3f000000,0x417e6666,0xff,7);
    *(byte *)(param_1 + 0x202) = *(byte *)(param_1 + 0x202) | 9;
    param_1[0x45] = 0x40800000;
  }
  return;
}


