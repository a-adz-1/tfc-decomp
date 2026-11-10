// RouteClassify__12CBaseMonsteri  @ 000c24e4
undefined4 RouteClassify__12CBaseMonsteri(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_2 & 1) == 0) {
    if ((param_2 & 2) == 0) {
      if ((param_2 & 0x10) == 0) {
        if ((param_2 & 0x20) == 0) {
          if ((param_2 & 0x40) != 0) {
            uVar1 = 0x40;
          }
        }
        else {
          uVar1 = 0x20;
        }
      }
      else {
        uVar1 = 0x10;
      }
    }
    else {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


