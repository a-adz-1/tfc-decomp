// FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_s  @ 000bf110
void FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_s
               (int *param_1,uint param_2,float *param_3,float *param_4,float *param_5,float param_6
               ,undefined4 param_7,int param_8,int param_9,int param_10)

{
  float fVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  longdouble lVar7;
  longdouble lVar8;
  undefined4 uStack_e8;
  uint local_d0;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [16];
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  int local_c;
  
  local_48 = *(float *)(gpGlobals + 0x40);
  local_44 = *(float *)(gpGlobals + 0x44);
  local_40 = *(float *)(gpGlobals + 0x48);
  local_54 = *(float *)(gpGlobals + 0x34);
  local_50 = *(float *)(gpGlobals + 0x38);
  local_4c = *(float *)(gpGlobals + 0x3c);
  if (param_10 == 0) {
    param_10 = *param_1;
  }
  ClearMultiDamage__Fv();
  DAT_001ad488 = 0x1002;
  local_d0 = 1;
  if (param_2 != 0) {
    do {
      do {
        lVar4 = (longdouble)(*DAT_0019f80c)(0xbf000000,0x3f000000);
        lVar5 = (longdouble)(*DAT_0019f80c)(0xbf000000,0x3f000000);
        lVar6 = (longdouble)(*DAT_0019f80c)(0xbf000000,0x3f000000);
        lVar7 = (longdouble)(*DAT_0019f80c)(0xbf000000,0x3f000000);
        lVar6 = lVar6 + lVar7;
        lVar7 = (longdouble)(float)(lVar4 + lVar5);
        lVar8 = lVar6 * lVar6 + lVar7 * lVar7;
        lVar7 = (longdouble)1;
      } while ((byte)(lVar7 < lVar8 |
                      (byte)((ushort)((ushort)(NAN(lVar7) || NAN(lVar8)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(lVar7 == lVar8) << 0xe) >> 8)) == 1);
      lVar7 = (longdouble)(float)(lVar4 + lVar5) * (longdouble)*param_5;
      lVar6 = lVar6 * (longdouble)param_5[1];
      lVar4 = (longdouble)local_48 * lVar7 + (longdouble)*param_4 + (longdouble)local_54 * lVar6;
      lVar5 = (longdouble)local_44 * lVar7 + (longdouble)param_4[1] + (longdouble)local_50 * lVar6;
      lVar7 = lVar7 * (longdouble)local_40 + (longdouble)param_4[2] + lVar6 * (longdouble)local_4c;
      local_60 = (float)lVar4;
      lVar4 = lVar4 * (longdouble)param_6;
      local_5c = (float)lVar5;
      lVar5 = lVar5 * (longdouble)param_6;
      local_58 = (float)lVar7;
      lVar7 = lVar7 * (longdouble)param_6;
      local_6c = (float)lVar4;
      local_68 = (float)lVar5;
      local_64 = (float)lVar7;
      local_84 = (float)(lVar4 + (longdouble)*param_3);
      local_80 = (float)(lVar5 + (longdouble)param_3[1]);
      local_7c = (float)(lVar7 + (longdouble)param_3[2]);
      local_78 = local_84;
      local_74 = local_80;
      local_70 = local_7c;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (param_3,&local_84,0,*(undefined4 *)(*param_1 + 0x208),local_3c);
      if ((param_8 != 0) &&
         (iVar2 = tracerCount_825 % param_8, tracerCount_825 = tracerCount_825 + 1, iVar2 == 0)) {
        if ((*(byte *)(*param_1 + 0x1a4) & 8) == 0) {
          local_78 = *param_3;
          local_74 = param_3[1];
          local_70 = param_3[2];
        }
        else {
          local_78 = *param_3 + *(float *)(gpGlobals + 0x40) + *(float *)(gpGlobals + 0x40) +
                     *(float *)(gpGlobals + 0x28) * 16.0;
          local_74 = param_3[1] + *(float *)(gpGlobals + 0x44) + *(float *)(gpGlobals + 0x44) +
                     *(float *)(gpGlobals + 0x2c) * 16.0;
          local_70 = param_3[2] + -4.0 + *(float *)(gpGlobals + 0x48) + *(float *)(gpGlobals + 0x48)
                     + *(float *)(gpGlobals + 0x30) * 16.0;
          local_6c = local_78;
          local_68 = local_74;
          local_64 = local_70;
        }
        switch(param_7) {
        case 2:
        case 6:
          break;
        default:
          (*DAT_0019f758)(5,0x17,&local_78,0);
          (*DAT_0019f760)(6);
          (*DAT_0019f774)(local_78);
          (*DAT_0019f774)(local_74);
          (*DAT_0019f774)(local_70);
          (*DAT_0019f774)(local_28);
          (*DAT_0019f774)(local_24);
          (*DAT_0019f774)(local_20);
          (*DAT_0019f75c)();
        }
      }
      if ((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
                (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) != 0x40) {
        iVar2 = local_c;
        if ((local_c == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(iVar2 + 0x7c);
        }
        if (param_9 == 0) {
          switch(param_7) {
          case 0:
            local_78 = local_60;
            local_74 = local_5c;
            local_70 = local_58;
            (**(code **)(*(int *)(iVar2 + 0x454) + 0x34))
                      (iVar2,param_10,0x42480000,&local_78,local_3c,0x80);
            goto LAB_000bf883;
          default:
            iVar3 = *(int *)(iVar2 + 0x454);
            uStack_e8 = 2;
            fVar1 = DAT_001a1ccc;
            break;
          case 2:
            local_78 = local_60;
            local_74 = local_5c;
            local_70 = local_58;
            FUN_000bf838(DAT_001a1cd4,&local_78,local_3c,2);
            return;
          case 3:
            local_78 = local_60;
            local_74 = local_5c;
            local_70 = local_58;
            FUN_000bf838(DAT_001a1cd0,&local_78,local_3c,2);
            return;
          case 4:
            iVar3 = *(int *)(iVar2 + 0x454);
            uStack_e8 = 2;
            fVar1 = DAT_001a1cdc;
            break;
          case 8:
            iVar3 = *(int *)(iVar2 + 0x454);
            uStack_e8 = 2;
            fVar1 = DAT_001a1d08;
            break;
          case 9:
            local_78 = local_60;
            local_74 = local_5c;
            local_70 = local_58;
            FUN_000bf838(DAT_001a1d0c,&local_78,local_3c,2);
            return;
          case 10:
            iVar3 = *(int *)(iVar2 + 0x454);
            uStack_e8 = 2;
            fVar1 = DAT_001a1d10;
          }
        }
        else {
          fVar1 = (float)param_9;
          if (param_2 < 2) {
            local_78 = local_60;
            local_74 = local_5c;
            local_70 = local_58;
            uStack_e8 = 0x1002;
            if (0x10 < param_9) {
              uStack_e8 = 0x2002;
            }
            FUN_000bf838(fVar1,&local_78,local_3c,uStack_e8);
            return;
          }
          iVar3 = *(int *)(iVar2 + 0x454);
          uStack_e8 = 0x1002;
          if (0x10 < param_9) {
            uStack_e8 = 0x2002;
          }
        }
        local_70 = local_58;
        local_74 = local_5c;
        local_78 = local_60;
        (**(code **)(iVar3 + 0x34))(iVar2,param_10,fVar1,&local_78,local_3c,uStack_e8);
      }
LAB_000bf883:
      if (local_d0 == 1) {
        local_78 = *param_3;
        local_74 = param_3[1];
        local_70 = param_3[2];
        local_6c = local_28;
        local_68 = local_24;
        local_64 = local_20;
        UTIL_BubbleTrail__FG6VectorT0i
                  (&local_78,&local_6c,(int)ROUND(param_6 * local_2c * 0.00390625));
      }
      local_d0 = local_d0 + 1;
    } while (local_d0 <= param_2);
  }
  ApplyMultiDamage__FP9entvars_sT0(*param_1,param_10);
  return;
}


