// StartObserver__11CBasePlayerG6VectorT1  @ 000d6558
void StartObserver__11CBasePlayerG6VectorT1(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  
  (*DAT_0019f758)(5,0x17,*param_1 + 8,0);
  (*DAT_0019f760)(0x7d);
  uVar2 = (*DAT_0019f7bc)(*(undefined4 *)(*param_1 + 0x208));
  (*DAT_0019f760)(uVar2);
  (*DAT_0019f75c)();
  iVar3 = param_1[0x237];
  if (iVar3 != 0) {
    (**(code **)(*(int *)(iVar3 + 0x454) + 0x128))(iVar3,0);
  }
  piVar4 = param_1 + 0x223;
  iVar3 = __opP11CBaseEntity__7EHANDLE(piVar4);
  if (iVar3 != 0) {
    iVar3 = __rf__7EHANDLE(piVar4);
    (**(code **)(*(int *)(iVar3 + 0x454) + 0xb8))(iVar3,param_1,param_1,0,0);
    __as__7EHANDLEP11CBaseEntity(piVar4,0);
  }
  param_1[0x22] = 0;
  param_1[0x10c] = 0;
  param_1[0x10b] = 0;
  param_1[0x10d] = 0;
  param_1[0x10e] = 0;
  if (((*(byte *)(param_1 + 0x21) & 0x10) == 0) ||
     (*(int *)(*param_1 + 0x208) != *(int *)(*param_1 + 400))) goto LAB_000d66c1;
  piVar4 = (int *)FindTimer__11CBaseEntityi(param_1,2);
  if (piVar4 == (int *)0x0) goto LAB_000d66c1;
  iVar3 = *(int *)(*piVar4 + 400);
  if (iVar3 == 0) {
    iVar3 = (*DAT_0019f7b4)(0);
    if (iVar3 != 0) goto LAB_000d66af;
    uVar5 = 0;
  }
  else {
LAB_000d66af:
    uVar5 = *(undefined4 *)(iVar3 + 0x7c);
  }
  TF_AddFrags__11CBasePlayeri(uVar5,1);
LAB_000d66c1:
  SetSuitUpdate__11CBasePlayerPcii(param_1,0,0,0);
  (*DAT_0019f758)(1,gmsgCurWeapon,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_0019f760)(0);
  (*DAT_0019f760)(0xff);
  (*DAT_0019f760)(0xff);
  (*DAT_0019f75c)();
  param_1[0x230] = 0;
  param_1[0x22f] = 0;
  *(undefined4 *)(*param_1 + 0x214) = 0;
  (*DAT_0019f758)(1,gmsgSetFOV,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_0019f760)(0);
  (*DAT_0019f75c)();
  param_1[0x22d] = 9;
  *(byte *)(param_1 + 0x1c3) = *(byte *)(param_1 + 0x1c3) | 0x20;
  *(undefined4 *)(*param_1 + 0x118) = 0x80;
  iVar3 = *param_1;
  *(undefined4 *)(iVar3 + 0x174) = g_vecZero;
  *(undefined4 *)(iVar3 + 0x178) = DAT_0019f664;
  *(undefined4 *)(iVar3 + 0x17c) = DAT_0019f668;
  iVar3 = *param_1;
  *(undefined4 *)(iVar3 + 0x74) = *param_3;
  *(undefined4 *)(iVar3 + 0x78) = param_3[1];
  *(undefined4 *)(iVar3 + 0x7c) = param_3[2];
  iVar1 = *param_1;
  *(undefined4 *)(iVar3 + 0x50) = *(undefined4 *)(iVar1 + 0x74);
  *(undefined4 *)(iVar3 + 0x54) = *(undefined4 *)(iVar1 + 0x78);
  *(undefined4 *)(iVar3 + 0x58) = *(undefined4 *)(iVar1 + 0x7c);
  *(undefined4 *)(*param_1 + 0xa0) = 1;
  *(undefined4 *)(*param_1 + 0x10c) = 0;
  *(undefined4 *)(*param_1 + 0x16c) = 0;
  *(undefined4 *)(*param_1 + 0x108) = 0;
  *(byte *)(param_1 + 0x1c3) = *(byte *)(param_1 + 0x1c3) & 0xf7;
  *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xbf;
  *(undefined4 *)(*param_1 + 0x170) = 3;
  *(undefined4 *)(*param_1 + 0x160) = 0x3f800000;
  param_1[0x21f] = 1;
  param_1[0x44] = 0;
  param_1[0x4c] = 0;
  TF_AddFrags__11CBasePlayeri(param_1,-param_1[0x4b]);
  iVar3 = param_1[0x48];
  param_1[0x48] = 0;
  *(undefined4 *)(*param_1 + 0x1ac) = 0;
  (*DAT_0019f758)(2,gmsgTeamInfo,0,0);
  uVar5 = (*DAT_0019f7bc)(*(undefined4 *)(*param_1 + 0x208));
  (*DAT_0019f760)(uVar5);
  (*DAT_0019f778)(&DAT_0014fc86);
  (*DAT_0019f75c)();
  TeamFortress_TeamIncreaseScore__Fii(iVar3,0);
  *(undefined4 *)(*param_1 + 0x20c) = 0;
  param_1[0x21] = param_1[0x21] & 0xfffffbf7;
  RemoveAllItems__11CBasePlayeri(param_1,0);
  CleanupOnPlayerDisconnection__11CBasePlayer(param_1);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,param_2);
  param_1[0x1a9] = 0;
  Observer_SetMode__11CBasePlayeri(param_1,param_1[0x1ab]);
  param_1[0x21] = 0;
  TeamFortress_SetSpeed__11CBasePlayer(param_1);
  (*DAT_0019f758)(2,gmsgSpectator,0,0);
  uVar5 = (*DAT_0019f7bc)(*(undefined4 *)(*param_1 + 0x208));
  (*DAT_0019f760)(uVar5);
  (*DAT_0019f760)(1);
  (*DAT_0019f75c)();
  return;
}


