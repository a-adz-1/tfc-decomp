// getDestPort__10EasySocket  @ 000d5ad0
uint16_t getDestPort__10EasySocket(int param_1)

{
  uint16_t uVar1;
  int iVar2;
  
  iVar2 = isInvalid__10EasySocket(param_1);
  if ((iVar2 == 0) && (*(int *)(param_1 + 0x18) != 0)) {
    uVar1 = ntohs(*(uint16_t *)(param_1 + 10));
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


