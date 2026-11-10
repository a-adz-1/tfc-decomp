// UpdateLowPriorityClientData__11CBasePlayer  @ 000deb30
void UpdateLowPriorityClientData__11CBasePlayer(int *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  byte bVar7;
  undefined4 uVar5;
  char *pcVar6;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  if (gDisplayTitle != 0) {
    (*DAT_00175578)(1,gmsgShowGameTitle,0,*(undefined4 *)(*param_1 + 0x1e8));
    (*DAT_00175580)(0);
    (*DAT_0017557c)();
    gDisplayTitle = 0;
  }
  if (param_1[0x25a] != param_1[0x25b]) {
    (*DAT_00175578)(1,gmsgConcuss,0,*(undefined4 *)(*param_1 + 0x1e8));
    (*DAT_00175580)(param_1[0x25a]);
    (*DAT_0017557c)();
    param_1[0x25b] = param_1[0x25a];
  }
  fVar3 = (float)param_1[0x201];
  fVar2 = *(float *)(*param_1 + 0x19c);
  if ((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) != 0x40) {
    param_1[0x201] = (int)ROUND(fVar2);
    (*DAT_00175578)(1,gmsgBattery,0,*(undefined4 *)(*param_1 + 0x1e8));
    (*DAT_00175588)((int)ROUND(*(float *)(*param_1 + 0x19c)));
    (*DAT_0017557c)();
  }
  fVar3 = (float)param_1[0x12];
  fVar2 = (float)param_1[0x2a];
  if ((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) != 0x40) {
    param_1[0x2a] = (int)fVar3;
    (*DAT_00175578)(1,gmsgGrenades,0,*(undefined4 *)(*param_1 + 0x1e8));
    (*DAT_00175580)(0);
    (*DAT_00175580)(param_1[0x12]);
    (*DAT_0017557c)();
  }
  fVar3 = (float)param_1[0x13];
  fVar2 = (float)param_1[0x2b];
  if ((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) != 0x40) {
    param_1[0x2b] = (int)fVar3;
    (*DAT_00175578)(1,gmsgGrenades,0,*(undefined4 *)(*param_1 + 0x1e8));
    (*DAT_00175580)(1);
    (*DAT_00175580)(param_1[0x13]);
    (*DAT_0017557c)();
  }
  if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(*param_1 + 0x144)) ||
                                      NAN((float)param_1[0x255])) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(*param_1 + 0x144) == (float)param_1[0x255]) << 0xe)
                   >> 8)) != 0x40) || (param_1[0x254] != param_1[0x253])) {
    (*DAT_00175578)(2,gmsgScoreInfo,0,0);
    uVar5 = (*DAT_001755dc)(*(undefined4 *)(*param_1 + 0x1e8));
    (*DAT_00175580)(uVar5);
    (*DAT_00175588)((int)ROUND(*(float *)(*param_1 + 0x144)));
    (*DAT_00175588)(param_1[0x253]);
    (*DAT_0017557c)();
    param_1[0x254] = param_1[0x253];
    param_1[0x255] = (int)ROUND(*(float *)(*param_1 + 0x144));
  }
  if ((*(byte *)(param_1 + 0x1f6) & 0xc0) != 0) {
    (*DAT_00175578)(1,gmsgTrain,0,*(undefined4 *)(*param_1 + 0x1e8));
    (*DAT_00175580)(param_1[0x1f6] & 0xf);
    (*DAT_0017557c)();
    *(byte *)(param_1 + 0x1f6) = *(byte *)(param_1 + 0x1f6) & 0x3f;
  }
  if ((param_1[0x22] & 1U) != param_1[0x20]) {
    (*DAT_00175578)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x1e8));
    (*DAT_00175580)(param_1[0x22] & 1);
    (*DAT_00175584)(100);
    (*DAT_00175584)(0x5f);
    if (param_1[0x16] == 0) {
      pcVar6 = "normalgrenade";
    }
    else {
      pcVar6 = (char *)(param_1[0x16] + *(int *)(gpGlobals + 0x98));
    }
    (*DAT_00175598)(pcVar6);
    (*DAT_00175580)(0xff);
    (*DAT_00175580)(0xa0);
    (*DAT_00175580)(0);
    (*DAT_0017557c)();
    param_1[0x20] = param_1[0x22] & 1;
  }
  fVar2 = (float)param_1[0x6c];
  fVar3 = (float)param_1[0x68];
  if ((byte)(fVar3 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) != 0x40) {
    (*DAT_00175578)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x1e8));
    fVar2 = (float)param_1[0x68];
    (*DAT_00175580)((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                          (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 1);
    (*DAT_00175598)("dmg_caltrop");
    (*DAT_00175580)(0xff);
    (*DAT_00175580)(0xa0);
    (*DAT_00175580)(0);
    (*DAT_0017557c)();
    param_1[0x6c] = param_1[0x68];
  }
  fVar2 = (float)param_1[0x6e];
  if ((short)param_1[0x22] < 0) {
    bVar7 = (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 1.0) << 0xe) >> 8);
  }
  else {
    bVar7 = 0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8);
  }
  if (bVar7 != 0x40) {
    (*DAT_00175578)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x1e8));
    (*DAT_00175580)((uint)param_1[0x22] >> 0xf & 1);
    (*DAT_00175598)("dmg_tranq");
    (*DAT_00175580)(0xff);
    (*DAT_00175580)(0xa0);
    (*DAT_00175580)(0);
    (*DAT_0017557c)();
    iVar10 = 0;
    if ((short)param_1[0x22] < 0) {
      iVar10 = 0x3f800000;
    }
    param_1[0x6e] = iVar10;
  }
  fVar2 = (float)param_1[0x6d];
  if ((*(byte *)((int)param_1 + 0x89) & 0x40) == 0) {
    bVar7 = 0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8);
  }
  else {
    bVar7 = (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 1.0) << 0xe) >> 8);
  }
  if (bVar7 != 0x40) {
    (*DAT_00175578)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x1e8));
    (*DAT_00175580)((uint)param_1[0x22] >> 0xe & 1);
    (*DAT_00175598)("dmg_haluc");
    (*DAT_00175580)(0xff);
    (*DAT_00175580)(0xa0);
    (*DAT_00175580)(0);
    (*DAT_0017557c)();
    iVar10 = 0;
    if ((*(byte *)((int)param_1 + 0x89) & 0x40) != 0) {
      iVar10 = 0x3f800000;
    }
    param_1[0x6d] = iVar10;
  }
  uVar4 = param_1[0x23];
  if (uVar4 != param_1[0x256]) {
    uVar8 = (param_1[0x256] ^ uVar4) & uVar4;
    uVar9 = (param_1[0x256] ^ uVar4) & param_1[0x256];
    param_1[0x256] = uVar4;
    if ((uVar8 & 0x20000) == 0) {
      if ((uVar9 & 0x20000) != 0) {
        (*DAT_00175578)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x1e8));
        (*DAT_00175580)(0);
        (*DAT_00175598)("flag_blue");
        (*DAT_0017557c)();
      }
    }
    else {
      (*DAT_00175578)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x1e8));
      (*DAT_00175580)(1);
      (*DAT_00175598)("flag_blue");
      (*DAT_00175580)(0);
      (*DAT_00175580)(0);
      (*DAT_00175580)(0xff);
      (*DAT_0017557c)();
    }
    if ((uVar8 & 0x40000) == 0) {
      if ((uVar9 & 0x40000) != 0) {
        (*DAT_00175578)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x1e8));
        (*DAT_00175580)(0);
        (*DAT_00175598)("flag_red");
        (*DAT_0017557c)();
      }
    }
    else {
      (*DAT_00175578)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x1e8));
      (*DAT_00175580)(1);
      (*DAT_00175598)("flag_red");
      (*DAT_00175580)(0xff);
      (*DAT_00175580)(0);
      (*DAT_00175580)(0);
      (*DAT_0017557c)();
    }
    if ((uVar8 & 0x1000000) == 0) {
      if ((uVar9 & 0x1000000) != 0) {
        (*DAT_00175578)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x1e8));
        (*DAT_00175580)(0);
        (*DAT_00175598)("flag_yellow");
        (*DAT_0017557c)();
      }
    }
    else {
      (*DAT_00175578)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x1e8));
      (*DAT_00175580)(1);
      (*DAT_00175598)("flag_yellow");
      (*DAT_00175580)(0xff);
      (*DAT_00175580)(0xa0);
      (*DAT_00175580)(0);
      (*DAT_0017557c)();
    }
    if ((uVar8 & 0x2000000) == 0) {
      if ((uVar9 & 0x2000000) != 0) {
        (*DAT_00175578)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x1e8));
        (*DAT_00175580)(0);
        (*DAT_00175598)("flag_green");
        (*DAT_0017557c)();
      }
    }
    else {
      (*DAT_00175578)(1,gmsgStatusIcon,0,*(undefined4 *)(*param_1 + 0x1e8));
      (*DAT_00175580)(1);
      (*DAT_00175598)("flag_green");
      (*DAT_00175580)(0);
      (*DAT_00175580)(0xff);
      (*DAT_00175580)(0);
      (*DAT_0017557c)();
    }
  }
  if (param_1[0x198] == 0) {
    param_1[0x198] = 1;
    iVar10 = 0;
    do {
      iVar1 = iVar10 * 0x2c;
      if ((&DAT_00182aa0)[iVar10 * 0xb] != 0) {
        pcVar6 = "Empty";
        if ((&DAT_00182a98)[iVar10 * 0xb] != 0) {
          pcVar6 = (char *)(&DAT_00182a98)[iVar10 * 0xb];
        }
        (*DAT_00175578)(1,gmsgWeaponList,0,*(undefined4 *)(*param_1 + 0x1e8));
        (*DAT_00175598)(pcVar6);
        uVar5 = GetAmmoIndex__11CBasePlayerPCc(*(undefined4 *)(&DAT_00182a88 + iVar1));
        (*DAT_00175580)(uVar5);
        (*DAT_00175580)(*(undefined4 *)(&DAT_00182a8c + iVar1));
        uVar5 = GetAmmoIndex__11CBasePlayerPCc(*(undefined4 *)(&DAT_00182a90 + iVar1));
        (*DAT_00175580)(uVar5);
        (*DAT_00175580)(*(undefined4 *)(&DAT_00182a94 + iVar1));
        (*DAT_00175580)((&_15CBasePlayerItem_ItemInfoArray)[iVar10 * 0xb]);
        (*DAT_00175580)((&DAT_00182a84)[iVar10 * 0xb]);
        (*DAT_00175580)((&DAT_00182aa0)[iVar10 * 0xb]);
        (*DAT_00175580)((&DAT_00182aa4)[iVar10 * 0xb]);
        (*DAT_0017557c)();
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < 0x20);
  }
  SendAmmoUpdate__11CBasePlayer(param_1);
  iVar10 = 0;
  do {
    if (param_1[iVar10 + 0x206] != 0) {
      (**(code **)(*(int *)(param_1[iVar10 + 0x206] + 0x3c8) + 0x144))
                (param_1[iVar10 + 0x206],param_1);
    }
    iVar10 = iVar10 + 1;
  } while (iVar10 < 6);
  return;
}


