// Voice_Deinit  @ 000934c4
void Voice_Deinit(void)

{
  return;
}


// Voice_GetClientListening  @ 000947c8
uint Voice_GetClientListening(int param_1,int param_2)

{
  uint uVar1;
  
  param_1 = param_1 + -1;
  param_2 = param_2 + -1;
  if ((((param_1 < 0) || (DAT_00524288 <= param_1)) || (param_2 < 0)) || (DAT_00524288 <= param_2))
  {
    uVar1 = 0;
  }
  else if (*(int *)((param_1 >> 5) * 4 + DAT_00524284 + 0x4ee4 + param_2 * 0x4eec) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1 << ((byte)param_1 & 0x1f) & 1;
  }
  return uVar1;
}


// Voice_Idle  @ 000934cc
void Voice_Idle(void)

{
  return;
}


// Voice_IsRecording  @ 000934b0
undefined4 Voice_IsRecording(void)

{
  return 0;
}


// Voice_RecordStart  @ 000934a4
undefined4 Voice_RecordStart(void)

{
  return 0;
}


// Voice_RecordStop  @ 000934d4
void Voice_RecordStop(void)

{
  return;
}


// Voice_RegisterCvars  @ 000934bc
void Voice_RegisterCvars(void)

{
  return;
}


// Voice_SetClientListening  @ 00094880
undefined4 Voice_SetClientListening(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  
  param_1 = param_1 + -1;
  param_2 = param_2 + -1;
  if ((((param_1 < 0) || (DAT_00524288 <= param_1)) || (param_2 < 0)) || (DAT_00524288 <= param_2))
  {
    uVar2 = 0;
  }
  else {
    puVar1 = (uint *)((param_1 >> 5) * 4 + 0x4ee4 + DAT_00524284 + param_2 * 0x4eec);
    if (param_3 == 0) {
      *puVar1 = *puVar1 & ~(1 << ((byte)param_1 & 0x1f));
    }
    else {
      *puVar1 = *puVar1 | 1 << ((byte)param_1 & 0x1f);
    }
    uVar2 = 1;
  }
  return uVar2;
}


