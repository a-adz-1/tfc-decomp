// SpawnRandomGibs__4CGibP9entvars_tii  @ 000a42a0
void SpawnRandomGibs__4CGibP9entvars_tii(int param_1,int param_2,int param_3)

{
  float fVar1;
  int iVar2;
  float fVar3;
  char *pcVar4;
  int *piVar5;
  int iVar6;
  longdouble lVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_20 = 0;
  do {
    if (param_2 <= local_20) {
      return;
    }
    piVar5 = (int *)GetClassPtr__H1Z4CGib_PX01_PX01(0);
    if (g_Language == 1) {
      pcVar4 = "@models/germangibs.mdl";
LAB_000a4305:
      Spawn__4CGibPCc(piVar5,pcVar4 + 1);
      uVar9 = 3;
      uVar8 = 0;
    }
    else {
      if (param_3 == 0) {
        pcVar4 = "@models/agibs.mdl";
        goto LAB_000a4305;
      }
      Spawn__4CGibPCc(piVar5,"models/hgibs.mdl");
      uVar9 = 5;
      uVar8 = 1;
    }
    uVar8 = (*DAT_00175628)(uVar8,uVar9);
    *(undefined4 *)(*piVar5 + 0xf4) = uVar8;
    if (param_1 != 0) {
      lVar7 = (longdouble)(*DAT_0017562c)(0,0x3f800000);
      *(float *)(*piVar5 + 8) =
           (float)(lVar7 * (longdouble)*(float *)(param_1 + 0xd4) +
                  (longdouble)*(float *)(param_1 + 0xa4));
      lVar7 = (longdouble)(*DAT_0017562c)(0,0x3f800000);
      *(float *)(*piVar5 + 0xc) =
           (float)(lVar7 * (longdouble)*(float *)(param_1 + 0xd8) +
                  (longdouble)*(float *)(param_1 + 0xa8));
      lVar7 = (longdouble)(*DAT_0017562c)(0,0x3f800000);
      *(float *)(*piVar5 + 0x10) =
           (float)((longdouble)1 +
                  lVar7 * (longdouble)*(float *)(param_1 + 0xdc) +
                  (longdouble)*(float *)(param_1 + 0xac));
      iVar6 = *piVar5;
      local_10 = g_vecAttackDir * -1.0;
      local_c = DAT_00175490 * -1.0;
      local_8 = DAT_00175494 * -1.0;
      *(float *)(iVar6 + 0x20) = local_10;
      *(float *)(iVar6 + 0x24) = local_c;
      *(float *)(iVar6 + 0x28) = local_8;
      lVar7 = (longdouble)(*DAT_0017562c)(0xbe800000,0x3e800000);
      *(float *)(*piVar5 + 0x20) = (float)(lVar7 + (longdouble)*(float *)(*piVar5 + 0x20));
      lVar7 = (longdouble)(*DAT_0017562c)(0xbe800000,0x3e800000);
      *(float *)(*piVar5 + 0x24) = (float)(lVar7 + (longdouble)*(float *)(*piVar5 + 0x24));
      lVar7 = (longdouble)(*DAT_0017562c)(0xbe800000,0x3e800000);
      *(float *)(*piVar5 + 0x28) = (float)(lVar7 + (longdouble)*(float *)(*piVar5 + 0x28));
      iVar6 = *piVar5;
      lVar7 = (longdouble)(*DAT_0017562c)(0x43960000,0x43c80000);
      iVar2 = *piVar5;
      local_10 = (float)(lVar7 * (longdouble)*(float *)(iVar2 + 0x20));
      local_c = (float)(lVar7 * (longdouble)*(float *)(iVar2 + 0x24));
      local_8 = (float)(lVar7 * (longdouble)*(float *)(iVar2 + 0x28));
      *(float *)(iVar6 + 0x20) = local_10;
      *(float *)(iVar6 + 0x24) = local_c;
      *(float *)(iVar6 + 0x28) = local_8;
      lVar7 = (longdouble)(*DAT_0017562c)(0x42c80000,0x43480000);
      *(float *)(*piVar5 + 0x5c) = (float)lVar7;
      lVar7 = (longdouble)(*DAT_0017562c)(0x42c80000,0x43960000);
      *(float *)(*piVar5 + 0x60) = (float)lVar7;
      iVar6 = *(int *)(param_1 + 0x1e8);
      if (iVar6 == 0) {
        iVar6 = (*DAT_001755d4)(0);
        if (iVar6 != 0) goto LAB_000a44ac;
        iVar6 = 0;
      }
      else {
LAB_000a44ac:
        iVar6 = *(int *)(iVar6 + 0xd8);
      }
      iVar6 = (**(code **)(*(int *)(iVar6 + 0x3c8) + 0x40))(iVar6);
      piVar5[0xf3] = iVar6;
      fVar1 = *(float *)(param_1 + 0x140);
      if ((byte)(-50.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == -50.0) << 0xe) >> 8)) == 1) {
        iVar6 = *piVar5;
        fVar1 = 0.7;
LAB_000a454b:
        local_10 = *(float *)(iVar6 + 0x20) * fVar1;
        fVar3 = *(float *)(iVar6 + 0x24) * fVar1;
        fVar1 = fVar1 * *(float *)(iVar6 + 0x28);
      }
      else {
        fVar1 = *(float *)(param_1 + 0x140);
        if ((byte)(-200.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                  (byte)((ushort)((ushort)(fVar1 == -200.0) << 0xe) >> 8)) != 1) {
          iVar6 = *piVar5;
          fVar1 = 4.0;
          goto LAB_000a454b;
        }
        iVar6 = *piVar5;
        local_10 = *(float *)(iVar6 + 0x20) + *(float *)(iVar6 + 0x20);
        fVar3 = *(float *)(iVar6 + 0x24) + *(float *)(iVar6 + 0x24);
        fVar1 = *(float *)(iVar6 + 0x28) + *(float *)(iVar6 + 0x28);
      }
      *(float *)(iVar6 + 0x20) = local_10;
      *(float *)(iVar6 + 0x24) = fVar3;
      *(float *)(iVar6 + 0x28) = fVar1;
      *(undefined4 *)(*piVar5 + 0xec) = 2;
      local_10 = 0.0;
      local_c = 0.0;
      local_8 = 0.0;
      local_1c = 0;
      local_18 = 0;
      local_14 = 0;
      UTIL_SetSize__FP9entvars_tRC6VectorT1(*piVar5,&local_1c,&local_10);
    }
    LimitVelocity__4CGib(piVar5);
    local_20 = local_20 + 1;
  } while( true );
}


