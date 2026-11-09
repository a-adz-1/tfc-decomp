// PlayerCustomization__FP7edict_sP15customization_s  @ 000a3a40
void PlayerCustomization__FP7edict_sP15customization_s(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xd8);
  }
  if (iVar2 == 0) {
    pcVar3 = FUN_0012d060;
  }
  else if (param_2 == 0) {
    pcVar3 = (code *)"PlayerCustomization:  NULL customization!\n";
  }
  else {
    iVar1 = *(int *)(param_2 + 0x44);
    if (-1 < iVar1) {
      if (iVar1 < 3) {
        return;
      }
      if (iVar1 == 3) {
        SetCustomDecalFrames__11CBasePlayeri(iVar2,*(undefined4 *)(param_2 + 0x74));
        return;
      }
    }
    pcVar3 = (code *)"PlayerCustomization:  Unknown customization type!\n";
  }
  (*DAT_001755b4)(1,pcVar3);
  return;
}


