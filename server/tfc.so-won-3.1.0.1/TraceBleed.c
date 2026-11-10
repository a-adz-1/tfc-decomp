// TraceBleed__11CBaseEntityfG6VectorP11TraceResulti  @ 000b50dc
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void TraceBleed__11CBaseEntityfG6VectorP11TraceResulti
               (int *param_1,float param_2,float *param_3,int param_4,uint param_5)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  longdouble lVar5;
  float local_60;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  undefined1 local_38 [16];
  float local_28;
  
  iVar2 = (**(code **)(param_1[0xf5] + 0x40))(param_1);
  if (((iVar2 != -1) &&
      ((byte)(param_2 < 0.0 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_2 == 0.0) << 0xe) >> 8)) != 0x40)) &&
     ((param_5 & 0x8000c7) != 0)) {
    if ((byte)((10.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
               (byte)((ushort)((ushort)(param_2 == 10.0) << 0xe) >> 8)) - 1) < 0x40) {
      if ((byte)((25.0 < param_2 | (byte)((ushort)((ushort)NAN(param_2) << 10) >> 8) |
                 (byte)((ushort)((ushort)(param_2 == 25.0) << 0xe) >> 8)) - 1) < 0x40) {
        local_60 = 0.3;
        iVar2 = 4;
      }
      else {
        local_60 = 0.2;
        iVar2 = 2;
      }
    }
    else {
      local_60 = 0.1;
      iVar2 = 1;
    }
    iVar4 = 0;
    if (iVar2 != 0) {
      fVar1 = -local_60;
      do {
        local_50 = *param_3 * -1.0;
        local_4c = param_3[1] * -1.0;
        local_48 = param_3[2] * -1.0;
        local_44 = local_50;
        local_40 = local_4c;
        local_3c = local_48;
        lVar5 = (longdouble)(*DAT_001a7fac)(fVar1,local_60);
        local_44 = (float)(lVar5 + (longdouble)local_44);
        lVar5 = (longdouble)(*DAT_001a7fac)(fVar1,local_60);
        local_40 = (float)(lVar5 + (longdouble)local_40);
        lVar5 = (longdouble)(*DAT_001a7fac)(fVar1,local_60);
        local_3c = (float)(lVar5 + (longdouble)local_3c);
        local_50 = *(float *)(param_4 + 0x14) + local_44 * -172.0;
        local_4c = *(float *)(param_4 + 0x18) + local_40 * -172.0;
        local_48 = *(float *)(param_4 + 0x1c) + local_3c * -172.0;
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (param_4 + 0x14,&local_50,1,*(undefined4 *)(*param_1 + 0x208),local_38);
        if ((byte)(1.0 < local_28 | (byte)((ushort)((ushort)NAN(local_28) << 10) >> 8) |
                  (byte)((ushort)((ushort)(local_28 == 1.0) << 0xe) >> 8)) != 0x40) {
          uVar3 = (**(code **)(param_1[0xf5] + 0x40))(param_1);
          UTIL_BloodDecalTrace__FP11TraceResulti(local_38,uVar3);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar2);
    }
  }
  return;
}


