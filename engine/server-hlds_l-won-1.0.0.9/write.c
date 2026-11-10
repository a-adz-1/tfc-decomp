// write__7ostreamPCSci  @ 0809d418
void write__7ostreamPCSci(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  write__7ostreamPCci(param_1,param_2,param_3);
  return;
}


// write__7ostreamPCUci  @ 0809d430
void write__7ostreamPCUci(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  write__7ostreamPCci(param_1,param_2,param_3);
  return;
}


// write__7ostreamPCci  @ 0809c8fc
/* WARNING: Removing unreachable block (ram,0x0809c945) */
/* WARNING: Removing unreachable block (ram,0x0809c9aa) */

int * write__7ostreamPCci(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
  }
  if (*(char *)(iVar1 + 0x12) == '\0') {
    puVar2 = (undefined4 *)*param_1;
    if (puVar2[1] != 0) {
      flush__7ostream(puVar2[1]);
      puVar2 = (undefined4 *)*param_1;
    }
    _IO_flockfile((_IO_FILE *)*puVar2);
    iVar1 = (**(code **)(*(int *)(*(int *)*param_1 + 0x4c) + 0x1c))
                      (*(int *)*param_1,param_2,param_3);
    if (iVar1 != param_3) {
      iVar1 = 0;
      if (param_1 != (int *)0x0) {
        iVar1 = *param_1;
      }
      *(byte *)(iVar1 + 0x12) = *(byte *)(iVar1 + 0x12) | 2;
    }
    _IO_funlockfile(*(_IO_FILE **)*param_1);
    iVar1 = 0;
    if (param_1 != (int *)0x0) {
      iVar1 = *param_1;
    }
    if ((*(byte *)(iVar1 + 0xd) & 0x60) != 0) {
      do_osfx__7ostream(param_1);
    }
  }
  return param_1;
}


// write__7ostreamPCvi  @ 0809d400
void write__7ostreamPCvi(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  write__7ostreamPCci(param_1,param_2,param_3);
  return;
}


// write_int__FR7ostreamUxi  @ 0809b890
void write_int__FR7ostreamUxi(int *param_1,uint param_2,uint param_3,int param_4)

{
  _IO_FILE *__fp;
  __ssize_t _Var1;
  char *pcVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  char *pcVar11;
  undefined8 uVar12;
  int local_34;
  int local_30;
  char *local_2c;
  char local_8 [4];
  
  uVar12 = CONCAT44(param_3,param_2);
  iVar5 = 0;
  pcVar11 = local_8 + 2;
  local_2c = "";
  local_30 = 0;
  local_34 = 0;
  if (param_1 != (int *)0x0) {
    iVar5 = *param_1;
  }
  if ((*(uint *)(iVar5 + 0xc) & 0x70) == 0x20) {
    do {
      pcVar6 = pcVar11;
      pcVar11 = pcVar6 + -1;
      cVar3 = ((byte)param_2 & 7) + 0x30;
      *pcVar11 = cVar3;
      param_2 = param_2 >> 3 | param_3 << 0x1d;
      param_3 = param_3 >> 3;
    } while (param_2 != 0 || param_3 != 0);
    iVar5 = 0;
    if (param_1 != (int *)0x0) {
      iVar5 = *param_1;
    }
    if ((*(char *)(iVar5 + 0xc) < '\0') && (cVar3 != '0')) {
      pcVar11 = pcVar6 + -2;
      *pcVar11 = '0';
    }
  }
  else {
    iVar5 = 0;
    if (param_1 != (int *)0x0) {
      iVar5 = *param_1;
    }
    if ((*(uint *)(iVar5 + 0xc) & 0x70) == 0x40) {
      iVar5 = 0;
      if (param_1 != (int *)0x0) {
        iVar5 = *param_1;
      }
      pcVar6 = "0123456789abcdef0x";
      if ((*(byte *)(iVar5 + 0xd) & 2) != 0) {
        pcVar6 = "0123456789ABCDEF0X";
      }
      do {
        pcVar11 = pcVar11 + -1;
        uVar10 = param_2 & 0xf;
        param_2 = param_2 >> 4 | param_3 << 0x1c;
        param_3 = param_3 >> 4;
        *pcVar11 = pcVar6[uVar10];
      } while (param_2 != 0 || param_3 != 0);
      iVar5 = 0;
      if (param_1 != (int *)0x0) {
        iVar5 = *param_1;
      }
      if (*(char *)(iVar5 + 0xc) < '\0') {
        local_2c = pcVar6 + 0x10;
        local_30 = 2;
      }
    }
    else {
      while( true ) {
        uVar10 = (uint)uVar12;
        if ((int)((ulonglong)uVar12 >> 0x20) == 0) break;
        pcVar11 = pcVar11 + -1;
        cVar3 = __umoddi3(uVar12,10,0);
        *pcVar11 = cVar3 + '0';
        uVar12 = __udivdi3(uVar12,10,0);
      }
      do {
        pcVar11 = pcVar11 + -1;
        uVar7 = uVar10 / 10;
        *pcVar11 = (char)uVar10 + (char)uVar7 * -10 + '0';
        uVar10 = uVar7;
      } while (uVar7 != 0);
      if (0 < param_4) {
        iVar5 = 0;
        if (param_1 != (int *)0x0) {
          iVar5 = *param_1;
        }
        if ((*(byte *)(iVar5 + 0xd) & 4) != 0) {
          local_34 = 1;
        }
      }
    }
  }
  pcVar6 = local_8 + (2 - (int)pcVar11);
  iVar5 = 0;
  if (param_1 != (int *)0x0) {
    iVar5 = *param_1;
  }
  iVar9 = *(int *)(iVar5 + 8);
  *(undefined4 *)(iVar5 + 8) = 0;
  pcVar2 = pcVar6 + local_34;
  if (param_4 < 0) {
    pcVar2 = pcVar2 + 1;
  }
  iVar5 = 0;
  if ((int)(pcVar2 + local_30) <= iVar9) {
    iVar5 = iVar9 - (int)(pcVar2 + local_30);
  }
  puVar8 = (undefined4 *)0x0;
  if (param_1 != (int *)0x0) {
    puVar8 = (undefined4 *)*param_1;
  }
  __fp = (_IO_FILE *)*puVar8;
  iVar9 = 0;
  if (param_1 != (int *)0x0) {
    iVar9 = *param_1;
  }
  uVar10 = *(uint *)(iVar9 + 0xc) & 0xe;
  iVar9 = 0;
  if (param_1 != (int *)0x0) {
    iVar9 = *param_1;
  }
  cVar3 = *(char *)(iVar9 + 0x10);
  if ((((iVar5 < 1) || (uVar10 == 2)) || (uVar10 == 8)) ||
     (_Var1 = _IO_padn(__fp,(int)cVar3,iVar5), iVar5 <= _Var1)) {
    if ((param_4 < 0) || (local_34 != 0)) {
      cVar4 = '+';
      if (param_4 < 0) {
        cVar4 = '-';
      }
      iVar9 = _IO_putc((int)cVar4,__fp);
      if (iVar9 < 0) goto LAB_0809bb34;
    }
    if (((((local_30 == 0) ||
          (iVar9 = (**(code **)((int)__fp->_offset + 0x1c))(__fp,local_2c,local_30), iVar9 != 0)) &&
         ((uVar10 != 8 || ((iVar5 < 1 || (_Var1 = _IO_padn(__fp,(int)cVar3,iVar5), iVar5 <= _Var1)))
          ))) && (pcVar11 = (char *)(**(code **)((int)__fp->_offset + 0x1c))(__fp,pcVar11,pcVar6),
                 pcVar11 == pcVar6)) &&
       (((uVar10 != 2 || (iVar5 < 1)) || (_Var1 = _IO_padn(__fp,(int)cVar3,iVar5), iVar5 <= _Var1)))
       ) goto LAB_0809bb45;
  }
LAB_0809bb34:
  iVar5 = 0;
  if (param_1 != (int *)0x0) {
    iVar5 = *param_1;
  }
  *(byte *)(iVar5 + 0x12) = *(byte *)(iVar5 + 0x12) | 4;
LAB_0809bb45:
  _IO_funlockfile(*(_IO_FILE **)*param_1);
  iVar5 = 0;
  if (param_1 != (int *)0x0) {
    iVar5 = *param_1;
  }
  if ((*(byte *)(iVar5 + 0xd) & 0x60) != 0) {
    do_osfx__7ostream(param_1);
  }
  return;
}


