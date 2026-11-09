// TurretDeath__11CBaseTurret  @ 00115570
void TurretDeath__11CBaseTurret(int *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  longdouble lVar5;
  longdouble lVar6;
  char *pcVar7;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  local_8 = *gpGlobals + 0.1;
  *(float *)(*param_1 + 0xe4) = local_8;
  if (*(int *)(*param_1 + 0x150) != 2) {
    *(undefined4 *)(*param_1 + 0x150) = 2;
    lVar5 = (longdouble)(*DAT_0017562c)(0,0x3f800000);
    if ((longdouble)0.33 < lVar5) {
      if ((longdouble)0.66 < lVar5) {
        uVar3 = *(undefined4 *)(*param_1 + 0x1e8);
        pcVar7 = "turret/tu_die3.wav";
      }
      else {
        uVar3 = *(undefined4 *)(*param_1 + 0x1e8);
        pcVar7 = "turret/tu_die2.wav";
      }
    }
    else {
      uVar3 = *(undefined4 *)(*param_1 + 0x1e8);
      pcVar7 = "turret/tu_die.wav";
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar3,4,pcVar7,0x3f800000,0x3f4ccccd,0,100);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),6,"turret/tu_active2.wav",0,0,0x20,100);
    if (param_1[0x18d] == 0) {
      param_1[0x19b] = -0x3e900000;
    }
    else {
      param_1[0x19b] = -0x3d4c0000;
    }
    SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,5);
    (**(code **)(param_1[0xf2] + 0x220))(param_1);
  }
  (**(code **)(param_1[0xf2] + 0x224))(param_1);
  lVar5 = (longdouble)(*DAT_0017562c)(0,0x40000000);
  if ((longdouble)*gpGlobals < lVar5 + (longdouble)*(float *)(*param_1 + 0x1c4)) {
    (*DAT_00175578)(0,0x17,0,0);
    (*DAT_00175580)(5);
    lVar5 = (longdouble)
            (*DAT_0017562c)(*(undefined4 *)(*param_1 + 0xa4),*(undefined4 *)(*param_1 + 0xb0));
    (*DAT_00175594)((float)lVar5);
    lVar5 = (longdouble)
            (*DAT_0017562c)(*(undefined4 *)(*param_1 + 0xa8),*(undefined4 *)(*param_1 + 0xb4));
    (*DAT_00175594)((float)lVar5);
    (*DAT_00175594)(*(float *)(*param_1 + 0x10) - (float)(param_1[0x18d] << 6));
    (*DAT_00175588)((int)g_sModelIndexSmoke);
    (*DAT_00175580)(0x19);
    (*DAT_00175580)(param_1[0x18d] * -5 + 10);
    (*DAT_0017557c)();
  }
  lVar5 = (longdouble)(*DAT_0017562c)(0,0x40a00000);
  iVar4 = *param_1;
  if ((longdouble)*gpGlobals < lVar5 + (longdouble)*(float *)(iVar4 + 0x1c4)) {
    lVar5 = (longdouble)(*DAT_0017562c)(*(undefined4 *)(iVar4 + 0xa4),*(undefined4 *)(iVar4 + 0xb0))
    ;
    lVar6 = (longdouble)
            (*DAT_0017562c)(*(undefined4 *)(*param_1 + 0xa8),*(undefined4 *)(*param_1 + 0xb4));
    local_10 = (float)lVar6;
    local_c = 0.0;
    local_14 = (float)lVar5;
    if (param_1[0x18d] == 0) {
      lVar5 = (longdouble)
              (*DAT_0017562c)(*(undefined4 *)(*param_1 + 0x10),*(undefined4 *)(*param_1 + 0xb8));
      local_c = local_c + (float)lVar5;
    }
    else {
      lVar5 = (longdouble)
              (*DAT_0017562c)(*(undefined4 *)(*param_1 + 0xac),*(undefined4 *)(*param_1 + 0x10));
      local_c = local_c + (float)lVar5;
    }
    local_10 = local_10 + 0.0;
    local_14 = local_14 + 0.0;
    UTIL_Sparks__FRC6Vector(&local_14);
  }
  if (param_1[0xf8] != 0) {
    iVar4 = MoveTurret__11CBaseTurret(param_1);
    if (iVar4 == 0) {
      fVar2 = *(float *)(*param_1 + 0x1c4) + 5.0;
      fVar1 = *gpGlobals;
      if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) {
        *(undefined4 *)(*param_1 + 0x118) = 0;
        param_1[3] = 0;
        param_1[4] = 0;
      }
    }
  }
  return;
}


