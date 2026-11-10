// TargetDistance__12CTalkMonster  @ 000f76f4
longdouble TargetDistance__12CTalkMonster(int *param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  
  piVar6 = param_1 + 0x141;
  iVar5 = __opP11CBaseEntity__7EHANDLE(piVar6);
  if (iVar5 != 0) {
    iVar5 = __rf__7EHANDLE(piVar6);
    iVar5 = (**(code **)(*(int *)(iVar5 + 0x454) + 0x8c))(iVar5);
    if (iVar5 != 0) {
      piVar6 = (int *)__rf__7EHANDLE(piVar6);
      iVar5 = *piVar6;
      iVar2 = *param_1;
      fVar1 = *(float *)(iVar5 + 8) - *(float *)(iVar2 + 8);
      fVar4 = *(float *)(iVar5 + 0xc) - *(float *)(iVar2 + 0xc);
      fVar3 = *(float *)(iVar5 + 0x10) - *(float *)(iVar2 + 0x10);
      fVar1 = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar1 * fVar1);
      goto LAB_000f778b;
    }
  }
  fVar1 = 1e+06;
LAB_000f778b:
  return (longdouble)fVar1;
}


