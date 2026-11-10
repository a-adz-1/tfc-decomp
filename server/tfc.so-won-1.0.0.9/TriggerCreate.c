// TriggerCreate__15CXenTreeTriggerP7edict_sRC6Vector  @ 0011e7f0
int * TriggerCreate__15CXenTreeTriggerP7edict_sRC6Vector(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)GetClassPtr__H1Z15CXenTreeTrigger_PX01_PX01(0);
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 8) = *param_2;
  *(undefined4 *)(iVar1 + 0xc) = param_2[1];
  *(undefined4 *)(iVar1 + 0x10) = param_2[2];
  *(char **)*piVar2 = "?xen_ttrigger" + (1 - *(int *)(gpGlobals + 0x98));
  *(undefined4 *)(*piVar2 + 0xec) = 1;
  *(undefined4 *)(*piVar2 + 0xe8) = 0;
  *(undefined4 *)(*piVar2 + 0x178) = param_1;
  return piVar2;
}


