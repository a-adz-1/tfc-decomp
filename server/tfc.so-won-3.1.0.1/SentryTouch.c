// SentryTouch__7CSentryP11CBaseEntity  @ 001095d0
void SentryTouch__7CSentryP11CBaseEntity(int param_1,int *param_2)

{
  int iVar1;
  
  if ((param_2 != (int *)0x0) && (iVar1 = *param_2, (*(byte *)(iVar1 + 0x1a4) & 0x28) != 0)) {
    (**(code **)(*(int *)(param_1 + 0x3d4) + 0x34))(param_1,iVar1,iVar1,0,0);
  }
  return;
}


