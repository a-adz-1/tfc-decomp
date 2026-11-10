// TriggerTouch__5CBeamP11CBaseEntity  @ 000abc30
void TriggerTouch__5CBeamP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  
  if ((*(byte *)(*param_2 + 0x184) & 0x28) != 0) {
    if (*(int *)(*param_1 + 0x178) != 0) {
      iVar1 = *(int *)(*param_1 + 0x178);
      if ((iVar1 == 0) && (iVar1 = (*DAT_001755d4)(0), iVar1 == 0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0xd8);
      }
      (**(code **)(*(int *)(iVar1 + 0x3c8) + 0xb0))(iVar1,param_2,param_1,3,0);
    }
    (*DAT_001755b4)(1,"Firing targets!!!\n");
    return;
  }
  return;
}


