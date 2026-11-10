// RocketTouch__12CTFRpgRocketP11CBaseEntity  @ 00101538
void RocketTouch__12CTFRpgRocketP11CBaseEntity(int *param_1,undefined4 param_2)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)(*DAT_001c118c)(0,0x41a00000);
  *(float *)(*param_1 + 0x1e0) = (float)((longdouble)92.0 + lVar1);
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x208),2,"weapons/rocket1.wav",0,0,0x20,100);
  ExplodeTouch__8CGrenadeP11CBaseEntity(param_1,param_2);
  return;
}


// RocketTouch__20CTFIncendiaryCRocketP11CBaseEntity  @ 00100ffc
void RocketTouch__20CTFIncendiaryCRocketP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  
  lVar4 = (longdouble)(*DAT_001c118c)(0,0x41a00000);
  *(float *)(*param_1 + 0x1e0) = (float)((longdouble)10.0 + lVar4);
  iVar2 = *param_1;
  param_1[0x1a6] = (int)(*(float *)(iVar2 + 0x1e0) * 0.5);
  param_1[0x1a7] = (int)(*(float *)(iVar2 + 0x1e0) + 30.0);
  param_1[0x1a4] = 1;
  if ((*(int *)(iVar2 + 0x198) == 0) ||
     (iVar3 = *(int *)(iVar2 + 0x198) + 0x80, *(int *)(iVar2 + 0x198) == 0)) {
    iVar3 = 0;
  }
  if (param_2 != (int *)0x0) {
    fVar1 = *(float *)(*param_2 + 0x16c);
    if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
      (**(code **)(param_2[0x111] + 0x38))
                (param_2,*param_1,iVar3,*(undefined4 *)(*param_1 + 0x1e0),0x1000040);
    }
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x208),2,"weapons/rocket1.wav",0,0,0x20,100);
  ExplodeTouch__8CGrenadeP11CBaseEntity(param_1,param_2);
  return;
}


