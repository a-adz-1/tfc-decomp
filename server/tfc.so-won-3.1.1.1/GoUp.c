// GoUp__12CFuncPlatRot  @ 000cddd0
void GoUp__12CFuncPlatRot(int *param_1)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  iVar1 = *(int *)(*param_1 + 0x1e8);
  if (iVar1 != 0) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),6,iVar1 + *(int *)(gpGlobals + 0x98),param_1[0x13f]
               ,0x3f4ccccd,0,100);
  }
  param_1[0x11d] = 2;
  param_1[0x134] = -0x10000;
  param_1[0x135] = (int)CallHitTop__9CFuncPlat;
  local_10 = param_1[0x124];
  local_c = param_1[0x125];
  local_8 = param_1[0x126];
  LinearMove__11CBaseToggleG6Vectorf(param_1,&local_10,*(undefined4 *)(*param_1 + 0x1f8));
  RotMove__12CFuncPlatRotR6Vectorf
            (param_1,param_1 + 0x140,*(float *)(*param_1 + 0x104) - *(float *)(*param_1 + 0x100));
  return;
}


// GoUp__16CFuncTrackChange  @ 000d0e9c
void GoUp__16CFuncTrackChange(int *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_1[0x14c] != 1) {
    (**(code **)(param_1[0x115] + 0x120))(param_1,2);
    iVar1 = *param_1;
    if ((*(byte *)(iVar1 + 0x1a0) & 0x10) == 0) {
      if (*(int *)(iVar1 + 0x1e8) != 0) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(iVar1 + 0x208),6,
                   *(int *)(iVar1 + 0x1e8) + *(int *)(gpGlobals + 0x98),param_1[0x13f],0x3f4ccccd,0,
                   100);
      }
      param_1[0x11d] = 2;
      param_1[0x134] = -0x10000;
      param_1[0x135] = (int)CallHitTop__9CFuncPlat;
      local_10 = param_1[0x124];
      local_c = param_1[0x125];
      local_8 = param_1[0x126];
      LinearMove__11CBaseToggleG6Vectorf(param_1,&local_10,*(undefined4 *)(*param_1 + 0x1f8));
      iVar1 = *param_1;
      param_1[0x134] = -0x10000;
      param_1[0x135] = (int)CallHitTop__9CFuncPlat;
      fVar2 = *(float *)(iVar1 + 0x104) - *(float *)(iVar1 + 0x100);
      fVar5 = (float)param_1[0x140] - *(float *)(iVar1 + 0x50);
      fVar4 = (float)param_1[0x141] - *(float *)(iVar1 + 0x54);
      fVar3 = (float)param_1[0x142] - *(float *)(iVar1 + 0x58);
      if ((byte)(fVar2 < 0.1 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == 0.1) << 0xe) >> 8)) == 1) {
        *(float *)(iVar1 + 0x5c) = fVar5;
        *(float *)(iVar1 + 0x60) = fVar4;
        *(float *)(iVar1 + 100) = fVar3;
        *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + 1.0;
      }
      else {
        *(float *)(iVar1 + 0x5c) = fVar5 / fVar2;
        *(float *)(iVar1 + 0x60) = fVar4 / fVar2;
        *(float *)(iVar1 + 100) = fVar3 / fVar2;
      }
    }
    else {
      param_1[0x11d] = 2;
      param_1[0x134] = -0x10000;
      param_1[0x135] = (int)CallHitTop__9CFuncPlat;
      local_10 = param_1[0x140];
      local_c = param_1[0x141];
      local_8 = param_1[0x142];
      AngularMove__11CBaseToggleG6Vectorf(param_1,&local_10,*(undefined4 *)(iVar1 + 0x1f8));
    }
    if (param_1[0x14c] == 2) {
      UpdateTrain__16CFuncTrackChangeR6Vector(param_1,param_1 + 0x140);
      *(undefined4 *)(param_1[0x148] + 0x458) = 0;
    }
  }
  return;
}


// GoUp__9CFuncPlat  @ 000d2a64
void GoUp__9CFuncPlat(int *param_1)

{
  int iVar1;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  iVar1 = *(int *)(*param_1 + 0x1e8);
  if (iVar1 != 0) {
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*param_1 + 0x208),6,iVar1 + *(int *)(gpGlobals + 0x98),param_1[0x13f]
               ,0x3f4ccccd,0,100);
  }
  param_1[0x11d] = 2;
  param_1[0x134] = -0x10000;
  param_1[0x135] = (int)CallHitTop__9CFuncPlat;
  iStack_10 = param_1[0x124];
  iStack_c = param_1[0x125];
  iStack_8 = param_1[0x126];
  LinearMove__11CBaseToggleG6Vectorf(param_1,&iStack_10,*(undefined4 *)(*param_1 + 0x1f8));
  return;
}


