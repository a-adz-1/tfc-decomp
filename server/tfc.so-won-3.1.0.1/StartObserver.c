// StartObserver__11CBasePlayerG6VectorT1  @ 000cb480
void StartObserver__11CBasePlayerG6VectorT1(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  
  (*DAT_001a7ef8)(5,0x17,*param_1 + 8,0);
  (*DAT_001a7f00)(0x7d);
  uVar2 = (*DAT_001a7f5c)(*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001a7f00)(uVar2);
  (*DAT_001a7efc)();
  if (param_1[0x211] != 0) {
    (**(code **)(*(int *)(param_1[0x211] + 0x3d4) + 0x120))(param_1[0x211],0);
  }
  piVar4 = param_1 + 0x1fd;
  iVar3 = __opP11CBaseEntity__7EHANDLE(piVar4);
  if (iVar3 != 0) {
    iVar3 = __rf__7EHANDLE(piVar4);
    (**(code **)(*(int *)(iVar3 + 0x3d4) + 0xb0))(iVar3,param_1,param_1,0,0);
    __as__7EHANDLEP11CBaseEntity(piVar4,0);
  }
  param_1[0x22] = 0;
  param_1[0xec] = 0;
  param_1[0xeb] = 0;
  param_1[0xed] = 0;
  param_1[0xee] = 0;
  if (((*(byte *)(param_1 + 0x21) & 0x10) == 0) ||
     (*(int *)(*param_1 + 0x208) != *(int *)(*param_1 + 400))) goto LAB_000cb5f1;
  piVar4 = (int *)FindTimer__11CBaseEntityi(param_1,2);
  if (piVar4 == (int *)0x0) goto LAB_000cb5f1;
  iVar3 = *(int *)(*piVar4 + 400);
  if (iVar3 == 0) {
    iVar3 = (*DAT_001a7f54)(0);
    if (iVar3 != 0) goto LAB_000cb5df;
    uVar5 = 0;
  }
  else {
LAB_000cb5df:
    uVar5 = *(undefined4 *)(iVar3 + 0x7c);
  }
  TF_AddFrags__11CBasePlayeri(uVar5,1);
LAB_000cb5f1:
  SetSuitUpdate__11CBasePlayerPcii(param_1,0,0,0);
  (*DAT_001a7ef8)(1,gmsgCurWeapon,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001a7f00)(0);
  (*DAT_001a7f00)(0xff);
  (*DAT_001a7f00)(0xff);
  (*DAT_001a7efc)();
  param_1[0x20a] = 0;
  param_1[0x209] = 0;
  *(undefined4 *)(*param_1 + 0x214) = 0;
  (*DAT_001a7ef8)(1,gmsgSetFOV,0,*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001a7f00)(0);
  (*DAT_001a7efc)();
  param_1[0x207] = 9;
  *(byte *)(param_1 + 0x19e) = *(byte *)(param_1 + 0x19e) | 0x20;
  *(undefined4 *)(*param_1 + 0x118) = 0x80;
  iVar3 = *param_1;
  *(undefined4 *)(iVar3 + 0x174) = g_vecZero;
  *(undefined4 *)(iVar3 + 0x178) = DAT_001a7e04;
  *(undefined4 *)(iVar3 + 0x17c) = DAT_001a7e08;
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
  *(byte *)(param_1 + 0x19e) = *(byte *)(param_1 + 0x19e) & 0xf7;
  *(byte *)(*param_1 + 0x1a5) = *(byte *)(*param_1 + 0x1a5) & 0xbf;
  *(undefined4 *)(*param_1 + 0x170) = 3;
  *(undefined4 *)(*param_1 + 0x160) = 0x3f800000;
  param_1[0x44] = 0;
  param_1[0x4c] = 0;
  param_1[0x1f9] = 1;
  TF_AddFrags__11CBasePlayeri(param_1,-param_1[0x4b]);
  iVar3 = param_1[0x48];
  param_1[0x48] = 0;
  *(undefined4 *)(*param_1 + 0x1ac) = 0;
  (*DAT_001a7ef8)(2,gmsgTeamInfo,0,0);
  uVar5 = (*DAT_001a7f5c)(*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001a7f00)(uVar5);
  (*DAT_001a7f18)(&DAT_00139fe6);
  (*DAT_001a7efc)();
  TeamFortress_TeamIncreaseScore__Fii(iVar3,0);
  *(undefined4 *)(*param_1 + 0x20c) = 0;
  *(byte *)(param_1 + 0x21) = *(byte *)(param_1 + 0x21) & 0xf7;
  *(byte *)((int)param_1 + 0x85) = *(byte *)((int)param_1 + 0x85) & 0xfb;
  RemoveAllItems__11CBasePlayeri(param_1,0);
  CleanupOnPlayerDisconnection__11CBasePlayer(param_1);
  UTIL_SetOrigin__FP9entvars_sRC6Vector(*param_1,param_2);
  param_1[0x341] = 0;
  Observer_SetMode__11CBasePlayeri(param_1,1);
  param_1[0x21] = 0;
  TeamFortress_SetSpeed__11CBasePlayer(param_1);
  (*DAT_001a7ef8)(2,gmsgSpectator,0,0);
  uVar5 = (*DAT_001a7f5c)(*(undefined4 *)(*param_1 + 0x208));
  (*DAT_001a7f00)(uVar5);
  (*DAT_001a7f00)(1);
  (*DAT_001a7efc)();
  return;
}


