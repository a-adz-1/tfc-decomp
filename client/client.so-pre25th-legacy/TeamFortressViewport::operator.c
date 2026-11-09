// TeamFortressViewport::operator_new  @ 000b90b0
/* DWARF original name: operator new */

void * TeamFortressViewport::operator_new(size_t stAllocateBlock)

{
  undefined4 *puVar1;
  uint uVar2;
  size_t sVar3;
  undefined4 *puVar4;
  byte bVar5;
  
  bVar5 = 0;
                    /* Unresolved local var: void * mem@[???] */
  puVar1 = operator_new(stAllocateBlock);
  puVar4 = puVar1;
  if (7 < stAllocateBlock) {
    sVar3 = stAllocateBlock;
    if (((uint)puVar1 & 1) != 0) {
      *(undefined1 *)puVar1 = 0;
      puVar4 = (undefined4 *)((int)puVar1 + 1);
      sVar3 = stAllocateBlock - 1;
    }
    if (((uint)puVar4 & 2) != 0) {
      *(undefined2 *)puVar4 = 0;
      sVar3 = sVar3 - 2;
      puVar4 = (undefined4 *)((int)puVar4 + 2);
    }
    if (((uint)puVar4 & 4) != 0) {
      *puVar4 = 0;
      sVar3 = sVar3 - 4;
      puVar4 = puVar4 + 1;
    }
    stAllocateBlock = sVar3 & 3;
    for (uVar2 = sVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + (uint)bVar5 * -2 + 1;
    }
  }
  if ((stAllocateBlock & 4) != 0) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  if ((stAllocateBlock & 2) != 0) {
    *(undefined2 *)puVar4 = 0;
    puVar4 = (undefined4 *)((int)puVar4 + 2);
  }
  if ((stAllocateBlock & 1) != 0) {
    *(undefined1 *)puVar4 = 0;
  }
  return puVar1;
}


