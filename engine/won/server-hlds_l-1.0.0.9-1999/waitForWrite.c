// waitForWrite__10EasySocketi  @ 0808e5f0
bool waitForWrite__10EasySocketi(uint *param_1,int param_2)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  __fd_mask *p_Var4;
  bool bVar5;
  timeval local_8c;
  byte local_84 [128];
  
  iVar3 = isInvalid__10EasySocket(param_1);
  if (iVar3 == 0) {
    if (param_2 < 0) {
      param_2 = 0;
    }
    local_8c.tv_sec = param_2 / 1000;
    local_8c.tv_usec = (param_2 % 1000) * 1000;
    p_Var4 = (__fd_mask *)local_84;
    for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
      *p_Var4 = 0;
      p_Var4 = p_Var4 + 1;
    }
    uVar1 = *param_1;
    pbVar2 = (byte *)((int)local_84 + ((int)(uVar1 & 0x1f) >> 3) + (uVar1 >> 5) * 4);
    *pbVar2 = *pbVar2 | '\x01' << (uVar1 & 7);
    iVar3 = select(0x400,(fd_set *)0x0,(fd_set *)local_84,(fd_set *)0x0,&local_8c);
    bVar5 = iVar3 == 1;
  }
  else {
    bVar5 = false;
  }
  return bVar5;
}


