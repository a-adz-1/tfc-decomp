// Wait__10CFuncTrain  @ 000c3530
void Wait__10CFuncTrain(int *param_1)

{
  float fVar1;
  int iVar2;
  
  if (*(int *)(param_1[0x120] + 0x1d4) != 0) {
    FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
              (*(int *)(param_1[0x120] + 0x1d4) + *(int *)(gpGlobals + 0x98),param_1,param_1,3,0);
    if ((*(byte *)(param_1[0x120] + 0x1a0) & 4) != 0) {
      *(undefined4 *)(param_1[0x120] + 0x1d4) = 0;
    }
  }
  if (((*(byte *)(param_1[0x120] + 0x1a0) & 1) == 0) && ((*(byte *)(*param_1 + 0x1a0) & 1) == 0)) {
    fVar1 = (float)param_1[0x100];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      Next__10CFuncTrain(param_1);
    }
    else {
      *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + (float)param_1[0x100];
      iVar2 = *param_1;
      if (*(int *)(iVar2 + 0x1e8) != 0) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(iVar2 + 0x208),6,
                   *(int *)(iVar2 + 0x1e8) + *(int *)(gpGlobals + 0x98),0,0,0x20,100);
      }
      iVar2 = *param_1;
      if (*(int *)(iVar2 + 0x1ec) != 0) {
        EMIT_SOUND_DYN__FP7edict_siPCcffii
                  (*(undefined4 *)(iVar2 + 0x208),2,
                   *(int *)(iVar2 + 0x1ec) + *(int *)(gpGlobals + 0x98),param_1[0x11f],0x3f4ccccd,0,
                   100);
      }
      param_1[3] = -0x10000;
      param_1[4] = (int)Next__10CFuncTrain;
    }
  }
  else {
    *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) | 1;
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 0x1e8) != 0) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(iVar2 + 0x208),6,
                 *(int *)(iVar2 + 0x1e8) + *(int *)(gpGlobals + 0x98),0,0,0x20,100);
    }
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 0x1ec) != 0) {
      EMIT_SOUND_DYN__FP7edict_siPCcffii
                (*(undefined4 *)(iVar2 + 0x208),2,
                 *(int *)(iVar2 + 0x1ec) + *(int *)(gpGlobals + 0x98),param_1[0x11f],0x3f4ccccd,0,
                 100);
    }
    *(undefined4 *)(*param_1 + 0x104) = 0;
  }
  return;
}


// Wait__10CGunTarget  @ 000c7270
void Wait__10CGunTarget(int *param_1)

{
  float fVar1;
  int *piVar2;
  longdouble lVar3;
  
  piVar2 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x121);
  if (piVar2 == (int *)0x0) {
    (**(code **)(param_1[0xf5] + 0x14c))(param_1);
  }
  else {
    if (*(int *)(*piVar2 + 0x1d4) != 0) {
      FireTargets__FPCcP11CBaseEntityT18USE_TYPEf
                (*(int *)(*piVar2 + 0x1d4) + *(int *)(gpGlobals + 0x98),param_1,param_1,3,0);
      if ((*(byte *)(*piVar2 + 0x1a0) & 4) != 0) {
        *(undefined4 *)(*piVar2 + 0x1d4) = 0;
      }
    }
    lVar3 = (longdouble)(**(code **)(piVar2[0xf5] + 100))(piVar2);
    param_1[0x100] = (int)(float)lVar3;
    *(undefined4 *)(*param_1 + 0x1c8) = *(undefined4 *)(*piVar2 + 0x1c8);
    param_1[3] = -0x10000;
    param_1[4] = (int)Next__10CGunTarget;
    fVar1 = (float)param_1[0x100];
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
      Next__10CGunTarget(param_1);
    }
    else {
      *(float *)(*param_1 + 0x104) = *(float *)(*param_1 + 0x100) + fVar1;
    }
  }
  return;
}


