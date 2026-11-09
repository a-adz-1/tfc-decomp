// HashSearch__6CGraphiiRi  @ 000ce0a0
void HashSearch__6CGraphiiRi(int param_1,uint param_2,uint param_3,int *param_4)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint local_c;
  undefined4 local_8;
  
  local_c = param_2 & 0xffff;
  local_c = local_c | param_3 << 0x10;
  (*DAT_00175618)(&local_8);
  (*DAT_0017561c)(&local_8,&local_c,4);
  uVar3 = (*DAT_00175624)(local_8);
  uVar4 = (uVar3 >> 4) % *(uint *)(param_1 + 0x20c0);
  iVar2 = *(int *)(param_1 + 0x20bc);
  if (*(short *)(iVar2 + uVar4 * 2) != -1) {
    do {
      puVar1 = (uint *)(*(int *)(param_1 + 0x10) + *(short *)(iVar2 + uVar4 * 2) * 0x18);
      if ((param_2 == *puVar1) && (param_3 == puVar1[1])) break;
      uVar4 = uVar4 + *(int *)(param_1 + 0x207c + (uVar3 & 0xf) * 4);
      if (*(int *)(param_1 + 0x20c0) <= (int)uVar4) {
        uVar4 = uVar4 - *(int *)(param_1 + 0x20c0);
      }
    } while (*(short *)(iVar2 + uVar4 * 2) != -1);
  }
  *param_4 = (int)*(short *)(*(int *)(param_1 + 0x20bc) + uVar4 * 2);
  return;
}


