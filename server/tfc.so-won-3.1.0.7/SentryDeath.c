// SentryDeath__7CSentry  @ 001190d8
void SentryDeath__7CSentry(int *param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  longdouble lVar4;
  longdouble lVar5;
  undefined1 auStack_1c [12];
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float local_4;
  
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  local_4 = *gpGlobals + 0.1;
  *(float *)(*param_1 + 0x104) = local_4;
  if (*(int *)(*param_1 + 0x170) != 2) {
    *(undefined4 *)(*param_1 + 0x170) = 2;
    lVar4 = (longdouble)(*DAT_001c118c)(0,0x3f800000);
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
    iVar2 = (*DAT_001c1188)(0,2);
    lVar4 = (longdouble)UTIL_AngleMod__Ff((float)(iVar2 * 0x78) + *(float *)(*param_1 + 0x54));
    *(float *)(*param_1 + 0x54) = (float)lVar4;
    (**(code **)(param_1[0x111] + 0x228))(param_1);
  }
  (**(code **)(param_1[0x111] + 0x22c))(param_1);
  GetAttachment__14CBaseAnimatingiR6VectorT2(param_1,1,&fStack_10,auStack_1c);
  lVar5 = (longdouble)(*DAT_001c118c)(0,0x40000000);
  lVar5 = lVar5 + (longdouble)*(float *)(*param_1 + 0x1e4);
  lVar4 = (longdouble)*gpGlobals;
  if (0x3f < (byte)((lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) - 1)) {
    (*DAT_001c10d8)(0,0x17,0,0);
    (*DAT_001c10e0)(5);
    lVar4 = (longdouble)(*DAT_001c118c)(0xc1800000,0x41800000);
    (*DAT_001c10f4)((float)(lVar4 + (longdouble)fStack_10));
    lVar4 = (longdouble)(*DAT_001c118c)(0xc1800000,0x41800000);
    (*DAT_001c10f4)((float)(lVar4 + (longdouble)fStack_c));
    (*DAT_001c10f4)(fStack_8 - 32.0);
    (*DAT_001c10e8)((int)g_sModelIndexSmoke);
    (*DAT_001c10e0)(0xf);
    (*DAT_001c10e0)(8);
    (*DAT_001c10dc)();
  }
  lVar5 = (longdouble)(*DAT_001c118c)(0,0x41000000);
  lVar5 = lVar5 + (longdouble)*(float *)(*param_1 + 0x1e4);
  lVar4 = (longdouble)*gpGlobals;
  if (0x3f < (byte)((lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) - 1)) {
    UTIL_Sparks__FRC6Vector(&fStack_10);
  }
  if ((param_1[0x117] != 0) && (*(float *)(*param_1 + 0x1e4) + 5.0 < *gpGlobals)) {
    *(undefined4 *)(*param_1 + 0x138) = 0;
    param_1[3] = 0;
    param_1[4] = 0;
  }
  return;
}


