// gcc2_compiled.  @ 0804c684
void gcc2_compiled_(void)

{
  code *pcVar1;
  
  if (completed_3 == 0) {
    while (*(int *)p_2 != 0) {
      pcVar1 = *(code **)p_2;
      p_2 = p_2 + 4;
      (*pcVar1)();
    }
    __deregister_frame_info(&cie_080acb3c);
    completed_3 = 1;
  }
  return;
}


// gcc2_compiled.  @ 0808d680
void gcc2_compiled_(char *param_1,char *param_2,char *param_3,char *param_4,char *param_5)

{
  char cVar1;
  int iVar2;
  size_t sVar3;
  char *pcVar4;
  char *pcVar5;
  char *local_8;
  
  local_8 = (char *)0x0;
  iVar2 = -1;
  pcVar5 = param_1;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if ((iVar2 == -2) || (param_1[1] != ':')) {
    if (param_2 != (char *)0x0) {
      *param_2 = '\0';
    }
  }
  else {
    if (param_2 != (char *)0x0) {
      strncpy(param_2,param_1,2);
      param_2[2] = '\0';
    }
    param_1 = param_1 + 2;
  }
  pcVar5 = (char *)0x0;
  cVar1 = *param_1;
  pcVar4 = param_1;
  while (cVar1 != '\0') {
    if ((*pcVar4 == '/') || (*pcVar4 == '\\')) {
      pcVar5 = pcVar4 + 1;
    }
    else if (*pcVar4 == '.') {
      local_8 = pcVar4;
    }
    pcVar4 = pcVar4 + 1;
    cVar1 = *pcVar4;
  }
  if (pcVar5 == (char *)0x0) {
    pcVar5 = param_1;
    if (param_3 != (char *)0x0) {
      *param_3 = '\0';
    }
  }
  else if (param_3 != (char *)0x0) {
    sVar3 = (int)pcVar5 - (int)param_1;
    if (0xff < sVar3) {
      sVar3 = 0xff;
    }
    strncpy(param_3,param_1,sVar3);
    param_3[sVar3] = '\0';
  }
  param_1 = pcVar5;
  if ((local_8 == (char *)0x0) || (local_8 < param_1)) {
    if (param_4 != (char *)0x0) {
      sVar3 = (int)pcVar4 - (int)param_1;
      if (0xff < sVar3) {
        sVar3 = 0xff;
      }
      strncpy(param_4,param_1,sVar3);
      param_4[sVar3] = '\0';
    }
    if (param_5 != (char *)0x0) {
      *param_5 = '\0';
    }
  }
  else {
    if (param_4 != (char *)0x0) {
      sVar3 = (int)local_8 - (int)param_1;
      if (0xff < sVar3) {
        sVar3 = 0xff;
      }
      strncpy(param_4,param_1,sVar3);
      param_4[sVar3] = '\0';
    }
    if (param_5 != (char *)0x0) {
      sVar3 = (int)pcVar4 - (int)local_8;
      if (0xff < sVar3) {
        sVar3 = 0xff;
      }
      strncpy(param_5,local_8,sVar3);
      param_5[sVar3] = '\0';
    }
  }
  return;
}


// gcc2_compiled.  @ 080905d0
void gcc2_compiled_(undefined4 *param_1)

{
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  return;
}


// gcc2_compiled.  @ 080908b0
int * gcc2_compiled_(int *param_1,int param_2)

{
  int iVar1;
  
  param_1[3] = (int)__vt_11WriteBuffer;
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("theSize>0","/e/quiver/goldsrc/common/WriteBuffer.cpp",0x1c,
                  "WriteBuffer::WriteBuffer(long unsigned int = 256)");
  }
  iVar1 = __builtin_vec_new(param_2);
  *param_1 = iVar1;
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("mBuffer","/e/quiver/goldsrc/common/WriteBuffer.cpp",0x1f,
                  "WriteBuffer::WriteBuffer(long unsigned int = 256)");
  }
  param_1[2] = 0;
  param_1[1] = param_2;
  return param_1;
}


// gcc2_compiled.  @ 0809dd6c
void gcc2_compiled_(void)

{
  undefined *puVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &PTR__GLOBAL__I_WSAGetLastError__Fv_080b1b74;
  puVar1 = PTR__GLOBAL__I_WSAGetLastError__Fv_080b1b74;
  while (puVar1 != (undefined *)0xffffffff) {
    (*(code *)*ppuVar2)();
    ppuVar2 = ppuVar2 + -1;
    puVar1 = *ppuVar2;
  }
  return;
}


