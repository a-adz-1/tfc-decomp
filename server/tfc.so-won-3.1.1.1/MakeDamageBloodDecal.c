// MakeDamageBloodDecal__12CBaseMonsterifP11TraceResultRC6Vector  @ 000bfb50
void MakeDamageBloodDecal__12CBaseMonsterifP11TraceResultRC6Vector
               (int *param_1,int param_2,float param_3,int param_4,float *param_5)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  longdouble lVar4;
  longdouble lVar5;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  undefined1 auStack_3c [16];
  float fStack_2c;
  
  iVar2 = (**(code **)(param_1[0x115] + 0x8c))(param_1);
  if (iVar2 == 0) {
    fVar1 = *(float *)(*param_1 + 0x1b0);
    if ((byte)((fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
      return;
    }
    *(float *)(*param_1 + 0x1b0) = fVar1 - 1.0;
  }
  iVar2 = 0;
  if (0 < param_2) {
    fVar1 = -param_3;
    do {
      fStack_48 = *param_5;
      fStack_44 = param_5[1];
      fStack_40 = param_5[2];
      lVar4 = (longdouble)(*DAT_0019f80c)(fVar1,param_3);
      fStack_48 = (float)(lVar4 + (longdouble)fStack_48);
      lVar4 = (longdouble)(*DAT_0019f80c)(fVar1,param_3);
      fStack_44 = (float)(lVar4 + (longdouble)fStack_44);
      lVar5 = (longdouble)(*DAT_0019f80c)(fVar1,param_3);
      lVar4 = (longdouble)fStack_40;
      fStack_40 = (float)(lVar5 + lVar4);
      fStack_54 = fStack_48 * 172.0 + *(float *)(param_4 + 0x14);
      fStack_50 = fStack_44 * 172.0 + *(float *)(param_4 + 0x18);
      fStack_4c = (float)((lVar5 + lVar4) * (longdouble)172.0 +
                         (longdouble)*(float *)(param_4 + 0x1c));
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (param_4 + 0x14,&fStack_54,1,*(undefined4 *)(*param_1 + 0x208),auStack_3c);
      if ((byte)(1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
                (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) != 0x40) {
        uVar3 = (**(code **)(param_1[0x115] + 0x44))(param_1);
        UTIL_BloodDecalTrace__FP11TraceResulti(auStack_3c,uVar3);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_2);
  }
  return;
}


