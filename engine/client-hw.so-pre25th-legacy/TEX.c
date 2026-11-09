// TEX_AddAnimatingTextures  @ 0016fc90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void TEX_AddAnimatingTextures(void)

{
  int iVar1;
  int iVar2;
  char (*pacVar3) [64];
  char cVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char (*local_48) [64];
  int local_44;
  char local_3c;
  char local_3b;
  undefined1 local_1d;
  
                    /* Unresolved local var: int base@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: char[32] name@[???] */
  iVar1 = nummiptex;
  if (0 < nummiptex) {
    local_48 = miptex;
    local_44 = 0;
    do {
      if (((*local_48)[0] == '-') || ((*local_48)[0] == '+')) {
        iVar6 = 0;
        Q_strncpy(&local_3c,*local_48,0x1f);
        local_1d = 0;
        cVar5 = '0';
        local_3b = '0';
LAB_0016fd24:
        cVar4 = cVar5;
        if (0 < nTexLumps) {
          iVar8 = 0;
          iVar7 = 0;
          do {
            iVar2 = Q_strcmp(&local_3c,(lumpinfo->lump).name + iVar8);
            if (iVar2 == 0) {
                    /* Unresolved local var: int i@[???] */
              iVar7 = 0;
              pacVar3 = miptex;
              if (nummiptex < 1) goto LAB_0016fe00;
              iVar7 = 0;
              pacVar3 = miptex;
              goto LAB_0016fd95;
            }
            iVar7 = iVar7 + 1;
            iVar8 = iVar8 + 0x24;
          } while (iVar7 < nTexLumps);
        }
        goto LAB_0016fda9;
      }
LAB_0016fcc4:
      local_44 = local_44 + 1;
      local_48 = local_48 + 1;
    } while (local_44 != iVar1);
    if (nummiptex != local_44) {
      Con_DPrintf("added %i texture frames\n",nummiptex - local_44);
    }
  }
  return;
  while( true ) {
    iVar7 = iVar7 + 1;
    pacVar3 = pacVar3 + 1;
    if (nummiptex <= iVar7) break;
LAB_0016fd95:
    iVar8 = Q_strcasecmp(&local_3c,*pacVar3);
    if (iVar8 == 0) goto LAB_0016fda9;
  }
  pacVar3 = miptex + iVar7;
  if (nummiptex == 0x200) {
    Sys_Error("Exceeded MAX_MAP_TEXTURES");
  }
LAB_0016fe00:
  Q_strncpy(*pacVar3,&local_3c,0x3f);
  miptex[iVar7][0x3f] = '\0';
  nummiptex = nummiptex + 1;
LAB_0016fda9:
  iVar6 = iVar6 + 1;
  cVar5 = cVar4 + '\x01';
  if (iVar6 != 0x14) {
    local_3b = cVar5;
    if (9 < iVar6) {
      local_3b = cVar4 + '\b';
    }
    goto LAB_0016fd24;
  }
  goto LAB_0016fcc4;
}


// TEX_CleanupWadInfo  @ 0016f7d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void TEX_CleanupWadInfo(void)

{
  int iVar1;
  
                    /* Unresolved local var: int i@[???] */
  if (lumpinfo != (texlumpinfo_t *)0x0) {
    Mem_Free(lumpinfo);
    lumpinfo = (texlumpinfo_t *)0x0;
  }
  if (0 < nTexFiles) {
    iVar1 = 0;
    do {
      FS_Close(texfiles[iVar1]);
      texfiles[iVar1] = (FILE *)0x0;
      iVar1 = iVar1 + 1;
    } while (iVar1 < nTexFiles);
  }
  nTexLumps = 0;
  nTexFiles = 0;
  return;
}


// TEX_InitFromWad  @ 0016f130
qboolean TEX_InitFromWad(char *path)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  FILE *pFVar5;
  int iVar6;
  texlumpinfo_t *ptVar7;
  __int32_t **pp_Var8;
  int32 iVar9;
  uint uVar10;
  uint uVar11;
  char cVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int local_64c;
  char local_630 [1022];
  undefined1 local_232;
  char local_230 [260];
  char local_12c [260];
  char local_28 [4];
  int32 local_24;
  int32 local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: wadinfo_t wadinfo@[???]
                       Unresolved local var: char[1024] szTmpPath@[???]
                       Unresolved local var: char * pszWadFile@[???] */
  Q_strncpy(local_630,path,0x3fe);
  local_232 = 0;
  pcVar3 = strchr(local_630,0x3b);
  if (pcVar3 == (char *)0x0) {
    Q_strcat(local_630,";");
  }
  pcVar3 = strtok(local_630,";");
  do {
    if (pcVar3 == (char *)0x0) {
      qsort(lumpinfo,nTexLumps,0x24,lump_sorter);
      return true;
    }
                    /* Unresolved local var: FileHandle_t texfile@[???]
                       Unresolved local var: char[260] wadPath@[???]
                       Unresolved local var: char[260] wadName@[???] */
    cVar12 = *pcVar3;
    pcVar4 = pcVar3;
    while (cVar12 != '\0') {
      while (cVar12 == '\\') {
        *pcVar4 = '/';
        pcVar4 = pcVar4 + 1;
        cVar12 = *pcVar4;
        if (cVar12 == '\0') goto LAB_0016f1c8;
      }
      pcVar4 = pcVar4 + 1;
      cVar12 = *pcVar4;
    }
LAB_0016f1c8:
    pcVar4 = COM_FileBase_s(pcVar3,local_12c,0x104);
    if (pcVar4 == (char *)0x0) {
      Sys_Error("TEX_InitFromWad: Invalid path length: %s",pcVar3);
      return false;
    }
    snprintf(local_230,0x100,"%s",local_12c);
    COM_DefaultExtension(local_230,".wad");
    pcVar3 = Q_strstr(local_12c,"pldecal");
    if ((pcVar3 == (char *)0x0) &&
       (pcVar3 = Q_strstr(local_12c,"tempdecal"), iVar6 = nTexFiles, pcVar3 == (char *)0x0)) {
      pFVar5 = FS_Open(local_230,"rb");
      texfiles[iVar6] = pFVar5;
      pFVar5 = texfiles[nTexFiles];
      if (pFVar5 == (FILE *)0x0) {
        Sys_Error("WARNING: couldn\'t open %s\n",local_230);
        return false;
      }
      nTexFiles = nTexFiles + 1;
      Con_DPrintf("Using WAD File: %s\n",local_230);
      iVar6 = FS_Read(local_28,0xc,1,pFVar5);
      if (iVar6 != 0xc) {
        Sys_Error("File read failure");
      }
      iVar6 = Q_strncmp(local_28,"WAD2",4);
      if ((iVar6 != 0) && (iVar6 = Q_strncmp(local_28,"WAD3",4), iVar6 != 0)) {
        Sys_Error("TEX_InitFromWad: %s isn\'t a wadfile",local_230);
      }
      local_24 = (*LittleLong)(local_24);
      local_20 = (*LittleLong)(local_20);
      FS_Seek(pFVar5,local_20,FILESYSTEM_SEEK_HEAD);
      ptVar7 = Mem_Realloc(lumpinfo,(local_24 + nTexLumps) * 0x24);
      lumpinfo = ptVar7;
      if (0 < local_24) {
        local_64c = 0;
        iVar6 = nTexLumps;
        do {
          iVar6 = FS_Read(ptVar7 + iVar6,0x20,1,pFVar5);
          if (iVar6 != 0x20) {
            Sys_Error("File read failure");
          }
          ptVar7 = lumpinfo + nTexLumps;
          cVar12 = (ptVar7->lump).name[0];
          if (cVar12 == '\0') {
            uVar10 = 0;
LAB_0016f607:
            pcVar3 = (ptVar7->lump).name + (uVar10 - 0x10);
            uVar15 = ~uVar10 + 0x11;
            uVar13 = -(int)pcVar3 & 0xf;
            if (uVar15 < uVar13) {
              uVar13 = uVar15;
            }
            uVar11 = uVar10;
            if (uVar13 == 0) {
LAB_0016f642:
              uVar10 = uVar15 - uVar13 >> 4;
              if (uVar10 != 0) {
                pcVar3 = pcVar3 + uVar13 + 0x10;
                uVar14 = 0;
                do {
                  uVar14 = uVar14 + 1;
                  pcVar3[0] = '\0';
                  pcVar3[1] = '\0';
                  pcVar3[2] = '\0';
                  pcVar3[3] = '\0';
                  pcVar3[4] = '\0';
                  pcVar3[5] = '\0';
                  pcVar3[6] = '\0';
                  pcVar3[7] = '\0';
                  pcVar3[8] = '\0';
                  pcVar3[9] = '\0';
                  pcVar3[10] = '\0';
                  pcVar3[0xb] = '\0';
                  pcVar3[0xc] = '\0';
                  pcVar3[0xd] = '\0';
                  pcVar3[0xe] = '\0';
                  pcVar3[0xf] = '\0';
                  pcVar3 = pcVar3 + 0x10;
                } while (uVar14 < uVar10);
                uVar11 = uVar11 + uVar10 * 0x10;
                if (uVar10 * 0x10 == uVar15 - uVar13) goto LAB_0016f69b;
              }
              do {
                (ptVar7->lump).name[uVar11] = '\0';
                uVar11 = uVar11 + 1;
              } while (uVar11 != 0x10);
            }
            else {
              do {
                (ptVar7->lump).name[uVar11] = '\0';
                uVar11 = uVar11 + 1;
              } while (uVar11 - uVar10 < uVar13);
              if (uVar13 != uVar15) goto LAB_0016f642;
            }
LAB_0016f69b:
            ptVar7 = lumpinfo + nTexLumps;
          }
          else {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int __res@[???] */
            pp_Var8 = __ctype_toupper_loc();
            (ptVar7->lump).name[0] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[1];
            if (cVar12 == '\0') {
              uVar10 = 1;
              goto LAB_0016f607;
            }
            (ptVar7->lump).name[1] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[2];
            if (cVar12 == '\0') {
              uVar10 = 2;
              goto LAB_0016f607;
            }
            (ptVar7->lump).name[2] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[3];
            if (cVar12 == '\0') {
              uVar10 = 3;
              goto LAB_0016f607;
            }
            (ptVar7->lump).name[3] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[4];
            if (cVar12 == '\0') {
              uVar10 = 4;
              goto LAB_0016f607;
            }
            (ptVar7->lump).name[4] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[5];
            if (cVar12 == '\0') {
              uVar10 = 5;
              goto LAB_0016f607;
            }
            (ptVar7->lump).name[5] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[6];
            if (cVar12 == '\0') {
              uVar10 = 6;
              goto LAB_0016f607;
            }
            (ptVar7->lump).name[6] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[7];
            if (cVar12 == '\0') {
              uVar10 = 7;
              goto LAB_0016f607;
            }
            (ptVar7->lump).name[7] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[8];
            if (cVar12 == '\0') {
              uVar10 = 8;
              goto LAB_0016f607;
            }
            (ptVar7->lump).name[8] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[9];
            if (cVar12 == '\0') {
              uVar10 = 9;
              goto LAB_0016f607;
            }
            (ptVar7->lump).name[9] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[10];
            if (cVar12 == '\0') {
              uVar10 = 10;
              goto LAB_0016f607;
            }
            (ptVar7->lump).name[10] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[0xb];
            if (cVar12 == '\0') {
              uVar10 = 0xb;
              goto LAB_0016f607;
            }
            (ptVar7->lump).name[0xb] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[0xc];
            if (cVar12 == '\0') {
              uVar10 = 0xc;
              goto LAB_0016f607;
            }
            (ptVar7->lump).name[0xc] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[0xd];
            if (cVar12 == '\0') {
              uVar10 = 0xd;
              goto LAB_0016f607;
            }
            (ptVar7->lump).name[0xd] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[0xe];
            if (cVar12 == '\0') {
              uVar10 = 0xe;
              goto LAB_0016f607;
            }
            (ptVar7->lump).name[0xe] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[0xf];
            if (cVar12 == '\0') {
              uVar10 = 0xf;
              goto LAB_0016f607;
            }
            (ptVar7->lump).name[0xf] = (char)(*pp_Var8)[cVar12];
          }
          iVar9 = (*LittleLong)((ptVar7->lump).filepos);
          (ptVar7->lump).filepos = iVar9;
          ptVar7 = lumpinfo;
          iVar1 = nTexLumps;
          iVar9 = (*LittleLong)(lumpinfo[nTexLumps].lump.disksize);
          iVar2 = nTexLumps;
          local_64c = local_64c + 1;
          iVar6 = nTexLumps + 1;
          nTexLumps = iVar6;
          ptVar7[iVar1].lump.disksize = iVar9;
          ptVar7 = lumpinfo;
          lumpinfo[iVar2].iTexFile = nTexFiles + -1;
        } while (local_64c < local_24);
      }
    }
    pcVar3 = strtok((char *)0x0,";");
  } while( true );
}


// TEX_LoadLump  @ 0016f840
int TEX_LoadLump(char *name,uchar *dest,int destSize)

{
  char cVar1;
  __int32_t *p_Var2;
  __int32_t **pp_Var3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined1 (*pauVar13) [16];
  undefined1 local_4c [16];
  undefined1 local_3c [4];
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  
                    /* Unresolved local var: texlumpinfo_t key@[???]
                       Unresolved local var: texlumpinfo_t * found@[???] */
                    /* Unresolved local var: int i@[???] */
  cVar1 = *name;
  if (cVar1 == '\0') {
    uVar7 = 0;
  }
  else {
                    /* Unresolved local var: int __res@[???] */
    pp_Var3 = __ctype_toupper_loc();
    p_Var2 = *pp_Var3;
    local_3c[0] = (undefined1)p_Var2[cVar1];
    if (name[1] == '\0') {
      uVar7 = 1;
    }
    else {
      local_3c[1] = (undefined1)p_Var2[name[1]];
      if (name[2] == '\0') {
        uVar7 = 2;
      }
      else {
        local_3c[2] = (undefined1)p_Var2[name[2]];
        if (name[3] == '\0') {
          uVar7 = 3;
        }
        else {
          local_3c[3] = (undefined1)p_Var2[name[3]];
          if (name[4] == '\0') {
            uVar7 = 4;
          }
          else {
            local_38 = (undefined1)p_Var2[name[4]];
            if (name[5] == '\0') {
              uVar7 = 5;
            }
            else {
              local_37 = (undefined1)p_Var2[name[5]];
              if (name[6] == '\0') {
                uVar7 = 6;
              }
              else {
                local_36 = (undefined1)p_Var2[name[6]];
                if (name[7] == '\0') {
                  uVar7 = 7;
                }
                else {
                  local_35 = (undefined1)p_Var2[name[7]];
                  if (name[8] == '\0') {
                    uVar7 = 8;
                  }
                  else {
                    local_34 = (undefined1)p_Var2[name[8]];
                    if (name[9] == '\0') {
                      uVar7 = 9;
                    }
                    else {
                      local_33 = (undefined1)p_Var2[name[9]];
                      if (name[10] == '\0') {
                        uVar7 = 10;
                      }
                      else {
                        local_32 = (undefined1)p_Var2[name[10]];
                        if (name[0xb] == '\0') {
                          uVar7 = 0xb;
                        }
                        else {
                          local_31 = (undefined1)p_Var2[name[0xb]];
                          if (name[0xc] == '\0') {
                            uVar7 = 0xc;
                          }
                          else {
                            local_30 = (undefined1)p_Var2[name[0xc]];
                            if (name[0xd] == '\0') {
                              uVar7 = 0xd;
                            }
                            else {
                              local_2f = (undefined1)p_Var2[name[0xd]];
                              if (name[0xe] == '\0') {
                                uVar7 = 0xe;
                              }
                              else {
                                local_2e = (undefined1)p_Var2[name[0xe]];
                                if (name[0xf] != '\0') {
                                  local_2d = (undefined1)p_Var2[name[0xf]];
                                  goto LAB_0016f9c1;
                                }
                                uVar7 = 0xf;
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
  uVar10 = ~uVar7 + 0x11;
  uVar12 = -(int)(local_3c + uVar7) & 0xfU;
  if (uVar10 < (-(int)(local_3c + uVar7) & 0xfU)) {
    uVar12 = uVar10;
  }
  uVar8 = uVar7;
  if (uVar12 != 0) {
    do {
      local_3c[uVar8] = 0;
      uVar8 = uVar8 + 1;
    } while (uVar8 - uVar7 < uVar12);
    if (uVar10 == uVar12) goto LAB_0016f9c1;
  }
  uVar9 = uVar10 - uVar12 >> 4;
  if (uVar9 != 0) {
    uVar11 = 0;
    pauVar13 = (undefined1 (*) [16])(local_3c + uVar12 + uVar7);
    do {
      uVar11 = uVar11 + 1;
      *pauVar13 = (undefined1  [16])0x0;
      pauVar13 = pauVar13 + 1;
    } while (uVar11 < uVar9);
    uVar8 = uVar8 + uVar9 * 0x10;
    if (uVar10 - uVar12 == uVar9 * 0x10) goto LAB_0016f9c1;
  }
  do {
    local_3c[uVar8] = 0;
    uVar8 = uVar8 + 1;
  } while (uVar8 != 0x10);
LAB_0016f9c1:
  piVar4 = bsearch(local_4c,lumpinfo,nTexLumps,0x24,lump_sorter);
  if (piVar4 == (int *)0x0) {
    Con_SafePrintf("WARNING: texture lump \"%s\" not found\n",name);
    iVar6 = 0;
  }
  else {
    if (destSize < piVar4[1]) {
      Sys_Error("TEX_LoadLump: texture lump \"%s\" too large to load",name);
    }
    FS_Seek(texfiles[piVar4[8]],*piVar4,FILESYSTEM_SEEK_HEAD);
    iVar6 = piVar4[1];
    iVar5 = FS_Read(dest,iVar6,1,texfiles[piVar4[8]]);
    if (iVar6 != iVar5) {
      Sys_Error("File read failure");
    }
    iVar6 = piVar4[1];
  }
  return iVar6;
}


