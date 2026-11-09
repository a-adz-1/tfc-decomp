// TraceBleed__11CBaseEntityfG6VectorP11TraceResulti  @ 000c6940
void TraceBleed__11CBaseEntityfG6VectorP11TraceResulti
               (int *param_1,float param_2,float *param_3,int param_4,uint param_5)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  longdouble lVar5;
  float local_64;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  undefined1 auStack_3c [16];
  float fStack_2c;
  
  iVar2 = (**(code **)(param_1[0xf2] + 0x40))(param_1);
  if (((iVar2 != -1) &&
      ((byte)(param_2 < 0.0 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_2 == 0.0) << 0xe) >> 8)) != 0x40)) &&
     ((param_5 & 0x8000c7) != 0)) {
    if (10.0 <= param_2) {
      if (25.0 <= param_2) {
        local_64 = 0.3;
        iVar2 = 4;
      }
      else {
        local_64 = 0.2;
        iVar2 = 2;
      }
    }
    else {
      local_64 = 0.1;
      iVar2 = 1;
    }
    iVar4 = 0;
    if (iVar2 != 0) {
      fVar1 = -local_64;
      do {
        fStack_54 = *param_3 * -1.0;
        fStack_50 = param_3[1] * -1.0;
        fStack_4c = param_3[2] * -1.0;
        fStack_48 = fStack_54;
        fStack_44 = fStack_50;
        fStack_40 = fStack_4c;
        lVar5 = (longdouble)(*DAT_0017562c)(fVar1,local_64);
        fStack_48 = (float)(lVar5 + (longdouble)fStack_48);
        lVar5 = (longdouble)(*DAT_0017562c)(fVar1,local_64);
        fStack_44 = (float)(lVar5 + (longdouble)fStack_44);
        lVar5 = (longdouble)(*DAT_0017562c)(fVar1,local_64);
        fStack_40 = (float)(lVar5 + (longdouble)fStack_40);
        fStack_54 = *(float *)(param_4 + 0x14) + fStack_48 * -172.0;
        fStack_50 = *(float *)(param_4 + 0x18) + fStack_44 * -172.0;
        fStack_4c = *(float *)(param_4 + 0x1c) + fStack_40 * -172.0;
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (param_4 + 0x14,&fStack_54,1,*(undefined4 *)(*param_1 + 0x1e8),auStack_3c);
        if ((byte)(1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) != 0x40) {
          uVar3 = (**(code **)(param_1[0xf2] + 0x40))(param_1);
          UTIL_BloodDecalTrace__FP11TraceResulti(auStack_3c,uVar3);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar2);
    }
  }
  return;
}


