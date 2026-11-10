// SetCustomDecalFrames__11CBasePlayeri  @ 000df820
void SetCustomDecalFrames__11CBasePlayeri(int param_1,int param_2)

{
  if (param_2 - 1U < 7) {
    *(int *)(param_1 + 0x97c) = param_2;
  }
  else {
    *(undefined4 *)(param_1 + 0x97c) = 0xffffffff;
  }
  return;
}


