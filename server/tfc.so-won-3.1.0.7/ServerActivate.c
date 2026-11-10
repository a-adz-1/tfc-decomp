// ServerActivate__FP7edict_sii  @ 00091ee0
void ServerActivate__FP7edict_sii(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *local_4;
  
  g_serveractive = 1;
  if (0 < param_2) {
    local_4 = (int *)(param_1 + 0x80);
    iVar5 = 0;
    piVar3 = (int *)(param_1 + 0x7c);
    iVar4 = 0;
    do {
      if (((*(int *)(param_1 + iVar5) == 0) && (param_3 <= iVar4)) && (*piVar3 != 0)) {
        iVar1 = param_1 + iVar5;
        if (iVar1 == 0) {
          iVar1 = (*DAT_001c1134)(0);
          if (iVar1 != 0) goto LAB_00091f58;
          piVar2 = (int *)0x0;
        }
        else {
LAB_00091f58:
          piVar2 = *(int **)(iVar1 + 0x7c);
        }
        if ((piVar2 == (int *)0x0) || (*(int *)(*piVar2 + 0x1a4) < 0)) {
          (*DAT_001c1114)(1,"Can\'t instance %s\n",*local_4 + *(int *)(gpGlobals + 0x98));
        }
        else {
          (**(code **)(piVar2[0x111] + 0x24))(piVar2);
        }
      }
      local_4 = local_4 + 0xc9;
      iVar5 = iVar5 + 0x324;
      piVar3 = piVar3 + 0xc9;
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_2);
  }
  ParseTFMapSettings__Fv();
  LinkUserMessages__Fv();
  (*DAT_001c110c)("sv_maxspeed",0x43c80000);
  (*DAT_001c10bc)("sv_maxspeed 400\n");
  (*DAT_001c1250)("tf_ceasefire",Admin_CeaseFire__Fv);
  return;
}


