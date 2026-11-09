// Z_CheckHeap  @ 08086720
void Z_CheckHeap(void)

{
  int *piVar1;
  
  for (piVar1 = *(int **)(mainzone + 0x10); piVar1[3] != mainzone + 4; piVar1 = (int *)piVar1[3]) {
    if ((int)piVar1 + *piVar1 != piVar1[3]) {
      Sys_Error("Z_CheckHeap: block size does not touch the next block\n");
    }
    if (*(int **)(piVar1[3] + 0x10) != piVar1) {
      Sys_Error("Z_CheckHeap: next block doesn\'t have proper back link\n");
    }
    if ((piVar1[1] == 0) && (*(int *)(piVar1[3] + 4) == 0)) {
      Sys_Error("Z_CheckHeap: two consecutive free blocks\n");
    }
  }
  return;
}


// Z_ClearZone  @ 08086490
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


// Z_Free  @ 080864e0
void Z_Free(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  if (param_1 == 0) {
    Sys_Error("Z_Free: NULL pointer");
  }
  piVar1 = (int *)(param_1 + -0x18);
  if (*(int *)(param_1 + -0x10) != 0x1d4a11) {
    Sys_Error("Z_Free: freed a pointer without ZONEID");
  }
  if (*(int *)(param_1 + -0x14) == 0) {
    Sys_Error("Z_Free: freed a freed pointer");
  }
  *(undefined4 *)(param_1 + -0x14) = 0;
  piVar2 = *(int **)(param_1 + -8);
  piVar4 = piVar1;
  if (piVar2[1] == 0) {
    *piVar2 = *piVar2 + *piVar1;
    iVar3 = *(int *)(param_1 + -0xc);
    piVar2[3] = iVar3;
    *(int **)(iVar3 + 0x10) = piVar2;
    piVar4 = piVar2;
    if (piVar1 == *(int **)(mainzone + 0x1c)) {
      *(int **)(mainzone + 0x1c) = piVar2;
    }
  }
  piVar1 = (int *)piVar4[3];
  if (piVar1[1] == 0) {
    *piVar4 = *piVar4 + *piVar1;
    iVar3 = piVar1[3];
    piVar4[3] = iVar3;
    *(int **)(iVar3 + 0x10) = piVar4;
    if (piVar1 == *(int **)(mainzone + 0x1c)) {
      *(int **)(mainzone + 0x1c) = piVar4;
    }
  }
  return;
}


// Z_Malloc  @ 08086580
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


// Z_Print  @ 08086680
void Z_Print(int param_1)

{
  int *piVar1;
  
  Con_Printf("zone size: %i  location: %p\n",*mainzone,mainzone);
  piVar1 = *(int **)(param_1 + 0x10);
  while( true ) {
    Con_Printf("block:%p    size:%7i    tag:%3i\n",piVar1,*piVar1,piVar1[1]);
    if (piVar1[3] == param_1 + 4) break;
    if ((int)piVar1 + *piVar1 != piVar1[3]) {
      Con_Printf("ERROR: block size does not touch the next block\n");
    }
    if (*(int **)(piVar1[3] + 0x10) != piVar1) {
      Con_Printf("ERROR: next block doesn\'t have proper back link\n");
    }
    if ((piVar1[1] == 0) && (*(int *)(piVar1[3] + 4) == 0)) {
      Con_Printf("ERROR: two consecutive free blocks\n");
    }
    piVar1 = (int *)piVar1[3];
  }
  return;
}


// Z_TagMalloc  @ 080865c0
uint * Z_TagMalloc(int param_1,uint param_2)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  
  if (param_2 == 0) {
    Sys_Error("Z_TagMalloc: tried to use a 0 tag");
  }
  uVar6 = param_1 + 0x23U & 0xfffffff8;
  puVar4 = *(uint **)(mainzone + 0x1c);
  puVar1 = puVar4 + 4;
  puVar5 = puVar4;
  do {
    if (puVar4 == (uint *)*puVar1) {
      return (uint *)0x0;
    }
    if (puVar4[1] == 0) {
      puVar4 = (uint *)puVar4[3];
    }
    else {
      puVar4 = (uint *)puVar4[3];
      puVar5 = puVar4;
    }
  } while ((puVar5[1] != 0) || ((int)*puVar5 < (int)uVar6));
  if (0x40 < (int)(*puVar5 - uVar6)) {
    piVar2 = (int *)(uVar6 + (int)puVar5);
    *piVar2 = *puVar5 - uVar6;
    piVar2[1] = 0;
    piVar2[4] = (int)puVar5;
    piVar2[2] = 0x1d4a11;
    uVar3 = puVar5[3];
    piVar2[3] = uVar3;
    *(int **)(uVar3 + 0x10) = piVar2;
    puVar5[3] = (uint)piVar2;
    *puVar5 = uVar6;
  }
  puVar5[1] = param_2;
  *(uint *)(mainzone + 0x1c) = puVar5[3];
  puVar5[2] = 0x1d4a11;
  *(undefined4 *)((*puVar5 - 4) + (int)puVar5) = 0x1d4a11;
  return puVar5 + 6;
}


