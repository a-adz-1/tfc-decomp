// Illumination__11CBaseEntity  @ 0010ddf0
void Illumination__11CBaseEntity(int *param_1)

{
  (*DAT_001754fc)(*(undefined4 *)(*param_1 + 0x1e8));
  return;
}


// Illumination__11CBasePlayer  @ 000df680
int Illumination__11CBasePlayer(int *param_1)

{
  int iVar1;
  
  iVar1 = (*DAT_001754fc)(*(undefined4 *)(*param_1 + 0x1e8));
  iVar1 = iVar1 + param_1[0x188];
  if (0xff < iVar1) {
    iVar1 = 0xff;
  }
  return iVar1;
}


