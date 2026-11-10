// TargetDistance__12CTalkMonster  @ 000f1df0
longdouble TargetDistance__12CTalkMonster(int *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  
  iVar5 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11e);
  if (iVar5 != 0) {
    iVar5 = __rf__7EHANDLE(param_1 + 0x11e);
    iVar5 = (**(code **)(*(int *)(iVar5 + 0x3c8) + 0x88))(iVar5);
    if (iVar5 != 0) {
      piVar6 = (int *)__rf__7EHANDLE(param_1 + 0x11e);
      iVar5 = *piVar6;
      iVar1 = *param_1;
      fVar2 = *(float *)(iVar5 + 8) - *(float *)(iVar1 + 8);
      fVar4 = *(float *)(iVar5 + 0xc) - *(float *)(iVar1 + 0xc);
      fVar3 = *(float *)(iVar5 + 0x10) - *(float *)(iVar1 + 0x10);
      return (longdouble)SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar2 * fVar2);
    }
  }
  return (longdouble)1e+06;
}


