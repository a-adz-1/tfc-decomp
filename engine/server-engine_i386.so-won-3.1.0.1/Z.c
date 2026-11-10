// Z_CheckHeap  @ 0008d83c
void Z_CheckHeap(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = *(int **)(mainzone + 0x10);
  piVar1 = (int *)piVar3[3];
  if (piVar1 != (int *)(mainzone + 4)) {
    do {
      piVar2 = piVar1;
      if ((int *)((int)piVar3 + *piVar3) != piVar1) {
        Sys_Error("Z_CheckHeap: block size does not touch the next block\n");
        piVar2 = (int *)piVar3[3];
      }
      if ((int *)piVar2[4] != piVar3) {
        Sys_Error("Z_CheckHeap: next block doesn\'t have proper back link\n");
        piVar2 = (int *)piVar3[3];
      }
      if ((piVar3[1] == 0) && (piVar2[1] == 0)) {
        Sys_Error("Z_CheckHeap: two consecutive free blocks\n");
        piVar2 = (int *)piVar3[3];
      }
      piVar1 = (int *)piVar2[3];
      piVar3 = piVar2;
    } while (piVar1 != (int *)(mainzone + 4));
  }
  return;
}


// Z_ClearZone  @ 0008d55c
void Z_ClearZone(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1 + 0x20;
  *(int *)(param_1 + 0x14) = iVar1;
  *(int *)(param_1 + 0x10) = iVar1;
  *(undefined4 *)(param_1 + 8) = 1;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(int *)(param_1 + 0x1c) = iVar1;
  *(int *)(param_1 + 0x2c) = param_1 + 4;
  *(int *)(param_1 + 0x30) = param_1 + 4;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0x1d4a11;
  *(int *)(param_1 + 0x20) = param_2 + -0x20;
  return;
}


// Z_Free  @ 0008d5ac
void Z_Free(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    Sys_Error("Z_Free: NULL pointer");
  }
  if (*(int *)(param_1 + -0x10) != 0x1d4a11) {
    Sys_Error("Z_Free: freed a pointer without ZONEID");
  }
  if (*(int *)(param_1 + -0x14) == 0) {
    Sys_Error("Z_Free: freed a freed pointer");
  }
  piVar1 = *(int **)(param_1 + -8);
  *(undefined4 *)(param_1 + -0x14) = 0;
  piVar3 = (int *)(param_1 + -0x18);
  if (piVar1[1] == 0) {
    *piVar1 = *piVar1 + *(int *)(param_1 + -0x18);
    iVar2 = *(int *)(param_1 + -0xc);
    piVar1[3] = iVar2;
    *(int **)(iVar2 + 0x10) = piVar1;
    piVar3 = piVar1;
    if ((int *)(param_1 + -0x18) == *(int **)(mainzone + 0x1c)) {
      *(int **)(mainzone + 0x1c) = piVar1;
    }
  }
  piVar1 = (int *)piVar3[3];
  if (piVar1[1] == 0) {
    *piVar3 = *piVar3 + *piVar1;
    iVar2 = piVar1[3];
    piVar3[3] = iVar2;
    *(int **)(iVar2 + 0x10) = piVar3;
    if (piVar1 == *(int **)(mainzone + 0x1c)) {
      *(int **)(mainzone + 0x1c) = piVar3;
    }
  }
  return;
}


// Z_Malloc  @ 0008d664
int Z_Malloc(undefined4 param_1)

{
  int iVar1;
  
  Z_CheckHeap();
  iVar1 = Z_TagMalloc(param_1,1);
  if (iVar1 == 0) {
    Sys_Error("Z_Malloc: failed on allocation of %i bytes",param_1);
  }
  Q_memset(iVar1,0,param_1);
  return iVar1;
}


// Z_Print  @ 0008d784
void Z_Print(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  Con_Printf("zone size: %i  location: %p\n",*mainzone,mainzone);
  piVar1 = *(int **)(param_1 + 0x10);
  while( true ) {
    piVar2 = piVar1;
    Con_Printf("block:%p    size:%7i    tag:%3i\n",piVar2,*piVar2,piVar2[1]);
    piVar1 = (int *)piVar2[3];
    if (piVar1 == (int *)(param_1 + 4)) break;
    if ((int *)((int)piVar2 + *piVar2) != piVar1) {
      Con_Printf("ERROR: block size does not touch the next block\n");
      piVar1 = (int *)piVar2[3];
    }
    if ((int *)piVar1[4] != piVar2) {
      Con_Printf("ERROR: next block doesn\'t have proper back link\n");
      piVar1 = (int *)piVar2[3];
    }
    if ((piVar2[1] == 0) && (piVar1[1] == 0)) {
      Con_Printf("ERROR: two consecutive free blocks\n");
      piVar1 = (int *)piVar2[3];
    }
  }
  return;
}


// Z_TagMalloc  @ 0008d6b4
uint * Z_TagMalloc(int param_1,uint param_2)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  
  if (param_2 == 0) {
    Sys_Error("Z_TagMalloc: tried to use a 0 tag");
  }
  uVar7 = param_1 + 0x23U & 0xfffffff8;
  puVar4 = *(uint **)(mainzone + 0x1c);
  puVar1 = puVar4 + 4;
  puVar5 = puVar4;
  do {
    if (puVar5 == (uint *)*puVar1) {
      return (uint *)0x0;
    }
    if (puVar5[1] == 0) {
      puVar5 = (uint *)puVar5[3];
    }
    else {
      puVar4 = (uint *)puVar5[3];
      puVar5 = puVar4;
    }
  } while ((puVar4[1] != 0) || ((int)*puVar4 < (int)uVar7));
  iVar6 = *puVar4 - uVar7;
  if (0x40 < iVar6) {
    piVar2 = (int *)(uVar7 + (int)puVar4);
    *piVar2 = iVar6;
    piVar2[1] = 0;
    piVar2[4] = (int)puVar4;
    piVar2[2] = 0x1d4a11;
    uVar3 = puVar4[3];
    piVar2[3] = uVar3;
    *(int **)(uVar3 + 0x10) = piVar2;
    puVar4[3] = (uint)piVar2;
    *puVar4 = uVar7;
  }
  puVar4[1] = param_2;
  *(uint *)(mainzone + 0x1c) = puVar4[3];
  puVar4[2] = 0x1d4a11;
  *(undefined4 *)((*puVar4 - 4) + (int)puVar4) = 0x1d4a11;
  return puVar4 + 6;
}


