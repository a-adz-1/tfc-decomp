// DispatchRestore__FP7edict_sP13saverestore_si  @ 0008da00
undefined4 DispatchRestore__FP7edict_sP13saverestore_si(int param_1,int *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  int *piVar6;
  undefined1 local_2cc [4];
  undefined4 local_2c8;
  undefined4 local_2c4;
  undefined1 local_2c0 [4];
  undefined4 local_2bc;
  undefined4 local_2b8;
  int local_2b4;
  int local_2b0;
  int local_2ac;
  undefined4 local_2a8;
  undefined4 local_2a4;
  float local_1cc;
  float local_1c8;
  float local_1c4;
  
  piVar6 = (int *)0x0;
  if (param_1 != 0) {
    piVar6 = *(int **)(param_1 + 0x7c);
  }
  if ((piVar6 != (int *)0x0) && (param_2 != (int *)0x0)) {
    __9entvars_s(&local_2a8);
    __18CSaveRestoreBufferP13saverestore_s(local_2c0,param_2);
    local_2bc = 0;
    local_2b8 = 1;
    if (param_3 != 0) {
      __18CSaveRestoreBufferP13saverestore_s(local_2cc,param_2);
      local_2c8 = 0;
      local_2c4 = 0;
      ReadEntVars__8CRestorePCcP9entvars_s(local_2cc,"ENTVARS",&local_2a8);
      iVar3 = *(int *)(param_2[10] + 8 + param_2[7] * 0x18);
      param_2[2] = iVar3;
      param_2[1] = iVar3 + *param_2;
      iVar3 = EntityFromTable__12CGlobalStatei(&gGlobalState,local_2a4);
      iVar3 = strcmp((char *)(param_2 + 0x155),(char *)(iVar3 + 0x40));
      if (iVar3 != 0) {
        ___18CSaveRestoreBuffer(local_2cc,2);
        ___18CSaveRestoreBuffer(local_2c0,2);
        return 0;
      }
      local_2b4 = param_2[0x151];
      local_2b0 = param_2[0x152];
      local_2ac = param_2[0x153];
      piVar6 = (int *)FindGlobalEntity__Fii(local_2a8,local_2a4);
      if (piVar6 == (int *)0x0) {
        ___18CSaveRestoreBuffer(local_2cc,2);
        ___18CSaveRestoreBuffer(local_2c0,2);
        return 0;
      }
      local_2bc = 1;
      iVar3 = *piVar6;
      fVar1 = *(float *)(iVar3 + 0xe0);
      fVar2 = *(float *)(iVar3 + 0xe4);
      param_2[0x151] = (int)(((float)param_2[0x151] - *(float *)(iVar3 + 0xdc)) + local_1cc);
      param_2[0x152] = (int)(((float)param_2[0x152] - fVar1) + local_1c8);
      param_2[0x153] = (int)(((float)param_2[0x153] - fVar2) + local_1c4);
      param_1 = *(int *)(*piVar6 + 0x208);
      EntityUpdate__12CGlobalStateii
                (&gGlobalState,*(undefined4 *)(*piVar6 + 4),*(undefined4 *)(gpGlobals + 0xc));
      ___18CSaveRestoreBuffer(local_2cc,2);
    }
    uVar4 = (**(code **)(piVar6[0x115] + 0x20))(piVar6);
    if ((uVar4 & 4) == 0) {
      (**(code **)(piVar6[0x115] + 0x1c))(piVar6,local_2c0);
      pcVar5 = *(code **)(piVar6[0x115] + 0x10);
    }
    else {
      (**(code **)(piVar6[0x115] + 0x1c))(piVar6,local_2c0);
      pcVar5 = *(code **)(piVar6[0x115] + 0xc);
    }
    (*pcVar5)(piVar6);
    piVar6 = (int *)0x0;
    if (param_1 != 0) {
      piVar6 = *(int **)(param_1 + 0x7c);
    }
    if (param_3 == 0) {
      if ((piVar6 != (int *)0x0) && (*(int *)(*piVar6 + 4) != 0)) {
        iVar3 = EntityFromTable__12CGlobalStatei(&gGlobalState,*(int *)(*piVar6 + 4));
        if (iVar3 == 0) {
          (*DAT_0019f794)(4,"Global Entity %s (%s) not in table!!!\n",
                          *(int *)(*piVar6 + 4) + *(int *)(gpGlobals + 0x98),
                          *(int *)*piVar6 + *(int *)(gpGlobals + 0x98));
          EntityAdd__12CGlobalStateii12GLOBALESTATE
                    (&gGlobalState,*(undefined4 *)(*piVar6 + 4),*(undefined4 *)(gpGlobals + 0xc),1);
        }
        else {
          if (*(int *)(iVar3 + 0x60) == 2) {
            ___18CSaveRestoreBuffer(local_2c0,2);
            return 0xffffffff;
          }
          iVar3 = strcmp((char *)(*(int *)(gpGlobals + 0xc) + *(int *)(gpGlobals + 0x98)),
                         (char *)(iVar3 + 0x40));
          if (iVar3 != 0) {
            MakeDormant__11CBaseEntity(piVar6);
          }
        }
      }
    }
    else {
      param_2[0x151] = local_2b4;
      param_2[0x152] = local_2b0;
      param_2[0x153] = local_2ac;
      if (piVar6 != (int *)0x0) {
        UTIL_SetOrigin__FP9entvars_sRC6Vector(*piVar6,*piVar6 + 8);
        (**(code **)(piVar6[0x115] + 0x70))(piVar6);
      }
    }
    ___18CSaveRestoreBuffer(local_2c0,2);
  }
  return 0;
}


