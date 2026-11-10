// TraceAttack__10CBreakableP9entvars_sfG6VectorP11TraceResulti  @ 0009e240
void TraceAttack__10CBreakableP9entvars_sfG6VectorP11TraceResulti
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,int param_5,
               undefined4 param_6)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  longdouble lVar4;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = (*DAT_001a7fa8)(0,1);
  if (iVar1 != 0) {
    if (param_1[0xf8] == 6) {
      UTIL_Sparks__FRC6Vector(param_5 + 0x14);
      lVar4 = (longdouble)(*DAT_001a7fac)(0x3f333333,0x3f800000);
      iVar1 = (*DAT_001a7fa8)(0,1);
      if (iVar1 == 0) {
        uVar3 = *(undefined4 *)(*param_1 + 0x208);
        pcVar2 = "buttons/spark5.wav";
      }
      else {
        if (iVar1 != 1) goto LAB_0009e346;
        uVar3 = *(undefined4 *)(*param_1 + 0x208);
        pcVar2 = "buttons/spark6.wav";
      }
      EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar3,2,pcVar2,(float)lVar4,0x3f4ccccd,0,100);
    }
    else if (param_1[0xf8] == 7) {
      lVar4 = (longdouble)(*DAT_001a7fac)(0x3f000000,0x3fc00000);
      UTIL_Ricochet__FRC6Vectorf(param_5 + 0x14,(float)lVar4);
    }
  }
LAB_0009e346:
  local_c = *param_4;
  local_8 = param_4[1];
  local_4 = param_4[2];
  TraceAttack__11CBaseEntityP9entvars_sfG6VectorP11TraceResulti
            (param_1,param_2,param_3,&local_c,param_5,param_6);
  return;
}


// TraceAttack__11CBaseEntityP9entvars_sfG6VectorP11TraceResulti  @ 000b458c
void TraceAttack__11CBaseEntityP9entvars_sfG6VectorP11TraceResulti
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  float fVar1;
  
  fVar1 = *(float *)(*param_1 + 0x16c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    AddMultiDamage__FP9entvars_sP11CBaseEntityfi(param_2,param_1,param_3,param_6);
    (**(code **)(param_1[0xf5] + 0x40))(param_1);
  }
  return;
}


// TraceAttack__11CBasePlayerP9entvars_sfG6VectorP11TraceResulti  @ 000c8558
void TraceAttack__11CBasePlayerP9entvars_sfG6VectorP11TraceResulti(void)

{
  FUN_000c8564();
  return;
}


// TraceAttack__11CBaseTurretP9entvars_sfG6VectorP11TraceResulti  @ 00108c60
void TraceAttack__11CBaseTurretP9entvars_sfG6VectorP11TraceResulti
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
               undefined4 param_6)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  
  if (*(int *)(param_5 + 0x34) == 10) {
    if (((byte)((byte)((ushort)((ushort)(NAN(*gpGlobals) || NAN(*(float *)(*param_1 + 0x1e4))) << 10
                               ) >> 8) |
               (byte)((ushort)((ushort)(*gpGlobals == *(float *)(*param_1 + 0x1e4)) << 0xe) >> 8))
         != 0x40) || (iVar2 = (*DAT_001a7fa8)(0,10), iVar2 < 1)) {
      lVar3 = (longdouble)(*DAT_001a7fac)(0x3f800000,0x40000000);
      UTIL_Ricochet__FRC6Vectorf(param_5 + 0x14,(float)lVar3);
      *(float *)(*param_1 + 0x1e4) = *gpGlobals;
    }
    param_3 = 0x3dcccccd;
  }
  fVar1 = *(float *)(*param_1 + 0x16c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    AddMultiDamage__FP9entvars_sP11CBaseEntityfi(param_2,param_1,param_3,param_6);
  }
  return;
}


// TraceAttack__12CBaseMonsterP9entvars_sfG6VectorP11TraceResulti  @ 000b7134
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TraceAttack__12CBaseMonsterP9entvars_sfG6VectorP11TraceResulti
               (int *param_1,undefined4 param_2,float param_3,undefined4 *param_4,int param_5,
               undefined4 param_6)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  fVar1 = *(float *)(*param_1 + 0x16c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_1[0x13c] = *(int *)(param_5 + 0x34);
    switch(*(undefined4 *)(param_5 + 0x34)) {
    case 1:
      param_3 = param_3 * DAT_001aa4ac;
      break;
    case 2:
      param_3 = param_3 * DAT_001aa4b0;
      break;
    case 3:
      param_3 = param_3 * DAT_001aa4b4;
      break;
    case 4:
    case 5:
      param_3 = param_3 * DAT_001aa4bc;
      break;
    case 6:
    case 7:
      param_3 = param_3 * _DAT_001aa4b8;
    }
    uStack_c = *(undefined4 *)(param_5 + 0x14);
    uStack_8 = *(undefined4 *)(param_5 + 0x18);
    uStack_4 = *(undefined4 *)(param_5 + 0x1c);
    uVar2 = (**(code **)(param_1[0xf5] + 0x40))(param_1,param_3);
    SpawnBlood__FG6Vectorif(&uStack_c,uVar2);
    uStack_c = *param_4;
    uStack_8 = param_4[1];
    uStack_4 = param_4[2];
    (**(code **)(param_1[0xf5] + 0x44))(param_1,param_3,&uStack_c,param_5,param_6);
    AddMultiDamage__FP9entvars_sP11CBaseEntityfi(param_2,param_1,param_3,param_6);
  }
  return;
}


