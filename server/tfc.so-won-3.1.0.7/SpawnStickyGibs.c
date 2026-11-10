// SpawnStickyGibs__4CGibP9entvars_sG6Vectori  @ 00094e88
void SpawnStickyGibs__4CGibP9entvars_sG6Vectori(int param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  longdouble lVar7;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if ((g_Language != 1) && (iVar6 = 0, 0 < param_3)) {
    do {
      piVar3 = (int *)GetClassPtr__H1Z4CGib_PX01_PX01(0);
      Spawn__4CGibPCc(piVar3,"models/stickygib.mdl");
      uVar4 = (*DAT_001c1188)(0,2);
      *(undefined4 *)(*piVar3 + 0x114) = uVar4;
      if (param_1 != 0) {
        lVar7 = (longdouble)(*DAT_001c118c)(0xc0400000,0x40400000);
        *(float *)(*piVar3 + 8) = (float)(lVar7 + (longdouble)*param_2);
        lVar7 = (longdouble)(*DAT_001c118c)(0xc0400000,0x40400000);
        *(float *)(*piVar3 + 0xc) = (float)(lVar7 + (longdouble)param_2[1]);
        lVar7 = (longdouble)(*DAT_001c118c)(0xc0400000,0x40400000);
        *(float *)(*piVar3 + 0x10) = (float)(lVar7 + (longdouble)param_2[2]);
        iVar5 = *piVar3;
        local_c = g_vecAttackDir * -1.0;
        local_8 = DAT_001c0ff0 * -1.0;
        local_4 = DAT_001c0ff4 * -1.0;
        *(float *)(iVar5 + 0x20) = local_c;
        *(float *)(iVar5 + 0x24) = local_8;
        *(float *)(iVar5 + 0x28) = local_4;
        lVar7 = (longdouble)(*DAT_001c118c)(0xbe19999a,0x3e19999a);
        *(float *)(*piVar3 + 0x20) = (float)(lVar7 + (longdouble)*(float *)(*piVar3 + 0x20));
        lVar7 = (longdouble)(*DAT_001c118c)(0xbe19999a,0x3e19999a);
        *(float *)(*piVar3 + 0x24) = (float)(lVar7 + (longdouble)*(float *)(*piVar3 + 0x24));
        lVar7 = (longdouble)(*DAT_001c118c)(0xbe19999a,0x3e19999a);
        *(float *)(*piVar3 + 0x28) = (float)(lVar7 + (longdouble)*(float *)(*piVar3 + 0x28));
        iVar5 = *piVar3;
        local_c = *(float *)(iVar5 + 0x20) * 900.0;
        local_8 = *(float *)(iVar5 + 0x24) * 900.0;
        local_4 = *(float *)(iVar5 + 0x28) * 900.0;
        *(float *)(iVar5 + 0x20) = local_c;
        *(float *)(iVar5 + 0x24) = local_8;
        *(float *)(iVar5 + 0x28) = local_4;
        lVar7 = (longdouble)(*DAT_001c118c)(0x437a0000,0x43c80000);
        *(float *)(*piVar3 + 0x5c) = (float)lVar7;
        lVar7 = (longdouble)(*DAT_001c118c)(0x437a0000,0x43c80000);
        *(float *)(*piVar3 + 0x60) = (float)lVar7;
        iVar5 = *(int *)(param_1 + 0x208);
        if ((iVar5 == 0) && (iVar5 = (*DAT_001c1134)(0), iVar5 == 0)) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(iVar5 + 0x7c);
        }
        iVar5 = (**(code **)(*(int *)(iVar5 + 0x444) + 0x44))(iVar5);
        piVar3[0x112] = iVar5;
        if (*(float *)(param_1 + 0x160) <= -50.0) {
          if (*(float *)(param_1 + 0x160) <= -200.0) {
            iVar5 = *piVar3;
            fVar1 = 4.0;
            goto LAB_00095167;
          }
          iVar5 = *piVar3;
          local_c = *(float *)(iVar5 + 0x20) + *(float *)(iVar5 + 0x20);
          fVar2 = *(float *)(iVar5 + 0x24) + *(float *)(iVar5 + 0x24);
          fVar1 = *(float *)(iVar5 + 0x28) + *(float *)(iVar5 + 0x28);
        }
        else {
          iVar5 = *piVar3;
          fVar1 = 0.7;
LAB_00095167:
          local_c = *(float *)(iVar5 + 0x20) * fVar1;
          fVar2 = *(float *)(iVar5 + 0x24) * fVar1;
          fVar1 = fVar1 * *(float *)(iVar5 + 0x28);
        }
        *(float *)(iVar5 + 0x20) = local_c;
        *(float *)(iVar5 + 0x24) = fVar2;
        *(float *)(iVar5 + 0x28) = fVar1;
        *(undefined4 *)(*piVar3 + 0x108) = 6;
        *(undefined4 *)(*piVar3 + 0x10c) = 2;
        local_c = 0.0;
        local_8 = 0.0;
        local_4 = 0.0;
        local_18 = 0;
        local_14 = 0;
        local_10 = 0;
        UTIL_SetSize__FP9entvars_sRC6VectorT1(*piVar3,&local_18,&local_c);
        piVar3[5] = -0x10000;
        piVar3[6] = (int)StickyGibTouch__4CGibP11CBaseEntity;
        piVar3[3] = 0;
        piVar3[4] = 0;
      }
      LimitVelocity__4CGib(piVar3);
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_3);
  }
  return;
}


