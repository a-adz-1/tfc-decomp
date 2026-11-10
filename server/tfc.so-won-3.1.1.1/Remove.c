// Remove__12CTFDispenser  @ 0009ae58
void Remove__12CTFDispenser(int *param_1)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  piVar1 = (int *)__rf__7EHANDLE(param_1 + 0x51);
  iVar2 = *(int *)(*piVar1 + 0x208);
  if (iVar2 == 0) {
    iVar2 = (*DAT_0019f7b4)(0);
    if (iVar2 == 0) {
      piVar1 = (int *)0x0;
      goto LAB_0009aea6;
    }
  }
  piVar1 = *(int **)(iVar2 + 0x7c);
LAB_0009aea6:
  if (piVar1[0x36b] == 0) {
    ClientPrint__FP9entvars_siPCcN42(*piVar1,4,"#Dispenser_destroyed",0,0,0,0);
  }
  if (piVar1[0x48] == 0) {
    pcVar3 = "SPECTATOR";
  }
  else {
    pcVar3 = (char *)GetTeamName__Fi(piVar1[0x48]);
  }
  uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar1 + 0x208),pcVar3);
  uVar4 = (*DAT_0019f864)(*(undefined4 *)(*piVar1 + 0x208),uVar4);
  UTIL_LogPrintf__FPce
            ("\"<-1><><>\" triggered \"Dispenser_destroyed\" against \"%s<%i><%s><%s>\"\n",
             *(int *)(*piVar1 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar4);
  piVar1[0x36b] = 0;
  piVar1[0x53] = 0;
  (*DAT_0019f758)(5,0x17,*param_1 + 8,0);
  (*DAT_0019f760)(3);
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 8));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_0019f768)((int)g_sModelIndexFireball);
  (*DAT_0019f760)(0x1e);
  (*DAT_0019f760)(0xf);
  (*DAT_0019f760)(3);
  (*DAT_0019f75c)();
  dremove__FP11CBaseEntity(param_1);
  return;
}


// Remove__12CTFSentrygun  @ 000ec384
void Remove__12CTFSentrygun(int *param_1)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int local_c;
  int *local_8;
  
  piVar1 = (int *)__rf__7EHANDLE(param_1 + 0x51);
  iVar2 = *(int *)(*piVar1 + 0x208);
  if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
    local_8 = (int *)0x0;
  }
  else {
    local_8 = *(int **)(iVar2 + 0x7c);
  }
  if (local_8[0x36a] == 0) {
    ClientPrint__FP9entvars_siPCcN42(*local_8,4,"#Sentry_destroyed",0,0,0,0);
  }
  if (local_8[0x48] == 0) {
    pcVar3 = "SPECTATOR";
  }
  else {
    pcVar3 = (char *)GetTeamName__Fi(local_8[0x48]);
  }
  uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*local_8 + 0x208),pcVar3);
  uVar4 = (*DAT_0019f864)(*(undefined4 *)(*local_8 + 0x208),uVar4);
  UTIL_LogPrintf__FPce
            ("\"<-1><><>\" triggered \"Sentry_destroyed\" against \"%s<%i><%s><%s>\"\n",
             *(int *)(*local_8 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar4);
  local_c = 1;
  local_8[0x54] = 0;
  local_8[0x36a] = 0;
  for (; local_c <= *(int *)(gpGlobals + 0x90); local_c = local_c + 1) {
    iVar2 = UTIL_PlayerByIndex__Fi(local_c);
    if (iVar2 != 0) {
      piVar1 = (int *)__opP11CBaseEntity__7EHANDLE(iVar2 + 0x138);
      if (piVar1 == param_1) {
        ResetMenu__11CBasePlayer(iVar2);
        __as__7EHANDLEP11CBaseEntity(iVar2 + 0x138,0);
      }
    }
  }
  (*DAT_0019f758)(5,0x17,*param_1 + 8,0);
  (*DAT_0019f760)(3);
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 8));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_0019f768)((int)g_sModelIndexFireball);
  (*DAT_0019f760)(0x1e);
  (*DAT_0019f760)(0xf);
  (*DAT_0019f760)(3);
  (*DAT_0019f75c)();
  dremove__FP11CBaseEntity(param_1);
  iVar2 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(0,"building_sentrygun_base");
  while( true ) {
    if (iVar2 == 0) {
      return;
    }
    piVar1 = (int *)__opP11CBaseEntity__7EHANDLE(iVar2 + 0x144);
    if (piVar1 == local_8) break;
    iVar2 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar2,"building_sentrygun_base");
  }
  dremove__FP11CBaseEntity(iVar2);
  return;
}


// Remove__14CQueuePriorityRf  @ 000cb2f4
int Remove__14CQueuePriorityRf(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[1];
  *param_2 = param_1[2];
  *param_1 = *param_1 + -1;
  iVar2 = param_1[*param_1 * 2 + 2];
  param_1[1] = param_1[*param_1 * 2 + 1];
  param_1[2] = iVar2;
  Heap_SiftDown__14CQueuePriorityi(param_1,0);
  return iVar1;
}


// Remove__16CTFSentrygunBase  @ 000eb9ec
void Remove__16CTFSentrygunBase(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int local_c;
  
  piVar1 = (int *)__rf__7EHANDLE(param_1 + 0x51);
  iVar2 = *(int *)(*piVar1 + 0x208);
  if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(iVar2 + 0x7c);
  }
  iVar2 = 0;
  do {
    iVar2 = UTIL_FindEntityByClassname__FP11CBaseEntityPCc(iVar2,FUN_00151e74);
    if (iVar2 == 0) goto LAB_000ebba2;
    piVar3 = (int *)__opP11CBaseEntity__7EHANDLE(iVar2 + 0x144);
  } while (piVar3 != piVar1);
  if (piVar1[0x36a] == 0) {
    ClientPrint__FP9entvars_siPCcN42(*piVar1,4,"#Sentry_destroyed",0,0,0,0);
  }
  if (piVar1[0x48] == 0) {
    pcVar4 = "SPECTATOR";
  }
  else {
    pcVar4 = (char *)GetTeamName__Fi(piVar1[0x48]);
  }
  uVar5 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar1 + 0x208),pcVar4);
  uVar5 = (*DAT_0019f864)(*(undefined4 *)(*piVar1 + 0x208),uVar5);
  UTIL_LogPrintf__FPce
            ("\"<-1><><>\" triggered \"Sentry_destroyed\" against \"%s<%i><%s><%s>\"\n",
             *(int *)(*piVar1 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar5);
  piVar1[0x54] = 0;
  piVar1[0x36a] = 0;
  for (local_c = 1; local_c <= *(int *)(gpGlobals + 0x90); local_c = local_c + 1) {
    iVar6 = UTIL_PlayerByIndex__Fi(local_c);
    if (iVar6 != 0) {
      iVar7 = __opP11CBaseEntity__7EHANDLE(iVar6 + 0x138);
      if (iVar7 == iVar2) {
        ResetMenu__11CBasePlayer(iVar6);
        __as__7EHANDLEP11CBaseEntity(iVar6 + 0x138,0);
      }
    }
  }
  dremove__FP11CBaseEntity(iVar2);
LAB_000ebba2:
  (*DAT_0019f758)(5,0x17,*param_1 + 8,0);
  (*DAT_0019f760)(3);
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 8));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_0019f768)((int)g_sModelIndexFireball);
  (*DAT_0019f760)(0x1e);
  (*DAT_0019f760)(0xf);
  (*DAT_0019f760)(3);
  (*DAT_0019f75c)();
  dremove__FP11CBaseEntity(param_1);
  return;
}


// Remove__6CQueueRf  @ 000cb3a0
int Remove__6CQueueRf(int *param_1,int *param_2)

{
  int iVar1;
  
  if (param_1[0xc9] == 100) {
    param_1[0xc9] = 0;
  }
  *param_1 = *param_1 + -1;
  *param_2 = param_1[param_1[0xc9] * 2 + 2];
  iVar1 = param_1[param_1[0xc9] * 2 + 1];
  param_1[0xc9] = param_1[0xc9] + 1;
  return iVar1;
}


// Remove__8CDetpack  @ 00099f78
void Remove__8CDetpack(int *param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  int *piVar4;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_0019f7b4)(0);
    if (iVar1 == 0) {
      piVar4 = (int *)0x0;
      goto LAB_00099fba;
    }
  }
  piVar4 = *(int **)(iVar1 + 0x7c);
LAB_00099fba:
  piVar4[0x31] = piVar4[0x31] + 1;
  ClientPrint__FP9entvars_siPCcN42(*piVar4,4,"#Detpack_blocking_door_destroyed",0,0,0,0);
  if (piVar4[0x48] == 0) {
    pcVar2 = "SPECTATOR";
  }
  else {
    pcVar2 = (char *)GetTeamName__Fi(piVar4[0x48]);
  }
  uVar3 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar4 + 0x208),pcVar2);
  uVar3 = (*DAT_0019f864)(*(undefined4 *)(*piVar4 + 0x208),uVar3);
  UTIL_LogPrintf__FPce
            ("\"<-1><><>\" triggered \"Detpack_blocking_door_destroyed\" against \"%s<%i><%s><%s>\"\n"
             ,*(int *)(*piVar4 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar3);
  if (param_1[0x1b0] != 0) {
    dremove__FP11CBaseEntity(param_1[0x1b0]);
  }
  (*DAT_0019f758)(5,0x17,*param_1 + 8,0);
  (*DAT_0019f760)(3);
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 8));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0xc));
  (*DAT_0019f774)(*(undefined4 *)(*param_1 + 0x10));
  (*DAT_0019f768)((int)g_sModelIndexSmoke);
  (*DAT_0019f760)(0x1e);
  (*DAT_0019f760)(0xf);
  (*DAT_0019f760)(3);
  (*DAT_0019f75c)();
  dremove__FP11CBaseEntity(param_1);
  return;
}


