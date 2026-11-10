// UpdateLowPriorityClientData__11CBasePlayer  @ 000dc020
void UpdateLowPriorityClientData__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  int iVar10;
  int iStack_14;
  
  if (gDisplayTitle != 0) {
    (*DAT_0019f758)(1,gmsgShowGameTitle,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_0019f760)(0);
    (*DAT_0019f75c)();
    gDisplayTitle = 0;
  }
  if (param_1[0x288] != param_1[0x289]) {
    (*DAT_0019f758)(1,gmsgConcuss,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_0019f760)(param_1[0x288]);
    (*DAT_0019f75c)();
    param_1[0x289] = param_1[0x288];
  }
  fVar2 = (float)param_1[0x22c];
  fVar1 = *(float *)(*param_1 + 0x1bc);
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 0x40) {
    param_1[0x22c] = (int)ROUND(fVar1);
    (*DAT_0019f758)(1,gmsgBattery,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_0019f768)((int)ROUND(*(float *)(*param_1 + 0x1bc)));
    (*DAT_0019f75c)();
  }
  fVar2 = (float)param_1[0x11];
  fVar1 = (float)param_1[0x2a];
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 0x40) {
    param_1[0x2a] = (int)fVar2;
    (*DAT_0019f758)(1,gmsgGrenades,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_0019f760)(0);
    (*DAT_0019f760)(param_1[0x11]);
    (*DAT_0019f75c)();
  }
  fVar2 = (float)param_1[0x12];
  fVar1 = (float)param_1[0x2b];
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 0x40) {
    param_1[0x2b] = (int)fVar2;
    (*DAT_0019f758)(1,gmsgGrenades,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_0019f760)(1);
    (*DAT_0019f760)(param_1[0x12]);
    (*DAT_0019f75c)();
  }
  iVar10 = *param_1;
  if (((((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar10 + 0x164)) ||
                                        NAN((float)param_1[0x281])) << 10) >> 8) |
               (byte)((ushort)((ushort)(*(float *)(iVar10 + 0x164) == (float)param_1[0x281]) << 0xe)
                     >> 8)) != 0x40) || (param_1[0x280] != param_1[0x27f])) ||
      (param_1[0x282] != *(int *)(iVar10 + 0x20c))) || (param_1[0x283] != *(int *)(iVar10 + 0x1ac)))
  {
    (*DAT_0019f758)(2,gmsgScoreInfo,0,0);
    uVar3 = (*DAT_0019f7bc)(*(undefined4 *)(*param_1 + 0x208));
    (*DAT_0019f760)(uVar3);
    (*DAT_0019f768)((int)ROUND(*(float *)(*param_1 + 0x164)));
    (*DAT_0019f768)(param_1[0x27f]);
    (*DAT_0019f768)(*(undefined4 *)(*param_1 + 0x20c));
    (*DAT_0019f768)(*(undefined4 *)(*param_1 + 0x1ac));
    (*DAT_0019f75c)();
    iVar10 = *param_1;
    param_1[0x282] = *(int *)(iVar10 + 0x20c);
    param_1[0x283] = *(int *)(iVar10 + 0x1ac);
    param_1[0x280] = param_1[0x27f];
    param_1[0x281] = (int)ROUND(*(float *)(iVar10 + 0x164));
  }
  if ((*(byte *)(param_1 + 0x221) & 0xc0) != 0) {
    (*DAT_0019f758)(1,gmsgTrain,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_0019f760)(param_1[0x221] & 0xf);
    (*DAT_0019f75c)();
    *(byte *)(param_1 + 0x221) = *(byte *)(param_1 + 0x221) & 0x3f;
  }
  fVar1 = (float)param_1[0x6c];
  fVar2 = (float)param_1[0x68];
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    (*DAT_0019f758)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
    fVar1 = (float)param_1[0x68];
    (*DAT_0019f760)((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1);
    (*DAT_0019f778)("dmg_caltrop");
    (*DAT_0019f760)(0xff);
    (*DAT_0019f760)(0xa0);
    (*DAT_0019f760)(0);
    (*DAT_0019f75c)();
    param_1[0x6c] = param_1[0x68];
  }
  uVar6 = param_1[0x21];
  uVar5 = uVar6 >> 0xf & 1;
  fVar1 = (float)param_1[0x6e];
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    if (uVar5 != 0) goto LAB_000dc5b8;
  }
  else if (uVar5 != 1) {
LAB_000dc5b8:
    (*DAT_0019f758)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_0019f760)((uint)param_1[0x21] >> 0xf & 1);
    (*DAT_0019f778)("dmg_tranq");
    (*DAT_0019f760)(0xff);
    (*DAT_0019f760)(0xa0);
    (*DAT_0019f760)(0);
    (*DAT_0019f75c)();
    iVar10 = 0;
    if ((short)param_1[0x21] < 0) {
      iVar10 = 0x3f800000;
    }
    param_1[0x6e] = iVar10;
    uVar6 = param_1[0x21];
  }
  uVar6 = uVar6 >> 0xe & 1;
  fVar1 = (float)param_1[0x6d];
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    if (uVar6 == 0) goto LAB_000dc76f;
  }
  else if (uVar6 == 1) goto LAB_000dc76f;
  (*DAT_0019f758)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_0019f760)((uint)param_1[0x21] >> 0xe & 1);
  (*DAT_0019f778)("dmg_haluc");
  (*DAT_0019f760)(0xff);
  (*DAT_0019f760)(0xa0);
  (*DAT_0019f760)(0);
  (*DAT_0019f75c)();
  iVar10 = 0;
  if ((*(byte *)((int)param_1 + 0x85) & 0x40) != 0) {
    iVar10 = 0x3f800000;
  }
  param_1[0x6d] = iVar10;
LAB_000dc76f:
  uVar6 = param_1[0x22];
  uVar5 = param_1[0x284];
  if (uVar6 != uVar5) {
    uVar8 = (uVar5 ^ uVar6) & uVar6;
    uVar5 = uVar5 & (uVar5 ^ uVar6);
    param_1[0x284] = uVar6;
    if ((uVar8 & 0x20000) == 0) {
      if ((uVar5 & 0x20000) != 0) {
        (*DAT_0019f758)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
        (*DAT_0019f760)(0);
        (*DAT_0019f778)("flag_blue");
        (*DAT_0019f75c)();
      }
    }
    else {
      (*DAT_0019f758)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
      (*DAT_0019f760)(1);
      (*DAT_0019f778)("flag_blue");
      (*DAT_0019f760)(0);
      (*DAT_0019f760)(0);
      (*DAT_0019f760)(0xff);
      (*DAT_0019f75c)();
    }
    if ((uVar8 & 0x40000) == 0) {
      if ((uVar5 & 0x40000) != 0) {
        (*DAT_0019f758)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
        (*DAT_0019f760)(0);
        (*DAT_0019f778)("flag_red");
        (*DAT_0019f75c)();
      }
    }
    else {
      (*DAT_0019f758)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
      (*DAT_0019f760)(1);
      (*DAT_0019f778)("flag_red");
      (*DAT_0019f760)(0xff);
      (*DAT_0019f760)(0);
      (*DAT_0019f760)(0);
      (*DAT_0019f75c)();
    }
    if ((uVar8 & 0x1000000) == 0) {
      if ((uVar5 & 0x1000000) != 0) {
        (*DAT_0019f758)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
        (*DAT_0019f760)(0);
        (*DAT_0019f778)("flag_yellow");
        (*DAT_0019f75c)();
      }
    }
    else {
      (*DAT_0019f758)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
      (*DAT_0019f760)(1);
      (*DAT_0019f778)("flag_yellow");
      (*DAT_0019f760)(0xff);
      (*DAT_0019f760)(0xa0);
      (*DAT_0019f760)(0);
      (*DAT_0019f75c)();
    }
    if ((uVar8 & 0x2000000) == 0) {
      if ((uVar5 & 0x2000000) != 0) {
        (*DAT_0019f758)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
        (*DAT_0019f760)(0);
        (*DAT_0019f778)("flag_green");
        (*DAT_0019f75c)();
      }
    }
    else {
      (*DAT_0019f758)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
      (*DAT_0019f760)(1);
      (*DAT_0019f778)("flag_green");
      (*DAT_0019f760)(0);
      (*DAT_0019f760)(0xff);
      (*DAT_0019f760)(0);
      (*DAT_0019f75c)();
    }
  }
  if (param_1[0x1c1] == 0) {
    param_1[0x1c1] = 1;
    iStack_14 = 0;
    do {
      iVar10 = iStack_14 * 0x2c;
      if (*(int *)(_15CBasePlayerItem_ItemInfoArray + iVar10 + 0x20) != 0) {
        pcVar9 = *(char **)(_15CBasePlayerItem_ItemInfoArray + iVar10 + 0x18);
        if (pcVar9 == (char *)0x0) {
          pcVar9 = "Empty";
        }
        (*DAT_0019f758)(1,gmsgWeaponList,0,*(undefined4 *)(*param_1 + 0x208));
        (*DAT_0019f778)(pcVar9);
        pcVar9 = *(char **)(_15CBasePlayerItem_ItemInfoArray + iVar10 + 8);
        if (pcVar9 != (char *)0x0) {
          iVar7 = 1;
          do {
            if (((char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar7 * 2] != (char *)0x0) &&
               (iVar4 = strcasecmp(pcVar9,(char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar7 * 2]),
               iVar4 == 0)) goto LAB_000dccc7;
            iVar7 = iVar7 + 1;
          } while (iVar7 < 0x20);
        }
        iVar7 = -1;
LAB_000dccc7:
        (*DAT_0019f760)(iVar7);
        (*DAT_0019f760)(*(undefined4 *)(_15CBasePlayerItem_ItemInfoArray + iVar10 + 0xc));
        pcVar9 = *(char **)(_15CBasePlayerItem_ItemInfoArray + iVar10 + 0x10);
        if (pcVar9 != (char *)0x0) {
          iVar7 = 1;
          do {
            if (((char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar7 * 2] != (char *)0x0) &&
               (iVar4 = strcasecmp(pcVar9,(char *)(&_15CBasePlayerItem_AmmoInfoArray)[iVar7 * 2]),
               iVar4 == 0)) goto LAB_000dcd43;
            iVar7 = iVar7 + 1;
          } while (iVar7 < 0x20);
        }
        iVar7 = -1;
LAB_000dcd43:
        (*DAT_0019f760)(iVar7);
        (*DAT_0019f760)(*(undefined4 *)(_15CBasePlayerItem_ItemInfoArray + iVar10 + 0x14));
        (*DAT_0019f760)(*(undefined4 *)(_15CBasePlayerItem_ItemInfoArray + iVar10));
        (*DAT_0019f760)(*(undefined4 *)(_15CBasePlayerItem_ItemInfoArray + iVar10 + 4));
        (*DAT_0019f760)(*(undefined4 *)(_15CBasePlayerItem_ItemInfoArray + iVar10 + 0x20));
        (*DAT_0019f760)(*(undefined4 *)(_15CBasePlayerItem_ItemInfoArray + iVar10 + 0x24));
        (*DAT_0019f75c)();
      }
      iStack_14 = iStack_14 + 1;
    } while (iStack_14 < 0x20);
  }
  SendAmmoUpdate__11CBasePlayer(param_1);
  iVar10 = 0;
  do {
    iVar7 = param_1[iVar10 + 0x231];
    if (iVar7 != 0) {
      (**(code **)(*(int *)(iVar7 + 0x454) + 0x14c))(iVar7,param_1);
    }
    iVar10 = iVar10 + 1;
  } while (iVar10 < 6);
  return;
}


