// TargetDistance__12CTalkMonster  @ 000e8914
longdouble TargetDistance__12CTalkMonster(int *param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  
  iVar5 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x121);
  if (iVar5 != 0) {
    iVar5 = __rf__7EHANDLE(param_1 + 0x121);
    iVar5 = (**(code **)(*(int *)(iVar5 + 0x3d4) + 0x88))(iVar5);
    if (iVar5 != 0) {
      piVar6 = (int *)__rf__7EHANDLE(param_1 + 0x121);
      iVar5 = *piVar6;
      iVar2 = *param_1;
      fVar1 = *(float *)(iVar5 + 8) - *(float *)(iVar2 + 8);
      fVar4 = *(float *)(iVar5 + 0xc) - *(float *)(iVar2 + 0xc);
      fVar3 = *(float *)(iVar5 + 0x10) - *(float *)(iVar2 + 0x10);
      fVar1 = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar1 * fVar1);
      goto LAB_000e89b9;
    }
  }
  fVar1 = 1e+06;
LAB_000e89b9:
  return (longdouble)fVar1;
}


