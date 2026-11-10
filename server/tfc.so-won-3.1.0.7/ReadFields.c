// ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi  @ 0011e4a4
undefined4
ReadFields__8CRestorePCcPvP15TYPEDESCRIPTIONi
          (int *param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ushort uVar7;
  undefined2 local_8;
  ushort local_6;
  undefined4 local_4;
  
  ReadShort__8CRestore(param_1);
  sVar1 = ReadShort__8CRestore(param_1);
  sVar2 = TokenHash__18CSaveRestoreBufferPCc(param_1,param_2);
  if (sVar1 == sVar2) {
    iVar4 = ReadInt__8CRestore(param_1);
    iVar6 = 0;
    uVar7 = 0;
    if (0 < param_5) {
      do {
        if ((param_1[1] == 0) || (((*(byte *)(param_4 + 0xe + (uint)uVar7 * 0x10) ^ 1) & 1) != 0)) {
          iVar5 = (uint)uVar7 * 0x10;
          memset((void *)(param_3 + *(int *)(param_4 + 8 + iVar5)),0,
                 (int)*(short *)(param_4 + 0xc + iVar5) *
                 *(int *)(gSizes + *(int *)(param_4 + iVar5) * 4));
        }
        uVar7 = uVar7 + 1;
      } while ((int)(uint)uVar7 < param_5);
    }
    uVar7 = 0;
    if (0 < iVar4) {
      do {
        BufferReadHeader__8CRestoreP6HEADER(param_1,&local_8);
        iVar6 = ReadField__8CRestorePvP15TYPEDESCRIPTIONiiiPcT1
                          (param_1,param_3,param_4,param_5,iVar6,local_8,
                           *(undefined4 *)(*(int *)(*param_1 + 0x18) + (uint)local_6 * 4),local_4);
        iVar6 = iVar6 + 1;
        uVar7 = uVar7 + 1;
      } while ((int)(uint)uVar7 < iVar4);
    }
    uVar3 = 1;
  }
  else {
    BufferRewind__18CSaveRestoreBufferi(param_1,4);
    uVar3 = 0;
  }
  return uVar3;
}


