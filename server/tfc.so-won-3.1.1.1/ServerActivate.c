// ServerActivate__FP7edict_sii  @ 00091838
void ServerActivate__FP7edict_sii(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  g_serveractive = 1;
  iVar3 = 0;
  if (0 < param_2) {
    do {
      iVar1 = iVar3 * 0x324;
      if (((*(int *)(param_1 + iVar1) == 0) && (param_3 <= iVar3)) &&
         (*(int *)(param_1 + 0x7c + iVar1) != 0)) {
        iVar1 = iVar1 + param_1;
        if (iVar1 == 0) {
          iVar1 = (*DAT_0019f7b4)(0);
          if (iVar1 != 0) goto LAB_000918af;
          piVar2 = (int *)0x0;
        }
        else {
LAB_000918af:
          piVar2 = *(int **)(iVar1 + 0x7c);
        }
        if ((piVar2 == (int *)0x0) || (*(int *)(*piVar2 + 0x1a4) < 0)) {
          (*DAT_0019f794)(1,"Can\'t instance %s\n",
                          *(int *)(param_1 + 0x80 + iVar3 * 0x324) + *(int *)(gpGlobals + 0x98));
        }
        else {
          (**(code **)(piVar2[0x115] + 0x24))(piVar2);
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_2);
  }
  ParseTFMapSettings__Fv();
  LinkUserMessages__Fv();
  (*DAT_0019f78c)("sv_maxspeed",0x43c80000);
  (*DAT_0019f73c)("sv_maxspeed 400\n");
  if (firstTime_696 != 0) {
    (*DAT_0019f8d0)("tf_ceasefire",Admin_CeaseFire__Fv);
    firstTime_696 = 0;
  }
  return;
}


