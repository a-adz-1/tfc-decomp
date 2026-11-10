// StrikeThink__10CLightning  @ 0009ff70
void StrikeThink__10CLightning(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined2 in_FPUControlWord;
  longdouble lVar8;
  int local_68;
  int *local_64;
  int *local_5c;
  int *local_54;
  int *local_50;
  undefined1 auStack_48 [56];
  undefined4 local_10;
  undefined2 local_8;
  undefined2 uStack_6;
  
  fVar1 = (float)param_1[0x119];
  if ((byte)(fVar1 < 0.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if ((*(byte *)(*param_1 + 0x1a0) & 4) == 0) {
      *(float *)(*param_1 + 0x104) = *gpGlobals + fVar1 + (float)param_1[0x11e];
    }
    else {
      lVar8 = (longdouble)(*DAT_0019f80c)(0,param_1[0x11e]);
      *(float *)(*param_1 + 0x104) =
           (float)((longdouble)*gpGlobals + (longdouble)(float)param_1[0x119] + lVar8);
    }
  }
  param_1[0x116] = 1;
  if (param_1[0x118] == 0) {
    iVar3 = param_1[0x117];
    if (iVar3 == 0) {
      RandomArea__10CLightning(param_1);
    }
    else {
      piVar5 = (int *)0x0;
      local_50 = (int *)0x0;
      fVar1 = gpGlobals[0x26];
      iVar7 = 0;
      while (piVar5 = (int *)UTIL_FindEntityByTargetname__FP11CBaseEntityPCc
                                       (piVar5,iVar3 + (int)fVar1), piVar5 != (int *)0x0) {
        iVar6 = iVar7 + 1;
        iVar2 = (*DAT_0019f808)(0,iVar7);
        iVar7 = iVar6;
        if (iVar2 < 1) {
          local_50 = piVar5;
        }
      }
      if (local_50 == (int *)0x0) {
        (*DAT_0019f794)(1,"env_beam: unknown entity \"%s\"\n",param_1[0x117] + (int)gpGlobals[0x26])
        ;
      }
      else {
        RandomPoint__10CLightningR6Vector(param_1,*local_50 + 8);
      }
    }
  }
  else {
    piVar5 = (int *)0x0;
    iVar3 = param_1[0x117];
    local_5c = (int *)0x0;
    fVar1 = gpGlobals[0x26];
    iVar7 = 0;
    while (piVar5 = (int *)UTIL_FindEntityByTargetname__FP11CBaseEntityPCc
                                     (piVar5,iVar3 + (int)fVar1), piVar5 != (int *)0x0) {
      iVar6 = iVar7 + 1;
      iVar2 = (*DAT_0019f808)(0,iVar7);
      iVar7 = iVar6;
      if (iVar2 < 1) {
        local_5c = piVar5;
      }
    }
    local_54 = local_5c;
    piVar5 = (int *)0x0;
    iVar3 = param_1[0x118];
    local_64 = (int *)0x0;
    fVar1 = gpGlobals[0x26];
    iVar7 = 0;
    while( true ) {
      piVar5 = (int *)UTIL_FindEntityByTargetname__FP11CBaseEntityPCc(piVar5,iVar3 + (int)fVar1);
      if (piVar5 == (int *)0x0) break;
      iVar6 = iVar7 + 1;
      iVar2 = (*DAT_0019f808)(0,iVar7);
      iVar7 = iVar6;
      if (iVar2 < 1) {
        local_64 = piVar5;
      }
    }
    if (((local_5c != (int *)0x0) && (local_64 != (int *)0x0)) &&
       (((iVar3 = IsPointEntity__FP11CBaseEntity(local_5c), iVar3 == 0 &&
         (iVar3 = IsPointEntity__FP11CBaseEntity(local_64), iVar3 == 0)) ||
        ((*(byte *)(*param_1 + 0x1a0) & 8) == 0)))) {
      (*DAT_0019f758)(0,0x17,0,0);
      iVar3 = IsPointEntity__FP11CBaseEntity(local_5c);
      if ((iVar3 == 0) && (iVar3 = IsPointEntity__FP11CBaseEntity(local_64), iVar3 == 0)) {
        if ((*(byte *)(*param_1 + 0x1a0) & 8) == 0) {
          uVar4 = 8;
        }
        else {
          uVar4 = 0x18;
        }
        (*DAT_0019f760)(uVar4);
        uVar4 = (*DAT_0019f7bc)(*(undefined4 *)(*local_5c + 0x208));
        (*DAT_0019f768)(uVar4);
        uVar4 = (*DAT_0019f7bc)(*(undefined4 *)(*local_64 + 0x208));
        (*DAT_0019f768)(uVar4);
      }
      else {
        iVar3 = IsPointEntity__FP11CBaseEntity(local_64);
        if (iVar3 == 0) {
          local_54 = local_64;
          local_64 = local_5c;
        }
        iVar3 = IsPointEntity__FP11CBaseEntity(local_54);
        if (iVar3 == 0) {
          (*DAT_0019f760)(1);
          uVar4 = (*DAT_0019f7bc)(*(undefined4 *)(*local_54 + 0x208));
          (*DAT_0019f768)(uVar4);
          (*DAT_0019f774)(*(undefined4 *)(*local_64 + 8));
          (*DAT_0019f774)(*(undefined4 *)(*local_64 + 0xc));
          (*DAT_0019f774)(*(undefined4 *)(*local_64 + 0x10));
        }
        else {
          (*DAT_0019f760)(0);
          (*DAT_0019f774)(*(undefined4 *)(*local_54 + 8));
          (*DAT_0019f774)(*(undefined4 *)(*local_54 + 0xc));
          (*DAT_0019f774)(*(undefined4 *)(*local_54 + 0x10));
          (*DAT_0019f774)(*(undefined4 *)(*local_64 + 8));
          (*DAT_0019f774)(*(undefined4 *)(*local_64 + 0xc));
          (*DAT_0019f774)(*(undefined4 *)(*local_64 + 0x10));
        }
      }
      (*DAT_0019f768)(param_1[0x11f]);
      (*DAT_0019f760)(param_1[0x121]);
      local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      (*DAT_0019f760)((int)ROUND(*(float *)(*param_1 + 0x138)));
      local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      (*DAT_0019f760)((int)ROUND((float)param_1[0x119] * 10.0));
      (*DAT_0019f760)(param_1[0x11a]);
      (*DAT_0019f760)(param_1[0x11b]);
      local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      (*DAT_0019f760)((int)ROUND(*(float *)(*param_1 + 0x150)));
      local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      (*DAT_0019f760)((int)ROUND(*(float *)(*param_1 + 0x154)));
      local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      (*DAT_0019f760)((int)ROUND(*(float *)(*param_1 + 0x158)));
      _local_8 = CONCAT22(uStack_6,in_FPUControlWord);
      local_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      (*DAT_0019f760)((int)ROUND(*(float *)(*param_1 + 0x14c)));
      (*DAT_0019f760)(param_1[0x11d]);
      (*DAT_0019f75c)();
      iVar3 = *local_64;
      local_68 = *param_1;
      if ((*(uint *)(local_68 + 0x1a0) & 0x30) != 0) {
        if ((*(uint *)(local_68 + 0x1a0) & 0x10) != 0) {
          UTIL_Sparks__FRC6Vector(*local_54 + 8);
          local_68 = *param_1;
        }
        if ((*(byte *)(local_68 + 0x1a0) & 0x20) != 0) {
          UTIL_Sparks__FRC6Vector(iVar3 + 8);
          local_68 = *param_1;
        }
      }
      if (0.0 < *(float *)(local_68 + 0x1e0)) {
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (*local_54 + 8,*local_64 + 8,0,0,auStack_48);
        *(float *)(*param_1 + 0x1e4) = *gpGlobals - 1.0;
        BeamDamage__5CBeamP11TraceResult(param_1,auStack_48);
      }
    }
  }
  return;
}


// StrikeThink__6CLaser  @ 000a1954
void StrikeThink__6CLaser(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *local_48;
  undefined1 auStack_3c [20];
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  piVar5 = (int *)0x0;
  local_48 = (int *)0x0;
  iVar4 = *(int *)(*param_1 + 0x1d4);
  fVar1 = gpGlobals[0x26];
  iVar3 = 0;
  while( true ) {
    piVar5 = (int *)UTIL_FindEntityByTargetname__FP11CBaseEntityPCc(piVar5,iVar4 + (int)fVar1);
    if (piVar5 == (int *)0x0) break;
    iVar6 = iVar3 + 1;
    iVar2 = (*DAT_0019f808)(0,iVar3);
    iVar3 = iVar6;
    if (iVar2 < 1) {
      local_48 = piVar5;
    }
  }
  if (local_48 != (int *)0x0) {
    iVar4 = *local_48;
    param_1[0x118] = *(int *)(iVar4 + 8);
    param_1[0x119] = *(int *)(iVar4 + 0xc);
    param_1[0x11a] = *(int *)(iVar4 + 0x10);
  }
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (*param_1 + 8,param_1 + 0x118,0,0,auStack_3c);
  iVar4 = *param_1;
  *(undefined4 *)(iVar4 + 0x50) = uStack_28;
  *(undefined4 *)(iVar4 + 0x54) = uStack_24;
  *(undefined4 *)(iVar4 + 0x58) = uStack_20;
  if ((undefined4 *)param_1[0x116] != (undefined4 *)0x0) {
    UTIL_SetOrigin__FP9entvars_sRC6Vector(*(undefined4 *)param_1[0x116],&uStack_28);
  }
  BeamDamage__5CBeamP11TraceResult(param_1,auStack_3c);
  iVar4 = *param_1;
  if ((*(uint *)(iVar4 + 0x148) & 0xf) == 2) {
    iVar3 = (*DAT_0019f7c0)(*(uint *)(iVar4 + 0x128) & 0xfff);
    iVar3 = iVar3 + 0x88;
    iVar4 = *param_1;
  }
  else {
    iVar3 = iVar4 + 8;
  }
  if ((*(uint *)(iVar4 + 0x1a0) & 0x30) != 0) {
    if ((*(uint *)(iVar4 + 0x1a0) & 0x10) != 0) {
      UTIL_Sparks__FRC6Vector(iVar3);
      iVar4 = *param_1;
    }
    if ((*(byte *)(iVar4 + 0x1a0) & 0x20) != 0) {
      UTIL_Sparks__FRC6Vector(&uStack_28);
      iVar4 = *param_1;
    }
  }
  *(float *)(iVar4 + 0x104) = *gpGlobals + 0.1;
  return;
}


