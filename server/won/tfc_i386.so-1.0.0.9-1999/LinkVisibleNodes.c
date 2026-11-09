// LinkVisibleNodes__6CGraphP5CLinkP8_IO_FILEPi  @ 000cb240
int LinkVisibleNodes__6CGraphP5CLinkP8_IO_FILEPi(int param_1,int param_2,FILE *param_3,int *param_4)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
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
    (*DAT_001755b4)(2,"No Nodes!\n");
    iStack_4c = 0;
  }
  else {
    if (param_3 == (FILE *)0x0) {
      (*DAT_001755b4)(2,"**LinkVisibleNodes:\ncan\'t write to file.");
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
        iVar3 = 0;
        do {
          iVar4 = (iStack_4c + iVar3) * 0x18;
          *(int *)(param_2 + iVar4) = iStack_40;
          *(undefined4 *)(param_2 + 4 + iVar4) = 0;
          *(undefined4 *)(param_2 + 8 + iVar4) = 0;
          iVar3 = iVar3 + 1;
        } while (iVar3 < 0x80);
        *(int *)(*(int *)(param_1 + 0xc) + 0x24 + iStack_40 * 0x58) = iStack_4c;
        iStack_44 = 0;
        if (0 < *(int *)(param_1 + 0x18)) {
          do {
            if (iStack_44 != iStack_40) {
              iVar3 = *(int *)(param_1 + 0xc);
              iVar4 = iStack_40 * 0x58;
              iVar5 = iStack_44 * 0x58;
              if ((*(uint *)(iVar3 + 0x1c + iVar4) & 7) == (*(uint *)(iVar3 + 0x1c + iVar5) & 7)) {
                iStack_c = 0;
                iStack_48 = 0;
                UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                          (iVar4 + iVar3,iVar5 + iVar3,1,g_pBodyQueueHead,auStack_3c);
                iVar3 = iStack_c;
                if (iStack_38 == 0) {
                  if ((byte)(1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) == 0x40) {
LAB_000cb52b:
                    if (param_3 != (FILE *)0x0) {
                      fprintf(param_3,"%4d",iStack_44);
                      iVar3 = *(int *)(param_2 + 8 + iStack_4c * 0x18);
                      bVar1 = false;
                      if ((iVar3 == 0) ||
                         (iVar3 = (*DAT_001755d8)(*(undefined4 *)(iVar3 + 0x1e8)), iVar3 == 0)) {
                        bVar1 = true;
                      }
                      if (!bVar1) {
                        iVar3 = iStack_c + 0xdc;
                        if (iStack_c == 0) {
                          iVar3 = 0;
                        }
                        iVar4 = iStack_48 + 0xdc;
                        if (iStack_48 == 0) {
                          iVar4 = 0;
                        }
                        piVar2 = (int *)(iStack_48 + 0xdc);
                        if (iStack_48 == 0) {
                          piVar2 = (int *)0x0;
                        }
                        fprintf(param_3,"  Entity on connection: %s, name: %s  Model: %s",
                                *piVar2 + *(int *)(gpGlobals + 0x98),
                                *(int *)(iVar4 + 0x1ac) + *(int *)(gpGlobals + 0x98),
                                *(int *)(iVar3 + 0x98) + *(int *)(gpGlobals + 0x98));
                      }
                      fprintf(param_3,"\n",iStack_44);
                    }
                    *(int *)(param_2 + 4 + iStack_4c * 0x18) = iStack_44;
                    iStack_50 = iStack_50 + 1;
                    iStack_4c = iStack_4c + 1;
                    if (iStack_50 == 0x80) {
                      (*DAT_001755b4)(2,
                                      "**LinkVisibleNodes:\nNode %d has NodeLinks > MAX_NODE_INITIAL_LINKS"
                                      ,iStack_40);
                      fprintf(param_3,"** NODE %d HAS NodeLinks > MAX_NODE_INITIAL_LINKS **\n",
                              iStack_40);
LAB_000cb2d2:
                      *param_4 = iStack_40;
                      return 0;
                    }
                    if (*(int *)(param_1 + 0x18) * 0x80 < iStack_4c) {
                      (*DAT_001755b4)(2,FUN_00136d80);
                      goto LAB_000cb2d2;
                    }
                    if (iStack_50 == 0) {
                      fprintf(param_3,"**NO INITIAL LINKS**\n");
                    }
                    *(int *)(DAT_001758cc + 0x20 + iStack_40 * 0x58) = iStack_50;
                    if (iStack_54 < iStack_50) {
                      iStack_54 = iStack_50;
                    }
                  }
                  else {
                    iStack_48 = iStack_c;
                    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                              (*(int *)(param_1 + 0xc) + iVar5,iVar4 + *(int *)(param_1 + 0xc),1,
                               g_pBodyQueueHead,auStack_3c);
                    if (iStack_c == iVar3) {
                      piVar2 = (int *)(iVar3 + 0xdc);
                      if (iVar3 == 0) {
                        piVar2 = (int *)0x0;
                      }
                      iVar3 = strcmp((char *)(*piVar2 + *(int *)(gpGlobals + 0x98)),"worldspawn");
                      if (iVar3 != 0) {
                        iVar3 = iStack_c + 0xdc;
                        if (iStack_c == 0) {
                          iVar3 = 0;
                        }
                        *(int *)(param_2 + 8 + iStack_4c * 0x18) = iVar3;
                        iVar3 = iStack_c + 0xdc;
                        if (iStack_c == 0) {
                          iVar3 = 0;
                        }
                        *(undefined4 *)(param_2 + 0xc + iStack_4c * 0x18) =
                             *(undefined4 *)(*(int *)(iVar3 + 0x98) + *(int *)(gpGlobals + 0x98));
                        iVar3 = iStack_c + 0xdc;
                        if (iStack_c == 0) {
                          iVar3 = 0;
                        }
                        if ((*(byte *)(iVar3 + 0x186) & 1) == 0) {
                          iVar3 = iStack_c + 0xdc;
                          if (iStack_c == 0) {
                            iVar3 = 0;
                          }
                          *(int *)(iVar3 + 0x184) = *(int *)(iVar3 + 0x184) + 0x10000;
                        }
                        goto LAB_000cb52b;
                      }
                    }
                  }
                }
              }
            }
            iStack_44 = iStack_44 + 1;
          } while (iStack_44 < *(int *)(param_1 + 0x18));
        }
        if (param_3 != (FILE *)0x0) {
          fprintf(param_3,
                  "----------------------------------------------------------------------------\n");
        }
        iStack_40 = iStack_40 + 1;
      } while (iStack_40 < *(int *)(param_1 + 0x18));
    }
    fprintf(param_3,"\n%4d Total Initial Connections - %4d Maximum connections for a single node.\n"
            ,iStack_4c,iStack_54);
    fprintf(param_3,
            "----------------------------------------------------------------------------\n\n\n");
  }
  return iStack_4c;
}


