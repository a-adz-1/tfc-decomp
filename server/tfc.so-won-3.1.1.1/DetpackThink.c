// DetpackThink__8CDetpack  @ 00099d40
void DetpackThink__8CDetpack(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined2 in_FPUControlWord;
  undefined4 *local_2c;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  float fStack_14;
  int local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  fVar1 = *(float *)(*param_1 + 0x160);
  if (((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) ||
     (fVar2 = *gpGlobals + 0.9,
     (byte)(fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8)) == 1)) {
    CheckBelowBuilding__11CBaseEntityi(param_1,8);
    iVar3 = *(int *)(*param_1 + 0x198);
    if ((iVar3 == 0) && (iVar3 = (*DAT_0019f7b4)(0), iVar3 == 0)) {
      local_2c = (undefined4 *)0x0;
    }
    else {
      local_2c = *(undefined4 **)(iVar3 + 0x7c);
    }
    _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
    iVar3 = (int)ROUND(*(float *)(*param_1 + 0x160) - *gpGlobals);
    *(float *)(*param_1 + 0x104) = *gpGlobals + 1.0;
    if (iVar3 < 0xb) {
      local_10 = iVar3;
      uVar4 = UTIL_dtos1__Fi(iVar3,0,0,0);
      ClientPrint__FP9entvars_siPCcN42(*local_2c,1,"#Detpack_countdown",uVar4);
      if ((iVar3 < 6) && (param_1[0x1ae] == 0)) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_1 + 0x208),1,"weapons/mine_charge.wav",0x3f800000,
                   0x3f4ccccd,0,100);
        param_1[0x1ae] = 1;
        iVar3 = *param_1;
        fStack_14 = *(float *)(iVar3 + 0x10) + 64.0;
        uStack_1c = *(undefined4 *)(iVar3 + 8);
        uStack_18 = *(undefined4 *)(iVar3 + 0xc);
        piVar5 = (int *)SpriteCreate__7CSpritePCcRC6Vectori("sprites/flare3.spr",&uStack_1c,0);
        param_1[0x1b0] = (int)piVar5;
        *(undefined4 *)(*piVar5 + 0x148) = 3;
        *(undefined4 *)(*piVar5 + 0x150) = 0x437f0000;
        *(undefined4 *)(*piVar5 + 0x154) = 0;
        *(undefined4 *)(*piVar5 + 0x158) = 0;
        *(undefined4 *)(*piVar5 + 0x14c) = 0;
        *(undefined4 *)(*piVar5 + 0x15c) = 0xe;
      }
      else if (iVar3 < 5) {
        if (param_1[0x1af] == 0) {
          param_1[0x1af] = 1;
          *(undefined4 *)(*(int *)param_1[0x1b0] + 0x14c) = 0x42800000;
        }
        else {
          param_1[0x1af] = 0;
          *(undefined4 *)(*(int *)param_1[0x1b0] + 0x14c) = 0;
        }
      }
    }
  }
  else {
    DetpackExplode__8CDetpack(param_1);
  }
  return;
}


