// WriteFunction__5CSavePCcPCii  @ 00120fdc
void WriteFunction__5CSavePCcPCii(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar2 = (uint *)(*DAT_0019f7dc)(*param_3);
  if (puVar2 == (uint *)0x0) {
    (*DAT_0019f794)(4,"Invalid function pointer in entity!");
    return;
  }
  uVar4 = (uint)puVar2 & 3;
  puVar1 = puVar2;
  if (uVar4 != 0) {
    puVar3 = puVar2;
    if ((POPCOUNT(uVar4) & 1U) != 0) {
      if (uVar4 != 2) {
        if ((char)*puVar2 == '\0') goto LAB_00121049;
        puVar3 = (uint *)((int)puVar2 + 1);
      }
      if ((char)*puVar3 == '\0') goto LAB_00121049;
      puVar3 = (uint *)((int)puVar3 + 1);
    }
    if ((char)*puVar3 == '\0') goto LAB_00121049;
    puVar1 = (uint *)((int)puVar3 + 1);
  }
  do {
    puVar3 = puVar1;
    uVar4 = *puVar3;
    if ((char)uVar4 == '\0') goto LAB_00121049;
    if ((char)(uVar4 >> 8) == '\0') goto LAB_00121048;
    if ((uVar4 & 0xff0000) == 0) goto LAB_00121047;
    puVar1 = puVar3 + 1;
  } while ((uVar4 & 0xff000000) != 0);
  puVar3 = (uint *)((int)puVar3 + 1);
LAB_00121047:
  puVar3 = (uint *)((int)puVar3 + 1);
LAB_00121048:
  puVar3 = (uint *)((int)puVar3 + 1);
LAB_00121049:
  BufferField__5CSavePCciT1(param_1,param_2,(char *)((int)puVar3 + (1 - (int)puVar2)),puVar2);
  return;
}


