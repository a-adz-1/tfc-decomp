// CRC_File  @ 000910cc
undefined4 CRC_File(undefined4 param_1,undefined4 param_2)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  undefined4 uVar4;
  FILE *local_408;
  undefined1 local_404 [1024];
  
  sVar1 = COM_FOpenFile(param_2,&local_408);
  if ((local_408 == (FILE *)0x0) || (sVar1 == 0xffffffff)) {
LAB_000911a7:
    uVar4 = 0;
  }
  else {
    if (0 < (int)sVar1) {
      do {
        sVar2 = sVar1;
        if (0x400 < (int)sVar1) {
          sVar2 = 0x400;
        }
        sVar2 = fread(local_404,1,sVar2,local_408);
        if (0 < (int)sVar2) {
          sVar1 = sVar1 - sVar2;
          CRC32_ProcessBuffer(param_1,local_404,sVar2);
        }
        iVar3 = feof(local_408);
        if (iVar3 != 0) {
          fclose(local_408);
          goto LAB_000911c0;
        }
        iVar3 = ferror(local_408);
        if (iVar3 != 0) {
          if (local_408 != (FILE *)0x0) {
            fclose(local_408);
          }
          goto LAB_000911a7;
        }
      } while (0 < (int)sVar1);
    }
    if (local_408 != (FILE *)0x0) {
      fclose(local_408);
    }
LAB_000911c0:
    uVar4 = 1;
  }
  return uVar4;
}


// CRC_MapFile  @ 000911d4
undefined4 CRC_MapFile(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  size_t sVar3;
  size_t sVar4;
  undefined1 *puVar5;
  size_t *local_494;
  int *local_490;
  int local_488;
  FILE *local_484;
  undefined1 local_480 [4];
  int local_47c;
  size_t local_478 [29];
  undefined1 local_404 [1024];
  
  iVar1 = COM_FOpenFile();
  if ((local_484 != (FILE *)0x0) && (iVar1 != -1)) {
    lVar2 = ftell(local_484);
    sVar3 = fread(local_480,0x7c,1,local_484);
    if (sVar3 == 1) {
      iVar1 = (*LittleLong)();
      puVar5 = &stack0xfffffb60;
      if (iVar1 - 0x1dU < 2) {
        local_488 = 0;
        local_490 = &local_47c;
        local_494 = local_478;
        do {
          if (local_488 != 0) {
            sVar3 = *local_494;
            fseek(local_484,lVar2 + *local_490,0);
            if (0 < (int)sVar3) {
              do {
                sVar4 = sVar3;
                if (0x400 < (int)sVar3) {
                  sVar4 = 0x400;
                }
                sVar4 = fread(local_404,1,sVar4,local_484);
                if (0 < (int)sVar4) {
                  sVar3 = sVar3 - sVar4;
                  CRC32_ProcessBuffer(param_1);
                }
                iVar1 = ferror(local_484);
                if (iVar1 != 0) {
                  if (local_484 == (FILE *)0x0) {
                    return 0;
                  }
                  goto LAB_00091360;
                }
              } while (0 < (int)sVar3);
            }
          }
          local_490 = local_490 + 2;
          local_494 = local_494 + 2;
          local_488 = local_488 + 1;
          if (0xe < local_488) {
            if (local_484 != (FILE *)0x0) {
              fclose(local_484);
            }
            return 1;
          }
        } while( true );
      }
      fclose(local_484);
      Con_Printf("Map [%s] has incorrect BSP version (%i should be %i).\n",param_2,iVar1);
    }
    else {
      puVar5 = &stack0xfffffb58;
      Con_Printf();
LAB_00091360:
      *(FILE **)(puVar5 + -4) = local_484;
      *(undefined4 *)(puVar5 + -8) = 0x91366;
      fclose(*(FILE **)(puVar5 + -4));
    }
  }
  return 0;
}


