// .LFB12  @ 000a33f8
size_t * _LFB12(size_t *param_1)

{
  uint __size;
  int iVar1;
  size_t *psVar2;
  size_t sVar3;
  uint uVar4;
  
  uVar4 = 0x10;
  if (0x10 < *param_1 + 1) {
    do {
      uVar4 = uVar4 * 2;
    } while (uVar4 < *param_1 + 1);
  }
  __size = uVar4 + 0x10;
  if (__size < 0x81) {
    iVar1 = (uVar4 + 0x17 >> 3) * 4;
    pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    psVar2 = *(size_t **)(&DAT_000b3e5c + iVar1);
    if (psVar2 == (size_t *)0x0) {
      psVar2 = (size_t *)refill__t24__default_alloc_template2b1i0Ui(uVar4 + 0x10);
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
    else {
      *(size_t *)(&DAT_000b3e5c + iVar1) = *psVar2;
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
  }
  else {
    psVar2 = malloc(__size);
    if (psVar2 == (size_t *)0x0) {
      psVar2 = (size_t *)oom_malloc__t23__malloc_alloc_template1i0Ui(__size);
    }
  }
  psVar2[1] = uVar4;
  psVar2[2] = 1;
  *(undefined1 *)(psVar2 + 3) = 0;
  sVar3 = 0;
  if (*param_1 != 0) {
    memcpy(psVar2 + 4,param_1 + 4,*param_1);
    sVar3 = *param_1;
  }
  *psVar2 = sVar3;
  return psVar2 + 4;
}


// .LFB15  @ 000a37d4
uint _LFB15(int *param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  
  iVar5 = *param_1;
  if (*(uint *)(iVar5 + -0x10) < param_3) {
    __out_of_range__FPCc("pos > length ()");
    iVar5 = *param_1;
  }
  uVar3 = *(int *)(iVar5 + -0x10) - param_3;
  uVar6 = uVar3;
  if (param_4 < uVar3) {
    uVar6 = param_4;
  }
  uVar1 = *(uint *)((byte *)*param_2 + -0x10);
  if (uVar1 < uVar6) {
    uVar6 = uVar1;
  }
  bVar9 = false;
  uVar2 = 0;
  bVar10 = true;
  uVar4 = uVar6;
  pbVar7 = (byte *)(param_3 + iVar5);
  pbVar8 = (byte *)*param_2;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    bVar9 = *pbVar7 < *pbVar8;
    bVar10 = *pbVar7 == *pbVar8;
    pbVar7 = pbVar7 + 1;
    pbVar8 = pbVar8 + 1;
  } while (bVar10);
  if (!bVar10) {
    uVar2 = -(uint)bVar9 | 1;
  }
  if (uVar2 == 0) {
    if (uVar6 == param_4) {
      uVar2 = 0;
    }
    else {
      uVar2 = uVar3 - uVar1;
    }
  }
  return uVar2;
}


// .LFE12  @ 000a3504
int * _LFE12(int *param_1,uint param_2,uint param_3,void *param_4,size_t param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  undefined4 *puVar5;
  void *__src;
  int iVar6;
  uint uVar7;
  size_t sVar8;
  uint uVar9;
  bool bVar10;
  undefined4 *local_24;
  
  uVar1 = *(uint *)(*param_1 + -0x10);
  if (uVar1 < param_2) {
    __out_of_range__FPCc("pos > len");
  }
  if (uVar1 - param_2 < param_3) {
    param_3 = uVar1 - param_2;
  }
  if (-param_5 - 2 < uVar1 - param_3) {
    __length_error__FPCc("len - n1 > max_size () - n2");
  }
  iVar6 = (uVar1 - param_3) + param_5;
  uVar7 = iVar6 + 1;
  *(undefined1 *)(*param_1 + -4) = 0;
  bVar4 = false;
  local_24 = (undefined4 *)*param_1;
  if (((uint)local_24[-2] < 2) && (uVar9 = local_24[-3], uVar7 <= uVar9)) {
    if (uVar7 < 0x11) {
      bVar10 = 0x20 < uVar9;
    }
    else {
      bVar10 = uVar7 * 2 < uVar9;
    }
    if (!bVar10) goto LAB_000a35a6;
  }
  bVar4 = true;
LAB_000a35a6:
  if (bVar4) {
    uVar9 = 0x10;
    if (0x10 < uVar7) {
      do {
        uVar9 = uVar9 * 2;
      } while (uVar9 < uVar7);
    }
    uVar7 = uVar9 + 0x10;
    if (uVar7 < 0x81) {
      iVar2 = (uVar9 + 0x17 >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      puVar5 = *(undefined4 **)(&DAT_000b3e5c + iVar2);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)refill__t24__default_alloc_template2b1i0Ui(uVar9 + 0x10);
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
      }
      else {
        *(undefined4 *)(&DAT_000b3e5c + iVar2) = *puVar5;
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
      }
    }
    else {
      puVar5 = malloc(uVar7);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)oom_malloc__t23__malloc_alloc_template1i0Ui(uVar7);
      }
    }
    puVar5[1] = uVar9;
    puVar5[2] = 1;
    *(undefined1 *)(puVar5 + 3) = 0;
    local_24 = (undefined4 *)*param_1;
    if (param_2 != 0) {
      memcpy(puVar5 + 4,local_24,param_2);
      local_24 = (undefined4 *)*param_1;
    }
    sVar8 = uVar1 - (param_2 + param_3);
    __src = (void *)((int)local_24 + param_3 + param_2);
    local_24 = puVar5 + 4;
    if (sVar8 != 0) {
      memcpy((void *)(param_2 + param_5 + (int)local_24),__src,sVar8);
    }
    if (param_5 != 0) {
      memcpy((void *)(param_2 + (int)local_24),param_4,param_5);
    }
    iVar2 = *param_1;
    iVar3 = *(int *)(iVar2 + -8);
    *(int *)(iVar2 + -8) = iVar3 + -1;
    if (iVar3 == 1) {
      if (*(int *)(iVar2 + -0xc) + 0x10U < 0x81) {
        iVar3 = (*(int *)(iVar2 + -0xc) + 0x17U >> 3) * 4;
        pthread_mutex_lock((pthread_mutex_t *)
                           _t24__default_alloc_template2b1i0___node_allocator_lock);
        *(undefined4 *)(iVar2 + -0x10) = *(undefined4 *)(&DAT_000b3e5c + iVar3);
        *(void **)(&DAT_000b3e5c + iVar3) = (void *)(iVar2 + -0x10);
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
      }
      else {
        free((void *)(iVar2 + -0x10));
      }
    }
    *param_1 = (int)local_24;
  }
  else {
    sVar8 = uVar1 - (param_2 + param_3);
    if (sVar8 != 0) {
      memmove((void *)(param_2 + param_5 + (int)local_24),
              (void *)((int)local_24 + param_3 + param_2),sVar8);
      local_24 = (undefined4 *)*param_1;
    }
    if (param_5 != 0) {
      memcpy((void *)((int)local_24 + param_2),param_4,param_5);
      local_24 = (undefined4 *)*param_1;
    }
  }
  local_24[-4] = iVar6;
  return param_1;
}


// .LFE15  @ 000a384c
int * _LFE15(int *param_1,int param_2,uint param_3,int *param_4,uint param_5,uint param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = *param_4;
  uVar1 = *(uint *)(iVar3 + -0x10);
  if (param_2 == 0) {
    iVar2 = *param_1;
    if (((*(uint *)(iVar2 + -0x10) <= param_3) && (param_5 == 0)) && (uVar1 <= param_6)) {
      if (param_4 == param_1) {
        return param_1;
      }
      iVar3 = *(int *)(iVar2 + -8);
      *(int *)(iVar2 + -8) = iVar3 + -1;
      if (iVar3 == 1) {
        if (*(int *)(iVar2 + -0xc) + 0x10U < 0x81) {
          iVar3 = (*(int *)(iVar2 + -0xc) + 0x17U >> 3) * 4;
          pthread_mutex_lock((pthread_mutex_t *)
                             _t24__default_alloc_template2b1i0___node_allocator_lock);
          *(undefined4 *)(iVar2 + -0x10) = *(undefined4 *)(&DAT_000b3e5c + iVar3);
          *(void **)(&DAT_000b3e5c + iVar3) = (void *)(iVar2 + -0x10);
          pthread_mutex_unlock
                    ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
        }
        else {
          free((void *)(iVar2 + -0x10));
        }
      }
      iVar3 = *param_4;
      if (*(char *)(iVar3 + -4) == '\0') {
        *(int *)(iVar3 + -8) = *(int *)(iVar3 + -8) + 1;
      }
      else {
        iVar3 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                          (iVar3 + -0x10);
      }
      *param_1 = iVar3;
      return param_1;
    }
  }
  if (uVar1 < param_5) {
    __out_of_range__FPCc("pos2 > len2");
    iVar3 = *param_4;
  }
  if (uVar1 - param_5 < param_6) {
    param_6 = uVar1 - param_5;
  }
  piVar4 = (int *)replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
                            (param_1,param_2,param_3,iVar3 + param_5,param_6);
  return piVar4;
}


// AlertMessage  @ 00093f08
void AlertMessage(int param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  undefined1 *__arg;
  
  if ((param_1 == 5) && (1 < DAT_001ab4e8)) {
    vsprintf(&szOut_141,param_2,&stack0x0000000c);
    Log_Printf(&DAT_000aea8e,&szOut_141);
    return;
  }
  if ((byte)((float)developer._12_4_ < 0.0 |
             (byte)((ushort)((ushort)NAN((float)developer._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)developer._12_4_ == 0.0) << 0xe) >> 8)) == 0x40) {
    return;
  }
  switch(param_1) {
  case 0:
    pcVar1 = "NOTE:  ";
    break;
  case 2:
    if ((float)developer._12_4_ < 2.0) {
      return;
    }
  case 1:
    szOut_141 = 0;
    goto switchD_00093f7d_default;
  case 3:
    pcVar1 = "WARNING:  ";
    break;
  case 4:
    pcVar1 = "ERROR:  ";
    break;
  default:
    goto switchD_00093f7d_default;
  }
  Q_strcpy(&szOut_141,pcVar1);
switchD_00093f7d_default:
  __arg = &stack0x0000000c;
  iVar2 = Q_strlen(&szOut_141);
  vsprintf(&szOut_141 + iVar2,param_2,__arg);
  Con_Printf(&DAT_000aea8e,&szOut_141);
  if (((param_1 != 5) && (param_1 != 1)) && (param_1 != 2)) {
    if (param_1 == 4) {
      Sys_Error(&szOut_141);
    }
    else if (param_1 == 3) {
      Sys_Warning(&szOut_141);
    }
  }
  return;
}


// AllocEngineString  @ 000720bc
int AllocEngineString(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ED_NewString(param_1);
  return iVar1 - pr_strings;
}


// AngleIMatrix  @ 000618b8
void AngleIMatrix(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  longdouble lVar7;
  
  lVar7 = (longdouble)fsin((longdouble)(param_1[1] * 0.017453292));
  fVar1 = (float)lVar7;
  lVar7 = (longdouble)fcos((longdouble)(param_1[1] * 0.017453292));
  fVar2 = (float)lVar7;
  lVar7 = (longdouble)fsin((longdouble)(*param_1 * 0.017453292));
  fVar3 = (float)lVar7;
  lVar7 = (longdouble)fcos((longdouble)(*param_1 * 0.017453292));
  fVar4 = (float)lVar7;
  lVar7 = (longdouble)fsin((longdouble)(param_1[2] * 0.017453292));
  fVar5 = (float)lVar7;
  lVar7 = (longdouble)fcos((longdouble)(param_1[2] * 0.017453292));
  fVar6 = (float)lVar7;
  *param_2 = fVar4 * fVar2;
  param_2[1] = fVar4 * fVar1;
  param_2[2] = -fVar3;
  param_2[4] = fVar6 * -fVar1 + fVar5 * fVar3 * fVar2;
  param_2[5] = fVar5 * fVar3 * fVar1 + fVar6 * fVar2;
  param_2[6] = fVar5 * fVar4;
  param_2[8] = fVar6 * fVar3 * fVar2 + -fVar5 * -fVar1;
  param_2[3] = 0.0;
  param_2[7] = 0.0;
  param_2[0xb] = 0.0;
  param_2[9] = fVar6 * fVar3 * fVar1 + -fVar5 * fVar2;
  param_2[10] = fVar6 * fVar4;
  return;
}


// AngleMatrix  @ 000617b4
void AngleMatrix(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  longdouble lVar7;
  
  lVar7 = (longdouble)fsin((longdouble)(param_1[1] * 0.017453292));
  fVar1 = (float)lVar7;
  lVar7 = (longdouble)fcos((longdouble)(param_1[1] * 0.017453292));
  fVar2 = (float)lVar7;
  lVar7 = (longdouble)fsin((longdouble)(*param_1 * 0.017453292));
  fVar3 = (float)lVar7;
  lVar7 = (longdouble)fcos((longdouble)(*param_1 * 0.017453292));
  fVar4 = (float)lVar7;
  lVar7 = (longdouble)fsin((longdouble)(param_1[2] * 0.017453292));
  fVar5 = (float)lVar7;
  lVar7 = (longdouble)fcos((longdouble)(param_1[2] * 0.017453292));
  fVar6 = (float)lVar7;
  *param_2 = fVar4 * fVar2;
  param_2[4] = fVar4 * fVar1;
  param_2[8] = -fVar3;
  param_2[1] = fVar6 * -fVar1 + fVar5 * fVar3 * fVar2;
  param_2[5] = fVar5 * fVar3 * fVar1 + fVar6 * fVar2;
  param_2[9] = fVar5 * fVar4;
  param_2[2] = fVar6 * fVar3 * fVar2 + -fVar5 * -fVar1;
  param_2[3] = 0.0;
  param_2[7] = 0.0;
  param_2[0xb] = 0.0;
  param_2[6] = fVar6 * fVar3 * fVar1 + -fVar5 * fVar2;
  param_2[10] = fVar6 * fVar4;
  return;
}


// AngleQuaternion  @ 0005e448
void AngleQuaternion(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  longdouble lVar6;
  longdouble lVar7;
  longdouble lVar8;
  longdouble lVar9;
  
  lVar6 = (longdouble)fsin((longdouble)(param_1[2] * 0.5));
  fVar1 = (float)lVar6;
  lVar6 = (longdouble)fcos((longdouble)(param_1[2] * 0.5));
  fVar2 = (float)lVar6;
  lVar6 = (longdouble)fsin((longdouble)(param_1[1] * 0.5));
  lVar7 = (longdouble)fcos((longdouble)(param_1[1] * 0.5));
  lVar8 = (longdouble)fsin((longdouble)(*param_1 * 0.5));
  lVar9 = (longdouble)fcos((longdouble)(*param_1 * 0.5));
  fVar3 = (float)lVar8 * (float)lVar7;
  fVar5 = (float)lVar9 * (float)lVar6;
  *param_2 = fVar3 * fVar2 - fVar5 * fVar1;
  fVar4 = (float)lVar9 * (float)lVar7;
  param_2[1] = fVar3 * fVar1 + fVar5 * fVar2;
  fVar3 = (float)lVar8 * (float)lVar6;
  param_2[2] = fVar4 * fVar1 - fVar3 * fVar2;
  param_2[3] = fVar3 * fVar1 + fVar4 * fVar2;
  return;
}


// AngleVectors  @ 00061588
void AngleVectors(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  longdouble lVar7;
  
  lVar7 = (longdouble)fsin((longdouble)(param_1[1] * 0.017453292));
  fVar1 = (float)lVar7;
  lVar7 = (longdouble)fcos((longdouble)(param_1[1] * 0.017453292));
  fVar2 = (float)lVar7;
  lVar7 = (longdouble)fsin((longdouble)(*param_1 * 0.017453292));
  fVar3 = (float)lVar7;
  lVar7 = (longdouble)fcos((longdouble)(*param_1 * 0.017453292));
  fVar4 = (float)lVar7;
  lVar7 = (longdouble)fsin((longdouble)(param_1[2] * 0.017453292));
  fVar5 = (float)lVar7;
  lVar7 = (longdouble)fcos((longdouble)(param_1[2] * 0.017453292));
  fVar6 = (float)lVar7;
  if (param_2 != (float *)0x0) {
    *param_2 = fVar4 * fVar2;
    param_2[1] = fVar4 * fVar1;
    param_2[2] = -fVar3;
  }
  if (param_3 != (float *)0x0) {
    *param_3 = fVar6 * fVar1 + fVar5 * -fVar3 * fVar2;
    param_3[1] = fVar6 * -fVar2 + fVar5 * -fVar3 * fVar1;
    param_3[2] = fVar5 * -fVar4;
  }
  if (param_4 != (float *)0x0) {
    *param_4 = -fVar5 * -fVar1 + fVar6 * fVar3 * fVar2;
    param_4[1] = fVar6 * fVar3 * fVar1 + -fVar5 * fVar2;
    param_4[2] = fVar6 * fVar4;
  }
  return;
}


// AngleVectorsTranspose  @ 000616a0
void AngleVectorsTranspose(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  longdouble lVar7;
  
  lVar7 = (longdouble)fsin((longdouble)(param_1[1] * 0.017453292));
  fVar1 = (float)lVar7;
  lVar7 = (longdouble)fcos((longdouble)(param_1[1] * 0.017453292));
  fVar2 = (float)lVar7;
  lVar7 = (longdouble)fsin((longdouble)(*param_1 * 0.017453292));
  fVar3 = (float)lVar7;
  lVar7 = (longdouble)fcos((longdouble)(*param_1 * 0.017453292));
  fVar4 = (float)lVar7;
  lVar7 = (longdouble)fsin((longdouble)(param_1[2] * 0.017453292));
  fVar5 = (float)lVar7;
  lVar7 = (longdouble)fcos((longdouble)(param_1[2] * 0.017453292));
  fVar6 = (float)lVar7;
  if (param_2 != (float *)0x0) {
    *param_2 = fVar4 * fVar2;
    param_2[1] = fVar6 * -fVar1 + fVar5 * fVar3 * fVar2;
    param_2[2] = fVar6 * fVar3 * fVar2 + -fVar5 * -fVar1;
  }
  if (param_3 != (float *)0x0) {
    *param_3 = fVar4 * fVar1;
    param_3[1] = fVar6 * fVar2 + fVar5 * fVar3 * fVar1;
    param_3[2] = fVar6 * fVar3 * fVar1 + -fVar5 * fVar2;
  }
  if (param_4 != (float *)0x0) {
    *param_4 = -fVar3;
    param_4[1] = fVar5 * fVar4;
    param_4[2] = fVar6 * fVar4;
  }
  return;
}


// AnimationAutomove  @ 000606b8
void AnimationAutomove(void)

{
  return;
}


// BoxOnPlaneSide  @ 000613f0
byte BoxOnPlaneSide(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  byte bVar4;
  
  switch(*(undefined1 *)((int)param_3 + 0x11)) {
  case 0:
    fVar1 = param_3[1];
    fVar3 = fVar1 * param_2[1] + *param_3 * *param_2;
    fVar2 = *param_3 * *param_1;
    break;
  case 1:
    fVar1 = param_3[1];
    fVar3 = fVar1 * param_2[1] + *param_3 * *param_1;
    fVar2 = *param_3 * *param_2;
    break;
  case 2:
    fVar1 = param_3[1];
    fVar3 = fVar1 * param_1[1] + *param_3 * *param_2;
    fVar2 = *param_3 * *param_1;
    goto LAB_000614a8;
  case 3:
    fVar1 = param_3[1];
    fVar3 = fVar1 * param_1[1] + *param_3 * *param_1;
    fVar2 = *param_3 * *param_2;
LAB_000614a8:
    fVar1 = fVar1 * param_2[1];
    goto LAB_000614ad;
  case 4:
    fVar1 = param_3[1];
    fVar3 = fVar1 * param_2[1] + *param_3 * *param_2;
    fVar2 = *param_3 * *param_1;
    goto LAB_000614f0;
  case 5:
    fVar1 = param_3[1];
    fVar3 = fVar1 * param_2[1] + *param_3 * *param_1;
    fVar2 = *param_3 * *param_2;
LAB_000614f0:
    fVar1 = fVar1 * param_1[1];
LAB_00061529:
    fVar3 = param_3[2] * param_1[2] + fVar3;
    fVar1 = param_3[2] * param_2[2] + fVar1 + fVar2;
    goto LAB_00061553;
  case 6:
    fVar1 = param_3[1];
    fVar3 = fVar1 * param_1[1] + *param_3 * *param_2;
    fVar2 = *param_3 * *param_1;
    goto LAB_00061524;
  case 7:
    fVar1 = param_3[1];
    fVar3 = fVar1 * param_1[1] + *param_3 * *param_1;
    fVar2 = *param_3 * *param_2;
LAB_00061524:
    fVar1 = fVar1 * param_2[1];
    goto LAB_00061529;
  default:
    fVar1 = 0.0;
    BOPS_Error();
    fVar3 = fVar1;
    goto LAB_00061553;
  }
  fVar1 = fVar1 * param_1[1];
LAB_000614ad:
  fVar3 = param_3[2] * param_2[2] + fVar3;
  fVar1 = param_3[2] * param_1[2] + fVar1 + fVar2;
LAB_00061553:
  fVar2 = param_3[3];
  bVar4 = (byte)((fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1) < 0x40;
  if (0x3f < (byte)((fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1)) {
    bVar4 = bVar4 | 2;
  }
  return bVar4;
}


// CVarGetFloat  @ 00071fe4
void CVarGetFloat(undefined4 param_1)

{
  Cvar_VariableValue(param_1);
  return;
}


// CVarGetPointer  @ 00072024
void CVarGetPointer(undefined4 param_1)

{
  Cvar_FindVar(param_1);
  return;
}


// CVarGetString  @ 00072004
void CVarGetString(undefined4 param_1)

{
  Cvar_VariableString(param_1);
  return;
}


// CVarRegister  @ 00072094
void CVarRegister(int param_1)

{
  if (param_1 != 0) {
    *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) | 8;
    Cvar_RegisterVariable(param_1);
  }
  return;
}


// CVarSetFloat  @ 00072044
void CVarSetFloat(undefined4 param_1,undefined4 param_2)

{
  Cvar_SetValue(param_1,param_2);
  return;
}


// CVarSetString  @ 00072070
void CVarSetString(undefined4 param_1,undefined4 param_2)

{
  Cvar_Set(param_1,param_2);
  return;
}


// CacheSystemCompare  @ 0008e2dc
void CacheSystemCompare(int *param_1,int *param_2)

{
  strcasecmp((char *)(*param_1 + 8),(char *)(*param_2 + 8));
  return;
}


// CalcSurfaceExtents  @ 000642dc
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void CalcSurfaceExtents(int param_1)

{
  float *pfVar1;
  int iVar2;
  ushort uVar3;
  float *pfVar4;
  int iVar5;
  float fVar6;
  short sVar7;
  int iVar8;
  ushort in_FPUControlWord;
  int *local_70;
  int *local_5c;
  int local_38;
  int local_34 [2];
  int local_2c [2];
  float local_24 [4];
  int local_14;
  ushort local_c;
  undefined2 uStack_a;
  ushort local_8;
  
  local_38 = 0;
  local_24[2] = 999999.0;
  local_24[0] = -99999.0;
  pfVar4 = *(float **)(param_1 + 0x34);
  local_24[1] = local_24[0];
  local_24[3] = local_24[2];
  if (0 < *(int *)(param_1 + 0x18)) {
    do {
      iVar8 = *(int *)(*(int *)(loadmodel + 0xbc) + (local_38 + *(int *)(param_1 + 0x14)) * 4);
      if (iVar8 < 0) {
        uVar3 = *(ushort *)(*(int *)(loadmodel + 0x9c) + 2 + iVar8 * -8);
      }
      else {
        uVar3 = *(ushort *)(*(int *)(loadmodel + 0x9c) + iVar8 * 8);
      }
      pfVar1 = (float *)(*(int *)(loadmodel + 0x94) + (uint)uVar3 * 0xc);
      fVar6 = pfVar1[2] * pfVar4[2] + *pfVar1 * *pfVar4 + pfVar1[1] * pfVar4[1] + pfVar4[3];
      if (fVar6 < local_24[2]) {
        local_24[2] = fVar6;
      }
      if (0x3f < (byte)((fVar6 < local_24[0] |
                         (byte)((ushort)((ushort)(NAN(fVar6) || NAN(local_24[0])) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar6 == local_24[0]) << 0xe) >> 8)) - 1)) {
        local_24[0] = fVar6;
      }
      fVar6 = pfVar1[2] * pfVar4[6] + *pfVar1 * pfVar4[4] + pfVar1[1] * pfVar4[5] + pfVar4[7];
      if (fVar6 < local_24[3]) {
        local_24[3] = fVar6;
      }
      if (0x3f < (byte)((fVar6 < local_24[1] |
                         (byte)((ushort)((ushort)(NAN(fVar6) || NAN(local_24[1])) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar6 == local_24[1]) << 0xe) >> 8)) - 1)) {
        local_24[1] = fVar6;
      }
      local_38 = local_38 + 1;
    } while (local_38 < *(int *)(param_1 + 0x18));
  }
  local_38 = 0;
  local_70 = local_2c;
  local_5c = local_34;
  iVar8 = 0;
  do {
    *local_70 = (int)ROUND(ROUND(*(float *)((int)local_24 + iVar8 * 2 + 8) * 0.0625));
    local_8 = in_FPUControlWord & 0xf3ff | 0x800;
    _local_c = CONCAT22(uStack_a,in_FPUControlWord);
    iVar2 = (int)ROUND(ROUND(*(float *)((int)local_24 + iVar8 * 2) * 0.0625));
    local_14 = iVar2;
    *local_5c = iVar2;
    iVar5 = *local_70;
    *(short *)(param_1 + 0x2c + iVar8) = (short)iVar5 << 4;
    sVar7 = ((short)iVar2 - (short)iVar5) * 0x10;
    *(short *)(param_1 + 0x30 + iVar8) = sVar7;
    if ((((uint)pfVar4[10] & 1) == 0) && (0x100 < sVar7)) {
      Sys_Error("Bad surface extents %d/%d",(int)*(short *)(param_1 + 0x30),
                (int)*(short *)(param_1 + 0x32));
    }
    local_70 = local_70 + 1;
    local_5c = local_5c + 1;
    iVar8 = iVar8 + 2;
    local_38 = local_38 + 1;
  } while (local_38 < 2);
  return;
}


// CheckGore  @ 00057298
void CheckGore(void)

{
  undefined1 local_104 [256];
  
  Q_memset(local_104,0,0x80);
  Cvar_SetValue("violence_hblood",0x3f800000);
  Cvar_SetValue("violence_hgibs",0x3f800000);
  Cvar_SetValue("violence_ablood",0x3f800000);
  Cvar_SetValue("violence_agibs",0x3f800000);
  return;
}


// CleanupName  @ 00089514
void CleanupName(char *param_1,int param_2)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  do {
    iVar4 = iVar3;
    if (*param_1 == '\0') break;
    *(undefined1 *)(iVar3 + param_2) = *(undefined1 *)(__ctype_toupper + *param_1 * 4);
    iVar4 = iVar3 + 1;
    if (param_1[1] == '\0') break;
    *(undefined1 *)(iVar3 + 1 + param_2) = *(undefined1 *)(__ctype_toupper + param_1[1] * 4);
    iVar4 = iVar3 + 2;
    if (param_1[2] == '\0') break;
    *(undefined1 *)(iVar3 + 2 + param_2) = *(undefined1 *)(__ctype_toupper + param_1[2] * 4);
    iVar4 = iVar3 + 3;
    if (param_1[3] == '\0') break;
    *(undefined1 *)(iVar3 + 3 + param_2) = *(undefined1 *)(__ctype_toupper + param_1[3] * 4);
    iVar4 = iVar3 + 4;
    if (param_1[4] == '\0') break;
    *(undefined1 *)(iVar3 + 4 + param_2) = *(undefined1 *)(__ctype_toupper + param_1[4] * 4);
    iVar4 = iVar3 + 5;
    if (param_1[5] == '\0') break;
    *(undefined1 *)(iVar3 + 5 + param_2) = *(undefined1 *)(__ctype_toupper + param_1[5] * 4);
    iVar4 = iVar3 + 6;
    if (param_1[6] == '\0') break;
    *(undefined1 *)(iVar3 + 6 + param_2) = *(undefined1 *)(__ctype_toupper + param_1[6] * 4);
    iVar4 = iVar3 + 7;
    if (param_1[7] == '\0') break;
    pcVar1 = param_1 + 7;
    param_1 = param_1 + 8;
    *(undefined1 *)(iVar3 + 7 + param_2) = *(undefined1 *)(__ctype_toupper + *pcVar1 * 4);
    iVar3 = iVar3 + 8;
    iVar4 = iVar3;
  } while (iVar3 < 0x10);
  if (0xf < iVar4) {
    return;
  }
  uVar2 = 0x10U - iVar4 & 3;
  if (iVar4 < 0x10) {
    if (uVar2 == 0) goto LAB_00089648;
    if (1 < uVar2) {
      if (2 < uVar2) {
        *(undefined1 *)(iVar4 + param_2) = 0;
        iVar4 = iVar4 + 1;
      }
      *(undefined1 *)(iVar4 + param_2) = 0;
      iVar4 = iVar4 + 1;
    }
  }
  *(undefined1 *)(iVar4 + param_2) = 0;
  iVar4 = iVar4 + 1;
  if (0xf < iVar4) {
    return;
  }
LAB_00089648:
  do {
    *(undefined1 *)(iVar4 + param_2) = 0;
    *(undefined1 *)(param_2 + 1 + iVar4) = 0;
    *(undefined1 *)(param_2 + 2 + iVar4) = 0;
    *(undefined1 *)(param_2 + 3 + iVar4) = 0;
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x10);
  return;
}


// ClearLink  @ 0008adf4
void ClearLink(int param_1)

{
  *(int *)(param_1 + 4) = param_1;
  *(int *)param_1 = param_1;
  return;
}


// ClientPrintf  @ 0006c33c
void ClientPrintf(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_001ab4e8 < iVar1)) {
    Con_Printf("tried to sprint to a non-client\n");
  }
  else {
    iVar1 = DAT_001ab4e4 + -0x5054 + iVar1 * 0x5054;
    if (param_2 == 1) {
      MSG_WriteChar(iVar1 + 0x74,0x1a);
    }
    else {
      if ((param_2 != 0) && (param_2 != 2)) {
        Con_Printf("invalid PRINT_TYPE %i\n",param_2);
        return;
      }
      MSG_WriteByte(iVar1 + 0x74,8);
    }
    MSG_WriteString(iVar1 + 0x74,param_3);
  }
  return;
}


// ClipVelocity  @ 0008010c
/* WARNING: Removing unreachable block (ram,0x00080262) */
/* WARNING: Removing unreachable block (ram,0x000801e9) */

byte ClipVelocity(float *param_1,float *param_2,float *param_3,float param_4)

{
  float *pfVar1;
  float fVar2;
  byte bVar3;
  
  fVar2 = param_2[2];
  bVar3 = 0.0 < fVar2;
  if ((byte)((byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8)) == 0x40) {
    bVar3 = bVar3 | 2;
  }
  pfVar1 = param_3 + 2;
  param_4 = (param_1[1] * param_2[1] + *param_1 * *param_2 + param_1[2] * fVar2) * param_4;
  if ((int)param_3 < (int)param_3 + 9) {
    fVar2 = *param_1 - *param_2 * param_4;
    *param_3 = fVar2;
    if ((0x3f < (byte)((fVar2 < -0.1 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar2 == -0.1) << 0xe) >> 8)) - 1)) && (fVar2 < 0.1)
       ) {
      *param_3 = 0.0;
    }
    fVar2 = param_1[1] - param_2[1] * param_4;
    param_3[1] = fVar2;
    if ((0x3f < (byte)((fVar2 < -0.1 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar2 == -0.1) << 0xe) >> 8)) - 1)) && (fVar2 < 0.1)
       ) {
      param_3[1] = 0.0;
    }
    param_3 = param_3 + 2;
    param_1 = param_1 + 2;
    param_2 = param_2 + 2;
  }
  fVar2 = *param_1 - *param_2 * param_4;
  *param_3 = fVar2;
  if ((0x3f < (byte)((fVar2 < -0.1 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar2 == -0.1) << 0xe) >> 8)) - 1)) && (fVar2 < 0.1))
  {
    *param_3 = 0.0;
  }
  param_1 = param_1 + 1;
  param_2 = param_2 + 1;
  for (param_3 = param_3 + 1; (int)param_3 <= (int)pfVar1; param_3 = param_3 + 4) {
    fVar2 = *param_1 - *param_2 * param_4;
    *param_3 = fVar2;
    if ((0x3f < (byte)((fVar2 < -0.1 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar2 == -0.1) << 0xe) >> 8)) - 1)) && (fVar2 < 0.1)
       ) {
      *param_3 = 0.0;
    }
    fVar2 = param_1[1] - param_2[1] * param_4;
    param_3[1] = fVar2;
    if ((0x3f < (byte)((fVar2 < -0.1 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar2 == -0.1) << 0xe) >> 8)) - 1)) && (fVar2 < 0.1)
       ) {
      param_3[1] = 0.0;
    }
    fVar2 = param_1[2] - param_2[2] * param_4;
    param_3[2] = fVar2;
    if ((0x3f < (byte)((fVar2 < -0.1 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar2 == -0.1) << 0xe) >> 8)) - 1)) && (fVar2 < 0.1)
       ) {
      param_3[2] = 0.0;
    }
    fVar2 = param_1[3] - param_2[3] * param_4;
    param_3[3] = fVar2;
    if ((0x3f < (byte)((fVar2 < -0.1 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar2 == -0.1) << 0xe) >> 8)) - 1)) && (fVar2 < 0.1)
       ) {
      param_3[3] = 0.0;
    }
    param_1 = param_1 + 4;
    param_2 = param_2 + 4;
  }
  return bVar3;
}


// CommatizeNumber  @ 0008e5e8
undefined4 CommatizeNumber(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  undefined1 local_6c [52];
  char local_38 [52];
  
  Q_memset(local_38,0,0x32);
  if (param_1 != 0) {
    do {
      iVar2 = param_1 / 1000;
      Q_strcpy(local_6c,local_38);
      sprintf(local_38,",%03i%s",param_1 % 1000,local_6c);
      param_1 = iVar2;
    } while (iVar2 != 0);
  }
  uVar3 = Q_strlen(local_38);
  uVar4 = 0;
  uVar5 = uVar4;
  if (0 < (int)uVar3) {
    uVar7 = uVar3 & 3;
    if (uVar7 == 0) goto LAB_0008e6b8;
    if (uVar7 < 2) goto LAB_0008e6e2;
    if (2 < uVar7) {
      if ((local_38[0] != '0') && (local_38[0] != ',')) goto LAB_0008e6f4;
      uVar4 = 1;
    }
    for (; (cVar1 = local_38[uVar4], cVar1 == '0' || (uVar5 = uVar4, cVar1 == ','));
        uVar4 = uVar4 + 2) {
      uVar4 = uVar4 + 1;
LAB_0008e6e2:
      cVar1 = local_38[uVar4];
      if (((cVar1 != '0') && (uVar5 = uVar4, cVar1 != ',')) ||
         (uVar4 = uVar4 + 1, uVar5 = uVar4, (int)uVar3 <= (int)uVar4)) break;
LAB_0008e6b8:
      cVar1 = local_38[uVar4];
      if ((cVar1 != '0') && (uVar5 = uVar4, cVar1 != ',')) break;
      uVar5 = uVar4 + 1;
      cVar1 = local_38[uVar5];
      if ((cVar1 != '0') && (cVar1 != ',')) break;
    }
  }
LAB_0008e6f4:
  if (uVar5 == uVar3) {
    pcVar6 = "0";
  }
  else {
    pcVar6 = local_38 + uVar5;
  }
  Q_strcpy(param_2,pcVar6);
  return param_2;
}


// ComparePath1  @ 0008e5a8
undefined4 ComparePath1(char *param_1,char *param_2)

{
  char cVar1;
  
  cVar1 = *param_1;
  if ((cVar1 != '/') && (cVar1 != '\\')) {
    while (cVar1 != '\0') {
      if (cVar1 != *param_2) {
        return 0;
      }
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      cVar1 = *param_1;
      if (cVar1 == '/') {
        return 1;
      }
      if (cVar1 == '\\') {
        return 1;
      }
    }
  }
  return 1;
}


// CopyString  @ 00047af8
undefined4 CopyString(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Q_strlen(param_1);
  uVar2 = Z_Malloc(iVar1 + 1);
  Q_strcpy(uVar2,param_1);
  return uVar2;
}


// CreateEntityList  @ 0005b06c
int CreateEntityList(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  int local_1c;
  int local_14;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  iVar6 = param_1[8];
  if (0 < iVar6) {
    local_1c = 0;
    do {
      local_14 = 0;
      iVar6 = param_1[10];
      iVar5 = *(int *)(iVar6 + 0x14 + local_1c);
      if (((iVar5 != 0) && (*(int *)(iVar6 + 0xc + local_1c) != 0)) &&
         (iVar1 = *(int *)(iVar6 + local_1c), 0 < iVar1)) {
        uVar2 = *(uint *)(iVar6 + 0x10 + local_1c);
        bVar7 = (param_2 & uVar2) != 0;
        if (iVar1 < DAT_001ab4e8 + 1) {
          local_14 = *(int *)(iVar1 * 0x5054 + DAT_001ab4e4 + -0x570);
          if (bVar7) {
            if (-1 < (int)uVar2) {
              Sys_Error("ENTITY IS NOT A PLAYER: %d\n",local_8);
              iVar6 = param_1[10];
            }
            if ((*(int *)(*(int *)(iVar6 + local_1c) * 0x5054 + DAT_001ab4e4 + -0x5054) == 0) ||
               (local_14 == 0)) {
              local_14 = 0;
            }
            else {
              EntityInit(local_14,*(undefined4 *)(iVar6 + 0x14 + local_1c));
              iVar6 = param_1[10];
            }
          }
        }
        else if (bVar7) {
          local_14 = CreateNamedEntity(iVar5);
          iVar6 = param_1[10];
        }
      }
      *(int *)(iVar6 + 4 + local_1c) = local_14;
      local_1c = local_1c + 0x18;
      local_8 = local_8 + 1;
      iVar6 = param_1[8];
    } while (local_8 < iVar6);
  }
  local_8 = 0;
  if (0 < iVar6) {
    iVar6 = 0;
    do {
      iVar5 = param_1[10];
      iVar1 = *(int *)(iVar5 + 4 + iVar6);
      param_1[7] = local_8;
      iVar3 = *(int *)(iVar5 + 8 + iVar6);
      param_1[2] = iVar3;
      param_1[1] = iVar3 + *param_1;
      if ((iVar1 != 0) && (uVar2 = *(uint *)(iVar5 + 0x10 + iVar6), (param_2 & uVar2) != 0)) {
        if ((uVar2 & 0x10000000) == 0) {
          uVar4 = NUM_FOR_EDICT(iVar1);
          Con_DPrintf("Transferring %s (%d)\n",*(int *)(param_1[10] + 0x14 + iVar6) + pr_strings,
                      uVar4);
          iVar5 = (*DAT_00386240)(iVar1,param_1,0);
          if (iVar5 < 0) {
            ED_Free(iVar1);
          }
          else {
            SV_LinkEdict(iVar1,0);
            if (-1 < *(int *)(param_1[10] + 0x10 + iVar6)) {
              iVar5 = EntityInSolid(iVar1);
              if (iVar5 != 0) {
                Con_DPrintf("Suppressing %s\n",*(int *)(param_1[10] + 0x14 + iVar6) + pr_strings);
                ED_Free(iVar1);
                goto LAB_0005b33d;
              }
            }
            local_c = local_c + 1;
            *(undefined4 *)(param_1[10] + 0x10 + iVar6) = 0x40000000;
          }
        }
        else {
          Con_DPrintf("Merging changes for global: %s\n",*(int *)(iVar5 + 0x14 + iVar6) + pr_strings
                     );
          (*DAT_00386240)(iVar1,param_1,1);
          ED_Free(iVar1);
        }
      }
LAB_0005b33d:
      iVar6 = iVar6 + 0x18;
      local_8 = local_8 + 1;
    } while (local_8 < param_1[8]);
  }
  return local_c;
}


// CreateNamedEntity  @ 0006dbf0
int CreateNamedEntity(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  if (param_1 == 0) {
    Sys_Error("Spawned a NULL entity!");
  }
  iVar1 = ED_Alloc();
  *(int *)(iVar1 + 0x80) = param_1;
  pcVar2 = (code *)GetEntityInit(param_1 + pr_strings);
  if (pcVar2 == (code *)0x0) {
    ED_Free(iVar1);
    iVar1 = 0;
    Con_DPrintf("Can\'t create entity: %s\n",param_1 + pr_strings);
  }
  else {
    (*pcVar2)(iVar1 + 0x80);
  }
  return iVar1;
}


// CrossProduct  @ 00061bb8
void CrossProduct(float *param_1,float *param_2,float *param_3)

{
  *param_3 = param_1[1] * param_2[2] - param_1[2] * param_2[1];
  param_3[1] = param_1[2] * *param_2 - *param_1 * param_2[2];
  param_3[2] = *param_1 * param_2[1] - param_1[1] * *param_2;
  return;
}


// DirectoryClear  @ 0005bae0
void DirectoryClear(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  char local_108 [260];
  
  iVar1 = Sys_FindFirst(param_1,0);
  if (iVar1 != 0) {
    do {
      uVar2 = Host_SaveGameDirectory(iVar1);
      sprintf(local_108,"%s%s",uVar2);
      Sys_Unlink(local_108);
      iVar1 = Sys_FindNext(0);
    } while (iVar1 != 0);
  }
  Sys_FindClose();
  return;
}


// DirectoryCopy  @ 0005b768
void DirectoryCopy(undefined4 param_1,FILE *param_2)

{
  void *__ptr;
  undefined4 uVar1;
  FILE *__stream;
  undefined4 local_210;
  char local_20c [260];
  undefined1 local_108 [260];
  
  __ptr = (void *)Sys_FindFirst(param_1,local_108);
  if (__ptr != (void *)0x0) {
    do {
      uVar1 = Host_SaveGameDirectory(__ptr);
      sprintf(local_20c,"%s%s",uVar1);
      COM_FixSlashes(local_20c);
      __stream = fopen(local_20c,"rb");
      local_210 = FileSize(__stream);
      fwrite(__ptr,1,0x104,param_2);
      fwrite(&local_210,4,1,param_2);
      FileCopy(param_2,__stream,local_210);
      fclose(__stream);
      __ptr = (void *)Sys_FindNext(local_108);
    } while (__ptr != (void *)0x0);
  }
  Sys_FindClose();
  return;
}


// DirectoryCount  @ 0005ba98
int DirectoryCount(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = Sys_FindFirst(param_1,0);
  if (iVar1 != 0) {
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      iVar1 = Sys_FindNext(0);
    } while (iVar1 != 0);
  }
  Sys_FindClose();
  return iVar2;
}


// DirectoryExtract  @ 0005b864
void DirectoryExtract(FILE *param_1,uint param_2)

{
  undefined4 uVar1;
  FILE *pFVar2;
  int local_214;
  undefined4 local_210;
  undefined1 local_20c [260];
  char local_108 [260];
  
  local_214 = 0;
  if (0 < (int)param_2) {
    if ((param_2 & 1) == 0) goto LAB_0005b954;
    fread(local_20c,1,0x104,param_1);
    fread(&local_210,4,1,param_1);
    uVar1 = Host_SaveGameDirectory(local_20c);
    sprintf(local_108,"%s%s",uVar1);
    COM_FixSlashes(local_108);
    pFVar2 = fopen(local_108,"wb");
    FileCopy(pFVar2,param_1,local_210);
    fclose(pFVar2);
    for (local_214 = 1; local_214 < (int)param_2; local_214 = local_214 + 2) {
LAB_0005b954:
      fread(local_20c,1,0x104,param_1);
      fread(&local_210,4,1,param_1);
      uVar1 = Host_SaveGameDirectory(local_20c);
      sprintf(local_108,"%s%s",uVar1);
      COM_FixSlashes(local_108);
      pFVar2 = fopen(local_108,"wb");
      FileCopy(pFVar2,param_1,local_210);
      fclose(pFVar2);
      fread(local_20c,1,0x104,param_1);
      fread(&local_210,4,1,param_1);
      uVar1 = Host_SaveGameDirectory(local_20c);
      sprintf(local_108,"%s%s",uVar1);
      COM_FixSlashes(local_108);
      pFVar2 = fopen(local_108,"wb");
      FileCopy(pFVar2,param_1,local_210);
      fclose(pFVar2);
    }
  }
  return;
}


// DispatchDirectUserMsg  @ 00092164
undefined4 DispatchDirectUserMsg(void)

{
  return 0;
}


// EngineFprintf  @ 00093ec4
void EngineFprintf(FILE *param_1,char *param_2)

{
  vsprintf(szOut_138,param_2,&stack0x0000000c);
  fprintf(param_1,"%s",szOut_138);
  return;
}


// EngineTakingFocus  @ 00094224
void EngineTakingFocus(void)

{
  return;
}


// EntOffsetOfPEntity  @ 00071dbc
int EntOffsetOfPEntity(int param_1)

{
  return param_1 - DAT_00186f94;
}


// EntityInSolid  @ 0005afb8
bool EntityInSolid(int param_1)

{
  int iVar1;
  bool bVar2;
  float local_10;
  float local_c;
  float local_8;
  
  if (((*(int *)(param_1 + 0x188) == 0xc) && (*(int *)(param_1 + 0x214) != 0)) &&
     ((*(byte *)(*(int *)(param_1 + 0x214) + 0x224) & 8) != 0)) {
    bVar2 = false;
  }
  else {
    local_10 = (*(float *)(param_1 + 0x144) + *(float *)(param_1 + 0x150)) * 0.5;
    local_c = (*(float *)(param_1 + 0x148) + *(float *)(param_1 + 0x154)) * 0.5;
    local_8 = (*(float *)(param_1 + 0x14c) + *(float *)(param_1 + 0x158)) * 0.5;
    g_groupmask = *(undefined4 *)(param_1 + 0x2c0);
    iVar1 = SV_PointContents(&local_10);
    bVar2 = iVar1 == -2;
  }
  return bVar2;
}


// EntityInit  @ 0005a448
void EntityInit(int param_1,int param_2)

{
  code *pcVar1;
  
  if (param_2 == 0) {
    Sys_Error("Bad class!!\n");
  }
  ReleaseEntityDLLFields(param_1);
  InitEntityDLLFields(param_1);
  *(int *)(param_1 + 0x80) = param_2;
  pcVar1 = (code *)GetEntityInit(param_2 + pr_strings);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(param_1 + 0x80);
  }
  return;
}


// EntityPatchRead  @ 0005aaac
void EntityPatchRead(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  FILE *__stream;
  int iVar2;
  int local_110;
  int local_10c;
  char local_108 [260];
  
  uVar1 = Host_SaveGameDirectory(param_2);
  sprintf(local_108,"%s%s.HL3",uVar1);
  COM_FixSlashes(local_108);
  __stream = fopen(local_108,"rb");
  if (__stream != (FILE *)0x0) {
    fread(&local_10c,4,1,__stream);
    iVar2 = 0;
    if (0 < local_10c) {
      do {
        fread(&local_110,4,1,__stream);
        iVar2 = iVar2 + 1;
        *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x10 + local_110 * 0x18) = 0x40000000;
      } while (iVar2 < local_10c);
    }
    fclose(__stream);
  }
  return;
}


// EntityPatchWrite  @ 0005a980
void EntityPatchWrite(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  FILE *__s;
  int local_110;
  int local_10c;
  char local_108 [260];
  
  uVar1 = Host_SaveGameDirectory(param_2);
  sprintf(local_108,"%s%s.HL3",uVar1);
  COM_FixSlashes(local_108);
  __s = fopen(local_108,"wb");
  if (__s != (FILE *)0x0) {
    local_10c = 0;
    local_110 = 0;
    if (0 < *(int *)(param_1 + 0x20)) {
      do {
        if ((*(byte *)(*(int *)(param_1 + 0x28) + 0x13 + local_110 * 0x18) & 0x40) != 0) {
          local_10c = local_10c + 1;
        }
        local_110 = local_110 + 1;
      } while (local_110 < *(int *)(param_1 + 0x20));
    }
    fwrite(&local_10c,4,1,__s);
    local_110 = 0;
    if (0 < *(int *)(param_1 + 0x20)) {
      do {
        if ((*(byte *)(*(int *)(param_1 + 0x28) + 0x13 + local_110 * 0x18) & 0x40) != 0) {
          fwrite(&local_110,4,1,__s);
        }
        local_110 = local_110 + 1;
      } while (local_110 < *(int *)(param_1 + 0x20));
    }
    fclose(__s);
  }
  return;
}


// EntryInTable  @ 0005aec4
int EntryInTable(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  param_3 = param_3 + 1;
  if (param_3 < *(int *)(param_1 + 0x24)) {
    iVar2 = param_1 + 0x2c + param_3 * 0x50;
    do {
      iVar1 = Q_strcmp(iVar2,param_2);
      if (iVar1 == 0) {
        return param_3;
      }
      iVar2 = iVar2 + 0x50;
      param_3 = param_3 + 1;
    } while (param_3 < *(int *)(param_1 + 0x24));
  }
  return -1;
}


// FileCopy  @ 0005b6f0
void FileCopy(FILE *param_1,FILE *param_2,size_t param_3)

{
  size_t __size;
  undefined1 local_404 [1024];
  
  if (0 < (int)param_3) {
    do {
      __size = param_3;
      if (0x400 < (int)param_3) {
        __size = 0x400;
      }
      fread(local_404,__size,1,param_2);
      fwrite(local_404,__size,1,param_1);
      param_3 = param_3 - __size;
    } while (0 < (int)param_3);
  }
  return;
}


// FileSize  @ 0005b69c
long FileSize(FILE *param_1)

{
  long __off;
  long lVar1;
  
  if (param_1 == (FILE *)0x0) {
    lVar1 = 0;
  }
  else {
    __off = ftell(param_1);
    fseek(param_1,0,2);
    lVar1 = ftell(param_1);
    fseek(param_1,__off,0);
  }
  return lVar1;
}


// FindAddressInTable  @ 00093568
int FindAddressInTable(int param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  uVar1 = *(uint *)(param_1 + 8);
  if (0 < (int)uVar1) {
    piVar2 = *(int **)(param_1 + 4);
    piVar3 = piVar2 + 1;
    uVar4 = uVar1 & 3;
    if (uVar4 != 0) {
      if (1 < uVar4) {
        if (2 < uVar4) {
          if (*piVar2 == param_2) {
            return piVar2[1];
          }
          piVar3 = piVar2 + 3;
          piVar2 = piVar2 + 2;
          iVar5 = 1;
        }
        if (*piVar2 == param_2) goto LAB_000935d0;
        piVar3 = piVar3 + 2;
        piVar2 = piVar2 + 2;
        iVar5 = iVar5 + 1;
      }
      if (*piVar2 == param_2) {
LAB_000935d0:
        return *piVar3;
      }
      piVar3 = piVar3 + 2;
      piVar2 = piVar2 + 2;
      iVar5 = iVar5 + 1;
      if ((int)uVar1 <= iVar5) {
        return 0;
      }
    }
    do {
      if (*piVar2 == param_2) goto LAB_000935d0;
      if (piVar2[2] == param_2) {
        return piVar3[2];
      }
      if (piVar2[4] == param_2) {
        return piVar3[4];
      }
      if (piVar2[6] == param_2) {
        return piVar3[6];
      }
      piVar3 = piVar3 + 8;
      piVar2 = piVar2 + 8;
      iVar5 = iVar5 + 4;
    } while (iVar5 < (int)uVar1);
  }
  return 0;
}


// FindEntityByString  @ 0006df0c
undefined4 FindEntityByString(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = iGetIndex(param_2);
  if ((iVar1 == -1) || (param_3 == 0)) {
    uVar2 = 0;
  }
  else {
    if (param_1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = NUM_FOR_EDICT(param_1,iVar1,param_3);
    }
    uVar2 = PF_find_Shared(uVar2);
  }
  return uVar2;
}


// FindEntityByVars  @ 00071ee8
int FindEntityByVars(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int local_c;
  
  local_c = 0;
  if (0 < (int)DAT_00186f8c) {
    iVar2 = DAT_00186f94 + 0x80;
    uVar1 = DAT_00186f8c & 3;
    iVar3 = DAT_00186f94;
    if (uVar1 == 0) goto LAB_00071f7c;
    if (1 < uVar1) {
      if (2 < uVar1) {
        if (iVar2 == param_1) {
          return DAT_00186f94;
        }
        iVar2 = DAT_00186f94 + 0x3a4;
        iVar3 = DAT_00186f94 + 0x324;
        local_c = 1;
      }
      if (iVar2 == param_1) {
        return iVar3;
      }
      iVar2 = iVar2 + 0x324;
      iVar3 = iVar3 + 0x324;
      local_c = local_c + 1;
    }
    if (iVar2 == param_1) {
      return iVar3;
    }
    iVar2 = iVar2 + 0x324;
    iVar3 = iVar3 + 0x324;
    for (local_c = local_c + 1; local_c < (int)DAT_00186f8c; local_c = local_c + 4) {
LAB_00071f7c:
      if (iVar2 == param_1) {
        return iVar3;
      }
      if (iVar2 + 0x324 == param_1) {
        return iVar3 + 0x324;
      }
      if (iVar2 + 0x648 == param_1) {
        return iVar3 + 0x648;
      }
      if (iVar2 + 0x96c == param_1) {
        return iVar3 + 0x96c;
      }
      iVar2 = iVar2 + 0xc90;
      iVar3 = iVar3 + 0xc90;
    }
  }
  return 0;
}


// FindEntityInSphere  @ 0006d9dc
int * FindEntityInSphere(int param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  int local_10;
  int local_c;
  
  if (param_1 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = NUM_FOR_EDICT(param_1);
  }
  param_3 = param_3 * param_3;
  iVar5 = iVar5 + 1;
  if (iVar5 < DAT_00186f8c) {
    local_c = iVar5 * 0x5054;
    local_10 = iVar5 * 0x324;
    do {
      piVar6 = (int *)(local_10 + (int)DAT_00186f94);
      if ((((*piVar6 == 0) && (piVar6[0x20] != 0)) &&
          ((DAT_001ab4e8 < iVar5 || (*(int *)(local_c + DAT_001ab4e4 + -0x5054) != 0)))) &&
         (0.0 <= param_3)) {
        fVar1 = *param_2;
        fVar2 = (float)piVar6[0x51];
        if ((byte)((fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) - 1) < 0x40) {
          fVar3 = (float)piVar6[0x54];
          fVar2 = 0.0;
          if (0x3f < (byte)((fVar1 < fVar3 |
                             (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar3)) << 10) >> 8) |
                            (byte)((ushort)((ushort)(fVar1 == fVar3) << 0xe) >> 8)) - 1)) {
            fVar2 = fVar1 - fVar3;
          }
        }
        else {
          fVar2 = fVar1 - fVar2;
        }
        fVar1 = fVar2 * fVar2 + 0.0;
        if (fVar1 <= param_3) {
          fVar2 = param_2[1];
          fVar3 = (float)piVar6[0x52];
          if ((byte)((fVar3 < fVar2 |
                      (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
            fVar4 = (float)piVar6[0x55];
            fVar3 = 0.0;
            if (0x3f < (byte)((fVar2 < fVar4 |
                               (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar4)) << 10) >> 8) |
                              (byte)((ushort)((ushort)(fVar2 == fVar4) << 0xe) >> 8)) - 1)) {
              fVar3 = fVar2 - fVar4;
            }
          }
          else {
            fVar3 = fVar2 - fVar3;
          }
          fVar1 = fVar3 * fVar3 + fVar1;
          if (fVar1 <= param_3) {
            fVar2 = param_2[2];
            fVar3 = (float)piVar6[0x53];
            if ((byte)((fVar3 < fVar2 |
                        (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
              fVar4 = (float)piVar6[0x56];
              fVar3 = 0.0;
              if (0x3f < (byte)((fVar2 < fVar4 |
                                 (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar4)) << 10) >> 8) |
                                (byte)((ushort)((ushort)(fVar2 == fVar4) << 0xe) >> 8)) - 1)) {
                fVar3 = fVar2 - fVar4;
              }
            }
            else {
              fVar3 = fVar2 - fVar3;
            }
            fVar1 = fVar3 * fVar3 + fVar1;
            if ((byte)((fVar1 < param_3 |
                        (byte)((ushort)((ushort)(NAN(fVar1) || NAN(param_3)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar1 == param_3) << 0xe) >> 8)) - 1) < 0x40) {
              return piVar6;
            }
          }
        }
      }
      local_c = local_c + 0x5054;
      local_10 = local_10 + 0x324;
      iVar5 = iVar5 + 1;
    } while (iVar5 < DAT_00186f8c);
  }
  return DAT_00186f94;
}


// FindMiptex  @ 00089be8
int FindMiptex(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < nummiptex) {
    iVar3 = 0;
    do {
      iVar1 = Q_strcasecmp(param_1,miptex + iVar3);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar3 = iVar3 + 0x40;
      iVar2 = iVar2 + 1;
    } while (iVar2 < nummiptex);
  }
  if (nummiptex == 0x200) {
    Sys_Error("Exceeded MAX_MAP_TEXTURES");
  }
  Q_strcpy(miptex + iVar2 * 0x40,param_1);
  nummiptex = nummiptex + 1;
  return iVar2;
}


// FindNameInTable  @ 00093614
undefined4 FindNameInTable(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    do {
      iVar1 = Q_strcmp(param_2,*(undefined4 *)(*(int *)(param_1 + 4) + 4 + iVar2 * 8));
      if (iVar1 == 0) {
        return *(undefined4 *)(*(int *)(param_1 + 4) + iVar2 * 8);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 8));
  }
  return 0;
}


// FindPassableSpace  @ 000584f8
undefined4 FindPassableSpace(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  local_8 = 0;
  iVar1 = param_1 + 0x88;
  while( true ) {
    VectorMA(iVar1,param_3,param_2,iVar1);
    iVar2 = SV_TestEntityPosition(param_1);
    if (iVar2 == 0) break;
    VectorMA(iVar1,param_3,param_2,iVar1);
    iVar2 = SV_TestEntityPosition(param_1);
    if (iVar2 == 0) break;
    VectorMA(iVar1,param_3,param_2,iVar1);
    iVar2 = SV_TestEntityPosition(param_1);
    if (iVar2 == 0) break;
    VectorMA(iVar1,param_3,param_2,iVar1);
    iVar2 = SV_TestEntityPosition(param_1);
    if (iVar2 == 0) break;
    local_8 = local_8 + 4;
    if (99 < local_8) {
      return 0;
    }
  }
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x88);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x8c);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x90);
  return 1;
}


// FindViewthing  @ 0005c7b4
int FindViewthing(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  iVar3 = 0;
  if (0 < DAT_00186f8c) {
    local_8 = 0;
    do {
      iVar2 = local_8 + DAT_00186f94;
      iVar1 = Q_strcmp(*(int *)(iVar2 + 0x80) + pr_strings,"viewthing");
      if (iVar1 == 0) {
        return iVar2;
      }
      local_8 = local_8 + 0x324;
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_00186f8c);
  }
  Con_Printf("No viewthing on map\n");
  return 0;
}


// FloatNoSwap  @ 00049cc4
longdouble FloatNoSwap(float param_1)

{
  return (longdouble)param_1;
}


// FloatSwap  @ 00049c7c
longdouble FloatSwap(uint param_1)

{
  return (longdouble)
         (float)(param_1 >> 0x18 | param_1 >> 8 & 0xff00 | (param_1 & 0xff00) << 8 | param_1 << 0x18
                );
}


// FloorDivMod  @ 000620e0
void FloorDivMod(double param_1,double param_2,int *param_3,int *param_4)

{
  double dVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 <= 0.0) {
    Sys_Error("FloorDivMod: bad denominator %d\n",param_2);
  }
  if ((byte)(param_1 < 0.0 | (byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_1 == 0.0) << 0xe) >> 8)) == 1) {
    dVar1 = ROUND(-param_1 / param_2);
    iVar3 = -(int)ROUND(dVar1);
    iVar2 = (int)ROUND(ROUND(-param_1 - dVar1 * param_2));
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar3 = iVar3 + -1;
      iVar2 = (int)ROUND(param_2) - iVar2;
    }
  }
  else {
    iVar3 = (int)ROUND(ROUND(param_1 / param_2));
    iVar2 = (int)ROUND(ROUND(param_1 - ROUND(param_1 / param_2) * param_2));
  }
  *param_3 = iVar3;
  *param_4 = iVar2;
  return;
}


// ForceReloadProfile  @ 0009341c
void ForceReloadProfile(void)

{
  return;
}


// ForwardSlashes  @ 0008969c
void ForwardSlashes(char *param_1)

{
  for (; *param_1 != '\0'; param_1 = param_1 + 1) {
    if (*param_1 == '\\') {
      *param_1 = '/';
    }
  }
  return;
}


// FreeEntPrivateData  @ 00071d60
void FreeEntPrivateData(int param_1)

{
  if (*(int *)(param_1 + 0x7c) != 0) {
    Mem_Free(*(int *)(param_1 + 0x7c));
  }
  *(undefined4 *)(param_1 + 0x7c) = 0;
  return;
}


// FunctionFromName  @ 00093664
int FunctionFromName(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < g_iextdllMac) {
    iVar3 = 0;
    do {
      iVar1 = FindNameInTable((int)&g_rgextdll + iVar3,param_1);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar3 = iVar3 + 0xc;
      iVar2 = iVar2 + 1;
    } while (iVar2 < g_iextdllMac);
  }
  Con_Printf("Can\'t find proc: %s\n",param_1);
  return 0;
}


// GameInit  @ 00092df8
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
GameInit(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
        undefined4 param_5,int param_6)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  char cVar5;
  char *pcVar6;
  undefined4 local_140;
  undefined1 *local_13c;
  char *local_138;
  char *local_134;
  undefined *local_130;
  code *local_12c;
  undefined4 local_128;
  undefined4 local_124;
  char local_120 [260];
  undefined1 *local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  Q_memset(&gmodinfo,0,0x234);
  pcVar6 = &OrigCmd_99;
  Q_strcpy(&OrigCmd_99,param_1);
  host_initialized = 0;
  Console_Printf = param_4[0x15];
  VID_LockBuffer = param_4[2];
  VID_UnlockBuffer = param_4[3];
  VID_Shutdown = param_4[4];
  VID_Update = param_4[5];
  VID_ForceLockState = param_4[6];
  VID_ForceUnlockedAndReturnState = param_4[7];
  VID_SetDefaultMode = param_4[8];
  VID_GetExtModeDescription = param_4[9];
  VID_GetVID = param_4[10];
  D_SurfaceCacheForRes = param_4[0x14];
  D_BeginDirectRect = param_4[0xb];
  D_EndDirectRect = param_4[0xc];
  Launcher_ConsolePrintf = param_4[0x15];
  Launcher_AppActivate = param_4[0xd];
  Launcher_CDAudio_Play = param_4[0xe];
  Launcher_CDAudio_Resume = param_4[0x10];
  Launcher_CDAudio_Pause = param_4[0xf];
  Launcher_CDAudio_Update = param_4[0x11];
  Launcher_ChangeGameDirectory = param_4[0x1b];
  Launcher_ErrorMessage = param_4[0x13];
  Launcher_InitCmds = param_4[0x12];
  Launcher_GetCDKey = param_4[0x16];
  Launcher_AuthFailed = param_4[0x1d];
  Launcher_IsValidCD = param_4[0x1a];
  gHasMMXTechnology = *param_4;
  gProcessorSpeed = param_4[1];
  if (param_6 != 0) {
    Launcher_IsValidCD = 0;
  }
  SeedRandomNumberGenerator();
  pcVar2 = getcwd(cwd_98,0x400);
  if (pcVar2 == (char *)0x0) {
    Sys_Error("Couldn\'t determine current directory");
  }
  iVar3 = Q_strlen(cwd_98);
  if (szReturn_26[iVar3 + 0x3f] == '/') {
    iVar3 = Q_strlen(cwd_98);
    szReturn_26[iVar3 + 0x3f] = 0;
  }
  local_18 = 0;
  local_14 = 1;
  argv = empty_string;
  cVar5 = OrigCmd_99;
  while (((cVar5 != '\0' && (local_14 < 0x32)) && (cVar5 = *pcVar6, cVar5 != '\0'))) {
    do {
      if ((byte)(cVar5 - 0x21U) < 0x5e) break;
      pcVar6 = pcVar6 + 1;
      cVar5 = *pcVar6;
    } while (cVar5 != '\0');
    if (cVar5 == '\0') break;
    (&argv)[local_14] = pcVar6;
    local_14 = local_14 + 1;
    for (; (byte)(*pcVar6 - 0x21U) < 0x5e; pcVar6 = pcVar6 + 1) {
    }
    if (*pcVar6 == '\0') break;
    *pcVar6 = '\0';
    pcVar6 = pcVar6 + 1;
    cVar5 = *pcVar6;
  }
  local_10 = &argv;
  local_1c = cwd_98;
  COM_InitArgv(local_14,&argv);
  local_14 = com_argc;
  local_10 = (undefined4 *)com_argv;
  isDedicated = param_6;
  local_c = param_2;
  local_8 = param_3;
  Sys_Init();
  S_BlockSound();
  Sys_Printf("Host_Init\n");
  iVar3 = Host_Init(&local_1c);
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    if (param_6 != 0) {
      bVar1 = true;
      Q_memset(&local_140,0,0x20);
      iVar3 = Crypt_ReturnAPI(1,&crypt);
      if (iVar3 == 0) {
        Sys_Printf("Host_Init:  Auth API Failure\n");
        return 0;
      }
      sprintf(local_120,"%s","woncomm.lst");
      iVar3 = COM_CheckParm("-comm");
      if ((iVar3 != 0) && (iVar3 < com_argc + -1)) {
        Q_strcpy(local_120,*(undefined4 *)(com_argv + 4 + iVar3 * 4));
      }
      local_140 = 1;
      local_13c = com_gamedir;
      local_138 = "2123437429222";
      local_130 = &DAT_000aeaa0;
      local_12c = Con_Printf;
      local_128 = 0;
      local_124 = 0;
      local_134 = local_120;
      (*_DAT_003861a8)(&local_140);
      iVar3 = COM_CheckParm("+sv_lan");
      if (((iVar3 != 0) && (iVar3 < com_argc + -1)) &&
         (iVar3 = Q_atoi(*(undefined4 *)(com_argv + 4 + iVar3 * 4)), iVar3 != 0)) {
        bVar1 = false;
      }
      if ((bVar1) && (iVar3 = (*_DAT_003861dc)(), iVar3 != 0)) {
        pcVar6 = "WON Auth Server\r\n";
      }
      else {
        pcVar6 = "Auth Server\r\n";
      }
      Con_Printf(pcVar6);
    }
    if (isDedicated != 0) {
      Host_InitializeGameDLL();
      NET_Config(1);
    }
    uVar4 = 1;
  }
  return uVar4;
}


// GameSetBackground  @ 00092dd4
void GameSetBackground(undefined4 param_1)

{
  gfBackground = param_1;
  return;
}


// GameSetState  @ 00092db0
void GameSetState(undefined4 param_1)

{
  giActive = param_1;
  return;
}


// GameSetSubState  @ 00092d80
void GameSetSubState(uint param_1)

{
  if ((param_1 & 2) == 0) {
    if (param_1 == 1) {
      return;
    }
  }
  else {
    param_1 = 1;
  }
  Dispatch_Substate(param_1);
  return;
}


// GetAttachment  @ 00060790
void GetAttachment(int param_1,int param_2,int param_3)

{
  int iVar1;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  pstudiohdr = Mod_Extradata(*(undefined4 *)(&DAT_00183e88 + *(int *)(param_1 + 0x134) * 4));
  local_8 = *(undefined4 *)(param_1 + 0xd8);
  local_10 = -*(float *)(param_1 + 0xd0);
  iVar1 = pstudiohdr + *(int *)(pstudiohdr + 0xd8) + param_2 * 0x58;
  local_c = *(undefined4 *)(param_1 + 0xd4);
  SV_StudioSetupBones(*(undefined4 *)(&DAT_00183e88 + *(int *)(param_1 + 0x134) * 4),
                      *(undefined4 *)(param_1 + 0x1b0),*(undefined4 *)(param_1 + 0x1a8),&local_10,
                      param_1 + 0x88,param_1 + 0x1bc,param_1 + 0x1c0,*(undefined4 *)(iVar1 + 0x24));
  if (param_3 != 0) {
    VectorTransform(iVar1 + 0x28,bonetransform + *(int *)(iVar1 + 0x24) * 0x30,param_3);
  }
  return;
}


// GetBonePosition  @ 000606c0
void GetBonePosition(int param_1,int param_2,undefined4 *param_3)

{
  pstudiohdr = Mod_Extradata(*(undefined4 *)(&DAT_00183e88 + *(int *)(param_1 + 0x134) * 4));
  SV_StudioSetupBones(*(undefined4 *)(&DAT_00183e88 + *(int *)(param_1 + 0x134) * 4),
                      *(undefined4 *)(param_1 + 0x1b0),*(undefined4 *)(param_1 + 0x1a8),
                      param_1 + 0xd0,param_1 + 0x88,param_1 + 0x1bc,param_1 + 0x1c0,param_2);
  if (param_3 != (undefined4 *)0x0) {
    param_2 = param_2 * 0x30;
    *param_3 = *(undefined4 *)(bonetransform + param_2 + 0xc);
    param_3[1] = *(undefined4 *)(bonetransform + param_2 + 0x1c);
    param_3[2] = *(undefined4 *)(bonetransform + param_2 + 0x2c);
  }
  return;
}


// GetDispatch  @ 00093514
int GetDispatch(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < g_iextdllMac) {
    iVar3 = 0;
    do {
      iVar1 = dlsym(*(undefined4 *)((int)&g_rgextdll + iVar3),param_1);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar3 = iVar3 + 0xc;
      iVar2 = iVar2 + 1;
    } while (iVar2 < g_iextdllMac);
  }
  return 0;
}


// GetEngineState  @ 00092d3c
undefined4 GetEngineState(void)

{
  return cls;
}


// GetEntityIllum  @ 0006df68
void GetEntityIllum(int param_1)

{
  if (param_1 != 0) {
    NUM_FOR_EDICT(param_1);
  }
  return;
}


// GetEntityInit  @ 0009372c
void GetEntityInit(undefined4 param_1)

{
  GetDispatch(param_1);
  return;
}


// GetGameInfo  @ 0009324c
undefined4 GetGameInfo(undefined4 *param_1)

{
  char *__format;
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_144;
  uint local_140;
  int local_13c;
  undefined1 local_138 [32];
  uint local_118;
  undefined1 local_114;
  undefined1 local_113;
  undefined1 local_112;
  undefined1 local_111;
  undefined2 local_110;
  char local_10e [258];
  uint local_c;
  uint local_8;
  
  Q_memset(&local_144,0,0x140);
  local_144 = build_number();
  local_140 = (uint)(DAT_001ab4e8 != 1);
  local_13c = DAT_001ab4e8;
  Q_strncpy(local_138,&DAT_001535a8,0x20);
  local_118 = (uint)(sv != 0);
  if ((1 < cls) && (DAT_00382508 == 3)) {
    local_114 = DAT_0038250c;
    local_113 = DAT_0038250d;
    local_112 = DAT_0038250e;
    local_111 = DAT_0038250f;
    local_110 = DAT_0038251a;
  }
  local_c = cls;
  local_8 = (uint)(DAT_0038494c != 0);
  Q_memset(local_10e,0,0x40);
  if (cls == 5) {
    if (DAT_0038494c == 2) {
      __format = "Currently in a game";
    }
    else {
      __format = "Finalizing connection";
    }
  }
  else {
    if (cls == 1) {
      sprintf(local_10e,"Disconnected");
      if (gfExtendedError != 0) {
        strcat(local_10e,": ");
        strcat(local_10e,gszDisconnectReason);
      }
      goto LAB_000933f9;
    }
    if (cls == 4) {
      __format = "Initializing and downloading";
    }
    else if (cls == 3) {
      __format = "Connected to server";
    }
    else if (cls == 2) {
      __format = "Connecting";
    }
    else if (cls == 0) {
      __format = "Running dedicated server";
    }
    else {
      __format = "?";
    }
  }
  sprintf(local_10e,__format);
LAB_000933f9:
  puVar2 = &local_144;
  for (iVar1 = 0x50; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return 1;
}


// GetIOFunction  @ 0009374c
void GetIOFunction(undefined4 param_1)

{
  GetDispatch(param_1);
  return;
}


// GetModelPtr  @ 00072128
void GetModelPtr(int param_1)

{
  Mod_Extradata(*(undefined4 *)(&DAT_00183e88 + *(int *)(param_1 + 0x134) * 4));
  return;
}


// GetPauseState  @ 000934ec
undefined4 GetPauseState(void)

{
  return DAT_00153584;
}


// GetVarsOfEnt  @ 00071ed8
int GetVarsOfEnt(int param_1)

{
  return param_1 + 0x80;
}


// GreatestCommonDivisor  @ 0006224c
int GreatestCommonDivisor(int param_1,int param_2)

{
  int iVar1;
  
  while( true ) {
    while (iVar1 = param_2, param_1 <= iVar1) {
      if (param_1 == 0) {
        return iVar1;
      }
      param_2 = iVar1 % param_1;
    }
    if (iVar1 == 0) break;
    param_2 = param_1 % iVar1;
    param_1 = iVar1;
  }
  return param_1;
}


// IndexOfEdict  @ 00071de8
int IndexOfEdict(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (param_1 - DAT_00186f94) * 0x28c1979 >> 2;
    if ((iVar1 < 0) || (DAT_00186f90 < iVar1)) {
      Sys_Error("Bad entity in IndexOfEdict()");
    }
  }
  return iVar1;
}


// InitEntityDLLFields  @ 00071cf8
void InitEntityDLLFields(int param_1)

{
  *(int *)(param_1 + 0x288) = param_1;
  return;
}


// InsertLinkAfter  @ 0008ae3c
void InsertLinkAfter(int *param_1,int param_2)

{
  param_1[1] = *(int *)(param_2 + 4);
  *param_1 = param_2;
  *(int **)(param_2 + 4) = param_1;
  *(int **)param_1[1] = param_1;
  return;
}


// InsertLinkBefore  @ 0008ae20
void InsertLinkBefore(int *param_1,int *param_2)

{
  int iVar1;
  
  param_1[1] = (int)param_2;
  iVar1 = *param_2;
  *param_1 = iVar1;
  *(int **)(iVar1 + 4) = param_1;
  *(int **)param_1[1] = param_1;
  return;
}


// Invert24To16  @ 00062290
int Invert24To16(int param_1)

{
  int iVar1;
  
  if (param_1 < 0x100) {
    iVar1 = -1;
  }
  else {
    iVar1 = (int)ROUND(1099511627776.0 / (double)param_1 + 0.5);
  }
  return iVar1;
}


// IsComment  @ 00088704
undefined4 IsComment(char *param_1)

{
  int iVar1;
  
  if (((param_1 != (char *)0x0) &&
      (((iVar1 = Q_strlen(param_1), iVar1 < 2 || (*param_1 != '/')) || (param_1[1] != '/')))) &&
     (0 < iVar1)) {
    return 0;
  }
  return 1;
}


// IsEndOfText  @ 0008876c
undefined4 IsEndOfText(char *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == (char *)0x0) || (*param_1 != '}')) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// IsStartOfText  @ 0008874c
undefined4 IsStartOfText(char *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == (char *)0x0) || (*param_1 != '{')) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// IsToken  @ 000889ac
undefined4 IsToken(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = Q_strlen(param_2);
    iVar2 = Q_strnicmp(param_1 + 1,param_2,uVar1);
    if (iVar2 == 0) {
      return 1;
    }
  }
  return 0;
}


// IsWhiteSpace  @ 0008878c
undefined4 IsWhiteSpace(char param_1)

{
  undefined4 uVar1;
  
  if ((((param_1 == ' ') || (param_1 == '\t')) || (param_1 == '\r')) || (param_1 == '\n')) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// LandmarkOrigin  @ 0005af20
void LandmarkOrigin(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    local_8 = param_1 + 0x4c;
    iVar2 = 0;
    do {
      iVar1 = Q_strcmp(local_8,param_3);
      if (iVar1 == 0) {
        *param_2 = *(undefined4 *)(iVar2 + 0x70 + param_1);
        param_2[1] = *(undefined4 *)(iVar2 + 0x74 + param_1);
        param_2[2] = *(undefined4 *)(iVar2 + 0x78 + param_1);
        return;
      }
      local_8 = local_8 + 0x50;
      iVar2 = iVar2 + 0x50;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x24));
  }
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  return;
}


// LauncherTakingFocus  @ 0009422c
void LauncherTakingFocus(void)

{
  return;
}


// Length  @ 00061bf8
longdouble Length(float *param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  fVar2 = 0.0;
  pfVar1 = param_1 + 2;
  if ((int)param_1 < (int)param_1 + 9) {
    fVar2 = *param_1;
    pfVar4 = param_1 + 1;
    param_1 = param_1 + 2;
    fVar2 = *pfVar4 * *pfVar4 + fVar2 * fVar2;
  }
  fVar3 = *param_1 * *param_1;
  for (param_1 = param_1 + 1; (int)param_1 <= (int)pfVar1; param_1 = param_1 + 4) {
    fVar2 = param_1[2] * param_1[2] + param_1[1] * param_1[1] + *param_1 * *param_1 + fVar3 + fVar2;
    fVar3 = param_1[3] * param_1[3];
  }
  return (longdouble)SQRT(fVar3 + fVar2);
}


// LoadAdjacentEntities  @ 0005b360
void LoadAdjacentEntities(undefined4 param_1,undefined4 param_2)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined1 *puVar7;
  int local_61c;
  undefined1 *local_618;
  int local_604;
  uint local_600;
  float local_5f8;
  float local_5f4;
  float local_5f0;
  undefined1 local_5ec [116];
  undefined1 local_578 [36];
  int local_554;
  undefined1 local_54c [80];
  undefined1 auStack_4fc [1272];
  
  local_604 = 0;
  Q_memset(local_578,0,0x574);
  DAT_00152bdc = local_578;
  (*DAT_0038628c)();
  local_600 = 0;
  if (0 < local_554) {
    local_618 = local_54c;
    local_61c = 0x2c;
    do {
      iVar6 = 0;
      if ((int)local_600 < 1) {
LAB_0005b50d:
        iVar6 = LoadSaveData(local_618);
        if (iVar6 != 0) {
          ParseSaveTables(iVar6,local_5ec,0);
          EntityPatchRead(iVar6,local_618);
          fVar1 = (float)DAT_0015358c;
          *(undefined4 *)(iVar6 + 0x52c) = 1;
          *(float *)(iVar6 + 0x550) = fVar1;
          LandmarkOrigin(local_578,&local_5f8,param_2);
          LandmarkOrigin(iVar6,iVar6 + 0x544,param_2);
          *(float *)(iVar6 + 0x544) = local_5f8 - *(float *)(iVar6 + 0x544);
          *(float *)(iVar6 + 0x548) = local_5f4 - *(float *)(iVar6 + 0x548);
          *(float *)(iVar6 + 0x54c) = local_5f0 - *(float *)(iVar6 + 0x54c);
          iVar4 = Q_strcmp(local_618,param_1);
          uVar2 = (uint)(iVar4 == 0) << 0x1f;
          iVar4 = -1;
          while (iVar4 = EntryInTable(iVar6,&DAT_001535a8,iVar4), -1 < iVar4) {
            uVar2 = uVar2 | 1 << ((byte)iVar4 & 0x1f);
          }
          if (uVar2 != 0) {
            local_604 = CreateEntityList(iVar6,uVar2);
          }
          if (local_604 != 0) {
            EntityPatchWrite(iVar6,local_618);
          }
          SaveExit(iVar6);
        }
      }
      else {
        puVar5 = local_578 + local_61c;
        puVar7 = local_54c;
        uVar2 = local_600 & 3;
        if (uVar2 == 0) {
LAB_0005b490:
          do {
            iVar3 = Q_strcmp(puVar5,puVar7);
            iVar4 = iVar6;
            if (iVar3 == 0) break;
            iVar3 = Q_strcmp(puVar5,puVar7 + 0x50);
            iVar4 = iVar6 + 1;
            if (iVar3 == 0) break;
            iVar3 = Q_strcmp(puVar5,puVar7 + 0xa0);
            iVar4 = iVar6 + 2;
            if (iVar3 == 0) break;
            iVar3 = Q_strcmp(puVar5,puVar7 + 0xf0);
            iVar4 = iVar6 + 3;
            if (iVar3 == 0) break;
            puVar7 = puVar7 + 0x140;
            iVar6 = iVar6 + 4;
            iVar4 = iVar6;
          } while (iVar6 < (int)local_600);
        }
        else if (uVar2 < 2) {
LAB_0005b46e:
          iVar3 = Q_strcmp(puVar5,puVar7);
          iVar4 = iVar6;
          if (iVar3 != 0) {
            puVar7 = puVar7 + 0x50;
            iVar6 = iVar6 + 1;
            if ((int)local_600 <= iVar6) goto LAB_0005b50d;
            goto LAB_0005b490;
          }
        }
        else if (uVar2 < 3) {
LAB_0005b452:
          iVar3 = Q_strcmp(puVar5,puVar7);
          iVar4 = iVar6;
          if (iVar3 != 0) {
            puVar7 = puVar7 + 0x50;
            iVar6 = iVar6 + 1;
            goto LAB_0005b46e;
          }
        }
        else {
          iVar3 = Q_strcmp(puVar5,puVar7);
          iVar4 = iVar6;
          if (iVar3 != 0) {
            puVar7 = auStack_4fc;
            iVar6 = 1;
            goto LAB_0005b452;
          }
        }
        if ((int)local_600 <= iVar4) goto LAB_0005b50d;
      }
      local_618 = local_618 + 0x50;
      local_61c = local_61c + 0x50;
      local_600 = local_600 + 1;
    } while ((int)local_600 < local_554);
  }
  DAT_00152bdc = (undefined1 *)0x0;
  return;
}


// LoadEntityDLLs  @ 000938d8
void LoadEntityDLLs(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  code *pcVar4;
  int **ppiVar5;
  int *piStack_4b4;
  int *local_4a0;
  int local_498;
  undefined1 local_494 [4];
  int local_490 [64];
  undefined1 local_390 [64];
  int local_350 [16];
  char local_310 [260];
  int local_20c [65];
  char local_108 [260];
  
  piStack_4b4 = (int *)0x938f5;
  SV_ResetModInfo();
  g_iextdllMac = 0;
  piStack_4b4 = (int *)0x258;
  Q_memset();
  iVar1 = COM_CheckParm();
  if ((iVar1 == 0) || (com_argc + -1 <= iVar1)) {
    piStack_4b4 = (int *)0xaec70;
  }
  else {
    piStack_4b4 = *(int **)(com_argv + 4 + iVar1 * 4);
  }
  Q_strcpy();
  piStack_4b4 = (int *)0xaec70;
  iVar1 = Q_stricmp();
  if (iVar1 != 0) {
    gmodinfo = 1;
  }
  piStack_4b4 = (int *)0xaec76;
  sprintf(local_310,"%s/%s/%s");
  piVar2 = (int *)Sys_FileOpenRead(local_310,local_494);
  if (piVar2 == (int *)0xffffffff) {
    piStack_4b4 = (int *)0xaebe7;
    sprintf(local_108,"%s/%s/*.so");
    piVar2 = (int *)Sys_FindFirst(local_108);
    while (piVar2 != (int *)0x0) {
      piStack_4b4 = piVar2;
      sprintf((char *)local_20c,"%s/%s/%s");
      LoadThisDll(piVar2);
      piVar2 = (int *)Sys_FindNext(0);
    }
    piStack_4b4 = (int *)0x93bea;
    Sys_FindClose();
  }
  else {
    if ((piVar2 == (int *)0x0) || (0x40000 < (int)piVar2)) {
      piStack_4b4 = piVar2;
      Sys_Error();
    }
    piStack_4b4 = (int *)((int)piVar2 + 1);
    piVar3 = (int *)Mem_Malloc();
    if (piVar3 == (int *)0x0) {
      piStack_4b4 = (int *)((int)piVar2 + 1);
      Sys_Error();
    }
    piStack_4b4 = piVar2;
    piStack_4b4 = (int *)Sys_FileRead();
    if (piStack_4b4 != piVar2) {
      Sys_Error();
    }
    *(undefined1 *)((int)piVar2 + (int)piVar3) = 0;
    com_ignorecolons = 1;
    local_4a0 = piVar3;
    while( true ) {
      piStack_4b4 = local_4a0;
      COM_Parse();
      iVar1 = Q_strlen();
      if (iVar1 < 1) break;
      piStack_4b4 = (int *)&com_token;
      Q_strcpy();
      local_4a0 = (int *)COM_Parse();
      Q_strcpy();
      iVar1 = Q_stricmp(local_390,"gamedll_linux");
      piStack_4b4 = local_490;
      if (iVar1 == 0) {
        sprintf((char *)local_20c,"%s/%s/%s");
        iVar1 = Q_strstr(local_20c,&DAT_000aed6d);
        if (iVar1 == 0) {
          piStack_4b4 = local_20c;
          Con_DPrintf();
        }
        else {
          piStack_4b4 = local_490;
          Con_DPrintf();
          LoadThisDll();
        }
      }
      else {
        DLL_SetModKey();
      }
    }
    com_ignorecolons = 0;
    piStack_4b4 = piVar3;
    Mem_Free();
    Sys_FileClose();
  }
  piStack_4b4 = (int *)0xaedbe;
  pcVar4 = (code *)GetDispatch();
  if (pcVar4 == (code *)0x0) {
    piStack_4b4 = (int *)0xaeec1;
    pcVar4 = (code *)GetDispatch();
    if (pcVar4 == (code *)0x0) {
      piStack_4b4 = local_20c;
      Host_Error();
      return;
    }
    local_498 = 0x8c;
    piStack_4b4 = (int *)0x8c;
    iVar1 = (*pcVar4)();
    if (iVar1 != 0) goto LAB_00093d28;
    piStack_4b4 = (int *)0xaedcc;
    Con_Printf();
    Con_Printf();
    Con_Printf();
    ppiVar5 = (int **)&stack0xfffffb3c;
  }
  else {
    local_498 = 0x8c;
    piStack_4b4 = &local_498;
    iVar1 = (*pcVar4)();
    if (iVar1 != 0) {
LAB_00093d28:
      piStack_4b4 = (int *)0x93d33;
      piStack_4b4 = (int *)(*DAT_00386290)();
      Con_DPrintf();
      return;
    }
    piStack_4b4 = (int *)0xaedcc;
    ppiVar5 = &piStack_4b4;
    Con_Printf();
    Con_Printf();
    Con_Printf();
    if (local_498 < 0x8d) {
      piStack_4b4 = local_350;
      Con_Printf();
    }
    else {
      piStack_4b4 = (int *)0xaee40;
      Con_Printf();
    }
    piStack_4b4 = (int *)0xaedcc;
  }
  *(undefined4 *)((int)ppiVar5 + -4) = 0x93d18;
  Con_Printf();
  *(undefined **)((int)ppiVar5 + -4) = &DAT_000aeebf;
  *(undefined4 *)((int)ppiVar5 + -8) = 0x93d24;
  Host_Error();
  return;
}


// LoadGame  @ 00059bf4
undefined4 LoadGame(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = scr_skipupdate;
  scr_skipupdate = 1;
  uVar2 = Host_Load(param_1);
  scr_skipupdate = uVar1;
  return uVar2;
}


// LoadGamestate  @ 0005ab64
undefined4 LoadGamestate(undefined4 param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int local_90;
  int local_88;
  int local_7c;
  undefined1 local_78 [8];
  int local_70;
  float local_60;
  undefined1 local_5c [32];
  undefined1 local_3c [32];
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar2 = (int *)LoadSaveData(param_1);
  if (piVar2 == (int *)0x0) {
    uVar3 = 0;
  }
  else {
    ParseSaveTables(piVar2,local_78,1);
    EntityPatchRead(piVar2,param_1);
    Cvar_SetValue("skill",(float)local_70);
    Q_strcpy(&DAT_001535a8,local_5c);
    Cvar_Set("sv_skyname",local_3c);
    Cvar_SetValue("sv_skycolor_r",(float)local_1c);
    Cvar_SetValue("sv_skycolor_g",(float)local_18);
    Cvar_SetValue("sv_skycolor_b",(float)local_14);
    Cvar_SetValue("sv_skyvec_x",local_10);
    Cvar_SetValue("sv_skyvec_y",local_c);
    Cvar_SetValue("sv_skyvec_z",local_8);
    local_7c = 0;
    iVar4 = piVar2[8];
    if (0 < iVar4) {
      local_88 = 0;
      do {
        iVar5 = DAT_00186f94;
        local_90 = piVar2[10];
        iVar4 = *(int *)(local_90 + 0x14 + local_88);
        if (((iVar4 == 0) || (*(int *)(local_90 + 0xc + local_88) == 0)) ||
           (uVar1 = *(uint *)(local_90 + 0x10 + local_88), (uVar1 & 0x40000000) != 0)) {
          *(undefined4 *)(local_90 + 4 + local_88) = 0;
        }
        else {
          if (*(int *)(local_90 + local_88) == 0) {
            EntityInit(DAT_00186f94,iVar4);
            local_90 = piVar2[10];
          }
          else {
            if (*(int *)(local_90 + local_88) < DAT_001ab4e8 + 1) {
              if (-1 < (int)uVar1) {
                Sys_Error("ENTITY IS NOT A PLAYER: %d\n",local_7c);
                local_90 = piVar2[10];
              }
              iVar5 = *(int *)(*(int *)(local_90 + local_88) * 0x5054 + DAT_001ab4e4 + -0x570);
              if ((param_2 == 0) || (iVar5 == 0)) {
                iVar5 = 0;
                goto LAB_0005adbd;
              }
              EntityInit(iVar5,*(undefined4 *)(local_90 + 0x14 + local_88));
            }
            else {
              iVar5 = CreateNamedEntity(iVar4);
            }
            local_90 = piVar2[10];
          }
LAB_0005adbd:
          *(int *)(local_90 + 4 + local_88) = iVar5;
        }
        local_88 = local_88 + 0x18;
        local_7c = local_7c + 1;
        iVar4 = piVar2[8];
      } while (local_7c < iVar4);
    }
    local_7c = 0;
    if (0 < iVar4) {
      local_90 = 0;
      do {
        iVar4 = *(int *)(piVar2[10] + 4 + local_90);
        piVar2[7] = local_7c;
        iVar5 = *(int *)(piVar2[10] + 8 + local_90);
        piVar2[2] = iVar5;
        piVar2[1] = iVar5 + *piVar2;
        if (iVar4 != 0) {
          iVar5 = (*DAT_00386240)(iVar4,piVar2,0);
          if (iVar5 < 0) {
            *(undefined4 *)(piVar2[10] + 4 + local_90) = 0;
            ED_Free(iVar4);
          }
          else {
            SV_LinkEdict(iVar4,0);
          }
        }
        local_90 = local_90 + 0x18;
        local_7c = local_7c + 1;
      } while (local_7c < piVar2[8]);
    }
    SaveExit(piVar2);
    DAT_0015358c = (double)local_60;
    uVar3 = 1;
  }
  return uVar3;
}


// LoadSaveData  @ 0005a4b0
undefined4 * LoadSaveData(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  FILE *__stream;
  undefined4 *puVar3;
  char *pcVar4;
  char *__ptr;
  int local_11c;
  int local_118;
  int local_114;
  size_t local_110;
  int local_10c;
  char local_108 [260];
  
  uVar2 = Host_SaveGameDirectory(param_1);
  sprintf(local_108,"%s%s.HL1",uVar2);
  COM_FixSlashes(local_108);
  Con_Printf("Loading game from %s...\n",local_108);
  __stream = fopen(local_108,"rb");
  if (__stream == (FILE *)0x0) {
    Con_Printf("ERROR: couldn\'t open.\n");
  }
  else {
    fread(&local_10c,4,1,__stream);
    if ((local_10c == 0x564c4156) && (fread(&local_10c,4,1,__stream), local_10c < 0x72)) {
      fread(&local_110,4,1,__stream);
      fread(&local_114,4,1,__stream);
      fread(&local_118,4,1,__stream);
      fread(&local_11c,4,1,__stream);
      puVar3 = (undefined4 *)Mem_Calloc(local_11c + 0x574 + local_114 * 0x18 + local_110,1);
      puVar3[8] = local_114;
      puVar3[5] = local_118;
      puVar3[4] = local_11c;
      Q_strcpy(puVar3 + 0x155,param_1);
      __ptr = (char *)(puVar3 + 0x15d);
      if (0 < local_11c) {
        fread(__ptr,puVar3[4],1,__stream);
        if (puVar3[6] == 0) {
          uVar2 = Mem_Calloc(local_118,4);
          puVar3[6] = uVar2;
        }
        local_10c = 0;
        if (0 < local_118) {
          do {
            pcVar4 = (char *)0x0;
            if (*__ptr != '\0') {
              pcVar4 = __ptr;
            }
            *(char **)(puVar3[6] + local_10c * 4) = pcVar4;
            do {
              cVar1 = *__ptr;
              __ptr = __ptr + 1;
            } while (cVar1 != '\0');
            local_10c = local_10c + 1;
          } while (local_10c < local_118);
        }
      }
      puVar3[10] = __ptr;
      puVar3[9] = 0;
      *puVar3 = __ptr + puVar3[8] * 0x18;
      puVar3[1] = __ptr + puVar3[8] * 0x18;
      puVar3[2] = 0;
      puVar3[3] = local_110;
      puVar3[0x14b] = 1;
      puVar3[0x154] = 0;
      puVar3[0x151] = 0;
      puVar3[0x152] = 0;
      puVar3[0x153] = 0;
      DAT_00152bdc = puVar3;
      fread((void *)*puVar3,local_110,1,__stream);
      fclose(__stream);
      return puVar3;
    }
  }
  return (undefined4 *)0x0;
}


// LoadThisDll  @ 00093d68
void LoadThisDll(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  iVar2 = dlopen(param_1,2);
  if (iVar2 == 0) {
    uVar3 = dlerror();
    Con_Printf("LoadLibrary failed on %s: %s\n",param_1,uVar3);
  }
  else {
    pcVar4 = (code *)dlsym(iVar2,"GiveFnptrsToDll");
    if (pcVar4 == (code *)0x0) {
      Con_Printf("Couldn\'t get GiveFnptrsToDll in %s\n",param_1);
    }
    else {
      (*pcVar4)(g_engfuncsExportedToDlls,&gGlobalVariables);
      if (g_iextdllMac != 0x32) {
        iVar1 = g_iextdllMac * 3;
        g_iextdllMac = g_iextdllMac + 1;
        Q_memset(&g_rgextdll + iVar1,0,0xc);
        (&g_rgextdll)[iVar1] = iVar2;
        return;
      }
      Con_Printf("Too many DLLs, ignoring remainder\n");
    }
  }
  if (iVar2 != 0) {
    dlclose(iVar2);
  }
  return;
}


// LongNoSwap  @ 00049c70
undefined4 LongNoSwap(undefined4 param_1)

{
  return param_1;
}


// LongSwap  @ 00049c3c
int LongSwap(uint param_1)

{
  return (param_1 >> 0x18) +
         param_1 * 0x1000000 + (param_1 & 0xff00) * 0x100 + (param_1 >> 8 & 0xff00);
}


// MD5Final  @ 000915a0
void MD5Final(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_2 + 0x10) >> 3 & 0x3f;
  puVar2 = (undefined1 *)(param_2 + 0x18 + uVar3);
  iVar1 = -uVar3;
  uVar3 = iVar1 + 0x3f;
  *puVar2 = 0x80;
  puVar2 = puVar2 + 1;
  if (uVar3 < 8) {
    Q_memset(puVar2,0,uVar3);
    MD5Transform(param_2,param_2 + 0x18);
    Q_memset(param_2 + 0x18,0,0x38);
  }
  else {
    Q_memset(puVar2,0,iVar1 + 0x37);
  }
  *(undefined4 *)(param_2 + 0x50) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(param_2 + 0x54) = *(undefined4 *)(param_2 + 0x14);
  MD5Transform(param_2,param_2 + 0x18);
  Q_memcpy(param_1,param_2,0x10);
  Q_memset(param_2,0,4);
  return;
}


// MD5Init  @ 000913b4
void MD5Init(undefined4 *param_1)

{
  *param_1 = 0x67452301;
  param_1[1] = 0xefcdab89;
  param_1[2] = 0x98badcfe;
  param_1[3] = 0x10325476;
  param_1[4] = 0;
  param_1[5] = 0;
  return;
}


// MD5Transform  @ 00091640
void MD5Transform(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  
  uVar18 = param_1[1];
  uVar19 = param_1[2];
  uVar20 = param_1[3];
  iVar1 = *param_2;
  uVar17 = ((uVar19 ^ uVar20) & uVar18 ^ uVar20) + iVar1 + *param_1 + -0x28955b88;
  uVar17 = (uVar17 * 0x80 | uVar17 >> 0x19) + uVar18;
  iVar2 = param_2[1];
  uVar20 = ((uVar18 ^ uVar19) & uVar17 ^ uVar19) + iVar2 + -0x173848aa + uVar20;
  uVar20 = (uVar20 * 0x1000 | uVar20 >> 0x14) + uVar17;
  iVar3 = param_2[2];
  uVar19 = ((uVar17 ^ uVar18) & uVar20 ^ uVar18) + iVar3 + 0x242070db + uVar19;
  uVar19 = (uVar19 * 0x20000 | uVar19 >> 0xf) + uVar20;
  iVar4 = param_2[3];
  uVar18 = ((uVar20 ^ uVar17) & uVar19 ^ uVar17) + iVar4 + -0x3e423112 + uVar18;
  uVar18 = (uVar18 * 0x400000 | uVar18 >> 10) + uVar19;
  iVar5 = param_2[4];
  uVar17 = ((uVar19 ^ uVar20) & uVar18 ^ uVar20) + iVar5 + -0xa83f051 + uVar17;
  uVar17 = (uVar17 * 0x80 | uVar17 >> 0x19) + uVar18;
  iVar6 = param_2[5];
  uVar20 = ((uVar18 ^ uVar19) & uVar17 ^ uVar19) + iVar6 + 0x4787c62a + uVar20;
  uVar20 = (uVar20 * 0x1000 | uVar20 >> 0x14) + uVar17;
  iVar7 = param_2[6];
  uVar19 = ((uVar17 ^ uVar18) & uVar20 ^ uVar18) + iVar7 + -0x57cfb9ed + uVar19;
  uVar19 = (uVar19 * 0x20000 | uVar19 >> 0xf) + uVar20;
  iVar8 = param_2[7];
  uVar18 = ((uVar20 ^ uVar17) & uVar19 ^ uVar17) + iVar8 + -0x2b96aff + uVar18;
  uVar18 = (uVar18 * 0x400000 | uVar18 >> 10) + uVar19;
  iVar9 = param_2[8];
  uVar17 = ((uVar19 ^ uVar20) & uVar18 ^ uVar20) + iVar9 + 0x698098d8 + uVar17;
  uVar17 = (uVar17 * 0x80 | uVar17 >> 0x19) + uVar18;
  iVar10 = param_2[9];
  uVar20 = ((uVar18 ^ uVar19) & uVar17 ^ uVar19) + iVar10 + -0x74bb0851 + uVar20;
  uVar20 = (uVar20 * 0x1000 | uVar20 >> 0x14) + uVar17;
  iVar11 = param_2[10];
  uVar19 = ((uVar17 ^ uVar18) & uVar20 ^ uVar18) + iVar11 + -0xa44f + uVar19;
  uVar19 = (uVar19 * 0x20000 | uVar19 >> 0xf) + uVar20;
  iVar12 = param_2[0xb];
  uVar18 = ((uVar20 ^ uVar17) & uVar19 ^ uVar17) + iVar12 + -0x76a32842 + uVar18;
  uVar18 = (uVar18 * 0x400000 | uVar18 >> 10) + uVar19;
  iVar13 = param_2[0xc];
  uVar17 = ((uVar19 ^ uVar20) & uVar18 ^ uVar20) + iVar13 + 0x6b901122 + uVar17;
  uVar17 = (uVar17 * 0x80 | uVar17 >> 0x19) + uVar18;
  iVar14 = param_2[0xd];
  uVar20 = ((uVar18 ^ uVar19) & uVar17 ^ uVar19) + iVar14 + -0x2678e6d + uVar20;
  uVar20 = (uVar20 * 0x1000 | uVar20 >> 0x14) + uVar17;
  iVar15 = param_2[0xe];
  uVar19 = ((uVar17 ^ uVar18) & uVar20 ^ uVar18) + iVar15 + -0x5986bc72 + uVar19;
  uVar19 = (uVar19 * 0x20000 | uVar19 >> 0xf) + uVar20;
  iVar16 = param_2[0xf];
  uVar18 = ((uVar20 ^ uVar17) & uVar19 ^ uVar17) + iVar16 + 0x49b40821 + uVar18;
  uVar18 = (uVar18 * 0x400000 | uVar18 >> 10) + uVar19;
  uVar17 = ((uVar18 ^ uVar19) & uVar20 ^ uVar19) + iVar2 + -0x9e1da9e + uVar17;
  uVar17 = (uVar17 * 0x20 | uVar17 >> 0x1b) + uVar18;
  uVar20 = ((uVar17 ^ uVar18) & uVar19 ^ uVar18) + iVar7 + -0x3fbf4cc0 + uVar20;
  uVar20 = (uVar20 * 0x200 | uVar20 >> 0x17) + uVar17;
  uVar19 = ((uVar20 ^ uVar17) & uVar18 ^ uVar17) + iVar12 + 0x265e5a51 + uVar19;
  uVar19 = (uVar19 * 0x4000 | uVar19 >> 0x12) + uVar20;
  uVar18 = ((uVar19 ^ uVar20) & uVar17 ^ uVar20) + iVar1 + -0x16493856 + uVar18;
  uVar18 = (uVar18 * 0x100000 | uVar18 >> 0xc) + uVar19;
  uVar17 = ((uVar18 ^ uVar19) & uVar20 ^ uVar19) + iVar6 + -0x29d0efa3 + uVar17;
  uVar17 = (uVar17 * 0x20 | uVar17 >> 0x1b) + uVar18;
  uVar20 = ((uVar17 ^ uVar18) & uVar19 ^ uVar18) + iVar11 + 0x2441453 + uVar20;
  uVar20 = (uVar20 * 0x200 | uVar20 >> 0x17) + uVar17;
  uVar19 = ((uVar20 ^ uVar17) & uVar18 ^ uVar17) + iVar16 + -0x275e197f + uVar19;
  uVar19 = (uVar19 * 0x4000 | uVar19 >> 0x12) + uVar20;
  uVar18 = ((uVar19 ^ uVar20) & uVar17 ^ uVar20) + iVar5 + -0x182c0438 + uVar18;
  uVar18 = (uVar18 * 0x100000 | uVar18 >> 0xc) + uVar19;
  uVar17 = ((uVar18 ^ uVar19) & uVar20 ^ uVar19) + iVar10 + 0x21e1cde6 + uVar17;
  uVar17 = (uVar17 * 0x20 | uVar17 >> 0x1b) + uVar18;
  uVar20 = ((uVar17 ^ uVar18) & uVar19 ^ uVar18) + iVar15 + -0x3cc8f82a + uVar20;
  uVar20 = (uVar20 * 0x200 | uVar20 >> 0x17) + uVar17;
  uVar19 = ((uVar20 ^ uVar17) & uVar18 ^ uVar17) + iVar4 + -0xb2af279 + uVar19;
  uVar19 = (uVar19 * 0x4000 | uVar19 >> 0x12) + uVar20;
  uVar18 = ((uVar19 ^ uVar20) & uVar17 ^ uVar20) + iVar9 + 0x455a14ed + uVar18;
  uVar18 = (uVar18 * 0x100000 | uVar18 >> 0xc) + uVar19;
  uVar17 = ((uVar18 ^ uVar19) & uVar20 ^ uVar19) + iVar14 + -0x561c16fb + uVar17;
  uVar17 = (uVar17 * 0x20 | uVar17 >> 0x1b) + uVar18;
  uVar20 = ((uVar17 ^ uVar18) & uVar19 ^ uVar18) + iVar3 + -0x3105c08 + uVar20;
  uVar20 = (uVar20 * 0x200 | uVar20 >> 0x17) + uVar17;
  uVar19 = ((uVar20 ^ uVar17) & uVar18 ^ uVar17) + iVar8 + 0x676f02d9 + uVar19;
  uVar19 = (uVar19 * 0x4000 | uVar19 >> 0x12) + uVar20;
  uVar18 = ((uVar19 ^ uVar20) & uVar17 ^ uVar20) + iVar13 + -0x72d5b376 + uVar18;
  uVar18 = (uVar18 * 0x100000 | uVar18 >> 0xc) + uVar19;
  uVar17 = (uVar18 ^ uVar19 ^ uVar20) + iVar6 + -0x5c6be + uVar17;
  uVar17 = (uVar17 * 0x10 | uVar17 >> 0x1c) + uVar18;
  uVar20 = (uVar17 ^ uVar18 ^ uVar19) + iVar9 + -0x788e097f + uVar20;
  uVar20 = (uVar20 * 0x800 | uVar20 >> 0x15) + uVar17;
  uVar19 = (uVar20 ^ uVar17 ^ uVar18) + iVar12 + 0x6d9d6122 + uVar19;
  uVar19 = (uVar19 * 0x10000 | uVar19 >> 0x10) + uVar20;
  uVar18 = (uVar19 ^ uVar20 ^ uVar17) + iVar15 + -0x21ac7f4 + uVar18;
  uVar18 = (uVar18 * 0x800000 | uVar18 >> 9) + uVar19;
  uVar17 = (uVar18 ^ uVar19 ^ uVar20) + iVar2 + -0x5b4115bc + uVar17;
  uVar17 = (uVar17 * 0x10 | uVar17 >> 0x1c) + uVar18;
  uVar20 = (uVar17 ^ uVar18 ^ uVar19) + iVar5 + 0x4bdecfa9 + uVar20;
  uVar20 = (uVar20 * 0x800 | uVar20 >> 0x15) + uVar17;
  uVar19 = (uVar20 ^ uVar17 ^ uVar18) + iVar8 + -0x944b4a0 + uVar19;
  uVar19 = (uVar19 * 0x10000 | uVar19 >> 0x10) + uVar20;
  uVar18 = (uVar19 ^ uVar20 ^ uVar17) + iVar11 + -0x41404390 + uVar18;
  uVar18 = (uVar18 * 0x800000 | uVar18 >> 9) + uVar19;
  uVar17 = (uVar18 ^ uVar19 ^ uVar20) + iVar14 + 0x289b7ec6 + uVar17;
  uVar17 = (uVar17 * 0x10 | uVar17 >> 0x1c) + uVar18;
  uVar20 = (uVar17 ^ uVar18 ^ uVar19) + iVar1 + -0x155ed806 + uVar20;
  uVar20 = (uVar20 * 0x800 | uVar20 >> 0x15) + uVar17;
  uVar19 = (uVar20 ^ uVar17 ^ uVar18) + iVar4 + -0x2b10cf7b + uVar19;
  uVar19 = (uVar19 * 0x10000 | uVar19 >> 0x10) + uVar20;
  uVar18 = (uVar19 ^ uVar20 ^ uVar17) + iVar7 + 0x4881d05 + uVar18;
  uVar18 = (uVar18 * 0x800000 | uVar18 >> 9) + uVar19;
  uVar17 = (uVar18 ^ uVar19 ^ uVar20) + iVar10 + -0x262b2fc7 + uVar17;
  uVar17 = (uVar17 * 0x10 | uVar17 >> 0x1c) + uVar18;
  uVar20 = (uVar17 ^ uVar18 ^ uVar19) + iVar13 + -0x1924661b + uVar20;
  uVar20 = (uVar20 * 0x800 | uVar20 >> 0x15) + uVar17;
  uVar19 = (uVar20 ^ uVar17 ^ uVar18) + iVar16 + 0x1fa27cf8 + uVar19;
  uVar19 = (uVar19 * 0x10000 | uVar19 >> 0x10) + uVar20;
  uVar18 = (uVar19 ^ uVar20 ^ uVar17) + iVar3 + -0x3b53a99b + uVar18;
  uVar18 = (uVar18 * 0x800000 | uVar18 >> 9) + uVar19;
  uVar17 = ((~uVar20 | uVar18) ^ uVar19) + iVar1 + -0xbd6ddbc + uVar17;
  uVar17 = (uVar17 * 0x40 | uVar17 >> 0x1a) + uVar18;
  uVar20 = ((~uVar19 | uVar17) ^ uVar18) + iVar8 + 0x432aff97 + uVar20;
  uVar20 = (uVar20 * 0x400 | uVar20 >> 0x16) + uVar17;
  uVar19 = ((~uVar18 | uVar20) ^ uVar17) + iVar15 + -0x546bdc59 + uVar19;
  uVar19 = (uVar19 * 0x8000 | uVar19 >> 0x11) + uVar20;
  uVar18 = ((~uVar17 | uVar19) ^ uVar20) + iVar6 + -0x36c5fc7 + uVar18;
  uVar18 = (uVar18 * 0x200000 | uVar18 >> 0xb) + uVar19;
  uVar17 = ((~uVar20 | uVar18) ^ uVar19) + iVar13 + 0x655b59c3 + uVar17;
  uVar17 = (uVar17 * 0x40 | uVar17 >> 0x1a) + uVar18;
  uVar20 = ((~uVar19 | uVar17) ^ uVar18) + iVar4 + -0x70f3336e + uVar20;
  uVar20 = (uVar20 * 0x400 | uVar20 >> 0x16) + uVar17;
  uVar19 = ((~uVar18 | uVar20) ^ uVar17) + iVar11 + -0x100b83 + uVar19;
  uVar19 = (uVar19 * 0x8000 | uVar19 >> 0x11) + uVar20;
  uVar18 = ((~uVar17 | uVar19) ^ uVar20) + iVar2 + -0x7a7ba22f + uVar18;
  uVar18 = (uVar18 * 0x200000 | uVar18 >> 0xb) + uVar19;
  uVar17 = ((~uVar20 | uVar18) ^ uVar19) + iVar9 + 0x6fa87e4f + uVar17;
  uVar17 = (uVar17 * 0x40 | uVar17 >> 0x1a) + uVar18;
  uVar20 = ((~uVar19 | uVar17) ^ uVar18) + iVar16 + -0x1d31920 + uVar20;
  uVar20 = (uVar20 * 0x400 | uVar20 >> 0x16) + uVar17;
  uVar19 = ((~uVar18 | uVar20) ^ uVar17) + iVar7 + -0x5cfebcec + uVar19;
  uVar19 = (uVar19 * 0x8000 | uVar19 >> 0x11) + uVar20;
  uVar18 = ((~uVar17 | uVar19) ^ uVar20) + iVar14 + 0x4e0811a1 + uVar18;
  uVar18 = (uVar18 * 0x200000 | uVar18 >> 0xb) + uVar19;
  uVar17 = ((~uVar20 | uVar18) ^ uVar19) + iVar5 + -0x8ac817e + uVar17;
  uVar17 = (uVar17 * 0x40 | uVar17 >> 0x1a) + uVar18;
  uVar20 = ((~uVar19 | uVar17) ^ uVar18) + iVar12 + -0x42c50dcb + uVar20;
  uVar21 = (uVar20 * 0x400 | uVar20 >> 0x16) + uVar17;
  uVar19 = ((~uVar18 | uVar21) ^ uVar17) + iVar3 + 0x2ad7d2bb + uVar19;
  uVar20 = (uVar19 * 0x8000 | uVar19 >> 0x11) + uVar21;
  uVar18 = ((~uVar17 | uVar20) ^ uVar21) + iVar10 + -0x14792c6f + uVar18;
  *param_1 = *param_1 + uVar17;
  param_1[1] = param_1[1] + (uVar18 * 0x200000 | uVar18 >> 0xb) + uVar20;
  param_1[2] = param_1[2] + uVar20;
  param_1[3] = param_1[3] + uVar21;
  return;
}


// MD5Update  @ 000913e8
void MD5Update(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  int *piVar4;
  undefined1 *puVar5;
  int *piVar6;
  uint uVar7;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  uint uStack_18;
  
  uStack_18 = 0x913f6;
  uVar1 = *(uint *)(param_1 + 0x10);
  uVar7 = uVar1 + param_3 * 8;
  *(uint *)(param_1 + 0x10) = uVar7;
  if (uVar7 < uVar1) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  uVar7 = uVar1 >> 3 & 0x3f;
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + (param_3 >> 0x1d);
  if (uVar7 != 0) {
    iStack_20 = param_1 + 0x18 + uVar7;
    uVar7 = 0x40 - uVar7;
    if (param_3 < uVar7) {
      uStack_18 = param_3;
      iStack_1c = param_2;
      piVar6 = &iStack_20;
      goto LAB_0009158f;
    }
    iStack_1c = param_2;
    iStack_24 = 0x91454;
    uStack_18 = uVar7;
    Q_memcpy();
    iStack_24 = param_1 + 0x18;
    iStack_28 = param_1;
    MD5Transform();
    param_2 = param_2 + uVar7;
    param_3 = param_3 - uVar7;
  }
  puVar5 = &stack0xffffffec;
  iVar2 = param_1 + 0x18;
  if (0x3f < param_3) {
    uVar7 = 0x3f - param_3 & 0xff;
    if (0x3f < (int)param_3) {
      puVar3 = &stack0xffffffec;
      if (uVar7 == 0) goto LAB_0009150c;
      if (uVar7 < 0xc0) {
        if (uVar7 < 0x80) {
          puVar3 = &stack0xffffffec;
          if (uVar7 < 0x40) goto LAB_0009150c;
          uStack_18 = 0x40;
          iStack_24 = 0x914b4;
          iStack_20 = iVar2;
          iStack_1c = param_2;
          Q_memcpy();
          iStack_28 = param_1;
          iStack_24 = iVar2;
          MD5Transform();
          param_2 = param_2 + 0x40;
          param_3 = param_3 - 0x40;
        }
        uStack_18 = 0x40;
        iStack_24 = 0x914d7;
        iStack_20 = iVar2;
        iStack_1c = param_2;
        Q_memcpy();
        iStack_28 = param_1;
        iStack_24 = iVar2;
        MD5Transform();
        param_2 = param_2 + 0x40;
        param_3 = param_3 - 0x40;
      }
    }
    uStack_18 = 0x40;
    iStack_24 = 0x914f7;
    iStack_20 = iVar2;
    iStack_1c = param_2;
    Q_memcpy();
    piVar4 = &iStack_28;
    iStack_28 = param_1;
    iStack_24 = iVar2;
    MD5Transform();
    param_2 = param_2 + 0x40;
    for (param_3 = param_3 - 0x40; puVar5 = (undefined1 *)((int)piVar4 + 0x14),
        puVar3 = (undefined1 *)((int)piVar4 + 0x14), 0x3f < param_3; param_3 = param_3 - 0x100) {
LAB_0009150c:
      *(undefined4 *)(puVar3 + -4) = 0x40;
      *(int *)(puVar3 + -8) = param_2;
      *(int *)(puVar3 + -0xc) = iVar2;
      *(undefined4 *)(puVar3 + -0x10) = 0x91515;
      Q_memcpy();
      *(int *)(puVar3 + -0x10) = iVar2;
      *(int *)(puVar3 + -0x14) = param_1;
      *(undefined4 *)(puVar3 + -0x18) = 0x9151f;
      MD5Transform();
      *(undefined4 *)(puVar3 + -4) = 0x40;
      *(int *)(puVar3 + -8) = param_2 + 0x40;
      *(int *)(puVar3 + -0xc) = iVar2;
      *(undefined4 *)(puVar3 + -0x10) = 0x9152e;
      Q_memcpy();
      *(int *)(puVar3 + -0x10) = iVar2;
      *(int *)(puVar3 + -0x14) = param_1;
      *(undefined4 *)(puVar3 + -0x18) = 0x91538;
      MD5Transform();
      *(undefined4 *)(puVar3 + -4) = 0x40;
      *(int *)(puVar3 + -8) = param_2 + 0x80;
      *(int *)(puVar3 + -0xc) = iVar2;
      *(undefined4 *)(puVar3 + -0x10) = 0x9154a;
      Q_memcpy();
      *(int *)(puVar3 + -0x10) = iVar2;
      *(int *)(puVar3 + -0x14) = param_1;
      *(undefined4 *)(puVar3 + -0x18) = 0x91554;
      MD5Transform();
      *(undefined4 *)(puVar3 + -4) = 0x40;
      *(int *)(puVar3 + -8) = param_2 + 0xc0;
      *(int *)(puVar3 + -0xc) = iVar2;
      *(undefined4 *)(puVar3 + -0x10) = 0x91566;
      Q_memcpy();
      *(int *)(puVar3 + -0x10) = iVar2;
      piVar4 = (int *)(puVar3 + -0x14);
      *(int *)(puVar3 + -0x14) = param_1;
      *(undefined4 *)(puVar3 + -0x18) = 0x91570;
      MD5Transform();
      param_2 = param_2 + 0x100;
    }
  }
  *(uint *)(puVar5 + -4) = param_3;
  *(int *)(puVar5 + -8) = param_2;
  piVar6 = (int *)(puVar5 + -0xc);
  *(int *)(puVar5 + -0xc) = iVar2;
LAB_0009158f:
  *(undefined4 *)((int)piVar6 + -4) = 0x91594;
  Q_memcpy();
  return;
}


// MaskExceptions  @ 00092ab0
void MaskExceptions(void)

{
  return;
}


// ModelFrameCount  @ 00060880
int ModelFrameCount(int param_1)

{
  int iVar1;
  
  iVar1 = 1;
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x44) == 1) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x184) + 0xc);
    }
    else if (*(int *)(param_1 + 0x44) == 3) {
      iVar1 = R_StudioBodyVariations(param_1);
    }
    if (iVar1 < 1) {
      iVar1 = 1;
    }
  }
  return iVar1;
}


// ModelFrames  @ 0006c238
undefined4 ModelFrames(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 - 1U < 0x1ff) {
    uVar1 = ModelFrameCount(*(undefined4 *)(&DAT_00183e88 + param_1 * 4));
  }
  else {
    Con_DPrintf("Bad sprite index!\n");
    uVar1 = 1;
  }
  return uVar1;
}


// NameForFunction  @ 000936c8
int NameForFunction(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < g_iextdllMac) {
    iVar3 = 0;
    do {
      iVar1 = FindAddressInTable((int)&g_rgextdll + iVar3,param_1);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar3 = iVar3 + 0xc;
      iVar2 = iVar2 + 1;
    } while (iVar2 < g_iextdllMac);
  }
  Con_Printf("Can\'t find address: %08lx\n",param_1);
  return 0;
}


// NetadrToSockadr  @ 0008ee54
void NetadrToSockadr(int *param_1,undefined2 *param_2)

{
  Q_memset(param_2,0,0x10);
  if (*param_1 == 2) {
    *param_2 = 2;
    param_2[1] = *(undefined2 *)((int)param_1 + 0x12);
    *(undefined4 *)(param_2 + 2) = 0xffffffff;
  }
  else if (*param_1 == 3) {
    *param_2 = 2;
    *(int *)(param_2 + 2) = param_1[1];
    param_2[1] = *(undefined2 *)((int)param_1 + 0x12);
  }
  return;
}


// PEntityOfEntIndex  @ 00071e58
int * PEntityOfEntIndex(int param_1)

{
  int *piVar1;
  
  if ((-1 < param_1) && (param_1 < DAT_00186f90)) {
    piVar1 = (int *)EDICT_NUM(param_1);
    if ((*piVar1 == 0) && (piVar1[0x1f] != 0)) {
      return piVar1;
    }
    if ((param_1 < DAT_001ab4e8) && (*piVar1 == 0)) {
      return piVar1;
    }
  }
  return (int *)0x0;
}


// PEntityOfEntOffset  @ 00071d94
int PEntityOfEntOffset(int param_1)

{
  return DAT_00186f94 + param_1;
}


// PVSFindEntities  @ 0006d718
int * PVSFindEntities(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int local_18;
  int *local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = *(float *)(param_1 + 0x88) + *(float *)(param_1 + 500);
  local_c = *(float *)(param_1 + 0x8c) + *(float *)(param_1 + 0x1f8);
  local_8 = *(float *)(param_1 + 0x90) + *(float *)(param_1 + 0x1fc);
  uVar1 = Mod_PointInLeaf(&local_10,DAT_00153668);
  uVar1 = Mod_LeafPVS(uVar1,DAT_00153668);
  PVSMark(DAT_00153668,uVar1);
  iVar5 = 1;
  local_14 = DAT_00186f94;
  if (1 < DAT_00186f8c) {
    local_18 = 0x324;
    do {
      piVar4 = (int *)(local_18 + (int)DAT_00186f94);
      if (*piVar4 == 0) {
        piVar3 = piVar4;
        if ((piVar4[0x62] == 0xc) && ((int *)piVar4[0x85] != (int *)0x0)) {
          piVar3 = (int *)piVar4[0x85];
        }
        iVar2 = PVSNode(*(undefined4 *)(DAT_00153668 + 0xa4),piVar3 + 0x51,piVar3 + 0x54);
        if (iVar2 != 0) {
          piVar4[0x82] = (int)local_14;
          local_14 = piVar4;
        }
      }
      local_18 = local_18 + 0x324;
      iVar5 = iVar5 + 1;
    } while (iVar5 < DAT_00186f8c);
  }
  if (cl._1356824_4_ != 0) {
    r_oldviewleaf = 0;
    R_MarkLeaves();
  }
  return local_14;
}


// PVSMark  @ 0006d680
void PVSMark(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int local_8;
  
  r_visframecount = r_visframecount + 1;
  if (0 < *(int *)(param_1 + 0x88)) {
    local_8 = 0x30;
    uVar2 = 0;
    do {
      if ((*(byte *)(((int)uVar2 >> 3) + param_2) >> (uVar2 & 7) & 1) != 0) {
        iVar1 = local_8 + *(int *)(param_1 + 0x8c);
        do {
          if (*(int *)(iVar1 + 4) == r_visframecount) break;
          *(int *)(iVar1 + 4) = r_visframecount;
          iVar1 = *(int *)(iVar1 + 0x14);
        } while (iVar1 != 0);
      }
      local_8 = local_8 + 0x30;
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < *(int *)(param_1 + 0x88));
  }
  return;
}


// PVSNode  @ 0006d59c
int * PVSNode(int *param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  if (param_1[1] == r_visframecount) {
    if (-1 < *param_1) {
      iVar3 = param_1[6];
      if (*(byte *)(iVar3 + 0x10) < 3) {
        fVar1 = *(float *)(iVar3 + 0xc);
        if (*(float *)(param_2 + (uint)*(byte *)(iVar3 + 0x10) * 4) < fVar1) {
          uVar5 = 3;
          fVar2 = *(float *)(param_3 + (uint)*(byte *)(iVar3 + 0x10) * 4);
          if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
            uVar5 = 2;
          }
        }
        else {
          uVar5 = 1;
        }
      }
      else {
        uVar5 = BoxOnPlaneSide(param_2,param_3,iVar3);
      }
      piVar4 = (int *)0x0;
      if ((uVar5 & 1) != 0) {
        piVar4 = (int *)PVSNode(param_1[7],param_2,param_3);
      }
      if (piVar4 != (int *)0x0) {
        return piVar4;
      }
      if ((uVar5 & 2) == 0) {
        return (int *)0x0;
      }
      piVar4 = (int *)PVSNode(param_1[8],param_2,param_3);
      return piVar4;
    }
    if (*param_1 != -2) {
      return param_1;
    }
  }
  return (int *)0x0;
}


// ParseDirective  @ 000889f8
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ParseDirective(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  float local_24;
  float local_20;
  float local_1c;
  
  if ((param_1 == (char *)0x0) || (*param_1 != '$')) {
    uVar2 = 0;
  }
  else {
    iVar1 = IsToken(param_1,"position");
    if (iVar1 == 0) {
      iVar1 = IsToken(param_1,"effect");
      if (iVar1 == 0) {
        iVar1 = IsToken(param_1,"fxtime");
        if (iVar1 == 0) {
          iVar1 = IsToken(param_1,"color2");
          if (iVar1 == 0) {
            iVar1 = IsToken(param_1,"color");
            if (iVar1 == 0) {
              iVar1 = IsToken(param_1,"fadein");
              if (iVar1 == 0) {
                iVar1 = IsToken(param_1,"fadeout");
                if (iVar1 == 0) {
                  iVar1 = IsToken(param_1,"holdtime");
                  if (iVar1 == 0) {
                    Con_DPrintf("Unknown token: %s\n",param_1);
                  }
                  else {
                    iVar1 = ParseFloats(param_1,&local_24,3);
                    if (iVar1 != 0) {
                      DAT_001fb47c = local_24;
                    }
                  }
                }
                else {
                  iVar1 = ParseFloats(param_1,&local_24,3);
                  if (iVar1 != 0) {
                    DAT_001fb478 = local_24;
                  }
                }
              }
              else {
                iVar1 = ParseFloats(param_1,&local_24,1);
                if (iVar1 != 0) {
                  DAT_001fb474 = local_24;
                }
              }
            }
            else {
              iVar1 = ParseFloats(param_1,&local_24,3);
              if (iVar1 != 0) {
                DAT_001fb464._0_1_ = (undefined1)(int)ROUND(local_24);
                DAT_001fb464._1_1_ = (undefined1)(int)ROUND(local_20);
                DAT_001fb464._2_1_ = (undefined1)(int)ROUND(local_1c);
              }
            }
          }
          else {
            iVar1 = ParseFloats(param_1,&local_24,3);
            if (iVar1 != 0) {
              DAT_001fb468 = (undefined1)(int)ROUND(local_24);
              DAT_001fb469 = (undefined1)(int)ROUND(local_20);
              DAT_001fb46a = (undefined1)(int)ROUND(local_1c);
            }
          }
        }
        else {
          iVar1 = ParseFloats(param_1,&local_24,1);
          if (iVar1 != 0) {
            DAT_001fb480 = local_24;
          }
        }
      }
      else {
        iVar1 = ParseFloats(param_1,&local_24,1);
        if (iVar1 != 0) {
          gMessageParms = (int)ROUND(local_24);
        }
      }
    }
    else {
      iVar1 = ParseFloats(param_1,&local_24,2);
      if (iVar1 != 0) {
        _DAT_001fb46c = local_24;
        _DAT_001fb470 = local_20;
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}


// ParseFloats  @ 00088850
bool ParseFloats(int param_1,float *param_2,int param_3)

{
  undefined4 uVar1;
  longdouble lVar2;
  
  if (param_1 != 0) {
    for (; 0 < param_3; param_3 = param_3 + -1) {
      uVar1 = SkipText(param_1);
      param_1 = SkipSpace(uVar1);
      if (param_1 == 0) break;
      lVar2 = (longdouble)Q_atof(param_1);
      *param_2 = (float)lVar2;
      param_2 = param_2 + 1;
    }
  }
  return param_3 == 0;
}


// ParseSaveTables  @ 0005a750
void ParseSaveTables(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_48;
  undefined1 local_44 [64];
  
  iVar4 = 0;
  if (0 < (int)param_1[8]) {
    iVar3 = 0;
    do {
      (*DAT_0038624c)(param_1,"ETABLE",iVar3 + param_1[10],gEntityTableDescription,5);
      iVar4 = iVar4 + 1;
      *(undefined4 *)(param_1[10] + 4 + iVar3) = 0;
      iVar3 = iVar3 + 0x18;
    } while (iVar4 < (int)param_1[8]);
  }
  *param_1 = param_1[1];
  param_1[2] = 0;
  (*DAT_0038624c)(param_1,"Save Header",param_2,gSaveHeaderDescription,0xd);
  iVar4 = *(int *)(param_2 + 0x10);
  param_1[9] = iVar4;
  iVar3 = 0;
  uVar2 = *(undefined4 *)(param_2 + 0x18);
  param_1[0x14b] = 1;
  param_1[0x154] = uVar2;
  param_1[0x151] = 0;
  param_1[0x152] = 0;
  param_1[0x153] = 0;
  if (0 < iVar4) {
    puVar1 = param_1 + 0xb;
    do {
      (*DAT_0038624c)(param_1,"ADJACENCY",puVar1,gAdjacencyDescription,4);
      puVar1 = puVar1 + 0x14;
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)param_1[9]);
  }
  if (param_3 != 0) {
    iVar4 = 0x3f;
    puVar1 = &DAT_00186f88;
    do {
      *puVar1 = 0;
      puVar1[-1] = 0;
      puVar1[-2] = 0;
      puVar1[-3] = 0;
      puVar1[-4] = 0;
      puVar1[-5] = 0;
      puVar1[-6] = 0;
      puVar1[-7] = 0;
      puVar1[-8] = 0;
      puVar1[-9] = 0;
      puVar1[-10] = 0;
      puVar1[-0xb] = 0;
      puVar1[-0xc] = 0;
      puVar1[-0xd] = 0;
      puVar1[-0xe] = 0;
      puVar1[-0xf] = 0;
      puVar1 = puVar1 + -0x10;
      iVar4 = iVar4 + -0x10;
    } while (-1 < iVar4);
  }
  iVar4 = 0;
  if (0 < *(int *)(param_2 + 0x14)) {
    do {
      (*DAT_0038624c)(param_1,FUN_000a7a48,&local_48,gLightstyleDescription,2);
      if (param_3 != 0) {
        iVar3 = Q_strlen(local_44);
        uVar2 = Hunk_Alloc(iVar3 + 1);
        (&DAT_00186e8c)[local_48] = uVar2;
        Q_strcpy(uVar2,local_44);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_2 + 0x14));
  }
  return;
}


// PrintFrameName  @ 0005c928
void PrintFrameName(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = Mod_Extradata(param_1);
  if (iVar1 != 0) {
    Con_Printf("frame %i: %s\n",param_2,iVar1 + 0x24 + param_2 * 0x20);
  }
  return;
}


// PvAllocEntPrivateData  @ 00071d08
undefined4 PvAllocEntPrivateData(int param_1,int param_2)

{
  undefined4 uVar1;
  
  FreeEntPrivateData(param_1);
  if (param_2 < 1) {
    uVar1 = 0;
  }
  else {
    uVar1 = Mem_Calloc(1,param_2);
    *(undefined4 *)(param_1 + 0x7c) = uVar1;
  }
  return uVar1;
}


// PvEntPrivateData  @ 00071d48
undefined4 PvEntPrivateData(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x7c);
  }
  return uVar1;
}


// QuaternionMatrix  @ 0005ea04
void QuaternionMatrix(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  
  fVar1 = param_1[1];
  fVar2 = param_1[2];
  *param_2 = (1.0 - (fVar1 + fVar1) * fVar1) - (fVar2 + fVar2) * fVar2;
  param_2[4] = (param_1[3] + param_1[3]) * param_1[2] + (*param_1 + *param_1) * param_1[1];
  param_2[8] = (*param_1 + *param_1) * param_1[2] - (param_1[3] + param_1[3]) * param_1[1];
  param_2[1] = (*param_1 + *param_1) * param_1[1] - (param_1[3] + param_1[3]) * param_1[2];
  fVar1 = *param_1;
  fVar2 = param_1[2];
  param_2[5] = (1.0 - (fVar1 + fVar1) * fVar1) - (fVar2 + fVar2) * fVar2;
  param_2[9] = (param_1[3] + param_1[3]) * *param_1 + (param_1[1] + param_1[1]) * param_1[2];
  param_2[2] = (param_1[3] + param_1[3]) * param_1[1] + (*param_1 + *param_1) * param_1[2];
  param_2[6] = (param_1[1] + param_1[1]) * param_1[2] - (param_1[3] + param_1[3]) * *param_1;
  fVar1 = *param_1;
  fVar2 = param_1[1];
  param_2[10] = (1.0 - (fVar1 + fVar1) * fVar1) - (fVar2 + fVar2) * fVar2;
  return;
}


// QuaternionSlerp  @ 0005e50c
/* WARNING: Removing unreachable block (ram,0x0005e63c) */
/* WARNING: Removing unreachable block (ram,0x0005e645) */
/* WARNING: Removing unreachable block (ram,0x0005e554) */
/* WARNING: Removing unreachable block (ram,0x0005e572) */
/* WARNING: Removing unreachable block (ram,0x0005e7ac) */
/* WARNING: Removing unreachable block (ram,0x0005e7cd) */

void QuaternionSlerp(float *param_1,float *param_2,float param_3,float *param_4)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float *pfVar10;
  float *pfVar11;
  longdouble lVar12;
  longdouble lVar13;
  longdouble lVar14;
  longdouble lVar15;
  longdouble lVar16;
  
  lVar12 = (longdouble)param_3;
  fVar3 = 0.0;
  fVar2 = 0.0;
  pfVar10 = param_1;
  pfVar11 = param_2;
  if ((int)param_2 < (int)param_2 + 0xd) goto LAB_0005e5a8;
  fVar2 = 0.0;
  fVar3 = *param_1 - *param_2;
  fVar5 = *param_1 + *param_2;
  fVar3 = fVar3 * fVar3 + 0.0;
  pfVar10 = param_1 + 1;
  for (pfVar11 = param_2 + 1; fVar2 = fVar5 * fVar5 + fVar2, (int)pfVar11 <= (int)(param_2 + 3);
      pfVar11 = pfVar11 + 4) {
LAB_0005e5a8:
    fVar7 = *pfVar10 - *pfVar11;
    fVar4 = *pfVar10 + *pfVar11;
    fVar9 = pfVar10[1] - pfVar11[1];
    fVar8 = pfVar10[1] + pfVar11[1];
    fVar6 = pfVar10[2] - pfVar11[2];
    fVar5 = pfVar10[2] + pfVar11[2];
    fVar2 = fVar5 * fVar5 + fVar8 * fVar8 + fVar4 * fVar4 + fVar2;
    fVar4 = pfVar10[3] - pfVar11[3];
    fVar5 = pfVar10[3] + pfVar11[3];
    fVar3 = fVar4 * fVar4 + fVar6 * fVar6 + fVar9 * fVar9 + fVar7 * fVar7 + fVar3;
    pfVar10 = pfVar10 + 4;
  }
  if (fVar2 < fVar3) {
    pfVar10 = param_2;
    if ((int)param_2 + 0xd <= (int)param_2) {
      *param_2 = -*param_2;
      pfVar10 = param_2 + 1;
      if ((int)(param_2 + 3) < (int)(param_2 + 1)) goto LAB_0005e681;
    }
    do {
      *pfVar10 = -*pfVar10;
      pfVar10[1] = -pfVar10[1];
      pfVar10[2] = -pfVar10[2];
      pfVar10[3] = -pfVar10[3];
      pfVar10 = pfVar10 + 4;
    } while ((int)pfVar10 <= (int)(param_2 + 3));
  }
LAB_0005e681:
  lVar16 = (longdouble)param_1[3] * (longdouble)param_2[3] +
           (longdouble)param_1[2] * (longdouble)param_2[2] +
           (longdouble)param_1[1] * (longdouble)param_2[1] +
           (longdouble)*param_1 * (longdouble)*param_2;
  lVar15 = (longdouble)1;
  cosom = (float)lVar16;
  lVar13 = (longdouble)1e-06;
  if (lVar16 + lVar15 <= lVar13) {
    *param_4 = -param_2[1];
    param_4[1] = *param_2;
    param_4[2] = -param_2[3];
    param_4[3] = param_2[2];
    lVar15 = (longdouble)fsin((lVar15 - lVar12) * (longdouble)1.5707963267948966);
    sclp = (float)lVar15;
    lVar12 = (longdouble)fsin(lVar12 * (longdouble)1.5707963267948966);
    sclq = (float)lVar12;
    pfVar10 = param_4 + 2;
    if ((int)param_4 < (int)param_4 + 9) {
      pfVar11 = param_1 + 1;
      *param_4 = sclq * *param_4 + sclp * *param_1;
      param_1 = param_1 + 2;
      param_4[1] = sclq * param_4[1] + sclp * *pfVar11;
      param_4 = param_4 + 2;
    }
    pfVar11 = param_1 + 1;
    *param_4 = sclq * *param_4 + sclp * *param_1;
    for (param_4 = param_4 + 1; (int)param_4 <= (int)pfVar10; param_4 = param_4 + 4) {
      *param_4 = sclq * *param_4 + sclp * *pfVar11;
      param_4[1] = sclq * param_4[1] + sclp * pfVar11[1];
      param_4[2] = sclq * param_4[2] + sclp * pfVar11[2];
      pfVar1 = pfVar11 + 3;
      pfVar11 = pfVar11 + 4;
      param_4[3] = sclq * param_4[3] + sclp * *pfVar1;
    }
  }
  else {
    lVar14 = lVar15 - lVar16;
    if ((byte)((lVar14 < lVar13 | (byte)((ushort)((ushort)(NAN(lVar14) || NAN(lVar13)) << 10) >> 8)
               | (byte)((ushort)((ushort)(lVar14 == lVar13) << 0xe) >> 8)) - 1) < 0x40) {
      lVar15 = lVar15 - lVar12;
      sclq = param_3;
    }
    else {
      lVar13 = (longdouble)fpatan((longdouble)(double)SQRT(lVar15 - lVar16 * lVar16),lVar16);
      omega = (float)lVar13;
      lVar13 = (longdouble)fsin((longdouble)omega);
      sinom = (float)lVar13;
      lVar15 = (longdouble)fsin((lVar15 - lVar12) * (longdouble)omega);
      lVar15 = lVar15 / (longdouble)sinom;
      lVar12 = (longdouble)fsin(lVar12 * (longdouble)omega);
      sclq = (float)(lVar12 / (longdouble)sinom);
    }
    sclp = (float)lVar15;
    pfVar10 = param_4 + 3;
    if ((int)param_4 + 0xd <= (int)param_4) {
      fVar2 = *param_1;
      fVar3 = *param_2;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      *param_4 = sclq * fVar3 + sclp * fVar2;
      param_4 = param_4 + 1;
      if ((int)pfVar10 < (int)param_4) {
        return;
      }
    }
    do {
      *param_4 = sclq * *param_2 + sclp * *param_1;
      param_4[1] = sclq * param_2[1] + sclp * param_1[1];
      param_4[2] = sclq * param_2[2] + sclp * param_1[2];
      pfVar11 = param_1 + 3;
      pfVar1 = param_2 + 3;
      param_1 = param_1 + 4;
      param_2 = param_2 + 4;
      param_4[3] = sclq * *pfVar1 + sclp * *pfVar11;
      param_4 = param_4 + 4;
    } while ((int)param_4 <= (int)pfVar10);
  }
  return;
}


// RadiusFromBounds  @ 000657b0
void RadiusFromBounds(float *param_1,float *param_2)

{
  float local_10;
  float fStack_c;
  float fStack_8;
  
  local_10 = *param_2;
  if (ABS(local_10) < ABS(*param_1)) {
    local_10 = *param_1;
  }
  local_10 = ABS(local_10);
  fStack_c = param_2[1];
  if (ABS(fStack_c) < ABS(param_1[1])) {
    fStack_c = param_1[1];
  }
  fStack_c = ABS(fStack_c);
  fStack_8 = param_2[2];
  if (ABS(fStack_8) < ABS(param_1[2])) {
    fStack_8 = param_1[2];
  }
  fStack_8 = ABS(fStack_8);
  Length(&local_10);
  return;
}


// RandomFloat  @ 00070a44
longdouble RandomFloat(float param_1,float param_2)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)fran1();
  return ((longdouble)param_2 - (longdouble)param_1) * lVar1 + (longdouble)param_1;
}


// RandomLong  @ 00070a6c
int RandomLong(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (param_2 - param_1) + 1;
  if (-1 < param_2 - param_1) {
    do {
      uVar2 = ran1();
    } while (0x7fffffffU - (int)(0x80000000 % (ulonglong)uVar1) < uVar2);
    param_1 = param_1 + uVar2 % uVar1;
  }
  return param_1;
}


// RegUserMsg  @ 0007c644
int RegUserMsg(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if ((((giNextUserMsg < 0x100) && (param_1 != 0)) && (iVar1 = Q_strlen(param_1), iVar1 < 0xc)) &&
     (piVar2 = sv_gpUserMsgs, param_2 < 0xc1)) {
    for (; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[5]) {
      iVar1 = Q_strcmp(param_1,piVar2 + 2);
      if (iVar1 == 0) goto LAB_0007c6ec;
    }
    piVar2 = (int *)Mem_ZeroMalloc(0x1c);
    *piVar2 = giNextUserMsg;
    giNextUserMsg = giNextUserMsg + 1;
    piVar2[1] = param_2;
    Q_strcpy(piVar2 + 2,param_1);
    if (piVar2 != (int *)0x0) {
      piVar2[5] = (int)sv_gpNewUserMsgs;
      sv_gpNewUserMsgs = piVar2;
LAB_0007c6ec:
      return *piVar2;
    }
  }
  return 0;
}


// ReleaseEntityDLLFields  @ 00071cd8
void ReleaseEntityDLLFields(undefined4 param_1)

{
  FreeEntPrivateData(param_1);
  return;
}


// ReleaseEntityDlls  @ 00093e38
void ReleaseEntityDlls(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  puVar3 = &g_rgextdll;
  iVar1 = g_iextdllMac * 3;
  if (svs != 0) {
    Cvar_UnlinkExternals();
    if (&g_rgextdll < &g_rgextdll + iVar1) {
      piVar2 = &DAT_00385ac4;
      do {
        dlclose(*puVar3);
        *puVar3 = 0;
        if (*piVar2 != 0) {
          Mem_Free(*piVar2);
        }
        *piVar2 = 0;
        piVar2 = piVar2 + 3;
        puVar3 = puVar3 + 3;
      } while (puVar3 < &g_rgextdll + iVar1);
    }
    svs = 0;
  }
  return;
}


// RemoveLink  @ 0008ae04
void RemoveLink(int *param_1)

{
  *(int *)param_1[1] = *param_1;
  *(int *)(*param_1 + 4) = param_1[1];
  return;
}


// SafeRead  @ 000894d4
void SafeRead(FILE *param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  
  sVar1 = fread(param_2,1,param_3,param_1);
  if (sVar1 != param_3) {
    Sys_Error("File read failure");
  }
  return;
}


// SaveExit  @ 000595b4
void SaveExit(int param_1)

{
  if (*(int *)(param_1 + 0x18) != 0) {
    Mem_Free(*(int *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  if (param_1 != 0) {
    Mem_Free(param_1);
  }
  DAT_00152bdc = 0;
  return;
}


// SaveGame  @ 00059968
undefined4 SaveGame(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = scr_skipupdate;
  scr_skipupdate = 1;
  uVar2 = SaveGameSlot(param_1,param_2);
  scr_skipupdate = uVar1;
  return uVar2;
}


// SaveGameSlot  @ 0005960c
undefined4 SaveGameSlot(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  void *__ptr;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  FILE *__s;
  char *pcVar5;
  int local_284;
  undefined4 local_27c;
  undefined1 local_278 [32];
  undefined1 local_258 [80];
  undefined4 local_208;
  char local_204 [256];
  char local_104 [256];
  
  iVar2 = SaveGamestate();
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    SaveExit(iVar2);
    puVar4 = (undefined4 *)SaveInit(0);
    uVar3 = Host_SaveGameDirectory();
    sprintf(local_104,"%s*.HL?",uVar3);
    COM_FixSlashes(local_104);
    local_208 = DirectoryCount(local_104);
    Q_strcpy(local_278,&DAT_001535a8);
    Q_strcpy(local_258,param_2);
    (*DAT_00386248)(puVar4,"GameHeader",local_278,gGameHeaderDescription,3);
    (*DAT_00386250)(puVar4);
    __ptr = (void *)puVar4[1];
    if (puVar4[6] != 0) {
      for (local_284 = 0; local_284 < (int)puVar4[5]; local_284 = local_284 + 1) {
        pcVar5 = *(char **)(puVar4[6] + local_284 * 4);
        if (pcVar5 == (char *)0x0) {
          iVar2 = puVar4[2];
          puVar4[2] = iVar2 + 1;
          if ((int)puVar4[3] < iVar2 + 1) goto LAB_00059638;
          *(undefined1 *)puVar4[1] = 0;
          puVar4[1] = puVar4[1] + 1;
        }
        else {
          iVar2 = Q_strlen(pcVar5);
          iVar2 = puVar4[2] + 1 + iVar2;
          puVar4[2] = iVar2;
          if ((int)puVar4[3] < iVar2) {
LAB_00059638:
            Con_Printf("Token Table Save/Restore overflow!");
            puVar4[2] = puVar4[3];
            break;
          }
          cVar1 = *pcVar5;
          *(char *)puVar4[1] = cVar1;
          puVar4[1] = puVar4[1] + 1;
          while (cVar1 != '\0') {
            pcVar5 = pcVar5 + 1;
            cVar1 = *pcVar5;
            *(char *)puVar4[1] = cVar1;
            puVar4[1] = puVar4[1] + 1;
          }
        }
      }
    }
    iVar2 = puVar4[1] - (int)__ptr;
    puVar4[4] = iVar2;
    if ((int)puVar4[2] < (int)puVar4[3]) {
      puVar4[2] = puVar4[2] - iVar2;
    }
    uVar3 = Host_SaveGameDirectory(param_1);
    sprintf(local_204,"%s%s",uVar3);
    COM_DefaultExtension(local_204,&DAT_000a7963);
    COM_FixSlashes(local_204);
    Con_DPrintf("Saving game to %s...\n",local_204);
    iVar2 = Q_stricmp(param_1,"quick");
    if ((iVar2 != 0) || (iVar2 = Q_stricmp(param_1,"autosave"), iVar2 != 0)) {
      Host_SaveAgeList(param_1,1);
    }
    __s = fopen(local_204,"wb");
    local_27c = 0x5641534a;
    fwrite(&local_27c,4,1,__s);
    local_27c = 0x71;
    fwrite(&local_27c,4,1,__s);
    fwrite(puVar4 + 2,4,1,__s);
    fwrite(puVar4 + 5,4,1,__s);
    fwrite(puVar4 + 4,4,1,__s);
    fwrite(__ptr,puVar4[4],1,__s);
    fwrite((void *)*puVar4,puVar4[2],1,__s);
    DirectoryCopy(local_104,__s);
    fclose(__s);
    SaveExit(puVar4);
    uVar3 = 1;
  }
  return uVar3;
}


// SaveGamestate  @ 00059e24
undefined4 * SaveGamestate(void)

{
  int *piVar1;
  byte *pbVar2;
  char cVar3;
  size_t __size;
  void *__ptr;
  int iVar4;
  void *__ptr_00;
  undefined4 *puVar5;
  undefined4 uVar6;
  FILE *__s;
  char *pcVar7;
  undefined2 in_FPUControlWord;
  int local_1d0;
  float local_1cc;
  int local_1c8;
  undefined2 local_1c0;
  undefined2 uStack_1be;
  int local_1bc;
  undefined1 local_1b8 [64];
  undefined1 local_178 [4];
  undefined4 local_174;
  int local_170;
  undefined4 local_16c;
  undefined4 local_168;
  int local_164;
  float local_160;
  undefined1 local_15c [32];
  undefined1 local_13c [32];
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  char local_104 [256];
  
  if (DAT_0038628c != (code *)0x0) {
    puVar5 = (undefined4 *)SaveInit(0);
    uVar6 = Host_SaveGameDirectory(&DAT_001535a8);
    sprintf(local_104,"%s%s.HL1",uVar6);
    COM_FixSlashes(local_104);
    (*DAT_0038628c)();
    local_174 = build_number();
    _local_1c0 = CONCAT22(uStack_1be,in_FPUControlWord);
    local_1c8 = (int)ROUND((float)skill._12_4_);
    local_16c = puVar5[8];
    local_168 = puVar5[9];
    local_1cc = (float)DAT_0015358c;
    local_170 = local_1c8;
    local_160 = local_1cc;
    Q_strcpy(local_13c,sv_skyname._4_4_);
    local_114 = 0;
    local_118 = 0;
    local_11c = 0;
    local_108 = 0;
    local_10c = 0;
    local_110 = 0;
    puVar5[0x154] = 0;
    Q_strcpy(local_15c,&DAT_001535a8);
    local_164 = 0;
    local_1d0 = 0;
    do {
      if ((&DAT_00186e8c)[local_1d0] != 0) {
        local_164 = local_164 + 1;
      }
      local_1d0 = local_1d0 + 1;
    } while (local_1d0 < 0x40);
    (*DAT_00386248)(puVar5,"Save Header",local_178,gSaveHeaderDescription,0xd);
    local_1d0 = 0;
    puVar5[0x154] = local_160;
    if (0 < (int)puVar5[9]) {
      do {
        (*DAT_00386248)(puVar5,"ADJACENCY",puVar5 + local_1d0 * 0x14 + 0xb,gAdjacencyDescription,4);
        local_1d0 = local_1d0 + 1;
      } while (local_1d0 < (int)puVar5[9]);
    }
    local_1d0 = 0;
    do {
      if ((&DAT_00186e8c)[local_1d0] != 0) {
        local_1bc = local_1d0;
        Q_strcpy(local_1b8,(&DAT_00186e8c)[local_1d0]);
        (*DAT_00386248)(puVar5,FUN_000a7a48,&local_1bc,gLightstyleDescription,2);
      }
      local_1d0 = local_1d0 + 1;
    } while (local_1d0 < 0x40);
    local_1d0 = 0;
    if (0 < DAT_00186f8c) {
      do {
        piVar1 = (int *)(DAT_00186f94 + local_1d0 * 0x324);
        puVar5[7] = local_1d0;
        *(undefined4 *)(puVar5[10] + 8 + local_1d0 * 0x18) = puVar5[2];
        *(undefined4 *)(puVar5[10] + 0xc + local_1d0 * 0x18) = 0;
        if (((*piVar1 == 0) && ((*DAT_0038623c)(piVar1,puVar5), 0 < local_1d0)) &&
           (local_1d0 < DAT_001ab4e8 + 1)) {
          pbVar2 = (byte *)(puVar5[10] + 0x13 + local_1d0 * 0x18);
          *pbVar2 = *pbVar2 | 0x80;
        }
        local_1d0 = local_1d0 + 1;
      } while (local_1d0 < DAT_00186f8c);
    }
    __size = puVar5[2];
    __ptr = (void *)puVar5[1];
    local_1d0 = 0;
    if (0 < DAT_00186f8c) {
      do {
        (*DAT_00386248)(puVar5,"ETABLE",puVar5[10] + local_1d0 * 0x18,gEntityTableDescription,5);
        local_1d0 = local_1d0 + 1;
      } while (local_1d0 < DAT_00186f8c);
    }
    iVar4 = puVar5[2];
    __ptr_00 = (void *)puVar5[1];
    if ((puVar5[6] != 0) && (local_1d0 = 0, 0 < (int)puVar5[5])) {
      do {
        pcVar7 = *(char **)(puVar5[6] + local_1d0 * 4);
        if (pcVar7 == (char *)0x0) {
          *(undefined1 *)puVar5[1] = 0;
          puVar5[1] = puVar5[1] + 1;
        }
        else {
          cVar3 = *pcVar7;
          *(char *)puVar5[1] = cVar3;
          puVar5[1] = puVar5[1] + 1;
          while (cVar3 != '\0') {
            pcVar7 = pcVar7 + 1;
            cVar3 = *pcVar7;
            *(char *)puVar5[1] = cVar3;
            puVar5[1] = puVar5[1] + 1;
          }
        }
        local_1d0 = local_1d0 + 1;
      } while (local_1d0 < (int)puVar5[5]);
    }
    puVar5[4] = puVar5[1] - (int)__ptr_00;
    COM_CreatePath(local_104);
    __s = fopen(local_104,"wb");
    if (__s != (FILE *)0x0) {
      local_1d0 = 0x564c4156;
      fwrite(&local_1d0,4,1,__s);
      local_1d0 = 0x71;
      fwrite(&local_1d0,4,1,__s);
      fwrite(puVar5 + 2,4,1,__s);
      fwrite(puVar5 + 8,4,1,__s);
      fwrite(puVar5 + 5,4,1,__s);
      fwrite(puVar5 + 4,4,1,__s);
      fwrite(__ptr_00,puVar5[4],1,__s);
      fwrite(__ptr,iVar4 - __size,1,__s);
      fwrite((void *)*puVar5,__size,1,__s);
      fclose(__s);
      EntityPatchWrite(puVar5,&DAT_001535a8);
      uVar6 = Host_SaveGameDirectory(&DAT_001535a8);
      sprintf(local_104,"%s%s.HL2",uVar6);
      COM_FixSlashes(local_104);
      CL_Save(local_104);
      return puVar5;
    }
    Con_Printf("Unable to open save game file %s.",local_104);
  }
  return (undefined4 *)0x0;
}


// SaveInit  @ 00059434
int * SaveInit(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_10;
  int local_c;
  
  if (param_1 < 1) {
    param_1 = 0x80000;
  }
  piVar1 = (int *)Mem_Calloc(param_1 + 0x574 + DAT_00186f8c * 0x18,1);
  piVar1[10] = (int)(piVar1 + 0x15d);
  piVar1[4] = 0;
  piVar1[5] = 0xfff;
  iVar2 = Mem_Calloc(piVar1[5],4);
  piVar1[6] = iVar2;
  local_10 = 0;
  if (0 < DAT_00186f8c) {
    iVar2 = 0;
    local_c = 0;
    do {
      iVar3 = local_c + DAT_00186f94;
      *(int *)(piVar1[10] + iVar2) = local_10;
      *(int *)(piVar1[10] + 4 + iVar2) = iVar3;
      *(undefined4 *)(piVar1[10] + 0x10 + iVar2) = 0;
      *(undefined4 *)(piVar1[10] + 8 + iVar2) = 0;
      local_10 = local_10 + 1;
      *(undefined4 *)(piVar1[10] + 0xc + iVar2) = 0;
      *(undefined4 *)(piVar1[10] + 0x14 + iVar2) = 0;
      iVar2 = iVar2 + 0x18;
      local_c = local_c + 0x324;
    } while (local_10 < DAT_00186f8c);
  }
  piVar1[8] = DAT_00186f8c;
  piVar1[9] = 0;
  iVar2 = piVar1[10] + DAT_00186f8c * 0x18;
  *piVar1 = iVar2;
  piVar1[1] = iVar2;
  piVar1[2] = 0;
  piVar1[3] = param_1;
  piVar1[0x154] = gGlobalVariables;
  piVar1[0x151] = vec3_origin;
  piVar1[0x152] = DAT_000b2e2c;
  iVar2 = DAT_000b2e30;
  piVar1[0x14b] = 0;
  piVar1[0x153] = iVar2;
  DAT_00152bdc = piVar1;
  return piVar1;
}


// SaveReadComment  @ 00059b5c
void SaveReadComment(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_78 [32];
  undefined1 local_58 [84];
  
  iVar1 = SaveReadHeader(param_1,local_78,0);
  if (iVar1 != 0) {
    Q_strcpy(param_2,local_58);
  }
  return;
}


// SaveReadHeader  @ 000599ac
undefined4 SaveReadHeader(FILE *param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  char *__ptr;
  size_t local_14;
  int local_10;
  size_t local_c;
  int local_8;
  
  fread(&local_8,4,1,param_1);
  if ((local_8 == 0x5641534a) && (fread(&local_8,4,1,param_1), local_8 == 0x71)) {
    fread(&local_c,4,1,param_1);
    fread(&local_10,4,1,param_1);
    fread(&local_14,4,1,param_1);
    puVar3 = (undefined4 *)Mem_Calloc(local_c + 0x574 + local_14,1);
    __ptr = (char *)(puVar3 + 0x15d);
    puVar3[8] = 0;
    puVar3[10] = 0;
    puVar3[9] = 0;
    if (0 < (int)local_14) {
      puVar3[5] = local_10;
      puVar3[4] = local_14;
      fread(__ptr,local_14,1,param_1);
      if (puVar3[6] == 0) {
        uVar2 = Mem_Calloc(local_10,4);
        puVar3[6] = uVar2;
      }
      iVar5 = 0;
      if (0 < local_10) {
        do {
          pcVar4 = (char *)0x0;
          if (*__ptr != '\0') {
            pcVar4 = __ptr;
          }
          *(char **)(puVar3[6] + iVar5 * 4) = pcVar4;
          do {
            cVar1 = *__ptr;
            __ptr = __ptr + 1;
          } while (cVar1 != '\0');
          iVar5 = iVar5 + 1;
        } while (iVar5 < local_10);
      }
    }
    puVar3[2] = 0;
    puVar3[3] = local_c;
    puVar3[0x14b] = 0;
    puVar3[0x154] = 0;
    puVar3[1] = __ptr;
    *puVar3 = __ptr;
    fread((void *)*puVar3,local_c,1,param_1);
    (*DAT_0038624c)(puVar3,"GameHeader",param_2,gGameHeaderDescription,3);
    if (param_3 != 0) {
      (*DAT_00386254)(puVar3);
    }
    SaveExit(puVar3);
    uVar2 = 1;
  }
  else {
    fclose(param_1);
    uVar2 = 0;
  }
  return uVar2;
}


// SaveSpawnParms  @ 000720e8
void SaveSpawnParms(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (DAT_001ab4e8 < iVar1)) {
    Host_Error("Entity is not a client");
  }
  return;
}


// SeedRandomNumberGenerator  @ 000707f8
void SeedRandomNumberGenerator(void)

{
  int iVar1;
  bool bVar2;
  
  idum = time((time_t *)0x0);
  iVar1 = -idum;
  if ((idum == -1000 || iVar1 < 1000) &&
     (bVar2 = idum != 1000, idum = iVar1, bVar2 && -0x3e9 < iVar1)) {
    idum = iVar1 + -0x153ad38;
  }
  return;
}


// ServerPrint  @ 0006c314
void ServerPrint(undefined4 param_1)

{
  Con_Printf(&DAT_000a91f8,param_1);
  return;
}


// SetAuth  @ 000941f4
void SetAuth(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &crypt;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// SetMessagePumpDisableMode  @ 00093448
void SetMessagePumpDisableMode(undefined4 param_1)

{
  g_bInactive = param_1;
  return;
}


// SetMinMaxSize  @ 0006bf64
void SetMinMaxSize(int param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  float *pfVar7;
  
  pfVar6 = param_3;
  pfVar7 = param_2;
  if ((int)param_3 < (int)param_3 + 9) {
    if (*param_3 < *param_2) {
      Host_Error("backwards mins/maxs");
    }
    if (param_3[1] < param_2[1]) {
      Host_Error("backwards mins/maxs");
    }
    pfVar6 = param_3 + 2;
    pfVar7 = param_2 + 2;
  }
  if (*pfVar6 < *pfVar7) {
    Host_Error("backwards mins/maxs");
  }
  pfVar7 = pfVar7 + 1;
  for (pfVar6 = pfVar6 + 1; (int)pfVar6 <= (int)(param_3 + 2); pfVar6 = pfVar6 + 4) {
    if (*pfVar6 < *pfVar7) {
      Host_Error("backwards mins/maxs");
    }
    if (pfVar6[1] < pfVar7[1]) {
      Host_Error("backwards mins/maxs");
    }
    if (pfVar6[2] < pfVar7[2]) {
      Host_Error("backwards mins/maxs");
    }
    if (pfVar6[3] < pfVar7[3]) {
      Host_Error("backwards mins/maxs");
    }
    pfVar7 = pfVar7 + 4;
  }
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  fVar3 = *param_3;
  fVar4 = param_3[1];
  fVar5 = param_3[2];
  *(float *)(param_1 + 0x15c) = *param_2;
  *(float *)(param_1 + 0x160) = fVar1;
  *(float *)(param_1 + 0x164) = fVar2;
  *(float *)(param_1 + 0x168) = fVar3;
  *(float *)(param_1 + 0x16c) = fVar4;
  *(float *)(param_1 + 0x170) = fVar5;
  *(float *)(param_1 + 0x174) = *param_3 - *param_2;
  *(float *)(param_1 + 0x178) = param_3[1] - param_2[1];
  *(float *)(param_1 + 0x17c) = param_3[2] - param_2[2];
  SV_LinkEdict(param_1,0);
  return;
}


// SetPauseState  @ 0009346c
void SetPauseState(int param_1)

{
  if (param_1 == 0) {
    if (gLauncherPause != 0) {
      DAT_00153584 = g_bPaused;
    }
    gLauncherPause = 0;
  }
  else {
    if (gLauncherPause == 0) {
      g_bPaused = DAT_00153584;
    }
    DAT_00153584 = 1;
    gLauncherPause = 1;
  }
  return;
}


// SetStartupMode  @ 00093424
void SetStartupMode(undefined4 param_1)

{
  g_bInStartup = param_1;
  return;
}


// ShortNoSwap  @ 00049c30
int ShortNoSwap(short param_1)

{
  return (int)param_1;
}


// ShortSwap  @ 00049c10
int ShortSwap(ushort param_1)

{
  return (int)(short)(param_1 * 0x100 + (param_1 >> 8));
}


// SkipSpace  @ 000887b4
char * SkipSpace(char *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  if (param_1 == (char *)0x0) {
    param_1 = (char *)0x0;
  }
  else {
    iVar4 = 0;
    cVar1 = *param_1;
    pcVar3 = param_1;
    while ((cVar1 != '\0' && (iVar2 = IsWhiteSpace((int)*pcVar3), iVar2 != 0))) {
      pcVar3 = pcVar3 + 1;
      iVar4 = iVar4 + 1;
      cVar1 = *pcVar3;
    }
    param_1 = param_1 + iVar4;
  }
  return param_1;
}


// SkipText  @ 00088804
char * SkipText(char *param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  if (param_1 == (char *)0x0) {
    param_1 = (char *)0x0;
  }
  else {
    iVar3 = 0;
    for (pcVar2 = param_1; *pcVar2 != '\0'; pcVar2 = pcVar2 + 1) {
      iVar1 = IsWhiteSpace((int)*pcVar2);
      if (iVar1 != 0) break;
      iVar3 = iVar3 + 1;
    }
    param_1 = param_1 + iVar3;
  }
  return param_1;
}


// SockadrToNetadr  @ 0008eeb8
void SockadrToNetadr(short *param_1,undefined4 *param_2)

{
  if (*param_1 == 2) {
    *param_2 = 3;
    param_2[1] = *(undefined4 *)(param_1 + 2);
    *(short *)((int)param_2 + 0x12) = param_1[1];
  }
  return;
}


// StringToFilter  @ 0007c6f8
undefined4 StringToFilter(char *param_1,undefined4 *param_2)

{
  char cVar1;
  char *pcVar2;
  int local_a8;
  int local_9c;
  undefined4 local_8c;
  undefined4 local_88;
  char local_84 [128];
  
  local_88 = 0;
  local_8c = 0;
  local_9c = 0;
  do {
    cVar1 = *param_1;
    if (9 < (byte)(cVar1 - 0x30U)) {
LAB_0007c80a:
      Con_Printf("Bad filter address: %s\n",param_1);
      return 0;
    }
    local_a8 = 0;
    do {
      pcVar2 = param_1;
      param_1 = pcVar2 + 1;
      local_84[local_a8] = cVar1;
      local_a8 = local_a8 + 1;
      cVar1 = *param_1;
    } while ((byte)(cVar1 - 0x30U) < 10);
    local_84[local_a8] = '\0';
    cVar1 = Q_atoi(local_84);
    local_84[local_9c + -4] = cVar1;
    if (cVar1 != '\0') {
      *(undefined1 *)((int)&local_8c + local_9c) = 0xff;
    }
    if (*param_1 == '\0') break;
    param_1 = pcVar2 + 2;
    cVar1 = *param_1;
    if (9 < (byte)(cVar1 - 0x30U)) goto LAB_0007c80a;
    local_a8 = 0;
    do {
      pcVar2 = param_1;
      param_1 = pcVar2 + 1;
      local_84[local_a8] = cVar1;
      local_a8 = local_a8 + 1;
      cVar1 = *param_1;
    } while ((byte)(cVar1 - 0x30U) < 10);
    local_84[local_a8] = '\0';
    cVar1 = Q_atoi(local_84);
    local_84[local_9c + -3] = cVar1;
    if (cVar1 != '\0') {
      *(undefined1 *)((int)&local_8c + local_9c + 1) = 0xff;
    }
    if (*param_1 == '\0') break;
    param_1 = pcVar2 + 2;
    local_9c = local_9c + 2;
  } while (local_9c < 4);
  *param_2 = local_8c;
  param_2[1] = local_88;
  return 1;
}


// SuckOutClassname  @ 00071c1c
void SuckOutClassname(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_114;
  undefined1 *local_110;
  undefined1 *local_10c;
  int local_108;
  undefined1 local_104 [256];
  
  do {
    uVar1 = COM_Parse(param_1);
    if (com_token == '}') {
      return;
    }
    Q_strcpy(local_104,&com_token);
    param_1 = COM_Parse(uVar1);
    iVar2 = Q_strcmp(local_104,"classname");
  } while (iVar2 != 0);
  local_114 = 0;
  local_10c = &com_token;
  local_108 = 0;
  local_110 = local_104;
  (*DAT_00386238)(param_2,&local_114);
  if (local_108 == 0) {
    Host_Error("SuckOutClassname: parse error");
  }
  return;
}


// SurfaceAtPoint  @ 0006cb64
int SurfaceAtPoint(int param_1,int *param_2,float *param_3,float *param_4)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  short *psVar9;
  bool bVar10;
  short *local_40;
  int local_28;
  int local_24;
  uint local_20;
  float local_10;
  float local_c;
  float local_8;
  
  if (*param_2 < 0) {
LAB_0006ccc5:
    iVar8 = 0;
  }
  else {
    fVar2 = *param_3;
    fVar3 = param_3[1];
    pfVar5 = (float *)param_2[6];
    fVar4 = param_3[2];
    fVar6 = (fVar2 * *pfVar5 + fVar3 * pfVar5[1] + fVar4 * pfVar5[2]) - pfVar5[3];
    fVar7 = (*param_4 * *pfVar5 + param_4[1] * pfVar5[1] + param_4[2] * pfVar5[2]) - pfVar5[3];
    bVar10 = (byte)(fVar6 < 0.0 | (byte)((ushort)((ushort)NAN(fVar6) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar6 == 0.0) << 0xe) >> 8)) == 1;
    local_20 = (uint)bVar10;
    if (((byte)(fVar7 < 0.0 | (byte)((ushort)((ushort)NAN(fVar7) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar7 == 0.0) << 0xe) >> 8)) == 1) != bVar10) {
      fVar6 = fVar6 / (fVar6 - fVar7);
      local_10 = fVar2 + (*param_4 - fVar2) * fVar6;
      local_c = (param_4[1] - fVar3) * fVar6 + fVar3;
      local_8 = (param_4[2] - fVar4) * fVar6 + fVar4;
      iVar8 = SurfaceAtPoint(param_1,param_2[local_20 + 7],param_3,&local_10);
      if (iVar8 != 0) {
        return iVar8;
      }
      if (((byte)(fVar7 < 0.0 | (byte)((ushort)((ushort)NAN(fVar7) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar7 == 0.0) << 0xe) >> 8)) == 1) == local_20)
      goto LAB_0006ccc5;
      local_28 = 0;
      local_24 = *(int *)(param_1 + 0xb4) + (uint)*(ushort *)(param_2 + 9) * 0x44;
      if (*(short *)((int)param_2 + 0x26) != 0) {
        local_40 = (short *)(local_24 + 0x32);
        psVar9 = (short *)(local_24 + 0x30);
        do {
          pfVar5 = *(float **)(psVar9 + 2);
          iVar8 = (int)ROUND(local_8 * pfVar5[2] + local_c * pfVar5[1] + local_10 * *pfVar5 +
                             pfVar5[3]);
          iVar1 = (int)ROUND(local_8 * pfVar5[6] + local_c * pfVar5[5] + local_10 * pfVar5[4] +
                             pfVar5[7]);
          if ((((psVar9[-2] <= iVar8) && (psVar9[-1] <= iVar1)) &&
              (iVar8 - psVar9[-2] <= (int)*psVar9)) && (iVar1 - psVar9[-1] <= (int)*local_40)) {
            return local_24;
          }
          local_28 = local_28 + 1;
          psVar9 = psVar9 + 0x22;
          local_40 = local_40 + 0x22;
          local_24 = local_24 + 0x44;
        } while (local_28 < (int)(uint)*(ushort *)((int)param_2 + 0x26));
      }
      local_20 = (uint)!bVar10;
      param_3 = &local_10;
    }
    iVar8 = SurfaceAtPoint(param_1,param_2[local_20 + 7],param_3,param_4);
  }
  return iVar8;
}


// SwapPic  @ 0008a1dc
void SwapPic(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*LittleLong)(*param_1);
  *param_1 = uVar1;
  uVar1 = (*LittleLong)(param_1[1]);
  param_1[1] = uVar1;
  return;
}


// SzFromIndex  @ 00071eb4
int SzFromIndex(int param_1)

{
  return pr_strings + param_1;
}


// TextMessageGet  @ 000893dc
undefined1 * TextMessageGet(undefined4 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = Q_stricmp(param_1,FUN_000aceb0);
  if (iVar1 == 0) {
    puVar2 = gNetworkTextMessage;
  }
  else {
    iVar1 = Q_stricmp(param_1,"__NETMESSAGE__2");
    if (iVar1 == 0) {
      puVar2 = gNetworkTextMessage + 0x2c;
    }
    else {
      iVar1 = Q_stricmp(param_1,"__NETMESSAGE__3");
      if (iVar1 == 0) {
        puVar2 = gNetworkTextMessage + 0x58;
      }
      else {
        iVar1 = Q_stricmp(param_1,"__NETMESSAGE__4");
        if (iVar1 == 0) {
          puVar2 = gNetworkTextMessage + 0x84;
        }
        else {
          iVar1 = 0;
          if (0 < gMessageTableCount) {
            iVar4 = 0;
            do {
              iVar3 = Q_strcmp(param_1,*(undefined4 *)(gMessageTable + 0x24 + iVar4));
              if (iVar3 == 0) {
                return (undefined1 *)(iVar4 + gMessageTable);
              }
              iVar4 = iVar4 + 0x2c;
              iVar1 = iVar1 + 1;
            } while (iVar1 < gMessageTableCount);
          }
          puVar2 = (undefined1 *)0x0;
        }
      }
    }
  }
  return puVar2;
}


// TextMessageInit  @ 0008937c
void TextMessageInit(void)

{
  int iVar1;
  undefined4 local_8;
  
  if (gMessageTable != 0) {
    Mem_Free(gMessageTable);
    gMessageTable = 0;
  }
  iVar1 = COM_LoadTempFile("titles.txt",&local_8);
  if (iVar1 != 0) {
    TextMessageParse(iVar1,local_8);
  }
  return;
}


// TextMessageParse  @ 00088ce4
void TextMessageParse(int param_1,undefined4 param_2)

{
  int *piVar1;
  bool bVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  int local_8d48;
  uint local_8d44;
  uint local_8d40;
  int local_8d38;
  int local_8d34;
  int local_8d2c;
  int local_8d28;
  undefined4 local_8d24 [9];
  int aiStack_8d00 [12];
  undefined4 auStack_8cd0 [11];
  undefined4 auStack_8ca4 [11];
  undefined4 auStack_8c78 [6557];
  undefined1 local_2604 [8192];
  undefined1 local_604 [512];
  undefined1 local_404 [512];
  undefined1 local_204 [512];
  
  bVar2 = false;
  local_8d34 = 0;
  local_8d38 = 0;
  local_8d28 = 0;
  local_8d40 = 0;
  while (iVar10 = local_8d28, iVar4 = memfgets(param_1,param_2,&local_8d28,local_204,0x200),
        iVar4 != 0) {
    if (599 < (int)local_8d40) {
      Sys_Error("tmessage::TextMessageParse : messageCount>=MAX_MESSAGES");
    }
    TrimSpace(local_204,local_404);
    if (bVar2) {
      if (bVar2) {
        iVar4 = IsEndOfText(local_404);
        if (iVar4 == 0) {
          iVar10 = IsStartOfText(local_404);
          if (iVar10 != 0) {
            pcVar3 = "Unexpected \'{\' found, line %d\n";
LAB_00088f22:
            Con_DPrintf(pcVar3,local_8d38);
            return;
          }
        }
        else {
          iVar4 = Q_strlen(local_604);
          if (0x2000 < iVar4 + local_8d34) {
            Con_DPrintf("Error parsing file!\n");
            return;
          }
          Q_strcpy(local_2604 + local_8d34,local_604);
          *(undefined1 *)(param_1 + -1 + iVar10) = 0;
          puVar9 = &gMessageParms;
          puVar11 = local_8d24 + local_8d40 * 0xb;
          for (iVar10 = 0xb; iVar10 != 0; iVar10 = iVar10 + -1) {
            *puVar11 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar11 = puVar11 + 1;
          }
          aiStack_8d00[local_8d40 * 0xb] = (int)(local_2604 + local_8d34);
          iVar10 = Q_strlen(local_604);
          local_8d34 = iVar10 + 1 + local_8d34;
          bVar2 = false;
          aiStack_8d00[local_8d40 * 0xb + 1] = local_8d2c;
          local_8d40 = local_8d40 + 1;
        }
      }
    }
    else {
      iVar10 = IsComment(local_404);
      if ((iVar10 == 0) && (iVar10 = ParseDirective(local_404), iVar10 == 0)) {
        iVar10 = IsStartOfText(local_404);
        if (iVar10 == 0) {
          iVar10 = IsEndOfText(local_404);
          if (iVar10 != 0) {
            pcVar3 = "Unexpected \'}\' found, line %d\n";
            goto LAB_00088f22;
          }
          Q_strcpy(local_604,local_404);
        }
        else {
          bVar2 = true;
          local_8d2c = param_1 + local_8d28;
        }
      }
    }
    local_8d38 = local_8d38 + 1;
  }
  Con_DPrintf("Parsed %d text messages\n",local_8d40);
  local_8d48 = 0;
  local_8d44 = 0;
  if (0 < (int)local_8d40) {
    iVar10 = 0;
    uVar5 = local_8d40 & 3;
    if (uVar5 != 0) {
      if (1 < uVar5) {
        if (2 < uVar5) {
          local_8d48 = Q_strlen(aiStack_8d00[1]);
          local_8d48 = local_8d48 + 1;
          iVar10 = 0x2c;
        }
        local_8d44 = (uint)(2 < uVar5);
        iVar4 = Q_strlen(*(undefined4 *)((int)aiStack_8d00 + iVar10 + 4));
        local_8d48 = iVar4 + 1 + local_8d48;
        iVar10 = iVar10 + 0x2c;
        local_8d44 = local_8d44 + 1;
      }
      iVar4 = Q_strlen(*(undefined4 *)((int)aiStack_8d00 + iVar10 + 4));
      local_8d48 = iVar4 + 1 + local_8d48;
      iVar10 = iVar10 + 0x2c;
      local_8d44 = local_8d44 + 1;
      if ((int)local_8d40 <= (int)local_8d44) goto LAB_000890f5;
    }
    do {
      iVar4 = Q_strlen(*(undefined4 *)((int)aiStack_8d00 + iVar10 + 4));
      iVar6 = Q_strlen(*(undefined4 *)((int)auStack_8cd0 + iVar10));
      iVar7 = Q_strlen(*(undefined4 *)((int)auStack_8ca4 + iVar10));
      iVar8 = Q_strlen(*(undefined4 *)((int)auStack_8c78 + iVar10));
      local_8d48 = iVar8 + iVar7 + iVar6 + iVar4 + 4 + local_8d48;
      iVar10 = iVar10 + 0xb0;
      local_8d44 = local_8d44 + 4;
    } while ((int)local_8d44 < (int)local_8d40);
  }
LAB_000890f5:
  iVar10 = local_8d40 * 0x2c;
  gMessageTable = Mem_Malloc(local_8d48 + local_8d34 + iVar10);
  Q_memcpy(gMessageTable,local_8d24,iVar10);
  iVar10 = iVar10 + gMessageTable;
  Q_memcpy(iVar10,local_2604,local_8d34);
  local_8d2c = iVar10 + local_8d34;
  local_8d44 = 0;
  iVar10 = iVar10 - *(int *)(gMessageTable + 0x24);
  if (0 < (int)local_8d40) {
    iVar4 = 0;
    if ((local_8d40 & 1) != 0) {
      *(int *)(gMessageTable + 0x24) = *(int *)(gMessageTable + 0x24) + iVar10;
      Q_strcpy(local_8d2c,*(undefined4 *)(gMessageTable + 0x28));
      *(int *)(gMessageTable + 0x28) = local_8d2c;
      iVar4 = Q_strlen(local_8d2c);
      local_8d2c = local_8d2c + 1 + iVar4;
      iVar4 = 0x2c;
      local_8d44 = 1;
      if ((int)local_8d40 < 2) {
        gMessageTableCount = local_8d40;
        return;
      }
    }
    do {
      piVar1 = (int *)(gMessageTable + 0x24 + iVar4);
      *piVar1 = *piVar1 + iVar10;
      Q_strcpy(local_8d2c,*(undefined4 *)(gMessageTable + 0x28 + iVar4));
      *(int *)(gMessageTable + 0x28 + iVar4) = local_8d2c;
      iVar7 = Q_strlen(local_8d2c);
      iVar7 = local_8d2c + 1 + iVar7;
      iVar6 = iVar4 + 0x2c;
      piVar1 = (int *)(gMessageTable + 0x24 + iVar6);
      *piVar1 = *piVar1 + iVar10;
      Q_strcpy(iVar7,*(undefined4 *)(gMessageTable + 0x28 + iVar6));
      *(int *)(gMessageTable + 0x28 + iVar6) = iVar7;
      iVar6 = Q_strlen(iVar7);
      local_8d2c = iVar7 + 1 + iVar6;
      iVar4 = iVar4 + 0x58;
      local_8d44 = local_8d44 + 2;
    } while ((int)local_8d44 < (int)local_8d40);
  }
  gMessageTableCount = local_8d40;
  return;
}


// TextMessageShutdown  @ 00089344
void TextMessageShutdown(void)

{
  if (gMessageTable != 0) {
    Mem_Free(gMessageTable);
    gMessageTable = 0;
  }
  return;
}


// TraceHull  @ 0006c964
void TraceHull(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,
              undefined4 param_5,undefined4 *param_6)

{
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
  undefined4 local_8;
  
  if (3 < param_4) {
    param_4 = 0;
  }
  SV_Move(&local_3c,param_1,gHullMins + param_4 * 0xc,gHullMaxs + param_4 * 0xc,param_2,param_3,
          param_5,0);
  *param_6 = local_3c;
  param_6[1] = local_38;
  param_6[2] = local_34;
  param_6[3] = local_30;
  param_6[4] = local_2c;
  param_6[8] = local_10;
  param_6[0xc] = local_c;
  param_6[0xd] = local_8;
  param_6[5] = local_28;
  param_6[6] = local_24;
  param_6[7] = local_20;
  param_6[9] = local_1c;
  param_6[10] = local_18;
  param_6[0xb] = local_14;
  return;
}


// TraceModel  @ 0006ca38
void TraceModel(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 local_44;
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
  undefined4 local_8;
  
  if (3 < param_3) {
    param_3 = 0;
  }
  iVar1 = *(int *)(&DAT_00183e88 + *(int *)(param_4 + 0x134) * 4);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x44) == 0)) {
    local_40 = *(undefined4 *)(param_4 + 0x18c);
    local_44 = *(undefined4 *)(param_4 + 0x188);
    *(undefined4 *)(param_4 + 0x18c) = 4;
    *(undefined4 *)(param_4 + 0x188) = 7;
  }
  SV_ClipMoveToEntity(&local_3c,param_4,param_1,gHullMins + param_3 * 0xc,gHullMaxs + param_3 * 0xc,
                      param_2);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x44) == 0)) {
    *(undefined4 *)(param_4 + 0x18c) = local_40;
    *(undefined4 *)(param_4 + 0x188) = local_44;
  }
  *param_5 = local_3c;
  param_5[1] = local_38;
  param_5[2] = local_34;
  param_5[3] = local_30;
  param_5[4] = local_2c;
  param_5[8] = local_10;
  param_5[0xc] = local_c;
  param_5[0xd] = local_8;
  param_5[5] = local_28;
  param_5[6] = local_24;
  param_5[7] = local_20;
  param_5[9] = local_1c;
  param_5[10] = local_18;
  param_5[0xb] = local_14;
  return;
}


// TraceMonsterHull  @ 0006d274
undefined4
TraceMonsterHull(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int *param_6)

{
  undefined4 uVar1;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  float local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  SV_Move(&local_3c,param_2,param_1 + 0x15c,param_1 + 0x168,param_3,param_4,param_5,
          (*(byte *)(param_1 + 0x226) & 0x80) != 0);
  if (param_6 != (int *)0x0) {
    *param_6 = local_3c;
    param_6[1] = local_38;
    param_6[2] = local_34;
    param_6[3] = local_30;
    param_6[4] = (int)local_2c;
    param_6[8] = local_10;
    param_6[0xc] = local_c;
    param_6[0xd] = local_8;
    param_6[5] = local_28;
    param_6[6] = local_24;
    param_6[7] = local_20;
    param_6[9] = local_1c;
    param_6[10] = local_18;
    param_6[0xb] = local_14;
  }
  if ((local_3c == 0) &&
     ((byte)(1.0 < local_2c | (byte)((ushort)((ushort)NAN(local_2c) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_2c == 1.0) << 0xe) >> 8)) == 0x40)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// TraceSphere  @ 0006ca14
void TraceSphere(void)

{
  Sys_Error("TraceSphere not yet implemented!\n");
  return;
}


// TraceTexture  @ 0006ce10
undefined4 TraceTexture(int param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int local_60;
  int local_5c;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_60 = 0;
  if (param_1 == 0) {
    local_5c = DAT_00153668;
    local_10 = *param_2;
    local_c = param_2[1];
    local_8 = param_2[2];
    local_1c = *param_3;
    local_18 = param_3[1];
    local_14 = param_3[2];
  }
  else {
    local_5c = *(int *)(&DAT_00183e88 + *(int *)(param_1 + 0x134) * 4);
    if (local_5c == 0) {
      return 0;
    }
    if (*(int *)(local_5c + 0x44) != 0) {
      return 0;
    }
    iVar4 = SV_HullForBsp(param_1,&vec3_origin,&vec3_origin,&local_28);
    local_10 = *param_2 - local_28;
    local_c = param_2[1] - local_24;
    local_8 = param_2[2] - local_20;
    local_1c = *param_3 - local_28;
    local_18 = param_3[1] - local_24;
    local_14 = param_3[2] - local_20;
    local_60 = *(int *)(iVar4 + 8);
    if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xd0)) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(param_1 + 0xd0) == 0.0) << 0xe) >> 8)) != 0x40)
        || ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0xd4)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(*(float *)(param_1 + 0xd4) == 0.0) << 0xe) >> 8)) != 0x40
           )) || (fVar1 = *(float *)(param_1 + 0xd8),
                 (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
      AngleVectors(param_1 + 0xd0,&local_34,&local_40,&local_4c);
      fVar2 = local_c * local_30;
      fVar3 = local_8 * local_2c;
      fVar1 = local_8 * local_38;
      local_8 = local_8 * local_44 + local_10 * local_4c + local_c * local_48;
      local_30 = local_18 * local_30;
      local_c = -(fVar1 + local_10 * local_40 + local_c * local_3c);
      local_2c = local_14 * local_2c;
      local_48 = local_18 * local_48;
      local_18 = -(local_14 * local_38 + local_1c * local_40 + local_18 * local_3c);
      local_14 = local_14 * local_44 + local_1c * local_4c + local_48;
      local_1c = local_2c + local_1c * local_34 + local_30;
      local_10 = fVar3 + fVar2 + local_10 * local_34;
    }
  }
  if (((local_5c != 0) && (*(int *)(local_5c + 0x44) == 0)) &&
     ((*(int *)(local_5c + 0xa4) != 0 &&
      (iVar4 = SurfaceAtPoint(local_5c,*(int *)(local_5c + 0xa4) + local_60 * 0x28,&local_10,
                              &local_1c), iVar4 != 0)))) {
    return *(undefined4 *)(*(int *)(iVar4 + 0x34) + 0x24);
  }
  return 0;
}


// TrimSpace  @ 000888bc
void TrimSpace(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  int local_8;
  
  local_8 = 0;
  iVar2 = Q_strlen(param_1);
  cVar1 = *param_1;
  pcVar5 = param_1;
  while ((cVar1 != '\0' && (iVar3 = IsWhiteSpace((int)*pcVar5), iVar3 != 0))) {
    pcVar5 = pcVar5 + 1;
    local_8 = local_8 + 1;
    cVar1 = *pcVar5;
  }
  iVar2 = iVar2 + -1;
  if (0 < iVar2) {
    uVar4 = -iVar2 & 3;
    if (uVar4 == 0) goto LAB_00088924;
    if (2 < uVar4) goto LAB_00088963;
    if (1 < uVar4) goto LAB_0008894e;
    while (iVar3 = IsWhiteSpace((int)param_1[iVar2]), iVar3 != 0) {
      iVar2 = iVar2 + -1;
LAB_0008894e:
      iVar3 = IsWhiteSpace((int)param_1[iVar2]);
      if (iVar3 == 0) break;
      iVar2 = iVar2 + -1;
LAB_00088963:
      iVar3 = IsWhiteSpace((int)param_1[iVar2]);
      if ((iVar3 == 0) || (iVar2 = iVar2 + -1, iVar2 < 1)) break;
LAB_00088924:
      iVar3 = IsWhiteSpace((int)param_1[iVar2]);
      if (iVar3 == 0) break;
      iVar2 = iVar2 + -1;
    }
  }
  iVar2 = (iVar2 + 1) - local_8;
  if (iVar2 < 1) {
    iVar2 = 0;
  }
  else {
    Q_strncpy(param_2,param_1 + local_8,iVar2);
  }
  *(undefined1 *)(iVar2 + param_2) = 0;
  return;
}


// ValidCmd  @ 0006d86c
undefined4 ValidCmd(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = Q_strlen(param_1);
  if ((iVar2 == 0) || ((cVar1 = *(char *)(param_1 + -1 + iVar2), cVar1 != '\n' && (cVar1 != ';'))))
  {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}


// VectorAngles  @ 00061dd8
void VectorAngles(float *param_1,float *param_2)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  
  lVar4 = (longdouble)0;
  lVar2 = (longdouble)param_1[1];
  if (((byte)((byte)((ushort)((ushort)(NAN(lVar2) || NAN(lVar4)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar2 == lVar4) << 0xe) >> 8)) == 0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN((longdouble)*param_1) || NAN(lVar4)) << 10) >> 8) |
            (byte)((ushort)((ushort)((longdouble)*param_1 == lVar4) << 0xe) >> 8)) == 0x40)) {
    lVar2 = (longdouble)270.0;
    if (lVar4 < (longdouble)param_1[2]) {
      lVar2 = (longdouble)90.0;
    }
  }
  else {
    lVar3 = (longdouble)*param_1;
    lVar4 = (longdouble)fpatan(lVar2,lVar3);
    lVar4 = (longdouble)(float)(lVar4 * (longdouble)57.29577951308232);
    lVar1 = (longdouble)0;
    if (0x3f < (byte)((lVar1 < lVar4 |
                       (byte)((ushort)((ushort)(NAN(lVar1) || NAN(lVar4)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar1 == lVar4) << 0xe) >> 8)) - 1)) {
      lVar4 = (longdouble)360.0 + lVar4;
    }
    lVar2 = (longdouble)
            fpatan((longdouble)param_1[2],(longdouble)(float)SQRT(lVar2 * lVar2 + lVar3 * lVar3));
    lVar2 = (longdouble)(float)(lVar2 * (longdouble)57.29577951308232);
    if (lVar2 < lVar1) {
      lVar2 = (longdouble)360.0 + lVar2;
    }
  }
  *param_2 = (float)lVar2;
  param_2[1] = (float)lVar4;
  param_2[2] = 0.0;
  return;
}


// VectorCompare  @ 00061a1c
undefined4 VectorCompare(float *param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  
  pfVar1 = param_2 + 2;
  if ((int)param_2 < (int)param_2 + 9) {
    if ((byte)((byte)((ushort)((ushort)(NAN(*param_2) || NAN(*param_1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(*param_2 == *param_1) << 0xe) >> 8)) != 0x40) {
      return 0;
    }
    if ((byte)((byte)((ushort)((ushort)(NAN(param_2[1]) || NAN(param_1[1])) << 10) >> 8) |
              (byte)((ushort)((ushort)(param_2[1] == param_1[1]) << 0xe) >> 8)) != 0x40) {
      return 0;
    }
    param_2 = param_2 + 2;
    param_1 = param_1 + 2;
  }
  if ((byte)((byte)((ushort)((ushort)(NAN(*param_2) || NAN(*param_1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(*param_2 == *param_1) << 0xe) >> 8)) == 0x40) {
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
    while( true ) {
      if ((int)pfVar1 < (int)param_2) {
        return 1;
      }
      if ((((byte)((byte)((ushort)((ushort)(NAN(*param_2) || NAN(*param_1)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(*param_2 == *param_1) << 0xe) >> 8)) != 0x40) ||
          ((byte)((byte)((ushort)((ushort)(NAN(param_2[1]) || NAN(param_1[1])) << 10) >> 8) |
                 (byte)((ushort)((ushort)(param_2[1] == param_1[1]) << 0xe) >> 8)) != 0x40)) ||
         ((byte)((byte)((ushort)((ushort)(NAN(param_2[2]) || NAN(param_1[2])) << 10) >> 8) |
                (byte)((ushort)((ushort)(param_2[2] == param_1[2]) << 0xe) >> 8)) != 0x40)) break;
      fVar2 = param_1[3];
      fVar3 = param_2[3];
      if ((byte)(fVar3 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) != 0x40) {
        return 0;
      }
      param_2 = param_2 + 4;
      param_1 = param_1 + 4;
    }
  }
  return 0;
}


// VectorInverse  @ 00061cd8
void VectorInverse(float *param_1)

{
  *param_1 = -*param_1;
  param_1[1] = -param_1[1];
  param_1[2] = -param_1[2];
  return;
}


// VectorMA  @ 00061af4
void VectorMA(float *param_1,float param_2,float *param_3,float *param_4)

{
  *param_4 = param_2 * *param_3 + *param_1;
  param_4[1] = param_2 * param_3[1] + param_1[1];
  param_4[2] = param_2 * param_3[2] + param_1[2];
  return;
}


// VectorMatrix  @ 00061d34
void VectorMatrix(float *param_1,undefined4 *param_2,float *param_3)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (((byte)((byte)((ushort)((ushort)NAN(*param_1) << 10) >> 8) |
             (byte)((ushort)((ushort)(*param_1 == 0.0) << 0xe) >> 8)) == 0x40) &&
     ((byte)((byte)((ushort)((ushort)NAN(param_1[1]) << 10) >> 8) |
            (byte)((ushort)((ushort)(param_1[1] == 0.0) << 0xe) >> 8)) == 0x40)) {
    *param_2 = 0x3f800000;
    param_2[1] = 0;
    param_2[2] = 0;
    *param_3 = -param_1[2];
    param_3[1] = 0.0;
    param_3[2] = 0.0;
  }
  else {
    local_10 = 0;
    local_c = 0;
    local_8 = 0x3f800000;
    CrossProduct(param_1,&local_10,param_2);
    VectorNormalize(param_2);
    CrossProduct(param_2,param_1,param_3);
    VectorNormalize(param_3);
  }
  return;
}


// VectorNormalize  @ 00061c7c
longdouble VectorNormalize(float *param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  
  lVar1 = (longdouble)*param_1;
  lVar2 = (longdouble)param_1[1];
  lVar3 = (longdouble)param_1[2];
  lVar4 = (longdouble)(float)SQRT(lVar3 * lVar3 + lVar2 * lVar2 + lVar1 * lVar1);
  lVar5 = (longdouble)0;
  if ((byte)(lVar5 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar5) || NAN(lVar4)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar5 == lVar4) << 0xe) >> 8)) != 0x40) {
    lVar5 = (longdouble)1 / lVar4;
    *param_1 = (float)(lVar1 * lVar5);
    param_1[1] = (float)(lVar2 * lVar5);
    param_1[2] = (float)(lVar5 * lVar3);
  }
  return lVar4;
}


// VectorScale  @ 00061cf8
void VectorScale(float *param_1,float param_2,float *param_3)

{
  *param_3 = *param_1 * param_2;
  param_3[1] = param_1[1] * param_2;
  param_3[2] = param_2 * param_1[2];
  return;
}


// VectorTransform  @ 000619bc
void VectorTransform(float *param_1,float *param_2,float *param_3)

{
  *param_3 = param_1[2] * param_2[2] + param_1[1] * param_2[1] + *param_1 * *param_2 + param_2[3];
  param_3[1] = param_1[2] * param_2[6] + param_1[1] * param_2[5] + *param_1 * param_2[4] +
               param_2[7];
  param_3[2] = param_1[2] * param_2[10] + param_1[1] * param_2[9] + *param_1 * param_2[8] +
               param_2[0xb];
  return;
}


// anglemod  @ 00061378
longdouble anglemod(float param_1)

{
  return (longdouble)((float)((int)ROUND(param_1 * 182.04445) & 0xffff) * 0.005493164);
}


// filelength  @ 00092330
long filelength(FILE *param_1)

{
  long __off;
  long lVar1;
  
  __off = ftell(param_1);
  fseek(param_1,0,2);
  lVar1 = ftell(param_1);
  fseek(param_1,__off,0);
  return lVar1;
}


// findhandle  @ 0009226c
int findhandle(void)

{
  int iVar1;
  
  if (sys_handles._4_4_ == 0) {
    iVar1 = 1;
  }
  else if (sys_handles._8_4_ == 0) {
    iVar1 = 2;
  }
  else if (sys_handles._12_4_ == 0) {
    iVar1 = 3;
  }
  else {
    iVar1 = 4;
    do {
      if (*(int *)(sys_handles + iVar1 * 4) == 0) {
        return iVar1;
      }
      if (*(int *)(sys_handles + (iVar1 + 1) * 4) == 0) {
        return iVar1 + 1;
      }
      if (*(int *)(sys_handles + (iVar1 + 2) * 4) == 0) {
        return iVar1 + 2;
      }
      if (*(int *)(sys_handles + (iVar1 + 3) * 4) == 0) {
        return iVar1 + 3;
      }
      iVar1 = iVar1 + 4;
    } while (iVar1 < 0x80);
    Sys_Error("out of handles");
    iVar1 = -1;
  }
  return iVar1;
}


// fran1  @ 000709f8
longdouble fran1(void)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = ran1();
  lVar2 = (longdouble)((float)iVar1 * 4.656613e-10);
  if ((longdouble)0.99999988 < lVar2) {
    lVar2 = (longdouble)0.9999999;
  }
  return lVar2;
}


// iGetIndex  @ 0006dd38
int iGetIndex(undefined4 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 local_4a8 [4];
  undefined1 local_4a4 [180];
  undefined1 local_3f0 [4];
  undefined1 local_3ec [4];
  undefined1 local_3e8 [264];
  undefined1 local_2e0 [4];
  undefined1 local_2dc [4];
  undefined1 local_2d8 [4];
  undefined1 local_2d4 [20];
  undefined1 local_2c0 [4];
  undefined1 local_2bc [4];
  undefined1 local_2b8 [4];
  undefined1 local_2b4 [176];
  undefined1 local_204 [512];
  
  Q_strcpy(local_204,param_1);
  Q_strlwr(local_204);
  iVar1 = Q_strcmp(local_204,"classname");
  if (iVar1 == 0) {
    puVar2 = local_4a8;
  }
  else {
    iVar1 = Q_strcmp(local_204,"model");
    if (iVar1 == 0) {
      puVar2 = local_3f0;
    }
    else {
      iVar1 = Q_strcmp(local_204,"viewmodel");
      if (iVar1 == 0) {
        puVar2 = local_3ec;
      }
      else {
        iVar1 = Q_strcmp(local_204,"weaponmodel");
        if (iVar1 == 0) {
          puVar2 = local_3e8;
        }
        else {
          iVar1 = Q_strcmp(local_204,"netname");
          if (iVar1 == 0) {
            puVar2 = local_2d8;
          }
          else {
            iVar1 = Q_strcmp(local_204,"target");
            if (iVar1 == 0) {
              puVar2 = local_2e0;
            }
            else {
              iVar1 = Q_strcmp(local_204,"targetname");
              if (iVar1 == 0) {
                puVar2 = local_2dc;
              }
              else {
                iVar1 = Q_strcmp(local_204,"message");
                if (iVar1 == 0) {
                  puVar2 = local_2d4;
                }
                else {
                  iVar1 = Q_strcmp(local_204,"noise");
                  if (iVar1 == 0) {
                    puVar2 = local_2c0;
                  }
                  else {
                    iVar1 = Q_strcmp(local_204,"noise1");
                    if (iVar1 == 0) {
                      puVar2 = local_2bc;
                    }
                    else {
                      iVar1 = Q_strcmp(local_204,"noise2");
                      if (iVar1 == 0) {
                        puVar2 = local_2b8;
                      }
                      else {
                        iVar1 = Q_strcmp(local_204,"noise3");
                        if (iVar1 == 0) {
                          puVar2 = local_2b4;
                        }
                        else {
                          iVar1 = Q_strcmp(local_204,"globalname");
                          if (iVar1 != 0) {
                            return -1;
                          }
                          puVar2 = local_4a4;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return (int)puVar2 - (int)local_4a8;
}


// memfgets  @ 00088660
int memfgets(int param_1,int param_2,int *param_3,int param_4,int param_5)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *param_3;
  if (((param_1 != 0) && (param_4 != 0)) && (iVar1 < param_2)) {
    if (param_5 + -1 < param_2 - iVar1) {
      param_2 = param_5 + -1 + iVar1;
    }
    bVar2 = false;
    iVar3 = iVar1;
    if (iVar1 < param_2) {
      do {
        if (*(char *)(iVar3 + param_1) == '\n') {
          bVar2 = true;
        }
        iVar3 = iVar3 + 1;
      } while ((iVar3 < param_2) && (!bVar2));
    }
    if (iVar3 != iVar1) {
      iVar4 = iVar3 - iVar1;
      Q_memcpy(param_4,param_1 + iVar1,iVar4);
      if (iVar4 < param_5) {
        *(undefined1 *)(iVar4 + param_4) = 0;
      }
      *param_3 = iVar3;
      return param_4;
    }
  }
  return 0;
}


// memsearch  @ 0004bd6c
int memsearch(byte *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < (int)param_2) {
    uVar1 = param_2 & 3;
    if (uVar1 != 0) {
      if (1 < uVar1) {
        if (2 < uVar1) {
          if (*param_1 == param_3) {
            return 0;
          }
          iVar2 = 1;
        }
        if (param_1[iVar2] == param_3) {
          return iVar2;
        }
        iVar2 = iVar2 + 1;
      }
      if (param_1[iVar2] == param_3) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      if ((int)param_2 <= iVar2) {
        return -1;
      }
    }
    do {
      if (param_1[iVar2] == param_3) {
        return iVar2;
      }
      if (param_1[iVar2 + 1] == param_3) {
        return iVar2 + 1;
      }
      if (param_1[iVar2 + 2] == param_3) {
        return iVar2 + 2;
      }
      if (param_1[iVar2 + 3] == param_3) {
        return iVar2 + 3;
      }
      iVar2 = iVar2 + 4;
    } while (iVar2 < (int)param_2);
  }
  return -1;
}


// ran1  @ 00070844
undefined4 ran1(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((idum < 1) || (iy_252 == 0)) {
    idum = -idum;
    if (idum < 1) {
      idum = 1;
    }
    iVar2 = 0x27;
    do {
      idum = (idum % 0x1f31d) * 0x41a7 + (idum / 0x1f31d) * -0xb14;
      if (idum < 0) {
        idum = idum + 0x7fffffff;
      }
      if (iVar2 < 0x20) {
        (&iv_253)[iVar2] = idum;
      }
      iVar2 = iVar2 + -1;
    } while (-1 < iVar2);
    iy_252 = iv_253;
  }
  idum = (idum % 0x1f31d) * 0x41a7 + (idum / 0x1f31d) * -0xb14;
  if (idum < 0) {
    idum = idum + 0x7fffffff;
  }
  if (iy_252 < 0) {
    iy_252 = iy_252 + 0x3ffffff;
  }
  iVar2 = iy_252 >> 0x1a;
  uVar1 = (&iv_253)[iVar2];
  iy_252 = uVar1;
  (&iv_253)[iVar2] = idum;
  return uVar1;
}


// va  @ 0004bcd0
undefined1 * va(char *param_1)

{
  vsprintf(string_226,param_1,&stack0x00000008);
  return string_226;
}


// vstr  @ 0004bd00
undefined1 * vstr(float *param_1)

{
  idx_229 = idx_229 + 1 & 0xf;
  sprintf(string_230 + idx_229 * 0x400,"%.4f %.4f %.4f",(double)*param_1,(double)param_1[1],
          (double)param_1[2]);
  return string_230 + idx_229 * 0x400;
}


