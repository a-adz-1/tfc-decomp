// SpriteCreate__7CSpritePCcRC6Vectori  @ 000a4704
int * SpriteCreate__7CSpritePCcRC6Vectori(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)GetClassPtr__H1Z7CSprite_PX01_PX01(0);
  *(int *)(*piVar2 + 0xb8) = param_1 - *(int *)(gpGlobals + 0x98);
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 8) = *param_2;
  *(undefined4 *)(iVar1 + 0xc) = param_2[1];
  *(undefined4 *)(iVar1 + 0x10) = param_2[2];
  (**(code **)(piVar2[0x115] + 0xc))(piVar2);
  *(int *)*piVar2 = (int)"env_sprite" - *(int *)(gpGlobals + 0x98);
  *(undefined4 *)(*piVar2 + 0x10c) = 0;
  *(undefined4 *)(*piVar2 + 0x108) = 8;
  if (param_3 != 0) {
    TurnOn__7CSprite(piVar2);
  }
  return piVar2;
}


