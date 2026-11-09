// CheckLocalMove__12CBaseMonsterRC6VectorT1P11CBaseEntityPf  @ 000c2c90
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char CheckLocalMove__12CBaseMonsterRC6VectorT1P11CBaseEntityPf
               (int *param_1,float *param_2,float *param_3,int *param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  byte bVar6;
  int iVar5;
  char cVar7;
  longdouble lVar8;
  float local_2c;
  float local_1c;
  float local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar5 = *param_1;
  local_10 = *(undefined4 *)(iVar5 + 8);
  local_c = *(undefined4 *)(iVar5 + 0xc);
  local_8 = *(undefined4 *)(iVar5 + 0x10);
  local_1c = *param_3 - *param_2;
  local_18 = param_3[1] - param_2[1];
  local_14 = param_3[2] - param_2[2];
  lVar8 = (longdouble)UTIL_VecToYaw__FRC6Vector(&local_1c);
  local_1c = *param_3 - *param_2;
  local_18 = param_3[1] - param_2[1];
  local_14 = param_3[2] - param_2[2];
  fVar1 = SQRT(local_18 * local_18 + local_1c * local_1c);
  cVar7 = '\x02';
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,param_2);
  if ((*(byte *)(*param_1 + 0x184) & 3) == 0) {
    (*DAT_00175528)(*(undefined4 *)(*param_1 + 0x1e8));
  }
  local_2c = 0.0;
  bVar6 = 0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
          (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8);
  do {
    if (bVar6 != 1) {
LAB_000c2e0d:
      if (((cVar7 == '\x02') && ((*(byte *)(*param_1 + 0x184) & 3) == 0)) &&
         ((param_4 == (int *)0x0 || ((*(byte *)(*param_4 + 0x185) & 2) != 0)))) {
        fVar1 = ABS(param_3[2] - *(float *)(*param_1 + 0x10));
        fVar2 = (float)_FUN_00135b40;
        if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) {
          cVar7 = '\x01';
        }
      }
      UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,&local_10);
      return cVar7;
    }
    fVar2 = local_2c + 16.0;
    fVar4 = fVar1 - 1.0;
    fVar3 = 16.0;
    if ((byte)((fVar4 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar2)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar4 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
      fVar3 = (fVar1 - local_2c) - 1.0;
    }
    iVar5 = (*DAT_0017552c)(*(undefined4 *)(*param_1 + 0x1e8),(float)lVar8,fVar3,2);
    if (iVar5 == 0) {
      if (param_5 != (float *)0x0) {
        *param_5 = local_2c;
      }
      cVar7 = '\0';
      if (param_4 != (int *)0x0) {
        cVar7 = (*(int *)(*param_4 + 0x1e8) == *(int *)(gpGlobals + 0x74)) * '\x02';
      }
      goto LAB_000c2e0d;
    }
    local_2c = local_2c + 16.0;
    bVar6 = local_2c < fVar1 | (byte)((ushort)((ushort)(NAN(local_2c) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_2c == fVar1) << 0xe) >> 8);
  } while( true );
}


