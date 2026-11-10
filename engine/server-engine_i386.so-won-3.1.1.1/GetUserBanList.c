// GetUserBanList__19CServerRemoteAccessR10CUtlBuffer  @ 000c7630
void GetUserBanList__19CServerRemoteAccessR10CUtlBuffer(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  double dVar2;
  char local_18;
  char cStack_17;
  char cStack_16;
  char cStack_15;
  int local_8;
  
  for (local_8 = 0; local_8 < numuserfilters; local_8 = local_8 + 1) {
    dVar2 = (double)*(float *)(userfilters + local_8 * 0x1c + 0x18);
    uVar1 = SV_GetIDString(userfilters + local_8 * 0x1c);
    Printf__10CUtlBufferPCce(param_2,"%i %s : %.3f min\n",local_8 + 1,uVar1,dVar2);
  }
  for (local_8 = 0; local_8 < numipfilters; local_8 = local_8 + 1) {
    uVar1 = *(undefined4 *)(ipfilters + local_8 * 0x10 + 4);
    cStack_15 = (char)((uint)uVar1 >> 0x18);
    cStack_16 = (char)((uint)uVar1 >> 0x10);
    cStack_17 = (char)((uint)uVar1 >> 8);
    local_18 = (char)uVar1;
    Printf__10CUtlBufferPCce
              (param_2,"%i %i.%i.%i.%i : %.3f min\n",numuserfilters + 1 + local_8,(int)local_18,
               (int)cStack_17,(int)cStack_16,(int)cStack_15,
               (double)*(float *)(ipfilters + local_8 * 0x10 + 0xc));
  }
  PutChar__10CUtlBufferc(param_2,0);
  return;
}


