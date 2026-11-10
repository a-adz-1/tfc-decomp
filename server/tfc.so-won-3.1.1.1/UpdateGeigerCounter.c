// UpdateGeigerCounter__11CBasePlayer  @ 000d86b0
void UpdateGeigerCounter__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint local_24;
  
  fVar1 = *gpGlobals;
  fVar2 = (float)param_1[0x215];
  if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
    param_1[0x215] = (int)(fVar1 + 0.25);
    local_24 = (uint)(longlong)ROUND((float)param_1[0x214] * 0.25);
    local_24 = local_24 & 0xff;
    if (local_24 != param_1[0x216]) {
      param_1[0x216] = local_24;
      (*DAT_0019f758)(1,gmsgGeigerRange,0,*(undefined4 *)(*param_1 + 0x208));
      (*DAT_0019f760)(local_24);
      (*DAT_0019f75c)();
    }
    iVar3 = (*DAT_0019f808)(0,3);
    if (iVar3 == 0) {
      param_1[0x214] = 0x447a0000;
    }
  }
  return;
}


