// SendMOTDToClient__10CGameRulesP7edict_s  @ 000b09ec
void SendMOTDToClient__10CGameRulesP7edict_s(void)

{
  return;
}


// SendMOTDToClient__18CHalfLifeMultiplayP7edict_s  @ 000b0718
void SendMOTDToClient__18CHalfLifeMultiplayP7edict_s(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  char *__src;
  char *pcVar6;
  undefined1 local_44 [4];
  char local_40 [60];
  undefined1 local_4;
  
  (*DAT_001c10d8)(1,gmsgServerName,0,param_2);
  uVar2 = (*DAT_001c1108)("hostname");
  (*DAT_001c10f8)(uVar2);
  (*DAT_001c10dc)();
  iVar5 = 0;
  uVar2 = (*DAT_001c1108)("motdfile",local_44);
  pcVar3 = (char *)(*DAT_001c119c)(uVar2);
  if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
    __src = pcVar3;
    while (iVar5 < 0x600) {
      uVar4 = 0xffffffff;
      pcVar6 = __src;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      if (~uVar4 - 1 < 0x3c) {
        strcpy(local_40,__src);
      }
      else {
        strncpy(local_40,__src,0x3c);
        local_4 = 0;
      }
      uVar4 = 0xffffffff;
      pcVar6 = local_40;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      iVar5 = iVar5 + -1 + ~uVar4;
      if (iVar5 < 0x600) {
        __src = pcVar3 + iVar5;
      }
      else {
        *__src = '\0';
      }
      (*DAT_001c10d8)(1,gmsgMOTD,0,param_2);
      (*DAT_001c10e0)(*__src == '\0');
      (*DAT_001c10f8)(local_40);
      (*DAT_001c10dc)();
      if ((__src == (char *)0x0) || (*__src == '\0')) break;
    }
  }
  (*DAT_001c11a0)(pcVar3);
  return;
}


