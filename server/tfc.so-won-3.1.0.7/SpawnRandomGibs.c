// SpawnRandomGibs__4CGibP9entvars_sii  @ 000955fc
void SpawnRandomGibs__4CGibP9entvars_sii(int param_1,int param_2,int param_3)

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
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_1c = 0;
  if (0 < param_2) {
    do {
      piVar5 = (int *)GetClassPtr__H1Z4CGib_PX01_PX01(0);
      if (g_Language == 1) {
        pcVar4 = "@models/germangibs.mdl";
LAB_00095672:
        Spawn__4CGibPCc(piVar5,pcVar4 + 1);
        uVar9 = 3;
        uVar8 = 0;
      }
      else {
        if (param_3 == 0) {
          pcVar4 = "?models/agibs.mdl";
          goto LAB_00095672;
        }
        Spawn__4CGibPCc(piVar5,"models/hgibs.mdl");
        uVar9 = 5;
        uVar8 = 1;
      }
      uVar8 = (*DAT_001c1188)(uVar8,uVar9);
      *(undefined4 *)(*piVar5 + 0x114) = uVar8;
      if (param_1 != 0) {
        lVar7 = (longdouble)(*DAT_001c118c)(0,0x3f800000);
        *(float *)(*piVar5 + 8) =
             (float)(lVar7 * (longdouble)*(float *)(param_1 + 0xf4) +
                    (longdouble)*(float *)(param_1 + 0xc4));
        lVar7 = (longdouble)(*DAT_001c118c)(0,0x3f800000);
        *(float *)(*piVar5 + 0xc) =
             (float)(lVar7 * (longdouble)*(float *)(param_1 + 0xf8) +
                    (longdouble)*(float *)(param_1 + 200));
        lVar7 = (longdouble)(*DAT_001c118c)(0,0x3f800000);
        *(float *)(*piVar5 + 0x10) =
             (float)((longdouble)1.0 +
                    lVar7 * (longdouble)*(float *)(param_1 + 0xfc) +
                    (longdouble)*(float *)(param_1 + 0xcc));
        iVar6 = *piVar5;
        local_c = g_vecAttackDir * -1.0;
        local_8 = DAT_001c0ff0 * -1.0;
        local_4 = DAT_001c0ff4 * -1.0;
        *(float *)(iVar6 + 0x20) = local_c;
        *(float *)(iVar6 + 0x24) = local_8;
        *(float *)(iVar6 + 0x28) = local_4;
        lVar7 = (longdouble)(*DAT_001c118c)(0xbe800000,0x3e800000);
        *(float *)(*piVar5 + 0x20) = (float)(lVar7 + (longdouble)*(float *)(*piVar5 + 0x20));
        lVar7 = (longdouble)(*DAT_001c118c)(0xbe800000,0x3e800000);
        *(float *)(*piVar5 + 0x24) = (float)(lVar7 + (longdouble)*(float *)(*piVar5 + 0x24));
        lVar7 = (longdouble)(*DAT_001c118c)(0xbe800000,0x3e800000);
        *(float *)(*piVar5 + 0x28) = (float)(lVar7 + (longdouble)*(float *)(*piVar5 + 0x28));
        iVar6 = *piVar5;
        lVar7 = (longdouble)(*DAT_001c118c)(0x43960000,0x43c80000);
        iVar2 = *piVar5;
        local_c = (float)(lVar7 * (longdouble)*(float *)(iVar2 + 0x20));
        local_8 = (float)(lVar7 * (longdouble)*(float *)(iVar2 + 0x24));
        local_4 = (float)(lVar7 * (longdouble)*(float *)(iVar2 + 0x28));
        *(float *)(iVar6 + 0x20) = local_c;
        *(float *)(iVar6 + 0x24) = local_8;
        *(float *)(iVar6 + 0x28) = local_4;
        lVar7 = (longdouble)(*DAT_001c118c)(0x42c80000,0x43480000);
        *(float *)(*piVar5 + 0x5c) = (float)lVar7;
        lVar7 = (longdouble)(*DAT_001c118c)(0x42c80000,0x43960000);
        *(float *)(*piVar5 + 0x60) = (float)lVar7;
        iVar6 = *(int *)(param_1 + 0x208);
        if ((iVar6 == 0) && (iVar6 = (*DAT_001c1134)(0), iVar6 == 0)) {
          iVar6 = 0;
        }
        else {
          iVar6 = *(int *)(iVar6 + 0x7c);
        }
        iVar6 = (**(code **)(*(int *)(iVar6 + 0x444) + 0x44))(iVar6);
        piVar5[0x112] = iVar6;
        if (*(float *)(param_1 + 0x160) <= -50.0) {
          if (*(float *)(param_1 + 0x160) <= -200.0) {
            iVar6 = *piVar5;
            fVar1 = 4.0;
            goto LAB_000958fb;
          }
          iVar6 = *piVar5;
          local_c = *(float *)(iVar6 + 0x20) + *(float *)(iVar6 + 0x20);
          fVar3 = *(float *)(iVar6 + 0x24) + *(float *)(iVar6 + 0x24);
          fVar1 = *(float *)(iVar6 + 0x28) + *(float *)(iVar6 + 0x28);
        }
        else {
          iVar6 = *piVar5;
          fVar1 = 0.7;
LAB_000958fb:
          local_c = *(float *)(iVar6 + 0x20) * fVar1;
          fVar3 = *(float *)(iVar6 + 0x24) * fVar1;
          fVar1 = fVar1 * *(float *)(iVar6 + 0x28);
        }
        *(float *)(iVar6 + 0x20) = local_c;
        *(float *)(iVar6 + 0x24) = fVar3;
        *(float *)(iVar6 + 0x28) = fVar1;
        *(undefined4 *)(*piVar5 + 0x10c) = 2;
        local_c = 0.0;
        local_8 = 0.0;
        local_4 = 0.0;
        local_18 = 0;
        local_14 = 0;
        local_10 = 0;
        UTIL_SetSize__FP9entvars_sRC6VectorT1(*piVar5,&local_18,&local_c);
      }
      LimitVelocity__4CGib(piVar5);
      local_1c = local_1c + 1;
    } while (local_1c < param_2);
  }
  return;
}


