// TraceAttack__10CBreakableP9entvars_sfG6VectorP11TraceResulti  @ 000a8c18
void TraceAttack__10CBreakableP9entvars_sfG6VectorP11TraceResulti
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,int param_5,
               undefined4 param_6)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  longdouble lVar4;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = (*DAT_001c1188)(0,1);
  if (iVar1 != 0) {
    if (param_1[0x114] == 6) {
      UTIL_Sparks__FRC6Vector(param_5 + 0x14);
      lVar4 = (longdouble)(*DAT_001c118c)(0x3f333333,0x3f800000);
      iVar1 = (*DAT_001c1188)(0,1);
      if (iVar1 == 0) {
        uVar3 = *(undefined4 *)(*param_1 + 0x208);
        pcVar2 = "buttons/spark5.wav";
      }
      else {
        if (iVar1 != 1) goto LAB_000a8d1e;
        uVar3 = *(undefined4 *)(*param_1 + 0x208);
        pcVar2 = "buttons/spark6.wav";
      }
      EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar3,2,pcVar2,(float)lVar4,0x3f4ccccd,0,100);
    }
    else if (param_1[0x114] == 7) {
      lVar4 = (longdouble)(*DAT_001c118c)(0x3f000000,0x3fc00000);
      UTIL_Ricochet__FRC6Vectorf(param_5 + 0x14,(float)lVar4);
    }
  }
LAB_000a8d1e:
  uStack_c = *param_4;
  uStack_8 = param_4[1];
  uStack_4 = param_4[2];
  TraceAttack__11CBaseEntityP9entvars_sfG6VectorP11TraceResulti
            (param_1,param_2,param_3,&uStack_c,param_5,param_6);
  return;
}


// TraceAttack__11CBaseEntityP9entvars_sfG6VectorP11TraceResulti  @ 000bf7ec
void TraceAttack__11CBaseEntityP9entvars_sfG6VectorP11TraceResulti
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  float fVar1;
  
  fVar1 = *(float *)(*param_1 + 0x16c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    AddMultiDamage__FP9entvars_sP11CBaseEntityfi(param_2,param_1,param_3,param_6);
    (**(code **)(param_1[0x111] + 0x44))(param_1);
  }
  return;
}


// TraceAttack__11CBasePlayerP9entvars_sfG6VectorP11TraceResulti  @ 000d3b8c
void TraceAttack__11CBasePlayerP9entvars_sfG6VectorP11TraceResulti
               (int *param_1,int param_2,float param_3,undefined4 *param_4,int param_5,uint param_6)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  undefined2 in_FPUControlWord;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined2 local_4;
  undefined2 uStack_2;
  
  fVar1 = *(float *)(*param_1 + 0x16c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    return;
  }
  param_1[0x158] = *(int *)(param_5 + 0x34);
  iVar2 = *(int *)(param_2 + 0x208);
  if ((iVar2 == 0) && (iVar2 = (*DAT_001c1134)(0), iVar2 == 0)) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(iVar2 + 0x7c);
  }
  if ((param_6 & 0x10000000) == 0) goto switchD_000d3c29_caseD_0;
  switch(*(undefined4 *)(param_5 + 0x34)) {
  case 1:
    param_3 = param_3 + param_3;
    ClientPrint__FP9entvars_siPCcN42(*piVar4,1,"#Sniper_headshot",0,0,0,0);
    piVar4[0xfa] = (int)"headshot" - *(int *)(gpGlobals + 0x98);
    break;
  case 6:
  case 7:
    iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar4);
    if ((iVar2 == 0) || (param_1 == piVar4)) {
LAB_000d3cce:
      param_3 = param_3 * 0.5;
      param_1[0x68] = (int)((float)param_1[0x68] + 1.0);
      TeamFortress_SetSpeed__11CBasePlayer(param_1);
      ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Sniper_leginjury",0,0,0,0);
    }
    else {
      _local_4 = CONCAT22(uStack_2,in_FPUControlWord);
      local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
      if (((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x1eU) == 0) goto LAB_000d3cce;
    }
    ClientPrint__FP9entvars_siPCcN42(*piVar4,1,"#Sniper_legshot",0,0,0,0);
  }
switchD_000d3c29_caseD_0:
  uVar5 = 0;
  iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar4);
  if ((iVar2 != 0) && (param_1 != piVar4)) {
    if ((param_6 & 0x40) == 0) {
      _local_4 = CONCAT22(uStack_2,in_FPUControlWord);
      local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
      if (((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 4U) != 0) {
        uVar5 = 1;
      }
    }
    else {
      _local_4 = CONCAT22(uStack_2,in_FPUControlWord);
      local_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
      uVar5 = (uint)(int)ROUND(*(float *)(gpGlobals + 0x1c)) >> 4 & 1;
    }
  }
  if (uVar5 == 0) {
    local_18 = *(undefined4 *)(param_5 + 0x14);
    local_14 = *(undefined4 *)(param_5 + 0x18);
    local_10 = *(undefined4 *)(param_5 + 0x1c);
    uVar3 = (**(code **)(param_1[0x111] + 0x44))(param_1,param_3);
    SpawnBlood__FG6Vectorif(&local_18,uVar3);
    local_18 = *param_4;
    local_14 = param_4[1];
    local_10 = param_4[2];
    (**(code **)(param_1[0x111] + 0x48))(param_1,param_3,&local_18,param_5,param_6);
  }
  AddMultiDamage__FP9entvars_sP11CBaseEntityfi(param_2,param_1,param_3,param_6);
  return;
}


// TraceAttack__11CBaseTurretP9entvars_sfG6VectorP11TraceResulti  @ 0011872c
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
         != 0x40) || (iVar2 = (*DAT_001c1188)(0,10), iVar2 < 1)) {
      lVar3 = (longdouble)(*DAT_001c118c)(0x3f800000,0x40000000);
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


// TraceAttack__12CBaseMonsterP9entvars_sfG6VectorP11TraceResulti  @ 000c2394
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TraceAttack__12CBaseMonsterP9entvars_sfG6VectorP11TraceResulti
               (int *param_1,undefined4 param_2,float param_3,undefined4 *param_4,int param_5,
               undefined4 param_6)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  fVar1 = *(float *)(*param_1 + 0x16c);
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_1[0x158] = *(int *)(param_5 + 0x34);
    switch(*(undefined4 *)(param_5 + 0x34)) {
    case 1:
      param_3 = param_3 * _DAT_001c368c;
      break;
    case 2:
      param_3 = param_3 * _DAT_001c3690;
      break;
    case 3:
      param_3 = param_3 * _DAT_001c3694;
      break;
    case 4:
    case 5:
      param_3 = param_3 * _DAT_001c369c;
      break;
    case 6:
    case 7:
      param_3 = param_3 * _DAT_001c3698;
    }
    local_c = *(undefined4 *)(param_5 + 0x14);
    local_8 = *(undefined4 *)(param_5 + 0x18);
    local_4 = *(undefined4 *)(param_5 + 0x1c);
    uVar2 = (**(code **)(param_1[0x111] + 0x44))(param_1,param_3);
    SpawnBlood__FG6Vectorif(&local_c,uVar2);
    local_c = *param_4;
    local_8 = param_4[1];
    local_4 = param_4[2];
    (**(code **)(param_1[0x111] + 0x48))(param_1,param_3,&local_c,param_5,param_6);
    AddMultiDamage__FP9entvars_sP11CBaseEntityfi(param_2,param_1,param_3,param_6);
  }
  return;
}


