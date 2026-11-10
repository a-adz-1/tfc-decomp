// Z_CheckHeap  @ 000c10bc
void Z_CheckHeap(void)

{
  int *local_8;
  
  for (local_8 = *(int **)(mainzone + 0x10); local_8[3] != mainzone + 4; local_8 = (int *)local_8[3]
      ) {
    if (*local_8 + (int)local_8 != local_8[3]) {
      Sys_Error("Z_CheckHeap: block size does not touch the next block\n");
    }
    if (*(int **)(local_8[3] + 0x10) != local_8) {
      Sys_Error("Z_CheckHeap: next block doesn\'t have proper back link\n");
    }
    if ((local_8[1] == 0) && (*(int *)(local_8[3] + 4) == 0)) {
      Sys_Error("Z_CheckHeap: two consecutive free blocks\n");
    }
  }
  return;
}


// Z_ClearZone  @ 000c0c18
void Z_ClearZone(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 0x20);
  *(int **)(param_1 + 0x14) = piVar1;
  *(int **)(param_1 + 0x10) = piVar1;
  *(undefined4 *)(param_1 + 8) = 1;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(int **)(param_1 + 0x1c) = piVar1;
  *(int *)(param_1 + 0x2c) = param_1 + 4;
  *(int *)(param_1 + 0x30) = param_1 + 4;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0x1d4a11;
  *piVar1 = param_2 + -0x20;
  return;
}


// Z_Free  @ 000c0c9c
void Z_Free(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *local_8;
  
  if (param_1 == 0) {
    Sys_Error("Z_Free: NULL pointer");
  }
  piVar2 = (int *)(param_1 + -0x18);
  if (*(int *)(param_1 + -0x10) != 0x1d4a11) {
    Sys_Error("Z_Free: freed a pointer without ZONEID");
  }
  if (*(int *)(param_1 + -0x14) == 0) {
    Sys_Error("Z_Free: freed a freed pointer");
  }
  *(undefined4 *)(param_1 + -0x14) = 0;
  piVar1 = *(int **)(param_1 + -8);
  local_8 = piVar2;
  if (piVar1[1] == 0) {
    *piVar1 = *piVar2 + *piVar1;
    piVar1[3] = *(int *)(param_1 + -0xc);
    *(int **)(piVar1[3] + 0x10) = piVar1;
    local_8 = piVar1;
    if (piVar2 == *(int **)(mainzone + 0x1c)) {
      *(int **)(mainzone + 0x1c) = piVar1;
    }
  }
  piVar2 = (int *)local_8[3];
  if (piVar2[1] == 0) {
    *local_8 = *piVar2 + *local_8;
    local_8[3] = piVar2[3];
    *(int **)(local_8[3] + 0x10) = local_8;
    if (piVar2 == *(int **)(mainzone + 0x1c)) {
      *(int **)(mainzone + 0x1c) = local_8;
    }
  }
  return;
}


// Z_Malloc  @ 000c0de0
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


// Z_Print  @ 000c0fb8
void Z_Print(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *local_8;
  
  Con_Printf("zone size: %i  location: %p\n",*mainzone,mainzone);
  local_8 = *(int **)(param_1 + 0x10);
  while( true ) {
    iVar3 = local_8[1];
    iVar2 = *local_8;
    piVar1 = local_8;
    Con_Printf("block:%p    size:%7i    tag:%3i\n",local_8,iVar2,iVar3);
    if (local_8[3] == param_1 + 4) break;
    if (*local_8 + (int)local_8 != local_8[3]) {
      Con_Printf("ERROR: block size does not touch the next block\n",piVar1,iVar2,iVar3);
    }
    if (*(int **)(local_8[3] + 0x10) != local_8) {
      Con_Printf("ERROR: next block doesn\'t have proper back link\n",piVar1,iVar2,iVar3);
    }
    if ((local_8[1] == 0) && (*(int *)(local_8[3] + 4) == 0)) {
      Con_Printf("ERROR: two consecutive free blocks\n",piVar1,iVar2,iVar3);
    }
    local_8 = (int *)local_8[3];
  }
  return;
}


// Z_TagMalloc  @ 000c0e50
uint * Z_TagMalloc(int param_1,uint param_2)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  uint *local_18;
  uint *local_10;
  
  if (param_2 == 0) {
    Sys_Error("Z_TagMalloc: tried to use a 0 tag");
  }
  uVar3 = param_1 + 0x23U & 0xfffffff8;
  local_18 = *(uint **)(mainzone + 0x1c);
  puVar1 = local_18 + 4;
  local_10 = local_18;
  do {
    if (local_10 == (uint *)*puVar1) {
      return (uint *)0x0;
    }
    if (local_10[1] == 0) {
      local_10 = (uint *)local_10[3];
    }
    else {
      local_18 = (uint *)local_10[3];
      local_10 = local_18;
    }
  } while ((local_18[1] != 0) || ((int)*local_18 < (int)uVar3));
  if (0x40 < (int)(*local_18 - uVar3)) {
    piVar2 = (int *)(uVar3 + (int)local_18);
    *piVar2 = *local_18 - uVar3;
    piVar2[1] = 0;
    piVar2[4] = (int)local_18;
    piVar2[2] = 0x1d4a11;
    piVar2[3] = local_18[3];
    *(int **)(piVar2[3] + 0x10) = piVar2;
    local_18[3] = (uint)piVar2;
    *local_18 = uVar3;
  }
  local_18[1] = param_2;
  *(uint *)(mainzone + 0x1c) = local_18[3];
  local_18[2] = 0x1d4a11;
  *(undefined4 *)((int)local_18 + (*local_18 - 4)) = 0x1d4a11;
  return local_18 + 6;
}


