// DT_ClearRenderState  @ 001dda90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DT_ClearRenderState(void)

{
  (*qglSelectTextureSGIS)(TEXTURE2_SGIS);
  (*qglDisable)(0xde1);
  (*qglSelectTextureSGIS)(TEXTURE1_SGIS);
  return;
}


// DT_GetDetailTextureName  @ 001dd810
/* WARNING: Removing unreachable block (ram,0x001dda48) */
/* WARNING: Removing unreachable block (ram,0x001dd943) */
/* WARNING: Removing unreachable block (ram,0x001dd949) */
/* WARNING: Removing unreachable block (ram,0x001dda14) */
/* WARNING: Removing unreachable block (ram,0x001dda25) */
/* WARNING: Removing unreachable block (ram,0x001dd986) */
/* WARNING: Removing unreachable block (ram,0x001dd992) */
/* WARNING: Removing unreachable block (ram,0x001dd99d) */
/* WARNING: Removing unreachable block (ram,0x001dda3a) */

char * DT_GetDetailTextureName(char *diffuseName)

{
  allocator *paVar1;
  code *pcVar2;
  int *piVar3;
  int iVar4;
  string sVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  string local_2c;
  char *local_28;
  int local_24 [5];
  
                    /* Unresolved local var: string detailName@[???]
                       Unresolved local var: size_type idx@[???]
                       Unresolved local var: size_type length@[???] */
  local_2c._M_dataplus._M_p = (_Alloc_hider)glViewport;
  iVar8 = (int)g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl.
               _M_finish -
          (int)g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl.
               _M_start >> 2;
  if (iVar8 != 0) {
    iVar9 = 0;
    do {
      std::string::string(&local_28,
                          &g_detailVector.
                           super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl.
                           _M_start[iVar9]->_diffuseName);
      pcVar7 = local_28;
      iVar6 = strcasecmp(diffuseName,local_28);
      paVar1 = (allocator *)(pcVar7 + -0xc);
      if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
        LOCK();
        piVar3 = (int *)(pcVar7 + -4);
        iVar4 = *piVar3;
        *piVar3 = *piVar3 + -1;
        UNLOCK();
        if (iVar4 < 1) {
          std::string::_Rep::_M_destroy(paVar1);
        }
      }
      if (iVar6 == 0) {
        std::string::string(local_24,&g_detailVector.
                                      super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>.
                                      _M_impl._M_start[iVar9]->_detailName);
        std::string::assign(&local_2c);
        if ((allocator *)(local_24[0] + -0xc) !=
            (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
          LOCK();
          piVar3 = (int *)(local_24[0] + -4);
          iVar8 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
          if (iVar8 < 1) {
            std::string::_Rep::_M_destroy((allocator *)(local_24[0] + -0xc));
          }
        }
        break;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 != iVar8);
  }
  sVar5._M_dataplus._M_p = local_2c._M_dataplus._M_p;
  pcVar7 = (char *)0x0;
  if (*(int *)((int)local_2c._M_dataplus._M_p + -0xc) != 0) {
    strcpy(DT_GetDetailTextureName::lexical_block_0::buffer,(char *)local_2c._M_dataplus._M_p);
    pcVar7 = DT_GetDetailTextureName::lexical_block_0::buffer;
  }
  paVar1 = (allocator *)((int)sVar5._M_dataplus._M_p + -0xc);
  if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
    LOCK();
    pcVar2 = (code *)((int)sVar5._M_dataplus._M_p + -4);
    iVar8 = *(int *)pcVar2;
    *(int *)pcVar2 = *(int *)pcVar2 + -1;
    UNLOCK();
    if (iVar8 < 1) {
      std::string::_Rep::_M_destroy(paVar1);
    }
  }
  return pcVar7;
}


// DT_GetToken  @ 001dd150
/* WARNING: Removing unreachable block (ram,0x001dd3bb) */

bool DT_GetToken(char **cPtr,ParseState *parseState,string *token)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  char *unaff_EBX;
  char *unaff_ESI;
  uint local_30;
  int local_24;
  allocator local_1e [14];
  
                    /* Unresolved local var: char * sPtr@[???]
                       Unresolved local var: char * ePtr@[???]
                       Unresolved local var: LexerState state@[???] */
  local_30 = 0;
LAB_001dd170:
  do {
    if (local_30 - 4 < 2) {
LAB_001dd276:
      *cPtr = unaff_EBX;
      return 1 < *parseState - PS_ERROR;
    }
    if (local_30 < 2) {
      do {
        if (local_30 == 1) goto LAB_001dd291;
      } while (local_30 != 0);
      unaff_EBX = *cPtr;
      local_30 = 1;
      unaff_ESI = unaff_EBX;
    }
    else {
      do {
        if (local_30 == 1) goto LAB_001dd291;
        if (local_30 == 2) {
          local_30 = 3;
          if ((*unaff_ESI != '/') || (unaff_ESI[1] != '/')) goto LAB_001dd170;
          cVar3 = unaff_ESI[2];
          unaff_ESI = unaff_ESI + 2;
          if ((cVar3 == '\r') || (cVar3 == '\n')) goto LAB_001dd330;
          goto LAB_001dd319;
        }
      } while (local_30 != 3);
                    /* Unresolved local var: int idx@[???] */
      for (; (((((cVar3 = *unaff_EBX, (byte)(cVar3 + 0xbfU) < 0x1a || ((byte)(cVar3 + 0x9fU) < 0x1a)
                 ) || ((byte)(cVar3 - 0x30U) < 10)) ||
               (((cVar3 == '_' || (cVar3 == '.')) ||
                ((cVar3 == '-' || ((cVar3 == '/' || (cVar3 == '{')))))))) || (cVar3 == '~')) ||
             ((((cVar3 == '!' || (cVar3 == '+')) || (cVar3 == '[')) || (cVar3 == ']'))));
          unaff_EBX = unaff_EBX + 1) {
      }
      if (unaff_EBX == unaff_ESI) {
        local_30 = 5;
        *parseState = PS_ERROR;
        unaff_ESI = unaff_EBX;
      }
      else {
        std::string::string(&local_24,unaff_ESI,(int)unaff_EBX - (int)unaff_ESI,local_1e);
        std::string::assign(token);
        if ((allocator *)(local_24 + -0xc) == (allocator *)&std::string::_Rep::_S_empty_rep_storage)
        goto LAB_001dd276;
        LOCK();
        piVar1 = (int *)(local_24 + -4);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        local_30 = 5;
        if (iVar2 < 1) {
          local_30 = 5;
          std::string::_Rep::_M_destroy((allocator *)(local_24 + -0xc));
        }
      }
    }
  } while( true );
LAB_001dd291:
                    /* Unresolved local var: int idx@[???] */
  while ((((unaff_EBX = unaff_ESI, cVar3 = *unaff_EBX, cVar3 == '\r' || (cVar3 == '\n')) ||
          (cVar3 == '\t')) || (cVar3 == ' '))) {
    unaff_ESI = unaff_EBX + 1;
  }
  unaff_ESI = unaff_EBX;
  if (cVar3 == -1) {
    local_30 = 5;
    *parseState = PS_COMPLETE;
  }
  else {
    local_30 = 2;
  }
  goto LAB_001dd170;
LAB_001dd319:
  if (cVar3 == -1) goto LAB_001dd330;
  unaff_ESI = unaff_ESI + 1;
  cVar3 = *unaff_ESI;
  if ((cVar3 == '\n') || (cVar3 == '\r')) goto LAB_001dd330;
  goto LAB_001dd319;
LAB_001dd330:
  local_30 = 1;
  goto LAB_001dd170;
}


// DT_Initialize  @ 001dd090
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


// DT_LoadDetailMapFile  @ 001ddac0
/* WARNING: Removing unreachable block (ram,0x001ddf3e) */
/* WARNING: Removing unreachable block (ram,0x001ddf85) */
/* WARNING: Removing unreachable block (ram,0x001ddf92) */
/* WARNING: Removing unreachable block (ram,0x001ddf4b) */
/* WARNING: Removing unreachable block (ram,0x001ddf52) */
/* WARNING: Removing unreachable block (ram,0x001ddf25) */
/* WARNING: Removing unreachable block (ram,0x001ddfa4) */
/* WARNING: Removing unreachable block (ram,0x001de021) */
/* WARNING: Removing unreachable block (ram,0x001de031) */
/* WARNING: Removing unreachable block (ram,0x001de016) */
/* WARNING: Removing unreachable block (ram,0x001de00b) */
/* WARNING: Removing unreachable block (ram,0x001ddf33) */

void DT_LoadDetailMapFile(char *levelName)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  DetailMap *pDVar4;
  pointer ppVar5;
  pointer ppVar6;
  pointer ppVar7;
  pointer ppDVar8;
  FileHandle_t file;
  uint size;
  char *pcVar9;
  int iVar10;
  int iVar11;
  string local_5c [4];
  string local_4c [4];
  int local_3c [4];
  string local_2c;
  allocator local_27;
  allocator local_26;
  allocator local_25 [21];
  
  ppVar7 = g_decalTexIDs.
           super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
           ._M_impl._M_finish;
  ppVar6 = g_decalTexIDs.
           super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
           ._M_impl._M_start;
                    /* Unresolved local var: size_type idx@[???]
                       Unresolved local var: size_type length@[???]
                       Unresolved local var: FileHandle_t fileHandle@[???]
                       Unresolved local var: string fileName@[???]
                       Unresolved local var: uint fileSize@[???]
                       Unresolved local var: char * pBuffer@[???]
                       Unresolved local var: uint numberBytesRead@[???]
                       Unresolved local var: int readSuccess@[???] */
  if (detTexSupported) {
    if (r_detailtextures.value == 0.0) {
      g_detTexLoaded = false;
      strlen(levelName);
      std::string::assign((char *)&g_levelName,(uint)levelName);
      return;
    }
    g_detTexLoaded = true;
    ppVar5 = g_decalTexIDs.
             super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
             ._M_impl._M_start;
    if (!g_demandLoad) {
      for (; ppVar5 != ppVar7; ppVar5 = ppVar5 + 1) {
        pcVar9 = (ppVar5->first)._M_dataplus._M_p;
        paVar1 = (allocator *)(pcVar9 + -0xc);
        if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
          LOCK();
          piVar2 = (int *)(pcVar9 + -4);
          iVar10 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar10 < 1) {
            std::string::_Rep::_M_destroy(paVar1);
          }
        }
      }
      g_decalTexIDs.
      super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
      ._M_impl._M_finish = ppVar6;
    }
    iVar10 = (int)g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl
                  ._M_finish -
             (int)g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl
                  ._M_start >> 2;
    if (iVar10 != 0) {
      iVar11 = 0;
      do {
        ppDVar8 = g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl
                  ._M_start + iVar11;
        pDVar4 = *ppDVar8;
        if (pDVar4 != (DetailMap *)0x0) {
          pcVar9 = (pDVar4->_detailName)._M_dataplus._M_p;
          paVar1 = (allocator *)(pcVar9 + -0xc);
          if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
            LOCK();
            piVar2 = (int *)(pcVar9 + -4);
            iVar3 = *piVar2;
            *piVar2 = *piVar2 + -1;
            UNLOCK();
            if (iVar3 < 1) {
              std::string::_Rep::_M_destroy(paVar1);
            }
          }
          pcVar9 = (pDVar4->_diffuseName)._M_dataplus._M_p;
          paVar1 = (allocator *)(pcVar9 + -0xc);
          if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
            LOCK();
            piVar2 = (int *)(pcVar9 + -4);
            iVar3 = *piVar2;
            *piVar2 = *piVar2 + -1;
            UNLOCK();
            if (iVar3 < 1) {
              std::string::_Rep::_M_destroy(paVar1);
            }
          }
          operator_delete(pDVar4);
          ppDVar8 = g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>.
                    _M_impl._M_start + iVar11;
        }
        iVar11 = iVar11 + 1;
        *ppDVar8 = (DetailMap *)0x0;
      } while (iVar11 != iVar10);
    }
    g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl._M_finish =
         g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl._M_start
    ;
    std::
    _Rb_tree<int,_std::pair<const_int,_DetailMap*>,_std::_Select1st<std::pair<const_int,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<const_int,_DetailMap*>_>_>
    ::_M_erase(&g_idMap._M_t,(_Link_type)g_idMap._M_t._M_impl._M_header._M_parent);
    g_idMap._M_t._M_impl._M_header._M_left = &g_idMap._M_t._M_impl._M_header;
    g_idMap._M_t._M_impl._M_header._M_parent = (_Base_ptr)0x0;
    g_idMap._M_t._M_impl._M_header._M_right = &g_idMap._M_t._M_impl._M_header;
    g_idMap._M_t._M_impl._M_node_count = 0;
    std::
    _Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
    ::_M_erase(&g_detailNameToIdMap._M_t,
               (_Link_type)g_detailNameToIdMap._M_t._M_impl._M_header._M_parent);
    g_detailNameToIdMap._M_t._M_impl._M_header._M_left = &g_detailNameToIdMap._M_t._M_impl._M_header
    ;
    g_detailNameToIdMap._M_t._M_impl._M_header._M_parent = (_Base_ptr)0x0;
    g_detailNameToIdMap._M_t._M_impl._M_header._M_right =
         &g_detailNameToIdMap._M_t._M_impl._M_header;
    g_detailNameToIdMap._M_t._M_impl._M_node_count = 0;
    std::
    _Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
    ::_M_erase(&g_detailLoadFailedMap._M_t,
               (_Link_type)g_detailLoadFailedMap._M_t._M_impl._M_header._M_parent);
    g_detailLoadFailedMap._M_t._M_impl._M_header._M_right =
         &g_detailLoadFailedMap._M_t._M_impl._M_header;
    g_detailLoadFailedMap._M_t._M_impl._M_node_count = 0;
    g_detailLoadFailedMap._M_t._M_impl._M_header._M_left =
         &g_detailLoadFailedMap._M_t._M_impl._M_header;
    g_detailLoadFailedMap._M_t._M_impl._M_header._M_parent = (_Base_ptr)0x0;
    std::string::string(local_5c,"maps/",&local_27);
    std::string::string(local_3c,"_detail.txt",local_25);
    std::string::string(local_4c,levelName,&local_26);
                    /* Unresolved local var:
                       basic_string<char,_std::char_traits<char>,_std::allocator<char>_> __str@[???]
                        */
    std::string::string(&local_2c,local_4c);
    std::string::append(&local_2c);
    std::string::append(local_5c);
    if ((allocator *)((int)local_2c._M_dataplus._M_p + -0xc) !=
        (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
      LOCK();
      piVar2 = (int *)((int)local_2c._M_dataplus._M_p + -4);
      iVar10 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar10 < 1) {
        std::string::_Rep::_M_destroy((allocator *)((int)local_2c._M_dataplus._M_p + -0xc));
      }
    }
    if ((allocator *)((int)local_4c[0]._M_dataplus._M_p + -0xc) !=
        (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
      LOCK();
      piVar2 = (int *)((int)local_4c[0]._M_dataplus._M_p + -4);
      iVar10 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar10 < 1) {
        std::string::_Rep::_M_destroy((allocator *)((int)local_4c[0]._M_dataplus._M_p + -0xc));
      }
    }
    if ((allocator *)(local_3c[0] + -0xc) != (allocator *)&std::string::_Rep::_S_empty_rep_storage)
    {
      LOCK();
      piVar2 = (int *)(local_3c[0] + -4);
      iVar10 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar10 < 1) {
        std::string::_Rep::_M_destroy((allocator *)(local_3c[0] + -0xc));
      }
    }
    file = FS_Open((char *)local_5c[0]._M_dataplus._M_p,"rb");
    if (file == (FileHandle_t)0x0) {
      Con_Printf("No detail texture mapping file: %s\n",local_5c[0]._M_dataplus._M_p);
    }
    else {
      size = FS_FileSize((char *)local_5c[0]._M_dataplus._M_p);
      pcVar9 = operator_new__(size + 10);
      iVar10 = FS_Read(pcVar9,size,1,file);
      if (0 < iVar10) {
        FS_Close(file);
        pcVar9[size] = -1;
        DT_Parse(pcVar9);
        if (pcVar9 != (char *)0x0) {
          operator_delete__(pcVar9);
        }
        if ((allocator *)((int)local_5c[0]._M_dataplus._M_p + -0xc) ==
            (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
          return;
        }
        LOCK();
        piVar2 = (int *)((int)local_5c[0]._M_dataplus._M_p + -4);
        iVar10 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (0 < iVar10) {
          return;
        }
        std::string::_Rep::_M_destroy((allocator *)((int)local_5c[0]._M_dataplus._M_p + -0xc));
        return;
      }
      Con_Printf("Detail texture mapping file read failed\n");
    }
    if ((allocator *)((int)local_5c[0]._M_dataplus._M_p + -0xc) !=
        (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
      LOCK();
      piVar2 = (int *)((int)local_5c[0]._M_dataplus._M_p + -4);
      iVar10 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar10 < 1) {
        std::string::_Rep::_M_destroy((allocator *)((int)local_5c[0]._M_dataplus._M_p + -0xc));
      }
    }
  }
  return;
}


// DT_LoadDetailTexture  @ 001de050
/* WARNING: Removing unreachable block (ram,0x001de782) */
/* WARNING: Removing unreachable block (ram,0x001de801) */
/* WARNING: Removing unreachable block (ram,0x001de80a) */
/* WARNING: Removing unreachable block (ram,0x001de871) */
/* WARNING: Removing unreachable block (ram,0x001de87e) */
/* WARNING: Removing unreachable block (ram,0x001de846) */
/* WARNING: Removing unreachable block (ram,0x001de851) */
/* WARNING: Removing unreachable block (ram,0x001de85c) */
/* WARNING: Removing unreachable block (ram,0x001de863) */
/* WARNING: Removing unreachable block (ram,0x001de705) */
/* WARNING: Removing unreachable block (ram,0x001de709) */
/* WARNING: Removing unreachable block (ram,0x001de755) */
/* WARNING: Removing unreachable block (ram,0x001de762) */
/* WARNING: Removing unreachable block (ram,0x001de716) */
/* WARNING: Removing unreachable block (ram,0x001de71f) */
/* WARNING: Removing unreachable block (ram,0x001de8b3) */
/* WARNING: Removing unreachable block (ram,0x001de777) */
/* WARNING: Removing unreachable block (ram,0x001de6cb) */

void DT_LoadDetailTexture(char *diffuseName,int diffuseId)

{
  int *piVar1;
  _Base_ptr *pp_Var2;
  int iVar3;
  char *pcVar4;
  pointer this;
  pointer ppVar5;
  pointer ppVar6;
  pointer ppVar7;
  int iVar8;
  _Base_ptr p_Var9;
  _Base_ptr p_Var10;
  pointer ppDVar11;
  pointer ppVar12;
  GLint GVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  code *pcVar19;
  string sVar20;
  pointer ppVar21;
  bool bVar22;
  bool bVar23;
  byte bVar24;
  allocator *this_00;
  allocator *paVar25;
  pair<const_int,_DetailMap*> *__v;
  _Base_ptr local_9c;
  _Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
  local_94;
  int local_7c;
  DetailMap *local_78;
  string local_74;
  GLint local_70;
  undefined1 local_6c [4];
  GLint local_68;
  string local_64;
  undefined4 local_60;
  undefined1 local_5c [4];
  undefined4 local_58;
  int local_54;
  DetailMap *local_50;
  string local_4c [4];
  string local_3c [4];
  char *local_2c;
  undefined8 local_28;
  pair<const_int,_DetailMap*> local_1f;
  
  bVar24 = 0;
                    /* Unresolved local var: int detailId@[???]
                       Unresolved local var: string detailName@[???]
                       Unresolved local var: size_type idx@[???]
                       Unresolved local var: size_type length@[???]
                       Unresolved local var: iterator iter@[???]
                       Unresolved local var: bool once@[???] */
  local_4c[0]._M_dataplus._M_p = (_Alloc_hider)glViewport;
  if (detTexSupported) {
    if (r_detailtextures.value != 0.0) {
      iVar15 = (int)g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>.
                    _M_impl._M_finish -
               (int)g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>.
                    _M_impl._M_start >> 2;
      if (iVar15 != 0) {
        iVar16 = 0;
        do {
          std::string::string(&local_2c,
                              &g_detailVector.
                               super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl.
                               _M_start[iVar16]->_diffuseName);
          pcVar4 = local_2c;
          iVar8 = strcasecmp(diffuseName,local_2c);
          paVar25 = (allocator *)(pcVar4 + -0xc);
          if (paVar25 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
            LOCK();
            piVar1 = (int *)(pcVar4 + -4);
            iVar3 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
            if (iVar3 < 1) {
              std::string::_Rep::_M_destroy(paVar25);
            }
          }
          if (iVar8 == 0) {
            this_00 = (allocator *)local_4c;
            __v = (pair<const_int,_DetailMap*> *)&local_28;
            std::string::string(__v,&g_detailVector.
                                     super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>.
                                     _M_impl._M_start[iVar16]->_detailName);
            std::string::assign((string *)this_00);
            paVar25 = (allocator *)((int)local_28 + -0xc);
            if (paVar25 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
              LOCK();
              piVar1 = (int *)((int)local_28 + -4);
              iVar15 = *piVar1;
              *piVar1 = *piVar1 + -1;
              UNLOCK();
              if (iVar15 < 1) {
                __v = &local_1f;
                std::string::_Rep::_M_destroy(paVar25);
                this_00 = paVar25;
              }
            }
                    /* Unresolved local var: iterator __j@[???] */
            if (g_detailLoadFailedMap._M_t._M_impl._M_header._M_parent == (_Base_ptr)0x0)
            goto LAB_001de2b6;
            local_9c = &g_detailLoadFailedMap._M_t._M_impl._M_header;
            uVar17 = *(uint *)((int)local_4c[0]._M_dataplus._M_p + -0xc);
            p_Var10 = g_detailLoadFailedMap._M_t._M_impl._M_header._M_parent;
            goto LAB_001de24b;
          }
          iVar16 = iVar16 + 1;
        } while (iVar16 != iVar15);
      }
      goto LAB_001de354;
    }
    pp_Var2 = &local_94._M_impl._M_header._M_parent;
    std::string::string(local_3c,diffuseName,(allocator *)((int)&local_28 + 4));
    std::string::string(pp_Var2,local_3c);
    ppVar21 = g_decalTexIDs.
              super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
              ._M_impl._M_finish;
    local_94._M_impl._M_header._M_left = (_Base_ptr)diffuseId;
    if (g_decalTexIDs.
        super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
        ._M_impl._M_finish ==
        g_decalTexIDs.
        super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
        ._M_impl._M_end_of_storage) {
                    /* Unresolved local var: size_type __len@[???]
                       Unresolved local var: size_type __elems_before@[???]
                       Unresolved local var: pointer __new_start@[???]
                       Unresolved local var: pointer __new_finish@[???] */
      uVar18 = (int)g_decalTexIDs.
                    super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                    ._M_impl._M_finish -
               (int)g_decalTexIDs.
                    super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                    ._M_impl._M_start >> 3;
      uVar17 = 8;
      if (uVar18 != 0) {
        uVar17 = 0xfffffff8;
        if ((uVar18 <= uVar18 * 2) && (uVar18 * 2 < 0x20000000)) {
          uVar17 = uVar18 << 4;
        }
      }
      ppVar12 = operator_new(uVar17);
      ppVar7 = ppVar12 + uVar18;
      this = ppVar12;
      ppVar5 = g_decalTexIDs.
               super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
               ._M_impl._M_start;
      ppVar6 = g_decalTexIDs.
               super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
               ._M_impl._M_finish;
      if (ppVar7 != (pointer)0x0) {
        std::string::string(ppVar7,(string *)pp_Var2);
        ppVar7->second = (int)local_94._M_impl._M_header._M_left;
        ppVar5 = g_decalTexIDs.
                 super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                 ._M_impl._M_start;
        ppVar6 = g_decalTexIDs.
                 super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                 ._M_impl._M_finish;
      }
      for (; ppVar7 = ppVar6, ppVar21 != ppVar5; ppVar5 = ppVar5 + 1) {
        g_decalTexIDs.
        super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
        ._M_impl._M_finish = ppVar6;
        if (this != (pointer)0x0) {
          std::string::string(this,&ppVar5->first);
          this->second = ppVar5->second;
        }
        this = this + 1;
        ppVar6 = g_decalTexIDs.
                 super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                 ._M_impl._M_finish;
      }
                    /* Unresolved local var:
                       pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>
                       * __cur@[???] */
      for (; this = this + 1,
          ppVar5 = g_decalTexIDs.
                   super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                   ._M_impl._M_start,
          g_decalTexIDs.
          super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
          ._M_impl._M_finish = ppVar7, ppVar21 != ppVar6; ppVar21 = ppVar21 + 1) {
        if (this != (pointer)0x0) {
          std::string::string(this,&ppVar21->first);
          this->second = ppVar21->second;
        }
        ppVar7 = g_decalTexIDs.
                 super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                 ._M_impl._M_finish;
      }
      for (; ppVar7 != ppVar5; ppVar5 = ppVar5 + 1) {
        pcVar4 = (ppVar5->first)._M_dataplus._M_p;
        paVar25 = (allocator *)(pcVar4 + -0xc);
        if (paVar25 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
          LOCK();
          piVar1 = (int *)(pcVar4 + -4);
          iVar15 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (iVar15 < 1) {
            std::string::_Rep::_M_destroy(paVar25);
          }
        }
      }
      if (g_decalTexIDs.
          super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
          ._M_impl._M_start != (pointer)0x0) {
        operator_delete(g_decalTexIDs.
                        super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                        ._M_impl._M_start);
      }
      g_decalTexIDs.
      super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
      ._M_impl._M_end_of_storage = (pointer)((int)&(ppVar12->first)._M_dataplus._M_p + uVar17);
      g_decalTexIDs.
      super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
      ._M_impl._M_start = ppVar12;
      g_decalTexIDs.
      super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
      ._M_impl._M_finish = this;
    }
    else {
      ppVar7 = (pointer)0x0;
      if (g_decalTexIDs.
          super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
          ._M_impl._M_finish != (pointer)0x0) {
        std::string::string(g_decalTexIDs.
                            super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                            ._M_impl._M_finish,(string *)pp_Var2);
        ppVar21->second = (int)local_94._M_impl._M_header._M_left;
        ppVar7 = g_decalTexIDs.
                 super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                 ._M_impl._M_finish;
      }
      g_decalTexIDs.
      super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
      ._M_impl._M_finish = ppVar7 + 1;
    }
    if (&local_94._M_impl._M_header._M_parent[-1]._M_parent !=
        (_Base_ptr *)&std::string::_Rep::_S_empty_rep_storage) {
      LOCK();
      pp_Var2 = &local_94._M_impl._M_header._M_parent[-1]._M_right;
      p_Var10 = *pp_Var2;
      *pp_Var2 = (_Base_ptr)((int)&(*pp_Var2)[-1]._M_right + 3);
      UNLOCK();
      if ((int)p_Var10 < 1) {
        std::string::_Rep::_M_destroy
                  ((allocator *)&local_94._M_impl._M_header._M_parent[-1]._M_parent);
      }
    }
    if ((allocator *)((int)local_3c[0]._M_dataplus._M_p + -0xc) !=
        (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
      LOCK();
      piVar1 = (int *)((int)local_3c[0]._M_dataplus._M_p + -4);
      iVar15 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar15 < 1) {
        std::string::_Rep::_M_destroy((allocator *)((int)local_3c[0]._M_dataplus._M_p + -0xc));
      }
    }
  }
LAB_001de329:
  if ((allocator *)((int)local_4c[0]._M_dataplus._M_p + -0xc) ==
      (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
    return;
  }
  LOCK();
  pcVar19 = (code *)((int)local_4c[0]._M_dataplus._M_p + -4);
  iVar15 = *(int *)pcVar19;
  *(int *)pcVar19 = *(int *)pcVar19 + -1;
  UNLOCK();
  if (0 < iVar15) {
    return;
  }
  std::string::_Rep::_M_destroy((allocator *)((int)local_4c[0]._M_dataplus._M_p + -0xc));
  return;
  while (p_Var10 = p_Var9->_M_left, local_9c = p_Var9, p_Var9->_M_left != (_Base_ptr)0x0) {
LAB_001de24b:
    p_Var9 = p_Var10;
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???] */
    uVar18 = *(uint *)((code *)p_Var9[1]._M_color + -0xc);
    uVar14 = uVar17;
    if (uVar18 <= uVar17) {
      uVar14 = uVar18;
    }
    bVar22 = false;
    bVar23 = true;
    pcVar19 = (code *)p_Var9[1]._M_color;
    sVar20._M_dataplus._M_p = local_4c[0]._M_dataplus._M_p;
    do {
      if (uVar14 == 0) break;
      uVar14 = uVar14 - 1;
      bVar22 = (byte)*pcVar19 < (byte)*(code *)sVar20._M_dataplus._M_p;
      bVar23 = *pcVar19 == *(code *)sVar20._M_dataplus._M_p;
      pcVar19 = pcVar19 + (uint)bVar24 * -2 + 1;
      sVar20._M_dataplus._M_p =
           (_Alloc_hider)(char *)((int)sVar20._M_dataplus._M_p + (uint)bVar24 * -2 + 1);
    } while (bVar23);
                    /* Unresolved local var: difference_type __d@[???] */
    iVar15 = (int)(char)((!bVar22 && !bVar23) - bVar22);
    if (iVar15 == 0) {
      iVar15 = uVar18 - uVar17;
    }
    if (iVar15 < 0) {
      p_Var10 = p_Var9->_M_right;
      if (p_Var9->_M_right == (_Base_ptr)0x0) break;
      goto LAB_001de24b;
    }
  }
  if (local_9c != &g_detailLoadFailedMap._M_t._M_impl._M_header) {
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???] */
    uVar18 = *(uint *)((code *)local_9c[1]._M_color + -0xc);
    uVar14 = uVar17;
    if (uVar18 <= uVar17) {
      uVar14 = uVar18;
    }
    bVar22 = false;
    bVar23 = true;
    sVar20._M_dataplus._M_p = local_4c[0]._M_dataplus._M_p;
    pcVar19 = (code *)local_9c[1]._M_color;
    do {
      if (uVar14 == 0) break;
      uVar14 = uVar14 - 1;
      bVar22 = (byte)*(code *)sVar20._M_dataplus._M_p < (byte)*pcVar19;
      bVar23 = *(code *)sVar20._M_dataplus._M_p == *pcVar19;
      sVar20._M_dataplus._M_p =
           (_Alloc_hider)(char *)((int)sVar20._M_dataplus._M_p + (uint)bVar24 * -2 + 1);
      pcVar19 = pcVar19 + (uint)bVar24 * -2 + 1;
    } while (bVar23);
                    /* Unresolved local var: difference_type __d@[???] */
    iVar15 = (int)(char)((!bVar22 && !bVar23) - bVar22);
    if (iVar15 == 0) {
      iVar15 = uVar17 - uVar18;
    }
    if (-1 < iVar15) goto LAB_001de329;
  }
LAB_001de2b6:
                    /* Unresolved local var: iterator __j@[???] */
  if (g_detailNameToIdMap._M_t._M_impl._M_header._M_parent != (_Base_ptr)0x0) {
    uVar17 = *(uint *)((int)local_4c[0]._M_dataplus._M_p + -0xc);
    local_9c = &g_detailNameToIdMap._M_t._M_impl._M_header;
    p_Var10 = g_detailNameToIdMap._M_t._M_impl._M_header._M_parent;
    do {
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???] */
      uVar18 = *(uint *)((code *)p_Var10[1]._M_color + -0xc);
      uVar14 = uVar17;
      if (uVar18 <= uVar17) {
        uVar14 = uVar18;
      }
      bVar22 = false;
      bVar23 = true;
      pcVar19 = (code *)p_Var10[1]._M_color;
      sVar20._M_dataplus._M_p = local_4c[0]._M_dataplus._M_p;
      do {
        if (uVar14 == 0) break;
        uVar14 = uVar14 - 1;
        bVar22 = (byte)*pcVar19 < (byte)*(code *)sVar20._M_dataplus._M_p;
        bVar23 = *pcVar19 == *(code *)sVar20._M_dataplus._M_p;
        pcVar19 = pcVar19 + (uint)bVar24 * -2 + 1;
        sVar20._M_dataplus._M_p =
             (_Alloc_hider)(char *)((int)sVar20._M_dataplus._M_p + (uint)bVar24 * -2 + 1);
      } while (bVar23);
                    /* Unresolved local var: difference_type __d@[???] */
      iVar15 = (int)(char)((!bVar22 && !bVar23) - bVar22);
      if (iVar15 == 0) {
        iVar15 = uVar18 - uVar17;
      }
      if (iVar15 < 0) {
        p_Var9 = p_Var10->_M_right;
      }
      else {
        p_Var9 = p_Var10->_M_left;
        local_9c = p_Var10;
      }
      p_Var10 = p_Var9;
    } while (p_Var9 != (_Base_ptr)0x0);
    if (local_9c != &g_detailNameToIdMap._M_t._M_impl._M_header) {
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???] */
      uVar18 = *(uint *)((code *)local_9c[1]._M_color + -0xc);
      uVar14 = uVar17;
      if (uVar18 <= uVar17) {
        uVar14 = uVar18;
      }
      bVar22 = false;
      bVar23 = true;
      sVar20._M_dataplus._M_p = local_4c[0]._M_dataplus._M_p;
      pcVar19 = (code *)local_9c[1]._M_color;
      do {
        if (uVar14 == 0) break;
        uVar14 = uVar14 - 1;
        bVar22 = (byte)*(code *)sVar20._M_dataplus._M_p < (byte)*pcVar19;
        bVar23 = *(code *)sVar20._M_dataplus._M_p == *pcVar19;
        sVar20._M_dataplus._M_p =
             (_Alloc_hider)(char *)((int)sVar20._M_dataplus._M_p + (uint)bVar24 * -2 + 1);
        pcVar19 = pcVar19 + (uint)bVar24 * -2 + 1;
      } while (bVar23);
                    /* Unresolved local var: difference_type __d@[???] */
      iVar15 = (int)(char)((!bVar22 && !bVar23) - bVar22);
      if (iVar15 == 0) {
        iVar15 = uVar17 - uVar18;
      }
      if (-1 < iVar15) {
        ppDVar11 = g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>.
                   _M_impl._M_start + iVar16;
        (*ppDVar11)->_oglTextureId = diffuseId;
        (*ppDVar11)->_oglDetailId = (GLint)local_9c[1]._M_parent;
        local_50 = *ppDVar11;
        local_54 = diffuseId;
        std::
        _Rb_tree<int,_std::pair<const_int,_DetailMap*>,_std::_Select1st<std::pair<const_int,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<const_int,_DetailMap*>_>_>
        ::_M_insert_unique((_Rb_tree<int,_std::pair<const_int,_DetailMap*>,_std::_Select1st<std::pair<const_int,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<const_int,_DetailMap*>_>_>
                            *)this_00,__v);
        goto LAB_001de354;
      }
    }
  }
  GVar13 = loadTextureFile((char *)local_4c[0]._M_dataplus._M_p);
  if (GVar13 == -1) {
    Con_Printf("Detail texture map load failed: %s\n",local_4c[0]._M_dataplus._M_p);
    std::string::string(&local_64,local_4c);
    local_60 = 0;
    std::string::string(local_5c,&local_64);
    local_58 = local_60;
    std::
    _Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
    ::_M_insert_unique(&local_94,
                       (pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>
                        *)&g_detailLoadFailedMap);
    std::string::~string(local_5c);
    std::string::~string(&local_64);
  }
  else {
    ppDVar11 = g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl.
               _M_start + iVar16;
    (*ppDVar11)->_oglTextureId = diffuseId;
    (*ppDVar11)->_oglDetailId = GVar13;
    local_78 = *ppDVar11;
    local_7c = diffuseId;
    std::
    _Rb_tree<int,_std::pair<const_int,_DetailMap*>,_std::_Select1st<std::pair<const_int,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<const_int,_DetailMap*>_>_>
    ::_M_insert_unique((_Rb_tree<int,_std::pair<const_int,_DetailMap*>,_std::_Select1st<std::pair<const_int,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<const_int,_DetailMap*>_>_>
                        *)this_00,__v);
    std::string::string(&local_74,local_4c);
    local_70 = GVar13;
    std::string::string(local_6c,&local_74);
    local_68 = local_70;
    std::
    _Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
    ::_M_insert_unique(&local_94,
                       (pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>
                        *)&g_detailNameToIdMap);
    std::string::~string(local_6c);
    std::string::~string(&local_74);
  }
LAB_001de354:
  if ((allocator *)((int)local_4c[0]._M_dataplus._M_p + -0xc) !=
      (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
    LOCK();
    pcVar19 = (code *)((int)local_4c[0]._M_dataplus._M_p + -4);
    iVar15 = *(int *)pcVar19;
    *(int *)pcVar19 = *(int *)pcVar19 + -1;
    UNLOCK();
    if (iVar15 < 1) {
      std::string::_Rep::_M_destroy((allocator *)((int)local_4c[0]._M_dataplus._M_p + -0xc));
    }
  }
  return;
}


// DT_Parse  @ 001dd3d0
/* WARNING: Removing unreachable block (ram,0x001dd7af) */
/* WARNING: Removing unreachable block (ram,0x001dd7a4) */
/* WARNING: Removing unreachable block (ram,0x001dd801) */

void DT_Parse(char *pBuffer)

{
  code *pcVar1;
  void *__dest;
  pointer __src;
  DetailMap *this;
  pointer ppDVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  size_t sVar6;
  bool bVar7;
  double dVar8;
  float local_7c;
  float local_78;
  ParseState local_6c [4];
  char *local_5c [4];
  string local_4c [4];
  string local_3c [4];
  string local_2c [7];
  
                    /* Unresolved local var: ParseState state@[???]
                       Unresolved local var: char * cPtr@[???]
                       Unresolved local var: string diffuseName@[???]
                       Unresolved local var: string detailName@[???]
                       Unresolved local var: string scaleFactorString@[???]
                       Unresolved local var: float sScaleFactor@[???]
                       Unresolved local var: float tScaleFactor@[???] */
  local_6c[0] = PS_START;
  local_2c[0]._M_dataplus._M_p = (_Alloc_hider)glViewport;
  local_4c[0]._M_dataplus._M_p = (_Alloc_hider)glViewport;
  local_3c[0]._M_dataplus._M_p = (_Alloc_hider)glViewport;
  do {
    if (local_6c[0] - PS_ERROR < 2) {
      if (local_6c[0] == PS_ERROR) {
        Con_Printf("Error parsing detail texture file.\n");
      }
      if ((allocator *)((int)local_2c[0]._M_dataplus._M_p + -0xc) !=
          (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
        LOCK();
        pcVar1 = (code *)((int)local_2c[0]._M_dataplus._M_p + -4);
        iVar4 = *(int *)pcVar1;
        *(int *)pcVar1 = *(int *)pcVar1 + -1;
        UNLOCK();
        if (iVar4 < 1) {
          std::string::_Rep::_M_destroy((allocator *)((int)local_2c[0]._M_dataplus._M_p + -0xc));
        }
      }
      if ((allocator *)((int)local_3c[0]._M_dataplus._M_p + -0xc) !=
          (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
        LOCK();
        pcVar1 = (code *)((int)local_3c[0]._M_dataplus._M_p + -4);
        iVar4 = *(int *)pcVar1;
        *(int *)pcVar1 = *(int *)pcVar1 + -1;
        UNLOCK();
        if (iVar4 < 1) {
          std::string::_Rep::_M_destroy((allocator *)((int)local_3c[0]._M_dataplus._M_p + -0xc));
        }
      }
      if ((allocator *)((int)local_4c[0]._M_dataplus._M_p + -0xc) !=
          (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
        LOCK();
        pcVar1 = (code *)((int)local_4c[0]._M_dataplus._M_p + -4);
        iVar4 = *(int *)pcVar1;
        *(int *)pcVar1 = *(int *)pcVar1 + -1;
        UNLOCK();
        if (iVar4 < 1) {
          std::string::_Rep::_M_destroy((allocator *)((int)local_4c[0]._M_dataplus._M_p + -0xc));
        }
      }
      return;
    }
switchD_001dd41d_switchD:
    switch(local_6c[0]) {
    case PS_START:
      local_6c[0] = PS_DIFFUSE_NAME;
      local_5c[0] = pBuffer;
      break;
    case PS_DIFFUSE_NAME:
      bVar7 = DT_GetToken(local_5c,local_6c,local_4c);
      if (bVar7) {
        local_6c[0] = PS_DETAIL_TEXTURE;
      }
      break;
    case PS_DETAIL_TEXTURE:
      bVar7 = DT_GetToken(local_5c,local_6c,local_3c);
      if (bVar7) {
        local_6c[0] = PS_S_SCALE_FACTOR;
      }
      break;
    case PS_S_SCALE_FACTOR:
      bVar7 = DT_GetToken(local_5c,local_6c,local_2c);
      if (bVar7) {
        dVar8 = strtod((char *)local_2c[0]._M_dataplus._M_p,(char **)0x0);
        local_7c = (float)dVar8;
        local_6c[0] = PS_T_SCALE_FACTOR;
      }
      break;
    case PS_T_SCALE_FACTOR:
      bVar7 = DT_GetToken(local_5c,local_6c,local_2c);
      if (bVar7) {
        dVar8 = strtod((char *)local_2c[0]._M_dataplus._M_p,(char **)0x0);
        local_78 = (float)dVar8;
        local_6c[0] = PS_ENTRY;
      }
      break;
    case PS_ENTRY:
      this = operator_new(0x18);
      std::string::string(this,local_4c);
      std::string::string(&this->_detailName,local_3c);
      __src = g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl.
              _M_finish;
      this->_oglTextureId = 0;
      this->_oglDetailId = 0;
      this->_sScale = local_7c;
      bVar7 = __src == g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>.
                       _M_impl._M_end_of_storage;
      this->_tScale = local_78;
      if (bVar7) {
                    /* Unresolved local var: size_type __len@[???]
                       Unresolved local var: size_type __elems_before@[???]
                       Unresolved local var: pointer __new_start@[DW_OP_breg4(ESP): +40]
                       Unresolved local var: pointer __new_finish@[???] */
        uVar5 = 4;
        uVar3 = (int)__src -
                (int)g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>.
                     _M_impl._M_start >> 2;
        if (uVar3 != 0) {
          if ((uVar3 * 2 < uVar3) || (0x3fffffff < uVar3 * 2)) {
            uVar5 = 0xfffffffc;
          }
          else {
            uVar5 = uVar3 * 8;
          }
        }
        ppDVar2 = operator_new(uVar5);
        if (ppDVar2 + uVar3 != (pointer)0x0) {
          ppDVar2[uVar3] = this;
        }
                    /* Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
        sVar6 = 0;
        iVar4 = (int)__src -
                (int)g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>.
                     _M_impl._M_start >> 2;
        if (iVar4 != 0) {
          sVar6 = iVar4 * 4;
          memmove(ppDVar2,g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>
                          ._M_impl._M_start,sVar6);
        }
        __dest = (void *)((int)ppDVar2 + sVar6 + 4);
                    /* Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
        sVar6 = 0;
        iVar4 = (int)g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>.
                     _M_impl._M_finish - (int)__src >> 2;
        if (iVar4 != 0) {
          sVar6 = iVar4 * 4;
          memmove(__dest,__src,sVar6);
        }
        if (g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl.
            _M_start != (pointer)0x0) {
          operator_delete(g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>
                          ._M_impl._M_start);
        }
        g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl.
        _M_end_of_storage = (pointer)(uVar5 + (int)ppDVar2);
        g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl._M_start
             = ppDVar2;
        g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl._M_finish
             = (pointer)(sVar6 + (int)__dest);
      }
      else {
        ppDVar2 = (pointer)0x0;
        if (__src != (pointer)0x0) {
          *__src = this;
          ppDVar2 = g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>.
                    _M_impl._M_finish;
        }
        g_detailVector.super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>._M_impl._M_finish
             = ppDVar2 + 1;
      }
      local_6c[0] = PS_DIFFUSE_NAME;
      break;
    default:
      goto switchD_001dd41d_switchD;
    }
  } while( true );
}


// DT_SetRenderState  @ 001de8d0
/* WARNING: Removing unreachable block (ram,0x001deb6a) */
/* WARNING: Removing unreachable block (ram,0x001deb72) */
/* WARNING: Removing unreachable block (ram,0x001debc3) */
/* WARNING: Removing unreachable block (ram,0x001debd0) */
/* WARNING: Removing unreachable block (ram,0x001deba7) */
/* WARNING: Removing unreachable block (ram,0x001debbe) */

int DT_SetRenderState(int diffuseId)

{
  _Base_ptr *pp_Var1;
  int *piVar2;
  pointer ppVar3;
  _Base_ptr p_Var4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  _Base_ptr p_Var8;
  _Base_ptr p_Var9;
  int iVar10;
  uint uVar11;
  char *local_28;
  int local_24;
  
                    /* Unresolved local var: DetailMap * pDetail@[???]
                       Unresolved local var: iterator iter@[???]
                       Unresolved local var: bool bind@[???]
                       Unresolved local var: bool scale@[???] */
  iVar7 = 0;
  if ((detTexSupported) && (r_detailtextures.value != 0.0)) {
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
        uVar11 = 0;
        do {
                    /* Unresolved local var:
                       pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>
                       p@[???] */
          ppVar3 = g_decalTexIDs.
                   super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
                   ._M_impl._M_start + uVar11;
          std::string::string(&local_28,&ppVar3->first);
          local_24 = ppVar3->second;
          DT_LoadDetailTexture(local_28,local_24);
          if ((allocator *)(local_28 + -0xc) !=
              (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
            LOCK();
            piVar2 = (int *)(local_28 + -4);
            iVar7 = *piVar2;
            *piVar2 = *piVar2 + -1;
            UNLOCK();
            if (iVar7 < 1) {
              std::string::_Rep::_M_destroy((allocator *)(local_28 + -0xc));
            }
          }
          uVar11 = uVar11 + 1;
        } while (uVar11 < (uint)((int)g_decalTexIDs.
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
    iVar7 = 0;
    if (g_idMap._M_t._M_impl._M_header._M_parent != (_Base_ptr)0x0) {
      p_Var8 = &g_idMap._M_t._M_impl._M_header;
      p_Var4 = g_idMap._M_t._M_impl._M_header._M_parent;
      do {
        while (p_Var9 = p_Var4, diffuseId <= (int)p_Var9[1]._M_color) {
          p_Var8 = p_Var9;
          p_Var4 = p_Var9->_M_left;
          if (p_Var9->_M_left == (_Base_ptr)0x0) goto LAB_001de93d;
        }
        pp_Var1 = &p_Var9->_M_right;
        p_Var9 = p_Var8;
        p_Var4 = *pp_Var1;
      } while (*pp_Var1 != (_Base_ptr)0x0);
LAB_001de93d:
      iVar10 = 0;
      iVar7 = 0;
      if ((((p_Var9 != &g_idMap._M_t._M_impl._M_header) &&
           (iVar7 = iVar10, (int)p_Var9[1]._M_color <= diffuseId)) &&
          (p_Var8 = p_Var9[1]._M_parent, p_Var8[1]._M_parent != (_Base_ptr)0x0)) &&
         (p_Var8[1]._M_color != _S_red)) {
        (*qglSelectTextureSGIS)(TEXTURE2_SGIS);
        (*qglEnable)(0xde1);
        p_Var4 = p_Var8[1]._M_parent;
        if ((lastDetTex == -1) || ((_Base_ptr)lastDetTex != p_Var4)) {
          bVar6 = true;
          lastDetTex = (GLint)p_Var4;
        }
        else {
          bVar6 = false;
        }
        if (((float)p_Var8->_M_left != lastDetSScale) ||
           (bVar5 = false, (float)p_Var8->_M_right != lastDetTScale)) {
          bVar5 = true;
          lastDetSScale = (GLfloat)p_Var8->_M_left;
          lastDetTScale = (GLfloat)p_Var8->_M_right;
        }
        if (bVar6) {
          (*qglBindTexture)(0xde1,(GLuint)p_Var4);
        }
        iVar7 = 1;
        if (bVar5) {
          (*qglMatrixMode)(0x1702);
          (*qglLoadIdentity)();
          (*qglScalef)((GLfloat)p_Var8->_M_left,(GLfloat)p_Var8->_M_right,1.0);
          (*qglMatrixMode)(0x1700);
          iVar7 = 1;
        }
      }
    }
  }
  return iVar7;
}


// DT_SetTextureCoordinates  @ 001dda60
void DT_SetTextureCoordinates(float u,float v)

{
  (*qglMTexCoord2fSGIS)(TEXTURE2_SGIS,u,v);
  return;
}


