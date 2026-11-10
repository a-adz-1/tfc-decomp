// AddToFullPack__FP14entity_state_siP7edict_sT2iiPUc  @ 0008aac4
undefined4
AddToFullPack__FP14entity_state_siP7edict_sT2iiPUc
          (undefined4 *param_1,undefined4 param_2,int param_3,int param_4,uint param_5,int param_6,
          undefined4 param_7)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((((*(int *)(param_3 + 0x198) != 0x80) || (param_3 == param_4)) &&
      (*(int *)(param_3 + 0x134) != 0)) &&
     (*(int *)(gpGlobals + 0x98) != -*(int *)(param_3 + 0x138))) {
    if ((*(byte *)(param_3 + 0x227) & 4) == 0) {
      if ((param_3 != param_4) && (iVar3 = (*DAT_001a8038)(param_3,param_7), iVar3 == 0)) {
        return 0;
      }
    }
    else if (param_3 != param_4) {
      return 0;
    }
    if ((((*(byte *)(param_3 + 0x225) & 1) == 0) || ((param_5 & 1) == 0)) ||
       (*(int *)(param_3 + 0x218) != param_4)) {
      if (*(int *)(param_4 + 0x2c0) != 0) {
        UTIL_SetGroupTrace__Fii(*(undefined4 *)(param_4 + 0x2c0),0);
        if (*(int *)(param_3 + 0x2c0) != 0) {
          if (g_groupop == 0) {
            if ((*(uint *)(param_3 + 0x2c0) & *(uint *)(param_4 + 0x2c0)) == 0) {
              return 0;
            }
          }
          else if ((g_groupop == 1) &&
                  ((*(uint *)(param_3 + 0x2c0) & *(uint *)(param_4 + 0x2c0)) != 0)) {
            return 0;
          }
        }
        UTIL_UnsetGroupTrace__Fv();
      }
      memset(param_1,0,0x154);
      param_1[1] = param_2;
      *param_1 = 1;
      if ((*(byte *)(param_3 + 0x227) & 0x20) != 0) {
        *param_1 = 2;
      }
      param_1[0x17] = (float)(int)ROUND(*(float *)(param_3 + 0x1b4) * 1000.0) * 0.001;
      param_1[4] = *(undefined4 *)(param_3 + 0x88);
      param_1[5] = *(undefined4 *)(param_3 + 0x8c);
      param_1[6] = *(undefined4 *)(param_3 + 0x90);
      param_1[7] = *(undefined4 *)(param_3 + 0xd0);
      param_1[8] = *(undefined4 *)(param_3 + 0xd4);
      param_1[9] = *(undefined4 *)(param_3 + 0xd8);
      param_1[0x1f] = *(undefined4 *)(param_3 + 0x15c);
      param_1[0x20] = *(undefined4 *)(param_3 + 0x160);
      param_1[0x21] = *(undefined4 *)(param_3 + 0x164);
      param_1[0x22] = *(undefined4 *)(param_3 + 0x168);
      param_1[0x23] = *(undefined4 *)(param_3 + 0x16c);
      param_1[0x24] = *(undefined4 *)(param_3 + 0x170);
      param_1[0x39] = *(undefined4 *)(param_3 + 0x10c);
      param_1[0x3a] = *(undefined4 *)(param_3 + 0x110);
      param_1[0x3b] = *(undefined4 *)(param_3 + 0x114);
      param_1[0x3c] = *(undefined4 *)(param_3 + 0x100);
      param_1[0x3d] = *(undefined4 *)(param_3 + 0x104);
      param_1[0x3e] = *(undefined4 *)(param_3 + 0x108);
      param_1[0x3f] = *(undefined4 *)(param_3 + 0x118);
      param_1[0x40] = *(undefined4 *)(param_3 + 0x11c);
      param_1[10] = *(undefined4 *)(param_3 + 0x134);
      param_1[0xc] = *(undefined4 *)(param_3 + 0x1b0);
      *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(param_3 + 400);
      param_1[0xf] = *(undefined4 *)(param_3 + 0x198);
      if ((((param_6 == 0) &&
           (fVar1 = *(float *)(param_3 + 0x1b4),
           (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) &&
          ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_3 + 0xa0)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(*(float *)(param_3 + 0xa0) == 0.0) << 0xe) >> 8)) == 0x40)
          ) && (((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_3 + 0xa4)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(*(float *)(param_3 + 0xa4) == 0.0) << 0xe) >> 8)) ==
                 0x40 && ((byte)((byte)((ushort)((ushort)NAN(*(float *)(param_3 + 0xa8)) << 10) >> 8
                                       ) |
                                (byte)((ushort)((ushort)(*(float *)(param_3 + 0xa8) == 0.0) << 0xe)
                                      >> 8)) == 0x40)))) {
        *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 1;
      }
      param_1[0x10] = *(undefined4 *)(param_3 + 0x1c4);
      *(undefined2 *)((int)param_1 + 0x3a) = *(undefined2 *)(param_3 + 0x18c);
      param_1[0xd] = *(undefined4 *)(param_3 + 0x228);
      param_1[0x16] = *(undefined4 *)(param_3 + 0x188);
      param_1[0xb] = *(undefined4 *)(param_3 + 0x1a8);
      param_1[0x18] = *(undefined4 *)(param_3 + 0x1b8);
      param_1[0x19] = *(undefined4 *)(param_3 + 0x194);
      *(undefined1 *)(param_1 + 0x1a) = *(undefined1 *)(param_3 + 0x1bc);
      *(undefined1 *)((int)param_1 + 0x69) = *(undefined1 *)(param_3 + 0x1bd);
      *(undefined1 *)((int)param_1 + 0x6a) = *(undefined1 *)(param_3 + 0x1be);
      *(undefined1 *)((int)param_1 + 0x6b) = *(undefined1 *)(param_3 + 0x1bf);
      *(undefined1 *)(param_1 + 0x1b) = *(undefined1 *)(param_3 + 0x1c0);
      *(undefined1 *)((int)param_1 + 0x6d) = *(undefined1 *)(param_3 + 0x1c1);
      param_1[0x12] = *(undefined4 *)(param_3 + 0x1c8);
      param_1[0x13] = (int)ROUND(*(float *)(param_3 + 0x1cc));
      param_1[0x15] = *(undefined4 *)(param_3 + 0x1dc);
      *(char *)(param_1 + 0x14) = (char)(longlong)ROUND(*(float *)(param_3 + 0x1d0));
      *(char *)((int)param_1 + 0x51) = (char)(longlong)ROUND(*(float *)(param_3 + 0x1d4));
      *(char *)((int)param_1 + 0x52) = (char)(longlong)ROUND(*(float *)(param_3 + 0x1d8));
      param_1[0x25] = 0;
      if (*(int *)(param_3 + 0x214) != 0) {
        uVar2 = (*DAT_001a7f5c)(*(undefined4 *)(param_3 + 0x214));
        param_1[0x25] = uVar2;
      }
      param_1[0x26] = 0;
      if (((*(int *)(param_3 + 0x218) != 0) &&
          (iVar3 = (*DAT_001a7f5c)(*(undefined4 *)(param_3 + 0x218)), 0 < iVar3)) &&
         (iVar3 <= *(int *)(gpGlobals + 0x90))) {
        param_1[0x26] = iVar3;
      }
      if (param_6 != 0) {
        param_1[0x2f] = *(undefined4 *)(param_3 + 0xac);
        param_1[0x30] = *(undefined4 *)(param_3 + 0xb0);
        param_1[0x31] = *(undefined4 *)(param_3 + 0xb4);
        uVar2 = (*DAT_001a7e4c)(*(int *)(param_3 + 0x140) + *(int *)(gpGlobals + 0x98));
        param_1[0x2d] = uVar2;
        param_1[0x2e] = *(undefined4 *)(param_3 + 0x1ac);
        param_1[0x2c] = *(uint *)(param_3 + 0x224) & 0x4000000;
        param_1[0x27] = *(undefined4 *)(param_3 + 0x1a0);
        param_1[0x28] = *(undefined4 *)(param_3 + 0x19c);
        param_1[0x29] = *(undefined4 *)(param_3 + 0x22c);
        param_1[0x2a] = *(undefined4 *)(param_3 + 0x28c);
        param_1[0x32] = *(uint *)(param_3 + 0x224) >> 0xe & 1;
        param_1[0x2b] = (int)ROUND(*(float *)(param_3 + 0x1e0));
      }
      return 1;
    }
  }
  return 0;
}


