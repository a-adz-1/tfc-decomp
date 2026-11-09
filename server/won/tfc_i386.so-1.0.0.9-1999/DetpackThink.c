// DetpackThink__8CDetpack  @ 000a7780
void DetpackThink__8CDetpack(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined2 in_FPUControlWord;
  float local_1c;
  float local_18;
  float local_14;
  int local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  fVar1 = *(float *)(*param_1 + 0x140);
  if (((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) &&
     (*(float *)(*param_1 + 0x140) <= *gpGlobals + 0.9)) {
    DetpackExplode__8CDetpack(param_1);
    return;
  }
  CheckBelowBuilding__11CBaseEntity(param_1);
  iVar2 = *(int *)(*param_1 + 0x178);
  if ((iVar2 == 0) && (iVar2 = (*DAT_001755d4)(0), iVar2 == 0)) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    puVar5 = *(undefined4 **)(iVar2 + 0xd8);
  }
  _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
  iVar2 = (int)ROUND(*(float *)(*param_1 + 0x140) - *gpGlobals);
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 1.0;
  if (iVar2 < 0xb) {
    local_10 = iVar2;
    uVar3 = UTIL_dtos1__Fi(iVar2,0,0,0);
    ClientPrint__FP9entvars_tiPCcN42(*puVar5,1,"#Detpack_countdown",uVar3);
    if ((iVar2 < 6) && (param_1[0x189] == 0)) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(*param_1 + 0x1e8),1,"weapons/mine_charge.wav",0x3f800000,0x3f4ccccd
                 ,0,100);
      param_1[0x189] = 1;
      iVar2 = *param_1;
      local_1c = *(float *)(iVar2 + 8) + 0.0;
      local_18 = *(float *)(iVar2 + 0xc) + 0.0;
      local_14 = *(float *)(iVar2 + 0x10) + 64.0;
      piVar4 = (int *)SpriteCreate__7CSpritePCcRC6Vectori("sprites/flare3.spr",&local_1c,0);
      param_1[0x18b] = (int)piVar4;
      *(undefined4 *)(*piVar4 + 0x128) = 3;
      *(undefined4 *)(*piVar4 + 0x130) = 0x437f0000;
      *(undefined4 *)(*piVar4 + 0x134) = 0;
      *(undefined4 *)(*piVar4 + 0x138) = 0;
      *(undefined4 *)(*piVar4 + 300) = 0;
      *(undefined4 *)(*piVar4 + 0x13c) = 0xe;
    }
    else if (iVar2 < 5) {
      if (param_1[0x18a] == 0) {
        param_1[0x18a] = 1;
        *(undefined4 *)(*(int *)param_1[0x18b] + 300) = 0x42800000;
      }
      else if (iVar2 < 5) {
        param_1[0x18a] = 0;
        *(undefined4 *)(*(int *)param_1[0x18b] + 300) = 0;
      }
    }
  }
  return;
}


