// UpdateAutoTargets__14CFuncTrackAutoi  @ 000d53e0
void UpdateAutoTargets__14CFuncTrackAutoi(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if ((*(int *)(param_1 + 0x48c) != 0) && (*(int *)(param_1 + 0x490) != 0)) {
    if (*(int *)(param_1 + 0x4a8) == 0) {
      piVar1 = (int *)GetNext__10CPathTrack(*(undefined4 *)(param_1 + 0x48c));
      uVar2 = *(undefined4 *)(param_1 + 0x490);
    }
    else {
      piVar1 = (int *)GetNext__10CPathTrack(*(undefined4 *)(param_1 + 0x490));
      uVar2 = *(undefined4 *)(param_1 + 0x48c);
    }
    piVar3 = (int *)GetNext__10CPathTrack(uVar2);
    if ((((piVar1 != (int *)0x0) &&
         (*(byte *)(*piVar1 + 0x180) = *(byte *)(*piVar1 + 0x180) & 0xfe,
         *(int *)(param_1 + 0x4a4) == 2)) && (*(int *)(param_1 + 0x494) != 0)) &&
       (piVar1 = *(int **)(param_1 + 0x494),
       (byte)((byte)((ushort)((ushort)NAN(*(float *)(*piVar1 + 0x1d8)) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(*piVar1 + 0x1d8) == 0.0) << 0xe) >> 8)) == 0x40)) {
      (**(code **)(piVar1[0xf2] + 0xb0))(piVar1,param_1,param_1,1,0);
    }
    if (piVar3 != (int *)0x0) {
      *(byte *)(*piVar3 + 0x180) = *(byte *)(*piVar3 + 0x180) | 1;
    }
  }
  return;
}


// UpdateAutoTargets__16CFuncTrackChangei  @ 000d5120
void UpdateAutoTargets__16CFuncTrackChangei(int param_1,int param_2)

{
  byte *pbVar1;
  
  if ((*(int *)(param_1 + 0x48c) != 0) && (*(int *)(param_1 + 0x490) != 0)) {
    if (param_2 == 0) {
      pbVar1 = (byte *)(**(int **)(param_1 + 0x48c) + 0x180);
      *pbVar1 = *pbVar1 & 0xfe;
    }
    else {
      pbVar1 = (byte *)(**(int **)(param_1 + 0x48c) + 0x180);
      *pbVar1 = *pbVar1 | 1;
    }
    if (param_2 == 1) {
      pbVar1 = (byte *)(**(int **)(param_1 + 0x490) + 0x180);
      *pbVar1 = *pbVar1 & 0xfe;
    }
    else {
      pbVar1 = (byte *)(**(int **)(param_1 + 0x490) + 0x180);
      *pbVar1 = *pbVar1 | 1;
    }
  }
  return;
}


