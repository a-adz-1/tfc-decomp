// CRC_File  @ 00066d50
BOOL CRC_File(CRC32_t *crcvalue,char *pszFileName)

{
  FileHandle_t file;
  BOOL BVar1;
  uint size;
  int iVar2;
  undefined1 local_41c [1036];
  
                    /* Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: byte[1024] chunk@[???]
                       Unresolved local var: int nBytesRead@[???]
                       Unresolved local var: int nSize@[???] */
  file = FS_Open(pszFileName,"rb");
  BVar1 = 0;
  if (file != (FileHandle_t)0x0) {
    size = FS_Size(file);
    if (0 < (int)size) {
      do {
        if ((int)size < 0x401) {
          iVar2 = FS_Read(local_41c,size,1,file);
        }
        else {
          iVar2 = FS_Read(local_41c,0x400,1,file);
        }
        if (0 < iVar2) {
          size = size - iVar2;
          CRC32_ProcessBuffer(crcvalue,local_41c,iVar2);
        }
        iVar2 = FS_EndOfFile(file);
        if (iVar2 != 0) break;
        iVar2 = FS_IsOk(file);
        if (iVar2 == 0) {
          FS_Close(file);
          return 0;
        }
      } while (0 < (int)size);
    }
    FS_Close(file);
    BVar1 = 1;
  }
  return BVar1;
}


// CRC_MapFile  @ 00066e50
int CRC_MapFile(CRC32_t *crcvalue,char *pszFileName)

{
  int iVar1;
  FileHandle_t file;
  uint uVar2;
  int iVar3;
  int32 iVar4;
  int iVar5;
  uint uVar6;
  undefined1 local_498 [1024];
  int32 local_98;
  int local_94 [33];
  
                    /* Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: byte[1024] chunk@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: int l@[???]
                       Unresolved local var: int nBytesRead@[???]
                       Unresolved local var: dheader_t header@[???]
                       Unresolved local var: int nSize@[???]
                       Unresolved local var: lump_t * curLump@[???]
                       Unresolved local var: int32 startOfs@[???]
                       Unresolved local var: int nLumpID@[???] */
  iVar1 = strcasecmp(com_gamedir,"bshift");
  iVar5 = 0;
  file = FS_Open(pszFileName,"rb");
  if (file != (FileHandle_t)0x0) {
    FS_Size(file);
    uVar2 = FS_Tell(file);
    iVar3 = FS_Read(&local_98,0x7c,1,file);
    if (iVar3 == 0x7c) {
      iVar4 = (*LittleLong)(local_98);
      if (1 < iVar4 - 0x1dU) {
        FS_Close(file);
        Con_Printf("Map [%s] has incorrect BSP version (%i should be %i).\n",pszFileName,iVar4,0x1e)
        ;
        return 0;
      }
      uVar6 = 0;
      do {
        if ((iVar1 == 0) != uVar6) {
          iVar5 = local_94[uVar6 * 2 + 1];
          FS_Seek(file,local_94[uVar6 * 2] + uVar2,FILESYSTEM_SEEK_HEAD);
          while (0 < iVar5) {
            if (iVar5 < 0x401) {
              iVar3 = FS_Read(local_498,iVar5,1,file);
            }
            else {
              iVar3 = FS_Read(local_498,0x400,1,file);
            }
            if (0 < iVar3) {
              iVar5 = iVar5 - iVar3;
              CRC32_ProcessBuffer(crcvalue,local_498,iVar3);
            }
            iVar3 = FS_IsOk(file);
            if (iVar3 == 0) {
              FS_Close(file);
              return 0;
            }
          }
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 != 0xf);
      iVar5 = 1;
      FS_Close(file);
    }
    else {
      Con_Printf("Could not read BSP header for map [%s].\n",pszFileName);
      FS_Close(file);
    }
  }
  return iVar5;
}


