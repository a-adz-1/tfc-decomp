// HashSearch__6CGraphiiRi  @ 000caee0
void HashSearch__6CGraphiiRi(int param_1,int param_2,int param_3,int *param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined2 local_c;
  undefined2 local_a;
  undefined4 local_8;
  
  local_c = (undefined2)param_2;
  local_a = (undefined2)param_3;
  (*DAT_0019f7f8)(&local_8);
  (*DAT_0019f7fc)(&local_8,&local_c,4);
  uVar4 = (*DAT_0019f804)(local_8);
  uVar2 = *(uint *)(param_1 + 0x20c0);
  uVar5 = (uVar4 >> 4) % uVar2;
  iVar3 = *(int *)(param_1 + 0x20bc);
  if (*(short *)(iVar3 + uVar5 * 2) != -1) {
    do {
      piVar1 = (int *)(*(int *)(param_1 + 0x10) + *(short *)(iVar3 + uVar5 * 2) * 0x18);
      if ((param_2 == *piVar1) && (param_3 == piVar1[1])) break;
      uVar5 = uVar5 + *(int *)(param_1 + 0x207c + (uVar4 & 0xf) * 4);
      if ((int)uVar2 <= (int)uVar5) {
        uVar5 = uVar5 - uVar2;
      }
    } while (*(short *)(iVar3 + uVar5 * 2) != -1);
  }
  *param_4 = (int)*(short *)(iVar3 + uVar5 * 2);
  return;
}


