// MakeDamageBloodDecal__12CBaseMonsterifP11TraceResultRC6Vector  @ 000c6b30
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void MakeDamageBloodDecal__12CBaseMonsterifP11TraceResultRC6Vector
               (int *param_1,int param_2,float param_3,int param_4,float *param_5)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  longdouble lVar4;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [16];
  float local_2c;
  
  iVar2 = (**(code **)(param_1[0xf2] + 0x88))(param_1);
  if (iVar2 == 0) {
    iVar2 = *param_1;
    if (*(float *)(iVar2 + 400) <= 0.0) {
      return;
    }
    *(float *)(iVar2 + 400) = *(float *)(iVar2 + 400) - 1.0;
  }
  iVar2 = 0;
  if (0 < param_2) {
    fVar1 = -param_3;
    do {
      local_48 = *param_5;
      local_44 = param_5[1];
      local_40 = param_5[2];
      lVar4 = (longdouble)(*DAT_0017562c)(fVar1,param_3);
      local_48 = (float)(lVar4 + (longdouble)local_48);
      lVar4 = (longdouble)(*DAT_0017562c)(fVar1,param_3);
      local_44 = (float)(lVar4 + (longdouble)local_44);
      lVar4 = (longdouble)(*DAT_0017562c)(fVar1,param_3);
      local_40 = (float)(lVar4 + (longdouble)local_40);
      local_54 = *(float *)(param_4 + 0x14) + local_48 * 172.0;
      local_50 = *(float *)(param_4 + 0x18) + local_44 * 172.0;
      local_4c = *(float *)(param_4 + 0x1c) + local_40 * 172.0;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (param_4 + 0x14,&local_54,1,*(undefined4 *)(*param_1 + 0x1e8),local_3c);
      if ((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) != 0x40) {
        uVar3 = (**(code **)(param_1[0xf2] + 0x40))(param_1);
        UTIL_BloodDecalTrace__FP11TraceResulti(local_3c,uVar3);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_2);
  }
  return;
}


