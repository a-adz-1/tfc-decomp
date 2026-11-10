// WeaponIdle__10CTFMedikit  @ 00128f7c
void WeaponIdle__10CTFMedikit(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  
  fVar1 = *(float *)(param_1 + 0x480);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    *(undefined4 *)(param_1 + 0x480) = 0x40f00000;
    iVar2 = (*DAT_001c1188)(0,1);
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x444);
      uVar3 = 0;
    }
    else {
      if (iVar2 != 1) {
        return;
      }
      iVar2 = *(int *)(param_1 + 0x444);
      uVar3 = 1;
    }
    (**(code **)(iVar2 + 0x168))(param_1,uVar3,1);
  }
  return;
}


// WeaponIdle__10CTFNailgun  @ 0012b0d8
void WeaponIdle__10CTFNailgun(int param_1)

{
  float fVar1;
  
  (**(code **)(*(int *)(param_1 + 0x444) + 0x164))(param_1);
  fVar1 = *(float *)(param_1 + 0x480);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    *(undefined4 *)(param_1 + 0x480) = 0x41700000;
    (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,1,1);
  }
  return;
}


// WeaponIdle__10CTFRailgun  @ 0012b99c
void WeaponIdle__10CTFRailgun(int param_1)

{
  float fVar1;
  
  (**(code **)(*(int *)(param_1 + 0x444) + 0x164))(param_1);
  fVar1 = *(float *)(param_1 + 0x480);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    *(undefined4 *)(param_1 + 0x480) = 0x41480000;
    (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,0,1);
  }
  return;
}


// WeaponIdle__10CTFShotgun  @ 0012c9f4
void WeaponIdle__10CTFShotgun(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  
  (**(code **)(*(int *)(param_1 + 0x444) + 0x164))(param_1);
  fVar1 = *(float *)(param_1 + 0x488);
  if (((byte)(1000.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 1000.0) << 0xe) >> 8)) != 0x40) &&
     (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1))) {
    (*DAT_001c120c)(1,*(undefined4 *)(**(int **)(param_1 + 0x464) + 0x208),
                    *(undefined2 *)(param_1 + 0x4ce),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    *(undefined4 *)(param_1 + 0x488) = 0x447a0000;
  }
  fVar1 = *(float *)(param_1 + 0x480);
  if ((byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    return;
  }
  if (*(int *)(param_1 + 0x4b0) == 0) {
    if (*(int *)(param_1 + 0x4a4) == 0) {
      if (*(int *)(param_1 + 0x4c4) <= *(int *)(*(int *)(param_1 + 0x464) + 0xcc))
      goto LAB_0012cb0f;
      goto LAB_0012cae0;
    }
  }
  else {
LAB_0012cae0:
    if (*(int *)(param_1 + 0x4a4) == 0) {
      iVar2 = UTIL_SharedRandomLong__FUiii
                        (*(undefined4 *)(*(int *)(param_1 + 0x464) + 0x68c),0,0x14);
      if (iVar2 == (iVar2 / 5) * 5) {
        if (iVar2 == (iVar2 / 0x14) * 0x14) {
          uVar3 = 0;
          *(undefined4 *)(param_1 + 0x480) = 0x400e38e4;
        }
        else {
          uVar3 = 8;
          *(undefined4 *)(param_1 + 0x480) = 0x4006bca2;
        }
      }
      else {
        uVar3 = 9;
        *(undefined4 *)(param_1 + 0x480) = 0x40a00000;
      }
      (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,uVar3,1);
      return;
    }
  }
  if ((*(int *)(param_1 + 0x4b0) == *(int *)(param_1 + 0x4c8)) ||
     (*(int *)(*(int *)(param_1 + 0x464) + 0xcc) < *(int *)(param_1 + 0x4c4))) {
    (*DAT_001c120c)(1,*(undefined4 *)(**(int **)(param_1 + 0x464) + 0x208),
                    *(undefined2 *)(param_1 + 0x4ce),0,&g_vecZero,&g_vecZero,0,0,0,0,1,0);
    *(undefined4 *)(param_1 + 0x4a4) = 0;
    *(undefined4 *)(param_1 + 0x480) = 0x3fc00000;
    return;
  }
LAB_0012cb0f:
  (**(code **)(*(int *)(param_1 + 0x444) + 0x178))(param_1);
  return;
}


// WeaponIdle__10CTFSpanner  @ 001278c4
void WeaponIdle__10CTFSpanner(int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x480);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    *(undefined4 *)(param_1 + 0x480) = 0x41480000;
    (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,0,1);
  }
  return;
}


// WeaponIdle__11CTFAssaultC  @ 001263e0
void WeaponIdle__11CTFAssaultC(uint param_1)

{
  float fVar1;
  uint uVar2;
  
  uVar2 = param_1;
  (**(code **)(*(int *)(param_1 + 0x444) + 0x164))(param_1);
  fVar1 = *(float *)(param_1 + 0x480);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    if (*(int *)(param_1 + 0x49c) == 0) {
      uVar2 = UTIL_SharedRandomLong__FUiii(*(undefined4 *)(*(int *)(param_1 + 0x464) + 0x68c),0,1);
      (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,~uVar2 & 1,1);
      *(undefined4 *)(param_1 + 0x480) = 0x41480000;
    }
    else {
      WindDown__11CTFAssaultCb(param_1,uVar2 & 0xffff0000);
    }
  }
  return;
}


// WeaponIdle__12CHandGrenade  @ 000b59d4
void WeaponIdle__12CHandGrenade(int param_1)

{
  int *piVar1;
  float fVar2;
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
  float fStack_14;
  float fStack_10;
  float local_c;
  float local_8;
  float local_4;
  
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x4c4)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(param_1 + 0x4c4) == 0.0) << 0xe) >> 8)) == 0x40) {
    *(float *)(param_1 + 0x4c4) = *gpGlobals;
  }
  fVar2 = *(float *)(param_1 + 0x480);
  if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1) {
    fVar2 = *(float *)(param_1 + 0x4c0);
    if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
      if (*(float *)(param_1 + 0x4c4) <= 0.0) {
        if (*(int *)(*(int *)(param_1 + 0x4a8) * 4 + *(int *)(param_1 + 0x464) + 0x8c4) != 0) {
          lVar6 = (longdouble)(*DAT_001c118c)(0,0x3f800000);
          lVar7 = (longdouble)0.75;
          bVar5 = (byte)(lVar7 < lVar6 |
                         (byte)((ushort)((ushort)(NAN(lVar7) || NAN(lVar6)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar7 == lVar6) << 0xe) >> 8)) == 1;
          if (bVar5) {
            *(undefined4 *)(param_1 + 0x480) = 0x40200000;
          }
          else {
            lVar6 = (longdouble)(*DAT_001c118c)(0x41200000,0x41700000);
            *(float *)(param_1 + 0x480) = (float)lVar6;
          }
          (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,bVar5,0);
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x4c0) = 0;
        if (*(int *)(*(int *)(param_1 + 0x4a8) * 4 + *(int *)(param_1 + 0x464) + 0x8c4) == 0) {
          (**(code **)(*(int *)(param_1 + 0x444) + 0x180))(param_1);
        }
        else {
          (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,7,0);
          lVar6 = (longdouble)(*DAT_001c118c)(0x41200000,0x41700000);
          *(float *)(param_1 + 0x480) = (float)lVar6;
          *(undefined4 *)(param_1 + 0x4c4) = 0xbf800000;
        }
      }
    }
    else {
      iVar4 = **(int **)(param_1 + 0x464);
      fVar2 = *(float *)(iVar4 + 0x74) + *(float *)(iVar4 + 0x68);
      local_8 = *(float *)(iVar4 + 0x78) + *(float *)(iVar4 + 0x6c);
      local_4 = *(float *)(iVar4 + 0x7c) + *(float *)(iVar4 + 0x70);
      if (0.0 <= fVar2) {
        fVar3 = 1.1111112;
      }
      else {
        fVar3 = 0.8888889;
      }
      fStack_10 = fVar3 * fVar2 + -10.0;
      fStack_44 = (90.0 - fStack_10) * 4.0;
      if (500.0 < fStack_44) {
        fStack_44 = 500.0;
      }
      local_c = fStack_10;
      UTIL_MakeVectors__FRC6Vector(&local_c);
      iVar4 = **(int **)(param_1 + 0x464);
      fStack_28 = *(float *)(iVar4 + 8) + *(float *)(iVar4 + 0x174) + gpGlobals[10] * 16.0;
      fStack_24 = *(float *)(iVar4 + 0xc) + *(float *)(iVar4 + 0x178) + gpGlobals[0xb] * 16.0;
      fStack_20 = *(float *)(iVar4 + 0x10) + *(float *)(iVar4 + 0x17c) + gpGlobals[0xc] * 16.0;
      iVar4 = **(int **)(param_1 + 0x464);
      fStack_40 = fStack_44 * gpGlobals[10] + *(float *)(iVar4 + 0x20);
      fStack_3c = fStack_44 * gpGlobals[0xb] + *(float *)(iVar4 + 0x24);
      fStack_38 = fStack_44 * gpGlobals[0xc] + *(float *)(iVar4 + 0x28);
      fStack_10 = (*(float *)(param_1 + 0x4c0) - *gpGlobals) + 3.0;
      fVar2 = fStack_10;
      if (0x3f < (byte)((0.0 < fStack_10 | (byte)((ushort)((ushort)NAN(fStack_10) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fStack_10 == 0.0) << 0xe) >> 8)) - 1)) {
        fVar2 = 0.0;
      }
      fStack_34 = fStack_40;
      fStack_30 = fStack_3c;
      fStack_2c = fStack_38;
      fStack_1c = fStack_28;
      fStack_18 = fStack_24;
      fStack_14 = fStack_20;
      ShootTimed__8CGrenadeP9entvars_sG6VectorT2f
                (**(undefined4 **)(param_1 + 0x464),&fStack_28,&fStack_40,fVar2);
      if ((byte)((500.0 < fStack_44 | (byte)((ushort)((ushort)NAN(fStack_44) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fStack_44 == 500.0) << 0xe) >> 8)) - 1) < 0x40) {
        if ((byte)((1000.0 < fStack_44 | (byte)((ushort)((ushort)NAN(fStack_44) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fStack_44 == 1000.0) << 0xe) >> 8)) - 1) < 0x40) {
          iVar4 = *(int *)(param_1 + 0x444);
          uVar8 = 5;
        }
        else {
          iVar4 = *(int *)(param_1 + 0x444);
          uVar8 = 4;
        }
      }
      else {
        iVar4 = *(int *)(param_1 + 0x444);
        uVar8 = 3;
      }
      (**(code **)(iVar4 + 0x168))(param_1,uVar8,0);
      SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x464),5);
      *(undefined4 *)(param_1 + 0x4c0) = 0;
      *(undefined4 *)(param_1 + 0x478) = 0x3f000000;
      *(undefined4 *)(param_1 + 0x480) = 0x3f000000;
      piVar1 = (int *)(*(int *)(param_1 + 0x4a8) * 4 + *(int *)(param_1 + 0x464) + 0x8c4);
      *piVar1 = *piVar1 + -1;
      if (*(int *)(*(int *)(param_1 + 0x4a8) * 4 + *(int *)(param_1 + 0x464) + 0x8c4) == 0) {
        *(undefined4 *)(param_1 + 0x478) = 0x3f000000;
        *(undefined4 *)(param_1 + 0x47c) = 0x3f000000;
        *(undefined4 *)(param_1 + 0x480) = 0x3f000000;
      }
    }
  }
  return;
}


// WeaponIdle__12CTFAutoRifle  @ 00126ab4
void WeaponIdle__12CTFAutoRifle(int param_1)

{
  float fVar1;
  
  (**(code **)(*(int *)(param_1 + 0x444) + 0x164))(param_1);
  fVar1 = *(float *)(param_1 + 0x480);
  if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
    (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,5,1);
    *(undefined4 *)(param_1 + 0x480) = 0x41480000;
  }
  return;
}


// WeaponIdle__14CTFIncendiaryC  @ 0012aa64
void WeaponIdle__14CTFIncendiaryC(void)

{
  FUN_0012aa6f();
  return;
}


// WeaponIdle__14CTFSniperRifle  @ 0012dfdc
void WeaponIdle__14CTFSniperRifle(int param_1)

{
  float fVar1;
  
  UpdateSpot__14CTFSniperRifle(param_1);
  (**(code **)(*(int *)(param_1 + 0x444) + 0x164))(param_1);
  fVar1 = *(float *)(param_1 + 0x480);
  if ((0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) &&
     ((*(byte *)(*(int *)(param_1 + 0x464) + 0x85) & 8) == 0)) {
    (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,0,1);
    *(undefined4 *)(param_1 + 0x480) = 0x41480000;
  }
  return;
}


// WeaponIdle__15CTFFlamethrower  @ 00129728
void WeaponIdle__15CTFFlamethrower(int param_1)

{
  float fVar1;
  int iVar2;
  
  (**(code **)(*(int *)(param_1 + 0x444) + 0x164))(param_1);
  fVar1 = *(float *)(param_1 + 0x480);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    iVar2 = UTIL_SharedRandomLong__FUiii(*(undefined4 *)(*(int *)(param_1 + 0x464) + 0x68c),0,4);
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 0x480) = 0x41480000;
    }
    else {
      *(undefined4 *)(param_1 + 0x480) = 0x40400000;
    }
    (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,iVar2 == 0,1);
  }
  return;
}


// WeaponIdle__17CBasePlayerWeapon  @ 00121f30
void WeaponIdle__17CBasePlayerWeapon(void)

{
  return;
}


// WeaponIdle__18CTFGrenadeLauncher  @ 00129fa4
void WeaponIdle__18CTFGrenadeLauncher(int param_1)

{
  float fVar1;
  
  (**(code **)(*(int *)(param_1 + 0x444) + 0x164))(param_1);
  fVar1 = *(float *)(param_1 + 0x480);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    return;
  }
  if (*(int *)(param_1 + 0x4b0) == 0) {
    if (*(int *)(param_1 + 0x4a4) == 0) {
      if (0 < *(int *)(*(int *)(param_1 + 0x464) + 0xe4)) goto LAB_0012a02d;
      goto LAB_0012a00c;
    }
  }
  else {
LAB_0012a00c:
    if (*(int *)(param_1 + 0x4a4) == 0) {
      *(undefined4 *)(param_1 + 0x480) = 0x40400000;
      (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,*(undefined4 *)(param_1 + 0x4c8),1);
      return;
    }
  }
  if ((*(int *)(param_1 + 0x4b0) == 6) || (*(int *)(*(int *)(param_1 + 0x464) + 0xe4) < 1)) {
    (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,*(undefined4 *)(param_1 + 0x4d0),1);
    *(undefined4 *)(param_1 + 0x4a4) = 0;
    *(undefined4 *)(param_1 + 0x480) = 0x3fc00000;
    return;
  }
LAB_0012a02d:
  (**(code **)(*(int *)(param_1 + 0x444) + 0x178))(param_1);
  return;
}


// WeaponIdle__6CTFRpg  @ 0012c170
void WeaponIdle__6CTFRpg(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  
  (**(code **)(*(int *)(param_1 + 0x444) + 0x164))(param_1);
  fVar1 = *(float *)(param_1 + 0x480);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    return;
  }
  if (*(int *)(param_1 + 0x4b0) == 0) {
    if (*(int *)(param_1 + 0x4a4) == 0) {
      if (0 < *(int *)(*(int *)(param_1 + 0x464) + 0xe4)) goto LAB_0012c1f9;
      goto LAB_0012c1d8;
    }
  }
  else {
LAB_0012c1d8:
    if (*(int *)(param_1 + 0x4a4) == 0) {
      if (*(int *)(*(int *)(param_1 + 0x464) + 0xb0) != 0) {
        uVar2 = 1;
        if (*(int *)(param_1 + 0x4b0) == 0) {
          uVar2 = 0xb;
        }
        *(undefined4 *)(param_1 + 0x480) = 0x40400000;
        (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,uVar2,1);
        return;
      }
      *(undefined4 *)(param_1 + 0x480) = 0x3f800000;
      return;
    }
  }
  if ((*(int *)(param_1 + 0x4b0) == 4) || (*(int *)(*(int *)(param_1 + 0x464) + 0xe4) < 1)) {
    (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,9,1);
    *(undefined4 *)(param_1 + 0x4a4) = 0;
    *(undefined4 *)(param_1 + 0x480) = 0x3fc00000;
    return;
  }
LAB_0012c1f9:
  (**(code **)(*(int *)(param_1 + 0x444) + 0x178))(param_1);
  return;
}


// WeaponIdle__8CTFKnife  @ 00127b44
void WeaponIdle__8CTFKnife(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  
  fVar1 = *(float *)(param_1 + 0x480);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    *(undefined4 *)(param_1 + 0x480) = 0x40f00000;
    iVar2 = (*DAT_001c1188)(0,1);
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x444);
      uVar3 = 0;
    }
    else {
      if (iVar2 != 1) {
        return;
      }
      iVar2 = *(int *)(param_1 + 0x444);
      uVar3 = 1;
    }
    (**(code **)(iVar2 + 0x168))(param_1,uVar3,1);
  }
  return;
}


// WeaponIdle__8CTFTranq  @ 0012e428
void WeaponIdle__8CTFTranq(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  
  (**(code **)(*(int *)(param_1 + 0x444) + 0x164))(param_1);
  fVar1 = *(float *)(param_1 + 0x480);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    iVar2 = UTIL_SharedRandomLong__FUiii(*(undefined4 *)(*(int *)(param_1 + 0x464) + 0x68c),0,3);
    if (iVar2 == (iVar2 / 3) * 3) {
      uVar3 = 2;
      *(undefined4 *)(param_1 + 0x480) = 0x40440000;
    }
    else if (iVar2 + 1 == ((iVar2 + 1) / 3) * 3) {
      uVar3 = 0;
      *(undefined4 *)(param_1 + 0x480) = 0x40700000;
    }
    else {
      uVar3 = 1;
      *(undefined4 *)(param_1 + 0x480) = 0x40200000;
    }
    (**(code **)(*(int *)(param_1 + 0x444) + 0x168))(param_1,uVar3,1);
  }
  return;
}


