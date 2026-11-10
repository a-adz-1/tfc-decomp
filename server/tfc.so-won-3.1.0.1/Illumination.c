// Illumination__11CBaseEntity  @ 00100098
void Illumination__11CBaseEntity(int *param_1)

{
  (*DAT_001a7e7c)(*(undefined4 *)(*param_1 + 0x208));
  return;
}


// Illumination__11CBasePlayer  @ 000d3178
int Illumination__11CBasePlayer(int *param_1)

{
  int iVar1;
  
  iVar1 = (*DAT_001a7e7c)(*(undefined4 *)(*param_1 + 0x208));
  iVar1 = iVar1 + param_1[0x18c];
  if (0xff < iVar1) {
    iVar1 = 0xff;
  }
  return iVar1;
}


