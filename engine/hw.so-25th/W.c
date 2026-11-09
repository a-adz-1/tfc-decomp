// W_CleanupName  @ 00112530
void W_CleanupName(char *in,char *out)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???] */
  cVar3 = *in;
  if (cVar3 == 0) {
    iVar4 = 0;
  }
  else {
    if ((int)cVar3 - 0x41U < 0x1a) {
      cVar3 = cVar3 + ' ';
    }
    *out = cVar3;
    cVar3 = in[1];
    if (cVar3 == 0) {
      iVar4 = 1;
    }
    else {
      if ((int)cVar3 - 0x41U < 0x1a) {
        cVar3 = cVar3 + ' ';
      }
      out[1] = cVar3;
      cVar3 = in[2];
      if (cVar3 == 0) {
        iVar4 = 2;
      }
      else {
        if ((int)cVar3 - 0x41U < 0x1a) {
          cVar3 = cVar3 + ' ';
        }
        out[2] = cVar3;
        cVar3 = in[3];
        if (cVar3 == 0) {
          iVar4 = 3;
        }
        else {
          if ((int)cVar3 - 0x41U < 0x1a) {
            cVar3 = cVar3 + ' ';
          }
          out[3] = cVar3;
          cVar3 = in[4];
          if (cVar3 == 0) {
            iVar4 = 4;
          }
          else {
            if ((int)cVar3 - 0x41U < 0x1a) {
              cVar3 = cVar3 + ' ';
            }
            out[4] = cVar3;
            cVar3 = in[5];
            if (cVar3 == 0) {
              iVar4 = 5;
            }
            else {
              if ((int)cVar3 - 0x41U < 0x1a) {
                cVar3 = cVar3 + ' ';
              }
              out[5] = cVar3;
              cVar3 = in[6];
              if (cVar3 == 0) {
                iVar4 = 6;
              }
              else {
                if ((int)cVar3 - 0x41U < 0x1a) {
                  cVar3 = cVar3 + ' ';
                }
                out[6] = cVar3;
                cVar3 = in[7];
                if (cVar3 == 0) {
                  iVar4 = 7;
                }
                else {
                  if ((int)cVar3 - 0x41U < 0x1a) {
                    cVar3 = cVar3 + ' ';
                  }
                  out[7] = cVar3;
                  cVar3 = in[8];
                  if (cVar3 == 0) {
                    iVar4 = 8;
                  }
                  else {
                    if ((int)cVar3 - 0x41U < 0x1a) {
                      cVar3 = cVar3 + ' ';
                    }
                    out[8] = cVar3;
                    cVar3 = in[9];
                    if (cVar3 == 0) {
                      iVar4 = 9;
                    }
                    else {
                      if ((int)cVar3 - 0x41U < 0x1a) {
                        cVar3 = cVar3 + ' ';
                      }
                      out[9] = cVar3;
                      cVar3 = in[10];
                      if (cVar3 == 0) {
                        iVar4 = 10;
                      }
                      else {
                        if ((int)cVar3 - 0x41U < 0x1a) {
                          cVar3 = cVar3 + ' ';
                        }
                        out[10] = cVar3;
                        cVar3 = in[0xb];
                        if (cVar3 == 0) {
                          iVar4 = 0xb;
                        }
                        else {
                          if ((int)cVar3 - 0x41U < 0x1a) {
                            cVar3 = cVar3 + ' ';
                          }
                          out[0xb] = cVar3;
                          cVar3 = in[0xc];
                          if (cVar3 == 0) {
                            iVar4 = 0xc;
                          }
                          else {
                            if ((int)cVar3 - 0x41U < 0x1a) {
                              cVar3 = cVar3 + ' ';
                            }
                            out[0xc] = cVar3;
                            cVar3 = in[0xd];
                            if (cVar3 == 0) {
                              iVar4 = 0xd;
                            }
                            else {
                              if ((int)cVar3 - 0x41U < 0x1a) {
                                cVar3 = cVar3 + ' ';
                              }
                              out[0xd] = cVar3;
                              cVar3 = in[0xe];
                              if (cVar3 == 0) {
                                iVar4 = 0xe;
                              }
                              else {
                                if ((int)cVar3 - 0x41U < 0x1a) {
                                  cVar3 = cVar3 + ' ';
                                }
                                out[0xe] = cVar3;
                                cVar3 = in[0xf];
                                if (cVar3 != 0) {
                                  if ((int)cVar3 - 0x41U < 0x1a) {
                                    cVar3 = cVar3 + ' ';
                                  }
                                  out[0xf] = cVar3;
                                  return;
                                }
                                iVar4 = 0xf;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  pcVar2 = out + iVar4;
  uVar6 = -iVar4 + 0x10;
  if (7 < uVar6) {
    if (((uint)pcVar2 & 1) != 0) {
      *pcVar2 = '\0';
      uVar6 = -iVar4 + 0xf;
      pcVar2 = pcVar2 + 1;
    }
    if (((uint)pcVar2 & 2) != 0) {
      pcVar2[0] = '\0';
      pcVar2[1] = '\0';
      uVar6 = uVar6 - 2;
      pcVar2 = pcVar2 + 2;
    }
    if (7 < uVar6) {
      uVar5 = 0;
      do {
        pcVar1 = pcVar2 + uVar5;
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        pcVar1 = pcVar2 + uVar5 + 4;
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        uVar5 = uVar5 + 8;
      } while (uVar5 < (uVar6 & 0xfffffff8));
      pcVar2 = pcVar2 + uVar5;
    }
  }
  if ((uVar6 & 4) != 0) {
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    pcVar2 = pcVar2 + 4;
  }
  if ((uVar6 & 2) != 0) {
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2 = pcVar2 + 2;
  }
  if ((uVar6 & 1) == 0) {
    return;
  }
  *pcVar2 = '\0';
  return;
}


// W_GetLumpName  @ 00113100
void * W_GetLumpName(int wad,char *name)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  lumpinfo_t *plVar8;
  int in_GS_OFFSET;
  char local_30 [16];
  int iStack_20;
  
                    /* Unresolved local var: lumpinfo_t * lump@[???] */
  iStack_20 = *(int *)(in_GS_OFFSET + 0x14);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: lumpinfo_t * lump_p@[???]
                       Unresolved local var: char[16] clean@[???]
                       Unresolved local var: int c@[???] */
  cVar2 = *name;
  if (cVar2 == 0) {
    iVar7 = 0;
  }
  else {
    local_30[0] = cVar2;
    if ((int)cVar2 - 0x41U < 0x1a) {
      local_30[0] = cVar2 + ' ';
    }
    cVar2 = name[1];
    if (cVar2 == 0) {
      iVar7 = 1;
    }
    else {
      local_30[1] = cVar2;
      if ((int)cVar2 - 0x41U < 0x1a) {
        local_30[1] = cVar2 + ' ';
      }
      cVar2 = name[2];
      if (cVar2 == 0) {
        iVar7 = 2;
      }
      else {
        local_30[2] = cVar2;
        if ((int)cVar2 - 0x41U < 0x1a) {
          local_30[2] = cVar2 + ' ';
        }
        cVar2 = name[3];
        if (cVar2 == 0) {
          iVar7 = 3;
        }
        else {
          local_30[3] = cVar2;
          if ((int)cVar2 - 0x41U < 0x1a) {
            local_30[3] = cVar2 + ' ';
          }
          cVar2 = name[4];
          if (cVar2 == 0) {
            iVar7 = 4;
          }
          else {
            local_30[4] = cVar2;
            if ((int)cVar2 - 0x41U < 0x1a) {
              local_30[4] = cVar2 + ' ';
            }
            cVar2 = name[5];
            if (cVar2 == 0) {
              iVar7 = 5;
            }
            else {
              local_30[5] = cVar2;
              if ((int)cVar2 - 0x41U < 0x1a) {
                local_30[5] = cVar2 + ' ';
              }
              cVar2 = name[6];
              if (cVar2 == 0) {
                iVar7 = 6;
              }
              else {
                local_30[6] = cVar2;
                if ((int)cVar2 - 0x41U < 0x1a) {
                  local_30[6] = cVar2 + ' ';
                }
                cVar2 = name[7];
                if (cVar2 == 0) {
                  iVar7 = 7;
                }
                else {
                  local_30[7] = cVar2;
                  if ((int)cVar2 - 0x41U < 0x1a) {
                    local_30[7] = cVar2 + ' ';
                  }
                  cVar2 = name[8];
                  if (cVar2 == 0) {
                    iVar7 = 8;
                  }
                  else {
                    local_30[8] = cVar2;
                    if ((int)cVar2 - 0x41U < 0x1a) {
                      local_30[8] = cVar2 + ' ';
                    }
                    cVar2 = name[9];
                    if (cVar2 == 0) {
                      iVar7 = 9;
                    }
                    else {
                      local_30[9] = cVar2;
                      if ((int)cVar2 - 0x41U < 0x1a) {
                        local_30[9] = cVar2 + ' ';
                      }
                      cVar2 = name[10];
                      if (cVar2 == 0) {
                        iVar7 = 10;
                      }
                      else {
                        local_30[10] = cVar2;
                        if ((int)cVar2 - 0x41U < 0x1a) {
                          local_30[10] = cVar2 + ' ';
                        }
                        cVar2 = name[0xb];
                        if (cVar2 == 0) {
                          iVar7 = 0xb;
                        }
                        else {
                          local_30[0xb] = cVar2;
                          if ((int)cVar2 - 0x41U < 0x1a) {
                            local_30[0xb] = cVar2 + ' ';
                          }
                          cVar2 = name[0xc];
                          if (cVar2 == 0) {
                            iVar7 = 0xc;
                          }
                          else {
                            local_30[0xc] = cVar2;
                            if ((int)cVar2 - 0x41U < 0x1a) {
                              local_30[0xc] = cVar2 + ' ';
                            }
                            cVar2 = name[0xd];
                            if (cVar2 == 0) {
                              iVar7 = 0xd;
                            }
                            else {
                              local_30[0xd] = cVar2;
                              if ((int)cVar2 - 0x41U < 0x1a) {
                                local_30[0xd] = cVar2 + ' ';
                              }
                              cVar2 = name[0xe];
                              if (cVar2 == 0) {
                                iVar7 = 0xe;
                              }
                              else {
                                local_30[0xe] = cVar2;
                                if ((int)cVar2 - 0x41U < 0x1a) {
                                  local_30[0xe] = cVar2 + ' ';
                                }
                                cVar2 = name[0xf];
                                if (cVar2 != 0) {
                                  local_30[0xf] = cVar2;
                                  if ((int)cVar2 - 0x41U < 0x1a) {
                                    local_30[0xf] = cVar2 + ' ';
                                  }
                                  goto LAB_001132d6;
                                }
                                iVar7 = 0xf;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  uVar4 = -iVar7 + 0x10;
  pcVar6 = local_30 + iVar7;
  if (7 < uVar4) {
    if (((uint)pcVar6 & 1) != 0) {
      *pcVar6 = '\0';
      uVar4 = -iVar7 + 0xf;
      pcVar6 = local_30 + iVar7 + 1;
    }
    if (((uint)pcVar6 & 2) != 0) {
      pcVar6[0] = '\0';
      pcVar6[1] = '\0';
      uVar4 = uVar4 - 2;
      pcVar6 = pcVar6 + 2;
    }
    if (7 < uVar4) {
      uVar5 = 0;
      do {
        pcVar1 = pcVar6 + uVar5;
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        pcVar1 = pcVar6 + uVar5 + 4;
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        uVar5 = uVar5 + 8;
      } while (uVar5 < (uVar4 & 0xfffffff8));
      pcVar6 = pcVar6 + uVar5;
    }
  }
  if ((uVar4 & 4) != 0) {
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    pcVar6 = pcVar6 + 4;
  }
  if ((uVar4 & 2) != 0) {
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6 = pcVar6 + 2;
  }
  if ((uVar4 & 1) != 0) {
    *pcVar6 = '\0';
  }
LAB_001132d6:
  iVar7 = 0;
  plVar8 = wads[wad].wad_lumps;
  if (0 < wads[wad].wad_numlumps) {
    do {
      iVar3 = Q_strcmp(local_30,plVar8->name);
      if (iVar3 == 0) {
        if (iStack_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return wads[wad].wad_base + plVar8->filepos;
      }
      iVar7 = iVar7 + 1;
      plVar8 = plVar8 + 1;
    } while (iVar7 < wads[wad].wad_numlumps);
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: lumpinfo_t * lump_p@[???]
                       Unresolved local var: char[16] clean@[???] */
                    /* WARNING: Subroutine does not return */
  Sys_Error("W_GetLumpinfo: %s not found",name);
}


// W_GetLumpNum  @ 001134b0
void * W_GetLumpNum(int wad,int num)

{
                    /* Unresolved local var: lumpinfo_t * lump@[???] */
  if ((-1 < num) && (num <= wads[wad].wad_numlumps)) {
    return wads[wad].wad_base + wads[wad].wad_lumps[num].filepos;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("W_GetLumpNum: bad number: %i",num);
}


// W_GetLumpinfo  @ 00112d50
lumpinfo_t * W_GetLumpinfo(int wad,char *name,qboolean doerror)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  lumpinfo_t *plVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  int in_GS_OFFSET;
  char local_30 [16];
  int iStack_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: lumpinfo_t * lump_p@[???]
                       Unresolved local var: char[16] clean@[???] */
  iStack_20 = *(int *)(in_GS_OFFSET + 0x14);
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???] */
  cVar2 = *name;
  if (cVar2 == 0) {
    iVar8 = 0;
  }
  else {
    local_30[0] = cVar2;
    if ((int)cVar2 - 0x41U < 0x1a) {
      local_30[0] = cVar2 + ' ';
    }
    cVar2 = name[1];
    if (cVar2 == 0) {
      iVar8 = 1;
    }
    else {
      local_30[1] = cVar2;
      if ((int)cVar2 - 0x41U < 0x1a) {
        local_30[1] = cVar2 + ' ';
      }
      cVar2 = name[2];
      if (cVar2 == 0) {
        iVar8 = 2;
      }
      else {
        local_30[2] = cVar2;
        if ((int)cVar2 - 0x41U < 0x1a) {
          local_30[2] = cVar2 + ' ';
        }
        cVar2 = name[3];
        if (cVar2 == 0) {
          iVar8 = 3;
        }
        else {
          local_30[3] = cVar2;
          if ((int)cVar2 - 0x41U < 0x1a) {
            local_30[3] = cVar2 + ' ';
          }
          cVar2 = name[4];
          if (cVar2 == 0) {
            iVar8 = 4;
          }
          else {
            local_30[4] = cVar2;
            if ((int)cVar2 - 0x41U < 0x1a) {
              local_30[4] = cVar2 + ' ';
            }
            cVar2 = name[5];
            if (cVar2 == 0) {
              iVar8 = 5;
            }
            else {
              local_30[5] = cVar2;
              if ((int)cVar2 - 0x41U < 0x1a) {
                local_30[5] = cVar2 + ' ';
              }
              cVar2 = name[6];
              if (cVar2 == 0) {
                iVar8 = 6;
              }
              else {
                local_30[6] = cVar2;
                if ((int)cVar2 - 0x41U < 0x1a) {
                  local_30[6] = cVar2 + ' ';
                }
                cVar2 = name[7];
                if (cVar2 == 0) {
                  iVar8 = 7;
                }
                else {
                  local_30[7] = cVar2;
                  if ((int)cVar2 - 0x41U < 0x1a) {
                    local_30[7] = cVar2 + ' ';
                  }
                  cVar2 = name[8];
                  if (cVar2 == 0) {
                    iVar8 = 8;
                  }
                  else {
                    local_30[8] = cVar2;
                    if ((int)cVar2 - 0x41U < 0x1a) {
                      local_30[8] = cVar2 + ' ';
                    }
                    cVar2 = name[9];
                    if (cVar2 == 0) {
                      iVar8 = 9;
                    }
                    else {
                      local_30[9] = cVar2;
                      if ((int)cVar2 - 0x41U < 0x1a) {
                        local_30[9] = cVar2 + ' ';
                      }
                      cVar2 = name[10];
                      if (cVar2 == 0) {
                        iVar8 = 10;
                      }
                      else {
                        local_30[10] = cVar2;
                        if ((int)cVar2 - 0x41U < 0x1a) {
                          local_30[10] = cVar2 + ' ';
                        }
                        cVar2 = name[0xb];
                        if (cVar2 == 0) {
                          iVar8 = 0xb;
                        }
                        else {
                          local_30[0xb] = cVar2;
                          if ((int)cVar2 - 0x41U < 0x1a) {
                            local_30[0xb] = cVar2 + ' ';
                          }
                          cVar2 = name[0xc];
                          if (cVar2 == 0) {
                            iVar8 = 0xc;
                          }
                          else {
                            local_30[0xc] = cVar2;
                            if ((int)cVar2 - 0x41U < 0x1a) {
                              local_30[0xc] = cVar2 + ' ';
                            }
                            cVar2 = name[0xd];
                            if (cVar2 == 0) {
                              iVar8 = 0xd;
                            }
                            else {
                              local_30[0xd] = cVar2;
                              if ((int)cVar2 - 0x41U < 0x1a) {
                                local_30[0xd] = cVar2 + ' ';
                              }
                              cVar2 = name[0xe];
                              if (cVar2 == 0) {
                                iVar8 = 0xe;
                              }
                              else {
                                local_30[0xe] = cVar2;
                                if ((int)cVar2 - 0x41U < 0x1a) {
                                  local_30[0xe] = cVar2 + ' ';
                                }
                                cVar2 = name[0xf];
                                if (cVar2 != 0) {
                                  local_30[0xf] = cVar2;
                                  if ((int)cVar2 - 0x41U < 0x1a) {
                                    local_30[0xf] = cVar2 + ' ';
                                  }
                                  goto LAB_00112f2a;
                                }
                                iVar8 = 0xf;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  uVar5 = -iVar8 + 0x10;
  pcVar6 = local_30 + iVar8;
  if (7 < uVar5) {
    if (((uint)pcVar6 & 1) != 0) {
      *pcVar6 = '\0';
      uVar5 = -iVar8 + 0xf;
      pcVar6 = local_30 + iVar8 + 1;
    }
    if (((uint)pcVar6 & 2) != 0) {
      pcVar6[0] = '\0';
      pcVar6[1] = '\0';
      uVar5 = uVar5 - 2;
      pcVar6 = pcVar6 + 2;
    }
    if (7 < uVar5) {
      uVar7 = 0;
      do {
        pcVar1 = pcVar6 + uVar7;
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        pcVar1 = pcVar6 + uVar7 + 4;
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        uVar7 = uVar7 + 8;
      } while (uVar7 < (uVar5 & 0xfffffff8));
      pcVar6 = pcVar6 + uVar7;
    }
  }
  if ((uVar5 & 4) != 0) {
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    pcVar6 = pcVar6 + 4;
  }
  if ((uVar5 & 2) != 0) {
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6 = pcVar6 + 2;
  }
  if ((uVar5 & 1) != 0) {
    *pcVar6 = '\0';
  }
LAB_00112f2a:
  iVar8 = 0;
  plVar4 = wads[wad].wad_lumps;
  if (0 < wads[wad].wad_numlumps) {
    do {
      iVar3 = Q_strcmp(local_30,plVar4->name);
      if (iVar3 == 0) goto LAB_00112f78;
      iVar8 = iVar8 + 1;
      plVar4 = plVar4 + 1;
    } while (iVar8 < wads[wad].wad_numlumps);
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: lumpinfo_t * lump_p@[???]
                       Unresolved local var: char[16] clean@[???] */
  if (doerror != false) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("W_GetLumpinfo: %s not found",name);
  }
  plVar4 = (lumpinfo_t *)0x0;
LAB_00112f78:
  if (iStack_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return plVar4;
}


// W_LoadWadFile  @ 00112870
int W_LoadWadFile(char *filename)

{
  char *pcVar1;
  int *piVar2;
  char cVar3;
  int32 iVar4;
  lumpinfo_t *plVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int32 *piVar10;
  int iVar11;
  wadlist_t *pwVar12;
  int local_20;
  
                    /* Unresolved local var: lumpinfo_t * lump_p@[???]
                       Unresolved local var: wadinfo_t * header@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int infotableofs@[???]
                       Unresolved local var: int slot@[???]
                       Unresolved local var: wadlist_t * wad@[???] */
  if (wads[0].loaded == false) {
    wads[0].wad_base = COM_LoadHunkFile(filename);
    if (wads[0].wad_base == (byte *)0x0) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("W_LoadWadFile: couldn\'t load %s",filename);
    }
    pwVar12 = wads;
    local_20 = 0;
LAB_001128da:
    Q_strncpy(pwVar12->wadname,filename,0x1f);
    piVar2 = (int *)pwVar12->wad_base;
    pwVar12->wadname[0x1f] = '\0';
    pwVar12->loaded = true;
    if (*piVar2 != 0x33444157) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("Wad file %s doesn\'t have WAD3 id\n",filename);
    }
    iVar4 = (*LittleLong)(piVar2[1]);
    pwVar12->wad_numlumps = iVar4;
    iVar4 = (*LittleLong)(piVar2[2]);
    plVar5 = (lumpinfo_t *)(pwVar12->wad_base + iVar4);
    pwVar12->wad_lumps = plVar5;
    if (pwVar12->wad_numlumps < 1) {
      return local_20;
    }
    iVar11 = 0;
    do {
      iVar4 = (*LittleLong)(plVar5->filepos);
      plVar5->filepos = iVar4;
      iVar4 = (*LittleLong)(plVar5->size);
      plVar5->size = iVar4;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???] */
      cVar3 = plVar5->name[0];
      if (cVar3 == 0) {
        iVar7 = 0;
LAB_00112b80:
        uVar9 = -iVar7 + 0x10;
        pcVar6 = plVar5->name + iVar7;
        if (7 < uVar9) {
          if (((uint)pcVar6 & 1) != 0) {
            *pcVar6 = '\0';
            pcVar6 = pcVar6 + 1;
            uVar9 = -iVar7 + 0xf;
          }
          if (((uint)pcVar6 & 2) != 0) {
            pcVar6[0] = '\0';
            pcVar6[1] = '\0';
            uVar9 = uVar9 - 2;
            pcVar6 = pcVar6 + 2;
          }
          if (7 < uVar9) {
            uVar8 = 0;
            do {
              pcVar1 = pcVar6 + uVar8;
              pcVar1[0] = '\0';
              pcVar1[1] = '\0';
              pcVar1[2] = '\0';
              pcVar1[3] = '\0';
              pcVar1 = pcVar6 + uVar8 + 4;
              pcVar1[0] = '\0';
              pcVar1[1] = '\0';
              pcVar1[2] = '\0';
              pcVar1[3] = '\0';
              uVar8 = uVar8 + 8;
            } while (uVar8 < (uVar9 & 0xfffffff8));
            pcVar6 = pcVar6 + uVar8;
          }
        }
        if ((uVar9 & 4) != 0) {
          pcVar6[0] = '\0';
          pcVar6[1] = '\0';
          pcVar6[2] = '\0';
          pcVar6[3] = '\0';
          pcVar6 = pcVar6 + 4;
        }
        if ((uVar9 & 2) != 0) {
          pcVar6[0] = '\0';
          pcVar6[1] = '\0';
          pcVar6 = pcVar6 + 2;
        }
        if ((uVar9 & 1) != 0) {
          *pcVar6 = '\0';
        }
      }
      else {
        if ((int)cVar3 - 0x41U < 0x1a) {
          cVar3 = cVar3 + ' ';
        }
        plVar5->name[0] = cVar3;
        cVar3 = plVar5->name[1];
        if (cVar3 == 0) {
          iVar7 = 1;
          goto LAB_00112b80;
        }
        if ((int)cVar3 - 0x41U < 0x1a) {
          cVar3 = cVar3 + ' ';
        }
        plVar5->name[1] = cVar3;
        cVar3 = plVar5->name[2];
        if (cVar3 == 0) {
          iVar7 = 2;
          goto LAB_00112b80;
        }
        if ((int)cVar3 - 0x41U < 0x1a) {
          cVar3 = cVar3 + ' ';
        }
        plVar5->name[2] = cVar3;
        cVar3 = plVar5->name[3];
        if (cVar3 == 0) {
          iVar7 = 3;
          goto LAB_00112b80;
        }
        if ((int)cVar3 - 0x41U < 0x1a) {
          cVar3 = cVar3 + ' ';
        }
        plVar5->name[3] = cVar3;
        cVar3 = plVar5->name[4];
        if (cVar3 == 0) {
          iVar7 = 4;
          goto LAB_00112b80;
        }
        if ((int)cVar3 - 0x41U < 0x1a) {
          cVar3 = cVar3 + ' ';
        }
        plVar5->name[4] = cVar3;
        cVar3 = plVar5->name[5];
        if (cVar3 == 0) {
          iVar7 = 5;
          goto LAB_00112b80;
        }
        if ((int)cVar3 - 0x41U < 0x1a) {
          cVar3 = cVar3 + ' ';
        }
        plVar5->name[5] = cVar3;
        cVar3 = plVar5->name[6];
        if (cVar3 == 0) {
          iVar7 = 6;
          goto LAB_00112b80;
        }
        if ((int)cVar3 - 0x41U < 0x1a) {
          cVar3 = cVar3 + ' ';
        }
        plVar5->name[6] = cVar3;
        cVar3 = plVar5->name[7];
        if (cVar3 == 0) {
          iVar7 = 7;
          goto LAB_00112b80;
        }
        if ((int)cVar3 - 0x41U < 0x1a) {
          cVar3 = cVar3 + ' ';
        }
        plVar5->name[7] = cVar3;
        cVar3 = plVar5->name[8];
        if (cVar3 == 0) {
          iVar7 = 8;
          goto LAB_00112b80;
        }
        if ((int)cVar3 - 0x41U < 0x1a) {
          cVar3 = cVar3 + ' ';
        }
        plVar5->name[8] = cVar3;
        cVar3 = plVar5->name[9];
        if (cVar3 == 0) {
          iVar7 = 9;
          goto LAB_00112b80;
        }
        if ((int)cVar3 - 0x41U < 0x1a) {
          cVar3 = cVar3 + ' ';
        }
        plVar5->name[9] = cVar3;
        cVar3 = plVar5->name[10];
        if (cVar3 == 0) {
          iVar7 = 10;
          goto LAB_00112b80;
        }
        if ((int)cVar3 - 0x41U < 0x1a) {
          cVar3 = cVar3 + ' ';
        }
        plVar5->name[10] = cVar3;
        cVar3 = plVar5->name[0xb];
        if (cVar3 == 0) {
          iVar7 = 0xb;
          goto LAB_00112b80;
        }
        if ((int)cVar3 - 0x41U < 0x1a) {
          cVar3 = cVar3 + ' ';
        }
        plVar5->name[0xb] = cVar3;
        cVar3 = plVar5->name[0xc];
        if (cVar3 == 0) {
          iVar7 = 0xc;
          goto LAB_00112b80;
        }
        if ((int)cVar3 - 0x41U < 0x1a) {
          cVar3 = cVar3 + ' ';
        }
        plVar5->name[0xc] = cVar3;
        cVar3 = plVar5->name[0xd];
        if (cVar3 == 0) {
          iVar7 = 0xd;
          goto LAB_00112b80;
        }
        if ((int)cVar3 - 0x41U < 0x1a) {
          cVar3 = cVar3 + ' ';
        }
        plVar5->name[0xd] = cVar3;
        cVar3 = plVar5->name[0xe];
        if (cVar3 == 0) {
          iVar7 = 0xe;
          goto LAB_00112b80;
        }
        if ((int)cVar3 - 0x41U < 0x1a) {
          cVar3 = cVar3 + ' ';
        }
        plVar5->name[0xe] = cVar3;
        cVar3 = plVar5->name[0xf];
        if (cVar3 == 0) {
          iVar7 = 0xf;
          goto LAB_00112b80;
        }
        if ((int)cVar3 - 0x41U < 0x1a) {
          cVar3 = cVar3 + ' ';
        }
        plVar5->name[0xf] = cVar3;
      }
      if (plVar5->type == 'B') {
        piVar2 = &plVar5->filepos;
        iVar11 = iVar11 + 1;
        plVar5 = plVar5 + 1;
        piVar10 = (int32 *)(pwVar12->wad_base + *piVar2);
        iVar4 = (*LittleLong)(*piVar10);
        *piVar10 = iVar4;
        iVar4 = (*LittleLong)(piVar10[1]);
        piVar10[1] = iVar4;
        if (pwVar12->wad_numlumps <= iVar11) {
          return local_20;
        }
      }
      else {
        iVar11 = iVar11 + 1;
        plVar5 = plVar5 + 1;
        if (pwVar12->wad_numlumps <= iVar11) {
          return local_20;
        }
      }
    } while( true );
  }
  if (wads[1].loaded == false) {
    wads[1].wad_base = COM_LoadHunkFile(filename);
    if (wads[1].wad_base != (byte *)0x0) {
      pwVar12 = wads + 1;
      local_20 = 1;
      goto LAB_001128da;
    }
    Con_Printf("WARNING:  W_LoadWadFile, couldn\'t load %s\n",filename);
  }
  else {
    Con_Printf("No room for wad %s\n",filename);
  }
  return -1;
}


// W_Shutdown  @ 00113510
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void W_Shutdown(void)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  
                    /* Unresolved local var: int slot@[???]
                       Unresolved local var: wadlist_t * wad@[???] */
  if (wads[0].loaded != false) {
    uVar3 = 0;
    do {
      pcVar1 = wads[0].wadname + (uVar3 - 4);
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      uVar2 = uVar3 + 8;
      pcVar1 = wads[0].wadname + uVar3;
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      uVar3 = uVar2;
    } while (uVar2 < 0x30);
    uVar3 = 0;
    if (wads[1].loaded != false) {
      do {
        pcVar1 = wads[1].wadname + (uVar3 - 4);
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        uVar2 = uVar3 + 8;
        pcVar1 = wads[1].wadname + uVar3;
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        uVar3 = uVar2;
      } while (uVar2 < 0x30);
    }
  }
  return;
}


