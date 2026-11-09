// DamageDecal__10CBreakablei  @ 000b3450
int DamageDecal__10CBreakablei(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x3d4) == 0) {
    iVar1 = (*DAT_00175628)(0,2);
    iVar1 = iVar1 + 0x19;
  }
  else if (*(int *)(param_1 + 0x3d4) == 7) {
    iVar1 = 0x23;
  }
  else {
    iVar1 = DamageDecal__11CBaseEntityi(param_1,param_2);
  }
  return iVar1;
}


// DamageDecal__11CBaseEntityi  @ 000a1a30
undefined4 DamageDecal__11CBaseEntityi(int *param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(*param_1 + 0x128) == 4) {
    uVar1 = 0xffffffff;
  }
  else if (*(int *)(*param_1 + 0x128) == 0) {
    uVar1 = (*DAT_00175628)(0,4);
  }
  else {
    uVar1 = 0x23;
  }
  return uVar1;
}


// DamageDecal__FP11CBaseEntityi  @ 0011a3a0
void DamageDecal__FP11CBaseEntityi(int param_1,undefined4 param_2)

{
  code *pcVar1;
  
  if (param_1 == 0) {
    param_2 = 4;
    param_1 = 0;
    pcVar1 = DAT_00175628;
  }
  else {
    pcVar1 = *(code **)(*(int *)(param_1 + 0x3c8) + 0x70);
  }
  (*pcVar1)(param_1,param_2);
  return;
}


