// SentryDeath__7CSentry  @ 00116280
void SentryDeath__7CSentry(int *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  longdouble lVar5;
  char *pcVar6;
  undefined1 local_20 [12];
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
        pcVar6 = "turret/tu_die3.wav";
      }
      else {
        uVar3 = *(undefined4 *)(*param_1 + 0x1e8);
        pcVar6 = "turret/tu_die2.wav";
      }
    }
    else {
      uVar3 = *(undefined4 *)(*param_1 + 0x1e8);
      pcVar6 = "turret/tu_die.wav";
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar3,4,pcVar6,0x3f800000,0x3f4ccccd,0,100);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x1e8),6,"turret/tu_active2.wav",0,0,0x20,100);
    SetBoneController__14CBaseAnimatingif(param_1,0,0);
    SetBoneController__14CBaseAnimatingif(param_1,1,0);
    SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,5);
    *(undefined4 *)(*param_1 + 0xec) = 0;
    iVar4 = (*DAT_00175628)(0,2);
    lVar5 = (longdouble)UTIL_AngleMod__Ff((float)(iVar4 * 0x78) + *(float *)(*param_1 + 0x54));
    *(float *)(*param_1 + 0x54) = (float)lVar5;
    (**(code **)(param_1[0xf2] + 0x220))(param_1);
  }
  (**(code **)(param_1[0xf2] + 0x224))(param_1);
  GetAttachment__14CBaseAnimatingiR6VectorT2(param_1,1,&local_14,local_20);
  lVar5 = (longdouble)(*DAT_0017562c)(0,0x40000000);
  if ((longdouble)*gpGlobals < lVar5 + (longdouble)*(float *)(*param_1 + 0x1c4)) {
    (*DAT_00175578)(0,0x17,0,0);
    (*DAT_00175580)(5);
    lVar5 = (longdouble)(*DAT_0017562c)(0xc1800000,0x41800000);
    (*DAT_00175594)((float)(lVar5 + (longdouble)local_14));
    lVar5 = (longdouble)(*DAT_0017562c)(0xc1800000,0x41800000);
    (*DAT_00175594)((float)(lVar5 + (longdouble)local_10));
    (*DAT_00175594)(local_c - 32.0);
    (*DAT_00175588)((int)g_sModelIndexSmoke);
    (*DAT_00175580)(0xf);
    (*DAT_00175580)(8);
    (*DAT_0017557c)();
  }
  lVar5 = (longdouble)(*DAT_0017562c)(0,0x41000000);
  if ((longdouble)*gpGlobals < lVar5 + (longdouble)*(float *)(*param_1 + 0x1c4)) {
    UTIL_Sparks__FRC6Vector(&local_14);
  }
  if (param_1[0xf8] != 0) {
    fVar2 = *(float *)(*param_1 + 0x1c4) + 5.0;
    fVar1 = *gpGlobals;
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) {
      *(undefined4 *)(*param_1 + 0x118) = 0;
      param_1[3] = 0;
      param_1[4] = 0;
    }
  }
  return;
}


