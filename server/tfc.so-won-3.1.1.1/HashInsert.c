// HashInsert__6CGraphiii  @ 000cafcc
void HashInsert__6CGraphiii(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined2 local_c;
  undefined2 local_a;
  undefined4 local_8;
  
  local_c = param_2;
  local_a = param_3;
  (*DAT_0019f7f8)(&local_8);
  (*DAT_0019f7fc)(&local_8,&local_c,4);
  uVar4 = (*DAT_0019f804)(local_8);
  uVar2 = *(uint *)(param_1 + 0x20c0);
  uVar5 = (uVar4 >> 4) % uVar2;
  iVar3 = *(int *)(param_1 + 0x20bc);
  sVar1 = *(short *)(iVar3 + uVar5 * 2);
  while (sVar1 != -1) {
    uVar5 = uVar5 + *(int *)(param_1 + 0x207c + (uVar4 & 0xf) * 4);
    if ((int)uVar2 <= (int)uVar5) {
      uVar5 = uVar5 - uVar2;
    }
    sVar1 = *(short *)(iVar3 + uVar5 * 2);
  }
  *(undefined2 *)(iVar3 + uVar5 * 2) = param_4;
  return;
}


