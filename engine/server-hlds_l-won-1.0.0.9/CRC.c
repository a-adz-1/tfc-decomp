// CRC_File  @ 0808c450
undefined4 CRC_File(undefined4 param_1,undefined4 param_2)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  undefined4 uVar4;
  FILE *local_408;
  undefined1 local_404 [1024];
  
  sVar1 = COM_FindFile(param_2,0,&local_408);
  if ((local_408 == (FILE *)0x0) || (sVar1 == 0xffffffff)) {
LAB_0808c543:
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
          local_408 = (FILE *)0x0;
          break;
        }
        iVar3 = ferror(local_408);
        if (iVar3 != 0) {
          if (local_408 != (FILE *)0x0) {
            fclose(local_408);
          }
          goto LAB_0808c543;
        }
      } while (0 < (int)sVar1);
    }
    if (local_408 != (FILE *)0x0) {
      fclose(local_408);
    }
    uVar4 = 1;
  }
  return uVar4;
}


// CRC_MapFile  @ 0808c580
undefined4 CRC_MapFile(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  size_t sVar3;
  size_t sVar4;
  int iVar5;
  undefined1 *puVar6;
  FILE *local_484;
  undefined1 local_480 [4];
  size_t asStack_47c [30];
  undefined1 local_404 [1024];
  
  iVar1 = COM_FOpenFile();
  if ((local_484 != (FILE *)0x0) && (iVar1 != -1)) {
    lVar2 = ftell(local_484);
    sVar3 = fread(local_480,0x7c,1,local_484);
    if (sVar3 == 1) {
      iVar1 = (*LittleLong)();
      puVar6 = &stack0xfffffb6c;
      if (iVar1 - 0x1dU < 2) {
        iVar1 = 0;
        do {
          if (iVar1 != 0) {
            sVar3 = asStack_47c[iVar1 * 2 + 1];
            fseek(local_484,lVar2 + asStack_47c[iVar1 * 2],0);
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
                iVar5 = ferror(local_484);
                if (iVar5 != 0) {
                  if (local_484 == (FILE *)0x0) {
                    return 0;
                  }
                  goto LAB_0808c6d7;
                }
              } while (0 < (int)sVar3);
            }
          }
          iVar1 = iVar1 + 1;
          if (0xe < iVar1) {
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
      puVar6 = &stack0xfffffb64;
      Con_Printf();
LAB_0808c6d7:
      *(FILE **)(puVar6 + -4) = local_484;
      *(undefined4 *)(puVar6 + -8) = 0x808c6e3;
      fclose(*(FILE **)(puVar6 + -4));
    }
  }
  return 0;
}


