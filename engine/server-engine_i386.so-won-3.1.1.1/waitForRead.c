// waitForRead__10EasySocketi  @ 000d64d8
bool waitForRead__10EasySocketi(uint *param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  __fd_mask *p_Var3;
  bool bVar4;
  fd_set local_8c;
  timeval local_c;
  
  iVar2 = isInvalid__10EasySocket(param_1);
  if (iVar2 == 0) {
    if (param_2 < 0) {
      param_2 = 0;
    }
    local_c.tv_sec = param_2 / 1000;
    local_c.tv_usec = (param_2 % 1000) * 1000;
    iVar2 = 0x20;
    p_Var3 = local_8c.fds_bits;
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      *p_Var3 = 0;
      p_Var3 = p_Var3 + 1;
    }
    pbVar1 = (byte *)((int)local_8c.fds_bits + ((int)(*param_1 & 0x1f) >> 3) + (*param_1 >> 5) * 4);
    *pbVar1 = *pbVar1 | '\x01' << (*param_1 & 7);
    iVar2 = select(0x400,&local_8c,(fd_set *)0x0,(fd_set *)0x0,&local_c);
    bVar4 = iVar2 == 1;
  }
  else {
    bVar4 = false;
  }
  return bVar4;
}


