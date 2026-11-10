// UpdateLowPriorityClientData__11CBasePlayer  @ 000d1ba0
void UpdateLowPriorityClientData__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  int iStack_14;
  int iStack_10;
  
  if (gDisplayTitle != 0) {
    (*DAT_001a7ef8)(1,gmsgShowGameTitle,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_001a7f00)(0);
    (*DAT_001a7efc)();
    gDisplayTitle = 0;
  }
  if (param_1[0x261] != param_1[0x262]) {
    (*DAT_001a7ef8)(1,gmsgConcuss,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_001a7f00)(param_1[0x261]);
    (*DAT_001a7efc)();
    param_1[0x262] = param_1[0x261];
  }
  fVar2 = (float)param_1[0x206];
  fVar1 = *(float *)(*param_1 + 0x1bc);
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 0x40) {
    param_1[0x206] = (int)ROUND(fVar1);
    (*DAT_001a7ef8)(1,gmsgBattery,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_001a7f08)((int)ROUND(*(float *)(*param_1 + 0x1bc)));
    (*DAT_001a7efc)();
  }
  fVar2 = (float)param_1[0x11];
  fVar1 = (float)param_1[0x2a];
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 0x40) {
    param_1[0x2a] = (int)fVar2;
    (*DAT_001a7ef8)(1,gmsgGrenades,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_001a7f00)(0);
    (*DAT_001a7f00)(param_1[0x11]);
    (*DAT_001a7efc)();
  }
  fVar2 = (float)param_1[0x12];
  fVar1 = (float)param_1[0x2b];
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 0x40) {
    param_1[0x2b] = (int)fVar2;
    (*DAT_001a7ef8)(1,gmsgGrenades,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_001a7f00)(1);
    (*DAT_001a7f00)(param_1[0x12]);
    (*DAT_001a7efc)();
  }
  iVar3 = *param_1;
  if (((((byte)((byte)((ushort)((ushort)(NAN(*(float *)(iVar3 + 0x164)) ||
                                        NAN((float)param_1[0x25a])) << 10) >> 8) |
               (byte)((ushort)((ushort)(*(float *)(iVar3 + 0x164) == (float)param_1[0x25a]) << 0xe)
                     >> 8)) != 0x40) || (param_1[0x259] != param_1[600])) ||
      (param_1[0x25b] != *(int *)(iVar3 + 0x20c))) || (param_1[0x25c] != *(int *)(iVar3 + 0x1ac))) {
    (*DAT_001a7ef8)(2,gmsgScoreInfo,0,0);
    uVar4 = (*DAT_001a7f5c)(*(undefined4 *)(*param_1 + 0x208));
    (*DAT_001a7f00)(uVar4);
    (*DAT_001a7f08)((int)ROUND(*(float *)(*param_1 + 0x164)));
    (*DAT_001a7f08)(param_1[600]);
    (*DAT_001a7f08)(*(undefined4 *)(*param_1 + 0x20c));
    (*DAT_001a7f08)(*(undefined4 *)(*param_1 + 0x1ac));
    (*DAT_001a7efc)();
    iVar3 = *param_1;
    param_1[0x25b] = *(int *)(iVar3 + 0x20c);
    param_1[0x25c] = *(int *)(iVar3 + 0x1ac);
    param_1[0x259] = param_1[600];
    param_1[0x25a] = (int)ROUND(*(float *)(iVar3 + 0x164));
  }
  if ((*(byte *)(param_1 + 0x1fb) & 0xc0) != 0) {
    (*DAT_001a7ef8)(1,gmsgTrain,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_001a7f00)(param_1[0x1fb] & 0xf);
    (*DAT_001a7efc)();
    *(byte *)(param_1 + 0x1fb) = *(byte *)(param_1 + 0x1fb) & 0x3f;
  }
  fVar1 = (float)param_1[0x6c];
  fVar2 = (float)param_1[0x68];
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
    (*DAT_001a7ef8)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
    fVar1 = (float)param_1[0x68];
    (*DAT_001a7f00)((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1);
    (*DAT_001a7f18)("dmg_caltrop");
    (*DAT_001a7f00)(0xff);
    (*DAT_001a7f00)(0xa0);
    (*DAT_001a7f00)(0);
    (*DAT_001a7efc)();
    param_1[0x6c] = param_1[0x68];
  }
  uVar6 = (uint)param_1[0x21] >> 0xf & 1;
  fVar1 = (float)param_1[0x6e];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    if (uVar6 != 0) goto LAB_000d2184;
  }
  else if (uVar6 != 1) {
LAB_000d2184:
    (*DAT_001a7ef8)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
    (*DAT_001a7f00)((uint)param_1[0x21] >> 0xf & 1);
    (*DAT_001a7f18)("dmg_tranq");
    (*DAT_001a7f00)(0xff);
    (*DAT_001a7f00)(0xa0);
    (*DAT_001a7f00)(0);
    (*DAT_001a7efc)();
    iVar3 = 0;
    if ((short)param_1[0x21] < 0) {
      iVar3 = 0x3f800000;
    }
    param_1[0x6e] = iVar3;
  }
  uVar6 = (uint)param_1[0x21] >> 0xe & 1;
  fVar1 = (float)param_1[0x6d];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    if (uVar6 == 0) goto LAB_000d2334;
  }
  else if (uVar6 == 1) goto LAB_000d2334;
  (*DAT_001a7ef8)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001a7f00)((uint)param_1[0x21] >> 0xe & 1);
  (*DAT_001a7f18)("dmg_haluc");
  (*DAT_001a7f00)(0xff);
  (*DAT_001a7f00)(0xa0);
  (*DAT_001a7f00)(0);
  (*DAT_001a7efc)();
  iVar3 = 0;
  if ((*(byte *)((int)param_1 + 0x85) & 0x40) != 0) {
    iVar3 = 0x3f800000;
  }
  param_1[0x6d] = iVar3;
LAB_000d2334:
  uVar6 = param_1[0x22];
  if (uVar6 != param_1[0x25d]) {
    uVar7 = (param_1[0x25d] ^ uVar6) & uVar6;
    uVar5 = (param_1[0x25d] ^ uVar6) & param_1[0x25d];
    param_1[0x25d] = uVar6;
    if ((uVar7 & 0x20000) == 0) {
      if ((uVar5 & 0x20000) != 0) {
        (*DAT_001a7ef8)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
        (*DAT_001a7f00)(0);
        (*DAT_001a7f18)("flag_blue");
        (*DAT_001a7efc)();
      }
    }
    else {
      (*DAT_001a7ef8)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
      (*DAT_001a7f00)(1);
      (*DAT_001a7f18)("flag_blue");
      (*DAT_001a7f00)(0);
      (*DAT_001a7f00)(0);
      (*DAT_001a7f00)(0xff);
      (*DAT_001a7efc)();
    }
    if ((uVar7 & 0x40000) == 0) {
      if ((uVar5 & 0x40000) != 0) {
        (*DAT_001a7ef8)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
        (*DAT_001a7f00)(0);
        (*DAT_001a7f18)("flag_red");
        (*DAT_001a7efc)();
      }
    }
    else {
      (*DAT_001a7ef8)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
      (*DAT_001a7f00)(1);
      (*DAT_001a7f18)("flag_red");
      (*DAT_001a7f00)(0xff);
      (*DAT_001a7f00)(0);
      (*DAT_001a7f00)(0);
      (*DAT_001a7efc)();
    }
    if ((uVar7 & 0x1000000) == 0) {
      if ((uVar5 & 0x1000000) != 0) {
        (*DAT_001a7ef8)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
        (*DAT_001a7f00)(0);
        (*DAT_001a7f18)("flag_yellow");
        (*DAT_001a7efc)();
      }
    }
    else {
      (*DAT_001a7ef8)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
      (*DAT_001a7f00)(1);
      (*DAT_001a7f18)("flag_yellow");
      (*DAT_001a7f00)(0xff);
      (*DAT_001a7f00)(0xa0);
      (*DAT_001a7f00)(0);
      (*DAT_001a7efc)();
    }
    if ((uVar7 & 0x2000000) == 0) {
      if ((uVar5 & 0x2000000) != 0) {
        (*DAT_001a7ef8)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
        (*DAT_001a7f00)(0);
        (*DAT_001a7f18)("flag_green");
        (*DAT_001a7efc)();
      }
    }
    else {
      (*DAT_001a7ef8)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x208));
      (*DAT_001a7f00)(1);
      (*DAT_001a7f18)("flag_green");
      (*DAT_001a7f00)(0);
      (*DAT_001a7f00)(0xff);
      (*DAT_001a7f00)(0);
      (*DAT_001a7efc)();
    }
  }
  if (param_1[0x19c] == 0) {
    param_1[0x19c] = 1;
    iStack_10 = 0;
    iStack_14 = 0;
    do {
      if (*(int *)(_15CBasePlayerItem_ItemInfoArray + iStack_14 + 0x20) != 0) {
        pcVar8 = "Empty";
        if (*(int *)(_15CBasePlayerItem_ItemInfoArray + iStack_14 + 0x18) != 0) {
          pcVar8 = *(char **)(_15CBasePlayerItem_ItemInfoArray + iStack_14 + 0x18);
        }
        (*DAT_001a7ef8)(1,gmsgWeaponList,0,*(undefined4 *)(*param_1 + 0x208));
        (*DAT_001a7f18)(pcVar8);
        uVar4 = GetAmmoIndex__11CBasePlayerPCc
                          (*(undefined4 *)(_15CBasePlayerItem_ItemInfoArray + iStack_14 + 8));
        (*DAT_001a7f00)(uVar4);
        (*DAT_001a7f00)(*(undefined4 *)(_15CBasePlayerItem_ItemInfoArray + iStack_14 + 0xc));
        uVar4 = GetAmmoIndex__11CBasePlayerPCc
                          (*(undefined4 *)(_15CBasePlayerItem_ItemInfoArray + iStack_14 + 0x10));
        (*DAT_001a7f00)(uVar4);
        (*DAT_001a7f00)(*(undefined4 *)(_15CBasePlayerItem_ItemInfoArray + iStack_14 + 0x14));
        (*DAT_001a7f00)(*(undefined4 *)(_15CBasePlayerItem_ItemInfoArray + iStack_14));
        (*DAT_001a7f00)(*(undefined4 *)(_15CBasePlayerItem_ItemInfoArray + iStack_14 + 4));
        (*DAT_001a7f00)(*(undefined4 *)(_15CBasePlayerItem_ItemInfoArray + iStack_14 + 0x20));
        (*DAT_001a7f00)(*(undefined4 *)(_15CBasePlayerItem_ItemInfoArray + iStack_14 + 0x24));
        (*DAT_001a7efc)();
      }
      iStack_14 = iStack_14 + 0x2c;
      iStack_10 = iStack_10 + 1;
    } while (iStack_10 < 0x20);
  }
  SendAmmoUpdate__11CBasePlayer(param_1);
  if (param_1[0x20b] != 0) {
    (**(code **)(*(int *)(param_1[0x20b] + 0x3d4) + 0x144))(param_1[0x20b],param_1);
  }
  if (param_1[0x20c] != 0) {
    (**(code **)(*(int *)(param_1[0x20c] + 0x3d4) + 0x144))(param_1[0x20c],param_1);
  }
  if (param_1[0x20d] != 0) {
    (**(code **)(*(int *)(param_1[0x20d] + 0x3d4) + 0x144))(param_1[0x20d],param_1);
  }
  if (param_1[0x20e] != 0) {
    (**(code **)(*(int *)(param_1[0x20e] + 0x3d4) + 0x144))(param_1[0x20e],param_1);
  }
  if (param_1[0x20f] != 0) {
    (**(code **)(*(int *)(param_1[0x20f] + 0x3d4) + 0x144))(param_1[0x20f],param_1);
  }
  if (param_1[0x210] != 0) {
    (**(code **)(*(int *)(param_1[0x210] + 0x3d4) + 0x144))(param_1[0x210],param_1);
  }
  return;
}


