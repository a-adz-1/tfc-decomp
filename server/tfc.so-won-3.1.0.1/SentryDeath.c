// SentryDeath__7CSentry  @ 0010960c
void SentryDeath__7CSentry(int *param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  longdouble lVar4;
  longdouble lVar5;
  undefined1 local_1c [12];
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  local_4 = *gpGlobals + 0.1;
  *(float *)(*param_1 + 0x104) = local_4;
  if (*(int *)(*param_1 + 0x170) != 2) {
    *(undefined4 *)(*param_1 + 0x170) = 2;
    lVar4 = (longdouble)(*DAT_001a7fac)(0,0x3f800000);
    lVar5 = (longdouble)0.33;
    if ((byte)(lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) == 1) {
      lVar5 = (longdouble)0.66;
      if ((byte)(lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8) |
                (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) == 1) {
        uVar3 = *(undefined4 *)(*param_1 + 0x208);
        pcVar1 = "turret/tu_die3.wav";
      }
      else {
        uVar3 = *(undefined4 *)(*param_1 + 0x208);
        pcVar1 = "turret/tu_die2.wav";
      }
    }
    else {
      uVar3 = *(undefined4 *)(*param_1 + 0x208);
      pcVar1 = "turret/tu_die.wav";
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar3,4,pcVar1,0x3f800000,0x3f4ccccd,0,100);
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),6,"turret/tu_active2.wav",0,0,0x20,100);
    SetBoneController__14CBaseAnimatingif(param_1,0,0);
    SetBoneController__14CBaseAnimatingif(param_1,1,0);
    SetTurretAnim__11CBaseTurret11TURRET_ANIM(param_1,5);
    *(undefined4 *)(*param_1 + 0x10c) = 0;
    iVar2 = (*DAT_001a7fa8)(0,2);
    lVar4 = (longdouble)UTIL_AngleMod__Ff((float)(iVar2 * 0x78) + *(float *)(*param_1 + 0x54));
    *(float *)(*param_1 + 0x54) = (float)lVar4;
    (**(code **)(param_1[0xf5] + 0x220))(param_1);
  }
  (**(code **)(param_1[0xf5] + 0x224))(param_1);
  GetAttachment__14CBaseAnimatingiR6VectorT2(param_1,1,&local_10,local_1c);
  lVar5 = (longdouble)(*DAT_001a7fac)(0,0x40000000);
  lVar5 = lVar5 + (longdouble)*(float *)(*param_1 + 0x1e4);
  lVar4 = (longdouble)*gpGlobals;
  if (0x3f < (byte)((lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) - 1)) {
    (*DAT_001a7ef8)(0,0x17,0,0);
    (*DAT_001a7f00)(5);
    lVar4 = (longdouble)(*DAT_001a7fac)(0xc1800000,0x41800000);
    (*DAT_001a7f14)((float)(lVar4 + (longdouble)local_10));
    lVar4 = (longdouble)(*DAT_001a7fac)(0xc1800000,0x41800000);
    (*DAT_001a7f14)((float)(lVar4 + (longdouble)local_c));
    (*DAT_001a7f14)(local_8 - 32.0);
    (*DAT_001a7f08)((int)g_sModelIndexSmoke);
    (*DAT_001a7f00)(0xf);
    (*DAT_001a7f00)(8);
    (*DAT_001a7efc)();
  }
  lVar5 = (longdouble)(*DAT_001a7fac)(0,0x41000000);
  lVar5 = lVar5 + (longdouble)*(float *)(*param_1 + 0x1e4);
  lVar4 = (longdouble)*gpGlobals;
  if (0x3f < (byte)((lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) - 1)) {
    UTIL_Sparks__FRC6Vector(&local_10);
  }
  if ((param_1[0xfb] != 0) && (*(float *)(*param_1 + 0x1e4) + 5.0 < *gpGlobals)) {
    *(undefined4 *)(*param_1 + 0x138) = 0;
    param_1[3] = 0;
    param_1[4] = 0;
  }
  return;
}


