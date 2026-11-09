// RopeTouch__9CPendulumP11CBaseEntity  @ 0009d2b0
void RopeTouch__9CPendulumP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  if ((*(byte *)(iVar1 + 0x184) & 8) == 0) {
    (*DAT_001755b4)(1,"Not a client\n");
  }
  else if (*(int *)(iVar1 + 0x1e8) != *(int *)(*param_1 + 0x170)) {
    *(undefined4 *)(*param_1 + 0x170) = *(undefined4 *)(*param_2 + 0x1e8);
    *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
    *(undefined4 *)(iVar1 + 0x24) = DAT_00175484;
    *(undefined4 *)(iVar1 + 0x28) = DAT_00175488;
    *(undefined4 *)(iVar1 + 0xe8) = 0;
  }
  return;
}


