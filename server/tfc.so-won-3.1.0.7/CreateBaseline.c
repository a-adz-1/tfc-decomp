// CreateBaseline__FiiP14entity_state_sP7edict_siG6VectorT5  @ 00093ac8
void CreateBaseline__FiiP14entity_state_sP7edict_siG6VectorT5
               (int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
               undefined4 *param_6,undefined4 *param_7)

{
  uint local_14;
  
  *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)(param_4 + 0x88);
  *(undefined4 *)(param_3 + 0x14) = *(undefined4 *)(param_4 + 0x8c);
  *(undefined4 *)(param_3 + 0x18) = *(undefined4 *)(param_4 + 0x90);
  *(undefined4 *)(param_3 + 0x1c) = *(undefined4 *)(param_4 + 0xd0);
  *(undefined4 *)(param_3 + 0x20) = *(undefined4 *)(param_4 + 0xd4);
  *(undefined4 *)(param_3 + 0x24) = *(undefined4 *)(param_4 + 0xd8);
  *(undefined4 *)(param_3 + 0x30) = *(undefined4 *)(param_4 + 0x1b0);
  *(undefined2 *)(param_3 + 0x38) = *(undefined2 *)(param_4 + 400);
  *(uint *)(param_3 + 0x48) = (uint)*(byte *)(param_4 + 0x1c8);
  local_14 = (uint)(longlong)ROUND(*(float *)(param_4 + 0x1cc));
  *(uint *)(param_3 + 0x4c) = local_14 & 0xff;
  *(char *)(param_3 + 0x50) = (char)(longlong)ROUND(*(float *)(param_4 + 0x1d0));
  *(char *)(param_3 + 0x51) = (char)(longlong)ROUND(*(float *)(param_4 + 0x1d4));
  *(char *)(param_3 + 0x52) = (char)(longlong)ROUND(*(float *)(param_4 + 0x1d8));
  *(uint *)(param_3 + 0x54) = (uint)*(byte *)(param_4 + 0x1dc);
  if (param_1 == 0) {
    *(undefined4 *)(param_3 + 0x7c) = *(undefined4 *)(param_4 + 0x15c);
    *(undefined4 *)(param_3 + 0x80) = *(undefined4 *)(param_4 + 0x160);
    *(undefined4 *)(param_3 + 0x84) = *(undefined4 *)(param_4 + 0x164);
    *(undefined4 *)(param_3 + 0x88) = *(undefined4 *)(param_4 + 0x168);
    *(undefined4 *)(param_3 + 0x8c) = *(undefined4 *)(param_4 + 0x16c);
    *(undefined4 *)(param_3 + 0x90) = *(undefined4 *)(param_4 + 0x170);
    *(undefined4 *)(param_3 + 0x34) = 0;
    *(undefined4 *)(param_3 + 0x28) = *(undefined4 *)(param_4 + 0x134);
    *(undefined4 *)(param_3 + 0x58) = *(undefined4 *)(param_4 + 0x188);
    *(undefined4 *)(param_3 + 0x40) = *(undefined4 *)(param_4 + 0x1c4);
    *(undefined2 *)(param_3 + 0x3a) = *(undefined2 *)(param_4 + 0x18c);
    *(undefined4 *)(param_3 + 0x60) = *(undefined4 *)(param_4 + 0x1b8);
    *(undefined4 *)(param_3 + 0xa0) = *(undefined4 *)(param_4 + 0x19c);
  }
  else {
    *(undefined4 *)(param_3 + 0x7c) = *param_6;
    *(undefined4 *)(param_3 + 0x80) = param_6[1];
    *(undefined4 *)(param_3 + 0x84) = param_6[2];
    *(undefined4 *)(param_3 + 0x88) = *param_7;
    *(undefined4 *)(param_3 + 0x8c) = param_7[1];
    *(undefined4 *)(param_3 + 0x90) = param_7[2];
    *(undefined4 *)(param_3 + 0x34) = param_2;
    *(undefined4 *)(param_3 + 0x28) = param_5;
    *(undefined4 *)(param_3 + 0x9c) = 0x3f800000;
    *(undefined4 *)(param_3 + 0x58) = 3;
    *(undefined4 *)(param_3 + 0x40) = *(undefined4 *)(param_4 + 0x1c4);
    *(undefined2 *)(param_3 + 0x3a) = 3;
    *(undefined4 *)(param_3 + 0x60) = 0x3f800000;
    *(undefined4 *)(param_3 + 0xa0) = 0x3f800000;
    *(undefined4 *)(param_3 + 0xa8) = *(undefined4 *)(param_4 + 0x28c);
    *(undefined4 *)(param_3 + 0xdc) = *(undefined4 *)(param_4 + 0x294);
  }
  return;
}


