// DamageDecal__10CBreakablei  @ 000a9778
int DamageDecal__10CBreakablei(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x460) == 0) {
    iVar1 = (*DAT_0019f808)(0,2);
    iVar1 = iVar1 + 0x19;
  }
  else if (*(int *)(param_1 + 0x460) == 7) {
    iVar1 = 0x23;
  }
  else {
    iVar1 = DamageDecal__11CBaseEntityi(param_1,param_2);
  }
  return iVar1;
}


// DamageDecal__11CBaseEntityi  @ 0008e9a0
undefined4 DamageDecal__11CBaseEntityi(int *param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(*param_1 + 0x148) == 4) {
    uVar1 = 0xffffffff;
  }
  else if (*(int *)(*param_1 + 0x148) == 0) {
    uVar1 = (*DAT_0019f808)(0,4);
  }
  else {
    uVar1 = 0x23;
  }
  return uVar1;
}


// DamageDecal__FP11CBaseEntityi  @ 001262f0
void DamageDecal__FP11CBaseEntityi(int param_1,undefined4 param_2)

{
  code *pcVar1;
  
  if (param_1 == 0) {
    param_2 = 4;
    param_1 = 0;
    pcVar1 = DAT_0019f808;
  }
  else {
    pcVar1 = *(code **)(*(int *)(param_1 + 0x454) + 0x74);
  }
  (*pcVar1)(param_1,param_2);
  return;
}


