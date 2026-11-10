// WeaponIdle__10CTFMedikit  @ 00118cb4
void WeaponIdle__10CTFMedikit(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  
  fVar1 = *(float *)(param_1 + 0x410);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    *(undefined4 *)(param_1 + 0x410) = 0x40f00000;
    iVar2 = (*DAT_001a7fa8)(0,1);
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x3d4);
      uVar3 = 0;
    }
    else {
      if (iVar2 != 1) {
        return;
      }
      iVar2 = *(int *)(param_1 + 0x3d4);
      uVar3 = 1;
    }
    (**(code **)(iVar2 + 0x160))(param_1,uVar3,1);
  }
  return;
}


// WeaponIdle__10CTFNailgun  @ 0011ac8c
void WeaponIdle__10CTFNailgun(int param_1)

{
  float fVar1;
  
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x15c))(param_1);
  fVar1 = *(float *)(param_1 + 0x410);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    *(undefined4 *)(param_1 + 0x410) = 0x41700000;
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,1,1);
  }
  return;
}


// WeaponIdle__10CTFRailgun  @ 0011b4ec
void WeaponIdle__10CTFRailgun(int param_1)

{
  float fVar1;
  
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x15c))(param_1);
  fVar1 = *(float *)(param_1 + 0x410);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    *(undefined4 *)(param_1 + 0x410) = 0x41480000;
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,0,1);
  }
  return;
}


// WeaponIdle__10CTFShotgun  @ 0011c4cc
void WeaponIdle__10CTFShotgun(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x15c))(param_1);
  fVar1 = *(float *)(param_1 + 0x418);
  if (((byte)(1000.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 1000.0) << 0xe) >> 8)) != 0x40) &&
     (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1))) {
    (*DAT_001a802c)(1,*(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0x208),
                    *(undefined2 *)(param_1 + 0x45e),0,&g_vecZero,&g_vecZero,0,0,0,0,0,0);
    *(undefined4 *)(param_1 + 0x418) = 0x447a0000;
  }
  fVar1 = *(float *)(param_1 + 0x410);
  if ((byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    return;
  }
  if (*(int *)(param_1 + 0x440) == 0) {
    if (*(int *)(param_1 + 0x434) == 0) {
      if (*(int *)(param_1 + 0x454) <= *(int *)(*(int *)(param_1 + 0x3f4) + 0xcc))
      goto LAB_0011c5e7;
      goto LAB_0011c5b8;
    }
  }
  else {
LAB_0011c5b8:
    if (*(int *)(param_1 + 0x434) == 0) {
      iVar2 = UTIL_SharedRandomLong__FUiii
                        (*(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x61c),0,0x14);
      if (iVar2 == (iVar2 / 5) * 5) {
        if (iVar2 == (iVar2 / 0x14) * 0x14) {
          uVar3 = 0;
          *(undefined4 *)(param_1 + 0x410) = 0x400e38e4;
        }
        else {
          uVar3 = 8;
          *(undefined4 *)(param_1 + 0x410) = 0x4006bca2;
        }
      }
      else {
        uVar3 = 9;
        *(undefined4 *)(param_1 + 0x410) = 0x40a00000;
      }
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,uVar3,1);
      return;
    }
  }
  if ((*(int *)(param_1 + 0x440) == *(int *)(param_1 + 0x458)) ||
     (*(int *)(*(int *)(param_1 + 0x3f4) + 0xcc) < *(int *)(param_1 + 0x454))) {
    (*DAT_001a802c)(1,*(undefined4 *)(**(int **)(param_1 + 0x3f4) + 0x208),
                    *(undefined2 *)(param_1 + 0x45e),0,&g_vecZero,&g_vecZero,0,0,0,0,1,0);
    *(undefined4 *)(param_1 + 0x434) = 0;
    *(undefined4 *)(param_1 + 0x410) = 0x3fc00000;
    return;
  }
LAB_0011c5e7:
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x170))(param_1);
  return;
}


// WeaponIdle__10CTFSpanner  @ 00117b00
void WeaponIdle__10CTFSpanner(int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x410);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    *(undefined4 *)(param_1 + 0x410) = 0x41480000;
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,0,1);
  }
  return;
}


// WeaponIdle__11CTFAssaultC  @ 001166a8
void WeaponIdle__11CTFAssaultC(int param_1)

{
  float fVar1;
  uint uVar2;
  
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x15c))(param_1);
  fVar1 = *(float *)(param_1 + 0x410);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    if (*(int *)(param_1 + 0x42c) == 0) {
      uVar2 = UTIL_SharedRandomLong__FUiii(*(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x61c),0,1);
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,~uVar2 & 1,1);
      *(undefined4 *)(param_1 + 0x410) = 0x41480000;
    }
    else {
      WindDown__11CTFAssaultC(param_1);
    }
  }
  return;
}


// WeaponIdle__12CHandGrenade  @ 000aa954
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
  float local_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float local_28;
  float local_24;
  float local_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x454)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(param_1 + 0x454) == 0.0) << 0xe) >> 8)) == 0x40) {
    *(float *)(param_1 + 0x454) = *gpGlobals;
  }
  fVar2 = *(float *)(param_1 + 0x410);
  if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) != 1) {
    fVar2 = *(float *)(param_1 + 0x450);
    if ((byte)(0.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
      if (*(float *)(param_1 + 0x454) <= 0.0) {
        if (*(int *)(*(int *)(param_1 + 0x438) * 4 + *(int *)(param_1 + 0x3f4) + 0x850) != 0) {
          lVar6 = (longdouble)(*DAT_001a7fac)(0,0x3f800000);
          lVar7 = (longdouble)0.75;
          bVar5 = (byte)(lVar7 < lVar6 |
                         (byte)((ushort)((ushort)(NAN(lVar7) || NAN(lVar6)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar7 == lVar6) << 0xe) >> 8)) == 1;
          if (bVar5) {
            *(undefined4 *)(param_1 + 0x410) = 0x40200000;
          }
          else {
            lVar6 = (longdouble)(*DAT_001a7fac)(0x41200000,0x41700000);
            *(float *)(param_1 + 0x410) = (float)lVar6;
          }
          (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,bVar5,0);
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x450) = 0;
        if (*(int *)(*(int *)(param_1 + 0x438) * 4 + *(int *)(param_1 + 0x3f4) + 0x850) == 0) {
          (**(code **)(*(int *)(param_1 + 0x3d4) + 0x178))(param_1);
        }
        else {
          (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,7,0);
          lVar6 = (longdouble)(*DAT_001a7fac)(0x41200000,0x41700000);
          *(float *)(param_1 + 0x410) = (float)lVar6;
          *(undefined4 *)(param_1 + 0x454) = 0xbf800000;
        }
      }
    }
    else {
      iVar4 = **(int **)(param_1 + 0x3f4);
      fVar2 = *(float *)(iVar4 + 0x74) + *(float *)(iVar4 + 0x68);
      local_8 = *(float *)(iVar4 + 0x78) + *(float *)(iVar4 + 0x6c);
      local_4 = *(float *)(iVar4 + 0x7c) + *(float *)(iVar4 + 0x70);
      if (0.0 <= fVar2) {
        fVar3 = 1.1111112;
      }
      else {
        fVar3 = 0.8888889;
      }
      local_10 = fVar3 * fVar2 + -10.0;
      local_44 = (90.0 - local_10) * 4.0;
      if (500.0 < local_44) {
        local_44 = 500.0;
      }
      local_c = local_10;
      UTIL_MakeVectors__FRC6Vector(&local_c);
      iVar4 = **(int **)(param_1 + 0x3f4);
      local_28 = *(float *)(iVar4 + 8) + *(float *)(iVar4 + 0x174) + gpGlobals[10] * 16.0;
      local_24 = *(float *)(iVar4 + 0xc) + *(float *)(iVar4 + 0x178) + gpGlobals[0xb] * 16.0;
      local_20 = *(float *)(iVar4 + 0x10) + *(float *)(iVar4 + 0x17c) + gpGlobals[0xc] * 16.0;
      iVar4 = **(int **)(param_1 + 0x3f4);
      fStack_40 = local_44 * gpGlobals[10] + *(float *)(iVar4 + 0x20);
      fStack_3c = local_44 * gpGlobals[0xb] + *(float *)(iVar4 + 0x24);
      fStack_38 = local_44 * gpGlobals[0xc] + *(float *)(iVar4 + 0x28);
      local_10 = (*(float *)(param_1 + 0x450) - *gpGlobals) + 3.0;
      fVar2 = local_10;
      if (0x3f < (byte)((0.0 < local_10 | (byte)((ushort)((ushort)NAN(local_10) << 10) >> 8) |
                        (byte)((ushort)((ushort)(local_10 == 0.0) << 0xe) >> 8)) - 1)) {
        fVar2 = 0.0;
      }
      fStack_34 = fStack_40;
      fStack_30 = fStack_3c;
      fStack_2c = fStack_38;
      fStack_1c = local_28;
      fStack_18 = local_24;
      fStack_14 = local_20;
      ShootTimed__8CGrenadeP9entvars_sG6VectorT2f
                (**(undefined4 **)(param_1 + 0x3f4),&local_28,&fStack_40,fVar2);
      if ((byte)((500.0 < local_44 | (byte)((ushort)((ushort)NAN(local_44) << 10) >> 8) |
                 (byte)((ushort)((ushort)(local_44 == 500.0) << 0xe) >> 8)) - 1) < 0x40) {
        if ((byte)((1000.0 < local_44 | (byte)((ushort)((ushort)NAN(local_44) << 10) >> 8) |
                   (byte)((ushort)((ushort)(local_44 == 1000.0) << 0xe) >> 8)) - 1) < 0x40) {
          iVar4 = *(int *)(param_1 + 0x3d4);
          uVar8 = 5;
        }
        else {
          iVar4 = *(int *)(param_1 + 0x3d4);
          uVar8 = 4;
        }
      }
      else {
        iVar4 = *(int *)(param_1 + 0x3d4);
        uVar8 = 3;
      }
      (**(code **)(iVar4 + 0x160))(param_1,uVar8,0);
      SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 0x3f4),5);
      *(undefined4 *)(param_1 + 0x450) = 0;
      *(undefined4 *)(param_1 + 0x408) = 0x3f000000;
      *(undefined4 *)(param_1 + 0x410) = 0x3f000000;
      piVar1 = (int *)(*(int *)(param_1 + 0x438) * 4 + *(int *)(param_1 + 0x3f4) + 0x850);
      *piVar1 = *piVar1 + -1;
      if (*(int *)(*(int *)(param_1 + 0x438) * 4 + *(int *)(param_1 + 0x3f4) + 0x850) == 0) {
        *(undefined4 *)(param_1 + 0x408) = 0x3f000000;
        *(undefined4 *)(param_1 + 0x40c) = 0x3f000000;
        *(undefined4 *)(param_1 + 0x410) = 0x3f000000;
      }
    }
  }
  return;
}


// WeaponIdle__12CTFAutoRifle  @ 00116d38
void WeaponIdle__12CTFAutoRifle(int param_1)

{
  float fVar1;
  
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x15c))(param_1);
  fVar1 = *(float *)(param_1 + 0x410);
  if (0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) {
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,5,1);
    *(undefined4 *)(param_1 + 0x410) = 0x41480000;
  }
  return;
}


// WeaponIdle__14CTFIncendiaryC  @ 0011a660
void WeaponIdle__14CTFIncendiaryC(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x15c))(param_1);
  fVar1 = *(float *)(param_1 + 0x410);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    if (*(int *)(*(int *)(param_1 + 0x3f4) + 0xe4) < 1) {
      *(undefined4 *)(param_1 + 0x410) = 0x3f800000;
    }
    else {
      uVar2 = 1;
      if (*(int *)(*(int *)(param_1 + 0x3f4) + 0xe4) == 0) {
        uVar2 = 9;
      }
      *(undefined4 *)(param_1 + 0x410) = 0x40400000;
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,uVar2,1);
    }
  }
  return;
}


// WeaponIdle__14CTFSniperRifle  @ 0011da34
void WeaponIdle__14CTFSniperRifle(int param_1)

{
  float fVar1;
  
  UpdateSpot__14CTFSniperRifle(param_1);
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x15c))(param_1);
  fVar1 = *(float *)(param_1 + 0x410);
  if ((0x3f < (byte)((0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1)) &&
     ((*(byte *)(*(int *)(param_1 + 0x3f4) + 0x85) & 8) == 0)) {
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,0,1);
    *(undefined4 *)(param_1 + 0x410) = 0x41480000;
  }
  return;
}


// WeaponIdle__15CTFFlamethrower  @ 001193c0
void WeaponIdle__15CTFFlamethrower(int param_1)

{
  float fVar1;
  int iVar2;
  
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x15c))(param_1);
  fVar1 = *(float *)(param_1 + 0x410);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    iVar2 = UTIL_SharedRandomLong__FUiii(*(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x61c),0,4);
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 0x410) = 0x41480000;
    }
    else {
      *(undefined4 *)(param_1 + 0x410) = 0x40400000;
    }
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,iVar2 == 0,1);
  }
  return;
}


// WeaponIdle__17CBasePlayerWeapon  @ 001123a0
void WeaponIdle__17CBasePlayerWeapon(void)

{
  return;
}


// WeaponIdle__18CTFGrenadeLauncher  @ 00119c04
void WeaponIdle__18CTFGrenadeLauncher(int param_1)

{
  float fVar1;
  
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x15c))(param_1);
  fVar1 = *(float *)(param_1 + 0x410);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    return;
  }
  if (*(int *)(param_1 + 0x440) == 0) {
    if (*(int *)(param_1 + 0x434) == 0) {
      if (0 < *(int *)(*(int *)(param_1 + 0x3f4) + 0xe4)) goto LAB_00119c8d;
      goto LAB_00119c6c;
    }
  }
  else {
LAB_00119c6c:
    if (*(int *)(param_1 + 0x434) == 0) {
      *(undefined4 *)(param_1 + 0x410) = 0x40400000;
      (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,*(undefined4 *)(param_1 + 0x458),1);
      return;
    }
  }
  if ((*(int *)(param_1 + 0x440) == 6) || (*(int *)(*(int *)(param_1 + 0x3f4) + 0xe4) < 1)) {
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,*(undefined4 *)(param_1 + 0x460),1);
    *(undefined4 *)(param_1 + 0x434) = 0;
    *(undefined4 *)(param_1 + 0x410) = 0x3fc00000;
    return;
  }
LAB_00119c8d:
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x170))(param_1);
  return;
}


// WeaponIdle__6CTFRpg  @ 0011bc88
void WeaponIdle__6CTFRpg(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x15c))(param_1);
  fVar1 = *(float *)(param_1 + 0x410);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
    return;
  }
  if (*(int *)(param_1 + 0x440) == 0) {
    if (*(int *)(param_1 + 0x434) == 0) {
      if (0 < *(int *)(*(int *)(param_1 + 0x3f4) + 0xe4)) goto LAB_0011bd11;
      goto LAB_0011bcf0;
    }
  }
  else {
LAB_0011bcf0:
    if (*(int *)(param_1 + 0x434) == 0) {
      if (*(int *)(*(int *)(param_1 + 0x3f4) + 0xb0) != 0) {
        uVar2 = 1;
        if (*(int *)(param_1 + 0x440) == 0) {
          uVar2 = 0xb;
        }
        *(undefined4 *)(param_1 + 0x410) = 0x40400000;
        (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,uVar2,1);
        return;
      }
      *(undefined4 *)(param_1 + 0x410) = 0x3f800000;
      return;
    }
  }
  if ((*(int *)(param_1 + 0x440) == 4) || (*(int *)(*(int *)(param_1 + 0x3f4) + 0xe4) < 1)) {
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,9,1);
    *(undefined4 *)(param_1 + 0x434) = 0;
    *(undefined4 *)(param_1 + 0x410) = 0x3fc00000;
    return;
  }
LAB_0011bd11:
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x170))(param_1);
  return;
}


// WeaponIdle__8CTFKnife  @ 00117d6c
void WeaponIdle__8CTFKnife(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  
  fVar1 = *(float *)(param_1 + 0x410);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    *(undefined4 *)(param_1 + 0x410) = 0x40f00000;
    iVar2 = (*DAT_001a7fa8)(0,1);
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x3d4);
      uVar3 = 0;
    }
    else {
      if (iVar2 != 1) {
        return;
      }
      iVar2 = *(int *)(param_1 + 0x3d4);
      uVar3 = 1;
    }
    (**(code **)(iVar2 + 0x160))(param_1,uVar3,1);
  }
  return;
}


// WeaponIdle__8CTFTranq  @ 0011de48
void WeaponIdle__8CTFTranq(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  
  (**(code **)(*(int *)(param_1 + 0x3d4) + 0x15c))(param_1);
  fVar1 = *(float *)(param_1 + 0x410);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 1) {
    iVar2 = UTIL_SharedRandomLong__FUiii(*(undefined4 *)(*(int *)(param_1 + 0x3f4) + 0x61c),0,3);
    if (iVar2 == (iVar2 / 3) * 3) {
      uVar3 = 2;
      *(undefined4 *)(param_1 + 0x410) = 0x40440000;
    }
    else if (iVar2 + 1 == ((iVar2 + 1) / 3) * 3) {
      uVar3 = 0;
      *(undefined4 *)(param_1 + 0x410) = 0x40700000;
    }
    else {
      uVar3 = 1;
      *(undefined4 *)(param_1 + 0x410) = 0x40200000;
    }
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x160))(param_1,uVar3,1);
  }
  return;
}


