// Auth_AddServer  @ 0006c924
void Auth_AddServer(undefined4 *param_1)

{
  int iVar1;
  char *__cp;
  in_addr_t iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 auStackY_48 [6];
  undefined4 uStackY_30;
  
  if (authCount < 10) {
    iVar1 = authCount * 0x10;
    authCount = authCount + 1;
    *(undefined2 *)(authServers + iVar1) = 2;
    puVar4 = param_1;
    puVar5 = auStackY_48;
    for (iVar3 = 5; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    __cp = (char *)NET_BaseAdrToString();
    uStackY_30 = 0x6c993;
    iVar2 = inet_addr(__cp);
    *(in_addr_t *)(authServers + iVar1 + 4) = iVar2;
    *(undefined2 *)(authServers + iVar1 + 2) = *(undefined2 *)((int)param_1 + 0x12);
  }
  return;
}


