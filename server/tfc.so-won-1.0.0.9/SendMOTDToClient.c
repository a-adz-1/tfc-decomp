// SendMOTDToClient__10CGameRulesP7edict_s  @ 000b8920
void SendMOTDToClient__10CGameRulesP7edict_s(void)

{
  return;
}


// SendMOTDToClient__18CHalfLifeMultiplayP7edict_s  @ 000b8760
void SendMOTDToClient__18CHalfLifeMultiplayP7edict_s(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char *__src;
  int iVar4;
  char *pcVar5;
  undefined1 local_48 [4];
  char local_44 [60];
  undefined1 local_8;
  
  pcVar2 = (char *)(*DAT_0017563c)("motd.txt",local_48);
  if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
    iVar4 = 0;
    __src = pcVar2;
    while (iVar4 < 0xf0) {
      uVar3 = 0xffffffff;
      pcVar5 = __src;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      if (~uVar3 - 1 < 0x3c) {
        strcpy(local_44,__src);
      }
      else {
        strncpy(local_44,__src,0x3c);
        local_8 = 0;
      }
      uVar3 = 0xffffffff;
      pcVar5 = local_44;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      iVar4 = iVar4 + -1 + ~uVar3;
      if (iVar4 < 0xf0) {
        __src = pcVar2 + iVar4;
      }
      else {
        *__src = '\0';
      }
      (*DAT_00175578)(1,gmsgMOTD,0,param_2);
      (*DAT_00175580)(*__src == '\0');
      (*DAT_00175598)(local_44);
      (*DAT_0017557c)();
      if ((__src == (char *)0x0) || (*__src == '\0')) break;
    }
  }
  (*DAT_00175640)(pcVar2);
  return;
}


