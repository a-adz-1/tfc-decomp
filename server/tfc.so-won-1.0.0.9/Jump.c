// Jump__11CBasePlayer  @ 000d9700
void Jump__11CBasePlayer(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  if ((*(byte *)(*param_1 + 0x185) & 8) == 0) {
    if (*(int *)(*param_1 + 0x1a0) < 2) {
      if ((((*(byte *)(param_1 + 0x18d) & 2) != 0) &&
          (iVar3 = *param_1, (*(byte *)(iVar3 + 0x185) & 2) != 0)) && (*(int *)(iVar3 + 0x17c) != 0)
         ) {
        UTIL_MakeVectors__FRC6Vector(iVar3 + 0x50);
        *(byte *)(*param_1 + 0x185) = *(byte *)(*param_1 + 0x185) & 0xfd;
        SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,2);
        uVar4 = MapTextureTypeStepType__Fc((int)*(char *)((int)param_1 + 0x7c1),0x3f800000);
        PlayStepSound__11CBasePlayerif(param_1,uVar4);
        if (((((*(byte *)(*param_1 + 0x185) & 0x40) == 0) && ((*(byte *)(param_1 + 0x19a) & 8) == 0)
             ) || ((param_1[0x1fc] == 0 ||
                   ((iVar3 = *param_1, (*(byte *)(iVar3 + 0x160) & 4) == 0 ||
                    (1.0 <= *gpGlobals - (float)param_1[0x19f])))))) ||
           (fVar1 = SQRT(*(float *)(iVar3 + 0x28) * *(float *)(iVar3 + 0x28) +
                         *(float *)(iVar3 + 0x24) * *(float *)(iVar3 + 0x24) +
                         *(float *)(iVar3 + 0x20) * *(float *)(iVar3 + 0x20)),
           (byte)(50.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == 50.0) << 0xe) >> 8)) != 1)) {
          *(undefined4 *)(*param_1 + 0x28) = 0x43862a01;
        }
        else {
          (*DAT_00175628)(0,1);
          *(undefined4 *)(*param_1 + 0x68) = 0xc0a00000;
          iVar3 = *param_1;
          fVar1 = gpGlobals[0xb];
          fVar2 = gpGlobals[0xc];
          *(float *)(iVar3 + 0x20) = gpGlobals[10] * 560.0;
          *(float *)(iVar3 + 0x24) = fVar1 * 560.0;
          *(float *)(iVar3 + 0x28) = fVar2 * 560.0;
          *(undefined4 *)(*param_1 + 0x28) = 0x4395aa92;
          SetAnimation__11CBasePlayer11PLAYER_ANIM(param_1,3);
        }
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(*param_1 + 0x1e8),4,FUN_00139b40,0x3f000000,0x3f4ccccd,0,100);
        iVar3 = *(int *)(*param_1 + 0x17c);
        if (((iVar3 != 0) && (iVar3 != -0xdc)) && ((*(byte *)(iVar3 + 0x260) & 4) != 0)) {
          iVar3 = *param_1;
          *(float *)(iVar3 + 0x20) = *(float *)(iVar3 + 0x20) + *(float *)(iVar3 + 0x2c);
          *(float *)(iVar3 + 0x24) = *(float *)(iVar3 + 0x24) + *(float *)(iVar3 + 0x30);
          *(float *)(iVar3 + 0x28) = *(float *)(iVar3 + 0x28) + *(float *)(iVar3 + 0x34);
        }
      }
    }
    else {
      fVar1 = (float)param_1[0x19e];
      fVar2 = *gpGlobals;
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 1) {
        param_1[0x19e] = (int)(*gpGlobals + 1.0);
        iVar3 = (*DAT_00175628)(0,3);
        if (iVar3 == 1) {
          uVar4 = *(undefined4 *)(*param_1 + 0x1e8);
          pcVar5 = "player/pl_wade2.wav";
        }
        else if (iVar3 < 2) {
          if (iVar3 != 0) {
            return;
          }
          uVar4 = *(undefined4 *)(*param_1 + 0x1e8);
          pcVar5 = "player/pl_wade1.wav";
        }
        else if (iVar3 == 2) {
          uVar4 = *(undefined4 *)(*param_1 + 0x1e8);
          pcVar5 = "player/pl_wade3.wav";
        }
        else {
          if (iVar3 != 3) {
            return;
          }
          uVar4 = *(undefined4 *)(*param_1 + 0x1e8);
          pcVar5 = "player/pl_wade4.wav";
        }
        EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar4,4,pcVar5,0x3f800000,0x3f4ccccd,0,100);
      }
    }
  }
  return;
}


