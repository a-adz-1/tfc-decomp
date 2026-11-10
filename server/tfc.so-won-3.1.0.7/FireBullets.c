// FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_s  @ 000bf89c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_s
               (int *param_1,uint param_2,float *param_3,float *param_4,float *param_5,float param_6
               ,undefined4 param_7,int param_8,int param_9,int param_10)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  longdouble lVar7;
  longdouble lVar8;
  float fVar9;
  undefined4 local_dc;
  uint local_cc;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float local_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  undefined1 local_38 [16];
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  int iStack_8;
  
  local_44 = *(float *)(gpGlobals + 0x40);
  local_40 = *(float *)(gpGlobals + 0x44);
  local_3c = *(float *)(gpGlobals + 0x48);
  local_50 = *(float *)(gpGlobals + 0x34);
  local_4c = *(float *)(gpGlobals + 0x38);
  local_48 = *(float *)(gpGlobals + 0x3c);
  if (param_10 == 0) {
    param_10 = *param_1;
  }
  ClearMultiDamage__Fv();
  DAT_001cede8 = 0x1002;
  local_cc = 1;
  if (param_2 != 0) {
    do {
      do {
        lVar4 = (longdouble)(*DAT_001c118c)(0xbf000000,0x3f000000);
        lVar5 = (longdouble)(*DAT_001c118c)(0xbf000000,0x3f000000);
        lVar6 = (longdouble)(*DAT_001c118c)(0xbf000000,0x3f000000);
        lVar7 = (longdouble)(*DAT_001c118c)(0xbf000000,0x3f000000);
        lVar7 = (longdouble)(float)lVar6 + lVar7;
        lVar6 = (longdouble)(float)(lVar5 + (longdouble)(float)lVar4);
        lVar8 = lVar7 * lVar7 + lVar6 * lVar6;
        lVar6 = (longdouble)1.0;
      } while ((byte)(lVar6 < lVar8 |
                      (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar8)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(lVar6 == lVar8) << 0xe) >> 8)) == 1);
      fVar9 = (float)(lVar5 + (longdouble)(float)lVar4) * *param_5;
      lVar7 = lVar7 * (longdouble)param_5[1];
      fStack_54 = param_4[2] + fVar9 * local_3c + (float)(lVar7 * (longdouble)local_48);
      fStack_5c = (float)((longdouble)(*param_4 + fVar9 * local_44) + lVar7 * (longdouble)local_50);
      fStack_58 = (float)((longdouble)(param_4[1] + fVar9 * local_40) + lVar7 * (longdouble)local_4c
                         );
      fStack_68 = param_6 * fStack_5c;
      fStack_64 = param_6 * fStack_58;
      fStack_60 = param_6 * fStack_54;
      fStack_80 = *param_3 + fStack_68;
      fStack_7c = param_3[1] + fStack_64;
      fStack_78 = param_3[2] + fStack_60;
      local_74 = fStack_80;
      fStack_70 = fStack_7c;
      fStack_6c = fStack_78;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                (param_3,&fStack_80,0,*(undefined4 *)(*param_1 + 0x208),local_38);
      if ((param_8 != 0) &&
         (iVar1 = tracerCount_823 % param_8, tracerCount_823 = tracerCount_823 + 1, iVar1 == 0)) {
        if ((*(byte *)(*param_1 + 0x1a4) & 8) == 0) {
          local_74 = *param_3;
          fStack_70 = param_3[1];
          fStack_6c = param_3[2];
        }
        else {
          local_74 = *param_3 + *(float *)(gpGlobals + 0x40) + *(float *)(gpGlobals + 0x40) +
                     *(float *)(gpGlobals + 0x28) * 16.0;
          fStack_70 = param_3[1] + *(float *)(gpGlobals + 0x44) + *(float *)(gpGlobals + 0x44) +
                      *(float *)(gpGlobals + 0x2c) * 16.0;
          fStack_6c = param_3[2] + -4.0 +
                      *(float *)(gpGlobals + 0x48) + *(float *)(gpGlobals + 0x48) +
                      *(float *)(gpGlobals + 0x30) * 16.0;
          fStack_68 = local_74;
          fStack_64 = fStack_70;
          fStack_60 = fStack_6c;
        }
        switch(param_7) {
        case 2:
        case 6:
          break;
        default:
          (*DAT_001c10d8)(5,0x17,&local_74,0);
          (*DAT_001c10e0)(6);
          (*DAT_001c10f4)(local_74);
          (*DAT_001c10f4)(fStack_70);
          (*DAT_001c10f4)(fStack_6c);
          (*DAT_001c10f4)(fStack_24);
          (*DAT_001c10f4)(fStack_20);
          (*DAT_001c10f4)(fStack_1c);
          (*DAT_001c10dc)();
        }
      }
      if ((byte)(1.0 < fStack_28 | (byte)((ushort)((ushort)NAN(fStack_28) << 10) >> 8) |
                (byte)((ushort)((ushort)(fStack_28 == 1.0) << 0xe) >> 8)) == 0x40)
      goto LAB_000c025c;
      iVar1 = iStack_8;
      if ((iStack_8 == 0) && (iVar1 = (*DAT_001c1134)(0), iVar1 == 0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0x7c);
      }
      if (param_9 != 0) {
        if (param_2 < 2) {
          iVar2 = *(int *)(iVar1 + 0x444);
          local_dc = 0x1002;
          if (0x10 < param_9) {
            local_dc = 0x2002;
          }
          fVar9 = (float)param_9;
          goto LAB_000c0198;
        }
        iVar2 = *(int *)(iVar1 + 0x444);
        local_dc = 0x1002;
        if (0x10 < param_9) {
          local_dc = 0x2002;
        }
        fVar9 = (float)param_9;
        goto LAB_000c01f4;
      }
      switch(param_7) {
      case 0:
        local_dc = 0x80;
        fVar9 = 50.0;
        pcVar3 = *(code **)(*(int *)(iVar1 + 0x444) + 0x34);
        goto LAB_000c0257;
      default:
        iVar2 = *(int *)(iVar1 + 0x444);
        local_dc = 2;
        fVar9 = _DAT_001c362c;
        break;
      case 2:
        iVar2 = *(int *)(iVar1 + 0x444);
        local_dc = 2;
        fVar9 = _DAT_001c3634;
        goto LAB_000c0198;
      case 3:
        iVar2 = *(int *)(iVar1 + 0x444);
        local_dc = 2;
        fVar9 = _DAT_001c3630;
        goto LAB_000c0198;
      case 4:
        iVar2 = *(int *)(iVar1 + 0x444);
        local_dc = 2;
        fVar9 = _DAT_001c363c;
        break;
      case 8:
        iVar2 = *(int *)(iVar1 + 0x444);
        local_dc = 2;
        fVar9 = _DAT_001c3668;
        break;
      case 9:
        iVar2 = *(int *)(iVar1 + 0x444);
        local_dc = 2;
        fVar9 = _DAT_001c366c;
LAB_000c0198:
        fStack_6c = fStack_54;
        fStack_70 = fStack_58;
        local_74 = fStack_5c;
        (**(code **)(iVar2 + 0x34))(iVar1,param_10,fVar9,&local_74,local_38,local_dc);
        goto LAB_000c025c;
      case 10:
        iVar2 = *(int *)(iVar1 + 0x444);
        local_dc = 2;
        fVar9 = _DAT_001c3670;
      }
LAB_000c01f4:
      pcVar3 = *(code **)(iVar2 + 0x34);
LAB_000c0257:
      fStack_6c = fStack_54;
      fStack_70 = fStack_58;
      local_74 = fStack_5c;
      (*pcVar3)(iVar1,param_10,fVar9,&local_74,local_38,local_dc);
LAB_000c025c:
      if (local_cc == 1) {
        local_74 = *param_3;
        fStack_70 = param_3[1];
        fStack_6c = param_3[2];
        fStack_68 = fStack_24;
        fStack_64 = fStack_20;
        fStack_60 = fStack_1c;
        UTIL_BubbleTrail__FG6VectorT0i
                  (&local_74,&fStack_68,(int)ROUND(param_6 * fStack_28 * 0.00390625));
      }
      local_cc = local_cc + 1;
    } while (local_cc <= param_2);
  }
  ApplyMultiDamage__FP9entvars_sT0(*param_1,param_10);
  return;
}


