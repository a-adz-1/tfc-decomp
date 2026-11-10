// _._10bad_typeid  @ 00127ce0
void ___10bad_typeid(undefined4 *param_1,byte param_2)

{
  *param_1 = __vt_10bad_typeid;
  *param_1 = __vt_9exception;
  if ((param_2 & 1) != 0) {
    __builtin_delete(param_1);
  }
  return;
}


// _._13bad_exception  @ 00127260
void ___13bad_exception(undefined4 *param_1,byte param_2)

{
  *param_1 = __vt_13bad_exception;
  *param_1 = __vt_9exception;
  if ((param_2 & 1) != 0) {
    __builtin_delete(param_1);
  }
  return;
}


// _._14__si_type_info  @ 00127bf0
void ___14__si_type_info(undefined4 param_1,undefined4 param_2)

{
  ___9type_info(param_1,param_2);
  return;
}


// _._15UTIL_GroupTrace  @ 00109d2c
void ___15UTIL_GroupTrace(undefined4 *param_1,uint param_2)

{
  g_groupmask = *param_1;
  g_groupop = param_1[1];
  (*DAT_001a805c)(g_groupmask,g_groupop);
  if ((param_2 & 1) != 0) {
    __builtin_delete(param_1);
  }
  return;
}


// _._16__attr_type_info  @ 001316b0
void ___16__attr_type_info(undefined4 param_1,undefined4 param_2)

{
  ___9type_info(param_1,param_2);
  return;
}


// _._16__func_type_info  @ 001315b0
void ___16__func_type_info(undefined4 param_1,undefined4 param_2)

{
  ___9type_info(param_1,param_2);
  return;
}


// _._16__ptmd_type_info  @ 001314b0
void ___16__ptmd_type_info(undefined4 param_1,undefined4 param_2)

{
  ___9type_info(param_1,param_2);
  return;
}


// _._16__ptmf_type_info  @ 00131530
void ___16__ptmf_type_info(undefined4 param_1,undefined4 param_2)

{
  ___9type_info(param_1,param_2);
  return;
}


// _._16__user_type_info  @ 00127cb0
void ___16__user_type_info(void)

{
  FUN_00127cb9();
  return;
}


// _._17__array_type_info  @ 00131430
void ___17__array_type_info(undefined4 param_1,undefined4 param_2)

{
  ___9type_info(param_1,param_2);
  return;
}


// _._17__class_type_info  @ 00127b20
void ___17__class_type_info(undefined4 param_1,undefined4 param_2)

{
  ___9type_info(param_1,param_2);
  return;
}


// _._18CSaveRestoreBuffer  @ 0010cddc
void ___18CSaveRestoreBuffer(undefined4 param_1,byte param_2)

{
  if ((param_2 & 1) != 0) {
    __builtin_delete(param_1);
  }
  return;
}


// _._19__builtin_type_info  @ 00131630
void ___19__builtin_type_info(undefined4 param_1,undefined4 param_2)

{
  ___9type_info(param_1,param_2);
  return;
}


// _._19__pointer_type_info  @ 00131730
void ___19__pointer_type_info(undefined4 param_1,undefined4 param_2)

{
  ___9type_info(param_1,param_2);
  return;
}


// _._8bad_cast  @ 00127da0
void ___8bad_cast(undefined4 *param_1,byte param_2)

{
  *param_1 = __vt_8bad_cast;
  *param_1 = __vt_9exception;
  if ((param_2 & 1) != 0) {
    __builtin_delete(param_1);
  }
  return;
}


// _._9bad_alloc  @ 00128c40
void ___9bad_alloc(undefined4 *param_1,byte param_2)

{
  *param_1 = __vt_9exception;
  if ((param_2 & 1) != 0) {
    __builtin_delete(param_1);
  }
  return;
}


// _._9exception  @ 00127320
void ___9exception(undefined4 *param_1,byte param_2)

{
  *param_1 = __vt_9exception;
  if ((param_2 & 1) != 0) {
    __builtin_delete(param_1);
  }
  return;
}


// _._9type_info  @ 00127730
void ___9type_info(int param_1,byte param_2)

{
  *(undefined1 **)(param_1 + 4) = __vt_9type_info;
  if ((param_2 & 1) != 0) {
    __builtin_delete(param_1);
  }
  return;
}


// _DotProduct  @ 0011f460
longdouble _DotProduct(float *param_1,float *param_2)

{
  return (longdouble)param_1[2] * (longdouble)param_2[2] +
         (longdouble)param_1[1] * (longdouble)param_2[1] +
         (longdouble)*param_1 * (longdouble)*param_2;
}


// _GLOBAL_.I._13CActAnimating.m_SaveData  @ 00115aec
void _GLOBAL__I__13CActAnimating_m_SaveData(void)

{
  _14CXenSporeLarge_m_hullSizes = 0x42b40000;
  DAT_001b5c64 = 0xc1c80000;
  DAT_001b5c68 = 0;
  DAT_001b5c6c = 0x41c80000;
  DAT_001b5c70 = 0x42960000;
  DAT_001b5c74 = 0;
  DAT_001b5c78 = 0xc1700000;
  DAT_001b5c7c = 0xc2c80000;
  DAT_001b5c80 = 0;
  DAT_001b5c84 = 0xc2b40000;
  DAT_001b5c88 = 0xc20c0000;
  DAT_001b5c8c = 0;
  DAT_001b5c90 = 0xc2b40000;
  DAT_001b5c94 = 0x42700000;
  DAT_001b5c98 = 0;
  return;
}


// _GLOBAL_.I._9CFuncTank.m_SaveData  @ 000a29c0
void _GLOBAL__I__9CFuncTank_m_SaveData(void)

{
  gTankSpread = 0;
  DAT_001a75a4 = 0;
  DAT_001a75a8 = 0;
  DAT_001a75ac = 0x3ccccccd;
  DAT_001a75b0 = 0x3ccccccd;
  DAT_001a75b4 = 0x3ccccccd;
  DAT_001a75b8 = 0x3d4ccccd;
  DAT_001a75bc = 0x3d4ccccd;
  DAT_001a75c0 = 0x3d4ccccd;
  DAT_001a75c4 = 0x3dcccccd;
  DAT_001a75c8 = 0x3dcccccd;
  DAT_001a75cc = 0x3dcccccd;
  DAT_001a75d0 = 0x3e800000;
  DAT_001a75d4 = 0x3e800000;
  DAT_001a75d8 = 0x3e800000;
  return;
}


// _GLOBAL_.I.gDecals  @ 001141f0
void _GLOBAL__I_gDecals(void)

{
  __12CGlobalState(&gGlobalState);
  return;
}


// _GLOBAL_.I.info_node  @ 000c0ba4
void _GLOBAL__I_info_node(void)

{
  int iVar1;
  
  iVar1 = 0x7f;
  do {
    iVar1 = iVar1 + -0x10;
  } while (iVar1 != -1);
  return;
}


// _GLOBAL_.I.sTeamSpawnNames  @ 000f8560
void _GLOBAL__I_sTeamSpawnNames(void)

{
  return;
}


// _VectorAdd  @ 0011f4a8
void _VectorAdd(float *param_1,float *param_2,float *param_3)

{
  *param_3 = *param_1 + *param_2;
  param_3[1] = param_1[1] + param_2[1];
  param_3[2] = param_1[2] + param_2[2];
  return;
}


// _VectorCopy  @ 0011f4d0
void _VectorCopy(undefined4 *param_1,undefined4 *param_2)

{
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  return;
}


// _VectorSubtract  @ 0011f480
void _VectorSubtract(float *param_1,float *param_2,float *param_3)

{
  *param_3 = *param_1 - *param_2;
  param_3[1] = param_1[1] - param_2[1];
  param_3[2] = param_1[2] - param_2[2];
  return;
}


// __10bad_typeid  @ 00127d20
undefined4 * __10bad_typeid(undefined4 *param_1)

{
  *param_1 = __vt_9exception;
  *param_1 = __vt_10bad_typeid;
  return param_1;
}


// __11CBaseEntity  @ 00128cdc
int __11CBaseEntity(int param_1)

{
  *(undefined1 **)(param_1 + 0x3d4) = __vt_11CBaseEntity;
  return param_1;
}


// __12CBaseMonster  @ 00128d00
int __12CBaseMonster(int param_1)

{
  __11CBaseEntity(param_1);
  *(undefined1 **)(param_1 + 0x3d4) = __vt_10CBaseDelay;
  *(undefined1 **)(param_1 + 0x3d4) = __vt_14CBaseAnimating;
  *(undefined1 **)(param_1 + 0x3d4) = __vt_11CBaseToggle;
  *(undefined1 **)(param_1 + 0x3d4) = __vt_12CBaseMonster;
  return param_1;
}


// __12CGlobalState  @ 00112d14
undefined4 __12CGlobalState(undefined4 param_1)

{
  Reset__12CGlobalState(param_1);
  return param_1;
}


// __13bad_exception  @ 001272a0
undefined4 * __13bad_exception(undefined4 *param_1)

{
  *param_1 = __vt_9exception;
  *param_1 = __vt_13bad_exception;
  return param_1;
}


// __14CHalfLifeRules  @ 000a385c
undefined4 * __14CHalfLifeRules(undefined4 *param_1)

{
  *param_1 = __vt_10CGameRules;
  *param_1 = __vt_14CHalfLifeRules;
  RefreshSkillData__10CGameRules(param_1);
  return param_1;
}


// __14CQueuePriority  @ 000bd42c
void __14CQueuePriority(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}


// __14__si_type_infoPCcRC16__user_type_info  @ 00127b50
undefined4 *
__14__si_type_infoPCcRC16__user_type_info(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  param_1[1] = __vt_9type_info;
  *param_1 = param_2;
  param_1[1] = __vt_16__user_type_info;
  param_1[1] = __vt_14__si_type_info;
  param_1[2] = param_3;
  return param_1;
}


// __15UTIL_GroupTraceii  @ 00109ccc
undefined4 * __15UTIL_GroupTraceii(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = g_groupmask;
  param_1[1] = g_groupop;
  g_groupmask = param_2;
  g_groupop = param_3;
  (*DAT_001a805c)(param_2,param_3);
  return param_1;
}


// __16__user_type_infoPCc  @ 00127c20
undefined4 * __16__user_type_infoPCc(undefined4 *param_1,undefined4 param_2)

{
  param_1[1] = __vt_9type_info;
  *param_1 = param_2;
  param_1[1] = __vt_16__user_type_info;
  return param_1;
}


// __17CHalfLifeTeamplay  @ 000ea260
undefined4 * __17CHalfLifeTeamplay(undefined4 *param_1)

{
  __18CHalfLifeMultiplay(param_1);
  *param_1 = __vt_17CHalfLifeTeamplay;
  param_1[3] = 0;
  param_1[4] = 0;
  return param_1;
}


// __17__class_type_infoPCcPCQ217__class_type_info9base_infoUi  @ 00127a80
undefined4 *
__17__class_type_infoPCcPCQ217__class_type_info9base_infoUi
          (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  param_1[1] = __vt_9type_info;
  *param_1 = param_2;
  param_1[1] = __vt_16__user_type_info;
  param_1[1] = __vt_17__class_type_info;
  param_1[2] = param_3;
  param_1[3] = param_4;
  return param_1;
}


// __18CHalfLifeMultiplay  @ 000a3aac
undefined4 * __18CHalfLifeMultiplay(undefined4 *param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 uVar4;
  char local_100 [256];
  
  *param_1 = __vt_10CGameRules;
  *param_1 = __vt_18CHalfLifeMultiplay;
  RefreshSkillData__10CGameRules(param_1);
  param_1[1] = 0;
  iVar1 = (*DAT_001a800c)();
  if (iVar1 == 0) {
    pcVar2 = (char *)(*DAT_001a7f28)("lservercfgfile");
    if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) goto LAB_000a3b8a;
    pcVar3 = "Executing listen server config file\n";
  }
  else {
    pcVar2 = (char *)(*DAT_001a7f28)("servercfgfile");
    if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) goto LAB_000a3b8a;
    pcVar3 = "Executing dedicated server config file\n";
  }
  (*DAT_001a7f34)(1,pcVar3);
  sprintf(local_100,"exec %s\n",pcVar2);
  (*DAT_001a7edc)(local_100);
LAB_000a3b8a:
  (*DAT_001a7ee0)();
  uVar4 = (*DAT_001a7f28)("hostname");
  UTIL_LogPrintf__FPce("Server name is \"%s\"\n",uVar4);
  return param_1;
}


// __18CSaveRestoreBuffer  @ 0010cdc0
void __18CSaveRestoreBuffer(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}


// __18CSaveRestoreBufferP13saverestore_s  @ 0010cdcc
undefined4 * __18CSaveRestoreBufferP13saverestore_s(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return param_1;
}


// __6CPlane  @ 000c1dd0
void __6CPlane(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


// __6CQueue  @ 000bd354
void __6CQueue(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[0xc9] = 0;
  param_1[0xca] = 0xffffffff;
  return;
}


// __6CStack  @ 000bd288
void __6CStack(int param_1)

{
  *(undefined4 *)(param_1 + 400) = 0;
  return;
}


// __8bad_cast  @ 00127de0
void __8bad_cast(void)

{
  FUN_00127de9();
  return;
}


// __9entvars_s  @ 001295b4
undefined4 __9entvars_s(undefined4 param_1)

{
  return param_1;
}


// __9exception  @ 00127350
undefined4 * __9exception(undefined4 *param_1)

{
  *param_1 = __vt_9exception;
  return param_1;
}


// __9type_infoPCc  @ 00127ea0
undefined4 * __9type_infoPCc(undefined4 *param_1,undefined4 param_2)

{
  param_1[1] = __vt_9type_info;
  *param_1 = param_2;
  return param_1;
}


// __as__7EHANDLEP11CBaseEntity  @ 000866d8
int * __as__7EHANDLEP11CBaseEntity(int *param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    *param_1 = 0;
    param_1[1] = 0;
  }
  else {
    iVar1 = *(int *)(*param_2 + 0x208);
    *param_1 = iVar1;
    if (iVar1 != 0) {
      param_1[1] = *(int *)(iVar1 + 4);
    }
  }
  return param_2;
}


// __builtin_delete  @ 001273c0
void __builtin_delete(void *param_1)

{
  if (param_1 != (void *)0x0) {
    free(param_1);
  }
  return;
}


// __builtin_new  @ 001274a0
void __builtin_new(int *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  
  puVar4 = &stack0xffffffec;
  if (param_1 == (int *)0x0) {
    param_1 = (int *)0x1;
  }
  pvVar1 = malloc((size_t)param_1);
  if (pvVar1 != (void *)0x0) {
    return;
  }
  do {
    pcVar3 = __new_handler;
    puVar5 = puVar4;
    if (__new_handler == (code *)0x0) {
      *(undefined4 *)(puVar4 + -4) = 4;
      *(undefined4 *)(puVar4 + -8) = 0x1274f9;
      param_1 = (int *)__eh_alloc();
      *param_1 = (int)__vt_9exception;
      *param_1 = (int)__vt_9bad_alloc;
      *(code **)(puVar4 + -4) = ___9bad_alloc;
      pcVar3 = *(code **)(*param_1 + 4);
      *(undefined4 *)(puVar4 + -8) = 0x127537;
      uVar2 = (*pcVar3)();
      *(undefined4 *)(puVar4 + -8) = uVar2;
      puVar5 = puVar4 + -0xc;
      *(int **)(puVar4 + -0xc) = param_1;
      *(undefined4 *)(puVar4 + -0x10) = 0x12753e;
      __cp_push_exception();
      *(undefined4 *)(puVar4 + -0x10) = 0x127543;
      pcVar3 = (code *)__throw();
    }
    *(undefined4 *)(puVar5 + -4) = 0x127552;
    (*pcVar3)();
    *(int **)(puVar5 + -4) = param_1;
    *(undefined4 *)(puVar5 + -8) = 0x127558;
    pvVar1 = malloc(*(size_t *)(puVar5 + -4));
    puVar4 = puVar5;
  } while (pvVar1 == (void *)0x0);
  FUN_00127640();
  return;
}


// __builtin_vec_new  @ 00127650
void __builtin_vec_new(undefined4 param_1)

{
  __builtin_new(param_1);
  return;
}


// __check_eh_spec  @ 00126e80
void __check_eh_spec(int param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined **ppuVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int iVar9;
  int *piVar10;
  undefined4 *puVar11;
  int local_c;
  
  local_c = __cp_eh_info();
  iVar9 = 0;
  puVar11 = param_2;
  if (0 < param_1) {
    do {
      iVar2 = __throw_type_match_rtti
                        (*puVar11,*(undefined4 *)(local_c + 0xc),*(undefined4 *)(local_c + 8));
      if (iVar2 != 0) {
        __uncatch_exception();
        __throw();
      }
      iVar9 = iVar9 + 1;
      puVar11 = puVar11 + 1;
    } while (iVar9 < param_1);
  }
  unexpected__Fv();
  __throw();
  ppuVar6 = &__DT_PLTGOT;
  iVar9 = __cp_eh_info();
  *(int *)(iVar9 + 0x1c) = *(int *)(iVar9 + 0x1c) + 1;
  *(undefined1 *)(iVar9 + 0x14) = 1;
  if ((local_c != iVar9) && (iVar2 = 0, puVar11 = param_2, local_c = iVar9, 0 < param_1)) {
    do {
      iVar3 = __throw_type_match_rtti
                        (*puVar11,*(undefined4 *)(iVar9 + 0xc),*(undefined4 *)(iVar9 + 8));
      if (iVar3 != 0) {
        __uncatch_exception();
        __throw();
      }
      iVar2 = iVar2 + 1;
      puVar11 = puVar11 + 1;
    } while (iVar2 < param_1);
  }
  uVar4 = __tf13bad_exception();
  piVar10 = (int *)0x0;
  puVar7 = &stack0xffffffe4;
  puVar8 = &stack0xffffffe4;
  if (param_1 < 1) goto LAB_0012700a;
  do {
    *(undefined4 *)(puVar7 + -4) = *(undefined4 *)(local_c + 8);
    *(undefined4 *)(puVar7 + -8) = uVar4;
    *(undefined4 *)(puVar7 + -0xc) = param_2[(int)piVar10];
    *(undefined4 *)(puVar7 + -0x10) = 0x126f80;
    iVar9 = __throw_type_match_rtti();
    puVar8 = puVar7;
    if (iVar9 == 0) goto LAB_00127000;
    *(undefined4 *)(puVar7 + -4) = 4;
    *(undefined4 *)(puVar7 + -8) = 0x126fa0;
    piVar10 = (int *)__eh_alloc();
    *piVar10 = (int)ppuVar6[0x8e3];
    *piVar10 = (int)ppuVar6[0x8e4];
    while( true ) {
      *(undefined **)(puVar7 + -4) = ppuVar6[0x8e5];
      pcVar1 = *(code **)(*piVar10 + 4);
      *(undefined4 *)(puVar7 + -8) = 0x126ff0;
      uVar5 = (*pcVar1)();
      *(undefined4 *)(puVar7 + -8) = uVar5;
      puVar8 = puVar7 + -0xc;
      *(int **)(puVar7 + -0xc) = piVar10;
      *(undefined4 *)(puVar7 + -0x10) = 0x126ff7;
      __cp_push_exception();
      *(undefined4 *)(puVar7 + -0x10) = 0x126ffc;
      __throw();
LAB_00127000:
      piVar10 = (int *)((int)piVar10 + 1);
      puVar7 = puVar8;
      if ((int)piVar10 < param_1) break;
LAB_0012700a:
      puVar7 = puVar8;
      *(undefined4 *)(puVar7 + -4) = 0x12700f;
      terminate__Fv();
      *(undefined4 *)(puVar7 + -4) = 0x127015;
      __throw();
      *(undefined4 *)(puVar7 + -4) = 0x127025;
      ppuVar6 = (undefined **)(*(int *)(puVar7 + -4) + 0x7e03f);
      *(undefined4 *)(puVar7 + -4) = 0x126fc5;
      __throw();
    }
  } while( true );
}


// __cp_eh_info  @ 00126c40
undefined4 __cp_eh_info(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)__get_eh_info();
  return *puVar1;
}


// __cp_exception_info  @ 00126c10
int __cp_exception_info(void)

{
  int *piVar1;
  
  piVar1 = (int *)__get_eh_info();
  return *piVar1 + 8;
}


// __cp_pop_exception  @ 00126da0
void __cp_pop_exception(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *extraout_EDX;
  
  piVar2 = (int *)__get_eh_info();
  iVar3 = *(int *)(param_1 + 0x1c);
  *(int *)(param_1 + 0x1c) = iVar3 + -1;
  if (iVar3 != 1) {
    return;
  }
  iVar3 = *piVar2;
  if ((param_1 == iVar3) && (*(char *)(param_1 + 0x14) == '\0')) {
    return;
  }
  if (iVar3 != 0) {
    do {
      if (iVar3 == param_1) break;
      piVar2 = (int *)(iVar3 + 0x18);
      iVar3 = *(int *)(iVar3 + 0x18);
    } while (iVar3 != 0);
    if (iVar3 != 0) goto LAB_00126e00;
  }
  terminate__Fv();
  piVar2 = extraout_EDX;
LAB_00126e00:
  *piVar2 = *(int *)(param_1 + 0x18);
  if (*(code **)(param_1 + 0x10) != (code *)0x0) {
    (**(code **)(param_1 + 0x10))(*(undefined4 *)(param_1 + 8),2);
  }
  cVar1 = __is_pointer__FPv(*(undefined4 *)(param_1 + 0xc));
  if (cVar1 == '\0') {
    __eh_free(*(undefined4 *)(param_1 + 8));
  }
  __eh_free(param_1);
  return;
}


// __cp_push_exception  @ 00126d30
void __cp_push_exception(void)

{
  FUN_00126d3b();
  return;
}


// __cplus_type_matcher  @ 00126cc0
int __cplus_type_matcher(int param_1,code *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(short *)(param_3 + 4) == 4) {
    if (param_2 == (code *)0xffffffff) {
      iVar1 = *(int *)(param_1 + 8);
    }
    else {
      uVar2 = (*param_2)();
      iVar1 = __throw_type_match_rtti
                        (uVar2,*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x20));
      if (iVar1 != 0) {
        *(int *)(param_1 + 8) = iVar1;
      }
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


// __default_terminate  @ 00125ff0
void __default_terminate(void)

{
                    /* WARNING: Subroutine does not return */
  abort();
}


// __default_unexpected__Fv  @ 00126b70
undefined * __default_unexpected__Fv(void)

{
  undefined *puVar1;
  undefined *unaff_EBP;
  
  terminate__Fv();
  puVar1 = __terminate_func;
  __terminate_func = unaff_EBP;
  return puVar1;
}


// __dynamic_cast  @ 001285c0
void __dynamic_cast(code *param_1,code *param_2,undefined4 param_3,undefined4 param_4,code *param_5,
                   undefined4 param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = (*param_1)();
  iVar1 = *(int *)(iVar2 + 4);
  uVar3 = (*param_5)(param_6);
  uVar3 = (*param_2)(param_3,param_4,uVar3);
  (**(code **)(iVar1 + 0xc))(iVar2,uVar3);
  return;
}


// __eh_alloc  @ 00126c60
void __eh_alloc(size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    terminate__Fv();
  }
  return;
}


// __eh_free  @ 00126ca0
void __eh_free(void *param_1)

{
  free(param_1);
  return;
}


// __empty  @ 00126080
void __empty(void)

{
  return;
}


// __eq__C9type_infoRC9type_info  @ 00127760
undefined1 __eq__C9type_infoRC9type_info(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if ((param_2 != param_1) && (iVar1 = strcmp((char *)*param_1,(char *)*param_2), iVar1 != 0)) {
    return 0;
  }
  return 1;
}


// __get_dynamic_handler_chain  @ 00126190
int __get_dynamic_handler_chain(void)

{
  int iVar1;
  
  iVar1 = (*(code *)get_eh_context)();
  return iVar1 + 4;
}


// __get_eh_context  @ 001260e0
void __get_eh_context(void)

{
  (*(code *)get_eh_context)();
  return;
}


// __get_eh_info  @ 00126100
int __get_eh_info(void)

{
  int iVar1;
  
  iVar1 = (*(code *)get_eh_context)();
  return iVar1 + 8;
}


// __get_eh_table_language  @ 00126420
int __get_eh_table_language(int param_1)

{
  return (int)*(short *)(param_1 + 4);
}


// __get_eh_table_version  @ 00126410
int __get_eh_table_version(int param_1)

{
  return (int)*(short *)(param_1 + 6);
}


// __is_pointer__FPv  @ 001283e0
bool __is_pointer__FPv(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = __dynamic_cast((*(int **)(param_1 + 4))[1],__tf19__pointer_type_info,1,
                           param_1 + **(int **)(param_1 + 4),__tf9type_info,param_1);
  }
  return iVar1 != 0;
}


// __ne__C9type_infoRC9type_info  @ 00127e60
uint __ne__C9type_infoRC9type_info(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = __eq__C9type_infoRC9type_info(param_1,param_2);
  return uVar1 ^ 1;
}


// __nw__11CBaseEntityUiP9entvars_s  @ 001003f0
void __nw__11CBaseEntityUiP9entvars_s(undefined4 param_1,int param_2)

{
  (*DAT_001a7f3c)(*(undefined4 *)(param_2 + 0x208),param_1);
  return;
}


// __nw__FUiPv  @ 00128bb0
undefined4 __nw__FUiPv(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}


// __opP11CBaseEntity__7EHANDLE  @ 000866b0
undefined4 __opP11CBaseEntity__7EHANDLE(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Get__7EHANDLE(param_1);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x7c);
  }
  return uVar2;
}


// __opi__7EHANDLE  @ 0008670c
bool __opi__7EHANDLE(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = Get__7EHANDLE(param_1);
  return iVar1 != 0;
}


// __pure_virtual  @ 00126b20
void __pure_virtual(void)

{
  __write(2,"pure virtual method called\n",0x1b);
                    /* WARNING: Subroutine does not return */
  _exit(-1);
}


// __rf__7EHANDLE  @ 00086734
undefined4 __rf__7EHANDLE(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Get__7EHANDLE(param_1);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x7c);
  }
  return uVar2;
}


// __rtti_array  @ 00128580
void __rtti_array(undefined4 *param_1,undefined4 param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    param_1[1] = __vt_9type_info;
    *param_1 = param_2;
    param_1[1] = __vt_17__array_type_info;
  }
  return;
}


// __rtti_attr  @ 00128470
void __rtti_attr(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 != (undefined4 *)0x0) {
    param_1[1] = __vt_9type_info;
    *param_1 = param_2;
    param_1[1] = __vt_16__attr_type_info;
    param_1[2] = param_4;
    param_1[3] = param_3;
  }
  return;
}


// __rtti_class  @ 001277a0
void __rtti_class(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 != (undefined4 *)0x0) {
    param_1[1] = __vt_9type_info;
    *param_1 = param_2;
    param_1[1] = __vt_16__user_type_info;
    param_1[1] = __vt_17__class_type_info;
    param_1[2] = param_3;
    param_1[3] = param_4;
  }
  return;
}


// __rtti_func  @ 001284c0
void __rtti_func(undefined4 *param_1,undefined4 param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    param_1[1] = __vt_9type_info;
    *param_1 = param_2;
    param_1[1] = __vt_16__func_type_info;
  }
  return;
}


// __rtti_ptmd  @ 00128540
void __rtti_ptmd(undefined4 *param_1,undefined4 param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    param_1[1] = __vt_9type_info;
    *param_1 = param_2;
    param_1[1] = __vt_16__ptmd_type_info;
  }
  return;
}


// __rtti_ptmf  @ 00128500
void __rtti_ptmf(undefined4 *param_1,undefined4 param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    param_1[1] = __vt_9type_info;
    *param_1 = param_2;
    param_1[1] = __vt_16__ptmf_type_info;
  }
  return;
}


// __rtti_ptr  @ 00128430
void __rtti_ptr(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 != (undefined4 *)0x0) {
    param_1[1] = __vt_9type_info;
    *param_1 = param_2;
    param_1[1] = __vt_19__pointer_type_info;
    param_1[2] = param_3;
  }
  return;
}


// __rtti_si  @ 001277f0
void __rtti_si(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 != (undefined4 *)0x0) {
    param_1[1] = __vt_9type_info;
    *param_1 = param_2;
    param_1[1] = __vt_16__user_type_info;
    param_1[1] = __vt_14__si_type_info;
    param_1[2] = param_3;
  }
  return;
}


// __rtti_user  @ 00127840
void __rtti_user(undefined4 *param_1,undefined4 param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    param_1[1] = __vt_9type_info;
    *param_1 = param_2;
    param_1[1] = __vt_16__user_type_info;
  }
  return;
}


// __sjpopnthrow  @ 00126300
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __sjpopnthrow(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  code *pcVar4;
  undefined4 uVar5;
  int iVar6;
  int local_644;
  undefined4 local_640;
  undefined1 *local_63c;
  undefined *local_638;
  undefined1 *local_634;
  
  iVar6 = (*(code *)get_eh_context)();
  piVar1 = (int *)(iVar6 + 4);
  puVar2 = (undefined4 *)(*(int *)(iVar6 + 4) + 4);
  if (*(int *)(*(int *)(iVar6 + 4) + 4) != 0) {
    local_640 = 0;
    local_644 = *(int *)(iVar6 + 4);
    local_638 = &DAT_00126380;
    *piVar1 = (int)&local_644;
    puVar3 = (undefined4 *)*puVar2;
    local_63c = &stack0xfffffffc;
    local_634 = &stack0xfffff9a4;
    while (puVar3 != (undefined4 *)0x0) {
      pcVar4 = (code *)puVar3[1];
      uVar5 = puVar3[2];
      *puVar2 = *puVar3;
      (*pcVar4)(uVar5,2);
      puVar3 = (undefined4 *)*puVar2;
    }
    *piVar1 = local_644;
  }
  *piVar1 = *(int *)*piVar1;
  __sjthrow();
  return;
}


// __sjthrow  @ 001261c0
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __sjthrow(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  code *pcVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iStack_644;
  undefined4 uStack_640;
  undefined1 *puStack_63c;
  undefined *puStack_638;
  undefined1 *puStack_634;
  
  iVar5 = (*(code *)get_eh_context)();
  piVar7 = (int *)(iVar5 + 4);
  puVar1 = (undefined4 *)(*(int *)(iVar5 + 4) + 4);
  if (*(int *)(*(int *)(iVar5 + 4) + 4) != 0) {
    uStack_640 = 0;
    iStack_644 = *(int *)(iVar5 + 4);
    puStack_638 = &UNK_00126250;
    *piVar7 = (int)&iStack_644;
    puVar2 = (undefined4 *)*puVar1;
    puStack_63c = &stack0xfffffffc;
    puStack_634 = &stack0xfffff9a0;
    while (puVar2 != (undefined4 *)0x0) {
      pcVar3 = (code *)puVar2[1];
      uVar4 = puVar2[2];
      *puVar1 = *puVar2;
      (*pcVar3)(uVar4,2);
      puVar2 = (undefined4 *)*puVar1;
    }
    *piVar7 = iStack_644;
  }
  if ((*(int *)(iVar5 + 8) == 0) || (piVar6 = (int *)*piVar7, *piVar6 == 0)) {
    __terminate();
    piVar6 = (int *)*piVar7;
  }
  *piVar7 = *piVar6;
                    /* WARNING: Could not recover jumptable at 0x001262ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)piVar6[3])();
  return;
}


// __terminate  @ 00126010
void __terminate(void)

{
  (*(code *)__terminate_func)();
  return;
}


// __tf10CBaseDelay  @ 000e7b40
undefined4 * __tf10CBaseDelay(void)

{
  if (__ti10CBaseDelay == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti10CBaseDelay,"10CBaseDelay",&__ti11CBaseEntity);
  }
  return &__ti10CBaseDelay;
}


// __tf10CBreakable  @ 0009f8f0
undefined4 * __tf10CBreakable(void)

{
  if (__ti10CBreakable == 0) {
    __tf10CBaseDelay();
    __rtti_si(&__ti10CBreakable,"10CBreakable",&__ti10CBaseDelay);
  }
  return &__ti10CBreakable;
}


// __tf10CCineBlood  @ 000a9474
undefined4 * __tf10CCineBlood(void)

{
  if (__ti10CCineBlood == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti10CCineBlood,"10CCineBlood",&__ti11CBaseEntity);
  }
  return &__ti10CCineBlood;
}


// __tf10CEnvFunnel  @ 0009b2d4
undefined4 * __tf10CEnvFunnel(void)

{
  if (__ti10CEnvFunnel == 0) {
    __tf10CBaseDelay();
    __rtti_si(&__ti10CEnvFunnel,"10CEnvFunnel",&__ti10CBaseDelay);
  }
  return &__ti10CEnvFunnel;
}


// __tf10CEnvGlobal  @ 00085964
undefined4 * __tf10CEnvGlobal(void)

{
  if (__ti10CEnvGlobal == 0) {
    __tf12CPointEntity();
    __rtti_si(&__ti10CEnvGlobal,"10CEnvGlobal",&__ti12CPointEntity);
  }
  return &__ti10CEnvGlobal;
}


// __tf10CFuncTrain  @ 000c7690
undefined4 * __tf10CFuncTrain(void)

{
  if (__ti10CFuncTrain == 0) {
    __tf14CBasePlatTrain();
    __rtti_si(&__ti10CFuncTrain,"10CFuncTrain",&__ti14CBasePlatTrain);
  }
  return &__ti10CFuncTrain;
}


// __tf10CFurniture  @ 000dded4
undefined4 * __tf10CFurniture(void)

{
  if (__ti10CFurniture == 0) {
    __tf12CBaseMonster();
    __rtti_si(&__ti10CFurniture,"10CFurniture",&__ti12CBaseMonster);
  }
  return &__ti10CFurniture;
}


// __tf10CGameRules  @ 000a5ce8
undefined4 * __tf10CGameRules(void)

{
  if (__ti10CGameRules == 0) {
    __rtti_user(&__ti10CGameRules,"10CGameRules");
  }
  return &__ti10CGameRules;
}


// __tf10CGunTarget  @ 000c7548
undefined4 * __tf10CGunTarget(void)

{
  if (__ti10CGunTarget == 0) {
    __tf12CBaseMonster();
    __rtti_si(&__ti10CGunTarget,"10CGunTarget",&__ti12CBaseMonster);
  }
  return &__ti10CGunTarget;
}


// __tf10CHealthKit  @ 000ab698
undefined4 * __tf10CHealthKit(void)

{
  if (__ti10CHealthKit == 0) {
    __tf5CItem();
    __rtti_si(&__ti10CHealthKit,"10CHealthKit",&__ti5CItem);
  }
  return &__ti10CHealthKit;
}


// __tf10CItemArmor  @ 000ee248
undefined4 * __tf10CItemArmor(void)

{
  if (__ti10CItemArmor == 0) {
    __tf5CItem();
    __rtti_si(&__ti10CItemArmor,"10CItemArmor",&__ti5CItem);
  }
  return &__ti10CItemArmor;
}


// __tf10CLaserSpot  @ 000f4c70
undefined4 * __tf10CLaserSpot(void)

{
  if (__ti10CLaserSpot == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti10CLaserSpot,"10CLaserSpot",&__ti11CBaseEntity);
  }
  return &__ti10CLaserSpot;
}


// __tf10CLightning  @ 0009b698
undefined4 * __tf10CLightning(void)

{
  if (__ti10CLightning == 0) {
    __tf5CBeam();
    __rtti_si(&__ti10CLightning,"10CLightning",&__ti5CBeam);
  }
  return &__ti10CLightning;
}


// __tf10CPathTrack  @ 000c1d8c
undefined4 * __tf10CPathTrack(void)

{
  if (__ti10CPathTrack == 0) {
    __tf12CPointEntity();
    __rtti_si(&__ti10CPathTrack,"10CPathTrack",&__ti12CPointEntity);
  }
  return &__ti10CPathTrack;
}


// __tf10CRotButton  @ 00085920
undefined4 * __tf10CRotButton(void)

{
  if (__ti10CRotButton == 0) {
    __tf11CBaseButton();
    __rtti_si(&__ti10CRotButton,"10CRotButton",&__ti11CBaseButton);
  }
  return &__ti10CRotButton;
}


// __tf10CTFBomblet  @ 000f23ac
undefined4 * __tf10CTFBomblet(void)

{
  if (__ti10CTFBomblet == 0) {
    __tf15CTFPrimeGrenade();
    __rtti_si(&__ti10CTFBomblet,"10CTFBomblet",&__ti15CTFPrimeGrenade);
  }
  return &__ti10CTFBomblet;
}


// __tf10CTFCaltrop  @ 000f20ec
undefined4 * __tf10CTFCaltrop(void)

{
  if (__ti10CTFCaltrop == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti10CTFCaltrop,"10CTFCaltrop",&__ti11CBaseEntity);
  }
  return &__ti10CTFCaltrop;
}


// __tf10CTFGrenade  @ 000f4d3c
undefined4 * __tf10CTFGrenade(void)

{
  if (__ti10CTFGrenade == 0) {
    __tf8CGrenade();
    __rtti_si(&__ti10CTFGrenade,"10CTFGrenade",&__ti8CGrenade);
  }
  return &__ti10CTFGrenade;
}


// __tf10CTFMedikit  @ 00118d30
undefined4 * __tf10CTFMedikit(void)

{
  if (__ti10CTFMedikit == 0) {
    __tf6CTFAxe();
    __rtti_si(&__ti10CTFMedikit,"10CTFMedikit",&__ti6CTFAxe);
  }
  return &__ti10CTFMedikit;
}


// __tf10CTFNailgun  @ 0011b098
undefined4 * __tf10CTFNailgun(void)

{
  if (__ti10CTFNailgun == 0) {
    __tf17CBasePlayerWeapon();
    __rtti_si(&__ti10CTFNailgun,"10CTFNailgun",&__ti17CBasePlayerWeapon);
  }
  return &__ti10CTFNailgun;
}


// __tf10CTFRailgun  @ 0011b55c
undefined4 * __tf10CTFRailgun(void)

{
  if (__ti10CTFRailgun == 0) {
    __tf17CBasePlayerWeapon();
    __rtti_si(&__ti10CTFRailgun,"10CTFRailgun",&__ti17CBasePlayerWeapon);
  }
  return &__ti10CTFRailgun;
}


// __tf10CTFRpgAmmo  @ 0012eb38
undefined4 * __tf10CTFRpgAmmo(void)

{
  if (__ti10CTFRpgAmmo == 0) {
    __tf15CBasePlayerAmmo();
    __rtti_si(&__ti10CTFRpgAmmo,"10CTFRpgAmmo",&__ti15CBasePlayerAmmo);
  }
  return &__ti10CTFRpgAmmo;
}


// __tf10CTFShotgun  @ 0011cb90
undefined4 * __tf10CTFShotgun(void)

{
  if (__ti10CTFShotgun == 0) {
    __tf17CBasePlayerWeapon();
    __rtti_si(&__ti10CTFShotgun,"10CTFShotgun",&__ti17CBasePlayerWeapon);
  }
  return &__ti10CTFShotgun;
}


// __tf10CTFSpanner  @ 00118d74
undefined4 * __tf10CTFSpanner(void)

{
  if (__ti10CTFSpanner == 0) {
    __tf6CTFAxe();
    __rtti_si(&__ti10CTFSpanner,"10CTFSpanner",&__ti6CTFAxe);
  }
  return &__ti10CTFSpanner;
}


// __tf10CWeaponBox  @ 00112304
undefined4 * __tf10CWeaponBox(void)

{
  if (__ti10CWeaponBox == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti10CWeaponBox,"10CWeaponBox",&__ti11CBaseEntity);
  }
  return &__ti10CWeaponBox;
}


// __tf10CWorldItem  @ 000abcdc
undefined4 * __tf10CWorldItem(void)

{
  if (__ti10CWorldItem == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti10CWorldItem,"10CWorldItem",&__ti11CBaseEntity);
  }
  return &__ti10CWorldItem;
}


// __tf10CXenPLight  @ 00115dac
undefined4 * __tf10CXenPLight(void)

{
  if (__ti10CXenPLight == 0) {
    __tf13CActAnimating();
    __rtti_si(&__ti10CXenPLight,"10CXenPLight",&__ti13CActAnimating);
  }
  return &__ti10CXenPLight;
}


// __tf10bad_typeid  @ 00127d50
undefined4 * __tf10bad_typeid(void)

{
  if (__ti10bad_typeid == 0) {
    __tf9exception();
    __rtti_si(&__ti10bad_typeid,"10bad_typeid",&__ti9exception);
  }
  return &__ti10bad_typeid;
}


// __tf11CBaseButton  @ 000859f0
undefined4 * __tf11CBaseButton(void)

{
  if (__ti11CBaseButton == 0) {
    __tf11CBaseToggle();
    __rtti_si(&__ti11CBaseButton,"11CBaseButton",&__ti11CBaseToggle);
  }
  return &__ti11CBaseButton;
}


// __tf11CBaseEntity  @ 0010073c
undefined4 * __tf11CBaseEntity(void)

{
  if (__ti11CBaseEntity == 0) {
    __rtti_user(&__ti11CBaseEntity,"11CBaseEntity");
  }
  return &__ti11CBaseEntity;
}


// __tf11CBasePlayer  @ 000d8e08
undefined4 * __tf11CBasePlayer(void)

{
  if (__ti11CBasePlayer == 0) {
    __tf12CBaseMonster();
    __rtti_si(&__ti11CBasePlayer,"11CBasePlayer",&__ti12CBaseMonster);
  }
  return &__ti11CBasePlayer;
}


// __tf11CBaseToggle  @ 000e7afc
undefined4 * __tf11CBaseToggle(void)

{
  if (__ti11CBaseToggle == 0) {
    __tf14CBaseAnimating();
    __rtti_si(&__ti11CBaseToggle,"11CBaseToggle",&__ti14CBaseAnimating);
  }
  return &__ti11CBaseToggle;
}


// __tf11CBaseTurret  @ 00109a8c
undefined4 * __tf11CBaseTurret(void)

{
  if (__ti11CBaseTurret == 0) {
    __tf12CBaseMonster();
    __rtti_si(&__ti11CBaseTurret,"11CBaseTurret",&__ti12CBaseMonster);
  }
  return &__ti11CBaseTurret;
}


// __tf11CCine2Slave  @ 0012b2b0
undefined4 * __tf11CCine2Slave(void)

{
  if (__ti11CCine2Slave == 0) {
    __tf18CLegacyCineMonster();
    __rtti_si(&__ti11CCine2Slave,"11CCine2Slave",&__ti18CLegacyCineMonster);
  }
  return &__ti11CCine2Slave;
}


// __tf11CCineBarney  @ 0012b380
undefined4 * __tf11CCineBarney(void)

{
  if (__ti11CCineBarney == 0) {
    __tf18CLegacyCineMonster();
    __rtti_si(&__ti11CCineBarney,"11CCineBarney",&__ti18CLegacyCineMonster);
  }
  return &__ti11CCineBarney;
}


// __tf11CEnvShooter  @ 0009b58c
undefined4 * __tf11CEnvShooter(void)

{
  if (__ti11CEnvShooter == 0) {
    __tf11CGibShooter();
    __rtti_si(&__ti11CEnvShooter,"11CEnvShooter",&__ti11CGibShooter);
  }
  return &__ti11CEnvShooter;
}


// __tf11CFireAndDie  @ 00106364
undefined4 * __tf11CFireAndDie(void)

{
  if (__ti11CFireAndDie == 0) {
    __tf10CBaseDelay();
    __rtti_si(&__ti11CFireAndDie,"11CFireAndDie",&__ti10CBaseDelay);
  }
  return &__ti11CFireAndDie;
}


// __tf11CGibShooter  @ 0009b5d0
undefined4 * __tf11CGibShooter(void)

{
  if (__ti11CGibShooter == 0) {
    __tf10CBaseDelay();
    __rtti_si(&__ti11CGibShooter,"11CGibShooter",&__ti10CBaseDelay);
  }
  return &__ti11CGibShooter;
}


// __tf11CItemHealth  @ 000ee28c
undefined4 * __tf11CItemHealth(void)

{
  if (__ti11CItemHealth == 0) {
    __tf5CItem();
    __rtti_si(&__ti11CItemHealth,"11CItemHealth",&__ti5CItem);
  }
  return &__ti11CItemHealth;
}


// __tf11CMiniTurret  @ 001099d4
undefined4 * __tf11CMiniTurret(void)

{
  if (__ti11CMiniTurret == 0) {
    __tf11CBaseTurret();
    __rtti_si(&__ti11CMiniTurret,"11CMiniTurret",&__ti11CBaseTurret);
  }
  return &__ti11CMiniTurret;
}


// __tf11CNodeViewer  @ 000c0bc4
undefined4 * __tf11CNodeViewer(void)

{
  if (__ti11CNodeViewer == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti11CNodeViewer,FUN_001394b4,&__ti11CBaseEntity);
  }
  return &__ti11CNodeViewer;
}


// __tf11CNullEntity  @ 000e7aa0
undefined4 * __tf11CNullEntity(void)

{
  if (__ti11CNullEntity == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti11CNullEntity,"11CNullEntity",&__ti11CBaseEntity);
  }
  return &__ti11CNullEntity;
}


// __tf11CPathCorner  @ 000c1d48
undefined4 * __tf11CPathCorner(void)

{
  if (__ti11CPathCorner == 0) {
    __tf12CPointEntity();
    __rtti_si(&__ti11CPathCorner,"11CPathCorner",&__ti12CPointEntity);
  }
  return &__ti11CPathCorner;
}


// __tf11CTFAssaultC  @ 00116754
undefined4 * __tf11CTFAssaultC(void)

{
  if (__ti11CTFAssaultC == 0) {
    __tf17CBasePlayerWeapon();
    __rtti_si(&__ti11CTFAssaultC,"11CTFAssaultC",&__ti17CBasePlayerWeapon);
  }
  return &__ti11CTFAssaultC;
}


// __tf11CTFGoalItem  @ 000ffffc
undefined4 * __tf11CTFGoalItem(void)

{
  if (__ti11CTFGoalItem == 0) {
    __tf7CTFGoal();
    __rtti_si(&__ti11CTFGoalItem,"11CTFGoalItem",&__ti7CTFGoal);
  }
  return &__ti11CTFGoalItem;
}


// __tf11CTestEffect  @ 0009b548
undefined4 * __tf11CTestEffect(void)

{
  if (__ti11CTestEffect == 0) {
    __tf10CBaseDelay();
    __rtti_si(&__ti11CTestEffect,"11CTestEffect",&__ti10CBaseDelay);
  }
  return &__ti11CTestEffect;
}


// __tf11CWallHealth  @ 000ab654
void __tf11CWallHealth(void)

{
  FUN_000ab65a();
  return;
}


// __tf12CAutoTrigger  @ 001066e8
undefined4 * __tf12CAutoTrigger(void)

{
  if (__ti12CAutoTrigger == 0) {
    __tf10CBaseDelay();
    __rtti_si(&__ti12CAutoTrigger,"12CAutoTrigger",&__ti10CBaseDelay);
  }
  return &__ti12CAutoTrigger;
}


// __tf12CBaseMonster  @ 000b7730
undefined4 * __tf12CBaseMonster(void)

{
  if (__ti12CBaseMonster == 0) {
    __tf11CBaseToggle();
    __rtti_si(&__ti12CBaseMonster,"12CBaseMonster",&__ti11CBaseToggle);
  }
  return &__ti12CBaseMonster;
}


// __tf12CBaseTrigger  @ 001065cc
undefined4 * __tf12CBaseTrigger(void)

{
  if (__ti12CBaseTrigger == 0) {
    __tf11CBaseToggle();
    __rtti_si(&__ti12CBaseTrigger,"12CBaseTrigger",&__ti11CBaseToggle);
  }
  return &__ti12CBaseTrigger;
}


// __tf12CChangeLevel  @ 00106318
undefined4 * __tf12CChangeLevel(void)

{
  if (__ti12CChangeLevel == 0) {
    __tf12CBaseTrigger();
    __rtti_si(&__ti12CChangeLevel,"12CChangeLevel",&__ti12CBaseTrigger);
  }
  return &__ti12CChangeLevel;
}


// __tf12CCine3Barney  @ 0012b1e0
undefined4 * __tf12CCine3Barney(void)

{
  if (__ti12CCine3Barney == 0) {
    __tf18CLegacyCineMonster();
    __rtti_si(&__ti12CCine3Barney,"12CCine3Barney",&__ti18CLegacyCineMonster);
  }
  return &__ti12CCine3Barney;
}


// __tf12CCineMonster  @ 000ddfa8
undefined4 * __tf12CCineMonster(void)

{
  if (__ti12CCineMonster == 0) {
    __tf12CBaseMonster();
    __rtti_si(&__ti12CCineMonster,"12CCineMonster",&__ti12CBaseMonster);
  }
  return &__ti12CCineMonster;
}


// __tf12CCinePanther  @ 0012b3e8
undefined4 * __tf12CCinePanther(void)

{
  if (__ti12CCinePanther == 0) {
    __tf18CLegacyCineMonster();
    __rtti_si(&__ti12CCinePanther,"12CCinePanther",&__ti18CLegacyCineMonster);
  }
  return &__ti12CCinePanther;
}


// __tf12CCyclerProbe  @ 000aa55c
undefined4 * __tf12CCyclerProbe(void)

{
  if (__ti12CCyclerProbe == 0) {
    __tf7CCycler();
    __rtti_si(&__ti12CCyclerProbe,"12CCyclerProbe",&__ti7CCycler);
  }
  return &__ti12CCyclerProbe;
}


// __tf12CEnvBeverage  @ 0009b290
undefined4 * __tf12CEnvBeverage(void)

{
  if (__ti12CEnvBeverage == 0) {
    __tf10CBaseDelay();
    __rtti_si(&__ti12CEnvBeverage,"12CEnvBeverage",&__ti10CBaseDelay);
  }
  return &__ti12CEnvBeverage;
}


// __tf12CFuncPlatRot  @ 000c76d4
undefined4 * __tf12CFuncPlatRot(void)

{
  if (__ti12CFuncPlatRot == 0) {
    __tf9CFuncPlat();
    __rtti_si(&__ti12CFuncPlatRot,"12CFuncPlatRot",&__ti9CFuncPlat);
  }
  return &__ti12CFuncPlatRot;
}


// __tf12CFuncTankGun  @ 000a2b4c
undefined4 * __tf12CFuncTankGun(void)

{
  if (__ti12CFuncTankGun == 0) {
    __tf9CFuncTank();
    __rtti_si(&__ti12CFuncTankGun,"12CFuncTankGun",&__ti9CFuncTank);
  }
  return &__ti12CFuncTankGun;
}


// __tf12CHandGrenade  @ 000aae3c
undefined4 * __tf12CHandGrenade(void)

{
  if (__ti12CHandGrenade == 0) {
    __tf17CBasePlayerWeapon();
    __rtti_si(&__ti12CHandGrenade,"12CHandGrenade",&__ti17CBasePlayerWeapon);
  }
  return &__ti12CHandGrenade;
}


// __tf12CItemBattery  @ 0012c2ec
undefined4 * __tf12CItemBattery(void)

{
  if (__ti12CItemBattery == 0) {
    __tf5CItem();
    __rtti_si(&__ti12CItemBattery,"12CItemBattery",&__ti5CItem);
  }
  return &__ti12CItemBattery;
}


// __tf12CItemPowerup  @ 000edfe0
undefined4 * __tf12CItemPowerup(void)

{
  if (__ti12CItemPowerup == 0) {
    __tf5CItem();
    __rtti_si(&__ti12CItemPowerup,"12CItemPowerup",&__ti5CItem);
  }
  return &__ti12CItemPowerup;
}


// __tf12CMultiSource  @ 00085a34
undefined4 * __tf12CMultiSource(void)

{
  if (__ti12CMultiSource == 0) {
    __tf12CPointEntity();
    __rtti_si(&__ti12CMultiSource,"12CMultiSource",&__ti12CPointEntity);
  }
  return &__ti12CMultiSource;
}


// __tf12CNoBuildArea  @ 0009c89c
undefined4 * __tf12CNoBuildArea(void)

{
  if (__ti12CNoBuildArea == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti12CNoBuildArea,"12CNoBuildArea",&__ti11CBaseEntity);
  }
  return &__ti12CNoBuildArea;
}


// __tf12CPlatTrigger  @ 000c7720
void __tf12CPlatTrigger(void)

{
  FUN_000c7726();
  return;
}


// __tf12CPointEntity  @ 000e7b88
undefined4 * __tf12CPointEntity(void)

{
  if (__ti12CPointEntity == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti12CPointEntity,"12CPointEntity",&__ti11CBaseEntity);
  }
  return &__ti12CPointEntity;
}


// __tf12CRevertSaved  @ 000d8b40
undefined4 * __tf12CRevertSaved(void)

{
  if (__ti12CRevertSaved == 0) {
    __tf12CPointEntity();
    __rtti_si(&__ti12CRevertSaved,"12CRevertSaved",&__ti12CPointEntity);
  }
  return &__ti12CRevertSaved;
}


// __tf12CTFAutoRifle  @ 00116dac
undefined4 * __tf12CTFAutoRifle(void)

{
  if (__ti12CTFAutoRifle == 0) {
    __tf17CBasePlayerWeapon();
    __rtti_si(&__ti12CTFAutoRifle,"12CTFAutoRifle",&__ti17CBasePlayerWeapon);
  }
  return &__ti12CTFAutoRifle;
}


// __tf12CTFDispenser  @ 00092ed4
undefined4 * __tf12CTFDispenser(void)

{
  if (__ti12CTFDispenser == 0) {
    __tf12CBaseMonster();
    __rtti_si(&__ti12CTFDispenser,"12CTFDispenser",&__ti12CBaseMonster);
  }
  return &__ti12CTFDispenser;
}


// __tf12CTFRpgRocket  @ 000f4cb4
undefined4 * __tf12CTFRpgRocket(void)

{
  if (__ti12CTFRpgRocket == 0) {
    __tf8CGrenade();
    __rtti_si(&__ti12CTFRpgRocket,"12CTFRpgRocket",&__ti8CGrenade);
  }
  return &__ti12CTFRpgRocket;
}


// __tf12CTFSentrygun  @ 000e0984
undefined4 * __tf12CTFSentrygun(void)

{
  if (__ti12CTFSentrygun == 0) {
    __tf12CBaseMonster();
    __rtti_si(&__ti12CTFSentrygun,"12CTFSentrygun",&__ti12CBaseMonster);
  }
  return &__ti12CTFSentrygun;
}


// __tf12CTFTimerGoal  @ 000fffb0
undefined4 * __tf12CTFTimerGoal(void)

{
  if (__ti12CTFTimerGoal == 0) {
    __tf7CTFGoal();
    __rtti_si(&__ti12CTFTimerGoal,"12CTFTimerGoal",&__ti7CTFGoal);
  }
  return &__ti12CTFTimerGoal;
}


// __tf12CTalkMonster  @ 000ea21c
undefined4 * __tf12CTalkMonster(void)

{
  if (__ti12CTalkMonster == 0) {
    __tf12CBaseMonster();
    __rtti_si(&__ti12CTalkMonster,"12CTalkMonster",&__ti12CBaseMonster);
  }
  return &__ti12CTalkMonster;
}


// __tf12CTriggerHurt  @ 00106584
undefined4 * __tf12CTriggerHurt(void)

{
  if (__ti12CTriggerHurt == 0) {
    __tf12CBaseTrigger();
    __rtti_si(&__ti12CTriggerHurt,"12CTriggerHurt",&__ti12CBaseTrigger);
  }
  return &__ti12CTriggerHurt;
}


// __tf12CTriggerOnce  @ 00106430
undefined4 * __tf12CTriggerOnce(void)

{
  if (__ti12CTriggerOnce == 0) {
    __tf16CTriggerMultiple();
    __rtti_si(&__ti12CTriggerOnce,"12CTriggerOnce",&__ti16CTriggerMultiple);
  }
  return &__ti12CTriggerOnce;
}


// __tf12CTriggerPush  @ 00106290
undefined4 * __tf12CTriggerPush(void)

{
  if (__ti12CTriggerPush == 0) {
    __tf12CBaseTrigger();
    __rtti_si(&__ti12CTriggerPush,"12CTriggerPush",&__ti12CBaseTrigger);
  }
  return &__ti12CTriggerPush;
}


// __tf12CTriggerSave  @ 00106208
undefined4 * __tf12CTriggerSave(void)

{
  if (__ti12CTriggerSave == 0) {
    __tf12CBaseTrigger();
    __rtti_si(&__ti12CTriggerSave,"12CTriggerSave",&__ti12CBaseTrigger);
  }
  return &__ti12CTriggerSave;
}


// __tf12CXenSporeMed  @ 00115bc8
undefined4 * __tf12CXenSporeMed(void)

{
  if (__ti12CXenSporeMed == 0) {
    __tf9CXenSpore();
    __rtti_si(&__ti12CXenSporeMed,"12CXenSporeMed",&__ti9CXenSpore);
  }
  return &__ti12CXenSporeMed;
}


// __tf13CActAnimating  @ 00115e00
undefined4 * __tf13CActAnimating(void)

{
  if (__ti13CActAnimating == 0) {
    __tf14CBaseAnimating();
    __rtti_si(&__ti13CActAnimating,"13CActAnimating",&__ti14CBaseAnimating);
  }
  return &__ti13CActAnimating;
}


// __tf13CButtonTarget  @ 00085828
undefined4 * __tf13CButtonTarget(void)

{
  if (__ti13CButtonTarget == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti13CButtonTarget,"13CButtonTarget",&__ti11CBaseEntity);
  }
  return &__ti13CButtonTarget;
}


// __tf13CCyclerSprite  @ 000aa518
undefined4 * __tf13CCyclerSprite(void)

{
  if (__ti13CCyclerSprite == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti13CCyclerSprite,"13CCyclerSprite",&__ti11CBaseEntity);
  }
  return &__ti13CCyclerSprite;
}


// __tf13CEnvExplosion  @ 0009d6ac
undefined4 * __tf13CEnvExplosion(void)

{
  if (__ti13CEnvExplosion == 0) {
    __tf12CBaseMonster();
    __rtti_si(&__ti13CEnvExplosion,"13CEnvExplosion",&__ti12CBaseMonster);
  }
  return &__ti13CEnvExplosion;
}


// __tf13CFuncConveyor  @ 00082690
undefined4 * __tf13CFuncConveyor(void)

{
  if (__ti13CFuncConveyor == 0) {
    __tf9CFuncWall();
    __rtti_si(&__ti13CFuncConveyor,"13CFuncConveyor",&__ti9CFuncWall);
  }
  return &__ti13CFuncConveyor;
}


// __tf13CFuncRotating  @ 000825bc
undefined4 * __tf13CFuncRotating(void)

{
  if (__ti13CFuncRotating == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti13CFuncRotating,"13CFuncRotating",&__ti11CBaseEntity);
  }
  return &__ti13CFuncRotating;
}


// __tf13CItemAntidote  @ 0012c064
undefined4 * __tf13CItemAntidote(void)

{
  if (__ti13CItemAntidote == 0) {
    __tf5CItem();
    __rtti_si(&__ti13CItemAntidote,"13CItemAntidote",&__ti5CItem);
  }
  return &__ti13CItemAntidote;
}


// __tf13CItemArmorRed  @ 000ee17c
undefined4 * __tf13CItemArmorRed(void)

{
  if (__ti13CItemArmorRed == 0) {
    __tf10CItemArmor();
    __rtti_si(&__ti13CItemArmorRed,"13CItemArmorRed",&__ti10CItemArmor);
  }
  return &__ti13CItemArmorRed;
}


// __tf13CItemLongJump  @ 0012bec0
undefined4 * __tf13CItemLongJump(void)

{
  if (__ti13CItemLongJump == 0) {
    __tf5CItem();
    __rtti_si(&__ti13CItemLongJump,"13CItemLongJump",&__ti5CItem);
  }
  return &__ti13CItemLongJump;
}


// __tf13CItemSecurity  @ 0012bf80
undefined4 * __tf13CItemSecurity(void)

{
  if (__ti13CItemSecurity == 0) {
    __tf5CItem();
    __rtti_si(&__ti13CItemSecurity,"13CItemSecurity",&__ti5CItem);
  }
  return &__ti13CItemSecurity;
}


// __tf13CMultiManager  @ 00106658
undefined4 * __tf13CMultiManager(void)

{
  if (__ti13CMultiManager == 0) {
    __tf11CBaseToggle();
    __rtti_si(&__ti13CMultiManager,"13CMultiManager",&__ti11CBaseToggle);
  }
  return &__ti13CMultiManager;
}


// __tf13CSquadMonster  @ 000e6a70
undefined4 * __tf13CSquadMonster(void)

{
  if (__ti13CSquadMonster == 0) {
    __tf12CBaseMonster();
    __rtti_si(&__ti13CSquadMonster,"13CSquadMonster",&__ti12CBaseMonster);
  }
  return &__ti13CSquadMonster;
}


// __tf13CStripWeapons  @ 000d8b84
undefined4 * __tf13CStripWeapons(void)

{
  if (__ti13CStripWeapons == 0) {
    __tf12CPointEntity();
    __rtti_si(&__ti13CStripWeapons,"13CStripWeapons",&__ti12CPointEntity);
  }
  return &__ti13CStripWeapons;
}


// __tf13CTFEMPGrenade  @ 000f2584
undefined4 * __tf13CTFEMPGrenade(void)

{
  if (__ti13CTFEMPGrenade == 0) {
    __tf15CTFPrimeGrenade();
    __rtti_si(&__ti13CTFEMPGrenade,"13CTFEMPGrenade",&__ti15CTFPrimeGrenade);
  }
  return &__ti13CTFEMPGrenade;
}


// __tf13CTFGasGrenade  @ 000f221c
undefined4 * __tf13CTFGasGrenade(void)

{
  if (__ti13CTFGasGrenade == 0) {
    __tf15CTFPrimeGrenade();
    __rtti_si(&__ti13CTFGasGrenade,"13CTFGasGrenade",&__ti15CTFPrimeGrenade);
  }
  return &__ti13CTFGasGrenade;
}


// __tf13CTeamFortress  @ 000ec8e4
undefined4 * __tf13CTeamFortress(void)

{
  if (__ti13CTeamFortress == 0) {
    __tf17CHalfLifeTeamplay();
    __rtti_si(&__ti13CTeamFortress,"13CTeamFortress",&__ti17CHalfLifeTeamplay);
  }
  return &__ti13CTeamFortress;
}


// __tf13CTriggerRelay  @ 001066a0
undefined4 * __tf13CTriggerRelay(void)

{
  if (__ti13CTriggerRelay == 0) {
    __tf10CBaseDelay();
    __rtti_si(&__ti13CTriggerRelay,"13CTriggerRelay",&__ti10CBaseDelay);
  }
  return &__ti13CTriggerRelay;
}


// __tf13CWeaponCycler  @ 000aa48c
undefined4 * __tf13CWeaponCycler(void)

{
  if (__ti13CWeaponCycler == 0) {
    __tf17CBasePlayerWeapon();
    __rtti_si(&__ti13CWeaponCycler,"13CWeaponCycler",&__ti17CBasePlayerWeapon);
  }
  return &__ti13CWeaponCycler;
}


// __tf13bad_exception  @ 001272d0
undefined4 * __tf13bad_exception(void)

{
  if (__ti13bad_exception == 0) {
    __tf9exception();
    __rtti_si(&__ti13bad_exception,"13bad_exception",&__ti9exception);
  }
  return &__ti13bad_exception;
}


// __tf14CBaseAnimating  @ 000b7778
undefined4 * __tf14CBaseAnimating(void)

{
  if (__ti14CBaseAnimating == 0) {
    __tf10CBaseDelay();
    __rtti_si(&__ti14CBaseAnimating,"14CBaseAnimating",&__ti10CBaseDelay);
  }
  return &__ti14CBaseAnimating;
}


// __tf14CBasePlatTrain  @ 000c7838
undefined4 * __tf14CBasePlatTrain(void)

{
  if (__ti14CBasePlatTrain == 0) {
    __tf11CBaseToggle();
    __rtti_si(&__ti14CBasePlatTrain,"14CBasePlatTrain",&__ti11CBaseToggle);
  }
  return &__ti14CBasePlatTrain;
}


// __tf14CBaseSpectator  @ 000e4728
undefined4 * __tf14CBaseSpectator(void)

{
  if (__ti14CBaseSpectator == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti14CBaseSpectator,"14CBaseSpectator",&__ti11CBaseEntity);
  }
  return &__ti14CBaseSpectator;
}


// __tf14CCineScientist  @ 0012b4b8
undefined4 * __tf14CCineScientist(void)

{
  if (__ti14CCineScientist == 0) {
    __tf18CLegacyCineMonster();
    __rtti_si(&__ti14CCineScientist,"14CCineScientist",&__ti18CLegacyCineMonster);
  }
  return &__ti14CCineScientist;
}


// __tf14CFuncTankLaser  @ 000a2b08
undefined4 * __tf14CFuncTankLaser(void)

{
  if (__ti14CFuncTankLaser == 0) {
    __tf9CFuncTank();
    __rtti_si(&__ti14CFuncTankLaser,"14CFuncTankLaser",&__ti9CFuncTank);
  }
  return &__ti14CFuncTankLaser;
}


// __tf14CFuncTrackAuto  @ 000c758c
undefined4 * __tf14CFuncTrackAuto(void)

{
  if (__ti14CFuncTrackAuto == 0) {
    __tf16CFuncTrackChange();
    __rtti_si(&__ti14CFuncTrackAuto,"14CFuncTrackAuto",&__ti16CFuncTrackChange);
  }
  return &__ti14CFuncTrackAuto;
}


// __tf14CGenericCycler  @ 0012b838
undefined4 * __tf14CGenericCycler(void)

{
  if (__ti14CGenericCycler == 0) {
    __tf7CCycler();
    __rtti_si(&__ti14CGenericCycler,"14CGenericCycler",&__ti7CCycler);
  }
  return &__ti14CGenericCycler;
}


// __tf14CHalfLifeRules  @ 000a5c38
undefined4 * __tf14CHalfLifeRules(void)

{
  if (__ti14CHalfLifeRules == 0) {
    __tf10CGameRules();
    __rtti_si(&__ti14CHalfLifeRules,"14CHalfLifeRules",&__ti10CGameRules);
  }
  return &__ti14CHalfLifeRules;
}


// __tf14CItemAmmoCells  @ 000ee024
undefined4 * __tf14CItemAmmoCells(void)

{
  if (__ti14CItemAmmoCells == 0) {
    __tf9CItemAmmo();
    __rtti_si(&__ti14CItemAmmoCells,"14CItemAmmoCells",&__ti9CItemAmmo);
  }
  return &__ti14CItemAmmoCells;
}


// __tf14CItemAmmoNails  @ 000ee0ac
undefined4 * __tf14CItemAmmoNails(void)

{
  if (__ti14CItemAmmoNails == 0) {
    __tf9CItemAmmo();
    __rtti_si(&__ti14CItemAmmoNails,"14CItemAmmoNails",&__ti9CItemAmmo);
  }
  return &__ti14CItemAmmoNails;
}


// __tf14CMomentaryDoor  @ 000954fc
undefined4 * __tf14CMomentaryDoor(void)

{
  if (__ti14CMomentaryDoor == 0) {
    __tf11CBaseToggle();
    __rtti_si(&__ti14CMomentaryDoor,"14CMomentaryDoor",&__ti11CBaseToggle);
  }
  return &__ti14CMomentaryDoor;
}


// __tf14CTFIncendiaryC  @ 0011a700
undefined4 * __tf14CTFIncendiaryC(void)

{
  if (__ti14CTFIncendiaryC == 0) {
    __tf17CBasePlayerWeapon();
    __rtti_si(&__ti14CTFIncendiaryC,"14CTFIncendiaryC",&__ti17CBasePlayerWeapon);
  }
  return &__ti14CTFIncendiaryC;
}


// __tf14CTFMirvGrenade  @ 000f245c
undefined4 * __tf14CTFMirvGrenade(void)

{
  if (__ti14CTFMirvGrenade == 0) {
    __tf15CTFPrimeGrenade();
    __rtti_si(&__ti14CTFMirvGrenade,"14CTFMirvGrenade",&__ti15CTFPrimeGrenade);
  }
  return &__ti14CTFMirvGrenade;
}


// __tf14CTFNailGrenade  @ 000f2320
undefined4 * __tf14CTFNailGrenade(void)

{
  if (__ti14CTFNailGrenade == 0) {
    __tf15CTFPrimeGrenade();
    __rtti_si(&__ti14CTFNailGrenade,"14CTFNailGrenade",&__ti15CTFPrimeGrenade);
  }
  return &__ti14CTFNailGrenade;
}


// __tf14CTFNailgunNail  @ 000f4cf8
undefined4 * __tf14CTFNailgunNail(void)

{
  if (__ti14CTFNailgunNail == 0) {
    __tf8CGrenade();
    __rtti_si(&__ti14CTFNailgunNail,"14CTFNailgunNail",&__ti8CGrenade);
  }
  return &__ti14CTFNailgunNail;
}


// __tf14CTFSniperRifle  @ 0011dabc
undefined4 * __tf14CTFSniperRifle(void)

{
  if (__ti14CTFSniperRifle == 0) {
    __tf17CBasePlayerWeapon();
    __rtti_si(&__ti14CTFSniperRifle,"14CTFSniperRifle",&__ti17CBasePlayerWeapon);
  }
  return &__ti14CTFSniperRifle;
}


// __tf14CTargetCDAudio  @ 001064b8
undefined4 * __tf14CTargetCDAudio(void)

{
  if (__ti14CTargetCDAudio == 0) {
    __tf12CPointEntity();
    __rtti_si(&__ti14CTargetCDAudio,"14CTargetCDAudio",&__ti12CPointEntity);
  }
  return &__ti14CTargetCDAudio;
}


// __tf14CTelefragDeath  @ 00106774
undefined4 * __tf14CTelefragDeath(void)

{
  if (__ti14CTelefragDeath == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti14CTelefragDeath,"14CTelefragDeath",&__ti11CBaseEntity);
  }
  return &__ti14CTelefragDeath;
}


// __tf14CTriggerCamera  @ 001060f4
undefined4 * __tf14CTriggerCamera(void)

{
  if (__ti14CTriggerCamera == 0) {
    __tf10CBaseDelay();
    __rtti_si(&__ti14CTriggerCamera,"14CTriggerCamera",&__ti10CBaseDelay);
  }
  return &__ti14CTriggerCamera;
}


// __tf14CTriggerVolume  @ 001063a8
undefined4 * __tf14CTriggerVolume(void)

{
  if (__ti14CTriggerVolume == 0) {
    __tf12CPointEntity();
    __rtti_si(&__ti14CTriggerVolume,"14CTriggerVolume",&__ti12CPointEntity);
  }
  return &__ti14CTriggerVolume;
}


// __tf14CXenSporeLarge  @ 00115b84
undefined4 * __tf14CXenSporeLarge(void)

{
  if (__ti14CXenSporeLarge == 0) {
    __tf9CXenSpore();
    __rtti_si(&__ti14CXenSporeLarge,"14CXenSporeLarge",&__ti9CXenSpore);
  }
  return &__ti14CXenSporeLarge;
}


// __tf14CXenSporeSmall  @ 00115c0c
undefined4 * __tf14CXenSporeSmall(void)

{
  if (__ti14CXenSporeSmall == 0) {
    __tf9CXenSpore();
    __rtti_si(&__ti14CXenSporeSmall,"14CXenSporeSmall",&__ti9CXenSpore);
  }
  return &__ti14CXenSporeSmall;
}


// __tf14__si_type_info  @ 00127ba0
undefined1 * __tf14__si_type_info(void)

{
  if (__ti14__si_type_info._0_4_ == 0) {
    __tf16__user_type_info();
    __rtti_si(__ti14__si_type_info,"14__si_type_info",&__ti16__user_type_info);
  }
  return __ti14__si_type_info;
}


// __tf15CAmbientGeneric  @ 000e3db8
undefined4 * __tf15CAmbientGeneric(void)

{
  if (__ti15CAmbientGeneric == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti15CAmbientGeneric,"15CAmbientGeneric",&__ti11CBaseEntity);
  }
  return &__ti15CAmbientGeneric;
}


// __tf15CBasePlayerAmmo  @ 00112350
undefined4 * __tf15CBasePlayerAmmo(void)

{
  if (__ti15CBasePlayerAmmo == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti15CBasePlayerAmmo,"15CBasePlayerAmmo",&__ti11CBaseEntity);
  }
  return &__ti15CBasePlayerAmmo;
}


// __tf15CBasePlayerItem  @ 0011246c
undefined4 * __tf15CBasePlayerItem(void)

{
  if (__ti15CBasePlayerItem == 0) {
    __tf14CBaseAnimating();
    __rtti_si(&__ti15CBasePlayerItem,"15CBasePlayerItem",&__ti14CBaseAnimating);
  }
  return &__ti15CBasePlayerItem;
}


// __tf15CCine2Scientist  @ 0012b450
undefined4 * __tf15CCine2Scientist(void)

{
  if (__ti15CCine2Scientist == 0) {
    __tf18CLegacyCineMonster();
    __rtti_si(&__ti15CCine2Scientist,"15CCine2Scientist",&__ti18CLegacyCineMonster);
  }
  return &__ti15CCine2Scientist;
}


// __tf15CCine3Scientist  @ 0012b248
undefined4 * __tf15CCine3Scientist(void)

{
  if (__ti15CCine3Scientist == 0) {
    __tf18CLegacyCineMonster();
    __rtti_si(&__ti15CCine3Scientist,"15CCine3Scientist",&__ti18CLegacyCineMonster);
  }
  return &__ti15CCine3Scientist;
}


// __tf15CFuncTankMortar  @ 000a2a80
undefined4 * __tf15CFuncTankMortar(void)

{
  if (__ti15CFuncTankMortar == 0) {
    __tf9CFuncTank();
    __rtti_si(&__ti15CFuncTankMortar,"15CFuncTankMortar",&__ti9CFuncTank);
  }
  return &__ti15CFuncTankMortar;
}


// __tf15CFuncTankRocket  @ 000a2ac4
undefined4 * __tf15CFuncTankRocket(void)

{
  if (__ti15CFuncTankRocket == 0) {
    __tf9CFuncTank();
    __rtti_si(&__ti15CFuncTankRocket,"15CFuncTankRocket",&__ti9CFuncTank);
  }
  return &__ti15CFuncTankRocket;
}


// __tf15CFuncTrackTrain  @ 000c78d4
undefined4 * __tf15CFuncTrackTrain(void)

{
  if (__ti15CFuncTrackTrain == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti15CFuncTrackTrain,"15CFuncTrackTrain",&__ti11CBaseEntity);
  }
  return &__ti15CFuncTrackTrain;
}


// __tf15CFuncWallToggle  @ 000826d4
undefined4 * __tf15CFuncWallToggle(void)

{
  if (__ti15CFuncWallToggle == 0) {
    __tf9CFuncWall();
    __rtti_si(&__ti15CFuncWallToggle,"15CFuncWallToggle",&__ti9CFuncWall);
  }
  return &__ti15CFuncWallToggle;
}


// __tf15CGenericMonster  @ 000a5f58
undefined4 * __tf15CGenericMonster(void)

{
  if (__ti15CGenericMonster == 0) {
    __tf12CBaseMonster();
    __rtti_si(&__ti15CGenericMonster,"15CGenericMonster",&__ti12CBaseMonster);
  }
  return &__ti15CGenericMonster;
}


// __tf15CItemAmmoShells  @ 000ee0f0
undefined4 * __tf15CItemAmmoShells(void)

{
  if (__ti15CItemAmmoShells == 0) {
    __tf9CItemAmmo();
    __rtti_si(&__ti15CItemAmmoShells,"15CItemAmmoShells",&__ti9CItemAmmo);
  }
  return &__ti15CItemAmmoShells;
}


// __tf15CItemArmorGreen  @ 000ee204
undefined4 * __tf15CItemArmorGreen(void)

{
  if (__ti15CItemArmorGreen == 0) {
    __tf10CItemArmor();
    __rtti_si(&__ti15CItemArmorGreen,"15CItemArmorGreen",&__ti10CItemArmor);
  }
  return &__ti15CItemArmorGreen;
}


// __tf15CTFFlamethrower  @ 00119464
undefined4 * __tf15CTFFlamethrower(void)

{
  if (__ti15CTFFlamethrower == 0) {
    __tf17CBasePlayerWeapon();
    __rtti_si(&__ti15CTFFlamethrower,"15CTFFlamethrower",&__ti17CBasePlayerWeapon);
  }
  return &__ti15CTFFlamethrower;
}


// __tf15CTFPrimeGrenade  @ 000f2704
undefined4 * __tf15CTFPrimeGrenade(void)

{
  if (__ti15CTFPrimeGrenade == 0) {
    __tf8CGrenade();
    __rtti_si(&__ti15CTFPrimeGrenade,"15CTFPrimeGrenade",&__ti8CGrenade);
  }
  return &__ti15CTFPrimeGrenade;
}


// __tf15CTFSuperNailgun  @ 0011b04c
undefined4 * __tf15CTFSuperNailgun(void)

{
  if (__ti15CTFSuperNailgun == 0) {
    __tf10CTFNailgun();
    __rtti_si(&__ti15CTFSuperNailgun,"15CTFSuperNailgun",&__ti10CTFNailgun);
  }
  return &__ti15CTFSuperNailgun;
}


// __tf15CTFSuperShotgun  @ 0011cb4c
undefined4 * __tf15CTFSuperShotgun(void)

{
  if (__ti15CTFSuperShotgun == 0) {
    __tf10CTFShotgun();
    __rtti_si(&__ti15CTFSuperShotgun,"15CTFSuperShotgun",&__ti10CTFShotgun);
  }
  return &__ti15CTFSuperShotgun;
}


// __tf15CTriggerCDAudio  @ 001064fc
undefined4 * __tf15CTriggerCDAudio(void)

{
  if (__ti15CTriggerCDAudio == 0) {
    __tf12CBaseTrigger();
    __rtti_si(&__ti15CTriggerCDAudio,"15CTriggerCDAudio",&__ti12CBaseTrigger);
  }
  return &__ti15CTriggerCDAudio;
}


// __tf15CTriggerCounter  @ 001063ec
undefined4 * __tf15CTriggerCounter(void)

{
  if (__ti15CTriggerCounter == 0) {
    __tf12CBaseTrigger();
    __rtti_si(&__ti15CTriggerCounter,"15CTriggerCounter",&__ti12CBaseTrigger);
  }
  return &__ti15CTriggerCounter;
}


// __tf15CTriggerGravity  @ 00106180
undefined4 * __tf15CTriggerGravity(void)

{
  if (__ti15CTriggerGravity == 0) {
    __tf12CBaseTrigger();
    __rtti_si(&__ti15CTriggerGravity,"15CTriggerGravity",&__ti12CBaseTrigger);
  }
  return &__ti15CTriggerGravity;
}


// __tf15CXenTreeTrigger  @ 00115d24
undefined4 * __tf15CXenTreeTrigger(void)

{
  if (__ti15CXenTreeTrigger == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti15CXenTreeTrigger,"15CXenTreeTrigger",&__ti11CBaseEntity);
  }
  return &__ti15CXenTreeTrigger;
}


// __tf16CFuncIllusionary  @ 0008264c
undefined4 * __tf16CFuncIllusionary(void)

{
  if (__ti16CFuncIllusionary == 0) {
    __tf11CBaseToggle();
    __rtti_si(&__ti16CFuncIllusionary,"16CFuncIllusionary",&__ti11CBaseToggle);
  }
  return &__ti16CFuncIllusionary;
}


// __tf16CFuncMonsterClip  @ 00082604
undefined4 * __tf16CFuncMonsterClip(void)

{
  if (__ti16CFuncMonsterClip == 0) {
    __tf9CFuncWall();
    __rtti_si(&__ti16CFuncMonsterClip,"16CFuncMonsterClip",&__ti9CFuncWall);
  }
  return &__ti16CFuncMonsterClip;
}


// __tf16CFuncMortarField  @ 000b8560
undefined4 * __tf16CFuncMortarField(void)

{
  if (__ti16CFuncMortarField == 0) {
    __tf11CBaseToggle();
    __rtti_si(&__ti16CFuncMortarField,"16CFuncMortarField",&__ti11CBaseToggle);
  }
  return &__ti16CFuncMortarField;
}


// __tf16CFuncTrackChange  @ 000c7604
undefined4 * __tf16CFuncTrackChange(void)

{
  if (__ti16CFuncTrackChange == 0) {
    __tf12CFuncPlatRot();
    __rtti_si(&__ti16CFuncTrackChange,"16CFuncTrackChange",&__ti12CFuncPlatRot);
  }
  return &__ti16CFuncTrackChange;
}


// __tf16CItemAmmoRockets  @ 000ee068
undefined4 * __tf16CItemAmmoRockets(void)

{
  if (__ti16CItemAmmoRockets == 0) {
    __tf9CItemAmmo();
    __rtti_si(&__ti16CItemAmmoRockets,"16CItemAmmoRockets",&__ti9CItemAmmo);
  }
  return &__ti16CItemAmmoRockets;
}


// __tf16CItemArmorYellow  @ 000ee1c0
undefined4 * __tf16CItemArmorYellow(void)

{
  if (__ti16CItemArmorYellow == 0) {
    __tf10CItemArmor();
    __rtti_si(&__ti16CItemArmorYellow,"16CItemArmorYellow",&__ti10CItemArmor);
  }
  return &__ti16CItemArmorYellow;
}


// __tf16CItemPowerupQuad  @ 000eded0
void __tf16CItemPowerupQuad(void)

{
  FUN_000eded6();
  return;
}


// __tf16CRenderFxManager  @ 00106610
undefined4 * __tf16CRenderFxManager(void)

{
  if (__ti16CRenderFxManager == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti16CRenderFxManager,"16CRenderFxManager",&__ti11CBaseEntity);
  }
  return &__ti16CRenderFxManager;
}


// __tf16CTFNapalmGrenade  @ 000f22b0
undefined4 * __tf16CTFNapalmGrenade(void)

{
  if (__ti16CTFNapalmGrenade == 0) {
    __tf15CTFPrimeGrenade();
    __rtti_si(&__ti16CTFNapalmGrenade,"16CTFNapalmGrenade",&__ti15CTFPrimeGrenade);
  }
  return &__ti16CTFNapalmGrenade;
}


// __tf16CTFNormalGrenade  @ 000f2618
undefined4 * __tf16CTFNormalGrenade(void)

{
  if (__ti16CTFNormalGrenade == 0) {
    __tf15CTFPrimeGrenade();
    __rtti_si(&__ti16CTFNormalGrenade,"16CTFNormalGrenade",&__ti15CTFPrimeGrenade);
  }
  return &__ti16CTFNormalGrenade;
}


// __tf16CTFSentrygunBase  @ 000e0930
undefined4 * __tf16CTFSentrygunBase(void)

{
  if (__ti16CTFSentrygunBase == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti16CTFSentrygunBase,"16CTFSentrygunBase",&__ti11CBaseEntity);
  }
  return &__ti16CTFSentrygunBase;
}


// __tf16CTriggerMultiple  @ 00106474
undefined4 * __tf16CTriggerMultiple(void)

{
  if (__ti16CTriggerMultiple == 0) {
    __tf12CBaseTrigger();
    __rtti_si(&__ti16CTriggerMultiple,"16CTriggerMultiple",&__ti12CBaseTrigger);
  }
  return &__ti16CTriggerMultiple;
}


// __tf16CTriggerTeleport  @ 0010624c
undefined4 * __tf16CTriggerTeleport(void)

{
  if (__ti16CTriggerTeleport == 0) {
    __tf12CBaseTrigger();
    __rtti_si(&__ti16CTriggerTeleport,"16CTriggerTeleport",&__ti12CBaseTrigger);
  }
  return &__ti16CTriggerTeleport;
}


// __tf16__attr_type_info  @ 00131660
undefined4 * __tf16__attr_type_info(void)

{
  if (__ti16__attr_type_info == 0) {
    __tf9type_info();
    __rtti_si(&__ti16__attr_type_info,"16__attr_type_info",&__ti9type_info);
  }
  return &__ti16__attr_type_info;
}


// __tf16__func_type_info  @ 00131560
undefined4 * __tf16__func_type_info(void)

{
  if (__ti16__func_type_info == 0) {
    __tf9type_info();
    __rtti_si(&__ti16__func_type_info,"16__func_type_info",&__ti9type_info);
  }
  return &__ti16__func_type_info;
}


// __tf16__ptmd_type_info  @ 00131460
undefined4 * __tf16__ptmd_type_info(void)

{
  if (__ti16__ptmd_type_info == 0) {
    __tf9type_info();
    __rtti_si(&__ti16__ptmd_type_info,"16__ptmd_type_info",&__ti9type_info);
  }
  return &__ti16__ptmd_type_info;
}


// __tf16__ptmf_type_info  @ 001314e0
undefined4 * __tf16__ptmf_type_info(void)

{
  if (__ti16__ptmf_type_info == 0) {
    __tf9type_info();
    __rtti_si(&__ti16__ptmf_type_info,"16__ptmf_type_info",&__ti9type_info);
  }
  return &__ti16__ptmf_type_info;
}


// __tf16__user_type_info  @ 00127c60
undefined4 * __tf16__user_type_info(void)

{
  if (__ti16__user_type_info == 0) {
    __tf9type_info();
    __rtti_si(&__ti16__user_type_info,"16__user_type_info",&__ti9type_info);
  }
  return &__ti16__user_type_info;
}


// __tf17CBasePlayerWeapon  @ 001123e0
undefined4 * __tf17CBasePlayerWeapon(void)

{
  if (__ti17CBasePlayerWeapon == 0) {
    __tf15CBasePlayerItem();
    __rtti_si(&__ti17CBasePlayerWeapon,"17CBasePlayerWeapon",&__ti15CBasePlayerItem);
  }
  return &__ti17CBasePlayerWeapon;
}


// __tf17CFrictionModifier  @ 00106730
undefined4 * __tf17CFrictionModifier(void)

{
  if (__ti17CFrictionModifier == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti17CFrictionModifier,"17CFrictionModifier",&__ti11CBaseEntity);
  }
  return &__ti17CFrictionModifier;
}


// __tf17CFuncTankControls  @ 000a2a3c
undefined4 * __tf17CFuncTankControls(void)

{
  if (__ti17CFuncTankControls == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti17CFuncTankControls,"17CFuncTankControls",&__ti11CBaseEntity);
  }
  return &__ti17CFuncTankControls;
}


// __tf17CHalfLifeTeamplay  @ 000ea9f8
undefined4 * __tf17CHalfLifeTeamplay(void)

{
  if (__ti17CHalfLifeTeamplay == 0) {
    __tf18CHalfLifeMultiplay();
    __rtti_si(&__ti17CHalfLifeTeamplay,"17CHalfLifeTeamplay",&__ti18CHalfLifeMultiplay);
  }
  return &__ti17CHalfLifeTeamplay;
}


// __tf17CInfoIntermission  @ 000d8a7c
undefined4 * __tf17CInfoIntermission(void)

{
  if (__ti17CInfoIntermission == 0) {
    __tf12CPointEntity();
    __rtti_si(&__ti17CInfoIntermission,"17CInfoIntermission",&__ti12CPointEntity);
  }
  return &__ti17CInfoIntermission;
}


// __tf17CScriptedSentence  @ 000ddf1c
undefined4 * __tf17CScriptedSentence(void)

{
  if (__ti17CScriptedSentence == 0) {
    __tf11CBaseToggle();
    __rtti_si(&__ti17CScriptedSentence,"17CScriptedSentence",&__ti11CBaseToggle);
  }
  return &__ti17CScriptedSentence;
}


// __tf17CTFCaltropGrenade  @ 000f2188
undefined4 * __tf17CTFCaltropGrenade(void)

{
  if (__ti17CTFCaltropGrenade == 0) {
    __tf15CTFPrimeGrenade();
    __rtti_si(&__ti17CTFCaltropGrenade,"17CTFCaltropGrenade",&__ti15CTFPrimeGrenade);
  }
  return &__ti17CTFCaltropGrenade;
}


// __tf17__array_type_info  @ 001313e0
undefined4 * __tf17__array_type_info(void)

{
  if (__ti17__array_type_info == 0) {
    __tf9type_info();
    __rtti_si(&__ti17__array_type_info,"17__array_type_info",&__ti9type_info);
  }
  return &__ti17__array_type_info;
}


// __tf17__class_type_info  @ 00127ad0
undefined4 * __tf17__class_type_info(void)

{
  if (__ti17__class_type_info == 0) {
    __tf16__user_type_info();
    __rtti_si(&__ti17__class_type_info,"17__class_type_info",&__ti16__user_type_info);
  }
  return &__ti17__class_type_info;
}


// __tf18CCine2HeavyWeapons  @ 0012b318
undefined4 * __tf18CCine2HeavyWeapons(void)

{
  if (__ti18CCine2HeavyWeapons == 0) {
    __tf18CLegacyCineMonster();
    __rtti_si(&__ti18CCine2HeavyWeapons,"18CCine2HeavyWeapons",&__ti18CLegacyCineMonster);
  }
  return &__ti18CCine2HeavyWeapons;
}


// __tf18CFuncTrainControls  @ 000c764c
undefined4 * __tf18CFuncTrainControls(void)

{
  if (__ti18CFuncTrainControls == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti18CFuncTrainControls,"18CFuncTrainControls",&__ti11CBaseEntity);
  }
  return &__ti18CFuncTrainControls;
}


// __tf18CHalfLifeMultiplay  @ 000a5bd4
undefined4 * __tf18CHalfLifeMultiplay(void)

{
  if (__ti18CHalfLifeMultiplay == 0) {
    __tf10CGameRules();
    __rtti_si(&__ti18CHalfLifeMultiplay,"18CHalfLifeMultiplay",&__ti10CGameRules);
  }
  return &__ti18CHalfLifeMultiplay;
}


// __tf18CLegacyCineMonster  @ 000a94b8
undefined4 * __tf18CLegacyCineMonster(void)

{
  if (__ti18CLegacyCineMonster == 0) {
    __tf12CBaseMonster();
    __rtti_si(&__ti18CLegacyCineMonster,"18CLegacyCineMonster",&__ti12CBaseMonster);
  }
  return &__ti18CLegacyCineMonster;
}


// __tf18CTFGrenadeLauncher  @ 0011a094
undefined4 * __tf18CTFGrenadeLauncher(void)

{
  if (__ti18CTFGrenadeLauncher == 0) {
    __tf17CBasePlayerWeapon();
    __rtti_si(&__ti18CTFGrenadeLauncher,"18CTFGrenadeLauncher",&__ti17CBasePlayerWeapon);
  }
  return &__ti18CTFGrenadeLauncher;
}


// __tf18CTriggerEndSection  @ 001061c4
undefined4 * __tf18CTriggerEndSection(void)

{
  if (__ti18CTriggerEndSection == 0) {
    __tf12CBaseTrigger();
    __rtti_si(&__ti18CTriggerEndSection,"18CTriggerEndSection",&__ti12CBaseTrigger);
  }
  return &__ti18CTriggerEndSection;
}


// __tf19CItemPowerupRadsuit  @ 000edf58
undefined4 * __tf19CItemPowerupRadsuit(void)

{
  if (__ti19CItemPowerupRadsuit == 0) {
    __tf12CItemPowerup();
    __rtti_si(&__ti19CItemPowerupRadsuit,"19CItemPowerupRadsuit",&__ti12CItemPowerup);
  }
  return &__ti19CItemPowerupRadsuit;
}


// __tf19CMomentaryRotButton  @ 000858dc
undefined4 * __tf19CMomentaryRotButton(void)

{
  if (__ti19CMomentaryRotButton == 0) {
    __tf11CBaseToggle();
    __rtti_si(&__ti19CMomentaryRotButton,"19CMomentaryRotButton",&__ti11CBaseToggle);
  }
  return &__ti19CMomentaryRotButton;
}


// __tf19CTFPipebombLauncher  @ 0011a048
undefined4 * __tf19CTFPipebombLauncher(void)

{
  if (__ti19CTFPipebombLauncher == 0) {
    __tf18CTFGrenadeLauncher();
    __rtti_si(&__ti19CTFPipebombLauncher,"19CTFPipebombLauncher",&__ti18CTFGrenadeLauncher);
  }
  return &__ti19CTFPipebombLauncher;
}


// __tf19CTriggerMonsterJump  @ 00106540
void __tf19CTriggerMonsterJump(void)

{
  FUN_00106546();
  return;
}


// __tf19__builtin_type_info  @ 001315e0
undefined4 * __tf19__builtin_type_info(void)

{
  if (__ti19__builtin_type_info == 0) {
    __tf9type_info();
    __rtti_si(&__ti19__builtin_type_info,"19__builtin_type_info",&__ti9type_info);
  }
  return &__ti19__builtin_type_info;
}


// __tf19__pointer_type_info  @ 001316e0
undefined4 * __tf19__pointer_type_info(void)

{
  if (__ti19__pointer_type_info == 0) {
    __tf9type_info();
    __rtti_si(&__ti19__pointer_type_info,"19__pointer_type_info",&__ti9type_info);
  }
  return &__ti19__pointer_type_info;
}


// __tf20CTFConcussionGrenade  @ 000f24f0
undefined4 * __tf20CTFConcussionGrenade(void)

{
  if (__ti20CTFConcussionGrenade == 0) {
    __tf15CTFPrimeGrenade();
    __rtti_si(&__ti20CTFConcussionGrenade,"20CTFConcussionGrenade",&__ti15CTFPrimeGrenade);
  }
  return &__ti20CTFConcussionGrenade;
}


// __tf20CTFFlamethrowerBurst  @ 000f4c24
undefined4 * __tf20CTFFlamethrowerBurst(void)

{
  if (__ti20CTFFlamethrowerBurst == 0) {
    __tf8CGrenade();
    __rtti_si(&__ti20CTFFlamethrowerBurst,"20CTFFlamethrowerBurst",&__ti8CGrenade);
  }
  return &__ti20CTFFlamethrowerBurst;
}


// __tf20CTFIncendiaryCRocket  @ 000f4be0
undefined4 * __tf20CTFIncendiaryCRocket(void)

{
  if (__ti20CTFIncendiaryCRocket == 0) {
    __tf8CGrenade();
    __rtti_si(&__ti20CTFIncendiaryCRocket,"20CTFIncendiaryCRocket",&__ti8CGrenade);
  }
  return &__ti20CTFIncendiaryCRocket;
}


// __tf20CTriggerChangeTarget  @ 0010613c
undefined4 * __tf20CTriggerChangeTarget(void)

{
  if (__ti20CTriggerChangeTarget == 0) {
    __tf10CBaseDelay();
    __rtti_si(&__ti20CTriggerChangeTarget,"20CTriggerChangeTarget",&__ti10CBaseDelay);
  }
  return &__ti20CTriggerChangeTarget;
}


// __tf22CItemPowerupInvincible  @ 000edf9c
undefined4 * __tf22CItemPowerupInvincible(void)

{
  if (__ti22CItemPowerupInvincible == 0) {
    __tf12CItemPowerup();
    __rtti_si(&__ti22CItemPowerupInvincible,"22CItemPowerupInvincible",&__ti12CItemPowerup);
  }
  return &__ti22CItemPowerupInvincible;
}


// __tf23CDispenserRefillThinker  @ 00092e80
undefined4 * __tf23CDispenserRefillThinker(void)

{
  if (__ti23CDispenserRefillThinker == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti23CDispenserRefillThinker,"23CDispenserRefillThinker",&__ti11CBaseEntity);
  }
  return &__ti23CDispenserRefillThinker;
}


// __tf24CItemPowerupInvisibility  @ 000edf14
void __tf24CItemPowerupInvisibility(void)

{
  FUN_000edf1a();
  return;
}


// __tf4CGib  @ 001297c4
undefined4 * __tf4CGib(void)

{
  if (__ti4CGib == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti4CGib,&UNK_00133a90,&__ti11CBaseEntity);
  }
  return &__ti4CGib;
}


// __tf5CBeam  @ 0009bb28
undefined4 * __tf5CBeam(void)

{
  if (__ti5CBeam == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti5CBeam,"5CBeam",&__ti11CBaseEntity);
  }
  return &__ti5CBeam;
}


// __tf5CFade  @ 0009b3a4
undefined4 * __tf5CFade(void)

{
  if (__ti5CFade == 0) {
    __tf12CPointEntity();
    __rtti_si(&__ti5CFade,"5CFade",&__ti12CPointEntity);
  }
  return &__ti5CFade;
}


// __tf5CGlow  @ 0009b614
undefined4 * __tf5CGlow(void)

{
  if (__ti5CGlow == 0) {
    __tf12CPointEntity();
    __rtti_si(&__ti5CGlow,"5CGlow",&__ti12CPointEntity);
  }
  return &__ti5CGlow;
}


// __tf5CItem  @ 000abd24
undefined4 * __tf5CItem(void)

{
  if (__ti5CItem == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti5CItem,&UNK_00136e0f,&__ti11CBaseEntity);
  }
  return &__ti5CItem;
}


// __tf6CBlood  @ 0009b504
undefined4 * __tf6CBlood(void)

{
  if (__ti6CBlood == 0) {
    __tf12CPointEntity();
    __rtti_si(&__ti6CBlood,"6CBlood",&__ti12CPointEntity);
  }
  return &__ti6CBlood;
}


// __tf6CDecal  @ 00114210
undefined4 * __tf6CDecal(void)

{
  if (__ti6CDecal == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti6CDecal,"6CDecal",&__ti11CBaseEntity);
  }
  return &__ti6CDecal;
}


// __tf6CGhost  @ 0012d928
undefined4 * __tf6CGhost(void)

{
  if (__ti6CGhost == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti6CGhost,"6CGhost",&__ti11CBaseEntity);
  }
  return &__ti6CGhost;
}


// __tf6CLaser  @ 0009b724
undefined4 * __tf6CLaser(void)

{
  if (__ti6CLaser == 0) {
    __tf5CBeam();
    __rtti_si(&__ti6CLaser,"6CLaser",&__ti5CBeam);
  }
  return &__ti6CLaser;
}


// __tf6CLight  @ 000ac628
undefined4 * __tf6CLight(void)

{
  if (__ti6CLight == 0) {
    __tf12CPointEntity();
    __rtti_si(&__ti6CLight,"6CLight",&__ti12CPointEntity);
  }
  return &__ti6CLight;
}


// __tf6CShake  @ 0009b478
undefined4 * __tf6CShake(void)

{
  if (__ti6CShake == 0) {
    __tf12CPointEntity();
    __rtti_si(&__ti6CShake,"6CShake",&__ti12CPointEntity);
  }
  return &__ti6CShake;
}


// __tf6CTFAxe  @ 00118e0c
undefined4 * __tf6CTFAxe(void)

{
  if (__ti6CTFAxe == 0) {
    __tf8CCrowbar();
    __rtti_si(&__ti6CTFAxe,"6CTFAxe",&__ti8CCrowbar);
  }
  return &__ti6CTFAxe;
}


// __tf6CTFRpg  @ 0011bdb0
undefined4 * __tf6CTFRpg(void)

{
  if (__ti6CTFRpg == 0) {
    __tf17CBasePlayerWeapon();
    __rtti_si(&__ti6CTFRpg,"6CTFRpg",&__ti17CBasePlayerWeapon);
  }
  return &__ti6CTFRpg;
}


// __tf6CTimer  @ 0012ebfc
undefined4 * __tf6CTimer(void)

{
  if (__ti6CTimer == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti6CTimer,FUN_001406b8,&__ti11CBaseEntity);
  }
  return &__ti6CTimer;
}


// __tf6CWorld  @ 00114254
undefined4 * __tf6CWorld(void)

{
  if (__ti6CWorld == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti6CWorld,"6CWorld",&__ti11CBaseEntity);
  }
  return &__ti6CWorld;
}


// __tf7CCineAI  @ 000ddf60
undefined4 * __tf7CCineAI(void)

{
  if (__ti7CCineAI == 0) {
    __tf12CCineMonster();
    __rtti_si(&__ti7CCineAI,"7CCineAI",&__ti12CCineMonster);
  }
  return &__ti7CCineAI;
}


// __tf7CCorpse  @ 00130164
undefined4 * __tf7CCorpse(void)

{
  if (__ti7CCorpse == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti7CCorpse,"7CCorpse",&__ti11CBaseEntity);
  }
  return &__ti7CCorpse;
}


// __tf7CCycler  @ 000aa5ac
undefined4 * __tf7CCycler(void)

{
  if (__ti7CCycler == 0) {
    __tf12CBaseMonster();
    __rtti_si(&__ti7CCycler,"7CCycler",&__ti12CBaseMonster);
  }
  return &__ti7CCycler;
}


// __tf7CLadder  @ 001062d4
undefined4 * __tf7CLadder(void)

{
  if (__ti7CLadder == 0) {
    __tf12CBaseTrigger();
    __rtti_si(&__ti7CLadder,"7CLadder",&__ti12CBaseTrigger);
  }
  return &__ti7CLadder;
}


// __tf7CMortar  @ 000b8518
undefined4 * __tf7CMortar(void)

{
  if (__ti7CMortar == 0) {
    __tf8CGrenade();
    __rtti_si(&__ti7CMortar,"7CMortar",&__ti8CGrenade);
  }
  return &__ti7CMortar;
}


// __tf7CSentry  @ 00109990
undefined4 * __tf7CSentry(void)

{
  if (__ti7CSentry == 0) {
    __tf11CBaseTurret();
    __rtti_si(&__ti7CSentry,"7CSentry",&__ti11CBaseTurret);
  }
  return &__ti7CSentry;
}


// __tf7CShower  @ 0009d6f8
undefined4 * __tf7CShower(void)

{
  if (__ti7CShower == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti7CShower,"7CShower",&__ti11CBaseEntity);
  }
  return &__ti7CShower;
}


// __tf7CSprite  @ 0009bd04
undefined4 * __tf7CSprite(void)

{
  if (__ti7CSprite == 0) {
    __tf12CPointEntity();
    __rtti_si(&__ti7CSprite,"7CSprite",&__ti12CPointEntity);
  }
  return &__ti7CSprite;
}


// __tf7CTFGoal  @ 00100048
undefined4 * __tf7CTFGoal(void)

{
  if (__ti7CTFGoal == 0) {
    __tf14CBaseAnimating();
    __rtti_si(&__ti7CTFGoal,"7CTFGoal",&__ti14CBaseAnimating);
  }
  return &__ti7CTFGoal;
}


// __tf7CTurret  @ 00109a18
undefined4 * __tf7CTurret(void)

{
  if (__ti7CTurret == 0) {
    __tf11CBaseTurret();
    __rtti_si(&__ti7CTurret,"7CTurret",&__ti11CBaseTurret);
  }
  return &__ti7CTurret;
}


// __tf8CAirtank  @ 0007f4c4
undefined4 * __tf8CAirtank(void)

{
  if (__ti8CAirtank == 0) {
    __tf8CGrenade();
    __rtti_si(&__ti8CAirtank,"8CAirtank",&__ti8CGrenade);
  }
  return &__ti8CAirtank;
}


// __tf8CCrowbar  @ 000900a0
undefined4 * __tf8CCrowbar(void)

{
  if (__ti8CCrowbar == 0) {
    __tf17CBasePlayerWeapon();
    __rtti_si(&__ti8CCrowbar,"8CCrowbar",&__ti17CBasePlayerWeapon);
  }
  return &__ti8CCrowbar;
}


// __tf8CDeadHEV  @ 000d8bd0
undefined4 * __tf8CDeadHEV(void)

{
  if (__ti8CDeadHEV == 0) {
    __tf12CBaseMonster();
    __rtti_si(&__ti8CDeadHEV,"8CDeadHEV",&__ti12CBaseMonster);
  }
  return &__ti8CDeadHEV;
}


// __tf8CDetpack  @ 00091738
undefined4 * __tf8CDetpack(void)

{
  if (__ti8CDetpack == 0) {
    __tf8CGrenade();
    __rtti_si(&__ti8CDetpack,"8CDetpack",&__ti8CGrenade);
  }
  return &__ti8CDetpack;
}


// __tf8CGrenade  @ 000a7b18
undefined4 * __tf8CGrenade(void)

{
  if (__ti8CGrenade == 0) {
    __tf12CBaseMonster();
    __rtti_si(&__ti8CGrenade,"8CGrenade",&__ti12CBaseMonster);
  }
  return &__ti8CGrenade;
}


// __tf8CMessage  @ 0009b318
undefined4 * __tf8CMessage(void)

{
  if (__ti8CMessage == 0) {
    __tf12CPointEntity();
    __rtti_si(&__ti8CMessage,"8CMessage",&__ti12CPointEntity);
  }
  return &__ti8CMessage;
}


// __tf8CNodeEnt  @ 000c0c0c
undefined4 * __tf8CNodeEnt(void)

{
  if (__ti8CNodeEnt == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti8CNodeEnt,"8CNodeEnt",&__ti11CBaseEntity);
  }
  return &__ti8CNodeEnt;
}


// __tf8CRotDoor  @ 00095540
undefined4 * __tf8CRotDoor(void)

{
  if (__ti8CRotDoor == 0) {
    __tf9CBaseDoor();
    __rtti_si(&__ti8CRotDoor,"8CRotDoor",&__ti9CBaseDoor);
  }
  return &__ti8CRotDoor;
}


// __tf8CSpeaker  @ 000e3d2c
undefined4 * __tf8CSpeaker(void)

{
  if (__ti8CSpeaker == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti8CSpeaker,"8CSpeaker",&__ti11CBaseEntity);
  }
  return &__ti8CSpeaker;
}


// __tf8CTFFlame  @ 000d957c
undefined4 * __tf8CTFFlame(void)

{
  if (__ti8CTFFlame == 0) {
    __tf12CBaseMonster();
    __rtti_si(&__ti8CTFFlame,"8CTFFlame",&__ti12CBaseMonster);
  }
  return &__ti8CTFFlame;
}


// __tf8CTFKnife  @ 00118db8
undefined4 * __tf8CTFKnife(void)

{
  if (__ti8CTFKnife == 0) {
    __tf6CTFAxe();
    __rtti_si(&__ti8CTFKnife,"8CTFKnife",&__ti6CTFAxe);
  }
  return &__ti8CTFKnife;
}


// __tf8CTFSpawn  @ 000fff64
undefined4 * __tf8CTFSpawn(void)

{
  if (__ti8CTFSpawn == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti8CTFSpawn,"8CTFSpawn",&__ti11CBaseEntity);
  }
  return &__ti8CTFSpawn;
}


// __tf8CTFTranq  @ 0011e0e0
undefined4 * __tf8CTFTranq(void)

{
  if (__ti8CTFTranq == 0) {
    __tf17CBasePlayerWeapon();
    __rtti_si(&__ti8CTFTranq,"8CTFTranq",&__ti17CBasePlayerWeapon);
  }
  return &__ti8CTFTranq;
}


// __tf8CXenHair  @ 00115d68
undefined4 * __tf8CXenHair(void)

{
  if (__ti8CXenHair == 0) {
    __tf13CActAnimating();
    __rtti_si(&__ti8CXenHair,"8CXenHair",&__ti13CActAnimating);
  }
  return &__ti8CXenHair;
}


// __tf8CXenHull  @ 001306b8
undefined4 * __tf8CXenHull(void)

{
  if (__ti8CXenHull == 0) {
    __tf12CPointEntity();
    __rtti_si(&__ti8CXenHull,"8CXenHull",&__ti12CPointEntity);
  }
  return &__ti8CXenHull;
}


// __tf8CXenTree  @ 00115ce0
undefined4 * __tf8CXenTree(void)

{
  if (__ti8CXenTree == 0) {
    __tf13CActAnimating();
    __rtti_si(&__ti8CXenTree,"8CXenTree",&__ti13CActAnimating);
  }
  return &__ti8CXenTree;
}


// __tf8bad_cast  @ 00127e10
undefined4 * __tf8bad_cast(void)

{
  if (__ti8bad_cast == 0) {
    __tf9exception();
    __rtti_si(&__ti8bad_cast,"8bad_cast",&__ti9exception);
  }
  return &__ti8bad_cast;
}


// __tf9CBaseDoor  @ 000955a0
undefined4 * __tf9CBaseDoor(void)

{
  if (__ti9CBaseDoor == 0) {
    __tf11CBaseToggle();
    __rtti_si(&__ti9CBaseDoor,"9CBaseDoor",&__ti11CBaseToggle);
  }
  return &__ti9CBaseDoor;
}


// __tf9CBubbling  @ 0009b6e0
undefined4 * __tf9CBubbling(void)

{
  if (__ti9CBubbling == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti9CBubbling,"9CBubbling",&__ti11CBaseEntity);
  }
  return &__ti9CBubbling;
}


// __tf9CEnvLight  @ 000ac5e4
undefined4 * __tf9CEnvLight(void)

{
  if (__ti9CEnvLight == 0) {
    __tf6CLight();
    __rtti_si(&__ti9CEnvLight,"9CEnvLight",&__ti6CLight);
  }
  return &__ti9CEnvLight;
}


// __tf9CEnvSound  @ 000e3d70
undefined4 * __tf9CEnvSound(void)

{
  if (__ti9CEnvSound == 0) {
    __tf12CPointEntity();
    __rtti_si(&__ti9CEnvSound,"9CEnvSound",&__ti12CPointEntity);
  }
  return &__ti9CEnvSound;
}


// __tf9CEnvSpark  @ 0008586c
undefined4 * __tf9CEnvSpark(void)

{
  if (__ti9CEnvSpark == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti9CEnvSpark,"9CEnvSpark",&__ti11CBaseEntity);
  }
  return &__ti9CEnvSpark;
}


// __tf9CFuncPlat  @ 000c77dc
undefined4 * __tf9CFuncPlat(void)

{
  if (__ti9CFuncPlat == 0) {
    __tf14CBasePlatTrain();
    __rtti_si(&__ti9CFuncPlat,"9CFuncPlat",&__ti14CBasePlatTrain);
  }
  return &__ti9CFuncPlat;
}


// __tf9CFuncTank  @ 000a2ddc
undefined4 * __tf9CFuncTank(void)

{
  if (__ti9CFuncTank == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti9CFuncTank,"9CFuncTank",&__ti11CBaseEntity);
  }
  return &__ti9CFuncTank;
}


// __tf9CFuncWall  @ 0008271c
undefined4 * __tf9CFuncWall(void)

{
  if (__ti9CFuncWall == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti9CFuncWall,"9CFuncWall",&__ti11CBaseEntity);
  }
  return &__ti9CFuncWall;
}


// __tf9CItemAmmo  @ 000ee138
undefined4 * __tf9CItemAmmo(void)

{
  if (__ti9CItemAmmo == 0) {
    __tf5CItem();
    __rtti_si(&__ti9CItemAmmo,"9CItemAmmo",&__ti5CItem);
  }
  return &__ti9CItemAmmo;
}


// __tf9CItemSoda  @ 0009b24c
undefined4 * __tf9CItemSoda(void)

{
  if (__ti9CItemSoda == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti9CItemSoda,"9CItemSoda",&__ti11CBaseEntity);
  }
  return &__ti9CItemSoda;
}


// __tf9CItemSuit  @ 0012c404
undefined4 * __tf9CItemSuit(void)

{
  if (__ti9CItemSuit == 0) {
    __tf5CItem();
    __rtti_si(&__ti9CItemSuit,"9CItemSuit",&__ti5CItem);
  }
  return &__ti9CItemSuit;
}


// __tf9CPendulum  @ 00082574
undefined4 * __tf9CPendulum(void)

{
  if (__ti9CPendulum == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti9CPendulum,"9CPendulum",&__ti11CBaseEntity);
  }
  return &__ti9CPendulum;
}


// __tf9CPushable  @ 0009f85c
undefined4 * __tf9CPushable(void)

{
  if (__ti9CPushable == 0) {
    __tf10CBreakable();
    __rtti_si(&__ti9CPushable,"9CPushable",&__ti10CBreakable);
  }
  return &__ti9CPushable;
}


// __tf9CRecharge  @ 000a8ca8
undefined4 * __tf9CRecharge(void)

{
  if (__ti9CRecharge == 0) {
    __tf11CBaseToggle();
    __rtti_si(&__ti9CRecharge,"9CRecharge",&__ti11CBaseToggle);
  }
  return &__ti9CRecharge;
}


// __tf9CSoundEnt  @ 000e44dc
undefined4 * __tf9CSoundEnt(void)

{
  if (__ti9CSoundEnt == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti9CSoundEnt,"9CSoundEnt",&__ti11CBaseEntity);
  }
  return &__ti9CSoundEnt;
}


// __tf9CSprayCan  @ 000d8c1c
undefined4 * __tf9CSprayCan(void)

{
  if (__ti9CSprayCan == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti9CSprayCan,"9CSprayCan",&__ti11CBaseEntity);
  }
  return &__ti9CSprayCan;
}


// __tf9CTFDetect  @ 000fff18
undefined4 * __tf9CTFDetect(void)

{
  if (__ti9CTFDetect == 0) {
    __tf11CBaseEntity();
    __rtti_si(&__ti9CTFDetect,FUN_00141630,&__ti11CBaseEntity);
  }
  return &__ti9CTFDetect;
}


// __tf9CTestHull  @ 0012c820
undefined4 * __tf9CTestHull(void)

{
  if (__ti9CTestHull == 0) {
    __tf12CBaseMonster();
    __rtti_si(&__ti9CTestHull,"9CTestHull",&__ti12CBaseMonster);
  }
  return &__ti9CTestHull;
}


// __tf9CWreckage  @ 000aa43c
undefined4 * __tf9CWreckage(void)

{
  if (__ti9CWreckage == 0) {
    __tf12CBaseMonster();
    __rtti_si(&__ti9CWreckage,"9CWreckage",&__ti12CBaseMonster);
  }
  return &__ti9CWreckage;
}


// __tf9CXenSpore  @ 00115c74
undefined4 * __tf9CXenSpore(void)

{
  if (__ti9CXenSpore == 0) {
    __tf13CActAnimating();
    __rtti_si(&__ti9CXenSpore,"9CXenSpore",&__ti13CActAnimating);
  }
  return &__ti9CXenSpore;
}


// __tf9bad_alloc  @ 00128bf0
undefined4 * __tf9bad_alloc(void)

{
  if (__ti9bad_alloc == 0) {
    __tf9exception();
    __rtti_si(&__ti9bad_alloc,"9bad_alloc",&__ti9exception);
  }
  return &__ti9bad_alloc;
}


// __tf9exception  @ 00127380
undefined4 * __tf9exception(void)

{
  if (__ti9exception == 0) {
    __rtti_user(&__ti9exception,"9exception");
  }
  return &__ti9exception;
}


// __tf9type_info  @ 00127ed0
undefined4 * __tf9type_info(void)

{
  if (__ti9type_info == 0) {
    __rtti_user(&__ti9type_info,"9type_info");
  }
  return &__ti9type_info;
}


// __tfSc  @ 00128b10
undefined4 * __tfSc(void)

{
  if (__tiSc == (undefined *)0x0) {
    __tiSc = &DAT_00145963;
    DAT_001b7dc8 = __vt_19__builtin_type_info;
  }
  return &__tiSc;
}


// __tfUc  @ 00128ac0
undefined4 * __tfUc(void)

{
  if (__tiUc == (undefined *)0x0) {
    __tiUc = &DAT_00145960;
    DAT_001b7dc0 = __vt_19__builtin_type_info;
  }
  return &__tiUc;
}


// __tfUi  @ 00128980
undefined4 * __tfUi(void)

{
  if (__tiUi == (undefined *)0x0) {
    __tiUi = &DAT_00145954;
    DAT_001b7da0 = __vt_19__builtin_type_info;
  }
  return &__tiUi;
}


// __tfUl  @ 001289d0
undefined4 * __tfUl(void)

{
  if (__tiUl == (undefined *)0x0) {
    __tiUl = &DAT_00145957;
    DAT_001b7da8 = __vt_19__builtin_type_info;
  }
  return &__tiUl;
}


// __tfUs  @ 00128a70
undefined4 * __tfUs(void)

{
  if (__tiUs == (undefined *)0x0) {
    __tiUs = &DAT_0014595d;
    DAT_001b7db8 = __vt_19__builtin_type_info;
  }
  return &__tiUs;
}


// __tfUx  @ 00128a20
undefined4 * __tfUx(void)

{
  if (__tiUx == (undefined *)0x0) {
    __tiUx = &DAT_0014595a;
    DAT_001b7db0 = __vt_19__builtin_type_info;
  }
  return &__tiUx;
}


// __tfb  @ 001287a0
undefined4 * __tfb(void)

{
  if (__tib == (undefined *)0x0) {
    __tib = &DAT_00145948;
    DAT_001b7d70 = __vt_19__builtin_type_info;
  }
  return &__tib;
}


// __tfc  @ 001287f0
undefined4 * __tfc(void)

{
  if (__tic == (undefined *)0x0) {
    __tic = &DAT_0014594a;
    DAT_001b7d78 = __vt_19__builtin_type_info;
  }
  return &__tic;
}


// __tfd  @ 001288e0
undefined4 * __tfd(void)

{
  if (__tid == (undefined *)0x0) {
    __tid = &DAT_00145950;
    DAT_001b7d90 = __vt_19__builtin_type_info;
  }
  return &__tid;
}


// __tff  @ 00128930
undefined4 * __tff(void)

{
  if (__tif == (undefined *)0x0) {
    __tif = &DAT_00145952;
    DAT_001b7d98 = __vt_19__builtin_type_info;
  }
  return &__tif;
}


// __tfi  @ 00128700
undefined4 * __tfi(void)

{
  if (__tii == (undefined *)0x0) {
    __tii = &DAT_00145944;
    DAT_001b7d60 = __vt_19__builtin_type_info;
  }
  return &__tii;
}


// __tfl  @ 001286b0
undefined4 * __tfl(void)

{
  if (__til == (undefined *)0x0) {
    __til = &DAT_00145942;
    DAT_001b7d58 = __vt_19__builtin_type_info;
  }
  return &__til;
}


// __tfr  @ 00128890
undefined4 * __tfr(void)

{
  if (__tir == (undefined *)0x0) {
    __tir = &DAT_0014594e;
    DAT_001b7d88 = __vt_19__builtin_type_info;
  }
  return &__tir;
}


// __tfs  @ 00128750
undefined4 * __tfs(void)

{
  if (__tis == (undefined *)0x0) {
    __tis = &DAT_00145946;
    DAT_001b7d68 = __vt_19__builtin_type_info;
  }
  return &__tis;
}


// __tfv  @ 00128610
undefined4 * __tfv(void)

{
  if (__tiv == (undefined *)0x0) {
    __tiv = &DAT_0014593e;
    DAT_001b7d48 = __vt_19__builtin_type_info;
  }
  return &__tiv;
}


// __tfw  @ 00128840
undefined4 * __tfw(void)

{
  if (__tiw == (undefined *)0x0) {
    __tiw = &DAT_0014594c;
    DAT_001b7d80 = __vt_19__builtin_type_info;
  }
  return &__tiw;
}


// __tfx  @ 00128660
undefined4 * __tfx(void)

{
  if (__tix == (undefined *)0x0) {
    __tix = &DAT_00145940;
    DAT_001b7d50 = __vt_19__builtin_type_info;
  }
  return &__tix;
}


// __throw  @ 00126740
int * __throw(void)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  int *piVar7;
  int *piVar8;
  int unaff_retaddr;
  uint uStack_180;
  uint uStack_178;
  int *piStack_16c;
  int *piStack_168;
  int *piStack_164;
  int iStack_160;
  int aiStack_154 [22];
  ushort uStack_fa;
  char acStack_f8 [20];
  int aiStack_e4 [28];
  undefined1 auStack_74 [112];
  
  piVar1 = (int *)(*(code *)get_eh_context)();
  piStack_16c = aiStack_e4;
  if (piVar1[2] == 0) {
    __terminate();
  }
  piStack_168 = (int *)__frame_state_for(0x126792,auStack_74);
  if (piStack_168 == (int *)0x0) {
    __terminate();
  }
  if ((short)piStack_168[0x16] == 5) {
    *piStack_168 = (int)&stack0xfffffffc;
  }
  else {
    *piStack_168 = (int)&stack0xfffffe68;
  }
  piStack_164 = (int *)0x0;
  *piStack_168 = *piStack_168 + piStack_168[2];
  piVar2 = piStack_168;
  piVar7 = aiStack_154;
  for (iVar4 = 0x1c; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar7 = *piVar2;
    piVar2 = piVar2 + 1;
    piVar7 = piVar7 + 1;
  }
  iVar4 = unaff_retaddr + -1;
  iStack_160 = iVar4;
  while( true ) {
    piVar2 = (int *)next_stack_level(iStack_160,piStack_168,piStack_16c);
    piStack_16c = piStack_168;
    if (piVar2 == (int *)0x0) break;
    piVar7 = (int *)piVar2[1];
    if (piVar7 == (int *)0x0) {
      uStack_178 = 0;
LAB_0012689a:
      piStack_164 = (int *)old_find_exception_handler(iStack_160,piVar7);
    }
    else {
      uStack_178 = (uint)(*piVar7 == -2);
      if (uStack_178 == 0) goto LAB_0012689a;
      piStack_164 = (int *)find_exception_handler(iStack_160,piVar7,piVar1[2]);
    }
    if (piStack_164 != (int *)0x0) break;
    iStack_160 = get_reg(*(undefined2 *)((int)piVar2 + 0x5a),piVar2,piStack_168);
    iStack_160 = iStack_160 + -1;
    piStack_168 = piVar2;
  }
  if (piStack_164 == (int *)0x0) {
    __terminate();
  }
  *piVar1 = (int)piStack_164;
  if (iStack_160 != iVar4) {
    piVar7 = aiStack_154;
    piVar8 = piVar2;
    for (iVar5 = 0x1c; iVar5 != 0; iVar5 = iVar5 + -1) {
      *piVar8 = *piVar7;
      piVar7 = piVar7 + 1;
      piVar8 = piVar8 + 1;
    }
    for (; piVar7 = piVar2, iVar4 != iStack_160; iVar4 = iVar4 + -1) {
      piVar2 = (int *)next_stack_level(iVar4,piVar7,piStack_168);
      uStack_180 = 0;
      uVar3 = (uint)*(ushort *)((int)piVar2 + 0x5a);
      do {
        if ((uStack_180 != uVar3) && (*(char *)(uStack_180 + 0x5c + (int)piVar2) != '\0')) {
          copy_reg(uStack_180,piVar2,aiStack_154);
          uVar3 = (uint)*(ushort *)((int)piVar2 + 0x5a);
        }
        uStack_180 = uStack_180 + 1;
      } while ((int)uStack_180 < 0x11);
      iVar4 = get_reg(uVar3,piVar2,piVar7);
      piStack_168 = piVar7;
    }
  }
  if (uStack_178 == 0) {
    puVar6 = &UNK_00126a90;
  }
  else {
    puVar6 = &UNK_00126a70;
  }
  if (*(char *)(uStack_fa + 0x5c + (int)aiStack_154) == '\x01') {
    put_reg((uint)uStack_fa,puVar6,aiStack_154);
  }
  if (uStack_178 != 0) {
    piStack_164 = piVar1;
  }
  return piStack_164;
}


// __throw_bad_cast  @ 001270a0
void __throw_bad_cast(void)

{
  code *pcVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined **ppuVar4;
  undefined1 *puVar5;
  
  ppuVar4 = &__DT_PLTGOT;
  piVar2 = (int *)__eh_alloc(4);
  *piVar2 = (int)__vt_9exception;
  *piVar2 = (int)__vt_8bad_cast;
  puVar5 = &stack0xfffffff0;
  do {
    *(undefined **)(puVar5 + -4) = ppuVar4[0x8e7];
    pcVar1 = *(code **)(*piVar2 + 4);
    *(undefined4 *)(puVar5 + -8) = 0x127120;
    uVar3 = (*pcVar1)();
    *(undefined4 *)(puVar5 + -8) = uVar3;
    *(int **)(puVar5 + -0xc) = piVar2;
    *(undefined4 *)(puVar5 + -0x10) = 0x127127;
    __cp_push_exception();
    *(undefined4 *)(puVar5 + -0x10) = 0x12712c;
    __throw();
    *(undefined4 *)(puVar5 + -0x10) = 0x127135;
    ppuVar4 = (undefined **)(*(int *)(puVar5 + -0x10) + 0x7df2f);
    *(undefined4 *)(puVar5 + -0x10) = 0x1270f5;
    __throw();
    puVar5 = puVar5 + -0xc;
  } while( true );
}


// __throw_bad_typeid  @ 00127150
void __throw_bad_typeid(void)

{
  code *pcVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined **ppuVar4;
  undefined1 *puVar5;
  
  ppuVar4 = &__DT_PLTGOT;
  piVar2 = (int *)__eh_alloc(4);
  *piVar2 = (int)__vt_9exception;
  *piVar2 = (int)__vt_10bad_typeid;
  puVar5 = &stack0xfffffff0;
  do {
    *(undefined **)(puVar5 + -4) = ppuVar4[0x8e9];
    pcVar1 = *(code **)(*piVar2 + 4);
    *(undefined4 *)(puVar5 + -8) = 0x1271d0;
    uVar3 = (*pcVar1)();
    *(undefined4 *)(puVar5 + -8) = uVar3;
    *(int **)(puVar5 + -0xc) = piVar2;
    *(undefined4 *)(puVar5 + -0x10) = 0x1271d7;
    __cp_push_exception();
    *(undefined4 *)(puVar5 + -0x10) = 0x1271dc;
    __throw();
    *(undefined4 *)(puVar5 + -0x10) = 0x1271e5;
    ppuVar4 = (undefined **)(*(int *)(puVar5 + -0x10) + 0x7de7f);
    *(undefined4 *)(puVar5 + -0x10) = 0x1271a5;
    __throw();
    puVar5 = puVar5 + -0xc;
  } while( true );
}


// __throw_type_match  @ 00126040
undefined4 __throw_type_match(char *param_1,char *param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = strcmp(param_1,param_2);
  if (iVar1 != 0) {
    param_3 = 0;
  }
  return param_3;
}


// __throw_type_match_rtti  @ 00127f40
undefined4 __throw_type_match_rtti(int param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  char cStack_15;
  char cStack_14;
  uint uStack_10;
  int iStack_c;
  
  cVar1 = __eq__C9type_infoRC9type_info(param_1,param_2);
  if (cVar1 != '\0') {
    return param_3;
  }
  if ((param_2 == 0) ||
     (iVar2 = __dynamic_cast((*(int **)(param_2 + 4))[1],__tf16__user_type_info,1,
                             param_2 + **(int **)(param_2 + 4),__tf9type_info,param_2), iVar2 == 0))
  {
    if (param_2 == 0) {
      return 0;
    }
    iVar2 = __dynamic_cast((*(int **)(param_2 + 4))[1],__tf19__pointer_type_info,1,
                           param_2 + **(int **)(param_2 + 4),__tf9type_info,param_2);
    if (iVar2 == 0) {
      return 0;
    }
    if (param_1 == 0) {
      return 0;
    }
    iVar3 = __dynamic_cast((*(int **)(param_1 + 4))[1],__tf19__pointer_type_info,1,
                           param_1 + **(int **)(param_1 + 4),__tf9type_info,param_1);
    if (iVar3 == 0) {
      return 0;
    }
    iVar6 = *(int *)(iVar2 + 8);
    iStack_c = *(int *)(iVar3 + 8);
    if ((iVar6 == 0) ||
       (iVar2 = __dynamic_cast(*(undefined4 *)(*(int *)(iVar6 + 4) + 4),__tf16__attr_type_info,1,
                               iVar6 + **(int **)(iVar6 + 4),__tf9type_info,iVar6), iVar2 == 0)) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(uint *)(iVar2 + 0xc);
      iVar6 = *(int *)(iVar2 + 8);
    }
    if ((iStack_c == 0) ||
       (iVar2 = __dynamic_cast(*(undefined4 *)(*(int *)(iStack_c + 4) + 4),__tf16__attr_type_info,1,
                               iStack_c + **(int **)(iStack_c + 4),__tf9type_info,iStack_c),
       iVar2 == 0)) {
      uStack_10 = 0;
    }
    else {
      uStack_10 = *(uint *)(iVar2 + 0xc);
      iStack_c = *(int *)(iVar2 + 8);
    }
    if ((uStack_10 & 1) < (uVar5 & 1)) {
      return 0;
    }
    if ((uStack_10 & 2) < (uVar5 & 2)) {
      return 0;
    }
    cVar1 = __eq__C9type_infoRC9type_info(iStack_c,iVar6);
    if (cVar1 != '\0') {
      return param_3;
    }
    uVar4 = __tfv();
    cVar1 = __eq__C9type_infoRC9type_info(iStack_c,uVar4);
    if (cVar1 != '\0') {
      if (iVar6 == 0) {
        return param_3;
      }
      iVar2 = __dynamic_cast(*(undefined4 *)(*(int *)(iVar6 + 4) + 4),__tf16__func_type_info,1,
                             iVar6 + **(int **)(iVar6 + 4),__tf9type_info,iVar6);
      if (iVar2 == 0) {
        return param_3;
      }
    }
    if ((iVar6 == 0) ||
       (iVar2 = __dynamic_cast(*(undefined4 *)(*(int *)(iVar6 + 4) + 4),__tf16__user_type_info,1,
                               iVar6 + **(int **)(iVar6 + 4),__tf9type_info,iVar6), iVar2 == 0)) {
      if (iVar6 == 0) {
        return 0;
      }
      iVar2 = __dynamic_cast(*(undefined4 *)(*(int *)(iVar6 + 4) + 4),__tf19__pointer_type_info,1,
                             iVar6 + **(int **)(iVar6 + 4),__tf9type_info,iVar6);
      if (iVar2 == 0) {
        return 0;
      }
      if (iStack_c == 0) {
        return 0;
      }
      iVar3 = __dynamic_cast(*(undefined4 *)(*(int *)(iStack_c + 4) + 4),__tf19__pointer_type_info,1
                             ,iStack_c + **(int **)(iStack_c + 4),__tf9type_info,iStack_c);
      if (iVar3 == 0) {
        return 0;
      }
      cStack_14 = (char)(uStack_10 & 1);
      cStack_15 = cStack_14;
      while( true ) {
        iStack_c = *(int *)(iVar3 + 8);
        iVar2 = *(int *)(iVar2 + 8);
        if ((iVar2 == 0) ||
           (iVar3 = __dynamic_cast(*(undefined4 *)(*(int *)(iVar2 + 4) + 4),__tf16__attr_type_info,1
                                   ,iVar2 + **(int **)(iVar2 + 4),__tf9type_info,iVar2), iVar3 == 0)
           ) {
          uVar5 = 0;
        }
        else {
          uVar5 = *(uint *)(iVar3 + 0xc);
          iVar2 = *(int *)(iVar3 + 8);
        }
        if ((iStack_c == 0) ||
           (iVar3 = __dynamic_cast(*(undefined4 *)(*(int *)(iStack_c + 4) + 4),
                                   __tf16__attr_type_info,1,iStack_c + **(int **)(iStack_c + 4),
                                   __tf9type_info,iStack_c), iVar3 == 0)) {
          uStack_10 = 0;
        }
        else {
          uStack_10 = *(uint *)(iVar3 + 0xc);
          iStack_c = *(int *)(iVar3 + 8);
        }
        if ((uStack_10 & 1) < (uVar5 & 1)) {
          return 0;
        }
        if ((uStack_10 & 2) < (uVar5 & 2)) {
          return 0;
        }
        if (cStack_15 == '\0') {
          if ((uVar5 & 1) < (uStack_10 & 1)) {
            return 0;
          }
          if ((uVar5 & 2) < (uStack_10 & 2)) {
            return 0;
          }
        }
        cVar1 = __eq__C9type_infoRC9type_info(iStack_c,iVar2);
        if (cVar1 != '\0') {
          return param_3;
        }
        if (iStack_c == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = __dynamic_cast(*(undefined4 *)(*(int *)(iStack_c + 4) + 4),
                                 __tf19__pointer_type_info,1,iStack_c + **(int **)(iStack_c + 4),
                                 __tf9type_info,iStack_c);
        }
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = __dynamic_cast(*(undefined4 *)(*(int *)(iVar2 + 4) + 4),__tf19__pointer_type_info,
                                 1,iVar2 + **(int **)(iVar2 + 4),__tf9type_info,iVar2);
        }
        if (iVar3 == 0) break;
        if (iVar2 == 0) {
          return 0;
        }
        if ((((byte)uStack_10 ^ 1) & 1) != 0) {
          cStack_15 = '\0';
        }
      }
      return 0;
    }
    iVar3 = *(int *)(iVar2 + 4);
    param_1 = iStack_c;
  }
  else {
    iVar3 = *(int *)(iVar2 + 4);
  }
  uVar4 = (**(code **)(iVar3 + 0xc))(iVar2,param_1,1,param_3,0,0);
  return uVar4;
}


// __uncatch_exception  @ 00126e50
void __uncatch_exception(void)

{
  int iVar1;
  
  iVar1 = __cp_eh_info();
  if (iVar1 == 0) {
    iVar1 = terminate__Fv();
  }
  *(undefined1 *)(iVar1 + 0x14) = 0;
  return;
}


// __vn__FUiPv  @ 00128b90
undefined4 __vn__FUiPv(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}


// _fini  @ 00131760
void _fini(void)

{
  undefined4 in_EDX;
  
  gcc2_compiled_(in_EDX,0x131775);
  return;
}


// _init  @ 0007a1b0
int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  __gmon_start__();
  frame_dummy();
  iVar1 = gcc2_compiled_();
  return iVar1;
}


// _rotr  @ 0010cf90
uint _rotr(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  param_2 = param_2 & 0x1f;
  uVar2 = param_2 - 1;
  if (param_2 != 0) {
    uVar1 = ~uVar2 & 3;
    if (uVar1 != 0) {
      if (uVar1 < 3) {
        if (uVar1 < 2) {
          uVar2 = param_1 & 1;
          param_1 = param_1 >> 1;
          if (uVar2 != 0) {
            param_1 = param_1 | 0x80000000;
          }
          uVar2 = param_2 - 2;
        }
        uVar1 = param_1 & 1;
        param_1 = param_1 >> 1;
        if (uVar1 != 0) {
          param_1 = param_1 | 0x80000000;
        }
        uVar2 = uVar2 - 1;
      }
      uVar1 = param_1 & 1;
      param_1 = param_1 >> 1;
      if (uVar1 != 0) {
        param_1 = param_1 | 0x80000000;
      }
      bVar4 = uVar2 == 0;
      uVar2 = uVar2 - 1;
      if (bVar4) {
        return param_1;
      }
    }
    do {
      uVar1 = param_1 >> 1;
      if ((param_1 & 1) != 0) {
        uVar1 = uVar1 | 0x80000000;
      }
      uVar3 = uVar1 >> 1;
      if ((uVar1 & 1) != 0) {
        uVar3 = uVar3 | 0x80000000;
      }
      uVar1 = uVar3 >> 1;
      if ((uVar3 & 1) != 0) {
        uVar1 = uVar1 | 0x80000000;
      }
      param_1 = uVar1 >> 1;
      if ((uVar1 & 1) != 0) {
        param_1 = param_1 | 0x80000000;
      }
      uVar2 = uVar2 - 4;
    } while (uVar2 != 0xffffffff);
  }
  return param_1;
}


