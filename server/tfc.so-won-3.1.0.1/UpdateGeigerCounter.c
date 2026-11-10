// UpdateGeigerCounter__11CBasePlayer  @ 000cd54c
void UpdateGeigerCounter__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint local_20;
  
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0x1ef];
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
    param_1[0x1ef] = (int)(*gpGlobals + 0.25);
    local_20 = (uint)(longlong)ROUND((float)param_1[0x1ee] * 0.25);
    local_20 = local_20 & 0xff;
    if (local_20 != param_1[0x1f0]) {
      param_1[0x1f0] = local_20;
      (*DAT_001a7ef8)(1,gmsgGeigerRange,0,*(undefined4 *)(*param_1 + 0x208));
      (*DAT_001a7f00)(local_20);
      (*DAT_001a7efc)();
    }
    iVar3 = (*DAT_001a7fa8)(0,3);
    if (iVar3 == 0) {
      param_1[0x1ee] = 0x447a0000;
    }
  }
  return;
}


