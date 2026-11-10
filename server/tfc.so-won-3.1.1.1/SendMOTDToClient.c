// SendMOTDToClient__10CGameRulesP7edict_s  @ 000b0304
void SendMOTDToClient__10CGameRulesP7edict_s(void)

{
  return;
}


// SendMOTDToClient__18CHalfLifeMultiplayP7edict_s  @ 000af39c
void SendMOTDToClient__18CHalfLifeMultiplayP7edict_s(undefined4 param_1,undefined4 param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint *__src;
  char *local_4c;
  undefined1 local_48 [4];
  uint local_44 [15];
  undefined1 local_8;
  
  (*DAT_0019f758)(1,gmsgServerName,0,param_2);
  uVar2 = (*DAT_0019f788)("hostname");
  (*DAT_0019f778)(uVar2);
  (*DAT_0019f75c)();
  local_4c = (char *)0x0;
  uVar2 = (*DAT_0019f788)("motdfile",local_48);
  puVar3 = (uint *)(*DAT_0019f81c)(uVar2);
  __src = puVar3;
  do {
    if (((__src == (uint *)0x0) || ((char)*__src == '\0')) || (0x5ff < (int)local_4c)) {
      (*DAT_0019f820)(puVar3);
      return;
    }
    uVar5 = (uint)__src & 3;
    puVar1 = __src;
    if (uVar5 == 0) {
LAB_000af467:
      do {
        puVar4 = puVar1;
        uVar5 = *puVar4;
        if ((char)uVar5 == '\0') goto LAB_000af489;
        if ((char)(uVar5 >> 8) == '\0') goto LAB_000af488;
        if ((uVar5 & 0xff0000) == 0) goto LAB_000af487;
        puVar1 = puVar4 + 1;
      } while ((uVar5 & 0xff000000) != 0);
      puVar4 = (uint *)((int)puVar4 + 1);
LAB_000af487:
      puVar4 = (uint *)((int)puVar4 + 1);
LAB_000af488:
      puVar4 = (uint *)((int)puVar4 + 1);
    }
    else {
      puVar4 = __src;
      if ((POPCOUNT(uVar5) & 1U) == 0) {
LAB_000af462:
        if ((char)*puVar4 != '\0') {
          puVar1 = (uint *)((int)puVar4 + 1);
          goto LAB_000af467;
        }
      }
      else if (uVar5 == 2) {
LAB_000af45d:
        if ((char)*puVar4 != '\0') {
          puVar4 = (uint *)((int)puVar4 + 1);
          goto LAB_000af462;
        }
      }
      else if ((char)*__src != '\0') {
        puVar4 = (uint *)((int)__src + 1);
        goto LAB_000af45d;
      }
    }
LAB_000af489:
    puVar1 = local_44;
    if ((uint)((int)puVar4 - (int)__src) < 0x3c) {
      strcpy((char *)local_44,(char *)__src);
    }
    else {
      strncpy((char *)local_44,(char *)__src,0x3c);
      local_8 = 0;
    }
    do {
      puVar4 = puVar1;
      uVar5 = *puVar4;
      if ((char)uVar5 == '\0') goto LAB_000af4d3;
      if ((char)(uVar5 >> 8) == '\0') goto LAB_000af4d2;
      if ((uVar5 & 0xff0000) == 0) goto LAB_000af4d1;
      puVar1 = puVar4 + 1;
    } while ((uVar5 & 0xff000000) != 0);
    puVar4 = (uint *)((int)puVar4 + 1);
LAB_000af4d1:
    puVar4 = (uint *)((int)puVar4 + 1);
LAB_000af4d2:
    puVar4 = (uint *)((int)puVar4 + 1);
LAB_000af4d3:
    local_4c = (char *)((int)puVar4 + ((int)local_4c - (int)local_44));
    if ((int)local_4c < 0x600) {
      __src = (uint *)((int)puVar3 + (int)local_4c);
    }
    else {
      *(undefined1 *)__src = 0;
    }
    (*DAT_0019f758)(1,gmsgMOTD,0,param_2);
    (*DAT_0019f760)((char)*__src == '\0');
    (*DAT_0019f778)(local_44);
    (*DAT_0019f75c)();
  } while( true );
}


