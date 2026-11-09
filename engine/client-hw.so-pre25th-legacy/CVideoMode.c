// CVideoMode_Common::AddMode  @ 002122e0
/* DWARF original prototype: bool AddMode(CVideoMode_Common * this, int width, int height, int bpp)
    */

bool __thiscall CVideoMode_Common::AddMode(CVideoMode_Common *this,int width,int height,int bpp)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: vmode_t * mode@[???] */
  iVar1 = this->m_nNumModes;
  if (0x1f < iVar1) {
    return false;
  }
                    /* Unresolved local var: int i@[???] */
  if (0 < iVar1) {
    iVar2 = 0;
    do {
                    /* Unresolved local var: vmode_t * mode@[???] */
      if (((this->m_rgModeList[iVar2].width == width) &&
          (this->m_rgModeList[iVar2].height == height)) && (this->m_rgModeList[iVar2].bpp == bpp)) {
        return true;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != iVar1);
  }
                    /* Unresolved local var: vmode_t * mode@[???] */
  this->m_nNumModes = iVar1 + 1;
  this->m_rgModeList[iVar1].width = width;
  this->m_rgModeList[iVar1].height = height;
  this->m_rgModeList[iVar1].bpp = bpp;
  return true;
}


// CVideoMode_Common::AdjustWindowForMode  @ 00212730
/* DWARF original prototype: void AdjustWindowForMode(CVideoMode_Common * this) */

void __thiscall CVideoMode_Common::AdjustWindowForMode(CVideoMode_Common *this)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined1 local_2c [8];
  int local_24;
  int local_20;
  
                    /* Unresolved local var: vmode_t * mode@[???]
                       Unresolved local var: RECT WindowRect@[???] */
  puVar1 = (uint *)(*(this->super_IVideoMode)._vptr_IVideoMode[4])(this);
  Snd_ReleaseBuffer();
  vid.width = *puVar1;
  vid.height = puVar1[1];
  iVar2 = (*(this->super_IVideoMode)._vptr_IVideoMode[7])(this);
  if ((char)iVar2 == '\0') {
    uVar6 = *puVar1;
    uVar5 = puVar1[1];
    (*(this->super_IVideoMode)._vptr_IVideoMode[0x12])(this);
    iVar2 = (*game->_vptr_IGame[6])(game);
    SDL_SetWindowPosition(iVar2,0,0);
  }
  else {
    uVar6 = this->m_rgModeList[this->m_nGameMode].width;
    uVar5 = this->m_rgModeList[this->m_nGameMode].height;
  }
  (*game->_vptr_IGame[9])(game,uVar6,uVar5);
  iVar3 = (*game->_vptr_IGame[6])(game);
                    /* Unresolved local var: int CenterX@[???]
                       Unresolved local var: int CenterY@[???]
                       Unresolved local var: SDL_Rect rect@[???]
                       Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???] */
  SDL_GetDisplayBounds(0,local_2c);
  iVar4 = (int)(local_24 - uVar6) / 2;
  iVar2 = 0;
  if (-1 < iVar4) {
    iVar2 = iVar4;
  }
  iVar4 = (int)(local_20 - uVar5) / 2;
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  (*game->_vptr_IGame[8])(game,iVar2,iVar4);
  SDL_SetWindowPosition(iVar3,iVar2,iVar4);
  Snd_AcquireBuffer();
  VOX_Init();
  (*(this->super_IVideoMode)._vptr_IVideoMode[10])(this);
  return;
}


// CVideoMode_Common::CVideoMode_Common  @ 002125f0
/* DWARF original prototype: void CVideoMode_Common(CVideoMode_Common * this) */

void __thiscall CVideoMode_Common::CVideoMode_Common(CVideoMode_Common *this)

{
  (this->m_ImageID).m_Memory.m_pMemory = (bimage_t *)0x0;
  (this->m_ImageID).m_Memory.m_NumAllocated = 0;
  (this->m_ImageID).m_Memory.m_GrowSize = 0;
  (this->m_ImageID).m_Size = 0;
  this->m_nNumModes = 0;
  this->m_nGameMode = 0;
  (this->m_safeMode).width = 0x280;
  (this->super_IVideoMode)._vptr_IVideoMode = (_func_int_varargs **)&PTR___cxa_pure_virtual_002954c8
  ;
  this->m_bWindowed = false;
  this->m_bInitialized = false;
  (this->m_safeMode).height = 0x1e0;
  (this->m_safeMode).bpp = 0x20;
  return;
}


// CVideoMode_Common::CenterEngineWindow  @ 002128b0
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


// CVideoMode_Common::ChangeDisplaySettingsToFullscreen  @ 002121f0
/* DWARF original prototype: void ChangeDisplaySettingsToFullscreen(CVideoMode_Common * this) */

void __thiscall CVideoMode_Common::ChangeDisplaySettingsToFullscreen(CVideoMode_Common *this)

{
  return;
}


// CVideoMode_Common::DrawStartupGraphic  @ 00213150
/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* DWARF original prototype: void DrawStartupGraphic(CVideoMode_Common * this, HWND window) */

void __thiscall CVideoMode_Common::DrawStartupGraphic(CVideoMode_Common *this,HWND window)

{
  void *__ptr;
  bimage_t *__ptr_00;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int unaff_EBP;
  uint *puVar13;
  int iVar14;
  int unaff_EDI;
  uint uVar15;
  undefined4 *puVar16;
  byte bVar17;
  ushort in_FPUControlWord;
  float local_ac;
  float local_a8;
  int local_a0;
  int local_9c;
  int local_98;
  int local_84;
  int local_7c;
  int local_78;
  CUtlMemory<unsigned_int> local_5c;
  int local_50;
  int local_3c [4];
  int local_2c [3];
  ushort local_20;
  ushort local_1e;
  
  bVar17 = 0;
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
                       Unresolved local var: bool s_bEnforceAspect@[???]
                       Unresolved local var: float xScale@[???]
                       Unresolved local var: float yScale@[???] */
  if ((this->m_ImageID).m_Size == 0) {
    return;
  }
  SDL_GetWindowSize(window,local_3c,local_2c);
  iVar10 = local_2c[0];
  iVar11 = local_3c[0];
  local_5c.m_pMemory = (uint *)0x0;
  local_5c.m_NumAllocated = 0;
  local_5c.m_GrowSize = 0;
  local_50 = 0;
  glViewport(0,0,local_3c[0],local_2c[0]);
  glDisable(0xb71);
  glEnable(0xde1);
  glMatrixMode(0x1701);
  glOrtho(0,0,(double)iVar11,(double)iVar10,0,0,0,0xbff00000,0,0x3ff00000);
  glClearColor(0,0,0);
  glClear(0x4000);
                    /* Unresolved local var: vmode_t * mode@[???] */
  piVar5 = (int *)(*videomode->_vptr_IVideoMode[4])(videomode);
  iVar14 = local_2c[0];
  iVar7 = local_3c[0];
  if (piVar5 != (int *)0x0) {
    unaff_EBP = *piVar5;
    unaff_EDI = piVar5[1];
  }
  iVar6 = COM_CheckParm("-stretchaspect");
  if (iVar6 == 0) {
    fVar1 = (float)unaff_EBP / (float)unaff_EDI;
    if (fVar1 < (float)iVar7 / (float)iVar14) {
                    /* Unresolved local var: float fDesiredWidth@[???] */
      fVar1 = (float)local_3c[0] - (float)local_2c[0] * fVar1;
      fVar2 = 0.0;
      goto LAB_0021335b;
    }
    if ((float)iVar7 / (float)iVar14 < fVar1) {
                    /* Unresolved local var: float fDesiredHeight@[???] */
      fVar2 = (float)local_2c[0] - (float)local_3c[0] * (1.0 / fVar1);
      fVar1 = 0.0;
      goto LAB_0021335b;
    }
  }
  fVar2 = 0.0;
  fVar1 = 0.0;
LAB_0021335b:
  fVar3 = ((float)iVar11 - fVar1) / (float)this->m_iBaseResX;
                    /* Unresolved local var: int x@[???] */
  fVar4 = ((float)iVar10 - fVar2) / (float)this->m_iBaseResY;
  if (0 < (this->m_ImageID).m_Size) {
    fVar1 = fVar1 * 0.5;
    local_98 = 0;
    local_84 = 0;
    fVar2 = fVar2 * 0.5;
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
      iVar11 = local_50;
      piVar5 = (int *)((int)&((this->m_ImageID).m_Memory.m_pMemory)->buffer + local_98);
      if (piVar5[1] == 0) {
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
        iVar7 = piVar5[2];
        local_a0 = (int)ROUND(fVar1);
        if (iVar7 == 0) goto LAB_00213acf;
LAB_00213487:
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
        local_1e = in_FPUControlWord & 0xf3ff | 0x800;
        local_9c = (int)(double)(int)ROUND(fVar2 + (float)iVar7 * fVar4);
        local_20 = in_FPUControlWord;
      }
      else {
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
        iVar7 = piVar5[2];
        local_a0 = (int)(double)(int)ROUND(fVar1 + (float)piVar5[1] * fVar3);
        if (iVar7 != 0) goto LAB_00213487;
LAB_00213acf:
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
        local_20 = in_FPUControlWord & 0xf3ff | 0x800;
        local_9c = (int)ROUND(fVar2);
        local_1e = in_FPUControlWord;
      }
      if ((char)piVar5[5] == '\0') {
        local_7c = local_a0 + piVar5[3];
        local_78 = local_9c + piVar5[4];
      }
      else {
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
        local_7c = (int)ROUND(fVar1 + (float)(piVar5[1] + piVar5[3]) * fVar3);
                    /* Unresolved local var: longdouble __value@[???]
                       Unresolved local var: int __ignore@[???]
                       Unresolved local var: ushort __cw@[???]
                       Unresolved local var: ushort __cwtmp@[???] */
        local_20 = in_FPUControlWord & 0xf3ff | 0x800;
        local_78 = (int)ROUND(fVar2 + (float)(piVar5[2] + piVar5[4]) * fVar4);
        local_1e = in_FPUControlWord;
      }
      if (local_5c.m_NumAllocated <= local_50) {
        CUtlMemory<unsigned_int>::Grow(&local_5c,(local_50 + 1) - local_5c.m_NumAllocated);
      }
      local_50 = local_50 + 1;
                    /* Unresolved local var: int numToMove@[???] */
      iVar7 = (local_50 - iVar11) + -1;
      if (0 < iVar7) {
        memmove(local_5c.m_pMemory + iVar11 + 1,local_5c.m_pMemory + iVar11,iVar7 * 4);
      }
      puVar13 = local_5c.m_pMemory + iVar11;
      glGenTextures(1,puVar13);
      glBindTexture(0xde1,*puVar13);
      glTexParameteri(0xde1,0x2800,0x2601);
      glTexParameteri(0xde1,0x2801,0x2601);
      glTexParameteri(0xde1,0x2802,0x812f);
      glTexParameteri(0xde1,0x2803,0x812f);
      glPixelStorei(0xcf5,1);
      iVar10 = 0;
      iVar11 = piVar5[3];
      iVar7 = piVar5[4];
      do {
        iVar14 = 1 << ((byte)iVar10 & 0x1f);
        if (iVar11 <= iVar14) break;
        iVar10 = iVar10 + 1;
      } while (iVar10 != 0x20);
      iVar10 = 0;
      do {
        iVar6 = 1 << ((byte)iVar10 & 0x1f);
        if (iVar7 <= iVar6) break;
        iVar10 = iVar10 + 1;
      } while (iVar10 != 0x20);
      if ((iVar11 == iVar14) && (iVar7 == iVar6)) {
        glTexImage2D(0xde1,0,0x1908,iVar11,iVar7,0,0x1908,0x1401,*piVar5);
        local_ac = 1.0;
        local_a8 = 1.0;
      }
      else {
        uVar15 = iVar6 * iVar14 * 4;
        puVar8 = operator_new__(uVar15);
        if (puVar8 == (undefined4 *)0x0) goto LAB_002139f4;
        puVar16 = puVar8;
        if (7 < uVar15) {
          uVar12 = uVar15;
          if (((uint)puVar8 & 1) != 0) {
            *(undefined1 *)puVar8 = 0;
            puVar16 = (undefined4 *)((int)puVar8 + 1);
            uVar12 = uVar15 - 1;
          }
          if (((uint)puVar16 & 2) != 0) {
            *(undefined2 *)puVar16 = 0;
            uVar12 = uVar12 - 2;
            puVar16 = (undefined4 *)((int)puVar16 + 2);
          }
          if (((uint)puVar16 & 4) != 0) {
            *puVar16 = 0;
            uVar12 = uVar12 - 4;
            puVar16 = puVar16 + 1;
          }
          uVar15 = uVar12 & 3;
          for (uVar12 = uVar12 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
            *puVar16 = 0;
            puVar16 = puVar16 + (uint)bVar17 * -2 + 1;
          }
        }
        if ((uVar15 & 4) != 0) {
          *puVar16 = 0;
          puVar16 = puVar16 + 1;
        }
        if ((uVar15 & 2) != 0) {
          *(undefined2 *)puVar16 = 0;
          puVar16 = (undefined4 *)((int)puVar16 + 2);
        }
        if ((uVar15 & 1) != 0) {
          *(undefined1 *)puVar16 = 0;
        }
                    /* Unresolved local var: int y@[???] */
        iVar11 = piVar5[4];
        if (0 < iVar11) {
          iVar7 = piVar5[3];
                    /* Unresolved local var: int x@[???] */
          iVar10 = 0;
          puVar16 = puVar8;
          do {
            iVar9 = 0;
            if (0 < iVar7) {
              do {
                puVar16[iVar9] = *(undefined4 *)(*piVar5 + (iVar10 * iVar7 + iVar9) * 4);
                iVar9 = iVar9 + 1;
                iVar7 = piVar5[3];
              } while (iVar9 < iVar7);
              iVar11 = piVar5[4];
            }
            iVar10 = iVar10 + 1;
            puVar16 = puVar16 + iVar14;
          } while (iVar10 < iVar11);
        }
        glTexImage2D(0xde1,0,0x1908,iVar14,iVar6,0,0x1908,0x1401,puVar8);
        local_ac = (float)piVar5[3] / (float)iVar14;
        local_a8 = (float)piVar5[4] / (float)iVar6;
        operator_delete__(puVar8);
      }
      glBegin(7);
      glTexCoord2f(0,local_a8);
      glVertex3i(local_a0,local_78,0);
      glTexCoord2f(local_ac,local_a8);
      glVertex3i(local_7c,local_78,0);
      glTexCoord2f(local_ac,0);
      glVertex3i(local_7c,local_9c,0);
      glTexCoord2f(0,0);
      glVertex3i(local_a0,local_9c,0);
      glEnd();
      local_84 = local_84 + 1;
      local_98 = local_98 + 0x18;
    } while (local_84 < (this->m_ImageID).m_Size);
  }
  SDL_GL_SwapWindow(window);
  if (0 < local_50) {
    iVar11 = 0;
    do {
      iVar7 = iVar11 + 1;
      glDeleteTextures(1,local_5c.m_pMemory + iVar11);
      iVar11 = iVar7;
    } while (iVar7 < local_50);
  }
  local_50 = 0;
  iVar11 = (this->m_ImageID).m_Size;
  if (0 < iVar11) {
    iVar10 = 0;
    iVar7 = 0;
    do {
      __ptr = *(void **)((int)&((this->m_ImageID).m_Memory.m_pMemory)->buffer + iVar10);
      if (__ptr != (void *)0x0) {
        free(__ptr);
        iVar11 = (this->m_ImageID).m_Size;
      }
      iVar7 = iVar7 + 1;
      iVar10 = iVar10 + 0x18;
    } while (iVar7 < iVar11);
  }
  iVar11 = (this->m_ImageID).m_Memory.m_GrowSize;
  (this->m_ImageID).m_Size = 0;
  if (-1 < iVar11) {
    __ptr_00 = (this->m_ImageID).m_Memory.m_pMemory;
    if (__ptr_00 != (bimage_t *)0x0) {
      free(__ptr_00);
      (this->m_ImageID).m_Memory.m_pMemory = (bimage_t *)0x0;
    }
    (this->m_ImageID).m_Memory.m_NumAllocated = 0;
  }
LAB_002139f4:
  local_50 = 0;
  if ((-1 < local_5c.m_GrowSize) && (local_5c.m_pMemory != (uint *)0x0)) {
    free(local_5c.m_pMemory);
    return;
  }
  return;
}


// CVideoMode_Common::FlipScreen  @ 00212210
/* DWARF original prototype: void FlipScreen(CVideoMode_Common * this) */

void __thiscall CVideoMode_Common::FlipScreen(CVideoMode_Common *this)

{
  return;
}


// CVideoMode_Common::GetCurrentMode  @ 002121d0
/* DWARF original prototype: vmode_t * GetCurrentMode(CVideoMode_Common * this) */

vmode_t * __thiscall CVideoMode_Common::GetCurrentMode(CVideoMode_Common *this)

{
  vmode_t *pvVar1;
  
  pvVar1 = (vmode_t *)(*(this->super_IVideoMode)._vptr_IVideoMode[5])(this,this->m_nGameMode);
  return pvVar1;
}


// CVideoMode_Common::GetInitialized  @ 00212150
/* DWARF original prototype: bool GetInitialized(CVideoMode_Common * this) */

bool __thiscall CVideoMode_Common::GetInitialized(CVideoMode_Common *this)

{
  return this->m_bInitialized;
}


// CVideoMode_Common::GetMode  @ 00212180
/* DWARF original prototype: vmode_t * GetMode(CVideoMode_Common * this, int num) */

vmode_t * __thiscall CVideoMode_Common::GetMode(CVideoMode_Common *this,int num)

{
  if ((-1 < num) && (num < this->m_nNumModes)) {
    return this->m_rgModeList + num;
  }
  return &this->m_safeMode;
}


// CVideoMode_Common::GetModeCount  @ 002121b0
/* DWARF original prototype: int GetModeCount(CVideoMode_Common * this) */

int __thiscall CVideoMode_Common::GetModeCount(CVideoMode_Common *this)

{
  return this->m_nNumModes;
}


// CVideoMode_Common::Init  @ 00213c00
/* DWARF original prototype: bool Init(CVideoMode_Common * this, void * pvInstance) */

bool __thiscall CVideoMode_Common::Init(CVideoMode_Common *this,void *pvInstance)

{
  _func_int_varargs **pp_Var1;
  char cVar2;
  CVideoMode_Common *in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  vmode_s *pvVar6;
  int iVar7;
  HWND window;
  int iVar8;
  int iVar9;
  undefined1 local_2c [8];
  int local_24;
  int local_20;
  
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int bitsperpixel@[???]
                       Unresolved local var: int maxbits@[???]
                       Unresolved local var: int iOK@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: bool bAllowForceRes@[???] */
  iVar3 = (*registry->_vptr_IRegistry[2])(registry,"ScreenWidth",0x400);
  iVar4 = (*registry->_vptr_IRegistry[2])(registry,"ScreenHeight",0x300);
  (*registry->_vptr_IRegistry[2])(registry,"ScreenBPP",0x20);
  COM_CheckParm("-16bpp");
  COM_CheckParm("-24bpp");
  COM_CheckParm("-32bpp");
  (*(in_EAX->super_IVideoMode)._vptr_IVideoMode[0x10])();
  in_EAX->m_nNumModes = 0;
  SetupSDLVideoModes();
  if (1 < in_EAX->m_nNumModes) {
    qsort(in_EAX->m_rgModeList,in_EAX->m_nNumModes,0xc,VideoModeCompare);
  }
  iVar5 = COM_CheckParm("-width");
  if (iVar5 != 0) {
    iVar3 = strtol(com_argv[iVar5 + 1],(char **)0x0,10);
  }
  iVar5 = COM_CheckParm("-w");
  if (iVar5 != 0) {
    iVar3 = strtol(com_argv[iVar5 + 1],(char **)0x0,10);
  }
  iVar5 = COM_CheckParm("-height");
  if (iVar5 == 0) {
    iVar5 = COM_CheckParm("-h");
  }
  else {
    iVar4 = strtol(com_argv[iVar5 + 1],(char **)0x0,10);
    iVar5 = COM_CheckParm("-h");
  }
  if (iVar5 == 0) {
    iVar5 = (*(in_EAX->super_IVideoMode)._vptr_IVideoMode[7])();
    cVar2 = (char)iVar5;
  }
  else {
    iVar4 = strtol(com_argv[iVar5 + 1],(char **)0x0,10);
    iVar5 = (*(in_EAX->super_IVideoMode)._vptr_IVideoMode[7])();
    cVar2 = (char)iVar5;
  }
  if ((cVar2 != '\0') && (iVar5 = SDL_GetDisplayBounds(0,local_2c), iVar5 == 0)) {
    if (local_24 < iVar3) {
      iVar3 = local_24;
    }
    if (local_20 < iVar4) {
      iVar4 = local_20;
    }
  }
  if ((iVar4 < 0) && (0 < iVar3)) {
    iVar4 = (int)((float)iVar3 * 3.0 * 0.25);
  }
  iVar5 = in_EAX->m_nNumModes;
  iVar8 = 0;
  if (0 < iVar5) {
    pvVar6 = in_EAX->m_rgModeList;
                    /* Unresolved local var: SDL_Rect rect@[???]
                       Unresolved local var: int wide@[???]
                       Unresolved local var: int tall@[???] */
    iVar7 = -1;
    do {
      while (iVar3 != pvVar6->width) {
        iVar8 = iVar8 + 1;
        pvVar6 = pvVar6 + 1;
        if (iVar8 == iVar5) goto LAB_00213d7b;
      }
      if (pvVar6->height == iVar4) goto LAB_00213d83;
      iVar9 = iVar8 + 1;
      pvVar6 = pvVar6 + 1;
      iVar7 = iVar8;
      iVar8 = iVar9;
    } while (iVar9 != iVar5);
LAB_00213d7b:
    iVar8 = 0;
    if (iVar7 != -1) {
      iVar8 = iVar7;
    }
  }
LAB_00213d83:
  pp_Var1 = (in_EAX->super_IVideoMode)._vptr_IVideoMode;
  in_EAX->m_nGameMode = iVar8;
  iVar5 = (*pp_Var1[7])();
  if (((char)iVar5 != '\0') ||
     ((iVar5 = COM_CheckParm("-nofbo"), iVar5 == 0 && (iVar5 = Host_GetVideoLevel(), iVar5 < 1)))) {
    iVar7 = COM_CheckParm("-forceres");
    iVar5 = in_EAX->m_nNumModes;
    if ((iVar7 != 0) || (iVar5 < 2)) {
      in_EAX->m_rgModeList[iVar8].width = iVar3;
      in_EAX->m_rgModeList[iVar8].height = iVar4;
      if (iVar5 == 0) {
        in_EAX->m_nNumModes = 1;
      }
    }
  }
  (*registry->_vptr_IRegistry[3])(registry,"ScreenWidth",in_EAX->m_rgModeList[iVar8].width);
  (*registry->_vptr_IRegistry[3])(registry,"ScreenHeight",in_EAX->m_rgModeList[iVar8].height);
  (*registry->_vptr_IRegistry[3])(registry,"ScreenBPP",in_EAX->m_rgModeList[iVar8].bpp);
  LoadStartupGraphic(in_EAX);
  AdjustWindowForMode(in_EAX);
  (*game->_vptr_IGame[0xd])(game);
  window = (HWND)(*game->_vptr_IGame[6])(game);
  DrawStartupGraphic(in_EAX,window);
  return true;
}


// CVideoMode_Common::Init  @ 00213ff0
/* DWARF original prototype: bool Init(CVideoMode_Common * this, void * pvInstance) */

bool __thiscall CVideoMode_Common::Init(CVideoMode_Common *this,void *pvInstance)

{
  bool bVar1;
  int iVar2;
  
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int bitsperpixel@[???]
                       Unresolved local var: int maxbits@[???]
                       Unresolved local var: int iOK@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: bool bAllowForceRes@[???] */
  iVar2 = (*game->_vptr_IGame[4])(game);
  if ((char)iVar2 == '\0') {
    return false;
  }
  bVar1 = Init(this,pvInstance);
  return bVar1;
}


// CVideoMode_Common::IsWindowedMode  @ 00212170
/* DWARF original prototype: bool IsWindowedMode(CVideoMode_Common * this) */

bool __thiscall CVideoMode_Common::IsWindowedMode(CVideoMode_Common *this)

{
  return this->m_bWindowed;
}


// CVideoMode_Common::LoadStartupGraphic  @ 00212de0
/* WARNING: Type propagation algorithm not settling */
/* DWARF original prototype: void LoadStartupGraphic(CVideoMode_Common * this) */

void __thiscall CVideoMode_Common::LoadStartupGraphic(CVideoMode_Common *this)

{
  int *piVar1;
  int iVar2;
  CUtlVector<CVideoMode_Common::bimage_t> *pCVar3;
  uint uVar4;
  byte *pbVar5;
  qboolean qVar6;
  long lVar7;
  int iVar8;
  uint uVar9;
  char *pcVar10;
  char *pcVar11;
  bimage_t *pbVar12;
  char *pcVar13;
  byte bVar14;
  size_t sStackY_250;
  char acStack_230 [8];
  char *local_228;
  CUtlVector<CVideoMode_Common::bimage_t> *local_224;
  char *local_220;
  char local_21c [524];
  
  bVar14 = 0;
                    /* Unresolved local var: FileHandle_t file@[???]
                       Unresolved local var: int fileSize@[???]
                       Unresolved local var: char * buffer@[???]
                       Unresolved local var: char[512] token@[???] */
  sStackY_250 = 0x212e04;
  local_224 = FS_Open("resource/BackgroundLoadingLayout.txt","rt");
  if (local_224 != (FileHandle_t)0x0) {
    sStackY_250 = 0x212e16;
    uVar4 = FS_Size(local_224);
    pCVar3 = local_224;
    iVar2 = -(uVar4 + 0x1f & 0xfffffff0);
    pcVar11 = acStack_230 + iVar2 + -0x1c;
    pcVar10 = acStack_230 + iVar2;
    local_220 = pcVar10;
    pcVar13 = pcVar10;
    if (3 < uVar4) {
      for (uVar9 = uVar4 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        pcVar13[0] = '\0';
        pcVar13[1] = '\0';
        pcVar13[2] = '\0';
        pcVar13[3] = '\0';
        pcVar13 = pcVar13 + (uint)bVar14 * -8 + 4;
      }
    }
    if ((uVar4 & 2) != 0) {
      pcVar13[0] = '\0';
      pcVar13[1] = '\0';
      pcVar13 = pcVar13 + 2;
    }
    if ((uVar4 & 1) != 0) {
      *pcVar13 = '\0';
    }
    *(uint *)(&stack0xfffffdb8 + iVar2) = uVar4;
    pcVar13 = local_220;
    *(CUtlVector<CVideoMode_Common::bimage_t> **)(&stack0xfffffdc0 + iVar2) = pCVar3;
    *(char **)(acStack_230 + iVar2 + -0x1c) = pcVar13;
    *(undefined4 *)(&stack0xfffffdbc + iVar2) = 1;
    *(undefined4 *)((int)&sStackY_250 + iVar2) = 0x212e65;
    FS_Read(*(void **)(acStack_230 + iVar2 + -0x1c),*(int *)(&stack0xfffffdb8 + iVar2),
            *(int *)(&stack0xfffffdbc + iVar2),*(FileHandle_t *)(&stack0xfffffdc0 + iVar2));
    *(CUtlVector<CVideoMode_Common::bimage_t> **)(acStack_230 + iVar2 + -0x1c) = local_224;
    *(undefined4 *)((int)&sStackY_250 + iVar2) = 0x212e73;
    FS_Close(*(FileHandle_t *)(acStack_230 + iVar2 + -0x1c));
    if (*local_220 != '\0') {
                    /* Unresolved local var: bimage_t * bimage@[???] */
      local_224 = &this->m_ImageID;
      while( true ) {
        *(undefined4 *)(&stack0xfffffdbc + iVar2) = 0;
        *(char **)(&stack0xfffffdb8 + iVar2) = local_21c;
        *(char **)(acStack_230 + iVar2 + -0x1c) = pcVar10;
        *(undefined4 *)((int)&sStackY_250 + iVar2) = 0x213003;
        local_220 = FS_ParseFile(*(char **)(acStack_230 + iVar2 + -0x1c),
                                 *(char **)(&stack0xfffffdb8 + iVar2),
                                 *(int **)(&stack0xfffffdbc + iVar2));
        if ((local_220 == (char *)0x0) || (local_21c[0] == '\0')) break;
        *(char **)(&stack0xfffffdb8 + iVar2) = "resolution";
        *(char **)(acStack_230 + iVar2 + -0x1c) = local_21c;
        *(undefined4 *)((int)&sStackY_250 + iVar2) = 0x21302f;
        iVar8 = strcasecmp(*(char **)(acStack_230 + iVar2 + -0x1c),
                           *(char **)(&stack0xfffffdb8 + iVar2));
        pcVar10 = local_220;
        if (iVar8 == 0) {
          *(undefined4 *)(&stack0xfffffdbc + iVar2) = 0;
          *(char **)(&stack0xfffffdb8 + iVar2) = local_21c;
          *(char **)(acStack_230 + iVar2 + -0x1c) = pcVar10;
          *(undefined4 *)((int)&sStackY_250 + iVar2) = 0x2130a8;
          pcVar10 = FS_ParseFile(*(char **)(acStack_230 + iVar2 + -0x1c),
                                 *(char **)(&stack0xfffffdb8 + iVar2),
                                 *(int **)(&stack0xfffffdbc + iVar2));
          *(char **)(acStack_230 + iVar2 + -0x1c) = local_21c;
          *(undefined4 *)(&stack0xfffffdbc + iVar2) = 10;
          *(undefined4 *)(&stack0xfffffdb8 + iVar2) = 0;
          *(undefined4 *)((int)&sStackY_250 + iVar2) = 0x2130c1;
          lVar7 = strtol(*(char **)(acStack_230 + iVar2 + -0x1c),
                         *(char ***)(&stack0xfffffdb8 + iVar2),*(int *)(&stack0xfffffdbc + iVar2));
          this->m_iBaseResX = lVar7;
          *(undefined4 *)(&stack0xfffffdbc + iVar2) = 0;
          *(char **)(&stack0xfffffdb8 + iVar2) = local_21c;
          *(char **)(acStack_230 + iVar2 + -0x1c) = pcVar10;
          *(undefined4 *)((int)&sStackY_250 + iVar2) = 0x2130d9;
          pcVar10 = FS_ParseFile(*(char **)(acStack_230 + iVar2 + -0x1c),
                                 *(char **)(&stack0xfffffdb8 + iVar2),
                                 *(int **)(&stack0xfffffdbc + iVar2));
          *(char **)(acStack_230 + iVar2 + -0x1c) = local_21c;
          *(undefined4 *)(&stack0xfffffdbc + iVar2) = 10;
          local_228 = pcVar10;
          *(undefined4 *)(&stack0xfffffdb8 + iVar2) = 0;
          *(undefined4 *)((int)&sStackY_250 + iVar2) = 0x2130f8;
          lVar7 = strtol(*(char **)(acStack_230 + iVar2 + -0x1c),
                         *(char ***)(&stack0xfffffdb8 + iVar2),*(int *)(&stack0xfffffdbc + iVar2));
          this->m_iBaseResY = lVar7;
        }
        else {
          pcVar10 = (char *)(this->m_ImageID).m_Size;
          iVar8 = (this->m_ImageID).m_Memory.m_NumAllocated;
          pcVar13 = pcVar10;
          if (iVar8 <= (int)pcVar10) {
            *(char **)(&stack0xfffffdb8 + iVar2) = pcVar10 + (1 - iVar8);
            local_228 = pcVar10;
            *(CUtlVector<CVideoMode_Common::bimage_t> **)(acStack_230 + iVar2 + -0x1c) = local_224;
            *(undefined4 *)((int)&sStackY_250 + iVar2) = 0x21312d;
            CUtlMemory<CVideoMode_Common::bimage_t>::Grow
                      (*(CUtlMemory<CVideoMode_Common::bimage_t> **)(acStack_230 + iVar2 + -0x1c),
                       *(int *)(&stack0xfffffdb8 + iVar2));
            pcVar10 = (char *)(this->m_ImageID).m_Size;
            pcVar13 = local_228;
          }
          pcVar10 = pcVar10 + 1;
          (this->m_ImageID).m_Size = (int)pcVar10;
          if (0 < (int)(pcVar10 + (-1 - (int)pcVar13))) {
            pbVar12 = (this->m_ImageID).m_Memory.m_pMemory;
            *(int *)(&stack0xfffffdbc + iVar2) = (int)(pcVar10 + (-1 - (int)pcVar13)) * 0x18;
            *(bimage_t **)(&stack0xfffffdb8 + iVar2) = pbVar12 + (int)pcVar13;
            *(bimage_t **)(acStack_230 + iVar2 + -0x1c) = pbVar12 + (int)(pcVar13 + 1);
            *(undefined4 *)((int)&sStackY_250 + iVar2) = 0x213087;
            memmove(*(void **)(acStack_230 + iVar2 + -0x1c),*(void **)(&stack0xfffffdb8 + iVar2),
                    *(size_t *)(&stack0xfffffdbc + iVar2));
          }
          pbVar12 = (this->m_ImageID).m_Memory.m_pMemory;
          pcVar11[0] = '\0';
          pcVar11[1] = '\0';
          pcVar11[2] = '\x04';
          pcVar11[3] = '\0';
          pbVar12 = pbVar12 + (int)pcVar13;
          *(undefined4 *)((int)&sStackY_250 + iVar2) = 0x212f02;
          pbVar5 = malloc(*(size_t *)(acStack_230 + iVar2 + -0x1c));
          pbVar12->buffer = pbVar5;
          *(int **)(&stack0xfffffdc4 + iVar2) = &pbVar12->height;
          *(int **)(&stack0xfffffdc0 + iVar2) = &pbVar12->width;
          *(undefined4 *)(&stack0xfffffdbc + iVar2) = 0x40000;
          *(byte **)(&stack0xfffffdb8 + iVar2) = pbVar5;
          *(char **)(acStack_230 + iVar2 + -0x1c) = local_21c;
          *(undefined4 *)((int)&sStackY_250 + iVar2) = 0x212f27;
          qVar6 = LoadTGA(*(char **)(acStack_230 + iVar2 + -0x1c),
                          *(uchar **)(&stack0xfffffdb8 + iVar2),*(int *)(&stack0xfffffdbc + iVar2),
                          *(int **)(&stack0xfffffdc0 + iVar2),*(int **)(&stack0xfffffdc4 + iVar2));
          if (qVar6 == false) {
            piVar1 = &(this->m_ImageID).m_Size;
            *piVar1 = *piVar1 + -1;
            return;
          }
          *(undefined4 *)(&stack0xfffffdbc + iVar2) = 0;
          pcVar10 = local_220;
          *(char **)(&stack0xfffffdb8 + iVar2) = local_21c;
          *(char **)(acStack_230 + iVar2 + -0x1c) = pcVar10;
          *(undefined4 *)((int)&sStackY_250 + iVar2) = 0x212f47;
          pcVar10 = FS_ParseFile(*(char **)(acStack_230 + iVar2 + -0x1c),
                                 *(char **)(&stack0xfffffdb8 + iVar2),
                                 *(int **)(&stack0xfffffdbc + iVar2));
          *(char **)(acStack_230 + iVar2 + -0x1c) = local_21c;
          *(char **)(&stack0xfffffdb8 + iVar2) = "scaled";
          local_228 = pcVar10;
          *(undefined4 *)((int)&sStackY_250 + iVar2) = 0x212f60;
          iVar8 = strcasecmp(*(char **)(acStack_230 + iVar2 + -0x1c),
                             *(char **)(&stack0xfffffdb8 + iVar2));
          pcVar10 = local_228;
          pbVar12->scaled = iVar8 == 0;
          *(undefined4 *)(&stack0xfffffdbc + iVar2) = 0;
          *(char **)(&stack0xfffffdb8 + iVar2) = local_21c;
          *(char **)(acStack_230 + iVar2 + -0x1c) = pcVar10;
          *(undefined4 *)((int)&sStackY_250 + iVar2) = 0x212f7e;
          pcVar10 = FS_ParseFile(*(char **)(acStack_230 + iVar2 + -0x1c),
                                 *(char **)(&stack0xfffffdb8 + iVar2),
                                 *(int **)(&stack0xfffffdbc + iVar2));
          *(char **)(acStack_230 + iVar2 + -0x1c) = local_21c;
          *(undefined4 *)(&stack0xfffffdbc + iVar2) = 10;
          local_228 = pcVar10;
          *(undefined4 *)(&stack0xfffffdb8 + iVar2) = 0;
          *(undefined4 *)((int)&sStackY_250 + iVar2) = 0x212f9d;
          lVar7 = strtol(*(char **)(acStack_230 + iVar2 + -0x1c),
                         *(char ***)(&stack0xfffffdb8 + iVar2),*(int *)(&stack0xfffffdbc + iVar2));
          pcVar10 = local_228;
          pbVar12->x = lVar7;
          *(undefined4 *)(&stack0xfffffdbc + iVar2) = 0;
          *(char **)(&stack0xfffffdb8 + iVar2) = local_21c;
          *(char **)(acStack_230 + iVar2 + -0x1c) = pcVar10;
          *(undefined4 *)((int)&sStackY_250 + iVar2) = 0x212fb8;
          pcVar10 = FS_ParseFile(*(char **)(acStack_230 + iVar2 + -0x1c),
                                 *(char **)(&stack0xfffffdb8 + iVar2),
                                 *(int **)(&stack0xfffffdbc + iVar2));
          *(undefined4 *)(&stack0xfffffdbc + iVar2) = 10;
          *(char **)(acStack_230 + iVar2 + -0x1c) = local_21c;
          local_228 = pcVar10;
          *(undefined4 *)(&stack0xfffffdb8 + iVar2) = 0;
          *(undefined4 *)((int)&sStackY_250 + iVar2) = 0x212fd7;
          lVar7 = strtol(*(char **)(acStack_230 + iVar2 + -0x1c),
                         *(char ***)(&stack0xfffffdb8 + iVar2),*(int *)(&stack0xfffffdbc + iVar2));
          pbVar12->y = lVar7;
        }
        if (local_228 == (char *)0x0) {
          return;
        }
        pcVar10 = local_228;
        if (*local_228 == '\0') {
          return;
        }
      }
    }
  }
  return;
}


// CVideoMode_Common::MaxBitsPerPixel  @ 002121c0
/* DWARF original prototype: int MaxBitsPerPixel(CVideoMode_Common * this) */

int __thiscall CVideoMode_Common::MaxBitsPerPixel(CVideoMode_Common *this)

{
  return 0x20;
}


// CVideoMode_Common::ReleaseFullScreen  @ 00212200
/* DWARF original prototype: void ReleaseFullScreen(CVideoMode_Common * this) */

void __thiscall CVideoMode_Common::ReleaseFullScreen(CVideoMode_Common *this)

{
  return;
}


// CVideoMode_Common::ReleaseVideo  @ 00212230
/* DWARF original prototype: void ReleaseVideo(CVideoMode_Common * this) */

void __thiscall CVideoMode_Common::ReleaseVideo(CVideoMode_Common *this)

{
  return;
}


// CVideoMode_Common::RestoreVideo  @ 00212220
/* DWARF original prototype: void RestoreVideo(CVideoMode_Common * this) */

void __thiscall CVideoMode_Common::RestoreVideo(CVideoMode_Common *this)

{
  return;
}


// CVideoMode_Common::SetInitialized  @ 00212160
/* DWARF original prototype: void SetInitialized(CVideoMode_Common * this, bool init) */

void __thiscall CVideoMode_Common::SetInitialized(CVideoMode_Common *this,bool init)

{
  this->m_bInitialized = init;
  return;
}


// CVideoMode_Common::Shutdown  @ 002123a0
/* DWARF original prototype: void Shutdown(CVideoMode_Common * this) */

void __thiscall CVideoMode_Common::Shutdown(CVideoMode_Common *this)

{
  _func_int_varargs **pp_Var1;
  int iVar2;
  
  (*(this->super_IVideoMode)._vptr_IVideoMode[0x11])(this);
  iVar2 = (*(this->super_IVideoMode)._vptr_IVideoMode[8])(this);
  if ((char)iVar2 == '\0') {
    return;
  }
  (*(this->super_IVideoMode)._vptr_IVideoMode[9])(this,0);
  videomode = (IVideoMode *)0x0;
  pp_Var1 = (this->super_IVideoMode)._vptr_IVideoMode;
  this->m_nGameMode = 0;
                    /* WARNING: Could not recover jumptable at 0x002123f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pp_Var1[0xf])();
  return;
}


// CVideoMode_Common::UpdateWindowPosition  @ 00212250
/* DWARF original prototype: void UpdateWindowPosition(CVideoMode_Common * this) */

void __thiscall CVideoMode_Common::UpdateWindowPosition(CVideoMode_Common *this)

{
  RECT local_2c;
  int local_1c;
  int local_18;
  int local_14;
  int local_10 [2];
  
                    /* Unresolved local var: RECT window_rect@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int cx@[???]
                       Unresolved local var: int cy@[???] */
  (*game->_vptr_IGame[10])(game,&local_1c,&local_18,&local_14,local_10);
  local_2c.left = local_1c;
  local_2c.right = local_1c + local_14;
  local_2c.top = local_18;
  local_2c.bottom = local_18 + local_10[0];
  VID_UpdateWindowVars(&local_2c,local_14 / 2 + local_1c,local_10[0] / 2 + local_18);
  return;
}


// CVideoMode_Common::~CVideoMode_Common  @ 00212520
/* DWARF original prototype: void ~CVideoMode_Common(CVideoMode_Common * this, int __in_chrg) */

void __thiscall CVideoMode_Common::~CVideoMode_Common(CVideoMode_Common *this,int __in_chrg)

{
  int iVar1;
  bimage_t *__ptr;
  
  iVar1 = (this->m_ImageID).m_Memory.m_GrowSize;
  (this->super_IVideoMode)._vptr_IVideoMode = (_func_int_varargs **)&PTR___cxa_pure_virtual_002954c8
  ;
  (this->m_ImageID).m_Size = 0;
  if (-1 < iVar1) {
    __ptr = (this->m_ImageID).m_Memory.m_pMemory;
    if (__ptr != (bimage_t *)0x0) {
      free(__ptr);
      (this->m_ImageID).m_Memory.m_pMemory = (bimage_t *)0x0;
      iVar1 = (this->m_ImageID).m_Memory.m_GrowSize;
      (this->m_ImageID).m_Memory.m_NumAllocated = 0;
      if (iVar1 < 0) {
        return;
      }
    }
    (this->m_ImageID).m_Memory.m_NumAllocated = 0;
  }
  return;
}


// CVideoMode_Common::~CVideoMode_Common  @ 00212580
/* DWARF original prototype: void ~CVideoMode_Common(CVideoMode_Common * this, int __in_chrg) */

void __thiscall CVideoMode_Common::~CVideoMode_Common(CVideoMode_Common *this,int __in_chrg)

{
  int iVar1;
  bimage_t *__ptr;
  
  iVar1 = (this->m_ImageID).m_Memory.m_GrowSize;
  (this->super_IVideoMode)._vptr_IVideoMode = (_func_int_varargs **)&PTR___cxa_pure_virtual_002954c8
  ;
  (this->m_ImageID).m_Size = 0;
  if (-1 < iVar1) {
    __ptr = (this->m_ImageID).m_Memory.m_pMemory;
    if (__ptr != (bimage_t *)0x0) {
      free(__ptr);
      (this->m_ImageID).m_Memory.m_pMemory = (bimage_t *)0x0;
      iVar1 = (this->m_ImageID).m_Memory.m_GrowSize;
      (this->m_ImageID).m_Memory.m_NumAllocated = 0;
      if (iVar1 < 0) goto LAB_002125d4;
    }
    (this->m_ImageID).m_Memory.m_NumAllocated = 0;
  }
LAB_002125d4:
  operator_delete(this);
  return;
}


// CVideoMode_OpenGL::CVideoMode_OpenGL  @ 00212930
/* DWARF original prototype: void CVideoMode_OpenGL(CVideoMode_OpenGL * this, bool windowed) */

void __thiscall CVideoMode_OpenGL::CVideoMode_OpenGL(CVideoMode_OpenGL *this,bool windowed)

{
  (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_pMemory = (bimage_t *)0x0;
  (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_NumAllocated = 0;
  (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_GrowSize = 0;
  (this->super_CVideoMode_Common).m_ImageID.m_Size = 0;
  (this->super_CVideoMode_Common).m_nNumModes = 0;
  (this->super_CVideoMode_Common).m_nGameMode = 0;
  (this->super_CVideoMode_Common).m_safeMode.width = 0x280;
  (this->super_CVideoMode_Common).m_bInitialized = false;
  (this->super_CVideoMode_Common).m_safeMode.height = 0x1e0;
  (this->super_CVideoMode_Common).m_safeMode.bpp = 0x20;
  (this->super_CVideoMode_Common).super_IVideoMode._vptr_IVideoMode =
       (_func_int_varargs **)&PTR_GetName_00295528;
  (this->super_CVideoMode_Common).m_bWindowed = windowed;
  return;
}


// CVideoMode_OpenGL::ChangeDisplaySettingsToFullscreen  @ 00212430
/* DWARF original prototype: void ChangeDisplaySettingsToFullscreen(CVideoMode_OpenGL * this) */

void __thiscall CVideoMode_OpenGL::ChangeDisplaySettingsToFullscreen(CVideoMode_OpenGL *this)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: vmode_t * mode@[???]
                       Unresolved local var: int iScreenMode@[???] */
  iVar1 = (*(this->super_CVideoMode_Common).super_IVideoMode._vptr_IVideoMode[7])(this);
  if ((char)iVar1 == '\0') {
    iVar1 = (*(this->super_CVideoMode_Common).super_IVideoMode._vptr_IVideoMode[4])(this);
    if (iVar1 != 0) {
                    /* Unresolved local var: vmode_t * mode@[???]
                       Unresolved local var: int iScreenMode@[???] */
      iVar1 = 1;
      if (bNeedsFullScreenModeSwitch < 1) {
        iVar1 = 0x1001;
      }
      if (ChangeDisplaySettingsToFullscreen::lexical_block_0::iLastScreenMode != iVar1) {
        iVar2 = (*game->_vptr_IGame[6])(game);
        SDL_SetWindowFullscreen(iVar2,0);
      }
      iVar2 = (*game->_vptr_IGame[6])(game);
      SDL_SetWindowFullscreen(iVar2,iVar1);
      ChangeDisplaySettingsToFullscreen::lexical_block_0::iLastScreenMode = iVar1;
      return;
    }
  }
  return;
}


// CVideoMode_OpenGL::FlipScreen  @ 00212240
/* DWARF original prototype: void FlipScreen(CVideoMode_OpenGL * this) */

void __thiscall CVideoMode_OpenGL::FlipScreen(CVideoMode_OpenGL *this)

{
  Sys_Error("This shouldn\'t be called\n");
  return;
}


// CVideoMode_OpenGL::GetName  @ 00214070
/* DWARF original prototype: char * GetName(CVideoMode_OpenGL * this) */

char * __thiscall CVideoMode_OpenGL::GetName(CVideoMode_OpenGL *this)

{
  return "gl";
}


// CVideoMode_OpenGL::Init  @ 00214020
/* DWARF original prototype: bool Init(CVideoMode_OpenGL * this, void * pvInstance) */

bool __thiscall CVideoMode_OpenGL::Init(CVideoMode_OpenGL *this,void *pvInstance)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  CVideoMode_Common *this_00;
  void *in_stack_ffffffe8;
  
                    /* Unresolved local var: bool bret@[DW_OP_reg3(EBX)]
                       Unresolved local var: int x@[???]
                       Unresolved local var: bool bAllowForceRes@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int bitsperpixel@[???]
                       Unresolved local var: int maxbits@[???]
                       Unresolved local var: int iOK@[???]
                       Unresolved local var: int i@[???] */
  this_00 = (CVideoMode_Common *)game;
  iVar2 = (*game->_vptr_IGame[4])();
  if ((char)iVar2 == '\0') {
    uVar3 = 0;
    bVar1 = false;
  }
  else {
    bVar1 = CVideoMode_Common::Init(this_00,in_stack_ffffffe8);
    uVar3 = (uint)bVar1;
  }
  (*(this->super_CVideoMode_Common).super_IVideoMode._vptr_IVideoMode[9])(this,uVar3);
  return bVar1;
}


// CVideoMode_OpenGL::ReleaseFullScreen  @ 002124e0
/* DWARF original prototype: void ReleaseFullScreen(CVideoMode_OpenGL * this) */

void __thiscall CVideoMode_OpenGL::ReleaseFullScreen(CVideoMode_OpenGL *this)

{
  int iVar1;
  
  iVar1 = (*(this->super_CVideoMode_Common).super_IVideoMode._vptr_IVideoMode[7])(this);
  if ((char)iVar1 == '\0') {
    iVar1 = (*game->_vptr_IGame[6])(game);
    SDL_SetWindowFullscreen(iVar1,0);
  }
  return;
}


// CVideoMode_OpenGL::ReleaseVideo  @ 00212400
/* DWARF original prototype: void ReleaseVideo(CVideoMode_OpenGL * this) */

void __thiscall CVideoMode_OpenGL::ReleaseVideo(CVideoMode_OpenGL *this)

{
  int iVar1;
  
  iVar1 = (*(this->super_CVideoMode_Common).super_IVideoMode._vptr_IVideoMode[7])(this);
  if ((char)iVar1 != '\0') {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0021242d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(this->super_CVideoMode_Common).super_IVideoMode._vptr_IVideoMode[0x11])();
  return;
}


// CVideoMode_OpenGL::RestoreVideo  @ 00212860
/* DWARF original prototype: void RestoreVideo(CVideoMode_OpenGL * this) */

void __thiscall CVideoMode_OpenGL::RestoreVideo(CVideoMode_OpenGL *this)

{
  int iVar1;
  
  iVar1 = (*(this->super_CVideoMode_Common).super_IVideoMode._vptr_IVideoMode[7])(this);
  if ((char)iVar1 != '\0') {
    return;
  }
  CVideoMode_Common::AdjustWindowForMode(&this->super_CVideoMode_Common);
  (*game->_vptr_IGame[6])(game);
  SDL_ShowWindow();
  return;
}


// CVideoMode_OpenGL::~CVideoMode_OpenGL  @ 00214080
/* DWARF original prototype: void ~CVideoMode_OpenGL(CVideoMode_OpenGL * this, int __in_chrg) */

void __thiscall CVideoMode_OpenGL::~CVideoMode_OpenGL(CVideoMode_OpenGL *this,int __in_chrg)

{
  int iVar1;
  bimage_t *__ptr;
  
  iVar1 = (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_GrowSize;
  (this->super_CVideoMode_Common).super_IVideoMode._vptr_IVideoMode =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_002954c8;
  (this->super_CVideoMode_Common).m_ImageID.m_Size = 0;
  if (-1 < iVar1) {
    __ptr = (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_pMemory;
    if (__ptr != (bimage_t *)0x0) {
      free(__ptr);
      (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_pMemory = (bimage_t *)0x0;
      iVar1 = (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_GrowSize;
      (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_NumAllocated = 0;
      if (iVar1 < 0) goto LAB_002140d4;
    }
    (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_NumAllocated = 0;
  }
LAB_002140d4:
  operator_delete(this);
  return;
}


// CVideoMode_OpenGL::~CVideoMode_OpenGL  @ 002140f0
/* DWARF original prototype: void ~CVideoMode_OpenGL(CVideoMode_OpenGL * this, int __in_chrg) */

void __thiscall CVideoMode_OpenGL::~CVideoMode_OpenGL(CVideoMode_OpenGL *this,int __in_chrg)

{
  int iVar1;
  bimage_t *__ptr;
  
  iVar1 = (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_GrowSize;
  (this->super_CVideoMode_Common).super_IVideoMode._vptr_IVideoMode =
       (_func_int_varargs **)&PTR___cxa_pure_virtual_002954c8;
  (this->super_CVideoMode_Common).m_ImageID.m_Size = 0;
  if (-1 < iVar1) {
    __ptr = (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_pMemory;
    if (__ptr != (bimage_t *)0x0) {
      free(__ptr);
      (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_pMemory = (bimage_t *)0x0;
      iVar1 = (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_GrowSize;
      (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_NumAllocated = 0;
      if (iVar1 < 0) {
        return;
      }
    }
    (this->super_CVideoMode_Common).m_ImageID.m_Memory.m_NumAllocated = 0;
  }
  return;
}


