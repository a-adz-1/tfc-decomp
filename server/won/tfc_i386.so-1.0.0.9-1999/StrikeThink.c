// StrikeThink__10CLightning  @ 000ac4e0
void StrikeThink__10CLightning(int *param_1)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined2 in_FPUControlWord;
  longdouble lVar6;
  int *local_4c;
  undefined1 auStack_48 [56];
  undefined4 uStack_10;
  undefined2 uStack_8;
  undefined2 uStack_6;
  
  fVar1 = (float)param_1[0xf6];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    if ((*(byte *)(*param_1 + 0x180) & 4) == 0) {
      *(float *)(*param_1 + 0xe4) = *gpGlobals + (float)param_1[0xf6] + (float)param_1[0xfb];
    }
    else {
      lVar6 = (longdouble)(*DAT_0017562c)(0,param_1[0xfb]);
      *(float *)(*param_1 + 0xe4) =
           (float)((longdouble)*gpGlobals + (longdouble)(float)param_1[0xf6] + lVar6);
    }
  }
  param_1[0xf3] = 1;
  if (param_1[0xf5] == 0) {
    if (param_1[0xf4] == 0) {
      RandomArea__10CLightning(param_1);
    }
    else {
      piVar2 = (int *)RandomTargetname__5CBeamPCc(param_1,param_1[0xf4] + (int)gpGlobals[0x26]);
      if (piVar2 == (int *)0x0) {
        (*DAT_001755b4)(1,"env_beam: unknown entity \"%s\"\n",param_1[0xf4] + (int)gpGlobals[0x26]);
      }
      else {
        RandomPoint__10CLightningR6Vector(param_1,*piVar2 + 8);
      }
    }
  }
  else {
    local_4c = (int *)RandomTargetname__5CBeamPCc(param_1,param_1[0xf4] + (int)gpGlobals[0x26]);
    piVar2 = (int *)RandomTargetname__5CBeamPCc(param_1,param_1[0xf5] + (int)gpGlobals[0x26]);
    if ((local_4c != (int *)0x0) && (piVar2 != (int *)0x0)) {
      (*DAT_00175578)(0,0x17,0,0);
      iVar3 = IsPointEntity__FP11CBaseEntity(local_4c);
      if ((iVar3 == 0) && (iVar3 = IsPointEntity__FP11CBaseEntity(piVar2), iVar3 == 0)) {
        if ((*(byte *)(*param_1 + 0x180) & 8) == 0) {
          uVar4 = 8;
        }
        else {
          uVar4 = 0x18;
        }
        (*DAT_00175580)(uVar4);
        uVar4 = (*DAT_001755dc)(*(undefined4 *)(*local_4c + 0x1e8));
        (*DAT_00175588)(uVar4);
        uVar4 = (*DAT_001755dc)(*(undefined4 *)(*piVar2 + 0x1e8));
        (*DAT_00175588)(uVar4);
      }
      else {
        if ((*(byte *)(*param_1 + 0x180) & 8) != 0) {
          return;
        }
        iVar3 = IsPointEntity__FP11CBaseEntity(piVar2);
        piVar5 = piVar2;
        if (iVar3 == 0) {
          piVar5 = local_4c;
          local_4c = piVar2;
        }
        iVar3 = IsPointEntity__FP11CBaseEntity(local_4c);
        piVar2 = piVar5;
        if (iVar3 == 0) {
          (*DAT_00175580)(1);
          uVar4 = (*DAT_001755dc)(*(undefined4 *)(*local_4c + 0x1e8));
          (*DAT_00175588)(uVar4);
          (*DAT_00175594)(*(undefined4 *)(*piVar5 + 8));
          (*DAT_00175594)(*(undefined4 *)(*piVar5 + 0xc));
          (*DAT_00175594)(*(undefined4 *)(*piVar5 + 0x10));
        }
        else {
          (*DAT_00175580)(0);
          (*DAT_00175594)(*(undefined4 *)(*local_4c + 8));
          (*DAT_00175594)(*(undefined4 *)(*local_4c + 0xc));
          (*DAT_00175594)(*(undefined4 *)(*local_4c + 0x10));
          (*DAT_00175594)(*(undefined4 *)(*piVar5 + 8));
          (*DAT_00175594)(*(undefined4 *)(*piVar5 + 0xc));
          (*DAT_00175594)(*(undefined4 *)(*piVar5 + 0x10));
        }
      }
      (*DAT_00175588)(param_1[0xfc]);
      (*DAT_00175580)(param_1[0xfe]);
      uStack_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      (*DAT_00175580)((int)ROUND(*(float *)(*param_1 + 0x118)));
      uStack_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      (*DAT_00175580)((int)ROUND((float)param_1[0xf6] * 10.0));
      (*DAT_00175580)(param_1[0xf7]);
      (*DAT_00175580)(param_1[0xf8]);
      uStack_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      (*DAT_00175580)((int)ROUND(*(float *)(*param_1 + 0x130)));
      uStack_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      (*DAT_00175580)((int)ROUND(*(float *)(*param_1 + 0x134)));
      uStack_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      (*DAT_00175580)((int)ROUND(*(float *)(*param_1 + 0x138)));
      _uStack_8 = CONCAT22(uStack_6,in_FPUControlWord);
      uStack_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
      (*DAT_00175580)((int)ROUND(*(float *)(*param_1 + 300)));
      (*DAT_00175580)(param_1[0xfa]);
      (*DAT_0017557c)();
      DoSparks__5CBeamRC6VectorT1(param_1,*local_4c + 8,*piVar2 + 8);
      fVar1 = *(float *)(*param_1 + 0x1c0);
      if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1) {
        UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                  (*local_4c + 8,*piVar2 + 8,0,0,auStack_48);
        *(float *)(*param_1 + 0x1c4) = *gpGlobals - 1.0;
        BeamDamage__5CBeamP11TraceResult(param_1,auStack_48);
      }
    }
  }
  return;
}


// StrikeThink__6CLaser  @ 000adc50
void StrikeThink__6CLaser(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined1 local_3c [56];
  
  piVar2 = (int *)RandomTargetname__5CBeamPCc
                            (param_1,*(int *)(*param_1 + 0x1b4) + (int)gpGlobals[0x26]);
  if (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    param_1[0xf5] = *(int *)(iVar1 + 8);
    param_1[0xf6] = *(int *)(iVar1 + 0xc);
    param_1[0xf7] = *(int *)(iVar1 + 0x10);
  }
  UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
            (*param_1 + 8,param_1 + 0xf5,0,0,local_3c);
  FireAtPoint__6CLaserR11TraceResult(param_1,local_3c);
  *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
  return;
}


