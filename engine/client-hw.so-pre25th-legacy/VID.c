// VID_AllocBuffers  @ 001d84b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int VID_AllocBuffers(void)

{
  return 1;
}


// VID_Init  @ 001d7dc0
int VID_Init(ushort *palette)

{
  int iVar1;
  
                    /* Unresolved local var: int iVidCmd@[???] */
  Cvar_RegisterVariable(&gl_ztrick);
  Cvar_RegisterVariable(&gl_vsync);
  iVar1 = COM_CheckParm("-gl_log");
  if (iVar1 != 0) {
    Cmd_AddCommand("gl_log",GLimp_EnableLogging);
  }
  return 1;
}


// VID_ShiftPalette  @ 001d73d0
void VID_ShiftPalette(ushort *palette)

{
  return;
}


// VID_TakeSnapshot  @ 001d7e10
void VID_TakeSnapshot(char *pFilename)

{
  undefined1 uVar1;
  FileHandle_t file;
  int iVar2;
  undefined1 *p;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 local_52;
  uint local_4e;
  uint local_4a;
  undefined2 local_46;
  undefined2 local_44;
  undefined4 local_42;
  undefined4 local_3e;
  undefined4 local_3a;
  undefined4 local_36;
  undefined4 local_32;
  undefined4 local_2e;
  undefined2 local_2a;
  int local_28;
  undefined2 local_24;
  undefined2 local_22;
  undefined4 local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: BITMAPFILEHEADER hdr@[???]
                       Unresolved local var: BITMAPINFOHEADER bi@[???]
                       Unresolved local var: DWORD imageSize@[???]
                       Unresolved local var: uchar * hp@[???]
                       Unresolved local var: uchar b@[???]
                       Unresolved local var: uchar * pBlue@[???]
                       Unresolved local var: uchar * pRed@[???]
                       Unresolved local var: int width@[???]
                       Unresolved local var: int height@[???] */
  if ((0 < bDoScaledFBO) ||
     (iVar8 = VideoMode_IsWindowed(), uVar5 = vid.width, uVar7 = vid.height, iVar8 != 0)) {
    uVar5 = window_rect.right - window_rect.left;
    uVar7 = window_rect.bottom - window_rect.top;
  }
  iVar8 = uVar5 * uVar7;
  file = FS_OpenPathID(pFilename,"wb","GAMECONFIG");
  if (file == (FileHandle_t)0x0) {
    Sys_Error("Couldn\'t create file for snapshot.\n");
  }
  local_28 = iVar8 * 3 + 0x36;
  local_2a = 0x4d42;
  local_24 = 0;
  local_22 = 0;
  local_20 = 0x36;
  iVar2 = FS_Write(&local_2a,0xe,1,file);
  if (iVar2 != 0xe) {
    Sys_Error("Couldn\'t write file header to snapshot.\n");
  }
  local_42 = 0;
  local_3e = 0;
  local_3a = 0;
  local_36 = 0;
  local_32 = 0;
  local_2e = 0;
  local_52 = 0x28;
  local_46 = 1;
  local_44 = 0x18;
  local_4e = uVar5;
  local_4a = uVar7;
  iVar2 = FS_Write(&local_52,0x28,1,file);
  if (iVar2 != 0x28) {
    Sys_Error("Couldn\'t write bitmap header to snapshot.\n");
  }
  iVar2 = uVar5 * 3;
  p = Mem_Malloc(iVar2 * uVar7 + 4);
  if (p == (undefined1 *)0x0) {
    Sys_Error("Couldn\'t allocate bitmap header to snapshot.\n");
  }
  (*qglPixelStorei)(0xd05,1);
  (*qglReadPixels)(0,0,uVar5,uVar7,0x1907,0x1401,p);
  if (0 < iVar8) {
    puVar4 = p;
    do {
      uVar1 = puVar4[2];
      puVar4[2] = *puVar4;
      *puVar4 = uVar1;
      puVar4 = puVar4 + 3;
    } while (puVar4 != p + iVar8 * 3);
  }
  if (0 < (int)uVar7) {
    uVar6 = 0;
    iVar8 = (uVar5 * -3 & 3) + iVar2;
    puVar4 = p;
    do {
                    /* Unresolved local var: int newWidth@[???] */
      iVar3 = FS_Write(puVar4,iVar8,1,file);
      if (iVar3 != iVar8) {
        Sys_Error("Couldn\'t write bitmap data snapshot.\n");
      }
      uVar6 = uVar6 + 1;
      puVar4 = puVar4 + iVar2;
    } while (uVar6 != uVar7);
  }
  Mem_Free(p);
  FS_Close(file);
  return;
}


// VID_TakeSnapshotRect  @ 001d80b0
void VID_TakeSnapshotRect(char *pFilename,int x,int y,int w,int h)

{
  undefined1 uVar1;
  FileHandle_t file;
  int iVar2;
  undefined1 *p;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 local_52;
  int local_4e;
  int local_4a;
  undefined2 local_46;
  undefined2 local_44;
  undefined4 local_42;
  undefined4 local_3e;
  undefined4 local_3a;
  undefined4 local_36;
  undefined4 local_32;
  undefined4 local_2e;
  undefined2 local_2a;
  int local_28;
  undefined2 local_24;
  undefined2 local_22;
  undefined4 local_20;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: BITMAPFILEHEADER hdr@[???]
                       Unresolved local var: BITMAPINFOHEADER bi@[???]
                       Unresolved local var: int imageSize@[???]
                       Unresolved local var: uchar * hp@[???]
                       Unresolved local var: uchar b@[???]
                       Unresolved local var: uchar * pBlue@[???]
                       Unresolved local var: uchar * pRed@[???] */
  file = FS_OpenPathID(pFilename,"wb","GAMECONFIG");
  iVar5 = h * w;
  if (file == (FileHandle_t)0x0) {
    Sys_Error("Couldn\'t create file for snapshot.\n");
  }
  local_28 = iVar5 * 3 + 0x36;
  local_2a = 0x4d42;
  local_24 = 0;
  local_22 = 0;
  local_20 = 0x36;
  iVar2 = FS_Write(&local_2a,0xe,1,file);
  if (iVar2 != 0xe) {
    Sys_Error("Couldn\'t write file header to snapshot.\n");
  }
  local_52 = 0x28;
  local_4e = w;
  local_46 = 1;
  local_4a = h;
  local_3e = 0;
  local_3a = 0;
  local_36 = 0;
  local_32 = 0;
  local_2e = 0;
  local_44 = 0x18;
  local_42 = 0;
  iVar2 = FS_Write(&local_52,0x28,1,file);
  if (iVar2 != 0x28) {
    Sys_Error("Couldn\'t write bitmap header to snapshot.\n");
  }
  p = Mem_Malloc(iVar5 * 3);
  if (p == (undefined1 *)0x0) {
    Sys_Error("Couldn\'t allocate bitmap header to snapshot.\n");
  }
  (*qglPixelStorei)(0xd05,1);
  (*qglReadPixels)(x,y,w,h,0x1907,0x1401,p);
  if (0 < iVar5) {
    puVar4 = p;
    do {
      uVar1 = puVar4[2];
      puVar4[2] = *puVar4;
      *puVar4 = uVar1;
      puVar4 = puVar4 + 3;
    } while (puVar4 != p + iVar5 * 3);
  }
  if (0 < h) {
    iVar2 = (w * -3 & 3U) + w * 3;
    iVar5 = 0;
    puVar4 = p;
    do {
                    /* Unresolved local var: int newWidth@[???] */
      iVar3 = FS_Write(puVar4,iVar2,1,file);
      if (iVar2 != iVar3) {
        Sys_Error("Couldn\'t write bitmap data snapshot.\n");
      }
      iVar5 = iVar5 + 1;
      puVar4 = puVar4 + w * 3;
    } while (iVar5 != h);
  }
  Mem_Free(p);
  FS_Close(file);
  return;
}


// VID_UpdateWindowVars  @ 001d83b0
void VID_UpdateWindowVars(RECT *prc,int x,int y)

{
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  window_rect.left = prc->left;
  window_rect.right = prc->right;
  window_rect.top = prc->top;
  window_rect.bottom = prc->bottom;
  if (pmainwindow != (HWND *)0x0) {
                    /* Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
    SDL_GetWindowSize(*pmainwindow,&local_1c,&local_18);
    SDL_GetWindowPosition(*pmainwindow,&local_14,&local_10);
    prc->left = local_14;
    prc->right = local_14 + local_1c;
    prc->top = local_10;
    prc->bottom = local_10 + local_18;
    window_center_x = local_1c / 2 + local_14;
    window_center_y = local_18 / 2 + local_10;
    return;
  }
  window_center_x = x;
  window_center_y = y;
  return;
}


// VID_WriteBuffer  @ 001d8310
void VID_WriteBuffer(char *pFilename)

{
  char local_110 [259];
  undefined1 local_d;
  
                    /* Unresolved local var: char[260] filename@[???] */
  if (pFilename != (char *)0x0) {
    Q_strncpy(VID_WriteBuffer::basefilename,pFilename,0x103);
    local_d = 0;
    VID_WriteBuffer::filenumber = 1;
  }
  snprintf(local_110,0x103,"%s%05d.bmp",VID_WriteBuffer::basefilename,VID_WriteBuffer::filenumber);
  local_d = 0;
  VID_TakeSnapshot(local_110);
  VID_WriteBuffer::filenumber = VID_WriteBuffer::filenumber + 1;
  return;
}


