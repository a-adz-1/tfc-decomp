// read__7istreamPSci  @ 0809d13c
void read__7istreamPSci(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  read__7istreamPci(param_1,param_2,param_3);
  return;
}


// read__7istreamPUci  @ 0809d154
void read__7istreamPUci(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  read__7istreamPci(param_1,param_2,param_3);
  return;
}


// read__7istreamPci  @ 0809ad7c
int * read__7istreamPci(int *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  int *piVar2;
  size_t sVar3;
  int *piVar4;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    _IO_flockfile(*(_IO_FILE **)*param_1);
    piVar4 = (int *)*param_1;
    if (piVar4[1] != 0) {
      piVar2 = (int *)0x0;
      if (param_1 != (int *)0x0) {
        piVar2 = piVar4;
      }
      if (*(int *)(*piVar2 + 8) == *(int *)(*piVar2 + 4)) {
        flush__7ostream(piVar4[1]);
        piVar4 = (int *)*param_1;
      }
    }
    sVar3 = _IO_sgetn((_IO_FILE *)*piVar4,param_2,param_3);
    param_1[1] = sVar3;
    if (sVar3 != param_3) {
      iVar1 = 0;
      if (param_1 != (int *)0x0) {
        iVar1 = *param_1;
      }
      *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 3;
    }
  }
  else {
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 2;
    param_1[1] = 0;
  }
  return param_1;
}


// read__7istreamPvi  @ 0809d124
void read__7istreamPvi(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  read__7istreamPci(param_1,param_2,param_3);
  return;
}


// read_int__FR7istreamRUxRi  @ 0809b070
undefined4 read_int__FR7istreamRUxRi(int *param_1,uint *param_2,undefined4 *param_3)

{
  _IO_FILE *__fp;
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int local_10;
  uint local_c;
  
  iVar4 = 0;
  if (param_1 != (int *)0x0) {
    iVar4 = *param_1;
  }
  if (*(char *)(iVar4 + 0x12) != '\0') {
    iVar4 = 0;
    if (param_1 != (int *)0x0) {
      iVar4 = *param_1;
    }
    *(byte *)(iVar4 + 0x12) = *(byte *)(iVar4 + 0x12) | 2;
    return 0;
  }
  _IO_flockfile(*(_IO_FILE **)*param_1);
  if (*(int *)(*param_1 + 4) != 0) {
    flush__7ostream(*(int *)(*param_1 + 4));
  }
  iVar4 = 0;
  if (param_1 != (int *)0x0) {
    iVar4 = *param_1;
  }
  if ((*(byte *)(iVar4 + 0xc) & 1) == 0) {
    iVar4 = 1;
  }
  else {
    iVar4 = _skip_ws__7istream(param_1);
  }
  if (iVar4 == 0) {
    return 0;
  }
  puVar5 = (undefined4 *)0x0;
  if (param_1 != (int *)0x0) {
    puVar5 = (undefined4 *)*param_1;
  }
  __fp = (_IO_FILE *)*puVar5;
  local_c = 10;
  local_10 = 0;
  iVar4 = skip_ws__FP9streambuf(__fp);
  if (iVar4 == -1) goto LAB_0809b328;
  *param_3 = 0;
  if (iVar4 == 0x2b) {
LAB_0809b153:
    iVar4 = skip_ws__FP9streambuf(__fp);
  }
  else if (iVar4 == 0x2d) {
    *param_3 = 1;
    goto LAB_0809b153;
  }
  if (iVar4 == -1) {
LAB_0809b328:
    iVar4 = 0;
    if (param_1 != (int *)0x0) {
      iVar4 = *param_1;
    }
    *(byte *)(iVar4 + 0x12) = *(byte *)(iVar4 + 0x12) | 3;
    return 0;
  }
  iVar3 = 0;
  if (param_1 != (int *)0x0) {
    iVar3 = *param_1;
  }
  if ((*(byte *)(iVar3 + 0xc) & 0x70) == 0) {
    if (iVar4 == 0x30) {
      iVar4 = _IO_getc(__fp);
      if (iVar4 == -1) {
        *param_2 = 0;
        param_2[1] = 0;
        return 1;
      }
      if ((iVar4 == 0x78) || (iVar4 == 0x58)) {
        local_c = 0x10;
        iVar4 = _IO_getc(__fp);
        if (iVar4 == -1) goto LAB_0809b328;
      }
      else {
        sputbackc__9streambufc(__fp,(int)(char)iVar4);
        local_c = 8;
        iVar4 = 0x30;
      }
    }
  }
  else {
    iVar3 = 0;
    if (param_1 != (int *)0x0) {
      iVar3 = *param_1;
    }
    if ((*(uint *)(iVar3 + 0xc) & 0x70) == 0x40) {
      local_c = 0x10;
    }
    else {
      iVar3 = 0;
      if (param_1 != (int *)0x0) {
        iVar3 = *param_1;
      }
      if ((*(uint *)(iVar3 + 0xc) & 0x70) == 0x20) {
        local_c = 8;
      }
    }
  }
  *param_2 = 0;
  param_2[1] = 0;
  while( true ) {
    if (iVar4 == -1) {
      return 1;
    }
    uVar6 = iVar4 - 0x30;
    if (9 < uVar6) {
      if (iVar4 - 0x41U < 6) {
        uVar6 = iVar4 - 0x37;
      }
      else {
        uVar6 = 999;
        if (iVar4 - 0x61U < 6) {
          uVar6 = iVar4 - 0x57;
        }
      }
    }
    if ((int)local_c <= (int)uVar6) break;
    local_10 = local_10 + 1;
    uVar1 = *param_2;
    uVar2 = (uint)((ulonglong)local_c * (ulonglong)uVar1);
    *param_2 = uVar2 + uVar6;
    param_2[1] = (int)((ulonglong)local_c * (ulonglong)uVar1 >> 0x20) + local_c * param_2[1] +
                 ((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar2,uVar6);
    iVar4 = _IO_getc(__fp);
  }
  sputbackc__9streambufc(__fp,(int)(char)iVar4);
  if (local_10 != 0) {
    return 1;
  }
  iVar4 = 0;
  if (param_1 != (int *)0x0) {
    iVar4 = *param_1;
  }
  *(byte *)(iVar4 + 0x12) = *(byte *)(iVar4 + 0x12) | 2;
  return 0;
}


