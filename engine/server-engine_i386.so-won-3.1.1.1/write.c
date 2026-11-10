// write__7ostreamPCSci  @ 0005277c
void write__7ostreamPCSci(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  write__7ostreamPCci(param_1,param_2,param_3);
  return;
}


// write__7ostreamPCUci  @ 0005275c
void write__7ostreamPCUci(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  write__7ostreamPCci(param_1,param_2,param_3);
  return;
}


// write__7ostreamPCci  @ 000523d0
int * write__7ostreamPCci(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 local_14 [16];
  
  if (*(char *)(*param_1 + 0x12) == '\0') {
    iVar1 = *(int *)(*param_1 + 4);
    if (iVar1 != 0) {
      flush__7ostream(iVar1);
    }
    _IO_flockfile(*(_IO_FILE **)*param_1);
    _pthread_cleanup_push_defer(local_14,_IO_funlockfile,*(undefined4 *)*param_1);
    iVar1 = (**(code **)(*(int *)(*(int *)*param_1 + 0x4c) + 0x1c))
                      (*(int *)*param_1,param_2,param_3);
    if (iVar1 != param_3) {
      *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 2;
    }
    _IO_funlockfile(*(_IO_FILE **)*param_1);
    if ((*(byte *)(*param_1 + 0xd) & 0x60) != 0) {
      do_osfx__7ostream(param_1);
    }
    _pthread_cleanup_pop_restore(local_14,0);
  }
  return param_1;
}


// write__7ostreamPCvi  @ 0005279c
void write__7ostreamPCvi(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  write__7ostreamPCci(param_1,param_2,param_3);
  return;
}


// write_int__FR7ostreamUxi  @ 00051450
void write_int__FR7ostreamUxi(int *param_1,uint param_2,uint param_3,int param_4)

{
  undefined4 *puVar1;
  _IO_FILE *__fp;
  char cVar2;
  char cVar3;
  uint uVar4;
  undefined1 *puVar5;
  __ssize_t _Var6;
  int iVar7;
  char *pcVar8;
  undefined1 *puVar9;
  uint uVar10;
  int iVar11;
  char *pcVar12;
  undefined8 uVar13;
  int local_34;
  int local_30;
  char *local_2c;
  undefined1 local_28 [32];
  char local_8 [4];
  
  uVar13 = CONCAT44(param_3,param_2);
  local_2c = "";
  local_30 = 0;
  local_34 = 0;
  pcVar12 = local_8 + 2;
  uVar4 = *(uint *)(*param_1 + 0xc) & 0x70;
  if (uVar4 == 0x20) {
    do {
      pcVar8 = pcVar12;
      pcVar12 = pcVar8 + -1;
      cVar2 = ((byte)param_2 & 7) + 0x30;
      *pcVar12 = cVar2;
      param_2 = param_2 >> 3 | param_3 << 0x1d;
      param_3 = param_3 >> 3;
    } while (param_2 != 0 || param_3 != 0);
    if ((*(char *)(*param_1 + 0xc) < '\0') && (cVar2 != '0')) {
      pcVar12 = pcVar8 + -2;
      *pcVar12 = '0';
    }
  }
  else if (uVar4 == 0x40) {
    pcVar8 = "0123456789abcdef0x";
    if ((*(uint *)(*param_1 + 0xc) & 0x200) != 0) {
      pcVar8 = "0123456789ABCDEF0X";
    }
    do {
      pcVar12 = pcVar12 + -1;
      *pcVar12 = pcVar8[param_2 & 0xf];
      param_2 = param_2 >> 4 | param_3 << 0x1c;
      param_3 = param_3 >> 4;
    } while (param_2 != 0 || param_3 != 0);
    if (*(char *)(*param_1 + 0xc) < '\0') {
      local_2c = pcVar8 + 0x10;
      local_30 = 2;
    }
  }
  else {
    for (; uVar4 = (uint)uVar13, (int)((ulonglong)uVar13 >> 0x20) != 0;
        uVar13 = __udivdi3(uVar13,10,0)) {
      pcVar12 = pcVar12 + -1;
      cVar2 = __umoddi3(uVar13,10,0);
      *pcVar12 = cVar2 + '0';
    }
    do {
      pcVar12 = pcVar12 + -1;
      uVar10 = uVar4 / 10;
      *pcVar12 = (char)uVar4 + (char)uVar10 * -10 + '0';
      uVar4 = uVar10;
    } while (uVar10 != 0);
    if ((0 < param_4) && ((*(byte *)(*param_1 + 0xd) & 4) != 0)) {
      local_34 = 1;
    }
  }
  puVar9 = local_28 + -(int)(pcVar12 + -0x22);
  iVar7 = *(int *)(*param_1 + 8);
  *(undefined4 *)(*param_1 + 8) = 0;
  puVar5 = puVar9 + local_34;
  if (param_4 < 0) {
    puVar5 = puVar5 + 1;
  }
  iVar11 = 0;
  if ((int)(puVar5 + local_30) <= iVar7) {
    iVar11 = iVar7 - (int)(puVar5 + local_30);
  }
  puVar1 = (undefined4 *)*param_1;
  __fp = (_IO_FILE *)*puVar1;
  uVar4 = puVar1[3] & 0xe;
  cVar2 = *(char *)(puVar1 + 4);
  if ((((iVar11 < 1) || (uVar4 == 2)) || (uVar4 == 8)) ||
     (_Var6 = _IO_padn(__fp,(int)cVar2,iVar11), iVar11 <= _Var6)) {
    if ((param_4 < 0) || (local_34 != 0)) {
      cVar3 = '+';
      if (param_4 < 0) {
        cVar3 = '-';
      }
      iVar7 = _IO_putc((int)cVar3,__fp);
      if (iVar7 < 0) goto LAB_000516c0;
    }
    if (((((local_30 == 0) ||
          (iVar7 = (**(code **)((int)__fp->_offset + 0x1c))(__fp,local_2c,local_30), iVar7 != 0)) &&
         ((uVar4 != 8 ||
          ((iVar11 < 1 || (_Var6 = _IO_padn(__fp,(int)cVar2,iVar11), iVar11 <= _Var6)))))) &&
        (puVar5 = (undefined1 *)(**(code **)((int)__fp->_offset + 0x1c))(__fp,pcVar12,puVar9),
        puVar5 == puVar9)) &&
       (((uVar4 != 2 || (iVar11 < 1)) || (_Var6 = _IO_padn(__fp,(int)cVar2,iVar11), iVar11 <= _Var6)
        ))) {
      _IO_funlockfile(*(_IO_FILE **)*param_1);
      if ((*(byte *)(*param_1 + 0xd) & 0x60) == 0) {
        return;
      }
      do_osfx__7ostream(param_1);
      return;
    }
  }
LAB_000516c0:
  *(byte *)(*param_1 + 0x12) = *(byte *)(*param_1 + 0x12) | 4;
  _IO_funlockfile(*(_IO_FILE **)*param_1);
  if ((*(byte *)(*param_1 + 0xd) & 0x60) != 0) {
    do_osfx__7ostream(param_1);
  }
  return;
}


