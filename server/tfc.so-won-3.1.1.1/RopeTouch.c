// RopeTouch__9CPendulumP11CBaseEntity  @ 00089474
void RopeTouch__9CPendulumP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  if ((*(byte *)(iVar1 + 0x1a4) & 8) == 0) {
    (*DAT_0019f794)(1,"Not a client\n");
  }
  else if (*(int *)(iVar1 + 0x208) != *(int *)(*param_1 + 400)) {
    *(int *)(*param_1 + 400) = *(int *)(iVar1 + 0x208);
    *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
    *(undefined4 *)(iVar1 + 0x24) = DAT_0019f664;
    *(undefined4 *)(iVar1 + 0x28) = DAT_0019f668;
    *(undefined4 *)(iVar1 + 0x108) = 0;
  }
  return;
}


