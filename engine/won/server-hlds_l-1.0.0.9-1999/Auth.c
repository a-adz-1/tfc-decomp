// Auth_CreatePath__FPc  @ 080944f0
void Auth_CreatePath__FPc(char *param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_1 + 1;
  cVar1 = param_1[1];
  while (cVar1 != '\0') {
    if ((*pcVar2 == '/') || (*pcVar2 == '\\')) {
      cVar1 = *pcVar2;
      *pcVar2 = '\0';
      mkdir(param_1,0x1ff);
      *pcVar2 = cVar1;
    }
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
  }
  return;
}


// Auth_GetLastError__11AuthRequest  @ 08090f00
int Auth_GetLastError__11AuthRequest(int param_1)

{
  return param_1 + 0x80a0;
}


// Auth_HashIP__FUlUsPc  @ 080945b0
void Auth_HashIP__FUlUsPc(undefined4 param_1,int param_2,char *param_3)

{
  char *__dest;
  char *__src;
  byte *pbVar1;
  int iVar2;
  undefined4 local_8;
  
  __dest = param_3;
  pbVar1 = (byte *)&param_1;
  local_8 = param_2 << 0x10;
  iVar2 = 0;
  do {
    local_8 = CONCAT22(local_8._2_2_,(ushort)local_8 + ((ushort)*pbVar1 ^ (ushort)local_8));
    pbVar1 = pbVar1 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  pbVar1 = (byte *)((int)&local_8 + 2);
  iVar2 = 0;
  do {
    local_8 = CONCAT22(local_8._2_2_,(ushort)local_8 + ((ushort)*pbVar1 ^ (ushort)local_8));
    pbVar1 = pbVar1 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  __src = (char *)Auth_Hashprint__FPUci(&local_8,2);
  strcpy(__dest,__src);
  __dest[4] = '\0';
  return;
}


// Auth_Hashprint__FPUci  @ 08094540
undefined1 * Auth_Hashprint__FPUci(int param_1,int param_2)

{
  int iVar1;
  char local_10 [12];
  
  memset(szReturn_539,0,0x80);
  iVar1 = 0;
  if (0 < param_2) {
    do {
      sprintf(local_10,"%02x",(uint)*(byte *)(iVar1 + param_1));
      strcat(szReturn_539,local_10);
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_2);
  }
  return szReturn_539;
}


// Auth_InitError__11AuthRequest  @ 08090eb0
void Auth_InitError__11AuthRequest(int param_1)

{
  sprintf((char *)(param_1 + 0x80a0),"No Error");
  *(undefined4 *)(param_1 + 0x809c) = 0;
  *(undefined4 *)(param_1 + 0x8094) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x8098) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x8090) = 0;
  return;
}


