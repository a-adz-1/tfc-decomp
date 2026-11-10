// NoFriendlyFire__13CSquadMonster  @ 000f4d84
undefined4 NoFriendlyFire__13CSquadMonster(int *param_1)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piStack_a4;
  float local_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  undefined1 auStack_70 [12];
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  undefined1 local_40 [20];
  undefined1 local_2c [20];
  undefined1 local_18 [20];
  
  iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x1a7);
  if (iVar2 != 0) {
    __6CPlane(local_18);
    __6CPlane(local_2c);
    __6CPlane(local_40);
    iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x13f);
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = __rf__7EHANDLE(param_1 + 0x13f);
    (**(code **)(*(int *)(iVar2 + 0x454) + 0xcc))(&local_88,iVar2);
    iVar2 = *param_1;
    fStack_7c = local_88 - *(float *)(iVar2 + 8);
    fStack_78 = fStack_84 - *(float *)(iVar2 + 0xc);
    fStack_74 = fStack_80 - *(float *)(iVar2 + 0x10);
    UTIL_VecToAngles__FRC6Vector(auStack_70,&fStack_7c);
    UTIL_MakeVectors__FRC6Vector(auStack_70);
    iVar2 = *param_1;
    fVar1 = *(float *)(iVar2 + 0xf4) * 1.5;
    fStack_4c = *(float *)(iVar2 + 8) - *(float *)(gpGlobals + 0x40) * fVar1;
    fStack_48 = *(float *)(iVar2 + 0xc) - *(float *)(gpGlobals + 0x44) * fVar1;
    fStack_44 = *(float *)(iVar2 + 0x10) - fVar1 * *(float *)(gpGlobals + 0x48);
    fStack_74 = *(float *)(iVar2 + 0xf4) * 1.5;
    fStack_7c = *(float *)(gpGlobals + 0x40) * fStack_74;
    fStack_78 = *(float *)(gpGlobals + 0x44) * fStack_74;
    fStack_74 = fStack_74 * *(float *)(gpGlobals + 0x48);
    fStack_58 = fStack_7c + *(float *)(iVar2 + 8);
    fStack_54 = fStack_78 + *(float *)(iVar2 + 0xc);
    fStack_50 = fStack_74 + *(float *)(iVar2 + 0x10);
    local_88 = -*(float *)(gpGlobals + 0x40);
    fStack_84 = -*(float *)(gpGlobals + 0x44);
    fStack_80 = -*(float *)(gpGlobals + 0x48);
    fStack_64 = local_88;
    fStack_60 = fStack_84;
    fStack_5c = fStack_80;
    InitializePlane__6CPlaneRC6VectorT1(local_2c,gpGlobals + 0x40,&fStack_4c);
    InitializePlane__6CPlaneRC6VectorT1(local_40,&fStack_64,&fStack_58);
    InitializePlane__6CPlaneRC6VectorT1(local_18,gpGlobals + 0x28,*param_1 + 8);
    piVar3 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x1a7);
    piStack_a4 = param_1;
    if (piVar3 != (int *)0x0) {
      piStack_a4 = piVar3;
    }
    iVar2 = 0;
    do {
      piVar3 = piStack_a4;
      if (iVar2 < 4) {
        piVar3 = (int *)__opP11CBaseEntity__7EHANDLE(piStack_a4 + iVar2 * 2 + 0x1a9);
      }
      if ((((piVar3 != (int *)0x0) && (piVar3 != param_1)) &&
          (iVar4 = PointInFront__6CPlaneRC6Vector(local_18,*piVar3 + 8), iVar4 != 0)) &&
         ((iVar4 = PointInFront__6CPlaneRC6Vector(local_2c,*piVar3 + 8), iVar4 != 0 &&
          (iVar4 = PointInFront__6CPlaneRC6Vector(local_40,*piVar3 + 8), iVar4 != 0)))) {
        return 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 5);
  }
  return 1;
}


