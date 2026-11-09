// VID_AllocBuffers  @ 00182aa0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int VID_AllocBuffers(void)

{
  return 1;
}


// VID_Init  @ 00182360
int VID_Init(word *palette)

{
  int iVar1;
  
                    /* Unresolved local var: int iVidCmd@[???] */
  Cvar_RegisterVariable(&gl_ztrick);
  Cvar_RegisterVariable(&gl_vsync);
  Cvar_RegisterVariable(&gl_lowlatency);
  Cvar_RegisterVariable(&gl_lowlatency_minslop_ms);
  Cvar_RegisterVariable(&gl_lowlatency_maxslop_ms);
  Cvar_RegisterVariable(&gl_lowlatency_debugoutput);
  iVar1 = COM_CheckParm("-gl_log");
  if (iVar1 != 0) {
    Cmd_AddCommand("gl_log",GLimp_EnableLogging);
  }
  return 1;
}


// VID_ShiftPalette  @ 001817f0
void VID_ShiftPalette(word *palette)

{
  return;
}


// VID_TakeSnapshot  @ 001823e0
void VID_TakeSnapshot(char *pFilename)

{
  undefined1 uVar1;
  FileHandle_t file;
  int iVar2;
  undefined1 *p;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  uint local_68;
  undefined2 local_52;
  int local_50;
  undefined2 local_4c;
  undefined2 local_4a;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  uint local_3c;
  undefined2 local_38;
  undefined2 local_36;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: BITMAPFILEHEADER hdr@[???]
                       Unresolved local var: BITMAPINFOHEADER bi@[???]
                       Unresolved local var: DWORD imageSize@[???]
                       Unresolved local var: byte * hp@[???]
                       Unresolved local var: byte b@[???]
                       Unresolved local var: byte * pBlue@[???]
                       Unresolved local var: byte * pRed@[???]
                       Unresolved local var: int width@[???]
                       Unresolved local var: int height@[???] */
  if (bDoScaledFBO < 1) {
    iVar7 = VideoMode_IsWindowed();
    if (iVar7 == 0) {
      local_68 = vid.height;
      uVar5 = vid.width;
      goto LAB_00182416;
    }
  }
  local_68 = window_rect.bottom - window_rect.top;
  uVar5 = window_rect.right - window_rect.left;
LAB_00182416:
  iVar7 = local_68 * uVar5;
  file = FS_OpenPathID(pFilename,"wb","GAMECONFIG");
  if (file == (FileHandle_t)0x0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Couldn\'t create file for snapshot.\n");
  }
  local_50 = iVar7 * 3 + 0x36;
  local_48 = 0x36;
  local_52 = 0x4d42;
  local_4c = 0;
  local_4a = 0;
  iVar2 = FS_Write(&local_52,0xe,1,file);
  if (iVar2 != 0xe) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Couldn\'t write file header to snapshot.\n");
  }
  local_44 = 0x28;
  local_3c = local_68;
  local_34 = 0;
  local_30 = 0;
  local_20 = 0;
  local_38 = 1;
  local_36 = 0x18;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_40 = uVar5;
  iVar2 = FS_Write(&local_44,0x28,1,file);
  if (iVar2 != 0x28) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Couldn\'t write bitmap header to snapshot.\n");
  }
  iVar2 = uVar5 * 3;
  p = Mem_Malloc(local_68 * iVar2 + 4);
  if (p != (undefined1 *)0x0) {
    (*qglPixelStorei)(0xd05,1);
    (*qglReadPixels)(0,0,uVar5,local_68,0x1907,0x1401,p);
    if (0 < iVar7) {
      puVar8 = p;
      do {
        puVar3 = puVar8 + 3;
        uVar1 = puVar8[2];
        puVar8[2] = *puVar8;
        *puVar8 = uVar1;
        puVar8 = puVar3;
      } while (puVar3 != p + iVar7 * 3);
    }
    if (0 < (int)local_68) {
      uVar6 = 0;
      iVar7 = (uVar5 * -3 & 3) + iVar2;
      puVar8 = p;
      do {
                    /* Unresolved local var: int newWidth@[???] */
        iVar4 = FS_Write(puVar8,iVar7,1,file);
        if (iVar4 != iVar7) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("Couldn\'t write bitmap data snapshot.\n");
        }
        uVar6 = uVar6 + 1;
        puVar8 = puVar8 + iVar2;
      } while (local_68 != uVar6);
    }
    Mem_Free(p);
    FS_Close(file);
    return;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Couldn\'t allocate bitmap header to snapshot.\n");
}


// VID_TakeSnapshotRect  @ 00182670
void VID_TakeSnapshotRect(char *pFilename,int x,int y,int w,int h)

{
  undefined1 uVar1;
  FileHandle_t file;
  int iVar2;
  undefined1 *p;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined2 local_52;
  int local_50;
  undefined2 local_4c;
  undefined2 local_4a;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  undefined2 local_38;
  undefined2 local_36;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: BITMAPFILEHEADER hdr@[???]
                       Unresolved local var: BITMAPINFOHEADER bi@[???]
                       Unresolved local var: int imageSize@[???]
                       Unresolved local var: byte * hp@[???]
                       Unresolved local var: byte b@[???]
                       Unresolved local var: byte * pBlue@[???]
                       Unresolved local var: byte * pRed@[???] */
  file = FS_OpenPathID(pFilename,"wb","GAMECONFIG");
  iVar5 = h * w;
  if (file == (FileHandle_t)0x0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Couldn\'t create file for snapshot.\n");
  }
  local_50 = iVar5 * 3 + 0x36;
  local_48 = 0x36;
  local_52 = 0x4d42;
  local_4c = 0;
  local_4a = 0;
  iVar2 = FS_Write(&local_52,0xe,1,file);
  if (iVar2 != 0xe) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Couldn\'t write file header to snapshot.\n");
  }
  local_44 = 0x28;
  local_40 = w;
  local_38 = 1;
  local_3c = h;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_20 = 0;
  local_36 = 0x18;
  local_28 = 0;
  local_24 = 0;
  iVar2 = FS_Write(&local_44,0x28,1,file);
  if (iVar2 != 0x28) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("Couldn\'t write bitmap header to snapshot.\n");
  }
  p = Mem_Malloc(iVar5 * 3);
  if (p != (undefined1 *)0x0) {
    (*qglPixelStorei)(0xd05,1);
    (*qglReadPixels)(x,y,w,h,0x1907,0x1401,p);
    if (0 < iVar5) {
      puVar6 = p;
      do {
        puVar3 = puVar6 + 3;
        uVar1 = puVar6[2];
        puVar6[2] = *puVar6;
        *puVar6 = uVar1;
        puVar6 = puVar3;
      } while (puVar3 != p + iVar5 * 3);
    }
    if (0 < h) {
      iVar5 = 0;
      iVar2 = (w * -3 & 3U) + w * 3;
      puVar6 = p;
      do {
                    /* Unresolved local var: int newWidth@[???] */
        iVar4 = FS_Write(puVar6,iVar2,1,file);
        if (iVar2 != iVar4) {
                    /* WARNING: Subroutine does not return */
          Sys_Error("Couldn\'t write bitmap data snapshot.\n");
        }
        iVar5 = iVar5 + 1;
        puVar6 = puVar6 + w * 3;
      } while (h != iVar5);
    }
    Mem_Free(p);
    FS_Close(file);
    return;
  }
                    /* WARNING: Subroutine does not return */
  Sys_Error("Couldn\'t allocate bitmap header to snapshot.\n");
}


// VID_UpdateWindowVars  @ 001829b0
void VID_UpdateWindowVars(RECT *prc,int x,int y)

{
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  if (pmainwindow == (HWND *)0x0) {
    window_center_x = x;
    window_center_y = y;
  }
  else {
                    /* Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
    SDL_GetWindowSize(*pmainwindow,&local_1c,&local_18);
    SDL_GetWindowPosition(*pmainwindow,&local_14,&local_10);
    window_center_x = local_1c / 2 + local_14;
    window_center_y = local_18 / 2 + local_10;
    prc->top = local_10;
    prc->left = local_14;
    prc->right = local_14 + local_1c;
    prc->bottom = local_10 + local_18;
  }
  window_rect.left = prc->left;
  window_rect.right = prc->right;
  window_rect.top = prc->top;
  window_rect.bottom = prc->bottom;
  return;
}


// VID_WriteBuffer  @ 001828d0
void VID_WriteBuffer(char *pFilename)

{
  int in_GS_OFFSET;
  char local_114 [259];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: char[260] filename@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (pFilename != (char *)0x0) {
    Q_strncpy(VID_WriteBuffer::basefilename,pFilename,0x103);
    local_11 = 0;
    VID_WriteBuffer::filenumber = 1;
  }
  __snprintf_chk(local_114,0x103,1,0x104,"%s%05d.bmp",VID_WriteBuffer::basefilename,
                 VID_WriteBuffer::filenumber);
  local_11 = 0;
  VID_TakeSnapshot(local_114);
  VID_WriteBuffer::filenumber = VID_WriteBuffer::filenumber + 1;
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


