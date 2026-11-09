// CRC32_Final  @ 0808c130
uint CRC32_Final(uint param_1)

{
  return ~param_1;
}


// CRC32_Init  @ 0808c120
void CRC32_Init(undefined4 *param_1)

{
  *param_1 = 0xffffffff;
  return;
}


// CRC32_ProcessBuffer  @ 0808c170
void CRC32_ProcessBuffer(uint *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  int local_8;
  
  uVar3 = *param_1;
  do {
    bVar2 = (byte)uVar3;
    switch(param_3) {
    case 3:
      uVar3 = uVar3 >> 8 ^ *(uint *)(pulCRCTable + (uint)(byte)((byte)*param_2 ^ bVar2) * 4);
      param_2 = (uint *)((int)param_2 + 1);
    case 2:
      uVar3 = uVar3 >> 8 ^ *(uint *)(pulCRCTable + (uint)(byte)((byte)*param_2 ^ (byte)uVar3) * 4);
      param_2 = (uint *)((int)param_2 + 1);
    case 1:
      uVar3 = uVar3 >> 8 ^ *(uint *)(pulCRCTable + (uint)(byte)((byte)*param_2 ^ (byte)uVar3) * 4);
    case 0:
      *param_1 = uVar3;
      return;
    case 7:
      uVar3 = uVar3 >> 8 ^ *(uint *)(pulCRCTable + (uint)(byte)((byte)*param_2 ^ bVar2) * 4);
      param_2 = (uint *)((int)param_2 + 1);
    case 6:
      uVar3 = uVar3 >> 8 ^ *(uint *)(pulCRCTable + (uint)(byte)((byte)*param_2 ^ (byte)uVar3) * 4);
      param_2 = (uint *)((int)param_2 + 1);
    case 5:
      uVar3 = uVar3 >> 8 ^ *(uint *)(pulCRCTable + (uint)(byte)((byte)*param_2 ^ (byte)uVar3) * 4);
      param_2 = (uint *)((int)param_2 + 1);
    case 4:
      uVar3 = (uVar3 ^ *param_2) >> 8 ^ *(uint *)(pulCRCTable + ((uVar3 ^ *param_2) & 0xff) * 4);
      uVar3 = uVar3 >> 8 ^ *(uint *)(pulCRCTable + (uVar3 & 0xff) * 4);
      uVar3 = uVar3 >> 8 ^ *(uint *)(pulCRCTable + (uVar3 & 0xff) * 4);
      *param_1 = uVar3 >> 8 ^ *(uint *)(pulCRCTable + (uVar3 & 0xff) * 4);
      return;
    }
    uVar1 = (uint)param_2 & 3;
    if (uVar1 == 2) {
LAB_0808c2bc:
      uVar3 = uVar3 >> 8 ^ *(uint *)(pulCRCTable + (uint)(byte)((byte)*param_2 ^ (byte)uVar3) * 4);
      param_2 = (uint *)((int)param_2 + 1);
LAB_0808c2d3:
      uVar3 = uVar3 >> 8 ^ *(uint *)(pulCRCTable + (uint)(byte)((byte)*param_2 ^ (byte)uVar3) * 4);
      param_2 = (uint *)((int)param_2 + 1);
    }
    else if (uVar1 < 3) {
      if (uVar1 == 1) goto LAB_0808c2d3;
    }
    else if (uVar1 == 3) {
      uVar3 = uVar3 >> 8 ^ *(uint *)(pulCRCTable + (uint)(byte)((byte)*param_2 ^ bVar2) * 4);
      param_2 = (uint *)((int)param_2 + 1);
      goto LAB_0808c2bc;
    }
    local_8 = (int)(param_3 - uVar1) >> 3;
    while (local_8 != 0) {
      local_8 = local_8 + -1;
      uVar3 = (uVar3 ^ *param_2) >> 8 ^ *(uint *)(pulCRCTable + ((uVar3 ^ *param_2) & 0xff) * 4);
      uVar3 = uVar3 >> 8 ^ *(uint *)(pulCRCTable + (uVar3 & 0xff) * 4);
      uVar3 = uVar3 >> 8 ^ *(uint *)(pulCRCTable + (uVar3 & 0xff) * 4);
      uVar3 = uVar3 >> 8 ^ *(uint *)(pulCRCTable + (uVar3 & 0xff) * 4) ^ param_2[1];
      uVar3 = uVar3 >> 8 ^ *(uint *)(pulCRCTable + (uVar3 & 0xff) * 4);
      uVar3 = uVar3 >> 8 ^ *(uint *)(pulCRCTable + (uVar3 & 0xff) * 4);
      uVar3 = uVar3 >> 8 ^ *(uint *)(pulCRCTable + (uVar3 & 0xff) * 4);
      uVar3 = uVar3 >> 8 ^ *(uint *)(pulCRCTable + (uVar3 & 0xff) * 4);
      param_2 = param_2 + 2;
    }
    param_3 = param_3 - uVar1 & 7;
  } while( true );
}


// CRC32_ProcessByte  @ 0808c140
void CRC32_ProcessByte(uint *param_1,byte param_2)

{
  *param_1 = *param_1 >> 8 ^ *(uint *)(pulCRCTable + (((uint)param_2 ^ *param_1) & 0xff) * 4);
  return;
}


