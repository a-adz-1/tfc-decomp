// CVideoMode_Common::AddMode  @ 001c26b0
/* DWARF original prototype: bool AddMode(CVideoMode_Common * this, int width, int height, int bpp)
    */

bool __thiscall CVideoMode_Common::AddMode(CVideoMode_Common *this,int width,int height,int bpp)

{
  int iVar1;
  vmode_t *pvVar2;
  
                    /* Unresolved local var: vmode_t * mode@[???] */
  iVar1 = this->m_nNumModes;
  if (0x1f < iVar1) {
    return false;
  }
                    /* Unresolved local var: int i@[???] */
  if (0 < iVar1) {
    pvVar2 = this->m_rgModeList;
    do {
                    /* Unresolved local var: vmode_t * mode@[???] */
      if (((pvVar2->width == width) && (pvVar2->height == height)) && (pvVar2->bpp == bpp)) {
        return true;
      }
      pvVar2 = pvVar2 + 1;
    } while (pvVar2 != this->m_rgModeList + iVar1);
  }
  this->m_nNumModes = iVar1 + 1;
  this->m_rgModeList[iVar1].width = width;
  this->m_rgModeList[iVar1].height = height;
  this->m_rgModeList[iVar1].bpp = bpp;
  return true;
}


// CVideoMode_Common::AdjustWindowForMode  @ 001c2d70
/* DWARF original prototype: void AdjustWindowForMode(CVideoMode_Common * this) */

void __thiscall CVideoMode_Common::AdjustWindowForMode(CVideoMode_Common *this)

{
  _func_int_varargs **pp_Var1;
  _func_int_varargs *p_Var2;
  char cVar3;
  int iVar4;
  vmode_t *pvVar5;
  int iVar6;
  int iVar7;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  RECT local_2c;
  
                    /* Unresolved local var: vmode_t * mode@[???]
                       Unresolved local var: RECT WindowRect@[???] */
  pp_Var1 = (this->super_IVideoMode)._vptr_IVideoMode;
  p_Var2 = pp_Var1[5];
  if (p_Var2 == GetCurrentMode) {
    p_Var2 = pp_Var1[6];
    iVar6 = this->m_nGameMode;
    if (p_Var2 == GetMode) {
      if ((this->m_nNumModes <= iVar6) || (pvVar5 = this->m_rgModeList + iVar6, iVar6 < 0)) {
        pvVar5 = &this->m_safeMode;
      }
    }
    else {
      pvVar5 = (vmode_t *)(*p_Var2)(this,iVar6);
    }
  }
  else {
    pvVar5 = (vmode_t *)(*p_Var2)(this);
  }
  Snd_ReleaseBuffer();
  vid.width = pvVar5->width;
  vid.height = pvVar5->height;
  p_Var2 = (this->super_IVideoMode)._vptr_IVideoMode[8];
  if (p_Var2 == IsWindowedMode) {
    cVar3 = this->m_bWindowed;
  }
  else {
    iVar6 = (*p_Var2)(this);
    cVar3 = (char)iVar6;
  }
  if (cVar3 == '\0') {
    iVar6 = pvVar5->width;
    iVar7 = pvVar5->height;
    (*(this->super_IVideoMode)._vptr_IVideoMode[0x13])(this);
    iVar4 = (*game->_vptr_IGame[6])(game);
    SDL_SetWindowPosition(iVar4,0,0);
  }
  else {
    iVar6 = this->m_rgModeList[this->m_nGameMode].width;
    iVar7 = this->m_rgModeList[this->m_nGameMode].height;
  }
                    /* Unresolved local var: int CenterX@[???]
                       Unresolved local var: int CenterY@[???]
                       Unresolved local var: SDL_Rect rect@[???]
                       Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???] */
  (*game->_vptr_IGame[9])(game,iVar6,iVar7);
  iVar4 = (*game->_vptr_IGame[6])(game);
  SDL_GetDisplayBounds(0,&local_2c);
  iVar6 = (local_2c.top - iVar6) / 2;
  if (iVar6 < 0) {
    iVar6 = 0;
  }
  iVar7 = (local_2c.bottom - iVar7) / 2;
  if (iVar7 < 0) {
    iVar7 = 0;
  }
  (*game->_vptr_IGame[8])(game,iVar6,iVar7);
  SDL_SetWindowPosition(iVar4,iVar6,iVar7);
  Snd_AcquireBuffer();
  VOX_Init();
  p_Var2 = (this->super_IVideoMode)._vptr_IVideoMode[0xb];
  if (p_Var2 == UpdateWindowPosition) {
                    /* Unresolved local var: RECT window_rect@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int cx@[???]
                       Unresolved local var: int cy@[???] */
    (*game->_vptr_IGame[10])(game,&local_3c,&local_38,&local_34,&local_30);
    local_2c.left = local_3c;
    local_2c.right = local_3c + local_34;
    local_2c.top = local_38;
    local_2c.bottom = local_38 + local_30;
    VID_UpdateWindowVars(&local_2c,local_34 / 2 + local_3c,local_30 / 2 + local_38);
    return;
  }
  (*p_Var2)(this);
  return;
}


// CVideoMode_Common::CVideoMode_Common  @ 001c4700
/* DWARF original prototype: void CVideoMode_Common(CVideoMode_Common * this) */

void __thiscall CVideoMode_Common::CVideoMode_Common(CVideoMode_Common *this)

{
  undefined1 local_20 [4];
  int local_1c;
  int local_18;
  
  (this->m_ImageID).m_Size = 0;
                    /* Unresolved local var: SDL_DisplayMode.conflict mode@[???] */
  this->m_nNumModes = 0;
  this->m_nGameMode = 0;
  (this->super_IVideoMode)._vptr_IVideoMode = (_func_int_varargs **)&PTR___cxa_pure_virtual_002700b8
  ;
  (this->m_ImageID).m_Memory.m_pMemory = (bimage_t *)0x0;
  (this->m_ImageID).m_Memory.m_NumAllocated = 0;
  (this->m_ImageID).m_Memory.m_GrowSize = 0;
  this->m_bWindowed = false;
  this->m_bInitialized = false;
  SDL_GetDesktopDisplayMode(0,local_20);
  (this->m_safeMode).width = local_1c;
  (this->m_safeMode).height = local_18;
  (this->m_safeMode).bpp = 0x20;
  return;
}


// CVideoMode_Common::CalculatePixelAspect  @ 001c42f0
float CVideoMode_Common::CalculatePixelAspect(uint width,uint height)

{
  if (width < 0x280) {
    return ((float)height / (float)(int)width) * 1.3333334;
  }
  return 1.0;
}


// CVideoMode_Common::CenterEngineWindow  @ 001c3030
/* DWARF original prototype: void CenterEngineWindow(CVideoMode_Common * this, HWND hWndCenter, int
   width, int height) */

void __thiscall
CVideoMode_Common::CenterEngineWindow(CVideoMode_Common *this,HWND hWndCenter,int width,int height)

{
  int iVar1;
  int iVar2;
  undefined1 local_1c [8];
  int local_14;
  int local_10;
  
                    /* Unresolved local var: int CenterX@[???]
                       Unresolved local var: int CenterY@[???]
                       Unresolved local var: SDL_Rect rect@[???]
                       Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???] */
  SDL_GetDisplayBounds(0,local_1c);
  iVar1 = (local_14 - width) / 2;
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  iVar2 = (local_10 - height) / 2;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  (*game->_vptr_IGame[8])(game,iVar1,iVar2);
  SDL_SetWindowPosition(hWndCenter,iVar1,iVar2);
  return;
}


// CVideoMode_Common::DrawStartupGraphic  @ 001c3990
/* DWARF original prototype: void DrawStartupGraphic(CVideoMode_Common * this, HWND window) */

void __thiscall CVideoMode_Common::DrawStartupGraphic(CVideoMode_Common *this,HWND window)

{
  bimage_t *pbVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  byte *pbVar17;
  byte bVar18;
  float fVar19;
  double dVar20;
  int local_68;
  int local_5c;
  void *local_58;
  int local_54;
  int local_48;
  float local_40;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: vmode_t localMode@[???]
                       Unresolved local var: int width@[???]
                       Unresolved local var: int height@[???]
                       Unresolved local var: vmode_t * mode@[???]
                       Unresolved local var: CUtlVector<unsigned_int> vecGLTex@[???]
                       Unresolved local var: float fSrcAspect@[???]
                       Unresolved local var: float fDstAspect@[???]
                       Unresolved local var: int srcWide@[???]
                       Unresolved local var: int srcTall@[???]
                       Unresolved local var: float flXDiff@[???]
                       Unresolved local var: float flYDiff@[???]
                       Unresolved local var: float xScale@[???]
                       Unresolved local var: float yScale@[???]
                       Unresolved local var: float fitScale@[???]
                       Unresolved local var: float fitAdjWidth@[???]
                       Unresolved local var: float fitAdjHeight@[???]
                       Unresolved local var: int fitOffsetX@[???]
                       Unresolved local var: int fitOffsetY@[???] */
  bVar18 = 0;
  if ((this->m_ImageID).m_Size != 0) {
    SDL_GetWindowSize(window,&local_24,local_20);
    glViewport(0,0,local_24,local_20[0]);
    glDisable(0xb71);
    glEnable(0xde1);
    glMatrixMode(0x1701);
    glOrtho(0,0,(double)local_24,(double)local_20[0],0,0,0,0xbff00000,0,0x3ff00000);
    glClearColor(0,0,0,0);
    glClear(0x4000);
    fVar19 = (float)this->m_iBaseResX;
    fVar2 = (float)local_24 / fVar19;
    iVar12 = this->m_iBaseResY;
    fVar4 = (float)local_20[0] / (float)iVar12;
    fVar3 = fVar4 * fVar19;
    local_40 = fVar4;
    if (fVar3 < (float)local_24) {
      fVar3 = fVar19 * fVar2;
      local_40 = fVar2;
    }
                    /* Unresolved local var: int x@[???] */
    local_68 = 0;
    if ((this->m_ImageID).m_Size < 1) {
LAB_001c4285:
      local_58 = (void *)0x0;
    }
    else {
      local_48 = 0;
      local_58 = (void *)0x0;
      do {
                    /* Unresolved local var: bimage_t * bimage@[???]
                       Unresolved local var: int dx@[???]
                       Unresolved local var: int dy@[???]
                       Unresolved local var: int dw@[???]
                       Unresolved local var: int dt@[???]
                       Unresolved local var: GLuint * tex@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: long * pExpanded@[???]
                       Unresolved local var: long * pToUse@[???]
                       Unresolved local var: int wide2@[???]
                       Unresolved local var: int tall2@[???]
                       Unresolved local var: float topv@[???]
                       Unresolved local var: float topu@[???] */
        iVar9 = local_68;
        pbVar1 = (this->m_ImageID).m_Memory.m_pMemory + local_68;
        if (pbVar1->scaled == false) {
          iVar5 = pbVar1->x;
          if (pbVar1->fit == false) {
            local_5c = 0;
            if (iVar5 != 0) {
              dVar20 = ceil((double)iVar5);
              local_5c = (int)dVar20;
            }
            local_54 = 0;
            if (pbVar1->y != 0) {
              dVar20 = ceil((double)pbVar1->y);
              local_54 = (int)dVar20;
            }
            iVar5 = local_5c + pbVar1->width;
            iVar6 = local_54 + pbVar1->height;
          }
          else {
            local_5c = 0;
            if (iVar5 != 0) {
              fVar19 = ceilf((float)iVar5 * local_40);
              local_5c = (int)fVar19;
            }
            local_5c = local_5c + (local_24 / 2 - (int)(fVar3 * 0.5));
            local_54 = 0;
            if (pbVar1->y != 0) {
              fVar19 = ceilf((float)pbVar1->y * local_40);
              local_54 = (int)fVar19;
            }
            local_54 = local_54 + (local_20[0] / 2 - (int)(local_40 * (float)iVar12 * 0.5));
            fVar19 = ceilf((float)pbVar1->width * local_40);
            iVar5 = (int)fVar19 + local_5c;
            fVar19 = ceilf((float)pbVar1->height * local_40);
            iVar6 = (int)fVar19 + local_54;
          }
        }
        else {
          iVar5 = pbVar1->x;
          local_5c = 0;
          if (iVar5 != 0) {
            fVar19 = ceilf((float)iVar5 * fVar2);
            local_5c = (int)fVar19;
          }
          iVar6 = pbVar1->y;
          local_54 = 0;
          if (iVar6 != 0) {
            fVar19 = ceilf((float)iVar6 * fVar4);
            local_54 = (int)fVar19;
          }
          fVar19 = ceilf((float)(iVar5 + pbVar1->width) * fVar2);
          iVar5 = (int)fVar19;
          fVar19 = ceilf((float)(iVar6 + pbVar1->height) * fVar4);
          iVar6 = (int)fVar19;
        }
        if (local_48 < local_68 + 1) {
                    /* Unresolved local var: int nNeed@[???]
                       Unresolved local var: int nGrowSize@[???]
                       Unresolved local var: int growSize@[???] */
          local_68 = local_68 + 1;
          local_48 = local_68;
          if (local_58 == (void *)0x0) {
            local_58 = malloc(local_68 * 4);
          }
          else {
            local_58 = realloc(local_58,local_68 * 4);
          }
        }
        local_68 = iVar9 + 1;
        glGenTextures(1);
        glBindTexture(0xde1);
        glTexParameteri(0xde1,0x2800,0x2601);
        glTexParameteri(0xde1,0x2801,0x2601);
        glTexParameteri(0xde1,0x2802,0x812f);
        glTexParameteri(0xde1,0x2803,0x812f);
        glPixelStorei(0xcf5);
        iVar9 = 0;
        do {
          iVar13 = 1 << ((byte)iVar9 & 0x1f);
          if (pbVar1->width <= iVar13) break;
          iVar9 = iVar9 + 1;
        } while (iVar9 != 0x20);
        iVar9 = 0;
        do {
          iVar16 = 1 << ((byte)iVar9 & 0x1f);
          if (pbVar1->height <= iVar16) {
            if ((pbVar1->height == iVar16) && (pbVar1->width == iVar13)) {
              pbVar7 = pbVar1->buffer;
              pbVar17 = (byte *)0x0;
              goto LAB_001c3f1b;
            }
            break;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 != 0x20);
        if (0x1fc00000 < (uint)(iVar16 * iVar13)) {
          __cxa_throw_bad_array_new_length();
          goto LAB_001c4285;
        }
        uVar11 = iVar16 * iVar13 * 4;
        pbVar7 = operator_new__(uVar11);
        if (pbVar7 == (byte *)0x0) goto LAB_001c4116;
        pbVar17 = pbVar7;
        if (7 < uVar11) {
          uVar10 = uVar11;
          if (((uint)pbVar7 & 1) != 0) {
            *pbVar7 = '\0';
            pbVar17 = pbVar7 + 1;
            uVar10 = uVar11 - 1;
          }
          if (((uint)pbVar17 & 2) != 0) {
            pbVar17[0] = '\0';
            pbVar17[1] = '\0';
            uVar10 = uVar10 - 2;
            pbVar17 = pbVar17 + 2;
          }
          if (((uint)pbVar17 & 4) != 0) {
            pbVar17[0] = '\0';
            pbVar17[1] = '\0';
            pbVar17[2] = '\0';
            pbVar17[3] = '\0';
            uVar10 = uVar10 - 4;
            pbVar17 = pbVar17 + 4;
          }
          uVar11 = uVar10 & 3;
          for (uVar10 = uVar10 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            pbVar17[0] = '\0';
            pbVar17[1] = '\0';
            pbVar17[2] = '\0';
            pbVar17[3] = '\0';
            pbVar17 = pbVar17 + ((uint)bVar18 * -2 + 1) * 4;
          }
        }
        if ((uVar11 & 4) != 0) {
          pbVar17[0] = '\0';
          pbVar17[1] = '\0';
          pbVar17[2] = '\0';
          pbVar17[3] = '\0';
          pbVar17 = pbVar17 + 4;
        }
        if ((uVar11 & 2) != 0) {
          pbVar17[0] = '\0';
          pbVar17[1] = '\0';
          pbVar17 = pbVar17 + 2;
        }
        if ((uVar11 & 1) != 0) {
          *pbVar17 = '\0';
        }
                    /* Unresolved local var: int y@[???] */
        iVar9 = pbVar1->height;
        pbVar17 = pbVar7;
        if (0 < iVar9) {
          iVar8 = pbVar1->width;
          iVar14 = 0;
          iVar15 = 0;
          do {
                    /* Unresolved local var: int x@[???] */
            if (0 < iVar8) {
              iVar9 = 0;
              do {
                *(undefined4 *)(pbVar7 + (iVar14 + iVar9) * 4) =
                     *(undefined4 *)(pbVar1->buffer + (iVar8 * iVar15 + iVar9) * 4);
                iVar9 = iVar9 + 1;
                iVar8 = pbVar1->width;
              } while (iVar9 < iVar8);
              iVar9 = pbVar1->height;
            }
            iVar15 = iVar15 + 1;
            iVar14 = iVar14 + iVar13;
          } while (iVar15 < iVar9);
        }
LAB_001c3f1b:
        glTexImage2D(0xde1,0,0x1908,iVar13,iVar16,0,0x1908,0x1401,pbVar7);
        if (pbVar17 == (byte *)0x0) {
          fVar19 = 1.0;
        }
        else {
          fVar19 = (float)pbVar1->width / (float)iVar13;
          operator_delete__(pbVar17);
        }
        glBegin(7);
        glTexCoord2f(0);
        glVertex3i(local_5c,iVar6,0);
        glTexCoord2f(fVar19);
        glVertex3i(iVar5,iVar6,0);
        glTexCoord2f(fVar19);
        glVertex3i(iVar5,local_54,0);
        glTexCoord2f(0);
        glVertex3i(local_5c,local_54,0);
        glEnd();
      } while (local_68 < (this->m_ImageID).m_Size);
    }
    SDL_GL_SwapWindow(window);
    iVar12 = 0;
    if (0 < local_68) {
      do {
        glDeleteTextures(1);
        iVar12 = iVar12 + 1;
      } while (local_68 != iVar12);
    }
    iVar9 = 0;
    iVar12 = (this->m_ImageID).m_Size;
    if (0 < iVar12) {
      do {
        pbVar7 = (this->m_ImageID).m_Memory.m_pMemory[iVar9].buffer;
        if (pbVar7 != (byte *)0x0) {
          free(pbVar7);
          iVar12 = (this->m_ImageID).m_Size;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar12);
    }
    iVar12 = (this->m_ImageID).m_Memory.m_GrowSize;
    (this->m_ImageID).m_Size = 0;
    if (-1 < iVar12) {
      pbVar1 = (this->m_ImageID).m_Memory.m_pMemory;
      if (pbVar1 != (bimage_t *)0x0) {
        free(pbVar1);
        (this->m_ImageID).m_Memory.m_pMemory = (bimage_t *)0x0;
      }
      (this->m_ImageID).m_Memory.m_NumAllocated = 0;
    }
LAB_001c4116:
    if (local_58 != (void *)0x0) {
      free(local_58);
      return;
    }
  }
  return;
}


// CVideoMode_Common::GetCurrentMode  @ 001c2950
/* DWARF original prototype: vmode_t * GetCurrentMode(CVideoMode_Common * this) */

vmode_t * __thiscall CVideoMode_Common::GetCurrentMode(CVideoMode_Common *this)

{
  _func_int_varargs *p_Var1;
  int iVar2;
  vmode_t *pvVar3;
  
  p_Var1 = (this->super_IVideoMode)._vptr_IVideoMode[6];
  iVar2 = this->m_nGameMode;
  if (p_Var1 != GetMode) {
    pvVar3 = (vmode_t *)(*p_Var1)(this,iVar2);
    return pvVar3;
  }
  if ((iVar2 < this->m_nNumModes) && (-1 < iVar2)) {
    return this->m_rgModeList + iVar2;
  }
  return &this->m_safeMode;
}


// CVideoMode_Common::GetInitialized  @ 001c2680
/* DWARF original prototype: bool GetInitialized(CVideoMode_Common * this) */

bool __thiscall CVideoMode_Common::GetInitialized(CVideoMode_Common *this)

{
  return this->m_bInitialized;
}


// CVideoMode_Common::GetMode  @ 001c2730
/* DWARF original prototype: vmode_t * GetMode(CVideoMode_Common * this, int num) */

vmode_t * __thiscall CVideoMode_Common::GetMode(CVideoMode_Common *this,int num)

{
  if ((num < this->m_nNumModes) && (-1 < num)) {
    return this->m_rgModeList + num;
  }
  return &this->m_safeMode;
}


// CVideoMode_Common::GetModeCount  @ 001c2760
/* DWARF original prototype: int GetModeCount(CVideoMode_Common * this) */

int __thiscall CVideoMode_Common::GetModeCount(CVideoMode_Common *this)

{
  return this->m_nNumModes;
}


// CVideoMode_Common::Init  @ 001c34f0
/* DWARF original prototype: bool Init(CVideoMode_Common * this, void * pvInstance) */

bool __thiscall CVideoMode_Common::Init(CVideoMode_Common *this,void *pvInstance)

{
  _func_int_varargs *p_Var1;
  _func_int_varargs **pp_Var2;
  IRegistry *pIVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  vmode_t *pvVar9;
  int iVar10;
  int iVar11;
  undefined1 local_40 [8];
  int local_38;
  int local_34;
  undefined1 local_30 [4];
  int local_2c;
  int local_28;
  
                    /* Unresolved local var: SDL_DisplayMode.conflict mode@[???]
                       Unresolved local var: int desktopW@[???]
                       Unresolved local var: int desktopH@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int bitsperpixel@[???]
                       Unresolved local var: int maxbits@[???]
                       Unresolved local var: int iOK@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: bool bAllowForceRes@[???] */
  iVar5 = (*game->_vptr_IGame[4])(game);
  if ((char)iVar5 == '\0') {
    return false;
  }
                    /* Unresolved local var: SDL_DisplayMode.conflict mode@[???]
                       Unresolved local var: int desktopW@[???]
                       Unresolved local var: int desktopH@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int bitsperpixel@[???]
                       Unresolved local var: int maxbits@[???]
                       Unresolved local var: int iOK@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: bool bAllowForceRes@[???] */
  SDL_GetDesktopDisplayMode(0,local_30);
  (this->m_safeMode).bpp = 0x20;
  pIVar3 = registry;
  (this->m_safeMode).width = local_2c;
  (this->m_safeMode).height = local_28;
  iVar6 = (*pIVar3->_vptr_IRegistry[2])(pIVar3,"DisplayWidth",local_2c);
  iVar7 = (*registry->_vptr_IRegistry[2])(registry,"DisplayHeight",local_28);
  (*registry->_vptr_IRegistry[2])(registry,"DisplayBPP",0x20);
  COM_CheckParm("-16bpp");
  COM_CheckParm("-24bpp");
  COM_CheckParm("-32bpp");
  p_Var1 = (this->super_IVideoMode)._vptr_IVideoMode[0x11];
  if (p_Var1 != MaxBitsPerPixel) {
    (*p_Var1)(this);
  }
  this->m_nNumModes = 0;
  SetupSDLVideoModes();
  if (1 < this->m_nNumModes) {
    qsort(this->m_rgModeList,this->m_nNumModes,0xc,VideoModeCompare);
  }
  iVar8 = COM_CheckParm("-width");
  if (iVar8 != 0) {
    iVar6 = strtol(com_argv[iVar8 + 1],(char **)0x0,10);
  }
  iVar8 = COM_CheckParm("-w");
  if (iVar8 == 0) {
    iVar8 = COM_CheckParm("-height");
  }
  else {
    iVar6 = strtol(com_argv[iVar8 + 1],(char **)0x0,10);
    iVar8 = COM_CheckParm("-height");
  }
  if (iVar8 == 0) {
    iVar8 = COM_CheckParm("-h");
  }
  else {
    iVar7 = strtol(com_argv[iVar8 + 1],(char **)0x0,10);
    iVar8 = COM_CheckParm("-h");
  }
  if (iVar8 != 0) {
    iVar7 = strtol(com_argv[iVar8 + 1],(char **)0x0,10);
  }
  p_Var1 = (this->super_IVideoMode)._vptr_IVideoMode[8];
  if (p_Var1 == IsWindowedMode) {
    cVar4 = this->m_bWindowed;
  }
  else {
    iVar8 = (*p_Var1)(this);
    cVar4 = (char)iVar8;
  }
                    /* Unresolved local var: SDL_Rect rect@[???] */
  if ((cVar4 != '\0') && (iVar8 = SDL_GetDisplayBounds(0,local_40), iVar8 == 0)) {
                    /* Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???] */
    if (local_38 < iVar6) {
      iVar6 = local_38;
    }
    if (local_34 < iVar7) {
      iVar7 = local_34;
    }
  }
  if ((0 < iVar6) && (iVar7 < 0)) {
    iVar7 = (int)((float)iVar6 * 3.0 * 0.25);
  }
  if (this->m_nNumModes < 1) {
    iVar8 = 0;
  }
  else {
    pvVar9 = this->m_rgModeList;
    iVar8 = -1;
    iVar11 = 0;
    do {
      if ((iVar6 == pvVar9->width) && (iVar8 = iVar11, pvVar9->height == iVar7)) goto LAB_001c36e7;
      iVar11 = iVar11 + 1;
      pvVar9 = pvVar9 + 1;
    } while (iVar11 != this->m_nNumModes);
    if (iVar8 == -1) {
      iVar8 = 0;
    }
  }
LAB_001c36e7:
  pp_Var2 = (this->super_IVideoMode)._vptr_IVideoMode;
  this->m_nGameMode = iVar8;
  p_Var1 = pp_Var2[8];
  if (p_Var1 == IsWindowedMode) {
    cVar4 = this->m_bWindowed;
  }
  else {
    iVar11 = (*p_Var1)(this);
    cVar4 = (char)iVar11;
  }
  if ((cVar4 != '\0') || (iVar11 = COM_CheckParm("-nofbo"), iVar11 == 0)) {
    iVar10 = COM_CheckParm("-forceres");
    iVar11 = this->m_nNumModes;
    if ((iVar10 != 0) || (iVar11 < 2)) {
      this->m_rgModeList[iVar8].width = iVar6;
      this->m_rgModeList[iVar8].height = iVar7;
      if (iVar11 == 0) {
        this->m_nNumModes = 1;
      }
    }
  }
  (*registry->_vptr_IRegistry[3])(registry,"DisplayWidth",this->m_rgModeList[iVar8].width);
  (*registry->_vptr_IRegistry[3])(registry,"DisplayHeight",this->m_rgModeList[iVar8].height);
  (*registry->_vptr_IRegistry[3])(registry,"DisplayBPP",this->m_rgModeList[iVar8].bpp);
  LoadStartupGraphic(this);
  AdjustWindowForMode(this);
  return (bool)(char)iVar5;
}


// CVideoMode_Common::IsWindowedMode  @ 001c26a0
/* DWARF original prototype: bool IsWindowedMode(CVideoMode_Common * this) */

bool __thiscall CVideoMode_Common::IsWindowedMode(CVideoMode_Common *this)

{
  return this->m_bWindowed;
}


// CVideoMode_Common::LoadStartupGraphic  @ 001c30b0
/* DWARF original prototype: void LoadStartupGraphic(CVideoMode_Common * this) */

void __thiscall CVideoMode_Common::LoadStartupGraphic(CVideoMode_Common *this)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  CVideoMode_Common *pCVar4;
  FileHandle_t file;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  long lVar8;
  char *pcVar9;
  bimage_t *pbVar11;
  byte *pbVar12;
  qboolean qVar13;
  uint uVar14;
  char *pcVar15;
  int in_GS_OFFSET;
  byte bVar16;
  size_t sStackY_260;
  char acStack_240 [8];
  CVideoMode_Common *local_238;
  char *local_234;
  char *local_230;
  char local_220 [512];
  int local_20;
  int iVar10;
  
                    /* Unresolved local var: FileHandle_t file@[???]
                       Unresolved local var: int fileSize@[???]
                       Unresolved local var: char * buffer@[???]
                       Unresolved local var: char[512] token@[???] */
  bVar16 = 0;
  local_238 = this;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  sStackY_260 = 0x1c30e5;
  file = FS_Open("resource/BackgroundLoadingLayout.txt","rt");
  pcVar7 = &stack0xfffffda4;
  if (file != (FileHandle_t)0x0) {
    sStackY_260 = 0x1c30f7;
    uVar5 = FS_Size(file);
    local_230 = (char *)(uVar5 + 1);
    iVar3 = -(uVar5 + 0x1f & 0xfffffff0);
    pcVar15 = acStack_240 + iVar3 + -0x1c;
    pcVar9 = acStack_240 + iVar3;
    local_234 = pcVar9;
    pcVar7 = pcVar9;
    if ((char *)0x3 < local_230) {
      for (uVar14 = (uint)local_230 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
        pcVar7[0] = '\0';
        pcVar7[1] = '\0';
        pcVar7[2] = '\0';
        pcVar7[3] = '\0';
        pcVar7 = pcVar7 + (uint)bVar16 * -8 + 4;
      }
    }
    if (((uint)local_230 & 2) != 0) {
      pcVar7[0] = '\0';
      pcVar7[1] = '\0';
      pcVar7 = pcVar7 + 2;
    }
    if (((uint)local_230 & 1) != 0) {
      *pcVar7 = '\0';
    }
    *(uint *)(&stack0xfffffda8 + iVar3) = uVar5;
    *(undefined4 *)(&stack0xfffffdac + iVar3) = 1;
    *(FileHandle_t *)(&stack0xfffffdb0 + iVar3) = file;
    *(char **)(acStack_240 + iVar3 + -0x1c) = pcVar9;
    *(undefined4 *)((int)&sStackY_260 + iVar3) = 0x1c3165;
    FS_Read(*(void **)(acStack_240 + iVar3 + -0x1c),*(int *)(&stack0xfffffda8 + iVar3),
            *(int *)(&stack0xfffffdac + iVar3),*(FileHandle_t *)(&stack0xfffffdb0 + iVar3));
    *(FileHandle_t *)(acStack_240 + iVar3 + -0x1c) = file;
    *(undefined4 *)((int)&sStackY_260 + iVar3) = 0x1c316d;
    FS_Close(*(FileHandle_t *)(acStack_240 + iVar3 + -0x1c));
    pCVar4 = local_238;
    do {
      pcVar7 = acStack_240 + iVar3 + -0x1c;
      if (*pcVar9 == '\0') break;
      *(undefined4 *)(&stack0xfffffdac + iVar3) = 0;
      *(char **)(&stack0xfffffda8 + iVar3) = local_220;
      *(char **)(acStack_240 + iVar3 + -0x1c) = pcVar9;
      *(undefined4 *)((int)&sStackY_260 + iVar3) = 0x1c3197;
      local_230 = FS_ParseFile(*(char **)(acStack_240 + iVar3 + -0x1c),
                               *(char **)(&stack0xfffffda8 + iVar3),
                               *(int **)(&stack0xfffffdac + iVar3));
      pcVar7 = acStack_240 + iVar3 + -0x1c;
      if ((local_230 == (char *)0x0) || (pcVar7 = acStack_240 + iVar3 + -0x1c, local_220[0] == '\0')
         ) break;
      *(char **)(&stack0xfffffda8 + iVar3) = "resolution";
      *(char **)(acStack_240 + iVar3 + -0x1c) = local_220;
      *(undefined4 *)((int)&sStackY_260 + iVar3) = 0x1c31d9;
      iVar6 = strcasecmp(*(char **)(acStack_240 + iVar3 + -0x1c),
                         *(char **)(&stack0xfffffda8 + iVar3));
      pcVar7 = local_230;
      if (iVar6 == 0) {
        *(undefined4 *)(&stack0xfffffdac + iVar3) = 0;
        *(char **)(&stack0xfffffda8 + iVar3) = local_220;
        *(char **)(acStack_240 + iVar3 + -0x1c) = pcVar7;
        *(undefined4 *)((int)&sStackY_260 + iVar3) = 0x1c31f9;
        pcVar7 = FS_ParseFile(*(char **)(acStack_240 + iVar3 + -0x1c),
                              *(char **)(&stack0xfffffda8 + iVar3),
                              *(int **)(&stack0xfffffdac + iVar3));
        *(char **)(acStack_240 + iVar3 + -0x1c) = local_220;
        *(undefined4 *)(&stack0xfffffdac + iVar3) = 10;
        *(undefined4 *)(&stack0xfffffda8 + iVar3) = 0;
        *(undefined4 *)((int)&sStackY_260 + iVar3) = 0x1c3212;
        lVar8 = strtol(*(char **)(acStack_240 + iVar3 + -0x1c),*(char ***)(&stack0xfffffda8 + iVar3)
                       ,*(int *)(&stack0xfffffdac + iVar3));
        pCVar4->m_iBaseResX = lVar8;
        *(undefined4 *)(&stack0xfffffdac + iVar3) = 0;
        *(char **)(&stack0xfffffda8 + iVar3) = local_220;
        *(char **)(acStack_240 + iVar3 + -0x1c) = pcVar7;
        *(undefined4 *)((int)&sStackY_260 + iVar3) = 0x1c322a;
        pcVar7 = FS_ParseFile(*(char **)(acStack_240 + iVar3 + -0x1c),
                              *(char **)(&stack0xfffffda8 + iVar3),
                              *(int **)(&stack0xfffffdac + iVar3));
        *(char **)(acStack_240 + iVar3 + -0x1c) = local_220;
        local_230 = pcVar7;
        *(undefined4 *)(&stack0xfffffdac + iVar3) = 10;
        *(undefined4 *)(&stack0xfffffda8 + iVar3) = 0;
        *(undefined4 *)((int)&sStackY_260 + iVar3) = 0x1c3247;
        lVar8 = strtol(*(char **)(acStack_240 + iVar3 + -0x1c),*(char ***)(&stack0xfffffda8 + iVar3)
                       ,*(int *)(&stack0xfffffdac + iVar3));
        pCVar4->m_iBaseResY = lVar8;
      }
      else {
                    /* Unresolved local var: bimage_t * bimage@[???] */
        iVar6 = (pCVar4->m_ImageID).m_Size;
        iVar2 = (pCVar4->m_ImageID).m_Memory.m_NumAllocated;
        pcVar7 = (char *)(iVar6 + 1);
        if (iVar2 < (int)pcVar7) {
                    /* Unresolved local var: int nNeed@[???]
                       Unresolved local var: int nGrowSize@[???] */
          local_234 = pcVar7 + -iVar2;
          pcVar9 = (char *)(pCVar4->m_ImageID).m_Memory.m_GrowSize;
          if ((int)(pcVar7 + -iVar2) < (int)pcVar9) {
                    /* Unresolved local var: int growSize@[???] */
            if ((0 < (int)pcVar9) || (pcVar9 != (char *)0x0)) {
              local_234 = pcVar9;
              goto LAB_001c3434;
            }
            iVar10 = 1;
            if (iVar2 != 0) {
              iVar10 = iVar2;
            }
            pcVar9 = (char *)(iVar10 + iVar2);
                    /* Unresolved local var: int growSize@[???] */
            pbVar11 = (pCVar4->m_ImageID).m_Memory.m_pMemory;
            (pCVar4->m_ImageID).m_Memory.m_NumAllocated = (int)pcVar9;
          }
          else {
            if ((int)pcVar9 < 0) goto LAB_001c3420;
LAB_001c3434:
            pcVar9 = local_234 + iVar2;
            pbVar11 = (pCVar4->m_ImageID).m_Memory.m_pMemory;
            (pCVar4->m_ImageID).m_Memory.m_NumAllocated = (int)pcVar9;
          }
          if (pbVar11 == (bimage_t *)0x0) {
            *(int *)(acStack_240 + iVar3 + -0x1c) = (int)pcVar9 * 0x18;
            local_234 = pcVar7;
            *(undefined4 *)((int)&sStackY_260 + iVar3) = 0x1c3464;
            pbVar11 = malloc(*(size_t *)(acStack_240 + iVar3 + -0x1c));
            (pCVar4->m_ImageID).m_Memory.m_pMemory = pbVar11;
            pcVar7 = local_234;
          }
          else {
            *(int *)(&stack0xfffffda8 + iVar3) = (int)pcVar9 * 0x18;
            *(bimage_t **)(acStack_240 + iVar3 + -0x1c) = pbVar11;
            *(undefined4 *)((int)&sStackY_260 + iVar3) = 0x1c32d4;
            pbVar11 = realloc(*(void **)(acStack_240 + iVar3 + -0x1c),
                              *(size_t *)(&stack0xfffffda8 + iVar3));
            iVar2 = (pCVar4->m_ImageID).m_Size;
            (pCVar4->m_ImageID).m_Memory.m_pMemory = pbVar11;
            pcVar7 = (char *)(iVar2 + 1);
          }
        }
        else {
LAB_001c3420:
          pbVar11 = (pCVar4->m_ImageID).m_Memory.m_pMemory;
        }
        (pCVar4->m_ImageID).m_Size = (int)pcVar7;
                    /* Unresolved local var: int numToMove@[???] */
        if (0 < (int)(pcVar7 + (-1 - iVar6))) {
          *(int *)(&stack0xfffffdac + iVar3) = (int)(pcVar7 + (-1 - iVar6)) * 0x18;
          *(bimage_t **)(&stack0xfffffda8 + iVar3) = pbVar11 + iVar6;
          *(bimage_t **)(acStack_240 + iVar3 + -0x1c) = pbVar11 + iVar6 + 1;
          *(undefined4 *)((int)&sStackY_260 + iVar3) = 0x1c3313;
          memmove(*(void **)(acStack_240 + iVar3 + -0x1c),*(void **)(&stack0xfffffda8 + iVar3),
                  *(size_t *)(&stack0xfffffdac + iVar3));
          pbVar11 = (pCVar4->m_ImageID).m_Memory.m_pMemory;
        }
        pcVar15[0] = '\0';
        pcVar15[1] = '\0';
        pcVar15[2] = '\x04';
        pcVar15[3] = '\0';
        pbVar11 = pbVar11 + iVar6;
        *(undefined4 *)((int)&sStackY_260 + iVar3) = 0x1c3327;
        pbVar12 = malloc(*(size_t *)(acStack_240 + iVar3 + -0x1c));
        pbVar11->buffer = pbVar12;
        *(int **)(&stack0xfffffdb4 + iVar3) = &pbVar11->height;
        *(int **)(&stack0xfffffdb0 + iVar3) = &pbVar11->width;
        *(undefined4 *)(&stack0xfffffdac + iVar3) = 0x40000;
        *(byte **)(&stack0xfffffda8 + iVar3) = pbVar12;
        *(char **)(acStack_240 + iVar3 + -0x1c) = local_220;
        *(undefined4 *)((int)&sStackY_260 + iVar3) = 0x1c334c;
        qVar13 = LoadTGA(*(char **)(acStack_240 + iVar3 + -0x1c),
                         *(byte **)(&stack0xfffffda8 + iVar3),*(int *)(&stack0xfffffdac + iVar3),
                         *(int **)(&stack0xfffffdb0 + iVar3),*(int **)(&stack0xfffffdb4 + iVar3));
        pcVar7 = local_230;
        if (qVar13 == false) {
          piVar1 = &(local_238->m_ImageID).m_Size;
          *piVar1 = *piVar1 + -1;
          pcVar7 = acStack_240 + iVar3 + -0x1c;
          break;
        }
        *(undefined4 *)(&stack0xfffffdac + iVar3) = 0;
        *(char **)(&stack0xfffffda8 + iVar3) = local_220;
        *(char **)(acStack_240 + iVar3 + -0x1c) = pcVar7;
        *(undefined4 *)((int)&sStackY_260 + iVar3) = 0x1c336c;
        pcVar7 = FS_ParseFile(*(char **)(acStack_240 + iVar3 + -0x1c),
                              *(char **)(&stack0xfffffda8 + iVar3),
                              *(int **)(&stack0xfffffdac + iVar3));
        *(char **)(&stack0xfffffda8 + iVar3) = "scaled";
        *(char **)(acStack_240 + iVar3 + -0x1c) = local_220;
        local_230 = pcVar7;
        *(undefined4 *)((int)&sStackY_260 + iVar3) = 0x1c3383;
        iVar6 = strcasecmp(*(char **)(acStack_240 + iVar3 + -0x1c),
                           *(char **)(&stack0xfffffda8 + iVar3));
        pbVar11->scaled = iVar6 == 0;
        *(undefined **)(&stack0xfffffda8 + iVar3) = &DAT_0026ff55;
        *(char **)(acStack_240 + iVar3 + -0x1c) = local_220;
        *(undefined4 *)((int)&sStackY_260 + iVar3) = 0x1c339a;
        iVar6 = strcasecmp(*(char **)(acStack_240 + iVar3 + -0x1c),
                           *(char **)(&stack0xfffffda8 + iVar3));
        pbVar11->fit = iVar6 == 0;
        *(char **)(acStack_240 + iVar3 + -0x1c) = local_230;
        *(undefined4 *)(&stack0xfffffdac + iVar3) = 0;
        *(char **)(&stack0xfffffda8 + iVar3) = local_220;
        *(undefined4 *)((int)&sStackY_260 + iVar3) = 0x1c33b8;
        pcVar7 = FS_ParseFile(*(char **)(acStack_240 + iVar3 + -0x1c),
                              *(char **)(&stack0xfffffda8 + iVar3),
                              *(int **)(&stack0xfffffdac + iVar3));
        *(char **)(acStack_240 + iVar3 + -0x1c) = local_220;
        local_230 = pcVar7;
        *(undefined4 *)(&stack0xfffffdac + iVar3) = 10;
        *(undefined4 *)(&stack0xfffffda8 + iVar3) = 0;
        *(undefined4 *)((int)&sStackY_260 + iVar3) = 0x1c33d5;
        lVar8 = strtol(*(char **)(acStack_240 + iVar3 + -0x1c),*(char ***)(&stack0xfffffda8 + iVar3)
                       ,*(int *)(&stack0xfffffdac + iVar3));
        pbVar11->x = lVar8;
        *(char **)(acStack_240 + iVar3 + -0x1c) = local_230;
        *(undefined4 *)(&stack0xfffffdac + iVar3) = 0;
        *(char **)(&stack0xfffffda8 + iVar3) = local_220;
        *(undefined4 *)((int)&sStackY_260 + iVar3) = 0x1c33f0;
        pcVar7 = FS_ParseFile(*(char **)(acStack_240 + iVar3 + -0x1c),
                              *(char **)(&stack0xfffffda8 + iVar3),
                              *(int **)(&stack0xfffffdac + iVar3));
        *(undefined4 *)(&stack0xfffffda8 + iVar3) = 0;
        *(char **)(acStack_240 + iVar3 + -0x1c) = local_220;
        local_230 = pcVar7;
        *(undefined4 *)(&stack0xfffffdac + iVar3) = 10;
        *(undefined4 *)((int)&sStackY_260 + iVar3) = 0x1c340d;
        lVar8 = strtol(*(char **)(acStack_240 + iVar3 + -0x1c),*(char ***)(&stack0xfffffda8 + iVar3)
                       ,*(int *)(&stack0xfffffdac + iVar3));
        pbVar11->y = lVar8;
      }
      pcVar9 = local_230;
      pcVar7 = acStack_240 + iVar3 + -0x1c;
    } while (local_230 != (char *)0x0);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)(pcVar7 + -4) = &UNK_001c34e6;
  __stack_chk_fail();
}


// CVideoMode_Common::MaxBitsPerPixel  @ 001c2770
/* DWARF original prototype: int MaxBitsPerPixel(CVideoMode_Common * this) */

int __thiscall CVideoMode_Common::MaxBitsPerPixel(CVideoMode_Common *this)

{
  return 0x20;
}


// CVideoMode_Common::PlayStartupSequence  @ 001c42a0
/* DWARF original prototype: void PlayStartupSequence(CVideoMode_Common * this) */

void __thiscall CVideoMode_Common::PlayStartupSequence(CVideoMode_Common *this)

{
  int iVar1;
  HWND window;
  
  iVar1 = COM_CheckParm("-novid");
  if (iVar1 == 0) {
    (*game->_vptr_IGame[0xd])(game);
  }
  window = (HWND)(*game->_vptr_IGame[6])(game);
  DrawStartupGraphic(this,window);
  return;
}


// CVideoMode_Common::ReleaseVideo  @ 001c2780
/* DWARF original prototype: void ReleaseVideo(CVideoMode_Common * this) */

void __thiscall CVideoMode_Common::ReleaseVideo(CVideoMode_Common *this)

{
  return;
}


// CVideoMode_Common::SetInitialized  @ 001c2690
/* DWARF original prototype: void SetInitialized(CVideoMode_Common * this, bool init) */

void __thiscall CVideoMode_Common::SetInitialized(CVideoMode_Common *this,bool init)

{
  this->m_bInitialized = init;
  return;
}


// CVideoMode_Common::Shutdown  @ 001c2870
/* DWARF original prototype: void Shutdown(CVideoMode_Common * this) */

void __thiscall CVideoMode_Common::Shutdown(CVideoMode_Common *this)

{
  _func_int_varargs *p_Var1;
  char cVar2;
  int iVar3;
  
  (*(this->super_IVideoMode)._vptr_IVideoMode[0x12])(this);
  p_Var1 = (this->super_IVideoMode)._vptr_IVideoMode[9];
  if (p_Var1 == GetInitialized) {
    cVar2 = this->m_bInitialized;
  }
  else {
    iVar3 = (*p_Var1)(this);
    cVar2 = (char)iVar3;
  }
  if (cVar2 != '\0') {
    p_Var1 = (this->super_IVideoMode)._vptr_IVideoMode[10];
    if (p_Var1 == SetInitialized) {
      this->m_bInitialized = false;
    }
    else {
      (*p_Var1)(this,0);
    }
    this->m_nGameMode = 0;
    videomode = (IVideoMode *)0x0;
    if (this != (CVideoMode_Common *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001c28d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(this->super_IVideoMode)._vptr_IVideoMode[0x10])();
      return;
    }
  }
  return;
}


// CVideoMode_Common::UpdateWindowPosition  @ 001c2790
/* DWARF original prototype: void UpdateWindowPosition(CVideoMode_Common * this) */

void __thiscall CVideoMode_Common::UpdateWindowPosition(CVideoMode_Common *this)

{
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  RECT local_1c;
  
                    /* Unresolved local var: RECT window_rect@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int cx@[???]
                       Unresolved local var: int cy@[???] */
  (*game->_vptr_IGame[10])(game,&local_2c,&local_28,&local_24,&local_20);
  local_1c.left = local_2c;
  local_1c.right = local_2c + local_24;
  local_1c.top = local_28;
  local_1c.bottom = local_28 + local_20;
  VID_UpdateWindowVars(&local_1c,local_24 / 2 + local_2c,local_20 / 2 + local_28);
  return;
}


// CVideoMode_Common::~CVideoMode_Common  @ 001c2b70
/* DWARF original prototype: void ~CVideoMode_Common(CVideoMode_Common * this, int __in_chrg) */

void __thiscall CVideoMode_Common::~CVideoMode_Common(CVideoMode_Common *this,int __in_chrg)

{
  int iVar1;
  bimage_t *__ptr;
  
  iVar1 = (this->m_ImageID).m_Memory.m_GrowSize;
  (this->super_IVideoMode)._vptr_IVideoMode = (_func_int_varargs **)&PTR___cxa_pure_virtual_002700b8
  ;
  (this->m_ImageID).m_Size = 0;
  if ((-1 < iVar1) && (__ptr = (this->m_ImageID).m_Memory.m_pMemory, __ptr != (bimage_t *)0x0)) {
    free(__ptr);
    return;
  }
  return;
}


// CVideoMode_Common::~CVideoMode_Common  @ 001c2bb0
/* DWARF original prototype: void ~CVideoMode_Common(CVideoMode_Common * this, int __in_chrg) */

void __thiscall CVideoMode_Common::~CVideoMode_Common(CVideoMode_Common *this,int __in_chrg)

{
  int iVar1;
  bimage_t *__ptr;
  
  iVar1 = (this->m_ImageID).m_Memory.m_GrowSize;
  (this->super_IVideoMode)._vptr_IVideoMode = (_func_int_varargs **)&PTR___cxa_pure_virtual_002700b8
  ;
  (this->m_ImageID).m_Size = 0;
  if ((-1 < iVar1) && (__ptr = (this->m_ImageID).m_Memory.m_pMemory, __ptr != (bimage_t *)0x0)) {
    free(__ptr);
  }
  operator_delete(this);
  return;
}


// CVideoMode_OpenGL::CVideoMode_OpenGL  @ 001c47b0
/* DWARF original prototype: void CVideoMode_OpenGL(CVideoMode_OpenGL * this, bool windowed) */

void __thiscall CVideoMode_OpenGL::CVideoMode_OpenGL(CVideoMode_OpenGL *this,bool windowed)

{
  undefined1 local_20 [4];
  int local_1c;
  int local_18;
  
  (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_GrowSize = 0;
  (this->super_CVideoMode_Common).m_ImageID.m_Size = 0;
                    /* Unresolved local var: SDL_DisplayMode.conflict mode@[???] */
  (this->super_CVideoMode_Common).m_nNumModes = 0;
  (this->super_CVideoMode_Common).m_nGameMode = 0;
  (this->super_CVideoMode_Common).super_IVideoMode._vptr_IVideoMode =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_002700b8;
  (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_pMemory = (bimage_t *)0x0;
  (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_NumAllocated = 0;
  (this->super_CVideoMode_Common).m_bWindowed = false;
  (this->super_CVideoMode_Common).m_bInitialized = false;
  SDL_GetDesktopDisplayMode(0,local_20);
  (this->super_CVideoMode_Common).super_IVideoMode._vptr_IVideoMode =
       (_func_int_varargs **)&PTR_GetName_00270110;
  (this->super_CVideoMode_Common).m_bWindowed = windowed;
  (this->super_CVideoMode_Common).m_safeMode.width = local_1c;
  (this->super_CVideoMode_Common).m_safeMode.height = local_18;
  (this->super_CVideoMode_Common).m_safeMode.bpp = 0x20;
  return;
}


// CVideoMode_OpenGL::ChangeDisplaySettingsToFullscreen  @ 001c2a50
/* DWARF original prototype: void ChangeDisplaySettingsToFullscreen(CVideoMode_OpenGL * this) */

void __thiscall CVideoMode_OpenGL::ChangeDisplaySettingsToFullscreen(CVideoMode_OpenGL *this)

{
  _func_int_varargs *p_Var1;
  _func_int_varargs **pp_Var2;
  char cVar3;
  int iVar4;
  vmode_t *pvVar5;
  int iVar6;
  
                    /* Unresolved local var: vmode_t * mode@[???]
                       Unresolved local var: int iScreenMode@[???] */
  p_Var1 = (this->super_CVideoMode_Common).super_IVideoMode._vptr_IVideoMode[8];
  if (p_Var1 == CVideoMode_Common::IsWindowedMode) {
    cVar3 = (this->super_CVideoMode_Common).m_bWindowed;
  }
  else {
    iVar6 = (*p_Var1)(this);
    cVar3 = (char)iVar6;
  }
  if (cVar3 == '\0') {
    pp_Var2 = (this->super_CVideoMode_Common).super_IVideoMode._vptr_IVideoMode;
    p_Var1 = pp_Var2[5];
    if (p_Var1 == CVideoMode_Common::GetCurrentMode) {
      p_Var1 = pp_Var2[6];
      iVar6 = (this->super_CVideoMode_Common).m_nGameMode;
      if (p_Var1 == CVideoMode_Common::GetMode) {
        if (((this->super_CVideoMode_Common).m_nNumModes <= iVar6) ||
           (pvVar5 = (this->super_CVideoMode_Common).m_rgModeList + iVar6, iVar6 < 0)) {
          pvVar5 = &(this->super_CVideoMode_Common).m_safeMode;
        }
      }
      else {
        pvVar5 = (vmode_t *)(*p_Var1)(this,iVar6);
      }
    }
    else {
      pvVar5 = (vmode_t *)(*p_Var1)(this);
    }
    if (pvVar5 != (vmode_t *)0x0) {
                    /* Unresolved local var: vmode_t * mode@[???]
                       Unresolved local var: int iScreenMode@[???] */
      iVar6 = 1;
      if (bNeedsFullScreenModeSwitch < 1) {
        iVar6 = 0x1001;
      }
      if (ChangeDisplaySettingsToFullscreen::iLastScreenMode != iVar6) {
        iVar4 = (*game->_vptr_IGame[6])(game);
        SDL_SetWindowFullscreen(iVar4,0);
      }
      iVar4 = (*game->_vptr_IGame[6])(game);
      SDL_SetWindowFullscreen(iVar4,iVar6);
      ChangeDisplaySettingsToFullscreen::iLastScreenMode = iVar6;
      return;
    }
  }
  return;
}


// CVideoMode_OpenGL::FlipScreen  @ 001c2820
/* DWARF original prototype: void FlipScreen(CVideoMode_OpenGL * this) */

void __thiscall CVideoMode_OpenGL::FlipScreen(CVideoMode_OpenGL *this)

{
                    /* WARNING: Subroutine does not return */
  Sys_Error("This shouldn\'t be called\n");
}


// CVideoMode_OpenGL::GetName  @ 001c4a50
/* DWARF original prototype: char * GetName(CVideoMode_OpenGL * this) */

char * __thiscall CVideoMode_OpenGL::GetName(CVideoMode_OpenGL *this)

{
  return "gl";
}


// CVideoMode_OpenGL::Init  @ 001c3940
/* DWARF original prototype: bool Init(CVideoMode_OpenGL * this, void * pvInstance) */

bool __thiscall CVideoMode_OpenGL::Init(CVideoMode_OpenGL *this,void *pvInstance)

{
  _func_int_varargs *p_Var1;
  bool bVar2;
  
                    /* Unresolved local var: bool bret@[???] */
  bVar2 = CVideoMode_Common::Init(&this->super_CVideoMode_Common,pvInstance);
  p_Var1 = (this->super_CVideoMode_Common).super_IVideoMode._vptr_IVideoMode[10];
  if (p_Var1 == CVideoMode_Common::SetInitialized) {
    (this->super_CVideoMode_Common).m_bInitialized = bVar2;
    return bVar2;
  }
  (*p_Var1)(this,(uint)bVar2);
  return bVar2;
}


// CVideoMode_OpenGL::ReleaseFullScreen  @ 001c2900
/* DWARF original prototype: void ReleaseFullScreen(CVideoMode_OpenGL * this) */

void __thiscall CVideoMode_OpenGL::ReleaseFullScreen(CVideoMode_OpenGL *this)

{
  _func_int_varargs *p_Var1;
  char cVar2;
  int iVar3;
  
  p_Var1 = (this->super_CVideoMode_Common).super_IVideoMode._vptr_IVideoMode[8];
  if (p_Var1 == CVideoMode_Common::IsWindowedMode) {
    cVar2 = (this->super_CVideoMode_Common).m_bWindowed;
  }
  else {
    iVar3 = (*p_Var1)(this);
    cVar2 = (char)iVar3;
  }
  if (cVar2 == '\0') {
    iVar3 = (*game->_vptr_IGame[6])(game);
    SDL_SetWindowFullscreen(iVar3,0);
  }
  return;
}


// CVideoMode_OpenGL::ReleaseVideo  @ 001c29b0
/* DWARF original prototype: void ReleaseVideo(CVideoMode_OpenGL * this) */

void __thiscall CVideoMode_OpenGL::ReleaseVideo(CVideoMode_OpenGL *this)

{
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  _func_int_varargs **pp_Var1;
  char cVar2;
  int iVar3;
  
  UNRECOVERED_JUMPTABLE = (this->super_CVideoMode_Common).super_IVideoMode._vptr_IVideoMode[8];
  if (UNRECOVERED_JUMPTABLE == CVideoMode_Common::IsWindowedMode) {
    cVar2 = (this->super_CVideoMode_Common).m_bWindowed;
  }
  else {
    iVar3 = (*UNRECOVERED_JUMPTABLE)(this);
    cVar2 = (char)iVar3;
  }
  if (cVar2 == '\0') {
    pp_Var1 = (this->super_CVideoMode_Common).super_IVideoMode._vptr_IVideoMode;
    UNRECOVERED_JUMPTABLE = pp_Var1[0x12];
    if (UNRECOVERED_JUMPTABLE != ReleaseFullScreen) {
                    /* WARNING: Could not recover jumptable at 0x001c2a38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
    UNRECOVERED_JUMPTABLE = pp_Var1[8];
    if (UNRECOVERED_JUMPTABLE == CVideoMode_Common::IsWindowedMode) {
      cVar2 = (this->super_CVideoMode_Common).m_bWindowed;
    }
    else {
      iVar3 = (*UNRECOVERED_JUMPTABLE)(this);
      cVar2 = (char)iVar3;
    }
    if (cVar2 == '\0') {
      iVar3 = (*game->_vptr_IGame[6])(game);
      SDL_SetWindowFullscreen(iVar3,0);
      return;
    }
  }
  return;
}


// CVideoMode_OpenGL::RestoreVideo  @ 001c2fd0
/* DWARF original prototype: void RestoreVideo(CVideoMode_OpenGL * this) */

void __thiscall CVideoMode_OpenGL::RestoreVideo(CVideoMode_OpenGL *this)

{
  _func_int_varargs *p_Var1;
  char cVar2;
  int iVar3;
  
  p_Var1 = (this->super_CVideoMode_Common).super_IVideoMode._vptr_IVideoMode[8];
  if (p_Var1 == CVideoMode_Common::IsWindowedMode) {
    cVar2 = (this->super_CVideoMode_Common).m_bWindowed;
  }
  else {
    iVar3 = (*p_Var1)(this);
    cVar2 = (char)iVar3;
  }
  if (cVar2 != '\0') {
    return;
  }
  CVideoMode_Common::AdjustWindowForMode(&this->super_CVideoMode_Common);
  (*game->_vptr_IGame[6])(game);
  SDL_ShowWindow();
  return;
}


// CVideoMode_OpenGL::~CVideoMode_OpenGL  @ 001c4a60
/* DWARF original prototype: void ~CVideoMode_OpenGL(CVideoMode_OpenGL * this, int __in_chrg) */

void __thiscall CVideoMode_OpenGL::~CVideoMode_OpenGL(CVideoMode_OpenGL *this,int __in_chrg)

{
  int iVar1;
  bimage_t *__ptr;
  
  iVar1 = (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_GrowSize;
  (this->super_CVideoMode_Common).super_IVideoMode._vptr_IVideoMode =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_002700b8;
  (this->super_CVideoMode_Common).m_ImageID.m_Size = 0;
  if ((-1 < iVar1) &&
     (__ptr = (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_pMemory, __ptr != (bimage_t *)0x0
     )) {
    free(__ptr);
    return;
  }
  return;
}


// CVideoMode_OpenGL::~CVideoMode_OpenGL  @ 001c4aa0
/* DWARF original prototype: void ~CVideoMode_OpenGL(CVideoMode_OpenGL * this, int __in_chrg) */

void __thiscall CVideoMode_OpenGL::~CVideoMode_OpenGL(CVideoMode_OpenGL *this,int __in_chrg)

{
  int iVar1;
  bimage_t *__ptr;
  
  iVar1 = (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_GrowSize;
  (this->super_CVideoMode_Common).super_IVideoMode._vptr_IVideoMode =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_002700b8;
  (this->super_CVideoMode_Common).m_ImageID.m_Size = 0;
  if ((-1 < iVar1) &&
     (__ptr = (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_pMemory, __ptr != (bimage_t *)0x0
     )) {
    free(__ptr);
  }
  operator_delete(this);
  return;
}


