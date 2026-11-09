// SetTrack__15CFuncTrackTrainP10CPathTrack  @ 000d5f40
void SetTrack__15CFuncTrackTrainP10CPathTrack(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *param_1;
  local_10 = *(undefined4 *)(iVar1 + 8);
  local_c = *(undefined4 *)(iVar1 + 0xc);
  local_8 = *(undefined4 *)(iVar1 + 0x10);
  iVar1 = Nearest__10CPathTrackG6Vector(param_2,&local_10);
  param_1[0xf3] = iVar1;
  return;
}


