// CRC_File  @ 00044290
BOOL CRC_File(CRC32_t *crcvalue,char *pszFileName)

{
  FileHandle_t file;
  uint size;
  int iVar1;
  BOOL BVar2;
  int in_GS_OFFSET;
  undefined1 local_420 [1024];
  int local_20;
  
                    /* Unresolved local var: FileHandle_t fp@[???]
                       Unresolved local var: byte[1024] chunk@[???]
                       Unresolved local var: int nBytesRead@[???]
                       Unresolved local var: int nSize@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  file = FS_Open(pszFileName,"rb");
  if (file == (FileHandle_t)0x0) {
    BVar2 = 0;
  }
  else {
    size = FS_Size(file);
    do {
      if ((int)size < 1) {
LAB_00044350:
        FS_Close(file);
        BVar2 = 1;
        goto LAB_0004435d;
      }
      if ((int)size < 0x401) {
        iVar1 = FS_Read(local_420,size,1,file);
      }
      else {
        iVar1 = FS_Read(local_420,0x400,1,file);
      }
      if (0 < iVar1) {
        size = size - iVar1;
        CRC32_ProcessBuffer(crcvalue,local_420,iVar1);
      }
      iVar1 = FS_EndOfFile(file);
      if (iVar1 != 0) goto LAB_00044350;
      iVar1 = FS_IsOk(file);
    } while (iVar1 != 0);
    FS_Close(file);
    BVar2 = 0;
  }
LAB_0004435d:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return BVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CRC_MapFile  @ 000443a0
int CRC_MapFile(CRC32_t *crcvalue,char *pszFileName)

{
  int iVar1;
  FileHandle_t file;
  uint uVar2;
  int iVar3;
  int32 iVar4;
  int in_GS_OFFSET;
  uint local_4ac;
  undefined4 *local_4a0;
  int32 local_49c [31];
  undefined1 local_420 [1024];
  int local_20;
  
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
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = strcasecmp(com_gamedir,"bshift");
  file = FS_Open(pszFileName,"rb");
  if (file == (FileHandle_t)0x0) {
    iVar1 = 0;
  }
  else {
    local_4a0 = local_49c;
    FS_Size(file);
    uVar2 = FS_Tell(file);
    iVar3 = FS_Read(local_4a0,0x7c,1,file);
    if (iVar3 == 0x7c) {
      iVar4 = (*LittleLong)(local_49c[0]);
      if (iVar4 - 0x1dU < 2) {
        local_4ac = 0;
        do {
          if ((iVar1 == 0) != local_4ac) {
            iVar4 = local_4a0[2];
            FS_Seek(file,uVar2 + local_4a0[1],FILESYSTEM_SEEK_HEAD);
            while (0 < iVar4) {
              while( true ) {
                if (iVar4 < 0x401) {
                  iVar3 = FS_Read(local_420,iVar4,1,file);
                }
                else {
                  iVar3 = FS_Read(local_420,0x400,1,file);
                }
                if (0 < iVar3) break;
                iVar3 = FS_IsOk(file);
                if (iVar3 == 0) goto LAB_0004454c;
              }
              iVar4 = iVar4 - iVar3;
              CRC32_ProcessBuffer(crcvalue,local_420,iVar3);
              iVar3 = FS_IsOk(file);
              if (iVar3 == 0) {
LAB_0004454c:
                FS_Close(file);
                iVar1 = 0;
                goto LAB_00044450;
              }
            }
          }
          local_4ac = local_4ac + 1;
          local_4a0 = local_4a0 + 2;
        } while (local_4ac != 0xf);
        FS_Close(file);
        iVar1 = 1;
      }
      else {
        FS_Close(file);
        Con_Printf("Map [%s] has incorrect BSP version (%i should be %i).\n",pszFileName,iVar4,0x1e)
        ;
        iVar1 = 0;
      }
    }
    else {
      Con_Printf("Could not read BSP header for map [%s].\n",pszFileName);
      FS_Close(file);
      iVar1 = 0;
    }
  }
LAB_00044450:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}


