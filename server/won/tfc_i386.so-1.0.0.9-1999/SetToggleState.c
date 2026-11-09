// SetToggleState__11CBaseEntityi  @ 0010e410
void SetToggleState__11CBaseEntityi(void)

{
  return;
}


// SetToggleState__8CRotDoori  @ 000aaa90
void SetToggleState__8CRotDoori(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar2 = *param_1;
    *(int *)(iVar2 + 0x50) = param_1[0x10a];
    *(int *)(iVar2 + 0x54) = param_1[0x10b];
    iVar1 = param_1[0x10c];
  }
  else {
    iVar2 = *param_1;
    *(int *)(iVar2 + 0x50) = param_1[0x107];
    *(int *)(iVar2 + 0x54) = param_1[0x108];
    iVar1 = param_1[0x109];
  }
  *(int *)(iVar2 + 0x58) = iVar1;
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,*param_1 + 8);
  return;
}


// SetToggleState__9CBaseDoori  @ 000a96e0
void SetToggleState__9CBaseDoori(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (param_2 == 0) {
    puVar1 = param_1 + 0x104;
  }
  else {
    puVar1 = param_1 + 0x101;
  }
  UTIL_SetOrigin__FP9entvars_tRC6Vector(*param_1,puVar1);
  return;
}


