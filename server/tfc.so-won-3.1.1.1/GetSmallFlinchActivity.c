// GetSmallFlinchActivity__12CBaseMonster  @ 00095ac4
undefined4 GetSmallFlinchActivity__12CBaseMonster(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  UTIL_MakeVectors__FRC6Vector(*param_1 + 0x50);
  switch(param_1[0x15c]) {
  default:
    uVar2 = 0x1a;
    break;
  case 1:
    uVar2 = 0x46;
    break;
  case 3:
    uVar2 = 0x48;
    break;
  case 4:
    uVar2 = 0x49;
    break;
  case 5:
    uVar2 = 0x4a;
    break;
  case 6:
    uVar2 = 0x4b;
    break;
  case 7:
    uVar2 = 0x4c;
  }
  iVar1 = LookupActivity__14CBaseAnimatingi(param_1,uVar2);
  if (iVar1 == -1) {
    uVar2 = 0x1a;
  }
  return uVar2;
}


