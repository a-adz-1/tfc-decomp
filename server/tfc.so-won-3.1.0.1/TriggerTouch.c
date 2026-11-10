// TriggerTouch__5CBeamP11CBaseEntity  @ 00096174
void TriggerTouch__5CBeamP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  
  if ((*(byte *)(*param_2 + 0x1a4) & 0x28) != 0) {
    if (*(int *)(*param_1 + 0x198) != 0) {
      iVar1 = *(int *)(*param_1 + 0x198);
      if ((iVar1 == 0) && (iVar1 = (*DAT_001a7f54)(0), iVar1 == 0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0x7c);
      }
      (**(code **)(*(int *)(iVar1 + 0x3d4) + 0xb0))(iVar1,param_2,param_1,3,0);
    }
    (*DAT_001a7f34)(1,"Firing targets!!!\n");
    return;
  }
  return;
}


