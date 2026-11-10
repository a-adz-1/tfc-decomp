// ShouldGibMonster__12CBaseMonsteri  @ 000a4c40
undefined4 ShouldGibMonster__12CBaseMonsteri(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (((param_2 == 0) && (*(float *)(*param_1 + 0x140) < -30.0)) || (param_2 == 2)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


