// WeaponIdle__10CTFMedikit  @ 0012c818
void WeaponIdle__10CTFMedikit(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  
  fVar1 = *(float *)(param_1 + 0x490);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    *(undefined4 *)(param_1 + 0x490) = 0x40f00000;
    iVar2 = (*DAT_0019f808)(0,1);
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x454);
      uVar3 = 0;
    }
    else {
      if (iVar2 != 1) {
        return;
      }
      iVar2 = *(int *)(param_1 + 0x454);
      uVar3 = 1;
    }
    (**(code **)(iVar2 + 0x168))(param_1,uVar3,1);
  }
  return;
}


// WeaponIdle__10CTFNailgun  @ 0012f500
void WeaponIdle__10CTFNailgun(int param_1)

{
  float fVar1;
  
  (**(code **)(*(int *)(param_1 + 0x454) + 0x164))(param_1);
  fVar1 = *(float *)(param_1 + 0x490);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    *(undefined4 *)(param_1 + 0x490) = 0x41700000;
    (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,1,1);
  }
  return;
}


// WeaponIdle__10CTFRailgun  @ 0012fab4
void WeaponIdle__10CTFRailgun(int param_1)

{
  float fVar1;
  
  (**(code **)(*(int *)(param_1 + 0x454) + 0x164))(param_1);
  fVar1 = *(float *)(param_1 + 0x490);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    *(undefined4 *)(param_1 + 0x490) = 0x41480000;
    (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,0,1);
  }
  return;
}


// WeaponIdle__10CTFShotgun  @ 00130ad4
void WeaponIdle__10CTFShotgun(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  
  (**(code **)(*(int *)(param_1 + 0x454) + 0x164))(param_1);
  fVar1 = *(float *)(param_1 + 0x498);
  if (((byte)(fVar1 < 1000.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 1000.0) << 0xe) >> 8)) != 0x40) &&
     (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1))) {
    (*DAT_0019f88c)(1,*(undefined4 *)(**(int **)(param_1 + 0x474) + 0x208),
                    *(undefined2 *)(param_1 + 0x4de),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    *(undefined4 *)(param_1 + 0x498) = 0x447a0000;
  }
  fVar1 = *(float *)(param_1 + 0x490);
  if ((byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    return;
  }
  if (*(int *)(param_1 + 0x4c0) == 0) {
    if (*(int *)(param_1 + 0x4b4) == 0) {
      if (*(int *)(param_1 + 0x4d4) <= *(int *)(*(int *)(param_1 + 0x474) + 0xcc))
      goto LAB_00130c06;
      goto LAB_00130bd7;
    }
  }
  else {
LAB_00130bd7:
    if (*(int *)(param_1 + 0x4b4) == 0) {
      iVar2 = UTIL_SharedRandomLong__FUiii
                        (*(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6b0),0,0x14);
      if (iVar2 == (iVar2 / 5) * 5) {
        if (iVar2 == (iVar2 / 0x14) * 0x14) {
          uVar3 = 0;
          *(undefined4 *)(param_1 + 0x490) = 0x400e38e4;
        }
        else {
          uVar3 = 8;
          *(undefined4 *)(param_1 + 0x490) = 0x4006bca2;
        }
      }
      else {
        uVar3 = 9;
        *(undefined4 *)(param_1 + 0x490) = 0x40a00000;
      }
      (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,uVar3,1);
      return;
    }
  }
  if ((*(int *)(param_1 + 0x4c0) == *(int *)(param_1 + 0x4d8)) ||
     ((*(int **)(param_1 + 0x474))[0x33] < *(int *)(param_1 + 0x4d4))) {
    (*DAT_0019f88c)(1,*(undefined4 *)(**(int **)(param_1 + 0x474) + 0x208),
                    *(undefined2 *)(param_1 + 0x4de),0,&g_vecZero,&g_vecZero,0,0,0,0,1,0);
    *(undefined4 *)(param_1 + 0x4b4) = 0;
    *(undefined4 *)(param_1 + 0x490) = 0x3fc00000;
    return;
  }
LAB_00130c06:
  (**(code **)(*(int *)(param_1 + 0x454) + 0x178))(param_1);
  return;
}


// WeaponIdle__10CTFSpanner  @ 0012cd24
void WeaponIdle__10CTFSpanner(int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x490);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    *(undefined4 *)(param_1 + 0x490) = 0x41480000;
    (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,0,1);
  }
  return;
}


// WeaponIdle__11CTFAssaultC  @ 0012a3b0
void WeaponIdle__11CTFAssaultC(int param_1)

{
  byte *pbVar1;
  float fVar2;
  uint uVar3;
  
  (**(code **)(*(int *)(param_1 + 0x454) + 0x164))(param_1);
  fVar2 = *(float *)(param_1 + 0x490);
  if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1) {
    if (*(int *)(param_1 + 0x4ac) == 0) {
      uVar3 = UTIL_SharedRandomLong__FUiii(*(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6b0),0,1);
      (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,~uVar3 & 1,1);
      *(undefined4 *)(param_1 + 0x490) = 0x41480000;
    }
    else {
      (*DAT_0019f88c)(7,*(undefined4 *)(**(int **)(param_1 + 0x474) + 0x208),
                      *(undefined2 *)(param_1 + 0x4da),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
      *(undefined4 *)(param_1 + 0x4ac) = 0;
      pbVar1 = (byte *)(*(int *)(param_1 + 0x474) + 0x85);
      *pbVar1 = *pbVar1 & 0xf7;
      TeamFortress_SetSpeed__11CBasePlayer(*(undefined4 *)(param_1 + 0x474));
      *(undefined4 *)(param_1 + 0x490) = 0x40000000;
    }
  }
  return;
}


// WeaponIdle__12CHandGrenade  @ 000b4a44
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WeaponIdle__12CHandGrenade(int param_1)

{
  float fVar1;
  int *piVar2;
  float fVar3;
  int iVar4;
  bool bVar5;
  longdouble lVar6;
  longdouble lVar7;
  undefined4 uVar8;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x4d4)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(param_1 + 0x4d4) == 0.0) << 0xe) >> 8)) == 0x40) {
    *(float *)(param_1 + 0x4d4) = *gpGlobals;
  }
  fVar1 = *(float *)(param_1 + 0x490);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    fVar1 = *(float *)(param_1 + 0x4d0);
    if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      if (*(float *)(param_1 + 0x4d4) <= 0.0) {
        if (*(int *)(*(int *)(param_1 + 0x4b8) * 4 + *(int *)(param_1 + 0x474) + 0x8ec) != 0) {
          lVar6 = (longdouble)(*DAT_0019f80c)(0,0x3f800000);
          lVar7 = (longdouble)_FUN_0014c880;
          bVar5 = (byte)(lVar7 < lVar6 |
                         (byte)((ushort)((ushort)(NAN(lVar7) || NAN(lVar6)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar7 == lVar6) << 0xe) >> 8)) == 1;
          if (bVar5) {
            *(undefined4 *)(param_1 + 0x490) = 0x40200000;
          }
          else {
            lVar6 = (longdouble)(*DAT_0019f80c)(0x41200000,0x41700000);
            *(float *)(param_1 + 0x490) = (float)lVar6;
          }
          (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,bVar5,0);
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x4d0) = 0;
        if (*(int *)(*(int *)(param_1 + 0x4b8) * 4 + *(int *)(param_1 + 0x474) + 0x8ec) == 0) {
          (**(code **)(*(int *)(param_1 + 0x454) + 0x180))(param_1);
        }
        else {
          (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,7,0);
          lVar6 = (longdouble)(*DAT_0019f80c)(0x41200000,0x41700000);
          *(float *)(param_1 + 0x490) = (float)lVar6;
          *(undefined4 *)(param_1 + 0x4d4) = 0xbf800000;
        }
      }
    }
    else {
      iVar4 = **(int **)(param_1 + 0x474);
      fVar1 = *(float *)(iVar4 + 0x74) + *(float *)(iVar4 + 0x68);
      local_c = *(float *)(iVar4 + 0x78) + *(float *)(iVar4 + 0x6c);
      local_8 = *(float *)(iVar4 + 0x7c) + *(float *)(iVar4 + 0x70);
      if (0.0 <= fVar1) {
        fVar3 = 1.1111112;
      }
      else {
        fVar3 = 0.8888889;
      }
      local_14 = (float)_FUN_0014c850 + fVar3 * fVar1;
      fVar1 = (90.0 - local_14) * 4.0;
      if (0x3f < (byte)((fVar1 < 500.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == 500.0) << 0xe) >> 8)) - 1)) {
        fVar1 = 500.0;
      }
      local_10 = local_14;
      UTIL_MakeVectors__FRC6Vector(&local_10);
      piVar2 = *(int **)(param_1 + 0x474);
      iVar4 = *piVar2;
      fStack_2c = *(float *)(iVar4 + 8) + *(float *)(iVar4 + 0x174) + gpGlobals[10] * 16.0;
      fStack_28 = *(float *)(*piVar2 + 0xc) + *(float *)(iVar4 + 0x178) + gpGlobals[0xb] * 16.0;
      fStack_24 = *(float *)(*piVar2 + 0x10) + *(float *)(iVar4 + 0x17c) + gpGlobals[0xc] * 16.0;
      fStack_40 = gpGlobals[0xb] * fVar1 + *(float *)(*piVar2 + 0x24);
      fStack_44 = gpGlobals[10] * fVar1 + *(float *)(*piVar2 + 0x20);
      fStack_3c = gpGlobals[0xc] * fVar1 + *(float *)(*piVar2 + 0x28);
      local_14 = (*(float *)(param_1 + 0x4d0) - *gpGlobals) + 3.0;
      fVar3 = local_14;
      if (0x3f < (byte)((0.0 < local_14 | (byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
                        (byte)((ushort)((ushort)(local_14 == 0.0) << 0xe) >> 8)) - 1)) {
        fVar3 = 0.0;
      }
      fStack_38 = fStack_44;
      fStack_34 = fStack_40;
      fStack_30 = fStack_3c;
      fStack_20 = fStack_2c;
      fStack_1c = fStack_28;
      fStack_18 = fStack_24;
      ShootTimed__8CGrenadeP9entvars_sG6VectorT2f(*piVar2,&fStack_2c,&fStack_44,fVar3);
      if (500.0 <= fVar1) {
        if ((byte)((1000.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar1 == 1000.0) << 0xe) >> 8)) - 1) < 0x40) {
          iVar4 = *(int *)(param_1 + 0x454);
          uVar8 = 5;
        }
        else {
          iVar4 = *(int *)(param_1 + 0x454);
          uVar8 = 4;
        }
      }
      else {
        iVar4 = *(int *)(param_1 + 0x454);
        uVar8 = 3;
      }
      (**(code **)(iVar4 + 0x168))(param_1,uVar8,0);
      SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x474),5);
      *(undefined4 *)(param_1 + 0x4d0) = 0;
      *(undefined4 *)(param_1 + 0x488) = 0x3f000000;
      *(undefined4 *)(param_1 + 0x490) = 0x3f000000;
      piVar2 = (int *)(*(int *)(param_1 + 0x4b8) * 4 + *(int *)(param_1 + 0x474) + 0x8ec);
      *piVar2 = *piVar2 + -1;
      if (*(int *)(*(int *)(param_1 + 0x4b8) * 4 + *(int *)(param_1 + 0x474) + 0x8ec) == 0) {
        *(undefined4 *)(param_1 + 0x488) = 0x3f000000;
        *(undefined4 *)(param_1 + 0x48c) = 0x3f000000;
        *(undefined4 *)(param_1 + 0x490) = 0x3f000000;
      }
    }
  }
  return;
}


// WeaponIdle__12CTFAutoRifle  @ 0012abb4
void WeaponIdle__12CTFAutoRifle(int param_1)

{
  float fVar1;
  
  (**(code **)(*(int *)(param_1 + 0x454) + 0x164))(param_1);
  fVar1 = *(float *)(param_1 + 0x490);
  if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
    (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,5,1);
    *(undefined4 *)(param_1 + 0x490) = 0x41480000;
  }
  return;
}


// WeaponIdle__14CTFIncendiaryC  @ 0012ea50
void WeaponIdle__14CTFIncendiaryC(int param_1)

{
  float fVar1;
  
  (**(code **)(*(int *)(param_1 + 0x454) + 0x164))(param_1);
  fVar1 = *(float *)(param_1 + 0x490);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    if (*(int *)(*(int *)(param_1 + 0x474) + 0xe4) < 1) {
      *(undefined4 *)(param_1 + 0x490) = 0x3f800000;
    }
    else {
      *(undefined4 *)(param_1 + 0x490) = 0x40400000;
      (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,1,1);
    }
  }
  return;
}


// WeaponIdle__14CTFSniperRifle  @ 00131e68
void WeaponIdle__14CTFSniperRifle(int param_1)

{
  float fVar1;
  
  UpdateSpot__14CTFSniperRifle(param_1);
  (**(code **)(*(int *)(param_1 + 0x454) + 0x164))(param_1);
  fVar1 = *(float *)(param_1 + 0x490);
  if ((0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) &&
     ((*(byte *)(*(int *)(param_1 + 0x474) + 0x85) & 8) == 0)) {
    (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,0,1);
    *(undefined4 *)(param_1 + 0x490) = 0x41480000;
  }
  return;
}


// WeaponIdle__15CTFFlamethrower  @ 0012d708
void WeaponIdle__15CTFFlamethrower(int param_1)

{
  float fVar1;
  int iVar2;
  
  (**(code **)(*(int *)(param_1 + 0x454) + 0x164))(param_1);
  fVar1 = *(float *)(param_1 + 0x490);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    iVar2 = UTIL_SharedRandomLong__FUiii(*(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6b0),0,4);
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 0x490) = 0x41480000;
    }
    else {
      *(undefined4 *)(param_1 + 0x490) = 0x40400000;
    }
    (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,iVar2 == 0,1);
  }
  return;
}


// WeaponIdle__17CBasePlayerWeapon  @ 00126584
void WeaponIdle__17CBasePlayerWeapon(void)

{
  return;
}


// WeaponIdle__18CTFGrenadeLauncher  @ 0012e248
void WeaponIdle__18CTFGrenadeLauncher(int param_1)

{
  float fVar1;
  
  (**(code **)(*(int *)(param_1 + 0x454) + 0x164))(param_1);
  fVar1 = *(float *)(param_1 + 0x490);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    return;
  }
  if (*(int *)(param_1 + 0x4c0) == 0) {
    if (*(int *)(param_1 + 0x4b4) == 0) {
      if (0 < *(int *)(*(int *)(param_1 + 0x474) + 0xe4)) goto LAB_0012e2c6;
      goto LAB_0012e2a9;
    }
  }
  else {
LAB_0012e2a9:
    if (*(int *)(param_1 + 0x4b4) == 0) {
      *(undefined4 *)(param_1 + 0x490) = 0x40400000;
      (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,*(undefined4 *)(param_1 + 0x4d8),1);
      return;
    }
  }
  if ((*(int *)(param_1 + 0x4c0) == 6) || (*(int *)(*(int *)(param_1 + 0x474) + 0xe4) < 1)) {
    (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,*(undefined4 *)(param_1 + 0x4e0),1);
    *(undefined4 *)(param_1 + 0x4b4) = 0;
    *(undefined4 *)(param_1 + 0x490) = 0x3fc00000;
    return;
  }
LAB_0012e2c6:
  (**(code **)(*(int *)(param_1 + 0x454) + 0x178))(param_1);
  return;
}


// WeaponIdle__6CTFRpg  @ 00130130
void WeaponIdle__6CTFRpg(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  
  (**(code **)(*(int *)(param_1 + 0x454) + 0x164))(param_1);
  fVar1 = *(float *)(param_1 + 0x490);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    return;
  }
  iVar2 = *(int *)(param_1 + 0x4c0);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x4b4) == 0) {
      if (0 < *(int *)(*(int *)(param_1 + 0x474) + 0xe4)) goto LAB_001301ae;
      goto LAB_00130191;
    }
  }
  else {
LAB_00130191:
    if (*(int *)(param_1 + 0x4b4) == 0) {
      if (*(int *)(*(int *)(param_1 + 0x474) + 0xb0) != 0) {
        uVar3 = 1;
        if (iVar2 == 0) {
          uVar3 = 0xb;
        }
        *(undefined4 *)(param_1 + 0x490) = 0x40400000;
        (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,uVar3,1);
        return;
      }
      *(undefined4 *)(param_1 + 0x490) = 0x3f800000;
      return;
    }
  }
  if ((iVar2 == 4) || (*(int *)(*(int *)(param_1 + 0x474) + 0xe4) < 1)) {
    (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,9,1);
    *(undefined4 *)(param_1 + 0x4b4) = 0;
    *(undefined4 *)(param_1 + 0x490) = 0x3fc00000;
    return;
  }
LAB_001301ae:
  (**(code **)(*(int *)(param_1 + 0x454) + 0x178))(param_1);
  return;
}


// WeaponIdle__8CTFKnife  @ 0012ca58
void WeaponIdle__8CTFKnife(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  
  fVar1 = *(float *)(param_1 + 0x490);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    *(undefined4 *)(param_1 + 0x490) = 0x40f00000;
    iVar2 = (*DAT_0019f808)(0,1);
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x454);
      uVar3 = 0;
    }
    else {
      if (iVar2 != 1) {
        return;
      }
      iVar2 = *(int *)(param_1 + 0x454);
      uVar3 = 1;
    }
    (**(code **)(iVar2 + 0x168))(param_1,uVar3,1);
  }
  return;
}


// WeaponIdle__8CTFTranq  @ 00132754
void WeaponIdle__8CTFTranq(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  
  (**(code **)(*(int *)(param_1 + 0x454) + 0x164))(param_1);
  fVar1 = *(float *)(param_1 + 0x490);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    iVar2 = UTIL_SharedRandomLong__FUiii(*(undefined4 *)(*(int *)(param_1 + 0x474) + 0x6b0),0,3);
    if (iVar2 == (iVar2 / 3) * 3) {
      uVar3 = 2;
      *(undefined4 *)(param_1 + 0x490) = 0x40440000;
    }
    else if (iVar2 + 1 == ((iVar2 + 1) / 3) * 3) {
      uVar3 = 0;
      *(undefined4 *)(param_1 + 0x490) = 0x40700000;
    }
    else {
      uVar3 = 1;
      *(undefined4 *)(param_1 + 0x490) = 0x40200000;
    }
    (**(code **)(*(int *)(param_1 + 0x454) + 0x168))(param_1,uVar3,1);
  }
  return;
}


