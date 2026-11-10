// Illumination__11CBaseEntity  @ 00112844
void Illumination__11CBaseEntity(int *param_1)

{
  (*DAT_0019f6dc)(*(undefined4 *)(*param_1 + 0x208));
  return;
}


// Illumination__11CBasePlayer  @ 000e5218
int Illumination__11CBasePlayer(int *param_1)

{
  int iVar1;
  
  iVar1 = (*DAT_0019f6dc)(*(undefined4 *)(*param_1 + 0x208));
  iVar1 = iVar1 + param_1[0x1b1];
  if (0xff < iVar1) {
    iVar1 = 0xff;
  }
  return iVar1;
}


