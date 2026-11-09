// WeaponIdle__10CTFMedikit  @ 000fa320
void WeaponIdle__10CTFMedikit(int param_1)

{
  int iVar1;
  longdouble lVar2;
  undefined4 uVar3;
  
  if (*(float *)(param_1 + 0x404) <= *gpGlobals) {
    lVar2 = (longdouble)(*DAT_0017562c)(0x40a00000,0x41200000);
    *(float *)(param_1 + 0x404) = (float)(lVar2 + (longdouble)*gpGlobals);
    iVar1 = (*DAT_00175628)(0,1);
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x3c8);
      uVar3 = 0;
    }
    else {
      if (iVar1 != 1) {
        return;
      }
      iVar1 = *(int *)(param_1 + 0x3c8);
      uVar3 = 1;
    }
    (**(code **)(iVar1 + 0x15c))(param_1,uVar3);
  }
  return;
}


// WeaponIdle__10CTFNailgun  @ 00100860
void WeaponIdle__10CTFNailgun(int param_1)

{
  longdouble lVar1;
  
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x158))(param_1);
  if (*(float *)(param_1 + 0x404) <= *gpGlobals) {
    lVar1 = (longdouble)(*DAT_0017562c)(0x41200000,0x41a00000);
    *(float *)(param_1 + 0x404) = (float)(lVar1 + (longdouble)*gpGlobals);
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,1);
  }
  return;
}


// WeaponIdle__10CTFRailgun  @ 00101050
void WeaponIdle__10CTFRailgun(int param_1)

{
  longdouble lVar1;
  
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x158))(param_1);
  if (*(float *)(param_1 + 0x404) <= *gpGlobals) {
    lVar1 = (longdouble)(*DAT_0017562c)(0x41200000,0x41700000);
    *(float *)(param_1 + 0x404) = (float)(lVar1 + (longdouble)*gpGlobals);
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,0);
  }
  return;
}


// WeaponIdle__10CTFShotgun  @ 001027b0
void WeaponIdle__10CTFShotgun(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  longdouble lVar5;
  
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x158))(param_1);
  fVar1 = *(float *)(param_1 + 0x430);
  if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
     (fVar2 = *gpGlobals,
     (byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1)) {
    iVar3 = (*DAT_00175628)(0,0x1f);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8),3,"weapons/scock1.wav",0x3f800000
               ,0x3f4ccccd,0,iVar3 + 0x5f);
    *(undefined4 *)(param_1 + 0x430) = 0;
  }
  fVar1 = *(float *)(param_1 + 0x404);
  fVar2 = *gpGlobals;
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
    return;
  }
  if (*(int *)(param_1 + 0x410) == 0) {
    if (*(int *)(param_1 + 0x424) == 0) {
      if (*(int *)(param_1 + 0x434) <= *(int *)(*(int *)(param_1 + 1000) + 0xcc)) goto LAB_001028a8;
      goto LAB_00102879;
    }
  }
  else {
LAB_00102879:
    if (*(int *)(param_1 + 0x424) == 0) {
      lVar5 = (longdouble)(*DAT_0017562c)(0,0x3f800000);
      if ((longdouble)0.8 < lVar5) {
        if ((longdouble)0.95 < lVar5) {
          uVar4 = 8;
        }
        else {
          uVar4 = 0;
        }
        fVar1 = 2.2222223;
      }
      else {
        uVar4 = 9;
        fVar1 = 5.0;
      }
      *(float *)(param_1 + 0x404) = fVar1 + *gpGlobals;
      (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,uVar4);
      return;
    }
  }
  if ((*(int *)(param_1 + 0x410) == *(int *)(param_1 + 0x438)) ||
     (*(int *)(*(int *)(param_1 + 1000) + 0xcc) < *(int *)(param_1 + 0x434))) {
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,4);
    iVar3 = (*DAT_00175628)(0,0x1f);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(**(int **)(param_1 + 1000) + 0x1e8),3,"weapons/scock1.wav",0x3f800000
               ,0x3f4ccccd,0,iVar3 + 0x5f);
    *(undefined4 *)(param_1 + 0x424) = 0;
    *(float *)(param_1 + 0x404) = *gpGlobals + 1.5;
    return;
  }
LAB_001028a8:
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x16c))(param_1);
  return;
}


// WeaponIdle__10CTFSpanner  @ 000f9630
void WeaponIdle__10CTFSpanner(int param_1)

{
  longdouble lVar1;
  
  if (*(float *)(param_1 + 0x404) <= *gpGlobals) {
    lVar1 = (longdouble)(*DAT_0017562c)(0x41200000,0x41700000);
    *(float *)(param_1 + 0x404) = (float)(lVar1 + (longdouble)*gpGlobals);
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,0);
  }
  return;
}


// WeaponIdle__11CTFAssaultC  @ 000f8020
void WeaponIdle__11CTFAssaultC(int param_1)

{
  int iVar1;
  longdouble lVar2;
  
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x158))(param_1);
  if (*(float *)(param_1 + 0x404) <= *gpGlobals) {
    if ((*(int *)(param_1 + 0x42c) == 0) ||
       (((*(byte *)(**(int **)(param_1 + 1000) + 0x160) ^ 1) & 1) == 0)) {
      iVar1 = (*DAT_00175628)(0,1);
      (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,iVar1 == 0);
      lVar2 = (longdouble)(*DAT_0017562c)(0x41200000,0x41700000);
      *(float *)(param_1 + 0x404) = (float)(lVar2 + (longdouble)*gpGlobals);
    }
    else {
      WindDown__11CTFAssaultC(param_1);
    }
  }
  return;
}


// WeaponIdle__12CHandGrenade  @ 000bc7f0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WeaponIdle__12CHandGrenade(int param_1)

{
  float fVar1;
  int *piVar2;
  float *pfVar3;
  int iVar4;
  longdouble lVar5;
  longdouble lVar6;
  undefined4 uVar7;
  float local_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x428)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(param_1 + 0x428) == 0.0) << 0xe) >> 8)) == 0x40) {
    *(float *)(param_1 + 0x428) = *gpGlobals;
  }
  if (*(float *)(param_1 + 0x404) <= *gpGlobals) {
    fVar1 = *(float *)(param_1 + 0x424);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      fVar1 = *(float *)(param_1 + 0x428);
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
        *(undefined4 *)(param_1 + 0x424) = 0;
        if (*(int *)(*(int *)(param_1 + 0x408) * 4 + *(int *)(param_1 + 1000) + 0x83c) == 0) {
          (**(code **)(*(int *)(param_1 + 0x3c8) + 0x174))(param_1);
        }
        else {
          (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,7);
          lVar5 = (longdouble)(*DAT_0017562c)(0x41200000,0x41700000);
          *(float *)(param_1 + 0x404) = (float)(lVar5 + (longdouble)*gpGlobals);
          *(undefined4 *)(param_1 + 0x428) = 0xbf800000;
        }
      }
      else if (*(int *)(*(int *)(param_1 + 0x408) * 4 + *(int *)(param_1 + 1000) + 0x83c) != 0) {
        lVar5 = (longdouble)(*DAT_0017562c)(0,0x3f800000);
        if ((longdouble)0.75 < lVar5) {
          local_14 = *gpGlobals + 2.5;
          *(float *)(param_1 + 0x404) = local_14;
        }
        else {
          lVar6 = (longdouble)(*DAT_0017562c)(0x41200000,0x41700000);
          *(float *)(param_1 + 0x404) = (float)(lVar6 + (longdouble)*gpGlobals);
        }
        (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,(longdouble)0.75 < lVar5);
      }
    }
    else {
      iVar4 = **(int **)(param_1 + 1000);
      local_14 = *(float *)(iVar4 + 0x74) + *(float *)(iVar4 + 0x68);
      local_c = *(float *)(iVar4 + 0x78) + *(float *)(iVar4 + 0x6c);
      local_8 = *(float *)(iVar4 + 0x7c) + *(float *)(iVar4 + 0x70);
      if ((byte)(local_14 < 0.0 | (byte)((ushort)((ushort)NAN(local_14) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_14 == 0.0) << 0xe) >> 8)) == 1) {
        local_14 = local_14 * 0.8888889;
      }
      else {
        local_14 = local_14 * 1.1111112;
      }
      local_14 = local_14 + -10.0;
      local_48 = (90.0 - local_14) * 4.0;
      if ((byte)(500.0 < local_48 | (byte)((ushort)((ushort)NAN(local_48) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_48 == 500.0) << 0xe) >> 8)) == 1) {
        local_48 = 500.0;
      }
      local_10 = local_14;
      UTIL_MakeVectors__FRC6Vector(&local_10);
      piVar2 = *(int **)(param_1 + 1000);
      iVar4 = *piVar2;
      local_2c = *(float *)(iVar4 + 8) + *(float *)(iVar4 + 0x154) + gpGlobals[10] * 16.0;
      local_28 = *(float *)(*piVar2 + 0xc) + *(float *)(iVar4 + 0x158) + gpGlobals[0xb] * 16.0;
      local_24 = *(float *)(*piVar2 + 0x10) + *(float *)(iVar4 + 0x15c) + gpGlobals[0xc] * 16.0;
      iVar4 = *piVar2;
      fStack_44 = local_48 * gpGlobals[10] + *(float *)(iVar4 + 0x20);
      fStack_40 = local_48 * gpGlobals[0xb] + *(float *)(iVar4 + 0x24);
      fStack_3c = local_48 * gpGlobals[0xc] + *(float *)(iVar4 + 0x28);
      local_14 = (*(float *)(param_1 + 0x424) - *gpGlobals) + 3.0;
      fVar1 = local_14;
      if (local_14 < 0.0) {
        fVar1 = 0.0;
      }
      local_38 = fStack_44;
      local_34 = fStack_40;
      local_30 = fStack_3c;
      local_20 = local_2c;
      local_1c = local_28;
      local_18 = local_24;
      ShootTimed__8CGrenadeP9entvars_tG6VectorT2f
                (**(undefined4 **)(param_1 + 1000),&local_2c,&fStack_44,fVar1);
      if (500.0 <= local_48) {
        if (_FUN_00133c10 <= local_48) {
          iVar4 = *(int *)(param_1 + 0x3c8);
          uVar7 = 5;
        }
        else {
          iVar4 = *(int *)(param_1 + 0x3c8);
          uVar7 = 4;
        }
      }
      else {
        iVar4 = *(int *)(param_1 + 0x3c8);
        uVar7 = 3;
      }
      (**(code **)(iVar4 + 0x15c))(param_1,uVar7);
      SetAnimation__11CBasePlayer11PLAYER_ANIM(*(undefined4 *)(param_1 + 1000),5);
      *(undefined4 *)(param_1 + 0x424) = 0;
      pfVar3 = gpGlobals;
      *(float *)(param_1 + 0x3fc) = *gpGlobals + 0.5;
      *(float *)(param_1 + 0x404) = *pfVar3 + 0.5;
      piVar2 = (int *)(*(int *)(param_1 + 0x408) * 4 + *(int *)(param_1 + 1000) + 0x83c);
      *piVar2 = *piVar2 + -1;
      if (*(int *)(*(int *)(param_1 + 0x408) * 4 + *(int *)(param_1 + 1000) + 0x83c) == 0) {
        fVar1 = *pfVar3 + 0.5;
        *(float *)(param_1 + 0x3fc) = fVar1;
        *(float *)(param_1 + 0x400) = fVar1;
        *(float *)(param_1 + 0x404) = fVar1;
      }
    }
  }
  return;
}


// WeaponIdle__12CTFAutoRifle  @ 000f8670
void WeaponIdle__12CTFAutoRifle(int param_1)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x158))(param_1);
  fVar1 = *(float *)(param_1 + 0x404);
  fVar2 = *gpGlobals;
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,5);
    lVar3 = (longdouble)(*DAT_0017562c)(0x41200000,0x41700000);
    *(float *)(param_1 + 0x404) = (float)(lVar3 + (longdouble)*gpGlobals);
  }
  return;
}


// WeaponIdle__14CTFIncendiaryC  @ 000ffb00
void WeaponIdle__14CTFIncendiaryC(int param_1)

{
  undefined4 uVar1;
  
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x158))(param_1);
  if (*(float *)(param_1 + 0x404) <= *gpGlobals) {
    if (*(int *)(*(int *)(param_1 + 1000) + 0xe4) < 1) {
      *(float *)(param_1 + 0x404) = *gpGlobals + 1.0;
    }
    else {
      (*DAT_0017562c)(0,0x3f800000);
      uVar1 = 1;
      if (*(int *)(*(int *)(param_1 + 1000) + 0xe4) == 0) {
        uVar1 = 9;
      }
      *(float *)(param_1 + 0x404) = *gpGlobals + 3.0;
      (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,uVar1);
    }
  }
  return;
}


// WeaponIdle__14CTFSniperRifle  @ 00103d20
void WeaponIdle__14CTFSniperRifle(int param_1)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  
  UpdateSpot__14CTFSniperRifle(param_1);
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x158))(param_1);
  fVar1 = *(float *)(param_1 + 0x404);
  fVar2 = *gpGlobals;
  if (((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) &&
     ((*(byte *)(*(int *)(param_1 + 1000) + 0x89) & 8) == 0)) {
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,0);
    lVar3 = (longdouble)(*DAT_0017562c)(0x41200000,0x41700000);
    *(float *)(param_1 + 0x404) = (float)(lVar3 + (longdouble)*gpGlobals);
  }
  return;
}


// WeaponIdle__15CTFFlamethrower  @ 000facd0
void WeaponIdle__15CTFFlamethrower(int param_1)

{
  int iVar1;
  longdouble lVar2;
  
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x158))(param_1);
  if (*(float *)(param_1 + 0x404) <= *gpGlobals) {
    iVar1 = (*DAT_00175628)(0,4);
    if (iVar1 != 0) {
      lVar2 = (longdouble)(*DAT_0017562c)(0x41200000,0x41700000);
      *(float *)(param_1 + 0x404) = (float)(lVar2 + (longdouble)*gpGlobals);
    }
    else {
      *(float *)(param_1 + 0x404) = *gpGlobals + 3.0;
    }
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,iVar1 == 0);
  }
  return;
}


// WeaponIdle__17CBasePlayerWeapon  @ 0011cb40
void WeaponIdle__17CBasePlayerWeapon(void)

{
  return;
}


// WeaponIdle__18CTFGrenadeLauncher  @ 000fbe40
void WeaponIdle__18CTFGrenadeLauncher(int param_1)

{
  float fVar1;
  
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x158))(param_1);
  if (*gpGlobals < *(float *)(param_1 + 0x404)) {
    return;
  }
  if (*(int *)(param_1 + 0x410) == 0) {
    if (*(int *)(param_1 + 0x424) != 0) goto LAB_000fbe9e;
    if (*(int *)(*(int *)(param_1 + 1000) + 0xe4) < 1) goto LAB_000fbe95;
LAB_000fbeb6:
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x16c))(param_1);
  }
  else {
LAB_000fbe95:
    if (*(int *)(param_1 + 0x424) == 0) {
      if (0 < *(int *)(*(int *)(param_1 + 1000) + 0xe4)) {
        *(float *)(param_1 + 0x404) = *gpGlobals + 3.0;
        (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,*(undefined4 *)(param_1 + 0x438));
        return;
      }
      fVar1 = *gpGlobals + 1.0;
    }
    else {
LAB_000fbe9e:
      if ((*(int *)(param_1 + 0x410) != 6) && (0 < *(int *)(*(int *)(param_1 + 1000) + 0xe4)))
      goto LAB_000fbeb6;
      (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,*(undefined4 *)(param_1 + 0x440));
      *(undefined4 *)(param_1 + 0x424) = 0;
      fVar1 = *gpGlobals + 1.5;
    }
    *(float *)(param_1 + 0x404) = fVar1;
  }
  return;
}


// WeaponIdle__6CTFRpg  @ 00101ce0
void WeaponIdle__6CTFRpg(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x158))(param_1);
  if (*gpGlobals < *(float *)(param_1 + 0x404)) {
    return;
  }
  if (*(int *)(param_1 + 0x410) == 0) {
    if (*(int *)(param_1 + 0x424) != 0) goto LAB_00101d3e;
    if (*(int *)(*(int *)(param_1 + 1000) + 0xe4) < 1) goto LAB_00101d35;
LAB_00101d56:
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x16c))(param_1);
  }
  else {
LAB_00101d35:
    if (*(int *)(param_1 + 0x424) == 0) {
      if (*(int *)(*(int *)(param_1 + 1000) + 0xb0) != 0) {
        (*DAT_0017562c)(0,0x3f800000);
        uVar2 = 1;
        if (*(int *)(param_1 + 0x410) == 0) {
          uVar2 = 0xb;
        }
        *(float *)(param_1 + 0x404) = *gpGlobals + 3.0;
        (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,uVar2);
        return;
      }
      fVar1 = *gpGlobals + 1.0;
    }
    else {
LAB_00101d3e:
      if ((*(int *)(param_1 + 0x410) != 4) && (0 < *(int *)(*(int *)(param_1 + 1000) + 0xe4)))
      goto LAB_00101d56;
      (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,9);
      *(undefined4 *)(param_1 + 0x424) = 0;
      fVar1 = *gpGlobals + 1.5;
    }
    *(float *)(param_1 + 0x404) = fVar1;
  }
  return;
}


// WeaponIdle__8CTFKnife  @ 000f9820
void WeaponIdle__8CTFKnife(int param_1)

{
  int iVar1;
  longdouble lVar2;
  undefined4 uVar3;
  
  if (*(float *)(param_1 + 0x404) <= *gpGlobals) {
    lVar2 = (longdouble)(*DAT_0017562c)(0x40a00000,0x41200000);
    *(float *)(param_1 + 0x404) = (float)(lVar2 + (longdouble)*gpGlobals);
    iVar1 = (*DAT_00175628)(0,1);
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x3c8);
      uVar3 = 0;
    }
    else {
      if (iVar1 != 1) {
        return;
      }
      iVar1 = *(int *)(param_1 + 0x3c8);
      uVar3 = 1;
    }
    (**(code **)(iVar1 + 0x15c))(param_1,uVar3);
  }
  return;
}


// WeaponIdle__8CTFTranq  @ 00104120
void WeaponIdle__8CTFTranq(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  (**(code **)(*(int *)(param_1 + 0x3c8) + 0x158))(param_1);
  if (*(float *)(param_1 + 0x404) <= *gpGlobals) {
    lVar3 = (longdouble)(*DAT_0017562c)(0,0x3f800000);
    if ((longdouble)0.3 < lVar3) {
      if ((longdouble)0.6 < lVar3) {
        uVar2 = 1;
        fVar1 = 2.5;
      }
      else {
        uVar2 = 0;
        fVar1 = 3.75;
      }
    }
    else {
      uVar2 = 2;
      fVar1 = 3.0625;
    }
    *(float *)(param_1 + 0x404) = fVar1 + *gpGlobals;
    (**(code **)(*(int *)(param_1 + 0x3c8) + 0x15c))(param_1,uVar2);
  }
  return;
}


