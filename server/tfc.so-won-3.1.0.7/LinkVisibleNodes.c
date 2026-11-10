// LinkVisibleNodes__6CGraphP5CLinkP8_IO_FILEPi  @ 000c5a14
int LinkVisibleNodes__6CGraphP5CLinkP8_IO_FILEPi(int param_1,int param_2,FILE *param_3,int *param_4)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_6c;
  int local_64;
  undefined4 *local_60;
  int *local_5c;
  int local_58;
  int local_54;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined1 local_38 [4];
  int local_34;
  float local_28;
  int local_8;
  
  *param_4 = 0;
  if (*(int *)(param_1 + 0x18) < 1) {
    (*DAT_001c1114)(2,"No Nodes!\n");
LAB_000c5b1e:
    local_44 = 0;
  }
  else {
    if (param_3 == (FILE *)0x0) {
      (*DAT_001c1114)(2,"**LinkVisibleNodes:\ncan\'t write to file.");
    }
    else {
      fprintf(param_3,
              "----------------------------------------------------------------------------\n");
      fprintf(param_3,"LinkVisibleNodes - Initial Connections\n");
      fprintf(param_3,
              "----------------------------------------------------------------------------\n");
    }
    local_44 = 0;
    local_4c = 0;
    local_3c = 0;
    if (0 < *(int *)(param_1 + 0x18)) {
      local_64 = 0;
      do {
        local_48 = 0;
        if (param_3 != (FILE *)0x0) {
          fprintf(param_3,"Node #%4d:\n\n",local_3c);
        }
        iVar3 = 0;
        do {
          iVar4 = (local_44 + iVar3) * 0x18;
          *(int *)(param_2 + iVar4) = local_3c;
          *(undefined4 *)(param_2 + 4 + iVar4) = 0;
          *(undefined4 *)(param_2 + 8 + iVar4) = 0;
          iVar4 = (local_44 + 1 + iVar3) * 0x18;
          *(int *)(param_2 + iVar4) = local_3c;
          *(undefined4 *)(param_2 + 4 + iVar4) = 0;
          *(undefined4 *)(param_2 + 8 + iVar4) = 0;
          iVar4 = (local_44 + 2 + iVar3) * 0x18;
          *(int *)(param_2 + iVar4) = local_3c;
          *(undefined4 *)(param_2 + 4 + iVar4) = 0;
          *(undefined4 *)(param_2 + 8 + iVar4) = 0;
          iVar4 = (local_44 + 3 + iVar3) * 0x18;
          *(int *)(param_2 + iVar4) = local_3c;
          *(undefined4 *)(param_2 + 4 + iVar4) = 0;
          *(undefined4 *)(param_2 + 8 + iVar4) = 0;
          iVar4 = (local_44 + 4 + iVar3) * 0x18;
          *(int *)(param_2 + iVar4) = local_3c;
          *(undefined4 *)(param_2 + 4 + iVar4) = 0;
          *(undefined4 *)(param_2 + 8 + iVar4) = 0;
          iVar4 = (local_44 + 5 + iVar3) * 0x18;
          *(int *)(param_2 + iVar4) = local_3c;
          *(undefined4 *)(param_2 + 4 + iVar4) = 0;
          *(undefined4 *)(param_2 + 8 + iVar4) = 0;
          iVar4 = (local_44 + 6 + iVar3) * 0x18;
          *(int *)(param_2 + iVar4) = local_3c;
          *(undefined4 *)(param_2 + 4 + iVar4) = 0;
          *(undefined4 *)(param_2 + 8 + iVar4) = 0;
          iVar4 = (local_44 + 7 + iVar3) * 0x18;
          *(int *)(param_2 + iVar4) = local_3c;
          *(undefined4 *)(param_2 + 4 + iVar4) = 0;
          *(undefined4 *)(param_2 + 8 + iVar4) = 0;
          iVar3 = iVar3 + 8;
        } while (iVar3 < 0x80);
        *(int *)(*(int *)(param_1 + 0xc) + 0x24 + local_64) = local_44;
        local_40 = 0;
        if (0 < *(int *)(param_1 + 0x18)) {
          local_54 = 0;
          local_58 = local_44 * 0x18;
          local_5c = (int *)(param_2 + 8 + local_58);
          local_60 = (undefined4 *)(param_2 + 0xc + local_58);
          do {
            if ((local_40 != local_3c) &&
               (iVar3 = *(int *)(param_1 + 0xc),
               (*(uint *)(iVar3 + 0x1c + local_64) & 7) == (*(uint *)(iVar3 + 0x1c + local_54) & 7))
               ) {
              local_8 = 0;
              local_6c = 0;
              UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                        (iVar3 + local_64,local_54 + iVar3,1,g_pBodyQueueHead,local_38);
              iVar3 = local_8;
              if (local_34 == 0) {
                if ((byte)(1.0 < local_28 | (byte)((ushort)((ushort)NAN(local_28) << 10) >> 8) |
                          (byte)((ushort)((ushort)(local_28 == 1.0) << 0xe) >> 8)) == 0x40) {
LAB_000c5f59:
                  if (param_3 != (FILE *)0x0) {
                    fprintf(param_3,"%4d",local_40);
                    bVar1 = false;
                    if ((*local_5c == 0) ||
                       (iVar3 = (*DAT_001c1138)(*(undefined4 *)(*local_5c + 0x208)), iVar3 == 0)) {
                      bVar1 = true;
                    }
                    if (!bVar1) {
                      iVar3 = local_8 + 0x80;
                      if (local_8 == 0) {
                        iVar3 = 0;
                      }
                      iVar4 = local_6c + 0x80;
                      if (local_6c == 0) {
                        iVar4 = 0;
                      }
                      piVar2 = (int *)(local_6c + 0x80);
                      if (local_6c == 0) {
                        piVar2 = (int *)0x0;
                      }
                      fprintf(param_3,(char *)FUN_001492a0,*piVar2 + *(int *)(gpGlobals + 0x98),
                              *(int *)(iVar4 + 0x1cc) + *(int *)(gpGlobals + 0x98),
                              *(int *)(iVar3 + 0xb8) + *(int *)(gpGlobals + 0x98));
                    }
                    fprintf(param_3,"\n",local_40);
                  }
                  *(int *)(param_2 + 4 + local_58) = local_40;
                  local_48 = local_48 + 1;
                  local_58 = local_58 + 0x18;
                  local_5c = local_5c + 6;
                  local_60 = local_60 + 6;
                  local_44 = local_44 + 1;
                  if (local_48 == 0x80) {
                    (*DAT_001c1114)(2,
                                    "**LinkVisibleNodes:\nNode %d has NodeLinks > MAX_NODE_INITIAL_LINKS"
                                    ,local_3c);
                    fprintf(param_3,(char *)FUN_00149340,local_3c);
                    *param_4 = local_3c;
                    return 0;
                  }
                  if (*(int *)(param_1 + 0x18) * 0x80 < local_44) {
                    (*DAT_001c1114)(2,
                                    "**LinkVisibleNodes:\nTotalLinks > MAX_NODE_INITIAL_LINKS * NUMNODES"
                                   );
                    *param_4 = local_3c;
                    goto LAB_000c5b1e;
                  }
                  if (local_48 == 0) {
                    fprintf(param_3,"**NO INITIAL LINKS**\n");
                  }
                  *(int *)(DAT_001c148c + 0x20 + local_64) = local_48;
                  if (local_4c < local_48) {
                    local_4c = local_48;
                  }
                }
                else {
                  local_6c = local_8;
                  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                            (*(int *)(param_1 + 0xc) + local_54,local_64 + *(int *)(param_1 + 0xc),1
                             ,g_pBodyQueueHead,local_38);
                  if (local_8 == iVar3) {
                    piVar2 = (int *)(iVar3 + 0x80);
                    if (iVar3 == 0) {
                      piVar2 = (int *)0x0;
                    }
                    iVar3 = strcmp((char *)(*piVar2 + *(int *)(gpGlobals + 0x98)),"worldspawn");
                    if (iVar3 != 0) {
                      iVar3 = local_8 + 0x80;
                      if (local_8 == 0) {
                        iVar3 = 0;
                      }
                      *local_5c = iVar3;
                      iVar3 = local_8 + 0x80;
                      if (local_8 == 0) {
                        iVar3 = 0;
                      }
                      *local_60 = *(undefined4 *)
                                   (*(int *)(iVar3 + 0xb8) + *(int *)(gpGlobals + 0x98));
                      iVar3 = local_8 + 0x80;
                      if (local_8 == 0) {
                        iVar3 = 0;
                      }
                      if ((*(byte *)(iVar3 + 0x1a6) & 1) == 0) {
                        iVar3 = local_8 + 0x80;
                        if (local_8 == 0) {
                          iVar3 = 0;
                        }
                        *(int *)(iVar3 + 0x1a4) = *(int *)(iVar3 + 0x1a4) + 0x10000;
                      }
                      goto LAB_000c5f59;
                    }
                  }
                }
              }
            }
            local_54 = local_54 + 0x58;
            local_40 = local_40 + 1;
          } while (local_40 < *(int *)(param_1 + 0x18));
        }
        if (param_3 != (FILE *)0x0) {
          fprintf(param_3,
                  "----------------------------------------------------------------------------\n");
        }
        local_64 = local_64 + 0x58;
        local_3c = local_3c + 1;
      } while (local_3c < *(int *)(param_1 + 0x18));
    }
    fprintf(param_3,(char *)FUN_001493e0,local_44,local_4c);
    fprintf(param_3,
            "----------------------------------------------------------------------------\n\n\n");
  }
  return local_44;
}


