// DispatchRestore__FP7edict_sP13saverestore_si  @ 000a08a0
undefined4 DispatchRestore__FP7edict_sP13saverestore_si(int param_1,int *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  code *pcVar6;
  undefined1 local_214 [4];
  undefined4 local_210;
  undefined4 local_20c;
  undefined1 local_208 [4];
  undefined4 local_204;
  undefined4 local_200;
  int local_1fc;
  int local_1f8;
  int local_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  float local_134;
  float local_130;
  float local_12c;
  
  if (param_1 == 0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(param_1 + 0xd8);
  }
  if ((piVar4 != (int *)0x0) && (param_2 != (int *)0x0)) {
    __4__14(&local_1f0);
    __18CSaveRestoreBufferP13saverestore_s(local_208,param_2);
    local_204 = 0;
    local_200 = 1;
    if (param_3 != 0) {
      __18CSaveRestoreBufferP13saverestore_s(local_214,param_2);
      local_210 = 0;
      local_20c = 0;
      ReadEntVars__8CRestorePCcP9entvars_t(local_214,"ENTVARS",&local_1f0);
      iVar3 = *(int *)(param_2[10] + 8 + param_2[7] * 0x18);
      param_2[2] = iVar3;
      param_2[1] = iVar3 + *param_2;
      iVar3 = EntityFromTable__12CGlobalStatei(&gGlobalState,local_1ec);
      iVar3 = strcmp((char *)(param_2 + 0x155),(char *)(iVar3 + 0x40));
      if (iVar3 != 0) {
        ___18CSaveRestoreBuffer(local_214,2);
        ___18CSaveRestoreBuffer(local_208,2);
        return 0;
      }
      local_1fc = param_2[0x151];
      local_1f8 = param_2[0x152];
      local_1f4 = param_2[0x153];
      piVar4 = (int *)FindGlobalEntity__Fii(local_1f0,local_1ec);
      if (piVar4 == (int *)0x0) {
        ___18CSaveRestoreBuffer(local_214,2);
        ___18CSaveRestoreBuffer(local_208,2);
        return 0;
      }
      local_204 = 1;
      iVar3 = *piVar4;
      fVar1 = *(float *)(iVar3 + 0xc0);
      fVar2 = *(float *)(iVar3 + 0xc4);
      param_2[0x151] = (int)(((float)param_2[0x151] - *(float *)(iVar3 + 0xbc)) + local_134);
      param_2[0x152] = (int)(((float)param_2[0x152] - fVar1) + local_130);
      param_2[0x153] = (int)(((float)param_2[0x153] - fVar2) + local_12c);
      param_1 = *(int *)(*piVar4 + 0x1e8);
      EntityUpdate__12CGlobalStateii
                (&gGlobalState,*(undefined4 *)(*piVar4 + 4),*(undefined4 *)(gpGlobals + 0xc));
      ___18CSaveRestoreBuffer(local_214,2);
    }
    uVar5 = (**(code **)(piVar4[0xf2] + 0x1c))(piVar4);
    if ((uVar5 & 4) == 0) {
      (**(code **)(piVar4[0xf2] + 0x18))(piVar4,local_208);
      pcVar6 = *(code **)(piVar4[0xf2] + 0xc);
    }
    else {
      (**(code **)(piVar4[0xf2] + 0x18))(piVar4,local_208);
      pcVar6 = *(code **)(piVar4[0xf2] + 8);
    }
    (*pcVar6)(piVar4);
    if (param_1 == 0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = *(int **)(param_1 + 0xd8);
    }
    if (param_3 == 0) {
      if ((piVar4 != (int *)0x0) && (*(int *)(*piVar4 + 4) != 0)) {
        iVar3 = EntityFromTable__12CGlobalStatei(&gGlobalState,*(undefined4 *)(*piVar4 + 4));
        if (iVar3 == 0) {
          (*DAT_001755b4)(4,"Global Entity %s (%s) not in table!!!\n",
                          *(int *)(*piVar4 + 4) + *(int *)(gpGlobals + 0x98),
                          *(int *)*piVar4 + *(int *)(gpGlobals + 0x98));
          EntityAdd__12CGlobalStateii12GLOBALESTATE
                    (&gGlobalState,*(undefined4 *)(*piVar4 + 4),*(undefined4 *)(gpGlobals + 0xc),1);
        }
        else {
          if (*(int *)(iVar3 + 0x60) == 2) {
            ___18CSaveRestoreBuffer(local_208,2);
            return 0xffffffff;
          }
          iVar3 = strcmp((char *)(*(int *)(gpGlobals + 0xc) + *(int *)(gpGlobals + 0x98)),
                         (char *)(iVar3 + 0x40));
          if (iVar3 != 0) {
            MakeDormant__11CBaseEntity(piVar4);
          }
        }
      }
    }
    else {
      param_2[0x151] = local_1fc;
      param_2[0x152] = local_1f8;
      param_2[0x153] = local_1f4;
      if (piVar4 != (int *)0x0) {
        UTIL_SetOrigin__FP9entvars_tRC6Vector(*piVar4,*piVar4 + 8);
        (**(code **)(piVar4[0xf2] + 0x6c))(piVar4);
      }
    }
    ___18CSaveRestoreBuffer(local_208,2);
  }
  return 0;
}


