// AdjustPointer  @ 100ad4c0
/* Library Function - Single Match
    void * __cdecl AdjustPointer(void *,struct PMD const &)
   
   Library: Visual Studio 1998 Release */

void * __cdecl AdjustPointer(void *param_1,PMD *param_2)

{
  int iVar1;
  void *pvVar2;
  
  pvVar2 = (void *)(*(int *)param_2 + (int)param_1);
  iVar1 = *(int *)(param_2 + 4);
  if (-1 < iVar1) {
    pvVar2 = (void *)((int)pvVar2 +
                     iVar1 + *(int *)(*(int *)((int)param_1 + iVar1) + *(int *)(param_2 + 8)));
  }
  return pvVar2;
}


// BuildCatchObject  @ 100ad240
/* Library Function - Single Match
    void __cdecl BuildCatchObject(struct EHExceptionRecord *,struct EHRegistrationNode *,struct
   _s_HandlerType const *,struct _s_CatchableType const *)
   
   Library: Visual Studio 1998 Release */

void __cdecl
BuildCatchObject(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_s_HandlerType *param_3,
                _s_CatchableType *param_4)

{
  EHRegistrationNode *_Dst;
  int iVar1;
  void *pvVar2;
  undefined4 *unaff_FS_OFFSET;
  size_t _Size;
  undefined4 uVar3;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_100ba6d8;
  puStack_10 = &LAB_100ac8a4;
  *unaff_FS_OFFSET = &local_14;
  if (((*(int *)(param_3 + 4) != 0) && (*(char *)(*(int *)(param_3 + 4) + 8) != '\0')) &&
     (*(int *)(param_3 + 8) != 0)) {
    _Dst = param_2 + *(int *)(param_3 + 8) + 0xc;
    local_8 = 0;
    if (((byte)*param_3 & 8) == 0) {
      if (((byte)*param_4 & 1) == 0) {
        if (*(int *)(param_4 + 0x18) == 0) {
          iVar1 = _ValidateRead(*(void **)(param_1 + 0x18),1);
          if ((iVar1 != 0) && (iVar1 = _ValidateWrite(_Dst,1), iVar1 != 0)) {
            _Size = *(size_t *)(param_4 + 0x14);
            pvVar2 = AdjustPointer(*(void **)(param_1 + 0x18),(PMD *)(param_4 + 8));
            FID_conflict__memcpy(_Dst,pvVar2,_Size);
            goto LAB_100ad42e;
          }
        }
        else {
          iVar1 = _ValidateRead(*(void **)(param_1 + 0x18),1);
          if (((iVar1 != 0) && (iVar1 = _ValidateWrite(_Dst,1), iVar1 != 0)) &&
             (iVar1 = _ValidateExecute(*(_func_int **)(param_4 + 0x18)), iVar1 != 0)) {
            if (((byte)*param_4 & 4) == 0) {
              pvVar2 = AdjustPointer(*(void **)(param_1 + 0x18),(PMD *)(param_4 + 8));
              FID_conflict__CallMemberFunction1(_Dst,*(undefined4 *)(param_4 + 0x18),pvVar2);
            }
            else {
              uVar3 = 1;
              pvVar2 = AdjustPointer(*(void **)(param_1 + 0x18),(PMD *)(param_4 + 8));
              FID_conflict__CallMemberFunction1(_Dst,*(undefined4 *)(param_4 + 0x18),pvVar2,uVar3);
            }
            goto LAB_100ad42e;
          }
        }
      }
      else {
        iVar1 = _ValidateRead(*(void **)(param_1 + 0x18),1);
        if ((iVar1 != 0) && (iVar1 = _ValidateWrite(_Dst,1), iVar1 != 0)) {
          FID_conflict__memcpy(_Dst,*(void **)(param_1 + 0x18),*(size_t *)(param_4 + 0x14));
          if ((*(int *)(param_4 + 0x14) == 4) && (*(void **)_Dst != (void *)0x0)) {
            pvVar2 = AdjustPointer(*(void **)_Dst,(PMD *)(param_4 + 8));
            *(void **)_Dst = pvVar2;
          }
          goto LAB_100ad42e;
        }
      }
    }
    else {
      iVar1 = _ValidateRead(*(void **)(param_1 + 0x18),1);
      if ((iVar1 != 0) && (iVar1 = _ValidateWrite(_Dst,1), iVar1 != 0)) {
        pvVar2 = *(void **)(param_1 + 0x18);
        *(void **)_Dst = pvVar2;
        pvVar2 = AdjustPointer(pvVar2,(PMD *)(param_4 + 8));
        *(void **)_Dst = pvVar2;
        goto LAB_100ad42e;
      }
    }
    _inconsistency();
  }
LAB_100ad42e:
  *unaff_FS_OFFSET = local_14;
  return;
}


// CallCatchBlock  @ 100ad0f0
/* Library Function - Single Match
    void * __cdecl CallCatchBlock(struct EHExceptionRecord *,struct EHRegistrationNode *,struct
   _CONTEXT *,struct _s_FuncInfo const *,void *,int,unsigned long)
   
   Library: Visual Studio 1998 Release */

void * __cdecl
CallCatchBlock(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,
              _s_FuncInfo *param_4,void *param_5,int param_6,ulong param_7)

{
  _ptiddata p_Var1;
  void *pvVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_14 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &DAT_100ba6c0;
  puStack_10 = &LAB_100ac8a4;
  *unaff_FS_OFFSET = &local_14;
  __getptd();
  __getptd();
  p_Var1 = __getptd();
  p_Var1->ptlocinfo = (pthreadlocinfo)param_1;
  p_Var1 = __getptd();
  p_Var1->_ownlocale = (int)param_3;
  local_8 = 1;
  pvVar2 = _CallCatchBlock2(param_2,param_4,param_5,param_6,param_7);
  local_8 = 0xffffffff;
  FUN_100ad1bd();
  *unaff_FS_OFFSET = local_14;
  return pvVar2;
}


// CatchIt  @ 100ad050
/* Library Function - Single Match
    void __cdecl CatchIt(struct EHExceptionRecord *,struct EHRegistrationNode *,struct _CONTEXT
   *,void *,struct _s_FuncInfo const *,struct _s_HandlerType const *,struct _s_CatchableType const
   *,struct _s_TryBlockMapEntry const *,int,struct EHRegistrationNode *)
   
   Library: Visual Studio 1998 Release */

void __cdecl
CatchIt(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
       _s_FuncInfo *param_5,_s_HandlerType *param_6,_s_CatchableType *param_7,
       _s_TryBlockMapEntry *param_8,int param_9,EHRegistrationNode *param_10)

{
  void *pvVar1;
  
  if (param_7 != (_s_CatchableType *)0x0) {
    BuildCatchObject(param_1,param_2,param_6,param_7);
  }
  if (param_10 == (EHRegistrationNode *)0x0) {
    param_10 = param_2;
  }
  _UnwindNestedFrames(param_10,param_1);
  ___FrameUnwindToState(param_2,param_4,param_5,*(undefined4 *)param_8);
  *(int *)(param_2 + 8) = *(int *)(param_8 + 4) + 1;
  pvVar1 = CallCatchBlock(param_1,param_2,param_3,param_5,*(void **)(param_6 + 0xc),param_9,0x100);
  if (pvVar1 != (void *)0x0) {
    _JumpToContinuation(pvVar1,param_2);
  }
  return;
}


// DestructExceptionObject  @ 100ad440
/* Library Function - Single Match
    void __cdecl DestructExceptionObject(struct EHExceptionRecord *,unsigned char)
   
   Library: Visual Studio 1998 Release */

void __cdecl DestructExceptionObject(EHExceptionRecord *param_1,uchar param_2)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_100ba6e8;
  puStack_10 = &LAB_100ac8a4;
  *unaff_FS_OFFSET = &local_14;
  if ((param_1 != (EHExceptionRecord *)0x0) &&
     (*(void **)(*(int *)(param_1 + 0x1c) + 4) != (void *)0x0)) {
    local_8 = 0;
    _CallMemberFunction0(*(void **)(param_1 + 0x18),*(void **)(*(int *)(param_1 + 0x1c) + 4));
  }
  *unaff_FS_OFFSET = local_14;
  return;
}


// Download4444  @ 1002a860
void Download4444(void)

{
                    /* 0x2a860  17  Download4444 */
  DAT_10423694 = 1;
  return;
}


// FindHandler  @ 100acb40
/* Library Function - Single Match
    void __cdecl FindHandler(struct EHExceptionRecord *,struct EHRegistrationNode *,struct _CONTEXT
   *,void *,struct _s_FuncInfo const *,unsigned char,int,struct EHRegistrationNode *)
   
   Library: Visual Studio 1998 Release */

void __cdecl
FindHandler(EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
           _s_FuncInfo *param_5,uchar param_6,int param_7,EHRegistrationNode *param_8)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  _ptiddata p_Var4;
  int iVar5;
  _s_HandlerType *p_Var6;
  int iVar7;
  int *piVar8;
  byte *pbVar9;
  int iVar10;
  byte *pbVar11;
  bool bVar12;
  _s_TryBlockMapEntry *local_18;
  uint local_c;
  uint local_8;
  uint *local_4;
  
  iVar2 = *(int *)(param_2 + 8);
  if ((iVar2 < -1) || (*(int *)(param_5 + 4) <= iVar2)) {
    _inconsistency();
  }
  if ((((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
      (*(int *)(param_1 + 0x14) == 0x19930520)) && (*(int *)(param_1 + 0x1c) == 0)) {
    p_Var4 = __getptd();
    if (p_Var4->ptlocinfo == (pthreadlocinfo)0x0) {
      return;
    }
    p_Var4 = __getptd();
    param_1 = (EHExceptionRecord *)p_Var4->ptlocinfo;
    p_Var4 = __getptd();
    param_3 = (_CONTEXT *)p_Var4->_ownlocale;
    iVar5 = _ValidateRead(param_1,1);
    if (iVar5 == 0) {
      _inconsistency();
    }
    if (((((pthreadlocinfo)param_1)->refcount == -0x1f928c9d) &&
        (((pthreadlocinfo)param_1)->lc_category[0].locale == (char *)0x3)) &&
       ((((pthreadlocinfo)param_1)->lc_category[0].wlocale == (wchar_t *)0x19930520 &&
        (((pthreadlocinfo)param_1)->lc_category[0].wrefcount == (int *)0x0)))) {
      _inconsistency();
    }
  }
  if (((*(int *)param_1 == -0x1f928c9d) && (*(int *)(param_1 + 0x10) == 3)) &&
     (*(int *)(param_1 + 0x14) == 0x19930520)) {
    local_18 = GetRangeOfTrysToCheck(param_5,param_7,iVar2,&local_c,&local_8);
    if (local_c < local_8) {
      do {
        if ((*(int *)local_18 <= iVar2) && (iVar2 <= *(int *)(local_18 + 4))) {
          p_Var6 = *(_s_HandlerType **)(local_18 + 0x10);
          for (iVar5 = *(int *)(local_18 + 0xc); iVar5 != 0; iVar5 = iVar5 + -1) {
            piVar8 = *(int **)(*(int *)(param_1 + 0x1c) + 0xc);
            for (iVar7 = *piVar8; iVar7 != 0; iVar7 = iVar7 + -1) {
              piVar8 = piVar8 + 1;
              iVar10 = *(int *)(p_Var6 + 4);
              local_4 = *(uint **)(param_1 + 0x1c);
              pbVar3 = (byte *)*piVar8;
              if ((iVar10 == 0) || (*(char *)(iVar10 + 8) == '\0')) {
LAB_100accff:
                bVar12 = true;
              }
              else {
                if (iVar10 == *(int *)(pbVar3 + 4)) {
LAB_100accd9:
                  if (((((*pbVar3 & 2) == 0) || (((byte)*p_Var6 & 8) != 0)) &&
                      (((*local_4 & 1) == 0 || (((byte)*p_Var6 & 1) != 0)))) &&
                     (((*local_4 & 2) == 0 || (((byte)*p_Var6 & 2) != 0)))) goto LAB_100accff;
                }
                else {
                  pbVar9 = (byte *)(iVar10 + 8);
                  pbVar11 = (byte *)(*(int *)(pbVar3 + 4) + 8);
                  do {
                    bVar1 = *pbVar9;
                    bVar12 = bVar1 < *pbVar11;
                    if (bVar1 != *pbVar11) {
LAB_100accd0:
                      iVar10 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
                      goto LAB_100accd5;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar9[1];
                    bVar12 = bVar1 < pbVar11[1];
                    if (bVar1 != pbVar11[1]) goto LAB_100accd0;
                    pbVar9 = pbVar9 + 2;
                    pbVar11 = pbVar11 + 2;
                  } while (bVar1 != 0);
                  iVar10 = 0;
LAB_100accd5:
                  if (iVar10 == 0) goto LAB_100accd9;
                }
                bVar12 = false;
              }
              if (bVar12) {
                CatchIt(param_1,param_2,param_3,param_4,param_5,p_Var6,(_s_CatchableType *)*piVar8,
                        local_18,param_7,param_8);
                goto LAB_100acd5d;
              }
            }
            p_Var6 = p_Var6 + 0x10;
          }
        }
LAB_100acd5d:
        local_18 = local_18 + 0x14;
        local_c = local_c + 1;
      } while (local_c < local_8);
    }
    if (param_6 != '\0') {
      DestructExceptionObject(param_1,'\x01');
      return;
    }
  }
  else {
    if (param_6 == '\0') {
      FindHandlerForForeignException(param_1,param_2,param_3,param_4,param_5,iVar2,param_7,param_8);
      return;
    }
    terminate();
  }
  return;
}


// FindHandlerForForeignException  @ 100acde0
/* Library Function - Single Match
    void __cdecl FindHandlerForForeignException(struct EHExceptionRecord *,struct EHRegistrationNode
   *,struct _CONTEXT *,void *,struct _s_FuncInfo const *,int,int,struct EHRegistrationNode *)
   
   Library: Visual Studio 1998 Release */

void __cdecl
FindHandlerForForeignException
          (EHExceptionRecord *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3,void *param_4,
          _s_FuncInfo *param_5,int param_6,int param_7,EHRegistrationNode *param_8)

{
  _ptiddata p_Var1;
  int iVar2;
  _s_TryBlockMapEntry *p_Var3;
  int iVar4;
  uint local_8;
  uint local_4;
  
  p_Var1 = __getptd();
  if (((p_Var1->ptmbcinfo == (pthreadmbcinfo)0x0) ||
      (iVar2 = _CallSETranslator(param_1,param_2,param_3,param_4,param_5,param_7,param_8),
      iVar2 == 0)) &&
     (p_Var3 = GetRangeOfTrysToCheck(param_5,param_7,param_6,&local_8,&local_4), local_8 < local_4))
  {
    do {
      if ((*(int *)p_Var3 <= param_6) && (param_6 <= *(int *)(p_Var3 + 4))) {
        iVar4 = *(int *)(p_Var3 + 0xc) * 0x10 + *(int *)(p_Var3 + 0x10);
        iVar2 = *(int *)(iVar4 + -0xc);
        if ((iVar2 == 0) || (*(char *)(iVar2 + 8) == '\0')) {
          CatchIt(param_1,param_2,param_3,param_4,param_5,(_s_HandlerType *)(iVar4 + -0x10),
                  (_s_CatchableType *)0x0,p_Var3,param_7,param_8);
        }
      }
      p_Var3 = p_Var3 + 0x14;
      local_8 = local_8 + 1;
    } while (local_8 < local_4);
  }
  return;
}


// ForceReloadProfile  @ 100868c0
void ForceReloadProfile(char *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 *puVar6;
  char *pcVar7;
  
  puVar6 = &DAT_105597c0;
                    /* 0x868c0  18  ForceReloadProfile */
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar5 = param_1;
  do {
    pcVar7 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar7 + -uVar3;
  pcVar7 = (char *)&DAT_105597c0;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar7 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar7 = pcVar7 + 1;
  }
  DAT_100db320 = 1;
  FUN_10086890(param_1);
  return;
}


// GameInit  @ 100862d0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
GameInit(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,undefined4 param_5,
        char *param_6,int param_7)

{
  char cVar1;
  BOOL BVar2;
  DWORD DVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 *puVar9;
  char *pcVar10;
  undefined *local_ac;
  undefined4 local_a8;
  int local_a4;
  undefined *local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  _OSVERSIONINFOA local_94;
  
  puVar9 = &DAT_10559d90;
                    /* 0x862d0  22  GameInit */
  for (iVar4 = 0x8d; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  uVar5 = 0xffffffff;
  do {
    pcVar8 = param_1;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar8;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar8 = pcVar8 + -uVar5;
  pcVar10 = (char *)&DAT_104c07e8;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar10 = pcVar10 + 4;
  }
  pcVar7 = (char *)&DAT_104c07e8;
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar10 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar10 = pcVar10 + 1;
  }
  DAT_100c1560 = 0;
  puVar9 = &DAT_105597c0;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  uVar5 = 0xffffffff;
  do {
    pcVar8 = param_6;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = param_6 + 1;
    cVar1 = *param_6;
    param_6 = pcVar8;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar8 = pcVar8 + -uVar5;
  pcVar10 = (char *)&DAT_105597c0;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar10 = pcVar10 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar10 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar10 = pcVar10 + 1;
  }
  DAT_1055a004 = param_5;
  _DAT_105599cc = param_4[2];
  _DAT_105599d0 = param_4[3];
  DAT_105597ac = param_4[4];
  DAT_10559d68 = param_4[5];
  DAT_105599d4 = param_4[6];
  DAT_10559d7c = param_4[7];
  _DAT_105599d8 = param_4[8];
  DAT_10559a14 = param_4[9];
  DAT_10559930 = param_4[10];
  _DAT_10559a1c = param_4[0x14];
  _DAT_10559924 = param_4[0xb];
  _DAT_10559a18 = param_4[0xc];
  DAT_100db304 = param_4[0x15];
  _DAT_10559a08 = param_4[0xd];
  DAT_10559d6c = param_4[0xe];
  DAT_10559d58 = param_4[0x10];
  DAT_10559a0c = param_4[0xf];
  DAT_1055992c = param_4[0x11];
  DAT_10559d78 = param_4[0x27];
  DAT_10559938 = param_4[0x13];
  DAT_105599c8 = param_4[0x28];
  DAT_10559d80 = param_4[0x12];
  DAT_10559d64 = param_4[0x16];
  _DAT_10559d48 = param_4[0x19];
  DAT_10559d5c = param_4[0x1a];
  DAT_10559d70 = param_4[0x1b];
  _DAT_10559934 = param_4[0x1c];
  DAT_10559d60 = param_4[0x1d];
  DAT_10559804 = param_4[0x1e];
  DAT_10559800 = param_4[0x1f];
  DAT_10559920 = param_4[0x20];
  DAT_10559d50 = param_4[0x21];
  DAT_10559a10 = param_4[0x22];
  DAT_10559928 = param_4[0x23];
  _DAT_105597b0 = param_4[0x24];
  DAT_10559d4c = param_4[0x25];
  DAT_10559810 = param_4[0x26];
  _DAT_10559d54 = *param_4;
  _DAT_105597b4 = param_4[1];
  if (param_7 != 0) {
    DAT_10559810 = 0;
  }
  local_94.dwOSVersionInfoSize = 0x94;
  BVar2 = GetVersionExA(&local_94);
  if (BVar2 == 0) {
    FUN_10085dc0(s_Couldn_t_get_OS_info_100db5a4);
  }
  DAT_10559808 = (uint)(3 < local_94.dwMajorVersion);
  FUN_10041240();
  FUN_1009ec0c();
  DVar3 = GetCurrentDirectoryA(0x400,&DAT_104c0be8);
  if (DVar3 == 0) {
    FUN_10085dc0(s_Couldn_t_determine_current_direc_100db5bc);
  }
  iVar4 = FUN_10060490(&DAT_104c0be8);
  if ((&DAT_104c0be7)[iVar4] == '/') {
    iVar4 = FUN_10060490(&DAT_104c0be8);
    (&DAT_104c0be7)[iVar4] = 0;
  }
  local_ac = &DAT_104c0be8;
  local_a8 = 0;
  local_a4 = 1;
  _DAT_10559c80 = PTR_DAT_100db314;
  cVar1 = (char)DAT_104c07e8;
  do {
    if ((cVar1 == '\0') || (0x31 < local_a4)) goto LAB_100865f9;
    if (*pcVar7 != '\0') {
      do {
        if ((' ' < *pcVar7) && (*pcVar7 < '\x7f')) break;
        pcVar8 = pcVar7 + 1;
        pcVar7 = pcVar7 + 1;
      } while (*pcVar8 != '\0');
      if (*pcVar7 == '\0') goto LAB_100865f9;
      local_a4 = local_a4 + 1;
      *(char **)(local_a4 * 4 + 0x10559c7c) = pcVar7;
      if (*pcVar7 != '\0') {
        do {
          if ((*pcVar7 < '!') || (*pcVar7 == '\x7f')) break;
          pcVar8 = pcVar7 + 1;
          pcVar7 = pcVar7 + 1;
        } while (*pcVar8 != '\0');
        if (*pcVar7 == '\0') {
LAB_100865f9:
          local_a0 = &DAT_10559c80;
          FUN_100624e0(local_a4,&DAT_10559c80);
          local_a4 = DAT_10998370;
          local_a0 = (undefined *)DAT_10998378;
          DAT_10559d74 = param_7;
          local_9c = param_2;
          local_98 = param_3;
          FUN_10085d20();
          S_BlockSound();
          FUN_10085f00(s_Host_Init_100db5e4);
          iVar4 = FUN_10017df0(&local_ac);
          if (iVar4 == 0) {
            return 0;
          }
          if (DAT_10559d74 != 0) {
            FUN_1005a310();
            FUN_1001ee90(1);
          }
          return 1;
        }
        *pcVar7 = '\0';
        pcVar7 = pcVar7 + 1;
      }
    }
    cVar1 = *pcVar7;
  } while( true );
}


// GameSetBackground  @ 100862c0
void GameSetBackground(undefined4 param_1)

{
                    /* 0x862c0  23  GameSetBackground */
  DAT_100db318 = param_1;
  return;
}


// GameSetState  @ 100862b0
void GameSetState(undefined4 param_1)

{
                    /* 0x862b0  24  GameSetState */
  DAT_105599c4 = param_1;
  return;
}


// GameSetSubState  @ 10086280
void GameSetSubState(uint param_1)

{
                    /* 0x86280  25  GameSetSubState */
  if ((param_1 & 2) != 0) {
    FUN_10086270(1);
    return;
  }
  if (param_1 != 1) {
    FUN_10086270(param_1);
  }
  return;
}


// GetEngineState  @ 10086220
undefined4 GetEngineState(void)

{
                    /* 0x86220  26  GetEngineState */
  return DAT_1099e680;
}


// GetGameInfo  @ 100866a0
undefined4 GetGameInfo(uint *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  uint local_140 [3];
  char local_134 [32];
  uint local_114;
  undefined1 local_110;
  undefined1 local_10f;
  undefined1 local_10e;
  undefined1 local_10d;
  undefined2 local_10c;
  char local_10a [258];
  int local_8;
  undefined4 local_4;
  
  puVar5 = local_140;
                    /* 0x866a0  27  GetGameInfo */
  for (iVar2 = 0x50; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  local_140[0] = FUN_10084e10();
  local_140[1] = (uint)(DAT_10ad9d10 != 1);
  local_140[2] = DAT_10ad9d10;
  _strncpy(local_134,(char *)&DAT_10ae1868,0x20);
  local_114 = (uint)(DAT_10ae1840 != 0);
  if (DAT_10a3e860 == 3) {
    local_110 = DAT_10a3e864;
    local_10f = DAT_10a3e865;
    local_10e = DAT_10a3e866;
    local_10c = DAT_10a3e870._2_2_;
    local_10d = DAT_10a3e867;
  }
  local_8 = DAT_1099e680;
  local_4 = DAT_109a234c;
  pcVar8 = local_10a;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    pcVar8[0] = '\0';
    pcVar8[1] = '\0';
    pcVar8[2] = '\0';
    pcVar8[3] = '\0';
    pcVar8 = pcVar8 + 4;
  }
  if (DAT_1099e680 == 5) {
    pcVar8 = s_Currently_in_a_game_100db5f0;
  }
  else {
    if (DAT_1099e680 == 1) {
      _sprintf(local_10a,s_Disconnected_100db604);
      if (DAT_100db2ec != 0) {
        iVar2 = -1;
        pcVar8 = local_10a;
        do {
          pcVar7 = pcVar8;
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          pcVar7 = pcVar8 + 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar7;
        } while (cVar1 != '\0');
        *(undefined2 *)(pcVar7 + -1) = DAT_100db614;
        pcVar7[1] = DAT_100db616;
        uVar3 = 0xffffffff;
        pcVar8 = &DAT_10559820;
        do {
          pcVar7 = pcVar8;
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          pcVar7 = pcVar8 + 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar7;
        } while (cVar1 != '\0');
        uVar3 = ~uVar3;
        iVar2 = -1;
        pcVar8 = local_10a;
        do {
          pcVar6 = pcVar8;
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          pcVar6 = pcVar8 + 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar6;
        } while (cVar1 != '\0');
        pcVar8 = pcVar7 + -uVar3;
        pcVar7 = pcVar6 + -1;
        for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
          pcVar8 = pcVar8 + 4;
          pcVar7 = pcVar7 + 4;
        }
        for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *pcVar7 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          pcVar7 = pcVar7 + 1;
        }
      }
      goto LAB_10086869;
    }
    if (DAT_1099e680 == 4) {
      if (DAT_109a2fac != 0) {
        _sprintf(local_10a,s_Downloading__s___i_percent_compl_100db618,&DAT_109a2ffc,DAT_109a3044);
        goto LAB_10086869;
      }
      pcVar8 = s_Initializing_and_downloading_100db63c;
    }
    else if (DAT_1099e680 == 3) {
      pcVar8 = s_Connected_to_server_100db65c;
    }
    else if (DAT_1099e680 == 2) {
      pcVar8 = s_Connecting_100db670;
    }
    else if (DAT_1099e680 == 0) {
      pcVar8 = s_Running_dedicated_server_100db67c;
    }
    else {
      pcVar8 = &DAT_100db698;
    }
  }
  _sprintf(local_10a,pcVar8);
LAB_10086869:
  puVar5 = local_140;
  for (iVar2 = 0x50; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *puVar5;
    puVar5 = puVar5 + 1;
    param_1 = param_1 + 1;
  }
  return 1;
}


// GetPauseState  @ 10086980
undefined4 GetPauseState(void)

{
                    /* 0x86980  28  GetPauseState */
  return DAT_10ae1844;
}


// GetRangeOfTrysToCheck  @ 100acec0
/* Library Function - Single Match
    struct _s_TryBlockMapEntry const * __cdecl GetRangeOfTrysToCheck(struct _s_FuncInfo const
   *,int,int,unsigned int *,unsigned int *)
   
   Library: Visual Studio 1998 Release */

_s_TryBlockMapEntry * __cdecl
GetRangeOfTrysToCheck(_s_FuncInfo *param_1,int param_2,int param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint local_c;
  uint local_8;
  
  iVar1 = *(int *)(param_1 + 0x10);
  uVar3 = *(uint *)(param_1 + 0xc);
  local_c = uVar3;
  if (-1 < param_2) {
    piVar2 = (int *)(uVar3 * 0x14 + 4 + iVar1);
    local_8 = uVar3;
    do {
      if (uVar3 == 0xffffffff) {
        _inconsistency();
      }
      uVar3 = uVar3 - 1;
      if (((piVar2[-5] < param_3) && (param_3 <= piVar2[-4])) || (uVar3 == 0xffffffff)) {
        param_2 = param_2 + -1;
        local_c = local_8;
        local_8 = uVar3;
      }
      piVar2 = piVar2 + -5;
    } while (-1 < param_2);
  }
  uVar3 = uVar3 + 1;
  *param_4 = uVar3;
  *param_5 = local_c;
  if ((*(uint *)(param_1 + 0xc) < local_c) || (local_c < uVar3)) {
    _inconsistency();
  }
  return (_s_TryBlockMapEntry *)(iVar1 + uVar3 * 0x14);
}


// LoadGame  @ 1005c2a0
void LoadGame(undefined4 param_1)

{
  undefined4 uVar1;
  
                    /* 0x5c2a0  43  LoadGame */
  uVar1 = DAT_1055a000;
  DAT_1055a000 = 1;
  FUN_1005c2d0(param_1);
  DAT_1055a000 = uVar1;
  return;
}


// SaveGame  @ 1005c020
void SaveGame(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
                    /* 0x5c020  52  SaveGame */
  uVar1 = DAT_1055a000;
  DAT_1055a000 = 1;
  FUN_1005bc50(param_1,param_2);
  DAT_1055a000 = uVar1;
  return;
}


// SetMessagePumpDisableMode  @ 10086920
void SetMessagePumpDisableMode(undefined4 param_1)

{
                    /* 0x86920  53  SetMessagePumpDisableMode */
  DAT_100db2e4 = param_1;
  return;
}


// SetPauseState  @ 10086930
void SetPauseState(int param_1)

{
                    /* 0x86930  54  SetPauseState */
  if (param_1 != 0) {
    if (DAT_100db328 == 0) {
      DAT_100db324 = DAT_10ae1844;
    }
    DAT_10ae1844 = 1;
    DAT_100db328 = 1;
    return;
  }
  if (DAT_100db328 != 0) {
    DAT_10ae1844 = DAT_100db324;
  }
  DAT_100db328 = 0;
  return;
}


// SetStartupMode  @ 10086910
void SetStartupMode(undefined4 param_1)

{
                    /* 0x86910  55  SetStartupMode */
  DAT_100db2e0 = param_1;
  return;
}


// TranslatorGuardHandler  @ 100a4c50
/* Library Function - Single Match
    enum _EXCEPTION_DISPOSITION __cdecl TranslatorGuardHandler(struct EHExceptionRecord *,struct
   TranslatorGuardRN *,void *,void *)
   
   Library: Visual Studio 1998 Release */

_EXCEPTION_DISPOSITION __cdecl
TranslatorGuardHandler
          (EHExceptionRecord *param_1,TranslatorGuardRN *param_2,void *param_3,void *param_4)

{
  _EXCEPTION_DISPOSITION _Var1;
  
  if (((byte)param_1[4] & 0x66) != 0) {
    *(undefined4 *)(param_2 + 0x24) = 1;
    return 1;
  }
  ___InternalCxxFrameHandler
            (param_1,*(undefined4 *)(param_2 + 0xc),param_3,0,*(undefined4 *)(param_2 + 8),
             *(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),1);
  if (*(int *)(param_2 + 0x24) == 0) {
    _UnwindNestedFrames((EHRegistrationNode *)param_2,param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x100a4caf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = (**(code **)(param_2 + 0x18))();
  return _Var1;
}


// cvtdate  @ 100aacf0
/* Library Function - Single Match
    _cvtdate
   
   Library: Visual Studio 1998 Release */

void __cdecl
cvtdate(int param_1,int param_2,uint param_3,int param_4,int param_5,int param_6,int param_7,
       int param_8,int param_9,int param_10,int param_11)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == 1) {
    if ((param_3 & 3) == 0) {
      iVar3 = *(int *)(&DAT_100df95c + param_4 * 4);
    }
    else {
      iVar3 = *(int *)(&DAT_100df994 + param_4 * 4);
    }
    iVar2 = (int)(((int)(param_3 - 1) >> 2) + param_3 * 0x16d + -0x63db + iVar3 + 1) % 7;
    iVar1 = param_5;
    if (iVar2 < param_6) {
      iVar1 = param_5 + -1;
    }
    iVar3 = iVar3 + 1 + (iVar1 * 7 - iVar2) + param_6;
    if (param_5 == 5) {
      if ((param_3 & 3) == 0) {
        iVar1 = *(int *)(&DAT_100df960 + param_4 * 4);
      }
      else {
        iVar1 = (&DAT_100df998)[param_4];
      }
      if (iVar1 < iVar3) {
        iVar3 = iVar3 + -7;
      }
    }
  }
  else {
    if ((param_3 & 3) == 0) {
      iVar3 = *(int *)(&DAT_100df95c + param_4 * 4);
    }
    else {
      iVar3 = *(int *)(&DAT_100df994 + param_4 * 4);
    }
    iVar3 = iVar3 + param_7;
  }
  if (param_1 != 1) {
    DAT_100de914 = iVar3;
    DAT_100de918 = param_11 + ((param_8 * 0x3c + param_9) * 0x3c + param_10 + DAT_100de868) * 1000;
    if (DAT_100de918 < 0) {
      DAT_100de918 = DAT_100de918 + 86399999;
    }
    else if (86399999 < DAT_100de918) {
      DAT_100de918 = DAT_100de918 + -86399999;
    }
    DAT_100de910 = param_3;
    return;
  }
  DAT_100de904 = iVar3;
  DAT_100de900 = param_3;
  DAT_100de908 = param_11 + ((param_8 * 0x3c + param_9) * 0x3c + param_10) * 1000;
  return;
}


// doexit  @ 100a6470
/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 1998 Release */

void __cdecl doexit(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  FID_conflict___lockexit();
  if (DAT_100dd9b8 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  DAT_100dd9b4 = 1;
  DAT_100dd9b0 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_10b21298 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_10b21294 + -4), DAT_10b21298 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_10b21298 <= puVar1);
    }
    __initterm(&DAT_100bf024,&DAT_100bf030);
  }
  __initterm(&DAT_100bf034,&DAT_100bf038);
  if (param_3 != 0) {
    FID_conflict___lockexit();
    return;
  }
  DAT_100dd9b8 = 1;
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}


// entry  @ 100a6c70
int entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 1;
  if ((param_2 == 0) && (DAT_100ddc48 == 0)) {
    return 0;
  }
  if ((param_2 == 1) || (param_2 == 2)) {
    if (DAT_10b20284 != (code *)0x0) {
      iVar1 = (*DAT_10b20284)(param_1,param_2,param_3);
    }
    if ((iVar1 == 0) || (iVar1 = __CRT_INIT_12(param_1,param_2,param_3), iVar1 == 0)) {
      return 0;
    }
  }
  iVar1 = FUN_10086230(param_1,param_2,param_3);
  if ((param_2 == 1) && (iVar1 == 0)) {
    __CRT_INIT_12(param_1,0,param_3);
  }
  if ((param_2 == 0) || (param_2 == 3)) {
    iVar2 = __CRT_INIT_12(param_1,param_2,param_3);
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    if ((iVar1 != 0) && (DAT_10b20284 != (code *)0x0)) {
      iVar1 = (*DAT_10b20284)(param_1,param_2,param_3);
    }
  }
  return iVar1;
}


// findenv  @ 100b4f20
/* Library Function - Single Match
    _findenv
   
   Library: Visual Studio 1998 Release */

int __cdecl findenv(uchar *param_1,size_t param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *DAT_100dd998;
  piVar2 = DAT_100dd998;
  while( true ) {
    if (iVar1 == 0) {
      return -((int)piVar2 - (int)DAT_100dd998 >> 2);
    }
    iVar1 = __mbsnbicoll(param_1,(uchar *)*piVar2,param_2);
    if ((iVar1 == 0) &&
       ((*(char *)(*piVar2 + param_2) == '=' || (*(char *)(*piVar2 + param_2) == '\0')))) break;
    piVar2 = piVar2 + 1;
    iVar1 = *piVar2;
  }
  return (int)piVar2 - (int)DAT_100dd998 >> 2;
}


// flsall  @ 100a5a00
/* Library Function - Single Match
    _flsall
   
   Library: Visual Studio 1998 Release */

int __cdecl flsall(int param_1)

{
  void *_File;
  int iVar1;
  int iVar2;
  int iVar3;
  int _Index;
  int local_4;
  
  iVar2 = 0;
  _Index = 0;
  local_4 = 0;
  __lock(2);
  if (0 < DAT_10b21290) {
    iVar3 = 0;
    do {
      _File = *(void **)(DAT_10b20288 + iVar3);
      if ((_File != (void *)0x0) && ((*(byte *)((int)_File + 0xc) & 0x83) != 0)) {
        FID_conflict___lock_file2(_Index,_File);
        iVar1 = *(int *)(DAT_10b20288 + iVar3);
        if ((*(uint *)(iVar1 + 0xc) & 0x83) != 0) {
          if (param_1 == 1) {
            iVar1 = __fflush_lk(iVar1);
            if (iVar1 != -1) {
              iVar2 = iVar2 + 1;
            }
          }
          else if (((param_1 == 0) && ((*(uint *)(iVar1 + 0xc) & 2) != 0)) &&
                  (iVar1 = __fflush_lk(iVar1), iVar1 == -1)) {
            local_4 = -1;
          }
        }
        FID_conflict___lock_file2(_Index,*(void **)(DAT_10b20288 + iVar3));
      }
      iVar3 = iVar3 + 4;
      _Index = _Index + 1;
    } while (_Index < DAT_10b21290);
  }
  FUN_100a7ed0(2);
  if (param_1 != 1) {
    iVar2 = local_4;
  }
  return iVar2;
}


// genfname  @ 100a5880
/* Library Function - Single Match
    _genfname
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl genfname(uchar *param_1)

{
  char cVar1;
  uchar *puVar2;
  ulong uVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uchar *puVar7;
  char *pcVar8;
  char local_4 [4];
  
  puVar2 = __mbsrchr(param_1,0x2e);
  uVar3 = _strtoul((char *)(puVar2 + 1),(char **)0x0,0x20);
  if (0x7ffe < uVar3 + 1) {
    return 0xffffffff;
  }
  pcVar4 = __ultoa(uVar3 + 1,local_4,0x20);
  uVar5 = 0xffffffff;
  do {
    pcVar8 = pcVar4;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar8;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  puVar7 = (uchar *)(pcVar8 + -uVar5);
  puVar2 = puVar2 + 1;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)puVar2 = *(undefined4 *)puVar7;
    puVar7 = puVar7 + 4;
    puVar2 = puVar2 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar2 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar2 = puVar2 + 1;
  }
  return 0;
}


// getSystemCP  @ 100ad890
/* Library Function - Single Match
    _getSystemCP
   
   Library: Visual Studio 1998 Release */

int __cdecl getSystemCP(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_100decbc = 1;
                    /* WARNING: Could not recover jumptable at 0x100ad8ad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_100decbc = 1;
                    /* WARNING: Could not recover jumptable at 0x100ad8c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_100de6c8;
  }
  DAT_100decbc = (uint)bVar2;
  return param_1;
}


// glAccum  @ 10027110
/* __stdcall glAccum,8 */

void glAccum(void)

{
                    /* 0x27110  62  _glAccum@8 */
  return;
}


// glAlphaFunc  @ 100233d0
/* __stdcall glAlphaFunc,8 */

void glAlphaFunc(undefined4 param_1)

{
  int iVar1;
  int *piStack_20;
  int *piStack_1c;
  int *piStack_18;
  int *piStack_14;
  int *piStack_10;
  
                    /* 0x233d0  63  _glAlphaFunc@8 */
  iVar1 = -1;
  switch(param_1) {
  case 0x200:
    iVar1 = 1;
    break;
  case 0x201:
    iVar1 = 2;
    break;
  case 0x202:
    iVar1 = 3;
    break;
  case 0x203:
    iVar1 = 4;
    break;
  case 0x204:
    iVar1 = 5;
    break;
  case 0x205:
    iVar1 = 6;
    break;
  case 0x206:
    iVar1 = 7;
    break;
  case 0x207:
    iVar1 = 8;
  }
  if (-1 < iVar1) {
    if (iVar1 != DAT_10423744) {
      if (DAT_104234b0 != 0) {
        if (DAT_104234ac != DAT_104234a8) {
          piStack_10 = (int *)0x0;
          piStack_14 = DAT_1042364c;
          piStack_18 = DAT_104234ac;
          piStack_1c = DAT_10423654;
          piStack_20 = (int *)((int)DAT_104234a8 - (int)DAT_104234ac);
          (**(code **)(*DAT_10423658 + 0x14))(DAT_10423658,5,DAT_104234ac);
          DAT_104234ac = DAT_104234a8;
        }
        piStack_10 = DAT_10423654;
        piStack_14 = (int *)0x10023494;
        (**(code **)(*DAT_10423654 + 0x10))();
        piStack_14 = (int *)0x8;
        piStack_18 = (int *)DAT_104234b0;
        piStack_1c = (int *)&DAT_10453ba8;
        piStack_20 = DAT_10423658;
        (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c,4);
        (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&piStack_20);
        DAT_104234ac = (int *)0x0;
        DAT_104234a8 = (int *)0x0;
        DAT_104234b0 = 0;
      }
      piStack_14 = (int *)0x19;
      piStack_18 = DAT_1042364c;
      piStack_1c = (int *)0x100234f9;
      DAT_10423744 = iVar1;
      piStack_10 = (int *)iVar1;
      (**(code **)(*DAT_1042364c + 0x58))();
    }
    piStack_10 = (int *)0x10023508;
    iVar1 = __ftol();
    if (iVar1 != DAT_10423740) {
      if (DAT_104234b0 != 0) {
        if (DAT_104234ac != DAT_104234a8) {
          piStack_10 = (int *)0x0;
          piStack_14 = DAT_1042364c;
          piStack_18 = DAT_104234ac;
          piStack_1c = DAT_10423654;
          piStack_20 = (int *)((int)DAT_104234a8 - (int)DAT_104234ac);
          (**(code **)(*DAT_10423658 + 0x14))(DAT_10423658,5,DAT_104234ac);
          DAT_104234ac = DAT_104234a8;
        }
        piStack_10 = DAT_10423654;
        piStack_14 = (int *)0x10023571;
        (**(code **)(*DAT_10423654 + 0x10))();
        piStack_14 = (int *)0x8;
        piStack_18 = (int *)DAT_104234b0;
        piStack_1c = (int *)&DAT_10453ba8;
        piStack_20 = DAT_10423658;
        (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c,4);
        (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&piStack_20);
        DAT_104234ac = (int *)0x0;
        DAT_104234a8 = (int *)0x0;
        DAT_104234b0 = 0;
      }
      piStack_14 = (int *)0x18;
      piStack_18 = DAT_1042364c;
      piStack_1c = (int *)0x100235d6;
      DAT_10423740 = iVar1;
      piStack_10 = (int *)iVar1;
      (**(code **)(*DAT_1042364c + 0x58))();
    }
  }
  return;
}


// glAreTexturesResident  @ 10027120
/* __stdcall glAreTexturesResident,12 */

undefined1 glAreTexturesResident(void)

{
                    /* 0x27120  64  _glAreTexturesResident@12 */
  return 0;
}


// glArrayElement  @ 10023600
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall glArrayElement,4 */

void glArrayElement(int param_1)

{
  float *pfVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  
                    /* 0x23600  65  _glArrayElement@4 */
  puVar3 = (undefined4 *)((DAT_104234b4 + DAT_104234a8) * 0x20 + DAT_104236cc);
  puVar7 = (undefined4 *)(param_1 * 0x10 + DAT_104236c4);
  uVar2 = puVar7[1];
  *puVar3 = *puVar7;
  puVar3[1] = uVar2;
  puVar3[2] = puVar7[2];
  pfVar1 = (float *)(DAT_104236c8 + param_1 * 0xc);
  uVar4 = (uint)ROUND(pfVar1[2] * _DAT_100c8bbc);
  iVar6 = (int)ROUND(pfVar1[1] * _DAT_100c8bbc);
  iVar5 = (int)ROUND(_DAT_100c8bbc * *pfVar1);
  if (0xff < (int)uVar4) {
    uVar4 = 0xff;
  }
  if (0xff < iVar6) {
    iVar6 = 0xff;
  }
  if (0xff < iVar5) {
    iVar5 = 0xff;
  }
  puVar3[3] = uVar4 | iVar6 << 8 | iVar5 << 0x10 | 0xff000000U;
  puVar3[4] = DAT_104236b4;
  puVar3[5] = DAT_104236b8;
  if (DAT_1042367c != 0) {
    puVar3[6] = DAT_104236bc;
    puVar3[7] = DAT_104236c0;
  }
  DAT_104234b4 = DAT_104234b4 + 1;
  return;
}


// glBegin  @ 10023720
/* __stdcall glBegin,4 */

void glBegin(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
                    /* 0x23720  66  _glBegin@4 */
  iVar4 = DAT_10423698;
  DAT_10423664 = param_1;
  DAT_104234b4 = 0;
  if (DAT_10423674 != 1) {
    DAT_104234b4 = 0;
    return;
  }
  if (DAT_10423670 != 0) {
    DAT_104234b4 = 0;
    return;
  }
  iVar2 = (&DAT_10423bd4)[DAT_10423698 * 0xc];
  iVar3 = (&DAT_10423bcc)[DAT_10423698 * 0xc];
  piVar1 = (int *)(&DAT_10423ba8 + DAT_10423698 * 0x30);
  if (iVar3 != DAT_10423b14) {
    FUN_1002bd50();
    DAT_10423b14 = iVar3;
    (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,0xd,iVar3);
  }
  iVar3 = (&DAT_10423bd0)[iVar4 * 0xc];
  if (iVar3 != DAT_10423b18) {
    FUN_1002bd50();
    DAT_10423b18 = iVar3;
    (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,0xe,iVar3);
  }
  iVar3 = (&DAT_10423bc4)[iVar4 * 0xc];
  if (DAT_10423b20 != iVar3) {
    FUN_1002bd50();
    DAT_10423b20 = iVar3;
    (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,0x10,iVar3);
  }
  iVar3 = (&DAT_10423bc0)[iVar4 * 0xc];
  if (iVar3 != DAT_10423b24) {
    FUN_1002bd50();
    DAT_10423b24 = iVar3;
    (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,0x11,iVar3);
  }
  iVar4 = (&DAT_10423bc8)[iVar4 * 0xc];
  if (iVar4 != DAT_10423b28) {
    FUN_1002bd50();
    DAT_10423b28 = iVar4;
    (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,0x12,iVar4);
  }
  if (iVar2 != DAT_10423ba0) {
    FUN_1002bd50();
    DAT_10423ba0 = iVar2;
    (**(code **)(*DAT_1042364c + 0x98))(DAT_1042364c,0,iVar2);
  }
  if (DAT_104236a4 < 0x1e02) {
    if (DAT_104236a4 == 0x1e01) {
      iVar4 = *piVar1;
      if ((iVar4 == 1) || (iVar4 == 3)) {
        if (DAT_10423ae8 != 2) {
          FUN_1002bd50();
          DAT_10423ae8 = 2;
          (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,2,2);
        }
        if (DAT_10423aec != 0) {
          FUN_1002bd50();
          DAT_10423aec = 0;
          (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,3,0);
        }
        if (DAT_10423ae4 != 2) {
          FUN_1002bd50();
          DAT_10423ae4 = 2;
          (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,1,2);
        }
        if (DAT_10423af4 != 2) {
          FUN_1002bd50();
          DAT_10423af4 = 2;
          (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,5,2);
        }
        if (DAT_10423af8 != 0) {
          FUN_1002bd50();
          DAT_10423af8 = 0;
          (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,6,0);
        }
        if (DAT_10423af0 != 3) {
          FUN_1002bd50();
          DAT_10423af0 = 3;
          (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,4,3);
        }
      }
      else if (iVar4 == 4) {
        if (DAT_10423ae8 != 2) {
          FUN_1002bd50();
          DAT_10423ae8 = 2;
          (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,2,2);
        }
        if (DAT_10423aec != 0) {
          FUN_1002bd50();
          DAT_10423aec = 0;
          (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,3,0);
        }
        if (DAT_10423ae4 != 2) {
          FUN_1002bd50();
          DAT_10423ae4 = 2;
          (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,1,2);
        }
        if (DAT_10423af4 != 2) {
          FUN_1002bd50();
          DAT_10423af4 = 2;
          (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,5,2);
        }
        if (DAT_10423af8 != 0) {
          FUN_1002bd50();
          DAT_10423af8 = 0;
          (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,6,0);
        }
        if (DAT_10423af0 != 2) {
          FUN_1002bd50();
          DAT_10423af0 = 2;
          (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,4,2);
        }
      }
    }
    else if (DAT_104236a4 == 0xbe2) {
      iVar4 = *piVar1;
      if ((iVar4 == 1) || (iVar4 == 3)) {
        FUN_1002be10(0,2,0x12);
        FUN_1002be10(0,3,0);
        uVar5 = 4;
LAB_10023eec:
        FUN_1002be10(0,1,uVar5);
        FUN_1002be10(0,5,2);
        FUN_1002be10(0,6,0);
        uVar5 = 3;
      }
      else {
        if (iVar4 != 4) goto LAB_10023f22;
        FUN_1002be10(0,2,0x12);
        FUN_1002be10(0,3,0);
        FUN_1002be10(0,1,4);
        FUN_1002be10(0,5,2);
        FUN_1002be10(0,6,0);
        uVar5 = 4;
      }
      FUN_1002be10(0,4,uVar5);
    }
  }
  else if (DAT_104236a4 == 0x2100) {
    iVar4 = *piVar1;
    if ((iVar4 == 1) || (iVar4 == 3)) {
      if (DAT_10423ae8 != 2) {
        FUN_1002bd50();
        DAT_10423ae8 = 2;
        (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,2,2);
      }
      if (DAT_10423aec != 0) {
        FUN_1002bd50();
        DAT_10423aec = 0;
        (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,3,0);
      }
      if (DAT_10423ae4 != 4) {
        FUN_1002bd50();
        DAT_10423ae4 = 4;
        (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,1,4);
      }
      if (DAT_10423af4 != 2) {
        FUN_1002bd50();
        DAT_10423af4 = 2;
        (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,5,2);
      }
      if (DAT_10423af8 != 0) {
        FUN_1002bd50();
        DAT_10423af8 = 0;
        (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,6,0);
      }
      if (DAT_10423af0 != 3) {
        FUN_1002bd50();
        DAT_10423af0 = 3;
        (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,4,3);
      }
    }
    else if (iVar4 == 4) {
      if (DAT_10423ae8 != 2) {
        FUN_1002bd50();
        DAT_10423ae8 = 2;
        (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,2,2);
      }
      if (DAT_10423aec != 0) {
        FUN_1002bd50();
        DAT_10423aec = 0;
        (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,3,0);
      }
      if (DAT_10423ae4 != 4) {
        FUN_1002bd50();
        DAT_10423ae4 = 4;
        (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,1,4);
      }
      if (DAT_10423af4 != 2) {
        FUN_1002bd50();
        DAT_10423af4 = 2;
        (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,5,2);
      }
      if (DAT_10423af8 != 0) {
        FUN_1002bd50();
        DAT_10423af8 = 0;
        (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,6,0);
      }
      if (DAT_10423af0 != 4) {
        FUN_1002bd50();
        DAT_10423af0 = 4;
        (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,4,4);
      }
    }
  }
  else if (DAT_104236a4 == 0x2101) {
    if (*piVar1 == 3) {
      if (DAT_10423ae8 != 2) {
        FUN_1002bd50();
        DAT_10423ae8 = 2;
        (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,2,2);
      }
      if (DAT_10423aec != 0) {
        FUN_1002bd50();
        DAT_10423aec = 0;
        (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,3,0);
      }
      if (DAT_10423ae4 != 2) {
        FUN_1002bd50();
        DAT_10423ae4 = 2;
        (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,1,2);
      }
      if (DAT_10423af4 != 2) {
        FUN_1002bd50();
        DAT_10423af4 = 2;
        (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,5,2);
      }
      if (DAT_10423af8 != 0) {
        FUN_1002bd50();
        DAT_10423af8 = 0;
        (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,6,0);
      }
      if (DAT_10423af0 != 3) {
        FUN_1002bd50();
        DAT_10423af0 = 3;
        (**(code **)(*DAT_1042364c + 0xa0))(DAT_1042364c,0,4,3);
      }
    }
    else if (*piVar1 == 4) {
      FUN_1002be10(0,2,2);
      FUN_1002be10(0,3,0);
      uVar5 = 0xd;
      goto LAB_10023eec;
    }
  }
LAB_10023f22:
  iVar4 = DAT_1042369c;
  if (DAT_1042367c == 0) {
    DAT_10423670 = 1;
    return;
  }
  iVar2 = (&DAT_10423bd4)[DAT_1042369c * 0xc];
  piVar1 = (int *)(&DAT_10423ba8 + DAT_1042369c * 0x30);
  FUN_1002be10(1,0xd,(&DAT_10423bcc)[DAT_1042369c * 0xc]);
  FUN_1002be10(1,0xe,(&DAT_10423bd0)[iVar4 * 0xc]);
  FUN_1002be10(1,0x10,(&DAT_10423bc4)[iVar4 * 0xc]);
  FUN_1002be10(1,0x11,(&DAT_10423bc0)[iVar4 * 0xc]);
  FUN_1002be10(1,0x12,(&DAT_10423bc8)[iVar4 * 0xc]);
  if (iVar2 != DAT_10423ba4) {
    FUN_1002bd50();
    DAT_10423ba4 = iVar2;
    (**(code **)(*DAT_1042364c + 0x98))(DAT_1042364c,1,iVar2);
  }
  if (DAT_104236a8 < 0x1e02) {
    if (DAT_104236a8 == 0x1e01) {
      iVar4 = *piVar1;
      if ((iVar4 != 1) && (iVar4 != 3)) {
        if (iVar4 != 4) {
          DAT_10423670 = 1;
          return;
        }
        FUN_1002be10(1,2,2);
        FUN_1002be10(1,3,1);
        FUN_1002be10(1,1,2);
        FUN_1002be10(1,5,2);
        FUN_1002be10(1,6,1);
        uVar5 = 2;
        goto LAB_100241fc;
      }
      FUN_1002be10(1,2,2);
      FUN_1002be10(1,3,1);
      uVar5 = 2;
    }
    else {
      if (DAT_104236a8 != 0xbe2) {
        DAT_10423670 = 1;
        return;
      }
      iVar4 = *piVar1;
      if ((iVar4 != 1) && (iVar4 != 3)) {
        if (iVar4 != 4) {
          DAT_10423670 = 1;
          return;
        }
        FUN_1002be10(1,2,0x12);
        FUN_1002be10(1,3,1);
        FUN_1002be10(1,1,4);
        FUN_1002be10(1,5,2);
        FUN_1002be10(1,6,1);
        uVar5 = 4;
        goto LAB_100241fc;
      }
      FUN_1002be10(1,2,0x12);
      FUN_1002be10(1,3,1);
      uVar5 = 4;
    }
  }
  else if (DAT_104236a8 == 0x2100) {
    iVar4 = *piVar1;
    if ((iVar4 != 1) && (iVar4 != 3)) {
      if (iVar4 != 4) {
        DAT_10423670 = 1;
        return;
      }
      FUN_1002be10(1,2,2);
      FUN_1002be10(1,3,1);
      FUN_1002be10(1,1,4);
      FUN_1002be10(1,5,2);
      FUN_1002be10(1,6,1);
      uVar5 = 4;
      goto LAB_100241fc;
    }
    FUN_1002be10(1,2,2);
    FUN_1002be10(1,3,1);
    uVar5 = 4;
  }
  else {
    if (DAT_104236a8 != 0x2101) {
      DAT_10423670 = 1;
      return;
    }
    if (*piVar1 == 3) {
      FUN_1002be10(1,2,2);
      FUN_1002be10(1,3,1);
      uVar5 = 2;
    }
    else {
      if (*piVar1 != 4) {
        DAT_10423670 = 1;
        return;
      }
      FUN_1002be10(1,2,2);
      FUN_1002be10(1,3,1);
      uVar5 = 0xd;
    }
  }
  FUN_1002be10(1,1,uVar5);
  FUN_1002be10(1,5,2);
  FUN_1002be10(1,6,1);
  uVar5 = 3;
LAB_100241fc:
  FUN_1002be10(1,4,uVar5);
  DAT_10423670 = 1;
  return;
}


// glBindTexture  @ 10024220
/* __stdcall glBindTexture,8 */

void glBindTexture(undefined4 param_1,undefined4 param_2)

{
                    /* 0x24220  67  _glBindTexture@8 */
  (&DAT_10423698)[DAT_104236a0] = param_2;
  DAT_10423670 = 0;
  return;
}


// glBitmap  @ 10027130
/* __stdcall glBitmap,28 */

void glBitmap(void)

{
                    /* 0x27130  68  _glBitmap@28 */
  return;
}


// glBlendFunc  @ 10024240
/* __stdcall glBlendFunc,8 */

void glBlendFunc(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int *piStack_20;
  int *piStack_1c;
  int *piStack_18;
  int *piStack_14;
  
                    /* 0x24240  69  _glBlendFunc@8 */
  iVar2 = -1;
  iVar1 = -1;
  if (param_1 < 0x303) {
    if (param_1 == 0x302) {
      iVar2 = 5;
    }
    else if (param_1 == 0) {
      iVar2 = 1;
    }
    else if (param_1 == 1) {
      iVar2 = 2;
    }
  }
  else {
    switch(param_1) {
    case 0x303:
      iVar2 = 6;
      break;
    case 0x304:
      iVar2 = 7;
      break;
    case 0x305:
      iVar2 = 8;
      break;
    case 0x306:
      iVar2 = 9;
      break;
    case 0x307:
      iVar2 = 10;
      break;
    case 0x308:
      iVar2 = 0xb;
    }
  }
  if (param_2 < 0x301) {
    if (param_2 == 0x300) {
      iVar1 = 3;
    }
    else if (param_2 == 0) {
      iVar1 = 1;
    }
    else if (param_2 == 1) {
      iVar1 = 2;
    }
  }
  else {
    switch(param_2) {
    case 0x301:
      iVar1 = 4;
      break;
    case 0x302:
      iVar1 = 5;
      break;
    case 0x303:
      iVar1 = 6;
      break;
    case 0x304:
      iVar1 = 7;
      break;
    case 0x305:
      iVar1 = 8;
    }
  }
  if ((-1 < iVar2) && (iVar2 != DAT_1042372c)) {
    if (DAT_104234b0 != 0) {
      if (DAT_104234ac != DAT_104234a8) {
        piStack_14 = (int *)0x0;
        piStack_18 = DAT_1042364c;
        piStack_1c = DAT_104234ac;
        piStack_20 = DAT_10423654;
        (**(code **)(*DAT_10423658 + 0x14))
                  (DAT_10423658,5,DAT_104234ac,(int)DAT_104234a8 - (int)DAT_104234ac);
        DAT_104234ac = DAT_104234a8;
      }
      piStack_14 = DAT_10423654;
      piStack_18 = (int *)0x10024382;
      (**(code **)(*DAT_10423654 + 0x10))();
      piStack_18 = (int *)0x8;
      piStack_1c = (int *)DAT_104234b0;
      piStack_20 = (int *)&DAT_10453ba8;
      (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c,4,DAT_10423658);
      (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&piStack_20);
      DAT_104234ac = (int *)0x0;
      DAT_104234a8 = (int *)0x0;
      DAT_104234b0 = 0;
    }
    piStack_18 = (int *)0x13;
    piStack_1c = DAT_1042364c;
    piStack_20 = (int *)0x100243e7;
    DAT_1042372c = iVar2;
    piStack_14 = (int *)iVar2;
    (**(code **)(*DAT_1042364c + 0x58))();
  }
  if ((-1 < iVar1) && (iVar1 != DAT_10423730)) {
    if (DAT_104234b0 != 0) {
      if (DAT_104234ac != DAT_104234a8) {
        piStack_14 = (int *)0x0;
        piStack_18 = DAT_1042364c;
        piStack_1c = DAT_104234ac;
        piStack_20 = DAT_10423654;
        (**(code **)(*DAT_10423658 + 0x14))
                  (DAT_10423658,5,DAT_104234ac,(int)DAT_104234a8 - (int)DAT_104234ac);
        DAT_104234ac = DAT_104234a8;
      }
      piStack_14 = DAT_10423654;
      piStack_18 = (int *)0x10024456;
      (**(code **)(*DAT_10423654 + 0x10))();
      piStack_18 = (int *)0x8;
      piStack_1c = (int *)DAT_104234b0;
      piStack_20 = (int *)&DAT_10453ba8;
      (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c,4,DAT_10423658);
      (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&piStack_20);
      DAT_104234ac = (int *)0x0;
      DAT_104234a8 = (int *)0x0;
      DAT_104234b0 = 0;
    }
    piStack_18 = (int *)0x14;
    piStack_1c = DAT_1042364c;
    piStack_20 = (int *)0x100244bb;
    DAT_10423730 = iVar1;
    piStack_14 = (int *)iVar1;
    (**(code **)(*DAT_1042364c + 0x58))();
  }
  return;
}


// glCallList  @ 10027140
/* __stdcall glCallList,4 */

void glCallList(void)

{
                    /* 0x27140  70  _glCallList@4 */
  return;
}


// glCallLists  @ 10027150
/* __stdcall glCallLists,12 */

void glCallLists(void)

{
                    /* 0x27150  71  _glCallLists@12 */
  return;
}


// glClear  @ 100244f0
/* __stdcall glClear,4 */

void glClear(uint param_1)

{
  undefined4 uVar1;
  int *piStack_20;
  int *piStack_1c;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
                    /* 0x244f0  72  _glClear@4 */
  if (DAT_104234b0 != 0) {
    if (DAT_104234ac != DAT_104234a8) {
      piStack_1c = (int *)0x0;
      piStack_20 = DAT_1042364c;
      (**(code **)(*DAT_10423658 + 0x14))
                (DAT_10423658,5,DAT_104234ac,DAT_104234a8 - DAT_104234ac,DAT_10423654,DAT_104234ac);
      DAT_104234ac = DAT_104234a8;
    }
    piStack_1c = DAT_10423654;
    piStack_20 = (int *)0x1002454f;
    (**(code **)(*DAT_10423654 + 0x10))();
    piStack_20 = (int *)0x8;
    (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c,4,DAT_10423658,&DAT_10453ba8,DAT_104234b0);
    (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&piStack_20);
    DAT_104234ac = 0;
    DAT_104234a8 = 0;
    DAT_104234b0 = 0;
  }
  uVar1 = 0;
  if ((param_1 & 0x4000) == 0) {
    if ((param_1 & 0x100) == 0) {
      if ((param_1 & 0x400) != 0) {
        uVar1 = 4;
      }
    }
    else {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 1;
  }
  piStack_1c = (int *)0x0;
  uStack_14 = 0;
  piStack_20 = (int *)0x3f800000;
  uStack_10 = 0;
  uStack_c = DAT_104234b8;
  uStack_8 = DAT_104234bc;
  (**(code **)(*DAT_10423650 + 0x50))(DAT_10423650,1,&uStack_14,uVar1,DAT_104236b0);
  return;
}


// glClearAccum  @ 10027220
/* __stdcall glClearAccum,16 */

void glClearAccum(void)

{
                    /* 0x27220  73  _glClearAccum@16 */
  return;
}


// glClearColor  @ 10024610
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall glClearColor,16 */

void glClearColor(float param_1,float param_2,float param_3,float param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* 0x24610  74  _glClearColor@16 */
  iVar3 = (int)ROUND(param_4 * _DAT_100c8bc0);
  uVar1 = (uint)ROUND(param_3 * _DAT_100c8bc0);
  iVar4 = (int)ROUND(param_2 * _DAT_100c8bc0);
  iVar2 = (int)ROUND(_DAT_100c8bc0 * param_1);
  if (0xff < iVar3) {
    iVar3 = 0xff;
  }
  if (0xff < (int)uVar1) {
    uVar1 = 0xff;
  }
  if (0xff < iVar4) {
    iVar4 = 0xff;
  }
  if (0xff < iVar2) {
    iVar2 = 0xff;
  }
  DAT_104236b0 = uVar1 | iVar4 << 8 | iVar2 << 0x10 | iVar3 << 0x18;
  return;
}


// glClearDepth  @ 10027230
/* __stdcall glClearDepth,8 */

void glClearDepth(void)

{
                    /* 0x27230  75  _glClearDepth@8 */
  return;
}


// glClearIndex  @ 10027240
/* __stdcall glClearIndex,4 */

void glClearIndex(void)

{
                    /* 0x27240  76  _glClearIndex@4 */
  return;
}


// glClearStencil  @ 10027250
/* __stdcall glClearStencil,4 */

void glClearStencil(void)

{
                    /* 0x27250  77  _glClearStencil@4 */
  return;
}


// glClipPlane  @ 10027260
/* __stdcall glClipPlane,8 */

void glClipPlane(void)

{
                    /* 0x27260  78  _glClipPlane@8 */
  return;
}


// glColor3b  @ 10027270
/* __stdcall glColor3b,12 */

void glColor3b(void)

{
                    /* 0x27270  79  _glColor3b@12 */
  return;
}


// glColor3bv  @ 10027280
/* __stdcall glColor3bv,4 */

void glColor3bv(void)

{
                    /* 0x27280  80  _glColor3bv@4 */
  return;
}


// glColor3d  @ 10027290
/* __stdcall glColor3d,24 */

void glColor3d(void)

{
                    /* 0x27290  81  _glColor3d@24 */
  return;
}


// glColor3dv  @ 100272a0
/* __stdcall glColor3dv,4 */

void glColor3dv(void)

{
                    /* 0x272a0  82  _glColor3dv@4 */
  return;
}


// glColor3f  @ 100246a0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall glColor3f,12 */

void glColor3f(float param_1,float param_2,float param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x246a0  83  _glColor3f@12 */
  uVar1 = (uint)ROUND(param_3 * _DAT_100c8bc4);
  iVar3 = (int)ROUND(param_2 * _DAT_100c8bc4);
  iVar2 = (int)ROUND(_DAT_100c8bc4 * param_1);
  if (0xff < (int)uVar1) {
    uVar1 = 0xff;
  }
  if (0xff < iVar3) {
    iVar3 = 0xff;
  }
  if (0xff < iVar2) {
    iVar2 = 0xff;
  }
  DAT_104236ac = uVar1 | iVar3 << 8 | iVar2 << 0x10 | 0xff000000U;
  return;
}


// glColor3fv  @ 100272b0
/* __stdcall glColor3fv,4 */

void glColor3fv(void)

{
                    /* 0x272b0  84  _glColor3fv@4 */
  return;
}


// glColor3i  @ 100272c0
/* __stdcall glColor3i,12 */

void glColor3i(void)

{
                    /* 0x272c0  85  _glColor3i@12 */
  return;
}


// glColor3iv  @ 10027490
/* __stdcall glColor3iv,4 */

void glColor3iv(void)

{
                    /* 0x27490  86  _glColor3iv@4 */
  return;
}


// glColor3s  @ 100274a0
/* __stdcall glColor3s,12 */

void glColor3s(void)

{
                    /* 0x274a0  87  _glColor3s@12 */
  return;
}


// glColor3sv  @ 100274d0
/* __stdcall glColor3sv,4 */

void glColor3sv(void)

{
                    /* 0x274d0  88  _glColor3sv@4 */
  return;
}


// glColor3ub  @ 10024720
/* __stdcall glColor3ub,12 */

void glColor3ub(byte param_1,byte param_2,byte param_3)

{
                    /* 0x24720  89  _glColor3ub@12 */
  DAT_104236ac = (param_1 | 0xffffff00) << 0x10 | (uint)param_2 << 8 | (uint)param_3;
  return;
}


// glColor3ubv  @ 10024750
/* __stdcall glColor3ubv,4 */

void glColor3ubv(byte *param_1)

{
                    /* 0x24750  90  _glColor3ubv@4 */
  DAT_104236ac = (*param_1 | 0xffffff00) << 0x10 | (uint)param_1[1] << 8 | (uint)param_1[2];
  return;
}


// glColor3ui  @ 100274e0
/* __stdcall glColor3ui,12 */

void glColor3ui(void)

{
                    /* 0x274e0  91  _glColor3ui@12 */
  return;
}


// glColor3uiv  @ 10027530
/* __stdcall glColor3uiv,4 */

void glColor3uiv(void)

{
                    /* 0x27530  92  _glColor3uiv@4 */
  return;
}


// glColor3us  @ 10027540
/* __stdcall glColor3us,12 */

void glColor3us(void)

{
                    /* 0x27540  93  _glColor3us@12 */
  return;
}


// glColor3usv  @ 10027550
/* __stdcall glColor3usv,4 */

void glColor3usv(void)

{
                    /* 0x27550  94  _glColor3usv@4 */
  return;
}


// glColor4b  @ 10027560
/* __stdcall glColor4b,16 */

void glColor4b(void)

{
                    /* 0x27560  95  _glColor4b@16 */
  return;
}


// glColor4bv  @ 10027810
/* __stdcall glColor4bv,4 */

void glColor4bv(void)

{
                    /* 0x27810  96  _glColor4bv@4 */
  return;
}


// glColor4d  @ 10027820
/* __stdcall glColor4d,32 */

void glColor4d(void)

{
                    /* 0x27820  97  _glColor4d@32 */
  return;
}


// glColor4dv  @ 10027830
/* __stdcall glColor4dv,4 */

void glColor4dv(void)

{
                    /* 0x27830  98  _glColor4dv@4 */
  return;
}


// glColor4f  @ 100247e0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall glColor4f,16 */

void glColor4f(float param_1,float param_2,float param_3,float param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* 0x247e0  99  _glColor4f@16 */
  iVar3 = (int)ROUND(param_4 * _DAT_100c8bc8);
  uVar1 = (uint)ROUND(param_3 * _DAT_100c8bc8);
  iVar4 = (int)ROUND(param_2 * _DAT_100c8bc8);
  iVar2 = (int)ROUND(_DAT_100c8bc8 * param_1);
  if (0xff < iVar3) {
    iVar3 = 0xff;
  }
  if (0xff < (int)uVar1) {
    uVar1 = 0xff;
  }
  if (0xff < iVar4) {
    iVar4 = 0xff;
  }
  if (0xff < iVar2) {
    iVar2 = 0xff;
  }
  DAT_104236ac = uVar1 | iVar4 << 8 | iVar2 << 0x10 | iVar3 << 0x18;
  return;
}


// glColor4fv  @ 10024870
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall glColor4fv,4 */

void glColor4fv(float *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* 0x24870  100  _glColor4fv@4 */
  iVar3 = (int)ROUND(param_1[3] * _DAT_100c8bcc);
  uVar1 = (uint)ROUND(param_1[2] * _DAT_100c8bcc);
  iVar4 = (int)ROUND(param_1[1] * _DAT_100c8bcc);
  iVar2 = (int)ROUND(_DAT_100c8bcc * *param_1);
  if (0xff < iVar3) {
    iVar3 = 0xff;
  }
  if (0xff < (int)uVar1) {
    uVar1 = 0xff;
  }
  if (0xff < iVar4) {
    iVar4 = 0xff;
  }
  if (0xff < iVar2) {
    iVar2 = 0xff;
  }
  DAT_104236ac = uVar1 | iVar4 << 8 | iVar2 << 0x10 | iVar3 << 0x18;
  return;
}


// glColor4i  @ 10027840
/* __stdcall glColor4i,16 */

void glColor4i(void)

{
                    /* 0x27840  101  _glColor4i@16 */
  return;
}


// glColor4iv  @ 10027850
/* __stdcall glColor4iv,4 */

void glColor4iv(void)

{
                    /* 0x27850  102  _glColor4iv@4 */
  return;
}


// glColor4s  @ 10027860
/* __stdcall glColor4s,16 */

void glColor4s(void)

{
                    /* 0x27860  103  _glColor4s@16 */
  return;
}


// glColor4sv  @ 10027870
/* __stdcall glColor4sv,4 */

void glColor4sv(void)

{
                    /* 0x27870  104  _glColor4sv@4 */
  return;
}


// glColor4ub  @ 10024780
/* __stdcall glColor4ub,16 */

void glColor4ub(byte param_1,byte param_2,byte param_3,byte param_4)

{
                    /* 0x24780  105  _glColor4ub@16 */
  DAT_104236ac = ((uint)param_4 << 0x10 | (uint)param_2) << 8 | (uint)param_1 << 0x10 |
                 (uint)param_3;
  return;
}


// glColor4ubv  @ 100247b0
/* __stdcall glColor4ubv,4 */

void glColor4ubv(byte *param_1)

{
                    /* 0x247b0  106  _glColor4ubv@4 */
  DAT_104236ac = ((uint)param_1[3] << 0x10 | (uint)param_1[1]) << 8 | (uint)param_1[2] |
                 (uint)*param_1 << 0x10;
  return;
}


// glColor4ui  @ 10027880
/* __stdcall glColor4ui,16 */

void glColor4ui(void)

{
                    /* 0x27880  107  _glColor4ui@16 */
  return;
}


// glColor4uiv  @ 10027890
/* __stdcall glColor4uiv,4 */

void glColor4uiv(void)

{
                    /* 0x27890  108  _glColor4uiv@4 */
  return;
}


// glColor4us  @ 100278a0
/* __stdcall glColor4us,16 */

void glColor4us(void)

{
                    /* 0x278a0  109  _glColor4us@16 */
  return;
}


// glColor4usv  @ 100278b0
/* __stdcall glColor4usv,4 */

void glColor4usv(void)

{
                    /* 0x278b0  110  _glColor4usv@4 */
  return;
}


// glColorMask  @ 100278c0
/* __stdcall glColorMask,16 */

void glColorMask(void)

{
                    /* 0x278c0  111  _glColorMask@16 */
  return;
}


// glColorMaterial  @ 100278d0
/* __stdcall glColorMaterial,8 */

void glColorMaterial(void)

{
                    /* 0x278d0  112  _glColorMaterial@8 */
  return;
}


// glColorPointer  @ 10024900
/* __stdcall glColorPointer,16 */

void glColorPointer(int param_1,int param_2,int param_3,undefined4 param_4)

{
                    /* 0x24900  113  _glColorPointer@16 */
  DAT_104236c8 = param_4;
  if (((param_1 != 3) && (param_2 != 0x1406)) && (param_3 != 0)) {
    OutputDebugStringA(s_Wrapper__unsupported_color_array_100c8c1c);
  }
  return;
}


// glCopyPixels  @ 100278e0
/* __stdcall glCopyPixels,20 */

void glCopyPixels(void)

{
                    /* 0x278e0  114  _glCopyPixels@20 */
  return;
}


// glCopyTexImage1D  @ 100278f0
/* __stdcall glCopyTexImage1D,28 */

void glCopyTexImage1D(void)

{
                    /* 0x278f0  115  _glCopyTexImage1D@28 */
  return;
}


// glCopyTexImage2D  @ 10027900
/* __stdcall glCopyTexImage2D,32 */

void glCopyTexImage2D(void)

{
                    /* 0x27900  116  _glCopyTexImage2D@32 */
  return;
}


// glCopyTexSubImage1D  @ 10027910
/* __stdcall glCopyTexSubImage1D,24 */

void glCopyTexSubImage1D(void)

{
                    /* 0x27910  117  _glCopyTexSubImage1D@24 */
  return;
}


// glCopyTexSubImage2D  @ 10027920
/* __stdcall glCopyTexSubImage2D,32 */

void glCopyTexSubImage2D(void)

{
                    /* 0x27920  118  _glCopyTexSubImage2D@32 */
  return;
}


// glCullFace  @ 10024940
/* __stdcall glCullFace,4 */

void glCullFace(int param_1)

{
  int iVar1;
  int *piStack_20;
  int *piStack_1c;
  int *piStack_18;
  int *piStack_14;
  int *piStack_10;
  
                    /* 0x24940  119  _glCullFace@4 */
  DAT_1042365c = param_1;
  if ((DAT_1042366c == 1) && (iVar1 = 3 - (uint)(param_1 == 0x405), DAT_10423738 != iVar1)) {
    if (DAT_104234b0 != 0) {
      if (DAT_104234ac != DAT_104234a8) {
        piStack_10 = (int *)0x0;
        piStack_14 = DAT_1042364c;
        piStack_18 = (int *)DAT_104234ac;
        piStack_1c = DAT_10423654;
        piStack_20 = (int *)(DAT_104234a8 - DAT_104234ac);
        (**(code **)(*DAT_10423658 + 0x14))(DAT_10423658,5,DAT_104234ac);
        DAT_104234ac = DAT_104234a8;
      }
      piStack_10 = DAT_10423654;
      piStack_14 = (int *)0x100249d1;
      (**(code **)(*DAT_10423654 + 0x10))();
      piStack_14 = (int *)0x8;
      piStack_18 = (int *)DAT_104234b0;
      piStack_1c = (int *)&DAT_10453ba8;
      piStack_20 = DAT_10423658;
      (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c,4);
      (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&piStack_20);
      DAT_104234ac = 0;
      DAT_104234a8 = 0;
      DAT_104234b0 = 0;
    }
    piStack_14 = (int *)0x16;
    piStack_18 = DAT_1042364c;
    piStack_1c = (int *)0x10024a36;
    DAT_10423738 = iVar1;
    piStack_10 = (int *)iVar1;
    (**(code **)(*DAT_1042364c + 0x58))();
  }
  return;
}


// glDeleteLists  @ 10027930
/* __stdcall glDeleteLists,8 */

void glDeleteLists(void)

{
                    /* 0x27930  120  _glDeleteLists@8 */
  return;
}


// glDeleteTextures  @ 1002a180
/* __stdcall glDeleteTextures,8 */

void glDeleteTextures(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x2a180  121  _glDeleteTextures@8 */
  if (0 < param_1) {
    do {
      iVar1 = *param_2;
      piVar2 = (int *)(&DAT_10423bd4)[iVar1 * 0xc];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
        (&DAT_10423bd4)[iVar1 * 0xc] = 0;
      }
      piVar2 = (int *)(&DAT_10423bbc)[iVar1 * 0xc];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
        (&DAT_10423bbc)[iVar1 * 0xc] = 0;
      }
      param_2 = param_2 + 1;
      (&DAT_10423bc0)[iVar1 * 0xc] = 1;
      param_1 = param_1 + -1;
      (&DAT_10423bcc)[iVar1 * 0xc] = 1;
      (&DAT_10423bc4)[iVar1 * 0xc] = 2;
      (&DAT_10423bc8)[iVar1 * 0xc] = 3;
      (&DAT_10423bd0)[iVar1 * 0xc] = 1;
    } while (param_1 != 0);
  }
  return;
}


// glDepthFunc  @ 10024a40
/* __stdcall glDepthFunc,4 */

void glDepthFunc(undefined4 param_1)

{
  int iVar1;
  int *piStack_20;
  int *piStack_1c;
  int *piStack_18;
  int *piStack_14;
  int *piStack_10;
  
                    /* 0x24a40  122  _glDepthFunc@4 */
  iVar1 = -1;
  switch(param_1) {
  case 0x200:
    iVar1 = 1;
    break;
  case 0x201:
    iVar1 = 2;
    break;
  case 0x202:
    iVar1 = 3;
    break;
  case 0x203:
    iVar1 = 4;
    break;
  case 0x204:
    iVar1 = 5;
    break;
  case 0x205:
    iVar1 = 6;
    break;
  case 0x206:
    iVar1 = 7;
    break;
  case 0x207:
    iVar1 = 8;
  }
  if ((-1 < iVar1) && (iVar1 != DAT_1042373c)) {
    if (DAT_104234b0 != 0) {
      if (DAT_104234ac != DAT_104234a8) {
        piStack_10 = (int *)0x0;
        piStack_14 = DAT_1042364c;
        piStack_18 = (int *)DAT_104234ac;
        piStack_1c = DAT_10423654;
        piStack_20 = (int *)(DAT_104234a8 - DAT_104234ac);
        (**(code **)(*DAT_10423658 + 0x14))(DAT_10423658,5,DAT_104234ac);
        DAT_104234ac = DAT_104234a8;
      }
      piStack_10 = DAT_10423654;
      piStack_14 = (int *)0x10024b04;
      (**(code **)(*DAT_10423654 + 0x10))();
      piStack_14 = (int *)0x8;
      piStack_18 = (int *)DAT_104234b0;
      piStack_1c = (int *)&DAT_10453ba8;
      piStack_20 = DAT_10423658;
      (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c,4);
      (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&piStack_20);
      DAT_104234ac = 0;
      DAT_104234a8 = 0;
      DAT_104234b0 = 0;
    }
    piStack_14 = (int *)0x17;
    piStack_18 = DAT_1042364c;
    piStack_1c = (int *)0x10024b69;
    DAT_1042373c = iVar1;
    piStack_10 = (int *)iVar1;
    (**(code **)(*DAT_1042364c + 0x58))();
  }
  return;
}


// glDepthMask  @ 10024ba0
/* __stdcall glDepthMask,4 */

void glDepthMask(char param_1)

{
  int iStack_20;
  int *piStack_1c;
  int *piStack_18;
  int *piStack_14;
  int *piStack_10;
  int *piStack_c;
  
                    /* 0x24ba0  123  _glDepthMask@4 */
  if (param_1 == '\0') {
    if (DAT_10423718 != 0) {
      if (DAT_104234b0 != 0) {
        if (DAT_104234ac != DAT_104234a8) {
          piStack_c = (int *)0x0;
          piStack_10 = DAT_1042364c;
          piStack_14 = (int *)DAT_104234ac;
          piStack_18 = DAT_10423654;
          piStack_1c = (int *)(DAT_104234a8 - DAT_104234ac);
          iStack_20 = DAT_104234ac;
          (**(code **)(*DAT_10423658 + 0x14))(DAT_10423658,5);
          DAT_104234ac = DAT_104234a8;
        }
        piStack_c = DAT_10423654;
        piStack_10 = (int *)0x10024c17;
        (**(code **)(*DAT_10423654 + 0x10))();
        piStack_10 = (int *)0x8;
        piStack_14 = (int *)DAT_104234b0;
        piStack_18 = (int *)&DAT_10453ba8;
        piStack_1c = DAT_10423658;
        iStack_20 = 4;
        (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c);
        (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&iStack_20);
        DAT_104234ac = 0;
        DAT_104234a8 = 0;
        DAT_104234b0 = 0;
      }
      piStack_c = (int *)0x0;
      DAT_10423718 = 0;
      piStack_10 = (int *)0xe;
      piStack_14 = DAT_1042364c;
      piStack_18 = (int *)0x10024c81;
      (**(code **)(*DAT_1042364c + 0x58))();
      return;
    }
  }
  else if (DAT_10423718 != 1) {
    if (DAT_104234b0 != 0) {
      if (DAT_104234ac != DAT_104234a8) {
        piStack_c = (int *)0x0;
        piStack_10 = DAT_1042364c;
        piStack_14 = (int *)DAT_104234ac;
        piStack_18 = DAT_10423654;
        piStack_1c = (int *)(DAT_104234a8 - DAT_104234ac);
        iStack_20 = DAT_104234ac;
        (**(code **)(*DAT_10423658 + 0x14))(DAT_10423658,5);
        DAT_104234ac = DAT_104234a8;
      }
      piStack_c = DAT_10423654;
      piStack_10 = (int *)0x10024ceb;
      (**(code **)(*DAT_10423654 + 0x10))();
      piStack_10 = (int *)0x8;
      piStack_14 = (int *)DAT_104234b0;
      piStack_18 = (int *)&DAT_10453ba8;
      piStack_1c = DAT_10423658;
      iStack_20 = 4;
      (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c);
      (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&iStack_20);
      DAT_104234ac = 0;
      DAT_104234a8 = 0;
      DAT_104234b0 = 0;
    }
    piStack_c = (int *)0x1;
    DAT_10423718 = 1;
    piStack_10 = (int *)0xe;
    piStack_14 = DAT_1042364c;
    piStack_18 = (int *)0x10024d55;
    (**(code **)(*DAT_1042364c + 0x58))();
  }
  return;
}


// glDepthRange  @ 10024d60
/* decompile failed: 
Low-level Error: Symbol $$undef0000003d extends beyond the end of the address space */


// glDisable  @ 10024e90
/* __stdcall glDisable,4 */

void glDisable(uint param_1)

{
  int *piStack_4c;
  int *piStack_48;
  int *piStack_44;
  int *piStack_40;
  
                    /* 0x24e90  125  _glDisable@4 */
  if (param_1 < 0xb61) {
    if (param_1 == 0xb60) {
      if (DAT_10423750 != 0) {
        FUN_1002bd50();
        DAT_10423750 = 0;
        piStack_40 = (int *)0x1c;
        piStack_44 = DAT_1042364c;
        piStack_48 = (int *)0x10024f72;
        (**(code **)(*DAT_1042364c + 0x58))();
      }
      if (DAT_104237a0 != 0) {
        FUN_1002bd50();
        DAT_104237a0 = 0;
        piStack_40 = (int *)0x30;
        piStack_44 = DAT_1042364c;
        piStack_48 = (int *)0x10024f9d;
        (**(code **)(*DAT_1042364c + 0x58))();
        return;
      }
    }
    else {
      if (param_1 != 0xb44) goto LAB_10024efa;
      DAT_1042366c = 0;
      if (DAT_10423738 != 1) {
        FUN_1002bd50();
        DAT_10423738 = 1;
        piStack_40 = (int *)0x16;
        piStack_44 = DAT_1042364c;
        piStack_48 = (int *)0x10024f43;
        (**(code **)(*DAT_1042364c + 0x58))();
        return;
      }
    }
  }
  else if (param_1 < 0xbc1) {
    if (param_1 == 0xbc0) {
      if (DAT_1042371c != 0) {
        FUN_1002bd50();
        DAT_1042371c = 0;
        piStack_40 = (int *)0xf;
        piStack_44 = DAT_1042364c;
        piStack_48 = (int *)0x10025003;
        (**(code **)(*DAT_1042364c + 0x58))();
        return;
      }
    }
    else {
      if (param_1 != 0xb71) goto LAB_10024efa;
      if (DAT_104236fc != 0) {
        FUN_1002bd50();
        DAT_104236fc = 0;
        piStack_40 = (int *)0x7;
        piStack_44 = DAT_1042364c;
        piStack_48 = (int *)0x10024fd0;
        (**(code **)(*DAT_1042364c + 0x58))();
        return;
      }
    }
  }
  else if (param_1 < 0xc12) {
    if (param_1 != 0xc11) {
      if (param_1 != 0xbe2) goto LAB_10024efa;
      if (DAT_1042374c != 0) {
        FUN_1002bd50();
        DAT_1042374c = 0;
        piStack_40 = (int *)0x1b;
        piStack_44 = DAT_1042364c;
        piStack_48 = (int *)0x10025036;
        (**(code **)(*DAT_1042364c + 0x58))();
        return;
      }
    }
  }
  else {
    if (param_1 == 0xde1) {
      if (DAT_104236a0 == 0) {
        if (DAT_10423ae4 != 1) {
          if (DAT_104234b0 != 0) {
            FUN_1002bf10();
            piStack_40 = (int *)0x10025074;
            (**(code **)(*DAT_10423654 + 0x10))();
            piStack_40 = (int *)0x8;
            piStack_44 = (int *)DAT_104234b0;
            piStack_48 = (int *)&DAT_10453ba8;
            piStack_4c = DAT_10423658;
            (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c,4);
            (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&piStack_4c);
            DAT_104234ac = (int *)0x0;
            DAT_104234a8 = (int *)0x0;
            DAT_104234b0 = 0;
          }
          DAT_10423ae4 = 1;
          piStack_40 = (int *)0x1;
          piStack_44 = (int *)0x0;
          piStack_48 = DAT_1042364c;
          piStack_4c = (int *)0x100250e4;
          (**(code **)(*DAT_1042364c + 0xa0))();
        }
        if (DAT_10423af0 != 1) {
          FUN_1002bd50();
          DAT_10423af0 = 1;
          piStack_40 = (int *)0x4;
          piStack_44 = (int *)0x0;
          piStack_48 = DAT_1042364c;
          piStack_4c = (int *)0x10025111;
          (**(code **)(*DAT_1042364c + 0xa0))();
        }
        DAT_10423674 = 0;
      }
      else {
        if (DAT_10423b44 != 1) {
          FUN_1002bd50();
          DAT_10423b44 = 1;
          piStack_40 = (int *)0x1;
          piStack_44 = (int *)0x1;
          piStack_48 = DAT_1042364c;
          piStack_4c = (int *)0x1002514a;
          (**(code **)(*DAT_1042364c + 0xa0))();
        }
        if (DAT_10423b50 != 1) {
          FUN_1002bd50();
          DAT_10423b50 = 1;
          piStack_40 = (int *)0x4;
          piStack_44 = (int *)0x1;
          piStack_48 = DAT_1042364c;
          piStack_4c = (int *)0x10025177;
          (**(code **)(*DAT_1042364c + 0xa0))();
        }
        DAT_1042367c = 0;
      }
      DAT_10423670 = 0;
      return;
    }
    if (param_1 != 0x8037) {
LAB_10024efa:
      piStack_40 = (int *)0x10024f05;
      OutputDebugStringA(s_Wrapper__glDisable_on_this_cap_n_100c8c40);
      return;
    }
    if (DAT_104234b0 != 0) {
      if (DAT_104234ac != DAT_104234a8) {
        piStack_40 = DAT_1042364c;
        piStack_44 = DAT_104234ac;
        piStack_48 = DAT_10423654;
        piStack_4c = (int *)((int)DAT_104234a8 - (int)DAT_104234ac);
        (**(code **)(*DAT_10423658 + 0x14))(DAT_10423658,5,DAT_104234ac);
        DAT_104234ac = DAT_104234a8;
      }
      piStack_40 = (int *)0x100251ed;
      (**(code **)(*DAT_10423654 + 0x10))();
      piStack_40 = (int *)0x8;
      piStack_44 = (int *)DAT_104234b0;
      piStack_48 = (int *)&DAT_10453ba8;
      piStack_4c = DAT_10423658;
      (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c,4);
      (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&piStack_4c);
      DAT_104234ac = (int *)0x0;
      DAT_104234a8 = (int *)0x0;
      DAT_104234b0 = 0;
    }
    piStack_40 = DAT_10423650;
    piStack_44 = (int *)0x10025257;
    (**(code **)(*DAT_10423650 + 0x40))();
    piStack_44 = (int *)&stack0xffffffcc;
    piStack_48 = DAT_10423650;
    piStack_4c = (int *)0x10025271;
    (**(code **)(*DAT_10423650 + 0x44))();
  }
  return;
}


// glDisableClientState  @ 10025280
/* __stdcall glDisableClientState,4 */

void glDisableClientState(int param_1)

{
                    /* 0x25280  126  _glDisableClientState@4 */
  if ((param_1 != 0x8074) && (param_1 != 0x8076)) {
    OutputDebugStringA(s_Wrapper__array_not_supported_100c8c70);
  }
  return;
}


// glDrawArrays  @ 10027940
/* __stdcall glDrawArrays,12 */

void glDrawArrays(void)

{
                    /* 0x27940  127  _glDrawArrays@12 */
  return;
}


// glDrawBuffer  @ 100252a0
/* __stdcall glDrawBuffer,4 */

void glDrawBuffer(void)

{
                    /* 0x252a0  128  _glDrawBuffer@4 */
  return;
}


// glDrawElements  @ 10027950
/* __stdcall glDrawElements,16 */

void glDrawElements(void)

{
                    /* 0x27950  129  _glDrawElements@16 */
  return;
}


// glDrawPixels  @ 10027960
/* __stdcall glDrawPixels,20 */

void glDrawPixels(void)

{
                    /* 0x27960  130  _glDrawPixels@20 */
  return;
}


// glEdgeFlag  @ 10027970
/* __stdcall glEdgeFlag,4 */

void glEdgeFlag(void)

{
                    /* 0x27970  131  _glEdgeFlag@4 */
  return;
}


// glEdgeFlagPointer  @ 10027980
/* __stdcall glEdgeFlagPointer,8 */

void glEdgeFlagPointer(void)

{
                    /* 0x27980  132  _glEdgeFlagPointer@8 */
  return;
}


// glEdgeFlagv  @ 10027990
/* __stdcall glEdgeFlagv,4 */

void glEdgeFlagv(void)

{
                    /* 0x27990  133  _glEdgeFlagv@4 */
  return;
}


// glEnable  @ 100252b0
/* __stdcall glEnable,4 */

void glEnable(uint param_1)

{
  undefined4 uStack_4c;
  undefined *puStack_48;
  int *piStack_44;
  int *piStack_40;
  undefined4 uStack_c;
  
                    /* 0x252b0  134  _glEnable@4 */
  if (param_1 < 0xb61) {
    if (param_1 == 0xb60) {
      if (DAT_10423750 != 1) {
        FUN_1002bd50();
        DAT_10423750 = 1;
        piStack_40 = (int *)0x1c;
        piStack_44 = DAT_1042364c;
        puStack_48 = (undefined *)0x100254a2;
        (**(code **)(*DAT_1042364c + 0x58))();
      }
      if (DAT_104237a0 != 1) {
        if (DAT_104234b0 != 0) {
          FUN_1002bf10();
          piStack_40 = (int *)0x100254cb;
          (**(code **)(*DAT_10423654 + 0x10))();
          piStack_40 = (int *)0x8;
          piStack_44 = (int *)DAT_104234b0;
          puStack_48 = &DAT_10453ba8;
          uStack_4c = DAT_10423658;
          (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c,4);
          (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&uStack_4c);
          DAT_104234ac = 0;
          DAT_104234a8 = 0;
          DAT_104234b0 = 0;
        }
        DAT_104237a0 = 1;
        piStack_40 = (int *)0x30;
        piStack_44 = DAT_1042364c;
        puStack_48 = (undefined *)0x10025536;
        (**(code **)(*DAT_1042364c + 0x58))();
        return;
      }
    }
    else {
      if (param_1 != 0xb44) goto LAB_1002531a;
      DAT_1042366c = 1;
      if (DAT_1042365c == 0x405) {
        if (DAT_10423738 != 2) {
          if (DAT_104234b0 != 0) {
            FUN_1002bf10();
            piStack_40 = (int *)0x10025370;
            (**(code **)(*DAT_10423654 + 0x10))();
            piStack_40 = (int *)0x8;
            piStack_44 = (int *)DAT_104234b0;
            puStack_48 = &DAT_10453ba8;
            uStack_4c = DAT_10423658;
            (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c,4);
            (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&uStack_4c);
            DAT_104234ac = 0;
            DAT_104234a8 = 0;
            DAT_104234b0 = 0;
          }
          DAT_10423738 = 2;
          piStack_40 = (int *)0x16;
          piStack_44 = DAT_1042364c;
          puStack_48 = (undefined *)0x100253db;
          (**(code **)(*DAT_1042364c + 0x58))();
          return;
        }
      }
      else if (DAT_10423738 != 3) {
        if (DAT_104234b0 != 0) {
          FUN_1002bf10();
          piStack_40 = (int *)0x10025407;
          (**(code **)(*DAT_10423654 + 0x10))();
          piStack_40 = (int *)0x8;
          piStack_44 = (int *)DAT_104234b0;
          puStack_48 = &DAT_10453ba8;
          uStack_4c = DAT_10423658;
          (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c,4);
          (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&uStack_4c);
          DAT_104234ac = 0;
          DAT_104234a8 = 0;
          DAT_104234b0 = 0;
        }
        DAT_10423738 = 3;
        piStack_40 = (int *)0x16;
        piStack_44 = DAT_1042364c;
        puStack_48 = (undefined *)0x10025472;
        (**(code **)(*DAT_1042364c + 0x58))();
        return;
      }
    }
  }
  else if (param_1 < 0xbc1) {
    if (param_1 == 0xbc0) {
      if (DAT_1042371c != 1) {
        if (DAT_104234b0 != 0) {
          FUN_1002bf10();
          piStack_40 = (int *)0x10025603;
          (**(code **)(*DAT_10423654 + 0x10))();
          piStack_40 = (int *)0x8;
          piStack_44 = (int *)DAT_104234b0;
          puStack_48 = &DAT_10453ba8;
          uStack_4c = DAT_10423658;
          (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c,4);
          (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&uStack_4c);
          DAT_104234ac = 0;
          DAT_104234a8 = 0;
          DAT_104234b0 = 0;
        }
        DAT_1042371c = 1;
        piStack_40 = (int *)0xf;
        piStack_44 = DAT_1042364c;
        puStack_48 = (undefined *)0x1002566e;
        (**(code **)(*DAT_1042364c + 0x58))();
        return;
      }
    }
    else {
      if (param_1 != 0xb71) goto LAB_1002531a;
      if (DAT_104236fc != 1) {
        if (DAT_104234b0 != 0) {
          FUN_1002bf10();
          piStack_40 = (int *)0x10025567;
          (**(code **)(*DAT_10423654 + 0x10))();
          piStack_40 = (int *)0x8;
          piStack_44 = (int *)DAT_104234b0;
          puStack_48 = &DAT_10453ba8;
          uStack_4c = DAT_10423658;
          (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c,4);
          (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&uStack_4c);
          DAT_104234ac = 0;
          DAT_104234a8 = 0;
          DAT_104234b0 = 0;
        }
        DAT_104236fc = 1;
        piStack_40 = (int *)0x7;
        piStack_44 = DAT_1042364c;
        puStack_48 = (undefined *)0x100255d2;
        (**(code **)(*DAT_1042364c + 0x58))();
        return;
      }
    }
  }
  else if (param_1 < 0xc12) {
    if (param_1 != 0xc11) {
      if (param_1 != 0xbe2) goto LAB_1002531a;
      if (DAT_1042374c != 1) {
        FUN_1002bd50();
        DAT_1042374c = 1;
        piStack_40 = (int *)0x1b;
        piStack_44 = DAT_1042364c;
        puStack_48 = (undefined *)0x1002569e;
        (**(code **)(*DAT_1042364c + 0x58))();
        return;
      }
    }
  }
  else {
    if (param_1 == 0xde1) {
      if (DAT_104236a0 == 0) {
        DAT_10423674 = 1;
      }
      else {
        DAT_1042367c = 1;
      }
      DAT_10423670 = 0;
      return;
    }
    if (param_1 != 0x8037) {
LAB_1002531a:
      piStack_40 = (int *)0x10025325;
      OutputDebugStringA(s_Wrapper__glEnable_on_this_cap_no_100c8c90);
      return;
    }
    piStack_40 = DAT_10423650;
    piStack_44 = (int *)0x100256f0;
    (**(code **)(*DAT_10423650 + 0x40))();
    DAT_10423668 = uStack_c;
  }
  return;
}


// glEnableClientState  @ 10025710
/* __stdcall glEnableClientState,4 */

void glEnableClientState(int param_1)

{
                    /* 0x25710  135  _glEnableClientState@4 */
  if ((param_1 != 0x8074) && (param_1 != 0x8076)) {
    OutputDebugStringA(s_Wrapper__array_not_supported_100c8cc0);
  }
  return;
}


// glEnd  @ 10025730
/* __stdcall glEnd,0 */

void glEnd(void)

{
  int iVar1;
  short sVar2;
  int iVar3;
  
                    /* 0x25730  136  _glEnd@0 */
  switch(DAT_10423664) {
  case 4:
    iVar3 = 0;
    if (0 < DAT_104234b4) {
      do {
        *(short *)(&DAT_10453ba8 + DAT_104234b0 * 2) = (short)DAT_104234a8;
        iVar3 = iVar3 + 1;
        DAT_104234a8 = DAT_104234a8 + 1;
        DAT_104234b0 = DAT_104234b0 + 1;
      } while (iVar3 < DAT_104234b4);
      return;
    }
    break;
  case 5:
    iVar3 = 0;
    DAT_104234b4 = DAT_104234b4 + -2;
    if (0 < DAT_104234b4) {
      do {
        *(short *)(&DAT_10453ba8 + DAT_104234b0 * 2) = (short)DAT_104234a8;
        DAT_104234b0 = DAT_104234b0 + 1;
        *(short *)(&DAT_10453ba8 + DAT_104234b0 * 2) = (short)DAT_104234a8 + 1;
        DAT_104234b0 = DAT_104234b0 + 1;
        *(short *)(&DAT_10453ba8 + DAT_104234b0 * 2) = (short)DAT_104234a8 + 2;
        DAT_104234b0 = DAT_104234b0 + 1;
        iVar1 = DAT_104234a8 + 1;
        if (iVar3 + 1 < DAT_104234b4) {
          sVar2 = (short)DAT_104234a8;
          DAT_104234a8 = DAT_104234a8 + 1;
          *(short *)(&DAT_10453ba8 + DAT_104234b0 * 2) = sVar2 + 2;
          DAT_104234b0 = DAT_104234b0 + 1;
          *(short *)(&DAT_10453ba8 + DAT_104234b0 * 2) = (short)DAT_104234a8;
          DAT_104234b0 = DAT_104234b0 + 1;
          *(short *)(&DAT_10453ba8 + DAT_104234b0 * 2) = (short)DAT_104234a8 + 2;
          DAT_104234b0 = DAT_104234b0 + 1;
          iVar1 = DAT_104234a8 + 1;
        }
        DAT_104234a8 = iVar1;
        iVar3 = iVar3 + 2;
      } while (iVar3 < DAT_104234b4);
    }
    DAT_104234a8 = DAT_104234a8 + 2;
    return;
  case 6:
  case 9:
    iVar3 = 1;
    DAT_104234b4 = DAT_104234b4 + -1;
    if (1 < DAT_104234b4) {
      do {
        *(short *)(&DAT_10453ba8 + DAT_104234b0 * 2) = (short)DAT_104234a8;
        DAT_104234b0 = DAT_104234b0 + 1;
        sVar2 = (short)iVar3;
        *(short *)(&DAT_10453ba8 + DAT_104234b0 * 2) = (short)DAT_104234a8 + sVar2;
        DAT_104234b0 = DAT_104234b0 + 1;
        iVar3 = iVar3 + 1;
        *(short *)(&DAT_10453ba8 + DAT_104234b0 * 2) = (short)DAT_104234a8 + sVar2 + 1;
        DAT_104234b0 = DAT_104234b0 + 1;
      } while (iVar3 < DAT_104234b4);
    }
    DAT_104234a8 = DAT_104234a8 + DAT_104234b4 + 1;
    return;
  case 7:
    iVar3 = 0;
    if (0 < DAT_104234b4) {
      do {
        *(short *)(&DAT_10453ba8 + DAT_104234b0 * 2) = (short)DAT_104234a8;
        iVar3 = iVar3 + 4;
        DAT_104234b0 = DAT_104234b0 + 1;
        *(short *)(&DAT_10453ba8 + DAT_104234b0 * 2) = (short)DAT_104234a8 + 1;
        DAT_104234b0 = DAT_104234b0 + 1;
        *(short *)(&DAT_10453ba8 + DAT_104234b0 * 2) = (short)DAT_104234a8 + 2;
        DAT_104234b0 = DAT_104234b0 + 1;
        *(short *)(&DAT_10453ba8 + DAT_104234b0 * 2) = (short)DAT_104234a8;
        DAT_104234b0 = DAT_104234b0 + 1;
        *(short *)(&DAT_10453ba8 + DAT_104234b0 * 2) = (short)DAT_104234a8 + 2;
        DAT_104234b0 = DAT_104234b0 + 1;
        *(short *)(&DAT_10453ba8 + DAT_104234b0 * 2) = (short)DAT_104234a8 + 3;
        DAT_104234b0 = DAT_104234b0 + 1;
        DAT_104234a8 = DAT_104234a8 + 4;
      } while (iVar3 < DAT_104234b4);
    }
  }
  return;
}


// glEndList  @ 100279a0
/* __stdcall glEndList,0 */

void glEndList(void)

{
                    /* 0x279a0  137  _glEndList@0 */
  return;
}


// glEvalCoord1d  @ 10027a70
/* __stdcall glEvalCoord1d,8 */

void glEvalCoord1d(void)

{
                    /* 0x27a70  138  _glEvalCoord1d@8 */
  return;
}


// glEvalCoord1dv  @ 10027a80
/* __stdcall glEvalCoord1dv,4 */

void glEvalCoord1dv(void)

{
                    /* 0x27a80  139  _glEvalCoord1dv@4 */
  return;
}


// glEvalCoord1f  @ 10027a90
/* __stdcall glEvalCoord1f,4 */

void glEvalCoord1f(void)

{
                    /* 0x27a90  140  _glEvalCoord1f@4 */
  return;
}


// glEvalCoord1fv  @ 10027aa0
/* __stdcall glEvalCoord1fv,4 */

void glEvalCoord1fv(void)

{
                    /* 0x27aa0  141  _glEvalCoord1fv@4 */
  return;
}


// glEvalCoord2d  @ 10027ab0
/* __stdcall glEvalCoord2d,16 */

void glEvalCoord2d(void)

{
                    /* 0x27ab0  142  _glEvalCoord2d@16 */
  return;
}


// glEvalCoord2dv  @ 10027ac0
/* __stdcall glEvalCoord2dv,4 */

void glEvalCoord2dv(void)

{
                    /* 0x27ac0  143  _glEvalCoord2dv@4 */
  return;
}


// glEvalCoord2f  @ 10027ad0
/* __stdcall glEvalCoord2f,8 */

void glEvalCoord2f(void)

{
                    /* 0x27ad0  144  _glEvalCoord2f@8 */
  return;
}


// glEvalCoord2fv  @ 10027ae0
/* __stdcall glEvalCoord2fv,4 */

void glEvalCoord2fv(void)

{
                    /* 0x27ae0  145  _glEvalCoord2fv@4 */
  return;
}


// glEvalMesh1  @ 10027af0
/* __stdcall glEvalMesh1,12 */

void glEvalMesh1(void)

{
                    /* 0x27af0  146  _glEvalMesh1@12 */
  return;
}


// glEvalMesh2  @ 10027b80
/* __stdcall glEvalMesh2,20 */

void glEvalMesh2(void)

{
                    /* 0x27b80  147  _glEvalMesh2@20 */
  return;
}


// glEvalPoint1  @ 10027b90
/* __stdcall glEvalPoint1,4 */

void glEvalPoint1(void)

{
                    /* 0x27b90  148  _glEvalPoint1@4 */
  return;
}


// glEvalPoint2  @ 10027ba0
/* __stdcall glEvalPoint2,8 */

void glEvalPoint2(void)

{
                    /* 0x27ba0  149  _glEvalPoint2@8 */
  return;
}


// glFeedbackBuffer  @ 10027bb0
/* __stdcall glFeedbackBuffer,12 */

void glFeedbackBuffer(void)

{
                    /* 0x27bb0  150  _glFeedbackBuffer@12 */
  return;
}


// glFinish  @ 10027bc0
/* __stdcall glFinish,0 */

void glFinish(void)

{
                    /* 0x27bc0  151  _glFinish@0 */
  return;
}


// glFlush  @ 10027bd0
/* __stdcall glFlush,0 */

void glFlush(void)

{
                    /* 0x27bd0  152  _glFlush@0 */
  return;
}


// glFogf  @ 10025a40
/* __stdcall glFogf,8 */

void glFogf(int param_1,int param_2)

{
  int iStack_20;
  int *piStack_1c;
  int *piStack_18;
  int *piStack_14;
  int *piStack_10;
  int *piStack_c;
  
                    /* 0x25a40  153  _glFogf@8 */
  if (param_1 == 0xb63) {
    if (param_2 != DAT_10423770) {
      if (DAT_104234b0 != 0) {
        if (DAT_104234ac != DAT_104234a8) {
          piStack_c = (int *)0x0;
          piStack_10 = DAT_1042364c;
          piStack_14 = (int *)DAT_104234ac;
          piStack_18 = DAT_10423654;
          piStack_1c = (int *)(DAT_104234a8 - DAT_104234ac);
          iStack_20 = DAT_104234ac;
          (**(code **)(*DAT_10423658 + 0x14))(DAT_10423658,5);
          DAT_104234ac = DAT_104234a8;
        }
        piStack_c = DAT_10423654;
        piStack_10 = (int *)0x10025acd;
        (**(code **)(*DAT_10423654 + 0x10))();
        piStack_10 = (int *)0x8;
        piStack_14 = (int *)DAT_104234b0;
        piStack_18 = (int *)&DAT_10453ba8;
        piStack_1c = DAT_10423658;
        iStack_20 = 4;
        (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c);
        (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&iStack_20);
        DAT_104234ac = 0;
        DAT_104234a8 = 0;
        DAT_104234b0 = 0;
      }
      piStack_c = (int *)param_2;
      DAT_10423770 = param_2;
      piStack_10 = (int *)0x24;
      piStack_14 = DAT_1042364c;
      piStack_18 = (int *)0x10025b36;
      (**(code **)(*DAT_1042364c + 0x58))();
      return;
    }
  }
  else {
    if (param_1 != 0xb64) {
      return;
    }
    if (param_2 != DAT_10423774) {
      if (DAT_104234b0 != 0) {
        if (DAT_104234ac != DAT_104234a8) {
          piStack_c = (int *)0x0;
          piStack_10 = DAT_1042364c;
          piStack_14 = (int *)DAT_104234ac;
          piStack_18 = DAT_10423654;
          piStack_1c = (int *)(DAT_104234a8 - DAT_104234ac);
          iStack_20 = DAT_104234ac;
          (**(code **)(*DAT_10423658 + 0x14))(DAT_10423658,5);
          DAT_104234ac = DAT_104234a8;
        }
        piStack_c = DAT_10423654;
        piStack_10 = (int *)0x10025ba8;
        (**(code **)(*DAT_10423654 + 0x10))();
        piStack_10 = (int *)0x8;
        piStack_14 = (int *)DAT_104234b0;
        piStack_18 = (int *)&DAT_10453ba8;
        piStack_1c = DAT_10423658;
        iStack_20 = 4;
        (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c);
        (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&iStack_20);
        DAT_104234ac = 0;
        DAT_104234a8 = 0;
        DAT_104234b0 = 0;
      }
      piStack_c = (int *)param_2;
      DAT_10423774 = param_2;
      piStack_10 = (int *)0x25;
      piStack_14 = DAT_1042364c;
      piStack_18 = (int *)0x10025c11;
      (**(code **)(*DAT_1042364c + 0x58))();
    }
  }
  return;
}


// glFogfv  @ 10025c20
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall glFogfv,8 */

void glFogfv(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piStack_20;
  int *piStack_1c;
  int *piStack_18;
  int *piStack_14;
  
                    /* 0x25c20  154  _glFogfv@8 */
  piStack_14 = (int *)0x10025c38;
  iVar1 = __ftol();
  piStack_14 = (int *)0x10025c48;
  uVar2 = __ftol();
  piStack_14 = (int *)0x10025c5a;
  iVar3 = __ftol();
  piStack_14 = (int *)0x10025c70;
  uVar4 = __ftol();
  uVar4 = (iVar1 << 0x10 | uVar2) << 8 | iVar3 << 0x10 | uVar4;
  _DAT_100c8bd0 = uVar4;
  if (uVar4 != DAT_10423768) {
    if (DAT_104234b0 != 0) {
      if (DAT_104234ac != DAT_104234a8) {
        piStack_14 = (int *)0x0;
        piStack_18 = DAT_1042364c;
        piStack_1c = (int *)DAT_104234ac;
        piStack_20 = DAT_10423654;
        (**(code **)(*DAT_10423658 + 0x14))(DAT_10423658,5,DAT_104234ac,DAT_104234a8 - DAT_104234ac)
        ;
        DAT_104234ac = DAT_104234a8;
      }
      piStack_14 = DAT_10423654;
      piStack_18 = (int *)0x10025cdf;
      (**(code **)(*DAT_10423654 + 0x10))();
      piStack_18 = (int *)0x8;
      piStack_1c = (int *)DAT_104234b0;
      piStack_20 = (int *)&DAT_10453ba8;
      (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c,4,DAT_10423658);
      (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&piStack_20);
      DAT_104234ac = 0;
      DAT_104234a8 = 0;
      DAT_104234b0 = 0;
    }
    piStack_18 = (int *)0x22;
    piStack_1c = DAT_1042364c;
    piStack_20 = (int *)0x10025d44;
    DAT_10423768 = uVar4;
    piStack_14 = (int *)uVar4;
    (**(code **)(*DAT_1042364c + 0x58))();
  }
  return;
}


// glFogi  @ 10025d50
/* __stdcall glFogi,8 */

void glFogi(int param_1,int param_2)

{
  int *piStack_20;
  int *piStack_1c;
  int *piStack_18;
  int *piStack_14;
  int *piStack_10;
  
                    /* 0x25d50  155  _glFogi@8 */
  if (param_1 == 0xb65) {
    if (param_2 == 0x800) {
      if (DAT_1042376c != 1) {
        if (DAT_104234b0 != 0) {
          if (DAT_104234ac != DAT_104234a8) {
            piStack_10 = (int *)0x0;
            piStack_14 = DAT_1042364c;
            piStack_18 = (int *)DAT_104234ac;
            piStack_1c = DAT_10423654;
            piStack_20 = (int *)(DAT_104234a8 - DAT_104234ac);
            (**(code **)(*DAT_10423658 + 0x14))(DAT_10423658,5,DAT_104234ac);
            DAT_104234ac = DAT_104234a8;
          }
          piStack_10 = DAT_10423654;
          piStack_14 = (int *)0x10025e8d;
          (**(code **)(*DAT_10423654 + 0x10))();
          piStack_14 = (int *)0x8;
          piStack_18 = (int *)DAT_104234b0;
          piStack_1c = (int *)&DAT_10453ba8;
          piStack_20 = DAT_10423658;
          (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c,4);
          (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&piStack_20);
          DAT_104234ac = 0;
          DAT_104234a8 = 0;
          DAT_104234b0 = 0;
        }
        piStack_10 = (int *)0x1;
        DAT_1042376c = 1;
        piStack_14 = (int *)0x23;
        piStack_18 = DAT_1042364c;
        piStack_1c = (int *)0x10025ef7;
        (**(code **)(*DAT_1042364c + 0x58))();
        return;
      }
    }
    else if (param_2 == 0x801) {
      if (DAT_1042376c != 2) {
        if (DAT_104234b0 != 0) {
          if (DAT_104234ac != DAT_104234a8) {
            piStack_10 = (int *)0x0;
            piStack_14 = DAT_1042364c;
            piStack_18 = (int *)DAT_104234ac;
            piStack_1c = DAT_10423654;
            piStack_20 = (int *)(DAT_104234a8 - DAT_104234ac);
            (**(code **)(*DAT_10423658 + 0x14))(DAT_10423658,5,DAT_104234ac);
            DAT_104234ac = DAT_104234a8;
          }
          piStack_10 = DAT_10423654;
          piStack_14 = (int *)0x10025f67;
          (**(code **)(*DAT_10423654 + 0x10))();
          piStack_14 = (int *)0x8;
          piStack_18 = (int *)DAT_104234b0;
          piStack_1c = (int *)&DAT_10453ba8;
          piStack_20 = DAT_10423658;
          (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c,4);
          (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&piStack_20);
          DAT_104234ac = 0;
          DAT_104234a8 = 0;
          DAT_104234b0 = 0;
        }
        piStack_10 = (int *)0x2;
        DAT_1042376c = 2;
        piStack_14 = (int *)0x23;
        piStack_18 = DAT_1042364c;
        piStack_1c = (int *)0x10025fd1;
        (**(code **)(*DAT_1042364c + 0x58))();
        return;
      }
    }
    else if (param_2 == 0x2601) {
      if (DAT_1042376c != 3) {
        if (DAT_104234b0 != 0) {
          if (DAT_104234ac != DAT_104234a8) {
            piStack_10 = (int *)0x0;
            piStack_14 = DAT_1042364c;
            piStack_18 = (int *)DAT_104234ac;
            piStack_1c = DAT_10423654;
            piStack_20 = (int *)(DAT_104234a8 - DAT_104234ac);
            (**(code **)(*DAT_10423658 + 0x14))(DAT_10423658,5,DAT_104234ac);
            DAT_104234ac = DAT_104234a8;
          }
          piStack_10 = DAT_10423654;
          piStack_14 = (int *)0x10026041;
          (**(code **)(*DAT_10423654 + 0x10))();
          piStack_14 = (int *)0x8;
          piStack_18 = (int *)DAT_104234b0;
          piStack_1c = (int *)&DAT_10453ba8;
          piStack_20 = DAT_10423658;
          (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c,4);
          (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&piStack_20);
          DAT_104234ac = 0;
          DAT_104234a8 = 0;
          DAT_104234b0 = 0;
        }
        piStack_10 = (int *)0x3;
        DAT_1042376c = 3;
        piStack_14 = (int *)0x23;
        piStack_18 = DAT_1042364c;
        piStack_1c = (int *)0x100260ab;
        (**(code **)(*DAT_1042364c + 0x58))();
      }
    }
    else if (DAT_1042376c != 0) {
      if (DAT_104234b0 != 0) {
        piStack_10 = (int *)0x10025da7;
        FUN_1002bf10();
        piStack_10 = DAT_10423654;
        piStack_14 = (int *)0x10025db2;
        (**(code **)(*DAT_10423654 + 0x10))();
        piStack_14 = (int *)0x8;
        piStack_18 = (int *)DAT_104234b0;
        piStack_1c = (int *)&DAT_10453ba8;
        piStack_20 = DAT_10423658;
        (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c,4);
        (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&piStack_20);
        DAT_104234ac = 0;
        DAT_104234a8 = 0;
        DAT_104234b0 = 0;
      }
      piStack_10 = (int *)0x0;
      DAT_1042376c = 0;
      piStack_14 = (int *)0x23;
      piStack_18 = DAT_1042364c;
      piStack_1c = (int *)0x10025e1d;
      (**(code **)(*DAT_1042364c + 0x58))();
      return;
    }
  }
  return;
}


// glFogiv  @ 10027be0
/* __stdcall glFogiv,8 */

void glFogiv(void)

{
                    /* 0x27be0  156  _glFogiv@8 */
  return;
}


// glFrontFace  @ 10027c70
/* __stdcall glFrontFace,4 */

void glFrontFace(void)

{
                    /* 0x27c70  157  _glFrontFace@4 */
  return;
}


// glFrustum  @ 100260c0
/* __stdcall glFrustum,48 */

void glFrustum(double param_1,double param_2,double param_3,double param_4,double param_5,
              double param_6)

{
  float afStack_40 [6];
  undefined4 uStack_28;
  undefined4 uStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  float fStack_8;
  undefined4 uStack_4;
  
                    /* 0x260c0  158  _glFrustum@48 */
  if (DAT_104234ac != DAT_104234a8) {
    (**(code **)(*DAT_10423658 + 0x14))
              (DAT_10423658,5,DAT_104234ac,DAT_104234a8 - DAT_104234ac,DAT_10423654,DAT_104234ac,
               DAT_1042364c,0);
    DAT_104234ac = DAT_104234a8;
  }
  afStack_40[4] = 0.0;
  afStack_40[0] = (float)((float10)(param_5 * 2.0) / (float10)(param_2 - param_1));
  local_10 = 0;
  afStack_40[1] = 0.0;
  fStack_20 = (float)(((float10)param_2 + (float10)param_1) / (float10)(param_2 - param_1));
  afStack_40[5] = (float)((float10)(param_5 * 2.0) / (float10)(param_4 - param_3));
  uStack_c = 0;
  afStack_40[2] = 0.0;
  uStack_28 = 0;
  fStack_1c = (float)(((float10)param_4 + (float10)param_3) / (float10)(param_4 - param_3));
  fStack_18 = (float)-(((float10)param_6 + (float10)param_5) / (float10)(param_6 - param_5));
  afStack_40[3] = 0.0;
  uStack_24 = 0;
  uStack_4 = 0;
  uStack_14 = 0xbf800000;
  fStack_8 = (float)(((float10)param_6 * (float10)param_5 * (float10)-2.0) /
                    (float10)(param_6 - param_5));
  (**(code **)(*DAT_1042364c + 0x6c))(DAT_1042364c,DAT_10423660,afStack_40);
  return;
}


// glGenLists  @ 10027c80
/* __stdcall glGenLists,4 */

undefined4 glGenLists(void)

{
                    /* 0x27c80  159  _glGenLists@4 */
  return 0;
}


// glGenTextures  @ 10027c90
/* __stdcall glGenTextures,8 */

void glGenTextures(void)

{
                    /* 0x27c90  160  _glGenTextures@8 */
  return;
}


// glGetBooleanv  @ 10027ca0
/* __stdcall glGetBooleanv,8 */

void glGetBooleanv(void)

{
                    /* 0x27ca0  161  _glGetBooleanv@8 */
  return;
}


// glGetClipPlane  @ 10027cb0
/* __stdcall glGetClipPlane,8 */

void glGetClipPlane(void)

{
                    /* 0x27cb0  162  _glGetClipPlane@8 */
  return;
}


// glGetDoublev  @ 10027cc0
/* __stdcall glGetDoublev,8 */

void glGetDoublev(void)

{
                    /* 0x27cc0  163  _glGetDoublev@8 */
  return;
}


// glGetError  @ 1002a160
/* __stdcall glGetError,0 */

undefined4 glGetError(void)

{
                    /* 0x2a160  164  _glGetError@0 */
  return 0;
}


// glGetFloatv  @ 10026230
/* __stdcall glGetFloatv,8 */

void glGetFloatv(int param_1,undefined4 param_2)

{
                    /* 0x26230  165  _glGetFloatv@8 */
  if (param_1 == 0xba6) {
    (**(code **)(*DAT_1042364c + 0x68))(DAT_1042364c,1,param_2);
    return;
  }
  if (param_1 != 0xba7) {
    return;
  }
  (**(code **)(*DAT_1042364c + 0x68))(DAT_1042364c,3,param_2);
  return;
}


// glGetIntegerv  @ 10027d50
/* __stdcall glGetIntegerv,8 */

void glGetIntegerv(void)

{
                    /* 0x27d50  166  _glGetIntegerv@8 */
  return;
}


// glGetLightfv  @ 10027d60
/* __stdcall glGetLightfv,12 */

void glGetLightfv(void)

{
                    /* 0x27d60  167  _glGetLightfv@12 */
  return;
}


// glGetLightiv  @ 10027d70
/* __stdcall glGetLightiv,12 */

void glGetLightiv(void)

{
                    /* 0x27d70  168  _glGetLightiv@12 */
  return;
}


// glGetMapdv  @ 10027d80
/* __stdcall glGetMapdv,12 */

void glGetMapdv(void)

{
                    /* 0x27d80  169  _glGetMapdv@12 */
  return;
}


// glGetMapfv  @ 10027d90
/* __stdcall glGetMapfv,12 */

void glGetMapfv(void)

{
                    /* 0x27d90  170  _glGetMapfv@12 */
  return;
}


// glGetMapiv  @ 10027da0
/* __stdcall glGetMapiv,12 */

void glGetMapiv(void)

{
                    /* 0x27da0  171  _glGetMapiv@12 */
  return;
}


// glGetMaterialfv  @ 10027db0
/* __stdcall glGetMaterialfv,12 */

void glGetMaterialfv(void)

{
                    /* 0x27db0  172  _glGetMaterialfv@12 */
  return;
}


// glGetMaterialiv  @ 10027e00
/* __stdcall glGetMaterialiv,12 */

void glGetMaterialiv(void)

{
                    /* 0x27e00  173  _glGetMaterialiv@12 */
  return;
}


// glGetPixelMapfv  @ 10027e10
/* __stdcall glGetPixelMapfv,8 */

void glGetPixelMapfv(void)

{
                    /* 0x27e10  174  _glGetPixelMapfv@8 */
  return;
}


// glGetPixelMapuiv  @ 10027e20
/* __stdcall glGetPixelMapuiv,8 */

void glGetPixelMapuiv(void)

{
                    /* 0x27e20  175  _glGetPixelMapuiv@8 */
  return;
}


// glGetPixelMapusv  @ 10027f60
/* __stdcall glGetPixelMapusv,8 */

void glGetPixelMapusv(void)

{
                    /* 0x27f60  176  _glGetPixelMapusv@8 */
  return;
}


// glGetPointerv  @ 10027f70
/* __stdcall glGetPointerv,8 */

void glGetPointerv(void)

{
                    /* 0x27f70  177  _glGetPointerv@8 */
  return;
}


// glGetPolygonStipple  @ 10027f80
/* __stdcall glGetPolygonStipple,4 */

void glGetPolygonStipple(void)

{
                    /* 0x27f80  178  _glGetPolygonStipple@4 */
  return;
}


// glGetString  @ 10026280
/* __stdcall glGetString,4 */

char * glGetString(undefined4 param_1)

{
                    /* 0x26280  179  _glGetString@4 */
  switch(param_1) {
  case 0x1f00:
    return (char *)&DAT_10423078;
  case 0x1f01:
    return (char *)&DAT_10423278;
  case 0x1f02:
    return &DAT_100c8ce0;
  case 0x1f03:
    if (DAT_10423680 != 0) {
      return s_GL_SGIS_multitexture_100c8ce4;
    }
  }
  return &DAT_100c8cfc;
}


// glGetTexEnvfv  @ 10027f90
/* __stdcall glGetTexEnvfv,12 */

void glGetTexEnvfv(void)

{
                    /* 0x27f90  180  _glGetTexEnvfv@12 */
  return;
}


// glGetTexEnviv  @ 10027fa0
/* __stdcall glGetTexEnviv,12 */

void glGetTexEnviv(void)

{
                    /* 0x27fa0  181  _glGetTexEnviv@12 */
  return;
}


// glGetTexGendv  @ 10027fb0
/* __stdcall glGetTexGendv,12 */

void glGetTexGendv(void)

{
                    /* 0x27fb0  182  _glGetTexGendv@12 */
  return;
}


// glGetTexGenfv  @ 10027fc0
/* __stdcall glGetTexGenfv,12 */

void glGetTexGenfv(void)

{
                    /* 0x27fc0  183  _glGetTexGenfv@12 */
  return;
}


// glGetTexGeniv  @ 10027fe0
/* __stdcall glGetTexGeniv,12 */

void glGetTexGeniv(void)

{
                    /* 0x27fe0  184  _glGetTexGeniv@12 */
  return;
}


// glGetTexImage  @ 10029190
/* __stdcall glGetTexImage,20 */

void glGetTexImage(void)

{
                    /* 0x29190  185  _glGetTexImage@20 */
  return;
}


// glGetTexLevelParameterfv  @ 100291a0
/* __stdcall glGetTexLevelParameterfv,16 */

void glGetTexLevelParameterfv(void)

{
                    /* 0x291a0  186  _glGetTexLevelParameterfv@16 */
  return;
}


// glGetTexLevelParameteriv  @ 100291b0
/* __stdcall glGetTexLevelParameteriv,16 */

void glGetTexLevelParameteriv(void)

{
                    /* 0x291b0  187  _glGetTexLevelParameteriv@16 */
  return;
}


// glGetTexParameterfv  @ 100291c0
/* __stdcall glGetTexParameterfv,12 */

void glGetTexParameterfv(void)

{
                    /* 0x291c0  188  _glGetTexParameterfv@12 */
  return;
}


// glGetTexParameteriv  @ 100291d0
/* __stdcall glGetTexParameteriv,12 */

void glGetTexParameteriv(void)

{
                    /* 0x291d0  189  _glGetTexParameteriv@12 */
  return;
}


// glHint  @ 100291e0
/* __stdcall glHint,8 */

void glHint(void)

{
                    /* 0x291e0  190  _glHint@8 */
  return;
}


// glIndexMask  @ 100291f0
/* __stdcall glIndexMask,4 */

void glIndexMask(void)

{
                    /* 0x291f0  191  _glIndexMask@4 */
  return;
}


// glIndexPointer  @ 10029200
/* __stdcall glIndexPointer,12 */

void glIndexPointer(void)

{
                    /* 0x29200  192  _glIndexPointer@12 */
  return;
}


// glIndexd  @ 10029210
/* __stdcall glIndexd,8 */

void glIndexd(void)

{
                    /* 0x29210  193  _glIndexd@8 */
  return;
}


// glIndexdv  @ 10029220
/* __stdcall glIndexdv,4 */

void glIndexdv(void)

{
                    /* 0x29220  194  _glIndexdv@4 */
  return;
}


// glIndexf  @ 10029230
/* __stdcall glIndexf,4 */

void glIndexf(void)

{
                    /* 0x29230  195  _glIndexf@4 */
  return;
}


// glIndexfv  @ 10029240
/* __stdcall glIndexfv,4 */

void glIndexfv(void)

{
                    /* 0x29240  196  _glIndexfv@4 */
  return;
}


// glIndexi  @ 10029250
/* __stdcall glIndexi,4 */

void glIndexi(void)

{
                    /* 0x29250  197  _glIndexi@4 */
  return;
}


// glIndexiv  @ 10029260
/* __stdcall glIndexiv,4 */

void glIndexiv(void)

{
                    /* 0x29260  198  _glIndexiv@4 */
  return;
}


// glIndexs  @ 10029270
/* __stdcall glIndexs,4 */

void glIndexs(void)

{
                    /* 0x29270  199  _glIndexs@4 */
  return;
}


// glIndexsv  @ 10029280
/* __stdcall glIndexsv,4 */

void glIndexsv(void)

{
                    /* 0x29280  200  _glIndexsv@4 */
  return;
}


// glIndexub  @ 10029290
/* __stdcall glIndexub,4 */

void glIndexub(void)

{
                    /* 0x29290  201  _glIndexub@4 */
  return;
}


// glIndexubv  @ 100292a0
/* __stdcall glIndexubv,4 */

void glIndexubv(void)

{
                    /* 0x292a0  202  _glIndexubv@4 */
  return;
}


// glInitNames  @ 100292b0
/* __stdcall glInitNames,0 */

void glInitNames(void)

{
                    /* 0x292b0  203  _glInitNames@0 */
  return;
}


// glInterleavedArrays  @ 100292c0
/* __stdcall glInterleavedArrays,12 */

void glInterleavedArrays(void)

{
                    /* 0x292c0  204  _glInterleavedArrays@12 */
  return;
}


// glIsEnabled  @ 100292d0
/* __stdcall glIsEnabled,4 */

undefined1 glIsEnabled(void)

{
                    /* 0x292d0  205  _glIsEnabled@4 */
  return 0;
}


// glIsList  @ 100292e0
/* __stdcall glIsList,4 */

undefined1 glIsList(void)

{
                    /* 0x292e0  206  _glIsList@4 */
  return 0;
}


// glIsTexture  @ 100292f0
/* __stdcall glIsTexture,4 */

undefined1 glIsTexture(void)

{
                    /* 0x292f0  207  _glIsTexture@4 */
  return 0;
}


// glLightModelf  @ 10029300
/* __stdcall glLightModelf,8 */

void glLightModelf(void)

{
                    /* 0x29300  208  _glLightModelf@8 */
  return;
}


// glLightModelfv  @ 10029310
/* __stdcall glLightModelfv,8 */

void glLightModelfv(void)

{
                    /* 0x29310  209  _glLightModelfv@8 */
  return;
}


// glLightModeli  @ 10029320
/* __stdcall glLightModeli,8 */

void glLightModeli(void)

{
                    /* 0x29320  210  _glLightModeli@8 */
  return;
}


// glLightModeliv  @ 10029330
/* __stdcall glLightModeliv,8 */

void glLightModeliv(void)

{
                    /* 0x29330  211  _glLightModeliv@8 */
  return;
}


// glLightf  @ 10029340
/* __stdcall glLightf,12 */

void glLightf(void)

{
                    /* 0x29340  212  _glLightf@12 */
  return;
}


// glLightfv  @ 10029350
/* __stdcall glLightfv,12 */

void glLightfv(void)

{
                    /* 0x29350  213  _glLightfv@12 */
  return;
}


// glLighti  @ 10029360
/* __stdcall glLighti,12 */

void glLighti(void)

{
                    /* 0x29360  214  _glLighti@12 */
  return;
}


// glLightiv  @ 10029370
/* __stdcall glLightiv,12 */

void glLightiv(void)

{
                    /* 0x29370  215  _glLightiv@12 */
  return;
}


// glLineStipple  @ 10029380
/* __stdcall glLineStipple,8 */

void glLineStipple(void)

{
                    /* 0x29380  216  _glLineStipple@8 */
  return;
}


// glLineWidth  @ 10029390
/* __stdcall glLineWidth,4 */

void glLineWidth(void)

{
                    /* 0x29390  217  _glLineWidth@4 */
  return;
}


// glListBase  @ 100293a0
/* __stdcall glListBase,4 */

void glListBase(void)

{
                    /* 0x293a0  218  _glListBase@4 */
  return;
}


// glLoadIdentity  @ 100262e0
/* __stdcall glLoadIdentity,0 */

void glLoadIdentity(void)

{
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
                    /* 0x262e0  219  _glLoadIdentity@0 */
  if (DAT_104234ac != DAT_104234a8) {
    (**(code **)(*DAT_10423658 + 0x14))
              (DAT_10423658,5,DAT_104234ac,DAT_104234a8 - DAT_104234ac,DAT_10423654,DAT_104234ac,
               DAT_1042364c,0);
    DAT_104234ac = DAT_104234a8;
  }
  local_40 = 0x3f800000;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0x3f800000;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0x3f800000;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  uStack_8 = 0;
  uStack_4 = 0x3f800000;
  (**(code **)(*DAT_1042364c + 100))(DAT_1042364c,DAT_10423660,&local_40);
  return;
}


// glLoadMatrixd  @ 100293b0
/* __stdcall glLoadMatrixd,4 */

void glLoadMatrixd(void)

{
                    /* 0x293b0  220  _glLoadMatrixd@4 */
  return;
}


// glLoadMatrixf  @ 10026390
/* __stdcall glLoadMatrixf,4 */

void glLoadMatrixf(undefined4 param_1)

{
                    /* 0x26390  221  _glLoadMatrixf@4 */
  if (DAT_104234ac != DAT_104234a8) {
    (**(code **)(*DAT_10423658 + 0x14))
              (DAT_10423658,5,DAT_104234ac,DAT_104234a8 - DAT_104234ac,DAT_10423654,DAT_104234ac,
               DAT_1042364c,0);
    DAT_104234ac = DAT_104234a8;
  }
  (**(code **)(*DAT_1042364c + 100))(DAT_1042364c,DAT_10423660,param_1);
  return;
}


// glLoadName  @ 100293c0
/* __stdcall glLoadName,4 */

void glLoadName(void)

{
                    /* 0x293c0  222  _glLoadName@4 */
  return;
}


// glLogicOp  @ 100293d0
/* __stdcall glLogicOp,4 */

void glLogicOp(void)

{
                    /* 0x293d0  223  _glLogicOp@4 */
  return;
}


// glMap1d  @ 100293e0
/* __stdcall glMap1d,32 */

void glMap1d(void)

{
                    /* 0x293e0  224  _glMap1d@32 */
  return;
}


// glMap1f  @ 100293f0
/* __stdcall glMap1f,24 */

void glMap1f(void)

{
                    /* 0x293f0  225  _glMap1f@24 */
  return;
}


// glMap2d  @ 10029400
/* __stdcall glMap2d,56 */

void glMap2d(void)

{
                    /* 0x29400  226  _glMap2d@56 */
  return;
}


// glMap2f  @ 10029410
/* __stdcall glMap2f,40 */

void glMap2f(void)

{
                    /* 0x29410  227  _glMap2f@40 */
  return;
}


// glMapGrid1d  @ 10029420
/* __stdcall glMapGrid1d,20 */

void glMapGrid1d(void)

{
                    /* 0x29420  228  _glMapGrid1d@20 */
  return;
}


// glMapGrid1f  @ 10029430
/* __stdcall glMapGrid1f,12 */

void glMapGrid1f(void)

{
                    /* 0x29430  229  _glMapGrid1f@12 */
  return;
}


// glMapGrid2d  @ 10029440
/* __stdcall glMapGrid2d,40 */

void glMapGrid2d(void)

{
                    /* 0x29440  230  _glMapGrid2d@40 */
  return;
}


// glMapGrid2f  @ 10029450
/* __stdcall glMapGrid2f,24 */

void glMapGrid2f(void)

{
                    /* 0x29450  231  _glMapGrid2f@24 */
  return;
}


// glMaterialf  @ 10029460
/* __stdcall glMaterialf,12 */

void glMaterialf(void)

{
                    /* 0x29460  232  _glMaterialf@12 */
  return;
}


// glMaterialfv  @ 10029470
/* __stdcall glMaterialfv,12 */

void glMaterialfv(void)

{
                    /* 0x29470  233  _glMaterialfv@12 */
  return;
}


// glMateriali  @ 10029480
/* __stdcall glMateriali,12 */

void glMateriali(void)

{
                    /* 0x29480  234  _glMateriali@12 */
  return;
}


// glMaterialiv  @ 10029490
/* __stdcall glMaterialiv,12 */

void glMaterialiv(void)

{
                    /* 0x29490  235  _glMaterialiv@12 */
  return;
}


// glMatrixMode  @ 100263f0
/* __stdcall glMatrixMode,4 */

void glMatrixMode(int param_1)

{
                    /* 0x263f0  236  _glMatrixMode@4 */
  if (param_1 == 0x1700) {
    DAT_10423660 = 1;
    return;
  }
  DAT_10423660 = 3;
  return;
}


// glMultMatrixd  @ 100294a0
/* __stdcall glMultMatrixd,4 */

void glMultMatrixd(void)

{
                    /* 0x294a0  237  _glMultMatrixd@4 */
  return;
}


// glMultMatrixf  @ 100294b0
/* __stdcall glMultMatrixf,4 */

void glMultMatrixf(void)

{
                    /* 0x294b0  238  _glMultMatrixf@4 */
  return;
}


// glNewList  @ 100294c0
/* __stdcall glNewList,8 */

void glNewList(void)

{
                    /* 0x294c0  239  _glNewList@8 */
  return;
}


// glNormal3b  @ 100294d0
/* __stdcall glNormal3b,12 */

void glNormal3b(void)

{
                    /* 0x294d0  240  _glNormal3b@12 */
  return;
}


// glNormal3bv  @ 100294e0
/* __stdcall glNormal3bv,4 */

void glNormal3bv(void)

{
                    /* 0x294e0  241  _glNormal3bv@4 */
  return;
}


// glNormal3d  @ 100294f0
/* __stdcall glNormal3d,24 */

void glNormal3d(void)

{
                    /* 0x294f0  242  _glNormal3d@24 */
  return;
}


// glNormal3dv  @ 10029500
/* __stdcall glNormal3dv,4 */

void glNormal3dv(void)

{
                    /* 0x29500  243  _glNormal3dv@4 */
  return;
}


// glNormal3f  @ 10029510
/* __stdcall glNormal3f,12 */

void glNormal3f(void)

{
                    /* 0x29510  244  _glNormal3f@12 */
  return;
}


// glNormal3fv  @ 10029520
/* __stdcall glNormal3fv,4 */

void glNormal3fv(void)

{
                    /* 0x29520  245  _glNormal3fv@4 */
  return;
}


// glNormal3i  @ 10029530
/* __stdcall glNormal3i,12 */

void glNormal3i(void)

{
                    /* 0x29530  246  _glNormal3i@12 */
  return;
}


// glNormal3iv  @ 10029540
/* __stdcall glNormal3iv,4 */

void glNormal3iv(void)

{
                    /* 0x29540  247  _glNormal3iv@4 */
  return;
}


// glNormal3s  @ 10029550
/* __stdcall glNormal3s,12 */

void glNormal3s(void)

{
                    /* 0x29550  248  _glNormal3s@12 */
  return;
}


// glNormal3sv  @ 10029560
/* __stdcall glNormal3sv,4 */

void glNormal3sv(void)

{
                    /* 0x29560  249  _glNormal3sv@4 */
  return;
}


// glNormalPointer  @ 10029570
/* __stdcall glNormalPointer,12 */

void glNormalPointer(void)

{
                    /* 0x29570  250  _glNormalPointer@12 */
  return;
}


// glOrtho  @ 10026420
/* __stdcall glOrtho,48 */

void glOrtho(double param_1,double param_2,double param_3,double param_4,double param_5,
            double param_6)

{
  float afStack_40 [6];
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  undefined4 uStack_4;
  
                    /* 0x26420  251  _glOrtho@48 */
  if (DAT_104234ac != DAT_104234a8) {
    (**(code **)(*DAT_10423658 + 0x14))
              (DAT_10423658,5,DAT_104234ac,DAT_104234a8 - DAT_104234ac,DAT_10423654,DAT_104234ac,
               DAT_1042364c,0);
    DAT_104234ac = DAT_104234a8;
  }
  local_20 = 0;
  afStack_40[4] = 0.0;
  afStack_40[0] = (float)((float10)2.0 / (float10)(param_2 - param_1));
  afStack_40[1] = 0.0;
  fStack_10 = (float)-(((float10)param_2 + (float10)param_1) / (float10)(param_2 - param_1));
  uStack_1c = 0;
  afStack_40[5] = (float)((float10)2.0 / (float10)(param_4 - param_3));
  afStack_40[2] = 0.0;
  uStack_28 = 0;
  fStack_c = (float)-(((float10)param_4 + (float10)param_3) / (float10)(param_4 - param_3));
  fStack_18 = (float)((float10)-2.0 / (float10)(param_6 - param_5));
  afStack_40[3] = 0.0;
  uStack_24 = 0;
  uStack_14 = 0;
  uStack_4 = 0x3f800000;
  fStack_8 = (float)-(((float10)param_6 + (float10)param_5) / (float10)(param_6 - param_5));
  (**(code **)(*DAT_1042364c + 0x6c))(DAT_1042364c,DAT_10423660,afStack_40);
  return;
}


// glPassThrough  @ 10029580
/* __stdcall glPassThrough,4 */

void glPassThrough(void)

{
                    /* 0x29580  252  _glPassThrough@4 */
  return;
}


// glPixelMapfv  @ 10029590
/* __stdcall glPixelMapfv,12 */

void glPixelMapfv(void)

{
                    /* 0x29590  253  _glPixelMapfv@12 */
  return;
}


// glPixelMapuiv  @ 100295a0
/* __stdcall glPixelMapuiv,12 */

void glPixelMapuiv(void)

{
                    /* 0x295a0  254  _glPixelMapuiv@12 */
  return;
}


// glPixelMapusv  @ 100295b0
/* __stdcall glPixelMapusv,12 */

void glPixelMapusv(void)

{
                    /* 0x295b0  255  _glPixelMapusv@12 */
  return;
}


// glPixelStoref  @ 100295c0
/* __stdcall glPixelStoref,8 */

void glPixelStoref(void)

{
                    /* 0x295c0  256  _glPixelStoref@8 */
  return;
}


// glPixelStorei  @ 100295d0
/* __stdcall glPixelStorei,8 */

void glPixelStorei(void)

{
                    /* 0x295d0  257  _glPixelStorei@8 */
  return;
}


// glPixelTransferf  @ 100295e0
/* __stdcall glPixelTransferf,8 */

void glPixelTransferf(void)

{
                    /* 0x295e0  258  _glPixelTransferf@8 */
  return;
}


// glPixelTransferi  @ 100295f0
/* __stdcall glPixelTransferi,8 */

void glPixelTransferi(void)

{
                    /* 0x295f0  259  _glPixelTransferi@8 */
  return;
}


// glPixelZoom  @ 10029600
/* __stdcall glPixelZoom,8 */

void glPixelZoom(void)

{
                    /* 0x29600  260  _glPixelZoom@8 */
  return;
}


// glPointSize  @ 10029610
/* __stdcall glPointSize,4 */

void glPointSize(void)

{
                    /* 0x29610  261  _glPointSize@4 */
  return;
}


// glPolygonMode  @ 10026580
/* __stdcall glPolygonMode,8 */

void glPolygonMode(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piStack_20;
  int *piStack_1c;
  int *piStack_18;
  int *piStack_14;
  int *piStack_10;
  
                    /* 0x26580  262  _glPolygonMode@8 */
  iVar1 = -1;
  if (param_2 == 0x1b00) {
    iVar1 = 1;
  }
  else if (param_2 == 0x1b01) {
    iVar1 = 2;
  }
  else if (param_2 == 0x1b02) {
    iVar1 = 3;
  }
  if ((-1 < iVar1) && (iVar1 != DAT_10423700)) {
    if (DAT_104234b0 != 0) {
      if (DAT_104234ac != DAT_104234a8) {
        piStack_10 = (int *)0x0;
        piStack_14 = DAT_1042364c;
        piStack_18 = (int *)DAT_104234ac;
        piStack_1c = DAT_10423654;
        piStack_20 = (int *)(DAT_104234a8 - DAT_104234ac);
        (**(code **)(*DAT_10423658 + 0x14))(DAT_10423658,5,DAT_104234ac);
        DAT_104234ac = DAT_104234a8;
      }
      piStack_10 = DAT_10423654;
      piStack_14 = (int *)0x10026628;
      (**(code **)(*DAT_10423654 + 0x10))();
      piStack_14 = (int *)0x8;
      piStack_18 = (int *)DAT_104234b0;
      piStack_1c = (int *)&DAT_10453ba8;
      piStack_20 = DAT_10423658;
      (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c,4);
      (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&piStack_20);
      DAT_104234ac = 0;
      DAT_104234a8 = 0;
      DAT_104234b0 = 0;
    }
    piStack_14 = (int *)0x8;
    piStack_18 = DAT_1042364c;
    piStack_1c = (int *)0x1002668d;
    DAT_10423700 = iVar1;
    piStack_10 = (int *)iVar1;
    (**(code **)(*DAT_1042364c + 0x58))();
  }
  return;
}


// glPolygonOffset  @ 100266a0
/* __stdcall glPolygonOffset,8 */

void glPolygonOffset(void)

{
  float unaff_retaddr;
  int iStack_4c;
  int *piStack_48;
  int *piStack_44;
  undefined1 *puStack_40;
  int *piStack_3c;
  int *piStack_38;
  undefined4 local_2c [8];
  float fStack_c;
  
                    /* 0x266a0  263  _glPolygonOffset@8 */
  if (DAT_104234b0 != 0) {
    if (DAT_104234ac != DAT_104234a8) {
      piStack_38 = (int *)0x0;
      piStack_3c = DAT_1042364c;
      puStack_40 = (undefined1 *)DAT_104234ac;
      piStack_44 = DAT_10423654;
      piStack_48 = (int *)(DAT_104234a8 - DAT_104234ac);
      iStack_4c = DAT_104234ac;
      (**(code **)(*DAT_10423658 + 0x14))(DAT_10423658,5);
      DAT_104234ac = DAT_104234a8;
    }
    piStack_38 = DAT_10423654;
    piStack_3c = (int *)0x100266ff;
    (**(code **)(*DAT_10423654 + 0x10))();
    piStack_3c = (int *)0x8;
    puStack_40 = (undefined1 *)DAT_104234b0;
    piStack_44 = (int *)&DAT_10453ba8;
    piStack_48 = DAT_10423658;
    iStack_4c = 4;
    (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c);
    (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&iStack_4c);
    DAT_104234ac = 0;
    DAT_104234a8 = 0;
    DAT_104234b0 = 0;
  }
  piStack_38 = local_2c;
  local_2c[0] = 0x2c;
  piStack_3c = DAT_10423650;
  puStack_40 = (undefined1 *)0x10026769;
  (**(code **)(*DAT_10423650 + 0x40))();
  puStack_40 = &stack0xffffffcc;
  fStack_c = (unaff_retaddr + 1.0) * DAT_10423668;
  piStack_44 = DAT_10423650;
  piStack_48 = (int *)0x1002678e;
  (**(code **)(*DAT_10423650 + 0x44))();
  return;
}


// glPolygonStipple  @ 10029620
/* __stdcall glPolygonStipple,4 */

void glPolygonStipple(void)

{
                    /* 0x29620  264  _glPolygonStipple@4 */
  return;
}


// glPopAttrib  @ 10029630
/* __stdcall glPopAttrib,0 */

void glPopAttrib(void)

{
                    /* 0x29630  265  _glPopAttrib@0 */
  return;
}


// glPopClientAttrib  @ 10029640
/* __stdcall glPopClientAttrib,0 */

void glPopClientAttrib(void)

{
                    /* 0x29640  266  _glPopClientAttrib@0 */
  return;
}


// glPopMatrix  @ 100267a0
/* __stdcall glPopMatrix,0 */

void glPopMatrix(void)

{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  bool bVar3;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar2 = DAT_104234ac;
  iVar1 = DAT_104234a8;
                    /* 0x267a0  267  _glPopMatrix@0 */
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_100268d1;
  *unaff_FS_OFFSET = &local_10;
  if (iVar2 != iVar1) {
    (**(code **)(*DAT_10423658 + 0x14))
              (DAT_10423658,5,iVar2,DAT_104234a8 - iVar2,DAT_10423654,iVar2,DAT_1042364c,0);
    DAT_104234ac = DAT_104234a8;
  }
  if (DAT_10423660 == 1) {
    local_8 = 0;
    (**(code **)(*DAT_1042364c + 100))(DAT_1042364c,1,DAT_104236d4);
    iVar1 = DAT_104236d4;
    bVar3 = DAT_104236d4 != 0;
    DAT_104236d4 = *(int *)(DAT_104236d4 + 0x40);
    if (bVar3) {
      FUN_100a4f30(iVar1);
    }
    local_8 = 0xffffffff;
    DAT_104236d0 = DAT_104236d0 + -1;
    FUN_1002686f();
  }
  else {
    local_8 = 1;
    (**(code **)(*DAT_1042364c + 100))(DAT_1042364c,DAT_10423660,DAT_104236dc);
    iVar1 = DAT_104236dc;
    bVar3 = DAT_104236dc != 0;
    DAT_104236dc = *(int *)(DAT_104236dc + 0x40);
    if (bVar3) {
      FUN_100a4f30(iVar1);
    }
    local_8 = 0xffffffff;
    DAT_104236d8 = DAT_104236d8 + -1;
    FUN_100268db();
  }
  *unaff_FS_OFFSET = local_10;
  return;
}


// glPopName  @ 10029650
/* __stdcall glPopName,0 */

void glPopName(void)

{
                    /* 0x29650  268  _glPopName@0 */
  return;
}


// glPrioritizeTextures  @ 10029660
/* __stdcall glPrioritizeTextures,12 */

void glPrioritizeTextures(void)

{
                    /* 0x29660  269  _glPrioritizeTextures@12 */
  return;
}


// glPushAttrib  @ 10029670
/* __stdcall glPushAttrib,4 */

void glPushAttrib(void)

{
                    /* 0x29670  270  _glPushAttrib@4 */
  return;
}


// glPushClientAttrib  @ 10029680
/* __stdcall glPushClientAttrib,4 */

void glPushClientAttrib(void)

{
                    /* 0x29680  271  _glPushClientAttrib@4 */
  return;
}


// glPushMatrix  @ 100268f0
/* __stdcall glPushMatrix,0 */

void glPushMatrix(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_5c [16];
  undefined4 *local_1c;
  int *local_18;
  undefined4 *local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x268f0  272  _glPushMatrix@0 */
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_10026a1b;
  *unaff_FS_OFFSET = &local_10;
  (**(code **)(*DAT_1042364c + 0x68))(DAT_1042364c,DAT_10423660,local_5c);
  if (DAT_10423660 == 1) {
    local_18 = &DAT_104236d0;
    local_14 = &DAT_104236d4;
    local_8 = 0;
    local_1c = operator_new(0x44);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_1c != (undefined4 *)0x0) {
      puVar2 = local_5c;
      puVar3 = local_1c;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      local_1c[0x10] = *local_14;
      *local_14 = local_1c;
    }
    local_8 = 0xffffffff;
    *local_18 = *local_18 + 1;
    FUN_100269a7();
  }
  else {
    local_18 = &DAT_104236d8;
    local_14 = &DAT_104236dc;
    local_8 = 2;
    local_1c = operator_new(0x44);
    local_8 = CONCAT31(local_8._1_3_,3);
    if (local_1c != (undefined4 *)0x0) {
      puVar2 = local_5c;
      puVar3 = local_1c;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      local_1c[0x10] = *local_14;
      *local_14 = local_1c;
    }
    local_8 = 0xffffffff;
    *local_18 = *local_18 + 1;
    FUN_10026a25();
  }
  *unaff_FS_OFFSET = local_10;
  return;
}


// glPushName  @ 10029690
/* __stdcall glPushName,4 */

void glPushName(void)

{
                    /* 0x29690  273  _glPushName@4 */
  return;
}


// glRasterPos2d  @ 100296a0
/* __stdcall glRasterPos2d,16 */

void glRasterPos2d(void)

{
                    /* 0x296a0  274  _glRasterPos2d@16 */
  return;
}


// glRasterPos2dv  @ 100296b0
/* __stdcall glRasterPos2dv,4 */

void glRasterPos2dv(void)

{
                    /* 0x296b0  275  _glRasterPos2dv@4 */
  return;
}


// glRasterPos2f  @ 100296c0
/* __stdcall glRasterPos2f,8 */

void glRasterPos2f(void)

{
                    /* 0x296c0  276  _glRasterPos2f@8 */
  return;
}


// glRasterPos2fv  @ 100296d0
/* __stdcall glRasterPos2fv,4 */

void glRasterPos2fv(void)

{
                    /* 0x296d0  277  _glRasterPos2fv@4 */
  return;
}


// glRasterPos2i  @ 100296e0
/* __stdcall glRasterPos2i,8 */

void glRasterPos2i(void)

{
                    /* 0x296e0  278  _glRasterPos2i@8 */
  return;
}


// glRasterPos2iv  @ 100296f0
/* __stdcall glRasterPos2iv,4 */

void glRasterPos2iv(void)

{
                    /* 0x296f0  279  _glRasterPos2iv@4 */
  return;
}


// glRasterPos2s  @ 10029700
/* __stdcall glRasterPos2s,8 */

void glRasterPos2s(void)

{
                    /* 0x29700  280  _glRasterPos2s@8 */
  return;
}


// glRasterPos2sv  @ 10029710
/* __stdcall glRasterPos2sv,4 */

void glRasterPos2sv(void)

{
                    /* 0x29710  281  _glRasterPos2sv@4 */
  return;
}


// glRasterPos3d  @ 10029720
/* __stdcall glRasterPos3d,24 */

void glRasterPos3d(void)

{
                    /* 0x29720  282  _glRasterPos3d@24 */
  return;
}


// glRasterPos3dv  @ 10029730
/* __stdcall glRasterPos3dv,4 */

void glRasterPos3dv(void)

{
                    /* 0x29730  283  _glRasterPos3dv@4 */
  return;
}


// glRasterPos3f  @ 10029740
/* __stdcall glRasterPos3f,12 */

void glRasterPos3f(void)

{
                    /* 0x29740  284  _glRasterPos3f@12 */
  return;
}


// glRasterPos3fv  @ 10029750
/* __stdcall glRasterPos3fv,4 */

void glRasterPos3fv(void)

{
                    /* 0x29750  285  _glRasterPos3fv@4 */
  return;
}


// glRasterPos3i  @ 10029760
/* __stdcall glRasterPos3i,12 */

void glRasterPos3i(void)

{
                    /* 0x29760  286  _glRasterPos3i@12 */
  return;
}


// glRasterPos3iv  @ 10029770
/* __stdcall glRasterPos3iv,4 */

void glRasterPos3iv(void)

{
                    /* 0x29770  287  _glRasterPos3iv@4 */
  return;
}


// glRasterPos3s  @ 10029780
/* __stdcall glRasterPos3s,12 */

void glRasterPos3s(void)

{
                    /* 0x29780  288  _glRasterPos3s@12 */
  return;
}


// glRasterPos3sv  @ 10029790
/* __stdcall glRasterPos3sv,4 */

void glRasterPos3sv(void)

{
                    /* 0x29790  289  _glRasterPos3sv@4 */
  return;
}


// glRasterPos4d  @ 100297a0
/* __stdcall glRasterPos4d,32 */

void glRasterPos4d(void)

{
                    /* 0x297a0  290  _glRasterPos4d@32 */
  return;
}


// glRasterPos4dv  @ 100297b0
/* __stdcall glRasterPos4dv,4 */

void glRasterPos4dv(void)

{
                    /* 0x297b0  291  _glRasterPos4dv@4 */
  return;
}


// glRasterPos4f  @ 100297c0
/* __stdcall glRasterPos4f,16 */

void glRasterPos4f(void)

{
                    /* 0x297c0  292  _glRasterPos4f@16 */
  return;
}


// glRasterPos4fv  @ 100297d0
/* __stdcall glRasterPos4fv,4 */

void glRasterPos4fv(void)

{
                    /* 0x297d0  293  _glRasterPos4fv@4 */
  return;
}


// glRasterPos4i  @ 100297e0
/* __stdcall glRasterPos4i,16 */

void glRasterPos4i(void)

{
                    /* 0x297e0  294  _glRasterPos4i@16 */
  return;
}


// glRasterPos4iv  @ 100297f0
/* __stdcall glRasterPos4iv,4 */

void glRasterPos4iv(void)

{
                    /* 0x297f0  295  _glRasterPos4iv@4 */
  return;
}


// glRasterPos4s  @ 10029800
/* __stdcall glRasterPos4s,16 */

void glRasterPos4s(void)

{
                    /* 0x29800  296  _glRasterPos4s@16 */
  return;
}


// glRasterPos4sv  @ 10029810
/* __stdcall glRasterPos4sv,4 */

void glRasterPos4sv(void)

{
                    /* 0x29810  297  _glRasterPos4sv@4 */
  return;
}


// glReadBuffer  @ 10029820
/* __stdcall glReadBuffer,4 */

void glReadBuffer(void)

{
                    /* 0x29820  298  _glReadBuffer@4 */
  return;
}


// glReadPixels  @ 10026a30
/* __stdcall glReadPixels,28 */

void glReadPixels(void)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  int iVar7;
  uint *puVar8;
  int *unaff_ESI;
  char *pcVar9;
  char *pcVar10;
  undefined4 *puVar11;
  int iVar12;
  int unaff_retaddr;
  int *piVar13;
  int *piVar14;
  LONG local_b8;
  int iStack_b4;
  int iStack_b0;
  uint *puStack_a8;
  tagPOINT tStack_9c;
  undefined4 uStack_94;
  LONG LStack_90;
  int iStack_8c;
  int iStack_88;
  undefined4 auStack_84 [4];
  uint *puStack_74;
  int iStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  
                    /* 0x26a30  299  _glReadPixels@28 */
  (**(code **)(*DAT_104234c8 + 0x44))(DAT_104234c8,&local_b8);
  puVar11 = auStack_84;
  for (iVar7 = 0x1f; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar11 = 0;
    puVar11 = puVar11 + 1;
  }
  auStack_84[0] = 0x7c;
  if (DAT_10423690 == 0) {
    local_b8 = 0;
    ClientToScreen(DAT_104234c0,(LPPOINT)&stack0xffffff44);
    tStack_9c.x = DAT_104234b8;
    tStack_9c.y = DAT_104234bc;
    ClientToScreen(DAT_104234c0,&tStack_9c);
    uStack_94 = 0;
    piVar14 = (int *)0x0;
    piVar13 = (int *)0x11;
    iStack_8c = tStack_9c.x;
    LStack_90 = local_b8;
    iStack_88 = tStack_9c.y;
    iVar7 = (**(code **)(*unaff_ESI + 100))(unaff_ESI,&uStack_94,auStack_84);
    if (iVar7 != 0) {
      OutputDebugStringA(s_Wrapper__Lock_on_primary_failed_100c8d20);
      (**(code **)(*piVar14 + 8))(piVar14);
      return;
    }
  }
  else {
    piVar14 = (int *)0x0;
    piVar13 = (int *)0x11;
    iVar7 = (**(code **)(*unaff_ESI + 100))(unaff_ESI,0,auStack_84);
    if (iVar7 != 0) {
      OutputDebugStringA(s_Wrapper__Lock_on_primary_failed_100c8d00);
      (**(code **)(*piVar14 + 8))(piVar14);
      return;
    }
  }
  local_b8 = 0;
  for (uVar2 = uStack_40; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1) {
    local_b8 = local_b8 + 1;
  }
  iStack_b4 = 8;
  for (; (uVar2 & 1) != 0; uVar2 = uVar2 >> 1) {
    iStack_b4 = iStack_b4 + -1;
  }
  bVar3 = 0;
  for (uVar2 = uStack_3c; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1) {
    bVar3 = bVar3 + 1;
  }
  bVar4 = 8;
  for (; (uVar2 & 1) != 0; uVar2 = uVar2 >> 1) {
    bVar4 = bVar4 - 1;
  }
  bVar5 = 0;
  for (uVar2 = uStack_38; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1) {
    bVar5 = bVar5 + 1;
  }
  bVar6 = 8;
  for (; (uVar2 & 1) != 0; uVar2 = uVar2 >> 1) {
    bVar6 = bVar6 - 1;
  }
  if (iStack_44 == 0x10) {
    iStack_b0 = 0;
    pcVar9 = (char *)(unaff_retaddr + (DAT_104234bc + -1) * DAT_104234b8 * 3);
    if (0 < DAT_104234bc) {
      do {
        puStack_a8 = (uint *)0x0;
        pcVar10 = pcVar9;
        puVar8 = puStack_74;
        if (0 < DAT_104234b8) {
          do {
            uVar2 = (uint)(ushort)*puVar8;
            pcVar9 = pcVar10 + 3;
            *pcVar10 = (char)((uStack_40 & uVar2) >> ((byte)local_b8 & 0x1f)) <<
                       ((byte)iStack_b4 & 0x1f);
            pcVar10[1] = (char)(((uStack_3c & uVar2) >> (bVar3 & 0x1f)) << (bVar4 & 0x1f));
            pcVar10[2] = (char)(((uStack_38 & uVar2) >> (bVar5 & 0x1f)) << (bVar6 & 0x1f));
            puStack_a8 = (uint *)((int)puStack_a8 + 1);
            pcVar10 = pcVar9;
            puVar8 = (uint *)((int)puVar8 + 2);
          } while ((int)puStack_a8 < DAT_104234b8);
        }
        puStack_74 = (uint *)((int)puStack_74 + iStack_88);
        iStack_b0 = iStack_b0 + 1;
        pcVar9 = pcVar9 + DAT_104234b8 * -6;
      } while (iStack_b0 < DAT_104234bc);
    }
  }
  else if (iStack_44 == 0x18) {
    puStack_a8 = puStack_74;
    iVar7 = 0;
    pcVar9 = (char *)(unaff_retaddr + (DAT_104234bc + -1) * DAT_104234b8 * 3);
    if (0 < DAT_104234bc) {
      do {
        iVar12 = 0;
        pcVar10 = pcVar9;
        puVar8 = puStack_a8;
        if (0 < DAT_104234b8) {
          do {
            uVar2 = *puVar8;
            iVar12 = iVar12 + 1;
            pcVar9 = pcVar10 + 3;
            uVar1 = *puVar8;
            *pcVar10 = (char)((uStack_40 & *puVar8) >> ((byte)local_b8 & 0x1f)) <<
                       ((byte)iStack_b4 & 0x1f);
            pcVar10[1] = (char)(((uStack_3c & uVar2) >> (bVar3 & 0x1f)) << (bVar4 & 0x1f));
            pcVar10[2] = (char)(((uStack_38 & uVar1) >> (bVar5 & 0x1f)) << (bVar6 & 0x1f));
            pcVar10 = pcVar9;
            puVar8 = (uint *)((int)puVar8 + 3);
          } while (iVar12 < DAT_104234b8);
        }
        puStack_a8 = (uint *)((int)puStack_a8 + iStack_88);
        iVar7 = iVar7 + 1;
        pcVar9 = pcVar9 + DAT_104234b8 * -6;
      } while (iVar7 < DAT_104234bc);
    }
  }
  else if (iStack_44 == 0x20) {
    puStack_a8 = puStack_74;
    iVar7 = 0;
    pcVar9 = (char *)(unaff_retaddr + (DAT_104234bc + -1) * DAT_104234b8 * 3);
    if (0 < DAT_104234bc) {
      do {
        iVar12 = 0;
        puVar8 = puStack_a8;
        pcVar10 = pcVar9;
        if (0 < DAT_104234b8) {
          do {
            uVar2 = *puVar8;
            iVar12 = iVar12 + 1;
            pcVar9 = pcVar10 + 3;
            uVar1 = *puVar8;
            *pcVar10 = (char)((uStack_40 & *puVar8) >> ((byte)local_b8 & 0x1f)) <<
                       ((byte)iStack_b4 & 0x1f);
            pcVar10[1] = (char)(((uStack_3c & uVar2) >> (bVar3 & 0x1f)) << (bVar4 & 0x1f));
            pcVar10[2] = (char)(((uStack_38 & uVar1) >> (bVar5 & 0x1f)) << (bVar6 & 0x1f));
            puVar8 = puVar8 + 1;
            pcVar10 = pcVar9;
          } while (iVar12 < DAT_104234b8);
        }
        puStack_a8 = (uint *)((int)puStack_a8 + iStack_88);
        iVar7 = iVar7 + 1;
        pcVar9 = pcVar9 + DAT_104234b8 * -6;
      } while (iVar7 < DAT_104234bc);
    }
  }
  (**(code **)(*piVar14 + 8))(piVar14);
  (**(code **)(*piVar13 + 0x80))(piVar13,0);
  return;
}


// glRectd  @ 10029830
/* __stdcall glRectd,32 */

void glRectd(void)

{
                    /* 0x29830  300  _glRectd@32 */
  return;
}


// glRectdv  @ 10029840
/* __stdcall glRectdv,8 */

void glRectdv(void)

{
                    /* 0x29840  301  _glRectdv@8 */
  return;
}


// glRectf  @ 10029850
/* __stdcall glRectf,16 */

void glRectf(void)

{
                    /* 0x29850  302  _glRectf@16 */
  return;
}


// glRectfv  @ 10029860
/* __stdcall glRectfv,8 */

void glRectfv(void)

{
                    /* 0x29860  303  _glRectfv@8 */
  return;
}


// glRecti  @ 10029870
/* __stdcall glRecti,16 */

void glRecti(void)

{
                    /* 0x29870  304  _glRecti@16 */
  return;
}


// glRectiv  @ 10029880
/* __stdcall glRectiv,8 */

void glRectiv(void)

{
                    /* 0x29880  305  _glRectiv@8 */
  return;
}


// glRects  @ 10029890
/* __stdcall glRects,16 */

void glRects(void)

{
                    /* 0x29890  306  _glRects@16 */
  return;
}


// glRectsv  @ 100298a0
/* __stdcall glRectsv,8 */

void glRectsv(void)

{
                    /* 0x298a0  307  _glRectsv@8 */
  return;
}


// glRenderMode  @ 100298b0
/* __stdcall glRenderMode,4 */

undefined4 glRenderMode(void)

{
                    /* 0x298b0  308  _glRenderMode@4 */
  return 0;
}


// glRotated  @ 100298c0
/* __stdcall glRotated,32 */

void glRotated(void)

{
                    /* 0x298c0  309  _glRotated@32 */
  return;
}


// glRotatef  @ 10026ed0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall glRotatef,16 */

void glRotatef(float param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  double dVar2;
  float10 fVar3;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  undefined4 uStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
                    /* 0x26ed0  310  _glRotatef@16 */
  if (DAT_104234ac != DAT_104234a8) {
    (**(code **)(*DAT_10423658 + 0x14))
              (DAT_10423658,5,DAT_104234ac,DAT_104234a8 - DAT_104234ac,DAT_10423654,DAT_104234ac,
               DAT_1042364c,0);
    DAT_104234ac = DAT_104234a8;
  }
  if ((DAT_10473bc8 & 1) == 0) {
    DAT_10473bc8 = DAT_10473bc8 | 1;
    fVar3 = (float10)FUN_100a46d1(0,0x3ff00000);
    _DAT_10473bc0 = (double)(fVar3 * (float10)4.0);
  }
  dVar2 = (double)((param_1 * (float)_DAT_10473bc0) / 180.0);
  fVar3 = (float10)FUN_100a3c4a(dVar2);
  fVar1 = (float)fVar3;
  fVar3 = (float10)FUN_100a3c40(dVar2);
  fStack_28 = (float)fVar3;
  fStack_2c = fVar1;
  fStack_18 = fVar1;
  if (param_2 == 1.0) {
    fStack_40 = 1.0;
    fStack_30 = 0.0;
    fStack_1c = -fStack_28;
    fStack_20 = 0.0;
    fStack_3c = 0.0;
    fStack_38 = 0.0;
  }
  else {
    if (param_3 == 1.0) {
      fStack_30 = 0.0;
      fStack_38 = -fStack_28;
      fStack_3c = 0.0;
      fStack_2c = 1.0;
      fStack_20 = fStack_28;
    }
    else {
      if (param_4 != 1.0) {
        return;
      }
      fStack_30 = -fStack_28;
      fStack_20 = 0.0;
      fStack_38 = 0.0;
      fStack_18 = 1.0;
      fStack_3c = fStack_28;
    }
    fStack_1c = 0.0;
    fStack_28 = 0.0;
    fStack_40 = fVar1;
  }
  uStack_4 = 0x3f800000;
  uStack_8 = 0;
  uStack_c = 0;
  uStack_10 = 0;
  uStack_14 = 0;
  uStack_24 = 0;
  uStack_34 = 0;
  (**(code **)(*DAT_1042364c + 0x6c))(DAT_1042364c,DAT_10423660,&fStack_40);
  return;
}


// glScaled  @ 100298d0
/* __stdcall glScaled,24 */

void glScaled(void)

{
                    /* 0x298d0  311  _glScaled@24 */
  return;
}


// glScalef  @ 10027160
/* __stdcall glScalef,12 */

void glScalef(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 uStack_4;
  
                    /* 0x27160  312  _glScalef@12 */
  if (DAT_104234ac != DAT_104234a8) {
    (**(code **)(*DAT_10423658 + 0x14))
              (DAT_10423658,5,DAT_104234ac,DAT_104234a8 - DAT_104234ac,DAT_10423654,DAT_104234ac,
               DAT_1042364c,0);
    DAT_104234ac = DAT_104234a8;
  }
  local_40 = param_1;
  local_30 = 0;
  local_20 = 0;
  local_10 = 0;
  local_3c = 0;
  local_2c = param_2;
  local_1c = 0;
  local_c = 0;
  local_38 = 0;
  local_28 = 0;
  local_18 = param_3;
  local_8 = 0;
  uStack_34 = 0;
  uStack_24 = 0;
  uStack_4 = 0x3f800000;
  uStack_14 = 0;
  (**(code **)(*DAT_1042364c + 0x6c))(DAT_1042364c,DAT_10423660,&local_40);
  return;
}


// glScissor  @ 100298e0
/* __stdcall glScissor,16 */

void glScissor(void)

{
                    /* 0x298e0  313  _glScissor@16 */
  return;
}


// glSelectBuffer  @ 100298f0
/* __stdcall glSelectBuffer,8 */

void glSelectBuffer(void)

{
                    /* 0x298f0  314  _glSelectBuffer@8 */
  return;
}


// glShadeModel  @ 100272d0
/* __stdcall glShadeModel,4 */

void glShadeModel(int param_1)

{
  int iStack_20;
  int *piStack_1c;
  int *piStack_18;
  int *piStack_14;
  int *piStack_10;
  int *piStack_c;
  
                    /* 0x272d0  315  _glShadeModel@4 */
  if (param_1 == 0x1d01) {
    if (DAT_10423704 != 2) {
      if (DAT_104234b0 != 0) {
        if (DAT_104234ac != DAT_104234a8) {
          piStack_c = (int *)0x0;
          piStack_10 = DAT_1042364c;
          piStack_14 = (int *)DAT_104234ac;
          piStack_18 = DAT_10423654;
          piStack_1c = (int *)(DAT_104234a8 - DAT_104234ac);
          iStack_20 = DAT_104234ac;
          (**(code **)(*DAT_10423658 + 0x14))(DAT_10423658,5);
          DAT_104234ac = DAT_104234a8;
        }
        piStack_c = DAT_10423654;
        piStack_10 = (int *)0x1002734b;
        (**(code **)(*DAT_10423654 + 0x10))();
        piStack_10 = (int *)0x8;
        piStack_14 = (int *)DAT_104234b0;
        piStack_18 = (int *)&DAT_10453ba8;
        piStack_1c = DAT_10423658;
        iStack_20 = 4;
        (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c);
        (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&iStack_20);
        DAT_104234ac = 0;
        DAT_104234a8 = 0;
        DAT_104234b0 = 0;
      }
      piStack_c = (int *)0x2;
      DAT_10423704 = 2;
      piStack_10 = (int *)0x9;
      piStack_14 = DAT_1042364c;
      piStack_18 = (int *)0x100273b5;
      (**(code **)(*DAT_1042364c + 0x58))();
      return;
    }
  }
  else if (DAT_10423704 != 1) {
    if (DAT_104234b0 != 0) {
      if (DAT_104234ac != DAT_104234a8) {
        piStack_c = (int *)0x0;
        piStack_10 = DAT_1042364c;
        piStack_14 = (int *)DAT_104234ac;
        piStack_18 = DAT_10423654;
        piStack_1c = (int *)(DAT_104234a8 - DAT_104234ac);
        iStack_20 = DAT_104234ac;
        (**(code **)(*DAT_10423658 + 0x14))(DAT_10423658,5);
        DAT_104234ac = DAT_104234a8;
      }
      piStack_c = DAT_10423654;
      piStack_10 = (int *)0x1002741f;
      (**(code **)(*DAT_10423654 + 0x10))();
      piStack_10 = (int *)0x8;
      piStack_14 = (int *)DAT_104234b0;
      piStack_18 = (int *)&DAT_10453ba8;
      piStack_1c = DAT_10423658;
      iStack_20 = 4;
      (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c);
      (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&iStack_20);
      DAT_104234ac = 0;
      DAT_104234a8 = 0;
      DAT_104234b0 = 0;
    }
    piStack_c = (int *)0x1;
    DAT_10423704 = 1;
    piStack_10 = (int *)0x9;
    piStack_14 = DAT_1042364c;
    piStack_18 = (int *)0x10027489;
    (**(code **)(*DAT_1042364c + 0x58))();
  }
  return;
}


// glStencilFunc  @ 10029900
/* __stdcall glStencilFunc,12 */

void glStencilFunc(void)

{
                    /* 0x29900  316  _glStencilFunc@12 */
  return;
}


// glStencilMask  @ 10029910
/* __stdcall glStencilMask,4 */

void glStencilMask(void)

{
                    /* 0x29910  317  _glStencilMask@4 */
  return;
}


// glStencilOp  @ 10029920
/* __stdcall glStencilOp,12 */

void glStencilOp(void)

{
                    /* 0x29920  318  _glStencilOp@12 */
  return;
}


// glTexCoord1d  @ 10029930
/* __stdcall glTexCoord1d,8 */

void glTexCoord1d(void)

{
                    /* 0x29930  319  _glTexCoord1d@8 */
  return;
}


// glTexCoord1dv  @ 10029940
/* __stdcall glTexCoord1dv,4 */

void glTexCoord1dv(void)

{
                    /* 0x29940  320  _glTexCoord1dv@4 */
  return;
}


// glTexCoord1f  @ 10029950
/* __stdcall glTexCoord1f,4 */

void glTexCoord1f(void)

{
                    /* 0x29950  321  _glTexCoord1f@4 */
  return;
}


// glTexCoord1fv  @ 10029960
/* __stdcall glTexCoord1fv,4 */

void glTexCoord1fv(void)

{
                    /* 0x29960  322  _glTexCoord1fv@4 */
  return;
}


// glTexCoord1i  @ 10029970
/* __stdcall glTexCoord1i,4 */

void glTexCoord1i(void)

{
                    /* 0x29970  323  _glTexCoord1i@4 */
  return;
}


// glTexCoord1iv  @ 10029980
/* __stdcall glTexCoord1iv,4 */

void glTexCoord1iv(void)

{
                    /* 0x29980  324  _glTexCoord1iv@4 */
  return;
}


// glTexCoord1s  @ 10029990
/* __stdcall glTexCoord1s,4 */

void glTexCoord1s(void)

{
                    /* 0x29990  325  _glTexCoord1s@4 */
  return;
}


// glTexCoord1sv  @ 100299a0
/* __stdcall glTexCoord1sv,4 */

void glTexCoord1sv(void)

{
                    /* 0x299a0  326  _glTexCoord1sv@4 */
  return;
}


// glTexCoord2d  @ 100299b0
/* __stdcall glTexCoord2d,16 */

void glTexCoord2d(void)

{
                    /* 0x299b0  327  _glTexCoord2d@16 */
  return;
}


// glTexCoord2dv  @ 100299c0
/* __stdcall glTexCoord2dv,4 */

void glTexCoord2dv(void)

{
                    /* 0x299c0  328  _glTexCoord2dv@4 */
  return;
}


// glTexCoord2f  @ 100274b0
/* __stdcall glTexCoord2f,8 */

void glTexCoord2f(undefined4 param_1,undefined4 param_2)

{
                    /* 0x274b0  329  _glTexCoord2f@8 */
  DAT_104236b4 = param_1;
  DAT_104236b8 = param_2;
  return;
}


// glTexCoord2fv  @ 100299d0
/* __stdcall glTexCoord2fv,4 */

void glTexCoord2fv(void)

{
                    /* 0x299d0  330  _glTexCoord2fv@4 */
  return;
}


// glTexCoord2i  @ 100299e0
/* __stdcall glTexCoord2i,8 */

void glTexCoord2i(void)

{
                    /* 0x299e0  331  _glTexCoord2i@8 */
  return;
}


// glTexCoord2iv  @ 100299f0
/* __stdcall glTexCoord2iv,4 */

void glTexCoord2iv(void)

{
                    /* 0x299f0  332  _glTexCoord2iv@4 */
  return;
}


// glTexCoord2s  @ 10029a00
/* __stdcall glTexCoord2s,8 */

void glTexCoord2s(void)

{
                    /* 0x29a00  333  _glTexCoord2s@8 */
  return;
}


// glTexCoord2sv  @ 10029a10
/* __stdcall glTexCoord2sv,4 */

void glTexCoord2sv(void)

{
                    /* 0x29a10  334  _glTexCoord2sv@4 */
  return;
}


// glTexCoord3d  @ 10029a20
/* __stdcall glTexCoord3d,24 */

void glTexCoord3d(void)

{
                    /* 0x29a20  335  _glTexCoord3d@24 */
  return;
}


// glTexCoord3dv  @ 10029a30
/* __stdcall glTexCoord3dv,4 */

void glTexCoord3dv(void)

{
                    /* 0x29a30  336  _glTexCoord3dv@4 */
  return;
}


// glTexCoord3f  @ 10029a40
/* __stdcall glTexCoord3f,12 */

void glTexCoord3f(void)

{
                    /* 0x29a40  337  _glTexCoord3f@12 */
  return;
}


// glTexCoord3fv  @ 10029a50
/* __stdcall glTexCoord3fv,4 */

void glTexCoord3fv(void)

{
                    /* 0x29a50  338  _glTexCoord3fv@4 */
  return;
}


// glTexCoord3i  @ 10029a60
/* __stdcall glTexCoord3i,12 */

void glTexCoord3i(void)

{
                    /* 0x29a60  339  _glTexCoord3i@12 */
  return;
}


// glTexCoord3iv  @ 10029a70
/* __stdcall glTexCoord3iv,4 */

void glTexCoord3iv(void)

{
                    /* 0x29a70  340  _glTexCoord3iv@4 */
  return;
}


// glTexCoord3s  @ 10029a80
/* __stdcall glTexCoord3s,12 */

void glTexCoord3s(void)

{
                    /* 0x29a80  341  _glTexCoord3s@12 */
  return;
}


// glTexCoord3sv  @ 10029a90
/* __stdcall glTexCoord3sv,4 */

void glTexCoord3sv(void)

{
                    /* 0x29a90  342  _glTexCoord3sv@4 */
  return;
}


// glTexCoord4d  @ 10029aa0
/* __stdcall glTexCoord4d,32 */

void glTexCoord4d(void)

{
                    /* 0x29aa0  343  _glTexCoord4d@32 */
  return;
}


// glTexCoord4dv  @ 10029ab0
/* __stdcall glTexCoord4dv,4 */

void glTexCoord4dv(void)

{
                    /* 0x29ab0  344  _glTexCoord4dv@4 */
  return;
}


// glTexCoord4f  @ 10029ac0
/* __stdcall glTexCoord4f,16 */

void glTexCoord4f(void)

{
                    /* 0x29ac0  345  _glTexCoord4f@16 */
  return;
}


// glTexCoord4fv  @ 10029ad0
/* __stdcall glTexCoord4fv,4 */

void glTexCoord4fv(void)

{
                    /* 0x29ad0  346  _glTexCoord4fv@4 */
  return;
}


// glTexCoord4i  @ 10029ae0
/* __stdcall glTexCoord4i,16 */

void glTexCoord4i(void)

{
                    /* 0x29ae0  347  _glTexCoord4i@16 */
  return;
}


// glTexCoord4iv  @ 10029af0
/* __stdcall glTexCoord4iv,4 */

void glTexCoord4iv(void)

{
                    /* 0x29af0  348  _glTexCoord4iv@4 */
  return;
}


// glTexCoord4s  @ 10029b00
/* __stdcall glTexCoord4s,16 */

void glTexCoord4s(void)

{
                    /* 0x29b00  349  _glTexCoord4s@16 */
  return;
}


// glTexCoord4sv  @ 10029b10
/* __stdcall glTexCoord4sv,4 */

void glTexCoord4sv(void)

{
                    /* 0x29b10  350  _glTexCoord4sv@4 */
  return;
}


// glTexCoordPointer  @ 10029b20
/* __stdcall glTexCoordPointer,16 */

void glTexCoordPointer(void)

{
                    /* 0x29b20  351  _glTexCoordPointer@16 */
  return;
}


// glTexEnvf  @ 100274f0
/* __stdcall glTexEnvf,12 */

void glTexEnvf(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
                    /* 0x274f0  352  _glTexEnvf@12 */
  if (param_2 == 0x2200) {
    uVar1 = __ftol();
    (&DAT_104236a4)[DAT_104236a0] = uVar1;
    DAT_10423670 = 0;
    return;
  }
  OutputDebugStringA(s_Wrapper__GL_TEXTURE_ENV_COLOR_no_100c8d44);
  return;
}


// glTexEnvfv  @ 10029b30
/* __stdcall glTexEnvfv,12 */

void glTexEnvfv(void)

{
                    /* 0x29b30  353  _glTexEnvfv@12 */
  return;
}


// glTexEnvi  @ 10029b40
/* __stdcall glTexEnvi,12 */

void glTexEnvi(void)

{
                    /* 0x29b40  354  _glTexEnvi@12 */
  return;
}


// glTexEnviv  @ 10029b50
/* __stdcall glTexEnviv,12 */

void glTexEnviv(void)

{
                    /* 0x29b50  355  _glTexEnviv@12 */
  return;
}


// glTexGend  @ 10029b60
/* __stdcall glTexGend,16 */

void glTexGend(void)

{
                    /* 0x29b60  356  _glTexGend@16 */
  return;
}


// glTexGendv  @ 10029b70
/* __stdcall glTexGendv,12 */

void glTexGendv(void)

{
                    /* 0x29b70  357  _glTexGendv@12 */
  return;
}


// glTexGenf  @ 10029b80
/* __stdcall glTexGenf,12 */

void glTexGenf(void)

{
                    /* 0x29b80  358  _glTexGenf@12 */
  return;
}


// glTexGenfv  @ 10029b90
/* __stdcall glTexGenfv,12 */

void glTexGenfv(void)

{
                    /* 0x29b90  359  _glTexGenfv@12 */
  return;
}


// glTexGeni  @ 10029ba0
/* __stdcall glTexGeni,12 */

void glTexGeni(void)

{
                    /* 0x29ba0  360  _glTexGeni@12 */
  return;
}


// glTexGeniv  @ 10029bb0
/* __stdcall glTexGeniv,12 */

void glTexGeniv(void)

{
                    /* 0x29bb0  361  _glTexGeniv@12 */
  return;
}


// glTexImage1D  @ 10029bc0
/* __stdcall glTexImage1D,32 */

void glTexImage1D(void)

{
                    /* 0x29bc0  362  _glTexImage1D@32 */
  return;
}


// glTexImage2D  @ 1002a320
/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* __stdcall glTexImage2D,36 */

void glTexImage2D(undefined4 param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *unaff_EBP;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piStack_d4;
  undefined4 *puStack_d0;
  int *piStack_cc;
  undefined4 uVar7;
  undefined1 local_8c [4];
  uint local_88;
  uint local_84;
  int local_7c [8];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 local_34 [4];
  undefined4 uStack_24;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  int local_4;
  
                    /* 0x2a320  363  _glTexImage2D@36 */
  iVar3 = (&DAT_10423698)[DAT_104236a0];
  iVar1 = iVar3 * 0x30;
  if ((DAT_10423678 == 0) || (((int)param_4 < 0x101 && ((int)param_5 < 0x101)))) {
    local_84 = param_4;
    local_88 = param_5;
  }
  else if ((int)param_5 < (int)param_4) {
    local_84 = 0x100;
    local_88 = (int)(param_5 << 8) / (int)param_4;
  }
  else {
    local_88 = 0x100;
    local_84 = (int)(param_4 << 8) / (int)param_5;
  }
  if (DAT_1042368c != 0) {
    if (local_84 < local_88) {
      local_84 = local_88;
    }
    else {
      local_88 = local_84;
    }
  }
  if (param_2 == 0) {
    piVar5 = local_7c;
    for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar5 = 0;
      piVar5 = piVar5 + 1;
    }
    if (param_3 == 1) {
      puVar4 = &DAT_1042352c;
    }
    else if (param_3 == 3) {
      puVar4 = &DAT_1042350c;
    }
    else {
      if (param_3 != 4) {
        OutputDebugStringA(s_Wrapper__texture_format_not_supp_100c9010);
        goto LAB_1002a47a;
      }
      if (DAT_10423694 != 0) {
        puVar4 = &DAT_104234ec;
        puVar6 = local_34;
        for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar6 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar6 = puVar6 + 1;
        }
        DAT_10423694 = 0;
        goto LAB_1002a47a;
      }
      puVar4 = &DAT_104234cc;
    }
    puVar6 = local_34;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
LAB_1002a47a:
    local_7c[0] = 0x7c;
    local_7c[2] = local_88;
    uVar7 = 0;
    local_7c[3] = local_84;
    local_7c[1] = 0x101007;
    local_4 = DAT_104236a0;
    local_14 = 0x1000;
    local_10 = 0x14;
    iVar2 = (**(code **)(*DAT_10423648 + 0x18))();
    if (iVar2 != 0) {
      OutputDebugStringA(s_Wrapper__CreateSurface_for_textu_100c9038);
      return;
    }
    piStack_cc = (int *)0x1002a519;
    FUN_10022fc0();
    if ((int *)(&DAT_10423bd4)[iVar3 * 0xc] != (int *)0x0) {
      (**(code **)(*(int *)(&DAT_10423bd4)[iVar3 * 0xc] + 8))();
    }
    if ((int *)(&DAT_10423bbc)[iVar3 * 0xc] != (int *)0x0) {
      (**(code **)(*(int *)(&DAT_10423bbc)[iVar3 * 0xc] + 8))();
    }
    iVar2 = (**(code **)*unaff_EBP)();
    if (iVar2 == 0) {
      *(int *)(&DAT_10423ba8 + iVar1) = param_3;
      *(undefined4 *)(iVar1 + 0x10423bac) = uVar7;
      *(undefined1 **)(iVar1 + 0x10423bb0) = local_8c;
      (&DAT_10423bbc)[iVar3 * 0xc] = local_7c;
      *(undefined4 *)(iVar1 + 0x10423bb4) = uStack_c;
      *(undefined4 *)(iVar1 + 0x10423bb8) = uStack_8;
      DAT_10423670 = 0;
      return;
    }
    OutputDebugStringA(s_Wrapper__QueryInterface_for_Text_100c9064);
    (**(code **)(local_7c[0] + 8))();
    return;
  }
  if ((param_2 != 1) || (DAT_10423684 == 0)) {
    if (DAT_10423684 == 0) {
      DAT_10423670 = 0;
      return;
    }
    piVar5 = (int *)(&DAT_10423bbc)[iVar3 * 0xc];
    iVar3 = 0;
    (**(code **)(*piVar5 + 4))();
    if (0 < iStack_40) {
      do {
        uStack_58 = 0;
        uStack_54 = 0;
        uStack_50 = 0;
        uStack_5c = 0x401000;
        iVar1 = (**(code **)(*piVar5 + 0x30))(piVar5,&uStack_5c,&piStack_d4);
        (**(code **)(*piVar5 + 8))(piVar5);
        if (iVar1 == -0x7789ff01) {
          return;
        }
        iVar3 = iVar3 + 1;
        piVar5 = piStack_d4;
      } while (iVar3 < iStack_40);
    }
    FUN_10022fc0(piVar5,uStack_3c,uStack_38,local_34[0],piStack_cc,puStack_d0,uStack_24);
    iVar3 = *piVar5;
    goto LAB_1002a7e2;
  }
  piVar5 = local_7c;
  for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
  }
  if (param_3 == 1) {
    puVar4 = &DAT_1042352c;
LAB_1002a60c:
    puVar6 = local_34;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  else {
    if (param_3 == 3) {
      puVar4 = &DAT_1042350c;
      goto LAB_1002a60c;
    }
    if (param_3 == 4) {
      if (DAT_10423694 == 0) {
        puVar4 = &DAT_104234cc;
        goto LAB_1002a60c;
      }
      puVar4 = &DAT_104234ec;
      puVar6 = local_34;
      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      DAT_10423694 = 0;
    }
  }
  local_7c[0] = 0x7c;
  local_7c[2] = *(undefined4 *)(iVar1 + 0x10423bb0);
  local_7c[3] = *(undefined4 *)(iVar1 + 0x10423bac);
  local_7c[1] = 0x101007;
  local_4 = DAT_104236a0;
  local_14 = 0x401008;
  local_10 = 0x14;
  iVar1 = (**(code **)(*DAT_10423648 + 0x18))();
  if (iVar1 != 0) {
    OutputDebugStringA(s_Wrapper__CreateSurface_for_textu_100c9094);
    return;
  }
  puVar4 = (undefined4 *)(&DAT_10423bbc)[iVar3 * 0xc];
  (**(code **)(*unaff_EBP + 0x14))();
  piVar5 = (int *)(&DAT_10423bd4)[iVar3 * 0xc];
  piStack_cc = (int *)0x1002a6a7;
  (**(code **)(*piVar5 + 8))();
  piStack_cc = (int *)(&DAT_10423bbc)[iVar3 * 0xc];
  puStack_d0 = (undefined4 *)0x1002a6b0;
  (**(code **)(*piStack_cc + 8))();
  piStack_d4 = (int *)&DAT_100b80d0;
  (&DAT_10423bbc)[iVar3 * 0xc] = puVar4;
  puStack_d0 = &DAT_10423bd4 + iVar3 * 0xc;
  (**(code **)*puVar4)(puVar4);
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_50 = 0x401000;
  (**(code **)(*(int *)(&DAT_10423bbc)[iVar3 * 0xc] + 0x30))
            ((int *)(&DAT_10423bbc)[iVar3 * 0xc],&uStack_50,&stack0xffffff44);
  FUN_10022fc0(piVar5,param_3,uStack_38,local_34[0],piStack_cc,puStack_d0,uStack_24);
  iVar3 = *piVar5;
LAB_1002a7e2:
  (**(code **)(iVar3 + 8))(piVar5);
  DAT_10423670 = 0;
  return;
}


// glTexParameterf  @ 10027570
/* __stdcall glTexParameterf,12 */

void glTexParameterf(undefined4 param_1,undefined4 param_2,float param_3)

{
  int iVar1;
  
                    /* 0x27570  364  _glTexParameterf@12 */
  switch(param_2) {
  case 0x2800:
    if (param_3 == 9728.0) {
      (&DAT_10423bc4)[(&DAT_10423698)[DAT_104236a0] * 0xc] = 1;
    }
    else {
      (&DAT_10423bc4)[(&DAT_10423698)[DAT_104236a0] * 0xc] = 2;
    }
    break;
  case 0x2801:
    iVar1 = __ftol();
    if (iVar1 < 0x2701) {
      if (iVar1 == 0x2700) {
        (&DAT_10423bc0)[(&DAT_10423698)[DAT_104236a0] * 0xc] = 1;
        (&DAT_10423bc8)[(&DAT_10423698)[DAT_104236a0] * 0xc] = 2;
      }
      else if (iVar1 == 0x2600) {
        (&DAT_10423bc0)[(&DAT_10423698)[DAT_104236a0] * 0xc] = 1;
        (&DAT_10423bc8)[(&DAT_10423698)[DAT_104236a0] * 0xc] = 1;
      }
      else if (iVar1 == 0x2601) {
        (&DAT_10423bc0)[(&DAT_10423698)[DAT_104236a0] * 0xc] = 2;
        (&DAT_10423bc8)[(&DAT_10423698)[DAT_104236a0] * 0xc] = 1;
      }
    }
    else if (iVar1 == 0x2701) {
      (&DAT_10423bc0)[(&DAT_10423698)[DAT_104236a0] * 0xc] = 2;
      (&DAT_10423bc8)[(&DAT_10423698)[DAT_104236a0] * 0xc] = 2;
    }
    else if (iVar1 == 0x2702) {
      (&DAT_10423bc0)[(&DAT_10423698)[DAT_104236a0] * 0xc] = 1;
      (&DAT_10423bc8)[(&DAT_10423698)[DAT_104236a0] * 0xc] = 3;
    }
    else if (iVar1 == 0x2703) {
      (&DAT_10423bc0)[(&DAT_10423698)[DAT_104236a0] * 0xc] = 2;
      (&DAT_10423bc8)[(&DAT_10423698)[DAT_104236a0] * 0xc] = 3;
    }
    break;
  case 0x2802:
    if (param_3 == 10496.0) {
      (&DAT_10423bcc)[(&DAT_10423698)[DAT_104236a0] * 0xc] = 3;
    }
    else {
      (&DAT_10423bcc)[(&DAT_10423698)[DAT_104236a0] * 0xc] = 1;
    }
    break;
  case 0x2803:
    if (param_3 == 10496.0) {
      (&DAT_10423bd0)[(&DAT_10423698)[DAT_104236a0] * 0xc] = 3;
    }
    else {
      (&DAT_10423bd0)[(&DAT_10423698)[DAT_104236a0] * 0xc] = 1;
    }
  }
  DAT_10423670 = 0;
  return;
}


// glTexParameterfv  @ 10029bd0
/* __stdcall glTexParameterfv,12 */

void glTexParameterfv(void)

{
                    /* 0x29bd0  365  _glTexParameterfv@12 */
  return;
}


// glTexParameteri  @ 10029be0
/* __stdcall glTexParameteri,12 */

void glTexParameteri(void)

{
                    /* 0x29be0  366  _glTexParameteri@12 */
  return;
}


// glTexParameteriv  @ 10029bf0
/* __stdcall glTexParameteriv,12 */

void glTexParameteriv(void)

{
                    /* 0x29bf0  367  _glTexParameteriv@12 */
  return;
}


// glTexSubImage1D  @ 10029c00
/* __stdcall glTexSubImage1D,28 */

void glTexSubImage1D(void)

{
                    /* 0x29c00  368  _glTexSubImage1D@28 */
  return;
}


// glTexSubImage2D  @ 1002a200
/* __stdcall glTexSubImage2D,36 */

void glTexSubImage2D(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                    undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *unaff_EDI;
  int *piVar4;
  undefined1 local_90 [4];
  tagRECT atStack_8c [7];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
                    /* 0x2a200  369  _glTexSubImage2D@36 */
  iVar3 = 0;
  piVar4 = (int *)(&DAT_10423bbc)[(&DAT_10423698)[DAT_104236a0] * 0xc];
  iVar2 = (&DAT_10423698)[DAT_104236a0] * 0x30;
  if (0 < param_2) {
    do {
      local_10 = 0;
      local_c = 0;
      local_8 = 0;
      local_14 = 0x401000;
      iVar1 = (**(code **)(*piVar4 + 0x30))(piVar4,&local_14,local_90);
      if (iVar1 == -0x7789ff01) {
        return;
      }
      iVar3 = iVar3 + 1;
      (**(code **)(*unaff_EDI + 8))(unaff_EDI);
      piVar4 = unaff_EDI;
    } while (iVar3 < param_2);
  }
  iVar3 = (param_3 * *(int *)(iVar2 + 0x10423bac)) / *(int *)(iVar2 + 0x10423bb4);
  iVar1 = (param_4 * *(int *)(iVar2 + 0x10423bb0)) / *(int *)(iVar2 + 0x10423bb8);
  SetRect(atStack_8c,iVar3,iVar1,
          (param_5 * *(int *)(iVar2 + 0x10423bac)) / *(int *)(iVar2 + 0x10423bb4) + iVar3,
          (param_6 * *(int *)(iVar2 + 0x10423bb0)) / *(int *)(iVar2 + 0x10423bb8) + iVar1);
  iVar2 = FUN_10023180(piVar4,*(undefined4 *)(&DAT_10423ba8 + iVar2),param_5,param_6,param_9,
                       atStack_8c);
  if (iVar2 != 0) {
    OutputDebugStringA(s_Wrapper__LoadSubSurface_Failure__100c8fec);
  }
  return;
}


// glTranslated  @ 10029c10
/* __stdcall glTranslated,24 */

void glTranslated(void)

{
                    /* 0x29c10  370  _glTranslated@24 */
  return;
}


// glTranslatef  @ 100279b0
/* __stdcall glTranslatef,12 */

void glTranslatef(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 uStack_4;
  
                    /* 0x279b0  371  _glTranslatef@12 */
  if (DAT_104234ac != DAT_104234a8) {
    (**(code **)(*DAT_10423658 + 0x14))
              (DAT_10423658,5,DAT_104234ac,DAT_104234a8 - DAT_104234ac,DAT_10423654,DAT_104234ac,
               DAT_1042364c,0);
    DAT_104234ac = DAT_104234a8;
  }
  local_40 = 0x3f800000;
  local_30 = 0;
  local_20 = 0;
  local_10 = param_1;
  local_3c = 0;
  local_2c = 0x3f800000;
  local_1c = 0;
  local_c = param_2;
  local_38 = 0;
  local_28 = 0;
  local_18 = 0x3f800000;
  local_8 = param_3;
  uStack_34 = 0;
  uStack_24 = 0;
  uStack_14 = 0;
  uStack_4 = 0x3f800000;
  (**(code **)(*DAT_1042364c + 0x6c))(DAT_1042364c,DAT_10423660,&local_40);
  return;
}


// glVertex2d  @ 10029c20
/* __stdcall glVertex2d,16 */

void glVertex2d(void)

{
                    /* 0x29c20  372  _glVertex2d@16 */
  return;
}


// glVertex2dv  @ 10029d10
/* __stdcall glVertex2dv,4 */

void glVertex2dv(void)

{
                    /* 0x29d10  373  _glVertex2dv@4 */
  return;
}


// glVertex2f  @ 10027b00
/* __stdcall glVertex2f,8 */

void glVertex2f(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
                    /* 0x27b00  374  _glVertex2f@8 */
  puVar1 = (undefined4 *)((DAT_104234b4 + DAT_104234a8) * 0x20 + DAT_104236cc);
  *puVar1 = param_1;
  puVar1[1] = param_2;
  puVar1[2] = 0;
  puVar1[3] = DAT_104236ac;
  puVar1[4] = DAT_104236b4;
  puVar1[5] = DAT_104236b8;
  if (DAT_1042367c != 0) {
    puVar1[6] = DAT_104236bc;
    puVar1[7] = DAT_104236c0;
  }
  DAT_104234b4 = DAT_104234b4 + 1;
  return;
}


// glVertex2fv  @ 10029d20
/* __stdcall glVertex2fv,4 */

void glVertex2fv(void)

{
                    /* 0x29d20  375  _glVertex2fv@4 */
  return;
}


// glVertex2i  @ 10029d30
/* __stdcall glVertex2i,8 */

void glVertex2i(void)

{
                    /* 0x29d30  376  _glVertex2i@8 */
  return;
}


// glVertex2iv  @ 10029d40
/* __stdcall glVertex2iv,4 */

void glVertex2iv(void)

{
                    /* 0x29d40  377  _glVertex2iv@4 */
  return;
}


// glVertex2s  @ 10029d50
/* __stdcall glVertex2s,8 */

void glVertex2s(void)

{
                    /* 0x29d50  378  _glVertex2s@8 */
  return;
}


// glVertex2sv  @ 10029d60
/* __stdcall glVertex2sv,4 */

void glVertex2sv(void)

{
                    /* 0x29d60  379  _glVertex2sv@4 */
  return;
}


// glVertex3d  @ 10029d70
/* __stdcall glVertex3d,24 */

void glVertex3d(void)

{
                    /* 0x29d70  380  _glVertex3d@24 */
  return;
}


// glVertex3dv  @ 10029d80
/* __stdcall glVertex3dv,4 */

void glVertex3dv(void)

{
                    /* 0x29d80  381  _glVertex3dv@4 */
  return;
}


// glVertex3f  @ 10027bf0
/* __stdcall glVertex3f,12 */

void glVertex3f(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
                    /* 0x27bf0  382  _glVertex3f@12 */
  puVar1 = (undefined4 *)((DAT_104234b4 + DAT_104234a8) * 0x20 + DAT_104236cc);
  puVar1[1] = param_2;
  *puVar1 = param_1;
  puVar1[2] = param_3;
  puVar1[3] = DAT_104236ac;
  puVar1[4] = DAT_104236b4;
  puVar1[5] = DAT_104236b8;
  if (DAT_1042367c != 0) {
    puVar1[6] = DAT_104236bc;
    puVar1[7] = DAT_104236c0;
  }
  DAT_104234b4 = DAT_104234b4 + 1;
  return;
}


// glVertex3fv  @ 10027cd0
/* __stdcall glVertex3fv,4 */

void glVertex3fv(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
                    /* 0x27cd0  383  _glVertex3fv@4 */
  puVar3 = (undefined4 *)((DAT_104234b4 + DAT_104234a8) * 0x20 + DAT_104236cc);
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  *puVar3 = *param_1;
  puVar3[1] = uVar1;
  puVar3[2] = uVar2;
  puVar3[3] = DAT_104236ac;
  puVar3[4] = DAT_104236b4;
  puVar3[5] = DAT_104236b8;
  if (DAT_1042367c != 0) {
    puVar3[6] = DAT_104236bc;
    puVar3[7] = DAT_104236c0;
  }
  DAT_104234b4 = DAT_104234b4 + 1;
  return;
}


// glVertex3i  @ 10029d90
/* __stdcall glVertex3i,12 */

void glVertex3i(void)

{
                    /* 0x29d90  384  _glVertex3i@12 */
  return;
}


// glVertex3iv  @ 10029da0
/* __stdcall glVertex3iv,4 */

void glVertex3iv(void)

{
                    /* 0x29da0  385  _glVertex3iv@4 */
  return;
}


// glVertex3s  @ 10029db0
/* __stdcall glVertex3s,12 */

void glVertex3s(void)

{
                    /* 0x29db0  386  _glVertex3s@12 */
  return;
}


// glVertex3sv  @ 10029dc0
/* __stdcall glVertex3sv,4 */

void glVertex3sv(void)

{
                    /* 0x29dc0  387  _glVertex3sv@4 */
  return;
}


// glVertex4d  @ 10029dd0
/* __stdcall glVertex4d,32 */

void glVertex4d(void)

{
                    /* 0x29dd0  388  _glVertex4d@32 */
  return;
}


// glVertex4dv  @ 10029de0
/* __stdcall glVertex4dv,4 */

void glVertex4dv(void)

{
                    /* 0x29de0  389  _glVertex4dv@4 */
  return;
}


// glVertex4f  @ 10029df0
/* __stdcall glVertex4f,16 */

void glVertex4f(void)

{
                    /* 0x29df0  390  _glVertex4f@16 */
  return;
}


// glVertex4fv  @ 10029e70
/* __stdcall glVertex4fv,4 */

void glVertex4fv(void)

{
                    /* 0x29e70  391  _glVertex4fv@4 */
  return;
}


// glVertex4i  @ 10029e80
/* __stdcall glVertex4i,16 */

void glVertex4i(void)

{
                    /* 0x29e80  392  _glVertex4i@16 */
  return;
}


// glVertex4iv  @ 10029e90
/* __stdcall glVertex4iv,4 */

void glVertex4iv(void)

{
                    /* 0x29e90  393  _glVertex4iv@4 */
  return;
}


// glVertex4s  @ 10029ea0
/* __stdcall glVertex4s,16 */

void glVertex4s(void)

{
                    /* 0x29ea0  394  _glVertex4s@16 */
  return;
}


// glVertex4sv  @ 10029eb0
/* __stdcall glVertex4sv,4 */

void glVertex4sv(void)

{
                    /* 0x29eb0  395  _glVertex4sv@4 */
  return;
}


// glVertexPointer  @ 10027dc0
/* __stdcall glVertexPointer,16 */

void glVertexPointer(int param_1,int param_2,int param_3,undefined4 param_4)

{
                    /* 0x27dc0  396  _glVertexPointer@16 */
  DAT_104236c4 = param_4;
  if (((param_1 != 3) && (param_2 != 0x1406)) && (param_3 != 0x10)) {
    OutputDebugStringA(s_Wrapper__unsupported_vertex_arra_100c8d74);
  }
  return;
}


// glViewport  @ 10027e30
/* __stdcall glViewport,16 */

void glViewport(undefined4 param_1,int param_2)

{
  int unaff_retaddr;
  int *piStack_38;
  int local_30;
  undefined4 uStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
                    /* 0x27e30  397  _glViewport@16 */
  if (DAT_104234b0 != 0) {
    if (DAT_104234ac != DAT_104234a8) {
      piStack_38 = (int *)0x0;
      (**(code **)(*DAT_10423658 + 0x14))
                (DAT_10423658,5,DAT_104234ac,DAT_104234a8 - DAT_104234ac,DAT_10423654,DAT_104234ac,
                 DAT_1042364c);
      DAT_104234ac = DAT_104234a8;
    }
    piStack_38 = DAT_10423654;
    (**(code **)(*DAT_10423654 + 0x10))();
    (**(code **)(*DAT_1042364c + 0x8c))(DAT_1042364c,4,DAT_10423658,&DAT_10453ba8,DAT_104234b0,8);
    (**(code **)(*DAT_10423654 + 0xc))(DAT_10423654,0x821,&DAT_104236cc,&uStack_20);
    DAT_104234ac = 0;
    DAT_104234a8 = 0;
    DAT_104234b0 = 0;
  }
  piStack_38 = &local_30;
  local_30 = 0x2c;
  (**(code **)(*DAT_10423650 + 0x40))(DAT_10423650);
  uStack_2c = param_1;
  iStack_28 = param_2;
  uStack_24 = 0xbf800000;
  uStack_20 = 0x3f800000;
  local_30 = (DAT_104234bc - param_2) - unaff_retaddr;
  uStack_1c = 0x40000000;
  uStack_18 = 0x40000000;
  (**(code **)(*DAT_10423650 + 0x44))(DAT_10423650,&piStack_38);
  return;
}


// setSBCS  @ 100ad940
/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 1998 Release */

void __cdecl setSBCS(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_100deba0;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_100decb0 = 0;
  DAT_100deca4 = 0;
  DAT_100deca8 = 0;
  DAT_100decb4 = 0;
  DAT_100decb8 = 0;
  return;
}


// shortsort  @ 100a4120
/* Library Function - Single Match
    _shortsort
   
   Library: Visual Studio 1998 Release */

void __cdecl shortsort(uint param_1,uint param_2,int param_3,code *param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  while (uVar2 = param_1, uVar1 = param_1, param_1 < param_2) {
    while (uVar1 = uVar1 + param_3, uVar1 <= param_2) {
      iVar3 = (*param_4)(uVar1,uVar2);
      if (0 < iVar3) {
        uVar2 = uVar1;
      }
    }
    swap(uVar2,param_2,param_3);
    param_2 = param_2 - param_3;
  }
  return;
}


// siglookup  @ 100b3490
/* Library Function - Single Match
    _siglookup
   
   Library: Visual Studio 1998 Release */

uint __cdecl siglookup(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2;
  do {
    if (*(int *)(uVar1 + 4) == param_1) break;
    uVar1 = uVar1 + 0xc;
  } while (uVar1 < param_2 + DAT_100dfa54 * 0xc);
  return -(uint)(*(int *)(uVar1 + 4) == param_1) & uVar1;
}


// storeTimeFmt  @ 100b1b40
/* Library Function - Single Match
    _storeTimeFmt
   
   Library: Visual Studio 1998 Release */

uint __cdecl storeTimeFmt(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  char *pcVar6;
  char *pcVar7;
  void *unaff_EDI;
  char *local_c;
  int local_8;
  int local_4;
  
  local_4 = 0;
  local_8 = 0;
  uVar2 = ___getlocaleinfo((_locale_t)0x0,param_1,(LPCWSTR)0x23,(LCTYPE)&local_4,unaff_EDI);
  uVar3 = ___getlocaleinfo((_locale_t)0x0,param_1,(LPCWSTR)0x25,(LCTYPE)&local_8,unaff_EDI);
  uVar4 = ___getlocaleinfo((_locale_t)0x1,param_1,(LPCWSTR)0x1e,(LCTYPE)&local_c,unaff_EDI);
  uVar4 = uVar2 | uVar3 | uVar4;
  if (uVar4 != 0) {
    return uVar4;
  }
  puVar5 = _malloc(0xd);
  *(undefined1 **)(param_2 + 0xa8) = puVar5;
  if (local_4 == 0) {
    *puVar5 = 0x68;
    pcVar7 = puVar5 + 1;
    if (local_8 == 0) goto LAB_100b1bdb;
    *pcVar7 = 'h';
  }
  else {
    *puVar5 = 0x48;
    pcVar7 = puVar5 + 1;
    if (local_8 == 0) goto LAB_100b1bdb;
    *pcVar7 = 'H';
  }
  pcVar7 = puVar5 + 2;
LAB_100b1bdb:
  cVar1 = *local_c;
  pcVar6 = local_c;
  while (cVar1 != '\0') {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    *pcVar7 = cVar1;
    pcVar7 = pcVar7 + 1;
    cVar1 = *pcVar6;
  }
  *pcVar7 = 'm';
  pcVar6 = pcVar7 + 1;
  if (local_8 != 0) {
    *pcVar6 = 'm';
    pcVar6 = pcVar7 + 2;
  }
  cVar1 = *local_c;
  pcVar7 = local_c;
  while (cVar1 != '\0') {
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    *pcVar6 = cVar1;
    pcVar6 = pcVar6 + 1;
    cVar1 = *pcVar7;
  }
  *pcVar6 = 's';
  pcVar6[1] = 's';
  pcVar6[2] = '\0';
  _free(local_c);
  return 0;
}


// strtoxl  @ 100ae1f0
/* Library Function - Single Match
    _strtoxl
   
   Library: Visual Studio 1998 Release */

uint __cdecl strtoxl(byte *param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  byte bVar6;
  uint uVar7;
  byte *pbVar8;
  
  bVar6 = *param_1;
  uVar7 = 0;
  pbVar1 = param_1;
  while( true ) {
    pbVar8 = pbVar1 + 1;
    if (DAT_100dd77c < 2) {
      uVar2 = *(ushort *)(PTR_DAT_100dd570 + (uint)bVar6 * 2) & 8;
    }
    else {
      uVar2 = __isctype((uint)bVar6,8);
    }
    if (uVar2 == 0) break;
    bVar6 = *pbVar8;
    pbVar1 = pbVar8;
  }
  if (bVar6 == 0x2d) {
    bVar6 = *pbVar8;
    param_4 = param_4 | 2;
    pbVar8 = pbVar1 + 2;
  }
  else if (bVar6 == 0x2b) {
    bVar6 = *pbVar8;
    pbVar8 = pbVar1 + 2;
  }
  if ((((int)param_3 < 0) || (param_3 == 1)) || (0x24 < (int)param_3)) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_1;
    }
    return 0;
  }
  if (param_3 == 0) {
    if (bVar6 == 0x30) {
      if ((*pbVar8 == 0x78) || (*pbVar8 == 0x58)) {
        param_3 = 0x10;
      }
      else {
        param_3 = 8;
      }
    }
    else {
      param_3 = 10;
    }
  }
  if (((param_3 == 0x10) && (bVar6 == 0x30)) && ((*pbVar8 == 0x78 || (*pbVar8 == 0x58)))) {
    bVar6 = pbVar8[1];
    pbVar8 = pbVar8 + 2;
  }
  uVar2 = (uint)(0xffffffff / (ulonglong)param_3);
  do {
    if (DAT_100dd77c < 2) {
      uVar3 = *(ushort *)(PTR_DAT_100dd570 + (uint)bVar6 * 2) & 4;
    }
    else {
      uVar3 = __isctype((uint)bVar6,4);
    }
    if (uVar3 == 0) {
      if (DAT_100dd77c < 2) {
        uVar3 = *(ushort *)(PTR_DAT_100dd570 + (uint)bVar6 * 2) & 0x103;
      }
      else {
        uVar3 = __isctype((uint)bVar6,0x103);
      }
      if (uVar3 == 0) {
LAB_100ae38e:
        pbVar8 = pbVar8 + -1;
        if ((param_4 & 8) == 0) {
          if (param_2 != (undefined4 *)0x0) {
            pbVar8 = param_1;
          }
          uVar7 = 0;
        }
        else if (((param_4 & 4) != 0) ||
                (((param_4 & 1) == 0 &&
                 ((((param_4 & 2) != 0 && (0x80000000 < uVar7)) ||
                  (((param_4 & 2) == 0 && (0x7fffffff < uVar7)))))))) {
          puVar5 = (undefined4 *)FUN_100a6390();
          *puVar5 = 0x22;
          if ((param_4 & 1) == 0) {
            if ((param_4 & 2) == 0) {
              uVar7 = 0x7fffffff;
            }
            else {
              uVar7 = 0x80000000;
            }
          }
          else {
            uVar7 = 0xffffffff;
          }
        }
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = pbVar8;
        }
        if ((param_4 & 2) != 0) {
          uVar7 = -uVar7;
        }
        return uVar7;
      }
      iVar4 = _toupper((int)(char)bVar6);
      uVar3 = iVar4 - 0x37;
    }
    else {
      uVar3 = (int)(char)bVar6 - 0x30;
    }
    if (param_3 <= uVar3) goto LAB_100ae38e;
    if ((uVar7 < uVar2) || ((uVar7 == uVar2 && (uVar3 <= (uint)(0xffffffff % (ulonglong)param_3)))))
    {
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
      uVar7 = uVar7 * param_3 + uVar3;
      param_4 = param_4 | 8;
    }
    else {
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
      param_4 = param_4 | 0xc;
    }
  } while( true );
}


// swap  @ 100a4180
/* Library Function - Single Match
    _swap
   
   Library: Visual Studio 1998 Release */

void __cdecl swap(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 uVar1;
  
  if (param_2 != param_1) {
    for (; param_3 != 0; param_3 = param_3 + -1) {
      uVar1 = *param_1;
      *param_1 = *param_2;
      param_1 = param_1 + 1;
      *param_2 = uVar1;
      param_2 = param_2 + 1;
    }
  }
  return;
}


// terminate  @ 100ac980
/* Library Function - Single Match
    void __cdecl terminate(void)
   
   Library: Visual Studio 1998 Release */

void __cdecl terminate(void)

{
  _ptiddata p_Var1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  uStack_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_100ba680;
  puStack_10 = &LAB_100ac8a4;
  *unaff_FS_OFFSET = &uStack_14;
  local_8 = 0;
  p_Var1 = __getptd();
  if (p_Var1->_tpxcptinfoptrs != (void *)0x0) {
    local_8 = 1;
    p_Var1 = __getptd();
    (*p_Var1->_tpxcptinfoptrs)();
  }
  local_8 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  _abort();
}


// wcsncnt  @ 100ab620
/* Library Function - Single Match
    _wcsncnt
   
   Library: Visual Studio 1998 Release */

int __cdecl wcsncnt(short *param_1,int param_2)

{
  int iVar1;
  short *psVar2;
  
  psVar2 = param_1;
  iVar1 = param_2;
  while (iVar1 != 0) {
    iVar1 = iVar1 + -1;
    if (*psVar2 == 0) goto LAB_100ab649;
    psVar2 = psVar2 + 1;
  }
  if (*psVar2 == 0) {
LAB_100ab649:
    param_2 = (int)psVar2 - (int)param_1 >> 1;
  }
  return param_2;
}


// wcsncnt  @ 100b28e0
/* Library Function - Single Match
    _wcsncnt
   
   Library: Visual Studio 1998 Release */

int __cdecl wcsncnt(short *param_1,int param_2)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = param_2;
  for (psVar2 = param_1; (iVar1 != 0 && (*psVar2 != 0)); psVar2 = psVar2 + 1) {
    iVar1 = iVar1 + -1;
  }
  if ((iVar1 != 0) && (*psVar2 == 0)) {
    param_2 = ((int)psVar2 - (int)param_1 >> 1) + 1;
  }
  return param_2;
}


// wcsncnt  @ 100b4970
/* Library Function - Single Match
    _wcsncnt
   
   Library: Visual Studio 1998 Release */

int __cdecl wcsncnt(short *param_1,int param_2)

{
  int iVar1;
  short *psVar2;
  
  psVar2 = param_1;
  iVar1 = param_2;
  while (iVar1 != 0) {
    iVar1 = iVar1 + -1;
    if (*psVar2 == 0) goto LAB_100b4999;
    psVar2 = psVar2 + 1;
  }
  if (*psVar2 == 0) {
LAB_100b4999:
    param_2 = (int)psVar2 - (int)param_1 >> 1;
  }
  return param_2;
}


// wcstoxl  @ 100b4200
/* Library Function - Single Match
    _wcstoxl
   
   Library: Visual Studio 1998 Release */

uint __cdecl wcstoxl(wint_t *param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  wint_t *pwVar1;
  wint_t wVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  wint_t *pwVar8;
  uint uVar9;
  
  uVar7 = 0;
  wVar2 = *param_1;
  iVar3 = _iswctype(wVar2,8);
  pwVar1 = param_1;
  while (pwVar8 = pwVar1 + 1, iVar3 != 0) {
    wVar2 = *pwVar8;
    iVar3 = _iswctype(wVar2,8);
    pwVar1 = pwVar8;
  }
  if (wVar2 == 0x2d) {
    wVar2 = *pwVar8;
    param_4 = param_4 | 2;
    pwVar8 = pwVar1 + 2;
  }
  else if (wVar2 == 0x2b) {
    wVar2 = *pwVar8;
    pwVar8 = pwVar1 + 2;
  }
  if ((((int)param_3 < 0) || (param_3 == 1)) || (0x24 < (int)param_3)) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_1;
    }
    return 0;
  }
  if (param_3 == 0) {
    if (wVar2 == 0x30) {
      if ((*pwVar8 == 0x78) || (*pwVar8 == 0x58)) {
        param_3 = 0x10;
      }
      else {
        param_3 = 8;
      }
    }
    else {
      param_3 = 10;
    }
  }
  if (((param_3 == 0x10) && (wVar2 == 0x30)) && ((*pwVar8 == 0x78 || (*pwVar8 == 0x58)))) {
    wVar2 = pwVar8[1];
    pwVar8 = pwVar8 + 2;
  }
  uVar4 = (uint)(0xffffffff / (ulonglong)param_3);
  do {
    iVar3 = _iswctype(wVar2,4);
    if (iVar3 == 0) {
      iVar3 = _iswctype(wVar2,0x103);
      if (iVar3 == 0) {
LAB_100b435c:
        pwVar8 = pwVar8 + -1;
        if ((param_4 & 8) == 0) {
          if (param_2 != (undefined4 *)0x0) {
            pwVar8 = param_1;
          }
          uVar7 = 0;
        }
        else if (((param_4 & 4) != 0) ||
                (((param_4 & 1) == 0 &&
                 ((((param_4 & 2) != 0 && (0x80000000 < uVar7)) ||
                  (((param_4 & 2) == 0 && (0x7fffffff < uVar7)))))))) {
          puVar5 = (undefined4 *)FUN_100a6390();
          *puVar5 = 0x22;
          if ((param_4 & 1) == 0) {
            if ((param_4 & 2) == 0) {
              uVar7 = 0x7fffffff;
            }
            else {
              uVar7 = 0x80000000;
            }
          }
          else {
            uVar7 = 0xffffffff;
          }
        }
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = pwVar8;
        }
        if ((param_4 & 2) != 0) {
          uVar7 = -uVar7;
        }
        return uVar7;
      }
      wVar2 = _towupper(wVar2);
      uVar6 = wVar2 - 0x37;
    }
    else {
      uVar6 = wVar2 - 0x30;
    }
    if (param_3 <= uVar6) goto LAB_100b435c;
    uVar9 = param_4 | 8;
    if ((uVar7 < uVar4) || ((uVar7 == uVar4 && (uVar6 <= (uint)(0xffffffff % (ulonglong)param_3)))))
    {
      uVar7 = uVar7 * param_3 + uVar6;
    }
    else {
      uVar9 = param_4 | 0xc;
    }
    wVar2 = *pwVar8;
    pwVar8 = pwVar8 + 1;
    param_4 = uVar9;
  } while( true );
}


// wfindenv  @ 100b7860
/* Library Function - Single Match
    _wfindenv
   
   Library: Visual Studio 1998 Release */

int __cdecl wfindenv(wchar_t *param_1,size_t param_2)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *DAT_100dd9a0;
  piVar3 = DAT_100dd9a0;
  while( true ) {
    if (iVar2 == 0) {
      return -((int)piVar3 - (int)DAT_100dd9a0 >> 2);
    }
    iVar2 = __wcsnicoll(param_1,(wchar_t *)*piVar3,param_2);
    if ((iVar2 == 0) && ((sVar1 = *(short *)(*piVar3 + param_2 * 2), sVar1 == 0x3d || (sVar1 == 0)))
       ) break;
    piVar3 = piVar3 + 1;
    iVar2 = *piVar3;
  }
  return (int)piVar3 - (int)DAT_100dd9a0 >> 2;
}


// wglCopyContext  @ 10029ec0
/* __stdcall wglCopyContext,12 */

undefined4 wglCopyContext(void)

{
                    /* 0x29ec0  406  _wglCopyContext@12 */
  return 0;
}


// wglCreateContext  @ 10027ff0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall wglCreateContext,4 */

undefined4 wglCreateContext(HDC param_1)

{
  char cVar1;
  bool bVar2;
  HRESULT HVar3;
  undefined4 uVar4;
  int iVar5;
  LSTATUS LVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  int *unaff_EBX;
  int unaff_EBP;
  undefined4 *puVar10;
  uint *puVar11;
  undefined4 *puVar12;
  char *pcVar13;
  HKEY pHStack_41c;
  int *piStack_418;
  HKEY pHStack_414;
  undefined4 uStack_410;
  HKEY *ppHStack_40c;
  HKEY pHStack_408;
  undefined4 uStack_404;
  undefined1 *puStack_400;
  HKEY pHStack_3fc;
  undefined4 uStack_3f8;
  HKEY pHStack_3f4;
  HKEY pHStack_3f0;
  HKEY pHStack_3ec;
  undefined1 *puStack_3e8;
  undefined4 *puStack_3e4;
  undefined4 uStack_3e0;
  undefined4 uStack_3dc;
  int *piStack_3d8;
  undefined4 uStack_3d4;
  HKEY pHStack_3d0;
  HKEY pHStack_3cc;
  HKEY pHStack_3c8;
  HKEY pHVar14;
  char *pcVar15;
  int *piVar16;
  int *piVar17;
  HKEY pHStack_390;
  int *piVar18;
  HKEY pHStack_374;
  int *piStack_370;
  HWND pHStack_36c;
  HKEY pHStack_368;
  undefined4 uStack_364;
  int *piStack_360;
  LONG *pLStack_35c;
  HKEY pHStack_358;
  int *piStack_338;
  uint auStack_2f4 [2];
  HWND pHStack_2ec;
  undefined4 uStack_2d4;
  undefined4 uStack_2d0;
  undefined4 uStack_2cc;
  undefined4 uStack_2c8;
  undefined4 uStack_2a4;
  undefined4 uStack_2a0;
  int iStack_290;
  uint uStack_28c;
  tagRECT local_274 [3];
  int iStack_244;
  undefined4 uStack_23c;
  int iStack_238;
  int aiStack_230 [60];
  undefined4 auStack_140 [3];
  undefined4 auStack_134 [77];
  
                    /* 0x27ff0  407  _wglCreateContext@4 */
  DAT_104234c4 = param_1;
  DAT_104234c0 = WindowFromDC(param_1);
  pHStack_358 = (HKEY)0x1002801f;
  GetClientRect(DAT_104234c0,local_274);
  DAT_104234b8 = local_274[0].right & 0xffff;
  DAT_104234bc = local_274[0].bottom & 0xffff;
  HVar3 = CoInitialize((LPVOID)0x0);
  if (HVar3 < 0) {
    uVar4 = 0;
  }
  else {
    pHStack_358 = (HKEY)0x0;
    pLStack_35c = (LONG *)0x10028062;
    iVar5 = DirectDrawCreate();
    if (iVar5 < 0) {
      pLStack_35c = (LONG *)0x1002806c;
      CoUninitialize();
      uVar4 = 0;
    }
    else {
      local_274[0].top = 0x6c;
      pLStack_35c = &local_274[0].top;
      piStack_360 = piStack_338;
      uStack_364 = 0x10028090;
      iVar5 = (**(code **)(*piStack_338 + 0x30))();
      if (iVar5 < 0) {
        pHStack_368 = (HKEY)0x1002809f;
        (**(code **)(*unaff_EBX + 8))();
        pHStack_368 = (HKEY)0x100280a7;
        CoUninitialize();
        uVar4 = 0;
      }
      else {
        pHStack_368 = (HKEY)0x100280b1;
        (**(code **)(*unaff_EBX + 8))();
        pHStack_368 = (HKEY)&DAT_104234c8;
        pHStack_36c = (HWND)&DAT_100b8918;
        piStack_370 = (int *)0x100280c0;
        iVar5 = FUN_100b5150();
        if (iVar5 < 0) {
          pHStack_368 = (HKEY)0x100280ca;
          CoUninitialize();
          uVar4 = 0;
        }
        else {
          pHStack_368 = (HKEY)0x0;
          pHStack_36c = DAT_104234c0;
          piStack_370 = DAT_10423648;
          pHStack_374 = DAT_104234c8;
          iVar5 = (**(code **)(DAT_104234c8->unused + 0x5c))();
          if (iVar5 < 0) {
            (**(code **)(DAT_104234c8->unused + 8))();
            CoUninitialize();
            uVar4 = 0;
          }
          else {
            puVar11 = auStack_2f4;
            for (iVar5 = 0x16; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar11 = 0;
              puVar11 = puVar11 + 1;
            }
            auStack_2f4[0] = 0x18;
            LVar6 = RegOpenKeyA((HKEY)0x80000002,s_Software_Microsoft_Quake_100c8d98,&pHStack_358);
            if (LVar6 == 0) {
              piStack_360 = (int *)0x4;
              pHStack_390 = (HKEY)0x10028167;
              LVar6 = RegQueryValueExA(pHStack_358,s_Emulation_100c8db4,(LPDWORD)0x0,
                                       (LPDWORD)&pLStack_35c,&stack0xfffffcb4,(LPDWORD)&piStack_360)
              ;
              if (((LVar6 == 0) && (pLStack_35c == (LONG *)0x4)) && (unaff_EBP != 0)) {
                uStack_2d4 = 0xa4665c60;
                uStack_2d0 = 0x11cf2673;
                uStack_2cc = 0xaa001aa3;
                uStack_2c8 = 0x5633b900;
                auStack_2f4[0] = auStack_2f4[0] | 0x40;
              }
              RegCloseKey(pHStack_358);
            }
            if (DAT_10423690 == 0) {
              pHStack_2ec = DAT_104234c0;
            }
            else {
              auStack_2f4[0] = auStack_2f4[0] | 1;
              iVar5 = (**(code **)(DAT_104234c8->unused + 0x14))();
              if (iVar5 < 0) {
                (**(code **)(DAT_104234c8->unused + 8))();
                CoUninitialize();
                return 0;
              }
              do {
                pHStack_390 = pHStack_368;
                iVar5 = (**(code **)(pHStack_368->unused + 0xc))();
                if (iVar5 < 0) {
                  (**(code **)(pHStack_368->unused + 8))();
                  (**(code **)(DAT_104234c8->unused + 8))();
                  CoUninitialize();
                  return 0;
                }
              } while ((pHStack_36c != (HWND)0x0) &&
                      (((auStack_2f4[0] != uStack_28c || (auStack_2f4[1] != iStack_290)) ||
                       (pHStack_2ec != (HWND)iStack_244))));
              (**(code **)(pHStack_368->unused + 8))();
              pHStack_2ec = (HWND)0x0;
            }
            uStack_2a4 = 0x3f800000;
            uStack_2a0 = 0x41200000;
            puVar11 = auStack_2f4;
            iVar5 = (**(code **)(DAT_104234c8->unused + 0x20))();
            if (iVar5 < 0) {
              (**(code **)(DAT_104234c8->unused + 8))();
              CoUninitialize();
              uVar4 = 0;
            }
            else {
              pHVar14 = DAT_104234c8;
              iVar5 = (**(code **)(DAT_104234c8->unused + 0x54))();
              if (iVar5 < 0) {
                (**(code **)(DAT_104234c8->unused + 8))();
                CoUninitialize();
                uVar4 = 0;
              }
              else {
                puVar9 = auStack_134;
                auStack_134[0] = 0xfc;
                aiStack_230[0] = 0xfc;
                piVar18 = aiStack_230;
                pHStack_390 = DAT_1042364c;
                (**(code **)(DAT_1042364c->unused + 0xc))();
                puVar10 = &uStack_23c;
                if (iStack_238 == 0) {
                  puVar10 = auStack_140;
                }
                puVar12 = &DAT_1042354c;
                for (iVar5 = 0x3f; iVar5 != 0; iVar5 = iVar5 + -1) {
                  *puVar12 = *puVar10;
                  puVar10 = puVar10 + 1;
                  puVar12 = puVar12 + 1;
                }
                LVar6 = RegOpenKeyA((HKEY)0x80000002,s_Software_Microsoft_Quake_100c8dc0,
                                    &pHStack_374);
                if (LVar6 == 0) {
                  LVar6 = RegQueryValueExA(pHStack_374,s_DisableMipMap_100c8ddc,(LPDWORD)0x0,
                                           (LPDWORD)&stack0xfffffc88,(LPBYTE)&pHStack_368,
                                           (LPDWORD)&stack0xfffffc84);
                  if (((LVar6 == 0) && (puVar11 == (uint *)0x4)) && (pHStack_368 != (HKEY)0x0)) {
                    DAT_10423684 = 0;
                    OutputDebugStringA(s_Wrapper__Mipmapping_disabled_100c8dec);
                  }
                  else {
                    DAT_10423684 = 1;
                  }
                  RegCloseKey(pHStack_374);
                }
                else {
                  DAT_10423684 = 1;
                }
                piVar16 = (int *)&stack0xfffffc80;
                piVar17 = (int *)0x0;
                iVar5 = (**(code **)(DAT_104234c8->unused + 0x18))();
                if (iVar5 < 0) {
                  (**(code **)(DAT_1042364c->unused + 8))();
                  (**(code **)(DAT_104234c8->unused + 8))();
                  CoUninitialize();
                  uVar4 = 0;
                }
                else {
                  bVar2 = false;
                  do {
                    iVar5 = (**(code **)(*piVar18 + 0xc))();
                    if (iVar5 < 0) {
                      (**(code **)(*piVar18 + 8))();
                      (**(code **)(DAT_1042364c->unused + 8))();
                      (**(code **)(DAT_104234c8->unused + 8))();
                      CoUninitialize();
                      return 0;
                    }
                    if (puVar9 == (undefined4 *)0x0) goto LAB_100284c6;
                  } while (((((((DAT_104234d0 & 0x40) == 0) || (DAT_104234d8 != 0x10)) ||
                             ((DAT_104234d0 & 1) == 0)) ||
                            ((DAT_104234e8 != 0x8000 || (DAT_104234dc != 0x7c00)))) ||
                           (DAT_104234e0 != 0x3e0)) || (DAT_104234e4 != 0x1f));
                  bVar2 = true;
LAB_100284c6:
                  if (bVar2) {
                    iVar5 = (**(code **)(*piVar18 + 0x14))();
                    if (iVar5 < 0) {
                      (**(code **)(pHStack_390->unused + 8))();
                      (**(code **)(DAT_1042364c->unused + 8))();
                      (**(code **)(DAT_104234c8->unused + 8))();
                      CoUninitialize();
                      uVar4 = 0;
                    }
                    else {
                      bVar2 = false;
                      do {
                        iVar5 = (**(code **)(pHStack_390->unused + 0xc))();
                        if (iVar5 < 0) {
                          (**(code **)(pHStack_390->unused + 8))();
                          (**(code **)(DAT_1042364c->unused + 8))();
                          (**(code **)(DAT_104234c8->unused + 8))();
                          CoUninitialize();
                          return 0;
                        }
                        if (piVar18 == (int *)0x0) goto LAB_100285ef;
                      } while ((((DAT_104234f0 & 0x40) == 0) || (DAT_104234f8 != 0x10)) ||
                              ((((DAT_104234f0 & 1) == 0 ||
                                (((DAT_10423508 != 0xf000 || (DAT_104234fc != 0xf00)) ||
                                 (DAT_10423500 != 0xf0)))) || (DAT_10423504 != 0xf))));
                      bVar2 = true;
LAB_100285ef:
                      if (!bVar2) {
                        OutputDebugStringA(s_Wrapper__Not_using_4444_texture__100c8e34);
                        puVar9 = &DAT_104234cc;
                        puVar10 = &DAT_104234ec;
                        for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
                          *puVar10 = *puVar9;
                          puVar9 = puVar9 + 1;
                          puVar10 = puVar10 + 1;
                        }
                      }
                      iVar5 = (**(code **)(pHStack_390->unused + 0x14))();
                      if (iVar5 < 0) {
                        (**(code **)(*piVar17 + 8))();
                        (**(code **)(DAT_1042364c->unused + 8))();
                        (**(code **)(DAT_104234c8->unused + 8))();
                        CoUninitialize();
                        uVar4 = 0;
                      }
                      else {
                        bVar2 = false;
                        do {
                          iVar5 = (**(code **)(*piVar17 + 0xc))();
                          if (iVar5 < 0) {
                            (**(code **)(*piVar17 + 8))();
                            (**(code **)(DAT_1042364c->unused + 8))();
                            (**(code **)(DAT_104234c8->unused + 8))();
                            CoUninitialize();
                            return 0;
                          }
                          if (pHStack_390 == (HKEY)0x0) goto LAB_100286fc;
                        } while (((((DAT_10423510 & 0x40) == 0) || (DAT_10423518 != 0x10)) ||
                                 (((DAT_10423510 & 1) != 0 ||
                                  ((DAT_1042351c != 0xf800 && (DAT_1042351c != 0x7c00)))))) ||
                                (((DAT_10423520 != 0x7e0 && (DAT_10423520 != 0x3e0)) ||
                                 (DAT_10423524 != 0x1f))));
                        bVar2 = true;
LAB_100286fc:
                        if (bVar2) {
                          iVar5 = (**(code **)(*piVar17 + 0x14))();
                          if (iVar5 < 0) {
                            (**(code **)(*piVar16 + 8))();
                            (**(code **)(DAT_1042364c->unused + 8))();
                            (**(code **)(DAT_104234c8->unused + 8))();
                            CoUninitialize();
                            uVar4 = 0;
                          }
                          else {
                            pHStack_390 = (HKEY)((uint)pHStack_390 & 0xffffff00);
                            do {
                              iVar5 = (**(code **)(*piVar16 + 0xc))();
                              if (iVar5 < 0) {
                                (**(code **)(*piVar16 + 8))();
                                (**(code **)(DAT_1042364c->unused + 8))();
                                (**(code **)(DAT_104234c8->unused + 8))();
                                CoUninitialize();
                                return 0;
                              }
                              if (piVar17 == (int *)0x0) goto LAB_100287fd;
                            } while ((((DAT_10423530 & 0x20000) == 0) || (DAT_10423538 != 8)) ||
                                    (DAT_1042353c != 0xff));
                            pHStack_390 = (HKEY)CONCAT31(pHStack_390._1_3_,1);
LAB_100287fd:
                            if ((char)pHStack_390 == '\0') {
                              OutputDebugStringA(s_Wrapper__Not_using_luminance_tex_100c8e88);
                              puVar9 = &DAT_1042350c;
                              puVar10 = &DAT_1042352c;
                              for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
                                *puVar10 = *puVar9;
                                puVar9 = puVar9 + 1;
                                puVar10 = puVar10 + 1;
                              }
                            }
                            (**(code **)(*piVar16 + 8))();
                            if ((DAT_10423600 < 0x200) || (DAT_10423604 < 0x200)) {
                              DAT_10423678 = 1;
                              OutputDebugStringA(s_Wrapper__Subsampling_textures_to_100c8eb0);
                            }
                            else {
                              DAT_10423678 = 0;
                            }
                            if ((DAT_104235d0 & 0x20) == 0) {
                              DAT_1042368c = 0;
                            }
                            else {
                              DAT_1042368c = 1;
                              OutputDebugStringA(s_Wrapper__Forcing_all_textures_to_100c8edc);
                            }
                            if (DAT_10423646 < 2) {
                              pcVar15 = s_Wrapper__Multitexturing_not_avai_100c8f2c;
                            }
                            else {
                              pcVar15 = s_Wrapper__Multitexturing_enabled_100c8f08;
                            }
                            DAT_10423680 = (uint)(DAT_10423646 >= 2);
                            OutputDebugStringA(pcVar15);
                            if ((DAT_104235d4 & 0x3c) == 0) {
                              DAT_10423684 = 0;
                              OutputDebugStringA(s_Wrapper__Mipmapping_disabled_100c8f64);
                            }
                            LVar6 = RegOpenKeyA((HKEY)0x80000002,s_Software_Microsoft_Quake_100c8f84
                                                ,&pHStack_390);
                            if (LVar6 == 0) {
                              pHStack_3c8 = (HKEY)0x1002894e;
                              LVar6 = RegQueryValueExA(pHStack_390,s_DoFlip_100c8fa0,(LPDWORD)0x0,
                                                       (LPDWORD)&stack0xfffffc6c,&stack0xfffffc7c,
                                                       (LPDWORD)&stack0xfffffc68);
                              if (((LVar6 == 0) && (piVar17 == (int *)0x4)) &&
                                 (pHVar14 != (HKEY)0x0)) {
                                DAT_10423688 = 1;
                              }
                              else {
                                DAT_10423688 = 0;
                              }
                              RegCloseKey(pHStack_390);
                            }
                            else {
                              DAT_10423688 = 0;
                            }
                            if (_DAT_100da53c != 0.0) {
                              DAT_10423688 = 1;
                            }
                            pHVar14 = DAT_104234c8;
                            iVar5 = (**(code **)(DAT_104234c8->unused + 0x50))();
                            if (iVar5 < 0) {
                              (**(code **)(DAT_1042364c->unused + 8))();
                              (**(code **)(DAT_104234c8->unused + 8))();
                              CoUninitialize();
                              uVar4 = 0;
                            }
                            else {
                              pHStack_3c8 = pHStack_390;
                              pHStack_3cc = (HKEY)0x10028a32;
                              iVar5 = (**(code **)(pHStack_390->unused + 0x24))();
                              if (iVar5 < 0) {
                                pHStack_3cc = DAT_1042364c;
                                pHStack_3d0 = (HKEY)0x10028a41;
                                (**(code **)(DAT_1042364c->unused + 8))();
                                pHStack_3d0 = DAT_104234c8;
                                uStack_3d4 = 0x10028a4d;
                                (**(code **)(DAT_104234c8->unused + 8))();
                                uStack_3d4 = 0x10028a53;
                                CoUninitialize();
                                uVar4 = 0;
                              }
                              else {
                                pHStack_3cc = (HKEY)&stack0xfffffcb4;
                                pHStack_3d0 = (HKEY)&DAT_104236cc;
                                uStack_3d4 = 0x821;
                                piStack_3d8 = DAT_10423654;
                                uStack_3dc = 0x10028a75;
                                pHStack_3ec = pHVar14;
                                (**(code **)(*DAT_10423654 + 0xc))();
                                uStack_3dc = 0;
                                uStack_3e0 = 0;
                                puStack_3e4 = &DAT_10423658;
                                puStack_3e8 = &stack0xfffffc54;
                                pHStack_3f0 = (HKEY)0x10028aa4;
                                iVar5 = (**(code **)(pHStack_3ec->unused + 0x24))();
                                if (iVar5 < 0) {
                                  pHStack_3f0 = DAT_1042364c;
                                  pHStack_3f4 = (HKEY)0x10028ab3;
                                  (**(code **)(DAT_1042364c->unused + 8))();
                                  pHStack_3f4 = DAT_104234c8;
                                  uStack_3f8 = 0x10028abf;
                                  (**(code **)(DAT_104234c8->unused + 8))();
                                  uStack_3f8 = 0x10028ac5;
                                  CoUninitialize();
                                  uVar4 = 0;
                                }
                                else {
                                  pHStack_3f0 = pHStack_3c8;
                                  pHStack_3f4 = (HKEY)0x10028ad8;
                                  (**(code **)(pHStack_3c8->unused + 8))();
                                  DAT_1042365c = 0x405;
                                  DAT_1042366c = 0;
                                  DAT_10423670 = 0;
                                  DAT_10423674 = 0;
                                  DAT_1042367c = 0;
                                  DAT_10423694 = 0;
                                  DAT_104236a4 = 0x2100;
                                  DAT_104236a8 = 0x2100;
                                  DAT_104234a8 = 0;
                                  DAT_104234ac = 0;
                                  DAT_104234b0 = 0;
                                  DAT_104236a0 = 0;
                                  puVar9 = &DAT_10423bbc;
                                  do {
                                    *puVar9 = 0;
                                    puVar10 = puVar9 + 0xc;
                                    puVar9[6] = 0;
                                    puVar9[1] = 1;
                                    puVar9[2] = 2;
                                    puVar9[3] = 3;
                                    puVar9[4] = 1;
                                    puVar9[5] = 1;
                                    puVar9 = puVar10;
                                  } while (puVar10 < &DAT_10453bbc);
                                  pHStack_390 = (HKEY)0x0;
                                  pHStack_3f4 = (HKEY)&stack0xfffffc4c;
                                  uStack_3f8 = 2;
                                  pHStack_3fc = DAT_1042364c;
                                  puStack_400 = (undefined1 *)0x10028bb6;
                                  (**(code **)(DAT_1042364c->unused + 100))();
                                  puStack_400 = &stack0xfffffc40;
                                  uStack_404 = 1;
                                  pHStack_408 = DAT_1042364c;
                                  ppHStack_40c = (HKEY *)0x10028bc8;
                                  (**(code **)(DAT_1042364c->unused + 100))();
                                  ppHStack_40c = &pHStack_3cc;
                                  uStack_410 = 3;
                                  pHStack_414 = DAT_1042364c;
                                  piStack_418 = (int *)0x10028bdf;
                                  (**(code **)(DAT_1042364c->unused + 100))();
                                  pHStack_41c = (HKEY)0x1;
                                  do {
                                    piStack_418 = (int *)((int)pHStack_41c * 4 + 0x104236e0);
                                    pHVar14 = (HKEY)((int)&pHStack_41c->unused + 1);
                                    (**(code **)(DAT_1042364c->unused + 0x54))(DAT_1042364c);
                                    pHStack_41c = pHVar14;
                                  } while ((int)pHVar14 < 0x100);
                                  pHStack_41c = (HKEY)0x1;
                                  do {
                                    piStack_418 = (int *)(&DAT_10423ae0 + (int)pHStack_41c * 4);
                                    pHVar14 = (HKEY)((int)&pHStack_41c->unused + 1);
                                    (**(code **)(DAT_1042364c->unused + 0x9c))(DAT_1042364c,0);
                                    pHStack_41c = pHVar14;
                                  } while ((int)pHVar14 < 0x18);
                                  if (DAT_10423680 != 0) {
                                    pHStack_41c = (HKEY)0x1;
                                    do {
                                      piStack_418 = (int *)((int)pHStack_41c * 4 + 0x10423b40);
                                      pHVar14 = (HKEY)((int)&pHStack_41c->unused + 1);
                                      (**(code **)(DAT_1042364c->unused + 0x9c))(DAT_1042364c,1);
                                      pHStack_41c = pHVar14;
                                    } while ((int)pHVar14 < 0x18);
                                  }
                                  DAT_10423ba0 = 0;
                                  DAT_10423ba4 = 0;
                                  if (DAT_104236f0 != 1) {
                                    if (DAT_104234b0 != 0) {
                                      if (DAT_104234ac != DAT_104234a8) {
                                        piStack_418 = (int *)0x0;
                                        pHStack_41c = DAT_1042364c;
                                        (**(code **)(*DAT_10423658 + 0x14))
                                                  (DAT_10423658,5,DAT_104234ac,
                                                   DAT_104234a8 - DAT_104234ac,DAT_10423654,
                                                   DAT_104234ac);
                                        DAT_104234ac = DAT_104234a8;
                                      }
                                      piStack_418 = DAT_10423654;
                                      pHStack_41c = (HKEY)0x10028cce;
                                      (**(code **)(*DAT_10423654 + 0x10))();
                                      pHStack_41c = (HKEY)0x8;
                                      (**(code **)(DAT_1042364c->unused + 0x8c))
                                                (DAT_1042364c,4,DAT_10423658,&DAT_10453ba8,
                                                 DAT_104234b0);
                                      (**(code **)(*DAT_10423654 + 0xc))
                                                (DAT_10423654,0x821,&DAT_104236cc,&pHStack_41c);
                                      DAT_104234ac = 0;
                                      DAT_104234a8 = 0;
                                      DAT_104234b0 = 0;
                                    }
                                    DAT_104236f0 = 1;
                                    piStack_418 = (int *)0x1;
                                    pHStack_41c = (HKEY)0x4;
                                    (**(code **)(DAT_1042364c->unused + 0x58))(DAT_1042364c);
                                  }
                                  if (DAT_10423754 != 0) {
                                    if (DAT_104234b0 != 0) {
                                      if (DAT_104234ac != DAT_104234a8) {
                                        piStack_418 = (int *)0x0;
                                        pHStack_41c = DAT_1042364c;
                                        (**(code **)(*DAT_10423658 + 0x14))
                                                  (DAT_10423658,5,DAT_104234ac,
                                                   DAT_104234a8 - DAT_104234ac,DAT_10423654,
                                                   DAT_104234ac);
                                        DAT_104234ac = DAT_104234a8;
                                      }
                                      piStack_418 = DAT_10423654;
                                      pHStack_41c = (HKEY)0x10028d9f;
                                      (**(code **)(*DAT_10423654 + 0x10))();
                                      pHStack_41c = (HKEY)0x8;
                                      (**(code **)(DAT_1042364c->unused + 0x8c))
                                                (DAT_1042364c,4,DAT_10423658,&DAT_10453ba8,
                                                 DAT_104234b0);
                                      (**(code **)(*DAT_10423654 + 0xc))
                                                (DAT_10423654,0x821,&DAT_104236cc,&pHStack_41c);
                                      DAT_104234ac = 0;
                                      DAT_104234a8 = 0;
                                      DAT_104234b0 = 0;
                                    }
                                    DAT_10423754 = 0;
                                    piStack_418 = (int *)0x0;
                                    pHStack_41c = (HKEY)0x1d;
                                    (**(code **)(DAT_1042364c->unused + 0x58))(DAT_1042364c);
                                  }
                                  if (DAT_10423748 != 1) {
                                    if (DAT_104234b0 != 0) {
                                      if (DAT_104234ac != DAT_104234a8) {
                                        piStack_418 = (int *)0x0;
                                        pHStack_41c = DAT_1042364c;
                                        (**(code **)(*DAT_10423658 + 0x14))
                                                  (DAT_10423658,5,DAT_104234ac,
                                                   DAT_104234a8 - DAT_104234ac,DAT_10423654,
                                                   DAT_104234ac);
                                        DAT_104234ac = DAT_104234a8;
                                      }
                                      piStack_418 = DAT_10423654;
                                      pHStack_41c = (HKEY)0x10028e71;
                                      (**(code **)(*DAT_10423654 + 0x10))();
                                      pHStack_41c = (HKEY)0x8;
                                      (**(code **)(DAT_1042364c->unused + 0x8c))
                                                (DAT_1042364c,4,DAT_10423658,&DAT_10453ba8,
                                                 DAT_104234b0);
                                      (**(code **)(*DAT_10423654 + 0xc))
                                                (DAT_10423654,0x821,&DAT_104236cc,&pHStack_41c);
                                      DAT_104234ac = 0;
                                      DAT_104234a8 = 0;
                                      DAT_104234b0 = 0;
                                    }
                                    DAT_10423748 = 1;
                                    piStack_418 = (int *)0x1;
                                    pHStack_41c = (HKEY)0x1a;
                                    (**(code **)(DAT_1042364c->unused + 0x58))(DAT_1042364c);
                                  }
                                  if (DAT_10423b0c != 0) {
                                    if (DAT_104234b0 != 0) {
                                      if (DAT_104234ac != DAT_104234a8) {
                                        piStack_418 = (int *)0x0;
                                        pHStack_41c = DAT_1042364c;
                                        (**(code **)(*DAT_10423658 + 0x14))
                                                  (DAT_10423658,5,DAT_104234ac,
                                                   DAT_104234a8 - DAT_104234ac,DAT_10423654,
                                                   DAT_104234ac);
                                        DAT_104234ac = DAT_104234a8;
                                      }
                                      piStack_418 = DAT_10423654;
                                      pHStack_41c = (HKEY)0x10028f42;
                                      (**(code **)(*DAT_10423654 + 0x10))();
                                      pHStack_41c = (HKEY)0x8;
                                      (**(code **)(DAT_1042364c->unused + 0x8c))
                                                (DAT_1042364c,4,DAT_10423658,&DAT_10453ba8,
                                                 DAT_104234b0);
                                      (**(code **)(*DAT_10423654 + 0xc))
                                                (DAT_10423654,0x821,&DAT_104236cc,&pHStack_41c);
                                      DAT_104234ac = 0;
                                      DAT_104234a8 = 0;
                                      DAT_104234b0 = 0;
                                    }
                                    DAT_10423b0c = 0;
                                    piStack_418 = (int *)0x0;
                                    pHStack_41c = (HKEY)0xb;
                                    (**(code **)(DAT_1042364c->unused + 0xa0))(DAT_1042364c,0);
                                  }
                                  if ((DAT_10423680 == 1) && (DAT_10423b6c != 1)) {
                                    if (DAT_104234b0 != 0) {
                                      if (DAT_104234ac != DAT_104234a8) {
                                        piStack_418 = (int *)0x0;
                                        pHStack_41c = DAT_1042364c;
                                        (**(code **)(*DAT_10423658 + 0x14))
                                                  (DAT_10423658,5,DAT_104234ac,
                                                   DAT_104234a8 - DAT_104234ac,DAT_10423654,
                                                   DAT_104234ac);
                                        DAT_104234ac = DAT_104234a8;
                                      }
                                      piStack_418 = DAT_10423654;
                                      pHStack_41c = (HKEY)0x10029027;
                                      (**(code **)(*DAT_10423654 + 0x10))();
                                      pHStack_41c = (HKEY)0x8;
                                      (**(code **)(DAT_1042364c->unused + 0x8c))
                                                (DAT_1042364c,4,DAT_10423658,&DAT_10453ba8,
                                                 DAT_104234b0);
                                      (**(code **)(*DAT_10423654 + 0xc))
                                                (DAT_10423654,0x821,&DAT_104236cc,&pHStack_41c);
                                      DAT_104234ac = 0;
                                      DAT_104234a8 = 0;
                                      DAT_104234b0 = 0;
                                    }
                                    DAT_10423b6c = 1;
                                    piStack_418 = (int *)0x1;
                                    pHStack_41c = (HKEY)0xb;
                                    (**(code **)(DAT_1042364c->unused + 0xa0))(DAT_1042364c,1);
                                  }
                                  piStack_418 = (int *)&DAT_10423648;
                                  pHStack_41c = DAT_104234c8;
                                  iVar5 = (**(code **)(DAT_104234c8->unused + 0x40))();
                                  if (iVar5 < 0) {
                                    (**(code **)(DAT_1042364c->unused + 8))(DAT_1042364c);
                                    (**(code **)(DAT_104234c8->unused + 8))(DAT_104234c8);
                                    CoUninitialize();
                                    uVar4 = 0;
                                  }
                                  else {
                                    iVar5 = (**(code **)(*DAT_10423648 + 0x6c))
                                                      (DAT_10423648,&DAT_10423078,1);
                                    if (iVar5 < 0) {
                                      uVar7 = 0xffffffff;
                                      pcVar15 = s_Microsoft_Corp__100c8fa8;
                                      do {
                                        pcVar13 = pcVar15;
                                        if (uVar7 == 0) break;
                                        uVar7 = uVar7 - 1;
                                        pcVar13 = pcVar15 + 1;
                                        cVar1 = *pcVar15;
                                        pcVar15 = pcVar13;
                                      } while (cVar1 != '\0');
                                      uVar7 = ~uVar7;
                                      pcVar15 = pcVar13 + -uVar7;
                                      pcVar13 = (char *)&DAT_10423078;
                                      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                                        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar15;
                                        pcVar15 = pcVar15 + 4;
                                        pcVar13 = pcVar13 + 4;
                                      }
                                      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                                        *pcVar13 = *pcVar15;
                                        pcVar15 = pcVar15 + 1;
                                        pcVar13 = pcVar13 + 1;
                                      }
                                      uVar7 = 0xffffffff;
                                      pcVar15 = s_Direct3D_100c8fb8;
                                      do {
                                        pcVar13 = pcVar15;
                                        if (uVar7 == 0) break;
                                        uVar7 = uVar7 - 1;
                                        pcVar13 = pcVar15 + 1;
                                        cVar1 = *pcVar15;
                                        pcVar15 = pcVar13;
                                      } while (cVar1 != '\0');
                                      uVar7 = ~uVar7;
                                      pcVar15 = pcVar13 + -uVar7;
                                      pcVar13 = (char *)&DAT_10423278;
                                      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                                        *(undefined4 *)pcVar13 = *(undefined4 *)pcVar15;
                                        pcVar15 = pcVar15 + 4;
                                        pcVar13 = pcVar13 + 4;
                                      }
                                      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                                        *pcVar13 = *pcVar15;
                                        pcVar15 = pcVar15 + 1;
                                        pcVar13 = pcVar13 + 1;
                                      }
                                    }
                                    iVar5 = (**(code **)(DAT_1042364c->unused + 0x34))
                                                      (DAT_1042364c,&DAT_10423650);
                                    if (iVar5 < 0) {
                                      (**(code **)(DAT_1042364c->unused + 8))();
                                      (**(code **)(*DAT_10423648 + 8))(DAT_10423648);
                                      (**(code **)(DAT_104234c8->unused + 8))(DAT_104234c8);
                                      CoUninitialize();
                                      uVar4 = 0;
                                    }
                                    else {
                                      (**(code **)(DAT_1042364c->unused + 0x24))(DAT_1042364c);
                                      uVar4 = 1;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                        else {
                          OutputDebugStringA(s_Wrapper__Unable_to_find_555_or_5_100c8e58);
                          (**(code **)(*piVar17 + 8))();
                          (**(code **)(DAT_1042364c->unused + 8))();
                          (**(code **)(DAT_104234c8->unused + 8))();
                          CoUninitialize();
                          uVar4 = 0;
                        }
                      }
                    }
                  }
                  else {
                    OutputDebugStringA(s_Wrapper__Unable_to_find_5551_tex_100c8e0c);
                    (**(code **)(*piVar18 + 8))();
                    (**(code **)(DAT_1042364c->unused + 8))();
                    (**(code **)(DAT_104234c8->unused + 8))();
                    CoUninitialize();
                    uVar4 = 0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar4;
}


// wglCreateLayerContext  @ 10029ed0
/* __stdcall wglCreateLayerContext,8 */

undefined4 wglCreateLayerContext(void)

{
                    /* 0x29ed0  408  _wglCreateLayerContext@8 */
  return 1;
}


// wglDeleteContext  @ 10029c30
/* __stdcall wglDeleteContext,4 */

undefined4 wglDeleteContext(void)

{
  int *piVar1;
  int *piVar2;
  
                    /* 0x29c30  409  _wglDeleteContext@4 */
  if (DAT_104234c8 == (int *)0x0) {
    return 1;
  }
  piVar2 = &DAT_10423bd4;
  (**(code **)(*DAT_1042364c + 0x28))(DAT_1042364c);
  do {
    piVar1 = (int *)*piVar2;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *piVar2 = 0;
    }
    piVar1 = (int *)piVar2[-6];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      piVar2[-6] = 0;
    }
    piVar2 = piVar2 + 0xc;
  } while (piVar2 < &DAT_10453bd4);
  (**(code **)(*DAT_10423650 + 8))(DAT_10423650);
  DAT_10423650 = (int *)0x0;
  (**(code **)(*DAT_10423654 + 0x10))(DAT_10423654);
  (**(code **)(*DAT_10423654 + 8))(DAT_10423654);
  DAT_10423654 = (int *)0x0;
  (**(code **)(*DAT_10423658 + 8))(DAT_10423658);
  DAT_10423658 = (int *)0x0;
  (**(code **)(*DAT_1042364c + 8))(DAT_1042364c);
  DAT_1042364c = (int *)0x0;
  (**(code **)(*DAT_10423648 + 8))(DAT_10423648);
  DAT_10423648 = (int *)0x0;
  (**(code **)(*DAT_104234c8 + 8))(DAT_104234c8);
  DAT_104234c8 = (int *)0x0;
  CoUninitialize();
  return 1;
}


// wglDescribeLayerPlane  @ 10029ee0
/* __stdcall wglDescribeLayerPlane,20 */

undefined4 wglDescribeLayerPlane(void)

{
                    /* 0x29ee0  410  _wglDescribeLayerPlane@20 */
  return 0;
}


// wglGetCurrentContext  @ 10029f00
/* __stdcall wglGetCurrentContext,0 */

undefined4 wglGetCurrentContext(void)

{
                    /* 0x29f00  411  _wglGetCurrentContext@0 */
  return 1;
}


// wglGetCurrentDC  @ 10029f20
/* __stdcall wglGetCurrentDC,0 */

undefined4 wglGetCurrentDC(void)

{
                    /* 0x29f20  412  _wglGetCurrentDC@0 */
  return DAT_104234c4;
}


// wglGetLayerPaletteEntries  @ 10029f10
/* __stdcall wglGetLayerPaletteEntries,20 */

undefined4 wglGetLayerPaletteEntries(void)

{
                    /* 0x29f10  413  _wglGetLayerPaletteEntries@20 */
  return 0;
}


// wglGetProcAddress  @ 10029f50
/* __stdcall wglGetProcAddress,4 */

undefined1 * wglGetProcAddress(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  char *pcVar4;
  bool bVar5;
  
                    /* 0x29f50  414  _wglGetProcAddress@4 */
  pcVar4 = s_glMTexCoord2fSGIS_100c8fc4;
  pbVar2 = param_1;
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < (byte)*pcVar4;
    if (bVar1 != *pcVar4) {
LAB_10029f7c:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_10029f81;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < (byte)pcVar4[1];
    if (bVar1 != pcVar4[1]) goto LAB_10029f7c;
    pbVar2 = pbVar2 + 2;
    pcVar4 = pcVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_10029f81:
  if (iVar3 == 0) {
    return &LAB_1002a800;
  }
  pcVar4 = s_glSelectTextureSGIS_100c8fd8;
  do {
    bVar1 = *param_1;
    bVar5 = bVar1 < (byte)*pcVar4;
    if (bVar1 != *pcVar4) {
LAB_10029fb8:
      iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_10029fbd;
    }
    if (bVar1 == 0) break;
    bVar1 = param_1[1];
    bVar5 = bVar1 < (byte)pcVar4[1];
    if (bVar1 != pcVar4[1]) goto LAB_10029fb8;
    param_1 = param_1 + 2;
    pcVar4 = pcVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_10029fbd:
  return (undefined1 *)((iVar3 != 0) - 1 & 0x1002a840);
}


// wglMakeCurrent  @ 10029ff0
/* __stdcall wglMakeCurrent,8 */

undefined4 wglMakeCurrent(void)

{
                    /* 0x29ff0  415  _wglMakeCurrent@8 */
  return 1;
}


// wglRealizeLayerPalette  @ 10029f40
/* __stdcall wglRealizeLayerPalette,12 */

undefined4 wglRealizeLayerPalette(void)

{
                    /* 0x29f40  416  _wglRealizeLayerPalette@12 */
  return 0;
}


// wglSetLayerPaletteEntries  @ 10029fd0
/* __stdcall wglSetLayerPaletteEntries,20 */

undefined4 wglSetLayerPaletteEntries(void)

{
                    /* 0x29fd0  417  _wglSetLayerPaletteEntries@20 */
  return 0;
}


// wglShareLists  @ 10029fe0
/* __stdcall wglShareLists,8 */

undefined4 wglShareLists(void)

{
                    /* 0x29fe0  418  _wglShareLists@8 */
  return 0;
}


// wglSwapLayerBuffers  @ 1002a000
/* __stdcall wglSwapLayerBuffers,8 */

undefined4 wglSwapLayerBuffers(void)

{
                    /* 0x2a000  419  _wglSwapLayerBuffers@8 */
  return 0;
}


// wglUseFontBitmapsA  @ 1002a020
/* __stdcall wglUseFontBitmapsA,16 */

undefined4 wglUseFontBitmapsA(void)

{
                    /* 0x2a020  420  _wglUseFontBitmapsA@16 */
  return 0;
}


// wglUseFontBitmapsW  @ 1002a140
/* __stdcall wglUseFontBitmapsW,16 */

undefined4 wglUseFontBitmapsW(void)

{
                    /* 0x2a140  421  _wglUseFontBitmapsW@16 */
  return 0;
}


// wglUseFontOutlinesA  @ 1002a150
/* __stdcall wglUseFontOutlinesA,32 */

undefined4 wglUseFontOutlinesA(void)

{
                    /* 0x2a150  422  _wglUseFontOutlinesA@32 */
  return 0;
}


// wglUseFontOutlinesW  @ 1002a170
/* __stdcall wglUseFontOutlinesW,32 */

undefined4 wglUseFontOutlinesW(void)

{
                    /* 0x2a170  423  _wglUseFontOutlinesW@32 */
  return 0;
}


// xtoa  @ 100ae160
/* Library Function - Single Match
    _xtoa
   
   Library: Visual Studio 1998 Release */

void __cdecl xtoa(uint param_1,char *param_2,uint param_3,int param_4)

{
  ulonglong uVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  
  pcVar2 = param_2;
  if (param_4 != 0) {
    *param_2 = '-';
    param_2 = param_2 + 1;
    param_1 = -param_1;
    pcVar2 = param_2;
  }
  do {
    pcVar4 = pcVar2;
    uVar1 = (ulonglong)param_1;
    param_1 = param_1 / param_3;
    cVar3 = (char)(uVar1 % (ulonglong)param_3);
    if ((uint)(uVar1 % (ulonglong)param_3) < 10) {
      cVar3 = cVar3 + '0';
    }
    else {
      cVar3 = cVar3 + 'W';
    }
    *pcVar4 = cVar3;
    pcVar2 = pcVar4 + 1;
  } while (param_1 != 0);
  pcVar4[1] = '\0';
  do {
    cVar3 = *pcVar4;
    *pcVar4 = *param_2;
    pcVar4 = pcVar4 + -1;
    *param_2 = cVar3;
    param_2 = param_2 + 1;
  } while (param_2 < pcVar4);
  return;
}


