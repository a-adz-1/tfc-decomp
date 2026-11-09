// W_CleanupName  @ 0016fe60
void W_CleanupName(char *in,char *out)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  undefined1 (*pauVar5) [16];
  uint uVar6;
  uint uVar7;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???] */
  cVar3 = *in;
  if (cVar3 == 0) {
    uVar1 = 0;
  }
  else {
    if ((int)cVar3 - 0x41U < 0x1a) {
      cVar3 = cVar3 + ' ';
    }
    *out = cVar3;
    cVar3 = in[1];
    if (cVar3 == 0) {
      uVar1 = 1;
    }
    else {
      if ((int)cVar3 - 0x41U < 0x1a) {
        cVar3 = cVar3 + ' ';
      }
      out[1] = cVar3;
      cVar3 = in[2];
      if (cVar3 == 0) {
        uVar1 = 2;
      }
      else {
        if ((int)cVar3 - 0x41U < 0x1a) {
          cVar3 = cVar3 + ' ';
        }
        out[2] = cVar3;
        cVar3 = in[3];
        if (cVar3 == 0) {
          uVar1 = 3;
        }
        else {
          if ((int)cVar3 - 0x41U < 0x1a) {
            cVar3 = cVar3 + ' ';
          }
          out[3] = cVar3;
          cVar3 = in[4];
          if (cVar3 == 0) {
            uVar1 = 4;
          }
          else {
            if ((int)cVar3 - 0x41U < 0x1a) {
              cVar3 = cVar3 + ' ';
            }
            out[4] = cVar3;
            cVar3 = in[5];
            if (cVar3 == 0) {
              uVar1 = 5;
            }
            else {
              if ((int)cVar3 - 0x41U < 0x1a) {
                cVar3 = cVar3 + ' ';
              }
              out[5] = cVar3;
              cVar3 = in[6];
              if (cVar3 == 0) {
                uVar1 = 6;
              }
              else {
                if ((int)cVar3 - 0x41U < 0x1a) {
                  cVar3 = cVar3 + ' ';
                }
                out[6] = cVar3;
                cVar3 = in[7];
                if (cVar3 == 0) {
                  uVar1 = 7;
                }
                else {
                  if ((int)cVar3 - 0x41U < 0x1a) {
                    cVar3 = cVar3 + ' ';
                  }
                  out[7] = cVar3;
                  cVar3 = in[8];
                  if (cVar3 == 0) {
                    uVar1 = 8;
                  }
                  else {
                    if ((int)cVar3 - 0x41U < 0x1a) {
                      cVar3 = cVar3 + ' ';
                    }
                    out[8] = cVar3;
                    cVar3 = in[9];
                    if (cVar3 == 0) {
                      uVar1 = 9;
                    }
                    else {
                      if ((int)cVar3 - 0x41U < 0x1a) {
                        cVar3 = cVar3 + ' ';
                      }
                      out[9] = cVar3;
                      cVar3 = in[10];
                      if (cVar3 == 0) {
                        uVar1 = 10;
                      }
                      else {
                        if ((int)cVar3 - 0x41U < 0x1a) {
                          cVar3 = cVar3 + ' ';
                        }
                        out[10] = cVar3;
                        cVar3 = in[0xb];
                        if (cVar3 == 0) {
                          uVar1 = 0xb;
                        }
                        else {
                          if ((int)cVar3 - 0x41U < 0x1a) {
                            cVar3 = cVar3 + ' ';
                          }
                          out[0xb] = cVar3;
                          cVar3 = in[0xc];
                          if (cVar3 == 0) {
                            uVar1 = 0xc;
                          }
                          else {
                            if ((int)cVar3 - 0x41U < 0x1a) {
                              cVar3 = cVar3 + ' ';
                            }
                            out[0xc] = cVar3;
                            cVar3 = in[0xd];
                            if (cVar3 == 0) {
                              uVar1 = 0xd;
                            }
                            else {
                              if ((int)cVar3 - 0x41U < 0x1a) {
                                cVar3 = cVar3 + ' ';
                              }
                              out[0xd] = cVar3;
                              cVar3 = in[0xe];
                              if (cVar3 == 0) {
                                uVar1 = 0xe;
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
                                uVar1 = 0xf;
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
  uVar6 = ~uVar1 + 0x11;
  uVar4 = -(int)(out + uVar1) & 0xf;
  if (uVar6 < uVar4) {
    uVar4 = uVar6;
  }
  uVar2 = uVar1;
  if (uVar4 != 0) {
    do {
      out[uVar2] = '\0';
      uVar2 = uVar2 + 1;
    } while (uVar2 - uVar1 < uVar4);
    if (uVar6 == uVar4) {
      return;
    }
  }
  uVar7 = uVar6 - uVar4 >> 4;
  if (uVar7 != 0) {
    pauVar5 = (undefined1 (*) [16])(out + uVar1 + uVar4);
    uVar1 = 0;
    do {
      uVar1 = uVar1 + 1;
      *pauVar5 = (undefined1  [16])0x0;
      pauVar5 = pauVar5 + 1;
    } while (uVar1 < uVar7);
    uVar2 = uVar2 + uVar7 * 0x10;
    if (uVar6 - uVar4 == uVar7 * 0x10) {
      return;
    }
  }
  do {
    out[uVar2] = '\0';
    if (uVar2 + 1 == 0x10) {
      return;
    }
    out[uVar2 + 1] = '\0';
    uVar2 = uVar2 + 2;
  } while (uVar2 != 0x10);
  return;
}


// W_GetLumpName  @ 001709b0
void * W_GetLumpName(int wad,char *name)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 (*pauVar6) [16];
  uint uVar7;
  lumpinfo_t *plVar8;
  int iVar9;
  uint uVar10;
  char local_2c [5];
  char local_27;
  char local_26;
  char local_25;
  char local_24;
  char local_23;
  char local_22;
  char local_21;
  char local_20;
  char local_1f;
  char local_1e;
  char local_1d;
  
                    /* Unresolved local var: lumpinfo_t * lump@[DW_OP_reg3(EBX)] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: lumpinfo_t * lump_p@[???]
                       Unresolved local var: char[16] clean@[???]
                       Unresolved local var: int c@[???] */
  cVar1 = *name;
  if (cVar1 == 0) {
    uVar3 = 0;
  }
  else {
    local_2c[0] = cVar1;
    if ((int)cVar1 - 0x41U < 0x1a) {
      local_2c[0] = cVar1 + ' ';
    }
    cVar1 = name[1];
    if (cVar1 == 0) {
      uVar3 = 1;
    }
    else {
      local_2c[1] = cVar1;
      if ((int)cVar1 - 0x41U < 0x1a) {
        local_2c[1] = cVar1 + ' ';
      }
      cVar1 = name[2];
      if (cVar1 == 0) {
        uVar3 = 2;
      }
      else {
        local_2c[2] = cVar1;
        if ((int)cVar1 - 0x41U < 0x1a) {
          local_2c[2] = cVar1 + ' ';
        }
        cVar1 = name[3];
        if (cVar1 == 0) {
          uVar3 = 3;
        }
        else {
          local_2c[3] = cVar1;
          if ((int)cVar1 - 0x41U < 0x1a) {
            local_2c[3] = cVar1 + ' ';
          }
          cVar1 = name[4];
          if (cVar1 == 0) {
            uVar3 = 4;
          }
          else {
            local_2c[4] = cVar1;
            if ((int)cVar1 - 0x41U < 0x1a) {
              local_2c[4] = cVar1 + ' ';
            }
            cVar1 = name[5];
            if (cVar1 == 0) {
              uVar3 = 5;
            }
            else {
              local_27 = cVar1;
              if ((int)cVar1 - 0x41U < 0x1a) {
                local_27 = cVar1 + ' ';
              }
              cVar1 = name[6];
              if (cVar1 == 0) {
                uVar3 = 6;
              }
              else {
                local_26 = cVar1;
                if ((int)cVar1 - 0x41U < 0x1a) {
                  local_26 = cVar1 + ' ';
                }
                cVar1 = name[7];
                if (cVar1 == 0) {
                  uVar3 = 7;
                }
                else {
                  local_25 = cVar1;
                  if ((int)cVar1 - 0x41U < 0x1a) {
                    local_25 = cVar1 + ' ';
                  }
                  cVar1 = name[8];
                  if (cVar1 == 0) {
                    uVar3 = 8;
                  }
                  else {
                    local_24 = cVar1;
                    if ((int)cVar1 - 0x41U < 0x1a) {
                      local_24 = cVar1 + ' ';
                    }
                    cVar1 = name[9];
                    if (cVar1 == 0) {
                      uVar3 = 9;
                    }
                    else {
                      local_23 = cVar1;
                      if ((int)cVar1 - 0x41U < 0x1a) {
                        local_23 = cVar1 + ' ';
                      }
                      cVar1 = name[10];
                      if (cVar1 == 0) {
                        uVar3 = 10;
                      }
                      else {
                        local_22 = cVar1;
                        if ((int)cVar1 - 0x41U < 0x1a) {
                          local_22 = cVar1 + ' ';
                        }
                        cVar1 = name[0xb];
                        if (cVar1 == 0) {
                          uVar3 = 0xb;
                        }
                        else {
                          local_21 = cVar1;
                          if ((int)cVar1 - 0x41U < 0x1a) {
                            local_21 = cVar1 + ' ';
                          }
                          cVar1 = name[0xc];
                          if (cVar1 == 0) {
                            uVar3 = 0xc;
                          }
                          else {
                            local_20 = cVar1;
                            if ((int)cVar1 - 0x41U < 0x1a) {
                              local_20 = cVar1 + ' ';
                            }
                            cVar1 = name[0xd];
                            if (cVar1 == 0) {
                              uVar3 = 0xd;
                            }
                            else {
                              local_1f = cVar1;
                              if ((int)cVar1 - 0x41U < 0x1a) {
                                local_1f = cVar1 + ' ';
                              }
                              cVar1 = name[0xe];
                              if (cVar1 == 0) {
                                uVar3 = 0xe;
                              }
                              else {
                                local_1e = cVar1;
                                if ((int)cVar1 - 0x41U < 0x1a) {
                                  local_1e = cVar1 + ' ';
                                }
                                cVar1 = name[0xf];
                                if (cVar1 != 0) {
                                  local_1d = cVar1;
                                  if ((int)cVar1 - 0x41U < 0x1a) {
                                    local_1d = cVar1 + ' ';
                                  }
                                  goto LAB_00170b7b;
                                }
                                uVar3 = 0xf;
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
  uVar10 = ~uVar3 + 0x11;
  uVar5 = -(int)(local_2c + uVar3) & 0xfU;
  if (uVar10 < (-(int)(local_2c + uVar3) & 0xfU)) {
    uVar5 = uVar10;
  }
  uVar4 = uVar3;
  if (uVar5 != 0) {
    do {
      local_2c[uVar4] = '\0';
      uVar4 = uVar4 + 1;
    } while (uVar4 - uVar3 < uVar5);
    if (uVar10 == uVar5) goto LAB_00170b7b;
  }
  uVar7 = uVar10 - uVar5 >> 4;
  if (uVar7 != 0) {
    pauVar6 = (undefined1 (*) [16])(local_2c + uVar5 + uVar3);
    uVar3 = 0;
    do {
      uVar3 = uVar3 + 1;
      *pauVar6 = (undefined1  [16])0x0;
      pauVar6 = pauVar6 + 1;
    } while (uVar3 < uVar7);
    uVar4 = uVar4 + uVar7 * 0x10;
    if (uVar10 - uVar5 == uVar7 * 0x10) goto LAB_00170b7b;
  }
  do {
    local_2c[uVar4] = '\0';
    if (uVar4 == 0xf) break;
    local_2c[uVar4 + 1] = '\0';
    uVar4 = uVar4 + 2;
  } while (uVar4 != 0x10);
LAB_00170b7b:
  plVar8 = wads[wad].wad_lumps;
  if (0 < wads[wad].wad_numlumps) {
    iVar9 = 0;
    do {
      iVar2 = Q_strcmp(local_2c,plVar8->name);
      if (iVar2 == 0) goto LAB_00170bd4;
      iVar9 = iVar9 + 1;
      plVar8 = plVar8 + 1;
    } while (iVar9 < wads[wad].wad_numlumps);
  }
  plVar8 = (lumpinfo_t *)0x0;
  Sys_Error("W_GetLumpinfo: %s not found",name);
LAB_00170bd4:
  return wads[wad].wad_base + plVar8->filepos;
}


// W_GetLumpNum  @ 00170d40
void * W_GetLumpNum(int wad,int num)

{
                    /* Unresolved local var: lumpinfo_t * lump@[???] */
  if ((num < 0) || (wads[wad].wad_numlumps < num)) {
    Sys_Error("W_GetLumpNum: bad number: %i",num);
  }
  return wads[wad].wad_base + wads[wad].wad_lumps[num].filepos;
}


// W_GetLumpinfo  @ 00170610
lumpinfo_t * W_GetLumpinfo(int wad,char *name,qboolean doerror)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 (*pauVar5) [16];
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  lumpinfo_t *plVar10;
  uint uVar11;
  char local_2c [5];
  char local_27;
  char local_26;
  char local_25;
  char local_24;
  char local_23;
  char local_22;
  char local_21;
  char local_20;
  char local_1f;
  char local_1e;
  char local_1d;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: lumpinfo_t * lump_p@[???]
                       Unresolved local var: char[16] clean@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???] */
  cVar1 = *name;
  if (cVar1 == 0) {
    uVar3 = 0;
  }
  else {
    local_2c[0] = cVar1;
    if ((int)cVar1 - 0x41U < 0x1a) {
      local_2c[0] = cVar1 + ' ';
    }
    cVar1 = name[1];
    if (cVar1 == 0) {
      uVar3 = 1;
    }
    else {
      local_2c[1] = cVar1;
      if ((int)cVar1 - 0x41U < 0x1a) {
        local_2c[1] = cVar1 + ' ';
      }
      cVar1 = name[2];
      if (cVar1 == 0) {
        uVar3 = 2;
      }
      else {
        local_2c[2] = cVar1;
        if ((int)cVar1 - 0x41U < 0x1a) {
          local_2c[2] = cVar1 + ' ';
        }
        cVar1 = name[3];
        if (cVar1 == 0) {
          uVar3 = 3;
        }
        else {
          local_2c[3] = cVar1;
          if ((int)cVar1 - 0x41U < 0x1a) {
            local_2c[3] = cVar1 + ' ';
          }
          cVar1 = name[4];
          if (cVar1 == 0) {
            uVar3 = 4;
          }
          else {
            local_2c[4] = cVar1;
            if ((int)cVar1 - 0x41U < 0x1a) {
              local_2c[4] = cVar1 + ' ';
            }
            cVar1 = name[5];
            if (cVar1 == 0) {
              uVar3 = 5;
            }
            else {
              local_27 = cVar1;
              if ((int)cVar1 - 0x41U < 0x1a) {
                local_27 = cVar1 + ' ';
              }
              cVar1 = name[6];
              if (cVar1 == 0) {
                uVar3 = 6;
              }
              else {
                local_26 = cVar1;
                if ((int)cVar1 - 0x41U < 0x1a) {
                  local_26 = cVar1 + ' ';
                }
                cVar1 = name[7];
                if (cVar1 == 0) {
                  uVar3 = 7;
                }
                else {
                  local_25 = cVar1;
                  if ((int)cVar1 - 0x41U < 0x1a) {
                    local_25 = cVar1 + ' ';
                  }
                  cVar1 = name[8];
                  if (cVar1 == 0) {
                    uVar3 = 8;
                  }
                  else {
                    local_24 = cVar1;
                    if ((int)cVar1 - 0x41U < 0x1a) {
                      local_24 = cVar1 + ' ';
                    }
                    cVar1 = name[9];
                    if (cVar1 == 0) {
                      uVar3 = 9;
                    }
                    else {
                      local_23 = cVar1;
                      if ((int)cVar1 - 0x41U < 0x1a) {
                        local_23 = cVar1 + ' ';
                      }
                      cVar1 = name[10];
                      if (cVar1 == 0) {
                        uVar3 = 10;
                      }
                      else {
                        local_22 = cVar1;
                        if ((int)cVar1 - 0x41U < 0x1a) {
                          local_22 = cVar1 + ' ';
                        }
                        cVar1 = name[0xb];
                        if (cVar1 == 0) {
                          uVar3 = 0xb;
                        }
                        else {
                          local_21 = cVar1;
                          if ((int)cVar1 - 0x41U < 0x1a) {
                            local_21 = cVar1 + ' ';
                          }
                          cVar1 = name[0xc];
                          if (cVar1 == 0) {
                            uVar3 = 0xc;
                          }
                          else {
                            local_20 = cVar1;
                            if ((int)cVar1 - 0x41U < 0x1a) {
                              local_20 = cVar1 + ' ';
                            }
                            cVar1 = name[0xd];
                            if (cVar1 == 0) {
                              uVar3 = 0xd;
                            }
                            else {
                              local_1f = cVar1;
                              if ((int)cVar1 - 0x41U < 0x1a) {
                                local_1f = cVar1 + ' ';
                              }
                              cVar1 = name[0xe];
                              if (cVar1 == 0) {
                                uVar3 = 0xe;
                              }
                              else {
                                local_1e = cVar1;
                                if ((int)cVar1 - 0x41U < 0x1a) {
                                  local_1e = cVar1 + ' ';
                                }
                                cVar1 = name[0xf];
                                if (cVar1 != 0) {
                                  local_1d = cVar1;
                                  if ((int)cVar1 - 0x41U < 0x1a) {
                                    local_1d = cVar1 + ' ';
                                  }
                                  goto LAB_001707da;
                                }
                                uVar3 = 0xf;
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
  uVar9 = ~uVar3 + 0x11;
  uVar6 = -(int)(local_2c + uVar3) & 0xfU;
  if (uVar9 < (-(int)(local_2c + uVar3) & 0xfU)) {
    uVar6 = uVar9;
  }
  uVar4 = uVar3;
  if (uVar6 != 0) {
    do {
      local_2c[uVar4] = '\0';
      uVar4 = uVar4 + 1;
    } while (uVar4 - uVar3 < uVar6);
    if (uVar9 == uVar6) goto LAB_001707da;
  }
  uVar11 = uVar9 - uVar6 >> 4;
  if (uVar11 != 0) {
    uVar7 = 0;
    pauVar5 = (undefined1 (*) [16])(local_2c + uVar3 + uVar6);
    do {
      uVar7 = uVar7 + 1;
      *pauVar5 = (undefined1  [16])0x0;
      pauVar5 = pauVar5 + 1;
    } while (uVar7 < uVar11);
    uVar4 = uVar4 + uVar11 * 0x10;
    if (uVar9 - uVar6 == uVar11 * 0x10) goto LAB_001707da;
  }
  do {
    local_2c[uVar4] = '\0';
    if (uVar4 == 0xf) break;
    local_2c[uVar4 + 1] = '\0';
    uVar4 = uVar4 + 2;
  } while (uVar4 != 0x10);
LAB_001707da:
  plVar10 = wads[wad].wad_lumps;
  if (0 < wads[wad].wad_numlumps) {
    iVar8 = 0;
    do {
      iVar2 = Q_strcmp(local_2c,plVar10->name);
      if (iVar2 == 0) {
        return plVar10;
      }
      iVar8 = iVar8 + 1;
      plVar10 = plVar10 + 1;
    } while (iVar8 < wads[wad].wad_numlumps);
  }
  if (doerror == false) {
    return (lumpinfo_t *)0x0;
  }
  Sys_Error("W_GetLumpinfo: %s not found",name);
  return (lumpinfo_t *)0x0;
}


// W_LoadWadFile  @ 00170140
int W_LoadWadFile(char *filename)

{
  int *piVar1;
  char cVar2;
  byte *pbVar3;
  int32 iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  lumpinfo_t *plVar9;
  uint uVar10;
  int32 *piVar11;
  uint uVar12;
  int local_30;
  wadlist_t *local_24;
  int local_20;
  
                    /* Unresolved local var: lumpinfo_t * lump_p@[???]
                       Unresolved local var: wadinfo_t * header@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int infotableofs@[???]
                       Unresolved local var: int slot@[???]
                       Unresolved local var: wadlist_t * wad@[???] */
  if (wads[0].loaded == false) {
    local_24 = wads;
    local_20 = 0;
  }
  else {
    if (wads[1].loaded != false) {
      Con_Printf("No room for wad %s\n",filename);
      return -1;
    }
    local_24 = wads + 1;
    local_20 = 1;
  }
  pbVar3 = COM_LoadHunkFile(filename);
  local_24->wad_base = pbVar3;
  if (pbVar3 == (byte *)0x0) {
    if (local_20 != 0) {
      Con_Printf("WARNING:  W_LoadWadFile, couldn\'t load %s\n",filename);
      return -1;
    }
    Sys_Error("W_LoadWadFile: couldn\'t load %s");
  }
  Q_strncpy(local_24->wadname,filename,0x1f);
  piVar1 = (int *)local_24->wad_base;
  local_24->wadname[0x1f] = '\0';
  local_24->loaded = true;
  if (*piVar1 != 0x33444157) {
    Sys_Error("Wad file %s doesn\'t have WAD3 id\n",filename);
  }
  iVar4 = (*LittleLong)(piVar1[1]);
  local_24->wad_numlumps = iVar4;
  iVar4 = (*LittleLong)(piVar1[2]);
  plVar9 = (lumpinfo_t *)(local_24->wad_base + iVar4);
  local_24->wad_lumps = plVar9;
  if (0 < local_24->wad_numlumps) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int c@[???] */
    local_30 = 0;
    do {
      iVar4 = (*LittleLong)(plVar9->filepos);
      plVar9->filepos = iVar4;
      iVar4 = (*LittleLong)(plVar9->size);
      plVar9->size = iVar4;
      cVar2 = plVar9->name[0];
      if (cVar2 == 0) {
        uVar6 = 0;
LAB_001704a0:
        uVar10 = ~uVar6 + 0x11;
        uVar8 = -(int)(plVar9->name + (uVar6 - 0x10)) & 0xf;
        if (uVar10 < uVar8) {
          uVar8 = uVar10;
        }
        uVar5 = uVar6;
        if (uVar8 != 0) {
          do {
            plVar9->name[uVar5] = '\0';
            uVar5 = uVar5 + 1;
          } while (uVar5 - uVar6 < uVar8);
          if (uVar10 == uVar8) goto LAB_00170433;
        }
        uVar12 = uVar10 - uVar8 >> 4;
        if (uVar12 != 0) {
          pcVar7 = plVar9->name + (uVar6 - 0x10) + uVar8 + 0x10;
          uVar6 = 0;
          do {
            uVar6 = uVar6 + 1;
            pcVar7[0] = '\0';
            pcVar7[1] = '\0';
            pcVar7[2] = '\0';
            pcVar7[3] = '\0';
            pcVar7[4] = '\0';
            pcVar7[5] = '\0';
            pcVar7[6] = '\0';
            pcVar7[7] = '\0';
            pcVar7[8] = '\0';
            pcVar7[9] = '\0';
            pcVar7[10] = '\0';
            pcVar7[0xb] = '\0';
            pcVar7[0xc] = '\0';
            pcVar7[0xd] = '\0';
            pcVar7[0xe] = '\0';
            pcVar7[0xf] = '\0';
            pcVar7 = pcVar7 + 0x10;
          } while (uVar6 < uVar12);
          uVar5 = uVar5 + uVar12 * 0x10;
          if (uVar10 - uVar8 == uVar12 * 0x10) goto LAB_00170433;
        }
        do {
          plVar9->name[uVar5] = '\0';
          if (uVar5 == 0xf) break;
          plVar9->name[uVar5 + 1] = '\0';
          uVar5 = uVar5 + 2;
        } while (uVar5 != 0x10);
      }
      else {
        if ((int)cVar2 - 0x41U < 0x1a) {
          cVar2 = cVar2 + ' ';
        }
        plVar9->name[0] = cVar2;
        cVar2 = plVar9->name[1];
        if (cVar2 == 0) {
          uVar6 = 1;
          goto LAB_001704a0;
        }
        if ((int)cVar2 - 0x41U < 0x1a) {
          cVar2 = cVar2 + ' ';
        }
        plVar9->name[1] = cVar2;
        cVar2 = plVar9->name[2];
        if (cVar2 == 0) {
          uVar6 = 2;
          goto LAB_001704a0;
        }
        if ((int)cVar2 - 0x41U < 0x1a) {
          cVar2 = cVar2 + ' ';
        }
        plVar9->name[2] = cVar2;
        cVar2 = plVar9->name[3];
        if (cVar2 == 0) {
          uVar6 = 3;
          goto LAB_001704a0;
        }
        if ((int)cVar2 - 0x41U < 0x1a) {
          cVar2 = cVar2 + ' ';
        }
        plVar9->name[3] = cVar2;
        cVar2 = plVar9->name[4];
        if (cVar2 == 0) {
          uVar6 = 4;
          goto LAB_001704a0;
        }
        if ((int)cVar2 - 0x41U < 0x1a) {
          cVar2 = cVar2 + ' ';
        }
        plVar9->name[4] = cVar2;
        cVar2 = plVar9->name[5];
        if (cVar2 == 0) {
          uVar6 = 5;
          goto LAB_001704a0;
        }
        if ((int)cVar2 - 0x41U < 0x1a) {
          cVar2 = cVar2 + ' ';
        }
        plVar9->name[5] = cVar2;
        cVar2 = plVar9->name[6];
        if (cVar2 == 0) {
          uVar6 = 6;
          goto LAB_001704a0;
        }
        if ((int)cVar2 - 0x41U < 0x1a) {
          cVar2 = cVar2 + ' ';
        }
        plVar9->name[6] = cVar2;
        cVar2 = plVar9->name[7];
        if (cVar2 == 0) {
          uVar6 = 7;
          goto LAB_001704a0;
        }
        if ((int)cVar2 - 0x41U < 0x1a) {
          cVar2 = cVar2 + ' ';
        }
        plVar9->name[7] = cVar2;
        cVar2 = plVar9->name[8];
        if (cVar2 == 0) {
          uVar6 = 8;
          goto LAB_001704a0;
        }
        if ((int)cVar2 - 0x41U < 0x1a) {
          cVar2 = cVar2 + ' ';
        }
        plVar9->name[8] = cVar2;
        cVar2 = plVar9->name[9];
        if (cVar2 == 0) {
          uVar6 = 9;
          goto LAB_001704a0;
        }
        if ((int)cVar2 - 0x41U < 0x1a) {
          cVar2 = cVar2 + ' ';
        }
        plVar9->name[9] = cVar2;
        cVar2 = plVar9->name[10];
        if (cVar2 == 0) {
          uVar6 = 10;
          goto LAB_001704a0;
        }
        if ((int)cVar2 - 0x41U < 0x1a) {
          cVar2 = cVar2 + ' ';
        }
        plVar9->name[10] = cVar2;
        cVar2 = plVar9->name[0xb];
        if (cVar2 == 0) {
          uVar6 = 0xb;
          goto LAB_001704a0;
        }
        if ((int)cVar2 - 0x41U < 0x1a) {
          cVar2 = cVar2 + ' ';
        }
        plVar9->name[0xb] = cVar2;
        cVar2 = plVar9->name[0xc];
        if (cVar2 == 0) {
          uVar6 = 0xc;
          goto LAB_001704a0;
        }
        if ((int)cVar2 - 0x41U < 0x1a) {
          cVar2 = cVar2 + ' ';
        }
        plVar9->name[0xc] = cVar2;
        cVar2 = plVar9->name[0xd];
        if (cVar2 == 0) {
          uVar6 = 0xd;
          goto LAB_001704a0;
        }
        if ((int)cVar2 - 0x41U < 0x1a) {
          cVar2 = cVar2 + ' ';
        }
        plVar9->name[0xd] = cVar2;
        cVar2 = plVar9->name[0xe];
        if (cVar2 == 0) {
          uVar6 = 0xe;
          goto LAB_001704a0;
        }
        if ((int)cVar2 - 0x41U < 0x1a) {
          cVar2 = cVar2 + ' ';
        }
        plVar9->name[0xe] = cVar2;
        cVar2 = plVar9->name[0xf];
        if (cVar2 == 0) {
          uVar6 = 0xf;
          goto LAB_001704a0;
        }
        if ((int)cVar2 - 0x41U < 0x1a) {
          cVar2 = cVar2 + ' ';
        }
        plVar9->name[0xf] = cVar2;
      }
LAB_00170433:
      if (plVar9->type == 'B') {
        piVar11 = (int32 *)(local_24->wad_base + plVar9->filepos);
        iVar4 = (*LittleLong)(*piVar11);
        *piVar11 = iVar4;
        iVar4 = (*LittleLong)(piVar11[1]);
        piVar11[1] = iVar4;
      }
      local_30 = local_30 + 1;
      plVar9 = plVar9 + 1;
    } while (local_30 < local_24->wad_numlumps);
  }
  return local_20;
}


// W_Shutdown  @ 00170da0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void W_Shutdown(void)

{
  char *pcVar1;
  uint uVar2;
  
                    /* Unresolved local var: int slot@[???]
                       Unresolved local var: wadlist_t * wad@[???] */
  if (wads[0].loaded != false) {
    uVar2 = 0;
    do {
      pcVar1 = wads[0].wadname + (uVar2 - 4);
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      pcVar1 = wads[0].wadname + uVar2;
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      pcVar1 = wads[0].wadname + uVar2 + 4;
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      pcVar1 = wads[0].wadname + uVar2 + 8;
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      uVar2 = uVar2 + 0x10;
    } while (uVar2 < 0x30);
    if (wads[1].loaded != false) {
      uVar2 = 0;
      do {
        pcVar1 = wads[1].wadname + (uVar2 - 4);
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        pcVar1 = wads[1].wadname + uVar2;
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        pcVar1 = wads[1].wadname + uVar2 + 4;
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        pcVar1 = wads[1].wadname + uVar2 + 8;
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        uVar2 = uVar2 + 0x10;
      } while (uVar2 < 0x30);
    }
  }
  return;
}


