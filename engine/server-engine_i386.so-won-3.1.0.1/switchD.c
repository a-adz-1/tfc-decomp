// switchD_00054354::caseD_0  @ 00054380
void switchD_00054354::caseD_0(void)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  size_t __size;
  char *__format;
  undefined4 uVar4;
  int iVar5;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  __format = (char *)(unaff_EBX + -0x14d68);
  while( true ) {
    sprintf(*(char **)(unaff_EBP + -0x2c4),__format);
    fVar2 = *(float *)(unaff_EBX + -0x14b08);
    iVar5 = *(int *)(*(int *)(unaff_EBP + -0x2a8) + 0x48);
    *(int *)(unaff_EBP + -0x2b4) = unaff_ESI + 1;
    Con_Printf(unaff_EBX + -0x14b8d,unaff_ESI + 1,*(undefined4 *)(unaff_EBP + -0x2c4),
               (double)(fVar2 * (float)iVar5),*(undefined4 *)(unaff_EBP + -0x2b0));
    __size = *(size_t *)(*(int *)(unaff_EBP + -0x2a8) + 0x8c);
    if (__size - 1 < 0x1ffff) {
      uVar4 = Mem_Malloc(__size + 1);
      *(undefined4 *)(unaff_EBP + -0x2b8) = uVar4;
      Q_memset(uVar4,0);
      fseek(*(FILE **)(unaff_EBP + -0x2ac),*(long *)(*(int *)(unaff_EBP + -0x2a8) + 0x88),0);
      fread(*(void **)(unaff_EBP + -0x2b8),__size,1,*(FILE **)(unaff_EBP + -0x2ac));
      iVar5 = unaff_EBP + -0x29c;
      Q_memset(iVar5,0,0x58);
      MD5Init(iVar5);
      MD5Update(iVar5,*(undefined4 *)(unaff_EBP + -0x2b8),__size);
      iVar1 = unaff_EBP + -0x244;
      MD5Final(iVar1,iVar5);
      iVar5 = *(int *)(unaff_EBP + -0x2a8) + 0x4d;
      *(int *)(unaff_EBP + -700) = iVar5;
      iVar5 = Q_memcmp(iVar5,iVar1,0x10);
      if (iVar5 == 0) {
        iVar5 = unaff_EBX + -0x14b39;
      }
      else {
        Con_Printf(unaff_EBX + -0x14b78);
        iVar5 = unaff_EBX + -0x14b6b;
        Con_Printf();
        uVar4 = MD5_Print(*(undefined4 *)(unaff_EBP + -700));
        Con_Printf(unaff_EBX + -0x14b55,uVar4);
        uVar4 = MD5_Print(iVar1);
        Con_Printf(unaff_EBX + -0x14b47,uVar4);
      }
      Con_Printf(iVar5);
      if (*(int *)(unaff_EBP + -0x2b8) != 0) {
        Mem_Free(*(undefined4 *)(unaff_EBP + -0x2b8));
      }
    }
    else {
      Con_Printf();
    }
    unaff_ESI = *(int *)(unaff_EBP + -0x2b4);
    if (*(int *)(unaff_EBP + -0x2a4) <= unaff_ESI) break;
    *(int *)(unaff_EBP + -0x2a8) = unaff_ESI * 0x90 + *(int *)(*(int *)(unaff_EBP + -0x2c0) + 4);
    COM_FileBase();
    uVar3 = *(uint *)(*(int *)(unaff_EBP + -0x2a8) + 0x40);
    if (uVar3 < 6) {
                    /* WARNING: Could not recover jumptable at 0x00054354. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(unaff_EBX - *(int *)(unaff_EBX + -0x66f1c + uVar3 * 4)))();
      return;
    }
    __format = (char *)(unaff_EBX + -0x14d4e);
  }
  fclose(*(FILE **)(unaff_EBP + -0x2ac));
  Mem_Free();
  return;
}


// switchD_00054354::caseD_3  @ 00054370
void switchD_00054354::caseD_3(void)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  size_t __size;
  char *__format;
  undefined4 uVar4;
  int iVar5;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  __format = (char *)(unaff_EBX + -0x14d73);
  while( true ) {
    sprintf(*(char **)(unaff_EBP + -0x2c4),__format);
    fVar2 = *(float *)(unaff_EBX + -0x14b08);
    iVar5 = *(int *)(*(int *)(unaff_EBP + -0x2a8) + 0x48);
    *(int *)(unaff_EBP + -0x2b4) = unaff_ESI + 1;
    Con_Printf(unaff_EBX + -0x14b8d,unaff_ESI + 1,*(undefined4 *)(unaff_EBP + -0x2c4),
               (double)(fVar2 * (float)iVar5),*(undefined4 *)(unaff_EBP + -0x2b0));
    __size = *(size_t *)(*(int *)(unaff_EBP + -0x2a8) + 0x8c);
    if (__size - 1 < 0x1ffff) {
      uVar4 = Mem_Malloc(__size + 1);
      *(undefined4 *)(unaff_EBP + -0x2b8) = uVar4;
      Q_memset(uVar4,0);
      fseek(*(FILE **)(unaff_EBP + -0x2ac),*(long *)(*(int *)(unaff_EBP + -0x2a8) + 0x88),0);
      fread(*(void **)(unaff_EBP + -0x2b8),__size,1,*(FILE **)(unaff_EBP + -0x2ac));
      iVar5 = unaff_EBP + -0x29c;
      Q_memset(iVar5,0,0x58);
      MD5Init(iVar5);
      MD5Update(iVar5,*(undefined4 *)(unaff_EBP + -0x2b8),__size);
      iVar1 = unaff_EBP + -0x244;
      MD5Final(iVar1,iVar5);
      iVar5 = *(int *)(unaff_EBP + -0x2a8) + 0x4d;
      *(int *)(unaff_EBP + -700) = iVar5;
      iVar5 = Q_memcmp(iVar5,iVar1,0x10);
      if (iVar5 == 0) {
        iVar5 = unaff_EBX + -0x14b39;
      }
      else {
        Con_Printf(unaff_EBX + -0x14b78);
        iVar5 = unaff_EBX + -0x14b6b;
        Con_Printf();
        uVar4 = MD5_Print(*(undefined4 *)(unaff_EBP + -700));
        Con_Printf(unaff_EBX + -0x14b55,uVar4);
        uVar4 = MD5_Print(iVar1);
        Con_Printf(unaff_EBX + -0x14b47,uVar4);
      }
      Con_Printf(iVar5);
      if (*(int *)(unaff_EBP + -0x2b8) != 0) {
        Mem_Free(*(undefined4 *)(unaff_EBP + -0x2b8));
      }
    }
    else {
      Con_Printf();
    }
    unaff_ESI = *(int *)(unaff_EBP + -0x2b4);
    if (*(int *)(unaff_EBP + -0x2a4) <= unaff_ESI) break;
    *(int *)(unaff_EBP + -0x2a8) = unaff_ESI * 0x90 + *(int *)(*(int *)(unaff_EBP + -0x2c0) + 4);
    COM_FileBase();
    uVar3 = *(uint *)(*(int *)(unaff_EBP + -0x2a8) + 0x40);
    if (uVar3 < 6) {
                    /* WARNING: Could not recover jumptable at 0x00054354. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(unaff_EBX - *(int *)(unaff_EBX + -0x66f1c + uVar3 * 4)))();
      return;
    }
    __format = (char *)(unaff_EBX + -0x14d4e);
  }
  fclose(*(FILE **)(unaff_EBP + -0x2ac));
  Mem_Free();
  return;
}


