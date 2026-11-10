// checkAsynchConnect__10EasySocketi  @ 000d634c
undefined4 checkAsynchConnect__10EasySocketi(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = isInvalid__10EasySocket(param_1);
  if (iVar1 == 0) {
    uVar2 = waitForWrite__10EasySocketi(param_1,param_2);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


