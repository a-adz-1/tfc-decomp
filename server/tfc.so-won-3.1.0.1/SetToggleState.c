// SetToggleState__11CBaseEntityi  @ 0010066c
void SetToggleState__11CBaseEntityi(void)

{
  return;
}


// SetToggleState__8CRotDoori  @ 00094e04
void SetToggleState__8CRotDoori(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar2 = *param_1;
    *(int *)(iVar2 + 0x50) = param_1[0x10d];
    *(int *)(iVar2 + 0x54) = param_1[0x10e];
    iVar1 = param_1[0x10f];
  }
  else {
    iVar2 = *param_1;
    *(int *)(iVar2 + 0x50) = param_1[0x10a];
    *(int *)(iVar2 + 0x54) = param_1[0x10b];
    iVar1 = param_1[0x10c];
  }
  *(int *)(iVar2 + 0x58) = iVar1;
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,*param_1 + 8);
  return;
}


// SetToggleState__9CBaseDoori  @ 00093804
void SetToggleState__9CBaseDoori(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (param_2 == 0) {
    puVar1 = param_1 + 0x107;
  }
  else {
    puVar1 = param_1 + 0x104;
  }
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,puVar1);
  return;
}


