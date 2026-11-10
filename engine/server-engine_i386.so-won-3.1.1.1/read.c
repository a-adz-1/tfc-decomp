// read__7istreamPSci  @ 00052a38
void read__7istreamPSci(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  read__7istreamPci(param_1,param_2,param_3);
  return;
}


// read__7istreamPUci  @ 00052a18
void read__7istreamPUci(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  read__7istreamPci(param_1,param_2,param_3);
  return;
}


// read__7istreamPci  @ 00050728
int * read__7istreamPci(int *param_1,void *param_2,size_t param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  undefined1 local_14 [16];
  
  puVar1 = (undefined4 *)*param_1;
  if (*(byte *)((int)puVar1 + 0x12) == 0) {
    _IO_flockfile((_IO_FILE *)*puVar1);
    iVar2 = ((int *)*param_1)[1];
    if ((iVar2 != 0) && (iVar3 = *(int *)*param_1, *(int *)(iVar3 + 8) == *(int *)(iVar3 + 4))) {
      flush__7ostream(iVar2);
    }
    _pthread_cleanup_push_defer(local_14,_IO_funlockfile,*(undefined4 *)*param_1);
    sVar4 = _IO_sgetn(*(_IO_FILE **)*param_1,param_2,param_3);
    param_1[1] = sVar4;
    if (sVar4 != param_3) {
      *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 3;
    }
    _IO_funlockfile(*(_IO_FILE **)*param_1);
    _pthread_cleanup_pop_restore(local_14,0);
  }
  else {
    *(byte *)((int)puVar1 + 0x12) = *(byte *)((int)puVar1 + 0x12) | 2;
    param_1[1] = 0;
  }
  return param_1;
}


// read__7istreamPvi  @ 00052a58
void read__7istreamPvi(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  read__7istreamPci(param_1,param_2,param_3);
  return;
}


// read_int__FR7istreamRUxRi  @ 00050af0
undefined4 read_int__FR7istreamRUxRi(int *param_1,uint *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  _IO_FILE *__fp;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int local_20;
  uint local_1c;
  undefined1 local_14 [16];
  
  puVar1 = (undefined4 *)*param_1;
  if (*(byte *)((int)puVar1 + 0x12) != 0) {
    *(byte *)((int)puVar1 + 0x12) = *(byte *)((int)puVar1 + 0x12) | 2;
    return 0;
  }
  _IO_flockfile((_IO_FILE *)*puVar1);
  if (*(int *)(*param_1 + 4) != 0) {
    flush__7ostream(*(int *)(*param_1 + 4));
  }
  if ((*(byte *)(*param_1 + 0xc) & 1) == 0) {
    iVar3 = 1;
  }
  else {
    iVar3 = _skip_ws__7istream(param_1);
  }
  if (iVar3 == 0) {
    return 0;
  }
  _pthread_cleanup_push_defer(local_14,_IO_funlockfile,*(undefined4 *)*param_1);
  __fp = *(_IO_FILE **)*param_1;
  local_1c = 10;
  local_20 = 0;
  iVar3 = skip_ws__FP9streambuf(__fp);
  if (iVar3 != -1) {
    *param_3 = 0;
    if (iVar3 == 0x2b) {
LAB_00050bda:
      iVar3 = skip_ws__FP9streambuf(__fp);
    }
    else if (iVar3 == 0x2d) {
      *param_3 = 1;
      goto LAB_00050bda;
    }
    if (iVar3 != -1) {
      uVar4 = *(uint *)(*param_1 + 0xc) & 0x70;
      if (uVar4 == 0) {
        if (iVar3 != 0x30) goto LAB_00050c9c;
        iVar3 = _IO_getc(__fp);
        if (iVar3 != -1) {
          if ((iVar3 == 0x78) || (iVar3 == 0x58)) {
            local_1c = 0x10;
            iVar3 = _IO_getc(__fp);
            if (iVar3 == -1) goto LAB_00050d80;
          }
          else {
            sputbackc__9streambufc(__fp,(int)(char)iVar3);
            local_1c = 8;
            iVar3 = 0x30;
          }
          goto LAB_00050c9c;
        }
        *param_2 = 0;
        param_2[1] = 0;
      }
      else {
        if (uVar4 == 0x40) {
          local_1c = 0x10;
        }
        else if (uVar4 == 0x20) {
          local_1c = 8;
        }
LAB_00050c9c:
        *param_2 = 0;
        param_2[1] = 0;
        while (iVar3 != -1) {
          uVar4 = iVar3 - 0x30;
          if (9 < uVar4) {
            if (iVar3 - 0x41U < 6) {
              uVar4 = iVar3 - 0x37;
            }
            else {
              uVar4 = 999;
              if (iVar3 - 0x61U < 6) {
                uVar4 = iVar3 - 0x57;
              }
            }
          }
          if ((int)local_1c <= (int)uVar4) {
            sputbackc__9streambufc(__fp,(int)(char)iVar3);
            if (local_20 == 0) {
              uVar6 = 0;
              *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 2;
              goto LAB_00050d8b;
            }
            break;
          }
          local_20 = local_20 + 1;
          uVar2 = *param_2;
          uVar5 = (uint)((ulonglong)local_1c * (ulonglong)uVar2);
          *param_2 = uVar5 + uVar4;
          param_2[1] = (int)((ulonglong)local_1c * (ulonglong)uVar2 >> 0x20) + local_1c * param_2[1]
                       + ((int)uVar4 >> 0x1f) + (uint)CARRY4(uVar5,uVar4);
          iVar3 = _IO_getc(__fp);
        }
      }
      uVar6 = 1;
      goto LAB_00050d8b;
    }
  }
LAB_00050d80:
  uVar6 = 0;
  *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 3;
LAB_00050d8b:
  _IO_funlockfile(*(_IO_FILE **)*param_1);
  _pthread_cleanup_pop_restore(local_14,0);
  return uVar6;
}


