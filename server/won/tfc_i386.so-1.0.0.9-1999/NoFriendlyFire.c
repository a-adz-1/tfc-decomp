// NoFriendlyFire__13CSquadMonster  @ 000efc40
undefined4 NoFriendlyFire__13CSquadMonster(int *param_1)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piStack_90;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  undefined1 local_70 [12];
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float local_4c;
  float local_48;
  float local_44;
  undefined1 local_40 [20];
  undefined1 local_2c [20];
  undefined1 local_18 [20];
  
  iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x184);
  if (iVar2 != 0) {
    __6CPlane(local_18);
    __6CPlane(local_2c);
    __6CPlane(local_40);
    iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x11c);
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = __rf__7EHANDLE(param_1 + 0x11c);
    (**(code **)(*(int *)(iVar2 + 0x3c8) + 0xc4))(&local_88,iVar2);
    iVar2 = *param_1;
    local_7c = local_88 - *(float *)(iVar2 + 8);
    local_78 = local_84 - *(float *)(iVar2 + 0xc);
    local_74 = local_80 - *(float *)(iVar2 + 0x10);
    UTIL_VecToAngles__FRC6Vector(local_70,&local_7c);
    UTIL_MakeVectors__FRC6Vector(local_70);
    iVar2 = *param_1;
    fVar1 = *(float *)(iVar2 + 0xd4) * 1.5;
    local_4c = *(float *)(iVar2 + 8) - fVar1 * *(float *)(gpGlobals + 0x40);
    local_48 = *(float *)(iVar2 + 0xc) - fVar1 * *(float *)(gpGlobals + 0x44);
    local_44 = *(float *)(iVar2 + 0x10) - fVar1 * *(float *)(gpGlobals + 0x48);
    local_74 = *(float *)(iVar2 + 0xd4) * 1.5;
    local_7c = local_74 * *(float *)(gpGlobals + 0x40);
    local_78 = local_74 * *(float *)(gpGlobals + 0x44);
    local_74 = local_74 * *(float *)(gpGlobals + 0x48);
    fStack_58 = *(float *)(iVar2 + 8) + local_7c;
    fStack_54 = *(float *)(iVar2 + 0xc) + local_78;
    fStack_50 = *(float *)(iVar2 + 0x10) + local_74;
    local_88 = *(float *)(gpGlobals + 0x40) * -1.0;
    local_84 = *(float *)(gpGlobals + 0x44) * -1.0;
    local_80 = *(float *)(gpGlobals + 0x48) * -1.0;
    fStack_64 = local_88;
    fStack_60 = local_84;
    fStack_5c = local_80;
    InitializePlane__6CPlaneRC6VectorT1(local_2c,gpGlobals + 0x40,&local_4c);
    InitializePlane__6CPlaneRC6VectorT1(local_40,&fStack_64,&fStack_58);
    InitializePlane__6CPlaneRC6VectorT1(local_18,gpGlobals + 0x28,*param_1 + 8);
    piVar3 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x184);
    piStack_90 = param_1;
    if (piVar3 != (int *)0x0) {
      piStack_90 = piVar3;
    }
    iVar2 = 0;
    do {
      piVar3 = piStack_90;
      if (iVar2 < 4) {
        piVar3 = (int *)__opP11CBaseEntity__7EHANDLE(piStack_90 + iVar2 * 2 + 0x186);
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


