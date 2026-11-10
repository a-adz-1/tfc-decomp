// LinkVisibleNodes__6CGraphP5CLinkP8_IO_FILEPi  @ 000c5dd8
int LinkVisibleNodes__6CGraphP5CLinkP8_IO_FILEPi(int param_1,int param_2,FILE *param_3,int *param_4)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piStack_70;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  undefined1 auStack_3c [4];
  int iStack_38;
  float fStack_2c;
  int iStack_c;
  
  *param_4 = 0;
  if (*(int *)(param_1 + 0x18) < 1) {
    (*DAT_0019f794)(2,"No Nodes!\n");
    iStack_4c = 0;
  }
  else {
    if (param_3 == (FILE *)0x0) {
      (*DAT_0019f794)(2,"**LinkVisibleNodes:\ncan\'t write to file.");
    }
    else {
      fprintf(param_3,
              "----------------------------------------------------------------------------\n");
      fprintf(param_3,"LinkVisibleNodes - Initial Connections\n");
      fprintf(param_3,
              "----------------------------------------------------------------------------\n");
    }
    iStack_4c = 0;
    iStack_54 = 0;
    iStack_40 = 0;
    if (0 < *(int *)(param_1 + 0x18)) {
      do {
        iStack_50 = 0;
        if (param_3 != (FILE *)0x0) {
          fprintf(param_3,"Node #%4d:\n\n",iStack_40);
        }
        iVar5 = 0;
        do {
          iVar3 = (iStack_4c + iVar5) * 0x18;
          iVar5 = iVar5 + 1;
          *(int *)(param_2 + iVar3) = iStack_40;
          *(undefined4 *)(param_2 + 4 + iVar3) = 0;
          *(undefined4 *)(param_2 + 8 + iVar3) = 0;
        } while (iVar5 < 0x80);
        iStack_44 = 0;
        *(int *)(*(int *)(param_1 + 0xc) + 0x24 + iStack_40 * 0x58) = iStack_4c;
        iVar5 = *(int *)(param_1 + 0x18);
        if (0 < iVar5) {
          do {
            if (iStack_44 != iStack_40) {
              iVar5 = *(int *)(param_1 + 0xc);
              iVar3 = iStack_40 * 0x58;
              iVar6 = iStack_44 * 0x58;
              if ((*(uint *)(iVar5 + 0x1c + iVar3) & 7) == (*(uint *)(iVar5 + 0x1c + iVar6) & 7)) {
                iStack_c = 0;
                iStack_48 = 0;
                UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                          (iVar5 + iVar3,iVar6 + iVar5,1,g_pBodyQueueHead,auStack_3c);
                iVar5 = iStack_c;
                if (iStack_38 == 0) {
                  if ((byte)(1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) == 0x40) {
FUN_000c6128:
                    if (param_3 != (FILE *)0x0) {
                      fprintf(param_3,"%4d",iStack_44);
                      bVar2 = false;
                      iVar5 = *(int *)(param_2 + 8 + iStack_4c * 0x18);
                      if ((iVar5 == 0) ||
                         (iVar5 = (*DAT_0019f7b8)(*(undefined4 *)(iVar5 + 0x208)), iVar5 == 0)) {
                        bVar2 = true;
                      }
                      if (!bVar2) {
                        piStack_70 = (int *)(iStack_c + 0x80);
                        piVar4 = (int *)(iStack_48 + 0x80);
                        if (iStack_c == 0) {
                          piStack_70 = (int *)0x0;
                        }
                        piVar1 = (int *)((int)piStack_70 + 0xb8);
                        piStack_70 = piVar4;
                        if (iStack_48 == 0) {
                          piStack_70 = (int *)0x0;
                        }
                        if (iStack_48 == 0) {
                          piVar4 = (int *)0x0;
                        }
                        fprintf(param_3,"  Entity on connection: %s, name: %s  Model: %s",
                                *piVar4 + *(int *)(gpGlobals + 0x98),
                                piStack_70[0x73] + *(int *)(gpGlobals + 0x98),
                                *piVar1 + *(int *)(gpGlobals + 0x98));
                      }
                      fprintf(param_3,"\n",iStack_44);
                    }
                    *(int *)(param_2 + 4 + iStack_4c * 0x18) = iStack_44;
                    iStack_50 = iStack_50 + 1;
                    iStack_4c = iStack_4c + 1;
                    if (iStack_50 == 0x80) {
                      (*DAT_0019f794)(2,
                                      "**LinkVisibleNodes:\nNode %d has NodeLinks > MAX_NODE_INITIAL_LINKS"
                                      ,iStack_40);
                      fprintf(param_3,"** NODE %d HAS NodeLinks > MAX_NODE_INITIAL_LINKS **\n",
                              iStack_40);
                      *param_4 = iStack_40;
                      return 0;
                    }
                    if (*(int *)(param_1 + 0x18) * 0x80 < iStack_4c) {
                      (*DAT_0019f794)(2,
                                      "**LinkVisibleNodes:\nTotalLinks > MAX_NODE_INITIAL_LINKS * NUMNODES"
                                     );
                      *param_4 = iStack_40;
                      return 0;
                    }
                    if (iStack_50 == 0) {
                      fprintf(param_3,"**NO INITIAL LINKS**\n");
                    }
                    *(int *)(DAT_0019fb2c + 0x20 + iStack_40 * 0x58) = iStack_50;
                    if (iStack_54 < iStack_50) {
                      iStack_54 = iStack_50;
                    }
                  }
                  else {
                    iStack_48 = iStack_c;
                    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                              (*(int *)(param_1 + 0xc) + iVar6,iVar3 + *(int *)(param_1 + 0xc),1,
                               g_pBodyQueueHead,auStack_3c);
                    if (iStack_c == iVar5) {
                      piStack_70 = (int *)(iVar5 + 0x80);
                      if (iVar5 == 0) {
                        piStack_70 = (int *)0x0;
                      }
                      iVar5 = strcmp((char *)(*piStack_70 + *(int *)(gpGlobals + 0x98)),"worldspawn"
                                    );
                      if (iVar5 != 0) {
                        iVar5 = iStack_c + 0x80;
                        if (iStack_c == 0) {
                          iVar5 = 0;
                        }
                        piStack_70 = (int *)(iStack_c + 0x80);
                        *(int *)(param_2 + 8 + iStack_4c * 0x18) = iVar5;
                        if (iStack_c == 0) {
                          piStack_70 = (int *)0x0;
                        }
                        *(undefined4 *)(iStack_4c * 0x18 + param_2 + 0xc) =
                             *(undefined4 *)
                              (*(int *)((int)piStack_70 + 0xb8) + *(int *)(gpGlobals + 0x98));
                        iVar5 = iStack_c + 0x80;
                        if (iStack_c == 0) {
                          iVar5 = 0;
                        }
                        if ((*(byte *)(iVar5 + 0x1a6) & 1) == 0) {
                          iVar5 = iStack_c + 0x80;
                          if (iStack_c == 0) {
                            iVar5 = 0;
                          }
                          *(int *)(iVar5 + 0x1a4) = *(int *)(iVar5 + 0x1a4) + 0x10000;
                        }
                        goto FUN_000c6128;
                      }
                    }
                  }
                }
              }
            }
            iStack_44 = iStack_44 + 1;
            iVar5 = *(int *)(param_1 + 0x18);
          } while (iStack_44 < iVar5);
        }
        if (param_3 != (FILE *)0x0) {
          fprintf(param_3,
                  "----------------------------------------------------------------------------\n");
          iVar5 = *(int *)(param_1 + 0x18);
        }
        iStack_40 = iStack_40 + 1;
      } while (iStack_40 < iVar5);
    }
    fprintf(param_3,"\n%4d Total Initial Connections - %4d Maximum connections for a single node.\n"
            ,iStack_4c,iStack_54);
    fprintf(param_3,
            "----------------------------------------------------------------------------\n\n\n");
  }
  return iStack_4c;
}


