// CheckLocalMove__12CBaseMonsterRC6VectorT1P11CBaseEntityPf  @ 000b0c1c
char CheckLocalMove__12CBaseMonsterRC6VectorT1P11CBaseEntityPf
               (int *param_1,float *param_2,float *param_3,int *param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  int iVar3;
  char cVar4;
  longdouble lVar5;
  float local_28;
  float local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar3 = *param_1;
  local_c = *(undefined4 *)(iVar3 + 8);
  local_8 = *(undefined4 *)(iVar3 + 0xc);
  local_4 = *(undefined4 *)(iVar3 + 0x10);
  local_18 = *param_3 - *param_2;
  local_14 = param_3[1] - param_2[1];
  local_10 = param_3[2] - param_2[2];
  lVar5 = (longdouble)UTIL_VecToYaw__FRC6Vector(&local_18);
  local_18 = *param_3 - *param_2;
  local_14 = param_3[1] - param_2[1];
  local_10 = param_3[2] - param_2[2];
  fVar2 = SQRT(local_14 * local_14 + local_18 * local_18);
  cVar4 = '\x02';
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,param_2);
  if ((*(byte *)(*param_1 + 0x1a4) & 3) == 0) {
    (*DAT_001a7ea8)(*(undefined4 *)(*param_1 + 0x208));
  }
  local_28 = 0.0;
  if (0.0 < fVar2) {
    do {
      fVar1 = 16.0;
      if (fVar2 - 1.0 <= local_28 + 16.0) {
        fVar1 = (fVar2 - local_28) - 1.0;
      }
      iVar3 = (*DAT_001a7eac)(*(undefined4 *)(*param_1 + 0x208),(float)lVar5,fVar1,2);
      if (iVar3 == 0) {
        if (param_5 != (float *)0x0) {
          *param_5 = local_28;
        }
        cVar4 = '\0';
        if (param_4 != (int *)0x0) {
          cVar4 = (*(int *)(*param_4 + 0x208) == *(int *)(gpGlobals + 0x74)) * '\x02';
        }
        break;
      }
      local_28 = local_28 + 16.0;
    } while ((byte)(local_28 < fVar2 |
                    (byte)((ushort)((ushort)(NAN(local_28) || NAN(fVar2)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(local_28 == fVar2) << 0xe) >> 8)) == 1);
  }
  if ((((cVar4 == '\x02') && ((*(byte *)(*param_1 + 0x1a4) & 3) == 0)) &&
      ((param_4 == (int *)0x0 || ((*(byte *)(*param_4 + 0x1a5) & 2) != 0)))) &&
     (64.0 < ABS(param_3[2] - *(float *)(*param_1 + 0x10)))) {
    cVar4 = '\x01';
  }
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,&local_c);
  return cVar4;
}


