// LinkEntForLink__6CGraphP5CLinkP5CNode  @ 000c96a0
int * LinkEntForLink__6CGraphP5CLinkP5CNode(undefined4 param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined1 *puVar8;
  int aiStackY_78 [5];
  undefined1 local_48 [12];
  undefined1 local_3c [48];
  int local_c;
  
  piVar1 = *(int **)(param_2 + 8);
  if (piVar1 != (int *)0x0) {
    iVar4 = strcmp((char *)(*piVar1 + *(int *)(gpGlobals + 0x98)),"func_door");
    if ((iVar4 == 0) ||
       (iVar4 = strcmp((char *)(*piVar1 + *(int *)(gpGlobals + 0x98)),"func_door_rotating"),
       iVar4 == 0)) {
      puVar8 = &stack0xffffffa8;
      if ((*(byte *)((int)piVar1 + 0x181) & 1) != 0) {
        return piVar1;
      }
      iVar4 = 0;
LAB_000c9718:
      do {
        *(int *)(puVar8 + -4) = piVar1[0x6b] + *(int *)(gpGlobals + 0x98);
        *(char **)(puVar8 + -8) = "target";
        *(int *)(puVar8 + -0xc) = iVar4;
        *(undefined4 *)(puVar8 + -0x10) = 0xc9737;
        iVar4 = (*DAT_001754f8)();
        bVar3 = false;
        if (iVar4 == 0) {
LAB_000c9751:
          bVar3 = true;
        }
        else {
          *(int *)(puVar8 + -4) = iVar4;
          *(undefined4 *)(puVar8 + -8) = 0xc974a;
          iVar5 = (*DAT_001755d8)();
          if (iVar5 == 0) goto LAB_000c9751;
        }
        if (bVar3) {
          return piVar1;
        }
        if (iVar4 == 0) {
          piVar7 = (int *)0x0;
        }
        else {
          piVar7 = (int *)(iVar4 + 0xdc);
        }
        iVar5 = *piVar7;
        iVar2 = *(int *)(gpGlobals + 0x98);
        *(char **)(puVar8 + -4) = "func_button";
        *(int *)(puVar8 + -8) = iVar5 + iVar2;
        *(undefined4 *)(puVar8 + -0xc) = 0xc978f;
        iVar5 = strcmp(*(char **)(puVar8 + -8),*(char **)(puVar8 + -4));
        if (iVar5 != 0) {
          iVar5 = *piVar7;
          iVar2 = *(int *)(gpGlobals + 0x98);
          *(char **)(puVar8 + -4) = "func_rot_button";
          *(int *)(puVar8 + -8) = iVar5 + iVar2;
          *(undefined4 *)(puVar8 + -0xc) = 0xc97af;
          iVar5 = strcmp(*(char **)(puVar8 + -8),*(char **)(puVar8 + -4));
          if (iVar5 != 0) goto LAB_000c9718;
        }
        *(int **)(puVar8 + -4) = piVar7;
        *(undefined1 **)(puVar8 + -8) = local_48;
        *(undefined4 *)(puVar8 + -0xc) = 0xc97c4;
        VecBModelOrigin__FP9entvars_t();
        *(undefined1 **)(puVar8 + -0xc) = local_3c;
        *(undefined4 *)(puVar8 + -0x10) = g_pBodyQueueHead;
        *(undefined4 *)(puVar8 + -0x14) = 1;
        *(undefined1 **)(puVar8 + -0x18) = local_48;
        *(undefined4 *)(puVar8 + -0x1c) = param_3;
        *(undefined4 *)(puVar8 + -0x20) = 0xc97dd;
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult();
        puVar8 = puVar8 + -4;
        if (local_c == 0) {
          piVar6 = (int *)0x0;
        }
        else {
          piVar6 = (int *)(local_c + 0xdc);
        }
      } while (piVar6 != piVar7);
      if (local_c != 0) {
        return (int *)(local_c + 0xdc);
      }
    }
    else {
      (*DAT_001755b4)(2,"Unsupported PathEnt:\n\'%s\'\n",*piVar1 + *(int *)(gpGlobals + 0x98));
    }
  }
  return (int *)0x0;
}


