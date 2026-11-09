// .LFB15  @ 0809e550
uint _LFB15(int *param_1,int *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  bool bVar7;
  
  if (*(uint *)(*param_1 + -0x10) < param_3) {
    __out_of_range__FPCc("pos > length ()");
  }
  uVar3 = *(int *)(*param_1 + -0x10) - param_3;
  if (param_4 < uVar3) {
    uVar3 = param_4;
  }
  if (*(uint *)(*param_2 + -0x10) < uVar3) {
    uVar3 = *(uint *)(*param_2 + -0x10);
  }
  bVar6 = false;
  uVar1 = 0;
  bVar7 = true;
  uVar2 = uVar3;
  pbVar4 = (byte *)(param_3 + *param_1);
  pbVar5 = (byte *)*param_2;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    bVar6 = *pbVar4 < *pbVar5;
    bVar7 = *pbVar4 == *pbVar5;
    pbVar4 = pbVar4 + 1;
    pbVar5 = pbVar5 + 1;
  } while (bVar7);
  if (!bVar7) {
    uVar1 = -(uint)bVar6 | 1;
  }
  if (uVar1 == 0) {
    if (uVar3 == param_4) {
      uVar1 = 0;
    }
    else {
      uVar1 = (*(int *)(*param_1 + -0x10) - param_3) - *(int *)(*param_2 + -0x10);
    }
  }
  return uVar1;
}


// .LFB21  @ 0809dfd0
size_t * _LFB21(size_t *param_1)

{
  int iVar1;
  uint uVar2;
  size_t *psVar3;
  uint __size;
  
  uVar2 = 0x10;
  if (0x10 < *param_1 + 1) {
    do {
      uVar2 = uVar2 * 2;
    } while (uVar2 < *param_1 + 1);
  }
  __size = uVar2 + 0x10;
  if (__size < 0x81) {
    iVar1 = (uVar2 + 0x17 >> 3) * 4;
    pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    psVar3 = *(size_t **)(&DAT_080ab95c + iVar1);
    if (psVar3 == (size_t *)0x0) {
      psVar3 = (size_t *)refill__t24__default_alloc_template2b1i0Ui(uVar2 + 0x10);
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
    else {
      *(size_t *)(&DAT_080ab95c + iVar1) = *psVar3;
      pthread_mutex_unlock
                ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
    }
  }
  else {
    psVar3 = malloc(__size);
    if (psVar3 == (size_t *)0x0) {
      psVar3 = (size_t *)oom_malloc__t23__malloc_alloc_template1i0Ui(__size);
    }
  }
  psVar3[1] = uVar2;
  psVar3[2] = 1;
  *(undefined1 *)(psVar3 + 3) = 0;
  if (*param_1 != 0) {
    memcpy(psVar3 + 4,param_1 + 4,*param_1);
  }
  *psVar3 = *param_1;
  return psVar3 + 4;
}


// .LFB22  @ 0809e110
int * _LFB22(int *param_1,uint param_2,uint param_3,void *param_4,size_t param_5)

{
  undefined4 *__ptr;
  int *piVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  undefined4 *puVar5;
  uint uVar6;
  size_t sVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  
  uVar2 = *(uint *)(*param_1 + -0x10);
  if (uVar2 < param_2) {
    __out_of_range__FPCc("pos > len");
  }
  if (uVar2 - param_2 < param_3) {
    param_3 = uVar2 - param_2;
  }
  if (-param_5 - 2 < uVar2 - param_3) {
    __length_error__FPCc("len - n1 > max_size () - n2");
  }
  iVar9 = (uVar2 - param_3) + param_5;
  uVar6 = iVar9 + 1;
  *(undefined1 *)(*param_1 + -4) = 0;
  bVar4 = false;
  if ((*(uint *)(*param_1 + -8) < 2) && (uVar8 = *(uint *)(*param_1 + -0xc), uVar6 <= uVar8)) {
    if (uVar6 < 0x11) {
      bVar10 = 0x20 < uVar8;
    }
    else {
      bVar10 = uVar6 * 2 < uVar8;
    }
    if (!bVar10) goto LAB_0809e1bc;
  }
  bVar4 = true;
LAB_0809e1bc:
  if (bVar4) {
    uVar6 = 0x10;
    if (0x10 < iVar9 + 1U) {
      do {
        uVar6 = uVar6 * 2;
      } while (uVar6 < iVar9 + 1U);
    }
    uVar8 = uVar6 + 0x10;
    if (uVar8 < 0x81) {
      iVar3 = (uVar6 + 0x17 >> 3) * 4;
      pthread_mutex_lock((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock)
      ;
      puVar5 = *(undefined4 **)(&DAT_080ab95c + iVar3);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)refill__t24__default_alloc_template2b1i0Ui(uVar8);
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
      }
      else {
        *(undefined4 *)(&DAT_080ab95c + iVar3) = *puVar5;
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
      }
    }
    else {
      puVar5 = malloc(uVar8);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)oom_malloc__t23__malloc_alloc_template1i0Ui(uVar8);
      }
    }
    puVar5[1] = uVar6;
    puVar5[2] = 1;
    *(undefined1 *)(puVar5 + 3) = 0;
    if (param_2 != 0) {
      memcpy(puVar5 + 4,(void *)*param_1,param_2);
    }
    sVar7 = uVar2 - (param_2 + param_3);
    if (sVar7 != 0) {
      memcpy((void *)(param_2 + param_5 + 0x10 + (int)puVar5),(void *)(param_2 + *param_1 + param_3)
             ,sVar7);
    }
    if (param_5 != 0) {
      memcpy((void *)(param_2 + 0x10 + (int)puVar5),param_4,param_5);
    }
    iVar3 = *param_1;
    __ptr = (undefined4 *)(iVar3 + -0x10);
    piVar1 = (int *)(iVar3 + -8);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      if (*(int *)(iVar3 + -0xc) + 0x10U < 0x81) {
        iVar3 = (*(int *)(iVar3 + -0xc) + 0x17U >> 3) * 4;
        pthread_mutex_lock((pthread_mutex_t *)
                           _t24__default_alloc_template2b1i0___node_allocator_lock);
        *__ptr = *(undefined4 *)(&DAT_080ab95c + iVar3);
        *(undefined4 **)(&DAT_080ab95c + iVar3) = __ptr;
        pthread_mutex_unlock
                  ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
      }
      else {
        free(__ptr);
      }
    }
    *param_1 = (int)(puVar5 + 4);
  }
  else {
    sVar7 = uVar2 - (param_2 + param_3);
    if (sVar7 != 0) {
      memmove((void *)(param_2 + param_5 + *param_1),(void *)(param_2 + *param_1 + param_3),sVar7);
    }
    if (param_5 != 0) {
      memcpy((void *)(*param_1 + param_2),param_4,param_5);
    }
  }
  *(int *)(*param_1 + -0x10) = iVar9;
  return param_1;
}


// .LFB45  @ 0809e430
int * _LFB45(int *param_1,int param_2,uint param_3,int *param_4,uint param_5,uint param_6)

{
  undefined4 *__ptr;
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  uVar1 = *(uint *)(*param_4 + -0x10);
  if (param_2 == 0) {
    iVar2 = *param_1;
    __ptr = (undefined4 *)(iVar2 + -0x10);
    if (((*(uint *)(iVar2 + -0x10) <= param_3) && (param_5 == 0)) && (uVar1 <= param_6)) {
      if (param_4 == param_1) {
        return param_1;
      }
      piVar3 = (int *)(iVar2 + -8);
      *piVar3 = *piVar3 + -1;
      if (*piVar3 == 0) {
        if (*(int *)(iVar2 + -0xc) + 0x10U < 0x81) {
          iVar2 = (*(int *)(iVar2 + -0xc) + 0x17U >> 3) * 4;
          pthread_mutex_lock((pthread_mutex_t *)
                             _t24__default_alloc_template2b1i0___node_allocator_lock);
          *__ptr = *(undefined4 *)(&DAT_080ab95c + iVar2);
          *(undefined4 **)(&DAT_080ab95c + iVar2) = __ptr;
          pthread_mutex_unlock
                    ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
        }
        else {
          free(__ptr);
        }
      }
      iVar2 = *param_4;
      if (*(char *)(iVar2 + -4) == '\0') {
        *(int *)(iVar2 + -8) = *(int *)(iVar2 + -8) + 1;
      }
      else {
        iVar2 = clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                          (iVar2 + -0x10);
      }
      *param_1 = iVar2;
      return param_1;
    }
  }
  if (uVar1 < param_5) {
    __out_of_range__FPCc("pos2 > len2");
  }
  if (uVar1 - param_5 < param_6) {
    param_6 = uVar1 - param_5;
  }
  piVar3 = (int *)replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
                            (param_1,param_2,param_3,*param_4 + param_5,param_6);
  return piVar3;
}


// AddAnimatingTextures  @ 08081550
void AddAnimatingTextures(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_2c;
  char local_24;
  char local_23;
  
  iVar1 = nummiptex;
  local_2c = 0;
  if (0 < nummiptex) {
    do {
      if ((miptex[local_2c * 0x40] == '+') || (miptex[local_2c * 0x40] == '-')) {
        strcpy(&local_24,miptex + local_2c * 0x40);
        iVar4 = 0;
        do {
          if (iVar4 < 10) {
            local_23 = (char)iVar4 + '0';
          }
          else {
            local_23 = (char)iVar4 + '7';
          }
          iVar3 = 0;
          if (0 < nTexLumps) {
            do {
              iVar2 = strcmp(&local_24,(char *)(lumpinfo + 0x10 + iVar3 * 0x24));
              if (iVar2 == 0) {
                FindMiptex(&local_24);
                break;
              }
              iVar3 = iVar3 + 1;
            } while (iVar3 < nTexLumps);
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < 0x14);
      }
      local_2c = local_2c + 1;
    } while (local_2c < iVar1);
  }
  if (nummiptex != iVar1) {
    Con_DPrintf("added %i texture frames\n",nummiptex - iVar1);
  }
  return;
}


// AddLinksToPmove  @ 0807ea80
void AddLinksToPmove(int *param_1)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  
  piVar3 = (int *)param_1[7];
  do {
    do {
      do {
        do {
          piVar5 = piVar3;
          if (piVar5 == param_1 + 6) {
            if (*param_1 != -1) {
              if ((float)param_1[1] < (float)(&pmove_maxs)[*param_1]) {
                AddLinksToPmove(param_1[2]);
              }
              fVar1 = (float)(&pmove_mins)[*param_1];
              fVar2 = (float)param_1[1];
              if ((byte)(fVar1 < fVar2 |
                         (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
                AddLinksToPmove(param_1[3]);
              }
            }
            return;
          }
          piVar3 = (int *)piVar5[1];
        } while (((((int *)piVar5[0x93] == sv_player) ||
                  ((((piVar5[0x70] != 4 && (piVar5[0x70] != 2)) && (piVar5[0x70] != 3)) &&
                   (piVar5[0x70] != 0)))) ||
                 ((piVar5[0x70] == 0 && ((piVar5[0x71] == 0 || (piVar5[0x5a] == 0)))))) ||
                ((((*(byte *)((int)piVar5 + 0x25a) & 0x80) != 0 && (piVar5[0x70] == 4)) ||
                 (piVar5 + -2 == sv_player))));
        iVar4 = 0;
        while ((float)piVar5[iVar4 + 0x5e] <= (float)(&pmove_maxs)[iVar4]) {
          fVar1 = (float)piVar5[iVar4 + 0x61];
          fVar2 = (float)(&pmove_mins)[iVar4];
          if (((byte)(fVar1 < fVar2 |
                      (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) ||
             (iVar4 = iVar4 + 1, 2 < iVar4)) break;
        }
      } while (iVar4 != 3);
      if (599 < DAT_081051e4) goto LAB_0807ebb3;
    } while ((*(byte *)((int)piVar5 + 0x25b) & 4) != 0);
    if ((piVar5[0x70] == 0) && (piVar5[0x71] == -0x10)) {
      if (0x10 < DAT_08112028) {
LAB_0807ebb3:
        Con_DPrintf("Too many physents on server playermove link adding...\n");
        return;
      }
      piVar6 = (int *)(&DAT_0811202c + DAT_08112028 * 0x58);
      DAT_08112028 = DAT_08112028 + 1;
    }
    else {
      piVar6 = &DAT_081051e8 + DAT_081051e4 * 0x16;
      DAT_081051e4 = DAT_081051e4 + 1;
    }
    *piVar6 = piVar5[0x37];
    piVar6[1] = piVar5[0x38];
    piVar6[2] = piVar5[0x39];
    piVar6[0xc] = piVar5[0x49];
    piVar6[0xd] = piVar5[0x4a];
    piVar6[0xe] = piVar5[0x4b];
    iVar4 = NUM_FOR_EDICT(piVar5 + -2);
    piVar6[0xb] = iVar4;
    piVar6[4] = 0;
    piVar6[0x11] = piVar5[0x7f];
    if (piVar5[0x70] == 4) {
LAB_0807ec74:
      piVar6[3] = (&DAT_0813e330)[piVar5[0x5a]];
    }
    else if (piVar5[0x70] == 0) {
      if (piVar5[0x5a] != 0) goto LAB_0807ec74;
      piVar6[3] = 0;
    }
    else {
      if (piVar5[0x70] == 2) {
        piVar6[3] = 0;
        if (piVar5[0x5a] == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = (&DAT_0813e330)[piVar5[0x5a]];
        }
        if ((iVar4 != 0) && ((*(byte *)(iVar4 + 0x51) & 2) != 0)) {
          piVar6[4] = iVar4;
        }
      }
      else {
        piVar6[3] = 0;
      }
      piVar6[5] = piVar5[100];
      piVar6[6] = piVar5[0x65];
      piVar6[7] = piVar5[0x66];
      piVar6[8] = piVar5[0x67];
      piVar6[9] = piVar5[0x68];
      piVar6[10] = piVar5[0x69];
    }
    piVar6[0xf] = piVar5[0x70];
    piVar6[0x10] = piVar5[0x71];
    piVar6[0x12] = piVar5[0x79];
    piVar6[0x13] = piVar5[0x77];
    piVar6[0x14] = piVar5[0x7c];
    *(short *)(piVar6 + 0x15) = (short)piVar5[0x7d];
  } while( true );
}


// AlertMessage  @ 080891b0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AlertMessage(int param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  if ((param_1 == 5) && (1 < svs)) {
    vsprintf(&szOut_235,param_2,&stack0x0000000c);
    Log_Printf(&DAT_080a7263,&szOut_235);
  }
  else if ((byte)(0.0 < (float)developer._12_4_ |
                  (byte)((ushort)((ushort)NAN((float)developer._12_4_) << 10) >> 8) |
                 (byte)((ushort)((ushort)((float)developer._12_4_ == 0.0) << 0xe) >> 8)) != 0x40) {
    switch(param_1) {
    case 0:
      szOut_235 = 'N';
      DAT_080c88a1 = 'O';
      szOut_235_1._1_1_ = 'T';
      szOut_235_1._2_1_ = 'E';
      DAT_080c88a4._0_1_ = ':';
      DAT_080c88a4._1_1_ = ' ';
      DAT_080c88a4._2_1_ = ' ';
      DAT_080c88a4._3_1_ = '\0';
      break;
    case 2:
      if ((float)developer._12_4_ < 2.0) {
        return;
      }
    case 1:
      _szOut_235 = _szOut_235 & 0xffffff00;
      break;
    case 3:
      szOut_235 = 'W';
      DAT_080c88a1 = 'A';
      szOut_235_1._1_1_ = 'R';
      szOut_235_1._2_1_ = 'N';
      DAT_080c88a4._0_1_ = 'I';
      DAT_080c88a4._1_1_ = 'N';
      DAT_080c88a4._2_1_ = 'G';
      DAT_080c88a4._3_1_ = ':';
      DAT_080c88a8._0_1_ = ' ';
      DAT_080c88a8._1_1_ = ' ';
      DAT_080c88aa = '\0';
      break;
    case 4:
      szOut_235 = 'E';
      DAT_080c88a1 = 'R';
      szOut_235_1._1_1_ = 'R';
      szOut_235_1._2_1_ = 'O';
      DAT_080c88a4._0_1_ = 'R';
      DAT_080c88a4._1_1_ = ':';
      DAT_080c88a4._2_1_ = ' ';
      DAT_080c88a4._3_1_ = ' ';
      DAT_080c88a8 = DAT_080c88a8 & 0xff00;
    }
    uVar2 = 0xffffffff;
    pcVar3 = &szOut_235;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    vsprintf(szOut_232 + ~uVar2 + 0x3ff,param_2,&stack0x0000000c);
    Con_Printf(&szOut_235);
  }
  return;
}


// AllocEngineString  @ 08070200
int AllocEngineString(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ED_NewString(param_1);
  return iVar1 - pr_strings;
}


// AngleIMatrix  @ 08061cf0
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
  param_2[5] = fVar6 * fVar2 + fVar5 * fVar3 * fVar1;
  param_2[6] = fVar4 * fVar5;
  param_2[8] = fVar3 * fVar6 * fVar2 + -fVar1 * -fVar5;
  param_2[9] = fVar3 * fVar6 * fVar1 + -fVar5 * fVar2;
  param_2[10] = fVar6 * fVar4;
  param_2[3] = 0.0;
  param_2[7] = 0.0;
  param_2[0xb] = 0.0;
  return;
}


// AngleMatrix  @ 08061c00
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
  param_2[5] = fVar6 * fVar2 + fVar5 * fVar3 * fVar1;
  param_2[9] = fVar4 * fVar5;
  param_2[2] = fVar3 * fVar6 * fVar2 + -fVar1 * -fVar5;
  param_2[6] = fVar3 * fVar6 * fVar1 + -fVar5 * fVar2;
  param_2[10] = fVar6 * fVar4;
  param_2[3] = 0.0;
  param_2[7] = 0.0;
  param_2[0xb] = 0.0;
  return;
}


// AngleQuaternion  @ 0805fc40
void AngleQuaternion(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  longdouble lVar5;
  longdouble lVar6;
  longdouble lVar7;
  longdouble lVar8;
  
  lVar5 = (longdouble)fsin((longdouble)(param_1[2] * 0.5));
  fVar1 = (float)lVar5;
  lVar5 = (longdouble)fcos((longdouble)(param_1[2] * 0.5));
  fVar2 = (float)lVar5;
  lVar5 = (longdouble)fsin((longdouble)(param_1[1] * 0.5));
  lVar6 = (longdouble)fcos((longdouble)(param_1[1] * 0.5));
  lVar7 = (longdouble)fsin((longdouble)(*param_1 * 0.5));
  lVar8 = (longdouble)fcos((longdouble)(*param_1 * 0.5));
  fVar3 = (float)lVar7 * (float)lVar6;
  fVar4 = (float)lVar5 * (float)lVar8;
  *param_2 = fVar3 * fVar2 - fVar1 * fVar4;
  param_2[1] = fVar3 * fVar1 + fVar4 * fVar2;
  fVar4 = (float)lVar8 * (float)lVar6;
  fVar3 = (float)lVar7 * (float)lVar5;
  param_2[2] = fVar1 * fVar4 - fVar3 * fVar2;
  param_2[3] = fVar3 * fVar1 + fVar4 * fVar2;
  return;
}


// AngleVectors  @ 080619f0
void AngleVectors(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  longdouble lVar8;
  longdouble lVar9;
  
  lVar8 = (longdouble)fsin((longdouble)(param_1[1] * 0.017453292));
  fVar1 = (float)lVar8;
  lVar8 = (longdouble)fcos((longdouble)(param_1[1] * 0.017453292));
  fVar2 = (float)lVar8;
  lVar8 = (longdouble)fsin((longdouble)(*param_1 * 0.017453292));
  fVar3 = (float)lVar8;
  lVar8 = (longdouble)fcos((longdouble)(*param_1 * 0.017453292));
  fVar4 = (float)lVar8;
  lVar8 = (longdouble)fsin((longdouble)(param_1[2] * 0.017453292));
  lVar9 = (longdouble)fcos((longdouble)(param_1[2] * 0.017453292));
  fVar5 = (float)lVar9;
  if (param_2 != (float *)0x0) {
    *param_2 = fVar4 * fVar2;
    param_2[1] = fVar4 * fVar1;
    param_2[2] = -fVar3;
  }
  if (param_3 != (float *)0x0) {
    fVar7 = -(float)lVar8;
    fVar6 = fVar3 * fVar7;
    *param_3 = -fVar1 * -fVar5 + fVar6 * fVar2;
    param_3[1] = -fVar5 * fVar2 + fVar6 * fVar1;
    param_3[2] = fVar7 * fVar4;
  }
  if (param_4 != (float *)0x0) {
    fVar6 = -(float)lVar8;
    *param_4 = -fVar1 * fVar6 + fVar5 * fVar3 * fVar2;
    param_4[1] = fVar6 * fVar2 + fVar5 * fVar3 * fVar1;
    param_4[2] = fVar5 * fVar4;
  }
  return;
}


// AngleVectorsTranspose  @ 08061af0
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
    param_4[1] = fVar4 * fVar5;
    param_4[2] = fVar4 * fVar6;
  }
  return;
}


// AnimationAutomove  @ 08061570
void AnimationAutomove(void)

{
  return;
}


// BoxOnPlaneSide  @ 080617c0
byte BoxOnPlaneSide(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  float local_c;
  float local_8;
  
  switch(*(undefined1 *)((int)param_3 + 0x11)) {
  case 0:
    local_c = param_3[2];
    local_8 = local_c * param_2[2] + param_3[1] * param_2[1] + *param_3 * *param_2;
    fVar2 = *param_3 * *param_1;
    fVar1 = param_3[1] * param_1[1];
    break;
  case 1:
    local_c = param_3[2];
    local_8 = local_c * param_2[2] + param_3[1] * param_2[1] + *param_3 * *param_1;
    fVar2 = *param_3 * *param_2;
    fVar1 = param_3[1] * param_1[1];
    break;
  case 2:
    fVar1 = param_3[1];
    local_c = param_3[2];
    local_8 = local_c * param_2[2] + fVar1 * param_1[1] + *param_3 * *param_2;
    fVar2 = *param_3 * *param_1;
    goto LAB_080618b7;
  case 3:
    fVar1 = param_3[1];
    local_c = param_3[2];
    local_8 = local_c * param_2[2] + fVar1 * param_1[1] + *param_3 * *param_1;
    fVar2 = *param_3 * *param_2;
LAB_080618b7:
    fVar1 = fVar1 * param_2[1];
    break;
  case 4:
    fVar1 = param_3[1];
    local_c = param_3[2];
    local_8 = local_c * param_1[2] + fVar1 * param_2[1] + *param_3 * *param_2;
    fVar2 = *param_3 * *param_1;
    goto LAB_08061927;
  case 5:
    fVar1 = param_3[1];
    local_c = param_3[2];
    local_8 = local_c * param_1[2] + fVar1 * param_2[1] + *param_3 * *param_1;
    fVar2 = *param_3 * *param_2;
LAB_08061927:
    fVar1 = fVar1 * param_1[1];
LAB_0806198c:
    fVar1 = fVar1 + fVar2;
    local_c = local_c * param_2[2];
    goto LAB_08061993;
  case 6:
    fVar1 = param_3[1];
    local_c = param_3[2];
    local_8 = local_c * param_1[2] + fVar1 * param_1[1] + *param_3 * *param_2;
    fVar2 = *param_3 * *param_1;
    goto LAB_08061987;
  case 7:
    fVar1 = param_3[1];
    local_c = param_3[2];
    local_8 = local_c * param_1[2] + fVar1 * param_1[1] + *param_3 * *param_1;
    fVar2 = *param_3 * *param_2;
LAB_08061987:
    fVar1 = fVar1 * param_2[1];
    goto LAB_0806198c;
  default:
    local_c = 0.0;
    local_8 = 0.0;
    BOPS_Error();
    goto LAB_080619b3;
  }
  fVar1 = fVar1 + fVar2;
  local_c = local_c * param_1[2];
LAB_08061993:
  local_c = local_c + fVar1;
LAB_080619b3:
  bVar3 = param_3[3] <= local_8;
  fVar1 = param_3[3];
  if ((byte)(local_c < fVar1 | (byte)((ushort)((ushort)(NAN(local_c) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(local_c == fVar1) << 0xe) >> 8)) == 1) {
    bVar3 = bVar3 | 2;
  }
  return bVar3;
}


// CVarGetFloat  @ 08070170
void CVarGetFloat(undefined4 param_1)

{
  Cvar_VariableValue(param_1);
  return;
}


// CVarGetPointer  @ 08070190
void CVarGetPointer(undefined4 param_1)

{
  Cvar_FindVar(param_1);
  return;
}


// CVarGetString  @ 08070180
void CVarGetString(undefined4 param_1)

{
  Cvar_VariableString(param_1);
  return;
}


// CVarRegister  @ 080701e0
void CVarRegister(int param_1)

{
  if (param_1 != 0) {
    *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) | 8;
    Cvar_RegisterVariable(param_1);
  }
  return;
}


// CVarSetFloat  @ 080701a0
void CVarSetFloat(undefined4 param_1,undefined4 param_2)

{
  Cvar_SetValue(param_1,param_2);
  return;
}


// CVarSetString  @ 080701c0
void CVarSetString(undefined4 param_1,undefined4 param_2)

{
  Cvar_Set(param_1,param_2);
  return;
}


// CacheSystemCompare  @ 08087090
void CacheSystemCompare(int *param_1,int *param_2)

{
  strcasecmp((char *)(*param_1 + 8),(char *)(*param_2 + 8));
  return;
}


// CalcSurfaceExtents  @ 08063820
void CalcSurfaceExtents(int param_1)

{
  float *pfVar1;
  float fVar2;
  ushort uVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ushort in_FPUControlWord;
  int local_34 [4];
  float local_24 [6];
  ushort local_c;
  undefined2 uStack_a;
  ushort local_8;
  
  iVar9 = loadmodel;
  local_24[3] = 999999.0;
  local_24[2] = 999999.0;
  local_24[1] = -99999.0;
  local_24[0] = -99999.0;
  iVar4 = *(int *)(param_1 + 0x34);
  iVar8 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    do {
      iVar6 = *(int *)(*(int *)(iVar9 + 0xbc) + (iVar8 + *(int *)(param_1 + 0x14)) * 4);
      if (iVar6 < 0) {
        uVar3 = *(ushort *)(*(int *)(iVar9 + 0x9c) + 2 + iVar6 * -8);
      }
      else {
        uVar3 = *(ushort *)(*(int *)(iVar9 + 0x9c) + iVar6 * 8);
      }
      pfVar1 = (float *)(*(int *)(iVar9 + 0x94) + (uint)uVar3 * 0xc);
      iVar6 = 0;
      do {
        iVar7 = iVar6 * 0x10;
        fVar5 = pfVar1[2] * *(float *)(iVar7 + iVar4 + 8) +
                pfVar1[1] * *(float *)(iVar7 + iVar4 + 4) + *pfVar1 * *(float *)(iVar7 + iVar4) +
                *(float *)(iVar7 + iVar4 + 0xc);
        fVar2 = local_24[iVar6 + 2];
        if ((byte)(fVar5 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar5) || NAN(fVar2)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar5 == fVar2) << 0xe) >> 8)) == 1) {
          local_24[iVar6 + 2] = fVar5;
        }
        if (local_24[iVar6] < fVar5) {
          local_24[iVar6] = fVar5;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < 2);
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(param_1 + 0x18));
  }
  iVar9 = 0;
  do {
    local_34[iVar9 + 2] = (int)ROUND(ROUND(local_24[iVar9 + 2] * 0.0625));
    local_8 = in_FPUControlWord & 0xf3ff | 0x800;
    _local_c = CONCAT22(uStack_a,in_FPUControlWord);
    local_24[4] = (float)CONCAT22(uStack_a,CONCAT11(0xc,(char)in_FPUControlWord));
    local_34[iVar9] = (int)ROUND(ROUND(local_24[iVar9] * 0.0625));
    iVar8 = iVar9 * 2;
    *(short *)(iVar8 + 0x2c + param_1) = (short)local_34[iVar9 + 2] << 4;
    *(short *)(iVar8 + param_1 + 0x30) =
         ((short)local_34[iVar9] - (short)local_34[iVar9 + 2]) * 0x10;
    if (((*(byte *)(iVar4 + 0x28) & 1) == 0) && (0x100 < *(short *)(iVar8 + param_1 + 0x30))) {
      Sys_Error("Bad surface extents %d/%d",(int)*(short *)(param_1 + 0x30),
                (int)*(short *)(param_1 + 0x32));
    }
    iVar9 = iVar9 + 1;
  } while (iVar9 < 2);
  return;
}


// CheckAuthenticationType  @ 08088290
void CheckAuthenticationType(void)

{
  gfUseLANAuthentication = 1;
  return;
}


// CheckGore  @ 080592e0
void CheckGore(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_104 [64];
  
  puVar2 = local_104;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  Cvar_SetValue("violence_hblood",0x3f800000);
  Cvar_SetValue("violence_hgibs",0x3f800000);
  Cvar_SetValue("violence_ablood",0x3f800000);
  Cvar_SetValue("violence_agibs",0x3f800000);
  return;
}


// CheckWaterJump  @ 08067e90
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CheckWaterJump(void)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10 [8];
  float local_8;
  
  if (((byte)((byte)((ushort)((ushort)NAN(_DAT_081051d0) << 10) >> 8) |
             (byte)((ushort)((ushort)(_DAT_081051d0 == 0.0) << 0xe) >> 8)) == 0x40) &&
     (-180.0 <= _DAT_0810518c)) {
    local_1c = forward;
    local_18 = DAT_080ca0ec;
    local_14 = 0;
    VectorNormalize(&local_1c);
    VectorMA(&DAT_0810516c,0x41c00000,&local_1c,local_10);
    local_8 = local_8 + 8.0;
    iVar1 = PM_PointContents(local_10);
    if (iVar1 == -2) {
      local_8 = local_8 + 24.0;
      iVar1 = PM_PointContents(local_10);
      if (iVar1 == -1) {
        VectorScale(&forward,0x43480000,&DAT_08105184);
        _DAT_0810518c = 225.0;
        _DAT_081051d0 = 2.0;
        DAT_081051cc._0_1_ = (byte)DAT_081051cc | 2;
      }
    }
  }
  return;
}


// CleanupName  @ 08081010
void CleanupName(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if (*(char *)(iVar2 + param_1) == '\0') break;
    iVar1 = toupper((int)*(char *)(iVar2 + param_1));
    *(char *)(iVar2 + param_2) = (char)iVar1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  for (; iVar2 < 0x10; iVar2 = iVar2 + 1) {
    *(undefined1 *)(iVar2 + param_2) = 0;
  }
  return;
}


// ClearLink  @ 0804dba0
void ClearLink(int param_1)

{
  *(int *)(param_1 + 4) = param_1;
  *(int *)param_1 = param_1;
  return;
}


// ClientPrintf  @ 0806bfd0
void ClientPrintf(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (svs < iVar1)) {
    Con_Printf("tried to sprint to a non-client\n");
  }
  else {
    iVar1 = DAT_0816dd10 + -0x52b8 + iVar1 * 0x52b8;
    if (param_2 == 1) {
      MSG_WriteChar(iVar1 + 0x78,0x1a);
    }
    else {
      if ((param_2 != 0) && (param_2 != 2)) {
        Con_Printf("invalid PRINT_TYPE %i\n",param_2);
        return;
      }
      MSG_WriteByte(iVar1 + 0x78,8);
    }
    MSG_WriteString(iVar1 + 0x78,param_3);
  }
  return;
}


// ClipVelocity  @ 0807a6e0
byte ClipVelocity(float *param_1,float *param_2,int param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  byte bVar9;
  
  fVar1 = param_2[2];
  bVar9 = (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1;
  if ((byte)((byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    bVar9 = bVar9 | 2;
  }
  fVar1 = *param_1;
  fVar2 = *param_2;
  fVar3 = param_1[1];
  fVar4 = param_2[1];
  fVar5 = param_1[2];
  fVar6 = param_2[2];
  iVar8 = 0;
  do {
    fVar7 = param_1[iVar8] -
            (fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2) * param_4 * param_2[iVar8];
    *(float *)(param_3 + iVar8 * 4) = fVar7;
    if ((-0.1 < fVar7) &&
       ((byte)(fVar7 < 0.1 | (byte)((ushort)((ushort)NAN(fVar7) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar7 == 0.1) << 0xe) >> 8)) == 1)) {
      *(undefined4 *)(param_3 + iVar8 * 4) = 0;
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 < 3);
  return bVar9;
}


// CommatizeNumber  @ 080871d0
char * CommatizeNumber(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char local_6c [52];
  char local_38 [52];
  
  pcVar5 = local_38;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    pcVar5[0] = '\0';
    pcVar5[1] = '\0';
    pcVar5[2] = '\0';
    pcVar5[3] = '\0';
    pcVar5 = pcVar5 + 4;
  }
  pcVar5[0] = '\0';
  pcVar5[1] = '\0';
  if (param_1 != 0) {
    do {
      iVar2 = param_1 / 1000;
      strcpy(local_6c,local_38);
      sprintf(local_38,",%03i%s",param_1 % 1000,local_6c);
      param_1 = iVar2;
    } while (iVar2 != 0);
  }
  uVar3 = 0xffffffff;
  pcVar5 = local_38;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  iVar4 = ~uVar3 - 1;
  iVar2 = 0;
  if (0 < iVar4) {
    do {
      if ((local_38[iVar2] != '0') && (local_38[iVar2] != ',')) break;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar4);
  }
  if (iVar2 == iVar4) {
    param_2[0] = '0';
    param_2[1] = '\0';
  }
  else {
    strcpy(param_2,local_38 + iVar2);
  }
  return param_2;
}


// ComparePath1  @ 08087190
undefined4 ComparePath1(char *param_1,char *param_2)

{
  for (; ((*param_1 != '/' && (*param_1 != '\\')) && (*param_1 != '\0')); param_1 = param_1 + 1) {
    if (*param_1 != *param_2) {
      return 0;
    }
    param_2 = param_2 + 1;
  }
  return 1;
}


// CopyString  @ 0804ccd0
char * CopyString(char *param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  
  uVar3 = 0xffffffff;
  pcVar2 = param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = (char *)Z_Malloc(~uVar3);
  strcpy(pcVar2,param_1);
  return pcVar2;
}


// CreateEntityList  @ 0805cac0
int CreateEntityList(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  int local_10;
  int local_8;
  
  local_8 = 0;
  iVar6 = 0;
  if (0 < param_1[8]) {
    do {
      local_10 = 0;
      iVar5 = param_1[10];
      iVar3 = iVar6 * 0x18;
      if (((*(int *)(iVar5 + 0x14 + iVar3) != 0) && (*(int *)(iVar5 + 0xc + iVar3) != 0)) &&
         (0 < *(int *)(iVar5 + iVar3))) {
        bVar7 = (param_2 & *(uint *)(iVar5 + 0x10 + iVar3)) != 0;
        if (*(int *)(iVar5 + iVar3) < svs + 1) {
          local_10 = *(int *)(*(int *)(iVar5 + iVar3) * 0x52b8 + DAT_0816dd10 + -0x3b0);
          if (bVar7) {
            if (-1 < *(int *)(iVar5 + 0x10 + iVar3)) {
              Sys_Error("ENTITY IS NOT A PLAYER: %d\n",iVar6);
            }
            if ((*(int *)(*(int *)(param_1[10] + iVar6 * 0x18) * 0x52b8 + DAT_0816dd10 + -0x52b8) ==
                 0) || (local_10 == 0)) {
              local_10 = 0;
            }
            else {
              EntityInit(local_10,*(undefined4 *)(param_1[10] + 0x14 + iVar6 * 0x18));
            }
          }
        }
        else if (bVar7) {
          local_10 = CreateNamedEntity(*(undefined4 *)(param_1[10] + 0x14 + iVar6 * 0x18));
        }
      }
      *(int *)(param_1[10] + 4 + iVar6 * 0x18) = local_10;
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_1[8]);
  }
  for (iVar6 = 0; iVar6 < param_1[8]; iVar6 = iVar6 + 1) {
    iVar3 = param_1[10];
    iVar5 = iVar6 * 0x18;
    iVar1 = *(int *)(iVar3 + 4 + iVar5);
    param_1[7] = iVar6;
    iVar2 = *(int *)(iVar3 + 8 + iVar5);
    param_1[2] = iVar2;
    param_1[1] = iVar2 + *param_1;
    if ((iVar1 != 0) && ((param_2 & *(uint *)(iVar3 + 0x10 + iVar5)) != 0)) {
      if ((*(byte *)(iVar3 + 0x13 + iVar5) & 0x10) == 0) {
        uVar4 = NUM_FOR_EDICT(iVar1);
        Con_DPrintf("Transferring %s (%d)\n",
                    *(int *)(param_1[10] + 0x14 + iVar6 * 0x18) + pr_strings,uVar4);
        iVar5 = (*DAT_08178ec0)(iVar1,param_1,0);
        if (iVar5 < 0) {
          ED_Free(iVar1);
        }
        else {
          SV_LinkEdict(iVar1,0);
          if ((*(int *)(param_1[10] + 0x10 + iVar6 * 0x18) < 0) ||
             (iVar5 = EntityInSolid(iVar1), iVar5 == 0)) {
            local_8 = local_8 + 1;
            *(undefined4 *)(param_1[10] + 0x10 + iVar6 * 0x18) = 0x40000000;
          }
          else {
            Con_DPrintf("Suppressing %s\n",*(int *)(param_1[10] + 0x14 + iVar6 * 0x18) + pr_strings)
            ;
            ED_Free(iVar1);
          }
        }
      }
      else {
        Con_DPrintf("Merging changes for global: %s\n",*(int *)(iVar3 + 0x14 + iVar5) + pr_strings);
        (*DAT_08178ec0)(iVar1,param_1,1);
        ED_Free(iVar1);
      }
    }
  }
  return local_8;
}


// CreateNamedEntity  @ 0806d590
int CreateNamedEntity(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  if (param_1 == 0) {
    Sys_Error("Spawned a NULL entity!");
  }
  iVar1 = ED_Alloc();
  *(int *)(iVar1 + 0xdc) = param_1;
  pcVar2 = (code *)GetEntityInit(param_1 + pr_strings);
  if (pcVar2 == (code *)0x0) {
    ED_Free(iVar1);
    iVar1 = 0;
    Con_DPrintf("Can\'t create entity: %s\n",param_1 + pr_strings);
  }
  else {
    (*pcVar2)(iVar1 + 0xdc);
  }
  return iVar1;
}


// CreateStuckTable  @ 08068100
void CreateStuckTable(void)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_1c;
  undefined4 local_10 [3];
  
  puVar6 = &rgv3tStuckTable;
  for (iVar5 = 0xa2; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  iVar5 = 0;
  fVar2 = -0.124;
  do {
    (&rgv3tStuckTable)[iVar5 * 3] = 0;
    (&DAT_0811c624)[iVar5 * 3] = 0;
    (&DAT_0811c628)[iVar5 * 3] = fVar2;
    iVar5 = iVar5 + 1;
    fVar2 = fVar2 + 0.124;
  } while ((byte)((fVar2 < 0.124 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 0.124) << 0xe) >> 8)) - 1) < 0x40);
  fVar2 = -0.124;
  do {
    (&rgv3tStuckTable)[iVar5 * 3] = 0;
    (&DAT_0811c624)[iVar5 * 3] = fVar2;
    (&DAT_0811c628)[iVar5 * 3] = 0;
    iVar5 = iVar5 + 1;
    fVar2 = fVar2 + 0.124;
  } while ((byte)((fVar2 < 0.124 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 0.124) << 0xe) >> 8)) - 1) < 0x40);
  fVar2 = -0.124;
  do {
    (&rgv3tStuckTable)[iVar5 * 3] = fVar2;
    (&DAT_0811c624)[iVar5 * 3] = 0;
    (&DAT_0811c628)[iVar5 * 3] = 0;
    iVar5 = iVar5 + 1;
    fVar2 = fVar2 + 0.124;
  } while ((byte)((fVar2 < 0.124 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 0.124) << 0xe) >> 8)) - 1) < 0x40);
  fVar2 = -0.124;
  do {
    fVar3 = -0.124;
    do {
      fVar4 = -0.124;
      do {
        (&rgv3tStuckTable)[iVar5 * 3] = fVar2;
        (&DAT_0811c624)[iVar5 * 3] = fVar3;
        (&DAT_0811c628)[iVar5 * 3] = fVar4;
        iVar5 = iVar5 + 1;
        fVar4 = fVar4 + 0.248;
      } while ((byte)((fVar4 < 0.124 | (byte)((ushort)((ushort)NAN(fVar4) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar4 == 0.124) << 0xe) >> 8)) - 1) < 0x40);
      fVar3 = fVar3 + 0.248;
    } while (fVar3 <= 0.124);
    fVar2 = fVar2 + 0.248;
  } while (fVar2 <= 0.124);
  local_10[0] = 0;
  local_10[1] = 0x3f800000;
  local_10[2] = 0x40c00000;
  local_1c = 0;
  do {
    uVar1 = local_10[local_1c];
    (&rgv3tStuckTable)[iVar5 * 3] = 0;
    (&DAT_0811c624)[iVar5 * 3] = 0;
    (&DAT_0811c628)[iVar5 * 3] = uVar1;
    iVar5 = iVar5 + 1;
    local_1c = local_1c + 1;
  } while (local_1c < 3);
  fVar2 = -2.0;
  do {
    (&rgv3tStuckTable)[iVar5 * 3] = 0;
    (&DAT_0811c624)[iVar5 * 3] = fVar2;
    (&DAT_0811c628)[iVar5 * 3] = 0;
    iVar5 = iVar5 + 1;
    fVar2 = fVar2 + 2.0;
  } while ((byte)((fVar2 < 2.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 2.0) << 0xe) >> 8)) - 1) < 0x40);
  fVar2 = -2.0;
  do {
    (&rgv3tStuckTable)[iVar5 * 3] = fVar2;
    (&DAT_0811c624)[iVar5 * 3] = 0;
    (&DAT_0811c628)[iVar5 * 3] = 0;
    iVar5 = iVar5 + 1;
    fVar2 = fVar2 + 2.0;
  } while ((byte)((fVar2 < 2.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar2 == 2.0) << 0xe) >> 8)) - 1) < 0x40);
  local_1c = 0;
  do {
    uVar1 = local_10[local_1c];
    fVar2 = -2.0;
    do {
      fVar3 = -2.0;
      do {
        (&rgv3tStuckTable)[iVar5 * 3] = fVar2;
        (&DAT_0811c624)[iVar5 * 3] = fVar3;
        (&DAT_0811c628)[iVar5 * 3] = uVar1;
        iVar5 = iVar5 + 1;
        fVar3 = fVar3 + 2.0;
      } while ((byte)((fVar3 < 2.0 | (byte)((ushort)((ushort)NAN(fVar3) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar3 == 2.0) << 0xe) >> 8)) - 1) < 0x40);
      fVar2 = fVar2 + 2.0;
    } while ((byte)((fVar2 < 2.0 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                    (byte)((ushort)((ushort)(fVar2 == 2.0) << 0xe) >> 8)) - 1) < 0x40);
    local_1c = local_1c + 1;
  } while (local_1c < 3);
  return;
}


// CrossProduct  @ 08061f70
void CrossProduct(float *param_1,float *param_2,float *param_3)

{
  *param_3 = param_1[1] * param_2[2] - param_1[2] * param_2[1];
  param_3[1] = param_1[2] * *param_2 - *param_1 * param_2[2];
  param_3[2] = *param_1 * param_2[1] - param_1[1] * *param_2;
  return;
}


// DirectoryClear  @ 0805d220
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


// DirectoryCopy  @ 0805d050
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


// DirectoryCount  @ 0805d1e0
int DirectoryCount(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = Sys_FindFirst(param_1,0);
  while (iVar1 != 0) {
    iVar2 = iVar2 + 1;
    iVar1 = Sys_FindNext(0);
  }
  Sys_FindClose();
  return iVar2;
}


// DirectoryExtract  @ 0805d120
void DirectoryExtract(FILE *param_1,int param_2)

{
  undefined4 uVar1;
  FILE *__stream;
  int iVar2;
  undefined4 local_210;
  undefined1 local_20c [260];
  char local_108 [260];
  
  if (0 < param_2) {
    iVar2 = 0;
    do {
      fread(local_20c,1,0x104,param_1);
      fread(&local_210,4,1,param_1);
      uVar1 = Host_SaveGameDirectory(local_20c);
      sprintf(local_108,"%s%s",uVar1);
      COM_FixSlashes(local_108);
      __stream = fopen(local_108,"wb");
      FileCopy(__stream,param_1,local_210);
      fclose(__stream);
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_2);
  }
  return;
}


// DispatchDirectUserMsg  @ 0808d530
undefined4 DispatchDirectUserMsg(void)

{
  return 0;
}


// DropPunchAngle  @ 0807e9f0
void DropPunchAngle(float param_1)

{
  float fVar1;
  longdouble lVar2;
  
  lVar2 = (longdouble)VectorNormalize(sv_player + 0x144);
  fVar1 = (float)(lVar2 - ((longdouble)10.0 + (longdouble)0.5 * lVar2) * (longdouble)param_1);
  if (fVar1 < 0.0) {
    fVar1 = 0.0;
  }
  VectorScale(sv_player + 0x144,fVar1,sv_player + 0x144);
  return;
}


// EngineFprintf  @ 08089180
void EngineFprintf(FILE *param_1,char *param_2)

{
  vsprintf(szOut_232,param_2,&stack0x0000000c);
  fprintf(param_1,szOut_232);
  return;
}


// EntOffsetOfPEntity  @ 08070050
int EntOffsetOfPEntity(int param_1)

{
  return param_1 - DAT_0814043c;
}


// EntityInSolid  @ 0805ca20
bool EntityInSolid(int param_1)

{
  int iVar1;
  bool bVar2;
  float local_10;
  float local_c;
  float local_8;
  
  if (((*(int *)(param_1 + 0x1c4) == 0xc) && (*(int *)(param_1 + 0x250) != 0)) &&
     ((*(byte *)(*(int *)(param_1 + 0x250) + 0x260) & 8) != 0)) {
    bVar2 = false;
  }
  else {
    local_10 = (*(float *)(param_1 + 0x180) + *(float *)(param_1 + 0x18c)) * 0.5;
    local_c = (*(float *)(param_1 + 0x184) + *(float *)(param_1 + 400)) * 0.5;
    local_8 = (*(float *)(param_1 + 0x188) + *(float *)(param_1 + 0x194)) * 0.5;
    iVar1 = SV_PointContents(&local_10);
    bVar2 = iVar1 == -2;
  }
  return bVar2;
}


// EntityInit  @ 0805c040
void EntityInit(int param_1,int param_2)

{
  code *pcVar1;
  
  if (param_2 == 0) {
    Sys_Error("Bad class!!\n");
  }
  ReleaseEntityDLLFields(param_1);
  InitEntityDLLFields(param_1);
  *(int *)(param_1 + 0xdc) = param_2;
  pcVar1 = (code *)GetEntityInit(param_2 + pr_strings);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(param_1 + 0xdc);
  }
  return;
}


// EntityPatchRead  @ 0805c5b0
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
        *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x10 + local_110 * 0x18) = 0x40000000;
        iVar2 = iVar2 + 1;
      } while (iVar2 < local_10c);
    }
    fclose(__stream);
  }
  return;
}


// EntityPatchWrite  @ 0805c4a0
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


// EntryInTable  @ 0805c940
int EntryInTable(int param_1,char *param_2,int param_3)

{
  int iVar1;
  
  do {
    param_3 = param_3 + 1;
    if (*(int *)(param_1 + 0x24) <= param_3) {
      return -1;
    }
    iVar1 = strcmp((char *)(param_1 + 0x2c + param_3 * 0x50),param_2);
  } while (iVar1 != 0);
  return param_3;
}


// FileCopy  @ 0805cff0
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


// FileSize  @ 0805cfa0
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


// FindAddressInTable  @ 08088930
undefined4 FindAddressInTable(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    do {
      if (*(int *)(*(int *)(param_1 + 4) + iVar1 * 8) == param_2) {
        return *(undefined4 *)(*(int *)(param_1 + 4) + 4 + iVar1 * 8);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 8));
  }
  return 0;
}


// FindEntityByString  @ 0806d900
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


// FindEntityByVars  @ 08070110
int FindEntityByVars(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < DAT_08140434) {
    do {
      iVar1 = DAT_0814043c + iVar2 * 0x2c8;
      if (iVar1 + 0xdc == param_1) {
        return iVar1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_08140434);
  }
  return 0;
}


// FindEntityInSphere  @ 0806d430
int * FindEntityInSphere(int param_1,int param_2,float param_3)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  if (param_1 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = NUM_FOR_EDICT(param_1);
  }
  param_3 = param_3 * param_3;
  do {
    do {
      iVar5 = iVar5 + 1;
      if (DAT_08140434 <= iVar5) {
        return DAT_0814043c;
      }
      piVar1 = DAT_0814043c + iVar5 * 0xb2;
    } while (((*piVar1 != 0) || (piVar1[0x37] == 0)) ||
            ((iVar5 <= svs && (*(int *)(DAT_0816dd10 + -0x52b8 + iVar5 * 0x52b8) == 0))));
    fVar4 = 0.0;
    iVar6 = 0;
    do {
      if (0x3f < (byte)((fVar4 < param_3 |
                         (byte)((ushort)((ushort)(NAN(fVar4) || NAN(param_3)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(fVar4 == param_3) << 0xe) >> 8)) - 1)) break;
      piVar7 = piVar1 + 0x60;
      fVar2 = *(float *)(param_2 + iVar6 * 4);
      fVar3 = (float)piVar7[iVar6];
      if ((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) == 1) {
LAB_0806d536:
        fVar3 = fVar2 - (float)piVar7[iVar6];
      }
      else {
        piVar7 = piVar1 + 99;
        fVar2 = *(float *)(param_2 + iVar6 * 4);
        fVar3 = 0.0;
        if ((float)piVar7[iVar6] < fVar2) goto LAB_0806d536;
      }
      fVar4 = fVar3 * fVar3 + fVar4;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 3);
    if (fVar4 <= param_3) {
      return piVar1;
    }
  } while( true );
}


// FindMiptex  @ 080814e0
int FindMiptex(char *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < nummiptex) {
    do {
      iVar1 = Q_strcasecmp(param_1,miptex + iVar2 * 0x40);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < nummiptex);
  }
  if (nummiptex == 0x200) {
    Sys_Error("Exceeded MAX_MAP_TEXTURES");
  }
  strcpy(miptex + iVar2 * 0x40,param_1);
  nummiptex = nummiptex + 1;
  return iVar2;
}


// FindNameInTable  @ 08088960
undefined4 FindNameInTable(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    do {
      iVar1 = strcmp(param_2,*(char **)(*(int *)(param_1 + 4) + 4 + iVar2 * 8));
      if (iVar1 == 0) {
        return *(undefined4 *)(*(int *)(param_1 + 4) + iVar2 * 8);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 8));
  }
  return 0;
}


// FindPassableSpace  @ 0805a450
undefined4 FindPassableSpace(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    VectorMA(param_1 + 0xe4,param_3,param_2,param_1 + 0xe4);
    iVar1 = SV_TestEntityPosition(param_1);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(param_1 + 0xe4);
      *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(param_1 + 0xe8);
      *(undefined4 *)(param_1 + 0xf8) = *(undefined4 *)(param_1 + 0xec);
      return 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 100);
  return 0;
}


// FindViewthing  @ 0805e230
int FindViewthing(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  iVar3 = 0;
  if (0 < DAT_08140434) {
    do {
      iVar1 = DAT_0814043c + iVar3 * 0x2c8;
      iVar2 = 10;
      bVar6 = true;
      pcVar4 = (char *)(pr_strings + *(int *)(iVar1 + 0xdc));
      pcVar5 = "viewthing";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        return iVar1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_08140434);
  }
  Con_Printf("No viewthing on map\n");
  return 0;
}


// FloatNoSwap  @ 0804e440
longdouble FloatNoSwap(float param_1)

{
  return (longdouble)param_1;
}


// FloatSwap  @ 0804e3f0
longdouble FloatSwap(uint param_1)

{
  return (longdouble)
         (float)(param_1 >> 0x18 | param_1 >> 8 & 0xff00 | (param_1 & 0xff00) << 8 | param_1 << 0x18
                );
}


// FloorDivMod  @ 08062450
void FloorDivMod(double param_1,undefined4 param_2,undefined4 param_3,int *param_4,int *param_5)

{
  int iVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  
  if ((double)CONCAT44(param_3,param_2) <= 0.0) {
    Sys_Error("FloorDivMod: bad denominator %d\n",param_2,param_3);
  }
  if ((byte)((0.0 < param_1 | (byte)((ushort)((ushort)NAN(param_1) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_1 == 0.0) << 0xe) >> 8)) - 1) < 0x40) {
    dVar2 = ROUND(param_1 / (double)CONCAT44(param_3,param_2));
    iVar4 = (int)ROUND(dVar2);
    iVar3 = (int)ROUND(ROUND(param_1 - dVar2 * (double)CONCAT44(param_3,param_2)));
  }
  else {
    dVar2 = ROUND(-param_1 / (double)CONCAT44(param_3,param_2));
    iVar4 = -(int)ROUND(dVar2);
    iVar1 = (int)ROUND(ROUND(-param_1 - dVar2 * (double)CONCAT44(param_3,param_2)));
    iVar3 = 0;
    if (iVar1 != 0) {
      iVar4 = iVar4 + -1;
      iVar3 = (int)ROUND((double)CONCAT44(param_3,param_2)) - iVar1;
    }
  }
  *param_4 = iVar4;
  *param_5 = iVar3;
  return;
}


// ForceReloadProfile  @ 08088820
void ForceReloadProfile(void)

{
  return;
}


// ForwardSlashes  @ 08081080
void ForwardSlashes(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    if (*param_1 == '\\') {
      *param_1 = '/';
    }
    param_1 = param_1 + 1;
    cVar1 = *param_1;
  }
  return;
}


// FreeEntPrivateData  @ 08070010
void FreeEntPrivateData(int param_1)

{
  if (*(int *)(param_1 + 0xd8) != 0) {
    free(*(void **)(param_1 + 0xd8));
  }
  *(undefined4 *)(param_1 + 0xd8) = 0;
  return;
}


// FunctionFromName  @ 080889c0
int FunctionFromName(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < g_iextdllMac) {
    do {
      iVar1 = FindNameInTable(&g_rgextdll + iVar2 * 3,param_1);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < g_iextdllMac);
  }
  Con_Printf("Can\'t find proc: %s\n",param_1);
  return 0;
}


// GameInit  @ 080882b0
bool GameInit(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
             undefined4 param_5,char *param_6,int param_7)

{
  char *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *local_1c;
  undefined4 local_18;
  int local_14;
  undefined1 *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  strcpy(&OrigCmd_191,param_1);
  host_initialized = 0;
  puVar3 = &g_szPlayerName;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  strcpy((char *)&g_szPlayerName,param_6);
  Console_Printf = (code *)param_4[0x15];
  VID_LockBuffer = param_4[2];
  VID_UnlockBuffer = param_4[3];
  VID_Shutdown = param_4[4];
  VID_Update = param_4[5];
  VID_ForceLockState = param_4[6];
  VID_ForceUnlockedAndReturnState = param_4[7];
  VID_SetDefaultMode = param_4[8];
  VID_GetExtModeDescription = param_4[9];
  D_SurfaceCacheForRes = param_4[0x14];
  VID_GetVID = param_4[10];
  D_BeginDirectRect = param_4[0xb];
  D_EndDirectRect = param_4[0xc];
  AppActivate = param_4[0xd];
  CDAudio_Play = param_4[0xe];
  CDAudio_Resume = param_4[0x10];
  CDAudio_Pause = param_4[0xf];
  CDAudio_Update = param_4[0x11];
  gHasMMXTechnology = *param_4;
  gProcessorSpeed = param_4[1];
  ErrorMessage = param_4[0x13];
  Launcher_InitCmds = param_4[0x12];
  Launcher_GetCDKey = param_4[0x16];
  Launcher_GetClientID = param_4[0x17];
  Launcher_VerifyMessage = param_4[0x19];
  Launcher_GetCertificate = param_4[0x1a];
  Launcher_RequestNewClientCertificate = param_4[0x1b];
  Launcher_ValidateClientCertificate = param_4[0x1c];
  Launcher_AuthRequest = param_4[0x1d];
  Launcher_AuthChallenge1 = param_4[0x1e];
  Launcher_AuthChallenge2 = param_4[0x1f];
  Launcher_AuthComplete = param_4[0x20];
  Launcher_DecodeAuthComplete = param_4[0x21];
  Launcher_DeleteAuthData = param_4[0x22];
  Launcher_GetConnectionKey = param_4[0x23];
  Launcher_BFEncrypt = param_4[0x24];
  Launcher_GetRawBFKey = param_4[0x25];
  if (param_7 == 0) {
    Launcher_IsValidCD = param_4[0x26];
  }
  else {
    Launcher_IsValidCD = 0;
  }
  SeedRandomNumberGenerator();
  pcVar1 = getcwd(cwd_190,0x400);
  if (pcVar1 == (char *)0x0) {
    Sys_Error("Couldn\'t determine current directory");
  }
  iVar2 = Q_strlen(cwd_190);
  if ((&DAT_080c7c9f)[iVar2] == '/') {
    iVar2 = Q_strlen(cwd_190);
    (&DAT_080c7c9f)[iVar2] = 0;
  }
  local_1c = cwd_190;
  local_18 = 0;
  local_14 = 1;
  argv._0_4_ = empty_string;
  if (OrigCmd_191 != '\0') {
    pcVar1 = &OrigCmd_191;
    do {
      if ((0x31 < local_14) || (*pcVar1 == '\0')) break;
      do {
        if ((byte)(*pcVar1 - 0x21U) < 0x5e) break;
        pcVar1 = pcVar1 + 1;
      } while (*pcVar1 != '\0');
      if (*pcVar1 == '\0') break;
      *(char **)(argv + local_14 * 4) = pcVar1;
      local_14 = local_14 + 1;
      for (; (byte)(*pcVar1 - 0x21U) < 0x5e; pcVar1 = pcVar1 + 1) {
      }
      if (*pcVar1 == '\0') break;
      *pcVar1 = '\0';
      pcVar1 = pcVar1 + 1;
    } while (*pcVar1 != '\0');
  }
  local_10 = argv;
  COM_InitArgv(local_14,argv);
  local_14 = com_argc;
  local_10 = (undefined1 *)com_argv;
  isDedicated = param_7;
  local_c = param_2;
  local_8 = param_3;
  Sys_Init();
  S_BlockSound();
  (*Console_Printf)("Host_Init\n");
  iVar2 = Host_Init(&local_1c);
  if (iVar2 != 0) {
    Host_InitializeGameDLL();
    NET_Config(1);
  }
  return iVar2 != 0;
}


// GameSetBackground  @ 08088280
void GameSetBackground(undefined4 param_1)

{
  gfBackground = param_1;
  return;
}


// GameSetState  @ 08088270
void GameSetState(undefined4 param_1)

{
  giActive = param_1;
  return;
}


// GameSetSubState  @ 08088250
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


// GetAttachment  @ 08061630
void GetAttachment(int param_1,int param_2,int param_3)

{
  int iVar1;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  pstudiohdr = Mod_Extradata((&DAT_0813e330)[*(int *)(param_1 + 0x170)]);
  iVar1 = pstudiohdr + *(int *)(pstudiohdr + 0xd8) + param_2 * 0x58;
  local_8 = *(undefined4 *)(param_1 + 0x134);
  local_10 = -*(float *)(param_1 + 300);
  local_c = *(undefined4 *)(param_1 + 0x130);
  SV_StudioSetupBones((&DAT_0813e330)[*(int *)(param_1 + 0x170)],*(undefined4 *)(param_1 + 0x1ec),
                      *(undefined4 *)(param_1 + 0x1e4),&local_10,param_1 + 0xe4,param_1 + 0x1f8,
                      param_1 + 0x1fc,*(undefined4 *)(iVar1 + 0x24));
  if (param_3 != 0) {
    VectorTransform(iVar1 + 0x28,bonetransform + *(int *)(iVar1 + 0x24) * 0x30,param_3);
  }
  return;
}


// GetBonePosition  @ 08061580
void GetBonePosition(int param_1,int param_2,undefined4 *param_3)

{
  pstudiohdr = Mod_Extradata((&DAT_0813e330)[*(int *)(param_1 + 0x170)]);
  SV_StudioSetupBones((&DAT_0813e330)[*(int *)(param_1 + 0x170)],*(undefined4 *)(param_1 + 0x1ec),
                      *(undefined4 *)(param_1 + 0x1e4),param_1 + 300,param_1 + 0xe4,param_1 + 0x1f8,
                      param_1 + 0x1fc,param_2);
  if (param_3 != (undefined4 *)0x0) {
    param_2 = param_2 * 0x30;
    *param_3 = *(undefined4 *)(bonetransform + param_2 + 0xc);
    param_3[1] = *(undefined4 *)(bonetransform + param_2 + 0x1c);
    param_3[2] = *(undefined4 *)(bonetransform + param_2 + 0x2c);
  }
  return;
}


// GetDispatch  @ 080888f0
int GetDispatch(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < g_iextdllMac) {
    do {
      iVar1 = dlsym((&g_rgextdll)[iVar2 * 3],param_1);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < g_iextdllMac);
  }
  return 0;
}


// GetEngineState  @ 08088230
undefined4 GetEngineState(void)

{
  return cls;
}


// GetEntityIllum  @ 0806d970
void GetEntityIllum(int param_1)

{
  if (param_1 != 0) {
    NUM_FOR_EDICT(param_1);
  }
  return;
}


// GetEntityInit  @ 08088a60
void GetEntityInit(undefined4 param_1)

{
  GetDispatch(param_1);
  return;
}


// GetGameInfo  @ 08088630
undefined4 GetGameInfo(uint *param_1)

{
  int iVar1;
  uint *puVar2;
  char *pcVar3;
  uint local_144 [3];
  char local_138 [32];
  undefined4 local_118;
  undefined1 local_114;
  undefined1 local_113;
  undefined1 local_112;
  undefined1 local_111;
  undefined2 local_110;
  char local_10e [258];
  int local_c;
  undefined4 local_8;
  
  puVar2 = local_144;
  for (iVar1 = 0x50; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_144[0] = build_number();
  local_144[1] = (uint)(svs != 1);
  local_144[2] = svs;
  strncpy(local_138,&DAT_0811d260,0x20);
  local_118 = sv;
  if (net_local_adr == 3) {
    local_114 = DAT_0817ad94;
    local_113 = DAT_0817ad95;
    local_112 = DAT_0817ad96;
    local_111 = DAT_0817ad97;
    local_110 = DAT_0817ada2;
  }
  local_c = cls;
  local_8 = DAT_081b9180;
  pcVar3 = local_10e;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    pcVar3[0] = '\0';
    pcVar3[1] = '\0';
    pcVar3[2] = '\0';
    pcVar3[3] = '\0';
    pcVar3 = pcVar3 + 4;
  }
  if (cls == 5) {
    pcVar3 = "Currently in a game";
  }
  else {
    if (cls == 1) {
      sprintf(local_10e,"Disconnected");
      if (gfExtendedError != 0) {
        strcat(local_10e,": ");
        strcat(local_10e,gszDisconnectReason);
      }
      goto LAB_080887e1;
    }
    if (cls == 4) {
      if (DAT_081b9ee8 != 0) {
        sprintf(local_10e,"Downloading %s, %i percent complete",&DAT_081b9f38,DAT_081b9f80);
        goto LAB_080887e1;
      }
      pcVar3 = "Initializing and downloading";
    }
    else if (cls == 3) {
      pcVar3 = "Connected to server";
    }
    else if (cls == 2) {
      pcVar3 = "Connecting";
    }
    else if (cls == 0) {
      pcVar3 = "Running dedicated server";
    }
    else {
      pcVar3 = "?";
    }
  }
  sprintf(local_10e,pcVar3);
LAB_080887e1:
  puVar2 = local_144;
  for (iVar1 = 0x50; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return 1;
}


// GetIOFunction  @ 08088a70
void GetIOFunction(undefined4 param_1)

{
  GetDispatch(param_1);
  return;
}


// GetModelPtr  @ 08070250
void GetModelPtr(int param_1)

{
  Mod_Extradata((&DAT_0813e330)[*(int *)(param_1 + 0x170)]);
  return;
}


// GetPauseState  @ 080888c0
undefined4 GetPauseState(void)

{
  return DAT_0811d244;
}


// GetRandomStuckOffsets  @ 080684b0
int GetRandomStuckOffsets(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2 * 4 + param_1 * 8;
  iVar2 = *(int *)(rgStuckLast + iVar1);
  *(int *)(rgStuckLast + iVar1) = *(int *)(rgStuckLast + iVar1) + 1;
  iVar2 = iVar2 % 0x36;
  *param_3 = (&rgv3tStuckTable)[iVar2 * 3];
  param_3[1] = (&DAT_0811c624)[iVar2 * 3];
  param_3[2] = (&DAT_0811c628)[iVar2 * 3];
  return iVar2;
}


// GetTickCount  @ 080893f0
undefined4 GetTickCount(void)

{
  return 0x28;
}


// GetVarsOfEnt  @ 08070100
int GetVarsOfEnt(int param_1)

{
  return param_1 + 0xdc;
}


// GreatestCommonDivisor  @ 080625b0
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


// IndexOfEdict  @ 08070070
int IndexOfEdict(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (param_1 - DAT_0814043c) * -0x5c0b817 >> 3;
    if ((iVar1 < 0) || (DAT_08140438 < iVar1)) {
      Sys_Error("Bad entity in IndexOfEdict()");
    }
  }
  return iVar1;
}


// InitEntityDLLFields  @ 0806ffa0
void InitEntityDLLFields(int param_1)

{
  *(int *)(param_1 + 0x2c4) = param_1;
  return;
}


// InsertLinkAfter  @ 0804dbf0
void InsertLinkAfter(int *param_1,int param_2)

{
  param_1[1] = *(int *)(param_2 + 4);
  *param_1 = param_2;
  *(int **)(param_2 + 4) = param_1;
  *(int **)param_1[1] = param_1;
  return;
}


// InsertLinkBefore  @ 0804dbd0
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


// Invert24To16  @ 08062600
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


// IsComment  @ 08080520
undefined4 IsComment(char *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  if (param_1 != (char *)0x0) {
    uVar2 = 0xffffffff;
    pcVar3 = param_1;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (((((int)(~uVar2 - 1) < 2) || (*param_1 != '/')) || (param_1[1] != '/')) &&
       (0 < (int)(~uVar2 - 1))) {
      return 0;
    }
  }
  return 1;
}


// IsEndOfText  @ 080805a0
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


// IsSinglePlayerGame  @ 08071780
bool IsSinglePlayerGame(void)

{
  int iVar1;
  
  iVar1 = cl._138436_4_;
  if (sv != 0) {
    iVar1 = svs;
  }
  return iVar1 == 1;
}


// IsStartOfText  @ 08080570
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


// IsToken  @ 080807b0
undefined4 IsToken(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  
  if ((param_1 != 0) && (param_2 != (char *)0x0)) {
    uVar3 = 0xffffffff;
    pcVar4 = param_2;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    iVar2 = strncasecmp((char *)(param_1 + 1),param_2,~uVar3 - 1);
    if (iVar2 == 0) {
      return 1;
    }
  }
  return 0;
}


// IsWhiteSpace  @ 080805d0
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


// JumpButton  @ 08067d90
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void JumpButton(void)

{
  if (DAT_081051d4 == 0) {
    if ((byte)(0.0 < _DAT_081051d0 | (byte)((ushort)((ushort)NAN(_DAT_081051d0) << 10) >> 8) |
              (byte)((ushort)((ushort)(_DAT_081051d0 == 0.0) << 0xe) >> 8)) != 0x40) {
      _DAT_081051d0 = _DAT_081051d0 - frametime;
      if ((byte)(_DAT_081051d0 < 0.0 | (byte)((ushort)((ushort)NAN(_DAT_081051d0) << 10) >> 8) |
                (byte)((ushort)((ushort)(_DAT_081051d0 == 0.0) << 0xe) >> 8)) != 1) {
        return;
      }
      _DAT_081051d0 = 0.0;
      return;
    }
    if (1 < waterlevel) {
      if (watertype == -3) {
        _DAT_0810518c = 100.0;
        onground = 0xffffffff;
        return;
      }
      if (watertype == -4) {
        _DAT_0810518c = 80.0;
        onground = 0xffffffff;
        return;
      }
      _DAT_0810518c = 50.0;
      onground = 0xffffffff;
      return;
    }
    if (onground != -1) {
      if (((byte)DAT_081051cc & 2) != 0) {
        return;
      }
      onground = -1;
      _DAT_0810518c = _DAT_0810518c + 268.32816;
    }
  }
  DAT_081051cc._0_1_ = (byte)DAT_081051cc | 2;
  return;
}


// LandmarkOrigin  @ 0805c9a0
void LandmarkOrigin(int param_1,undefined4 *param_2,char *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    do {
      iVar4 = iVar3 * 0x50;
      iVar2 = strcmp((char *)(param_1 + 0x4c + iVar4),param_3);
      if (iVar2 == 0) {
        *param_2 = *(undefined4 *)(iVar4 + 0x70 + param_1);
        param_2[1] = *(undefined4 *)(iVar4 + 0x74 + param_1);
        uVar1 = *(undefined4 *)(iVar4 + 0x78 + param_1);
        goto LAB_0805ca10;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x24));
  }
  *param_2 = vec3_origin._0_4_;
  param_2[1] = vec3_origin._4_4_;
  uVar1 = vec3_origin._8_4_;
LAB_0805ca10:
  param_2[2] = uVar1;
  return;
}


// Length  @ 08061fb0
longdouble Length(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar2 = 0.0;
  iVar3 = 0;
  do {
    fVar1 = *(float *)(param_1 + iVar3 * 4);
    fVar2 = fVar1 * fVar1 + fVar2;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  return (longdouble)SQRT(fVar2);
}


// LoadAdjacentEntities  @ 0805cd80
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LoadAdjacentEntities(char *param_1,undefined4 param_2)

{
  char *__s1;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int local_600;
  float local_5f8;
  float local_5f4;
  float local_5f0;
  undefined1 local_5ec [116];
  undefined4 local_578 [9];
  int local_554;
  char local_54c [1352];
  
  local_600 = 0;
  puVar4 = local_578;
  for (iVar2 = 0x15d; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  gGlobalVariables._156_4_ = local_578;
  (*DAT_08178f08)();
  iVar2 = 0;
  if (0 < local_554) {
    do {
      iVar3 = 0;
      if (iVar2 < 1) {
LAB_0805ce15:
        __s1 = local_54c + iVar2 * 0x50;
        iVar3 = LoadSaveData(__s1);
        if (iVar3 != 0) {
          ParseSaveTables(iVar3,local_5ec,0);
          EntityPatchRead(iVar3,__s1);
          *(float *)(iVar3 + 0x550) = (float)_DAT_0811d24c;
          *(undefined4 *)(iVar3 + 0x52c) = 1;
          uVar5 = 0;
          LandmarkOrigin(local_578,&local_5f8,param_2);
          LandmarkOrigin(iVar3,iVar3 + 0x544,param_2);
          *(float *)(iVar3 + 0x544) = local_5f8 - *(float *)(iVar3 + 0x544);
          *(float *)(iVar3 + 0x548) = local_5f4 - *(float *)(iVar3 + 0x548);
          *(float *)(iVar3 + 0x54c) = local_5f0 - *(float *)(iVar3 + 0x54c);
          iVar1 = strcmp(__s1,param_1);
          if (iVar1 == 0) {
            uVar5 = 0x80000000;
          }
          iVar1 = -1;
          while( true ) {
            iVar1 = EntryInTable(iVar3,&DAT_0811d260,iVar1);
            if (iVar1 < 0) break;
            uVar5 = uVar5 | 1 << ((byte)iVar1 & 0x1f);
          }
          if (uVar5 != 0) {
            local_600 = CreateEntityList(iVar3,uVar5);
          }
          if (local_600 != 0) {
            EntityPatchWrite(iVar3,local_54c + iVar2 * 0x50);
          }
          SaveExit(iVar3);
        }
      }
      else {
        do {
          iVar1 = strcmp(local_54c + iVar2 * 0x50,local_54c + iVar3 * 0x50);
          if (iVar1 == 0) break;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar2);
        if (iVar2 <= iVar3) goto LAB_0805ce15;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < local_554);
  }
  gGlobalVariables._156_4_ = 0;
  return;
}


// LoadBMP  @ 08051ac0
uint * LoadBMP(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *__ptr;
  void *__ptr_00;
  size_t sVar3;
  uint uVar4;
  uint __n;
  size_t __size;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *local_46c;
  uint *puVar7;
  uint *local_44c;
  undefined4 local_448;
  undefined4 local_444;
  int local_440;
  undefined1 local_43c [1024];
  int local_3c;
  int local_38;
  uint local_34;
  short local_30;
  short local_2e;
  int local_2c;
  int local_1c;
  undefined1 local_14 [4];
  int local_10;
  int local_c;
  
  puVar7 = (uint *)0x0;
  iVar1 = COM_OpenFile(param_1,&local_448);
  if (((((iVar1 != -1) && (iVar1 = Sys_FileRead(local_440,local_14,0x10), iVar1 == 0x10)) &&
       (local_c == 0)) &&
      ((iVar1 = Sys_FileRead(local_440,&local_3c,0x28), iVar1 == 0x28 && (local_3c == 0x28)))) &&
     ((local_30 == 1 && ((local_2e == 8 && (local_2c == 0)))))) {
    if (local_1c == 0) {
      local_1c = 0x100;
      iVar1 = 0x400;
    }
    else {
      iVar1 = local_1c * 4;
    }
    iVar2 = Sys_FileRead(local_440,local_43c,iVar1);
    if ((iVar2 == iVar1) && (__ptr = malloc(0x300), __ptr != (undefined4 *)0x0)) {
      puVar5 = __ptr;
      for (iVar1 = 0xc0; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      if (0 < local_1c) {
        iVar1 = 0;
        local_46c = __ptr;
        do {
          iVar2 = iVar1 * 4;
          *(undefined1 *)local_46c = local_43c[iVar2 + 2];
          *(undefined1 *)((int)local_46c + 1) = local_43c[iVar2 + 1];
          *(undefined1 *)((int)local_46c + 2) = local_43c[iVar2];
          local_46c = (undefined4 *)((int)local_46c + 3);
          iVar1 = iVar1 + 1;
        } while (iVar1 < local_1c);
      }
      iVar1 = COM_FileTell(local_448,local_444,local_440);
      __size = local_10 - iVar1;
      __ptr_00 = malloc(__size);
      sVar3 = Sys_FileRead(local_440,__ptr_00,__size);
      if (sVar3 != __size) {
        return (uint *)0x0;
      }
      __n = local_38 + 3U & 0xfffffffc;
      if ((param_3 == 0) && (param_4 == -1)) {
        puVar7 = malloc(__size + 0x30e);
        local_44c = puVar7 + 2;
        *puVar7 = __n;
        puVar7[1] = local_34;
        local_46c = (undefined4 *)((int)__ptr_00 + (local_34 - 1) * __n);
        iVar1 = 0;
        if (0 < (int)local_34) {
          do {
            memmove((uint *)(__n * iVar1 + (int)local_44c),local_46c,__n);
            local_46c = (undefined4 *)((int)local_46c - __n);
            iVar1 = iVar1 + 1;
          } while (iVar1 < (int)local_34);
        }
        __ptr_00 = (void *)((int)local_46c + __n);
      }
      else {
        uVar4 = param_4 - param_3;
        puVar7 = malloc(uVar4 * __n + 0x30e);
        local_44c = puVar7 + 2;
        *puVar7 = __n;
        puVar7[1] = uVar4;
        local_46c = (undefined4 *)(((local_34 - param_3) + -1) * __n + (int)__ptr_00);
        if (0 < (int)uVar4) {
          iVar1 = 0;
          do {
            memmove((uint *)(__n * iVar1 + (int)local_44c),local_46c,__n);
            local_46c = (undefined4 *)((int)local_46c - __n);
            iVar1 = iVar1 + 1;
          } while (iVar1 < param_4 - param_3);
        }
      }
      free(__ptr_00);
      *(undefined1 *)(__n * puVar7[1] + (int)local_44c) = 0;
      *(undefined1 *)((int)local_44c + __n * puVar7[1] + 1) = 1;
      puVar5 = __ptr;
      puVar6 = (undefined4 *)((int)local_44c + __n * puVar7[1] + 2);
      for (iVar1 = 0xc0; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      free(__ptr);
    }
  }
  if (local_440 != -1) {
    COM_CloseFile(local_448,local_444,local_440);
  }
  return puVar7;
}


// LoadBMP16  @ 08052060
ushort * LoadBMP16(FILE *param_1,int param_2)

{
  short sVar1;
  size_t sVar2;
  void *__ptr;
  uint uVar3;
  uint uVar4;
  ushort uVar5;
  ushort uVar6;
  byte *pbVar7;
  bool bVar8;
  short local_9e;
  int local_9c;
  ushort *local_98;
  int local_94;
  byte *local_90;
  ushort *local_8c;
  int local_88;
  ushort *local_84;
  int local_80;
  byte *local_7c;
  ushort *local_78;
  int local_74;
  ushort *local_70;
  int local_6c;
  byte *local_68;
  ushort *local_64;
  int local_60;
  ushort *local_5c;
  int local_58;
  byte *local_54;
  ushort *local_50;
  ushort *local_40;
  uint local_3c;
  int local_38;
  int local_34;
  short local_30;
  short local_2e;
  int local_2c;
  size_t local_28;
  int local_1c;
  short local_14 [4];
  int local_c;
  int local_8;
  
  local_40 = (ushort *)0x0;
  sVar2 = fread(local_14,0x10,1,param_1);
  if (((((sVar2 == 1) && (local_14[0] == 0x4d42)) && (local_c == 0)) &&
      ((sVar2 = fread(&local_3c,0x28,1,param_1), sVar2 == 1 && (0x27 < local_3c)))) &&
     ((local_30 == 1 && (local_2c == 0)))) {
    if (local_2e == 0x10) {
      fseek(param_1,0,local_8);
      local_40 = (ushort *)Hunk_AllocName(local_28,"SKYBOX");
      if ((local_40 != (ushort *)0x0) && (sVar2 = fread(local_40,local_28,1,param_1), sVar2 != 1)) {
        free(local_40);
        local_40 = (ushort *)0x0;
      }
    }
    else if (local_2e == 8) {
      if (local_1c == 0) {
        local_1c = 0x100;
      }
      __ptr = malloc(local_1c * 4);
      if ((__ptr != (void *)0x0) && (sVar2 = fread(__ptr,local_1c * 4,1,param_1), sVar2 == 1)) {
        local_90 = malloc(local_28);
        fseek(param_1,0,local_8);
        if (local_90 != (byte *)0x0) {
          sVar2 = fread(local_90,local_28,1,param_1);
          if (sVar2 == 1) {
            uVar3 = local_38 + 3;
            if ((int)uVar3 < 0) {
              uVar3 = local_38 + 6;
            }
            uVar3 = uVar3 & 0xfffffffc;
            uVar4 = local_38 + 1U >> 1;
            local_58 = local_34;
            if (local_34 < 0) {
              local_58 = -local_34;
            }
            local_40 = (ushort *)Hunk_AllocName(uVar4 * 4 * local_58,"SKYBOX");
            if (local_40 != (ushort *)0x0) {
              if (param_2 == 0) {
                if (local_34 < 1) {
                  local_94 = local_58 + -1;
                  local_8c = local_40;
                  if (local_94 != -1) {
                    do {
                      local_98 = local_8c;
                      local_9c = local_38 + -1;
                      pbVar7 = local_90;
                      if (local_9c != -1) {
                        do {
                          sVar1 = RandomLong(0,3);
                          uVar6 = (ushort)*(byte *)((int)__ptr + (uint)*pbVar7 * 4 + 2) + sVar1;
                          sVar1 = RandomLong(0,3);
                          uVar5 = (ushort)*(byte *)((int)__ptr + (uint)*pbVar7 * 4 + 1) + sVar1;
                          local_9e = RandomLong(0,3);
                          local_9e = (ushort)*(byte *)((int)__ptr + (uint)*pbVar7 * 4) + local_9e;
                          if (0xff < (short)uVar6) {
                            uVar6 = 0xff;
                          }
                          if (0xff < (short)uVar5) {
                            uVar5 = 0xff;
                          }
                          if (0xff < local_9e) {
                            local_9e = 0xff;
                          }
                          *local_98 = (uVar6 & 0xf8) << 8 | (uVar5 & 0xfc) << 3 | local_9e >> 3;
                          local_98 = local_98 + 1;
                          bVar8 = local_9c != 0;
                          local_9c = local_9c + -1;
                          pbVar7 = pbVar7 + 1;
                        } while (bVar8);
                      }
                      local_8c = local_8c + uVar4 * 2;
                      local_90 = local_90 + uVar3;
                      bVar8 = local_94 != 0;
                      local_94 = local_94 + -1;
                    } while (bVar8);
                  }
                }
                else {
                  local_7c = local_90 + (local_28 - uVar3);
                  local_80 = local_58 + -1;
                  local_78 = local_40;
                  if (local_80 != -1) {
                    do {
                      local_84 = local_78;
                      local_88 = local_38 + -1;
                      pbVar7 = local_7c;
                      if (local_88 != -1) {
                        do {
                          sVar1 = RandomLong(0,3);
                          uVar6 = (ushort)*(byte *)((int)__ptr + (uint)*pbVar7 * 4 + 2) + sVar1;
                          sVar1 = RandomLong(0,3);
                          uVar5 = (ushort)*(byte *)((int)__ptr + (uint)*pbVar7 * 4 + 1) + sVar1;
                          local_9e = RandomLong(0,3);
                          local_9e = (ushort)*(byte *)((int)__ptr + (uint)*pbVar7 * 4) + local_9e;
                          if (0xff < (short)uVar6) {
                            uVar6 = 0xff;
                          }
                          if (0xff < (short)uVar5) {
                            uVar5 = 0xff;
                          }
                          if (0xff < local_9e) {
                            local_9e = 0xff;
                          }
                          *local_84 = (uVar6 & 0xf8) << 8 | (uVar5 & 0xfc) << 3 | local_9e >> 3;
                          local_84 = local_84 + 1;
                          pbVar7 = pbVar7 + 1;
                          bVar8 = local_88 != 0;
                          local_88 = local_88 + -1;
                        } while (bVar8);
                      }
                      local_78 = local_78 + uVar4 * 2;
                      local_7c = local_7c + -uVar3;
                      bVar8 = local_80 != 0;
                      local_80 = local_80 + -1;
                    } while (bVar8);
                  }
                }
              }
              else if (local_34 < 1) {
                local_6c = local_58 + -1;
                local_68 = local_90;
                local_64 = local_40;
                if (local_6c != -1) {
                  do {
                    local_70 = local_64;
                    local_74 = local_38 + -1;
                    pbVar7 = local_68;
                    if (local_74 != -1) {
                      do {
                        sVar1 = RandomLong(0,3);
                        uVar6 = (ushort)*(byte *)((int)__ptr + (uint)*pbVar7 * 4 + 2) + sVar1;
                        sVar1 = RandomLong(0,3);
                        uVar5 = (ushort)*(byte *)((int)__ptr + (uint)*pbVar7 * 4 + 1) + sVar1;
                        local_9e = RandomLong(0,3);
                        local_9e = (ushort)*(byte *)((int)__ptr + (uint)*pbVar7 * 4) + local_9e;
                        if (0xff < (short)uVar6) {
                          uVar6 = 0xff;
                        }
                        if (0xff < (short)uVar5) {
                          uVar5 = 0xff;
                        }
                        if (0xff < local_9e) {
                          local_9e = 0xff;
                        }
                        *local_70 = (uVar6 & 0xf8) << 7 | (uVar5 & 0xf8) << 2 | local_9e >> 3;
                        local_70 = local_70 + 1;
                        bVar8 = local_74 != 0;
                        local_74 = local_74 + -1;
                        pbVar7 = pbVar7 + 1;
                      } while (bVar8);
                    }
                    local_68 = local_68 + uVar3;
                    bVar8 = local_6c != 0;
                    local_6c = local_6c + -1;
                    local_64 = local_64 + uVar4 * 2;
                  } while (bVar8);
                }
              }
              else {
                local_54 = local_90 + (local_28 - uVar3);
                local_58 = local_58 + -1;
                local_50 = local_40;
                if (local_58 != -1) {
                  do {
                    local_5c = local_50;
                    local_60 = local_38 + -1;
                    pbVar7 = local_54;
                    if (local_60 != -1) {
                      do {
                        sVar1 = RandomLong(0,3);
                        uVar6 = (ushort)*(byte *)((int)__ptr + (uint)*pbVar7 * 4 + 2) + sVar1;
                        sVar1 = RandomLong(0,3);
                        uVar5 = (ushort)*(byte *)((int)__ptr + (uint)*pbVar7 * 4 + 1) + sVar1;
                        local_9e = RandomLong(0,3);
                        local_9e = (ushort)*(byte *)((int)__ptr + (uint)*pbVar7 * 4) + local_9e;
                        if (0xff < (short)uVar6) {
                          uVar6 = 0xff;
                        }
                        if (0xff < (short)uVar5) {
                          uVar5 = 0xff;
                        }
                        if (0xff < local_9e) {
                          local_9e = 0xff;
                        }
                        *local_5c = (uVar6 & 0xf8) << 7 | (uVar5 & 0xf8) << 2 | local_9e >> 3;
                        local_5c = local_5c + 1;
                        bVar8 = local_60 != 0;
                        local_60 = local_60 + -1;
                        pbVar7 = pbVar7 + 1;
                      } while (bVar8);
                    }
                    local_50 = local_50 + uVar4 * 2;
                    local_54 = local_54 + -uVar3;
                    bVar8 = local_58 != 0;
                    local_58 = local_58 + -1;
                  } while (bVar8);
                }
              }
            }
          }
          else {
            free(local_90);
            free(__ptr);
          }
        }
      }
    }
  }
  fclose(param_1);
  return local_40;
}


// LoadBMP8  @ 08051e50
void LoadBMP8(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  void *pvVar4;
  size_t __size;
  void *pvVar5;
  size_t __size_00;
  undefined4 *puVar6;
  uint __n;
  undefined1 local_43c [1024];
  int local_3c;
  int local_38;
  int local_34;
  short local_30;
  short local_2e;
  int local_2c;
  int local_1c;
  undefined1 local_14 [4];
  int local_10;
  int local_c;
  
  *param_4 = 0;
  *param_2 = 0;
  iVar1 = Sys_FileRead(param_1[2],local_14,0x10);
  if ((((iVar1 == 0x10) && (local_c == 0)) &&
      (iVar1 = Sys_FileRead(param_1[2],&local_3c,0x28), iVar1 == 0x28)) &&
     (((local_3c == 0x28 && (local_30 == 1)) && ((local_2e == 8 && (local_2c == 0)))))) {
    if (local_1c == 0) {
      local_1c = 0x100;
      iVar1 = 0x400;
    }
    else {
      iVar1 = local_1c * 4;
    }
    iVar2 = Sys_FileRead(param_1[2],local_43c,iVar1);
    if (iVar2 == iVar1) {
      puVar3 = malloc(0x300);
      *param_2 = puVar3;
      if (puVar3 != (undefined4 *)0x0) {
        puVar6 = puVar3;
        for (iVar1 = 0xc0; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
        iVar1 = 0;
        if (0 < local_1c) {
          do {
            iVar2 = iVar1 * 4;
            *(undefined1 *)puVar3 = local_43c[iVar2 + 2];
            *(undefined1 *)((int)puVar3 + 1) = local_43c[iVar2 + 1];
            *(undefined1 *)((int)puVar3 + 2) = local_43c[iVar2];
            puVar3 = (undefined4 *)((int)puVar3 + 3);
            iVar1 = iVar1 + 1;
          } while (iVar1 < local_1c);
        }
        iVar1 = COM_FileTell(*param_1,param_1[1],param_1[2]);
        __size_00 = local_10 - iVar1;
        pvVar4 = malloc(__size_00);
        __size = Sys_FileRead(param_1[2],pvVar4,__size_00);
        if (__size != __size_00) {
          return;
        }
        __n = local_38 + 3U & 0xfffffffc;
        pvVar5 = malloc(__size);
        *param_4 = pvVar5;
        pvVar4 = (void *)((int)pvVar4 + (local_34 + -1) * __n);
        iVar1 = 0;
        if (0 < local_34) {
          do {
            memmove((void *)(__n * iVar1 + (int)pvVar5),pvVar4,__n);
            pvVar4 = (void *)((int)pvVar4 - __n);
            iVar1 = iVar1 + 1;
          } while (iVar1 < local_34);
        }
        free((void *)((int)pvVar4 + __n));
      }
    }
  }
  if (param_1[2] != -1) {
    COM_CloseFile(*param_1,param_1[1],param_1[2]);
  }
  return;
}


// LoadEntityDLLs  @ 08088c20
void LoadEntityDLLs(undefined4 param_1)

{
  char cVar1;
  void *__ptr;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  code *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 local_494;
  char local_490 [256];
  char local_390 [64];
  char local_350 [4];
  undefined2 local_34c;
  char local_310 [260];
  char local_20c [260];
  char local_108 [260];
  
  SV_ResetModInfo();
  g_iextdllMac = 0;
  puVar7 = &g_rgextdll;
  for (iVar6 = 0x96; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  iVar6 = COM_CheckParm();
  if ((iVar6 == 0) || (com_argc + -1 <= iVar6)) {
    builtin_strncpy(local_350,"valv",4);
    local_34c = 0x65;
  }
  else {
    strcpy(local_350,*(char **)(com_argv + 4 + iVar6 * 4));
  }
  iVar6 = strcasecmp(local_350,"valve");
  if (iVar6 != 0) {
    gmodinfo = 1;
  }
  sprintf(local_310,"%s/%s/%s",param_1,local_350);
  iVar6 = Sys_FileOpenRead(local_310,&local_494);
  if (iVar6 == -1) {
    sprintf(local_108,"%s/%s/*.so",param_1,"valve/dlls");
    iVar6 = Sys_FindFirst(local_108,0);
    while (iVar6 != 0) {
      LoadThisDll();
      iVar6 = Sys_FindNext(0);
    }
    Sys_FindClose();
  }
  else {
    if ((iVar6 == 0) || (0x40000 < iVar6)) {
      Sys_Error("Game listing file size is bogus [%s: size %i]","liblist.gam");
    }
    __ptr = malloc(iVar6 + 1);
    if (__ptr == (void *)0x0) {
      Sys_Error("Could not allocate space for game listing file of %i bytes");
    }
    iVar2 = Sys_FileRead(local_494,__ptr);
    if (iVar2 != iVar6) {
      Sys_Error("Error reading in game listing file, expected %i bytes, read %i",iVar6);
    }
    *(undefined1 *)(iVar6 + (int)__ptr) = 0;
    com_ignorecolons = 1;
LAB_08088d90:
    uVar3 = COM_Parse();
    iVar6 = -1;
    pcVar4 = &com_token;
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (iVar6 != -2) {
      strcpy(local_390,&com_token);
      COM_Parse(uVar3);
      strcpy(local_490,&com_token);
      iVar6 = strcasecmp(local_390,"gamedll_linux");
      if (iVar6 == 0) {
        sprintf(local_20c,"%s/%s/%s",param_1,local_350);
        pcVar4 = strstr(local_20c,".so");
        if (pcVar4 == (char *)0x0) {
          Con_Printf("Skipping non-shared library:  %s\n");
        }
        else {
          Con_Printf("Adding:  %s\n");
          LoadThisDll(local_20c);
        }
      }
      else {
        DLL_SetModKey(&gmodinfo,local_390);
      }
      goto LAB_08088d90;
    }
    com_ignorecolons = 0;
    free(__ptr);
    Sys_FileClose(local_494);
  }
  pcVar5 = (code *)GetDispatch();
  if (pcVar5 == (code *)0x0) {
    Sys_Error();
    return;
  }
  iVar6 = (*pcVar5)(&gEntityInterface,0x8a);
  if (iVar6 == 0) {
    Sys_Error();
    return;
  }
  Con_Printf();
  uVar3 = (*DAT_08178f0c)();
  Con_Printf("Dlls loaded for game:\n%s\n",uVar3);
  if (gmodinfo != 0) {
    Con_Printf();
    Con_Printf("Site:  %s\n",&DAT_08178c04);
    Con_Printf("D/L :  %s\n",&DAT_08178d04);
    Con_Printf("Ver.:  %i\n",DAT_08178e24);
    Con_Printf("HL  :  %s\n",&DAT_08178e04);
    Con_Printf("Size:  %.2f MB\n",(double)DAT_08178e28 * 9.5367431640625e-07);
    if (DAT_08178e2c != 0) {
      Con_Printf();
    }
    if (DAT_08178e30 == 0) goto LAB_0808900d;
  }
  Con_Printf();
LAB_0808900d:
  Con_Printf();
  return;
}


// LoadGame  @ 0805b8d0
void LoadGame(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = scr_skipupdate;
  scr_skipupdate = 1;
  Host_Load(param_1);
  scr_skipupdate = uVar1;
  return;
}


// LoadGamestate  @ 0805c660
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 LoadGamestate(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 local_78 [8];
  int local_70;
  float local_60;
  char local_5c [32];
  undefined1 local_3c [32];
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar1 = (int *)LoadSaveData(param_1);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    ParseSaveTables(piVar1,local_78,1);
    EntityPatchRead(piVar1,param_1);
    Cvar_SetValue("skill",(float)local_70);
    strcpy(&DAT_0811d260,local_5c);
    Cvar_Set("sv_skyname",local_3c);
    Cvar_SetValue("cl_skycolor_r",(float)local_1c);
    Cvar_SetValue("cl_skycolor_g",(float)local_18);
    Cvar_SetValue("cl_skycolor_b",(float)local_14);
    Cvar_SetValue("cl_skyvec_x",local_10);
    Cvar_SetValue("cl_skyvec_y",local_c);
    Cvar_SetValue("cl_skyvec_z",local_8);
    if (0 < piVar1[8]) {
      iVar6 = 0;
      do {
        iVar5 = piVar1[10];
        iVar3 = iVar6 * 0x18;
        if (((*(int *)(iVar5 + 0x14 + iVar3) == 0) || (*(int *)(iVar5 + 0xc + iVar3) == 0)) ||
           ((*(byte *)(iVar5 + 0x13 + iVar3) & 0x40) != 0)) {
          *(undefined4 *)(piVar1[10] + 4 + iVar6 * 0x18) = 0;
        }
        else {
          if (*(int *)(iVar5 + iVar3) == 0) {
            uVar2 = *(undefined4 *)(iVar5 + 0x14 + iVar3);
            iVar5 = DAT_0814043c;
LAB_0805c819:
            EntityInit(iVar5,uVar2);
          }
          else if (*(int *)(piVar1[10] + iVar6 * 0x18) < svs + 1) {
            if (-1 < *(int *)(piVar1[10] + 0x10 + iVar6 * 0x18)) {
              Sys_Error("ENTITY IS NOT A PLAYER: %d\n",iVar6);
            }
            iVar5 = *(int *)(*(int *)(piVar1[10] + iVar6 * 0x18) * 0x52b8 + DAT_0816dd10 + -0x3b0);
            if ((param_2 != 0) && (iVar5 != 0)) {
              uVar2 = *(undefined4 *)(piVar1[10] + 0x14 + iVar6 * 0x18);
              goto LAB_0805c819;
            }
            iVar5 = 0;
          }
          else {
            iVar5 = CreateNamedEntity(*(undefined4 *)(piVar1[10] + 0x14 + iVar6 * 0x18));
          }
          *(int *)(piVar1[10] + 4 + iVar6 * 0x18) = iVar5;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < piVar1[8]);
    }
    for (iVar6 = 0; iVar6 < piVar1[8]; iVar6 = iVar6 + 1) {
      iVar4 = iVar6 * 0x18;
      iVar5 = *(int *)(piVar1[10] + 4 + iVar4);
      piVar1[7] = iVar6;
      iVar3 = *(int *)(piVar1[10] + 8 + iVar4);
      piVar1[2] = iVar3;
      piVar1[1] = iVar3 + *piVar1;
      if (iVar5 != 0) {
        iVar3 = (*DAT_08178ec0)(iVar5,piVar1,0);
        if (iVar3 < 0) {
          *(undefined4 *)(piVar1[10] + 4 + iVar4) = 0;
          ED_Free(iVar5);
        }
        else {
          SV_LinkEdict(iVar5,0);
        }
      }
    }
    SaveExit(piVar1);
    _DAT_0811d24c = (double)local_60;
    uVar2 = 1;
  }
  return uVar2;
}


// LoadLump  @ 08081440
long LoadLump(undefined4 param_1,undefined4 param_2)

{
  long *plVar1;
  long lVar2;
  undefined1 local_28 [16];
  undefined1 local_18 [20];
  
  CleanupName(param_1,local_18);
  plVar1 = bsearch(local_28,lumpinfo,nTexLumps,0x24,lump_sorter);
  if (plVar1 == (long *)0x0) {
    Con_SafePrintf("WARNING: texture lump \"%s\" not found\n",param_1);
    lVar2 = 0;
  }
  else {
    fseek((FILE *)(&texfiles)[plVar1[8]],*plVar1,0);
    SafeRead((&texfiles)[plVar1[8]],param_2,plVar1[1]);
    lVar2 = plVar1[1];
  }
  return lVar2;
}


// LoadSaveData  @ 0805c0a0
undefined4 * LoadSaveData(char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  FILE *__stream;
  undefined4 *puVar3;
  void *pvVar4;
  char *pcVar5;
  char *pcVar6;
  int local_11c;
  size_t local_118;
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
      puVar3 = calloc(local_11c + 0x574 + local_114 * 0x18 + local_110,1);
      puVar3[8] = local_114;
      puVar3[5] = local_118;
      puVar3[4] = local_11c;
      strcpy((char *)(puVar3 + 0x155),param_1);
      pcVar6 = (char *)(puVar3 + 0x15d);
      if (0 < local_11c) {
        fread(pcVar6,puVar3[4],1,__stream);
        if (puVar3[6] == 0) {
          pvVar4 = calloc(local_118,4);
          puVar3[6] = pvVar4;
        }
        local_10c = 0;
        if (0 < (int)local_118) {
          do {
            pcVar5 = (char *)0x0;
            if (*pcVar6 != '\0') {
              pcVar5 = pcVar6;
            }
            *(char **)(puVar3[6] + local_10c * 4) = pcVar5;
            do {
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            local_10c = local_10c + 1;
          } while (local_10c < (int)local_118);
        }
      }
      puVar3[10] = pcVar6;
      puVar3[9] = 0;
      pcVar6 = pcVar6 + puVar3[8] * 0x18;
      *puVar3 = pcVar6;
      puVar3[1] = pcVar6;
      puVar3[2] = 0;
      puVar3[3] = local_110;
      puVar3[0x14b] = 1;
      puVar3[0x154] = 0;
      puVar3[0x151] = vec3_origin._0_4_;
      puVar3[0x152] = vec3_origin._4_4_;
      puVar3[0x153] = vec3_origin._8_4_;
      gGlobalVariables._156_4_ = puVar3;
      fread(pcVar6,local_110,1,__stream);
      fclose(__stream);
      return puVar3;
    }
  }
  return (undefined4 *)0x0;
}


// LoadThisDll  @ 08089030
void LoadThisDll(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  int iVar5;
  
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
      (*pcVar4)(g_engfuncsExportedToDlls,gGlobalVariables);
      iVar1 = g_iextdllMac;
      if (g_iextdllMac != 0x32) {
        iVar5 = g_iextdllMac * 0xc;
        g_iextdllMac = g_iextdllMac + 1;
        (&g_rgextdll)[iVar1 * 3] = 0;
        (&DAT_08178964)[iVar1 * 3] = 0;
        *(undefined4 *)(&DAT_08178968 + iVar5) = 0;
        (&g_rgextdll)[iVar1 * 3] = iVar2;
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


// LongNoSwap  @ 0804e3e0
undefined4 LongNoSwap(undefined4 param_1)

{
  return param_1;
}


// LongSwap  @ 0804e3a0
int LongSwap(uint param_1)

{
  return param_1 * 0x1000000 + (param_1 & 0xff00) * 0x100 + (param_1 >> 8 & 0xff00) +
         (param_1 >> 0x18);
}


// MD5Final  @ 0808c840
void MD5Final(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  uVar3 = (uint)param_2[4] >> 3 & 0x3f;
  puVar2 = (undefined1 *)((int)param_2 + uVar3 + 0x18);
  *puVar2 = 0x80;
  puVar2 = puVar2 + 1;
  iVar1 = -uVar3;
  uVar3 = iVar1 + 0x3f;
  if (uVar3 < 8) {
    memset(puVar2,0,uVar3);
    MD5Transform__FPUiPCUi(param_2,param_2 + 6);
    memset(param_2 + 6,0,0x38);
  }
  else {
    memset(puVar2,0,iVar1 + 0x37);
  }
  param_2[0x14] = param_2[4];
  param_2[0x15] = param_2[5];
  MD5Transform__FPUiPCUi(param_2,param_2 + 6);
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  memset(param_2,0,4);
  return;
}


// MD5Init  @ 0808c730
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


// MD5Update  @ 0808c770
void MD5Update(int param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  void *__dest;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  uVar3 = uVar1 + param_3 * 8;
  *(uint *)(param_1 + 0x10) = uVar3;
  if (uVar3 < uVar1) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + (param_3 >> 0x1d);
  uVar3 = uVar1 >> 3 & 0x3f;
  if (uVar3 != 0) {
    __dest = (void *)(param_1 + 0x18 + uVar3);
    uVar3 = 0x40 - uVar3;
    if (param_3 < uVar3) goto LAB_0808c82d;
    memcpy(__dest,param_2,uVar3);
    MD5Transform__FPUiPCUi(param_1,param_1 + 0x18);
    param_2 = (undefined4 *)((int)param_2 + uVar3);
    param_3 = param_3 - uVar3;
  }
  if (0x3f < param_3) {
    do {
      puVar4 = param_2;
      puVar5 = (undefined4 *)(param_1 + 0x18);
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      MD5Transform__FPUiPCUi(param_1,param_1 + 0x18);
      param_2 = param_2 + 0x10;
      param_3 = param_3 - 0x40;
    } while (0x3f < param_3);
  }
  __dest = (void *)(param_1 + 0x18);
LAB_0808c82d:
  memcpy(__dest,param_2,param_3);
  return;
}


// MaskExceptions  @ 080880b0
void MaskExceptions(void)

{
  return;
}


// ModelFrameCount  @ 08061710
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


// ModelFrames  @ 0806bee0
undefined4 ModelFrames(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 - 1U < 0x1ff) {
    uVar1 = ModelFrameCount((&DAT_0813e330)[param_1]);
  }
  else {
    Con_DPrintf("Bad sprite index!\n");
    uVar1 = 1;
  }
  return uVar1;
}


// NameForFunction  @ 08088a10
int NameForFunction(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < g_iextdllMac) {
    do {
      iVar1 = FindAddressInTable(&g_rgextdll + iVar2 * 3,param_1);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < g_iextdllMac);
  }
  Con_Printf("Can\'t find address: %08lx\n",param_1);
  return 0;
}


// NetadrToSockadr  @ 0808abd0
void NetadrToSockadr(int *param_1,undefined4 *param_2)

{
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  if (*param_1 == 2) {
    *(undefined2 *)param_2 = 2;
    *(undefined2 *)((int)param_2 + 2) = *(undefined2 *)((int)param_1 + 0x12);
    param_2[1] = 0xffffffff;
  }
  else if (*param_1 == 3) {
    *(undefined2 *)param_2 = 2;
    param_2[1] = param_1[1];
    *(undefined2 *)((int)param_2 + 2) = *(undefined2 *)((int)param_1 + 0x12);
  }
  return;
}


// PEntityOfEntIndex  @ 080700b0
int * PEntityOfEntIndex(int param_1)

{
  int *piVar1;
  
  if ((-1 < param_1) && (param_1 < DAT_08140438)) {
    piVar1 = (int *)EDICT_NUM(param_1);
    if ((*piVar1 == 0) && (piVar1[0x36] != 0)) {
      return piVar1;
    }
    if ((param_1 < svs) && (*piVar1 == 0)) {
      return piVar1;
    }
  }
  return (int *)0x0;
}


// PEntityOfEntOffset  @ 08070040
int PEntityOfEntOffset(int param_1)

{
  return DAT_0814043c + param_1;
}


// PVSFindEntities  @ 0806d1d0
int * PVSFindEntities(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = *(float *)(param_1 + 0xe4) + *(float *)(param_1 + 0x230);
  local_c = *(float *)(param_1 + 0xe8) + *(float *)(param_1 + 0x234);
  local_8 = *(float *)(param_1 + 0xec) + *(float *)(param_1 + 0x238);
  uVar2 = Mod_PointInLeaf(&local_10,DAT_0811d320);
  uVar2 = Mod_LeafPVS(uVar2,DAT_0811d320);
  PVSMark(DAT_0811d320,uVar2);
  iVar5 = 1;
  piVar6 = DAT_0814043c;
  if (1 < DAT_08140434) {
    do {
      piVar1 = DAT_0814043c + iVar5 * 0xb2;
      if (*piVar1 == 0) {
        piVar4 = piVar1;
        if ((piVar1[0x71] == 0xc) && (piVar1[0x94] != 0)) {
          piVar4 = (int *)piVar1[0x94];
        }
        iVar3 = PVSNode(*(undefined4 *)(DAT_0811d320 + 0xa4),piVar4 + 0x60,piVar4 + 99);
        if (iVar3 != 0) {
          piVar1[0x91] = (int)piVar6;
          piVar6 = piVar1;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < DAT_08140434);
  }
  if (cl._138448_4_ != 0) {
    r_oldviewleaf = 0;
    R_MarkLeaves();
  }
  return piVar6;
}


// PVSMark  @ 0806d150
void PVSMark(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  r_visframecount = r_visframecount + 1;
  uVar2 = 0;
  if (0 < *(int *)(param_1 + 0x88)) {
    do {
      iVar1 = r_visframecount;
      if (((*(byte *)(((int)uVar2 >> 3) + param_2) >> (uVar2 & 7) & 1) != 0) &&
         (iVar3 = *(int *)(param_1 + 0x8c) + 0x30 + uVar2 * 0x30,
         *(int *)(iVar3 + 4) != r_visframecount)) {
        do {
          *(int *)(iVar3 + 4) = iVar1;
          iVar3 = *(int *)(iVar3 + 0x14);
          if (iVar3 == 0) break;
        } while (*(int *)(iVar3 + 4) != r_visframecount);
      }
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < *(int *)(param_1 + 0x88));
  }
  return;
}


// PVSNode  @ 0806d060
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
        fVar2 = *(float *)(param_2 + (uint)*(byte *)(iVar3 + 0x10) * 4);
        if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
          uVar5 = 1;
        }
        else {
          uVar5 = 3;
          if (*(float *)(param_3 + (uint)*(byte *)(iVar3 + 0x10) * 4) <= *(float *)(iVar3 + 0xc)) {
            uVar5 = 2;
          }
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


// ParseDirective  @ 08080800
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
                      _DAT_0816de1c = local_24;
                    }
                  }
                }
                else {
                  iVar1 = ParseFloats(param_1,&local_24,3);
                  if (iVar1 != 0) {
                    _DAT_0816de18 = local_24;
                  }
                }
              }
              else {
                iVar1 = ParseFloats(param_1,&local_24,1);
                if (iVar1 != 0) {
                  _DAT_0816de14 = local_24;
                }
              }
            }
            else {
              iVar1 = ParseFloats(param_1,&local_24,3);
              if (iVar1 != 0) {
                DAT_0816de04._0_1_ = (undefined1)(int)ROUND(local_24);
                DAT_0816de04._1_1_ = (undefined1)(int)ROUND(local_20);
                DAT_0816de04._2_1_ = (undefined1)(int)ROUND(local_1c);
              }
            }
          }
          else {
            iVar1 = ParseFloats(param_1,&local_24,3);
            if (iVar1 != 0) {
              DAT_0816de08 = (undefined1)(int)ROUND(local_24);
              DAT_0816de09 = (undefined1)(int)ROUND(local_20);
              DAT_0816de0a = (undefined1)(int)ROUND(local_1c);
            }
          }
        }
        else {
          iVar1 = ParseFloats(param_1,&local_24,1);
          if (iVar1 != 0) {
            _DAT_0816de20 = local_24;
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
        _DAT_0816de0c = local_24;
        _DAT_0816de10 = local_20;
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}


// ParseFloats  @ 08080690
bool ParseFloats(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  longdouble lVar3;
  
  iVar2 = 0;
  if (param_1 != 0) {
    for (; 0 < param_3; param_3 = param_3 + -1) {
      uVar1 = SkipText(param_1);
      param_1 = SkipSpace(uVar1);
      if (param_1 == 0) break;
      lVar3 = (longdouble)__strtod_internal(param_1,0,0);
      *(float *)(param_2 + iVar2 * 4) = (float)lVar3;
      iVar2 = iVar2 + 1;
    }
  }
  return param_3 == 0;
}


// ParseSaveTables  @ 0805c300
void ParseSaveTables(undefined4 *param_1,int param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  int local_48;
  char local_44 [64];
  
  iVar4 = 0;
  if (0 < (int)param_1[8]) {
    do {
      (*DAT_08178ecc)(param_1,"ETABLE",param_1[10] + iVar4 * 0x18,gEntityTableDescription,5);
      *(undefined4 *)(param_1[10] + 4 + iVar4 * 0x18) = 0;
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)param_1[8]);
  }
  *param_1 = param_1[1];
  param_1[2] = 0;
  (*DAT_08178ecc)(param_1,"Save Header",param_2,gSaveHeaderDescription,0xd);
  param_1[9] = *(undefined4 *)(param_2 + 0x10);
  param_1[0x154] = *(undefined4 *)(param_2 + 0x18);
  param_1[0x14b] = 1;
  param_1[0x151] = vec3_origin._0_4_;
  param_1[0x152] = vec3_origin._4_4_;
  param_1[0x153] = vec3_origin._8_4_;
  if (0 < (int)param_1[9]) {
    iVar4 = 0;
    do {
      (*DAT_08178ecc)(param_1,"ADJACENCY",param_1 + iVar4 * 0x14 + 0xb,gAdjacencyDescription,4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)param_1[9]);
  }
  if (param_3 != 0) {
    iVar4 = 0;
    do {
      (&DAT_08140334)[iVar4] = 0;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x40);
  }
  if (0 < *(int *)(param_2 + 0x14)) {
    iVar4 = 0;
    do {
      (*DAT_08178ecc)(param_1,"LIGHTSTYLE",&local_48,gLightstyleDescription,2);
      if (param_3 != 0) {
        uVar3 = 0xffffffff;
        pcVar2 = local_44;
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          cVar1 = *pcVar2;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        pcVar2 = (char *)Hunk_Alloc(~uVar3);
        (&DAT_08140334)[local_48] = pcVar2;
        strcpy(pcVar2,local_44);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_2 + 0x14));
  }
  return;
}


// PlayerMove  @ 080698b0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PlayerMove(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  DAT_08105164 = param_1;
  frametime = (float)(byte)DAT_081125ac * 0.001;
  DAT_081125d0 = 0;
  AngleVectors(&DAT_08105178,&forward,&right,up);
  if ((param_1 == 0) &&
     ((byte)(0.0 < (float)cl_dumpents._12_4_ |
             (byte)((ushort)((ushort)NAN((float)cl_dumpents._12_4_) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)cl_dumpents._12_4_ == 0.0) << 0xe) >> 8)) != 0x40)) {
    Cvar_SetValue("cl_dumpents",0);
    PM_PrintPhysEnts();
  }
  if (DAT_081051d8 != 0) {
    SpectatorMove();
    return;
  }
  if ((DAT_081051dc != 8) && (iVar1 = PM_CheckStuck(), iVar1 != 0)) {
    return;
  }
  PM_CatagorizePosition();
  if (DAT_08105164 == 0) {
    lastc_177._0_4_ = DAT_0810516c;
    lastc_177._4_4_ = DAT_08105170;
    lastc_177._8_4_ = _DAT_08105174;
  }
  else {
    lasts_176._0_4_ = DAT_0810516c;
    lasts_176._4_4_ = DAT_08105170;
    lasts_176._8_4_ = _DAT_08105174;
  }
  if ((DAT_081051d4 == 0) && ((DAT_081051bc._3_1_ & 1) == 0)) {
    iVar2 = PM_Ladder();
    if (iVar2 == 0) {
      if ((DAT_081051dc != 3) && (DAT_081051dc != 8)) {
        DAT_081051dc = 3;
      }
    }
    else {
      PM_LadderMove(iVar2);
    }
  }
  if ((onground != -1) && ((DAT_081125ca & 0x20) != 0)) {
    VectorScale(&DAT_08105184,0x3e99999a,&DAT_08105184);
  }
  switch(DAT_081051dc) {
  case 0:
    break;
  default:
    Con_DPrintf("Bogus pmove player movetype %i on (%i) 0=cl 1=sv\n",DAT_081051dc,DAT_08105164);
    break;
  case 3:
    iVar1 = PM_CheckWater();
    if ((iVar1 == 0) &&
       ((byte)((byte)((ushort)((ushort)NAN(_DAT_081051d0) << 10) >> 8) |
              (byte)((ushort)((ushort)(_DAT_081051d0 == 0.0) << 0xe) >> 8)) == 0x40)) {
      PM_AddCorrectGravity();
    }
    PM_CheckVelocity();
    PM_CatagorizePosition();
    if ((byte)(0.0 < _DAT_081051d0 | (byte)((ushort)((ushort)NAN(_DAT_081051d0) << 10) >> 8) |
              (byte)((ushort)((ushort)(_DAT_081051d0 == 0.0) << 0xe) >> 8)) != 0x40) {
      PM_WaterJump();
      PM_FlyMove();
      return;
    }
    if (waterlevel < 2) {
      if (onground != -1) {
        _DAT_0810518c = 0.0;
        PM_Friction();
      }
      if ((DAT_081125ca & 2) == 0) {
        DAT_081051cc._0_1_ = (byte)DAT_081051cc & 0xfd;
      }
      else if (iVar2 == 0) {
        JumpButton();
      }
      PM_CheckVelocity();
      PM_CatagorizePosition();
      if (onground == -1) {
        PM_AirMove();
      }
      else {
        PM_WalkMove();
      }
      DAT_08105184 = DAT_08105184 - _DAT_0810519c;
      DAT_08105188 = DAT_08105188 - _DAT_081051a0;
      _DAT_0810518c = _DAT_0810518c - _DAT_081051a4;
      PM_CheckVelocity();
      iVar2 = PM_CheckWater();
      if ((iVar2 == 0) &&
         ((byte)((byte)((ushort)((ushort)NAN(_DAT_081051d0) << 10) >> 8) |
                (byte)((ushort)((ushort)(_DAT_081051d0 == 0.0) << 0xe) >> 8)) == 0x40)) {
        PM_FixupGravityVelocity();
      }
      PM_CatagorizePosition();
      if (onground == -1) {
        return;
      }
      _DAT_0810518c = 0.0;
      return;
    }
    if ((waterlevel == 2) &&
       ((byte)((byte)((ushort)((ushort)NAN(_DAT_081051d0) << 10) >> 8) |
              (byte)((ushort)((ushort)(_DAT_081051d0 == 0.0) << 0xe) >> 8)) == 0x40)) {
      CheckWaterJump();
    }
    if ((_DAT_0810518c < 0.0) &&
       ((byte)(_DAT_081051d0 < 0.0 | (byte)((ushort)((ushort)NAN(_DAT_081051d0) << 10) >> 8) |
              (byte)((ushort)((ushort)(_DAT_081051d0 == 0.0) << 0xe) >> 8)) != 0x40)) {
      _DAT_081051d0 = 0.0;
    }
    if ((DAT_081125ca & 2) == 0) {
      DAT_081051cc._0_1_ = (byte)DAT_081051cc & 0xfd;
    }
    else {
      JumpButton();
    }
    PM_WaterMove();
    goto LAB_08069bdc;
  case 5:
    PM_CheckWater();
    if ((DAT_081125ca & 2) == 0) {
      DAT_081051cc._0_1_ = (byte)DAT_081051cc & 0xfd;
    }
    else if (iVar2 == 0) {
      JumpButton();
    }
    DAT_08105184 = DAT_08105184 + _DAT_0810519c;
    DAT_08105188 = DAT_08105188 + _DAT_081051a0;
    _DAT_0810518c = _DAT_0810518c + _DAT_081051a4;
    PM_FlyMove();
LAB_08069bdc:
    DAT_08105184 = DAT_08105184 - _DAT_0810519c;
    DAT_08105188 = DAT_08105188 - _DAT_081051a0;
    _DAT_0810518c = _DAT_0810518c - _DAT_081051a4;
    break;
  case 6:
  case 10:
    PM_Physics_Toss();
    break;
  case 8:
    PM_NoClip();
  }
  return;
}


// PrintFrameName  @ 0805e370
void PrintFrameName(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = Mod_Extradata(param_1);
  if (iVar1 != 0) {
    Con_Printf("frame %i: %s\n",param_2,iVar1 + 0x24 + param_2 * 0x20);
  }
  return;
}


// ProcessorSpeed  @ 080892f0
int ProcessorSpeed(void)

{
  FILE *__stream;
  int iVar1;
  char *pcVar2;
  longdouble lVar3;
  char local_104 [256];
  
  if (wasread_239 == 0) {
    wasread_239 = 1;
    __stream = fopen("/proc/cpuinfo","r");
    if (__stream == (FILE *)0x0) {
      return 0;
    }
    do {
      pcVar2 = fgets(local_104,0x100,__stream);
      if (pcVar2 == (char *)0x0) {
        fclose(__stream);
        return 0;
      }
      iVar1 = strncmp(local_104,"bogomips",8);
    } while ((iVar1 != 0) || (pcVar2 = strrchr(local_104,0x20), pcVar2 == (char *)0x0));
    lVar3 = (longdouble)__strtod_internal(pcVar2 + 1,0,0);
    speed_238 = (float)lVar3;
    fclose(__stream);
  }
  return (int)ROUND(speed_238);
}


// PvAllocEntPrivateData  @ 0806ffb0
void * PvAllocEntPrivateData(int param_1,size_t param_2)

{
  void *pvVar1;
  
  FreeEntPrivateData(param_1);
  if ((int)param_2 < 1) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = calloc(1,param_2);
    *(void **)(param_1 + 0xd8) = pvVar1;
  }
  return pvVar1;
}


// PvEntPrivateData  @ 0806fff0
undefined4 PvEntPrivateData(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0xd8);
  }
  return uVar1;
}


// QuaternionMatrix  @ 0805feb0
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


// QuaternionSlerp  @ 0805fd00
void QuaternionSlerp(float *param_1,float *param_2,float param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  longdouble lVar7;
  longdouble lVar8;
  
  lVar4 = (longdouble)param_3;
  fVar1 = 0.0;
  iVar3 = 0;
  fVar2 = fVar1;
  do {
    fVar1 = (param_1[iVar3] - param_2[iVar3]) * (param_1[iVar3] - param_2[iVar3]) + fVar1;
    fVar2 = (param_1[iVar3] + param_2[iVar3]) * (param_1[iVar3] + param_2[iVar3]) + fVar2;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1) {
    iVar3 = 0;
    do {
      param_2[iVar3] = -param_2[iVar3];
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
  }
  lVar8 = (longdouble)param_1[3] * (longdouble)param_2[3] +
          (longdouble)param_1[2] * (longdouble)param_2[2] +
          (longdouble)param_1[1] * (longdouble)param_2[1] +
          (longdouble)*param_1 * (longdouble)*param_2;
  cosom = (float)lVar8;
  lVar7 = (longdouble)1;
  lVar5 = lVar8 + lVar7;
  lVar6 = (longdouble)1e-06;
  if ((byte)(lVar6 < lVar5 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) == 1) {
    if (lVar7 - lVar8 <= lVar6) {
      lVar7 = (longdouble)1 - lVar4;
      sclq = param_3;
    }
    else {
      lVar5 = (longdouble)fpatan((longdouble)(double)SQRT(lVar7 - lVar8 * lVar8),lVar8);
      omega = (float)lVar5;
      lVar5 = (longdouble)fsin((longdouble)omega);
      sinom = (float)lVar5;
      lVar7 = (longdouble)fsin((lVar7 - lVar4) * (longdouble)omega);
      lVar7 = lVar7 / (longdouble)sinom;
      lVar4 = (longdouble)fsin(lVar4 * (longdouble)omega);
      sclq = (float)(lVar4 / (longdouble)sinom);
    }
    fVar2 = sclq;
    sclp = (float)lVar7;
    fVar1 = sclp;
    iVar3 = 0;
    do {
      param_4[iVar3] = fVar2 * param_2[iVar3] + fVar1 * param_1[iVar3];
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
  }
  else {
    *param_4 = -param_2[1];
    param_4[1] = *param_2;
    param_4[2] = -param_2[3];
    param_4[3] = param_2[2];
    lVar7 = (longdouble)fsin(((longdouble)1 - lVar4) * (longdouble)1.5707963267948966);
    lVar4 = (longdouble)fsin((longdouble)1.5707963267948966 * lVar4);
    iVar3 = 0;
    sclp = (float)lVar7;
    sclq = (float)lVar4;
    do {
      param_4[iVar3] = (float)lVar4 * param_4[iVar3] + (float)lVar7 * param_1[iVar3];
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
  }
  return;
}


// RadiusFromBounds  @ 08064670
void RadiusFromBounds(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float local_10 [3];
  
  iVar4 = 0;
  do {
    fVar1 = *(float *)(param_1 + iVar4 * 4);
    fVar2 = ABS(fVar1);
    fVar3 = ABS(*(float *)(param_2 + iVar4 * 4));
    if ((byte)(fVar3 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar3 == fVar2) << 0xe) >> 8)) != 1) {
      fVar1 = *(float *)(param_2 + iVar4 * 4);
    }
    local_10[iVar4] = ABS(fVar1);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  Length(local_10);
  return;
}


// RandomFloat  @ 0806f3d0
longdouble RandomFloat(float param_1,float param_2)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)fran1();
  return ((longdouble)param_2 - (longdouble)param_1) * lVar1 + (longdouble)param_1;
}


// RandomLong  @ 0806f3f0
int RandomLong(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (param_2 - param_1) + 1;
  if (-1 < param_2 - param_1) {
    do {
      uVar1 = ran1();
    } while (0x7fffffffU - (int)(0x80000000 % (ulonglong)uVar2) < uVar1);
    param_1 = uVar1 % uVar2 + param_1;
  }
  return param_1;
}


// RegUserMsg  @ 080788d0
int RegUserMsg(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  char *pcVar5;
  
  if ((giNextUserMsg < 0x100) && (param_1 != (char *)0x0)) {
    uVar4 = 0xffffffff;
    pcVar5 = param_1;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    if ((~uVar4 - 1 < 0xc) && (piVar3 = sv_gpUserMsgs, param_2 < 0xc1)) {
      for (; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[5]) {
        iVar2 = strcmp(param_1,(char *)(piVar3 + 2));
        if (iVar2 == 0) goto LAB_08078972;
      }
      piVar3 = malloc(0x18);
      *piVar3 = giNextUserMsg;
      giNextUserMsg = giNextUserMsg + 1;
      piVar3[1] = param_2;
      strcpy((char *)(piVar3 + 2),param_1);
      if (piVar3 != (int *)0x0) {
        piVar3[5] = (int)sv_gpNewUserMsgs;
        sv_gpNewUserMsgs = piVar3;
LAB_08078972:
        return *piVar3;
      }
    }
  }
  return 0;
}


// ReleaseEntityDLLFields  @ 0806ff90
void ReleaseEntityDLLFields(undefined4 param_1)

{
  FreeEntPrivateData(param_1);
  return;
}


// ReleaseEntityDlls  @ 08089130
void ReleaseEntityDlls(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = g_iextdllMac * 3;
  for (puVar2 = &g_rgextdll; puVar2 < &g_rgextdll + iVar1; puVar2 = puVar2 + 3) {
    dlclose(*puVar2);
    *puVar2 = 0;
  }
  return;
}


// RemoveLink  @ 0804dbb0
void RemoveLink(int *param_1)

{
  *(int *)param_1[1] = *param_1;
  *(int *)(*param_1 + 4) = param_1[1];
  return;
}


// ResetStuckOffsets  @ 08068530
void ResetStuckOffsets(int param_1,int param_2)

{
  *(undefined4 *)(rgStuckLast + param_2 * 4 + param_1 * 8) = 0;
  return;
}


// SafeRead  @ 08080fe0
void SafeRead(FILE *param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  
  sVar1 = fread(param_2,1,param_3,param_1);
  if (sVar1 != param_3) {
    Sys_Error("File read failure");
  }
  return;
}


// SaveExit  @ 0805b340
void SaveExit(void *param_1)

{
  if (*(int *)((int)param_1 + 0x18) != 0) {
    free(*(void **)((int)param_1 + 0x18));
    *(undefined4 *)((int)param_1 + 0x18) = 0;
    *(undefined4 *)((int)param_1 + 0x14) = 0;
  }
  if (param_1 != (void *)0x0) {
    free(param_1);
  }
  gGlobalVariables._156_4_ = 0;
  return;
}


// SaveGame  @ 0805b6a0
void SaveGame(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = scr_skipupdate;
  scr_skipupdate = 1;
  SaveGameSlot(param_1,param_2);
  scr_skipupdate = uVar1;
  return;
}


// SaveGameSlot  @ 0805b390
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 SaveGameSlot(char *param_1,char *param_2)

{
  char cVar1;
  void *__ptr;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  FILE *__s;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  int local_284;
  undefined4 local_27c;
  char local_278 [32];
  char local_258 [80];
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
    strcpy(local_278,&DAT_0811d260);
    strcpy(local_258,param_2);
    (*DAT_08178ec8)(puVar4,"GameHeader",local_278,gGameHeaderDescription,3);
    (*_DAT_08178ed0)(puVar4);
    __ptr = (void *)puVar4[1];
    if (puVar4[6] != 0) {
      for (local_284 = 0; local_284 < (int)puVar4[5]; local_284 = local_284 + 1) {
        if (*(int *)(puVar4[6] + local_284 * 4) == 0) {
          puVar4[2] = puVar4[2] + 1;
          if ((int)puVar4[3] < (int)puVar4[2]) goto LAB_0805b3b0;
          *(undefined1 *)puVar4[1] = 0;
          puVar4[1] = puVar4[1] + 1;
        }
        else {
          pcVar6 = *(char **)(puVar4[6] + local_284 * 4);
          uVar5 = 0xffffffff;
          pcVar7 = pcVar6;
          do {
            if (uVar5 == 0) break;
            uVar5 = uVar5 - 1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + 1;
          } while (cVar1 != '\0');
          iVar2 = puVar4[2];
          puVar4[2] = ~uVar5 + iVar2;
          if ((int)puVar4[3] < (int)(~uVar5 + iVar2)) {
LAB_0805b3b0:
            Con_Printf("Token Table Save/Restore overflow!");
            puVar4[2] = puVar4[3];
            break;
          }
          cVar1 = *pcVar6;
          *(char *)puVar4[1] = cVar1;
          puVar4[1] = puVar4[1] + 1;
          while (cVar1 != '\0') {
            pcVar6 = pcVar6 + 1;
            cVar1 = *pcVar6;
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
    COM_DefaultExtension(local_204,&DAT_080a1123);
    COM_FixSlashes(local_204);
    Con_DPrintf("Saving game to %s...\n",local_204);
    iVar2 = strcasecmp(param_1,"quick");
    if ((iVar2 != 0) || (iVar2 = strcasecmp(param_1,"autosave"), iVar2 != 0)) {
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


// SaveGamestate  @ 0805bab0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  char local_1b8 [64];
  undefined1 local_178 [4];
  undefined4 local_174;
  int local_170;
  undefined4 local_16c;
  undefined4 local_168;
  int local_164;
  float local_160;
  char local_15c [32];
  char local_13c [32];
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  char local_104 [256];
  
  if (DAT_08178f08 != (code *)0x0) {
    puVar5 = (undefined4 *)SaveInit(0);
    uVar6 = Host_SaveGameDirectory(&DAT_0811d260);
    sprintf(local_104,"%s%s.HL1",uVar6);
    COM_FixSlashes(local_104);
    (*DAT_08178f08)();
    local_174 = build_number();
    _local_1c0 = CONCAT22(uStack_1be,in_FPUControlWord);
    local_1c8 = (int)ROUND((float)skill._12_4_);
    local_16c = puVar5[8];
    local_168 = puVar5[9];
    local_1cc = (float)_DAT_0811d24c;
    local_170 = local_1c8;
    local_160 = local_1cc;
    strcpy(local_13c,(char *)sv_skyname._4_4_);
    local_108 = 0;
    local_10c = 0;
    local_110 = 0;
    local_114 = 0;
    local_118 = 0;
    local_11c = 0;
    puVar5[0x154] = 0;
    strcpy(local_15c,&DAT_0811d260);
    local_164 = 0;
    local_1d0 = 0;
    do {
      if ((&DAT_08140334)[local_1d0] != 0) {
        local_164 = local_164 + 1;
      }
      local_1d0 = local_1d0 + 1;
    } while (local_1d0 < 0x40);
    (*DAT_08178ec8)(puVar5,"Save Header",local_178,gSaveHeaderDescription,0xd);
    puVar5[0x154] = local_160;
    for (local_1d0 = 0; local_1d0 < (int)puVar5[9]; local_1d0 = local_1d0 + 1) {
      (*DAT_08178ec8)(puVar5,"ADJACENCY",puVar5 + local_1d0 * 0x14 + 0xb,gAdjacencyDescription,4);
    }
    local_1d0 = 0;
    do {
      if ((&DAT_08140334)[local_1d0] != 0) {
        local_1bc = local_1d0;
        strcpy(local_1b8,(char *)(&DAT_08140334)[local_1d0]);
        (*DAT_08178ec8)(puVar5,"LIGHTSTYLE",&local_1bc,gLightstyleDescription,2);
      }
      local_1d0 = local_1d0 + 1;
    } while (local_1d0 < 0x40);
    local_1d0 = 0;
    if (0 < DAT_08140434) {
      do {
        piVar1 = (int *)(DAT_0814043c + local_1d0 * 0x2c8);
        puVar5[7] = local_1d0;
        *(undefined4 *)(puVar5[10] + 8 + local_1d0 * 0x18) = puVar5[2];
        *(undefined4 *)(puVar5[10] + 0xc + local_1d0 * 0x18) = 0;
        if (((*piVar1 == 0) && ((*DAT_08178ebc)(piVar1,puVar5), 0 < local_1d0)) &&
           (local_1d0 < svs + 1)) {
          pbVar2 = (byte *)(puVar5[10] + 0x13 + local_1d0 * 0x18);
          *pbVar2 = *pbVar2 | 0x80;
        }
        local_1d0 = local_1d0 + 1;
      } while (local_1d0 < DAT_08140434);
    }
    __size = puVar5[2];
    __ptr = (void *)puVar5[1];
    for (local_1d0 = 0; local_1d0 < DAT_08140434; local_1d0 = local_1d0 + 1) {
      (*DAT_08178ec8)(puVar5,"ETABLE",puVar5[10] + local_1d0 * 0x18,gEntityTableDescription,5);
    }
    iVar4 = puVar5[2];
    __ptr_00 = (void *)puVar5[1];
    if ((puVar5[6] != 0) && (local_1d0 = 0, 0 < (int)puVar5[5])) {
      do {
        if (*(int *)(puVar5[6] + local_1d0 * 4) == 0) {
          *(undefined1 *)puVar5[1] = 0;
          puVar5[1] = puVar5[1] + 1;
        }
        else {
          pcVar7 = *(char **)(puVar5[6] + local_1d0 * 4);
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
      EntityPatchWrite(puVar5,&DAT_0811d260);
      uVar6 = Host_SaveGameDirectory(&DAT_0811d260);
      sprintf(local_104,"%s%s.HL2",uVar6);
      COM_FixSlashes(local_104);
      CL_Save(local_104);
      return puVar5;
    }
    Con_Printf("Unable to open save game file %s.",local_104);
  }
  return (undefined4 *)0x0;
}


// SaveInit  @ 0805b200
int * SaveInit(int param_1)

{
  int iVar1;
  int *piVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 < 1) {
    param_1 = 0x80000;
  }
  piVar2 = calloc(param_1 + 0x574 + DAT_08140434 * 0x18,1);
  piVar2[10] = (int)(piVar2 + 0x15d);
  piVar2[4] = 0;
  piVar2[5] = 0xfff;
  pvVar3 = calloc(0xfff,4);
  piVar2[6] = (int)pvVar3;
  iVar5 = 0;
  if (0 < DAT_08140434) {
    do {
      iVar1 = DAT_0814043c + iVar5 * 0x2c8;
      iVar4 = iVar5 * 0x18;
      *(int *)(piVar2[10] + iVar4) = iVar5;
      *(int *)(piVar2[10] + 4 + iVar4) = iVar1;
      *(undefined4 *)(piVar2[10] + 0x10 + iVar4) = 0;
      *(undefined4 *)(piVar2[10] + 8 + iVar4) = 0;
      *(undefined4 *)(piVar2[10] + 0xc + iVar4) = 0;
      *(undefined4 *)(piVar2[10] + 0x14 + iVar4) = 0;
      iVar5 = iVar5 + 1;
    } while (iVar5 < DAT_08140434);
  }
  iVar5 = DAT_08140434;
  piVar2[8] = DAT_08140434;
  piVar2[9] = 0;
  iVar5 = piVar2[10] + iVar5 * 0x18;
  *piVar2 = iVar5;
  piVar2[1] = iVar5;
  piVar2[2] = 0;
  piVar2[3] = param_1;
  piVar2[0x154] = gGlobalVariables._0_4_;
  piVar2[0x151] = vec3_origin._0_4_;
  piVar2[0x152] = vec3_origin._4_4_;
  piVar2[0x153] = vec3_origin._8_4_;
  piVar2[0x14b] = 0;
  gGlobalVariables._156_4_ = piVar2;
  return piVar2;
}


// SaveReadComment  @ 0805b850
void SaveReadComment(undefined4 param_1,char *param_2)

{
  int iVar1;
  undefined1 local_78 [32];
  char local_58 [84];
  
  iVar1 = SaveReadHeader(param_1,local_78,0);
  if (iVar1 != 0) {
    strcpy(param_2,local_58);
  }
  return;
}


// SaveReadHeader  @ 0805b6d0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 SaveReadHeader(FILE *param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  void *pvVar4;
  char *pcVar5;
  int iVar6;
  char *__ptr;
  size_t local_14;
  size_t local_10;
  size_t local_c;
  int local_8;
  
  fread(&local_8,4,1,param_1);
  if ((local_8 == 0x5641534a) && (fread(&local_8,4,1,param_1), local_8 == 0x71)) {
    fread(&local_c,4,1,param_1);
    fread(&local_10,4,1,param_1);
    fread(&local_14,4,1,param_1);
    puVar3 = calloc(local_c + 0x574 + local_14,1);
    puVar3[8] = 0;
    puVar3[10] = 0;
    puVar3[9] = 0;
    __ptr = (char *)(puVar3 + 0x15d);
    if (0 < (int)local_14) {
      puVar3[5] = local_10;
      puVar3[4] = local_14;
      fread(__ptr,local_14,1,param_1);
      if (puVar3[6] == 0) {
        pvVar4 = calloc(local_10,4);
        puVar3[6] = pvVar4;
      }
      iVar6 = 0;
      if (0 < (int)local_10) {
        do {
          pcVar5 = (char *)0x0;
          if (*__ptr != '\0') {
            pcVar5 = __ptr;
          }
          *(char **)(puVar3[6] + iVar6 * 4) = pcVar5;
          do {
            cVar1 = *__ptr;
            __ptr = __ptr + 1;
          } while (cVar1 != '\0');
          iVar6 = iVar6 + 1;
        } while (iVar6 < (int)local_10);
      }
    }
    puVar3[2] = 0;
    puVar3[3] = local_c;
    puVar3[0x14b] = 0;
    puVar3[0x154] = 0;
    puVar3[1] = __ptr;
    *puVar3 = __ptr;
    fread(__ptr,local_c,1,param_1);
    (*DAT_08178ecc)(puVar3,"GameHeader",param_2,gGameHeaderDescription,3);
    if (param_3 != 0) {
      (*_DAT_08178ed4)(puVar3);
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


// SaveSpawnParms  @ 08070220
void SaveSpawnParms(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = NUM_FOR_EDICT(param_1);
  if ((iVar1 < 1) || (svs < iVar1)) {
    Host_Error("Entity is not a client");
  }
  return;
}


// SeedRandomNumberGenerator  @ 0806f190
void SeedRandomNumberGenerator(void)

{
  int iVar1;
  
  idum = time((time_t *)0x0);
  iVar1 = -idum;
  if ((idum == -1000 || iVar1 < 1000) && (idum = iVar1, -1000 < iVar1)) {
    idum = iVar1 + -0x153ad38;
  }
  return;
}


// ServerPrint  @ 0806bfb0
void ServerPrint(undefined4 param_1)

{
  Con_Printf(&DAT_080a2e6c,param_1);
  return;
}


// SetMessagePumpDisableMode  @ 08088840
void SetMessagePumpDisableMode(undefined4 param_1)

{
  g_bInactive = param_1;
  return;
}


// SetMinMaxSize  @ 0806bd40
void SetMinMaxSize(int param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  
  iVar6 = 0;
  do {
    if (param_3[iVar6] < param_2[iVar6]) {
      Host_Error("backwards mins/maxs");
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 3);
  fVar1 = param_2[1];
  fVar2 = param_2[2];
  fVar3 = *param_3;
  fVar4 = param_3[1];
  fVar5 = param_3[2];
  *(float *)(param_1 + 0x198) = *param_2;
  *(float *)(param_1 + 0x19c) = fVar1;
  *(float *)(param_1 + 0x1a0) = fVar2;
  *(float *)(param_1 + 0x1a4) = fVar3;
  *(float *)(param_1 + 0x1a8) = fVar4;
  *(float *)(param_1 + 0x1ac) = fVar5;
  *(float *)(param_1 + 0x1b0) = *param_3 - *param_2;
  *(float *)(param_1 + 0x1b4) = param_3[1] - param_2[1];
  *(float *)(param_1 + 0x1b8) = param_3[2] - param_2[2];
  SV_LinkEdict(param_1,0);
  return;
}


// SetPauseState  @ 08088850
void SetPauseState(int param_1)

{
  if (param_1 == 0) {
    if (gLauncherPause != 0) {
      DAT_0811d244 = g_bPaused;
    }
    gLauncherPause = 0;
  }
  else {
    if (gLauncherPause == 0) {
      g_bPaused = DAT_0811d244;
    }
    DAT_0811d244 = 1;
    gLauncherPause = 1;
  }
  return;
}


// SetStartupMode  @ 08088830
void SetStartupMode(undefined4 param_1)

{
  g_bInStartup = param_1;
  return;
}


// ShortNoSwap  @ 0804e390
int ShortNoSwap(short param_1)

{
  return (int)param_1;
}


// ShortSwap  @ 0804e370
int ShortSwap(undefined4 param_1)

{
  return (int)(short)((short)param_1 * 0x100 + ((ushort)((uint)param_1 >> 8) & 0xff));
}


// SkipSpace  @ 08080600
char * SkipSpace(char *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == (char *)0x0) {
    param_1 = (char *)0x0;
  }
  else {
    iVar3 = 0;
    cVar1 = *param_1;
    while ((cVar1 != '\0' && (iVar2 = IsWhiteSpace((int)param_1[iVar3]), iVar2 != 0))) {
      iVar3 = iVar3 + 1;
      cVar1 = param_1[iVar3];
    }
    param_1 = param_1 + iVar3;
  }
  return param_1;
}


// SkipText  @ 08080650
int SkipText(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    for (iVar2 = 0; *(char *)(iVar2 + param_1) != '\0'; iVar2 = iVar2 + 1) {
      iVar1 = IsWhiteSpace((int)*(char *)(iVar2 + param_1));
      if (iVar1 != 0) break;
    }
    iVar2 = iVar2 + param_1;
  }
  return iVar2;
}


// SockadrToNetadr  @ 0808ac30
void SockadrToNetadr(short *param_1,undefined4 *param_2)

{
  if (*param_1 == 2) {
    *param_2 = 3;
    param_2[1] = *(undefined4 *)(param_1 + 2);
    *(short *)((int)param_2 + 0x12) = param_1[1];
  }
  return;
}


// SpectatorMove  @ 080688f0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SpectatorMove(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  float local_1c [6];
  
  lVar4 = (longdouble)Length(&DAT_08105184);
  if ((longdouble)1 <= lVar4) {
    lVar6 = (longdouble)(float)movevars._8_4_;
    lVar5 = lVar4;
    if ((byte)(lVar4 < lVar6 | (byte)((ushort)((ushort)(NAN(lVar4) || NAN(lVar6)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar4 == lVar6) << 0xe) >> 8)) == 1) {
      lVar5 = (longdouble)(float)movevars._8_4_;
    }
    lVar6 = lVar4 - (lVar5 * (longdouble)((float)movevars._32_4_ * 1.5) * (longdouble)frametime +
                    (longdouble)0);
    if (lVar6 < (longdouble)0) {
      lVar6 = (longdouble)0;
    }
    VectorScale(&DAT_08105184,(float)(lVar6 / lVar4),&DAT_08105184);
  }
  else {
    DAT_08105184 = (float)vec3_origin._0_4_;
    DAT_08105188 = (float)vec3_origin._4_4_;
    _DAT_0810518c = (float)vec3_origin._8_4_;
  }
  fVar2 = _DAT_081125c0;
  fVar1 = _DAT_081125bc;
  VectorNormalize(&forward);
  VectorNormalize(&right);
  iVar3 = 0;
  do {
    local_1c[iVar3 + 3] = fVar2 * (float)(&right)[iVar3] + fVar1 * (float)(&forward)[iVar3];
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  local_1c[2] = local_1c[5] + _DAT_081125c4;
  local_1c[0] = local_1c[3];
  local_1c[1] = local_1c[4];
  local_1c[5] = local_1c[2];
  lVar4 = (longdouble)VectorNormalize(local_1c);
  if ((longdouble)(float)movevars._16_4_ < lVar4) {
    VectorScale(local_1c + 3,(float)((longdouble)(float)movevars._16_4_ / lVar4),local_1c + 3);
    lVar4 = (longdouble)(float)movevars._16_4_;
  }
  lVar6 = lVar4 - ((longdouble)_DAT_0810518c * (longdouble)local_1c[2] +
                  (longdouble)DAT_08105188 * (longdouble)local_1c[1] +
                  (longdouble)DAT_08105184 * (longdouble)local_1c[0]);
  if ((longdouble)0 < lVar6) {
    lVar4 = (longdouble)(float)movevars._20_4_ * (longdouble)frametime * lVar4;
    if ((byte)(lVar6 < lVar4 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar4)) << 10) >> 8) |
              (byte)((ushort)((ushort)(lVar6 == lVar4) << 0xe) >> 8)) == 1) {
      lVar4 = lVar6;
    }
    iVar3 = 0;
    do {
      (&DAT_08105184)[iVar3] =
           (float)(lVar4 * (longdouble)local_1c[iVar3] + (longdouble)(&DAT_08105184)[iVar3]);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
    VectorMA(&DAT_0810516c,frametime,&DAT_08105184,&DAT_0810516c);
  }
  return;
}


// StringToFilter  @ 08078bb0
undefined4 StringToFilter(char *param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 local_8c;
  undefined4 local_88;
  char local_84 [128];
  
  iVar3 = 0;
  do {
    local_84[iVar3 + -4] = '\0';
    *(undefined1 *)((int)&local_8c + iVar3) = 0;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  iVar3 = 0;
  do {
    if (9 < (byte)(*param_1 - 0x30U)) {
      Con_Printf("Bad filter address: %s\n",param_1);
      return 0;
    }
    iVar2 = 0;
    cVar1 = *param_1;
    while ((byte)(cVar1 - 0x30U) < 10) {
      local_84[iVar2] = cVar1;
      param_1 = param_1 + 1;
      iVar2 = iVar2 + 1;
      cVar1 = *param_1;
    }
    local_84[iVar2] = '\0';
    cVar1 = __strtol_internal(local_84,0,10,0);
    local_84[iVar3 + -4] = cVar1;
    if (cVar1 != '\0') {
      *(undefined1 *)((int)&local_8c + iVar3) = 0xff;
    }
    if (*param_1 == '\0') break;
    param_1 = param_1 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  *param_2 = local_8c;
  param_2[1] = local_88;
  return 1;
}


// SuckOutClassname  @ 0806fec0
void SuckOutClassname(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  bool bVar7;
  undefined4 local_114;
  byte *local_110;
  undefined1 *local_10c;
  int local_108;
  byte local_104 [256];
  
  do {
    uVar1 = COM_Parse(param_1);
    if (com_token == '}') {
      return;
    }
    strcpy((char *)local_104,&com_token);
    param_1 = COM_Parse(uVar1);
    iVar3 = 10;
    bVar6 = false;
    uVar2 = 0;
    bVar7 = true;
    pbVar4 = local_104;
    pbVar5 = (byte *)"classname";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pbVar4 < *pbVar5;
      bVar7 = *pbVar4 == *pbVar5;
      pbVar4 = pbVar4 + 1;
      pbVar5 = pbVar5 + 1;
    } while (bVar7);
    if (!bVar7) {
      uVar2 = -(uint)bVar6 | 1;
    }
    if (uVar2 == 0) {
      local_114 = 0;
      local_110 = local_104;
      local_10c = &com_token;
      local_108 = 0;
      (*DAT_08178eb8)(param_2,&local_114);
      if (local_108 == 0) {
        Host_Error("SuckOutClassname: parse error");
      }
      return;
    }
  } while( true );
}


// SurfaceAtPoint  @ 0806c6f0
int SurfaceAtPoint(int param_1,int *param_2,float *param_3,float *param_4)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  float local_10;
  float local_c;
  float local_8;
  
  if (*param_2 < 0) {
    iVar6 = 0;
  }
  else {
    pfVar3 = (float *)param_2[6];
    fVar4 = (param_3[2] * pfVar3[2] + param_3[1] * pfVar3[1] + *param_3 * *pfVar3) - pfVar3[3];
    fVar5 = (param_4[2] * pfVar3[2] + param_4[1] * pfVar3[1] + *param_4 * *pfVar3) - pfVar3[3];
    uVar7 = (uint)(fVar4 < 0.0);
    if (fVar5 < 0.0 == uVar7) {
      iVar6 = param_2[uVar7 + 7];
    }
    else {
      fVar4 = fVar4 / (fVar4 - fVar5);
      local_10 = (*param_4 - *param_3) * fVar4 + *param_3;
      local_c = (param_4[1] - param_3[1]) * fVar4 + param_3[1];
      local_8 = (param_4[2] - param_3[2]) * fVar4 + param_3[2];
      iVar6 = SurfaceAtPoint(param_1,param_2[uVar7 + 7],param_3,&local_10);
      if (iVar6 != 0) {
        return iVar6;
      }
      if (fVar5 < 0.0 == uVar7) {
        return 0;
      }
      iVar6 = *(int *)(param_1 + 0xb4) + (uint)*(ushort *)(param_2 + 9) * 0x44;
      iVar8 = 0;
      if (*(short *)((int)param_2 + 0x26) != 0) {
        do {
          pfVar3 = *(float **)(iVar6 + 0x34);
          iVar1 = (int)ROUND(local_8 * pfVar3[2] + local_c * pfVar3[1] + local_10 * *pfVar3 +
                             pfVar3[3]);
          iVar2 = (int)ROUND(local_8 * pfVar3[6] + local_c * pfVar3[5] + local_10 * pfVar3[4] +
                             pfVar3[7]);
          if ((((*(short *)(iVar6 + 0x2c) <= iVar1) && (*(short *)(iVar6 + 0x2e) <= iVar2)) &&
              (iVar1 - *(short *)(iVar6 + 0x2c) <= (int)*(short *)(iVar6 + 0x30))) &&
             (iVar2 - *(short *)(iVar6 + 0x2e) <= (int)*(short *)(iVar6 + 0x32))) {
            return iVar6;
          }
          iVar8 = iVar8 + 1;
          iVar6 = iVar6 + 0x44;
        } while (iVar8 < (int)(uint)*(ushort *)((int)param_2 + 0x26));
      }
      param_3 = &local_10;
      iVar6 = param_2[(uVar7 ^ 1) + 7];
    }
    iVar6 = SurfaceAtPoint(param_1,iVar6,param_3,param_4);
  }
  return iVar6;
}


// SwapPic  @ 08081850
void SwapPic(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*LittleLong)(*param_1);
  *param_1 = uVar1;
  uVar1 = (*LittleLong)(param_1[1]);
  param_1[1] = uVar1;
  return;
}


// SzFromIndex  @ 080700f0
int SzFromIndex(int param_1)

{
  return pr_strings + param_1;
}


// TextMessageGet  @ 08080ef0
undefined1 * TextMessageGet(char *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  
  iVar1 = strcasecmp(param_1,"__NETMESSAGE__1");
  if (iVar1 == 0) {
    puVar2 = gNetworkTextMessage;
  }
  else {
    iVar1 = strcasecmp(param_1,"__NETMESSAGE__2");
    if (iVar1 == 0) {
      puVar2 = (undefined1 *)0x80ab48c;
    }
    else {
      iVar1 = strcasecmp(param_1,"__NETMESSAGE__3");
      if (iVar1 == 0) {
        puVar2 = (undefined1 *)0x80ab4b8;
      }
      else {
        iVar1 = strcasecmp(param_1,"__NETMESSAGE__4");
        if (iVar1 == 0) {
          puVar2 = (undefined1 *)0x80ab4e4;
        }
        else {
          iVar1 = 0;
          if (0 < gMessageTableCount) {
            do {
              iVar3 = strcmp(param_1,*(char **)(gMessageTable + 0x24 + iVar1 * 0x2c));
              if (iVar3 == 0) {
                return (undefined1 *)(iVar1 * 0x2c + gMessageTable);
              }
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


// TextMessageInit  @ 08080ea0
void TextMessageInit(void)

{
  int iVar1;
  undefined4 local_8;
  
  if (gMessageTable != (void *)0x0) {
    free(gMessageTable);
    gMessageTable = (void *)0x0;
  }
  iVar1 = COM_LoadTempFile("titles.txt",&local_8);
  if (iVar1 != 0) {
    TextMessageParse(iVar1,local_8);
  }
  return;
}


// TextMessageParse  @ 08080ad0
void TextMessageParse(int param_1,undefined4 param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  size_t __n;
  void *__dest;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  char *pcVar11;
  int local_6adc;
  int local_6ad4;
  size_t local_6ad0;
  char *local_6acc;
  int local_6ac8;
  undefined4 local_6ac4 [9];
  int aiStack_6aa0 [4391];
  char local_2604 [8192];
  char local_604 [512];
  char local_404 [512];
  undefined1 local_204 [512];
  
  bVar3 = false;
  local_6ad0 = 0;
  local_6ad4 = 0;
  local_6ac8 = 0;
  local_6adc = 0;
  do {
    iVar7 = local_6ac8;
    iVar5 = memfgets(param_1,param_2,&local_6ac8,local_204,0x200);
    if (iVar5 == 0) {
      Con_DPrintf("Parsed %d text messages\n",local_6adc);
      iVar7 = 0;
      if (0 < local_6adc) {
        iVar5 = 0;
        do {
          uVar6 = 0xffffffff;
          pcVar11 = (char *)aiStack_6aa0[iVar5 * 0xb + 1];
          do {
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            cVar2 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar2 != '\0');
          iVar7 = iVar7 + ~uVar6;
          iVar5 = iVar5 + 1;
        } while (iVar5 < local_6adc);
      }
      __n = local_6adc * 0x2c;
      gMessageTable = malloc(iVar7 + local_6ad0 + __n);
      memcpy(gMessageTable,local_6ac4,__n);
      __dest = (void *)(__n + (int)gMessageTable);
      memcpy(__dest,local_2604,local_6ad0);
      iVar7 = *(int *)((int)gMessageTable + 0x24);
      local_6acc = (char *)((int)__dest + local_6ad0);
      iVar5 = 0;
      if (0 < local_6adc) {
        do {
          pvVar4 = gMessageTable;
          iVar8 = iVar5 * 0x2c;
          piVar1 = (int *)((int)gMessageTable + iVar8 + 0x24);
          *piVar1 = (int)__dest + (*piVar1 - iVar7);
          strcpy(local_6acc,*(char **)((int)pvVar4 + iVar8 + 0x28));
          *(char **)((int)gMessageTable + iVar8 + 0x28) = local_6acc;
          uVar6 = 0xffffffff;
          pcVar11 = local_6acc;
          do {
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            cVar2 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar2 != '\0');
          local_6acc = local_6acc + ~uVar6;
          iVar5 = iVar5 + 1;
        } while (iVar5 < local_6adc);
      }
      gMessageTableCount = local_6adc;
      return;
    }
    TrimSpace(local_204,local_404);
    if (bVar3) {
      if (bVar3) {
        iVar5 = IsEndOfText(local_404);
        if (iVar5 == 0) {
          iVar7 = IsStartOfText(local_404);
          if (iVar7 != 0) {
            Con_DPrintf("Unexpected \'{\' found, line %d\n",local_6ad4);
            return;
          }
        }
        else {
          uVar6 = 0xffffffff;
          pcVar11 = local_604;
          do {
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            cVar2 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar2 != '\0');
          if (0x2000 < (int)((local_6ad0 - 1) + ~uVar6)) {
            Con_DPrintf("Error parsing file!\n");
            return;
          }
          strcpy(local_2604 + local_6ad0,local_604);
          *(undefined1 *)(param_1 + -1 + iVar7) = 0;
          puVar9 = &gMessageParms;
          puVar10 = local_6ac4 + local_6adc * 0xb;
          for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
          aiStack_6aa0[local_6adc * 0xb] = (int)(local_2604 + local_6ad0);
          uVar6 = 0xffffffff;
          pcVar11 = local_604;
          do {
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            cVar2 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar2 != '\0');
          local_6ad0 = local_6ad0 + ~uVar6;
          aiStack_6aa0[local_6adc * 0xb + 1] = (int)local_6acc;
          local_6adc = local_6adc + 1;
          bVar3 = false;
        }
      }
    }
    else {
      iVar7 = IsComment(local_404);
      if ((iVar7 == 0) && (iVar7 = ParseDirective(local_404), iVar7 == 0)) {
        iVar7 = IsStartOfText(local_404);
        if (iVar7 == 0) {
          iVar7 = IsEndOfText(local_404);
          if (iVar7 != 0) {
            Con_DPrintf("Unexpected \'}\' found, line %d\n",local_6ad4);
            return;
          }
          strcpy(local_604,local_404);
        }
        else {
          bVar3 = true;
          local_6acc = (char *)(param_1 + local_6ac8);
        }
      }
    }
    local_6ad4 = local_6ad4 + 1;
  } while( true );
}


// TraceHull  @ 0806c530
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


// TraceModel  @ 0806c5f0
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
  iVar1 = (&DAT_0813e330)[*(int *)(param_4 + 0x170)];
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x44) == 0)) {
    local_40 = *(undefined4 *)(param_4 + 0x1c8);
    local_44 = *(undefined4 *)(param_4 + 0x1c4);
    *(undefined4 *)(param_4 + 0x1c8) = 4;
    *(undefined4 *)(param_4 + 0x1c4) = 7;
  }
  SV_ClipMoveToEntity(&local_3c,param_4,param_1,gHullMins + param_3 * 0xc,gHullMaxs + param_3 * 0xc,
                      param_2);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x44) == 0)) {
    *(undefined4 *)(param_4 + 0x1c8) = local_40;
    *(undefined4 *)(param_4 + 0x1c4) = local_44;
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


// TraceMonsterHull  @ 0806cd60
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
  
  SV_Move(&local_3c,param_2,param_1 + 0x198,param_1 + 0x1a4,param_3,param_4,param_5,
          (*(byte *)(param_1 + 0x262) & 0x80) != 0);
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


// TraceSphere  @ 0806c5d0
void TraceSphere(void)

{
  Sys_Error("TraceSphere not yet implemented!\n");
  return;
}


// TraceTexture  @ 0806c940
undefined4 TraceTexture(int param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
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
  
  local_5c = 0;
  if (param_1 == 0) {
    local_10 = *param_2;
    local_c = param_2[1];
    local_8 = param_2[2];
    local_1c = *param_3;
    local_18 = param_3[1];
    local_14 = param_3[2];
    iVar5 = DAT_0811d320;
  }
  else {
    iVar5 = (&DAT_0813e330)[*(int *)(param_1 + 0x170)];
    if (iVar5 == 0) {
      return 0;
    }
    if (*(int *)(iVar5 + 0x44) != 0) {
      return 0;
    }
    iVar4 = SV_HullForBsp(param_1,vec3_origin,vec3_origin,&local_28);
    local_10 = *param_2 - local_28;
    local_c = param_2[1] - local_24;
    local_8 = param_2[2] - local_20;
    local_1c = *param_3 - local_28;
    local_18 = param_3[1] - local_24;
    local_14 = param_3[2] - local_20;
    local_5c = *(int *)(iVar4 + 8);
    if ((((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 300)) << 10) >> 8) |
                (byte)((ushort)((ushort)(*(float *)(param_1 + 300) == 0.0) << 0xe) >> 8)) != 0x40)
        || ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_1 + 0x130)) << 10) >> 8) |
                  (byte)((ushort)((ushort)(*(float *)(param_1 + 0x130) == 0.0) << 0xe) >> 8)) !=
            0x40)) ||
       (fVar1 = *(float *)(param_1 + 0x134),
       (byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
      AngleVectors(param_1 + 300,&local_34,&local_40,&local_4c);
      fVar3 = local_8 * local_2c;
      fVar2 = local_10 * local_40;
      fVar1 = local_8 * local_38;
      local_8 = local_8 * local_44 + local_c * local_48 + local_10 * local_4c;
      local_2c = local_14 * local_2c;
      local_40 = local_1c * local_40;
      local_38 = local_14 * local_38;
      local_14 = local_14 * local_44 + local_18 * local_48 + local_1c * local_4c;
      local_1c = local_2c + local_18 * local_30 + local_1c * local_34;
      local_18 = -(local_38 + local_18 * local_3c + local_40);
      local_10 = fVar3 + local_c * local_30 + local_10 * local_34;
      local_c = -(fVar1 + local_c * local_3c + fVar2);
    }
  }
  if (((iVar5 != 0) && (*(int *)(iVar5 + 0x44) == 0)) &&
     ((*(int *)(iVar5 + 0xa4) != 0 &&
      (iVar5 = SurfaceAtPoint(iVar5,*(int *)(iVar5 + 0xa4) + local_5c * 0x28,&local_10,&local_1c),
      iVar5 != 0)))) {
    return *(undefined4 *)(*(int *)(iVar5 + 0x34) + 0x24);
  }
  return 0;
}


// TrimSpace  @ 08080700
void TrimSpace(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  size_t __n;
  int iVar6;
  char *pcVar7;
  
  iVar6 = 0;
  uVar4 = 0xffffffff;
  pcVar7 = param_1;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  iVar5 = ~uVar4 - 1;
  if (*param_1 != '\0') {
    iVar6 = 0;
    do {
      iVar2 = IsWhiteSpace((int)param_1[iVar6]);
      if (iVar2 == 0) break;
      iVar6 = iVar6 + 1;
    } while (param_1[iVar6] != '\0');
  }
  do {
    iVar2 = iVar5;
    iVar5 = iVar2 + -1;
    if (iVar5 < 1) break;
    iVar3 = IsWhiteSpace((int)param_1[iVar5]);
  } while (iVar3 != 0);
  __n = iVar2 - iVar6;
  if ((int)__n < 1) {
    __n = 0;
  }
  else {
    strncpy(param_2,param_1 + iVar6,__n);
  }
  param_2[__n] = '\0';
  return;
}


// ValidCmd  @ 0806d2e0
undefined4 ValidCmd(char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  char *pcVar4;
  
  uVar3 = 0xffffffff;
  pcVar4 = param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  if ((uVar3 == 1) || ((param_1[uVar3 - 2] != '\n' && (param_1[uVar3 - 2] != ';')))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


// VectorAngles  @ 08062140
void VectorAngles(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  
  fVar2 = 0.0;
  if (((byte)((byte)((ushort)((ushort)NAN(param_1[1]) << 10) >> 8) |
             (byte)((ushort)((ushort)(param_1[1] == 0.0) << 0xe) >> 8)) == 0x40) &&
     ((byte)((byte)((ushort)((ushort)NAN(*param_1) << 10) >> 8) |
            (byte)((ushort)((ushort)(*param_1 == 0.0) << 0xe) >> 8)) == 0x40)) {
    fVar1 = param_1[2];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
      fVar1 = 90.0;
    }
    else {
      fVar2 = 0.0;
      fVar1 = 270.0;
    }
  }
  else {
    lVar3 = (longdouble)fpatan((longdouble)param_1[1],(longdouble)*param_1);
    fVar2 = (float)((lVar3 * (longdouble)180.0) / (longdouble)3.141592653589793);
    if (fVar2 < 0.0) {
      fVar2 = fVar2 + 360.0;
    }
    lVar3 = (longdouble)
            fpatan((longdouble)param_1[2],
                   (longdouble)SQRT(param_1[1] * param_1[1] + *param_1 * *param_1));
    fVar1 = (float)((lVar3 * (longdouble)180.0) / (longdouble)3.141592653589793);
    if (fVar1 < 0.0) {
      fVar1 = fVar1 + 360.0;
    }
  }
  *param_2 = fVar1;
  param_2[1] = fVar2;
  param_2[2] = 0.0;
  return;
}


// VectorCompare  @ 08061e40
undefined4 VectorCompare(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    fVar1 = *(float *)(param_1 + iVar3 * 4);
    fVar2 = *(float *)(param_2 + iVar3 * 4);
    if ((byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) != 0x40) {
      return 0;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  return 1;
}


// VectorInverse  @ 08062030
void VectorInverse(float *param_1)

{
  *param_1 = -*param_1;
  param_1[1] = -param_1[1];
  param_1[2] = -param_1[2];
  return;
}


// VectorMA  @ 08061e90
void VectorMA(float *param_1,float param_2,float *param_3,float *param_4)

{
  *param_4 = param_2 * *param_3 + *param_1;
  param_4[1] = param_2 * param_3[1] + param_1[1];
  param_4[2] = param_2 * param_3[2] + param_1[2];
  return;
}


// VectorMatrix  @ 080620a0
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


// VectorNormalize  @ 08061fe0
void VectorNormalize(float *param_1)

{
  float fVar1;
  
  fVar1 = SQRT(param_1[2] * param_1[2] + param_1[1] * param_1[1] + *param_1 * *param_1);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    fVar1 = 1.0 / fVar1;
    *param_1 = fVar1 * *param_1;
    param_1[1] = fVar1 * param_1[1];
    param_1[2] = fVar1 * param_1[2];
  }
  return;
}


// VectorScale  @ 08062050
void VectorScale(float *param_1,float param_2,float *param_3)

{
  *param_3 = param_2 * *param_1;
  param_3[1] = param_2 * param_1[1];
  param_3[2] = param_2 * param_1[2];
  return;
}


// VectorTransform  @ 08061de0
void VectorTransform(float *param_1,float *param_2,float *param_3)

{
  *param_3 = param_1[2] * param_2[2] + param_1[1] * param_2[1] + *param_1 * *param_2 + param_2[3];
  param_3[1] = param_1[2] * param_2[6] + param_1[1] * param_2[5] + *param_1 * param_2[4] +
               param_2[7];
  param_3[2] = param_1[2] * param_2[10] + param_1[1] * param_2[9] + *param_1 * param_2[8] +
               param_2[0xb];
  return;
}


// anglemod  @ 08061750
longdouble anglemod(float param_1)

{
  return (longdouble)((float)((int)ROUND(param_1 * 182.04445) & 0xffff) * 0.005493164);
}


// filelength  @ 08087950
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


// findhandle  @ 080878f0
int findhandle(void)

{
  int iVar1;
  
  iVar1 = 1;
  do {
    if (*(int *)(sys_handles + iVar1 * 4) == 0) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 10);
  Sys_Error("out of handles");
  return -1;
}


// fran1  @ 0806f390
longdouble fran1(void)

{
  int iVar1;
  longdouble lVar2;
  longdouble lVar3;
  
  iVar1 = ran1();
  lVar2 = (longdouble)((float)iVar1 * 4.656613e-10);
  lVar3 = (longdouble)0.99999988;
  if ((byte)(lVar3 < lVar2 | (byte)((ushort)((ushort)(NAN(lVar3) || NAN(lVar2)) << 10) >> 8) |
            (byte)((ushort)((ushort)(lVar3 == lVar2) << 0xe) >> 8)) == 1) {
    lVar2 = (longdouble)0.9999999;
  }
  return lVar2;
}


// iGetIndex  @ 0806d6a0
int iGetIndex(char *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  undefined1 local_3f0 [4];
  undefined1 local_3ec [148];
  undefined1 local_358 [4];
  undefined1 local_354 [4];
  undefined1 local_350 [264];
  undefined1 local_248 [4];
  undefined1 local_244 [4];
  undefined1 local_240 [4];
  undefined1 local_23c [20];
  undefined1 local_228 [4];
  undefined1 local_224 [4];
  undefined1 local_220 [4];
  undefined1 local_21c [24];
  char local_204 [512];
  
  strcpy(local_204,param_1);
  Q_strlwr(local_204);
  iVar1 = 10;
  bVar5 = true;
  pcVar3 = local_204;
  pcVar4 = "classname";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    puVar2 = local_3f0;
  }
  else {
    iVar1 = 6;
    bVar5 = true;
    pcVar3 = local_204;
    pcVar4 = "model";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      puVar2 = local_358;
    }
    else {
      iVar1 = 10;
      bVar5 = true;
      pcVar3 = local_204;
      pcVar4 = "viewmodel";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar5 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      if (bVar5) {
        puVar2 = local_354;
      }
      else {
        iVar1 = 0xc;
        bVar5 = true;
        pcVar3 = local_204;
        pcVar4 = "weaponmodel";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar5 = *pcVar3 == *pcVar4;
          pcVar3 = pcVar3 + 1;
          pcVar4 = pcVar4 + 1;
        } while (bVar5);
        if (bVar5) {
          puVar2 = local_350;
        }
        else {
          iVar1 = 8;
          bVar5 = true;
          pcVar3 = local_204;
          pcVar4 = "netname";
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar5 = *pcVar3 == *pcVar4;
            pcVar3 = pcVar3 + 1;
            pcVar4 = pcVar4 + 1;
          } while (bVar5);
          if (bVar5) {
            puVar2 = local_240;
          }
          else {
            iVar1 = 7;
            bVar5 = true;
            pcVar3 = local_204;
            pcVar4 = "target";
            do {
              if (iVar1 == 0) break;
              iVar1 = iVar1 + -1;
              bVar5 = *pcVar3 == *pcVar4;
              pcVar3 = pcVar3 + 1;
              pcVar4 = pcVar4 + 1;
            } while (bVar5);
            if (bVar5) {
              puVar2 = local_248;
            }
            else {
              iVar1 = 0xb;
              bVar5 = true;
              pcVar3 = local_204;
              pcVar4 = "targetname";
              do {
                if (iVar1 == 0) break;
                iVar1 = iVar1 + -1;
                bVar5 = *pcVar3 == *pcVar4;
                pcVar3 = pcVar3 + 1;
                pcVar4 = pcVar4 + 1;
              } while (bVar5);
              if (bVar5) {
                puVar2 = local_244;
              }
              else {
                iVar1 = 8;
                bVar5 = true;
                pcVar3 = local_204;
                pcVar4 = "message";
                do {
                  if (iVar1 == 0) break;
                  iVar1 = iVar1 + -1;
                  bVar5 = *pcVar3 == *pcVar4;
                  pcVar3 = pcVar3 + 1;
                  pcVar4 = pcVar4 + 1;
                } while (bVar5);
                if (bVar5) {
                  puVar2 = local_23c;
                }
                else {
                  iVar1 = 6;
                  bVar5 = true;
                  pcVar3 = local_204;
                  pcVar4 = "noise";
                  do {
                    if (iVar1 == 0) break;
                    iVar1 = iVar1 + -1;
                    bVar5 = *pcVar3 == *pcVar4;
                    pcVar3 = pcVar3 + 1;
                    pcVar4 = pcVar4 + 1;
                  } while (bVar5);
                  if (bVar5) {
                    puVar2 = local_228;
                  }
                  else {
                    iVar1 = 7;
                    bVar5 = true;
                    pcVar3 = local_204;
                    pcVar4 = "noise1";
                    do {
                      if (iVar1 == 0) break;
                      iVar1 = iVar1 + -1;
                      bVar5 = *pcVar3 == *pcVar4;
                      pcVar3 = pcVar3 + 1;
                      pcVar4 = pcVar4 + 1;
                    } while (bVar5);
                    if (bVar5) {
                      puVar2 = local_224;
                    }
                    else {
                      iVar1 = 7;
                      bVar5 = true;
                      pcVar3 = local_204;
                      pcVar4 = "noise2";
                      do {
                        if (iVar1 == 0) break;
                        iVar1 = iVar1 + -1;
                        bVar5 = *pcVar3 == *pcVar4;
                        pcVar3 = pcVar3 + 1;
                        pcVar4 = pcVar4 + 1;
                      } while (bVar5);
                      if (bVar5) {
                        puVar2 = local_220;
                      }
                      else {
                        iVar1 = 7;
                        bVar5 = true;
                        pcVar3 = local_204;
                        pcVar4 = "noise3";
                        do {
                          if (iVar1 == 0) break;
                          iVar1 = iVar1 + -1;
                          bVar5 = *pcVar3 == *pcVar4;
                          pcVar3 = pcVar3 + 1;
                          pcVar4 = pcVar4 + 1;
                        } while (bVar5);
                        if (bVar5) {
                          puVar2 = local_21c;
                        }
                        else {
                          iVar1 = 0xb;
                          bVar5 = true;
                          pcVar3 = local_204;
                          pcVar4 = "globalname";
                          do {
                            if (iVar1 == 0) break;
                            iVar1 = iVar1 + -1;
                            bVar5 = *pcVar3 == *pcVar4;
                            pcVar3 = pcVar3 + 1;
                            pcVar4 = pcVar4 + 1;
                          } while (bVar5);
                          if (!bVar5) {
                            return -1;
                          }
                          puVar2 = local_3ec;
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
  return (int)puVar2 - (int)local_3f0;
}


// idprintf  @ 080532b0
undefined4 * idprintf(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  char local_10 [12];
  
  puVar2 = &szReturn_416;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  iVar1 = 0;
  if (0 < param_2) {
    do {
      sprintf(local_10,"%02x",(uint)*(byte *)(iVar1 + param_1));
      strcat((char *)&szReturn_416,local_10);
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_2);
  }
  return &szReturn_416;
}


// main  @ 0808a1d0
undefined4 main(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  char *pcVar9;
  int local_b4c;
  int local_b40;
  undefined4 local_b3c;
  int local_b38;
  undefined *local_b34;
  undefined *local_b30;
  char local_b2c [256];
  char local_a2c [2600];
  
  strcpy(g_szEXEName,(char *)*param_2);
  BuildCmdLine__FiPPc(param_1,param_2);
  iVar6 = CheckExeChecksum__Fv();
  uVar7 = 0;
  if (iVar6 != 0) {
    Eng_SetState__Fi(0);
    ef._84_4_ = Sys_Printf;
    ef._88_4_ = UTIL_GetCDKey__FPcPiPi;
    ef._92_4_ = UTIL_GetClientID__FPv;
    ef._96_4_ = UTIL_GetUUID__FPvPiPi;
    ef._72_4_ = Launcher_InitCmds__Fv;
    ef._100_4_ = Launcher_VerifyMessage__FiPUciPciT1;
    ef._112_4_ = Launcher_ValidateClientCertificate__FPvi;
    ef._104_4_ = Launcher_GetCertificate__FPvPi;
    ef._108_4_ = Launcher_RequestNewClientCertificate__Fv;
    ef._116_4_ = Launcher_AuthRequest__FPviP15authchallenge_t;
    ef._120_4_ = Launcher_AuthChallenge1__FPviP15authchallenge_t;
    ef._124_4_ = Launcher_AuthChallenge2__FPviP15authchallenge_t;
    ef._128_4_ = Launcher_AuthComplete__FPviP15authchallenge_t;
    ef._132_4_ = Launcher_DecodeAuthComplete__FPviP15authchallenge_t;
    ef._136_4_ = Launcher_DeleteAuthData__FP15authchallenge_t;
    ef._140_4_ = Launcher_GetConnectionKey__FPvPi;
    ef._144_4_ = Launcher_BFEncrypt__FPviT0Pi;
    ef._148_4_ = Launcher_GetRawBFKey__FPvT0Pi;
    ef._8_4_ = VID_LockBuffer;
    ef._12_4_ = VID_UnlockBuffer;
    ef._16_4_ = VID_Shutdown;
    ef._20_4_ = VID_Update;
    ef._52_4_ = 0;
    ef._24_4_ = 0;
    ef._28_4_ = 0;
    ef._32_4_ = 0;
    ef._36_4_ = VID_GetExtModeDescription;
    ef._44_4_ = D_BeginDirectRect;
    ef._48_4_ = D_EndDirectRect;
    ef._56_4_ = 0;
    ef._60_4_ = 0;
    ef._64_4_ = 0;
    ef._68_4_ = 0;
    ef._76_4_ = ErrorMessage__FiPCc;
    ef._80_4_ = D_SurfaceCacheForRes;
    memset(&g_szGUID,0,0xe);
    iVar6 = CheckCDKey__Fv();
    if (iVar6 == 0) {
      uVar7 = 0;
    }
    else {
      local_b38 = 10;
      memset(local_a2c,0,0xa28);
      iVar6 = ParseServers__FPcPi(local_a2c,&local_b38);
      if (iVar6 == 0) {
        sprintf(local_a2c,"half-life.west.won.net:7001");
        local_b38 = 1;
      }
      bVar5 = false;
      Split__FPcT0Pii(local_a2c,local_b2c,&local_b3c,0x1b59);
      uVar7 = __builtin_new(0x82a0);
      if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc]
          == '\0') {
        _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
             _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
             _8_4_ + 1;
        local_b30 = &force_to_data;
      }
      else {
        local_b30 = (undefined *)
                    clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                              (
                              _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                              );
      }
      uVar8 = 0xffffffff;
      pcVar9 = local_a2c;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar4 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar4 != '\0');
      replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
                (&local_b30,0,0xffffffff,local_a2c,~uVar8 - 1);
      iVar6 = __11AuthRequestRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i
                        (uVar7,&local_b30,local_b3c);
      puVar1 = (undefined4 *)(local_b30 + -0x10);
      piVar2 = (int *)(local_b30 + -8);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) {
        if (*(int *)(local_b30 + -0xc) + 0x10U < 0x81) {
          iVar3 = (*(int *)(local_b30 + -0xc) + 0x17U >> 3) * 4;
          pthread_mutex_lock((pthread_mutex_t *)
                             _t24__default_alloc_template2b1i0___node_allocator_lock);
          *puVar1 = *(undefined4 *)(&DAT_080ab95c + iVar3);
          *(undefined4 **)(&DAT_080ab95c + iVar3) = puVar1;
          pthread_mutex_unlock
                    ((pthread_mutex_t *)_t24__default_alloc_template2b1i0___node_allocator_lock);
        }
        else {
          free(puVar1);
        }
      }
      gAuthRequest = iVar6;
      if (iVar6 == 0) {
        Sys_Error("Could not create authentication object");
        uVar7 = 0;
      }
      else {
        getAuthVerifierKey__11AuthRequestPCc(iVar6,"kver.kp");
        local_b4c = 0;
        do {
          if (local_b38 <= local_b4c) break;
          local_b40 = 2;
          do {
            Split__FPcT0Pii(local_a2c + local_b4c * 0x104,local_b2c,&local_b3c,0x1b59);
            if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                [0xc] == '\0') {
              _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
              _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                      ._8_4_ + 1;
              local_b34 = &force_to_data;
            }
            else {
              local_b34 = (undefined *)
                          clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                                    (
                                    _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                                    );
            }
            uVar8 = 0xffffffff;
            pcVar9 = local_b2c;
            do {
              if (uVar8 == 0) break;
              uVar8 = uVar8 - 1;
              cVar4 = *pcVar9;
              pcVar9 = pcVar9 + 1;
            } while (cVar4 != '\0');
            replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
                      (&local_b34,0,0xffffffff,local_b2c,~uVar8 - 1);
            setAddrPort__12TitanRequestRCt12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0i
                      (gAuthRequest,&local_b34,local_b3c);
            puVar1 = (undefined4 *)(local_b34 + -0x10);
            piVar2 = (int *)(local_b34 + -8);
            *piVar2 = *piVar2 + -1;
            if (*piVar2 == 0) {
              if (*(int *)(local_b34 + -0xc) + 0x10U < 0x81) {
                iVar6 = (*(int *)(local_b34 + -0xc) + 0x17U >> 3) * 4;
                pthread_mutex_lock((pthread_mutex_t *)
                                   _t24__default_alloc_template2b1i0___node_allocator_lock);
                *puVar1 = *(undefined4 *)(&DAT_080ab95c + iVar6);
                *(undefined4 **)(&DAT_080ab95c + iVar6) = puVar1;
                pthread_mutex_unlock
                          ((pthread_mutex_t *)
                           _t24__default_alloc_template2b1i0___node_allocator_lock);
              }
              else {
                free(puVar1);
              }
            }
            iVar6 = getCertificate__11AuthRequesti(gAuthRequest,1);
            if (iVar6 != 0) {
              bVar5 = true;
              break;
            }
            usleep(500);
            local_b40 = local_b40 + -1;
          } while (-1 < local_b40);
          local_b4c = local_b4c + 1;
        } while (!bVar5);
        iVar6 = AllocGameMem__Fv();
        if (iVar6 != 0) {
          InvokeEngine__FiPce(0,&DAT_080a748f);
          if ((gAuthRequest == 0) ||
             (iVar6 = GetCertificate__11AuthRequest(gAuthRequest), iVar6 == 0)) {
            pcVar9 = "Auth Server\r\n";
          }
          else {
            pcVar9 = "WON Auth Server\r\n";
          }
          Sys_Printf(pcVar9);
          Sys_Printf(" ...\n");
          do {
            Eng_Frame__Fi(0);
            iVar6 = Sys_ConsoleInput();
            if (iVar6 != 0) {
              Cbuf_AddText(iVar6);
              Cbuf_AddText(&DAT_080a731d);
            }
            UpdateStatus__Fv();
          } while( true );
        }
        uVar7 = 0xffffffff;
      }
    }
  }
  return uVar7;
}


// memfgets  @ 08080480
void * memfgets(int param_1,int param_2,int *param_3,void *param_4,int param_5)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  size_t __n;
  
  iVar1 = *param_3;
  if (((param_1 != 0) && (param_4 != (void *)0x0)) && (iVar1 < param_2)) {
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
      __n = iVar3 - iVar1;
      memcpy(param_4,(void *)(param_1 + iVar1),__n);
      if ((int)__n < param_5) {
        *(undefined1 *)(__n + (int)param_4) = 0;
      }
      *param_3 = iVar3;
      return param_4;
    }
  }
  return (void *)0x0;
}


// memsearch  @ 080503e0
int memsearch(int param_1,int param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < param_2) {
    do {
      if (*(byte *)(iVar1 + param_1) == param_3) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_2);
  }
  return -1;
}


// ran1  @ 0806f1e0
undefined4 ran1(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((idum < 1) || (iy_264 == 0)) {
    if (-idum < 1) {
      idum = 1;
    }
    else {
      idum = -idum;
    }
    iVar2 = 0x27;
    do {
      idum = idum * 0x41a7 + (idum / 0x1f31d) * -0x7fffffff;
      if (idum < 0) {
        idum = idum + 0x7fffffff;
      }
      if (iVar2 < 0x20) {
        (&iv_265)[iVar2] = idum;
      }
      iVar2 = iVar2 + -1;
    } while (-1 < iVar2);
    iy_264 = iv_265;
  }
  idum = idum * 0x41a7 + (idum / 0x1f31d) * -0x7fffffff;
  if (idum < 0) {
    idum = idum + 0x7fffffff;
  }
  if (iy_264 < 0) {
    iy_264 = iy_264 + 0x3ffffff;
  }
  iVar2 = iy_264 >> 0x1a;
  uVar1 = (&iv_265)[iVar2];
  iy_264 = uVar1;
  (&iv_265)[iVar2] = idum;
  return uVar1;
}


// va  @ 08050380
undefined1 * va(char *param_1)

{
  vsprintf(string_301,param_1,&stack0x00000008);
  return string_301;
}


// vstr  @ 080503a0
undefined1 * vstr(float *param_1)

{
  sprintf(string_304,"%.2f %.2f %.2f",(double)*param_1,(double)param_1[1],(double)param_1[2]);
  return string_304;
}


