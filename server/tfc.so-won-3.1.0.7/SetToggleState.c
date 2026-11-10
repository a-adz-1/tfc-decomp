// SetToggleState__11CBaseEntityi  @ 0010f974
void SetToggleState__11CBaseEntityi(void)

{
  return;
}


// SetToggleState__8CRotDoori  @ 0009f304
void SetToggleState__8CRotDoori(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar2 = *param_1;
    *(int *)(iVar2 + 0x50) = param_1[0x129];
    *(int *)(iVar2 + 0x54) = param_1[0x12a];
    iVar1 = param_1[299];
  }
  else {
    iVar2 = *param_1;
    *(int *)(iVar2 + 0x50) = param_1[0x126];
    *(int *)(iVar2 + 0x54) = param_1[0x127];
    iVar1 = param_1[0x128];
  }
  *(int *)(iVar2 + 0x58) = iVar1;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  return;
}


// SetToggleState__9CBaseDoori  @ 0009dd04
void SetToggleState__9CBaseDoori(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (param_2 == 0) {
    puVar1 = param_1 + 0x123;
  }
  else {
    puVar1 = param_1 + 0x120;
  }
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,puVar1);
  return;
}


