// LinkEntForLink__6CGraphP5CLinkP5CNode  @ 000c414c
int * LinkEntForLink__6CGraphP5CLinkP5CNode(undefined4 param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  undefined1 *puVar6;
  int *piVar7;
  int aiStackY_80 [5];
  int iStack_54;
  undefined1 auStack_48 [12];
  undefined1 auStack_3c [48];
  int iStack_c;
  
  puVar6 = &stack0xffffffa0;
  piVar1 = *(int **)(param_2 + 8);
  if (piVar1 != (int *)0x0) {
    iStack_54 = 0;
    iVar4 = strcmp((char *)(*piVar1 + *(int *)(gpGlobals + 0x98)),"func_door");
    if ((iVar4 != 0) &&
       (iVar4 = strcmp((char *)(*piVar1 + *(int *)(gpGlobals + 0x98)),"func_door_rotating"),
       iVar4 != 0)) {
      (*DAT_0019f794)(2,"Unsupported PathEnt:\n\'%s\'\n",*piVar1 + *(int *)(gpGlobals + 0x98));
      return (int *)0x0;
    }
    if ((*(byte *)((int)piVar1 + 0x1a1) & 1) != 0) {
      return piVar1;
    }
LAB_000c41e4:
    do {
      *(int *)(puVar6 + -4) = piVar1[0x73] + *(int *)(gpGlobals + 0x98);
      *(char **)(puVar6 + -8) = "target";
      *(int *)(puVar6 + -0xc) = iStack_54;
      *(undefined4 *)(puVar6 + -0x10) = 0xc4212;
      iStack_54 = (*DAT_0019f6d8)();
      bVar3 = false;
      if (iStack_54 == 0) {
LAB_000c4238:
        bVar3 = true;
      }
      else {
        *(int *)(puVar6 + -4) = iStack_54;
        *(undefined4 *)(puVar6 + -8) = 0xc4231;
        iVar4 = (*DAT_0019f7b8)();
        if (iVar4 == 0) goto LAB_000c4238;
      }
      if (bVar3) {
        return piVar1;
      }
      piVar7 = (int *)(iStack_54 + 0x80);
      if (iStack_54 == 0) {
        piVar7 = (int *)0x0;
      }
      iVar4 = *piVar7;
      iVar2 = *(int *)(gpGlobals + 0x98);
      *(char **)(puVar6 + -4) = "func_button";
      *(int *)(puVar6 + -8) = iVar4 + iVar2;
      *(undefined4 *)(puVar6 + -0xc) = 0xc4274;
      iVar4 = strcmp(*(char **)(puVar6 + -8),*(char **)(puVar6 + -4));
      if (iVar4 != 0) {
        iVar4 = *piVar7;
        iVar2 = *(int *)(gpGlobals + 0x98);
        *(char **)(puVar6 + -4) = "func_rot_button";
        *(int *)(puVar6 + -8) = iVar4 + iVar2;
        *(undefined4 *)(puVar6 + -0xc) = 0xc4298;
        iVar4 = strcmp(*(char **)(puVar6 + -8),*(char **)(puVar6 + -4));
        if (iVar4 != 0) goto LAB_000c41e4;
      }
      *(int **)(puVar6 + -4) = piVar7;
      *(undefined1 **)(puVar6 + -8) = auStack_48;
      *(undefined4 *)(puVar6 + -0xc) = 0xc42ad;
      VecBModelOrigin__FP9entvars_s();
      *(undefined1 **)(puVar6 + -0xc) = auStack_3c;
      *(undefined4 *)(puVar6 + -0x10) = g_pBodyQueueHead;
      *(undefined4 *)(puVar6 + -0x14) = 1;
      *(undefined1 **)(puVar6 + -0x18) = auStack_48;
      *(undefined4 *)(puVar6 + -0x1c) = param_3;
      *(undefined4 *)(puVar6 + -0x20) = 0xc42c6;
      UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult();
      puVar6 = puVar6 + -4;
      piVar5 = (int *)(iStack_c + 0x80);
      if (iStack_c == 0) {
        piVar5 = (int *)0x0;
      }
    } while (piVar5 != piVar7);
    if (iStack_c != 0) {
      return (int *)(iStack_c + 0x80);
    }
  }
  return (int *)0x0;
}


