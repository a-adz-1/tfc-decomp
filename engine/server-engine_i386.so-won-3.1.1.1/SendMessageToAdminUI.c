// SendMessageToAdminUI__19CServerRemoteAccessPCc  @ 000c7aa4
void SendMessageToAdminUI__19CServerRemoteAccessPCc(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = AddToTail__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZi(param_1 + 4);
  uVar1 = __vc__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii(param_1 + 4,uVar1);
  PutInt__10CUtlBufferi(uVar1,0);
  PutInt__10CUtlBufferi(uVar1,1);
  PutString__10CUtlBufferPCc(uVar1,param_2);
  return;
}


