// UpdateAutoTargets__14CFuncTrackAutoi  @ 000c6c58
void UpdateAutoTargets__14CFuncTrackAutoi(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if ((*(int *)(param_1 + 0x498) != 0) && (*(int *)(param_1 + 0x49c) != 0)) {
    if (*(int *)(param_1 + 0x4b4) == 0) {
      piVar1 = (int *)GetNext__10CPathTrack(*(undefined4 *)(param_1 + 0x498));
      uVar2 = *(undefined4 *)(param_1 + 0x49c);
    }
    else {
      piVar1 = (int *)GetNext__10CPathTrack(*(undefined4 *)(param_1 + 0x49c));
      uVar2 = *(undefined4 *)(param_1 + 0x498);
    }
    piVar3 = (int *)GetNext__10CPathTrack(uVar2);
    if ((((piVar1 != (int *)0x0) &&
         (*(byte *)(*piVar1 + 0x1a0) = *(byte *)(*piVar1 + 0x1a0) & 0xfe,
         *(int *)(param_1 + 0x4b0) == 2)) && (*(int *)(param_1 + 0x4a0) != 0)) &&
       (piVar1 = *(int **)(param_1 + 0x4a0),
       (byte)((byte)((ushort)((ushort)NAN(*(float *)(*piVar1 + 0x1f8)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(*piVar1 + 0x1f8) == 0.0) << 0xe) >> 8)) == 0x40)) {
      (**(code **)(piVar1[0xf5] + 0xb0))(piVar1,param_1,param_1,1,0);
    }
    if (piVar3 != (int *)0x0) {
      *(byte *)(*piVar3 + 0x1a0) = *(byte *)(*piVar3 + 0x1a0) | 1;
    }
  }
  return;
}


// UpdateAutoTargets__16CFuncTrackChangei  @ 000c69b4
void UpdateAutoTargets__16CFuncTrackChangei(int param_1,int param_2)

{
  byte *pbVar1;
  
  if ((*(int *)(param_1 + 0x498) != 0) && (*(int *)(param_1 + 0x49c) != 0)) {
    if (param_2 == 0) {
      pbVar1 = (byte *)(**(int **)(param_1 + 0x498) + 0x1a0);
      *pbVar1 = *pbVar1 & 0xfe;
    }
    else {
      pbVar1 = (byte *)(**(int **)(param_1 + 0x498) + 0x1a0);
      *pbVar1 = *pbVar1 | 1;
    }
    if (param_2 == 1) {
      pbVar1 = (byte *)(**(int **)(param_1 + 0x49c) + 0x1a0);
      *pbVar1 = *pbVar1 & 0xfe;
    }
    else {
      pbVar1 = (byte *)(**(int **)(param_1 + 0x49c) + 0x1a0);
      *pbVar1 = *pbVar1 | 1;
    }
  }
  return;
}


