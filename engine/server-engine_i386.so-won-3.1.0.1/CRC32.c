// CRC32_Final  @ 00090c94
uint CRC32_Final(uint param_1)

{
  return ~param_1;
}


// CRC32_Final__FUl  @ 00095328
uint CRC32_Final__FUl(uint param_1)

{
  return ~param_1;
}


// CRC32_Init  @ 00090c84
void CRC32_Init(undefined4 *param_1)

{
  *param_1 = 0xffffffff;
  return;
}


// CRC32_Init__FPUl  @ 00095318
void CRC32_Init__FPUl(undefined4 *param_1)

{
  *param_1 = 0xffffffff;
  return;
}


// CRC32_ProcessBuffer  @ 00090cd8
void CRC32_ProcessBuffer(uint *param_1,uint *param_2,uint param_3)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  uint *local_c;
  uint local_8;
  
  uVar5 = *param_1;
  local_c = param_2;
  do {
    bVar2 = (byte)uVar5;
    switch(param_3) {
    case 3:
      uVar4 = *local_c;
      local_c = (uint *)((int)local_c + 1);
      uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uint)(byte)(bVar2 ^ (byte)uVar4) * 4);
    case 2:
      uVar4 = *local_c;
      local_c = (uint *)((int)local_c + 1);
      uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uint)(byte)((byte)uVar5 ^ (byte)uVar4) * 4);
    case 1:
      uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uint)(byte)((byte)uVar5 ^ (byte)*local_c) * 4);
    case 0:
      *param_1 = uVar5;
      return;
    case 7:
      uVar4 = *local_c;
      local_c = (uint *)((int)local_c + 1);
      uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uint)(byte)(bVar2 ^ (byte)uVar4) * 4);
    case 6:
      uVar4 = *local_c;
      local_c = (uint *)((int)local_c + 1);
      uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uint)(byte)((byte)uVar5 ^ (byte)uVar4) * 4);
    case 5:
      uVar4 = *local_c;
      local_c = (uint *)((int)local_c + 1);
      uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uint)(byte)((byte)uVar5 ^ (byte)uVar4) * 4);
    case 4:
      uVar5 = (uVar5 ^ *local_c) >> 8 ^ *(uint *)(&pulCRCTable + ((uVar5 ^ *local_c) & 0xff) * 4);
      uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4);
      uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4);
      *param_1 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4);
      return;
    }
    uVar4 = (uint)local_c & 3;
    if (uVar4 == 2) {
LAB_00090e5e:
      uVar3 = *local_c;
      local_c = (uint *)((int)local_c + 1);
      uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uint)(byte)((byte)uVar5 ^ (byte)uVar3) * 4);
LAB_00090e7b:
      uVar3 = *local_c;
      local_c = (uint *)((int)local_c + 1);
      uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uint)(byte)((byte)uVar5 ^ (byte)uVar3) * 4);
    }
    else if (uVar4 < 3) {
      if (uVar4 == 1) goto LAB_00090e7b;
    }
    else if (uVar4 == 3) {
      uVar3 = *local_c;
      local_c = (uint *)((int)local_c + 1);
      uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uint)(byte)(bVar2 ^ (byte)uVar3) * 4);
      goto LAB_00090e5e;
    }
    iVar1 = (int)(param_3 - uVar4) >> 3;
    local_8 = iVar1 - 1;
    if (iVar1 != 0) {
      if ((~local_8 & 1) != 0) {
        uVar5 = (uVar5 ^ *local_c) >> 8 ^ *(uint *)(&pulCRCTable + ((uVar5 ^ *local_c) & 0xff) * 4);
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4);
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4);
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4) ^ local_c[1];
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4);
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4);
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4);
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4);
        local_c = local_c + 2;
        bVar6 = local_8 == 0;
        local_8 = iVar1 - 2;
        if (bVar6) goto LAB_00090fec;
      }
      do {
        uVar5 = (uVar5 ^ *local_c) >> 8 ^ *(uint *)(&pulCRCTable + ((uVar5 ^ *local_c) & 0xff) * 4);
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4);
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4);
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4) ^ local_c[1];
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4);
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4);
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4);
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4) ^ local_c[2];
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4);
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4);
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4);
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4) ^ local_c[3];
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4);
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4);
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4);
        uVar5 = uVar5 >> 8 ^ *(uint *)(&pulCRCTable + (uVar5 & 0xff) * 4);
        local_c = local_c + 4;
        local_8 = local_8 - 2;
      } while (local_8 != 0xffffffff);
    }
LAB_00090fec:
    param_3 = param_3 - uVar4 & 7;
  } while( true );
}


// CRC32_ProcessBuffer__FPUlPvi  @ 00095358
void CRC32_ProcessBuffer__FPUlPvi(uint *param_1,uint *param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  
  uVar3 = *param_1;
  do {
    bVar1 = (byte)uVar3;
    switch(param_3) {
    case 3:
      uVar2 = *param_2;
      param_2 = (uint *)((int)param_2 + 1);
      uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uint)(byte)(bVar1 ^ (byte)uVar2) * 4);
    case 2:
      uVar2 = *param_2;
      param_2 = (uint *)((int)param_2 + 1);
      uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uint)(byte)((byte)uVar3 ^ (byte)uVar2) * 4);
    case 1:
      uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uint)(byte)((byte)uVar3 ^ (byte)*param_2) * 4);
    case 0:
      *param_1 = uVar3;
      return;
    case 7:
      uVar2 = *param_2;
      param_2 = (uint *)((int)param_2 + 1);
      uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uint)(byte)(bVar1 ^ (byte)uVar2) * 4);
    case 6:
      uVar2 = *param_2;
      param_2 = (uint *)((int)param_2 + 1);
      uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uint)(byte)((byte)uVar3 ^ (byte)uVar2) * 4);
    case 5:
      uVar2 = *param_2;
      param_2 = (uint *)((int)param_2 + 1);
      uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uint)(byte)((byte)uVar3 ^ (byte)uVar2) * 4);
    case 4:
      uVar3 = (uVar3 ^ *param_2) >> 8 ^ *(uint *)(&pulCRCTable + ((uVar3 ^ *param_2) & 0xff) * 4);
      uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4);
      uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4);
      *param_1 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4);
      return;
    }
    uVar2 = (uint)param_2 & 3;
    if (uVar2 == 2) {
LAB_0009546d:
      uVar5 = *param_2;
      param_2 = (uint *)((int)param_2 + 1);
      uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uint)(byte)((byte)uVar3 ^ (byte)uVar5) * 4);
LAB_00095481:
      uVar5 = *param_2;
      param_2 = (uint *)((int)param_2 + 1);
      uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uint)(byte)((byte)uVar3 ^ (byte)uVar5) * 4);
    }
    else if (uVar2 < 3) {
      if (uVar2 == 1) goto LAB_00095481;
    }
    else if (uVar2 == 3) {
      uVar5 = *param_2;
      param_2 = (uint *)((int)param_2 + 1);
      uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uint)(byte)(bVar1 ^ (byte)uVar5) * 4);
      goto LAB_0009546d;
    }
    iVar4 = (int)(param_3 - uVar2) >> 3;
    uVar5 = iVar4 - 1;
    if (iVar4 != 0) {
      if ((~uVar5 & 1) != 0) {
        uVar3 = (uVar3 ^ *param_2) >> 8 ^ *(uint *)(&pulCRCTable + ((uVar3 ^ *param_2) & 0xff) * 4);
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4);
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4);
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4) ^ param_2[1];
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4);
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4);
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4);
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4);
        param_2 = param_2 + 2;
        bVar6 = uVar5 == 0;
        uVar5 = iVar4 - 2;
        if (bVar6) goto LAB_000955ce;
      }
      do {
        uVar3 = (uVar3 ^ *param_2) >> 8 ^ *(uint *)(&pulCRCTable + ((uVar3 ^ *param_2) & 0xff) * 4);
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4);
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4);
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4) ^ param_2[1];
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4);
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4);
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4);
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4) ^ param_2[2];
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4);
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4);
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4);
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4) ^ param_2[3];
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4);
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4);
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4);
        uVar3 = uVar3 >> 8 ^ *(uint *)(&pulCRCTable + (uVar3 & 0xff) * 4);
        param_2 = param_2 + 4;
        uVar5 = uVar5 - 2;
      } while (uVar5 != 0xffffffff);
    }
LAB_000955ce:
    param_3 = param_3 - uVar2 & 7;
  } while( true );
}


// CRC32_ProcessByte  @ 00090ca0
void CRC32_ProcessByte(uint *param_1,byte param_2)

{
  *param_1 = *param_1 >> 8 ^ *(uint *)(&pulCRCTable + (((uint)param_2 ^ *param_1) & 0xff) * 4);
  return;
}


// CRC32_ProcessByte__FPUlUc  @ 00095334
void CRC32_ProcessByte__FPUlUc(uint *param_1,byte param_2)

{
  *param_1 = *param_1 >> 8 ^ *(uint *)(&pulCRCTable + (((uint)param_2 ^ *param_1) & 0xff) * 4);
  return;
}


