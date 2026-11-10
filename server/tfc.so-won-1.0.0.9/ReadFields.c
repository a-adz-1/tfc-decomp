// ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi  @ 00119de0
undefined4
ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
          (int *param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  int local_1c;
  undefined2 uStack_c;
  ushort uStack_a;
  undefined4 uStack_8;
  
  ReadShort__8CRestore(param_1);
  sVar1 = ReadShort__8CRestore(param_1);
  sVar2 = TokenHash__18CSaveRestoreBufferPCc(param_1,param_2);
  if (sVar1 == sVar2) {
    iVar4 = ReadInt__8CRestore(param_1);
    local_1c = 0;
    uVar6 = 0;
    if (0 < param_5) {
      do {
        if ((param_1[1] == 0) || (((*(byte *)(param_4 + 0xe + (uint)uVar6 * 0x10) ^ 1) & 1) != 0)) {
          iVar5 = (uint)uVar6 * 0x10;
          memset((void *)(param_3 + *(int *)(param_4 + 8 + iVar5)),0,
                 (int)*(short *)(param_4 + 0xc + iVar5) *
                 *(int *)(gSizes + *(int *)(param_4 + iVar5) * 4));
        }
        uVar6 = uVar6 + 1;
      } while ((int)(uint)uVar6 < param_5);
    }
    uVar6 = 0;
    if (0 < iVar4) {
      do {
        BufferReadHeader__8CRestoreP6HEADER(param_1,&uStack_c);
        local_1c = ReadField__8CRestorePvP15TYPEDESCRIPTIONiiiPcT1
                             (param_1,param_3,param_4,param_5,local_1c,uStack_c,
                              *(undefined4 *)(*(int *)(*param_1 + 0x18) + (uint)uStack_a * 4),
                              uStack_8);
        local_1c = local_1c + 1;
        uVar6 = uVar6 + 1;
      } while ((int)(uint)uVar6 < iVar4);
    }
    uVar3 = 1;
  }
  else {
    BufferRewind__18CSaveRestoreBufferi(param_1,4);
    uVar3 = 0;
  }
  return uVar3;
}


