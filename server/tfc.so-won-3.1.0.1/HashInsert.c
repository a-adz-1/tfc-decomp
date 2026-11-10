// HashInsert__6CGraphiii  @ 000bde50
void HashInsert__6CGraphiii(int param_1,uint param_2,ushort param_3,undefined2 param_4)

{
  uint uVar1;
  uint uVar2;
  uint local_8;
  undefined4 local_4;
  
  local_8 = param_2 & 0xffff;
  local_8 = local_8 | (uint)param_3 << 0x10;
  (*DAT_001a7f98)(&local_4);
  (*DAT_001a7f9c)(&local_4,&local_8,4);
  uVar1 = (*DAT_001a7fa4)(local_4);
  uVar2 = (uVar1 >> 4) % *(uint *)(param_1 + 0x20c0);
  while (*(short *)(*(int *)(param_1 + 0x20bc) + uVar2 * 2) != -1) {
    uVar2 = uVar2 + *(int *)(param_1 + 0x207c + (uVar1 & 0xf) * 4);
    if (*(int *)(param_1 + 0x20c0) <= (int)uVar2) {
      uVar2 = uVar2 - *(int *)(param_1 + 0x20c0);
    }
  }
  *(undefined2 *)(*(int *)(param_1 + 0x20bc) + uVar2 * 2) = param_4;
  return;
}


