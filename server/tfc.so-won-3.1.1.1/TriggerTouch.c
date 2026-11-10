// TriggerTouch__5CBeamP11CBaseEntity  @ 000a5264
void TriggerTouch__5CBeamP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  
  if ((*(byte *)(*param_2 + 0x1a4) & 0x28) != 0) {
    if (*(int *)(*param_1 + 0x198) != 0) {
      iVar1 = *(int *)(*(int *)(*param_1 + 0x198) + 0x7c);
      (**(code **)(*(int *)(iVar1 + 0x454) + 0xb8))(iVar1,param_2,param_1,3,0);
    }
    (*DAT_0019f794)(1,"Firing targets!!!\n");
  }
  return;
}


