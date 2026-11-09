// COM_AddAppDirectory  @ 00063e00
void COM_AddAppDirectory(char *pszBaseDir,char *appName)

{
  FS_AddSearchPath(pszBaseDir,"PLATFORM");
  return;
}


// COM_AddDefaultDir  @ 00063e10
void COM_AddDefaultDir(char *pszDir)

{
  if ((pszDir != (char *)0x0) && (*pszDir != '\0')) {
    FileSystem_AddFallbackGameDir(pszDir);
    return;
  }
  return;
}


// COM_AddExtension  @ 00062d90
void COM_AddExtension(char *path,char *extension,int size)

{
  qboolean qVar1;
  
  if (((extension != (char *)0x0) && (path != (char *)0x0)) && (0 < size)) {
    qVar1 = COM_HasFileExtension(path,extension);
    if (qVar1 == false) {
      if (*extension != '.') {
        strncat(path,".",size - 1U);
      }
      strncat(path,extension,size - 1U);
      return;
    }
  }
  return;
}


// COM_BinPrintf  @ 0005fc40
char * COM_BinPrintf(uchar *buf,int nLen)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  char *pcVar6;
  char local_26 [22];
  
  pcVar6 = COM_BinPrintf::szReturn;
                    /* Unresolved local var: uchar c@[???]
                       Unresolved local var: char[10] szChunk@[???]
                       Unresolved local var: int i@[???] */
  for (iVar3 = 0x400; iVar3 != 0; iVar3 = iVar3 + -1) {
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    pcVar6 = pcVar6 + 4;
  }
  if (0 < nLen) {
    iVar3 = 0;
    do {
      snprintf(local_26,10,"%02x",(uint)buf[iVar3]);
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
      iVar3 = iVar3 + 1;
      strncat(COM_BinPrintf::szReturn,local_26,
              0xfff - ((int)puVar5 + (-0x10af63 - (uint)CARRY1((byte)uVar2,(byte)uVar2))));
    } while (iVar3 != nLen);
  }
  return COM_BinPrintf::szReturn;
}


// COM_BitOpsInit  @ 0005fe20
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
    uVar2 = uVar1;
    *(undefined4 *)((int)&bfread.msg_readcount + uVar2) = 0;
    *(undefined4 *)((int)&bfread.pbuf + uVar2) = 0;
    *(undefined4 *)((int)&bfread.nBitFieldReadStartByte + uVar2) = 0;
    *(undefined4 *)((int)&bfread.nBytesRead + uVar2) = 0;
    uVar1 = uVar2 + 0x10;
  } while (uVar2 + 0x10 < 0x10);
  *(undefined4 *)((int)&bfread.nCurInputBit + uVar2) = 0;
  *(undefined4 *)((int)&bfread.pInByte + uVar2) = 0;
  return;
}


// COM_BlockSequenceCRCByte  @ 00066c60
byte COM_BlockSequenceCRCByte(byte *base,int length,int sequence)

{
  uint uVar1;
  int count;
  undefined1 local_60 [64];
  CRC32_t local_20 [4];
  
                    /* Unresolved local var: CRC32_t crc@[???]
                       Unresolved local var: byte * p@[DW_OP_reg7(EDI)]
                       Unresolved local var: byte[64] chkb@[???] */
  if (sequence < 0) {
    Sys_Error("sequence < 0, in COM_BlockSequenceCRCByte\n");
  }
  uVar1 = (uint)sequence % 0x3fc;
  count = 0x3c;
  if (length < 0x3d) {
    count = length;
  }
  Q_memcpy(local_60,base,count);
  local_60[count] = *(undefined1 *)((int)pulCRCTable + uVar1);
  local_60[count + 1] = *(undefined1 *)((int)pulCRCTable + uVar1 + 1);
  local_60[count + 2] = *(undefined1 *)((int)pulCRCTable + uVar1 + 2);
  local_60[count + 3] = *(undefined1 *)((int)pulCRCTable + uVar1 + 3);
  local_20[0] = 0xffffffff;
  CRC32_ProcessBuffer(local_20,local_60,count + 4);
  return ~(byte)local_20[0];
}


// COM_BuildNumber  @ 000996c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int COM_BuildNumber(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  
  if (build_number::b != 0) {
    return build_number::b;
  }
  iVar2 = Q_strncasecmp(date,mon[0],3);
  if (iVar2 == 0) {
    iVar2 = 0;
    uVar5 = 0;
  }
  else {
    iVar2 = (int)mond[0];
    iVar3 = Q_strncasecmp(date,mon[1],3);
    if (iVar3 == 0) {
      uVar5 = 1;
    }
    else {
      iVar2 = iVar2 + mond[1];
      iVar3 = Q_strncasecmp(date,mon[2],3);
      if (iVar3 == 0) {
        uVar5 = 2;
      }
      else {
        iVar2 = iVar2 + mond[2];
        iVar3 = Q_strncasecmp(date,mon[3],3);
        if (iVar3 == 0) {
          uVar5 = 3;
        }
        else {
          iVar2 = iVar2 + mond[3];
          iVar3 = Q_strncasecmp(date,mon[4],3);
          if (iVar3 == 0) {
            uVar5 = 4;
          }
          else {
            iVar2 = iVar2 + mond[4];
            iVar3 = Q_strncasecmp(date,mon[5],3);
            if (iVar3 == 0) {
              uVar5 = 5;
            }
            else {
              iVar2 = iVar2 + mond[5];
              iVar3 = Q_strncasecmp(date,mon[6],3);
              if (iVar3 == 0) {
                uVar5 = 6;
              }
              else {
                iVar2 = iVar2 + mond[6];
                iVar3 = Q_strncasecmp(date,mon[7],3);
                if (iVar3 == 0) {
                  uVar5 = 7;
                }
                else {
                  iVar2 = iVar2 + mond[7];
                  iVar3 = Q_strncasecmp(date,mon[8],3);
                  if (iVar3 == 0) {
                    uVar5 = 8;
                  }
                  else {
                    iVar2 = iVar2 + mond[8];
                    iVar3 = Q_strncasecmp(date,mon[9],3);
                    if (iVar3 == 0) {
                      uVar5 = 9;
                    }
                    else {
                      iVar2 = iVar2 + mond[9];
                      iVar3 = Q_strncasecmp(date,mon[10],3);
                      if (iVar3 != 0) {
                        bVar1 = true;
                        iVar2 = iVar2 + mond[10];
                        goto LAB_0005ade2;
                      }
                      uVar5 = 10;
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
  bVar1 = 1 < uVar5;
LAB_0005ade2:
  lVar4 = strtol(date + 4,(char **)0x0,10);
  uVar5 = strtol(date + 7,(char **)0x0,10);
  iVar2 = iVar2 + -1 + lVar4 + (int)((float)(int)(uVar5 - 0x76d) * 365.25);
  if ((uVar5 & 3) == 0) {
    iVar2 = (iVar2 + 1) - (uint)!bVar1;
  }
  build_number::b = iVar2 + -0x88b3;
  return iVar2 + -0x88b3;
}


// COM_CheckParm  @ 00063170
int COM_CheckParm(char *parm)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???] */
  if (1 < com_argc) {
    iVar3 = 1;
    do {
      pcVar1 = com_argv[iVar3];
      if (((pcVar1 != (char *)0x0) && (parm != (char *)0x0)) && (*parm == *pcVar1)) {
        if (*parm == '\0') {
          return iVar3;
        }
        iVar4 = 0;
        while (iVar2 = iVar4 + 1, parm[iVar2] == pcVar1[iVar4 + 1]) {
          iVar4 = iVar4 + 1;
          if (parm[iVar2] == '\0') {
            return iVar3;
          }
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != com_argc);
  }
  return 0;
}


// COM_ClearCustomizationList  @ 0005eb50
void COM_ClearCustomizationList(customization_t *pHead,qboolean bCleanDecals)

{
  customization_s *pcVar1;
  customization_s *p;
  void *pvVar2;
  undefined4 *p_00;
  int iVar3;
  int iVar4;
  
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
                       Unresolved local var: cachepic_t * pic@[???] */
        if ((bCleanDecals != false) && (cls.state == ca_active)) {
          R_DecalRemoveAll(~(uint)(p->resource).playernum);
          p_00 = p->pInfo;
        }
        Mem_Free((void *)p_00[4]);
        iVar3 = p_00[1];
        if (0 < (int)p_00[2]) {
          iVar4 = 0;
          do {
            pvVar2 = Cache_Check((cache_user_t *)(iVar3 + 0x40));
            if (pvVar2 != (void *)0x0) {
              Cache_Free((cache_user_t *)(iVar3 + 0x40));
            }
            iVar4 = iVar4 + 1;
            iVar3 = iVar3 + 0x44;
          } while (iVar4 < (int)p_00[2]);
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


// COM_CompareFileTime  @ 00064390
int COM_CompareFileTime(char *filename1,char *filename2,int *iCompare)

{
  int iVar1;
  int32 iVar2;
  int32 iVar3;
  
                    /* Unresolved local var: int bRet@[???] */
  *iCompare = 0;
  if ((filename2 == (char *)0x0) || (filename1 == (char *)0x0)) {
    iVar1 = 0;
  }
  else {
                    /* Unresolved local var: int32 ft1@[???]
                       Unresolved local var: int32 ft2@[???] */
    iVar2 = FS_GetFileTime(filename1);
    iVar3 = FS_GetFileTime(filename2);
    if (iVar2 < iVar3) {
      *iCompare = -1;
      return 1;
    }
    iVar1 = 1;
    if (iVar3 < iVar2) {
      *iCompare = 1;
      return iVar1;
    }
  }
  return iVar1;
}


// COM_CopyFile  @ 000636e0
void COM_CopyFile(char *netpath,char *cachepath)

{
  FileHandle_t file;
  uint size;
  char *pcVar1;
  FileHandle_t file_00;
  char cVar2;
  undefined1 local_101c [4108];
  
                    /* Unresolved local var: FileHandle_t in@[???]
                       Unresolved local var: FileHandle_t out@[???]
                       Unresolved local var: int remaining@[???]
                       Unresolved local var: int count@[???]
                       Unresolved local var: char[4096] buf@[???] */
  file = FS_Open(netpath,"rb");
  if (file != (FileHandle_t)0x0) {
    size = FS_Size(file);
                    /* Unresolved local var: char * ofs@[???]
                       Unresolved local var: char old@[???] */
    cVar2 = cachepath[1];
    if (cVar2 != '\0') {
      pcVar1 = cachepath + 1;
      do {
        while ((cVar2 != '\\' && (cVar2 != '/'))) {
          pcVar1 = pcVar1 + 1;
          cVar2 = *pcVar1;
          if (cVar2 == '\0') goto LAB_00063765;
        }
        *pcVar1 = '\0';
        FS_CreateDirHierarchy(cachepath,(char *)0x0);
        *pcVar1 = cVar2;
        pcVar1 = pcVar1 + 1;
        cVar2 = *pcVar1;
      } while (cVar2 != '\0');
    }
LAB_00063765:
    file_00 = FS_Open(cachepath,"wb");
    if (size != 0) {
      do {
        if (size < 0x1000) {
          FS_Read(local_101c,size,1,file);
          FS_Write(local_101c,size,1,file_00);
          break;
        }
        FS_Read(local_101c,0x1000,1,file);
        FS_Write(local_101c,0x1000,1,file_00);
        size = size - 0x1000;
      } while (size != 0);
    }
    FS_Close(file);
    FS_Close(file_00);
  }
  return;
}


// COM_CopyFileChunk  @ 00063b20
void COM_CopyFileChunk(FileHandle_t dst,FileHandle_t src,int nSize)

{
  int iVar1;
  undefined1 local_41c [1036];
  
                    /* Unresolved local var: int copysize@[???]
                       Unresolved local var: char[1024] copybuf@[???] */
  iVar1 = nSize;
  if (0x400 < nSize) {
    do {
      iVar1 = iVar1 + -0x400;
      FS_Read(local_41c,0x400,1,src);
      FS_Write(local_41c,0x400,1,dst);
    } while (0x400 < iVar1);
    nSize = (nSize + -0x400) - (nSize - 0x401U & 0xfffffc00);
  }
  FS_Read(local_41c,nSize,1,src);
  FS_Write(local_41c,nSize,1,dst);
  FS_Flush(src);
  FS_Flush(dst);
  return;
}


// COM_CreateCustomization  @ 0005ec80
qboolean COM_CreateCustomization
                   (customization_t *pListHead,resource_t *pResource,int playernumber,int flags,
                   customization_t **pCustomization,int *nLumps)

{
  undefined4 uVar1;
  customization_s *p;
  uint uVar2;
  uchar *puVar3;
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
    uVar1 = *(undefined4 *)(pResource->szFileName + uVar2);
    *(undefined4 *)((p->resource).szFileName + uVar2 + 4) =
         *(undefined4 *)(pResource->szFileName + uVar2 + 4);
    *(undefined4 *)((p->resource).szFileName + uVar2) = uVar1;
    uVar2 = uVar2 + 8;
  } while (uVar2 < 0x88);
  if (pResource->nDownloadSize < 1) {
LAB_0005ed7c:
    if (p->pBuffer != (void *)0x0) {
      Mem_Free(p->pBuffer);
    }
    if (p->pInfo != (void *)0x0) {
      Mem_Free(p->pInfo);
    }
    Mem_Free(p);
    return false;
  }
  p->bInUse = true;
  if ((flags & 1U) == 0) {
    puVar3 = COM_LoadFile(pResource->szFileName,5,(int *)0x0);
    p->pBuffer = puVar3;
  }
  else {
    qVar4 = HPAK_GetDataPointer("custom.hpk",pResource,&p->pBuffer,(int *)0x0);
    if (qVar4 == false) goto LAB_0005ed7c;
  }
  if ((((p->resource).ucFlags & 4) != 0) && ((p->resource).type == t_decal)) {
                    /* Unresolved local var: void * pNewBuffer@[???]
                       Unresolved local var: cachewad_t * pWad@[???] */
    (p->resource).playernum = (uchar)playernumber;
    qVar4 = CustomDecal_Validate(p->pBuffer,pResource->nDownloadSize);
    if (qVar4 == false) goto LAB_0005ed7c;
    if ((flags & 4U) == 0) {
      wad = Mem_ZeroMalloc(0x2c);
      p->pInfo = wad;
      if (((0x4c00 < pResource->nDownloadSize - 0x400U) ||
          (qVar4 = CustomDecal_Init(wad,p->pBuffer,pResource->nDownloadSize,playernumber),
          qVar4 == false)) || (wad->lumpCount < 1)) goto LAB_0005ed7c;
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
    }
  }
  if (pCustomization != (customization_t **)0x0) {
    *pCustomization = p;
  }
  p->pNext = pListHead->pNext;
  pListHead->pNext = p;
  return true;
}


// COM_CreatePath  @ 00063680
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
      while ((cVar1 == '\\' || (cVar1 == '/'))) {
        *pcVar2 = '\0';
        FS_CreateDirHierarchy(path,(char *)0x0);
        *pcVar2 = cVar1;
        pcVar2 = pcVar2 + 1;
        cVar1 = *pcVar2;
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


// COM_DefaultExtension  @ 00062e20
void COM_DefaultExtension(char *path,char *extension)

{
  char cVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  char *__s;
  
                    /* Unresolved local var: char * src@[???] */
                    /* Unresolved local var: int count@[???] */
  iVar4 = -1;
  if ((path != (char *)0x0) && (*path != '\0')) {
    iVar2 = 0;
    do {
      iVar4 = iVar2;
      iVar2 = iVar4 + 1;
    } while (path[iVar4 + 1] != '\0');
  }
  __s = path + iVar4;
  cVar1 = *__s;
  while ((cVar1 != '/' && (path != __s))) {
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


// COM_EntsForPlayerSlots  @ 00064470
int COM_EntsForPlayerSlots(int nPlayers)

{
  char *pcVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
                    /* Unresolved local var: int nMax@[???]
                       Unresolved local var: int nWeaponSlots@[???]
                       Unresolved local var: int i@[DW_OP_reg3(EBX)] */
  iVar3 = gmodinfo.num_edicts;
                    /* Unresolved local var: int i@[???] */
  if (1 < com_argc) {
    iVar5 = 1;
    do {
      pcVar1 = com_argv[iVar5];
      if ((pcVar1 != (char *)0x0) && (pcVar4 = "-num_edicts", *pcVar1 == '-')) {
        while( true ) {
          pcVar4 = pcVar4 + 1;
          pcVar1 = pcVar1 + 1;
          if (*pcVar4 != *pcVar1) break;
          if (*pcVar4 == '\0') {
            lVar2 = strtol(com_argv[iVar5 + 1],(char **)0x0,10);
            if (iVar3 <= lVar2) {
              iVar3 = strtol(com_argv[iVar5 + 1],(char **)0x0,10);
            }
            goto LAB_000644ca;
          }
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 != com_argc);
  }
LAB_000644ca:
  return (nPlayers + -1) * 0xf + iVar3;
}


// COM_ExpandFilename  @ 00063810
int COM_ExpandFilename(char *filename)

{
  char local_110 [264];
  
                    /* Unresolved local var: char[260] netpath@[???] */
  FS_GetLocalPath(filename,local_110,0x104);
  strcpy(filename,local_110);
  return (uint)(*filename != '\0');
}


// COM_ExplainDisconnection  @ 0005fd10
void COM_ExplainDisconnection(qboolean bPrint,char *fmt,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  vsnprintf(COM_ExplainDisconnection::string,0x400,fmt,&stack0x0000000c);
  strncpy(gszDisconnectReason,COM_ExplainDisconnection::string,0xff);
  gszDisconnectReason[0xff] = '\0';
  gfExtendedError = true;
  if ((bPrint != false) && (gszDisconnectReason[0] != '#')) {
    Con_Printf("%s\n",gszDisconnectReason);
  }
  return;
}


// COM_ExtendedExplainDisconnection  @ 0005fda0
void COM_ExtendedExplainDisconnection(qboolean bPrint,char *fmt,...)

{
                    /* Unresolved local var: va_list argptr@[???] */
  vsnprintf(COM_ExtendedExplainDisconnection::string,0x400,fmt,&stack0x0000000c);
  strncpy(gszExtendedDisconnectReason,COM_ExtendedExplainDisconnection::string,0xff);
  gszExtendedDisconnectReason[0xff] = '\0';
  if ((bPrint != false) && (gszExtendedDisconnectReason[0] != '#')) {
    Con_Printf("%s\n",gszExtendedDisconnectReason);
  }
  return;
}


// COM_FileBase  @ 00062d60
void COM_FileBase(char *in,char *out)

{
  COM_FileBase_s(in,out,-1);
  return;
}


// COM_FileBase_s  @ 00062c50
char * COM_FileBase_s(char *in,char *out,int size)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  size_t __n;
  
                    /* Unresolved local var: int len@[???]
                       Unresolved local var: int start@[???]
                       Unresolved local var: int end@[???] */
                    /* Unresolved local var: int count@[???] */
  if (in != (char *)0x0) {
    iVar4 = 0;
    if (*in != '\0') {
      do {
        iVar2 = iVar4;
        iVar4 = iVar2 + 1;
      } while (in[iVar2 + 1] != '\0');
      iVar4 = iVar2;
      if (iVar2 == 0) {
LAB_00062cca:
        iVar4 = -1;
        if (*in == '.') goto LAB_00062ce0;
        iVar4 = iVar2;
        goto LAB_00062ce0;
      }
      cVar1 = in[iVar2];
      iVar3 = iVar2;
      if (cVar1 == '.') {
LAB_00062d58:
        iVar4 = iVar3 + -1;
        goto LAB_00062ce0;
      }
      if (cVar1 == '/') goto LAB_00062ce0;
      if (cVar1 == '\\') goto LAB_00062ce0;
      do {
        iVar3 = iVar3 + -1;
        if (iVar3 == 0) goto LAB_00062cca;
        cVar1 = in[iVar3];
        if (cVar1 == '.') goto LAB_00062d58;
      } while ((cVar1 != '/') && (cVar1 != '\\'));
      cVar1 = in[iVar2];
      while ((cVar1 != '/' && (cVar1 != '\\'))) {
        iVar2 = iVar2 + -1;
        if (iVar2 == -1) {
          iVar2 = 0;
          goto LAB_00062cf6;
        }
LAB_00062ce0:
        cVar1 = in[iVar2];
      }
      iVar2 = iVar2 + 1;
LAB_00062cf6:
      __n = (iVar4 - iVar2) + 1;
      if (((int)__n < size) || (size < 0)) {
        strncpy(out,in + iVar2,__n);
        out[__n] = '\0';
        return out;
      }
    }
  }
  return (char *)0x0;
}


// COM_FileExtension  @ 00062900
char * COM_FileExtension(char *in)

{
  char cVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  
                    /* Unresolved local var: int i@[???] */
  cVar3 = *in;
  if ((cVar3 != '\0') && (cVar3 != '.')) {
    do {
      in = in + 1;
      cVar3 = *in;
      if (cVar3 == '.') break;
    } while (cVar3 != '\0');
  }
  pcVar2 = "";
  if (cVar3 != '\0') {
    cVar3 = in[1];
    iVar4 = 0;
    if (cVar3 != '\0') {
      iVar4 = 1;
      cVar1 = in[2];
      COM_FileExtension::exten[0] = cVar3;
      if (cVar1 != '\0') {
        iVar4 = 2;
        cVar3 = in[3];
        COM_FileExtension::exten[1] = cVar1;
        if (cVar3 != '\0') {
          iVar4 = 3;
          cVar1 = in[4];
          COM_FileExtension::exten[2] = cVar3;
          if (cVar1 != '\0') {
            iVar4 = 4;
            cVar3 = in[5];
            COM_FileExtension::exten[3] = cVar1;
            if (cVar3 != '\0') {
              iVar4 = 5;
              cVar1 = in[6];
              COM_FileExtension::exten[4] = cVar3;
              if (cVar1 != '\0') {
                iVar4 = 6;
                COM_FileExtension::exten[5] = cVar1;
                if (in[7] != '\0') {
                  iVar4 = 7;
                  COM_FileExtension::exten[6] = in[7];
                }
              }
            }
          }
        }
      }
    }
    COM_FileExtension::exten[iVar4] = '\0';
    pcVar2 = COM_FileExtension::exten;
  }
  return pcVar2;
}


// COM_FileSize  @ 00063870
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


// COM_FixSlashes  @ 00063650
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


// COM_FreeFile  @ 00063af0
void COM_FreeFile(void *buffer)

{
  (*g_engdstAddrs.COM_FreeFile)(&buffer);
  if (buffer != (void *)0x0) {
    Mem_Free(buffer);
  }
  return;
}


// COM_GetApproxWavePlayLength  @ 00064e90
uint COM_GetApproxWavePlayLength(char *filepath)

{
  FileHandle_t file;
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char local_bd [8];
  char local_b5 [4];
  undefined4 auStack_b1 [29];
  undefined1 local_3d;
  char local_3c [16];
  uint local_2c;
  
                    /* Unresolved local var: FileHandle_t hFile@[???]
                       Unresolved local var: uint filelength@[???]
                       Unresolved local var: int found@[???]
                       Unresolved local var: FormatChunk format@[???]
                       Unresolved local var: FormatChunk * tempFormat@[???]
                       Unresolved local var: uint numMilliseconds@[???]
                       Unresolved local var: char[129] buf@[???] */
  uVar4 = 0;
  file = FS_Open(filepath,"rb");
  if (file != (FileHandle_t)0x0) {
    uVar1 = FS_Size(file);
    FS_Read(local_bd,0x80,1,file);
    FS_Close(file);
    local_3d = 0;
    iVar2 = strncasecmp(local_bd,"RIFF",4);
    if (iVar2 == 0) {
      iVar2 = strncasecmp(local_b5,"WAVE",4);
      uVar4 = 0;
      uVar3 = 0;
      if (iVar2 == 0) {
        do {
          *(undefined4 *)(local_3c + uVar3) = *(undefined4 *)((int)auStack_b1 + uVar3);
          uVar3 = uVar3 + 4;
        } while (uVar3 < 0x18);
        uVar4 = 0;
        iVar2 = strncasecmp(local_3c,"fmt ",4);
        if (iVar2 == 0) {
          if (local_2c == 0) {
            Con_Printf("COM_GetApproxWavePlayLength: bad AvgBytesPerSec\n");
          }
          else if (local_2c < 1000) {
            uVar4 = ((uVar1 - 0x80) / local_2c) * 1000;
          }
          else {
            uVar4 = (uVar1 - 0x80) / (local_2c / 1000);
          }
        }
      }
    }
  }
  return uVar4;
}


// COM_GetGameDir  @ 00064430
void COM_GetGameDir(char *szGameDir)

{
  if (szGameDir != (char *)0x0) {
    snprintf(szGameDir,0x103,"%s",com_gamedir);
  }
  return;
}


// COM_HasFileExtension  @ 00062af0
qboolean COM_HasFileExtension(char *in,char *ext)

{
  char cVar1;
  int iVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  bool bVar8;
  
  if ((ext != (char *)0x0) && (in != (char *)0x0)) {
                    /* Unresolved local var: char * cur@[???]
                       Unresolved local var: int i@[???] */
    pcVar7 = "";
    pcVar4 = ext + (*ext == '.');
    cVar3 = *in;
    if (cVar3 != '\0') {
      iVar5 = -1;
      pcVar7 = in;
      do {
        if (cVar3 == '.') {
          iVar5 = (int)pcVar7 - (int)in;
        }
        pcVar7 = pcVar7 + 1;
        cVar3 = *pcVar7;
      } while (cVar3 != '\0');
      pcVar7 = "";
      if (-1 < iVar5) {
        pcVar6 = in + iVar5;
                    /* Unresolved local var: int i@[???] */
        cVar3 = *pcVar6;
        if (cVar3 == '.') {
          cVar3 = '.';
        }
        else {
          do {
            bVar8 = cVar3 == '\0';
            cVar3 = '\0';
            if (bVar8) break;
            pcVar6 = pcVar6 + 1;
            cVar3 = *pcVar6;
          } while (cVar3 != '.');
        }
        pcVar7 = "";
        if (cVar3 != '\0') {
          cVar3 = pcVar6[1];
          iVar5 = 0;
          if (cVar3 != '\0') {
            iVar5 = 1;
            cVar1 = pcVar6[2];
            COM_FileExtension::exten[0] = cVar3;
            if (cVar1 != '\0') {
              iVar5 = 2;
              cVar3 = pcVar6[3];
              COM_FileExtension::exten[1] = cVar1;
              if (cVar3 != '\0') {
                iVar5 = 3;
                cVar1 = pcVar6[4];
                COM_FileExtension::exten[2] = cVar3;
                if (cVar1 != '\0') {
                  iVar5 = 4;
                  cVar3 = pcVar6[5];
                  COM_FileExtension::exten[3] = cVar1;
                  if (cVar3 != '\0') {
                    iVar5 = 5;
                    cVar1 = pcVar6[6];
                    COM_FileExtension::exten[4] = cVar3;
                    if (cVar1 != '\0') {
                      iVar5 = 6;
                      COM_FileExtension::exten[5] = cVar1;
                      if (pcVar6[7] != '\0') {
                        iVar5 = 7;
                        COM_FileExtension::exten[6] = pcVar6[7];
                      }
                    }
                  }
                }
              }
            }
          }
          COM_FileExtension::exten[iVar5] = '\0';
          pcVar7 = COM_FileExtension::exten;
        }
      }
    }
    if (pcVar4 == (char *)0x0) {
      return false;
    }
    if (*pcVar7 != *pcVar4) {
      return false;
    }
    if (*pcVar7 == '\0') {
      return true;
    }
    iVar5 = 0;
    while (iVar2 = iVar5 + 1, pcVar7[iVar2] == pcVar4[iVar5 + 1]) {
      iVar5 = iVar5 + 1;
      if (pcVar7[iVar2] == '\0') {
        return true;
      }
    }
  }
  return false;
}


// COM_HexConvert  @ 0005fb60
void COM_HexConvert(char *pszInput,int nInputLength,uchar *pOutput)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: uchar * p@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: char * pIn@[???] */
  if (0 < nInputLength) {
    iVar4 = 0;
    iVar5 = (nInputLength - 1U >> 1) + 1;
    do {
      while( true ) {
        cVar1 = *pszInput;
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
        cVar1 = pszInput[1];
        bVar2 = cVar1 - 0x30;
        if (9 < bVar2) break;
LAB_0005fbcc:
        pszInput = pszInput + 2;
        pOutput[iVar4] = bVar2 | bVar3;
        iVar4 = iVar4 + 1;
        if (iVar4 == iVar5) {
          return;
        }
      }
      if (5 < (byte)(cVar1 + 0xbfU)) {
        bVar2 = 0x30;
        if ((byte)(cVar1 + 0x9fU) < 6) {
          bVar2 = cVar1 + 0xa9;
        }
        goto LAB_0005fbcc;
      }
      pszInput = pszInput + 2;
      pOutput[iVar4] = cVar1 - 0x37U | bVar3;
      iVar4 = iVar4 + 1;
    } while (iVar4 != iVar5);
  }
  return;
}


// COM_Init  @ 00063340
/* WARNING: Removing unreachable block (ram,0x0006334e) */

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
    uVar2 = uVar1;
    *(undefined4 *)((int)&bfread.msg_readcount + uVar2) = 0;
    *(undefined4 *)((int)&bfread.pbuf + uVar2) = 0;
    *(undefined4 *)((int)&bfread.nBitFieldReadStartByte + uVar2) = 0;
    *(undefined4 *)((int)&bfread.nBytesRead + uVar2) = 0;
    uVar1 = uVar2 + 0x10;
  } while (uVar2 + 0x10 < 0x10);
  *(undefined4 *)((int)&bfread.nCurInputBit + uVar2) = 0;
  *(undefined4 *)((int)&bfread.pInByte + uVar2) = 0;
  return;
}


// COM_InitArgv  @ 000631e0
void COM_InitArgv(int argc,char **argv)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
                    /* Unresolved local var: qboolean safe@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: int n@[???] */
  if (argc < 1) {
    com_argc = 0;
    com_cmdline[0] = '\0';
  }
  else {
    iVar8 = 0;
    iVar7 = 0;
    do {
      cVar2 = *argv[iVar7];
      iVar5 = iVar8;
      while (cVar2 != '\0') {
        com_cmdline[iVar5] = cVar2;
        iVar6 = iVar5 + 1;
        if (0xfe < iVar6) goto LAB_0006323b;
        iVar5 = iVar6;
        cVar2 = argv[iVar7][iVar6 - iVar8];
      }
      iVar7 = iVar7 + 1;
      com_cmdline[iVar5] = ' ';
      iVar8 = iVar5 + 1;
    } while (((iVar7 < argc) && (iVar7 < 0x32)) && (iVar8 < 0xff));
LAB_0006323b:
    com_cmdline[iVar5 + 1] = '\0';
    bVar4 = false;
    com_argc = 0;
    do {
      iVar8 = com_argc;
      largv[iVar8] = argv[iVar8];
      pcVar3 = argv[iVar8];
      if ((pcVar3 != (char *)0x0) && (iVar7 = 0, *pcVar3 == '-')) {
        do {
          pcVar1 = &DAT_000e10bc + iVar7;
          if (*pcVar1 != pcVar3[iVar7 + 1]) goto LAB_00063286;
          iVar7 = iVar7 + 1;
        } while (*pcVar1 != '\0');
        bVar4 = true;
      }
LAB_00063286:
      com_argc = iVar8 + 1;
    } while ((com_argc != 0x32) && (com_argc < argc));
    if (bVar4) {
      largv[com_argc] = "-stdvid";
      largv[iVar8 + 2] = "-nolan";
      largv[iVar8 + 3] = "-nosound";
      largv[iVar8 + 4] = "-nocdaudio";
      largv[iVar8 + 5] = "-nojoy";
      largv[iVar8 + 6] = "-nomouse";
      largv[iVar8 + 7] = "-dibonly";
      com_argc = iVar8 + 8;
    }
  }
  largv[com_argc] = " ";
  com_argv = largv;
  return;
}


// COM_LastFileExtension  @ 000629c0
/* WARNING: Removing unreachable block (ram,0x00062aee) */

char * COM_LastFileExtension(char *in)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char cVar5;
  
                    /* Unresolved local var: char * cur@[???]
                       Unresolved local var: int i@[???] */
  pcVar2 = "";
  if ((in != (char *)0x0) && (cVar5 = *in, cVar5 != '\0')) {
    iVar3 = -1;
    pcVar2 = in;
    do {
      if (cVar5 == '.') {
        iVar3 = (int)pcVar2 - (int)in;
      }
      pcVar2 = pcVar2 + 1;
      cVar5 = *pcVar2;
    } while (cVar5 != '\0');
    pcVar2 = "";
    if (-1 < iVar3) {
      pcVar4 = in + iVar3;
                    /* Unresolved local var: int i@[???] */
      cVar5 = *pcVar4;
      if ((cVar5 != '\0') && (cVar5 != '.')) {
        do {
          pcVar4 = pcVar4 + 1;
          if (*pcVar4 == '.') goto LAB_00062a40;
          cVar5 = '\0';
        } while (*pcVar4 != '\0');
      }
      pcVar2 = "";
      if (cVar5 != '\0') {
LAB_00062a40:
        cVar5 = pcVar4[1];
        iVar3 = 0;
        if (cVar5 != '\0') {
          iVar3 = 1;
          cVar1 = pcVar4[2];
          COM_FileExtension::exten[0] = cVar5;
          if (cVar1 != '\0') {
            iVar3 = 2;
            cVar5 = pcVar4[3];
            COM_FileExtension::exten[1] = cVar1;
            if (cVar5 != '\0') {
              iVar3 = 3;
              cVar1 = pcVar4[4];
              COM_FileExtension::exten[2] = cVar5;
              if (cVar1 != '\0') {
                iVar3 = 4;
                cVar5 = pcVar4[5];
                COM_FileExtension::exten[3] = cVar1;
                if (cVar5 != '\0') {
                  iVar3 = 5;
                  cVar1 = pcVar4[6];
                  COM_FileExtension::exten[4] = cVar5;
                  if (cVar1 != '\0') {
                    iVar3 = 6;
                    COM_FileExtension::exten[5] = cVar1;
                    if (pcVar4[7] != '\0') {
                      iVar3 = 7;
                      COM_FileExtension::exten[6] = pcVar4[7];
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
    }
  }
  return pcVar2;
}


// COM_ListMaps  @ 00064030
void COM_ListMaps(char *pszSubString)

{
  char *__s1;
  uint uVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  FileHandle_t file;
  size_t __n;
  int local_1120;
  char local_111c [4096];
  int local_11c [32];
  undefined4 local_9c;
  undefined4 local_98;
  undefined2 local_94;
  undefined1 local_92;
  char local_5c [76];
  
                    /* Unresolved local var: int nSubStringLen@[???]
                       Unresolved local var: int showOutdated@[???]
                       Unresolved local var: char * findfn@[???] */
  __n = 0;
  if ((pszSubString != (char *)0x0) && (*pszSubString != '\0')) {
    __n = strlen(pszSubString);
  }
  Con_Printf("-------------\n");
                    /* Unresolved local var: char[64] mapwild@[???]
                       Unresolved local var: char[4096] curDir@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: dheader_t header@[???]
                       Unresolved local var: char[64] sz@[???] */
  local_1120 = 1;
  do {
    local_9c = 0x7370616d;
    local_98 = 0x622e2a2f;
    local_94 = 0x7073;
    local_92 = 0;
    __s1 = Sys_FindFirst((char *)&local_9c,(char *)0x0);
    while (__s1 != (char *)0x0) {
      uVar1 = snprintf(local_111c,0x1000,"maps/%s",__s1);
      if (uVar1 < 0x1000) {
        FS_GetLocalPath(local_111c,local_111c,0x1000);
        pcVar2 = strstr(local_111c,com_gamedir);
        if ((pcVar2 != (char *)0x0) &&
           ((__n == 0 || (iVar3 = strncasecmp(__s1,pszSubString,__n), iVar3 == 0)))) {
          uVar1 = 0;
          do {
            uVar4 = uVar1;
            *(undefined4 *)((int)local_11c + uVar4 + 4) = 0;
            *(undefined4 *)((int)local_11c + uVar4) = 0;
            *(undefined4 *)((int)local_11c + uVar4 + 8) = 0;
            *(undefined4 *)((int)local_11c + uVar4 + 0xc) = 0;
            uVar1 = uVar4 + 0x10;
          } while (uVar1 < 0x70);
          *(undefined4 *)(uVar1 + (int)local_11c) = 0;
          *(undefined4 *)((int)local_11c + uVar4 + 0x14) = 0;
          *(undefined4 *)((int)local_11c + uVar4 + 0x18) = 0;
          uVar1 = snprintf(local_5c,0x40,"maps/%s",__s1);
          if (0x3f < uVar1) goto LAB_00064248;
          file = FS_Open(local_5c,"rb");
          if (file == (FileHandle_t)0x0) {
            Con_Printf("Could not open map %s\n",local_5c);
          }
          else {
            FS_Read(local_11c,0x7c,1,file);
            FS_Close(file);
          }
                    /* Unresolved local var: qboolean valid@[???] */
          if (local_11c[0] == 0x1e) {
            if (local_1120 == 0) {
              Con_Printf("%s\n",__s1);
            }
          }
          else if (local_1120 != 0) {
            Con_Printf("OUTDATED:  %s\n",__s1);
          }
        }
      }
      else {
LAB_00064248:
        Con_Printf("Map name too long: %s\n",__s1);
      }
      __s1 = Sys_FindNext((char *)0x0);
    }
    Sys_FindClose();
    local_1120 = local_1120 + -1;
    if (local_1120 == -1) {
      return;
    }
  } while( true );
}


// COM_LoadCacheFile  @ 00063d90
void COM_LoadCacheFile(char *path,cache_user_s *cu)

{
  loadcache = cu;
  COM_LoadFile(path,3,(int *)0x0);
  return;
}


// COM_LoadFile  @ 000638c0
uchar * COM_LoadFile(char *path,int usehunk,int *pLength)

{
  FileHandle_t file;
  uint size;
  char *pcVar1;
  uchar *pOutput;
  char local_101c [32];
  undefined1 local_ffc;
  
                    /* Unresolved local var: FileHandle_t hFile@[???]
                       Unresolved local var: uchar * buf@[???]
                       Unresolved local var: char[4096] base@[???]
                       Unresolved local var: int len@[???] */
  (*g_engdstAddrs.COM_LoadFile)(&path,&usehunk,&pLength);
  if (pLength != (int *)0x0) {
    *pLength = 0;
  }
  file = FS_Open(path,"rb");
  if (file == (FileHandle_t)0x0) {
    return (uchar *)0x0;
  }
  size = FS_Size(file);
  pcVar1 = COM_FileBase_s(path,local_101c,0x1000);
  if (pcVar1 == (char *)0x0) {
    Sys_Error("COM_LoadFile: bad path name for %s",path);
    FS_Close(file);
    return (uchar *)0x0;
  }
  local_ffc = 0;
  if (usehunk == 1) {
    pOutput = Hunk_AllocName(size + 1,local_101c);
  }
  else if (usehunk == 2) {
LAB_00063a7e:
    pOutput = Hunk_TempAlloc(size + 1);
  }
  else if (usehunk == 0) {
    pOutput = Z_Malloc(size + 1);
  }
  else if (usehunk == 3) {
    pOutput = Cache_Alloc(loadcache,size + 1,local_101c);
  }
  else if (usehunk == 4) {
    pOutput = loadbuf;
    if (loadsize <= (int)size) goto LAB_00063a7e;
  }
  else {
    if (usehunk != 5) {
      Sys_Error("COM_LoadFile: bad usehunk");
      goto LAB_000639bb;
    }
    pOutput = Mem_Malloc(size + 1);
  }
  if (pOutput != (uchar *)0x0) {
    pOutput[size] = '\0';
    FS_Read(pOutput,size,1,file);
    FS_Close(file);
    if (pLength == (int *)0x0) {
      return pOutput;
    }
    *pLength = size;
    return pOutput;
  }
LAB_000639bb:
  Sys_Error("COM_LoadFile: not enough space for %s",path);
  FS_Close(file);
  return (uchar *)0x0;
}


// COM_LoadFileForMe  @ 00064360
uchar * COM_LoadFileForMe(char *filename,int *pLength)

{
  uchar *puVar1;
  
  puVar1 = COM_LoadFile(filename,5,pLength);
  return puVar1;
}


// COM_LoadFileLimit  @ 00063c10
uchar * COM_LoadFileLimit(char *path,int pos,int cbmax,int *pcbread,FileHandle_t *phFile)

{
  uint uVar1;
  uchar *pOutput;
  FileHandle_t file;
  
                    /* Unresolved local var: FileHandle_t hFile@[???]
                       Unresolved local var: uchar * buf@[???]
                       Unresolved local var: int len@[???]
                       Unresolved local var: int cbload@[???] */
  file = *phFile;
  if ((file == (FileHandle_t)0x0) && (file = FS_Open(path,"rb"), file == (FileHandle_t)0x0)) {
    return (uchar *)0x0;
  }
  uVar1 = FS_Size(file);
  if ((int)uVar1 < pos) {
    Sys_Error("COM_LoadFileLimit: invalid seek position for %s",path);
  }
  FS_Seek(file,pos,FILESYSTEM_SEEK_HEAD);
  if ((int)uVar1 <= cbmax) {
    cbmax = uVar1;
  }
  *pcbread = cbmax;
  pOutput = Hunk_TempAlloc(cbmax + 1);
  if (pOutput == (uchar *)0x0) {
    if (path != (char *)0x0) {
      Sys_Error("COM_LoadFileLimit: not enough space for %s",path);
    }
    FS_Close(file);
  }
  else {
    pOutput[cbmax] = '\0';
    FS_Read(pOutput,cbmax,1,file);
    *phFile = file;
  }
  return pOutput;
}


// COM_LoadHunkFile  @ 00063d30
uchar * COM_LoadHunkFile(char *path)

{
  uchar *puVar1;
  
  puVar1 = COM_LoadFile(path,1,(int *)0x0);
  return puVar1;
}


// COM_LoadStackFile  @ 00063dc0
uchar * COM_LoadStackFile(char *path,void *buffer,int bufsize,int *length)

{
  uchar *puVar1;
  
                    /* Unresolved local var: uchar * buf@[???] */
  loadbuf = buffer;
  loadsize = bufsize;
  puVar1 = COM_LoadFile(path,4,length);
  return puVar1;
}


// COM_LoadTempFile  @ 00063d60
uchar * COM_LoadTempFile(char *path,int *pLength)

{
  uchar *puVar1;
  
  puVar1 = COM_LoadFile(path,2,pLength);
  return puVar1;
}


// COM_Log  @ 000642d0
void COM_Log(char *pszFile,char *fmt,...)

{
  FileHandle_t file;
  char *pFileName;
  char local_40c [1028];
  
                    /* Unresolved local var: va_list argptr@[???]
                       Unresolved local var: char[1024] string@[???]
                       Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: char * pfilename@[???] */
  pFileName = "c:\\hllog.txt";
  if (pszFile != (char *)0x0) {
    pFileName = pszFile;
  }
  vsnprintf(local_40c,0x400,fmt,&stack0x0000000c);
  file = FS_Open(pFileName,"a+t");
  if (file != (FileHandle_t)0x0) {
    FS_FPrintf(file,"%s",local_40c);
    FS_Close(file);
  }
  return;
}


// COM_Munge  @ 00064890
void COM_Munge(uchar *data,int len,int seq)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  undefined4 local_14;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int mungelen@[???]
                       Unresolved local var: int32 c@[???]
                       Unresolved local var: int32 * pc@[???]
                       Unresolved local var: uchar * p@[???]
                       Unresolved local var: int j@[???] */
  uVar2 = len & 0xfffffffc;
  if ((int)uVar2 < 0) {
    uVar2 = uVar2 + 3;
  }
  if (0 < (int)uVar2 >> 2) {
    bVar5 = 0x7a;
    uVar3 = 1;
    uVar7 = 0;
    do {
      uVar4 = uVar3;
      bVar6 = bVar5 | 0xa5;
      uVar3 = *(uint *)(data + uVar7 * 4) ^ ~seq;
                    /* Unresolved local var: uchar b1@[???]
                       Unresolved local var: uchar b2@[???]
                       Unresolved local var: uchar b3@[???]
                       Unresolved local var: uchar b4@[???] */
      iVar1 = uVar3 * 0x1000000 + (uVar3 >> 8 & 0xff) * 0x10000 + (uVar3 >> 8 & 0xff00) +
              (uVar3 >> 0x18);
      bVar5 = mungify_table[uVar4 & 0xf];
      local_14 = CONCAT13((mungify_table[uVar4 + 2 & 0xf] | 0xbf) ^ (byte)((uint)iVar1 >> 0x18),
                          CONCAT12((mungify_table[uVar4 + 1 & 0xf] | 0xaf) ^
                                   (byte)((uint)iVar1 >> 0x10),
                                   CONCAT11((bVar5 | 0xa7) ^ (byte)((uint)iVar1 >> 8),
                                            bVar6 ^ (byte)iVar1)));
      *(uint *)(data + uVar4 * 4 + -4) = seq ^ local_14;
      uVar3 = uVar4 + 1;
      uVar7 = uVar4;
    } while (uVar4 != (int)uVar2 >> 2);
  }
  return;
}


// COM_Munge2  @ 00064a90
void COM_Munge2(uchar *data,int len,int seq)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  undefined4 local_14;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int mungelen@[???]
                       Unresolved local var: int32 c@[???]
                       Unresolved local var: int32 * pc@[???]
                       Unresolved local var: uchar * p@[???]
                       Unresolved local var: int j@[???] */
  uVar2 = len & 0xfffffffc;
  if ((int)uVar2 < 0) {
    uVar2 = uVar2 + 3;
  }
  if (0 < (int)uVar2 >> 2) {
    bVar5 = 5;
    uVar3 = 1;
    uVar7 = 0;
    do {
      uVar4 = uVar3;
      bVar6 = bVar5 | 0xa5;
      uVar3 = *(uint *)(data + uVar7 * 4) ^ ~seq;
                    /* Unresolved local var: uchar b1@[???]
                       Unresolved local var: uchar b2@[???]
                       Unresolved local var: uchar b3@[???]
                       Unresolved local var: uchar b4@[???] */
      iVar1 = uVar3 * 0x1000000 + (uVar3 >> 8 & 0xff) * 0x10000 + (uVar3 >> 8 & 0xff00) +
              (uVar3 >> 0x18);
      bVar5 = mungify_table2[uVar4 & 0xf];
      local_14 = CONCAT13((mungify_table2[uVar4 + 2 & 0xf] | 0xbf) ^ (byte)((uint)iVar1 >> 0x18),
                          CONCAT12((mungify_table2[uVar4 + 1 & 0xf] | 0xaf) ^
                                   (byte)((uint)iVar1 >> 0x10),
                                   CONCAT11((bVar5 | 0xa7) ^ (byte)((uint)iVar1 >> 8),
                                            bVar6 ^ (byte)iVar1)));
      *(uint *)(data + uVar4 * 4 + -4) = seq ^ local_14;
      uVar3 = uVar4 + 1;
      uVar7 = uVar4;
    } while (uVar4 != (int)uVar2 >> 2);
  }
  return;
}


// COM_Munge3  @ 00064c90
void COM_Munge3(uchar *data,int len,int seq)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  undefined4 local_14;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int mungelen@[???]
                       Unresolved local var: int32 c@[???]
                       Unresolved local var: int32 * pc@[???]
                       Unresolved local var: uchar * p@[???]
                       Unresolved local var: int j@[???] */
  uVar2 = len & 0xfffffffc;
  if ((int)uVar2 < 0) {
    uVar2 = uVar2 + 3;
  }
  if (0 < (int)uVar2 >> 2) {
    bVar5 = 0x20;
    uVar3 = 1;
    uVar7 = 0;
    do {
      uVar4 = uVar3;
      bVar6 = bVar5 | 0xa5;
      uVar3 = *(uint *)(data + uVar7 * 4) ^ ~seq;
                    /* Unresolved local var: uchar b1@[???]
                       Unresolved local var: uchar b2@[???]
                       Unresolved local var: uchar b3@[???]
                       Unresolved local var: uchar b4@[???] */
      iVar1 = uVar3 * 0x1000000 + (uVar3 >> 8 & 0xff) * 0x10000 + (uVar3 >> 8 & 0xff00) +
              (uVar3 >> 0x18);
      bVar5 = mungify_table3[uVar4 & 0xf];
      local_14 = CONCAT13((mungify_table3[uVar4 + 2 & 0xf] | 0xbf) ^ (byte)((uint)iVar1 >> 0x18),
                          CONCAT12((mungify_table3[uVar4 + 1 & 0xf] | 0xaf) ^
                                   (byte)((uint)iVar1 >> 0x10),
                                   CONCAT11((bVar5 | 0xa7) ^ (byte)((uint)iVar1 >> 8),
                                            bVar6 ^ (byte)iVar1)));
      *(uint *)(data + uVar4 * 4 + -4) = seq ^ local_14;
      uVar3 = uVar4 + 1;
      uVar7 = uVar4;
    } while (uVar4 != (int)uVar2 >> 2);
  }
  return;
}


// COM_Nibble  @ 0005fb20
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


// COM_NormalizeAngles  @ 00064530
void COM_NormalizeAngles(vec_t *angles)

{
  float fVar1;
  ushort in_FPUStatusWord;
  ushort uVar2;
  longdouble lVar3;
  longdouble lVar4;
  double dVar5;
  
                    /* Unresolved local var: int i@[???] */
  fVar1 = *angles;
  lVar3 = (longdouble)fVar1;
  uVar2 = in_FPUStatusWord & 0xfdff;
  if ((longdouble)180.0 < lVar3) {
    do {
      lVar3 = lVar3 - (longdouble)(unkint10)(lVar3 / (longdouble)360.0) * (longdouble)360.0;
    } while ((in_FPUStatusWord & 0x400) != 0);
    if (NAN(lVar3)) {
      dVar5 = fmod((double)fVar1,360.0);
      lVar3 = (longdouble)dVar5;
    }
    *angles = (float)lVar3 - 360.0;
    lVar3 = (longdouble)angles[1];
    uVar2 = uVar2 & 0xfdff;
    if ((longdouble)180.0 < lVar3) goto LAB_000645e4;
  }
  else {
    if (lVar3 < (longdouble)-180.0) {
      do {
        lVar3 = lVar3 - (longdouble)(unkint10)(lVar3 / (longdouble)360.0) * (longdouble)360.0;
      } while ((in_FPUStatusWord & 0x400) != 0);
      if (NAN(lVar3)) {
        dVar5 = fmod((double)fVar1,360.0);
        lVar3 = (longdouble)dVar5;
      }
      *angles = (float)lVar3 + 360.0;
    }
    lVar3 = (longdouble)angles[1];
    uVar2 = uVar2 & 0xfdff;
    if ((longdouble)180.0 < lVar3) {
LAB_000645e4:
      lVar4 = lVar3;
      do {
        lVar4 = lVar4 - (longdouble)(unkint10)(lVar4 / (longdouble)360.0) * (longdouble)360.0;
      } while ((uVar2 & 0x400) != 0);
      if (NAN(lVar4)) {
        dVar5 = fmod((double)lVar3,360.0);
        lVar4 = (longdouble)dVar5;
      }
      angles[1] = (float)lVar4 - 360.0;
      lVar3 = (longdouble)angles[2];
      uVar2 = uVar2 & 0xfdff;
      if ((longdouble)180.0 < lVar3) goto LAB_00064625;
      goto LAB_0006458e;
    }
  }
  if (lVar3 < (longdouble)-180.0) {
    lVar4 = lVar3;
    do {
      lVar4 = lVar4 - (longdouble)(unkint10)(lVar4 / (longdouble)360.0) * (longdouble)360.0;
    } while ((uVar2 & 0x400) != 0);
    if (NAN(lVar4)) {
      dVar5 = fmod((double)lVar3,360.0);
      lVar4 = (longdouble)dVar5;
    }
    angles[1] = (float)lVar4 + 360.0;
  }
  lVar3 = (longdouble)angles[2];
  uVar2 = uVar2 & 0xfdff;
  if ((longdouble)180.0 < lVar3) {
LAB_00064625:
    lVar4 = lVar3;
    do {
      lVar4 = lVar4 - (longdouble)(unkint10)(lVar4 / (longdouble)360.0) * (longdouble)360.0;
    } while ((uVar2 & 0x400) != 0);
    if (NAN(lVar4)) {
      dVar5 = fmod((double)lVar3,360.0);
      lVar4 = (longdouble)dVar5;
    }
    angles[2] = (float)lVar4 - 360.0;
    return;
  }
LAB_0006458e:
  if (lVar3 < (longdouble)-180.0) {
    lVar4 = lVar3;
    do {
      lVar4 = lVar4 - (longdouble)(unkint10)(lVar4 / (longdouble)360.0) * (longdouble)360.0;
    } while ((uVar2 & 0x400) != 0);
    if (NAN(lVar4)) {
      dVar5 = fmod((double)lVar3,360.0);
      lVar4 = (longdouble)dVar5;
    }
    angles[2] = (float)lVar4 + 360.0;
    return;
  }
  return;
}


// COM_Parse  @ 00062ea0
char * COM_Parse(char *data)

{
  qboolean qVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  bool bVar6;
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
  while( true ) {
    while ((qVar1 = V_UTF8ToUChar32(data,&local_10), qVar1 == 0 && (local_10 < 0x21))) {
      if (local_10 == 0) {
        return (char *)0x0;
      }
      data = Q_UnicodeAdvance(data,1);
    }
    bVar4 = *data;
    if (bVar4 != 0x2f) break;
    bVar3 = 0x2f;
    if (data[1] != 0x2f) goto LAB_00062fa2;
    while ((bVar3 != 10 && (bVar3 != 0))) {
      data = data + 1;
      bVar3 = *data;
    }
  }
  if (bVar4 == 0x22) {
    bVar4 = data[1];
    pbVar5 = (byte *)(data + 2);
    if ((bVar4 == 0) || (bVar4 == 0x22)) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0;
      do {
        com_token[iVar2] = bVar4;
        iVar2 = iVar2 + 1;
        bVar4 = *pbVar5;
        pbVar5 = pbVar5 + 1;
        if ((bVar4 == 0) || (bVar4 == 0x22)) break;
      } while (iVar2 != 0x7ff);
    }
  }
  else {
    if ((((bVar4 == 0x7d) || (bVar4 == 0x7b)) || (bVar4 == 0x29)) ||
       ((bVar4 == 0x28 || (bVar4 == 0x27)))) goto LAB_00063051;
LAB_00062fa2:
    bVar6 = com_ignorecolons == false;
    if (((bVar4 == 0x3a) && (bVar6)) || (bVar4 == 0x2c)) {
LAB_00063051:
      com_token[0] = bVar4;
      com_token[1] = '\0';
      return (char *)(byte *)(data + 1);
    }
    iVar2 = 0;
    while( true ) {
      com_token[iVar2] = bVar4;
      pbVar5 = (byte *)(data + iVar2 + 1);
      iVar2 = iVar2 + 1;
      bVar4 = data[iVar2];
      if (((((bVar4 == 0x7d) || (bVar4 == 0x7b)) || (bVar4 == 0x28)) ||
          ((bVar4 == 0x29 || (bVar4 == 0x27)))) || ((bVar4 == 0x3a && (bVar6)))) break;
      if (((bVar4 == 0x2c) || (0x7fe < iVar2)) || (bVar4 < 0x21)) break;
    }
  }
  com_token[iVar2] = '\0';
  return (char *)pbVar5;
}


// COM_ParseDirectoryFromCmd  @ 00063e70
void COM_ParseDirectoryFromCmd(char *pCmdName,char *pDirName,int nLen,char *pDefault)

{
  char cVar1;
  size_t sVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  
                    /* Unresolved local var: char * pParameter@[???]
                       Unresolved local var: int cmdParameterIndex@[DW_OP_reg1(ECX)] */
                    /* Unresolved local var: int i@[???] */
  if (1 < com_argc) {
    iVar3 = 1;
    do {
      pcVar4 = com_argv[iVar3];
      if (((pcVar4 != (char *)0x0) && (pCmdName != (char *)0x0)) &&
         (cVar1 = *pCmdName, pcVar5 = pCmdName, cVar1 == *pcVar4)) {
        do {
          if (cVar1 == '\0') {
            if (com_argc + -1 <= iVar3) goto LAB_00063ed3;
            cVar1 = *com_argv[iVar3 + 1];
            if ((cVar1 == '+') || (pcVar4 = com_argv[iVar3 + 1], cVar1 == '-')) goto LAB_00063ed3;
            goto LAB_00063eef;
          }
          pcVar5 = pcVar5 + 1;
          pcVar4 = pcVar4 + 1;
          cVar1 = *pcVar5;
        } while (cVar1 == *pcVar4);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != com_argc);
  }
LAB_00063ed3:
  pcVar4 = pDefault;
  if (pDefault == (char *)0x0) {
    *pDirName = '\0';
  }
  else {
LAB_00063eef:
    strncpy(pDirName,pcVar4,nLen);
    pDirName[nLen + -1] = '\0';
  }
                    /* Unresolved local var: int len@[???] */
  sVar2 = strlen(pDirName);
  if (0 < (int)sVar2) {
    cVar1 = pDirName[sVar2 - 1];
    if ((cVar1 != '/') && (cVar1 != '\\')) {
      return;
    }
    pDirName[sVar2 - 1] = '\0';
  }
  return;
}


// COM_ParseLine  @ 00063080
char * COM_ParseLine(char *data)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int c@[???]
                       Unresolved local var: int len@[???] */
  if (s_com_token_unget != false) {
    s_com_token_unget = false;
    return data;
  }
  com_token[0] = '\0';
  if (data != (char *)0x0) {
    cVar2 = *data;
    iVar4 = 0;
    do {
      iVar3 = iVar4;
      com_token[iVar3] = cVar2;
      pcVar1 = data + iVar3 + 1;
      iVar4 = iVar3 + 1;
      cVar2 = data[iVar4];
      if (cVar2 < ' ') break;
    } while (iVar4 < 0x7ff);
    com_token[iVar3 + 1] = '\0';
    if (cVar2 != '\0') {
      cVar2 = *pcVar1;
      while( true ) {
        if ('\x1f' < cVar2) {
          return pcVar1;
        }
        if (cVar2 == '\0') break;
        pcVar1 = pcVar1 + 1;
        cVar2 = *pcVar1;
      }
    }
  }
  return (char *)0x0;
}


// COM_RemoveEvilChars  @ 000996d0
void COM_RemoveEvilChars(char *string)

{
                    /* Unresolved local var: char * c@[???] */
  if (string != (char *)0x0) {
    if (*string == '\0') {
      return;
    }
    do {
      if ((*string == '%') || (*string < ' ')) {
        *string = ' ';
      }
      string = string + 1;
    } while ((string != (char *)0x0) && (*string != '\0'));
  }
  return;
}


// COM_SetupDirectories  @ 00063f70
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

qboolean COM_SetupDirectories(void)

{
  char *pGameDir;
  int iVar1;
  char local_20c [520];
  
                    /* Unresolved local var: char[512] basedir@[???] */
  com_clientfallback[0] = '\0';
  com_gamedir[0] = '\0';
  COM_ParseDirectoryFromCmd("-basedir",local_20c,0x200,"valve");
  COM_ParseDirectoryFromCmd("-game",com_gamedir,0x104,local_20c);
  pGameDir = (char *)0x0;
  if (com_gamedir[0] != '\0') {
    pGameDir = com_gamedir;
  }
  iVar1 = FileSystem_SetGameDirectory(local_20c,pGameDir);
  if (iVar1 != 0) {
    Info_SetValueForStarKey(serverinfo,"*gamedir",com_gamedir,0x200);
  }
  return (uint)(iVar1 != 0);
}


// COM_Shutdown  @ 00063df0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void COM_Shutdown(void)

{
  return;
}


// COM_SizeofResourceList  @ 0005eec0
int COM_SizeofResourceList(resource_t *pList,resourceinfo_t *ri)

{
  resource_s *prVar1;
  int iVar2;
  resourcetype_t rVar3;
  int iVar4;
  
                    /* Unresolved local var: resource_t * p@[???]
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
      if ((t_world|t_skin) < rVar3) goto LAB_0005eefd;
LAB_0005ef1a:
      ri->info[rVar3].size = ri->info[rVar3].size + iVar2;
      prVar1 = prVar1->pNext;
    }
    if (prVar1->nIndex != 1) goto LAB_0005ef1a;
    ri->info[6].size = ri->info[6].size + iVar2;
LAB_0005eefd:
    prVar1 = prVar1->pNext;
  } while( true );
}


// COM_SkipPath  @ 00062820
char * COM_SkipPath(char *pathname)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  
                    /* Unresolved local var: char * last@[???] */
  cVar3 = *pathname;
  if (cVar3 != '\0') {
    pcVar1 = pathname + 1;
    do {
      while ((pcVar2 = pcVar1, cVar3 == '\\' || (cVar3 == '/'))) {
        cVar3 = *pcVar2;
        pathname = pcVar2;
        pcVar1 = pcVar2 + 1;
        if (cVar3 == '\0') {
          return pcVar2;
        }
      }
      cVar3 = *pcVar2;
      pcVar1 = pcVar2 + 1;
    } while (cVar3 != '\0');
  }
  return pathname;
}


// COM_StripExtension  @ 00062860
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
      if (pcVar3 < in) {
        return;
      }
      out = out + iVar4;
    }
  }
  bVar2 = false;
  do {
    cVar1 = *pcVar3;
    if ((bVar2) || (cVar1 != '.')) {
      if ((cVar1 == '\\') || (cVar1 == '/')) {
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


// COM_StripTrailingSlash  @ 00063e30
void COM_StripTrailingSlash(char *ppath)

{
  char *pcVar1;
  size_t sVar2;
  
                    /* Unresolved local var: int len@[???] */
  sVar2 = strlen(ppath);
  if (0 < (int)sVar2) {
    pcVar1 = ppath + (sVar2 - 1);
    if (*pcVar1 == '/') {
      *pcVar1 = '\0';
    }
    else if (*pcVar1 == '\\') {
      *pcVar1 = '\0';
    }
  }
  return;
}


// COM_TokenWaiting  @ 00063110
int COM_TokenWaiting(char *buffer)

{
  ushort **ppuVar1;
  char cVar2;
  
                    /* Unresolved local var: char * p@[???] */
  cVar2 = *buffer;
  if ((cVar2 != '\n') && (cVar2 != '\0')) {
    ppuVar1 = __ctype_b_loc();
    do {
      if (((*ppuVar1)[cVar2] & 0x2008) != 0x2000) {
        return 1;
      }
      buffer = buffer + 1;
      cVar2 = *buffer;
    } while ((cVar2 != '\n') && (cVar2 != '\0'));
  }
  return 0;
}


// COM_UnMunge  @ 00064990
void COM_UnMunge(uchar *data,int len,int seq)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  undefined1 local_14 [2];
  byte bStack_12;
  byte bStack_11;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int mungelen@[???]
                       Unresolved local var: int32 c@[???]
                       Unresolved local var: int32 * pc@[???]
                       Unresolved local var: uchar * p@[???]
                       Unresolved local var: int j@[???] */
  uVar1 = len & 0xfffffffc;
  if ((int)uVar1 < 0) {
    uVar1 = uVar1 + 3;
  }
  if (0 < (int)uVar1 >> 2) {
    bVar3 = 0x7a;
    uVar6 = 1;
    uVar5 = 0;
    do {
      uVar2 = uVar6;
      bVar4 = bVar3 | 0xa5;
      uVar6 = *(uint *)(data + uVar5 * 4) ^ seq;
      bVar3 = mungify_table[uVar2 & 0xf];
      _local_14 = CONCAT12((mungify_table[uVar2 + 1 & 0xf] | 0xaf) ^ (byte)(uVar6 >> 0x10),
                           CONCAT11((bVar3 | 0xa7) ^ (byte)(uVar6 >> 8),bVar4 ^ (byte)uVar6));
      bVar4 = (mungify_table[uVar2 + 2 & 0xf] | 0xbf) ^ (byte)(uVar6 >> 0x18);
      _local_14 = CONCAT13(bVar4,_local_14);
                    /* Unresolved local var: uchar b1@[???]
                       Unresolved local var: uchar b2@[???]
                       Unresolved local var: uchar b3@[???]
                       Unresolved local var: uchar b4@[???] */
      *(uint *)(data + uVar2 * 4 + -4) =
           ((_local_14 & 0xff0000) >> 8) +
           _local_14 * 0x1000000 + ((_local_14 & 0xff00) >> 8) * 0x10000 + (uint)bVar4 ^ ~seq;
      uVar6 = uVar2 + 1;
      uVar5 = uVar2;
    } while (uVar2 != (int)uVar1 >> 2);
  }
  return;
}


// COM_UnMunge2  @ 00064b90
void COM_UnMunge2(uchar *data,int len,int seq)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  undefined1 local_14 [2];
  byte bStack_12;
  byte bStack_11;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int mungelen@[???]
                       Unresolved local var: int32 c@[???]
                       Unresolved local var: int32 * pc@[???]
                       Unresolved local var: uchar * p@[???]
                       Unresolved local var: int j@[???] */
  uVar1 = len & 0xfffffffc;
  if ((int)uVar1 < 0) {
    uVar1 = uVar1 + 3;
  }
  if (0 < (int)uVar1 >> 2) {
    bVar3 = 5;
    uVar6 = 1;
    uVar5 = 0;
    do {
      uVar2 = uVar6;
      bVar4 = bVar3 | 0xa5;
      uVar6 = *(uint *)(data + uVar5 * 4) ^ seq;
      bVar3 = mungify_table2[uVar2 & 0xf];
      _local_14 = CONCAT12((mungify_table2[uVar2 + 1 & 0xf] | 0xaf) ^ (byte)(uVar6 >> 0x10),
                           CONCAT11((bVar3 | 0xa7) ^ (byte)(uVar6 >> 8),bVar4 ^ (byte)uVar6));
      bVar4 = (mungify_table2[uVar2 + 2 & 0xf] | 0xbf) ^ (byte)(uVar6 >> 0x18);
      _local_14 = CONCAT13(bVar4,_local_14);
                    /* Unresolved local var: uchar b1@[???]
                       Unresolved local var: uchar b2@[???]
                       Unresolved local var: uchar b3@[???]
                       Unresolved local var: uchar b4@[???] */
      *(uint *)(data + uVar2 * 4 + -4) =
           ((_local_14 & 0xff0000) >> 8) +
           _local_14 * 0x1000000 + ((_local_14 & 0xff00) >> 8) * 0x10000 + (uint)bVar4 ^ ~seq;
      uVar6 = uVar2 + 1;
      uVar5 = uVar2;
    } while (uVar2 != (int)uVar1 >> 2);
  }
  return;
}


// COM_UnMunge3  @ 00064d90
void COM_UnMunge3(uchar *data,int len,int seq)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  undefined1 local_14 [2];
  byte bStack_12;
  byte bStack_11;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int mungelen@[???]
                       Unresolved local var: int32 c@[???]
                       Unresolved local var: int32 * pc@[???]
                       Unresolved local var: uchar * p@[???]
                       Unresolved local var: int j@[???] */
  uVar1 = len & 0xfffffffc;
  if ((int)uVar1 < 0) {
    uVar1 = uVar1 + 3;
  }
  if (0 < (int)uVar1 >> 2) {
    bVar3 = 0x20;
    uVar6 = 1;
    uVar5 = 0;
    do {
      uVar2 = uVar6;
      bVar4 = bVar3 | 0xa5;
      uVar6 = *(uint *)(data + uVar5 * 4) ^ seq;
      bVar3 = mungify_table3[uVar2 & 0xf];
      _local_14 = CONCAT12((mungify_table3[uVar2 + 1 & 0xf] | 0xaf) ^ (byte)(uVar6 >> 0x10),
                           CONCAT11((bVar3 | 0xa7) ^ (byte)(uVar6 >> 8),bVar4 ^ (byte)uVar6));
      bVar4 = (mungify_table3[uVar2 + 2 & 0xf] | 0xbf) ^ (byte)(uVar6 >> 0x18);
      _local_14 = CONCAT13(bVar4,_local_14);
                    /* Unresolved local var: uchar b1@[???]
                       Unresolved local var: uchar b2@[???]
                       Unresolved local var: uchar b3@[???]
                       Unresolved local var: uchar b4@[???] */
      *(uint *)(data + uVar2 * 4 + -4) =
           ((_local_14 & 0xff0000) >> 8) +
           _local_14 * 0x1000000 + ((_local_14 & 0xff00) >> 8) * 0x10000 + (uint)bVar4 ^ ~seq;
      uVar6 = uVar2 + 1;
      uVar5 = uVar2;
    } while (uVar2 != (int)uVar1 >> 2);
  }
  return;
}


// COM_UngetToken  @ 00062e90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void COM_UngetToken(void)

{
  s_com_token_unget = true;
  return;
}


// COM_WriteFile  @ 00063530
void COM_WriteFile(char *filename,void *data,int len)

{
  FileHandle_t file;
  char *pcVar1;
  char local_11c [272];
  
                    /* Unresolved local var: FileHandle_t handle@[???]
                       Unresolved local var: char[260] name@[???] */
  snprintf(local_11c,0x104,"%s",filename);
  pcVar1 = local_11c;
  while (local_11c[0] != '\0') {
    while (local_11c[0] != '\\') {
      pcVar1 = pcVar1 + 1;
      local_11c[0] = *pcVar1;
      if (local_11c[0] == '\0') goto LAB_00063587;
    }
    *pcVar1 = '/';
    pcVar1 = pcVar1 + 1;
    local_11c[0] = *pcVar1;
  }
LAB_00063587:
                    /* Unresolved local var: char * ofs@[???]
                       Unresolved local var: char old@[???] */
  if (local_11c[1] != '\0') {
    pcVar1 = local_11c + 1;
    do {
      while ((local_11c[1] == '\\' || (local_11c[1] == '/'))) {
        *pcVar1 = '\0';
        FS_CreateDirHierarchy(local_11c,(char *)0x0);
        *pcVar1 = local_11c[1];
        pcVar1 = pcVar1 + 1;
        local_11c[1] = *pcVar1;
        if (local_11c[1] == '\0') goto LAB_000635cd;
      }
      pcVar1 = pcVar1 + 1;
      local_11c[1] = *pcVar1;
    } while (local_11c[1] != '\0');
  }
LAB_000635cd:
  file = FS_Open(local_11c,"wb");
  if (file != (FileHandle_t)0x0) {
    Sys_Printf("COM_WriteFile: %s\n",local_11c);
    FS_Write(data,len,1,file);
    FS_Close(file);
    return;
  }
  Sys_Printf("COM_WriteFile: failed on %s\n",local_11c);
  return;
}


