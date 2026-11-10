// NoFriendlyFire__13CSquadMonster  @ 000e6178
undefined4 NoFriendlyFire__13CSquadMonster(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *unaff_retaddr;
  int *piVar7;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  undefined1 local_6c [4];
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined1 local_44 [8];
  undefined1 local_3c [12];
  undefined1 local_30 [8];
  undefined1 local_28 [12];
  undefined1 local_1c [8];
  undefined1 local_14 [16];
  int *local_4;
  
  iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x61c);
  if (iVar2 == 0) {
LAB_000e6587:
    uVar3 = 1;
  }
  else {
    __6CPlane(local_14);
    __6CPlane(local_28);
    __6CPlane(local_3c);
    iVar2 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x47c);
    if (iVar2 != 0) {
      iVar2 = __rf__7EHANDLE(param_1 + 0x47c);
      (**(code **)(*(int *)(iVar2 + 0x3d4) + 0xc4))(&local_84,iVar2);
      iVar2 = *unaff_retaddr;
      local_7c = local_88 - *(float *)(iVar2 + 8);
      local_78 = local_84 - *(float *)(iVar2 + 0xc);
      local_74 = local_80 - *(float *)(iVar2 + 0x10);
      UTIL_VecToAngles__FRC6Vector(local_6c,&local_7c);
      UTIL_MakeVectors__FRC6Vector(local_6c);
      iVar2 = *local_4;
      fVar1 = *(float *)(iVar2 + 0xf4) * 1.5;
      local_50 = *(float *)(iVar2 + 8) - fVar1 * *(float *)(gpGlobals + 0x40);
      local_4c = *(float *)(iVar2 + 0xc) - fVar1 * *(float *)(gpGlobals + 0x44);
      local_48 = *(float *)(iVar2 + 0x10) - fVar1 * *(float *)(gpGlobals + 0x48);
      local_78 = *(float *)(iVar2 + 0xf4) * 1.5;
      local_80 = local_78 * *(float *)(gpGlobals + 0x40);
      local_7c = local_78 * *(float *)(gpGlobals + 0x44);
      local_78 = local_78 * *(float *)(gpGlobals + 0x48);
      local_5c = *(float *)(iVar2 + 8) + local_80;
      local_58 = *(float *)(iVar2 + 0xc) + local_7c;
      local_54 = *(float *)(iVar2 + 0x10) + local_78;
      local_68 = *(float *)(gpGlobals + 0x40) * -1.0;
      local_64 = *(float *)(gpGlobals + 0x44) * -1.0;
      local_84 = *(float *)(gpGlobals + 0x48) * -1.0;
      local_60 = local_84;
      InitializePlane__6CPlaneRC6VectorT1(local_30,gpGlobals + 0x40,&local_50);
      InitializePlane__6CPlaneRC6VectorT1(local_44,&local_68,&local_5c);
      InitializePlane__6CPlaneRC6VectorT1(local_1c,gpGlobals + 0x28,*local_4 + 8);
      piVar4 = (int *)__opP11CBaseEntity__7EHANDLE(local_4 + 0x187);
      piVar7 = local_4;
      if (piVar4 != (int *)0x0) {
        piVar7 = piVar4;
      }
      piVar4 = (int *)__opP11CBaseEntity__7EHANDLE(piVar7 + 0x189);
      if ((((piVar4 == (int *)0x0) || (piVar4 == local_4)) ||
          (iVar2 = PointInFront__6CPlaneRC6Vector(local_1c,*piVar4 + 8), iVar2 == 0)) ||
         ((iVar2 = PointInFront__6CPlaneRC6Vector(local_30,*piVar4 + 8), iVar2 == 0 ||
          (iVar2 = PointInFront__6CPlaneRC6Vector(local_44,*piVar4 + 8), iVar2 == 0)))) {
        piVar4 = piVar7 + 0x18b;
        iVar2 = 1;
        do {
          piVar6 = piVar7;
          if (iVar2 < 4) {
            piVar6 = (int *)__opP11CBaseEntity__7EHANDLE(piVar4);
          }
          if (((piVar6 != (int *)0x0) && (piVar6 != local_4)) &&
             ((iVar5 = PointInFront__6CPlaneRC6Vector(local_1c,*piVar6 + 8), iVar5 != 0 &&
              ((iVar5 = PointInFront__6CPlaneRC6Vector(local_30,*piVar6 + 8), iVar5 != 0 &&
               (iVar5 = PointInFront__6CPlaneRC6Vector(local_44,*piVar6 + 8), iVar5 != 0))))))
          goto LAB_000e61e8;
          piVar6 = piVar7;
          if (iVar2 + 1 < 4) {
            piVar6 = (int *)__opP11CBaseEntity__7EHANDLE(piVar4 + 2);
          }
          if ((((piVar6 != (int *)0x0) && (piVar6 != local_4)) &&
              (iVar5 = PointInFront__6CPlaneRC6Vector(local_1c,*piVar6 + 8), iVar5 != 0)) &&
             ((iVar5 = PointInFront__6CPlaneRC6Vector(local_30,*piVar6 + 8), iVar5 != 0 &&
              (iVar5 = PointInFront__6CPlaneRC6Vector(local_44,*piVar6 + 8), iVar5 != 0))))
          goto LAB_000e61e8;
          piVar4 = piVar4 + 4;
          iVar2 = iVar2 + 2;
        } while (iVar2 < 5);
        goto LAB_000e6587;
      }
    }
LAB_000e61e8:
    uVar3 = 0;
  }
  return uVar3;
}


