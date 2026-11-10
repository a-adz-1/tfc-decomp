// HashInsert__6CGraphiii  @ 000cdfe0
void HashInsert__6CGraphiii(int param_1,uint param_2,ushort param_3,undefined2 param_4)

{
  uint uVar1;
  uint uVar2;
  uint local_c;
  undefined4 local_8;
  
  local_c = param_2 & 0xffff;
  local_c = local_c | (uint)param_3 << 0x10;
  (*DAT_00175618)(&local_8);
  (*DAT_0017561c)(&local_8,&local_c,4);
  uVar1 = (*DAT_00175624)(local_8);
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


