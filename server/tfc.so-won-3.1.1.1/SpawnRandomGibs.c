// SpawnRandomGibs__4CGibP9entvars_sii  @ 00095270
void SpawnRandomGibs__4CGibP9entvars_sii(int param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  longdouble lVar6;
  undefined4 uVar7;
  undefined4 uVar8;
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
    piVar4 = (int *)GetClassPtr__H1Z4CGib_PX01_PX01(0);
    if (g_Language == 1) {
      pcVar3 = "@models/germangibs.mdl";
LAB_000952da:
      Spawn__4CGibPCc(piVar4,pcVar3 + 1);
      uVar8 = 3;
      uVar7 = 0;
    }
    else {
      if (param_3 == 0) {
        pcVar3 = "@models/agibs.mdl";
        goto LAB_000952da;
      }
      Spawn__4CGibPCc(piVar4,"models/hgibs.mdl");
      uVar8 = 5;
      uVar7 = 1;
    }
    uVar7 = (*DAT_0019f808)(uVar7,uVar8);
    *(undefined4 *)(*piVar4 + 0x114) = uVar7;
    if (param_1 != 0) {
      lVar6 = (longdouble)(*DAT_0019f80c)(0,0x3f800000);
      *(float *)(*piVar4 + 8) =
           (float)(lVar6 * (longdouble)*(float *)(param_1 + 0xf4) +
                  (longdouble)*(float *)(param_1 + 0xc4));
      lVar6 = (longdouble)(*DAT_0019f80c)(0,0x3f800000);
      *(float *)(*piVar4 + 0xc) =
           (float)(lVar6 * (longdouble)*(float *)(param_1 + 0xf8) +
                  (longdouble)*(float *)(param_1 + 200));
      lVar6 = (longdouble)(*DAT_0019f80c)(0,0x3f800000);
      *(float *)(*piVar4 + 0x10) =
           (float)((longdouble)1 +
                  lVar6 * (longdouble)*(float *)(param_1 + 0xfc) +
                  (longdouble)*(float *)(param_1 + 0xcc));
      iVar5 = *piVar4;
      local_10 = -g_vecAttackDir;
      local_c = -DAT_0019f670;
      local_8 = -DAT_0019f674;
      *(float *)(iVar5 + 0x20) = local_10;
      *(float *)(iVar5 + 0x24) = local_c;
      *(float *)(iVar5 + 0x28) = local_8;
      lVar6 = (longdouble)(*DAT_0019f80c)(0xbe800000,0x3e800000);
      *(float *)(*piVar4 + 0x20) = (float)(lVar6 + (longdouble)*(float *)(*piVar4 + 0x20));
      lVar6 = (longdouble)(*DAT_0019f80c)(0xbe800000,0x3e800000);
      *(float *)(*piVar4 + 0x24) = (float)(lVar6 + (longdouble)*(float *)(*piVar4 + 0x24));
      lVar6 = (longdouble)(*DAT_0019f80c)(0xbe800000,0x3e800000);
      *(float *)(*piVar4 + 0x28) = (float)(lVar6 + (longdouble)*(float *)(*piVar4 + 0x28));
      iVar5 = *piVar4;
      lVar6 = (longdouble)(*DAT_0019f80c)(0x43960000,0x43c80000);
      local_10 = (float)((longdouble)*(float *)(*piVar4 + 0x20) * lVar6);
      local_c = (float)((longdouble)*(float *)(*piVar4 + 0x24) * lVar6);
      local_8 = (float)(lVar6 * (longdouble)*(float *)(*piVar4 + 0x28));
      *(float *)(iVar5 + 0x20) = local_10;
      *(float *)(iVar5 + 0x24) = local_c;
      *(float *)(iVar5 + 0x28) = local_8;
      lVar6 = (longdouble)(*DAT_0019f80c)(0x42c80000,0x43480000);
      *(float *)(*piVar4 + 0x5c) = (float)lVar6;
      lVar6 = (longdouble)(*DAT_0019f80c)(0x42c80000,0x43960000);
      *(float *)(*piVar4 + 0x60) = (float)lVar6;
      iVar5 = *(int *)(param_1 + 0x208);
      if (iVar5 == 0) {
        iVar5 = (*DAT_0019f7b4)(0);
        if (iVar5 != 0) goto LAB_000954dd;
        iVar5 = 0;
      }
      else {
LAB_000954dd:
        iVar5 = *(int *)(iVar5 + 0x7c);
      }
      iVar5 = (**(code **)(*(int *)(iVar5 + 0x454) + 0x44))(iVar5);
      piVar4[0x116] = iVar5;
      fVar1 = *(float *)(param_1 + 0x160);
      if ((byte)((fVar1 < -50.0 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar1 == -50.0) << 0xe) >> 8)) - 1) < 0x40) {
        if (fVar1 <= -200.0) {
          iVar5 = *piVar4;
          fVar1 = 4.0;
          goto LAB_00095563;
        }
        iVar5 = *piVar4;
        local_10 = *(float *)(iVar5 + 0x20) + *(float *)(iVar5 + 0x20);
        fVar2 = *(float *)(iVar5 + 0x24) + *(float *)(iVar5 + 0x24);
        fVar1 = *(float *)(iVar5 + 0x28) + *(float *)(iVar5 + 0x28);
      }
      else {
        iVar5 = *piVar4;
        fVar1 = 0.7;
LAB_00095563:
        local_10 = *(float *)(iVar5 + 0x20) * fVar1;
        fVar2 = *(float *)(iVar5 + 0x24) * fVar1;
        fVar1 = fVar1 * *(float *)(iVar5 + 0x28);
      }
      *(float *)(iVar5 + 0x20) = local_10;
      *(float *)(iVar5 + 0x24) = fVar2;
      *(float *)(iVar5 + 0x28) = fVar1;
      *(undefined4 *)(*piVar4 + 0x10c) = 2;
      local_10 = 0.0;
      local_c = 0.0;
      local_8 = 0.0;
      local_1c = 0;
      local_18 = 0;
      local_14 = 0;
      UTIL_SetSize__FP9entvars_sRC6VectorT1(*piVar4,&local_1c,&local_10);
    }
    LimitVelocity__4CGib(piVar4);
    local_20 = local_20 + 1;
  } while( true );
}


