// ExpandThink__7CSprite  @ 000ae300
void ExpandThink__7CSprite(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0xf3];
  iVar3 = *param_1;
  *(float *)(iVar3 + 0x124) =
       (fVar1 - fVar2) * *(float *)(iVar3 + 0x1d8) + *(float *)(iVar3 + 0x124);
  iVar3 = *param_1;
  *(float *)(iVar3 + 300) = *(float *)(iVar3 + 300) - (fVar1 - fVar2) * *(float *)(iVar3 + 0x140);
  pfVar4 = gpGlobals;
  if (0.0 < *(float *)(*param_1 + 300)) {
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
    param_1[0xf3] = (int)*pfVar4;
  }
  else {
    *(undefined4 *)(*param_1 + 300) = 0;
    UTIL_Remove__FP11CBaseEntity(param_1);
  }
  return;
}


