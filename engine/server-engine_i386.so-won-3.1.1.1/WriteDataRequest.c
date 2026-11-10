// WriteDataRequest__19CServerRemoteAccessPCvi  @ 000c6ad8
void WriteDataRequest__19CServerRemoteAccessPCvi(int param_1,undefined4 param_2,int param_3)

{
  undefined1 local_224 [256];
  undefined1 local_124 [256];
  int local_24;
  undefined4 local_20;
  undefined1 local_1c [24];
  
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + param_3;
  __10CUtlBufferPCvib(local_1c,param_2,param_3,0xc0000);
  local_20 = GetInt__10CUtlBuffer(local_1c);
  local_24 = GetInt__10CUtlBuffer(local_1c);
  if (local_24 == 1) {
    GetString__10CUtlBufferPc(local_1c,local_124);
    GetString__10CUtlBufferPc(local_1c,local_224);
    SetValue__19CServerRemoteAccessPCcT1(param_1,local_124,local_224);
  }
  else if (local_24 < 2) {
    if (local_24 == 0) {
      GetString__10CUtlBufferPc(local_1c,local_124);
      RequestValue__19CServerRemoteAccessiPCc(param_1,local_20,local_124);
    }
  }
  else if (local_24 == 2) {
    GetString__10CUtlBufferPc(local_1c,local_224);
    ExecCommand__19CServerRemoteAccessPCc(param_1,local_224);
  }
  ___10CUtlBuffer(local_1c,2);
  return;
}


