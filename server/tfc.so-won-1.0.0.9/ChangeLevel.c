// ChangeLevel__18CHalfLifeMultiplay  @ 000b8580
void ChangeLevel__18CHalfLifeMultiplay(void)

{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  char *__s;
  int iVar4;
  uint uVar5;
  char *__s_00;
  char *pcVar6;
  int local_68;
  char local_64 [32];
  char local_44 [32];
  char local_24 [32];
  
  builtin_strncpy(local_44,"hldm1",6);
  uVar3 = (*DAT_001755a8)("mapcyclefile");
  strcpy(local_24,(char *)(*(int *)(gpGlobals + 0xc) + *(int *)(gpGlobals + 0x98)));
  strcpy(local_44,(char *)(*(int *)(gpGlobals + 0xc) + *(int *)(gpGlobals + 0x98)));
  __s = (char *)(*DAT_0017563c)(uVar3,&local_68);
  if ((__s != (char *)0x0) && (local_68 != 0)) {
    sscanf(__s," %32s",local_24);
    iVar4 = (*DAT_00175678)(local_24);
    if (iVar4 != 0) {
      strcpy(local_44,local_24);
    }
    bVar2 = false;
    __s_00 = __s;
    while (*__s_00 != '\0') {
      iVar4 = isspace((int)*__s_00);
      if (iVar4 == 0) {
        if (*__s_00 == '\0') break;
        iVar4 = sscanf(__s_00," %32s",local_64);
        if ((iVar4 != 1) || (local_64[0] < '\r')) break;
        if (bVar2) {
          iVar4 = (*DAT_00175678)(local_64);
          if (iVar4 != 0) {
            strcpy(local_24,local_64);
            break;
          }
        }
        iVar4 = strcmp(local_64,(char *)(*(int *)(gpGlobals + 0xc) + *(int *)(gpGlobals + 0x98)));
        if (iVar4 == 0) {
          bVar2 = true;
        }
        uVar5 = 0xffffffff;
        pcVar6 = local_64;
        do {
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        __s_00 = __s_00 + (~uVar5 - 1);
      }
      else {
        __s_00 = __s_00 + 1;
      }
    }
    (*DAT_00175640)(__s);
  }
  iVar4 = (*DAT_00175678)(local_24);
  if (iVar4 == 0) {
    strcpy(local_24,local_44);
  }
  g_fGameOver = 1;
  (*DAT_001755b4)(1,"CHANGE LEVEL: %s\n",local_24);
  (*DAT_001754d8)(local_24,0);
  return;
}


