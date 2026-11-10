// SpriteCreate__7CSpritePCcRC6Vectori  @ 00098df0
int * SpriteCreate__7CSpritePCcRC6Vectori(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  
  piVar1 = (int *)GetClassPtr__H1Z7CSprite_PX01_PX01(0);
  SpriteInit__7CSpritePCcRC6Vector(piVar1,param_1,param_2);
  *(int *)*piVar1 = (int)"env_sprite" - *(int *)(gpGlobals + 0x98);
  *(undefined4 *)(*piVar1 + 0x10c) = 0;
  *(undefined4 *)(*piVar1 + 0x108) = 8;
  if (param_3 != 0) {
    TurnOn__7CSprite(piVar1);
  }
  return piVar1;
}


