// GetPlayerList__19CServerRemoteAccessR10CUtlBuffer  @ 000c7790
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GetPlayerList__19CServerRemoteAccessR10CUtlBuffer(undefined4 param_1,undefined4 param_2)

{
  size_t sVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int aiStackY_78 [3];
  int *piStackY_6c;
  char *pcStackY_68;
  int *piStackY_64;
  undefined4 uStackY_60;
  undefined4 uStackY_5c;
  int iStackY_58;
  int iStackY_54;
  int iStackY_50;
  int local_c;
  int *local_8;
  
  local_8 = DAT_00524284;
  for (local_c = 0; local_c < DAT_00524288; local_c = local_c + 1) {
    if (*local_8 != 0) {
      iStackY_50 = 0xc77ed;
      sVar1 = strlen((char *)(local_8 + 0x12fb));
      if (sVar1 != 0) {
        iStackY_50 = (int)ROUND(*(float *)(local_8[0x12a1] + 0x1e4));
        iStackY_54 = (int)ROUND((float)local_8[0x924]);
        iStackY_58 = (int)ROUND(_FUN_000edf00 * (float)local_8[0x923]);
        piVar3 = local_8 + 8;
        piVar4 = aiStackY_78;
        for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar4 = *piVar3;
          piVar3 = piVar3 + 1;
          piVar4 = piVar4 + 1;
        }
        uStackY_5c = NET_AdrToString();
        piStackY_6c = local_8 + 0x12a4;
        aiStackY_78[2] = 0xc78e1;
        uStackY_60 = SV_GetIDString();
        piStackY_64 = local_8 + 0x12fb;
        pcStackY_68 = "\"%s\" %s %s %d %d %d %d\n";
        piStackY_6c = (int *)param_2;
        aiStackY_78[2] = 0xc7902;
        Printf__10CUtlBufferPCce();
      }
    }
    local_8 = local_8 + 0x13bb;
  }
  iStackY_50 = 0xc7922;
  PutChar__10CUtlBufferc();
  return;
}


