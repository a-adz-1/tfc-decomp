// RocketTouch__12CTFRpgRocketP11CBaseEntity  @ 00101540
void RocketTouch__12CTFRpgRocketP11CBaseEntity(int *param_1,undefined4 param_2)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)(*DAT_0017562c)(0,0x41a00000);
  *(float *)(*param_1 + 0x1c0) = (float)((longdouble)92.0 + lVar1);
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x1e8),2,"weapons/rocket1.wav",0,0,0x20,100);
  ExplodeTouch__8CGrenadeP11CBaseEntity(param_1,param_2);
  return;
}


// RocketTouch__20CTFIncendiaryCRocketP11CBaseEntity  @ 000ff470
void RocketTouch__20CTFIncendiaryCRocketP11CBaseEntity(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  
  lVar3 = (longdouble)(*DAT_0017562c)(0,0x41a00000);
  *(float *)(*param_1 + 0x1c0) = (float)((longdouble)10.0 + lVar3);
  iVar2 = *param_1;
  param_1[0x186] = (int)(*(float *)(iVar2 + 0x1c0) * 0.5);
  param_1[0x187] = (int)(*(float *)(iVar2 + 0x1c0) + 30.0);
  param_1[0x184] = 1;
  if ((*(int *)(iVar2 + 0x178) == 0) || (*(int *)(iVar2 + 0x178) == 0)) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(iVar2 + 0x178) + 0xdc;
  }
  if ((param_2 != (int *)0x0) &&
     (fVar1 = *(float *)(*param_2 + 0x14c),
     (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
           (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40)) {
    (**(code **)(param_2[0xf2] + 0x34))
              (param_2,*param_1,iVar2,*(undefined4 *)(*param_1 + 0x1c0),0x1000040);
  }
  EMIT_SOUND_DYN__FP7edict_siPCcffii
            (*(undefined4 *)(*param_1 + 0x1e8),2,"weapons/rocket1.wav",0,0,0x20,100);
  ExplodeTouch__8CGrenadeP11CBaseEntity(param_1,param_2);
  return;
}


