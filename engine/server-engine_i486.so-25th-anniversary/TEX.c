// TEX_AddAnimatingTextures  @ 000a6fb0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void TEX_AddAnimatingTextures(void)

{
  int iVar1;
  int iVar2;
  char (*pacVar3) [64];
  int iVar4;
  int iVar5;
  int in_GS_OFFSET;
  char local_59;
  int local_58;
  char (*local_54) [64];
  char local_40;
  char local_3f;
  undefined1 local_21;
  int local_20;
  
                    /* Unresolved local var: int base@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int k@[???]
                       Unresolved local var: char[32] name@[???] */
  iVar1 = nummiptex;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (0 < nummiptex) {
    local_54 = miptex;
    local_58 = 0;
    do {
      if (((*local_54)[0] - 0x2bU & 0xfd) == 0) {
        iVar5 = 0;
        Q_strncpy(&local_40,*local_54,0x1f);
        local_21 = 0;
        local_59 = '0';
LAB_000a7040:
        do {
          local_3f = local_59 + '\a';
          if (iVar5 < 10) {
            local_3f = local_59;
          }
          iVar4 = 0;
          if (0 < nTexLumps) {
            do {
              iVar2 = Q_strcmp(&local_40,lumpinfo[iVar4].lump.name);
              if (iVar2 == 0) {
                    /* Unresolved local var: int i@[???] */
                if (nummiptex < 1) {
                  iVar4 = 0;
                  goto LAB_000a70e7;
                }
                pacVar3 = miptex;
                iVar4 = 0;
                goto LAB_000a70bd;
              }
              iVar4 = iVar4 + 1;
            } while (iVar4 < nTexLumps);
          }
LAB_000a70cd:
          iVar5 = iVar5 + 1;
          local_59 = local_59 + '\x01';
        } while (iVar5 != 0x14);
      }
LAB_000a6ff0:
      local_58 = local_58 + 1;
      local_54 = local_54 + 1;
    } while (iVar1 != local_58);
    if (iVar1 != nummiptex) {
      Con_DPrintf("added %i texture frames\n",nummiptex - iVar1);
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
  while( true ) {
    iVar4 = iVar4 + 1;
    pacVar3 = pacVar3 + 1;
    if (nummiptex <= iVar4) break;
LAB_000a70bd:
    iVar2 = Q_strcasecmp(&local_40,pacVar3);
    if (iVar2 == 0) goto LAB_000a70cd;
  }
  if (nummiptex == 0x200) {
    Sys_Error("Exceeded MAX_MAP_TEXTURES");
  }
LAB_000a70e7:
  iVar5 = iVar5 + 1;
  Q_strncpy(miptex[iVar4],&local_40,0x3f);
  nummiptex = nummiptex + 1;
  local_59 = local_59 + '\x01';
  miptex[iVar4][0x3f] = '\0';
  if (iVar5 == 0x14) goto LAB_000a6ff0;
  goto LAB_000a7040;
}


// TEX_CleanupWadInfo  @ 000a6ac0
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


// TEX_InitFromWad  @ 000a6440
qboolean TEX_InitFromWad(char *path)

{
  texlumpinfo_t *ptVar1;
  char *pcVar2;
  char *pcVar3;
  qboolean qVar4;
  FILE *pFVar5;
  int iVar6;
  texlumpinfo_t *ptVar7;
  __int32_t **pp_Var8;
  int32 iVar9;
  int iVar10;
  uint uVar11;
  char cVar12;
  int iVar13;
  uint uVar14;
  int in_GS_OFFSET;
  char local_634 [4];
  int32 local_630;
  int32 local_62c;
  char local_628 [260];
  char local_524 [260];
  char local_420 [1022];
  undefined1 local_22;
  int local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: wadinfo_t wadinfo@[???]
                       Unresolved local var: char[1024] szTmpPath@[???]
                       Unresolved local var: char * pszWadFile@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  Q_strncpy(local_420,path,0x3fe);
  local_22 = 0;
  pcVar2 = strchr(local_420,0x3b);
  if (pcVar2 == (char *)0x0) {
    Q_strcat(local_420,";");
  }
                    /* Unresolved local var: FileHandle_t texfile@[???]
                       Unresolved local var: char[260] wadPath@[???]
                       Unresolved local var: char[260] wadName@[???] */
  pcVar2 = strtok(local_420,";");
  do {
    if (pcVar2 == (char *)0x0) {
      qsort(lumpinfo,nTexLumps,0x24,lump_sorter);
      qVar4 = true;
LAB_000a65a5:
      if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return qVar4;
    }
    cVar12 = *pcVar2;
    pcVar3 = pcVar2;
    while (cVar12 != '\0') {
      while (cVar12 == '\\') {
        *pcVar3 = '/';
        pcVar3 = pcVar3 + 1;
        cVar12 = *pcVar3;
        if (cVar12 == '\0') goto LAB_000a64f8;
      }
      pcVar3 = pcVar3 + 1;
      cVar12 = *pcVar3;
    }
LAB_000a64f8:
    pcVar3 = COM_FileBase_s(pcVar2,local_524,0x104);
    if (pcVar3 == (char *)0x0) {
      Sys_Error("TEX_InitFromWad: Invalid path length: %s",pcVar2);
      qVar4 = false;
      goto LAB_000a65a5;
    }
    snprintf(local_628,0x100,"%s",local_524);
    COM_DefaultExtension(local_628,".wad");
    pcVar2 = Q_strstr(local_524,"pldecal");
    if ((pcVar2 == (char *)0x0) &&
       (pcVar2 = Q_strstr(local_524,"tempdecal"), iVar6 = nTexFiles, pcVar2 == (char *)0x0)) {
      pFVar5 = FS_Open(local_628,"rb");
      texfiles[iVar6] = pFVar5;
      pFVar5 = texfiles[nTexFiles];
      if (pFVar5 == (FILE *)0x0) {
        Sys_Error("WARNING: couldn\'t open %s\n",local_628);
        qVar4 = false;
        goto LAB_000a65a5;
      }
      nTexFiles = nTexFiles + 1;
      Con_DPrintf("Using WAD File: %s\n",local_628);
      iVar6 = FS_Read(local_634,0xc,1,pFVar5);
      if (iVar6 != 0xc) {
        Sys_Error("File read failure");
      }
      iVar6 = Q_strncmp(local_634,"WAD2",4);
      if ((iVar6 != 0) && (iVar6 = Q_strncmp(local_634,"WAD3",4), iVar6 != 0)) {
        Sys_Error("TEX_InitFromWad: %s isn\'t a wadfile",local_628);
      }
      local_630 = (*LittleLong)(local_630);
      local_62c = (*LittleLong)(local_62c);
      FS_Seek(pFVar5,local_62c,FILESYSTEM_SEEK_HEAD);
      ptVar7 = Mem_Realloc(lumpinfo,(nTexLumps + local_630) * 0x24);
      lumpinfo = ptVar7;
      if (0 < local_630) {
        iVar6 = 0;
        do {
          iVar10 = FS_Read(ptVar7 + nTexLumps,0x20,1,pFVar5);
          if (iVar10 != 0x20) {
            Sys_Error("File read failure");
          }
          ptVar7 = lumpinfo + nTexLumps;
          cVar12 = (ptVar7->lump).name[0];
          if (cVar12 == '\0') {
            iVar10 = 0;
LAB_000a68fa:
            pcVar2 = (ptVar7->lump).name + iVar10;
            uVar14 = -iVar10 + 0x10;
            if (7 < uVar14) {
              if (((uint)pcVar2 & 1) != 0) {
                *pcVar2 = '\0';
                pcVar2 = pcVar2 + 1;
                uVar14 = -iVar10 + 0xf;
              }
              if (((uint)pcVar2 & 2) != 0) {
                pcVar2[0] = '\0';
                pcVar2[1] = '\0';
                uVar14 = uVar14 - 2;
                pcVar2 = pcVar2 + 2;
              }
              if (7 < uVar14) {
                uVar11 = 0;
                do {
                  pcVar3 = pcVar2 + uVar11;
                  pcVar3[0] = '\0';
                  pcVar3[1] = '\0';
                  pcVar3[2] = '\0';
                  pcVar3[3] = '\0';
                  pcVar3 = pcVar2 + uVar11 + 4;
                  pcVar3[0] = '\0';
                  pcVar3[1] = '\0';
                  pcVar3[2] = '\0';
                  pcVar3[3] = '\0';
                  uVar11 = uVar11 + 8;
                } while (uVar11 < (uVar14 & 0xfffffff8));
                pcVar2 = pcVar2 + uVar11;
              }
            }
            if ((uVar14 & 4) != 0) {
              pcVar2[0] = '\0';
              pcVar2[1] = '\0';
              pcVar2[2] = '\0';
              pcVar2[3] = '\0';
              pcVar2 = pcVar2 + 4;
            }
            if ((uVar14 & 2) != 0) {
              pcVar2[0] = '\0';
              pcVar2[1] = '\0';
              pcVar2 = pcVar2 + 2;
            }
            if ((uVar14 & 1) != 0) {
              *pcVar2 = '\0';
            }
            ptVar7 = lumpinfo + nTexLumps;
          }
          else {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int __res@[???] */
            pp_Var8 = __ctype_toupper_loc();
            (ptVar7->lump).name[0] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[1];
            if (cVar12 == '\0') {
              iVar10 = 1;
              goto LAB_000a68fa;
            }
            (ptVar7->lump).name[1] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[2];
            if (cVar12 == '\0') {
              iVar10 = 2;
              goto LAB_000a68fa;
            }
            (ptVar7->lump).name[2] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[3];
            if (cVar12 == '\0') {
              iVar10 = 3;
              goto LAB_000a68fa;
            }
            (ptVar7->lump).name[3] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[4];
            if (cVar12 == '\0') {
              iVar10 = 4;
              goto LAB_000a68fa;
            }
            (ptVar7->lump).name[4] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[5];
            if (cVar12 == '\0') {
              iVar10 = 5;
              goto LAB_000a68fa;
            }
            (ptVar7->lump).name[5] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[6];
            if (cVar12 == '\0') {
              iVar10 = 6;
              goto LAB_000a68fa;
            }
            (ptVar7->lump).name[6] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[7];
            if (cVar12 == '\0') {
              iVar10 = 7;
              goto LAB_000a68fa;
            }
            (ptVar7->lump).name[7] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[8];
            if (cVar12 == '\0') {
              iVar10 = 8;
              goto LAB_000a68fa;
            }
            (ptVar7->lump).name[8] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[9];
            if (cVar12 == '\0') {
              iVar10 = 9;
              goto LAB_000a68fa;
            }
            (ptVar7->lump).name[9] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[10];
            if (cVar12 == '\0') {
              iVar10 = 10;
              goto LAB_000a68fa;
            }
            (ptVar7->lump).name[10] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[0xb];
            if (cVar12 == '\0') {
              iVar10 = 0xb;
              goto LAB_000a68fa;
            }
            (ptVar7->lump).name[0xb] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[0xc];
            if (cVar12 == '\0') {
              iVar10 = 0xc;
              goto LAB_000a68fa;
            }
            (ptVar7->lump).name[0xc] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[0xd];
            if (cVar12 == '\0') {
              iVar10 = 0xd;
              goto LAB_000a68fa;
            }
            (ptVar7->lump).name[0xd] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[0xe];
            if (cVar12 == '\0') {
              iVar10 = 0xe;
              goto LAB_000a68fa;
            }
            (ptVar7->lump).name[0xe] = (char)(*pp_Var8)[cVar12];
            cVar12 = (ptVar7->lump).name[0xf];
            if (cVar12 == '\0') {
              iVar10 = 0xf;
              goto LAB_000a68fa;
            }
            (ptVar7->lump).name[0xf] = (char)(*pp_Var8)[cVar12];
          }
          iVar6 = iVar6 + 1;
          iVar9 = (*LittleLong)((ptVar7->lump).filepos);
          (ptVar7->lump).filepos = iVar9;
          ptVar1 = lumpinfo;
          iVar10 = nTexLumps;
          iVar9 = (*LittleLong)(lumpinfo[nTexLumps].lump.disksize);
          ptVar7 = lumpinfo;
          iVar13 = nTexFiles + -1;
          ptVar1[iVar10].lump.disksize = iVar9;
          ptVar7[nTexLumps].iTexFile = iVar13;
          nTexLumps = nTexLumps + 1;
        } while (iVar6 < local_630);
      }
    }
    pcVar2 = strtok((char *)0x0,";");
  } while( true );
}


// TEX_LoadLump  @ 000a6b30
int TEX_LoadLump(char *name,byte *dest,int destSize)

{
  char cVar1;
  __int32_t *p_Var2;
  __int32_t **pp_Var3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  int in_GS_OFFSET;
  undefined1 local_44 [16];
  undefined1 local_34 [2];
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  int local_20;
  
                    /* Unresolved local var: texlumpinfo_t key@[???]
                       Unresolved local var: texlumpinfo_t * found@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
                    /* Unresolved local var: int i@[???] */
  cVar1 = *name;
  if (cVar1 == '\0') {
    iVar6 = 0;
  }
  else {
                    /* Unresolved local var: int __res@[???] */
    pp_Var3 = __ctype_toupper_loc();
    p_Var2 = *pp_Var3;
    local_34[0] = (undefined1)p_Var2[cVar1];
    if (name[1] == '\0') {
      iVar6 = 1;
    }
    else {
      local_34[1] = (undefined1)p_Var2[name[1]];
      if (name[2] == '\0') {
        iVar6 = 2;
      }
      else {
        local_32 = (undefined1)p_Var2[name[2]];
        if (name[3] == '\0') {
          iVar6 = 3;
        }
        else {
          local_31 = (undefined1)p_Var2[name[3]];
          if (name[4] == '\0') {
            iVar6 = 4;
          }
          else {
            local_30 = (undefined1)p_Var2[name[4]];
            if (name[5] == '\0') {
              iVar6 = 5;
            }
            else {
              local_2f = (undefined1)p_Var2[name[5]];
              if (name[6] == '\0') {
                iVar6 = 6;
              }
              else {
                local_2e = (undefined1)p_Var2[name[6]];
                if (name[7] == '\0') {
                  iVar6 = 7;
                }
                else {
                  local_2d = (undefined1)p_Var2[name[7]];
                  if (name[8] == '\0') {
                    iVar6 = 8;
                  }
                  else {
                    local_2c = (undefined1)p_Var2[name[8]];
                    if (name[9] == '\0') {
                      iVar6 = 9;
                    }
                    else {
                      local_2b = (undefined1)p_Var2[name[9]];
                      if (name[10] == '\0') {
                        iVar6 = 10;
                      }
                      else {
                        local_2a = (undefined1)p_Var2[name[10]];
                        if (name[0xb] == '\0') {
                          iVar6 = 0xb;
                        }
                        else {
                          local_29 = (undefined1)p_Var2[name[0xb]];
                          if (name[0xc] == '\0') {
                            iVar6 = 0xc;
                          }
                          else {
                            local_28 = (undefined1)p_Var2[name[0xc]];
                            if (name[0xd] == '\0') {
                              iVar6 = 0xd;
                            }
                            else {
                              local_27 = (undefined1)p_Var2[name[0xd]];
                              if (name[0xe] == '\0') {
                                iVar6 = 0xe;
                              }
                              else {
                                local_26 = (undefined1)p_Var2[name[0xe]];
                                if (name[0xf] != '\0') {
                                  local_25 = (undefined1)p_Var2[name[0xf]];
                                  goto LAB_000a6c94;
                                }
                                iVar6 = 0xf;
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
  uVar7 = -iVar6 + 0x10;
  puVar8 = (undefined4 *)(local_34 + iVar6);
  if (7 < uVar7) {
    if (((uint)puVar8 & 1) != 0) {
      *(undefined1 *)puVar8 = 0;
      uVar7 = -iVar6 + 0xf;
      puVar8 = (undefined4 *)(local_34 + iVar6 + 1);
    }
    if (((uint)puVar8 & 2) != 0) {
      *(undefined2 *)puVar8 = 0;
      uVar7 = uVar7 - 2;
      puVar8 = (undefined4 *)((int)puVar8 + 2);
    }
    if (7 < uVar7) {
      uVar9 = 0;
      do {
        *(undefined4 *)((int)puVar8 + uVar9) = 0;
        *(undefined4 *)((int)puVar8 + uVar9 + 4) = 0;
        uVar9 = uVar9 + 8;
      } while (uVar9 < (uVar7 & 0xfffffff8));
      puVar8 = (undefined4 *)((int)puVar8 + uVar9);
    }
  }
  if ((uVar7 & 4) != 0) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  if ((uVar7 & 2) != 0) {
    *(undefined2 *)puVar8 = 0;
    puVar8 = (undefined4 *)((int)puVar8 + 2);
  }
  if ((uVar7 & 1) != 0) {
    *(undefined1 *)puVar8 = 0;
  }
LAB_000a6c94:
  piVar4 = bsearch(local_44,lumpinfo,nTexLumps,0x24,lump_sorter);
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
    if (iVar5 != iVar6) {
      Sys_Error("File read failure");
    }
    iVar6 = piVar4[1];
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


