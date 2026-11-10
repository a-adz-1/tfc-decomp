// RopeTouch__9CPendulumP11CBaseEntity  @ 000824ec
void RopeTouch__9CPendulumP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  if ((*(byte *)(iVar1 + 0x1a4) & 8) == 0) {
    (*DAT_001a7f34)(1,"Not a client\n");
  }
  else if (*(int *)(iVar1 + 0x208) != *(int *)(*param_1 + 400)) {
    *(undefined4 *)(*param_1 + 400) = *(undefined4 *)(*param_2 + 0x208);
    *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
    *(undefined4 *)(iVar1 + 0x24) = DAT_001a7e04;
    *(undefined4 *)(iVar1 + 0x28) = DAT_001a7e08;
    *(undefined4 *)(iVar1 + 0x108) = 0;
  }
  return;
}


