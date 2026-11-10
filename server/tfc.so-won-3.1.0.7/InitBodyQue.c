// InitBodyQue__Fv  @ 001224d0
void InitBodyQue__Fv(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (int)"bodyque" - *(int *)(gpGlobals + 0x98);
  g_pBodyQueueHead = (*DAT_001c107c)(iVar3);
  iVar2 = g_pBodyQueueHead + 0x80;
  if (g_pBodyQueueHead == 0) {
    iVar2 = 0;
  }
  iVar1 = (*DAT_001c107c)(iVar3);
  *(int *)(iVar2 + 0x198) = iVar1;
  iVar2 = iVar1 + 0x80;
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  iVar1 = (*DAT_001c107c)(iVar3);
  *(int *)(iVar2 + 0x198) = iVar1;
  iVar2 = iVar1 + 0x80;
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  iVar3 = (*DAT_001c107c)(iVar3);
  *(int *)(iVar2 + 0x198) = iVar3;
  iVar2 = iVar3 + 0x80;
  if (iVar3 == 0) {
    iVar2 = 0;
  }
  *(int *)(iVar2 + 0x198) = g_pBodyQueueHead;
  return;
}


