// TEX_AddAnimatingTextures  @ 00112370
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
LAB_00112400:
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
                  goto LAB_001124a7;
                }
                pacVar3 = miptex;
                iVar4 = 0;
                goto LAB_0011247d;
              }
              iVar4 = iVar4 + 1;
            } while (iVar4 < nTexLumps);
          }
LAB_0011248d:
          iVar5 = iVar5 + 1;
          local_59 = local_59 + '\x01';
        } while (iVar5 != 0x14);
      }
LAB_001123b0:
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
LAB_0011247d:
    iVar2 = Q_strcasecmp(&local_40,pacVar3);
    if (iVar2 == 0) goto LAB_0011248d;
  }
  if (nummiptex == 0x200) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Exceeded MAX_MAP_TEXTURES");
  }
LAB_001124a7:
  iVar5 = iVar5 + 1;
  Q_strncpy(miptex[iVar4],&local_40,0x3f);
  nummiptex = nummiptex + 1;
  local_59 = local_59 + '\x01';
  miptex[iVar4][0x3f] = '\0';
  if (iVar5 == 0x14) goto LAB_001123b0;
  goto LAB_00112400;
}


// TEX_CleanupWadInfo  @ 00111e80
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


// TEX_InitFromWad  @ 00111800
qboolean TEX_InitFromWad(char *path)

{
  texlumpinfo_t *ptVar1;
  char *pcVar2;
  char *pcVar3;
  FILE *pFVar4;
  int iVar5;
  texlumpinfo_t *ptVar6;
  __int32_t **pp_Var7;
  int32 iVar8;
  int iVar9;
  uint uVar10;
  char cVar11;
  int iVar12;
  uint uVar13;
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
      if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return true;
    }
    cVar11 = *pcVar2;
    pcVar3 = pcVar2;
    while (cVar11 != '\0') {
      while (cVar11 == '\\') {
        *pcVar3 = '/';
        pcVar3 = pcVar3 + 1;
        cVar11 = *pcVar3;
        if (cVar11 == '\0') goto LAB_001118b8;
      }
      pcVar3 = pcVar3 + 1;
      cVar11 = *pcVar3;
    }
LAB_001118b8:
    pcVar3 = COM_FileBase_s(pcVar2,local_524,0x104);
    if (pcVar3 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("TEX_InitFromWad: Invalid path length: %s",pcVar2);
    }
    snprintf(local_628,0x100,"%s",local_524);
    COM_DefaultExtension(local_628,".wad");
    pcVar2 = Q_strstr(local_524,"pldecal");
    if ((pcVar2 == (char *)0x0) &&
       (pcVar2 = Q_strstr(local_524,"tempdecal"), iVar5 = nTexFiles, pcVar2 == (char *)0x0)) {
      pFVar4 = FS_Open(local_628,"rb");
      texfiles[iVar5] = pFVar4;
      pFVar4 = texfiles[nTexFiles];
      if (pFVar4 == (FILE *)0x0) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("WARNING: couldn\'t open %s\n",local_628);
      }
      nTexFiles = nTexFiles + 1;
      Con_DPrintf("Using WAD File: %s\n",local_628);
      iVar5 = FS_Read(local_634,0xc,1,pFVar4);
      if (iVar5 != 0xc) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("File read failure");
      }
      iVar5 = Q_strncmp(local_634,"WAD2",4);
      if ((iVar5 != 0) && (iVar5 = Q_strncmp(local_634,"WAD3",4), iVar5 != 0)) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("TEX_InitFromWad: %s isn\'t a wadfile",local_628);
      }
      local_630 = (*LittleLong)(local_630);
      local_62c = (*LittleLong)(local_62c);
      FS_Seek(pFVar4,local_62c,FILESYSTEM_SEEK_HEAD);
      ptVar6 = Mem_Realloc(lumpinfo,(nTexLumps + local_630) * 0x24);
      lumpinfo = ptVar6;
      if (0 < local_630) {
        iVar5 = 0;
        do {
          iVar9 = FS_Read(ptVar6 + nTexLumps,0x20,1,pFVar4);
          if (iVar9 != 0x20) {
                    /* WARNING: Subroutine does not return */
            Sys_Error("File read failure");
          }
          ptVar6 = lumpinfo + nTexLumps;
          cVar11 = (ptVar6->lump).name[0];
          if (cVar11 == '\0') {
            iVar9 = 0;
LAB_00111cba:
            pcVar2 = (ptVar6->lump).name + iVar9;
            uVar13 = -iVar9 + 0x10;
            if (7 < uVar13) {
              if (((uint)pcVar2 & 1) != 0) {
                *pcVar2 = '\0';
                pcVar2 = pcVar2 + 1;
                uVar13 = -iVar9 + 0xf;
              }
              if (((uint)pcVar2 & 2) != 0) {
                pcVar2[0] = '\0';
                pcVar2[1] = '\0';
                uVar13 = uVar13 - 2;
                pcVar2 = pcVar2 + 2;
              }
              if (7 < uVar13) {
                uVar10 = 0;
                do {
                  pcVar3 = pcVar2 + uVar10;
                  pcVar3[0] = '\0';
                  pcVar3[1] = '\0';
                  pcVar3[2] = '\0';
                  pcVar3[3] = '\0';
                  pcVar3 = pcVar2 + uVar10 + 4;
                  pcVar3[0] = '\0';
                  pcVar3[1] = '\0';
                  pcVar3[2] = '\0';
                  pcVar3[3] = '\0';
                  uVar10 = uVar10 + 8;
                } while (uVar10 < (uVar13 & 0xfffffff8));
                pcVar2 = pcVar2 + uVar10;
              }
            }
            if ((uVar13 & 4) != 0) {
              pcVar2[0] = '\0';
              pcVar2[1] = '\0';
              pcVar2[2] = '\0';
              pcVar2[3] = '\0';
              pcVar2 = pcVar2 + 4;
            }
            if ((uVar13 & 2) != 0) {
              pcVar2[0] = '\0';
              pcVar2[1] = '\0';
              pcVar2 = pcVar2 + 2;
            }
            if ((uVar13 & 1) != 0) {
              *pcVar2 = '\0';
            }
            ptVar6 = lumpinfo + nTexLumps;
          }
          else {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int __res@[???] */
            pp_Var7 = __ctype_toupper_loc();
            (ptVar6->lump).name[0] = (char)(*pp_Var7)[cVar11];
            cVar11 = (ptVar6->lump).name[1];
            if (cVar11 == '\0') {
              iVar9 = 1;
              goto LAB_00111cba;
            }
            (ptVar6->lump).name[1] = (char)(*pp_Var7)[cVar11];
            cVar11 = (ptVar6->lump).name[2];
            if (cVar11 == '\0') {
              iVar9 = 2;
              goto LAB_00111cba;
            }
            (ptVar6->lump).name[2] = (char)(*pp_Var7)[cVar11];
            cVar11 = (ptVar6->lump).name[3];
            if (cVar11 == '\0') {
              iVar9 = 3;
              goto LAB_00111cba;
            }
            (ptVar6->lump).name[3] = (char)(*pp_Var7)[cVar11];
            cVar11 = (ptVar6->lump).name[4];
            if (cVar11 == '\0') {
              iVar9 = 4;
              goto LAB_00111cba;
            }
            (ptVar6->lump).name[4] = (char)(*pp_Var7)[cVar11];
            cVar11 = (ptVar6->lump).name[5];
            if (cVar11 == '\0') {
              iVar9 = 5;
              goto LAB_00111cba;
            }
            (ptVar6->lump).name[5] = (char)(*pp_Var7)[cVar11];
            cVar11 = (ptVar6->lump).name[6];
            if (cVar11 == '\0') {
              iVar9 = 6;
              goto LAB_00111cba;
            }
            (ptVar6->lump).name[6] = (char)(*pp_Var7)[cVar11];
            cVar11 = (ptVar6->lump).name[7];
            if (cVar11 == '\0') {
              iVar9 = 7;
              goto LAB_00111cba;
            }
            (ptVar6->lump).name[7] = (char)(*pp_Var7)[cVar11];
            cVar11 = (ptVar6->lump).name[8];
            if (cVar11 == '\0') {
              iVar9 = 8;
              goto LAB_00111cba;
            }
            (ptVar6->lump).name[8] = (char)(*pp_Var7)[cVar11];
            cVar11 = (ptVar6->lump).name[9];
            if (cVar11 == '\0') {
              iVar9 = 9;
              goto LAB_00111cba;
            }
            (ptVar6->lump).name[9] = (char)(*pp_Var7)[cVar11];
            cVar11 = (ptVar6->lump).name[10];
            if (cVar11 == '\0') {
              iVar9 = 10;
              goto LAB_00111cba;
            }
            (ptVar6->lump).name[10] = (char)(*pp_Var7)[cVar11];
            cVar11 = (ptVar6->lump).name[0xb];
            if (cVar11 == '\0') {
              iVar9 = 0xb;
              goto LAB_00111cba;
            }
            (ptVar6->lump).name[0xb] = (char)(*pp_Var7)[cVar11];
            cVar11 = (ptVar6->lump).name[0xc];
            if (cVar11 == '\0') {
              iVar9 = 0xc;
              goto LAB_00111cba;
            }
            (ptVar6->lump).name[0xc] = (char)(*pp_Var7)[cVar11];
            cVar11 = (ptVar6->lump).name[0xd];
            if (cVar11 == '\0') {
              iVar9 = 0xd;
              goto LAB_00111cba;
            }
            (ptVar6->lump).name[0xd] = (char)(*pp_Var7)[cVar11];
            cVar11 = (ptVar6->lump).name[0xe];
            if (cVar11 == '\0') {
              iVar9 = 0xe;
              goto LAB_00111cba;
            }
            (ptVar6->lump).name[0xe] = (char)(*pp_Var7)[cVar11];
            cVar11 = (ptVar6->lump).name[0xf];
            if (cVar11 == '\0') {
              iVar9 = 0xf;
              goto LAB_00111cba;
            }
            (ptVar6->lump).name[0xf] = (char)(*pp_Var7)[cVar11];
          }
          iVar5 = iVar5 + 1;
          iVar8 = (*LittleLong)((ptVar6->lump).filepos);
          (ptVar6->lump).filepos = iVar8;
          ptVar1 = lumpinfo;
          iVar9 = nTexLumps;
          iVar8 = (*LittleLong)(lumpinfo[nTexLumps].lump.disksize);
          ptVar6 = lumpinfo;
          iVar12 = nTexFiles + -1;
          ptVar1[iVar9].lump.disksize = iVar8;
          ptVar6[nTexLumps].iTexFile = iVar12;
          nTexLumps = nTexLumps + 1;
        } while (iVar5 < local_630);
      }
    }
    pcVar2 = strtok((char *)0x0,";");
  } while( true );
}


// TEX_LoadLump  @ 00111ef0
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
                                  goto LAB_00112054;
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
LAB_00112054:
  piVar4 = bsearch(local_44,lumpinfo,nTexLumps,0x24,lump_sorter);
  if (piVar4 == (int *)0x0) {
    Con_SafePrintf("WARNING: texture lump \"%s\" not found\n",name);
    iVar6 = 0;
  }
  else {
    if (destSize < piVar4[1]) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("TEX_LoadLump: texture lump \"%s\" too large to load",name);
    }
    FS_Seek(texfiles[piVar4[8]],*piVar4,FILESYSTEM_SEEK_HEAD);
    iVar6 = piVar4[1];
    iVar5 = FS_Read(dest,iVar6,1,texfiles[piVar4[8]]);
    if (iVar5 != iVar6) {
                    /* WARNING: Subroutine does not return */
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


