// StrikeThink__10CLightning  @ 00096ab0
void StrikeThink__10CLightning(int *param_1)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined2 in_FPUControlWord;
  longdouble lVar6;
  int *local_48;
  undefined1 auStack_44 [56];
  undefined4 uStack_c;
  undefined2 uStack_4;
  undefined2 uStack_2;
  
  fVar1 = (float)param_1[0xf9];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if ((*(byte *)(*param_1 + 0x1a0) & 4) == 0) {
      *(float *)(*param_1 + 0x104) = *gpGlobals + (float)param_1[0xf9] + (float)param_1[0xfe];
    }
    else {
      lVar6 = (longdouble)(*DAT_001a7fac)(0,param_1[0xfe]);
      *(float *)(*param_1 + 0x104) =
           (float)((longdouble)*gpGlobals + (longdouble)(float)param_1[0xf9] + lVar6);
    }
  }
  param_1[0xf6] = 1;
  if (param_1[0xf8] == 0) {
    if (param_1[0xf7] == 0) {
      RandomArea__10CLightning(param_1);
    }
    else {
      piVar2 = (int *)RandomTargetname__5CBeamPCc(param_1,param_1[0xf7] + (int)gpGlobals[0x26]);
      if (piVar2 == (int *)0x0) {
        (*DAT_001a7f34)(1,"env_beam: unknown entity \"%s\"\n",param_1[0xf7] + (int)gpGlobals[0x26]);
      }
      else {
        RandomPoint__10CLightningR6Vector(param_1,*piVar2 + 8);
      }
    }
  }
  else {
    local_48 = (int *)RandomTargetname__5CBeamPCc(param_1,param_1[0xf7] + (int)gpGlobals[0x26]);
    piVar2 = (int *)RandomTargetname__5CBeamPCc(param_1,param_1[0xf8] + (int)gpGlobals[0x26]);
    if ((local_48 != (int *)0x0) && (piVar2 != (int *)0x0)) {
      (*DAT_001a7ef8)(0,0x17,0,0);
      iVar3 = IsPointEntity__FP11CBaseEntity(local_48);
      if ((iVar3 == 0) && (iVar3 = IsPointEntity__FP11CBaseEntity(piVar2), iVar3 == 0)) {
        if ((*(byte *)(*param_1 + 0x1a0) & 8) == 0) {
          uVar4 = 8;
        }
        else {
          uVar4 = 0x18;
        }
        (*DAT_001a7f00)(uVar4);
        uVar4 = (*DAT_001a7f5c)(*(undefined4 *)(*local_48 + 0x208));
        (*DAT_001a7f08)(uVar4);
        uVar4 = (*DAT_001a7f5c)(*(undefined4 *)(*piVar2 + 0x208));
        (*DAT_001a7f08)(uVar4);
      }
      else {
        if ((*(byte *)(*param_1 + 0x1a0) & 8) != 0) {
          return;
        }
        iVar3 = IsPointEntity__FP11CBaseEntity(piVar2);
        piVar5 = piVar2;
        if (iVar3 == 0) {
          piVar5 = local_48;
          local_48 = piVar2;
        }
        iVar3 = IsPointEntity__FP11CBaseEntity(local_48);
        piVar2 = piVar5;
        if (iVar3 == 0) {
          (*DAT_001a7f00)(1);
          uVar4 = (*DAT_001a7f5c)(*(undefined4 *)(*local_48 + 0x208));
          (*DAT_001a7f08)(uVar4);
          (*DAT_001a7f14)(*(undefined4 *)(*piVar5 + 8));
          (*DAT_001a7f14)(*(undefined4 *)(*piVar5 + 0xc));
          (*DAT_001a7f14)(*(undefined4 *)(*piVar5 + 0x10));
        }
        else {
          (*DAT_001a7f00)(0);
          (*DAT_001a7f14)(*(undefined4 *)(*local_48 + 8));
          (*DAT_001a7f14)(*(undefined4 *)(*local_48 + 0xc));
          (*DAT_001a7f14)(*(undefined4 *)(*local_48 + 0x10));
          (*DAT_001a7f14)(*(undefined4 *)(*piVar5 + 8));
          (*DAT_001a7f14)(*(undefined4 *)(*piVar5 + 0xc));
          (*DAT_001a7f14)(*(undefined4 *)(*piVar5 + 0x10));
        }
      }
      (*DAT_001a7f08)(param_1[0xff]);
      (*DAT_001a7f00)(param_1[0x101]);
      uStack_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
      (*DAT_001a7f00)((int)ROUND(*(float *)(*param_1 + 0x138)));
      uStack_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
      (*DAT_001a7f00)((int)ROUND((float)param_1[0xf9] * 10.0));
      (*DAT_001a7f00)(param_1[0xfa]);
      (*DAT_001a7f00)(param_1[0xfb]);
      uStack_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
      (*DAT_001a7f00)((int)ROUND(*(float *)(*param_1 + 0x150)));
      uStack_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
      (*DAT_001a7f00)((int)ROUND(*(float *)(*param_1 + 0x154)));
      uStack_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
      (*DAT_001a7f00)((int)ROUND(*(float *)(*param_1 + 0x158)));
      _uStack_4 = CONCAT22(uStack_2,in_FPUControlWord);
      uStack_c = CONCAT22(uStack_2,CONCAT11(0xc,(char)in_FPUControlWord));
      (*DAT_001a7f00)((int)ROUND(*(float *)(*param_1 + 0x14c)));
      (*DAT_001a7f00)(param_1[0xfd]);
      (*DAT_001a7efc)();
      DoSparks__5CBeamRC6VectorT1(param_1,*local_48 + 8,*piVar2 + 8);
      if (0.0 < *(float *)(*param_1 + 0x1e0)) {
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (*local_48 + 8,*piVar2 + 8,0,0,auStack_44);
        *(float *)(*param_1 + 0x1e4) = *gpGlobals - 1.0;
        BeamDamage__5CBeamP11TraceResult(param_1,auStack_44);
      }
    }
  }
  return;
}


// StrikeThink__6CLaser  @ 000987b0
void StrikeThink__6CLaser(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined1 local_38 [56];
  
  piVar2 = (int *)RandomTargetname__5CBeamPCc
                            (param_1,*(int *)(*param_1 + 0x1d4) + (int)gpGlobals[0x26]);
  if (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    param_1[0xf8] = *(int *)(iVar1 + 8);
    param_1[0xf9] = *(int *)(iVar1 + 0xc);
    param_1[0xfa] = *(int *)(iVar1 + 0x10);
  }
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (*param_1 + 8,param_1 + 0xf8,0,0,local_38);
  FireAtPoint__6CLaserR11TraceResult(param_1,local_38);
  *(float *)(*param_1 + 0x104) = *gpGlobals + 0.1;
  return;
}


