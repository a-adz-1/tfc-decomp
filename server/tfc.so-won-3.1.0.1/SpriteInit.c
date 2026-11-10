// SpriteInit__7CSpritePCcRC6Vector  @ 00098d94
void SpriteInit__7CSpritePCcRC6Vector(int *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  *(int *)(*param_1 + 0xb8) = param_2 - *(int *)(gpGlobals + 0x98);
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + 8) = *param_3;
  *(undefined4 *)(iVar1 + 0xc) = param_3[1];
  *(undefined4 *)(iVar1 + 0x10) = param_3[2];
  (**(code **)(param_1[0xf5] + 8))(param_1);
  return;
}


