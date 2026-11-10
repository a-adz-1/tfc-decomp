// CRC32_Final  @ 0005cabc
uint CRC32_Final(uint param_1)

{
  return ~param_1;
}


// CRC32_Final__FUl  @ 000cc8d8
uint CRC32_Final__FUl(uint param_1)

{
  return ~param_1;
}


// CRC32_Init  @ 0005caac
void CRC32_Init(undefined4 *param_1)

{
  *param_1 = 0xffffffff;
  return;
}


// CRC32_Init__FPUl  @ 000cc8c4
void CRC32_Init__FPUl(undefined4 *param_1)

{
  *param_1 = 0xffffffff;
  return;
}


// CRC32_ProcessBuffer  @ 0005cb28
void CRC32_ProcessBuffer(uint *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  int iStack_14;
  uint *local_c;
  uint local_8;
  
  local_8 = *param_1;
  local_c = param_2;
  switch(param_3) {
  case 3:
    local_8 = *(uint *)(&pulCRCTable + (uint)(byte)((byte)*param_2 ^ (byte)local_8) * 4) ^
              local_8 >> 8;
    local_c = (uint *)((int)param_2 + 1);
  case 2:
    local_8 = *(uint *)(&pulCRCTable + (uint)(byte)((byte)*local_c ^ (byte)local_8) * 4) ^
              local_8 >> 8;
    local_c = (uint *)((int)local_c + 1);
  case 1:
    local_8 = *(uint *)(&pulCRCTable + (uint)(byte)((byte)*local_c ^ (byte)local_8) * 4) ^
              local_8 >> 8;
  case 0:
    *param_1 = local_8;
    FUN_0005cf18();
    return;
  case 7:
    local_8 = *(uint *)(&pulCRCTable + (uint)(byte)((byte)*param_2 ^ (byte)local_8) * 4) ^
              local_8 >> 8;
    local_c = (uint *)((int)param_2 + 1);
  case 6:
    local_8 = *(uint *)(&pulCRCTable + (uint)(byte)((byte)*local_c ^ (byte)local_8) * 4) ^
              local_8 >> 8;
    local_c = (uint *)((int)local_c + 1);
  case 5:
    local_8 = *(uint *)(&pulCRCTable + (uint)(byte)((byte)*local_c ^ (byte)local_8) * 4) ^
              local_8 >> 8;
    local_c = (uint *)((int)local_c + 1);
  case 4:
    uVar1 = *(uint *)(&pulCRCTable + ((local_8 ^ *local_c) & 0xff) * 4) ^ (local_8 ^ *local_c) >> 8;
    uVar1 = *(uint *)(&pulCRCTable + (uVar1 & 0xff) * 4) ^ uVar1 >> 8;
    uVar1 = *(uint *)(&pulCRCTable + (uVar1 & 0xff) * 4) ^ uVar1 >> 8;
    *param_1 = *(uint *)(&pulCRCTable + (uVar1 & 0xff) * 4) ^ uVar1 >> 8;
    FUN_0005cf18();
    return;
  default:
    iStack_14 = (int)(param_3 - ((uint)param_2 & 3)) >> 3;
    do {
      iStack_14 = iStack_14 + -1;
    } while (iStack_14 != -1);
    FUN_0005cf0c();
    return;
  }
}


// CRC32_ProcessBuffer__FPUlPvi  @ 000cc93c
void CRC32_ProcessBuffer__FPUlPvi(uint *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int local_14;
  uint *local_c;
  uint local_8;
  
  local_8 = *param_1;
  local_c = param_2;
  do {
    switch(param_3) {
    case 3:
      local_8 = *(uint *)(&pulCRCTable + (uint)(byte)((byte)*local_c ^ (byte)local_8) * 4) ^
                local_8 >> 8;
      local_c = (uint *)((int)local_c + 1);
    case 2:
      local_8 = *(uint *)(&pulCRCTable + (uint)(byte)((byte)*local_c ^ (byte)local_8) * 4) ^
                local_8 >> 8;
      local_c = (uint *)((int)local_c + 1);
    case 1:
      local_8 = *(uint *)(&pulCRCTable + (uint)(byte)((byte)*local_c ^ (byte)local_8) * 4) ^
                local_8 >> 8;
    case 0:
      *param_1 = local_8;
      return;
    case 7:
      local_8 = *(uint *)(&pulCRCTable + (uint)(byte)((byte)*local_c ^ (byte)local_8) * 4) ^
                local_8 >> 8;
      local_c = (uint *)((int)local_c + 1);
    case 6:
      local_8 = *(uint *)(&pulCRCTable + (uint)(byte)((byte)*local_c ^ (byte)local_8) * 4) ^
                local_8 >> 8;
      local_c = (uint *)((int)local_c + 1);
    case 5:
      local_8 = *(uint *)(&pulCRCTable + (uint)(byte)((byte)*local_c ^ (byte)local_8) * 4) ^
                local_8 >> 8;
      local_c = (uint *)((int)local_c + 1);
    case 4:
      uVar1 = *(uint *)(&pulCRCTable + ((local_8 ^ *local_c) & 0xff) * 4) ^
              (local_8 ^ *local_c) >> 8;
      uVar1 = *(uint *)(&pulCRCTable + (uVar1 & 0xff) * 4) ^ uVar1 >> 8;
      uVar1 = *(uint *)(&pulCRCTable + (uVar1 & 0xff) * 4) ^ uVar1 >> 8;
      *param_1 = *(uint *)(&pulCRCTable + (uVar1 & 0xff) * 4) ^ uVar1 >> 8;
      return;
    }
    uVar1 = (uint)local_c & 3;
    if (uVar1 == 2) {
LAB_000ccb5d:
      local_8 = *(uint *)(&pulCRCTable + (uint)(byte)((byte)*local_c ^ (byte)local_8) * 4) ^
                local_8 >> 8;
      local_c = (uint *)((int)local_c + 1);
LAB_000ccb86:
      local_8 = *(uint *)(&pulCRCTable + (uint)(byte)((byte)*local_c ^ (byte)local_8) * 4) ^
                local_8 >> 8;
      local_c = (uint *)((int)local_c + 1);
    }
    else if (uVar1 < 3) {
      if (uVar1 == 1) goto LAB_000ccb86;
    }
    else if (uVar1 == 3) {
      local_8 = *(uint *)(&pulCRCTable + (uint)(byte)((byte)*local_c ^ (byte)local_8) * 4) ^
                local_8 >> 8;
      local_c = (uint *)((int)local_c + 1);
      goto LAB_000ccb5d;
    }
    local_14 = (int)(param_3 - uVar1) >> 3;
    while (local_14 = local_14 + -1, local_14 != -1) {
      uVar2 = *(uint *)(&pulCRCTable + ((local_8 ^ *local_c) & 0xff) * 4) ^
              (local_8 ^ *local_c) >> 8;
      uVar2 = *(uint *)(&pulCRCTable + (uVar2 & 0xff) * 4) ^ uVar2 >> 8;
      uVar2 = *(uint *)(&pulCRCTable + (uVar2 & 0xff) * 4) ^ uVar2 >> 8;
      uVar2 = *(uint *)(&pulCRCTable + (uVar2 & 0xff) * 4) ^ uVar2 >> 8 ^ local_c[1];
      uVar2 = *(uint *)(&pulCRCTable + (uVar2 & 0xff) * 4) ^ uVar2 >> 8;
      uVar2 = *(uint *)(&pulCRCTable + (uVar2 & 0xff) * 4) ^ uVar2 >> 8;
      uVar2 = *(uint *)(&pulCRCTable + (uVar2 & 0xff) * 4) ^ uVar2 >> 8;
      local_8 = *(uint *)(&pulCRCTable + (uVar2 & 0xff) * 4) ^ uVar2 >> 8;
      local_c = local_c + 2;
    }
    param_3 = param_3 - uVar1 & 7;
  } while( true );
}


// CRC32_ProcessByte  @ 0005cacc
void CRC32_ProcessByte(uint *param_1,byte param_2)

{
  *param_1 = *(uint *)(&pulCRCTable + ((*param_1 ^ (uint)param_2) & 0xff) * 4) ^ *param_1 >> 8;
  return;
}


// CRC32_ProcessByte__FPUlUc  @ 000cc8ec
void CRC32_ProcessByte__FPUlUc(uint *param_1,byte param_2)

{
  *param_1 = *(uint *)(&pulCRCTable + ((*param_1 ^ (uint)param_2) & 0xff) * 4) ^ *param_1 >> 8;
  return;
}


