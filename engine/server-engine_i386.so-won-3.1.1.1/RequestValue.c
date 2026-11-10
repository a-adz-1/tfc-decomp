// RequestValue__19CServerRemoteAccessiPCc  @ 000c6d58
void RequestValue__19CServerRemoteAccessiPCc(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 local_1c [24];
  
  __10CUtlBufferiib(local_1c,0,0x100,0xc0001);
  LookupValue__19CServerRemoteAccessPCcR10CUtlBuffer(param_1,param_3,local_1c);
  uVar1 = AddToTail__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi(param_1 + 4);
  uVar1 = __vc__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii(param_1 + 4,uVar1);
  PutInt__10CUtlBufferi(uVar1,param_2);
  PutInt__10CUtlBufferi(uVar1,0);
  PutString__10CUtlBufferPCc(uVar1,param_3);
  uVar2 = TellPut__C10CUtlBuffer(local_1c);
  PutInt__10CUtlBufferi(uVar1,uVar2);
  iVar3 = TellPut__C10CUtlBuffer(local_1c);
  if (iVar3 != 0) {
    uVar2 = TellPut__C10CUtlBuffer(local_1c);
    uVar4 = Base__10CUtlBuffer(local_1c);
    Put__10CUtlBufferPCvi(uVar1,uVar4,uVar2);
  }
  ___10CUtlBuffer(local_1c,2);
  return;
}


