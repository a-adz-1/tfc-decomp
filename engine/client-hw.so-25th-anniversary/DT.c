// DT_ClearRenderState  @ 00189370
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DT_ClearRenderState(void)

{
  (*qglSelectTextureSGIS)(TEXTURE2_SGIS);
  (*qglDisable)(0xde1);
  (*qglSelectTextureSGIS)(TEXTURE1_SGIS);
  return;
}


// DT_GetDetailTextureName  @ 00189090
/* WARNING: Removing unreachable block (ram,0x001892d7) */
/* WARNING: Removing unreachable block (ram,0x001891d8) */
/* WARNING: Removing unreachable block (ram,0x001891f4) */
/* WARNING: Removing unreachable block (ram,0x0018922d) */
/* WARNING: Removing unreachable block (ram,0x0018923a) */
/* WARNING: Removing unreachable block (ram,0x001891e0) */
/* WARNING: Removing unreachable block (ram,0x001891e8) */
/* WARNING: Removing unreachable block (ram,0x001891ef) */
/* WARNING: Removing unreachable block (ram,0x001892ee) */

char * DT_GetDetailTextureName(char *diffuseName)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  string sVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  string local_28;
  char *local_24;
  int local_20 [4];
  
                    /* Unresolved local var: string detailName@[???]
                       Unresolved local var: size_type idx@[???]
                       Unresolved local var: size_type length@[???] */
  local_28._M_dataplus._M_p = (_Alloc_hider)&std::nothrow;
  iVar7 = (int)g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl.
               _M_finish -
          (int)g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl.
               _M_start >> 2;
  if (iVar7 != 0) {
    iVar8 = 0;
    do {
      std::string::string(&local_24,
                          &g_detailVector.
                           super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl.
                           _M_start[iVar8]->_diffuseName);
      pcVar6 = local_24;
      iVar5 = strcasecmp(diffuseName,local_24);
      paVar1 = (allocator *)(pcVar6 + -0xc);
      if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
        LOCK();
        piVar2 = (int *)(pcVar6 + -4);
        iVar3 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar3 < 1) {
          std::string::_Rep::_M_destroy(paVar1);
        }
      }
      if (iVar5 == 0) {
        std::string::string(local_20,&g_detailVector.
                                      super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>.
                                      _M_impl._M_start[iVar8]->_detailName);
        std::string::assign(&local_28);
        if ((allocator *)(local_20[0] + -0xc) !=
            (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
          LOCK();
          piVar2 = (int *)(local_20[0] + -4);
          iVar7 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar7 < 1) {
            std::string::_Rep::_M_destroy((allocator *)(local_20[0] + -0xc));
          }
        }
        break;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 != iVar7);
  }
  sVar4._M_dataplus._M_p = local_28._M_dataplus._M_p;
  if (*(int *)((int)local_28._M_dataplus._M_p + -0xc) == 0) {
    pcVar6 = (char *)0x0;
  }
  else {
    __strcpy_chk(DT_GetDetailTextureName::buffer,local_28._M_dataplus._M_p,0x80);
    pcVar6 = DT_GetDetailTextureName::buffer;
  }
  if (sVar4._M_dataplus._M_p != (_Alloc_hider)&std::nothrow) {
    LOCK();
    piVar2 = (int *)((int)sVar4._M_dataplus._M_p + -4);
    iVar7 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar7 < 1) {
      std::string::_Rep::_M_destroy((allocator *)((int)sVar4._M_dataplus._M_p + -0xc));
    }
  }
  return pcVar6;
}


// DT_GetToken  @ 00188df0
/* WARNING: Removing unreachable block (ram,0x00189056) */

bool DT_GetToken(char **cPtr,ParseState *parseState,string *token)

{
  byte *pbVar1;
  int *piVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  byte *unaff_ESI;
  byte *unaff_EDI;
  allocator local_22 [2];
  int local_20 [4];
  
                    /* Unresolved local var: char * sPtr@[???]
                       Unresolved local var: char * ePtr@[???]
                       Unresolved local var: LexerState state@[???] */
  iVar5 = 0;
LAB_00188e00:
  if (1 < iVar5 - 4U) {
    while (iVar5 != 1) {
      if (iVar5 == 0) {
        iVar5 = 1;
        unaff_ESI = (byte *)*cPtr;
        unaff_EDI = unaff_ESI;
        goto LAB_00188e00;
      }
      if (iVar5 == 2) {
        iVar5 = 3;
        if ((*unaff_ESI == 0x2f) && (unaff_ESI[1] == 0x2f)) {
          pbVar1 = unaff_ESI + 2;
          unaff_ESI = unaff_ESI + 2;
          if (((byte)(*pbVar1 + 1) < 0xf) && (((byte)(0x4801 >> (*pbVar1 + 1 & 0x1f)) & 1) == 1)) {
            iVar5 = 1;
          }
          else {
            do {
              do {
                unaff_ESI = unaff_ESI + 1;
              } while (0xe < (byte)(*unaff_ESI + 1));
            } while ((0x4801U >> (*unaff_ESI + 1 & 0x1f) & 1) == 0);
            iVar5 = 1;
          }
        }
        goto LAB_00188e00;
      }
      if (iVar5 == 3) goto LAB_00188e30;
    }
                    /* Unresolved local var: int idx@[???] */
    bVar4 = *unaff_ESI;
    if ((byte)(bVar4 - 9) < 0x18) {
      iVar5 = 2;
      unaff_EDI = unaff_ESI;
      if (((byte)(0x800013 >> (bVar4 - 9 & 0x1f)) & 1) != 1) goto LAB_00188e00;
      do {
        unaff_ESI = unaff_ESI + 1;
        bVar4 = *unaff_ESI;
        if (0x17 < (byte)(bVar4 - 9)) break;
      } while ((0x800013U >> (bVar4 - 9 & 0x1f) & 1) != 0);
    }
    unaff_EDI = unaff_ESI;
    if (bVar4 == 0xff) {
      iVar5 = 5;
      *parseState = PS_COMPLETE;
    }
    else {
      iVar5 = 2;
    }
    goto LAB_00188e00;
  }
LAB_00188eda:
  *cPtr = (char *)unaff_EDI;
  return 1 < *parseState - PS_ERROR;
LAB_00188e30:
  bVar4 = *unaff_EDI;
  if (0x1a < (byte)((bVar4 & 0xdf) + 0xbf)) {
                    /* Unresolved local var: int idx@[???] */
    bVar3 = 0;
    if ((byte)(bVar4 - 0x21) < 0x19) {
      bVar3 = (byte)(0x1fff401 >> (bVar4 - 0x21 & 0x1f)) & 1;
    }
    if (((bVar4 & 0xfd) != 0x5d && bVar4 != 0x7e) && (bVar3 == 0)) goto code_r0x00188e7a;
  }
  unaff_EDI = unaff_EDI + 1;
  goto LAB_00188e30;
code_r0x00188e7a:
  if (unaff_EDI == unaff_ESI) {
    *parseState = PS_ERROR;
  }
  else {
    std::string::string(local_20,(char *)unaff_ESI,(int)unaff_EDI - (int)unaff_ESI,local_22);
    std::string::swap(token);
    if ((allocator *)(local_20[0] + -0xc) != (allocator *)&std::string::_Rep::_S_empty_rep_storage)
    {
      LOCK();
      piVar2 = (int *)(local_20[0] + -4);
      iVar5 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar5 < 1) {
        std::string::_Rep::_M_destroy((allocator *)(local_20[0] + -0xc));
      }
    }
  }
  goto LAB_00188eda;
}


// DT_Initialize  @ 00188d30
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DT_Initialize(void)

{
  Cvar_RegisterVariable(&r_detailtextures);
  Cvar_RegisterVariable(&r_detailtexturessupported);
  (*qglSelectTextureSGIS)(TEXTURE2_SGIS);
  (*qglEnable)(0xde1);
  (*qglTexEnvf)(0x2300,0x2200,34160.0);
  (*qglTexEnvf)(0x2300,0x8571,8448.0);
  (*qglTexEnvf)(0x2300,0x8573,2.0);
  (*qglDisable)(0xde1);
  (*qglSelectTextureSGIS)(TEXTURE0_SGIS);
  detTexSupported = true;
  return;
}


// DT_LoadDetailMapFile  @ 00189770
/* WARNING: Removing unreachable block (ram,0x00189ce1) */
/* WARNING: Removing unreachable block (ram,0x00189d0e) */
/* WARNING: Removing unreachable block (ram,0x00189af0) */
/* WARNING: Removing unreachable block (ram,0x00189b4f) */
/* WARNING: Removing unreachable block (ram,0x00189bb7) */
/* WARNING: Removing unreachable block (ram,0x00189b8c) */
/* WARNING: Removing unreachable block (ram,0x00189b99) */
/* WARNING: Removing unreachable block (ram,0x00189bb0) */
/* WARNING: Removing unreachable block (ram,0x00189ae0) */
/* WARNING: Removing unreachable block (ram,0x00189cf1) */
/* WARNING: Removing unreachable block (ram,0x00189cfe) */

void DT_LoadDetailMapFile(char *levelName)

{
  allocator *paVar1;
  int iVar2;
  DetailMap *pDVar3;
  pointer ppVar4;
  pointer ppDVar5;
  int *piVar6;
  FileHandle_t file;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  pointer ppVar10;
  int iVar11;
  pointer ppVar12;
  allocator local_2f;
  allocator local_2e [2];
  string local_2c;
  string local_28;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: size_type idx@[???]
                       Unresolved local var: size_type length@[???]
                       Unresolved local var: FileHandle_t fileHandle@[???]
                       Unresolved local var: string fileName@[???]
                       Unresolved local var: uint fileSize@[???]
                       Unresolved local var: char * pBuffer@[???]
                       Unresolved local var: uint numberBytesRead@[???]
                       Unresolved local var: int readSuccess@[???] */
  ppVar4 = g_decalTexIDs.
           super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
           ._M_impl._M_finish;
  if (detTexSupported) {
    if (r_detailtextures.value == 0.0) {
      g_detTexLoaded = false;
      strlen(levelName);
      std::string::assign((char *)&g_levelName,(uint)levelName);
    }
    else {
      g_detTexLoaded = true;
      ppVar12 = g_decalTexIDs.
                super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                ._M_impl._M_finish;
      if (!g_demandLoad) {
        ppVar12 = g_decalTexIDs.
                  super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                  ._M_impl._M_start;
        for (ppVar10 = g_decalTexIDs.
                       super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                       ._M_impl._M_start; ppVar10 != ppVar4; ppVar10 = ppVar10 + 1) {
          pcVar7 = (ppVar10->first)._M_dataplus._M_p;
          paVar1 = (allocator *)(pcVar7 + -0xc);
          if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
            LOCK();
            piVar6 = (int *)(pcVar7 + -4);
            iVar9 = *piVar6;
            *piVar6 = *piVar6 + -1;
            UNLOCK();
            if (iVar9 < 1) {
              std::string::_Rep::_M_destroy(paVar1);
            }
          }
        }
      }
      g_decalTexIDs.
      super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
      ._M_impl._M_finish = ppVar12;
      iVar9 = (int)g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>.
                   _M_impl._M_finish -
              (int)g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>.
                   _M_impl._M_start >> 2;
      if (iVar9 != 0) {
        iVar11 = 0;
        do {
          ppDVar5 = g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>.
                    _M_impl._M_start + iVar11;
          pDVar3 = *ppDVar5;
          if (pDVar3 != (DetailMap *)0x0) {
            pcVar7 = (pDVar3->_detailName)._M_dataplus._M_p;
            paVar1 = (allocator *)(pcVar7 + -0xc);
            if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
              LOCK();
              piVar6 = (int *)(pcVar7 + -4);
              iVar2 = *piVar6;
              *piVar6 = *piVar6 + -1;
              UNLOCK();
              if (iVar2 < 1) {
                std::string::_Rep::_M_destroy(paVar1);
              }
            }
            pcVar7 = (pDVar3->_diffuseName)._M_dataplus._M_p;
            paVar1 = (allocator *)(pcVar7 + -0xc);
            if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
              LOCK();
              piVar6 = (int *)(pcVar7 + -4);
              iVar2 = *piVar6;
              *piVar6 = *piVar6 + -1;
              UNLOCK();
              if (iVar2 < 1) {
                std::string::_Rep::_M_destroy(paVar1);
              }
            }
            operator_delete(pDVar3);
            ppDVar5 = g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>.
                      _M_impl._M_start + iVar11;
          }
          iVar11 = iVar11 + 1;
          *ppDVar5 = (DetailMap *)0x0;
        } while (iVar11 != iVar9);
      }
      g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl._M_finish =
           g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl.
           _M_start;
      std::
      _Rb_tree<int,_std::pair<int_const,_DetailMap*>,_std::_Select1st<std::pair<int_const,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<int_const,_DetailMap*>_>_>
      ::_M_erase(&g_idMap._M_t,(_Link_type)g_idMap._M_t._M_impl._M_header._M_parent);
      g_idMap._M_t._M_impl._M_header._M_parent = (_Base_ptr)0x0;
      g_idMap._M_t._M_impl._M_header._M_left = &g_idMap._M_t._M_impl._M_header;
      g_idMap._M_t._M_impl._M_header._M_right = &g_idMap._M_t._M_impl._M_header;
      g_idMap._M_t._M_impl._M_node_count = 0;
      std::
      _Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
      ::_M_erase(&g_detailNameToIdMap._M_t,
                 (_Link_type)g_detailNameToIdMap._M_t._M_impl._M_header._M_parent);
      g_detailNameToIdMap._M_t._M_impl._M_header._M_parent = (_Base_ptr)0x0;
      g_detailNameToIdMap._M_t._M_impl._M_header._M_left =
           &g_detailNameToIdMap._M_t._M_impl._M_header;
      g_detailNameToIdMap._M_t._M_impl._M_header._M_right =
           &g_detailNameToIdMap._M_t._M_impl._M_header;
      g_detailNameToIdMap._M_t._M_impl._M_node_count = 0;
      std::
      _Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
      ::_M_erase(&g_detailLoadFailedMap._M_t,
                 (_Link_type)g_detailLoadFailedMap._M_t._M_impl._M_header._M_parent);
      g_detailLoadFailedMap._M_t._M_impl._M_header._M_parent = (_Base_ptr)0x0;
      g_detailLoadFailedMap._M_t._M_impl._M_header._M_left =
           &g_detailLoadFailedMap._M_t._M_impl._M_header;
      g_detailLoadFailedMap._M_t._M_impl._M_header._M_right =
           &g_detailLoadFailedMap._M_t._M_impl._M_header;
      g_detailLoadFailedMap._M_t._M_impl._M_node_count = 0;
      std::string::string(&local_2c,"maps/",(allocator *)local_20);
      std::string::string(&local_24,"_detail.txt",local_2e);
      std::string::string(&local_28,levelName,&local_2f);
                    /* Unresolved local var: uint __size@[???]
                       Unresolved local var: bool __cond@[???] */
      uVar8 = *(int *)(local_24 + -0xc) + *(int *)((int)local_28._M_dataplus._M_p - 0xc);
      if ((*(uint *)((int)local_28._M_dataplus._M_p - 8) < uVar8) &&
         (uVar8 <= *(uint *)(local_24 + -8))) {
        piVar6 = (int *)std::string::insert((uint)&local_24,(char *)0x0,
                                            (uint)local_28._M_dataplus._M_p);
      }
      else {
        piVar6 = (int *)std::string::append(&local_28);
      }
      local_20[0] = *piVar6;
      *piVar6 = (int)&std::nothrow;
      std::string::append(&local_2c);
      if ((allocator *)(local_20[0] + -0xc) != (allocator *)&std::string::_Rep::_S_empty_rep_storage
         ) {
        LOCK();
        piVar6 = (int *)(local_20[0] + -4);
        iVar9 = *piVar6;
        *piVar6 = *piVar6 + -1;
        UNLOCK();
        if (iVar9 < 1) {
          std::string::_Rep::_M_destroy((allocator *)(local_20[0] + -0xc));
        }
      }
      if ((allocator *)((int)local_28._M_dataplus._M_p - 0xcU) !=
          (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
        LOCK();
        piVar6 = (int *)((int)local_28._M_dataplus._M_p - 4);
        iVar9 = *piVar6;
        *piVar6 = *piVar6 + -1;
        UNLOCK();
        if (iVar9 < 1) {
          std::string::_Rep::_M_destroy((allocator *)((int)local_28._M_dataplus._M_p - 0xcU));
        }
      }
      if ((allocator *)(local_24 + -0xc) != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
        LOCK();
        piVar6 = (int *)(local_24 + -4);
        iVar9 = *piVar6;
        *piVar6 = *piVar6 + -1;
        UNLOCK();
        if (iVar9 < 1) {
          std::string::_Rep::_M_destroy((allocator *)(local_24 + -0xc));
        }
      }
      file = FS_Open((char *)local_2c._M_dataplus._M_p,"rb");
      if (file == (FileHandle_t)0x0) {
        Con_Printf("No detail texture mapping file: %s\n",local_2c._M_dataplus._M_p);
      }
      else {
        uVar8 = FS_FileSize((char *)local_2c._M_dataplus._M_p);
        pcVar7 = operator_new__(uVar8 + 10);
        iVar9 = FS_Read(pcVar7,uVar8,1,file);
        if (iVar9 < 1) {
          Con_Printf("Detail texture mapping file read failed\n");
        }
        else {
          FS_Close(file);
          pcVar7[uVar8] = -1;
          DT_Parse(pcVar7);
          if (pcVar7 != (char *)0x0) {
            operator_delete__(pcVar7);
          }
        }
      }
      if ((allocator *)((int)local_2c._M_dataplus._M_p + -0xc) !=
          (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
        LOCK();
        piVar6 = (int *)((int)local_2c._M_dataplus._M_p + -4);
        iVar9 = *piVar6;
        *piVar6 = *piVar6 + -1;
        UNLOCK();
        if (iVar9 < 1) {
          std::string::_Rep::_M_destroy((allocator *)((int)local_2c._M_dataplus._M_p + -0xc));
        }
      }
    }
  }
  return;
}


// DT_LoadDetailTexture  @ 00189da0
/* WARNING: Removing unreachable block (ram,0x0018a1d0) */
/* WARNING: Removing unreachable block (ram,0x0018a1dd) */
/* WARNING: Removing unreachable block (ram,0x0018a0f0) */
/* WARNING: Removing unreachable block (ram,0x0018a117) */
/* WARNING: Removing unreachable block (ram,0x0018a150) */
/* WARNING: Removing unreachable block (ram,0x0018a15d) */
/* WARNING: Removing unreachable block (ram,0x0018a100) */
/* WARNING: Removing unreachable block (ram,0x0018a108) */
/* WARNING: Removing unreachable block (ram,0x0018a112) */
/* WARNING: Removing unreachable block (ram,0x0018a177) */

void DT_LoadDetailTexture(char *diffuseName,int diffuseId)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  pointer ppVar4;
  char *pcVar5;
  int iVar6;
  GLint GVar7;
  int iVar8;
  int iVar9;
  pointer ppDVar10;
  _Rb_tree<int,_std::pair<int_const,_DetailMap*>,_std::_Select1st<std::pair<int_const,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<int_const,_DetailMap*>_>_>
  *this;
  _Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
  *this_00;
  map<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
  *pmVar11;
  string *psVar12;
  undefined1 local_5c [26];
  allocator local_42 [2];
  string local_40;
  char *local_3c;
  int local_38;
  basic_string<char,_std::char_traits<char>,_std::allocator<char>_> local_34;
  int local_30;
  undefined4 *local_2c;
  GLint local_28;
  undefined4 *local_24;
  DetailMap *local_20;
  
                    /* Unresolved local var: int detailId@[???]
                       Unresolved local var: string detailName@[???]
                       Unresolved local var: size_type idx@[???]
                       Unresolved local var: size_type length@[???]
                       Unresolved local var: iterator iter@[???]
                       Unresolved local var: bool once@[???] */
  local_40._M_dataplus._M_p = (_Alloc_hider)&std::nothrow;
  if (detTexSupported) {
    if (r_detailtextures.value == 0.0) {
      std::string::string(&local_34,diffuseName,local_42);
      ppVar4 = g_decalTexIDs.
               super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
               ._M_impl._M_finish;
      local_30 = diffuseId;
      if (g_decalTexIDs.
          super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
          ._M_impl._M_finish ==
          g_decalTexIDs.
          super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
          ._M_impl._M_end_of_storage) {
        std::
        vector<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
        ::
        _M_emplace_back_aux<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>
                  (&g_decalTexIDs);
      }
      else {
        if (g_decalTexIDs.
            super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
            ._M_impl._M_finish != (pointer)0x0) {
          ((g_decalTexIDs.
            super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
            ._M_impl._M_finish)->first)._M_dataplus._M_p = (char *)local_34._M_dataplus._M_p;
          local_34._M_dataplus._M_p = (_Alloc_hider)&std::nothrow;
          ppVar4->second = diffuseId;
        }
        g_decalTexIDs.
        super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
        ._M_impl._M_finish =
             g_decalTexIDs.
             super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
             ._M_impl._M_finish + 1;
      }
      if ((allocator *)((int)local_34._M_dataplus._M_p + -0xc) !=
          (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
        LOCK();
        piVar2 = (int *)((int)local_34._M_dataplus._M_p + -4);
        iVar8 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar8 < 1) {
          std::string::_Rep::_M_destroy((allocator *)((int)local_34._M_dataplus._M_p + -0xc));
        }
      }
    }
    else {
      iVar8 = (int)g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>.
                   _M_impl._M_finish -
              (int)g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>.
                   _M_impl._M_start >> 2;
      if (iVar8 == 0) {
        return;
      }
      iVar9 = 0;
      do {
        std::string::string(&local_3c,
                            &g_detailVector.
                             super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl.
                             _M_start[iVar9]->_diffuseName);
        pcVar5 = local_3c;
        iVar6 = strcasecmp(diffuseName,local_3c);
        paVar1 = (allocator *)(pcVar5 + -0xc);
        if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
          LOCK();
          piVar2 = (int *)(pcVar5 + -4);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 < 1) {
            std::string::_Rep::_M_destroy(paVar1);
          }
        }
        if (iVar6 == 0) {
          std::string::string(&local_38,
                              &g_detailVector.
                               super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl.
                               _M_start[iVar9]->_detailName);
          std::string::assign(&local_40);
          if ((allocator *)(local_38 + -0xc) !=
              (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
            LOCK();
            piVar2 = (int *)(local_38 + -4);
            iVar8 = *piVar2;
            *piVar2 = *piVar2 + -1;
            UNLOCK();
            if (iVar8 < 1) {
              std::string::_Rep::_M_destroy((allocator *)(local_38 + -0xc));
            }
          }
          std::
          _Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
          ::find((_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                  *)(local_5c + 0xc),
                 (basic_string<char,_std::char_traits<char>,_std::allocator<char>_> *)
                 &g_detailLoadFailedMap);
          if ((_Rb_tree_node_base *)local_5c._12_4_ == &g_detailLoadFailedMap._M_t._M_impl._M_header
             ) {
            psVar12 = &local_40;
            std::
            _Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
            ::find((_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                    *)(local_5c + 0xc),
                   (basic_string<char,_std::char_traits<char>,_std::allocator<char>_> *)
                   &g_detailNameToIdMap);
            if ((_Rb_tree_node_base *)local_5c._12_4_ == &g_detailNameToIdMap._M_t._M_impl._M_header
               ) {
              GVar7 = loadTextureFile((char *)local_40._M_dataplus._M_p);
              if (GVar7 == -1) {
                Con_Printf("Detail texture map load failed: %s\n",local_40._M_dataplus._M_p,psVar12)
                ;
                std::string::string(&local_24,&local_40);
                this_00 = (_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                           *)local_5c;
                pmVar11 = &g_detailLoadFailedMap;
                local_20 = (DetailMap *)0x0;
                std::
                _Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                ::_M_insert_unique<std::pair<std::basic_string<char>,_int>_>
                          (this_00,(pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>
                                    *)&g_detailLoadFailedMap);
                if (local_24 != &std::nothrow) {
                  std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>::_Rep::
                  _M_dispose((_Rep *)this_00,(allocator<char> *)pmVar11);
                }
              }
              else {
                ppDVar10 = g_detailVector.
                           super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl.
                           _M_start + iVar9;
                (*ppDVar10)->_oglTextureId = diffuseId;
                (*ppDVar10)->_oglDetailId = GVar7;
                local_24 = (undefined4 *)diffuseId;
                local_20 = *ppDVar10;
                this = (_Rb_tree<int,_std::pair<int_const,_DetailMap*>,_std::_Select1st<std::pair<int_const,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<int_const,_DetailMap*>_>_>
                        *)local_5c;
                std::
                _Rb_tree<int,_std::pair<int_const,_DetailMap*>,_std::_Select1st<std::pair<int_const,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<int_const,_DetailMap*>_>_>
                ::_M_insert_unique<std::pair<int,_DetailMap*>_>
                          (this,(pair<int,_DetailMap*> *)&g_idMap);
                std::string::string(&local_2c,&local_40);
                pmVar11 = &g_detailNameToIdMap;
                local_28 = GVar7;
                std::
                _Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                ::_M_insert_unique<std::pair<std::basic_string<char>,_int>_>
                          ((_Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                            *)this,(pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>
                                    *)&g_detailNameToIdMap);
                if (local_2c != &std::nothrow) {
                  std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>::_Rep::
                  _M_dispose((_Rep *)this,(allocator<char> *)pmVar11);
                }
              }
            }
            else {
              ppDVar10 = g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>.
                         _M_impl._M_start + iVar9;
              (*ppDVar10)->_oglTextureId = diffuseId;
              (*ppDVar10)->_oglDetailId = (GLint)((_Base_ptr)(local_5c._12_4_ + 0x10))->_M_parent;
              local_24 = (undefined4 *)diffuseId;
              local_20 = *ppDVar10;
              std::
              _Rb_tree<int,_std::pair<int_const,_DetailMap*>,_std::_Select1st<std::pair<int_const,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<int_const,_DetailMap*>_>_>
              ::_M_insert_unique<std::pair<int,_DetailMap*>_>
                        ((_Rb_tree<int,_std::pair<int_const,_DetailMap*>,_std::_Select1st<std::pair<int_const,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<int_const,_DetailMap*>_>_>
                          *)local_5c,(pair<int,_DetailMap*> *)&g_idMap);
            }
          }
          break;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 != iVar8);
    }
    if ((allocator *)((int)local_40._M_dataplus._M_p + -0xc) !=
        (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
      LOCK();
      piVar2 = (int *)((int)local_40._M_dataplus._M_p + -4);
      iVar8 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar8 < 1) {
        std::string::_Rep::_M_destroy((allocator *)((int)local_40._M_dataplus._M_p + -0xc));
      }
    }
  }
  return;
}


// DT_Parse  @ 001893a0
/* WARNING: Removing unreachable block (ram,0x001896ed) */
/* WARNING: Removing unreachable block (ram,0x001896d0) */
/* WARNING: Removing unreachable block (ram,0x001896e0) */

void DT_Parse(char *pBuffer)

{
  int *piVar1;
  int iVar2;
  DetailMap *this;
  pointer ppDVar3;
  bool bVar4;
  double dVar5;
  float local_48;
  float local_44;
  ParseState local_34;
  char *local_30;
  string local_2c;
  string local_28;
  string local_24;
  DetailMap *local_20;
  
                    /* Unresolved local var: ParseState state@[???]
                       Unresolved local var: char * cPtr@[???]
                       Unresolved local var: string diffuseName@[???]
                       Unresolved local var: string detailName@[???]
                       Unresolved local var: string scaleFactorString@[???]
                       Unresolved local var: float sScaleFactor@[???]
                       Unresolved local var: float tScaleFactor@[???] */
  local_2c._M_dataplus._M_p = (_Alloc_hider)&std::nothrow;
  local_28._M_dataplus._M_p = (_Alloc_hider)&std::nothrow;
  local_34 = PS_START;
  local_24._M_dataplus._M_p = (_Alloc_hider)&std::nothrow;
  do {
    if (local_34 - PS_ERROR < 2) {
      if (local_34 == PS_ERROR) {
        Con_Printf("Error parsing detail texture file.\n");
      }
      if ((allocator *)((int)local_24._M_dataplus._M_p + -0xc) !=
          (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
        LOCK();
        piVar1 = (int *)((int)local_24._M_dataplus._M_p + -4);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 < 1) {
          std::string::_Rep::_M_destroy((allocator *)((int)local_24._M_dataplus._M_p + -0xc));
        }
      }
      if ((allocator *)((int)local_28._M_dataplus._M_p + -0xc) !=
          (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
        LOCK();
        piVar1 = (int *)((int)local_28._M_dataplus._M_p + -4);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 < 1) {
          std::string::_Rep::_M_destroy((allocator *)((int)local_28._M_dataplus._M_p + -0xc));
        }
      }
      if ((allocator *)((int)local_2c._M_dataplus._M_p + -0xc) !=
          (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
        LOCK();
        piVar1 = (int *)((int)local_2c._M_dataplus._M_p + -4);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 < 1) {
          std::string::_Rep::_M_destroy((allocator *)((int)local_2c._M_dataplus._M_p + -0xc));
        }
      }
      return;
    }
switchD_001893ed_switchD:
    switch(local_34) {
    case PS_START:
      local_34 = PS_DIFFUSE_NAME;
      local_30 = pBuffer;
      break;
    case PS_DIFFUSE_NAME:
      bVar4 = DT_GetToken(&local_30,&local_34,&local_2c);
      if (bVar4) {
        local_34 = PS_DETAIL_TEXTURE;
      }
      break;
    case PS_DETAIL_TEXTURE:
      bVar4 = DT_GetToken(&local_30,&local_34,&local_28);
      if (bVar4) {
        local_34 = PS_S_SCALE_FACTOR;
      }
      break;
    case PS_S_SCALE_FACTOR:
      bVar4 = DT_GetToken(&local_30,&local_34,&local_24);
      if (bVar4) {
        dVar5 = strtod((char *)local_24._M_dataplus._M_p,(char **)0x0);
        local_48 = (float)dVar5;
        local_34 = PS_T_SCALE_FACTOR;
      }
      break;
    case PS_T_SCALE_FACTOR:
      bVar4 = DT_GetToken(&local_30,&local_34,&local_24);
      if (bVar4) {
        dVar5 = strtod((char *)local_24._M_dataplus._M_p,(char **)0x0);
        local_44 = (float)dVar5;
        local_34 = PS_ENTRY;
      }
      break;
    case PS_ENTRY:
      this = operator_new(0x18);
      std::string::string(this,&local_2c);
      std::string::string(&this->_detailName,&local_28);
      ppDVar3 = g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl.
                _M_finish;
      bVar4 = g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl.
              _M_finish ==
              g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl.
              _M_end_of_storage;
      this->_sScale = local_48;
      this->_tScale = local_44;
      this->_oglTextureId = 0;
      this->_oglDetailId = 0;
      local_20 = this;
      if (bVar4) {
        std::vector<DetailMap*,_std::allocator<DetailMap*>_>::_M_emplace_back_aux<DetailMap*>
                  (&g_detailVector);
      }
      else {
        if (ppDVar3 != (pointer)0x0) {
          *ppDVar3 = this;
          ppDVar3 = g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>.
                    _M_impl._M_finish;
        }
        g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl._M_finish
             = ppDVar3 + 1;
      }
      local_34 = PS_DIFFUSE_NAME;
      break;
    default:
      goto switchD_001893ed_switchD;
    }
  } while( true );
}


// DT_SetRenderState  @ 0018a2d0
/* WARNING: Removing unreachable block (ram,0x0018a52d) */
/* WARNING: Removing unreachable block (ram,0x0018a54d) */
/* WARNING: Removing unreachable block (ram,0x0018a582) */
/* WARNING: Removing unreachable block (ram,0x0018a58f) */
/* WARNING: Removing unreachable block (ram,0x0018a538) */

int DT_SetRenderState(int diffuseId)

{
  _Base_ptr *pp_Var1;
  int *piVar2;
  pointer ppVar3;
  int iVar4;
  _Base_ptr p_Var5;
  _Base_ptr p_Var6;
  _Base_ptr p_Var7;
  uint uVar8;
  char *local_24;
  int local_20;
  
                    /* Unresolved local var: DetailMap * pDetail@[???]
                       Unresolved local var: iterator iter@[???]
                       Unresolved local var: bool bind@[???]
                       Unresolved local var: bool scale@[???] */
  if ((!detTexSupported) || (r_detailtextures.value == 0.0)) {
    return 0;
  }
  if (!g_detTexLoaded) {
    Con_Printf("Loading Detail Textures...\n");
    g_demandLoad = true;
    DT_LoadDetailMapFile((char *)g_levelName._M_dataplus._M_p);
                    /* Unresolved local var: int i@[???] */
    if ((uint)((int)g_decalTexIDs.
                    super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                    ._M_impl._M_finish -
              (int)g_decalTexIDs.
                   super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                   ._M_impl._M_start) >> 3 != 0) {
      uVar8 = 0;
      do {
                    /* Unresolved local var:
                       pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>
                       p@[???] */
        ppVar3 = g_decalTexIDs.
                 super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                 ._M_impl._M_start + uVar8;
        std::string::string(&local_24,&ppVar3->first);
        local_20 = ppVar3->second;
        DT_LoadDetailTexture(local_24,local_20);
        if ((allocator *)(local_24 + -0xc) != (allocator *)&std::string::_Rep::_S_empty_rep_storage)
        {
          LOCK();
          piVar2 = (int *)(local_24 + -4);
          iVar4 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar4 < 1) {
            std::string::_Rep::_M_destroy((allocator *)(local_24 + -0xc));
          }
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < (uint)((int)g_decalTexIDs.
                                   super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                                   ._M_impl._M_finish -
                              (int)g_decalTexIDs.
                                   super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                                   ._M_impl._M_start >> 3));
    }
    g_detTexLoaded = true;
    g_demandLoad = false;
  }
                    /* Unresolved local var: iterator __j@[???] */
  if (g_idMap._M_t._M_impl._M_header._M_parent == (_Base_ptr)0x0) {
    return 0;
  }
  p_Var5 = g_idMap._M_t._M_impl._M_header._M_parent;
  p_Var6 = &g_idMap._M_t._M_impl._M_header;
  do {
    while (p_Var7 = p_Var5, (int)p_Var7[1]._M_color < diffuseId) {
      pp_Var1 = &p_Var7->_M_right;
      p_Var5 = *pp_Var1;
      p_Var7 = p_Var6;
      if (*pp_Var1 == (_Base_ptr)0x0) goto LAB_0018a32d;
    }
    p_Var5 = p_Var7->_M_left;
    p_Var6 = p_Var7;
  } while (p_Var7->_M_left != (_Base_ptr)0x0);
LAB_0018a32d:
  if (p_Var7 == &g_idMap._M_t._M_impl._M_header) {
    return 0;
  }
  if (diffuseId < (int)p_Var7[1]._M_color) {
    return 0;
  }
  p_Var5 = p_Var7[1]._M_parent;
  if (p_Var5[1]._M_parent == (_Base_ptr)0x0) {
    return 0;
  }
  if (p_Var5[1]._M_color != _S_red) {
    (*qglSelectTextureSGIS)(TEXTURE2_SGIS);
    (*qglEnable)(0xde1);
    p_Var6 = p_Var5[1]._M_parent;
    if ((lastDetTex == -1) || ((_Base_ptr)lastDetTex != p_Var6)) {
      lastDetTex = (GLint)p_Var6;
      if ((float)p_Var5->_M_left == lastDetSScale) {
        p_Var7 = p_Var5->_M_right;
        if (lastDetTScale == (float)p_Var5->_M_right) {
          (*qglBindTexture)(0xde1,(GLuint)p_Var6);
          return 1;
        }
      }
      else {
        p_Var7 = p_Var5->_M_right;
      }
      lastDetTScale = (GLfloat)p_Var7;
      lastDetSScale = (GLfloat)p_Var5->_M_left;
      (*qglBindTexture)(0xde1,(GLuint)p_Var6);
      p_Var7 = (_Base_ptr)lastDetTScale;
      p_Var6 = (_Base_ptr)lastDetSScale;
    }
    else {
      p_Var6 = p_Var5->_M_left;
      if ((float)p_Var6 == lastDetSScale) {
        p_Var7 = p_Var5->_M_right;
        if (lastDetTScale == (float)p_Var5->_M_right) {
          return 1;
        }
      }
      else {
        p_Var7 = p_Var5->_M_right;
      }
    }
    lastDetSScale = (GLfloat)p_Var6;
    lastDetTScale = (GLfloat)p_Var7;
    (*qglMatrixMode)(0x1702);
    (*qglLoadIdentity)();
    (*qglScalef)((GLfloat)p_Var5->_M_left,(GLfloat)p_Var5->_M_right,1.0);
    (*qglMatrixMode)(0x1700);
    return 1;
  }
  return 0;
}


// DT_SetTextureCoordinates  @ 00189340
void DT_SetTextureCoordinates(float u,float v)

{
  (*qglMTexCoord2fSGIS)(TEXTURE2_SGIS,u,v);
  return;
}


