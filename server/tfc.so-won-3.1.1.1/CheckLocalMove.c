// CheckLocalMove__12CBaseMonsterRC6VectorT1P11CBaseEntityPf  @ 000bc5b0
char CheckLocalMove__12CBaseMonsterRC6VectorT1P11CBaseEntityPf
               (int *param_1,float *param_2,float *param_3,int *param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  char cVar5;
  longdouble lVar6;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar4 = *param_1;
  uStack_10 = *(undefined4 *)(iVar4 + 8);
  uStack_c = *(undefined4 *)(iVar4 + 0xc);
  uStack_8 = *(undefined4 *)(iVar4 + 0x10);
  fStack_1c = *param_3 - *param_2;
  fStack_18 = param_3[1] - param_2[1];
  fStack_14 = param_3[2] - param_2[2];
  lVar6 = (longdouble)UTIL_VecToYaw__FRC6Vector(&fStack_1c);
  fStack_1c = *param_3 - *param_2;
  fStack_18 = param_3[1] - param_2[1];
  fStack_14 = param_3[2] - param_2[2];
  fVar2 = SQRT(fStack_18 * fStack_18 + fStack_1c * fStack_1c);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,param_2);
  cVar5 = '\x02';
  if ((*(byte *)(*param_1 + 0x1a4) & 3) == 0) {
    (*DAT_0019f708)(*(undefined4 *)(*param_1 + 0x208));
  }
  fVar3 = 0.0;
  if (0.0 < fVar2) {
    do {
      fVar1 = 16.0;
      if (fVar2 - 1.0 <= fVar3 + 16.0) {
        fVar1 = (fVar2 - fVar3) - 1.0;
      }
      iVar4 = (*DAT_0019f70c)(*(undefined4 *)(*param_1 + 0x208),(float)lVar6,fVar1,2);
      if (iVar4 == 0) {
        if (param_5 != (float *)0x0) {
          *param_5 = fVar3;
        }
        cVar5 = '\0';
        if (param_4 != (int *)0x0) {
          cVar5 = (*(int *)(*param_4 + 0x208) == *(int *)(gpGlobals + 0x74)) * '\x02';
        }
        break;
      }
      fVar3 = fVar3 + 16.0;
    } while ((byte)(fVar3 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) == 1);
  }
  iVar4 = *param_1;
  if ((((cVar5 == '\x02') && ((*(byte *)(iVar4 + 0x1a4) & 3) == 0)) &&
      ((param_4 == (int *)0x0 || ((*(byte *)(*param_4 + 0x1a5) & 2) != 0)))) &&
     (64.0 < ABS(param_3[2] - *(float *)(iVar4 + 0x10)))) {
    cVar5 = '\x01';
  }
  UTIL_SetOrigin__FP9entvars_sRC6Vector(iVar4,&uStack_10);
  return cVar5;
}


