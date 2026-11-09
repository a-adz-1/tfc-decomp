// TraceAttack__10CBreakableP9entvars_tfG6VectorP11TraceResulti  @ 000b2990
void TraceAttack__10CBreakableP9entvars_tfG6VectorP11TraceResulti
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,int param_5,
               undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  char *pcVar4;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = (*DAT_00175628)(0,1);
  if (iVar1 != 0) {
    if (param_1[0xf5] == 6) {
      UTIL_Sparks__FRC6Vector(param_5 + 0x14);
      lVar3 = (longdouble)(*DAT_0017562c)(0x3f333333,0x3f800000);
      iVar1 = (*DAT_00175628)(0,1);
      if (iVar1 == 0) {
        uVar2 = *(undefined4 *)(*param_1 + 0x1e8);
        pcVar4 = "buttons/spark5.wav";
      }
      else {
        if (iVar1 != 1) goto LAB_000b2a93;
        uVar2 = *(undefined4 *)(*param_1 + 0x1e8);
        pcVar4 = "buttons/spark6.wav";
      }
      EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar2,2,pcVar4,(float)lVar3,0x3f4ccccd,0,100);
    }
    else if (param_1[0xf5] == 7) {
      lVar3 = (longdouble)(*DAT_0017562c)(0x3f000000,0x3fc00000);
      UTIL_Ricochet__FRC6Vectorf(param_5 + 0x14,(float)lVar3);
    }
  }
LAB_000b2a93:
  local_10 = *param_4;
  local_c = param_4[1];
  local_8 = param_4[2];
  TraceAttack__11CBaseEntityP9entvars_tfG6VectorP11TraceResulti
            (param_1,param_2,param_3,&local_10,param_5,param_6);
  return;
}


// TraceAttack__11CBaseEntityP9entvars_tfG6VectorP11TraceResulti  @ 000c5e40
void TraceAttack__11CBaseEntityP9entvars_tfG6VectorP11TraceResulti
               (int *param_1,undefined4 param_2,undefined4 param_3,float *param_4,int param_5,
               undefined4 param_6)

{
  float fVar1;
  int iVar2;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_1c = *param_4 * 4.0;
  local_18 = param_4[1] * 4.0;
  local_14 = param_4[2] * 4.0;
  local_10 = *(float *)(param_5 + 0x14) - local_1c;
  local_c = *(float *)(param_5 + 0x18) - local_18;
  local_8 = *(float *)(param_5 + 0x1c) - local_14;
  fVar1 = *(float *)(*param_1 + 0x14c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    AddMultiDamage__FP9entvars_tP11CBaseEntityfi(param_2,param_1,param_3,param_6);
    iVar2 = (**(code **)(param_1[0xf2] + 0x40))(param_1);
    if (iVar2 != -1) {
      local_1c = local_10;
      local_18 = local_c;
      local_14 = local_8;
      SpawnBlood__FG6Vectorif(&local_1c,iVar2,param_3);
      local_1c = *param_4;
      local_18 = param_4[1];
      local_14 = param_4[2];
      (**(code **)(param_1[0xf2] + 0x44))(param_1,param_3,&local_1c,param_5,param_6);
    }
  }
  return;
}


// TraceAttack__11CBasePlayerP9entvars_tfG6VectorP11TraceResulti  @ 000d6a50
void TraceAttack__11CBasePlayerP9entvars_tfG6VectorP11TraceResulti
               (int *param_1,int param_2,float param_3,undefined4 *param_4,int param_5,uint param_6)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  undefined2 in_FPUControlWord;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined2 uStack_8;
  undefined2 uStack_6;
  
  fVar1 = *(float *)(*param_1 + 0x14c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    return;
  }
  param_1[0x139] = *(int *)(param_5 + 0x34);
  iVar2 = *(int *)(param_2 + 0x1e8);
  if ((iVar2 == 0) && (iVar2 = (*DAT_001755d4)(0), iVar2 == 0)) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(iVar2 + 0xd8);
  }
  if ((param_6 & 0x10000000) == 0) goto switchD_000d6ad2_caseD_0;
  switch(*(undefined4 *)(param_5 + 0x34)) {
  case 1:
    param_3 = param_3 + param_3;
    ClientPrint__FP9entvars_tiPCcN42(*piVar4,1,"#Sniper_headshot",0,0,0,0);
    piVar4[0xdb] = (int)"headshot" - *(int *)(gpGlobals + 0x98);
    break;
  case 6:
  case 7:
    iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar4);
    if ((iVar2 == 0) || (param_1 == piVar4)) {
LAB_000d6b54:
      param_3 = param_3 * 0.5;
      param_1[0x68] = (int)((float)param_1[0x68] + 1.0);
      TeamFortress_SetSpeed__11CBasePlayer(param_1);
      ClientPrint__FP9entvars_tiPCcN42(*param_1,1,"#Sniper_leginjury",0,0,0,0);
    }
    else {
      _uStack_8 = CONCAT22(uStack_6,in_FPUControlWord);
      uStack_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      if (((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x1eU) == 0) goto LAB_000d6b54;
    }
    ClientPrint__FP9entvars_tiPCcN42(*piVar4,1,"#Sniper_legshot",0,0,0,0);
  }
switchD_000d6ad2_caseD_0:
  uVar5 = 0;
  iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar4);
  if ((iVar2 != 0) && (param_1 != piVar4)) {
    if ((param_6 & 0x40) == 0) {
      _uStack_8 = CONCAT22(uStack_6,in_FPUControlWord);
      uStack_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      if (((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 4U) != 0) {
        uVar5 = 1;
      }
    }
    else {
      _uStack_8 = CONCAT22(uStack_6,in_FPUControlWord);
      uStack_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      uVar5 = (uint)(int)ROUND(*(float *)(gpGlobals + 0x1c)) >> 4 & 1;
    }
  }
  if (uVar5 == 0) {
    uStack_1c = *(undefined4 *)(param_5 + 0x14);
    uStack_18 = *(undefined4 *)(param_5 + 0x18);
    uStack_14 = *(undefined4 *)(param_5 + 0x1c);
    uVar3 = (**(code **)(param_1[0xf2] + 0x40))(param_1,param_3);
    SpawnBlood__FG6Vectorif(&uStack_1c,uVar3);
    uStack_1c = *param_4;
    uStack_18 = param_4[1];
    uStack_14 = param_4[2];
    (**(code **)(param_1[0xf2] + 0x44))(param_1,param_3,&uStack_1c,param_5,param_6);
  }
  AddMultiDamage__FP9entvars_tP11CBaseEntityfi(param_2,param_1,param_3,param_6);
  return;
}


// TraceAttack__11CBaseTurretP9entvars_tfG6VectorP11TraceResulti  @ 00115970
void TraceAttack__11CBaseTurretP9entvars_tfG6VectorP11TraceResulti
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
               undefined4 param_6)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  
  if (*(int *)(param_5 + 0x34) == 10) {
    if (((byte)((byte)((ushort)((ushort)(NAN(*gpGlobals) || NAN(*(float *)(*param_1 + 0x1c4))) << 10
                               ) >> 8) |
               (byte)((ushort)((ushort)(*gpGlobals == *(float *)(*param_1 + 0x1c4)) << 0xe) >> 8))
         != 0x40) || (iVar2 = (*DAT_00175628)(0,10), iVar2 < 1)) {
      lVar3 = (longdouble)(*DAT_0017562c)(0x3f800000,0x40000000);
      UTIL_Ricochet__FRC6Vectorf(param_5 + 0x14,(float)lVar3);
      *(float *)(*param_1 + 0x1c4) = *gpGlobals;
    }
    param_3 = 0x3dcccccd;
  }
  fVar1 = *(float *)(*param_1 + 0x14c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    AddMultiDamage__FP9entvars_tP11CBaseEntityfi(param_2,param_1,param_3,param_6);
  }
  return;
}


// TraceAttack__12CBaseMonsterP9entvars_tfG6VectorP11TraceResulti  @ 000c82d0
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TraceAttack__12CBaseMonsterP9entvars_tfG6VectorP11TraceResulti
               (int *param_1,undefined4 param_2,float param_3,undefined4 *param_4,int param_5,
               undefined4 param_6)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  fVar1 = *(float *)(*param_1 + 0x14c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_1[0x139] = *(int *)(param_5 + 0x34);
    switch(*(undefined4 *)(param_5 + 0x34)) {
    case 1:
      param_3 = param_3 * _DAT_00177acc;
      break;
    case 2:
      param_3 = param_3 * _DAT_00177ad0;
      break;
    case 3:
      param_3 = param_3 * _DAT_00177ad4;
      break;
    case 4:
    case 5:
      param_3 = param_3 * _DAT_00177adc;
      break;
    case 6:
    case 7:
      param_3 = param_3 * _DAT_00177ad8;
    }
    uStack_10 = *(undefined4 *)(param_5 + 0x14);
    uStack_c = *(undefined4 *)(param_5 + 0x18);
    uStack_8 = *(undefined4 *)(param_5 + 0x1c);
    uVar2 = (**(code **)(param_1[0xf2] + 0x40))(param_1,param_3);
    SpawnBlood__FG6Vectorif(&uStack_10,uVar2);
    uStack_10 = *param_4;
    uStack_c = param_4[1];
    uStack_8 = param_4[2];
    (**(code **)(param_1[0xf2] + 0x44))(param_1,param_3,&uStack_10,param_5,param_6);
    AddMultiDamage__FP9entvars_tP11CBaseEntityfi(param_2,param_1,param_3,param_6);
  }
  return;
}


