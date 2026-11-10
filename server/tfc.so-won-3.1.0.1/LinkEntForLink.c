// LinkEntForLink__6CGraphP5CLinkP5CNode  @ 000b870c
int * LinkEntForLink__6CGraphP5CLinkP5CNode(undefined4 param_1,int param_2)

{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined1 *puVar6;
  int *piVar7;
  undefined4 auStackY_7c [5];
  int aiStack_4c [16];
  int aiStack_c [3];
  
  piVar2 = *(int **)(param_2 + 8);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    iVar3 = strcmp((char *)(*piVar2 + *(int *)(gpGlobals + 0x98)),"func_door");
    if ((iVar3 == 0) ||
       (iVar3 = strcmp((char *)(*piVar2 + *(int *)(gpGlobals + 0x98)),"func_door_rotating"),
       iVar3 == 0)) {
      puVar1 = &stack0xffffffa4;
      if ((*(byte *)((int)piVar2 + 0x1a1) & 1) == 0) {
LAB_000b87a4:
        do {
          puVar6 = puVar1;
          *(int *)(puVar6 + -4) = piVar2[0x73] + *(int *)(gpGlobals + 0x98);
          *(char **)(puVar6 + -8) = "target";
          *(undefined4 *)(puVar6 + -0xc) = *(undefined4 *)(puVar6 + 0x10);
          *(undefined4 *)(puVar6 + -0x10) = 0xb87d0;
          iVar3 = (*DAT_001a7e78)();
          *(undefined4 *)(puVar6 + 0x10) = 0;
          if (iVar3 == 0) {
LAB_000b87f7:
            *(undefined4 *)(puVar6 + 0x10) = 1;
          }
          else {
            *(int *)(puVar6 + -4) = iVar3;
            *(undefined4 *)(puVar6 + -8) = 0xb87f0;
            iVar4 = (*DAT_001a7f58)();
            if (iVar4 == 0) goto LAB_000b87f7;
          }
          if (*(int *)(puVar6 + 0x10) != 0) {
            return piVar2;
          }
          *(int *)(puVar6 + 0x10) = iVar3;
          piVar7 = (int *)(iVar3 + 0x80);
          if (*(int *)(puVar6 + 0x10) == 0) {
            piVar7 = (int *)0x0;
          }
          iVar3 = *piVar7;
          iVar4 = *(int *)(gpGlobals + 0x98);
          *(char **)(puVar6 + -4) = "func_button";
          *(int *)(puVar6 + -8) = iVar3 + iVar4;
          *(undefined4 *)(puVar6 + -0xc) = 0xb8837;
          iVar3 = strcmp(*(char **)(puVar6 + -8),*(char **)(puVar6 + -4));
          if (iVar3 != 0) {
            iVar3 = *piVar7;
            iVar4 = *(int *)(gpGlobals + 0x98);
            *(char **)(puVar6 + -4) = "func_rot_button";
            *(int *)(puVar6 + -8) = iVar3 + iVar4;
            *(undefined4 *)(puVar6 + -0xc) = 0xb885b;
            iVar3 = strcmp(*(char **)(puVar6 + -8),*(char **)(puVar6 + -4));
            puVar1 = puVar6;
            if (iVar3 != 0) goto LAB_000b87a4;
          }
          *(int **)(puVar6 + -4) = piVar7;
          *(undefined4 *)(puVar6 + -8) = *(undefined4 *)(puVar6 + 0x14);
          *(undefined4 *)(puVar6 + -0xc) = 0xb8871;
          VecBModelOrigin__FP9entvars_s();
          *(undefined1 **)(puVar6 + -0xc) = puVar6 + 0x20;
          *(undefined4 *)(puVar6 + -0x10) = g_pBodyQueueHead;
          *(undefined4 *)(puVar6 + -0x14) = 1;
          *(undefined4 *)(puVar6 + -0x18) = *(undefined4 *)(puVar6 + 0x10);
          *(undefined4 *)(puVar6 + -0x1c) = *(undefined4 *)(puVar6 + 100);
          *(undefined4 *)(puVar6 + -0x20) = 0xb8890;
          UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult();
          piVar5 = (int *)(*(int *)(puVar6 + 0x50) + 0x80);
          if (*(int *)(puVar6 + 0x50) == 0) {
            piVar5 = (int *)0x0;
          }
          puVar1 = puVar6 + -4;
        } while (piVar5 != piVar7);
        piVar2 = (int *)(*(int *)(puVar6 + 0x50) + 0x80);
        if (*(int *)(puVar6 + 0x50) == 0) {
          piVar2 = (int *)0x0;
        }
      }
    }
    else {
      (*DAT_001a7f34)(2,"Unsupported PathEnt:\n\'%s\'\n",*piVar2 + *(int *)(gpGlobals + 0x98));
      piVar2 = (int *)0x0;
    }
  }
  return piVar2;
}


