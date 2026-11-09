// COM_AddAppDirectory  @ 000a56d0
void COM_AddAppDirectory(char *pszBaseDir,char *appName)

{
  FS_AddSearchPath(pszBaseDir,"PLATFORM");
  return;
}


// COM_AddAppDirectoryToSearchPath  @ 00167a80
void COM_AddAppDirectoryToSearchPath(char *pszBaseDir,char *appName)

{
  (*g_engdstAddrs.COM_AddAppDirectoryToSearchPath)(&pszBaseDir,&appName);
  COM_AddAppDirectory(pszBaseDir,appName);
  return;
}


// COM_AddDefaultDir  @ 000a56e0
void COM_AddDefaultDir(char *pszDir)

{
  if ((pszDir != (char *)0x0) && (*pszDir != '\0')) {
    FileSystem_AddFallbackGameDir(pszDir);
    return;
  }
  return;
}


// COM_AddExtension  @ 000a43d0
void COM_AddExtension(char *path,char *extension,int size)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char cVar4;
  char *pcVar5;
  char *pcVar6;
  
  if ((extension == (char *)0x0 || size < 1) || (path == (char *)0x0)) {
    return;
  }
  if (*extension == '.') {
    cVar4 = *path;
    pcVar6 = extension + 1;
    if (cVar4 != '\0') goto LAB_000a441f;
LAB_000a4590:
    pcVar5 = "";
LAB_000a4508:
    if (pcVar6 == (char *)0x0) goto LAB_000a450c;
  }
  else {
                    /* Unresolved local var: char * cur@[???]
                       Unresolved local var: int i@[???] */
    cVar4 = *path;
    pcVar6 = extension;
    if (cVar4 != '\0') {
LAB_000a441f:
      iVar2 = -1;
      pcVar5 = path;
      do {
        if (cVar4 == '.') {
          iVar2 = (int)pcVar5 - (int)path;
        }
        pcVar5 = pcVar5 + 1;
        cVar4 = *pcVar5;
      } while (cVar4 != '\0');
      if (iVar2 < 0) goto LAB_000a4590;
      pcVar3 = path + iVar2;
                    /* Unresolved local var: int i@[???] */
      cVar4 = *pcVar3;
      while ((cVar4 != '\0' && (cVar4 != '.'))) {
        pcVar3 = pcVar3 + 1;
        cVar4 = *pcVar3;
      }
      pcVar5 = "";
      if (cVar4 != '\0') {
        cVar4 = pcVar3[1];
        if (cVar4 == '\0') {
          iVar2 = 0;
        }
        else {
          cVar1 = pcVar3[2];
          COM_FileExtension::exten[0] = cVar4;
          if (cVar1 == '\0') {
            iVar2 = 1;
          }
          else {
            cVar4 = pcVar3[3];
            COM_FileExtension::exten[1] = cVar1;
            if (cVar4 == '\0') {
              iVar2 = 2;
            }
            else {
              cVar1 = pcVar3[4];
              COM_FileExtension::exten[2] = cVar4;
              if (cVar1 == '\0') {
                iVar2 = 3;
              }
              else {
                cVar4 = pcVar3[5];
                COM_FileExtension::exten[3] = cVar1;
                if (cVar4 == '\0') {
                  iVar2 = 4;
                }
                else {
                  cVar1 = pcVar3[6];
                  COM_FileExtension::exten[4] = cVar4;
                  if (cVar1 == '\0') {
                    iVar2 = 5;
                  }
                  else {
                    COM_FileExtension::exten[5] = cVar1;
                    if (pcVar3[7] == '\0') {
                      iVar2 = 6;
                    }
                    else {
                      iVar2 = 7;
                      COM_FileExtension::exten[6] = pcVar3[7];
                    }
                  }
                }
              }
            }
          }
        }
        COM_FileExtension::exten[iVar2] = '\0';
        pcVar5 = COM_FileExtension::exten;
      }
      goto LAB_000a4508;
    }
    pcVar5 = "";
  }
  for (; *pcVar5 == *pcVar6; pcVar5 = pcVar5 + 1) {
    if (*pcVar5 == '\0') {
      return;
    }
    pcVar6 = pcVar6 + 1;
  }
LAB_000a450c:
  if (*extension != '.') {
    strncat(path,".",size - 1U);
  }
  strncat(path,extension,size - 1U);
  return;
}


// COM_BinPrintf  @ 0009e860
char * COM_BinPrintf(uchar *buf,int nLen)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uchar *puVar6;
  char *pcVar7;
  int in_GS_OFFSET;
  undefined1 local_2a [10];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar7 = COM_BinPrintf::szReturn;
                    /* Unresolved local var: uchar c@[???]
                       Unresolved local var: char[10] szChunk@[???]
                       Unresolved local var: int i@[???] */
  for (iVar3 = 0x400; iVar3 != 0; iVar3 = iVar3 + -1) {
    pcVar7[0] = '\0';
    pcVar7[1] = '\0';
    pcVar7[2] = '\0';
    pcVar7[3] = '\0';
    pcVar7 = pcVar7 + 4;
  }
  if (0 < nLen) {
    puVar6 = buf + nLen;
    do {
      __snprintf_chk(local_2a,10,1,10,0x255a73,*buf);
      puVar5 = (uint *)COM_BinPrintf::szReturn;
      do {
        puVar4 = puVar5;
        uVar1 = *puVar4 + 0xfefefeff & ~*puVar4;
        uVar2 = uVar1 & 0x80808080;
        puVar5 = puVar4 + 1;
      } while (uVar2 == 0);
      if ((uVar1 & 0x8080) == 0) {
        puVar5 = (uint *)((int)puVar4 + 6);
        uVar2 = uVar2 >> 0x10;
      }
      buf = buf + 1;
      __strncat_chk(COM_BinPrintf::szReturn,local_2a,
                    0xfff - ((int)puVar5 + (-0x2e3903 - (uint)CARRY1((byte)uVar2,(byte)uVar2))),
                    0x1000);
    } while (buf != puVar6);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return COM_BinPrintf::szReturn;
}


// COM_BitOpsInit  @ 0009f750
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void COM_BitOpsInit(void)

{
  uint uVar1;
  uint uVar2;
  
  bfwrite.nCurOutputBit = 0;
  bfwrite.pOutByte = (uchar *)0x0;
  bfwrite.pbuf = (sizebuf_t *)0x0;
  uVar1 = 0;
  do {
    *(undefined4 *)((int)&bfread.msg_readcount + uVar1) = 0;
    uVar2 = uVar1 + 8;
    *(undefined4 *)((int)&bfread.pbuf + uVar1) = 0;
    uVar1 = uVar2;
  } while (uVar2 < 0x18);
  return;
}


// COM_BlockSequenceCRCByte  @ 000a8160
byte COM_BlockSequenceCRCByte(byte *base,int length,int sequence)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  uint *puVar8;
  uint *dest;
  uint uVar9;
  int in_GS_OFFSET;
  undefined4 local_60;
  int local_20;
  
                    /* Unresolved local var: CRC32_t crc@[???]
                       Unresolved local var: byte * p@[???]
                       Unresolved local var: byte[64] chkb@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (sequence < 0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("sequence < 0, in COM_BlockSequenceCRCByte\n");
  }
  dest = &local_60;
  uVar3 = (uint)sequence % 0x3fc;
  if (0x3c < length) {
    length = 0x3c;
  }
  Q_memcpy(dest,base,length);
                    /* Unresolved local var: CRC32_t ulCrc@[???]
                       Unresolved local var: uchar * pb@[???]
                       Unresolved local var: uint nFront@[???]
                       Unresolved local var: int nMain@[???] */
  *(undefined1 *)((int)&local_60 + length) = *(undefined1 *)((int)pulCRCTable + uVar3);
  *(undefined1 *)((int)&local_60 + length + 1) = *(undefined1 *)((int)pulCRCTable + uVar3 + 1);
  *(undefined1 *)((int)&local_60 + length + 2) = *(undefined1 *)((int)pulCRCTable + uVar3 + 2);
  *(undefined1 *)((int)&local_60 + length + 3) = *(undefined1 *)((int)pulCRCTable + uVar3 + 3);
  uVar9 = length + 4;
  uVar3 = 0xffffffff;
  do {
    bVar1 = (byte)uVar3;
    puVar8 = dest;
    switch(uVar9) {
    case 0:
switchD_000a8204_caseD_0:
      if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return ~(byte)uVar3;
    case 1:
      goto switchD_000a8204_caseD_1;
    case 3:
      puVar8 = (uint *)((int)dest + 1);
      uVar3 = uVar3 >> 8 ^ pulCRCTable[(byte)(bVar1 ^ (byte)*dest)];
    case 2:
      dest = (uint *)((int)puVar8 + 1);
      uVar3 = uVar3 >> 8 ^ pulCRCTable[(byte)((byte)uVar3 ^ (byte)*puVar8)];
      goto switchD_000a8204_caseD_1;
    case 4:
      goto LAB_000a8250;
    case 5:
      goto switchD_000a8204_caseD_5;
    case 6:
      goto switchD_000a8204_caseD_6;
    case 7:
      puVar8 = (uint *)((int)dest + 1);
      uVar3 = uVar3 >> 8 ^ pulCRCTable[(byte)(bVar1 ^ (byte)*dest)];
      goto switchD_000a8204_caseD_6;
    default:
      uVar4 = (uint)dest & 3;
      puVar8 = dest;
      if (uVar4 == 2) {
LAB_000a8405:
        dest = (uint *)((int)puVar8 + 1);
        uVar3 = uVar3 >> 8 ^ pulCRCTable[(byte)((byte)uVar3 ^ (byte)*puVar8)];
LAB_000a841a:
        uVar2 = *dest;
        dest = (uint *)((int)dest + 1);
        uVar3 = uVar3 >> 8 ^ pulCRCTable[(byte)((byte)uVar3 ^ (byte)uVar2)];
      }
      else {
        if (uVar4 == 3) {
          puVar8 = (uint *)((int)dest + 1);
          uVar3 = uVar3 >> 8 ^ pulCRCTable[(byte)(bVar1 ^ (byte)*dest)];
          goto LAB_000a8405;
        }
        if (uVar4 == 1) goto LAB_000a841a;
      }
      iVar7 = (int)(uVar9 - uVar4) >> 3;
      if (iVar7 != 0) {
        puVar8 = dest + iVar7 * 2;
        puVar5 = dest;
        do {
          puVar6 = puVar5 + 2;
          uVar3 = (uVar3 ^ *puVar5) >> 8 ^ pulCRCTable[(uVar3 ^ *puVar5) & 0xff];
          uVar3 = uVar3 >> 8 ^ pulCRCTable[uVar3 & 0xff];
          uVar3 = uVar3 >> 8 ^ pulCRCTable[uVar3 & 0xff];
          uVar3 = uVar3 >> 8 ^ puVar5[1] ^ pulCRCTable[uVar3 & 0xff];
          uVar3 = uVar3 >> 8 ^ pulCRCTable[uVar3 & 0xff];
          uVar3 = uVar3 >> 8 ^ pulCRCTable[uVar3 & 0xff];
          uVar3 = uVar3 >> 8 ^ pulCRCTable[uVar3 & 0xff];
          uVar3 = uVar3 >> 8 ^ pulCRCTable[uVar3 & 0xff];
          puVar5 = puVar6;
          dest = puVar8;
        } while (puVar6 != puVar8);
      }
      uVar9 = uVar9 - uVar4 & 7;
    }
  } while( true );
switchD_000a8204_caseD_6:
  dest = (uint *)((int)puVar8 + 1);
  uVar3 = uVar3 >> 8 ^ pulCRCTable[(byte)((byte)uVar3 ^ (byte)*puVar8)];
switchD_000a8204_caseD_5:
  uVar9 = *dest;
  dest = (uint *)((int)dest + 1);
  uVar3 = uVar3 >> 8 ^ pulCRCTable[(byte)((byte)uVar3 ^ (byte)uVar9)];
LAB_000a8250:
  uVar3 = (uVar3 ^ *dest) >> 8 ^ pulCRCTable[(uVar3 ^ *dest) & 0xff];
  uVar3 = uVar3 >> 8 ^ pulCRCTable[uVar3 & 0xff];
  uVar3 = uVar3 >> 8 ^ pulCRCTable[uVar3 & 0xff];
  uVar3 = uVar3 >> 8 ^ pulCRCTable[uVar3 & 0xff];
  goto switchD_000a8204_caseD_0;
switchD_000a8204_caseD_1:
  uVar3 = uVar3 >> 8 ^ pulCRCTable[(byte)((byte)uVar3 ^ (byte)*dest)];
  goto switchD_000a8204_caseD_0;
}


// COM_BuildNumber  @ 000e8260
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int COM_BuildNumber(void)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  if (build_number::b == 0) {
    iVar6 = 0;
    iVar7 = 0;
    do {
      iVar3 = Q_strncasecmp(date,mon[iVar6],3);
      if (iVar3 == 0) {
        bVar2 = 1 < iVar6;
        goto LAB_0009a01a;
      }
      pcVar1 = mond + iVar6;
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + *pcVar1;
    } while (iVar6 != 0xb);
    bVar2 = true;
LAB_0009a01a:
    lVar4 = strtol(date + 4,(char **)0x0,10);
    uVar5 = strtol(date + 7,(char **)0x0,10);
    iVar6 = (int)((float)(int)(uVar5 - 0x76d) * 365.25) + iVar7 + -1 + lVar4;
    if ((uVar5 & 3) == 0) {
      iVar6 = (iVar6 + 1) - (uint)!bVar2;
    }
    build_number::b = iVar6 + -0x88b3;
  }
  return build_number::b;
}


// COM_CheckParm  @ 000a4920
int COM_CheckParm(char *parm)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
                    /* Unresolved local var: int i@[???] */
  if (1 < com_argc) {
    iVar2 = 1;
    do {
      pcVar3 = com_argv[iVar2];
      if (((pcVar3 != (char *)0x0) && (parm != (char *)0x0)) &&
         (cVar1 = *pcVar3, pcVar4 = parm, cVar1 == *parm)) {
        do {
          if (cVar1 == '\0') {
            return iVar2;
          }
          pcVar4 = pcVar4 + 1;
          cVar1 = *pcVar4;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 == *pcVar3);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != com_argc);
  }
  return 0;
}


// COM_ClearCustomizationList  @ 0009d7c0
void COM_ClearCustomizationList(customization_t *pHead,qboolean bCleanDecals)

{
  customization_s *pcVar1;
  customization_s *p;
  void *pvVar2;
  undefined4 *p_00;
  int iVar3;
  cache_user_t *c;
  
                    /* Unresolved local var: customization_t * pNext@[???]
                       Unresolved local var: customization_t * pCurrent@[???]
                       Unresolved local var: int i@[???] */
  p = pHead->pNext;
  while (p != (customization_s *)0x0) {
    pcVar1 = p->pNext;
    if ((p->bInUse != false) &&
       (((p->pBuffer == (void *)0x0 || (Mem_Free(p->pBuffer), p->bInUse != false)) &&
        (p_00 = p->pInfo, p_00 != (undefined4 *)0x0)))) {
      if ((p->resource).type == t_decal) {
                    /* Unresolved local var: cachewad_t * pWad@[???]
                       Unresolved local var: cacheentry_t * pic@[???] */
        if ((bCleanDecals != false) && (cls.state == ca_active)) {
          R_DecalRemoveAll(~(uint)(p->resource).playernum);
          p_00 = p->pInfo;
        }
        iVar3 = 0;
        Mem_Free((void *)p_00[4]);
        c = (cache_user_t *)(p_00[1] + 0x40);
        if (0 < (int)p_00[2]) {
          do {
            pvVar2 = Cache_Check(c);
            if (pvVar2 != (void *)0x0) {
              Cache_Free(c);
            }
            iVar3 = iVar3 + 1;
            c = c + 0x11;
          } while (iVar3 < (int)p_00[2]);
        }
        Mem_Free((void *)*p_00);
        Mem_Free((void *)p_00[1]);
        p_00 = p->pInfo;
      }
      Mem_Free(p_00);
    }
    Mem_Free(p);
    p = pcVar1;
  }
  pHead->pNext = (customization_s *)0x0;
  return;
}


// COM_CompareFileTime  @ 000a5d10
int COM_CompareFileTime(char *filename1,char *filename2,int *iCompare)

{
  int32 iVar1;
  int32 iVar2;
  int iVar3;
  
                    /* Unresolved local var: int bRet@[???] */
  *iCompare = 0;
  if ((filename1 == (char *)0x0) || (filename2 == (char *)0x0)) {
    iVar3 = 0;
  }
  else {
                    /* Unresolved local var: int32 ft1@[???]
                       Unresolved local var: int32 ft2@[???] */
    iVar1 = FS_GetFileTime(filename1);
    iVar2 = FS_GetFileTime(filename2);
    if (iVar1 < iVar2) {
      *iCompare = -1;
      return 1;
    }
    iVar3 = 1;
    if (iVar2 < iVar1) {
      *iCompare = 1;
      return iVar3;
    }
  }
  return iVar3;
}


// COM_CopyFile  @ 000a4ef0
void COM_CopyFile(char *netpath,char *cachepath)

{
  FileHandle_t file;
  uint size;
  char *pcVar1;
  FileHandle_t file_00;
  char cVar2;
  int in_GS_OFFSET;
  undefined1 local_1020 [4096];
  int local_20;
  
                    /* Unresolved local var: FileHandle_t in@[???]
                       Unresolved local var: FileHandle_t out@[???]
                       Unresolved local var: int remaining@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: char[4096] buf@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  file = FS_Open(netpath,"rb");
  if (file != (FileHandle_t)0x0) {
    size = FS_Size(file);
                    /* Unresolved local var: char * ofs@[???]
                       Unresolved local var: char old@[???] */
    pcVar1 = cachepath + 1;
    cVar2 = cachepath[1];
    while (cVar2 != '\0') {
      while ((cVar2 == '/' || (cVar2 == '\\'))) {
        *pcVar1 = '\0';
        FS_CreateDirHierarchy(cachepath,(char *)0x0);
        *pcVar1 = cVar2;
        pcVar1 = pcVar1 + 1;
        cVar2 = *pcVar1;
        if (cVar2 == '\0') goto LAB_000a4f85;
      }
      pcVar1 = pcVar1 + 1;
      cVar2 = *pcVar1;
    }
LAB_000a4f85:
    file_00 = FS_Open(cachepath,"wb");
    for (; size != 0; size = size - 0x1000) {
      if (size < 0x1000) {
        FS_Read(local_1020,size,1,file);
        FS_Write(local_1020,size,1,file_00);
        break;
      }
      FS_Read(local_1020,0x1000,1,file);
      FS_Write(local_1020,0x1000,1,file_00);
    }
    FS_Close(file);
    FS_Close(file_00);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// COM_CopyFileChunk  @ 000a53a0
void COM_CopyFileChunk(FileHandle_t dst,FileHandle_t src,int nSize)

{
  int iVar1;
  int in_GS_OFFSET;
  undefined1 local_420 [1024];
  int local_20;
  
                    /* Unresolved local var: int copysize@[???]
                       Unresolved local var: char[1024] copybuf@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (0x400 < nSize) {
    iVar1 = nSize;
    do {
      iVar1 = iVar1 + -0x400;
      FS_Read(local_420,0x400,1,src);
      FS_Write(local_420,0x400,1,dst);
    } while (0x400 < iVar1);
    nSize = (nSize + -0x400) - (nSize - 0x401U & 0xfffffc00);
  }
  FS_Read(local_420,nSize,1,src);
  FS_Write(local_420,nSize,1,dst);
  FS_Flush(src);
  FS_Flush(dst);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// COM_CreateCustomization  @ 0009d8d0
qboolean COM_CreateCustomization
                   (customization_t *pListHead,resource_t *pResource,int playernumber,int flags,
                   customization_t **pCustomization,int *nLumps)

{
  undefined4 uVar1;
  customization_s *p;
  uint uVar2;
  byte *pbVar3;
  qboolean qVar4;
  cachewad_s *wad;
  
                    /* Unresolved local var: customization_t * pCust@[???]
                       Unresolved local var: qboolean bError@[???] */
  if (pCustomization != (customization_t **)0x0) {
    *pCustomization = (customization_t *)0x0;
  }
  p = Mem_ZeroMalloc(0xa4);
  uVar2 = 0;
  do {
    uVar1 = *(undefined4 *)(pResource->szFileName + uVar2 + 4);
    *(undefined4 *)((p->resource).szFileName + uVar2) =
         *(undefined4 *)(pResource->szFileName + uVar2);
    *(undefined4 *)((p->resource).szFileName + uVar2 + 4) = uVar1;
    uVar2 = uVar2 + 8;
  } while (uVar2 < 0x88);
  if (0 < pResource->nDownloadSize) {
    p->bInUse = true;
    if ((flags & 1U) == 0) {
      pbVar3 = COM_LoadFile(pResource->szFileName,5,(int *)0x0);
      p->pBuffer = pbVar3;
    }
    else {
      qVar4 = HPAK_GetDataPointer("custom.hpk",pResource,&p->pBuffer,(int *)0x0);
      if (qVar4 == false) goto LAB_0009dab0;
    }
    if ((((p->resource).ucFlags & 4) == 0) || ((p->resource).type != t_decal)) {
LAB_0009d968:
      if (pCustomization != (customization_t **)0x0) {
        *pCustomization = p;
      }
      p->pNext = pListHead->pNext;
      pListHead->pNext = p;
      return true;
    }
                    /* Unresolved local var: void * pNewBuffer@[???]
                       Unresolved local var: cachewad_t * pWad@[???] */
    (p->resource).playernum = (uchar)playernumber;
    qVar4 = CustomDecal_Validate(p->pBuffer,pResource->nDownloadSize);
    if (qVar4 != false) {
      if ((flags & 4U) != 0) goto LAB_0009d968;
      wad = Mem_ZeroMalloc(0x30);
      p->pInfo = wad;
      if (((pResource->nDownloadSize - 0x400U < 0x4c01) &&
          (qVar4 = CustomDecal_Init(wad,p->pBuffer,pResource->nDownloadSize,playernumber),
          qVar4 != false)) && (0 < wad->lumpCount)) {
        if (nLumps != (int *)0x0) {
          *nLumps = wad->lumpCount;
        }
        p->bTranslated = true;
        p->nUserData1 = 0;
        p->nUserData2 = wad->lumpCount;
        if ((flags & 2U) != 0) {
          Mem_Free(wad->name);
          Mem_Free(wad->cache);
          Mem_Free(wad->lumps);
          Mem_Free(p->pInfo);
          p->pInfo = (void *)0x0;
        }
        if (qVar4 != false) goto LAB_0009d968;
      }
    }
  }
LAB_0009dab0:
  if (p->pBuffer != (void *)0x0) {
    Mem_Free(p->pBuffer);
  }
  if (p->pInfo != (void *)0x0) {
    Mem_Free(p->pInfo);
  }
  Mem_Free(p);
  return false;
}


// COM_CreatePath  @ 000a4e90
void COM_CreatePath(char *path)

{
  char cVar1;
  char *pcVar2;
  
                    /* Unresolved local var: char * ofs@[???]
                       Unresolved local var: char old@[???] */
  cVar1 = path[1];
  if (cVar1 != '\0') {
    pcVar2 = path + 1;
    do {
      while ((cVar1 == '/' || (cVar1 == '\\'))) {
        *pcVar2 = '\0';
        FS_CreateDirHierarchy(path,(char *)0x0);
        *pcVar2 = cVar1;
        cVar1 = pcVar2[1];
        pcVar2 = pcVar2 + 1;
        if (cVar1 == '\0') {
          return;
        }
      }
      pcVar2 = pcVar2 + 1;
      cVar1 = *pcVar2;
    } while (cVar1 != '\0');
  }
  return;
}


// COM_DefaultExtension  @ 000a45f0
void COM_DefaultExtension(char *path,char *extension)

{
  char cVar1;
  int iVar2;
  char *__s;
  size_t sVar3;
  int iVar4;
  
                    /* Unresolved local var: char * src@[???] */
                    /* Unresolved local var: int count@[???] */
  if ((path == (char *)0x0) || (*path == '\0')) {
    iVar4 = -1;
  }
  else {
    iVar2 = 0;
    do {
      iVar4 = iVar2;
      iVar2 = iVar4 + 1;
    } while (path[iVar4 + 1] != '\0');
  }
  __s = path + iVar4;
  cVar1 = *__s;
  while ((path != __s && (cVar1 != '/'))) {
    if (cVar1 == '.') {
      return;
    }
    __s = __s + -1;
    cVar1 = *__s;
  }
  sVar3 = strlen(__s);
  strncat(path,extension,0x104 - sVar3);
  return;
}


// COM_EntsForPlayerSlots  @ 000a5df0
int COM_EntsForPlayerSlots(int nPlayers)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  
                    /* Unresolved local var: int nMax@[???]
                       Unresolved local var: int nWeaponSlots@[???]
                       Unresolved local var: int i@[???] */
  iVar2 = gmodinfo.num_edicts;
                    /* Unresolved local var: int i@[???] */
  if (1 < com_argc) {
    iVar5 = 1;
    do {
      pcVar4 = com_argv[iVar5];
      if ((pcVar4 != (char *)0x0) && (*pcVar4 == '-')) {
        pcVar3 = "-num_edicts";
        while( true ) {
          pcVar3 = pcVar3 + 1;
          pcVar4 = pcVar4 + 1;
          if (*pcVar3 != *pcVar4) break;
          if (*pcVar3 == '\0') {
            if (iVar5 != 0) {
              lVar1 = strtol(com_argv[iVar5 + 1],(char **)0x0,10);
              if (iVar2 <= lVar1) {
                iVar2 = strtol(com_argv[iVar5 + 1],(char **)0x0,10);
              }
            }
            goto LAB_000a5e4a;
          }
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 != com_argc);
  }
LAB_000a5e4a:
  return (nPlayers + -1) * 0xf + iVar2;
}


// COM_ExpandFilename  @ 000a5050
int COM_ExpandFilename(char *filename)

{
  int in_GS_OFFSET;
  char local_114 [260];
  int local_10;
  
                    /* Unresolved local var: char[260] netpath@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  FS_GetLocalPath(filename,local_114,0x104);
  strcpy(filename,local_114);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return (uint)(*filename != '\0');
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// COM_ExplainDisconnection  @ 0009e960
void COM_ExplainDisconnection(qboolean bPrint,char *fmt,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  __vsnprintf_chk(COM_ExplainDisconnection::string,0x400,1,0x400,fmt,&stack0x0000000c);
  strncpy(gszDisconnectReason,COM_ExplainDisconnection::string,0xff);
  gfExtendedError = true;
  gszDisconnectReason[0xff] = '\0';
  if ((bPrint != false) && (gszDisconnectReason[0] != '#')) {
    Con_Printf("%s\n",gszDisconnectReason);
  }
  return;
}


// COM_ExtendedExplainDisconnection  @ 0009ea00
void COM_ExtendedExplainDisconnection(qboolean bPrint,char *fmt,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  __vsnprintf_chk(COM_ExtendedExplainDisconnection::string,0x400,1,0x400,fmt,&stack0x0000000c);
  strncpy(gszExtendedDisconnectReason,COM_ExtendedExplainDisconnection::string,0xff);
  gszExtendedDisconnectReason[0xff] = '\0';
  if ((bPrint != false) && (gszExtendedDisconnectReason[0] != '#')) {
    Con_Printf("%s\n",gszExtendedDisconnectReason);
  }
  return;
}


// COM_FileBase  @ 000a43a0
void COM_FileBase(char *in,char *out)

{
  COM_FileBase_s(in,out,-1);
  return;
}


// COM_FileBase_s  @ 000a4280
char * COM_FileBase_s(char *in,char *out,int size)

{
  char cVar1;
  size_t __n;
  char cVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int start@[???]
                       Unresolved local var: int end@[???] */
                    /* Unresolved local var: int count@[???] */
  if ((in != (char *)0x0) && (cVar1 = *in, cVar1 != '\0')) {
    iVar4 = 0;
    do {
      iVar3 = iVar4;
      iVar4 = iVar3 + 1;
    } while (in[iVar3 + 1] != '\0');
    if (iVar3 == 0) {
      iVar4 = 0;
      cVar2 = cVar1;
    }
    else {
      cVar2 = in[iVar3];
      iVar4 = iVar3;
      if ((1 < (byte)(cVar2 - 0x2eU)) && (cVar2 != '\\')) {
        while (iVar4 = iVar4 + -1, cVar2 = cVar1, iVar4 != 0) {
          cVar2 = in[iVar4];
          if (((byte)(cVar2 - 0x2eU) < 2) || (cVar2 == '\\')) break;
        }
      }
    }
    iVar4 = iVar4 + -1;
    if (cVar2 != '.') {
      iVar4 = iVar3;
    }
    do {
      if ((in[iVar3] == '/') || (in[iVar3] == '\\')) {
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 - iVar3;
        goto joined_r0x000a4367;
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != -1);
    iVar3 = 0;
joined_r0x000a4367:
    __n = iVar4 + 1;
    if ((size < 0) || ((int)__n < size)) {
      strncpy(out,in + iVar3,__n);
      out[__n] = '\0';
      return out;
    }
  }
  return (char *)0x0;
}


// COM_FileExtension  @ 000a3ee0
char * COM_FileExtension(char *in)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char cVar4;
  
                    /* Unresolved local var: int i@[???] */
  cVar4 = *in;
  if ((cVar4 != '.') && (cVar4 != '\0')) {
    do {
      in = in + 1;
      cVar4 = *in;
      if (cVar4 == '\0') break;
    } while (cVar4 != '.');
  }
  pcVar2 = "";
  if (cVar4 != '\0') {
    cVar4 = in[1];
    if (cVar4 == '\0') {
      iVar3 = 0;
    }
    else {
      cVar1 = in[2];
      COM_FileExtension::exten[0] = cVar4;
      if (cVar1 == '\0') {
        iVar3 = 1;
      }
      else {
        cVar4 = in[3];
        COM_FileExtension::exten[1] = cVar1;
        if (cVar4 == '\0') {
          iVar3 = 2;
        }
        else {
          cVar1 = in[4];
          COM_FileExtension::exten[2] = cVar4;
          if (cVar1 == '\0') {
            iVar3 = 3;
          }
          else {
            cVar4 = in[5];
            COM_FileExtension::exten[3] = cVar1;
            if (cVar4 == '\0') {
              iVar3 = 4;
            }
            else {
              cVar1 = in[6];
              COM_FileExtension::exten[4] = cVar4;
              if (cVar1 == '\0') {
                iVar3 = 5;
              }
              else {
                COM_FileExtension::exten[5] = cVar1;
                if (in[7] == '\0') {
                  iVar3 = 6;
                }
                else {
                  iVar3 = 7;
                  COM_FileExtension::exten[6] = in[7];
                }
              }
            }
          }
        }
      }
    }
    COM_FileExtension::exten[iVar3] = '\0';
    pcVar2 = COM_FileExtension::exten;
  }
  return pcVar2;
}


// COM_FileSize  @ 000a50e0
int COM_FileSize(char *filename)

{
  FileHandle_t file;
  uint uVar1;
  
                    /* Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: int iSize@[???] */
  file = FS_Open(filename,"rb");
  if (file == (FileHandle_t)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = FS_Size(file);
    FS_Close(file);
  }
  return uVar1;
}


// COM_FixSlashes  @ 000a4e60
void COM_FixSlashes(char *pname)

{
  char cVar1;
  
  cVar1 = *pname;
  do {
    if (cVar1 == '\0') {
      return;
    }
    while (cVar1 != '\\') {
      pname = pname + 1;
      cVar1 = *pname;
      if (cVar1 == '\0') {
        return;
      }
    }
    *pname = '/';
    pname = pname + 1;
    cVar1 = *pname;
  } while( true );
}


// COM_FreeFile  @ 000a5370
void COM_FreeFile(void *buffer)

{
  (*g_engdstAddrs.COM_FreeFile)(&buffer);
  if (buffer != (void *)0x0) {
    Mem_Free(buffer);
  }
  return;
}


// COM_GetApproxWavePlayLength  @ 000a6640
uint COM_GetApproxWavePlayLength(char *filepath)

{
  FileHandle_t file;
  uint uVar1;
  int iVar2;
  uint uVar3;
  int in_GS_OFFSET;
  char local_ac [16];
  uint local_9c;
  char local_91 [8];
  char local_89 [4];
  undefined4 auStack_85 [29];
  undefined1 local_11;
  int local_10;
  
                    /* Unresolved local var: FileHandle_t hFile@[???]
                       Unresolved local var: uint filelength@[???]
                       Unresolved local var: int found@[???]
                       Unresolved local var: FormatChunk format@[???]
                       Unresolved local var: FormatChunk * tempFormat@[???]
                       Unresolved local var: uint numMilliseconds@[???]
                       Unresolved local var: char[129] buf@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  file = FS_Open(filepath,"rb");
  if (file != (FileHandle_t)0x0) {
    uVar1 = FS_Size(file);
    FS_Read(local_91,0x80,1,file);
    FS_Close(file);
    local_11 = 0;
    iVar2 = strncasecmp(local_91,"RIFF",4);
    if (iVar2 == 0) {
      iVar2 = strncasecmp(local_89,"WAVE",4);
      uVar3 = 0;
      if (iVar2 == 0) {
        do {
          *(undefined4 *)(local_ac + uVar3) = *(undefined4 *)((int)auStack_85 + uVar3);
          uVar3 = uVar3 + 4;
        } while (uVar3 < 0x18);
        iVar2 = strncasecmp(local_ac,"fmt ",4);
        if (iVar2 == 0) {
          if (local_9c != 0) {
            if (local_9c < 1000) {
              uVar1 = ((uVar1 - 0x80) / local_9c) * 1000;
            }
            else {
              uVar1 = (uVar1 - 0x80) / (local_9c / 1000);
            }
            goto LAB_000a6782;
          }
          Con_Printf("COM_GetApproxWavePlayLength: bad AvgBytesPerSec\n");
        }
      }
    }
  }
  uVar1 = 0;
LAB_000a6782:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// COM_GetGameDir  @ 000a5db0
void COM_GetGameDir(char *szGameDir)

{
  if (szGameDir != (char *)0x0) {
    snprintf(szGameDir,0x103,"%s",com_gamedir);
  }
  return;
}


// COM_HasFileExtension  @ 000a40c0
qboolean COM_HasFileExtension(char *in,char *ext)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char cVar4;
  char *pcVar5;
  
  if (in == (char *)0x0) {
    return false;
  }
  if (ext == (char *)0x0) {
    return false;
  }
  if (*ext == '.') {
    cVar4 = *in;
    ext = ext + 1;
    if (cVar4 != '\0') goto LAB_000a40ef;
LAB_000a4230:
    pcVar5 = "";
  }
  else {
                    /* Unresolved local var: char * cur@[???]
                       Unresolved local var: int i@[???] */
    cVar4 = *in;
    if (cVar4 == '\0') {
      pcVar5 = "";
      goto LAB_000a41de;
    }
LAB_000a40ef:
    iVar2 = -1;
    pcVar5 = in;
    do {
      if (cVar4 == '.') {
        iVar2 = (int)pcVar5 - (int)in;
      }
      pcVar5 = pcVar5 + 1;
      cVar4 = *pcVar5;
    } while (cVar4 != '\0');
    if (iVar2 < 0) goto LAB_000a4230;
    pcVar3 = in + iVar2;
                    /* Unresolved local var: int i@[???] */
    cVar4 = *pcVar3;
    if ((cVar4 != '.') && (cVar4 != '\0')) {
      do {
        pcVar3 = pcVar3 + 1;
        cVar4 = *pcVar3;
        if (cVar4 == '\0') break;
      } while (cVar4 != '.');
    }
    pcVar5 = "";
    if (cVar4 != '\0') {
      cVar4 = pcVar3[1];
      if (cVar4 == '\0') {
        iVar2 = 0;
      }
      else {
        cVar1 = pcVar3[2];
        COM_FileExtension::exten[0] = cVar4;
        if (cVar1 == '\0') {
          iVar2 = 1;
        }
        else {
          cVar4 = pcVar3[3];
          COM_FileExtension::exten[1] = cVar1;
          if (cVar4 == '\0') {
            iVar2 = 2;
          }
          else {
            cVar1 = pcVar3[4];
            COM_FileExtension::exten[2] = cVar4;
            if (cVar1 == '\0') {
              iVar2 = 3;
            }
            else {
              cVar4 = pcVar3[5];
              COM_FileExtension::exten[3] = cVar1;
              if (cVar4 == '\0') {
                iVar2 = 4;
              }
              else {
                cVar1 = pcVar3[6];
                COM_FileExtension::exten[4] = cVar4;
                if (cVar1 == '\0') {
                  iVar2 = 5;
                }
                else {
                  COM_FileExtension::exten[5] = cVar1;
                  if (pcVar3[7] == '\0') {
                    iVar2 = 6;
                  }
                  else {
                    iVar2 = 7;
                    COM_FileExtension::exten[6] = pcVar3[7];
                  }
                }
              }
            }
          }
        }
      }
      COM_FileExtension::exten[iVar2] = '\0';
      pcVar5 = COM_FileExtension::exten;
    }
  }
  if (ext == (char *)0x0) {
    return false;
  }
LAB_000a41de:
  cVar4 = *ext;
  if (cVar4 == *pcVar5) {
    do {
      if (cVar4 == '\0') {
        return true;
      }
      pcVar5 = pcVar5 + 1;
      cVar4 = *pcVar5;
      ext = ext + 1;
    } while (cVar4 == *ext);
  }
  return false;
}


// COM_HexConvert  @ 0009e7b0
void COM_HexConvert(char *pszInput,int nInputLength,uchar *pOutput)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  
                    /* Unresolved local var: uchar * p@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char * pIn@[???] */
  if (0 < nInputLength) {
    iVar4 = 0;
    do {
      while( true ) {
        cVar1 = pszInput[iVar4];
        if ((byte)(cVar1 - 0x30U) < 10) {
          bVar3 = cVar1 << 4;
        }
        else if ((byte)(cVar1 + 0xbfU) < 6) {
          bVar3 = (cVar1 + -0x37) * '\x10';
        }
        else {
          bVar3 = 0;
          if ((byte)(cVar1 + 0x9fU) < 6) {
            bVar3 = (cVar1 + -0x57) * '\x10';
          }
        }
        cVar1 = pszInput[iVar4 + 1];
        bVar2 = cVar1 - 0x30;
        if (9 < bVar2) break;
LAB_0009e7f9:
        iVar4 = iVar4 + 2;
        *pOutput = bVar2 | bVar3;
        pOutput = pOutput + 1;
        if (nInputLength <= iVar4) {
          return;
        }
      }
      if ((byte)(cVar1 + 0xbfU) < 6) {
        bVar2 = cVar1 - 0x37;
        goto LAB_0009e7f9;
      }
      bVar2 = 0x30;
      if (5 < (byte)(cVar1 + 0x9fU)) goto LAB_0009e7f9;
      iVar4 = iVar4 + 2;
      *pOutput = cVar1 + 0xa9U | bVar3;
      pOutput = pOutput + 1;
    } while (iVar4 < nInputLength);
  }
  return;
}


// COM_Init  @ 000a4b40
/* WARNING: Removing unreachable block (ram,0x000a4b4a) */

void COM_Init(char *basedir)

{
  uint uVar1;
  uint uVar2;
  
  bigendien = false;
  BigShort = ShortSwap;
  LittleShort = ShortNoSwap;
  BigLong = LongSwap;
  LittleLong = LongNoSwap;
  BigFloat = FloatSwap;
  LittleFloat = FloatNoSwap;
  bfwrite.nCurOutputBit = 0;
  bfwrite.pOutByte = (uchar *)0x0;
  bfwrite.pbuf = (sizebuf_t *)0x0;
  uVar1 = 0;
  do {
    *(undefined4 *)((int)&bfread.msg_readcount + uVar1) = 0;
    uVar2 = uVar1 + 8;
    *(undefined4 *)((int)&bfread.pbuf + uVar1) = 0;
    uVar1 = uVar2;
  } while (uVar2 < 0x18);
  return;
}


// COM_InitArgv  @ 000a4980
/* WARNING: Removing unreachable block (ram,0x000a4af3) */
/* WARNING: Removing unreachable block (ram,0x000a4b0d) */
/* WARNING: Removing unreachable block (ram,0x000a4ac1) */
/* WARNING: Removing unreachable block (ram,0x000a4ab1) */

void COM_InitArgv(int argc,char **argv)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  
                    /* Unresolved local var: qboolean safe@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int n@[???] */
  iVar7 = 0;
  iVar9 = 0;
  if (argc < 1) {
    com_cmdline[0] = '\0';
    com_argc = 0;
  }
  else {
    do {
      cVar1 = *argv[iVar7];
      iVar3 = iVar9;
      while (cVar1 != '\0') {
        iVar5 = iVar3 + 1;
        com_cmdline[iVar3] = cVar1;
        if (iVar5 == 0xff) goto LAB_000a49ce;
        iVar3 = iVar5;
        cVar1 = argv[iVar7][iVar5 - iVar9];
      }
      iVar7 = iVar7 + 1;
      iVar5 = iVar3 + 1;
      com_cmdline[iVar3] = ' ';
      if ((0x31 < iVar7) || (argc <= iVar7)) goto LAB_000a49ce;
      iVar9 = iVar5;
    } while (iVar5 != 0xff);
    iVar5 = 0xff;
LAB_000a49ce:
    com_cmdline[iVar5] = '\0';
    bVar2 = false;
    iVar9 = 0;
    do {
      iVar7 = iVar9;
      largv[iVar7] = argv[iVar7];
      pcVar4 = argv[iVar7];
      if ((pcVar4 != (char *)0x0) && (*pcVar4 == '-')) {
        pcVar8 = "-safe";
        do {
          pcVar8 = pcVar8 + 1;
          pcVar4 = pcVar4 + 1;
          if (*pcVar8 != *pcVar4) goto joined_r0x000a4a17;
        } while (*pcVar8 != '\0');
        bVar2 = true;
      }
joined_r0x000a4a17:
    } while ((iVar7 + 1 < argc) && (iVar9 = iVar7 + 1, iVar7 + 1 < 0x32));
    com_argc = iVar7 + 1;
    if (bVar2) {
      uVar6 = 0;
      do {
        *(undefined4 *)((int)largv + uVar6 + com_argc * 4) = *(undefined4 *)((int)safeargvs + uVar6)
        ;
        uVar6 = uVar6 + 4;
      } while (uVar6 < 0x1c);
      com_argc = iVar7 + 8;
    }
  }
  com_argv = largv;
  largv[com_argc] = " ";
  return;
}


// COM_LastFileExtension  @ 000a3fb0
char * COM_LastFileExtension(char *in)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char cVar5;
  
                    /* Unresolved local var: char * cur@[???]
                       Unresolved local var: int i@[???] */
  if ((in != (char *)0x0) && (cVar5 = *in, cVar5 != '\0')) {
    iVar2 = -1;
    pcVar4 = in;
    do {
      if (cVar5 == '.') {
        iVar2 = (int)pcVar4 - (int)in;
      }
      pcVar4 = pcVar4 + 1;
      cVar5 = *pcVar4;
    } while (cVar5 != '\0');
    if (-1 < iVar2) {
      pcVar4 = in + iVar2;
                    /* Unresolved local var: int i@[???] */
      cVar5 = *pcVar4;
      while ((cVar5 != '\0' && (cVar5 != '.'))) {
        pcVar4 = pcVar4 + 1;
        cVar5 = *pcVar4;
      }
      pcVar3 = "";
      if (cVar5 != '\0') {
        cVar5 = pcVar4[1];
        if (cVar5 == '\0') {
          iVar2 = 0;
        }
        else {
          cVar1 = pcVar4[2];
          COM_FileExtension::exten[0] = cVar5;
          if (cVar1 == '\0') {
            iVar2 = 1;
          }
          else {
            cVar5 = pcVar4[3];
            COM_FileExtension::exten[1] = cVar1;
            if (cVar5 == '\0') {
              iVar2 = 2;
            }
            else {
              cVar1 = pcVar4[4];
              COM_FileExtension::exten[2] = cVar5;
              if (cVar1 == '\0') {
                iVar2 = 3;
              }
              else {
                cVar5 = pcVar4[5];
                COM_FileExtension::exten[3] = cVar1;
                if (cVar5 == '\0') {
                  iVar2 = 4;
                }
                else {
                  cVar1 = pcVar4[6];
                  COM_FileExtension::exten[4] = cVar5;
                  if (cVar1 == '\0') {
                    iVar2 = 5;
                  }
                  else {
                    COM_FileExtension::exten[5] = cVar1;
                    if (pcVar4[7] == '\0') {
                      iVar2 = 6;
                    }
                    else {
                      iVar2 = 7;
                      COM_FileExtension::exten[6] = pcVar4[7];
                    }
                  }
                }
              }
            }
          }
        }
        COM_FileExtension::exten[iVar2] = '\0';
        pcVar3 = COM_FileExtension::exten;
      }
      return pcVar3;
    }
  }
  return "";
}


// COM_ListMaps  @ 000a5950
void COM_ListMaps(char *pszSubString)

{
  char *__s1;
  uint uVar1;
  char *pcVar2;
  int iVar3;
  FileHandle_t file;
  size_t __n;
  int in_GS_OFFSET;
  int local_1128;
  int local_111c [31];
  undefined4 local_10a0;
  undefined4 local_109c;
  undefined2 local_1098;
  undefined1 local_1096;
  char local_1060 [64];
  char local_1020 [4096];
  int local_20;
  
                    /* Unresolved local var: int nSubStringLen@[???]
                       Unresolved local var: int showOutdated@[???]
                       Unresolved local var: char * findfn@[???] */
  __n = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((pszSubString != (char *)0x0) && (*pszSubString != '\0')) {
    __n = strlen(pszSubString);
  }
  Con_Printf("-------------\n");
  local_1128 = 1;
                    /* Unresolved local var: char[64] mapwild@[???]
                       Unresolved local var: char[4096] curDir@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: dheader_t header@[???]
                       Unresolved local var: char[64] sz@[???] */
  do {
    local_10a0 = 0x7370616d;
    local_1096 = 0;
    local_109c = 0x622e2a2f;
    local_1098 = 0x7073;
    __s1 = Sys_FindFirst((char *)&local_10a0,(char *)0x0);
    while (__s1 != (char *)0x0) {
      uVar1 = __snprintf_chk(local_1020,0x1000,1,0x1000,0x255b2c,__s1);
      if (uVar1 < 0x1000) {
        FS_GetLocalPath(local_1020,local_1020,0x1000);
        pcVar2 = strstr(local_1020,com_gamedir);
        if ((pcVar2 != (char *)0x0) &&
           ((__n == 0 || (iVar3 = strncasecmp(__s1,pszSubString,__n), iVar3 == 0)))) {
          uVar1 = 0;
          do {
            *(undefined4 *)((int)local_111c + uVar1) = 0;
            *(undefined4 *)((int)local_111c + uVar1 + 4) = 0;
            uVar1 = uVar1 + 8;
          } while (uVar1 < 0x78);
          *(undefined4 *)((int)local_111c + uVar1) = 0;
          uVar1 = __snprintf_chk(local_1060,0x40,1,0x40,0x255b2c,__s1);
          if (0x3f < uVar1) goto LAB_000a5ba8;
          file = FS_Open(local_1060,"rb");
          if (file == (FileHandle_t)0x0) {
            Con_Printf("Could not open map %s\n",local_1060);
          }
          else {
            FS_Read(local_111c,0x7c,1,file);
            FS_Close(file);
          }
                    /* Unresolved local var: qboolean valid@[???] */
          if (local_111c[0] == 0x1e) {
            if (local_1128 == 0) {
              Con_Printf("%s\n",__s1);
            }
          }
          else if (local_1128 != 0) {
            Con_Printf("OUTDATED:  %s\n",__s1);
          }
        }
      }
      else {
LAB_000a5ba8:
        Con_Printf("Map name too long: %s\n",__s1);
      }
      __s1 = Sys_FindNext((char *)0x0);
    }
    Sys_FindClose();
    local_1128 = local_1128 + -1;
    if (local_1128 == -1) {
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
  } while( true );
}


// COM_LoadCacheFile  @ 000a5660
void COM_LoadCacheFile(char *path,cache_user_s *cu)

{
  loadcache = cu;
  COM_LoadFile(path,3,(int *)0x0);
  return;
}


// COM_LoadFile  @ 000a5130
byte * COM_LoadFile(char *path,int usehunk,int *pLength)

{
  FileHandle_t file;
  uint size;
  char *pcVar1;
  byte *pOutput;
  int in_GS_OFFSET;
  uint *local_1024;
  char *local_1020 [4];
  char local_1010 [32];
  undefined1 local_ff0;
  int local_10;
  
                    /* Unresolved local var: FileHandle_t hFile@[???]
                       Unresolved local var: byte * buf@[???]
                       Unresolved local var: char[4096] base@[???]
                       Unresolved local var: int len@[???] */
  local_1020[0] = path;
  local_1024 = (uint *)pLength;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  (*g_engdstAddrs.COM_LoadFile)(local_1020,&usehunk,(int **)&local_1024);
  if (local_1024 != (uint *)0x0) {
    *local_1024 = 0;
  }
  file = FS_Open(local_1020[0],"rb");
  if (file == (FileHandle_t)0x0) {
    pOutput = (byte *)0x0;
    goto LAB_000a5250;
  }
  size = FS_Size(file);
  pcVar1 = COM_FileBase_s(local_1020[0],local_1010,0x1000);
  if (pcVar1 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("COM_LoadFile: bad path name for %s",local_1020[0]);
  }
  local_ff0 = 0;
  if (usehunk == 1) {
    pOutput = Hunk_AllocName(size + 1,local_1010);
  }
  else if (usehunk == 2) {
LAB_000a52e6:
    pOutput = Hunk_TempAlloc(size + 1);
  }
  else if (usehunk == 0) {
    pOutput = Z_Malloc(size + 1);
  }
  else if (usehunk == 3) {
    pOutput = Cache_Alloc(loadcache,size + 1,local_1010);
  }
  else if (usehunk == 4) {
    pOutput = loadbuf;
    if (loadsize <= (int)size) goto LAB_000a52e6;
  }
  else {
    if (usehunk != 5) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("COM_LoadFile: bad usehunk");
    }
    pOutput = Mem_Malloc(size + 1);
  }
  if (pOutput == (byte *)0x0) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("COM_LoadFile: not enough space for %s",local_1020[0]);
  }
  pOutput[size] = '\0';
  FS_Read(pOutput,size,1,file);
  FS_Close(file);
  if (local_1024 != (uint *)0x0) {
    *local_1024 = size;
  }
LAB_000a5250:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pOutput;
}


// COM_LoadFileForMe  @ 000a5ce0
byte * COM_LoadFileForMe(char *filename,int *pLength)

{
  byte *pbVar1;
  
  pbVar1 = COM_LoadFile(filename,5,pLength);
  return pbVar1;
}


// COM_LoadFileLimit  @ 000a54e0
byte * COM_LoadFileLimit(char *path,int pos,int cbmax,int *pcbread,FileHandle_t *phFile)

{
  uint size;
  byte *pOutput;
  FileHandle_t file;
  
                    /* Unresolved local var: FileHandle_t hFile@[???]
                       Unresolved local var: byte * buf@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: int cbload@[???] */
  file = *phFile;
  if ((file == (FileHandle_t)0x0) && (file = FS_Open(path,"rb"), file == (FileHandle_t)0x0)) {
    return (byte *)0x0;
  }
  size = FS_Size(file);
  if ((int)size < pos) {
                    /* WARNING: Subroutine does not return */
    Sys_Error("COM_LoadFileLimit: invalid seek position for %s",path);
  }
  FS_Seek(file,pos,FILESYSTEM_SEEK_HEAD);
  if (cbmax < (int)size) {
    size = cbmax;
  }
  *pcbread = size;
  pOutput = Hunk_TempAlloc(size + 1);
  if (pOutput == (byte *)0x0) {
    if (path != (char *)0x0) {
                    /* WARNING: Subroutine does not return */
      Sys_Error("COM_LoadFileLimit: not enough space for %s",path);
    }
    FS_Close(file);
    pOutput = (byte *)0x0;
  }
  else {
    pOutput[size] = '\0';
    FS_Read(pOutput,size,1,file);
    *phFile = file;
  }
  return pOutput;
}


// COM_LoadHunkFile  @ 000a5600
byte * COM_LoadHunkFile(char *path)

{
  byte *pbVar1;
  
  pbVar1 = COM_LoadFile(path,1,(int *)0x0);
  return pbVar1;
}


// COM_LoadStackFile  @ 000a5690
byte * COM_LoadStackFile(char *path,void *buffer,int bufsize,int *length)

{
  byte *pbVar1;
  
                    /* Unresolved local var: byte * buf@[???] */
  loadbuf = buffer;
  loadsize = bufsize;
  pbVar1 = COM_LoadFile(path,4,length);
  return pbVar1;
}


// COM_LoadTempFile  @ 000a5630
byte * COM_LoadTempFile(char *path,int *pLength)

{
  byte *pbVar1;
  
  pbVar1 = COM_LoadFile(path,2,pLength);
  return pbVar1;
}


// COM_Log  @ 000a5c20
void COM_Log(char *pszFile,char *fmt,...)

{
  FileHandle_t file;
  int in_GS_OFFSET;
  undefined1 local_410 [1024];
  int local_10;
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: char[1024] string@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: char * pfilename@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (pszFile == (char *)0x0) {
    pszFile = "c:\\hllog.txt";
  }
  __vsnprintf_chk(local_410,0x400,1,0x400,fmt,&stack0x0000000c);
  file = FS_Open(pszFile,"a+t");
  if (file != (FileHandle_t)0x0) {
    FS_FPrintf(file,"%s",local_410);
    FS_Close(file);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// COM_Munge  @ 000a6070
void COM_Munge(uchar *data,int len,int seq)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  byte bVar7;
  byte local_2a;
  byte local_29;
  undefined4 local_14;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int mungelen@[???]
                       Unresolved local var: int32 c@[???]
                       Unresolved local var: int32 * pc@[???]
                       Unresolved local var: uchar * p@[???]
                       Unresolved local var: int j@[???] */
  uVar5 = len & 0xfffffffc;
  uVar2 = uVar5 + 3;
  if (-1 < (int)uVar5) {
    uVar2 = uVar5;
  }
  if (0 < (int)uVar2 >> 2) {
    local_29 = 0xf1;
    local_2a = 5;
    uVar5 = 1;
    bVar1 = 100;
    bVar4 = 0x7a;
    while( true ) {
      bVar7 = bVar1;
      uVar3 = ~seq ^ *(uint *)(data + uVar5 * 4 + -4);
      iVar6 = (uVar3 >> 8 & 0xff00) + (uVar3 >> 8 & 0xff) * 0x10000 + uVar3 * 0x1000000 +
              (uVar3 >> 0x18);
      local_14._1_1_ = (byte)((uint)iVar6 >> 8);
      local_14._1_1_ = local_14._1_1_ ^ (bVar7 | 0xa7);
      local_14._0_1_ = (byte)iVar6;
      uVar3 = uVar5 + 1;
      local_14._0_1_ = (byte)local_14 ^ (bVar4 | 0xa5);
      local_14._2_1_ = (byte)((uint)iVar6 >> 0x10);
      local_14._2_1_ = local_14._2_1_ ^ (local_2a | 0xaf);
      local_14._3_1_ = (byte)((uint)iVar6 >> 0x18);
      local_14 = CONCAT13(local_14._3_1_ ^ (local_29 | 0xbf),
                          CONCAT12(local_14._2_1_,CONCAT11(local_14._1_1_,(byte)local_14)));
      *(uint *)(data + uVar5 * 4 + -4) = seq ^ local_14;
      if (uVar3 == ((int)uVar2 >> 2) + 1U) break;
      local_2a = mungify_table[uVar5 + 2 & 0xf];
      local_29 = mungify_table[uVar5 + 3 & 0xf];
      uVar5 = uVar3;
      bVar1 = mungify_table[uVar3 & 0xf];
      bVar4 = bVar7;
    }
  }
  return;
}


// COM_Munge2  @ 000a6260
void COM_Munge2(uchar *data,int len,int seq)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  byte bVar7;
  byte local_2a;
  byte local_29;
  undefined4 local_14;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int mungelen@[???]
                       Unresolved local var: int32 c@[???]
                       Unresolved local var: int32 * pc@[???]
                       Unresolved local var: uchar * p@[???]
                       Unresolved local var: int j@[???] */
  uVar5 = len & 0xfffffffc;
  uVar2 = uVar5 + 3;
  if (-1 < (int)uVar5) {
    uVar2 = uVar5;
  }
  if (0 < (int)uVar2 >> 2) {
    local_29 = 0xed;
    local_2a = 0x7a;
    uVar5 = 1;
    bVar1 = 0x61;
    bVar4 = 5;
    while( true ) {
      bVar7 = bVar1;
      uVar3 = ~seq ^ *(uint *)(data + uVar5 * 4 + -4);
      iVar6 = (uVar3 >> 8 & 0xff00) + (uVar3 >> 8 & 0xff) * 0x10000 + uVar3 * 0x1000000 +
              (uVar3 >> 0x18);
      local_14._1_1_ = (byte)((uint)iVar6 >> 8);
      local_14._1_1_ = local_14._1_1_ ^ (bVar7 | 0xa7);
      local_14._0_1_ = (byte)iVar6;
      uVar3 = uVar5 + 1;
      local_14._0_1_ = (byte)local_14 ^ (bVar4 | 0xa5);
      local_14._2_1_ = (byte)((uint)iVar6 >> 0x10);
      local_14._2_1_ = local_14._2_1_ ^ (local_2a | 0xaf);
      local_14._3_1_ = (byte)((uint)iVar6 >> 0x18);
      local_14 = CONCAT13(local_14._3_1_ ^ (local_29 | 0xbf),
                          CONCAT12(local_14._2_1_,CONCAT11(local_14._1_1_,(byte)local_14)));
      *(uint *)(data + uVar5 * 4 + -4) = seq ^ local_14;
      if (uVar3 == ((int)uVar2 >> 2) + 1U) break;
      local_2a = mungify_table2[uVar5 + 2 & 0xf];
      local_29 = mungify_table2[uVar5 + 3 & 0xf];
      uVar5 = uVar3;
      bVar1 = mungify_table2[uVar3 & 0xf];
      bVar4 = bVar7;
    }
  }
  return;
}


// COM_Munge3  @ 000a6450
void COM_Munge3(uchar *data,int len,int seq)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  byte bVar7;
  byte local_2a;
  byte local_29;
  undefined4 local_14;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int mungelen@[???]
                       Unresolved local var: int32 c@[???]
                       Unresolved local var: int32 * pc@[???]
                       Unresolved local var: uchar * p@[???]
                       Unresolved local var: int j@[???] */
  uVar5 = len & 0xfffffffc;
  uVar2 = uVar5 + 3;
  if (-1 < (int)uVar5) {
    uVar2 = uVar5;
  }
  if (0 < (int)uVar2 >> 2) {
    local_29 = 0x61;
    local_2a = 0x13;
    uVar5 = 1;
    bVar1 = 7;
    bVar4 = 0x20;
    while( true ) {
      bVar7 = bVar1;
      uVar3 = ~seq ^ *(uint *)(data + uVar5 * 4 + -4);
      iVar6 = (uVar3 >> 8 & 0xff00) + (uVar3 >> 8 & 0xff) * 0x10000 + uVar3 * 0x1000000 +
              (uVar3 >> 0x18);
      local_14._1_1_ = (byte)((uint)iVar6 >> 8);
      local_14._1_1_ = local_14._1_1_ ^ (bVar7 | 0xa7);
      local_14._0_1_ = (byte)iVar6;
      uVar3 = uVar5 + 1;
      local_14._0_1_ = (byte)local_14 ^ (bVar4 | 0xa5);
      local_14._2_1_ = (byte)((uint)iVar6 >> 0x10);
      local_14._2_1_ = local_14._2_1_ ^ (local_2a | 0xaf);
      local_14._3_1_ = (byte)((uint)iVar6 >> 0x18);
      local_14 = CONCAT13(local_14._3_1_ ^ (local_29 | 0xbf),
                          CONCAT12(local_14._2_1_,CONCAT11(local_14._1_1_,(byte)local_14)));
      *(uint *)(data + uVar5 * 4 + -4) = seq ^ local_14;
      if (uVar3 == ((int)uVar2 >> 2) + 1U) break;
      local_2a = mungify_table3[uVar5 + 2 & 0xf];
      local_29 = mungify_table3[uVar5 + 3 & 0xf];
      uVar5 = uVar3;
      bVar1 = mungify_table3[uVar3 & 0xf];
      bVar4 = bVar7;
    }
  }
  return;
}


// COM_Nibble  @ 0009e770
uchar COM_Nibble(char c)

{
  byte bVar1;
  
  bVar1 = c - 0x30;
  if (9 < bVar1) {
    if ((byte)(c + 0xbfU) < 6) {
      return c + 0xc9;
    }
    bVar1 = 0x30;
    if ((byte)(c + 0x9fU) < 6) {
      return c + 0xa9;
    }
  }
  return bVar1;
}


// COM_NormalizeAngles  @ 000a5ec0
void COM_NormalizeAngles(vec_t *angles)

{
  float fVar1;
  double dVar2;
  
                    /* Unresolved local var: int i@[???] */
  fVar1 = *angles;
  if (180.0 < fVar1) {
    dVar2 = fmod((double)fVar1,360.0);
    *angles = (float)dVar2 - 360.0;
    fVar1 = angles[1];
  }
  else {
    if (fVar1 < -180.0) {
      dVar2 = fmod((double)fVar1,360.0);
      *angles = (float)dVar2 + 360.0;
    }
    fVar1 = angles[1];
  }
  if (180.0 < fVar1) {
    dVar2 = fmod((double)fVar1,360.0);
    angles[1] = (float)dVar2 - 360.0;
    fVar1 = angles[2];
  }
  else {
    if (fVar1 < -180.0) {
      dVar2 = fmod((double)fVar1,360.0);
      angles[1] = (float)dVar2 + 360.0;
    }
    fVar1 = angles[2];
  }
  if (180.0 < fVar1) {
    dVar2 = fmod((double)fVar1,360.0);
    angles[2] = (float)dVar2 - 360.0;
    return;
  }
  if (-180.0 <= fVar1) {
    return;
  }
  dVar2 = fmod((double)fVar1,360.0);
  angles[2] = (float)dVar2 + 360.0;
  return;
}


// COM_Parse  @ 000a4690
char * COM_Parse(char *data)

{
  bool bVar1;
  qboolean qVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int local_10;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: int wchar@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: qboolean bError@[???] */
  if (s_com_token_unget != false) {
    s_com_token_unget = false;
    return data;
  }
  com_token[0] = '\0';
  if (data == (char *)0x0) {
    com_token[0] = '\0';
    return (char *)0x0;
  }
  do {
    while ((qVar2 = V_UTF8ToUChar32(data,&local_10), qVar2 == 0 && (local_10 < 0x21))) {
      if (local_10 == 0) {
        return (char *)0x0;
      }
      data = Q_UnicodeAdvance(data,1);
    }
    cVar6 = *data;
    uVar3 = (uint)cVar6;
    if (uVar3 != 0x2f) {
      if (uVar3 == 0x22) {
        cVar6 = data[1];
        pcVar5 = data + 2;
        if ((cVar6 != '\0') && (cVar6 != '\"')) {
          iVar7 = 0;
          pcVar4 = pcVar5;
          break;
        }
        iVar7 = 0;
        goto LAB_000a477f;
      }
      if ((((((cVar6 + 0x85U & 0xfd) == 0) || (uVar3 - 0x28 < 2)) || (uVar3 == 0x27)) ||
          ((uVar3 == 0x3a && (com_ignorecolons == false)))) || (uVar3 == 0x2c)) {
        com_token[0] = cVar6;
        com_token[1] = '\0';
        return data + 1;
      }
LAB_000a4798:
      bVar1 = com_ignorecolons == false;
      iVar7 = 0;
      goto LAB_000a47ce;
    }
    if (data[1] != '/') goto LAB_000a4798;
    do {
      data = data + 1;
      if (*data == '\0') break;
    } while (*data != '\n');
  } while( true );
  while (pcVar4 = pcVar5, iVar7 != 0x7ff) {
    com_token[iVar7] = cVar6;
    pcVar5 = pcVar4 + 1;
    iVar7 = iVar7 + 1;
    cVar6 = *pcVar4;
    if ((cVar6 == '\"') || (cVar6 == '\0')) break;
  }
LAB_000a477f:
  com_token[iVar7] = '\0';
  return pcVar5;
  while (iVar7 = iVar8 + 1, (uVar3 == 0x2c || 0x7fe < iVar8 + 1) < (0x20 < uVar3)) {
LAB_000a47ce:
    iVar8 = iVar7;
    com_token[iVar8] = (char)uVar3;
    data = data + 1;
    cVar6 = *data;
    if ((((cVar6 + 0x85U & 0xfd) == 0) || (uVar3 = (uint)cVar6, (byte)(cVar6 - 0x27U) < 3)) ||
       ((uVar3 == 0x3a && (bVar1)))) break;
  }
  com_token[iVar8 + 1] = '\0';
  return data;
}


// COM_ParseDirectoryFromCmd  @ 000a5740
void COM_ParseDirectoryFromCmd(char *pCmdName,char *pDirName,int nLen,char *pDefault)

{
  char cVar1;
  char *pcVar2;
  size_t sVar3;
  int iVar4;
  char *pcVar5;
  
                    /* Unresolved local var: char * pParameter@[???]
                       Unresolved local var: int cmdParameterIndex@[???] */
                    /* Unresolved local var: int i@[???] */
  if (1 < com_argc) {
    iVar4 = 1;
    do {
      pcVar2 = com_argv[iVar4];
      if (((pcVar2 != (char *)0x0) && (pCmdName != (char *)0x0)) &&
         (cVar1 = *pcVar2, pcVar5 = pCmdName, cVar1 == *pCmdName)) {
        do {
          if (cVar1 == '\0') {
            if (((iVar4 == 0) || (com_argc + -1 <= iVar4)) ||
               ((pcVar2 = com_argv[iVar4 + 1], (*pcVar2 - 0x2bU & 0xfd) == 0 ||
                (pcVar2 == (char *)0x0)))) goto LAB_000a57a3;
            strncpy(pDirName,pcVar2,nLen);
            pDirName[nLen + -1] = '\0';
            goto LAB_000a57d8;
          }
          pcVar5 = pcVar5 + 1;
          cVar1 = *pcVar5;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 == *pcVar2);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != com_argc);
  }
LAB_000a57a3:
  if (pDefault == (char *)0x0) {
    *pDirName = '\0';
  }
  else {
    strncpy(pDirName,pDefault,nLen);
    pDirName[nLen + -1] = '\0';
  }
LAB_000a57d8:
                    /* Unresolved local var: int len@[???] */
  sVar3 = strlen(pDirName);
  if (0 < (int)sVar3) {
    cVar1 = pDirName[sVar3 - 1];
    if ((cVar1 == '\\') || (cVar1 == '/')) {
      pDirName[sVar3 - 1] = '\0';
      return;
    }
  }
  return;
}


// COM_ParseFile  @ 00167000
char * COM_ParseFile(char *data,char *token)

{
  char *pcVar1;
  
                    /* Unresolved local var: char * return_data@[???] */
  (*g_engdstAddrs.COM_ParseFile)(&data,&token);
  pcVar1 = COM_Parse(data);
  Q_strncpy(token,com_token,0x400);
  return pcVar1;
}


// COM_ParseLine  @ 000a4850
char * COM_ParseLine(char *data)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: int len@[???] */
  if (s_com_token_unget != false) {
    s_com_token_unget = false;
    return data;
  }
  com_token[0] = '\0';
  if (data != (char *)0x0) {
    cVar2 = *data;
    iVar1 = 0;
    do {
      iVar3 = iVar1;
      com_token[iVar3] = cVar2;
      data = data + 1;
      cVar2 = *data;
      if (cVar2 < ' ') break;
      iVar1 = iVar3 + 1;
    } while (iVar3 + 1 < 0x7ff);
    com_token[iVar3 + 1] = '\0';
    if (cVar2 != '\0') {
      while( true ) {
        if ('\x1f' < *data) {
          return data;
        }
        if (*data == '\0') break;
        data = data + 1;
      }
    }
  }
  return (char *)0x0;
}


// COM_RemoveEvilChars  @ 000e8270
void COM_RemoveEvilChars(char *string)

{
  char cVar1;
  
                    /* Unresolved local var: char * c@[???] */
  if (string != (char *)0x0) {
    cVar1 = *string;
    if (cVar1 == '\0') {
      return;
    }
    do {
      if ((cVar1 == '%') || (cVar1 < ' ')) {
        *string = ' ';
      }
      string = string + 1;
    } while ((string != (char *)0x0) && (cVar1 = *string, cVar1 != '\0'));
  }
  return;
}


// COM_SetupDirectories  @ 000a5870
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean COM_SetupDirectories(void)

{
  char *pGameDir;
  int iVar1;
  int in_GS_OFFSET;
  char local_210 [512];
  int local_10;
  
                    /* Unresolved local var: char[512] basedir@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  com_clientfallback[0] = '\0';
  com_gamedir[0] = '\0';
  COM_ParseDirectoryFromCmd("-basedir",local_210,0x200,"valve");
  COM_ParseDirectoryFromCmd("-game",com_gamedir,0x104,local_210);
  pGameDir = com_gamedir;
  if (com_gamedir[0] == '\0') {
    pGameDir = (char *)0x0;
  }
  iVar1 = FileSystem_SetGameDirectory(local_210,pGameDir);
  if (iVar1 != 0) {
    Info_SetValueForStarKey(serverinfo,"*gamedir",com_gamedir,0x200);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return (uint)(iVar1 != 0);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// COM_Shutdown  @ 000a56c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void COM_Shutdown(void)

{
  return;
}


// COM_SizeofResourceList  @ 0009db20
int COM_SizeofResourceList(resource_t *pList,resourceinfo_t *ri)

{
  resource_s *prVar1;
  int iVar2;
  resourcetype_t rVar3;
  int iVar4;
  
                    /* Unresolved local var: resource_t * p@[DW_OP_reg2(EDX)]
                       Unresolved local var: int nSize@[???] */
  Q_memset(ri,0,0x20);
  prVar1 = pList->pNext;
  iVar4 = 0;
  do {
    while( true ) {
      if (pList == prVar1) {
        return iVar4;
      }
      iVar2 = prVar1->nDownloadSize;
      rVar3 = prVar1->type;
      iVar4 = iVar4 + iVar2;
      if (rVar3 == t_model) break;
      if ((t_world|t_skin) < rVar3) goto LAB_0009db5d;
LAB_0009db7a:
      ri->info[rVar3].size = ri->info[rVar3].size + iVar2;
      prVar1 = prVar1->pNext;
    }
    if (prVar1->nIndex != 1) goto LAB_0009db7a;
    ri->info[6].size = ri->info[6].size + iVar2;
LAB_0009db5d:
    prVar1 = prVar1->pNext;
  } while( true );
}


// COM_SkipPath  @ 000a3e20
char * COM_SkipPath(char *pathname)

{
  char cVar1;
  char *pcVar2;
  
                    /* Unresolved local var: char * last@[???] */
  cVar1 = *pathname;
  pcVar2 = pathname;
  while (cVar1 != '\0') {
    pcVar2 = pcVar2 + 1;
    if (cVar1 == '/' || cVar1 == '\\') {
      pathname = pcVar2;
    }
    cVar1 = *pcVar2;
  }
  return pathname;
}


// COM_StripExtension  @ 000a3e50
void COM_StripExtension(char *in,char *out)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  int iVar4;
  
                    /* Unresolved local var: char * in_current@[???]
                       Unresolved local var: char * out_current@[???]
                       Unresolved local var: int found_extension@[???] */
                    /* Unresolved local var: int count@[???] */
  if (in == (char *)0x0) {
    pcVar3 = (char *)0x0;
  }
  else {
    pcVar3 = in;
    if (*in != '\0') {
      do {
        pcVar3 = pcVar3 + 1;
      } while (*pcVar3 != '\0');
      iVar4 = 0;
      do {
                    /* Unresolved local var: int count@[???] */
        iVar4 = iVar4 + 1;
      } while (in[iVar4] != '\0');
      out = out + iVar4;
      if (pcVar3 < in) {
        return;
      }
    }
  }
  bVar2 = false;
  do {
    if ((bVar2) || (*pcVar3 != '.')) {
      cVar1 = *pcVar3;
      if ((cVar1 == '/') || (cVar1 == '\\')) {
        bVar2 = true;
      }
      *out = cVar1;
    }
    else {
      *out = '\0';
      bVar2 = true;
    }
    pcVar3 = pcVar3 + -1;
    out = out + -1;
  } while (in <= pcVar3);
  return;
}


// COM_StripTrailingSlash  @ 000a5700
void COM_StripTrailingSlash(char *ppath)

{
  char cVar1;
  size_t sVar2;
  
                    /* Unresolved local var: int len@[???] */
  sVar2 = strlen(ppath);
  if (0 < (int)sVar2) {
    cVar1 = ppath[sVar2 - 1];
    if ((cVar1 == '\\') || (cVar1 == '/')) {
      ppath[sVar2 - 1] = '\0';
      return;
    }
  }
  return;
}


// COM_TokenWaiting  @ 000a48c0
int COM_TokenWaiting(char *buffer)

{
  char cVar1;
  ushort **ppuVar2;
  
                    /* Unresolved local var: char * p@[???] */
  cVar1 = *buffer;
  if ((cVar1 != '\0') && (cVar1 != '\n')) {
    ppuVar2 = __ctype_b_loc();
    do {
      if (((*ppuVar2)[cVar1] & 0x2008) != 0x2000) {
        return 1;
      }
      buffer = buffer + 1;
      cVar1 = *buffer;
    } while ((cVar1 != '\0') && (cVar1 != '\n'));
  }
  return 0;
}


// COM_UnMunge  @ 000a6170
void COM_UnMunge(uchar *data,int len,int seq)

{
  uint uVar1;
  ushort uVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  byte bVar9;
  uint uVar10;
  undefined4 local_14;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int mungelen@[???]
                       Unresolved local var: int32 c@[???]
                       Unresolved local var: int32 * pc@[???]
                       Unresolved local var: uchar * p@[???]
                       Unresolved local var: int j@[???] */
  uVar8 = len & 0xfffffffc;
  uVar5 = uVar8 + 3;
  if (-1 < (int)uVar8) {
    uVar5 = uVar8;
  }
  if (0 < (int)uVar5 >> 2) {
    bVar6 = 0xf1;
    bVar7 = 5;
    uVar8 = 1;
    bVar3 = 100;
    bVar4 = 0x7a;
    while( true ) {
      bVar9 = bVar3;
      uVar10 = seq ^ *(uint *)(data + uVar8 * 4 + -4);
      uVar1 = uVar8 + 1;
      local_14._0_1_ = (byte)uVar10;
      local_14._0_1_ = (byte)local_14 ^ (bVar4 | 0xa5);
      local_14._2_1_ = (byte)(uVar10 >> 0x10);
      local_14._3_1_ = (byte)(uVar10 >> 0x18);
      local_14._3_1_ = local_14._3_1_ ^ (bVar6 | 0xbf);
      uVar2 = CONCAT11(local_14._3_1_,local_14._2_1_ ^ (bVar7 | 0xaf));
      local_14._1_1_ = (byte)(uVar10 >> 8);
      local_14._1_1_ = local_14._1_1_ ^ (bVar9 | 0xa7);
      local_14 = CONCAT22(uVar2,CONCAT11(local_14._1_1_,(byte)local_14));
      *(uint *)(data + uVar8 * 4 + -4) =
           (uVar2 & 0xff) * 0x100 + (uint)local_14._1_1_ * 0x10000 + local_14 * 0x1000000 +
           (uint)local_14._3_1_ ^ ~seq;
      if (uVar1 == ((int)uVar5 >> 2) + 1U) break;
      bVar7 = mungify_table[uVar8 + 2 & 0xf];
      bVar6 = mungify_table[uVar8 + 3 & 0xf];
      uVar8 = uVar1;
      bVar3 = mungify_table[uVar1 & 0xf];
      bVar4 = bVar9;
    }
  }
  return;
}


// COM_UnMunge2  @ 000a6360
void COM_UnMunge2(uchar *data,int len,int seq)

{
  uint uVar1;
  ushort uVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  byte bVar9;
  uint uVar10;
  undefined4 local_14;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int mungelen@[???]
                       Unresolved local var: int32 c@[???]
                       Unresolved local var: int32 * pc@[???]
                       Unresolved local var: uchar * p@[???]
                       Unresolved local var: int j@[???] */
  uVar8 = len & 0xfffffffc;
  uVar5 = uVar8 + 3;
  if (-1 < (int)uVar8) {
    uVar5 = uVar8;
  }
  if (0 < (int)uVar5 >> 2) {
    bVar6 = 0xed;
    bVar7 = 0x7a;
    uVar8 = 1;
    bVar3 = 0x61;
    bVar4 = 5;
    while( true ) {
      bVar9 = bVar3;
      uVar10 = seq ^ *(uint *)(data + uVar8 * 4 + -4);
      uVar1 = uVar8 + 1;
      local_14._0_1_ = (byte)uVar10;
      local_14._0_1_ = (byte)local_14 ^ (bVar4 | 0xa5);
      local_14._2_1_ = (byte)(uVar10 >> 0x10);
      local_14._3_1_ = (byte)(uVar10 >> 0x18);
      local_14._3_1_ = local_14._3_1_ ^ (bVar6 | 0xbf);
      uVar2 = CONCAT11(local_14._3_1_,local_14._2_1_ ^ (bVar7 | 0xaf));
      local_14._1_1_ = (byte)(uVar10 >> 8);
      local_14._1_1_ = local_14._1_1_ ^ (bVar9 | 0xa7);
      local_14 = CONCAT22(uVar2,CONCAT11(local_14._1_1_,(byte)local_14));
      *(uint *)(data + uVar8 * 4 + -4) =
           (uVar2 & 0xff) * 0x100 + (uint)local_14._1_1_ * 0x10000 + local_14 * 0x1000000 +
           (uint)local_14._3_1_ ^ ~seq;
      if (uVar1 == ((int)uVar5 >> 2) + 1U) break;
      bVar7 = mungify_table2[uVar8 + 2 & 0xf];
      bVar6 = mungify_table2[uVar8 + 3 & 0xf];
      uVar8 = uVar1;
      bVar3 = mungify_table2[uVar1 & 0xf];
      bVar4 = bVar9;
    }
  }
  return;
}


// COM_UnMunge3  @ 000a6550
void COM_UnMunge3(uchar *data,int len,int seq)

{
  uint uVar1;
  ushort uVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  byte bVar9;
  uint uVar10;
  undefined4 local_14;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int mungelen@[???]
                       Unresolved local var: int32 c@[???]
                       Unresolved local var: int32 * pc@[???]
                       Unresolved local var: uchar * p@[???]
                       Unresolved local var: int j@[???] */
  uVar8 = len & 0xfffffffc;
  uVar5 = uVar8 + 3;
  if (-1 < (int)uVar8) {
    uVar5 = uVar8;
  }
  if (0 < (int)uVar5 >> 2) {
    bVar6 = 0x61;
    bVar7 = 0x13;
    uVar8 = 1;
    bVar3 = 7;
    bVar4 = 0x20;
    while( true ) {
      bVar9 = bVar3;
      uVar10 = seq ^ *(uint *)(data + uVar8 * 4 + -4);
      uVar1 = uVar8 + 1;
      local_14._0_1_ = (byte)uVar10;
      local_14._0_1_ = (byte)local_14 ^ (bVar4 | 0xa5);
      local_14._2_1_ = (byte)(uVar10 >> 0x10);
      local_14._3_1_ = (byte)(uVar10 >> 0x18);
      local_14._3_1_ = local_14._3_1_ ^ (bVar6 | 0xbf);
      uVar2 = CONCAT11(local_14._3_1_,local_14._2_1_ ^ (bVar7 | 0xaf));
      local_14._1_1_ = (byte)(uVar10 >> 8);
      local_14._1_1_ = local_14._1_1_ ^ (bVar9 | 0xa7);
      local_14 = CONCAT22(uVar2,CONCAT11(local_14._1_1_,(byte)local_14));
      *(uint *)(data + uVar8 * 4 + -4) =
           (uVar2 & 0xff) * 0x100 + (uint)local_14._1_1_ * 0x10000 + local_14 * 0x1000000 +
           (uint)local_14._3_1_ ^ ~seq;
      if (uVar1 == ((int)uVar5 >> 2) + 1U) break;
      bVar7 = mungify_table3[uVar8 + 2 & 0xf];
      bVar6 = mungify_table3[uVar8 + 3 & 0xf];
      uVar8 = uVar1;
      bVar3 = mungify_table3[uVar1 & 0xf];
      bVar4 = bVar9;
    }
  }
  return;
}


// COM_UngetToken  @ 000a4680
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void COM_UngetToken(void)

{
  s_com_token_unget = true;
  return;
}


// COM_WriteFile  @ 000a4d20
void COM_WriteFile(char *filename,void *data,int len)

{
  FileHandle_t file;
  char cVar1;
  char *pcVar2;
  int in_GS_OFFSET;
  char local_124 [260];
  int local_20;
  
                    /* Unresolved local var: FileHandle_t handle@[???]
                       Unresolved local var: char[260] name@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  snprintf(local_124,0x104,"%s",filename);
  pcVar2 = local_124;
  while (local_124[0] != '\0') {
    while (local_124[0] != '\\') {
      pcVar2 = pcVar2 + 1;
      local_124[0] = *pcVar2;
      if (local_124[0] == '\0') goto LAB_000a4d98;
    }
    *pcVar2 = '/';
    pcVar2 = pcVar2 + 1;
    local_124[0] = *pcVar2;
  }
LAB_000a4d98:
                    /* Unresolved local var: char * ofs@[???]
                       Unresolved local var: char old@[???] */
  pcVar2 = local_124 + 1;
  cVar1 = local_124[1];
  while (cVar1 != '\0') {
    while ((cVar1 != '/' && (cVar1 != '\\'))) {
      pcVar2 = pcVar2 + 1;
      cVar1 = *pcVar2;
      if (cVar1 == '\0') goto LAB_000a4ddf;
    }
    *pcVar2 = '\0';
    FS_CreateDirHierarchy(local_124,(char *)0x0);
    *pcVar2 = cVar1;
    cVar1 = pcVar2[1];
    pcVar2 = pcVar2 + 1;
  }
LAB_000a4ddf:
  file = FS_Open(local_124,"wb");
  if (file == (FileHandle_t)0x0) {
    Sys_Printf("COM_WriteFile: failed on %s\n",local_124);
  }
  else {
    Sys_Printf("COM_WriteFile: %s\n",local_124);
    FS_Write(data,len,1,file);
    FS_Close(file);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


