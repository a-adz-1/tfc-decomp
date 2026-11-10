// TraceAttack__10CBreakableP9entvars_sfG6VectorP11TraceResulti  @ 000a8310
void TraceAttack__10CBreakableP9entvars_sfG6VectorP11TraceResulti
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,int param_5,
               undefined4 param_6)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  longdouble lVar4;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar1 = (*DAT_0019f808)(0,1);
  if (iVar1 != 0) {
    if (param_1[0x118] == 6) {
      UTIL_Sparks__FRC6Vector(param_5 + 0x14);
      lVar4 = (longdouble)(*DAT_0019f80c)(0x3f333333,0x3f800000);
      iVar1 = (*DAT_0019f808)(0,1);
      if (iVar1 == 0) {
        uVar3 = *(undefined4 *)(*param_1 + 0x208);
        pcVar2 = "buttons/spark5.wav";
      }
      else {
        if (iVar1 != 1) goto LAB_000a8421;
        uVar3 = *(undefined4 *)(*param_1 + 0x208);
        pcVar2 = "buttons/spark6.wav";
      }
      EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar3,2,pcVar2,(float)lVar4,0x3f4ccccd,0,100);
    }
    else if (param_1[0x118] == 7) {
      lVar4 = (longdouble)(*DAT_0019f80c)(0x3f000000,0x3fc00000);
      UTIL_Ricochet__FRC6Vectorf(param_5 + 0x14,(float)lVar4);
    }
  }
LAB_000a8421:
  uStack_10 = *param_4;
  uStack_c = param_4[1];
  uStack_8 = param_4[2];
  TraceAttack__11CBaseEntityP9entvars_sfG6VectorP11TraceResulti
            (param_1,param_2,param_3,&uStack_10,param_5,param_6);
  return;
}


// TraceAttack__11CBaseEntityP9entvars_sfG6VectorP11TraceResulti  @ 000c1b00
void TraceAttack__11CBaseEntityP9entvars_sfG6VectorP11TraceResulti
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  float fVar1;
  
  fVar1 = *(float *)(*param_1 + 0x16c);
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    AddMultiDamage__FP9entvars_sP11CBaseEntityfi(param_2,param_1,param_3,param_6);
    (**(code **)(param_1[0x115] + 0x44))(param_1);
  }
  return;
}


// TraceAttack__11CBasePlayerP9entvars_sfG6VectorP11TraceResulti  @ 000d3d9c
void TraceAttack__11CBasePlayerP9entvars_sfG6VectorP11TraceResulti
               (int *param_1,int param_2,float param_3,undefined4 *param_4,int param_5,uint param_6)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  undefined2 in_FPUControlWord;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  uint uStack_10;
  undefined2 uStack_8;
  undefined2 uStack_6;
  
  fVar1 = *(float *)(*param_1 + 0x16c);
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 0x40) {
    return;
  }
  param_1[0x15c] = *(int *)(param_5 + 0x34);
  iVar2 = *(int *)(param_2 + 0x208);
  if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = *(int **)(iVar2 + 0x7c);
  }
  if ((param_6 & 0x10000000) == 0) goto switchD_000d3e30_caseD_0;
  switch(*(undefined4 *)(param_5 + 0x34)) {
  case 1:
    param_3 = param_3 + param_3;
    ClientPrint__FP9entvars_siPCcN42(*piVar5,1,"#Sniper_headshot",0,0,0,0);
    piVar5[0xfe] = (int)"headshot" - *(int *)(gpGlobals + 0x98);
    break;
  case 6:
  case 7:
    iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar5);
    if ((iVar2 == 0) || (param_1 == piVar5)) {
LAB_000d3ed5:
      param_3 = param_3 * 0.5;
      param_1[0x68] = (int)((float)param_1[0x68] + 1.0);
      TeamFortress_SetSpeed__11CBasePlayer(param_1);
      ClientPrint__FP9entvars_siPCcN42(*param_1,1,"#Sniper_leginjury",0,0,0,0);
    }
    else {
      _uStack_8 = CONCAT22(uStack_6,in_FPUControlWord);
      uStack_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      if (((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 0x1eU) == 0) goto LAB_000d3ed5;
    }
    ClientPrint__FP9entvars_siPCcN42(*piVar5,1,"#Sniper_legshot",0,0,0,0);
  }
switchD_000d3e30_caseD_0:
  uVar4 = 0;
  iVar2 = IsAlly__11CBaseEntityP11CBaseEntity(param_1,piVar5);
  if ((iVar2 != 0) && (param_1 != piVar5)) {
    if ((param_6 & 0x40) == 0) {
      _uStack_8 = CONCAT22(uStack_6,in_FPUControlWord);
      uStack_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      if (((int)ROUND(*(float *)(gpGlobals + 0x1c)) & 4U) != 0) {
        uVar4 = 1;
      }
    }
    else {
      _uStack_8 = CONCAT22(uStack_6,in_FPUControlWord);
      uStack_10 = (uint)ROUND(*(float *)(gpGlobals + 0x1c));
      uVar4 = uStack_10 >> 4 & 1;
    }
  }
  if (uVar4 == 0) {
    uStack_1c = *(undefined4 *)(param_5 + 0x14);
    uStack_18 = *(undefined4 *)(param_5 + 0x18);
    uStack_14 = *(undefined4 *)(param_5 + 0x1c);
    uVar3 = (**(code **)(param_1[0x115] + 0x44))(param_1,param_3);
    SpawnBlood__FG6Vectorif(&uStack_1c,uVar3);
    uStack_1c = *param_4;
    uStack_18 = param_4[1];
    uStack_14 = param_4[2];
    (**(code **)(param_1[0x115] + 0x48))(param_1,param_3,&uStack_1c,param_5,param_6);
  }
  AddMultiDamage__FP9entvars_sP11CBaseEntityfi(param_2,param_1,param_3,param_6);
  return;
}


// TraceAttack__11CBaseTurretP9entvars_sfG6VectorP11TraceResulti  @ 0011cd94
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
         != 0x40) || (iVar2 = (*DAT_0019f808)(0,10), iVar2 < 1)) {
      lVar3 = (longdouble)(*DAT_0019f80c)(0x3f800000,0x40000000);
      UTIL_Ricochet__FRC6Vectorf(param_5 + 0x14,(float)lVar3);
      *(float *)(*param_1 + 0x1e4) = *gpGlobals;
    }
    param_3 = 0x3dcccccd;
  }
  fVar1 = *(float *)(*param_1 + 0x16c);
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    AddMultiDamage__FP9entvars_sP11CBaseEntityfi(param_2,param_1,param_3,param_6);
  }
  return;
}


// TraceAttack__12CBaseMonsterP9entvars_sfG6VectorP11TraceResulti  @ 000c1698
void TraceAttack__12CBaseMonsterP9entvars_sfG6VectorP11TraceResulti
               (int *param_1,undefined4 param_2,float param_3,undefined4 *param_4,int param_5,
               undefined4 param_6)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  fVar1 = *(float *)(*param_1 + 0x16c);
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    param_1[0x15c] = *(int *)(param_5 + 0x34);
    switch(*(undefined4 *)(param_5 + 0x34)) {
    case 1:
      param_3 = param_3 * DAT_001a1d2c;
      break;
    case 2:
      param_3 = param_3 * DAT_001a1d30;
      break;
    case 3:
      param_3 = param_3 * DAT_001a1d34;
      break;
    case 4:
    case 5:
      param_3 = param_3 * DAT_001a1d3c;
      break;
    case 6:
    case 7:
      param_3 = param_3 * DAT_001a1d38;
    }
    uStack_10 = *(undefined4 *)(param_5 + 0x14);
    uStack_c = *(undefined4 *)(param_5 + 0x18);
    uStack_8 = *(undefined4 *)(param_5 + 0x1c);
    uVar2 = (**(code **)(param_1[0x115] + 0x44))(param_1,param_3);
    SpawnBlood__FG6Vectorif(&uStack_10,uVar2);
    uStack_10 = *param_4;
    uStack_c = param_4[1];
    uStack_8 = param_4[2];
    (**(code **)(param_1[0x115] + 0x48))(param_1,param_3,&uStack_10,param_5,param_6);
    AddMultiDamage__FP9entvars_sP11CBaseEntityfi(param_2,param_1,param_3,param_6);
  }
  return;
}


