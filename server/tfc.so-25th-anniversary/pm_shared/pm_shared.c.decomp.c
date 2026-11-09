// Ghidra decompilation of functions from pm_shared/pm_shared.c
// 53 functions, ordered by original source line

// PM_SwapTextures  @ 0013caf0  (line 156)

void PM_SwapTextures(int i,int j)

{
  char cVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *__src;
  char *pcVar8;
  int in_GS_OFFSET;
  byte bVar9;
  char local_2d;
  char acStack_2c [12];
  int local_20;
  
                    /* Unresolved local var: char chTemp@[???]
                       Unresolved local var: char[13] szTemp@[???] */
  bVar9 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar7 = &local_2d;
  iVar4 = __stpcpy_chk(pcVar7,grgszTextureName + i,0xd);
  cVar1 = grgchTextureType[i];
  __src = grgszTextureName[j];
  strcpy(grgszTextureName[i],__src);
  grgchTextureType[i] = grgchTextureType[j];
  uVar5 = iVar4 - (int)pcVar7;
  uVar6 = uVar5 + 1;
  if (7 < uVar6) {
    if (((uint)__src & 1) != 0) {
      __src = grgszTextureName[j] + 1;
      grgszTextureName[j][0] = local_2d;
      pcVar7 = acStack_2c;
      uVar6 = uVar5;
    }
    pcVar8 = __src;
    if (((uint)__src & 2) != 0) {
      uVar2 = *(undefined2 *)pcVar7;
      pcVar8 = __src + 2;
      pcVar7 = pcVar7 + 2;
      uVar6 = uVar6 - 2;
      *(undefined2 *)__src = uVar2;
    }
    __src = pcVar8;
    if (((uint)pcVar8 & 4) != 0) {
      uVar3 = *(undefined4 *)pcVar7;
      __src = pcVar8 + 4;
      pcVar7 = pcVar7 + 4;
      uVar6 = uVar6 - 4;
      *(undefined4 *)pcVar8 = uVar3;
    }
  }
  for (; uVar6 != 0; uVar6 = uVar6 - 1) {
    *__src = *pcVar7;
    pcVar7 = pcVar7 + (uint)bVar9 * -2 + 1;
    __src = __src + (uint)bVar9 * -2 + 1;
  }
  grgchTextureType[j] = cVar1;
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// PM_SortTextures  @ 0013cc30  (line 171)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_SortTextures(void)

{
  int iVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  char *__s2;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  int in_GS_OFFSET;
  byte bVar13;
  int local_50;
  char (*local_4c) [13];
  char local_2d;
  char acStack_2c [12];
  int local_20;
  
  iVar4 = gcTextures;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
  bVar13 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_4c = grgszTextureName;
  local_50 = 0;
  pcVar5 = grgchTextureType + gcTextures;
  if (0 < gcTextures) {
    do {
      iVar1 = local_50 + 1;
      if (iVar1 < iVar4) {
        __s2 = grgszTextureName[iVar1];
        pcVar9 = grgchTextureType + local_50 + 1;
        do {
          iVar6 = strcasecmp(*local_4c,__s2);
          if (0 < iVar6) {
            iVar6 = __stpcpy_chk(&local_2d,local_4c,0xd);
            cVar2 = grgchTextureType[local_50];
            strcpy(*local_4c,__s2);
            pcVar10 = &local_2d;
            grgchTextureType[local_50] = *pcVar9;
            uVar7 = iVar6 - (int)pcVar10;
            uVar8 = uVar7 + 1;
            pcVar12 = __s2;
            if (7 < uVar8) {
              pcVar11 = __s2;
              if (((uint)__s2 & 1) != 0) {
                pcVar11 = __s2 + 1;
                pcVar10 = acStack_2c;
                *__s2 = local_2d;
                uVar8 = uVar7;
              }
              pcVar12 = pcVar11;
              if (((uint)pcVar11 & 2) != 0) {
                uVar3 = *(undefined2 *)pcVar10;
                pcVar12 = pcVar11 + 2;
                pcVar10 = pcVar10 + 2;
                uVar8 = uVar8 - 2;
                *(undefined2 *)pcVar11 = uVar3;
              }
              if (((uint)pcVar12 & 4) != 0) {
                uVar8 = uVar8 - 4;
                *(undefined4 *)pcVar12 = *(undefined4 *)pcVar10;
                pcVar10 = pcVar10 + 4;
                pcVar12 = pcVar12 + 4;
              }
            }
                    /* Unresolved local var: char chTemp@[???]
                       Unresolved local var: char[13] szTemp@[???] */
            for (; uVar8 != 0; uVar8 = uVar8 - 1) {
              *pcVar12 = *pcVar10;
              pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
              pcVar12 = pcVar12 + (uint)bVar13 * -2 + 1;
            }
            *pcVar9 = cVar2;
          }
          pcVar9 = pcVar9 + 1;
          __s2 = __s2 + 0xd;
        } while (pcVar9 != pcVar5);
      }
      local_4c = local_4c + 1;
      local_50 = iVar1;
    } while (iVar1 < iVar4);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// PM_InitTextureTypes  @ 0013cdc0  (line 191)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_InitTextureTypes(void)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  char *pcVar6;
  ushort **ppuVar7;
  __int32_t **pp_Var8;
  int iVar9;
  char cVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  char *__s2;
  char *pcVar14;
  char *pcVar15;
  char *pcVar16;
  int in_GS_OFFSET;
  byte bVar17;
  int local_250;
  char (*local_24c) [13];
  int local_234;
  char local_22d;
  char acStack_22c [12];
  char local_220 [4];
  int aiStack_21c [131];
  
                    /* Unresolved local var: char[512] buffer@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: byte * pMemFile@[???]
                       Unresolved local var: int fileSize@[???]
                       Unresolved local var: int filePos@[???] */
  bVar17 = 0;
  aiStack_21c[0x7f] = *(int *)(in_GS_OFFSET + 0x14);
  if (PM_InitTextureTypes::bTextureTypeInit == false) {
    iVar9 = 0x680;
    pcVar6 = grgszTextureName[0];
    for (; uVar4 = 0, iVar9 != 0; iVar9 = iVar9 + -1) {
      pcVar6[0] = '\0';
      pcVar6[1] = '\0';
      pcVar6[2] = '\0';
      pcVar6[3] = '\0';
      pcVar6 = pcVar6 + 4;
    }
    do {
      pcVar6 = grgchTextureType + uVar4;
      pcVar6[0] = '\0';
      pcVar6[1] = '\0';
      pcVar6[2] = '\0';
      pcVar6[3] = '\0';
      uVar3 = uVar4 + 8;
      pcVar6 = grgchTextureType + uVar4 + 4;
      pcVar6[0] = '\0';
      pcVar6[1] = '\0';
      pcVar6[2] = '\0';
      pcVar6[3] = '\0';
      uVar4 = uVar3;
    } while (uVar3 < 0x200);
    uVar4 = 0;
    gcTextures = 0;
    do {
      pcVar6 = local_220 + uVar4;
      pcVar6[0] = '\0';
      pcVar6[1] = '\0';
      pcVar6[2] = '\0';
      pcVar6[3] = '\0';
      *(undefined4 *)((int)aiStack_21c + uVar4) = 0;
      uVar4 = uVar4 + 8;
    } while (uVar4 < 0x200);
    iVar9 = (*pmove->COM_FileSize)("sound/materials.txt");
    pbVar5 = (*pmove->COM_LoadFile)("sound/materials.txt",5,(int *)0x0);
    if (pbVar5 != (byte *)0x0) {
      local_234 = 0;
LAB_0013cea0:
      do {
        pcVar6 = (*pmove->memfgets)(pbVar5,iVar9,&local_234,local_220,0x1ff);
        cVar10 = local_220[0];
        iVar1 = gcTextures;
        if ((pcVar6 == (char *)0x0) || (0x1ff < gcTextures)) goto LAB_0013cfe0;
        if (local_220[0] != '\0') {
          ppuVar7 = __ctype_b_loc();
          iVar11 = 0;
          do {
            if (((*ppuVar7)[cVar10] & 0x2000) == 0) {
              if ((cVar10 != '/') && (((*ppuVar7)[cVar10] & 0x400) != 0)) {
                    /* Unresolved local var: int __res@[???] */
                pp_Var8 = __ctype_toupper_loc();
                iVar12 = iVar11 + 1;
                grgchTextureType[iVar1] = (char)(*pp_Var8)[cVar10];
                cVar10 = *(char *)((int)aiStack_21c + iVar11 + -3);
                if (cVar10 != '\0') {
                  goto LAB_0013cf6e;
                }
              }
              break;
            }
            iVar11 = iVar11 + 1;
            cVar10 = local_220[iVar11];
          } while (cVar10 != '\0');
        }
      } while( true );
    }
  }
LAB_0013cde3:
  if (aiStack_21c[0x7f] != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_0013cfe0:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???] */
  (*pmove->COM_FreeFile)(pbVar5);
  iVar9 = gcTextures;
  local_250 = 0;
  local_24c = grgszTextureName;
  pcVar6 = grgchTextureType + gcTextures;
  if (0 < gcTextures) {
    do {
      iVar1 = local_250 + 1;
      if (iVar1 < iVar9) {
        __s2 = grgszTextureName[iVar1];
        pcVar13 = grgchTextureType + local_250 + 1;
        do {
          iVar11 = strcasecmp(*local_24c,__s2);
          if (0 < iVar11) {
            iVar11 = __stpcpy_chk(&local_22d,local_24c,0xd);
            cVar10 = grgchTextureType[local_250];
            strcpy(*local_24c,__s2);
            grgchTextureType[local_250] = *pcVar13;
            uVar4 = (iVar11 - (int)&local_22d) + 1;
            pcVar14 = &local_22d;
            pcVar16 = __s2;
            if (7 < uVar4) {
              pcVar15 = __s2;
              if (((uint)__s2 & 1) != 0) {
                pcVar15 = __s2 + 1;
                pcVar14 = acStack_22c;
                *__s2 = local_22d;
                uVar4 = iVar11 - (int)&local_22d;
              }
              pcVar16 = pcVar15;
              if (((uint)pcVar15 & 2) != 0) {
                uVar2 = *(undefined2 *)pcVar14;
                pcVar16 = pcVar15 + 2;
                pcVar14 = pcVar14 + 2;
                uVar4 = uVar4 - 2;
                *(undefined2 *)pcVar15 = uVar2;
              }
              if (((uint)pcVar16 & 4) != 0) {
                uVar4 = uVar4 - 4;
                *(undefined4 *)pcVar16 = *(undefined4 *)pcVar14;
                pcVar14 = pcVar14 + 4;
                pcVar16 = pcVar16 + 4;
              }
            }
                    /* Unresolved local var: char chTemp@[???]
                       Unresolved local var: char[13] szTemp@[???] */
            for (; uVar4 != 0; uVar4 = uVar4 - 1) {
              *pcVar16 = *pcVar14;
              pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
              pcVar16 = pcVar16 + (uint)bVar17 * -2 + 1;
            }
            *pcVar13 = cVar10;
          }
          pcVar13 = pcVar13 + 1;
          __s2 = __s2 + 0xd;
        } while (pcVar6 != pcVar13);
      }
      local_24c = local_24c + 1;
      local_250 = iVar1;
    } while (iVar1 < iVar9);
  }
  PM_InitTextureTypes::bTextureTypeInit = true;
  goto LAB_0013cde3;
  while( true ) {
    iVar12 = iVar12 + 1;
    cVar10 = local_220[iVar12];
    if (cVar10 == '\0') break;
LAB_0013cf6e:
    iVar11 = iVar12;
    if ((*(byte *)((int)*ppuVar7 + cVar10 * 2 + 1) & 0x20) == 0) goto LAB_0013cf80;
  }
  goto LAB_0013cea0;
  while ((*(byte *)((int)*ppuVar7 + cVar10 * 2 + 1) & 0x20) == 0) {
LAB_0013cf80:
    iVar11 = iVar11 + 1;
    cVar10 = local_220[iVar11];
    if (cVar10 == '\0') goto LAB_0013cea0;
  }
  if (iVar12 + 0xb < iVar11) {
    iVar11 = iVar12 + 0xc;
  }
  gcTextures = iVar1 + 1;
  *(undefined1 *)((int)aiStack_21c + iVar11 + -4) = 0;
  __strcpy_chk(grgszTextureName + iVar1,local_220 + iVar12,0xd);
  goto LAB_0013cea0;
}


// PM_FindTextureType  @ 0013d180  (line 261)

char PM_FindTextureType(char *name)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int left@[???]
                       Unresolved local var: int right@[???]
                       Unresolved local var: int pivot@[???]
                       Unresolved local var: int val@[???] */
  iVar3 = gcTextures + -1;
  if (-1 < iVar3) {
    iVar4 = 0;
    do {
      while( true ) {
        iVar2 = (iVar3 + iVar4) / 2;
        iVar1 = strncasecmp(name,grgszTextureName[iVar2],0xc);
        if (iVar1 == 0) {
          return grgchTextureType[iVar2];
        }
        if (0 < iVar1) break;
        iVar3 = iVar2 + -1;
        if (iVar3 < iVar4) {
          return 'C';
        }
      }
      iVar4 = iVar2 + 1;
    } while (iVar4 <= iVar3);
  }
  return 'C';
}


// PM_PlayStepSound  @ 0013d200  (line 298)

void PM_PlayStepSound(int step,float fvol)

{
  int iVar1;
  playermove_t *ppVar2;
  int32 iVar3;
  float fVar4;
  vec_t local_18;
  vec_t local_14;
  undefined4 local_10;
  
                    /* Unresolved local var: int irand@[???]
                       Unresolved local var: vec3_t.conflict hvel@[???] */
  ppVar2 = pmove;
  pmove->iStepLeft = (uint)(pmove->iStepLeft == 0);
  if (ppVar2->runfuncs == false) {
    return;
  }
  iVar3 = (*ppVar2->RandomLong)(0,1);
  if ((pmove->multiplayer != false) && (pmove->movevars->footsteps == false)) {
    return;
  }
  local_18 = pmove->velocity[0];
  local_14 = pmove->velocity[1];
  local_10 = 0;
  iVar1 = pmove->iStepLeft;
  if (((pmove->multiplayer != false) && (g_onladder == 0)) &&
     (fVar4 = Length(&local_18), fVar4 <= 220.0)) {
    return;
  }
  iVar1 = iVar3 + iVar1 * 2;
  switch(step) {
  default:
    if (iVar1 == 1) {
      (*pmove->PM_PlaySound)(4,"player/pl_step3.wav",fvol,0.8,0,100);
    }
    else if (iVar1 < 2) {
      if (iVar1 == 0) {
        (*pmove->PM_PlaySound)(4,"player/pl_step1.wav",fvol,0.8,0,100);
      }
    }
    else if (iVar1 == 2) {
      (*pmove->PM_PlaySound)(4,"player/pl_step2.wav",fvol,0.8,0,100);
    }
    else if (iVar1 == 3) {
      (*pmove->PM_PlaySound)(4,"player/pl_step4.wav",fvol,0.8,0,100);
    }
    break;
  case 1:
    if (iVar1 == 1) {
      (*pmove->PM_PlaySound)(4,"player/pl_metal3.wav",fvol,0.8,0,100);
    }
    else if (iVar1 < 2) {
      if (iVar1 == 0) {
        (*pmove->PM_PlaySound)(4,"player/pl_metal1.wav",fvol,0.8,0,100);
      }
    }
    else if (iVar1 == 2) {
      (*pmove->PM_PlaySound)(4,"player/pl_metal2.wav",fvol,0.8,0,100);
    }
    else if (iVar1 == 3) {
      (*pmove->PM_PlaySound)(4,"player/pl_metal4.wav",fvol,0.8,0,100);
    }
    break;
  case 2:
    if (iVar1 == 1) {
      (*pmove->PM_PlaySound)(4,"player/pl_dirt3.wav",fvol,0.8,0,100);
    }
    else if (iVar1 < 2) {
      if (iVar1 == 0) {
        (*pmove->PM_PlaySound)(4,"player/pl_dirt1.wav",fvol,0.8,0,100);
      }
    }
    else if (iVar1 == 2) {
      (*pmove->PM_PlaySound)(4,"player/pl_dirt2.wav",fvol,0.8,0,100);
    }
    else if (iVar1 == 3) {
      (*pmove->PM_PlaySound)(4,"player/pl_dirt4.wav",fvol,0.8,0,100);
    }
    break;
  case 3:
    if (iVar1 == 1) {
      (*pmove->PM_PlaySound)(4,"player/pl_duct3.wav",fvol,0.8,0,100);
    }
    else if (iVar1 < 2) {
      if (iVar1 == 0) {
        (*pmove->PM_PlaySound)(4,"player/pl_duct1.wav",fvol,0.8,0,100);
      }
    }
    else if (iVar1 == 2) {
      (*pmove->PM_PlaySound)(4,"player/pl_duct2.wav",fvol,0.8,0,100);
    }
    else if (iVar1 == 3) {
      (*pmove->PM_PlaySound)(4,"player/pl_duct4.wav",fvol,0.8,0,100);
    }
    break;
  case 4:
    if (iVar1 == 1) {
      (*pmove->PM_PlaySound)(4,"player/pl_grate3.wav",fvol,0.8,0,100);
    }
    else if (iVar1 < 2) {
      if (iVar1 == 0) {
        (*pmove->PM_PlaySound)(4,"player/pl_grate1.wav",fvol,0.8,0,100);
      }
    }
    else if (iVar1 == 2) {
      (*pmove->PM_PlaySound)(4,"player/pl_grate2.wav",fvol,0.8,0,100);
    }
    else if (iVar1 == 3) {
      (*pmove->PM_PlaySound)(4,"player/pl_grate4.wav",fvol,0.8,0,100);
    }
    break;
  case 5:
    iVar3 = (*pmove->RandomLong)(0,4);
    if (iVar3 == 0) {
switchD_0013d701_caseD_4:
      (*pmove->PM_PlaySound)(4,"player/pl_tile5.wav",fvol,0.8,0,100);
    }
    else {
      switch(iVar1) {
      case 0:
        (*pmove->PM_PlaySound)(4,"player/pl_tile1.wav",fvol,0.8,0,100);
        break;
      case 1:
        (*pmove->PM_PlaySound)(4,"player/pl_tile3.wav",fvol,0.8,0,100);
        break;
      case 2:
        (*pmove->PM_PlaySound)(4,"player/pl_tile2.wav",fvol,0.8,0,100);
        break;
      case 3:
        (*pmove->PM_PlaySound)(4,"player/pl_tile4.wav",fvol,0.8,0,100);
        break;
      case 4:
        goto switchD_0013d701_caseD_4;
      }
    }
    break;
  case 6:
    if (iVar1 == 1) {
      (*pmove->PM_PlaySound)(4,"player/pl_slosh3.wav",fvol,0.8,0,100);
    }
    else if (iVar1 < 2) {
      if (iVar1 == 0) {
        (*pmove->PM_PlaySound)(4,"player/pl_slosh1.wav",fvol,0.8,0,100);
      }
    }
    else if (iVar1 == 2) {
      (*pmove->PM_PlaySound)(4,"player/pl_slosh2.wav",fvol,0.8,0,100);
    }
    else if (iVar1 == 3) {
      (*pmove->PM_PlaySound)(4,"player/pl_slosh4.wav",fvol,0.8,0,100);
    }
    break;
  case 7:
                    /* try { // try from 0013d355 to 0014d359 has its CatchHandler @ 0013d340 */
    if (PM_PlayStepSound::iSkipStep == 0) {
      PM_PlayStepSound::iSkipStep = 1;
    }
    else {
      if (PM_PlayStepSound::iSkipStep == 3) {
        PM_PlayStepSound::iSkipStep = 0;
      }
      else {
        PM_PlayStepSound::iSkipStep = PM_PlayStepSound::iSkipStep + 1;
      }
      if (iVar1 == 1) {
        (*pmove->PM_PlaySound)(4,"player/pl_wade2.wav",fvol,0.8,0,100);
      }
      else if (iVar1 < 2) {
        if (iVar1 == 0) {
          (*pmove->PM_PlaySound)(4,"player/pl_wade1.wav",fvol,0.8,0,100);
        }
      }
      else if (iVar1 == 2) {
        (*pmove->PM_PlaySound)(4,"player/pl_wade3.wav",fvol,0.8,0,100);
      }
      else if (iVar1 == 3) {
        (*pmove->PM_PlaySound)(4,"player/pl_wade4.wav",fvol,0.8,0,100);
      }
    }
    break;
  case 8:
    if (iVar1 == 1) {
      (*pmove->PM_PlaySound)(4,"player/pl_ladder3.wav",fvol,0.8,0,100);
    }
    else if (iVar1 < 2) {
      if (iVar1 == 0) {
        (*pmove->PM_PlaySound)(4,"player/pl_ladder1.wav",fvol,0.8,0,100);
      }
    }
    else if (iVar1 == 2) {
      (*pmove->PM_PlaySound)(4,"player/pl_ladder2.wav",fvol,0.8,0,100);
    }
    else if (iVar1 == 3) {
      (*pmove->PM_PlaySound)(4,"player/pl_ladder4.wav",fvol,0.8,0,100);
    }
  }
  return;
}


// PM_MapTextureTypeStepType  @ 0013deb0  (line 441)

int PM_MapTextureTypeStepType(char chTextureType)

{
  int iVar1;
  
  iVar1 = 0;
  if ((byte)(chTextureType + 0xbcU) < 0x13) {
    iVar1 = *(int *)(CSWTCH_100 + (uint)(byte)(chTextureType + 0xbcU) * 4);
  }
  return iVar1;
}


// PM_CatagorizeTextureType  @ 0013ded0  (line 463)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_CatagorizeTextureType(void)

{
  char *__s1;
  playermove_t *ppVar1;
  char *pcVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  vec_t local_34;
  vec_t local_30;
  float local_2c;
  vec_t local_28;
  vec_t local_24;
  float local_20;
  
                    /* Unresolved local var: vec3_t.conflict start@[???]
                       Unresolved local var: vec3_t.conflict end@[???]
                       Unresolved local var: char * pTextureName@[???] */
  ppVar1 = pmove;
  local_34 = pmove->origin[0];
  pmove->sztexturename[0] = '\0';
  local_30 = ppVar1->origin[1];
  ppVar1->chtexturetype = 'C';
  local_2c = ppVar1->origin[2];
  local_20 = local_2c - 64.0;
  local_28 = local_34;
  local_24 = local_30;
  pcVar2 = (*ppVar1->PM_TraceTexture)(ppVar1->onground,&local_34,&local_28);
  ppVar1 = pmove;
  if (pcVar2 != (char *)0x0) {
    cVar4 = *pcVar2;
    if ((cVar4 - 0x2bU & 0xfd) == 0) {
      cVar4 = pcVar2[2];
      pcVar2 = pcVar2 + 2;
    }
    if ((cVar4 == '{' || cVar4 == '~') || ((byte)(cVar4 - 0x20U) < 2)) {
      pcVar2 = pcVar2 + 1;
    }
    __s1 = pmove->sztexturename;
    __strcpy_chk(__s1,pcVar2,0x100);
    ppVar1->sztexturename[0xc] = '\0';
                    /* Unresolved local var: int left@[???]
                       Unresolved local var: int right@[???]
                       Unresolved local var: int pivot@[???]
                       Unresolved local var: int val@[???] */
    iVar7 = gcTextures + -1;
    if (-1 < iVar7) {
      iVar6 = 0;
      do {
        while( true ) {
          iVar5 = (iVar6 + iVar7) / 2;
          iVar3 = strncasecmp(__s1,grgszTextureName[iVar5],0xc);
          if (iVar3 == 0) {
            cVar4 = grgchTextureType[iVar5];
            goto LAB_0013e002;
          }
          if (0 < iVar3) break;
          iVar7 = iVar5 + -1;
          if (iVar7 < iVar6) goto LAB_0013e000;
        }
        iVar6 = iVar5 + 1;
      } while (iVar6 <= iVar7);
    }
LAB_0013e000:
    cVar4 = 'C';
LAB_0013e002:
    ppVar1->chtexturetype = cVar4;
  }
  return;
}


// PM_UpdateStepSound  @ 0013e040  (line 496)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_UpdateStepSound(void)

{
  float fVar1;
  bool bVar2;
  playermove_t *ppVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  float fVar7;
  float fVar8;
  float local_3c;
  float local_34;
  vec_t local_24;
  vec_t local_20;
  float local_1c;
  vec_t local_18;
  vec_t local_14;
  float local_10;
  
                    /* Unresolved local var: int fWalking@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: vec3_t.conflict knee@[???]
                       Unresolved local var: vec3_t.conflict feet@[???]
                       Unresolved local var: vec3_t.conflict center@[???]
                       Unresolved local var: float height@[???]
                       Unresolved local var: float speed@[???]
                       Unresolved local var: float velrun@[???]
                       Unresolved local var: float velwalk@[???]
                       Unresolved local var: float flduck@[???]
                       Unresolved local var: int fLadder@[???]
                       Unresolved local var: int step@[???] */
  PM_CatagorizeTextureType();
  fVar7 = Length(pmove->velocity);
  if ((pmove->movetype == 5) && ((pmove->flags & 0x80000U) == 0)) {
    bVar2 = true;
    local_3c = 100.0;
    local_34 = 80.0;
    fVar1 = 60.0;
  }
  else {
    if ((pmove->flags & 0x4000U) == 0) {
      local_3c = 0.0;
      local_34 = 210.0;
      fVar1 = 120.0;
    }
    else {
      local_3c = 100.0;
      local_34 = 80.0;
      fVar1 = 60.0;
    }
    bVar2 = false;
    if (pmove->onground == -1) {
      return;
    }
  }
  fVar8 = Length(pmove->velocity);
  ppVar3 = pmove;
  if (fVar8 <= 0.0) {
    return;
  }
  if ((fVar7 < fVar1) && (pmove->flTimeStepSound != 0)) {
    return;
  }
  local_24 = pmove->origin[0];
  local_20 = pmove->origin[1];
  fVar1 = pmove->player_maxs[pmove->usehull][2] - pmove->player_mins[pmove->usehull][2];
  local_1c = pmove->origin[2] - fVar1 * 0.3;
  local_10 = pmove->origin[2] - fVar1 * 0.5;
  local_18 = local_24;
  local_14 = local_20;
  if (bVar2) {
    iVar4 = 8;
    pmove->flTimeStepSound = 0x15e;
    fVar7 = 350.0;
    fVar1 = 0.35;
    goto LAB_0013e14f;
  }
  iVar4 = (*pmove->PM_PointContents)(&local_24,(int *)0x0);
  ppVar3 = pmove;
  if (iVar4 == -3) {
    iVar4 = 7;
    fVar7 = 600.0;
    fVar1 = 0.65;
    pmove->flTimeStepSound = 600;
    goto LAB_0013e14f;
  }
  iVar4 = (*pmove->PM_PointContents)(&local_18,(int *)0x0);
  ppVar3 = pmove;
  if (iVar4 == -3) {
    if (fVar7 < local_34) {
      iVar4 = 400;
      fVar7 = 400.0;
      fVar1 = 0.2;
    }
    else if (fVar7 < local_34) {
      fVar7 = 400.0;
      iVar4 = 400;
      fVar1 = 0.5;
    }
    else {
      iVar4 = 300;
      fVar7 = 300.0;
      fVar1 = 0.5;
    }
    pmove->flTimeStepSound = iVar4;
    iVar4 = 6;
    goto LAB_0013e14f;
  }
  iVar4 = 0;
  bVar6 = pmove->chtexturetype + 0xbc;
  if (bVar6 < 0x13) {
    iVar4 = *(int *)(CSWTCH_100 + (uint)bVar6 * 4);
  }
  switch(pmove->chtexturetype) {
  case 'D':
    if (local_34 <= fVar7) {
      iVar5 = 300;
      fVar7 = 300.0;
      fVar1 = 0.55;
    }
    else {
      iVar5 = 400;
      fVar7 = 400.0;
      fVar1 = 0.25;
    }
    goto LAB_0013e2c1;
  default:
    break;
  case 'G':
  case 'S':
    break;
  case 'M':
    break;
  case 'V':
    if (local_34 <= fVar7) {
      iVar5 = 300;
      fVar7 = 300.0;
      fVar1 = 0.7;
    }
    else {
      iVar5 = 400;
      fVar7 = 400.0;
      fVar1 = 0.4;
    }
    goto LAB_0013e2c1;
  }
  if (fVar7 < local_34) {
    iVar5 = 400;
    fVar7 = 400.0;
    fVar1 = 0.2;
  }
  else {
    fVar7 = 300.0;
    iVar5 = 300;
    fVar1 = 0.5;
  }
LAB_0013e2c1:
  pmove->flTimeStepSound = iVar5;
LAB_0013e14f:
  ppVar3->flTimeStepSound = (int)(fVar7 + local_3c);
  if ((ppVar3->flags & 0x4000) != 0) {
    fVar1 = fVar1 * 0.35;
  }
  PM_PlayStepSound(iVar4,fVar1);
  return;
}


// PM_UpdateStepSound  @ 0013e400  (line 511)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_UpdateStepSound(void)

{
                    /* Unresolved local var: int fWalking@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: vec3_t.conflict knee@[???]
                       Unresolved local var: vec3_t.conflict feet@[???]
                       Unresolved local var: vec3_t.conflict center@[???]
                       Unresolved local var: float height@[???]
                       Unresolved local var: float speed@[???]
                       Unresolved local var: float velrun@[???]
                       Unresolved local var: float velwalk@[???]
                       Unresolved local var: float flduck@[???]
                       Unresolved local var: int fLadder@[???]
                       Unresolved local var: int step@[???] */
  if ((pmove->flTimeStepSound < 1) && ((pmove->flags & 0x1000) == 0)) {
    PM_UpdateStepSound();
    return;
  }
  return;
}


// PM_AddToTouched  @ 0013e420  (line 643)

qboolean PM_AddToTouched(pmtrace_t tr,vec_t *impactvelocity)

{
  int iVar1;
  int *piVar2;
  playermove_t *ppVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  vec_t vVar7;
  vec_t vVar8;
  vec_t vVar9;
  
                    /* Unresolved local var: int i@[???] */
  iVar6 = pmove->numtouch;
  if (iVar6 < 1) {
    if (iVar6 == 0) {
      vVar9 = *impactvelocity;
      vVar8 = impactvelocity[1];
      vVar7 = impactvelocity[2];
LAB_0013e47b:
      ppVar3 = pmove;
      pmove->numtouch = iVar6 + 1;
      tr.deltavelocity[0] = vVar9;
      tr.deltavelocity[1] = vVar8;
      uVar5 = 0;
      tr.deltavelocity[2] = vVar7;
      do {
        *(undefined4 *)((int)ppVar3->touchindex[iVar6].endpos + (uVar5 - 0x14)) =
             *(undefined4 *)((int)tr.endpos + (uVar5 - 0x14));
        uVar5 = uVar5 + 4;
      } while (uVar5 < 0x44);
      return true;
    }
  }
  else {
    iVar4 = 0;
    iVar1 = pmove->touchindex[0].ent;
    piVar2 = &pmove->touchindex[1].ent;
    while (tr.ent != iVar1) {
      iVar4 = iVar4 + 1;
      if (iVar4 == iVar6) {
        vVar9 = *impactvelocity;
        vVar8 = impactvelocity[1];
        vVar7 = impactvelocity[2];
        if (599 < iVar6) {
          (*pmove->Con_DPrintf)("Too many entities were touched!\n");
          iVar6 = pmove->numtouch;
        }
        goto LAB_0013e47b;
      }
      iVar1 = *piVar2;
      piVar2 = piVar2 + 0x11;
    }
  }
  return false;
}


// PM_CheckVelocity  @ 0013e530  (line 671)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_CheckVelocity(void)

{
  float fVar1;
  vec_t vVar2;
  vec_t *pvVar3;
  int iVar4;
  playermove_t *ppVar5;
  uint uVar6;
  
                    /* Unresolved local var: int i@[???] */
  ppVar5 = pmove;
  uVar6 = nanmask;
  if (((uint)pmove->velocity[0] & nanmask) == nanmask) {
    (*pmove->Con_Printf)("PM  Got a NaN velocity %i\n",0);
    ppVar5 = pmove;
    uVar6 = nanmask;
    pmove->velocity[0] = 0.0;
  }
  if (((uint)ppVar5->origin[0] & uVar6) == uVar6) {
    (*ppVar5->Con_Printf)("PM  Got a NaN origin on %i\n",0);
    ppVar5 = pmove;
    pmove->origin[0] = 0.0;
  }
  fVar1 = ppVar5->movevars->maxvelocity;
  if (fVar1 < ppVar5->velocity[0]) {
    (*ppVar5->Con_DPrintf)("PM  Got a velocity too high on %i\n",0);
    ppVar5 = pmove;
    uVar6 = nanmask;
    vVar2 = pmove->velocity[1];
    pmove->velocity[0] = pmove->movevars->maxvelocity;
    if (uVar6 != ((uint)vVar2 & uVar6)) goto LAB_0013e58f;
LAB_0013e64f:
    (*ppVar5->Con_Printf)("PM  Got a NaN velocity %i\n",1);
    ppVar5 = pmove;
    iVar4 = nanmask;
    pvVar3 = pmove->origin;
    pmove->velocity[1] = 0.0;
    if (iVar4 == ((uint)pvVar3[1] & iVar4)) {
LAB_0013e690:
      (*ppVar5->Con_Printf)("PM  Got a NaN origin on %i\n",1);
      ppVar5 = pmove;
      pmove->origin[1] = 0.0;
    }
  }
  else {
    if (ppVar5->velocity[0] < -fVar1) {
      (*ppVar5->Con_DPrintf)("PM  Got a velocity too low on %i\n",0);
      ppVar5 = pmove;
      pmove->velocity[0] = -pmove->movevars->maxvelocity;
    }
    uVar6 = nanmask;
    if (nanmask == ((uint)ppVar5->velocity[1] & nanmask)) goto LAB_0013e64f;
LAB_0013e58f:
    if (uVar6 == ((uint)ppVar5->origin[1] & uVar6)) goto LAB_0013e690;
  }
  fVar1 = ppVar5->movevars->maxvelocity;
  if (fVar1 < ppVar5->velocity[1]) {
    (*ppVar5->Con_DPrintf)("PM  Got a velocity too high on %i\n",1);
    ppVar5 = pmove;
    uVar6 = nanmask;
    pvVar3 = pmove->velocity;
    pmove->velocity[1] = pmove->movevars->maxvelocity;
    if (uVar6 != ((uint)pvVar3[2] & uVar6)) goto LAB_0013e5d3;
LAB_0013e73a:
    (*ppVar5->Con_Printf)("PM  Got a NaN velocity %i\n",2);
    ppVar5 = pmove;
    iVar4 = nanmask;
    pvVar3 = pmove->origin;
    pmove->velocity[2] = 0.0;
    if (((uint)pvVar3[2] & iVar4) != iVar4) goto LAB_0013e5e0;
  }
  else {
    if (ppVar5->velocity[1] < -fVar1) {
      (*ppVar5->Con_DPrintf)("PM  Got a velocity too low on %i\n",1);
      ppVar5 = pmove;
      pmove->velocity[1] = -pmove->movevars->maxvelocity;
    }
    uVar6 = nanmask;
    if (nanmask == ((uint)ppVar5->velocity[2] & nanmask)) goto LAB_0013e73a;
LAB_0013e5d3:
    if (((uint)ppVar5->origin[2] & uVar6) != uVar6) goto LAB_0013e5e0;
  }
  (*ppVar5->Con_Printf)("PM  Got a NaN origin on %i\n",2);
  ppVar5 = pmove;
  pmove->origin[2] = 0.0;
LAB_0013e5e0:
  fVar1 = ppVar5->movevars->maxvelocity;
  if (fVar1 < ppVar5->velocity[2]) {
    (*ppVar5->Con_DPrintf)("PM  Got a velocity too high on %i\n",2);
    pmove->velocity[2] = pmove->movevars->maxvelocity;
    return;
  }
  if (ppVar5->velocity[2] < -fVar1) {
    (*ppVar5->Con_DPrintf)("PM  Got a velocity too low on %i\n",2);
    pmove->velocity[2] = -pmove->movevars->maxvelocity;
    return;
  }
  return;
}


// PM_ClipVelocity  @ 0013e890  (line 716)

int PM_ClipVelocity(vec_t *in,vec_t *normal,vec_t *out,float overbounce)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  
                    /* Unresolved local var: float backoff@[???]
                       Unresolved local var: float change@[???]
                       Unresolved local var: float angle@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int blocked@[???] */
  fVar1 = normal[2];
  uVar3 = (uint)(0.0 < fVar1);
  if (fVar1 == 0.0) {
    uVar3 = 0.0 < fVar1 | 2;
  }
  fVar1 = (fVar1 * in[2] + *in * *normal + in[1] * normal[1]) * overbounce;
  fVar2 = *in - *normal * fVar1;
  if ((fVar2 <= -0.1) || (0.1 <= fVar2)) {
    *out = fVar2;
  }
  else {
    *out = 0.0;
  }
  fVar2 = in[1] - normal[1] * fVar1;
  if ((fVar2 <= -0.1) || (0.1 <= fVar2)) {
    out[1] = fVar2;
  }
  else {
    out[1] = 0.0;
  }
  fVar1 = in[2] - fVar1 * normal[2];
  if ((-0.1 < fVar1) && (fVar1 < 0.1)) {
    out[2] = 0.0;
    return uVar3;
  }
  out[2] = fVar1;
  return uVar3;
}


// PM_AddCorrectGravity  @ 0013e990  (line 751)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_AddCorrectGravity(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  vec_t *pvVar5;
  playermove_t *ppVar6;
  
                    /* Unresolved local var: float ent_gravity@[???] */
  ppVar6 = pmove;
  if (pmove->waterjumptime != 0.0) {
    return;
  }
  fVar4 = 1.0;
  if (pmove->gravity != 0.0) {
    fVar4 = pmove->gravity;
  }
  fVar1 = pmove->frametime;
  fVar2 = pmove->movevars->gravity;
  pvVar5 = pmove->velocity;
  fVar3 = pmove->basevelocity[2];
  pmove->basevelocity[2] = 0.0;
  ppVar6->velocity[2] = fVar1 * fVar3 + (pvVar5[2] - fVar4 * fVar2 * 0.5 * fVar1);
  PM_CheckVelocity();
  return;
}


// PM_FixupGravityVelocity  @ 0013ea10  (line 773)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_FixupGravityVelocity(void)

{
  float fVar1;
  
                    /* Unresolved local var: float ent_gravity@[???] */
  if (pmove->waterjumptime != 0.0) {
    return;
  }
  fVar1 = 1.0;
  if (pmove->gravity != 0.0) {
    fVar1 = pmove->gravity;
  }
  pmove->velocity[2] =
       pmove->velocity[2] - fVar1 * pmove->movevars->gravity * pmove->frametime * 0.5;
  PM_CheckVelocity();
  return;
}


// PM_FlyMove  @ 0013ea70  (line 795)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int PM_FlyMove(void)

{
  vec_t *pvVar1;
  float fVar2;
  float fVar3;
  vec_t vVar4;
  vec_t vVar5;
  vec_t vVar6;
  float fVar7;
  _func_pmtrace_t_float_ptr_float_ptr_int_int *p_Var8;
  vec_t vVar9;
  _func_void_char_ptr_varargs *p_Var10;
  float fVar11;
  float fVar12;
  int *piVar13;
  playermove_t *ppVar14;
  float *pfVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  vec_t *pvVar19;
  vec_t *pvVar20;
  vec_t *pvVar21;
  uint uVar22;
  int iVar23;
  vec_t vVar24;
  vec_t vVar25;
  vec_t vVar26;
  vec_t vVar27;
  vec_t vVar28;
  vec_t vVar29;
  vec_t vVar30;
  vec_t vVar31;
  vec_t avStack_184 [12];
  vec_t local_154 [5];
  float local_140;
  vec_t local_13c [7];
  float local_120 [6];
  vec_t local_108 [3];
  float local_fc [4];
  vec_t local_ec [21];
  float local_98;
  vec_t local_94 [12];
  vec_t local_64 [4];
  float local_54;
  vec_t local_50 [16];
  
                    /* Unresolved local var: int bumpcount@[???]
                       Unresolved local var: int numbumps@[???]
                       Unresolved local var: vec3_t.conflict dir@[???]
                       Unresolved local var: float d@[???]
                       Unresolved local var: int numplanes@[???]
                       Unresolved local var: vec_t[5][3] planes@[???]
                       Unresolved local var: vec3_t.conflict primal_velocity@[???]
                       Unresolved local var: vec3_t.conflict original_velocity@[???]
                       Unresolved local var: vec3_t.conflict new_velocity@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: pmtrace_t trace@[???]
                       Unresolved local var: vec3_t.conflict end@[???]
                       Unresolved local var: float time_left@[???]
                       Unresolved local var: float allFraction@[???]
                       Unresolved local var: int blocked@[???] */
  uVar22 = 0;
  iVar23 = 0;
  local_108[2] = 5.60519e-45;
  fVar2 = pmove->velocity[0];
  local_120[5] = fVar2;
  vVar28 = pmove->velocity[1];
  local_108[0] = vVar28;
  vVar27 = pmove->velocity[2];
  local_108[1] = vVar27;
  local_120[3] = pmove->frametime;
  local_120[4] = 0.0;
  ppVar14 = pmove;
  pvVar19 = avStack_184 + 2;
  fVar3 = fVar2;
  vVar5 = vVar27;
  vVar6 = vVar28;
  do {
    if (((fVar3 == 0.0) && (vVar28 == 0.0)) && (pvVar21 = pvVar19, vVar27 == 0.0))
    goto LAB_0013f0d0;
    pvVar19[0xd] = vVar6;
    pvVar19[0xc] = vVar5;
    pvVar19[0xb] = fVar2;
    fVar2 = pvVar19[0x1a];
    pvVar19[0x24] = fVar3 * fVar2 + ppVar14->origin[0];
    pvVar19[0x25] = vVar28 * fVar2 + ppVar14->origin[1];
    fVar3 = ppVar14->origin[2];
    pvVar19[4] = -NAN;
    pvVar19[2] = (vec_t)(pvVar19 + 0x24);
    pvVar19[3] = 0.0;
    pvVar19[1] = (vec_t)ppVar14->origin;
    pvVar19[0x26] = fVar2 * vVar27 + fVar3;
    *pvVar19 = (vec_t)(pvVar19 + 0x36);
    p_Var8 = ppVar14->PM_PlayerTrace;
    pvVar19[-1] = 1.829371e-39;
    (*p_Var8)((pmtrace_t *)*pvVar19,(float *)pvVar19[1],(float *)pvVar19[2],(int)pvVar19[3],
              (int)pvVar19[4]);
    vVar31 = vec3_origin[2];
    vVar9 = vec3_origin[1];
    ppVar14 = pmove;
    pvVar20 = pvVar19 + -1;
    pvVar21 = pvVar19 + -1;
    fVar3 = pvVar19[0x39];
    vVar4 = pvVar19[0x3f];
    vVar28 = pvVar19[0x3a];
    vVar27 = pvVar19[0x3b];
    vVar26 = pvVar19[0x3c];
    pvVar19[0x1a] = pvVar19[0x1a] + fVar3;
    fVar2 = pvVar19[10];
    vVar5 = pvVar19[0xb];
    vVar25 = pvVar19[0x3d];
    vVar24 = pvVar19[0x3e];
    vVar6 = pvVar19[0xc];
    if (pvVar19[0x35] != 0.0) {
      pmove->velocity[0] = vec3_origin[0];
      ppVar14->velocity[1] = vVar9;
      ppVar14->velocity[2] = vVar31;
      return 4;
    }
    iVar18 = iVar23;
    if (0.0 < fVar3) {
      fVar2 = pmove->velocity[0];
      pmove->origin[0] = vVar28;
      vVar6 = ppVar14->velocity[1];
      ppVar14->origin[1] = vVar27;
      vVar5 = ppVar14->velocity[2];
      ppVar14->origin[2] = vVar26;
      iVar18 = 0;
    }
    if (fVar3 == 1.0) goto LAB_0013f0d0;
    uVar16 = 0;
    pvVar19[0x35] = 0.0;
    do {
      *(undefined4 *)((int)pvVar19 + uVar16 + 0x118) = *(undefined4 *)((int)pvVar19 + uVar16 + 0xd4)
      ;
      uVar16 = uVar16 + 4;
    } while (uVar16 < 0x44);
                    /* Unresolved local var: int i@[???] */
    iVar23 = pmove->numtouch;
    vVar9 = pvVar19[0x41];
    ppVar14 = pmove;
    if (iVar23 < 1) {
      if (iVar23 == 0) {
        vVar31 = pmove->velocity[0];
        vVar30 = pmove->velocity[1];
        vVar29 = pmove->velocity[2];
LAB_0013ecb6:
        ppVar14 = pmove;
        pmove->numtouch = iVar23 + 1;
        pvVar19[0x46] = 0.0;
        pvVar19[0x4b] = vVar28;
        pvVar19[0x4c] = vVar27;
        pvVar19[0x4a] = fVar3;
        pvVar19[0x4d] = vVar26;
        uVar16 = 0;
        pvVar19[0x4e] = vVar25;
        pvVar19[0x50] = vVar4;
        pvVar19[0x4f] = vVar24;
        pvVar19[0x53] = vVar31;
        pvVar19[0x54] = vVar30;
        pvVar19[0x55] = vVar29;
        pvVar19[0x52] = vVar9;
        do {
          *(undefined4 *)((int)ppVar14->touchindex[iVar23].endpos + (uVar16 - 0x14)) =
               *(undefined4 *)((int)pvVar19 + uVar16 + 0x118);
          uVar16 = uVar16 + 4;
        } while (uVar16 < 0x44);
      }
    }
    else {
      iVar17 = 0;
      vVar31 = (vec_t)pmove->touchindex[0].ent;
      piVar13 = &pmove->touchindex[1].ent;
      while (vVar31 != vVar9) {
        iVar17 = iVar17 + 1;
        if (iVar17 == iVar23) {
          vVar31 = pmove->velocity[0];
          vVar30 = pmove->velocity[1];
          vVar29 = pmove->velocity[2];
          if (599 < iVar23) {
            pvVar19[0x16] = vVar6;
            pvVar19[0x15] = vVar5;
            pvVar19[0x14] = fVar2;
            pvVar19[0x13] = vVar4;
            pvVar19[-1] = (vec_t)"Too many entities were touched!\n";
            pvVar19[0xf] = fVar3;
            pvVar19[0x12] = vVar31;
            pvVar19[0x11] = vVar30;
            pvVar19[0x10] = vVar29;
            pvVar19[0xe] = vVar28;
            pvVar19[0xd] = vVar27;
            pvVar19[0xc] = vVar26;
            pvVar19[0xb] = vVar25;
            pvVar19[10] = vVar24;
            p_Var10 = pmove->Con_DPrintf;
            pvVar19[-2] = 1.832376e-39;
            (*p_Var10)((char *)pvVar19[-1]);
            vVar31 = pvVar19[0x12];
            vVar30 = pvVar19[0x11];
            vVar29 = pvVar19[0x10];
            iVar23 = pmove->numtouch;
            vVar6 = pvVar19[0x16];
            vVar5 = pvVar19[0x15];
            fVar2 = pvVar19[0x14];
            vVar4 = pvVar19[0x13];
            fVar3 = pvVar19[0xf];
            vVar28 = pvVar19[0xe];
            vVar27 = pvVar19[0xd];
            vVar26 = pvVar19[0xc];
            vVar25 = pvVar19[0xb];
            vVar24 = pvVar19[10];
          }
          goto LAB_0013ecb6;
        }
        vVar31 = (vec_t)*piVar13;
        piVar13 = piVar13 + 0x11;
      }
    }
    if (0.7 < vVar4) {
      uVar22 = uVar22 | 1;
    }
    if (vVar4 == 0.0) {
      uVar22 = uVar22 | 2;
    }
    pvVar19[0x19] = pvVar19[0x19] - fVar3 * pvVar19[0x19];
    if (4 < iVar18) {
LAB_0013f465:
      ppVar14->velocity[0] = vec3_origin[0];
      ppVar14->velocity[1] = vec3_origin[1];
      ppVar14->velocity[2] = vec3_origin[2];
      pvVar21 = pvVar19 + -1;
      goto LAB_0013f0d0;
    }
    iVar23 = iVar18 + 1;
    pvVar19[iVar18 * 3 + 0x26] = vVar25;
    pvVar19[iVar18 * 3 + 0x28] = vVar4;
    pvVar19[iVar18 * 3 + 0x27] = vVar24;
    if (((iVar23 == 1) && (ppVar14->movetype == 3)) &&
       ((ppVar14->onground == -1 || (ppVar14->friction != 1.0)))) {
      fVar3 = pvVar19[0x28];
                    /* Unresolved local var: float backoff@[???]
                       Unresolved local var: float change@[???]
                       Unresolved local var: float angle@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int blocked@[???] */
      fVar7 = pvVar19[0x27];
      if (fVar3 <= 0.7) {
        fVar11 = (fVar3 * vVar5 + fVar7 * vVar6 + pvVar19[0x26] * fVar2) *
                 ((1.0 - ppVar14->friction) * ppVar14->movevars->bounce + 1.0);
      }
      else {
        fVar11 = fVar3 * vVar5 + fVar7 * vVar6 + pvVar19[0x26] * fVar2;
      }
                    /* Unresolved local var: float backoff@[???]
                       Unresolved local var: float change@[???]
                       Unresolved local var: float angle@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int blocked@[???] */
      fVar12 = fVar2 - pvVar19[0x26] * fVar11;
      fVar2 = fVar12;
      if ((-0.1 < fVar12) && (fVar2 = 0.0, 0.1 <= fVar12)) {
        fVar2 = fVar12;
      }
      fVar7 = vVar6 - fVar7 * fVar11;
      vVar28 = fVar7;
      if ((-0.1 < fVar7) && (vVar28 = 0.0, 0.1 <= fVar7)) {
        vVar28 = fVar7;
      }
      fVar3 = vVar5 - fVar11 * fVar3;
      vVar27 = fVar3;
      if ((-0.1 < fVar3) && (vVar27 = 0.0, 0.1 <= fVar3)) {
        vVar27 = fVar3;
      }
      ppVar14->velocity[0] = fVar2;
      ppVar14->velocity[1] = vVar28;
      ppVar14->velocity[2] = vVar27;
      fVar3 = fVar2;
      vVar5 = vVar27;
      vVar6 = vVar28;
    }
    else {
      pfVar15 = pvVar19 + 0x26;
      iVar18 = 0;
      pvVar19[0xd] = pvVar19[0x29];
      pvVar19[0xe] = pvVar19[0x2a];
      pvVar19[0xf] = pvVar19[0x2b];
      pvVar19[0x10] = pvVar19[0x2c];
      pvVar19[0x11] = pvVar19[0x2d];
      pvVar19[0x12] = pvVar19[0x2e];
      pvVar19[0x13] = pvVar19[0x2f];
      pvVar19[0x14] = pvVar19[0x30];
      pvVar19[0x15] = pvVar19[0x31];
      pvVar19[0x16] = pvVar19[0x32];
      pvVar19[0x17] = pvVar19[0x33];
      pvVar19[0x18] = pvVar19[0x34];
      pvVar19[10] = pvVar19[0x26];
      pvVar19[0xb] = pvVar19[0x27];
      pvVar19[0xc] = pvVar19[0x28];
      do {
                    /* Unresolved local var: float backoff@[???]
                       Unresolved local var: float change@[???]
                       Unresolved local var: float angle@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int blocked@[???] */
        fVar3 = pfVar15[2] * vVar5 + *pfVar15 * fVar2 + pfVar15[1] * vVar6;
        fVar7 = fVar2 - *pfVar15 * fVar3;
        ppVar14->velocity[0] = fVar7;
        if ((-0.1 < fVar7) && (fVar7 < 0.1)) {
          ppVar14->velocity[0] = 0.0;
        }
        vVar28 = vVar6 - pfVar15[1] * fVar3;
        ppVar14->velocity[1] = vVar28;
        if ((-0.1 < vVar28) && (vVar28 < 0.1)) {
          ppVar14->velocity[1] = 0.0;
          vVar28 = 0.0;
        }
        vVar27 = vVar5 - fVar3 * pfVar15[2];
        ppVar14->velocity[2] = vVar27;
        if ((-0.1 < vVar27) && (vVar27 < 0.1)) {
          ppVar14->velocity[2] = 0.0;
          vVar27 = 0.0;
        }
        if (iVar18 == 0) {
          if (iVar23 == 1) break;
          fVar3 = ppVar14->velocity[0];
LAB_0013ef89:
          if (0.0 <= pvVar19[0xf] * vVar27 + pvVar19[0xd] * fVar3 + pvVar19[0xe] * vVar28) {
            if (iVar23 == 2) break;
            if (iVar18 != 2) goto LAB_0013efbd;
            if (iVar23 == 3) break;
LAB_0013efed:
            if (0.0 <= pvVar19[0x15] * vVar27 + pvVar19[0x13] * fVar3 + pvVar19[0x14] * vVar28) {
              if (iVar23 != 5) goto LAB_0013f152;
              if (iVar18 == 4) goto LAB_0013f070;
LAB_0013f01d:
              if (0.0 <= pvVar19[0x18] * vVar27 + pvVar19[0x17] * vVar28 + fVar3 * pvVar19[0x16])
              break;
            }
          }
        }
        else {
          fVar3 = ppVar14->velocity[0];
          if (0.0 <= pvVar19[0xc] * vVar27 + pvVar19[0xb] * vVar28 + pvVar19[10] * fVar3) {
            if (iVar23 == 1) break;
            if (iVar18 != 1) goto LAB_0013ef89;
            if (iVar23 == 2) break;
LAB_0013efbd:
            if (0.0 <= pvVar19[0x12] * vVar27 + pvVar19[0x10] * fVar3 + pvVar19[0x11] * vVar28) {
              if (iVar23 == 3) break;
              if (iVar18 != 3) goto LAB_0013efed;
              if (iVar23 == 5) goto LAB_0013f01d;
LAB_0013f152:
              if (iVar23 == 4) break;
            }
          }
        }
        iVar18 = iVar18 + 1;
        pfVar15 = pfVar15 + 3;
      } while (iVar18 != iVar23);
      if (iVar23 == iVar18) {
        if (iVar23 != 2) goto LAB_0013f465;
        pvVar19[0xc] = vVar6;
        *pvVar19 = (vec_t)(pvVar19 + 0x29);
        pvVar19[0xb] = vVar5;
        pvVar19[-1] = (vec_t)(pvVar19 + 0x26);
        pvVar19[10] = fVar2;
        pvVar19[1] = (vec_t)(pvVar19 + 0x20);
        pvVar19[-2] = 1.831634e-39;
        CrossProduct((vec_t *)pvVar19[-1],(vec_t *)*pvVar19,(vec_t *)pvVar19[1]);
        pvVar19[1] = (vec_t)pmove->velocity;
        fVar2 = pmove->velocity[0];
        fVar3 = pmove->velocity[1];
        fVar7 = pmove->velocity[2];
        pvVar19[-1] = (vec_t)(pvVar19 + 0x20);
        *pvVar19 = pvVar19[0x22] * fVar7 + pvVar19[0x21] * fVar3 + pvVar19[0x20] * fVar2;
        pvVar19[-2] = 1.831716e-39;
        VectorScale((vec_t *)pvVar19[-1],*pvVar19,(vec_t *)pvVar19[1]);
        vVar28 = pmove->velocity[1];
        vVar27 = pmove->velocity[2];
        fVar2 = pvVar19[10];
        vVar5 = pvVar19[0xb];
        vVar6 = pvVar19[0xc];
        ppVar14 = pmove;
      }
LAB_0013f070:
      fVar3 = ppVar14->velocity[0];
      if (pvVar19[0x1d] * vVar27 + pvVar19[0x1c] * vVar28 + pvVar19[0x1b] * ppVar14->velocity[0] <=
          0.0) goto LAB_0013f465;
    }
    pvVar1 = pvVar19 + 0x1e;
    *pvVar1 = (vec_t)((int)*pvVar1 + -1);
    pvVar19 = pvVar19 + -1;
    pvVar21 = pvVar20;
    if (*pvVar1 == 0.0) {
LAB_0013f0d0:
      vVar27 = vec3_origin[2];
      vVar28 = vec3_origin[1];
      ppVar14 = pmove;
      if (*(float *)((int)pvVar21 + 0x6c) == 0.0) {
        pmove->velocity[0] = vec3_origin[0];
        ppVar14->velocity[1] = vVar28;
        ppVar14->velocity[2] = vVar27;
        return uVar22;
      }
      return uVar22;
    }
  } while( true );
}


// PM_Accelerate  @ 0013f530  (line 996)

void PM_Accelerate(vec_t *wishdir,float wishspeed,float accel)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  playermove_t *ppVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float addspeed@[???]
                       Unresolved local var: float accelspeed@[???]
                       Unresolved local var: float currentspeed@[???] */
  ppVar5 = pmove;
  if ((pmove->dead == false) && (pmove->waterjumptime == 0.0)) {
    fVar1 = pmove->velocity[1];
    fVar2 = pmove->velocity[2];
    fVar3 = wishspeed - (wishdir[2] * fVar2 + pmove->velocity[0] * *wishdir + wishdir[1] * fVar1);
    if (0.0 < fVar3) {
      fVar4 = accel * pmove->frametime * wishspeed * pmove->friction;
      if (fVar3 < fVar4) {
        fVar4 = fVar3;
      }
      pmove->velocity[0] = pmove->velocity[0] + *wishdir * fVar4;
      ppVar5->velocity[1] = wishdir[1] * fVar4 + fVar1;
      ppVar5->velocity[2] = fVar4 * wishdir[2] + fVar2;
    }
  }
  return;
}


// PM_WalkMove  @ 0013f5d0  (line 1035)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_WalkMove(void)

{
  vec_t vVar1;
  vec_t vVar2;
  vec_t vVar3;
  float fVar4;
  float fVar5;
  vec_t vVar6;
  vec_t vVar7;
  qboolean qVar8;
  int iVar9;
  movevars_s *pmVar10;
  float fVar11;
  playermove_t *ppVar12;
  vec_t *v;
  float fVar13;
  float local_b8;
  float local_b4;
  float local_74;
  float local_70;
  undefined4 local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  vec_t local_54;
  pmtrace_t local_50;
  
                    /* Unresolved local var: int clip@[???]
                       Unresolved local var: int oldonground@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t.conflict wishvel@[???]
                       Unresolved local var: float spd@[???]
                       Unresolved local var: float fmove@[???]
                       Unresolved local var: float smove@[???]
                       Unresolved local var: vec3_t.conflict wishdir@[???]
                       Unresolved local var: float wishspeed@[???]
                       Unresolved local var: vec3_t.conflict dest@[???]
                       Unresolved local var: vec3_t.conflict start@[???]
                       Unresolved local var: vec3_t.conflict original@[???]
                       Unresolved local var: vec3_t.conflict originalvel@[???]
                       Unresolved local var: vec3_t.conflict down@[???]
                       Unresolved local var: vec3_t.conflict downvel@[???]
                       Unresolved local var: float downdist@[???]
                       Unresolved local var: float updist@[???]
                       Unresolved local var: pmtrace_t trace@[???] */
  ppVar12 = pmove;
  fVar13 = (pmove->cmd).forwardmove;
  v = pmove->forward;
  pmove->forward[2] = 0.0;
  fVar4 = (ppVar12->cmd).sidemove;
  ppVar12->right[2] = 0.0;
  VectorNormalize(v);
  VectorNormalize(pmove->right);
  local_6c = 0;
  local_60 = 0.0;
  local_74 = pmove->right[0] * fVar4 + pmove->forward[0] * fVar13;
  local_70 = fVar4 * pmove->right[1] + fVar13 * pmove->forward[1];
  local_68 = local_74;
  local_64 = local_70;
  fVar13 = VectorNormalize(&local_68);
  if (pmove->maxspeed < fVar13) {
    VectorScale(&local_74,pmove->maxspeed / fVar13,&local_74);
    fVar13 = pmove->maxspeed;
  }
  ppVar12 = pmove;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float addspeed@[???]
                       Unresolved local var: float accelspeed@[???]
                       Unresolved local var: float currentspeed@[???] */
  qVar8 = pmove->dead;
  pmove->velocity[2] = 0.0;
  if (qVar8 == false) {
    fVar4 = ppVar12->velocity[0];
    if (ppVar12->waterjumptime == 0.0) {
      fVar5 = ppVar12->velocity[1];
      fVar11 = fVar13 - (local_60 * 0.0 + fVar5 * local_64 + fVar4 * local_68);
      if (0.0 < fVar11) {
        fVar13 = ppVar12->movevars->accelerate * ppVar12->frametime * fVar13 * ppVar12->friction;
        if (fVar11 < fVar13) {
          fVar13 = fVar11;
        }
        fVar4 = local_68 * fVar13 + fVar4;
        ppVar12->velocity[0] = fVar4;
        fVar5 = local_64 * fVar13 + fVar5;
        ppVar12->velocity[1] = fVar5;
        ppVar12->velocity[2] = fVar13 * local_60 + 0.0;
      }
    }
    else {
      fVar5 = ppVar12->velocity[1];
    }
  }
  else {
    fVar4 = ppVar12->velocity[0];
    fVar5 = ppVar12->velocity[1];
  }
  ppVar12->velocity[0] = fVar4 + ppVar12->basevelocity[0];
  ppVar12->velocity[1] = fVar5 + ppVar12->basevelocity[1];
  ppVar12->velocity[2] = ppVar12->basevelocity[2] + 0.0;
  fVar13 = Length(ppVar12->velocity);
  ppVar12 = pmove;
  if (1.0 <= fVar13) {
    local_54 = pmove->origin[2];
    iVar9 = pmove->onground;
    local_5c = pmove->frametime * pmove->velocity[0] + pmove->origin[0];
    local_58 = pmove->frametime * pmove->velocity[1] + pmove->origin[1];
    (*pmove->PM_PlayerTrace)(&local_50,pmove->origin,&local_5c,0,-1);
    ppVar12 = pmove;
    if ((float)local_50.inwater == 1.0) {
      pmove->origin[0] = local_50.fraction;
      ppVar12->origin[1] = local_50.endpos[0];
      ppVar12->origin[2] = local_50.endpos[1];
    }
    else if (((iVar9 != -1) || (pmove->waterlevel != 0)) && (pmove->waterjumptime == 0.0)) {
      fVar13 = pmove->origin[0];
      vVar1 = pmove->velocity[0];
      fVar4 = pmove->origin[1];
      vVar2 = pmove->velocity[1];
      vVar3 = pmove->velocity[2];
      fVar5 = pmove->origin[2];
      PM_FlyMove();
      ppVar12 = pmove;
      pmVar10 = pmove->movevars;
      vVar6 = pmove->origin[0];
      pmove->origin[0] = fVar13;
      vVar7 = ppVar12->origin[2];
      ppVar12->origin[1] = fVar4;
      ppVar12->velocity[0] = vVar1;
      ppVar12->velocity[1] = vVar2;
      ppVar12->velocity[2] = vVar3;
      ppVar12->origin[2] = fVar5;
      local_58 = fVar5 + pmVar10->stepsize;
      local_60 = fVar13;
      local_5c = fVar4;
      (*ppVar12->PM_PlayerTrace)(&local_50,ppVar12->origin,&local_5c,0,-1);
      ppVar12 = pmove;
      if (local_54 == 0.0 && local_58 == 0.0) {
        pmove->origin[0] = (vec_t)local_50.inwater;
        ppVar12->origin[2] = local_50.endpos[0];
        ppVar12->origin[1] = local_50.fraction;
      }
      PM_FlyMove();
      local_64 = pmove->origin[0];
      local_60 = pmove->origin[1];
      local_5c = pmove->origin[2] - pmove->movevars->stepsize;
      (*pmove->PM_PlayerTrace)(&local_50,pmove->origin,&local_5c,0,-1);
      ppVar12 = pmove;
      if (0.7 <= local_50.endpos[2]) {
        if (local_5c == 0.0 && local_58 == 0.0) {
          pmove->origin[0] = (vec_t)local_50.inopen;
          ppVar12->origin[1] = (vec_t)local_50.inwater;
          ppVar12->origin[2] = local_50.fraction;
        }
        else {
          local_50.fraction = pmove->origin[2];
          local_50.inopen = (qboolean)pmove->origin[0];
          local_50.inwater = (qboolean)pmove->origin[1];
        }
        ppVar12->up[0] = (vec_t)local_50.inopen;
        ppVar12->up[1] = (vec_t)local_50.inwater;
        ppVar12->up[2] = local_50.fraction;
        if ((fVar4 - local_b4) * (fVar4 - local_b4) + (fVar13 - local_b8) * (fVar13 - local_b8) <=
            ((float)local_50.inwater - local_b4) * ((float)local_50.inwater - local_b4) +
            ((float)local_50.inopen - local_b8) * ((float)local_50.inopen - local_b8)) {
          ppVar12->velocity[2] = vVar6;
          return;
        }
      }
      ppVar12->origin[0] = fVar13;
      ppVar12->origin[1] = fVar4;
      ppVar12->origin[2] = vVar1;
      ppVar12->velocity[0] = fVar5;
      ppVar12->velocity[1] = vVar7;
      ppVar12->velocity[2] = vVar6;
    }
    return;
  }
  pmove->velocity[0] = 0.0;
  ppVar12->velocity[1] = 0.0;
  ppVar12->velocity[2] = 0.0;
  return;
}


// PM_Friction  @ 0013fb60  (line 1203)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_Friction(void)

{
  float fVar1;
  float fVar2;
  playermove_t *ppVar3;
  playermove_t *ppVar4;
  movevars_s *pmVar5;
  float fVar6;
  float local_74;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  pmtrace_t local_50;
  
                    /* Unresolved local var: float * vel@[???]
                       Unresolved local var: float speed@[???]
                       Unresolved local var: float newspeed@[???]
                       Unresolved local var: float control@[???]
                       Unresolved local var: float friction@[???]
                       Unresolved local var: float drop@[???]
                       Unresolved local var: vec3_t.conflict newvel@[???] */
  ppVar3 = pmove;
  if (pmove->waterjumptime == 0.0) {
    fVar1 = pmove->velocity[2] * pmove->velocity[2] +
            pmove->velocity[1] * pmove->velocity[1] + pmove->velocity[0] * pmove->velocity[0];
    fVar6 = SQRT(fVar1);
    if (NAN(fVar6)) {
      fVar6 = sqrtf(fVar1);
    }
    if (0.1 <= fVar6) {
      fVar1 = 0.0;
      if (pmove->onground != -1) {
                    /* Unresolved local var: vec3_t.conflict start@[???]
                       Unresolved local var: vec3_t.conflict stop@[???]
                       Unresolved local var: pmtrace_t trace@[???] */
        local_68 = (ppVar3->velocity[0] / fVar6) * 16.0 + pmove->origin[0];
        local_64 = (ppVar3->velocity[1] / fVar6) * 16.0 + pmove->origin[1];
        local_60 = pmove->player_mins[pmove->usehull][2] + pmove->origin[2];
        local_54 = local_60 - 34.0;
        local_5c = local_68;
        local_58 = local_64;
        (*pmove->PM_PlayerTrace)(&local_50,&local_68,&local_5c,0,-1);
        if ((float)local_50.inwater == 1.0) {
          pmVar5 = pmove->movevars;
          fVar1 = pmVar5->friction * pmVar5->edgefriction;
        }
        else {
          pmVar5 = pmove->movevars;
          fVar1 = pmVar5->friction;
        }
        fVar6 = pmVar5->stopspeed;
        if (pmVar5->stopspeed <= local_74) {
          fVar6 = local_74;
        }
        fVar1 = fVar6 * fVar1 * pmove->friction * pmove->frametime + 0.0;
        fVar6 = local_74;
      }
      ppVar4 = pmove;
      fVar2 = 0.0;
      if (0.0 <= fVar6 - fVar1) {
        fVar2 = fVar6 - fVar1;
      }
      fVar2 = fVar2 / fVar6;
      fVar1 = ppVar3->velocity[1];
      fVar6 = ppVar3->velocity[2];
      pmove->velocity[0] = fVar2 * ppVar3->velocity[0];
      ppVar4->velocity[1] = fVar1 * fVar2;
      ppVar4->velocity[2] = fVar6 * fVar2;
      return;
    }
  }
  return;
}


// PM_AirAccelerate  @ 0013fcf0  (line 1284)

void PM_AirAccelerate(vec_t *wishdir,float wishspeed,float accel)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  playermove_t *ppVar5;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float addspeed@[???]
                       Unresolved local var: float accelspeed@[???]
                       Unresolved local var: float currentspeed@[???]
                       Unresolved local var: float wishspd@[???] */
  ppVar5 = pmove;
  if ((pmove->dead == false) && (pmove->waterjumptime == 0.0)) {
    fVar3 = wishspeed;
    if (30.0 < wishspeed) {
      fVar3 = 30.0;
    }
    fVar1 = pmove->velocity[1];
    fVar2 = pmove->velocity[2];
    fVar3 = fVar3 - (wishdir[2] * fVar2 + pmove->velocity[0] * *wishdir + wishdir[1] * fVar1);
    if (0.0 < fVar3) {
      fVar4 = pmove->friction * wishspeed * accel * pmove->frametime;
      if (fVar3 < fVar4) {
        fVar4 = fVar3;
      }
      pmove->velocity[0] = *wishdir * fVar4 + pmove->velocity[0];
      ppVar5->velocity[1] = wishdir[1] * fVar4 + fVar1;
      ppVar5->velocity[2] = fVar4 * wishdir[2] + fVar2;
    }
  }
  return;
}


// PM_WaterMove  @ 0013fda0  (line 1322)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_WaterMove(void)

{
  float fVar1;
  float fVar2;
  playermove_t *ppVar3;
  float fVar4;
  float fVar5;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  vec_t local_74;
  undefined4 local_70;
  float local_6c;
  vec_t local_68;
  undefined4 local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  pmtrace_t local_50;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t.conflict wishvel@[???]
                       Unresolved local var: float wishspeed@[???]
                       Unresolved local var: vec3_t.conflict wishdir@[???]
                       Unresolved local var: vec3_t.conflict start@[???]
                       Unresolved local var: vec3_t.conflict dest@[???]
                       Unresolved local var: vec3_t.conflict temp@[???]
                       Unresolved local var: pmtrace_t trace@[???]
                       Unresolved local var: float speed@[???]
                       Unresolved local var: float newspeed@[???]
                       Unresolved local var: float addspeed@[???]
                       Unresolved local var: float accelspeed@[???] */
  fVar4 = (pmove->cmd).forwardmove;
  fVar5 = (pmove->cmd).sidemove;
  local_8c = pmove->forward[0] * fVar4 + pmove->right[0] * fVar5;
  local_88 = pmove->right[1] * fVar5 + pmove->forward[1] * fVar4;
  fVar1 = pmove->right[2] * fVar5 + pmove->forward[2] * fVar4;
  if (fVar4 == 0.0) {
    local_84 = (pmove->cmd).upmove;
    if ((fVar5 == 0.0) && (local_84 == 0.0)) {
      local_84 = fVar1 - 60.0;
      goto LAB_0013fe52;
    }
  }
  else {
    local_84 = (pmove->cmd).upmove;
  }
  local_84 = local_84 + fVar1;
LAB_0013fe52:
  local_80 = local_8c;
  local_7c = local_88;
  local_78 = local_84;
  fVar4 = VectorNormalize(&local_80);
  if (pmove->maxspeed < fVar4) {
    VectorScale(&local_8c,pmove->maxspeed / fVar4,&local_8c);
    fVar4 = pmove->maxspeed;
  }
  ppVar3 = pmove;
  fVar4 = fVar4 * 0.8;
  local_5c = pmove->velocity[0] + pmove->basevelocity[0];
  pmove->velocity[0] = local_5c;
  local_58 = ppVar3->velocity[1] + ppVar3->basevelocity[1];
  ppVar3->velocity[1] = local_58;
  local_54 = ppVar3->velocity[2] + ppVar3->basevelocity[2];
  ppVar3->velocity[2] = local_54;
  fVar5 = VectorNormalize(&local_5c);
  if (fVar5 == 0.0) {
    fVar2 = 0.0;
  }
  else {
    fVar1 = fVar5 - pmove->frametime * fVar5 * pmove->movevars->friction * pmove->friction;
    fVar2 = 0.0;
    if (0.0 <= fVar1) {
      fVar2 = fVar1;
    }
    VectorScale(pmove->velocity,fVar2 / fVar5,pmove->velocity);
  }
  if (0.1 <= fVar4) {
    fVar2 = fVar4 - fVar2;
    if (fVar2 <= 0.0) {
      fVar5 = pmove->frametime;
      ppVar3 = pmove;
    }
    else {
      VectorNormalize(&local_8c);
      ppVar3 = pmove;
      fVar5 = pmove->frametime;
      fVar4 = fVar4 * pmove->movevars->accelerate * fVar5 * pmove->friction;
      if (fVar2 < fVar4) {
        fVar4 = fVar2;
      }
      pmove->velocity[0] = local_8c * fVar4 + pmove->velocity[0];
      ppVar3->velocity[1] = local_88 * fVar4 + ppVar3->velocity[1];
      ppVar3->velocity[2] = fVar4 * local_84 + ppVar3->velocity[2];
    }
    VectorMA(ppVar3->origin,fVar5,ppVar3->velocity,&local_68);
    local_74 = local_68;
    local_70 = local_64;
    local_6c = pmove->movevars->stepsize + 1.0 + local_60;
    (*pmove->PM_PlayerTrace)(&local_50,&local_74,&local_68,0,-1);
    ppVar3 = pmove;
    if ((local_50.allsolid != false) || (local_54 != 0.0)) {
      PM_FlyMove();
      return;
    }
    pmove->origin[0] = local_50.fraction;
    ppVar3->origin[1] = local_50.endpos[0];
    ppVar3->origin[2] = local_50.endpos[1];
  }
  return;
}


// PM_AirMove  @ 00140110  (line 1418)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_AirMove(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  playermove_t *ppVar5;
  vec_t *v;
  float fVar6;
  float local_24;
  float local_20;
  undefined4 local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t.conflict wishvel@[???]
                       Unresolved local var: float fmove@[???]
                       Unresolved local var: float smove@[???]
                       Unresolved local var: vec3_t.conflict wishdir@[???]
                       Unresolved local var: float wishspeed@[???] */
  ppVar5 = pmove;
  fVar6 = (pmove->cmd).forwardmove;
  v = pmove->forward;
  pmove->forward[2] = 0.0;
  fVar1 = (ppVar5->cmd).sidemove;
  ppVar5->right[2] = 0.0;
  VectorNormalize(v);
  VectorNormalize(pmove->right);
  local_1c = 0;
  local_10 = 0.0;
  local_24 = pmove->right[0] * fVar1 + pmove->forward[0] * fVar6;
  local_20 = fVar1 * pmove->right[1] + fVar6 * pmove->forward[1];
  local_18 = local_24;
  local_14 = local_20;
  fVar6 = VectorNormalize(&local_18);
  if (pmove->maxspeed < fVar6) {
    VectorScale(&local_24,pmove->maxspeed / fVar6,&local_24);
    fVar6 = pmove->maxspeed;
  }
  ppVar5 = pmove;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float addspeed@[???]
                       Unresolved local var: float accelspeed@[???]
                       Unresolved local var: float currentspeed@[???]
                       Unresolved local var: float wishspd@[???] */
  if ((pmove->dead == false) && (pmove->waterjumptime == 0.0)) {
    fVar4 = 30.0;
    if (fVar6 <= 30.0) {
      fVar4 = fVar6;
    }
    fVar1 = pmove->velocity[0];
    fVar2 = pmove->velocity[1];
    fVar3 = pmove->velocity[2];
    fVar4 = fVar4 - (local_10 * fVar3 + fVar2 * local_14 + fVar1 * local_18);
    if (0.0 < fVar4) {
      fVar6 = fVar6 * pmove->movevars->airaccelerate * pmove->frametime * pmove->friction;
      if (fVar4 < fVar6) {
        fVar6 = fVar4;
      }
      fVar1 = local_18 * fVar6 + fVar1;
      pmove->velocity[0] = fVar1;
      fVar2 = local_14 * fVar6 + fVar2;
      ppVar5->velocity[1] = fVar2;
      fVar3 = fVar6 * local_10 + fVar3;
      ppVar5->velocity[2] = fVar3;
    }
  }
  else {
    fVar1 = pmove->velocity[0];
    fVar2 = pmove->velocity[1];
    fVar3 = pmove->velocity[2];
  }
  ppVar5->velocity[0] = fVar1 + ppVar5->basevelocity[0];
  ppVar5->velocity[1] = fVar2 + ppVar5->basevelocity[1];
  ppVar5->velocity[2] = fVar3 + ppVar5->basevelocity[2];
  PM_FlyMove();
  return;
}


// PM_InWater  @ 001402f0  (line 1465)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean PM_InWater(void)

{
  return (uint)(1 < pmove->waterlevel);
}


// PM_CheckWater  @ 00140310  (line 1476)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean PM_CheckWater(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  playermove_t *ppVar4;
  int local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: vec3_t.conflict point@[???]
                       Unresolved local var: int cont@[???]
                       Unresolved local var: int truecont@[???]
                       Unresolved local var: float height@[???]
                       Unresolved local var: float heightover2@[???] */
  ppVar4 = pmove;
  iVar3 = pmove->usehull;
  local_18 = (*(float *)("_ZN12CRevertSaved12MessageThinkEv" +
                         (int)(pmove->visents[0].name + iVar3 * 0xc + 0x11) +
                        (int)&__DT_REL[0].r_offset) +
             *(float *)("_ZN11CBasePlayer11PlayerTouchEP11CBaseEntity" +
                        (int)(pmove->visents[0].name + iVar3 * 0xc + 1) + (int)&__DT_REL[0].r_offset
                       )) * 0.5 + pmove->origin[0];
  local_14 = (*(float *)("_ZN12CRevertSaved12MessageThinkEv" +
                         (int)(pmove->visents[0].name + iVar3 * 0xc + 0x15) +
                        (int)&__DT_REL[0].r_offset) +
             *(float *)("_ZN11CBasePlayer11PlayerTouchEP11CBaseEntity" +
                        (int)(pmove->visents[0].name + iVar3 * 0xc + 5) + (int)&__DT_REL[0].r_offset
                       )) * 0.5 + pmove->origin[1];
  fVar1 = pmove->origin[2];
  fVar2 = *(float *)("_ZN12CRevertSaved12MessageThinkEv" +
                     (int)(pmove->visents[0].name + iVar3 * 0xc + 0x19) + (int)&__DT_REL[0].r_offset
                    );
  pmove->waterlevel = 0;
  ppVar4->watertype = -1;
  local_10 = fVar1 + fVar2 + 1.0;
  iVar3 = (*ppVar4->PM_PointContents)(&local_18,&local_1c);
  ppVar4 = pmove;
  if (iVar3 + 0xeU < 0xc) {
    pmove->watertype = iVar3;
    ppVar4->waterlevel = 1;
    local_10 = (ppVar4->player_mins[ppVar4->usehull][2] + ppVar4->player_maxs[ppVar4->usehull][2]) *
               0.5 + ppVar4->origin[2];
    iVar3 = (*ppVar4->PM_PointContents)(&local_18,(int *)0x0);
    ppVar4 = pmove;
    if (iVar3 + 0xeU < 0xc) {
      local_10 = pmove->origin[2] + pmove->view_ofs[2];
      pmove->waterlevel = 2;
      iVar3 = (*ppVar4->PM_PointContents)(&local_18,(int *)0x0);
      ppVar4 = pmove;
      if (iVar3 + 0xeU < 0xc) {
        pmove->waterlevel = 3;
        iVar3 = 3;
      }
      else {
        iVar3 = pmove->waterlevel;
      }
    }
    else {
      iVar3 = pmove->waterlevel;
    }
    if (5 < local_1c + 0xeU) goto LAB_001403a5;
    VectorMA(ppVar4->basevelocity,(float)iVar3 * 50.0,
             PM_CheckWater::lexical_block_0::current_table[-9 - local_1c],ppVar4->basevelocity);
  }
  iVar3 = pmove->waterlevel;
LAB_001403a5:
  return (uint)(1 < iVar3);
}


// PM_CatagorizePosition  @ 001404c0  (line 1547)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_CatagorizePosition(void)

{
  float fVar1;
  int *piVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  playermove_t *ppVar7;
  vec_t vVar8;
  vec_t vVar9;
  vec_t vVar10;
  vec_t local_b0;
  vec_t local_ac;
  float local_a8;
  pmtrace_t local_a4;
  qboolean local_60;
  vec_t local_50;
  vec_t local_4c;
  vec_t local_48;
  float local_3c;
  float local_34;
  vec_t local_30;
  vec_t local_2c;
  vec_t local_28;
  
                    /* Unresolved local var: vec3_t.conflict point@[???]
                       Unresolved local var: pmtrace_t tr@[???] */
  PM_CheckWater();
  local_b0 = pmove->origin[0];
  local_a8 = pmove->origin[2] - 2.0;
  local_ac = pmove->origin[1];
  if (pmove->velocity[2] <= 180.0) {
    (*pmove->PM_PlayerTrace)(&local_a4,pmove->origin,&local_b0,0,-1);
    fVar3 = local_a8;
    ppVar7 = pmove;
    if (local_a4.plane.normal[1] < 0.7) {
      pmove->onground = -1;
    }
    else {
      pmove->onground = (int)local_a4.plane.dist;
      if (local_a4.plane.dist == -NAN) {
        return;
      }
      ppVar7->waterjumptime = 0.0;
      if (((ppVar7->waterlevel < 2) && (local_a4.allsolid == false)) && (local_a8 == 0.0)) {
        ppVar7->origin[0] = local_a4.fraction;
        ppVar7->origin[1] = local_a4.endpos[0];
        ppVar7->origin[2] = local_a4.endpos[1];
      }
    }
    uVar4 = 0;
    if (0 < (int)local_a4.plane.dist) {
      do {
        *(undefined4 *)((int)local_a4.deltavelocity + uVar4 + 0xc) =
             *(undefined4 *)((int)local_a4.endpos + (uVar4 - 0x18));
        uVar4 = uVar4 + 4;
      } while (uVar4 < 0x44);
                    /* Unresolved local var: int i@[???] */
      iVar6 = ppVar7->numtouch;
      if (iVar6 < 1) {
        if (iVar6 == 0) {
          vVar10 = ppVar7->velocity[0];
          vVar9 = ppVar7->velocity[1];
          vVar8 = ppVar7->velocity[2];
LAB_0014067c:
          ppVar7->numtouch = iVar6 + 1;
          local_50 = local_a4.fraction;
          local_4c = local_a4.endpos[0];
          uVar4 = 0;
          local_48 = local_a4.endpos[1];
          local_3c = local_a4.plane.normal[1];
          local_30 = vVar10;
          local_2c = vVar9;
          local_28 = vVar8;
          local_a4.hitgroup = (int)fVar3;
          local_60 = local_a4.allsolid;
          local_34 = local_a4.plane.dist;
          do {
            *(undefined4 *)((int)ppVar7->touchindex[iVar6].endpos + (uVar4 - 0x14)) =
                 *(undefined4 *)((int)local_a4.deltavelocity + uVar4 + 0xc);
            uVar4 = uVar4 + 4;
          } while (uVar4 < 0x44);
        }
      }
      else {
        iVar5 = 0;
        fVar1 = (float)ppVar7->touchindex[0].ent;
        piVar2 = &ppVar7->touchindex[1].ent;
        while (fVar1 != local_a4.plane.dist) {
          iVar5 = iVar5 + 1;
          if (iVar5 == iVar6) {
            vVar10 = ppVar7->velocity[0];
            vVar9 = ppVar7->velocity[1];
            vVar8 = ppVar7->velocity[2];
            if (599 < iVar6) {
              (*ppVar7->Con_DPrintf)("Too many entities were touched!\n");
              iVar6 = pmove->numtouch;
              ppVar7 = pmove;
            }
            goto LAB_0014067c;
          }
          fVar1 = (float)*piVar2;
          piVar2 = piVar2 + 0x11;
        }
      }
    }
  }
  else {
    pmove->onground = -1;
  }
  return;
}


// PM_GetRandomStuckOffsets  @ 001407c0  (line 1608)

int PM_GetRandomStuckOffsets(int nIndex,int server,vec_t *offset)

{
  int iVar1;
  
                    /* Unresolved local var: int idx@[???] */
  iVar1 = rgStuckLast[nIndex][server];
  rgStuckLast[nIndex][server] = iVar1 + 1;
  iVar1 = iVar1 % 0x36;
  *offset = rgv3tStuckTable[iVar1][0];
  offset[1] = rgv3tStuckTable[iVar1][1];
  offset[2] = rgv3tStuckTable[iVar1][2];
  return iVar1;
}


// PM_ResetStuckOffsets  @ 00140830  (line 1620)

void PM_ResetStuckOffsets(int nIndex,int server)

{
  rgStuckLast[nIndex][server] = 0;
  return;
}


// PM_CheckStuck  @ 00140850  (line 1635)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int PM_CheckStuck(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  qboolean qVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  playermove_t *ppVar10;
  longdouble extraout_ST0;
  float local_78;
  float local_74;
  float local_6c;
  float local_68;
  float local_64;
  pmtrace_t local_60;
  
                    /* Unresolved local var: vec3_t.conflict base@[???]
                       Unresolved local var: vec3_t.conflict offset@[???]
                       Unresolved local var: vec3_t.conflict test@[???]
                       Unresolved local var: int hitent@[???]
                       Unresolved local var: int idx@[???]
                       Unresolved local var: float fTime@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: pmtrace_t traceresult@[???] */
  iVar5 = (*pmove->PM_TestPlayerPosition)(pmove->origin,&local_60);
  ppVar10 = pmove;
  if (iVar5 == -1) {
    rgStuckLast[pmove->player_index][pmove->server] = 0;
    return 0;
  }
  fVar1 = pmove->origin[0];
  qVar6 = pmove->server;
  fVar2 = pmove->origin[1];
  fVar3 = pmove->origin[2];
  if (((qVar6 == false) || (pmove->multiplayer == false)) &&
     ((iVar5 == 0 || (pmove->physents[iVar5].model != (model_s *)0x0)))) {
                    /* Unresolved local var: int nReps@[???] */
    iVar7 = pmove->player_index;
    rgStuckLast[iVar7][qVar6] = 0;
    iVar8 = 0x36;
    iVar9 = 0;
    while( true ) {
                    /* Unresolved local var: int idx@[???] */
      rgStuckLast[iVar7][qVar6] = iVar9 + 1;
      iVar9 = iVar9 % 0x36;
      local_6c = fVar1 + rgv3tStuckTable[iVar9][0];
      local_68 = rgv3tStuckTable[iVar9][1] + fVar2;
      local_64 = rgv3tStuckTable[iVar9][2] + fVar3;
      iVar7 = (*ppVar10->PM_TestPlayerPosition)(&local_6c,&local_60);
      ppVar10 = pmove;
      if (iVar7 == -1) {
        iVar5 = pmove->player_index;
        qVar6 = pmove->server;
        pmove->origin[0] = local_6c;
        ppVar10->origin[1] = local_68;
        ppVar10->origin[2] = local_64;
        rgStuckLast[iVar5][qVar6] = 0;
        return 0;
      }
      iVar8 = iVar8 + -1;
      qVar6 = pmove->server;
      if (iVar8 == 0) break;
      iVar7 = pmove->player_index;
      iVar9 = rgStuckLast[iVar7][qVar6];
    }
  }
  (*pmove->Sys_FloatTime)();
  ppVar10 = pmove;
  if (PM_CheckStuck::rgStuckCheckTime[pmove->player_index][qVar6 == false] <
      (float)extraout_ST0 - 0.05) {
    PM_CheckStuck::rgStuckCheckTime[pmove->player_index][qVar6 == false] = (float)extraout_ST0;
    (*ppVar10->PM_StuckTouch)(iVar5,&local_60);
    ppVar10 = pmove;
                    /* Unresolved local var: int idx@[???] */
    iVar5 = rgStuckLast[pmove->player_index][pmove->server];
    rgStuckLast[pmove->player_index][pmove->server] = iVar5 + 1;
    iVar5 = iVar5 % 0x36;
    local_6c = fVar1 + rgv3tStuckTable[iVar5][0];
    local_68 = rgv3tStuckTable[iVar5][1] + fVar2;
    local_64 = rgv3tStuckTable[iVar5][2] + fVar3;
    iVar7 = (*ppVar10->PM_TestPlayerPosition)(&local_6c,(pmtrace_t *)0x0);
    ppVar10 = pmove;
    if (iVar7 == -1) {
      rgStuckLast[pmove->player_index][pmove->server] = 0;
      if (iVar5 < 0x1b) {
        return 0;
      }
      ppVar10->origin[0] = local_6c;
      ppVar10->origin[1] = local_68;
      ppVar10->origin[2] = local_64;
      return 0;
    }
    if ((((pmove->cmd).buttons & 7) != 0) && (pmove->physents[iVar7].player != 0)) {
      iVar5 = 5;
      local_74 = 0.0;
      do {
        iVar7 = 3;
        local_78 = -8.0;
        do {
          iVar9 = 3;
          fVar4 = -8.0;
          do {
            local_68 = fVar2 + fVar4;
            local_6c = fVar1 + local_78;
            local_64 = fVar3 + local_74;
            iVar8 = (*pmove->PM_TestPlayerPosition)(&local_6c,(pmtrace_t *)0x0);
            ppVar10 = pmove;
            if (iVar8 == -1) {
              pmove->origin[0] = local_6c;
              ppVar10->origin[1] = local_68;
              ppVar10->origin[2] = local_64;
              return 0;
            }
                    /* Unresolved local var: float x@[???]
                       Unresolved local var: float y@[???]
                       Unresolved local var: float z@[???]
                       Unresolved local var: float xystep@[???]
                       Unresolved local var: float zstep@[???]
                       Unresolved local var: float xyminmax@[???]
                       Unresolved local var: float zminmax@[???] */
            iVar9 = iVar9 + -1;
            fVar4 = fVar4 + 8.0;
          } while (iVar9 != 0);
          iVar7 = iVar7 + -1;
          local_78 = local_78 + 8.0;
        } while (iVar7 != 0);
        iVar5 = iVar5 + -1;
        local_74 = local_74 + 18.0;
      } while (iVar5 != 0);
    }
  }
  return 1;
}


// PM_SpectatorMove  @ 00140c60  (line 1758)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_SpectatorMove(void)

{
  vec_t *veca;
  int iVar1;
  vec_t vVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  vec_t vVar7;
  vec_t vVar8;
  vec_t vVar9;
  int iVar10;
  playermove_t *ppVar11;
  vec_t *vecb;
  int *piVar12;
  movevars_s *pmVar13;
  float fVar14;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
  vVar8 = vec3_origin[1];
  vVar7 = vec3_origin[0];
                    /* Unresolved local var: float speed@[???]
                       Unresolved local var: float drop@[???]
                       Unresolved local var: float friction@[???]
                       Unresolved local var: float control@[???]
                       Unresolved local var: float newspeed@[???]
                       Unresolved local var: float currentspeed@[???]
                       Unresolved local var: float addspeed@[???]
                       Unresolved local var: float accelspeed@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t.conflict wishvel@[???]
                       Unresolved local var: float fmove@[???]
                       Unresolved local var: float smove@[???]
                       Unresolved local var: vec3_t.conflict wishdir@[???]
                       Unresolved local var: float wishspeed@[???] */
  ppVar11 = pmove;
  if (pmove->iuser1 == 3) {
    fVar14 = Length(pmove->velocity);
    vVar8 = vec3_origin[2];
    vVar7 = vec3_origin[1];
    ppVar11 = pmove;
    if (fVar14 < 1.0) {
      pmove->velocity[0] = vec3_origin[0];
      ppVar11->velocity[1] = vVar7;
      ppVar11->velocity[2] = vVar8;
    }
    else {
      fVar3 = pmove->movevars->stopspeed;
      if (fVar3 <= fVar14) {
        fVar3 = fVar14;
      }
      fVar3 = fVar14 - (fVar3 * pmove->movevars->friction * 1.5 * pmove->frametime + 0.0);
      fVar4 = 0.0;
      if (0.0 <= fVar3) {
        fVar4 = fVar3;
      }
      VectorScale(pmove->velocity,fVar4 / fVar14,pmove->velocity);
      ppVar11 = pmove;
    }
    fVar14 = (ppVar11->cmd).forwardmove;
    fVar3 = (ppVar11->cmd).sidemove;
    VectorNormalize(ppVar11->forward);
    VectorNormalize(pmove->right);
    local_24 = pmove->forward[0] * fVar14 + pmove->right[0] * fVar3;
    local_20 = pmove->forward[1] * fVar14 + pmove->right[1] * fVar3;
    local_1c = fVar3 * pmove->right[2] + fVar14 * pmove->forward[2] + (pmove->cmd).upmove;
    local_18 = local_24;
    local_14 = local_20;
    local_10 = local_1c;
    fVar14 = VectorNormalize(&local_18);
    pmVar13 = pmove->movevars;
    if (pmVar13->spectatormaxspeed < fVar14) {
      VectorScale(&local_24,pmVar13->spectatormaxspeed / fVar14,&local_24);
      pmVar13 = pmove->movevars;
      fVar14 = pmVar13->spectatormaxspeed;
    }
    ppVar11 = pmove;
    fVar3 = fVar14 - (pmove->velocity[2] * local_10 +
                     pmove->velocity[0] * local_18 + pmove->velocity[1] * local_14);
    if (fVar3 <= 0.0) {
      return;
    }
    fVar4 = pmove->frametime;
    veca = pmove->origin;
    fVar14 = pmVar13->accelerate * fVar4 * fVar14;
    if (fVar3 < fVar14) {
      fVar14 = fVar3;
    }
    vecb = pmove->velocity;
    *vecb = pmove->velocity[0] + local_18 * fVar14;
    ppVar11->velocity[1] = local_14 * fVar14 + ppVar11->velocity[1];
    ppVar11->velocity[2] = local_10 * fVar14 + ppVar11->velocity[2];
    VectorMA(veca,fVar4,vecb,veca);
    return;
  }
                    /* Unresolved local var: int target@[???] */
  iVar5 = pmove->iuser2;
  if (iVar5 < 1) {
    return;
  }
  iVar6 = pmove->numphysent;
  if (iVar6 < 1) {
    if (iVar6 == 0) {
      return;
    }
  }
  else {
    iVar10 = 0;
    piVar12 = &pmove->physents[1].info;
    if (iVar5 != pmove->physents[0].info) {
      do {
        iVar10 = iVar10 + 1;
        if (iVar10 == iVar6) {
          return;
        }
        iVar1 = *piVar12;
        piVar12 = piVar12 + 0x38;
      } while (iVar5 != iVar1);
      goto LAB_00140ccb;
    }
  }
  iVar10 = 0;
LAB_00140ccb:
  pmove->angles[0] = pmove->physents[iVar10].angles[0];
  vVar9 = vec3_origin[2];
  ppVar11->angles[1] = ppVar11->physents[iVar10].angles[1];
  ppVar11->angles[2] = ppVar11->physents[iVar10].angles[2];
  ppVar11->origin[0] = ppVar11->physents[iVar10].origin[0];
  ppVar11->origin[1] = ppVar11->physents[iVar10].origin[1];
  vVar2 = ppVar11->physents[iVar10].origin[2];
  ppVar11->velocity[0] = vVar7;
  ppVar11->velocity[1] = vVar8;
  ppVar11->origin[2] = vVar2;
  ppVar11->velocity[2] = vVar9;
  return;
}


// PM_SplineFraction  @ 00140f40  (line 1891)

float PM_SplineFraction(float value,float scale)

{
  float fVar1;
  float fVar2;
  
                    /* Unresolved local var: float valueSquared@[???] */
  fVar1 = scale * value;
  fVar2 = fVar1 * fVar1;
  return fVar2 * 3.0 - (fVar2 + fVar2) * fVar1;
}


// PM_FixPlayerCrouchStuck  @ 00140f60  (line 1899)

void PM_FixPlayerCrouchStuck(int direction)

{
  vec_t vVar1;
  vec_t vVar2;
  float fVar3;
  float fVar4;
  playermove_t *ppVar5;
  int iVar6;
  int iVar7;
  
                    /* Unresolved local var: int hitent@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t.conflict test@[???] */
  iVar6 = (*pmove->PM_TestPlayerPosition)(pmove->origin,(pmtrace_t *)0x0);
  if (iVar6 != -1) {
    iVar6 = 0x24;
    vVar1 = pmove->origin[0];
    vVar2 = pmove->origin[1];
    fVar3 = pmove->origin[2];
    fVar4 = fVar3;
    while( true ) {
      ppVar5 = pmove;
      pmove->origin[2] = fVar4 + (float)direction;
      iVar7 = (*ppVar5->PM_TestPlayerPosition)(ppVar5->origin,(pmtrace_t *)0x0);
      ppVar5 = pmove;
      if (iVar7 == -1) break;
      iVar6 = iVar6 + -1;
      if (iVar6 == 0) {
        pmove->origin[0] = vVar1;
        ppVar5->origin[1] = vVar2;
        ppVar5->origin[2] = fVar3;
        return;
      }
      fVar4 = pmove->origin[2];
    }
  }
  return;
}


// PM_UnDuck  @ 00141010  (line 1921)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_UnDuck(void)

{
  playermove_t *ppVar1;
  vec_t local_64;
  vec_t local_60;
  float local_5c;
  float local_58;
  float local_54;
  pmtrace_t local_50;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: pmtrace_t trace@[???]
                       Unresolved local var: vec3_t.conflict newOrigin@[???] */
  local_5c = pmove->origin[0];
  local_58 = pmove->origin[1];
  local_54 = pmove->origin[2];
  if (pmove->onground != -1) {
    local_5c = (pmove->player_mins[1][0] - pmove->player_mins[0][0]) + local_5c;
    local_58 = (pmove->player_mins[1][1] - pmove->player_mins[0][1]) + local_58;
    local_54 = (pmove->player_mins[1][2] - pmove->player_mins[0][2]) + local_54;
  }
  (*pmove->PM_PlayerTrace)(&local_50,&local_5c,&local_5c,0,-1);
  ppVar1 = pmove;
  if (local_50.allsolid == false) {
    pmove->usehull = 0;
    (*ppVar1->PM_PlayerTrace)(&local_50,&local_5c,&local_5c,0,-1);
    ppVar1 = pmove;
    if (local_54 == 0.0) {
      pmove->flags = pmove->flags & 0xffffbfff;
      ppVar1->origin[0] = local_64;
      ppVar1->origin[1] = local_60;
      ppVar1->origin[2] = local_5c;
      ppVar1->bInDuck = false;
      ppVar1->view_ofs[2] = 28.0;
      ppVar1->flDuckTime = 0.0;
      PM_CatagorizePosition();
      return;
    }
    pmove->usehull = 1;
    return;
  }
  return;
}


// PM_Duck  @ 00141170  (line 1965)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_Duck(void)

{
  vec_t *pvVar1;
  vec_t vVar2;
  vec_t vVar3;
  float fVar4;
  float fVar5;
  ushort uVar6;
  uint uVar7;
  playermove_t *ppVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  qboolean qVar12;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float time@[???]
                       Unresolved local var: float duckFraction@[???]
                       Unresolved local var: int buttonsChanged@[???]
                       Unresolved local var: int nButtonPressed@[???]
                       Unresolved local var: int duckchange@[???]
                       Unresolved local var: int duckpressed@[???] */
  ppVar8 = pmove;
  uVar6 = (pmove->cmd).buttons;
  uVar7 = pmove->oldbuttons;
  uVar11 = uVar7 & 0xfffffffb;
  if ((uVar6 & 4) != 0) {
    uVar11 = uVar7 | 4;
  }
  pmove->oldbuttons = uVar11;
  if ((ppVar8->iuser3 != 0) || (ppVar8->dead != false)) {
    if ((ppVar8->flags & 0x4000) == 0) {
      return;
    }
LAB_001412aa:
    PM_UnDuck();
    return;
  }
  uVar11 = ppVar8->flags;
  if ((uVar11 & 0x4000) == 0) {
    if ((uVar6 & 4) == 0) {
      if (ppVar8->bInDuck == false) {
        return;
      }
      goto LAB_001412aa;
    }
    if (((uVar7 ^ uVar6) & uVar6 & 4) != 0) {
      ppVar8->flDuckTime = 1000.0;
      fVar4 = 0.0;
      ppVar8->bInDuck = true;
      goto LAB_00141224;
    }
  }
  else {
    (ppVar8->cmd).forwardmove = (ppVar8->cmd).forwardmove * 0.333;
    (ppVar8->cmd).sidemove = (ppVar8->cmd).sidemove * 0.333;
    (ppVar8->cmd).upmove = (ppVar8->cmd).upmove * 0.333;
    if ((uVar6 & 4) == 0) goto LAB_001412aa;
  }
  fVar5 = ppVar8->flDuckTime / 1000.0;
  fVar4 = 1.0 - fVar5;
  if (fVar4 < 0.0) {
    qVar12 = ppVar8->bInDuck;
    fVar4 = 0.0;
  }
  else {
    qVar12 = ppVar8->bInDuck;
  }
  if (qVar12 == false) {
    return;
  }
  if (fVar5 <= 0.6) {
    ppVar8->flags = uVar11 | 0x4000;
    iVar9 = ppVar8->onground;
    ppVar8->usehull = 1;
    ppVar8->view_ofs[2] = 12.0;
    ppVar8->bInDuck = false;
    if (iVar9 == -1) {
      return;
    }
                    /* Unresolved local var: int hitent@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t.conflict test@[???] */
    ppVar8->origin[0] = ppVar8->origin[0] - (ppVar8->player_mins[1][0] - ppVar8->player_mins[0][0]);
    ppVar8->origin[1] = ppVar8->origin[1] - (ppVar8->player_mins[1][1] - ppVar8->player_mins[0][1]);
    ppVar8->origin[2] = ppVar8->origin[2] - (ppVar8->player_mins[1][2] - ppVar8->player_mins[0][2]);
    iVar9 = (*ppVar8->PM_TestPlayerPosition)(ppVar8->origin,(pmtrace_t *)0x0);
    if (iVar9 != -1) {
      iVar9 = 0x24;
      vVar2 = pmove->origin[0];
      vVar3 = pmove->origin[1];
      fVar4 = pmove->origin[2];
      fVar5 = fVar4;
      while( true ) {
        ppVar8 = pmove;
        pvVar1 = pmove->origin;
        pmove->origin[2] = fVar5 + 1.0;
        iVar10 = (*ppVar8->PM_TestPlayerPosition)(pvVar1,(pmtrace_t *)0x0);
        ppVar8 = pmove;
        if (iVar10 == -1) break;
        iVar9 = iVar9 + -1;
        if (iVar9 == 0) {
          pmove->origin[0] = vVar2;
          ppVar8->origin[1] = vVar3;
          ppVar8->origin[2] = fVar4;
          break;
        }
        fVar5 = pmove->origin[2];
      }
    }
    PM_CatagorizePosition();
    return;
  }
LAB_00141224:
  if (ppVar8->onground == -1) {
    ppVar8->flags = uVar11 | 0x4000;
    ppVar8->usehull = 1;
    ppVar8->view_ofs[2] = 12.0;
    ppVar8->bInDuck = false;
  }
  else {
                    /* Unresolved local var: float fMore@[???]
                       Unresolved local var: float valueSquared@[???] */
    fVar4 = fVar4 * 2.5;
    fVar5 = fVar4 * fVar4;
    fVar4 = fVar5 * 3.0 - (fVar5 + fVar5) * fVar4;
    ppVar8->view_ofs[2] = fVar4 * -6.0 + (1.0 - fVar4) * 28.0;
  }
  return;
}


// PM_LadderMove  @ 00141490  (line 2060)

void PM_LadderMove(physent_t *pLadder)

{
  int *piVar1;
  plane_t *v2;
  ushort uVar2;
  float fVar3;
  float scale;
  float scale_00;
  playermove_t *ppVar4;
  int iVar5;
  vec_t *out;
  float local_d8;
  float local_d4;
  float local_d0;
  vec_t local_cc;
  vec_t local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  vec_t local_a8 [3];
  vec_t local_9c [3];
  float local_90;
  float local_8c;
  float local_88;
  vec_t local_84 [3];
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  vec_t local_60 [3];
  trace_t local_54;
  
                    /* Unresolved local var: vec3_t.conflict ladderCenter@[???]
                       Unresolved local var: trace_t trace@[???]
                       Unresolved local var: qboolean onFloor@[???]
                       Unresolved local var: vec3_t.conflict floor@[???]
                       Unresolved local var: vec3_t.conflict modelmins@[???]
                       Unresolved local var: vec3_t.conflict modelmaxs@[???] */
  if ((pmove->movetype != 8) && (1.0 < pmove->maxspeed)) {
    (*pmove->PM_GetModelBounds)(pLadder->model,&local_c0,&local_b4);
    local_d8 = local_c0 + local_b4;
    local_d4 = local_bc + local_b0;
    local_d0 = local_b8 + local_ac;
    VectorScale(&local_d8,0.5,&local_d8);
    ppVar4 = pmove;
    piVar1 = &pmove->usehull;
    pmove->movetype = 5;
    local_cc = ppVar4->origin[0];
    local_c8 = ppVar4->origin[1];
    local_c4 = (ppVar4->player_mins[*piVar1][2] - 1.0) + ppVar4->origin[2];
    iVar5 = (*ppVar4->PM_PointContents)(&local_cc,(int *)0x0);
    ppVar4 = pmove;
    pmove->gravity = 0.0;
    (*ppVar4->PM_TraceModel)(pLadder,ppVar4->origin,&local_d8,&local_54);
    if (local_54.fraction != 1.0) {
                    /* Unresolved local var: float forward@[???]
                       Unresolved local var: float right@[???]
                       Unresolved local var: vec3_t.conflict vpn@[???]
                       Unresolved local var: vec3_t.conflict v_right@[???]
                       Unresolved local var: float flSpeed@[???] */
      fVar3 = 200.0;
      if (pmove->maxspeed < 200.0) {
        fVar3 = pmove->maxspeed;
      }
      AngleVectors(pmove->angles,local_a8,local_9c,(vec_t *)0x0);
      ppVar4 = pmove;
      if ((pmove->flags & 0x4000) != 0) {
        fVar3 = fVar3 * 0.333;
      }
      uVar2 = (pmove->cmd).buttons;
      scale = 0.0;
      if ((uVar2 & 0x10) != 0) {
        scale = 0.0 - fVar3;
      }
      if ((uVar2 & 8) != 0) {
        scale = scale + fVar3;
      }
      scale_00 = 0.0;
      if ((uVar2 & 0x200) != 0) {
        scale_00 = 0.0 - fVar3;
      }
      if ((uVar2 & 0x400) != 0) {
        scale_00 = scale_00 + fVar3;
      }
      if ((uVar2 & 2) == 0) {
        if ((scale == 0.0) && (scale_00 == 0.0)) {
          pmove->velocity[0] = 0.0;
          ppVar4->velocity[1] = 0.0;
          ppVar4->velocity[2] = 0.0;
        }
        else {
                    /* Unresolved local var: vec3_t.conflict velocity@[???]
                       Unresolved local var: vec3_t.conflict perp@[???]
                       Unresolved local var: vec3_t.conflict cross@[???]
                       Unresolved local var: vec3_t.conflict lateral@[???]
                       Unresolved local var: vec3_t.conflict tmp@[???]
                       Unresolved local var: float normal@[???] */
          VectorScale(local_a8,scale,&local_90);
          v2 = &local_54.plane;
          VectorMA(&local_90,scale_00,local_9c,&local_90);
          local_60[0] = 0.0;
          local_60[1] = 0.0;
          local_60[2] = 1.0;
          CrossProduct(local_60,v2->normal,local_84);
          VectorNormalize(local_84);
          fVar3 = local_88 * local_54.plane.normal[2] +
                  local_8c * local_54.plane.normal[1] + local_90 * local_54.plane.normal[0];
          VectorScale(v2->normal,fVar3,&local_78);
          local_6c = local_90 - local_78;
          local_68 = local_8c - local_74;
          local_64 = local_88 - local_70;
          CrossProduct(v2->normal,local_84,local_60);
          VectorMA(&local_6c,-fVar3,local_60,pmove->velocity);
          if ((iVar5 == -2) && (0.0 < fVar3)) {
            VectorMA(pmove->velocity,200.0,v2->normal,pmove->velocity);
          }
        }
      }
      else {
        out = pmove->velocity;
        pmove->movetype = 3;
        VectorScale(local_54.plane.normal,270.0,out);
      }
    }
  }
  return;
}


// PM_Ladder  @ 00141880  (line 2191)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

physent_t * PM_Ladder(void)

{
  model_s *pmVar1;
  int iVar2;
  hull_s *phVar3;
  int iVar4;
  playermove_t *ppVar5;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: physent_t * pe@[???]
                       Unresolved local var: hull_t * hull@[???]
                       Unresolved local var: int num@[???]
                       Unresolved local var: vec3_t.conflict test@[???] */
  iVar4 = 0;
  iVar2 = pmove->nummoveent;
  ppVar5 = pmove;
  if (0 < iVar2) {
    do {
      pmVar1 = *(model_s **)((int)&__DT_REL[iVar4 * 0x1c + 0x14da].r_info + (int)ppVar5->physents);
      if (pmVar1 != (model_s *)0x0) {
        iVar2 = (*ppVar5->PM_GetModelType)(pmVar1);
        if ((iVar2 == 0) &&
           (*(int *)((int)&__DT_REL[iVar4 * 0x1c + 0x14e1].r_offset + (int)ppVar5->physents) ==
            -0x10)) {
          phVar3 = (*pmove->PM_HullForBsp)(ppVar5->moveents + iVar4,&local_28);
          local_28 = pmove->origin[0] - local_28;
          local_24 = pmove->origin[1] - local_24;
          local_20 = pmove->origin[2] - local_20;
          iVar2 = (*pmove->PM_HullPointContents)(phVar3,phVar3->firstclipnode,&local_28);
          if (iVar2 != -1) {
            return ppVar5->moveents + iVar4;
          }
        }
        iVar2 = pmove->nummoveent;
        ppVar5 = pmove;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  return (physent_t *)0x0;
}


// PM_WaterJump  @ 00141970  (line 2225)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_WaterJump(void)

{
  vec_t vVar1;
  float fVar2;
  playermove_t *ppVar3;
  
  ppVar3 = pmove;
  fVar2 = pmove->waterjumptime;
  if (10000.0 < fVar2) {
    fVar2 = 10000.0;
  }
  else if (fVar2 == 0.0) {
    return;
  }
  fVar2 = fVar2 - (float)(pmove->cmd).msec;
  pmove->waterjumptime = fVar2;
  if ((fVar2 < 0.0) || (ppVar3->waterlevel == 0)) {
    ppVar3->flags = ppVar3->flags & 0xfffff7ff;
    ppVar3->waterjumptime = 0.0;
  }
  vVar1 = ppVar3->movedir[1];
  ppVar3->velocity[0] = ppVar3->movedir[0];
  ppVar3->velocity[1] = vVar1;
  return;
}


// PM_AddGravity  @ 00141a00  (line 2256)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_AddGravity(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  vec_t *pvVar6;
  playermove_t *ppVar7;
  
                    /* Unresolved local var: float ent_gravity@[???] */
  ppVar7 = pmove;
  fVar5 = 1.0;
  if (pmove->gravity != 0.0) {
    fVar5 = pmove->gravity;
  }
  fVar1 = pmove->movevars->gravity;
  fVar2 = pmove->frametime;
  pvVar6 = pmove->velocity;
  fVar3 = pmove->frametime;
  fVar4 = pmove->basevelocity[2];
  pmove->basevelocity[2] = 0.0;
  ppVar7->velocity[2] = fVar3 * fVar4 + (pvVar6[2] - fVar5 * fVar1 * fVar2);
  PM_CheckVelocity();
  return;
}


// PM_PushEntity  @ 00141a40  (line 2275)

pmtrace_t * PM_PushEntity(pmtrace_t *__return_storage_ptr__,vec_t *push)

{
  vec_t vVar1;
  vec_t vVar2;
  vec_t vVar3;
  float fVar4;
  qboolean qVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  playermove_t *ppVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  vec_t vVar13;
  vec_t vVar14;
  vec_t vVar15;
  float local_78;
  float local_74;
  float local_70 [5];
  vec_t vStack_5c;
  vec_t vStack_58;
  vec_t vStack_54;
  int local_40;
  vec_t local_3c;
  vec_t local_38;
  vec_t local_34;
  
                    /* Unresolved local var: pmtrace_t trace@[???]
                       Unresolved local var: vec3_t.conflict end@[???] */
  local_78 = pmove->origin[0] + *push;
  local_74 = pmove->origin[1] + push[1];
  local_70[0] = pmove->origin[2] + push[2];
  (*pmove->PM_PlayerTrace)(__return_storage_ptr__,pmove->origin,&local_78,0,-1);
  ppVar9 = pmove;
  vVar1 = __return_storage_ptr__->endpos[0];
  vVar2 = __return_storage_ptr__->endpos[1];
  vVar3 = __return_storage_ptr__->endpos[2];
  qVar5 = __return_storage_ptr__->allsolid;
  fVar4 = __return_storage_ptr__->fraction;
  pmove->origin[0] = vVar1;
  ppVar9->origin[1] = vVar2;
  ppVar9->origin[2] = vVar3;
  if ((fVar4 < 1.0) && (qVar5 == false)) {
    __return_storage_ptr__->allsolid = false;
    uVar10 = 0;
    do {
      *(undefined4 *)((int)local_70 + uVar10) =
           *(undefined4 *)((int)__return_storage_ptr__->endpos + (uVar10 - 0x14));
      uVar10 = uVar10 + 4;
    } while (uVar10 < 0x44);
                    /* Unresolved local var: int i@[???] */
    iVar12 = ppVar9->numtouch;
    iVar6 = __return_storage_ptr__->ent;
    if (iVar12 < 1) {
      if (iVar12 == 0) {
        vVar15 = ppVar9->velocity[0];
        vVar14 = ppVar9->velocity[1];
        vVar13 = ppVar9->velocity[2];
LAB_00141b9c:
        ppVar9->numtouch = iVar12 + 1;
        local_70[0] = 0.0;
        local_70[4] = fVar4;
        vStack_5c = vVar1;
        vStack_58 = vVar2;
        vStack_54 = vVar3;
        local_3c = vVar15;
        local_38 = vVar14;
        uVar10 = 0;
        local_34 = vVar13;
        local_40 = iVar6;
        do {
          *(undefined4 *)((int)ppVar9->touchindex[iVar12].endpos + (uVar10 - 0x14)) =
               *(undefined4 *)((int)local_70 + uVar10);
          uVar10 = uVar10 + 4;
        } while (uVar10 < 0x44);
      }
    }
    else {
      iVar11 = 0;
      iVar7 = ppVar9->touchindex[0].ent;
      piVar8 = &ppVar9->touchindex[1].ent;
      while (iVar7 != iVar6) {
        iVar11 = iVar11 + 1;
        if (iVar11 == iVar12) {
          vVar15 = ppVar9->velocity[0];
          vVar14 = ppVar9->velocity[1];
          vVar13 = ppVar9->velocity[2];
          if (599 < iVar12) {
            (*ppVar9->Con_DPrintf)("Too many entities were touched!\n");
            iVar12 = pmove->numtouch;
            ppVar9 = pmove;
          }
          goto LAB_00141b9c;
        }
        iVar7 = *piVar8;
        piVar8 = piVar8 + 0x11;
      }
    }
  }
  __return_storage_ptr__->allsolid = qVar5;
  return __return_storage_ptr__;
}


// PM_Physics_Toss  @ 00141ca0  (line 2303)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_Physics_Toss(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  vec_t *pvVar6;
  playermove_t *ppVar7;
  vec_t vVar8;
  vec_t vVar9;
  int iVar10;
  vec_t local_5c [3];
  pmtrace_t local_50;
  
                    /* Unresolved local var: pmtrace_t trace@[???]
                       Unresolved local var: vec3_t.conflict move@[???]
                       Unresolved local var: float backoff@[???] */
  PM_CheckWater();
  if (pmove->velocity[2] <= 0.0) {
    if (((pmove->onground != -1) &&
        (iVar10 = VectorCompare(pmove->basevelocity,vec3_origin), iVar10 != 0)) &&
       (iVar10 = VectorCompare(pmove->velocity,vec3_origin), iVar10 != 0)) {
      return;
    }
  }
  else {
    pmove->onground = -1;
  }
  PM_CheckVelocity();
  ppVar7 = pmove;
  if (((pmove->movetype & 0xfffffffdU) != 9) && (pmove->movetype != 5)) {
                    /* Unresolved local var: float ent_gravity@[???] */
    fVar5 = 1.0;
    if (pmove->gravity != 0.0) {
      fVar5 = pmove->gravity;
    }
    fVar1 = pmove->movevars->gravity;
    fVar2 = pmove->frametime;
    pvVar6 = pmove->velocity;
    fVar3 = pmove->frametime;
    fVar4 = pmove->basevelocity[2];
    pmove->basevelocity[2] = 0.0;
    ppVar7->velocity[2] = fVar3 * fVar4 + (pvVar6[2] - fVar5 * fVar1 * fVar2);
    PM_CheckVelocity();
  }
  ppVar7 = pmove;
  pmove->velocity[0] = pmove->velocity[0] + pmove->basevelocity[0];
  ppVar7->velocity[1] = ppVar7->velocity[1] + ppVar7->basevelocity[1];
  ppVar7->velocity[2] = ppVar7->velocity[2] + ppVar7->basevelocity[2];
  PM_CheckVelocity();
  VectorScale(pmove->velocity,pmove->frametime,local_5c);
  ppVar7 = pmove;
  pmove->velocity[0] = pmove->velocity[0] - pmove->basevelocity[0];
  ppVar7->velocity[1] = ppVar7->velocity[1] - ppVar7->basevelocity[1];
  ppVar7->velocity[2] = ppVar7->velocity[2] - ppVar7->basevelocity[2];
  PM_PushEntity(&local_50,local_5c);
  PM_CheckVelocity();
  vVar9 = vec3_origin[2];
  vVar8 = vec3_origin[1];
  ppVar7 = pmove;
  if (local_50.allsolid != false) {
    pmove->velocity[0] = vec3_origin[0];
    ppVar7->velocity[1] = vVar8;
    ppVar7->velocity[2] = vVar9;
    ppVar7->onground = local_50.ent;
    return;
  }
  if (local_50.fraction != 1.0) {
    if (pmove->movetype == 10) {
      fVar5 = 2.0 - pmove->friction;
    }
    else {
      fVar5 = 2.0;
      if (pmove->movetype != 0xb) {
        fVar5 = 1.0;
      }
    }
                    /* Unresolved local var: float backoff@[???]
                       Unresolved local var: float change@[???]
                       Unresolved local var: float angle@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int blocked@[???] */
    fVar5 = (pmove->velocity[2] * local_50.plane.normal[2] +
            pmove->velocity[1] * local_50.plane.normal[1] +
            local_50.plane.normal[0] * pmove->velocity[0]) * fVar5;
    fVar1 = pmove->velocity[0] - local_50.plane.normal[0] * fVar5;
    pmove->velocity[0] = fVar1;
    if ((-0.1 < fVar1) && (fVar1 < 0.1)) {
      ppVar7->velocity[0] = 0.0;
    }
    fVar1 = ppVar7->velocity[1] - local_50.plane.normal[1] * fVar5;
    ppVar7->velocity[1] = fVar1;
    if ((-0.1 < fVar1) && (fVar1 < 0.1)) {
      ppVar7->velocity[1] = 0.0;
    }
    fVar5 = ppVar7->velocity[2] - fVar5 * local_50.plane.normal[2];
    ppVar7->velocity[2] = fVar5;
    if ((-0.1 < fVar5) && (fVar5 < 0.1)) {
      ppVar7->velocity[2] = 0.0;
    }
    if (0.7 < local_50.plane.normal[2]) {
                    /* Unresolved local var: float vel@[???]
                       Unresolved local var: vec3_t.conflict base@[???] */
      fVar5 = ppVar7->velocity[2];
      fVar1 = ppVar7->frametime;
      if (fVar5 < ppVar7->movevars->gravity * fVar1) {
        fVar5 = 0.0;
        ppVar7->velocity[2] = 0.0;
        ppVar7->onground = local_50.ent;
      }
      else {
        fVar5 = fVar5 * fVar5;
      }
      vVar9 = vec3_origin[2];
      vVar8 = vec3_origin[1];
      if ((ppVar7->velocity[1] * ppVar7->velocity[1] + ppVar7->velocity[0] * ppVar7->velocity[0] +
           fVar5 < 900.0) || (1 < ppVar7->movetype - 10U)) {
        ppVar7->velocity[0] = vec3_origin[0];
        ppVar7->velocity[1] = vVar8;
        ppVar7->velocity[2] = vVar9;
        ppVar7->onground = local_50.ent;
      }
      else {
        VectorScale(ppVar7->velocity,fVar1 * (1.0 - local_50.fraction) * 0.9,local_5c);
        PM_PushEntity(&local_50,local_5c);
      }
    }
  }
  PM_CheckWater();
  return;
}


// PM_NoClip  @ 00142060  (line 2408)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_NoClip(void)

{
  float fVar1;
  float fVar2;
  playermove_t *ppVar3;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t.conflict wishvel@[???]
                       Unresolved local var: float fmove@[???]
                       Unresolved local var: float smove@[???] */
  fVar1 = (pmove->cmd).forwardmove;
  fVar2 = (pmove->cmd).sidemove;
  VectorNormalize(pmove->forward);
  VectorNormalize(pmove->right);
  local_18 = pmove->forward[0] * fVar1 + pmove->right[0] * fVar2;
  local_14 = pmove->right[1] * fVar2 + pmove->forward[1] * fVar1;
  local_10 = fVar2 * pmove->right[2] + fVar1 * pmove->forward[2] + (pmove->cmd).upmove;
  VectorMA(pmove->origin,pmove->frametime,&local_18,pmove->origin);
  ppVar3 = pmove;
  pmove->velocity[0] = 0.0;
  ppVar3->velocity[1] = 0.0;
  ppVar3->velocity[2] = 0.0;
  return;
}


// PM_PreventMegaBunnyJumping  @ 00142120  (line 2445)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_PreventMegaBunnyJumping(void)

{
  float fVar1;
  float fVar2;
  
                    /* Unresolved local var: float spd@[???]
                       Unresolved local var: float fraction@[???]
                       Unresolved local var: float maxscaledspeed@[???] */
  fVar1 = pmove->maxspeed * 1.7;
  if ((0.0 < fVar1) && (fVar2 = Length(pmove->velocity), fVar1 < fVar2)) {
    VectorScale(pmove->velocity,(fVar1 / fVar2) * 0.65,pmove->velocity);
    return;
  }
  return;
}


// PM_Jump  @ 00142190  (line 2481)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_Jump(void)

{
  vec_t *pvVar1;
  vec_t vVar2;
  byte bVar3;
  char *pcVar4;
  long lVar5;
  int32 iVar6;
  playermove_t *ppVar7;
  int step;
  float fVar8;
  float fVar9;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: qboolean tfc@[???]
                       Unresolved local var: qboolean cansuperjump@[???] */
  if (pmove->dead != false) {
    pmove->oldbuttons = pmove->oldbuttons | 2;
    return;
  }
  pcVar4 = (*pmove->PM_Info_ValueForKey)(pmove->physinfo,"tfc");
  lVar5 = strtol(pcVar4,(char **)0x0,10);
  ppVar7 = pmove;
  if ((lVar5 != 1) || (pmove->deadflag != 5)) {
    if (pmove->waterjumptime != 0.0) {
      fVar9 = pmove->waterjumptime - (float)(pmove->cmd).msec;
      fVar8 = 0.0;
      if (0.0 <= fVar9) {
        fVar8 = fVar9;
      }
      pmove->waterjumptime = fVar8;
      return;
    }
    if (pmove->waterlevel < 2) {
      if (pmove->onground != -1) {
        if ((pmove->oldbuttons & 2U) != 0) {
          return;
        }
                    /* Unresolved local var: float spd@[???]
                       Unresolved local var: float fraction@[???]
                       Unresolved local var: float maxscaledspeed@[???] */
        fVar9 = pmove->maxspeed * 1.7;
        pmove->onground = -1;
        if ((0.0 < fVar9) && (fVar8 = Length(ppVar7->velocity), ppVar7 = pmove, fVar9 < fVar8)) {
          VectorScale(pmove->velocity,(fVar9 / fVar8) * 0.65,pmove->velocity);
          ppVar7 = pmove;
        }
        if (lVar5 == 1) {
          (*ppVar7->PM_PlaySound)(4,"player/plyrjmp8.wav",0.5,0.8,0,100);
        }
        else {
          bVar3 = ppVar7->chtexturetype + 0xbc;
          step = 0;
          if (bVar3 < 0x13) {
            step = *(int *)(CSWTCH_100 + (uint)bVar3 * 4);
          }
          PM_PlayStepSound(step,1.0);
        }
        pcVar4 = (*pmove->PM_Info_ValueForKey)(pmove->physinfo,"slj");
        lVar5 = strtol(pcVar4,(char **)0x0,10);
        if ((((pmove->bInDuck == false) && ((pmove->flags & 0x4000) == 0)) || (lVar5 != 1)) ||
           (((((pmove->cmd).buttons & 4) == 0 || (pmove->flDuckTime <= 0.0)) ||
            (fVar9 = Length(pmove->velocity), ppVar7 = pmove, fVar9 <= 50.0)))) {
          ppVar7 = pmove;
          pmove->velocity[2] = 268.32816;
          fVar9 = 268.32816;
        }
        else {
          pvVar1 = pmove->forward;
          pmove->punchangle[0] = -5.0;
          ppVar7->velocity[0] = *pvVar1 * 350.0 * 1.6;
          ppVar7->velocity[1] = ppVar7->forward[1] * 350.0 * 1.6;
          fVar9 = 299.33258;
          ppVar7->velocity[2] = 299.33258;
        }
                    /* Unresolved local var: float ent_gravity@[???] */
        if (ppVar7->waterjumptime == 0.0) {
          fVar8 = 1.0;
          if (ppVar7->gravity != 0.0) {
            fVar8 = ppVar7->gravity;
          }
          ppVar7->velocity[2] = fVar9 - fVar8 * ppVar7->movevars->gravity * ppVar7->frametime * 0.5;
          PM_CheckVelocity();
          ppVar7 = pmove;
        }
      }
      ppVar7->oldbuttons = ppVar7->oldbuttons | 2;
    }
    else {
      pmove->onground = -1;
      if (ppVar7->watertype == -3) {
        ppVar7->velocity[2] = 100.0;
      }
      else {
        vVar2 = 50.0;
        if (ppVar7->watertype == -4) {
          vVar2 = 80.0;
        }
        ppVar7->velocity[2] = vVar2;
      }
      if (ppVar7->flSwimTime <= 0.0) {
        ppVar7->flSwimTime = 1000.0;
        iVar6 = (*ppVar7->RandomLong)(0,3);
        if (iVar6 == 1) {
          (*pmove->PM_PlaySound)(4,"player/pl_wade2.wav",1.0,0.8,0,100);
        }
        else if (iVar6 < 2) {
          if (iVar6 == 0) {
            (*pmove->PM_PlaySound)(4,"player/pl_wade1.wav",1.0,0.8,0,100);
          }
        }
        else if (iVar6 == 2) {
          (*pmove->PM_PlaySound)(4,"player/pl_wade3.wav",1.0,0.8,0,100);
        }
        else if (iVar6 == 3) {
          (*pmove->PM_PlaySound)(4,"player/pl_wade4.wav",1.0,0.8,0,100);
        }
      }
    }
  }
  return;
}


// PM_CheckWaterJump  @ 00142640  (line 2627)

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_CheckWaterJump(void)

{
  int iVar1;
  uint uVar2;
  playermove_t *ppVar3;
  float afStack_f4 [2];
  undefined1 local_ec [92];
  vec_t local_90;
  vec_t local_8c;
  float local_88;
  vec_t local_84 [3];
  float local_78;
  float local_74;
  float local_70;
  vec_t local_6c;
  vec_t local_68;
  float local_64 [8];
  vec_t local_44 [2];
  float local_3c;
  
                    /* Unresolved local var: vec3_t.conflict vecStart@[???]
                       Unresolved local var: vec3_t.conflict vecEnd@[???]
                       Unresolved local var: vec3_t.conflict flatforward@[???]
                       Unresolved local var: vec3_t.conflict flatvelocity@[???]
                       Unresolved local var: float curspeed@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: int savehull@[???] */
  if ((pmove->waterjumptime == 0.0) && (-180.0 <= pmove->velocity[2])) {
    local_6c = pmove->velocity[0];
    local_68 = pmove->velocity[1];
    local_64[0] = 0.0;
    afStack_f4[1] = VectorNormalize(&local_6c);
    local_70 = 0.0;
    local_78 = pmove->forward[0];
    local_74 = pmove->forward[1];
    VectorNormalize(&local_78);
    if ((afStack_f4[1] == 0.0) ||
       (0.0 <= local_64[0] * local_70 + local_68 * local_74 + local_6c * local_78)) {
      local_88 = pmove->origin[2] + 8.0;
      local_90 = pmove->origin[0];
      local_8c = pmove->origin[1];
      VectorMA(&local_90,24.0,&local_78,local_84);
      ppVar3 = pmove;
      iVar1 = pmove->usehull;
      pmove->usehull = 2;
      (*ppVar3->PM_PlayerTrace)((pmtrace_t *)local_ec,&local_90,local_84,0,-1);
      uVar2 = 0;
      do {
        *(undefined4 *)((int)local_64 + uVar2) = *(undefined4 *)((int)afStack_f4 + uVar2 + 4);
        uVar2 = uVar2 + 4;
      } while (uVar2 < 0x44);
      ppVar3 = pmove;
      if ((local_64[4] < 1.0) && (ABS(local_3c) < 0.1)) {
        local_8c = (*(float *)("_ZN11CBasePlayer11PlayerTouchEP11CBaseEntity" +
                               (int)(pmove->visents[0].name + iVar1 * 0xc + 9) +
                              (int)&__DT_REL[0].r_offset) - 8.0) + local_8c;
        VectorMA(&local_90,24.0,&local_78,local_84);
        VectorMA(vec3_origin,-50.0,local_44,pmove->movedir);
        (*pmove->PM_PlayerTrace)((pmtrace_t *)(afStack_f4 + 1),&local_90,local_84,0,-1);
        ppVar3 = pmove;
        uVar2 = 0;
        do {
          *(undefined4 *)((int)local_64 + (uVar2 - 4)) = *(undefined4 *)((int)afStack_f4 + uVar2);
          uVar2 = uVar2 + 4;
        } while (uVar2 < 0x44);
        if (local_64[3] == 1.0) {
          pmove->waterjumptime = 2000.0;
          ppVar3->velocity[2] = 225.0;
          ppVar3->oldbuttons = ppVar3->oldbuttons | 2;
          ppVar3->flags = ppVar3->flags | 0x800;
        }
      }
      ppVar3->usehull = iVar1;
    }
    return;
  }
  return;
}


// PM_CheckFalling  @ 00142950  (line 2682)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_CheckFalling(void)

{
  float fVar1;
  int *piVar2;
  byte bVar3;
  playermove_t *ppVar4;
  char *__nptr;
  long lVar5;
  int step;
  float fvol;
  
  if (pmove->onground == -1) {
    return;
  }
  ppVar4 = pmove;
  if ((pmove->dead == false) && (fVar1 = pmove->flFallVelocity, 350.0 <= fVar1)) {
    fvol = 0.5;
    if (pmove->waterlevel < 1) {
      if (580.0 < fVar1) {
        (*pmove->PM_PlaySound)(2,"player/pl_fallpain3.wav",1.0,0.8,0,100);
        fvol = 1.0;
      }
      else if (290.0 < fVar1) {
                    /* Unresolved local var: qboolean tfc@[???] */
        __nptr = (*pmove->PM_Info_ValueForKey)(pmove->physinfo,"tfc");
        lVar5 = strtol(__nptr,(char **)0x0,10);
        if (lVar5 == 1) {
          (*pmove->PM_PlaySound)(2,"player/pl_fallpain3.wav",1.0,0.8,0,100);
        }
        fvol = 0.85;
      }
      else if (fVar1 < 200.0) goto LAB_00142972;
    }
    ppVar4 = pmove;
    piVar2 = &pmove->flags;
                    /* Unresolved local var: int fWalking@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: vec3_t.conflict knee@[???]
                       Unresolved local var: vec3_t.conflict feet@[???]
                       Unresolved local var: vec3_t.conflict center@[???]
                       Unresolved local var: float height@[???]
                       Unresolved local var: float speed@[???]
                       Unresolved local var: float velrun@[???]
                       Unresolved local var: float velwalk@[???]
                       Unresolved local var: float flduck@[???]
                       Unresolved local var: int fLadder@[???]
                       Unresolved local var: int step@[???] */
    pmove->flTimeStepSound = 0;
    if ((*piVar2 & 0x1000) == 0) {
      PM_UpdateStepSound();
      ppVar4 = pmove;
    }
    step = 0;
    bVar3 = ppVar4->chtexturetype + 0xbc;
    if (bVar3 < 0x13) {
      step = *(int *)(CSWTCH_100 + (uint)bVar3 * 4);
    }
    PM_PlayStepSound(step,fvol);
    ppVar4 = pmove;
    pmove->punchangle[2] = pmove->flFallVelocity * 0.013;
    if (8.0 < ppVar4->punchangle[0]) {
      ppVar4->punchangle[0] = 8.0;
    }
    if (ppVar4->onground == -1) {
      return;
    }
  }
LAB_00142972:
  ppVar4->flFallVelocity = 0.0;
  return;
}


// PM_PlayWaterSounds  @ 00142b60  (line 2757)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_PlayWaterSounds(void)

{
  int32 iVar1;
  
  if (pmove->oldwaterlevel == 0) {
    if (pmove->waterlevel == 0) {
      return;
    }
  }
  else if (pmove->waterlevel != 0) {
    return;
  }
  iVar1 = (*pmove->RandomLong)(0,3);
  if (iVar1 != 1) {
    if (iVar1 < 2) {
      if (iVar1 == 0) {
        (*pmove->PM_PlaySound)(4,"player/pl_wade1.wav",1.0,0.8,0,100);
        return;
      }
    }
    else {
      if (iVar1 == 2) {
        (*pmove->PM_PlaySound)(4,"player/pl_wade3.wav",1.0,0.8,0,100);
        return;
      }
      if (iVar1 == 3) {
        (*pmove->PM_PlaySound)(4,"player/pl_wade4.wav",1.0,0.8,0,100);
      }
    }
    return;
  }
  (*pmove->PM_PlaySound)(4,"player/pl_wade2.wav",1.0,0.8,0,100);
  return;
}


// PM_CalcRoll  @ 00142cd0  (line 2787)

float PM_CalcRoll(vec_t *angles,vec_t *velocity,float rollangle,float rollspeed)

{
  float fVar1;
  float fVar2;
  vec_t local_30 [3];
  float local_24;
  float local_20;
  float local_1c;
  vec_t local_18 [5];
  
                    /* Unresolved local var: float sign@[???]
                       Unresolved local var: float side@[???]
                       Unresolved local var: float value@[???]
                       Unresolved local var: vec3_t.conflict forward@[???]
                       Unresolved local var: vec3_t.conflict right@[???]
                       Unresolved local var: vec3_t.conflict up@[???] */
  AngleVectors(angles,local_30,&local_24,local_18);
  fVar1 = velocity[2] * local_1c + velocity[1] * local_20 + *velocity * local_24;
  fVar2 = -1.0;
  if (0.0 <= fVar1) {
    fVar2 = 1.0;
  }
  fVar1 = ABS(fVar1);
  if (fVar1 < rollspeed) {
    rollangle = (fVar1 * rollangle) / rollspeed;
  }
  return fVar2 * rollangle;
}


// PM_DropPunchAngle  @ 00142d50  (line 2822)

void PM_DropPunchAngle(vec_t *punchangle)

{
  float fVar1;
  
                    /* Unresolved local var: float len@[???] */
  fVar1 = VectorNormalize(punchangle);
  fVar1 = fVar1 - (fVar1 * 0.5 + 10.0) * pmove->frametime;
  if (fVar1 <= 0.0) {
    fVar1 = 0.0;
  }
  VectorScale(punchangle,fVar1,punchangle);
  return;
}


// PM_CheckParamters  @ 00142da0  (line 2838)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_CheckParamters(void)

{
  vec_t *v;
  vec_t vVar1;
  vec_t vVar2;
  float fVar3;
  uint uVar4;
  qboolean qVar5;
  float fVar6;
  playermove_t *ppVar7;
  float fVar8;
  float fVar9;
  float local_3c;
  float local_38;
  float local_34;
  vec_t local_30 [3];
  float local_24;
  float local_20;
  float local_1c;
  vec_t local_18 [5];
  
                    /* Unresolved local var: float spd@[???]
                       Unresolved local var: float maxspeed@[???]
                       Unresolved local var: vec3_t.conflict v_angle@[???] */
  fVar8 = (pmove->cmd).forwardmove;
  fVar9 = (pmove->cmd).sidemove;
  fVar3 = (pmove->cmd).upmove;
  fVar8 = fVar3 * fVar3 + fVar9 * fVar9 + fVar8 * fVar8;
  fVar9 = SQRT(fVar8);
  if (NAN(fVar9)) {
    fVar9 = sqrtf(fVar8);
  }
  ppVar7 = pmove;
  fVar8 = pmove->clientmaxspeed;
  if (fVar8 != 0.0) {
    fVar3 = pmove->maxspeed;
    if (fVar8 < pmove->maxspeed) {
      fVar3 = fVar8;
    }
    pmove->maxspeed = fVar3;
  }
  if ((fVar9 == 0.0) || (fVar9 <= ppVar7->maxspeed)) {
    if ((ppVar7->flags & 0x1001000U) != 0) goto LAB_00142f30;
LAB_00142e24:
    if (ppVar7->dead != false) goto LAB_00142f30;
  }
  else {
                    /* Unresolved local var: float fRatio@[???] */
    fVar9 = ppVar7->maxspeed / fVar9;
    uVar4 = ppVar7->flags;
    (ppVar7->cmd).forwardmove = (ppVar7->cmd).forwardmove * fVar9;
    (ppVar7->cmd).sidemove = (ppVar7->cmd).sidemove * fVar9;
    (ppVar7->cmd).upmove = fVar9 * (ppVar7->cmd).upmove;
    if ((uVar4 & 0x1001000) == 0) goto LAB_00142e24;
LAB_00142f30:
    (ppVar7->cmd).forwardmove = 0.0;
    (ppVar7->cmd).sidemove = 0.0;
    (ppVar7->cmd).upmove = 0.0;
  }
  v = ppVar7->punchangle;
                    /* Unresolved local var: float len@[???] */
  fVar8 = VectorNormalize(v);
  fVar8 = fVar8 - (fVar8 * 0.5 + 10.0) * pmove->frametime;
  if (fVar8 <= 0.0) {
    fVar8 = 0.0;
  }
  VectorScale(v,fVar8,v);
  ppVar7 = pmove;
  if (pmove->dead == false) {
    local_3c = (pmove->cmd).viewangles[0] + pmove->punchangle[0];
    local_38 = pmove->punchangle[1] + (pmove->cmd).viewangles[1];
    local_34 = pmove->punchangle[2] + (pmove->cmd).viewangles[2];
    fVar8 = pmove->movevars->rollspeed;
    fVar9 = pmove->movevars->rollangle;
                    /* Unresolved local var: float sign@[???]
                       Unresolved local var: float side@[???]
                       Unresolved local var: float value@[???]
                       Unresolved local var: vec3_t.conflict forward@[???]
                       Unresolved local var: vec3_t.conflict right@[???]
                       Unresolved local var: vec3_t.conflict up@[???] */
    AngleVectors(&local_3c,local_30,&local_24,local_18);
    fVar3 = ppVar7->velocity[2] * local_1c +
            ppVar7->velocity[1] * local_20 + ppVar7->velocity[0] * local_24;
    fVar6 = -1.0;
    if (0.0 <= fVar3) {
      fVar6 = 1.0;
    }
    fVar3 = ABS(fVar3);
    if (fVar3 < fVar8) {
      fVar9 = (fVar9 * fVar3) / fVar8;
    }
    ppVar7->angles[2] = fVar9 * fVar6 * 4.0;
    ppVar7 = pmove;
    qVar5 = pmove->dead;
    pmove->angles[1] = local_38;
    ppVar7->angles[0] = local_3c;
    if (qVar5 == false) goto LAB_00142eb9;
  }
  else {
    vVar1 = pmove->oldangles[1];
    vVar2 = pmove->oldangles[2];
    pmove->angles[0] = pmove->oldangles[0];
    ppVar7->angles[1] = vVar1;
    ppVar7->angles[2] = vVar2;
  }
  ppVar7->view_ofs[2] = -8.0;
  local_38 = ppVar7->angles[1];
LAB_00142eb9:
  if (180.0 < local_38) {
    ppVar7->angles[1] = local_38 - 360.0;
  }
  return;
}


// PM_ReduceTimers  @ 00143080  (line 2917)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void PM_ReduceTimers(void)

{
  float fVar1;
  float fVar2;
  playermove_t *ppVar3;
  int iVar4;
  
  ppVar3 = pmove;
  if (0 < pmove->flTimeStepSound) {
    iVar4 = pmove->flTimeStepSound - (uint)(pmove->cmd).msec;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    pmove->flTimeStepSound = iVar4;
  }
  if (0.0 < ppVar3->flDuckTime) {
    fVar1 = ppVar3->flDuckTime - (float)(ppVar3->cmd).msec;
    fVar2 = 0.0;
    if (0.0 <= fVar1) {
      fVar2 = fVar1;
    }
    ppVar3->flDuckTime = fVar2;
  }
  if (0.0 < ppVar3->flSwimTime) {
    fVar1 = ppVar3->flSwimTime - (float)(ppVar3->cmd).msec;
    fVar2 = 0.0;
    if (0.0 <= fVar1) {
      fVar2 = fVar1;
    }
    ppVar3->flSwimTime = fVar2;
  }
  return;
}


// PM_PlayerMove  @ 00143120  (line 2955)

void PM_PlayerMove(qboolean server)

{
  int *piVar1;
  vec_t vVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  playermove_t *ppVar7;
  int iVar8;
  uint uVar9;
  physent_t *pLadder;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: physent_t * pLadder@[???] */
  pmove->server = server;
  PM_CheckParamters();
  ppVar7 = pmove;
  uVar9 = (uint)(pmove->cmd).msec;
  pmove->numtouch = 0;
  ppVar7->frametime = (float)uVar9 * 0.001;
  if (0 < ppVar7->flTimeStepSound) {
    iVar8 = ppVar7->flTimeStepSound - uVar9;
    if (iVar8 < 0) {
      iVar8 = 0;
    }
    ppVar7->flTimeStepSound = iVar8;
  }
  if (0.0 < ppVar7->flDuckTime) {
    fVar3 = ppVar7->flDuckTime - (float)uVar9;
    fVar4 = 0.0;
    if (0.0 <= fVar3) {
      fVar4 = fVar3;
    }
    ppVar7->flDuckTime = fVar4;
  }
  if (0.0 < ppVar7->flSwimTime) {
    fVar3 = ppVar7->flSwimTime - (float)uVar9;
    fVar4 = 0.0;
    if (0.0 <= fVar3) {
      fVar4 = fVar3;
    }
    ppVar7->flSwimTime = fVar4;
  }
  AngleVectors(ppVar7->angles,ppVar7->forward,ppVar7->right,ppVar7->up);
  if ((pmove->spectator != 0) || (0 < pmove->iuser1)) {
    PM_SpectatorMove();
    PM_CatagorizePosition();
    return;
  }
  if (((pmove->movetype & 0xfffffff7U) != 0) && (iVar8 = PM_CheckStuck(), iVar8 != 0)) {
    PM_Duck();
    iVar8 = PM_CheckStuck();
    if (iVar8 != 0) {
      return;
    }
  }
  PM_CatagorizePosition();
  ppVar7 = pmove;
  piVar1 = &pmove->onground;
  pmove->oldwaterlevel = pmove->waterlevel;
  if (*piVar1 == -1) {
    ppVar7->flFallVelocity = -ppVar7->velocity[2];
  }
  pLadder = (physent_t *)0x0;
  g_onladder = 0;
  if (((ppVar7->dead == false) && ((ppVar7->flags & 0x1000000) == 0)) &&
     (pLadder = PM_Ladder(), ppVar7 = pmove, pLadder != (physent_t *)0x0)) {
    g_onladder = 1;
  }
                    /* Unresolved local var: int fWalking@[???]
                       Unresolved local var: float fvol@[???]
                       Unresolved local var: vec3_t.conflict knee@[???]
                       Unresolved local var: vec3_t.conflict feet@[???]
                       Unresolved local var: vec3_t.conflict center@[???]
                       Unresolved local var: float height@[???]
                       Unresolved local var: float speed@[???]
                       Unresolved local var: float velrun@[???]
                       Unresolved local var: float velwalk@[???]
                       Unresolved local var: float flduck@[???]
                       Unresolved local var: int fLadder@[???]
                       Unresolved local var: int step@[???] */
  if ((ppVar7->flTimeStepSound < 1) && ((ppVar7->flags & 0x1000) == 0)) {
    PM_UpdateStepSound();
  }
  PM_Duck();
  ppVar7 = pmove;
  if ((pmove->dead != false) || ((pmove->flags & 0x1000000) != 0)) {
    iVar8 = pmove->movetype;
LAB_001432a8:
    ppVar7 = pmove;
    switch(iVar8) {
    case 0:
      return;
    default:
      (*pmove->Con_DPrintf)
                ("Bogus pmove player movetype %i on (%i) 0=cl 1=sv\n",iVar8,pmove->server);
      return;
    case 3:
      goto switchD_001432b1_caseD_3;
    case 5:
      PM_CheckWater();
      ppVar7 = pmove;
      if (((pmove->cmd).buttons & 2) == 0) {
        pmove->oldbuttons = pmove->oldbuttons & 0xfffffffd;
      }
      else if (pLadder == (physent_t *)0x0) {
        PM_Jump();
        ppVar7 = pmove;
      }
      ppVar7->velocity[0] = ppVar7->velocity[0] + ppVar7->basevelocity[0];
      ppVar7->velocity[1] = ppVar7->velocity[1] + ppVar7->basevelocity[1];
      ppVar7->velocity[2] = ppVar7->velocity[2] + ppVar7->basevelocity[2];
      PM_FlyMove();
      ppVar7 = pmove;
      pmove->velocity[0] = pmove->velocity[0] - pmove->basevelocity[0];
      ppVar7->velocity[1] = ppVar7->velocity[1] - ppVar7->basevelocity[1];
      ppVar7->velocity[2] = ppVar7->velocity[2] - ppVar7->basevelocity[2];
      return;
    case 6:
    case 10:
      PM_Physics_Toss();
      return;
    case 8:
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vec3_t.conflict wishvel@[???]
                       Unresolved local var: float fmove@[???]
                       Unresolved local var: float smove@[???] */
      fVar3 = (pmove->cmd).forwardmove;
      fVar4 = (pmove->cmd).sidemove;
      VectorNormalize(pmove->forward);
      VectorNormalize(pmove->right);
      local_18 = pmove->forward[0] * fVar3 + pmove->right[0] * fVar4;
      local_14 = pmove->forward[1] * fVar3 + pmove->right[1] * fVar4;
      local_10 = fVar4 * pmove->right[2] + fVar3 * pmove->forward[2] + (pmove->cmd).upmove;
      VectorMA(pmove->origin,pmove->frametime,&local_18,pmove->origin);
      ppVar7 = pmove;
      pmove->velocity[0] = 0.0;
      ppVar7->velocity[1] = 0.0;
      ppVar7->velocity[2] = 0.0;
      return;
    }
  }
  if (pLadder != (physent_t *)0x0) {
    PM_LadderMove(pLadder);
    iVar8 = pmove->movetype;
    goto LAB_001432a8;
  }
  iVar8 = pmove->movetype;
  if ((iVar8 == 3) || (iVar8 == 8)) goto LAB_001432a8;
  pmove->movetype = 3;
switchD_001432b1_caseD_3:
  iVar8 = ppVar7->waterlevel;
                    /* Unresolved local var: float ent_gravity@[???] */
  fVar3 = ppVar7->waterjumptime;
  if (iVar8 < 2) {
    if (fVar3 != 0.0) {
LAB_00143590:
      if (10000.0 < fVar3) {
        fVar3 = 10000.0;
      }
      fVar3 = fVar3 - (float)(ppVar7->cmd).msec;
      ppVar7->waterjumptime = fVar3;
      if ((fVar3 < 0.0) || (ppVar7->waterlevel == 0)) {
        ppVar7->flags = ppVar7->flags & 0xfffff7ff;
        ppVar7->waterjumptime = 0.0;
      }
      vVar2 = ppVar7->movedir[1];
      ppVar7->velocity[0] = ppVar7->movedir[0];
      ppVar7->velocity[1] = vVar2;
      PM_FlyMove();
      PM_CheckWater();
      return;
    }
    fVar3 = 1.0;
    if (ppVar7->gravity != 0.0) {
      fVar3 = ppVar7->gravity;
    }
    fVar4 = ppVar7->frametime;
    fVar5 = ppVar7->movevars->gravity;
    fVar6 = ppVar7->basevelocity[2];
    ppVar7->basevelocity[2] = 0.0;
    ppVar7->velocity[2] = fVar4 * fVar6 + (ppVar7->velocity[2] - fVar3 * fVar5 * 0.5 * fVar4);
    PM_CheckVelocity();
    ppVar7 = pmove;
    fVar3 = pmove->waterjumptime;
    if (fVar3 != 0.0) goto LAB_00143590;
    iVar8 = pmove->waterlevel;
    if (iVar8 < 2) {
      if (((pmove->cmd).buttons & 2) == 0) {
        pmove->oldbuttons = pmove->oldbuttons & 0xfffffffd;
      }
      else if (pLadder == (physent_t *)0x0) {
        PM_Jump();
        ppVar7 = pmove;
      }
      if (ppVar7->onground != -1) {
        ppVar7->velocity[2] = 0.0;
        PM_Friction();
      }
      PM_CheckVelocity();
      if (pmove->onground == -1) {
        PM_AirMove();
      }
      else {
        PM_WalkMove();
      }
      PM_CatagorizePosition();
      ppVar7 = pmove;
      pmove->velocity[0] = pmove->velocity[0] - pmove->basevelocity[0];
      ppVar7->velocity[1] = ppVar7->velocity[1] - ppVar7->basevelocity[1];
      ppVar7->velocity[2] = ppVar7->velocity[2] - ppVar7->basevelocity[2];
      PM_CheckVelocity();
      if (pmove->waterlevel < 2) {
        PM_FixupGravityVelocity();
      }
      if (pmove->onground != -1) {
        pmove->velocity[2] = 0.0;
      }
      PM_CheckFalling();
      goto LAB_0014353e;
    }
  }
  else if (fVar3 != 0.0) goto LAB_00143590;
  if (((iVar8 == 2) && (PM_CheckWaterJump(), ppVar7 = pmove, pmove->velocity[2] < 0.0)) &&
     (pmove->waterjumptime != 0.0)) {
    pmove->waterjumptime = 0.0;
  }
  if (((ppVar7->cmd).buttons & 2) == 0) {
    ppVar7->oldbuttons = ppVar7->oldbuttons & 0xfffffffd;
  }
  else {
    PM_Jump();
  }
  PM_WaterMove();
  ppVar7 = pmove;
  pmove->velocity[0] = pmove->velocity[0] - pmove->basevelocity[0];
  ppVar7->velocity[1] = ppVar7->velocity[1] - ppVar7->basevelocity[1];
  ppVar7->velocity[2] = ppVar7->velocity[2] - ppVar7->basevelocity[2];
  PM_CatagorizePosition();
LAB_0014353e:
  PM_PlayWaterSounds();
  return;
}


// PM_Move  @ 00143e10  (line 3327)

void PM_Move(playermove_s *ppmove,int server)

{
  playermove_t *ppVar1;
  uint uVar2;
  
  pmove = ppmove;
  PM_PlayerMove((uint)(server != 0));
  ppVar1 = pmove;
  if (pmove->onground == -1) {
    uVar2 = pmove->flags & 0xfffffdff;
  }
  else {
    uVar2 = pmove->flags | 0x200;
  }
  pmove->flags = uVar2;
  if ((ppVar1->multiplayer == false) && (ppVar1->movetype == 3)) {
    ppVar1->friction = 1.0;
    return;
  }
  return;
}


// PM_GetVisEntInfo  @ 00143e90  (line 3351)

int PM_GetVisEntInfo(int ent)

{
  if ((-1 < ent) && (ent <= pmove->numvisent)) {
    return pmove->visents[ent].info;
  }
  return -1;
}


// PM_GetPhysEntInfo  @ 00143ed0  (line 3360)

int PM_GetPhysEntInfo(int ent)

{
  if ((-1 < ent) && (ent <= pmove->numphysent)) {
    return pmove->physents[ent].info;
  }
  return -1;
}


// PM_Init  @ 00143f10  (line 3369)

void PM_Init(playermove_s *ppmove)

{
  pmove = ppmove;
  PM_CreateStuckTable();
  PM_InitTextureTypes();
  return;
}


