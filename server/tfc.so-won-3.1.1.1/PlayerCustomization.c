// PlayerCustomization__FP7edict_sP15customization_s  @ 00094760
void PlayerCustomization__FP7edict_sP15customization_s(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = 0;
  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 0x7c);
  }
  if (iVar2 == 0) {
    pcVar3 = "PlayerCustomization:  Couldn\'t get player!\n";
  }
  else if (param_2 == 0) {
    pcVar3 = "PlayerCustomization:  NULL customization!\n";
  }
  else {
    iVar1 = *(int *)(param_2 + 0x44);
    if (-1 < iVar1) {
      if (iVar1 < 3) {
        return;
      }
      if (iVar1 == 3) {
        SetCustomDecalFrames__11CBasePlayeri(iVar2,*(undefined4 *)(param_2 + 0x94));
        return;
      }
    }
    pcVar3 = "PlayerCustomization:  Unknown customization type!\n";
  }
  (*DAT_0019f794)(1,pcVar3);
  return;
}


