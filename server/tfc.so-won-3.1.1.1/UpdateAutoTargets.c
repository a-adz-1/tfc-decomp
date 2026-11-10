// UpdateAutoTargets__14CFuncTrackAutoi  @ 000d1944
void UpdateAutoTargets__14CFuncTrackAutoi(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if ((*(int *)(param_1 + 0x518) != 0) && (*(int *)(param_1 + 0x51c) != 0)) {
    if (*(int *)(param_1 + 0x534) == 0) {
      piVar1 = (int *)GetNext__10CPathTrack(*(int *)(param_1 + 0x518));
      uVar2 = *(undefined4 *)(param_1 + 0x51c);
    }
    else {
      piVar1 = (int *)GetNext__10CPathTrack(*(int *)(param_1 + 0x51c));
      uVar2 = *(undefined4 *)(param_1 + 0x518);
    }
    piVar3 = (int *)GetNext__10CPathTrack(uVar2);
    if ((((piVar1 != (int *)0x0) &&
         (*(byte *)(*piVar1 + 0x1a0) = *(byte *)(*piVar1 + 0x1a0) & 0xfe,
         *(int *)(param_1 + 0x530) == 2)) &&
        (piVar1 = *(int **)(param_1 + 0x520), piVar1 != (int *)0x0)) &&
       ((byte)((byte)((ushort)((ushort)NAN(*(float *)(*piVar1 + 0x1f8)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*(float *)(*piVar1 + 0x1f8) == 0.0) << 0xe) >> 8)) == 0x40))
    {
      (**(code **)(piVar1[0x115] + 0xb8))(piVar1,param_1,param_1,1,0);
    }
    if (piVar3 != (int *)0x0) {
      *(byte *)(*piVar3 + 0x1a0) = *(byte *)(*piVar3 + 0x1a0) | 1;
    }
  }
  return;
}


// UpdateAutoTargets__16CFuncTrackChangei  @ 000d1cf8
void UpdateAutoTargets__16CFuncTrackChangei(int param_1,int param_2)

{
  byte *pbVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x518);
  if ((piVar2 != (int *)0x0) && (*(int *)(param_1 + 0x51c) != 0)) {
    if (param_2 == 0) {
      *(byte *)(*piVar2 + 0x1a0) = *(byte *)(*piVar2 + 0x1a0) & 0xfe;
    }
    else {
      *(byte *)(*piVar2 + 0x1a0) = *(byte *)(*piVar2 + 0x1a0) | 1;
    }
    if (param_2 == 1) {
      pbVar1 = (byte *)(**(int **)(param_1 + 0x51c) + 0x1a0);
      *pbVar1 = *pbVar1 & 0xfe;
    }
    else {
      pbVar1 = (byte *)(**(int **)(param_1 + 0x51c) + 0x1a0);
      *pbVar1 = *pbVar1 | 1;
    }
  }
  return;
}


