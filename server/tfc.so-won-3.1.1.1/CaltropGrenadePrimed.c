// CaltropGrenadePrimed__17CTFCaltropGrenade  @ 000ffb98
void CaltropGrenadePrimed__17CTFCaltropGrenade(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if ((iVar1 == 0) && (iVar1 = (*DAT_0019f7b4)(0), iVar1 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(iVar1 + 0x7c);
  }
  if (*(int *)(iVar1 + 0x80) == 0) {
    if (((*(byte *)(iVar1 + 0x85) & 4) == 0) &&
       (*(float *)(*param_1 + 0x104) = *gpGlobals + 0.1, *gpGlobals <= (float)param_1[0x1ae])) {
      return;
    }
    *(uint *)(iVar1 + 0x84) = *(uint *)(iVar1 + 0x84) & 0xfffffbfe;
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x20) = g_vecZero;
    *(undefined4 *)(iVar1 + 0x24) = DAT_0019f664;
    *(undefined4 *)(iVar1 + 0x28) = DAT_0019f668;
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x5c) = g_vecZero;
    *(undefined4 *)(iVar1 + 0x60) = DAT_0019f664;
    *(undefined4 *)(iVar1 + 100) = DAT_0019f668;
    (**(code **)(param_1[0x115] + 0x23c))(param_1);
    *(int *)(*param_1 + 0x1e4) = param_1[0x1ae];
    param_1[3] = -0x10000;
    param_1[4] = (int)Detonate__8CGrenade;
    *(float *)(*param_1 + 0x104) = *gpGlobals;
    uVar2 = (*DAT_0019f808)(3,6);
    *(undefined4 *)(*param_1 + 0x128) = uVar2;
    *(undefined4 *)(*param_1 + 0x138) = 0x3f800000;
    *(undefined4 *)(*param_1 + 0x11c) = 0x3f000000;
    *(undefined4 *)(*param_1 + 0x120) = 0x3f4ccccd;
    (**(code **)(param_1[0x115] + 0x228))(param_1);
  }
  else {
    *(undefined4 *)(iVar1 + 0x80) = 0;
    *(uint *)(iVar1 + 0x84) = *(uint *)(iVar1 + 0x84) & 0xfffffbfe;
    dremove__FP11CBaseEntity(param_1);
  }
  return;
}


