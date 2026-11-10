// ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi  @ 00120568
undefined4
ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
          (int *param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iStack_28;
  ushort uStack_22;
  int iStack_10;
  undefined2 uStack_c;
  ushort uStack_a;
  undefined4 uStack_8;
  
  ReadShort__8CRestore(param_1);
  sVar1 = ReadShort__8CRestore(param_1);
  sVar2 = TokenHash__18CSaveRestoreBufferPCc(param_1,param_2);
  if (sVar1 == sVar2) {
    iVar4 = ReadInt__8CRestore(param_1);
    iStack_10 = 0;
    uStack_22 = 0;
    if (0 < param_5) {
      do {
        if ((param_1[1] == 0) ||
           (((*(byte *)(param_4 + 0xe + (uint)uStack_22 * 0x10) ^ 1) & 1) != 0)) {
          iVar5 = (uint)uStack_22 * 0x10;
          memset((void *)(param_3 + *(int *)(param_4 + 8 + iVar5)),0,
                 (int)*(short *)(param_4 + 0xc + iVar5) *
                 *(int *)(gSizes + *(int *)(param_4 + iVar5) * 4));
        }
        uStack_22 = uStack_22 + 1;
      } while ((int)(uint)uStack_22 < param_5);
    }
    uStack_22 = 0;
    if (0 < iVar4) {
      do {
        BufferReadHeader__8CRestoreP6HEADER(param_1,&uStack_c);
        iStack_10 = ReadField__8CRestorePvP15TYPEDESCRIPTIONiiiPcT1
                              (param_1,param_3,param_4,param_5,iStack_10,uStack_c,
                               *(undefined4 *)(*(int *)(*param_1 + 0x18) + (uint)uStack_a * 4),
                               uStack_8);
        iStack_10 = iStack_10 + 1;
        uStack_22 = uStack_22 + 1;
      } while ((int)(uint)uStack_22 < iVar4);
    }
    uVar3 = 1;
  }
  else {
    iStack_28 = 4;
    iVar4 = *param_1;
    if (iVar4 != 0) {
      if (*(int *)(iVar4 + 8) < 4) {
        iStack_28 = *(int *)(iVar4 + 8);
      }
      *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) - iStack_28;
      *(int *)(*param_1 + 8) = *(int *)(*param_1 + 8) - iStack_28;
    }
    uVar3 = 0;
  }
  return uVar3;
}


