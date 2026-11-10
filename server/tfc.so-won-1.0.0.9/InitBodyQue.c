// InitBodyQue__Fv  @ 0011d060
void InitBodyQue__Fv(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = (int)"bodyque" - *(int *)(gpGlobals + 0x98);
  g_pBodyQueueHead = (*DAT_0017551c)(iVar4);
  iVar2 = g_pBodyQueueHead + 0xdc;
  if (g_pBodyQueueHead == 0) {
    iVar2 = 0;
  }
  iVar3 = 0;
  do {
    iVar1 = (*DAT_0017551c)(iVar4);
    *(int *)(iVar2 + 0x178) = iVar1;
    iVar2 = iVar1 + 0xdc;
    if (iVar1 == 0) {
      iVar2 = 0;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  *(int *)(iVar2 + 0x178) = g_pBodyQueueHead;
  return;
}


