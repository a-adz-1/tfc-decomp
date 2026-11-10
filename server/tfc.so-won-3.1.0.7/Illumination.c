// Illumination__11CBaseEntity  @ 0010f3cc
void Illumination__11CBaseEntity(int *param_1)

{
  (*DAT_001c105c)(*(undefined4 *)(*param_1 + 0x208));
  return;
}


// Illumination__11CBasePlayer  @ 000de87c
int Illumination__11CBasePlayer(int *param_1)

{
  int iVar1;
  
  iVar1 = (*DAT_001c105c)(*(undefined4 *)(*param_1 + 0x208));
  iVar1 = iVar1 + param_1[0x1a8];
  if (0xff < iVar1) {
    iVar1 = 0xff;
  }
  return iVar1;
}


