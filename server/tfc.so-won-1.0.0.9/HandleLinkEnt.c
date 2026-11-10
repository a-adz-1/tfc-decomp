// HandleLinkEnt__6CGraphiP9entvars_tiQ26CGraph9NODEQUERY  @ 000c9840
undefined4
HandleLinkEnt__6CGraphiP9entvars_tiQ26CGraph9NODEQUERY
          (int *param_1,undefined4 param_2,int *param_3,uint param_4,int param_5)

{
  bool bVar1;
  int iVar2;
  
  if ((*param_1 == 0) || (param_1[1] == 0)) {
    (*DAT_001755b4)(2,"Graph not ready!\n");
    return 0;
  }
  bVar1 = false;
  if ((param_3 == (int *)0x0) || (iVar2 = (*DAT_001755d8)(param_3[0x7a]), iVar2 == 0)) {
    bVar1 = true;
  }
  if (bVar1) {
    (*DAT_001755b4)(2,"dead path ent!\n");
  }
  else {
    iVar2 = strcmp((char *)(*param_3 + *(int *)(gpGlobals + 0x98)),"func_door");
    if ((iVar2 == 0) ||
       (iVar2 = strcmp((char *)(*param_3 + *(int *)(gpGlobals + 0x98)),"func_door_rotating"),
       iVar2 == 0)) {
      iVar2 = param_3[0x7a];
      if ((iVar2 == 0) && (iVar2 = (*DAT_001755d4)(0), iVar2 == 0)) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(iVar2 + 0xd8);
      }
      if ((*(byte *)((int)param_3 + 0x181) & 1) == 0) {
        iVar2 = (**(code **)(*(int *)(iVar2 + 0x3c8) + 0x54))(iVar2);
        if ((iVar2 != 0) || ((*(byte *)(param_3 + 0x60) & 0x20) == 0)) {
          if ((param_4 & 0x200) == 0) {
            return 0;
          }
          if (((*(byte *)((int)param_3 + 0x181) & 2) != 0) && (param_5 != 1)) {
            return 0;
          }
        }
      }
      else if (((param_4 & 0x200) == 0) &&
              ((iVar2 = (**(code **)(*(int *)(iVar2 + 0x3c8) + 0x54))(iVar2), iVar2 != 0 ||
               ((*(byte *)(param_3 + 0x60) & 0x20) == 0)))) {
        return 0;
      }
    }
    else {
      iVar2 = strcmp((char *)(*param_3 + *(int *)(gpGlobals + 0x98)),"func_breakable");
      if ((iVar2 != 0) || (param_5 != 1)) {
        (*DAT_001755b4)(2,"Unhandled Ent in Path %s\n",*param_3 + *(int *)(gpGlobals + 0x98));
        return 0;
      }
    }
  }
  return 1;
}


