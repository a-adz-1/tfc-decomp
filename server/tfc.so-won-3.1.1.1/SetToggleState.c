// SetToggleState__11CBaseEntityi  @ 00112e5c
void SetToggleState__11CBaseEntityi(void)

{
  return;
}


// SetToggleState__8CRotDoori  @ 0009f004
void SetToggleState__8CRotDoori(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar2 = *param_1;
    *(int *)(iVar2 + 0x50) = param_1[0x12d];
    *(int *)(iVar2 + 0x54) = param_1[0x12e];
    iVar1 = param_1[0x12f];
  }
  else {
    iVar2 = *param_1;
    *(int *)(iVar2 + 0x50) = param_1[0x12a];
    *(int *)(iVar2 + 0x54) = param_1[299];
    iVar1 = param_1[300];
  }
  *(int *)(iVar2 + 0x58) = iVar1;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  return;
}


// SetToggleState__9CBaseDoori  @ 0009f23c
void SetToggleState__9CBaseDoori(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (param_2 == 0) {
    puVar1 = param_1 + 0x127;
  }
  else {
    puVar1 = param_1 + 0x124;
  }
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,puVar1);
  return;
}


