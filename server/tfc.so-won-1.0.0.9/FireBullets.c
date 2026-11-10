// FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_t  @ 000c5f40
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FireBullets__11CBaseEntityUlG6VectorN22fiiiP9entvars_t
               (int *param_1,uint param_2,float *param_3,float *param_4,float *param_5,float param_6
               ,int param_7,int param_8,int param_9,int param_10)

{
  float fVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  longdouble lVar6;
  longdouble lVar7;
  longdouble lVar8;
  longdouble lVar9;
  longdouble lVar10;
  int iStack_ec;
  uint uStack_dc;
  int iStack_d8;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  undefined1 auStack_3c [16];
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  int iStack_c;
  
  fStack_48 = *(float *)(gpGlobals + 0x40);
  fStack_44 = *(float *)(gpGlobals + 0x44);
  fStack_40 = *(float *)(gpGlobals + 0x48);
  fStack_54 = *(float *)(gpGlobals + 0x34);
  fStack_50 = *(float *)(gpGlobals + 0x38);
  fStack_4c = *(float *)(gpGlobals + 0x3c);
  iStack_d8 = 0;
  if (param_10 == 0) {
    param_10 = *param_1;
  }
  ClearMultiDamage__Fv();
  DAT_00183028 = 0x1002;
  uStack_dc = 1;
  do {
    if (param_2 < uStack_dc) {
      ApplyMultiDamage__FP9entvars_tT0(*param_1,param_10);
      uVar2 = (undefined1)DAT_00154ce4;
      if (0 < iStack_d8) {
        (*DAT_00175578)(5,0x17,param_3,0);
        (*DAT_00175580)(0x7e);
        (*DAT_00175594)(*param_3);
        (*DAT_00175594)(param_3[1]);
        (*DAT_00175594)(param_3[2]);
        (*DAT_00175594)(*param_4 * 10.0);
        (*DAT_00175594)(param_4[1] * 10.0);
        (*DAT_00175594)(param_4[2] * 10.0);
        (*DAT_00175594)((float)_FUN_00135eb0 * *param_5);
        (*DAT_00175594)((float)_FUN_00135eb0 * param_5[1]);
        (*DAT_00175580)(iStack_d8);
        (*DAT_00175580)(uVar2);
        (*DAT_0017557c)();
      }
      return;
    }
    do {
      lVar6 = (longdouble)(*DAT_0017562c)(0xbf000000,0x3f000000);
      lVar7 = (longdouble)(*DAT_0017562c)(0xbf000000,0x3f000000);
      lVar8 = (longdouble)(*DAT_0017562c)(0xbf000000,0x3f000000);
      lVar9 = (longdouble)(*DAT_0017562c)(0xbf000000,0x3f000000);
      lVar9 = (longdouble)(float)lVar8 + lVar9;
      lVar8 = (longdouble)(float)(lVar7 + (longdouble)(float)lVar6);
      lVar10 = lVar9 * lVar9 + lVar8 * lVar8;
      lVar8 = (longdouble)1;
    } while ((byte)(lVar8 < lVar10 |
                    (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar10)) << 10) >> 8) |
                   (byte)((ushort)((ushort)(lVar8 == lVar10) << 0xe) >> 8)) == 1);
    fVar1 = (float)(lVar7 + (longdouble)(float)lVar6) * *param_5;
    lVar9 = lVar9 * (longdouble)param_5[1];
    fStack_58 = param_4[2] + fVar1 * fStack_40 + (float)(lVar9 * (longdouble)fStack_4c);
    fStack_60 = (float)((longdouble)(*param_4 + fVar1 * fStack_48) + lVar9 * (longdouble)fStack_54);
    fStack_5c = (float)((longdouble)(param_4[1] + fVar1 * fStack_44) + lVar9 * (longdouble)fStack_50
                       );
    fStack_6c = param_6 * fStack_60;
    fStack_68 = param_6 * fStack_5c;
    fStack_64 = param_6 * fStack_58;
    fStack_84 = *param_3 + fStack_6c;
    fStack_80 = param_3[1] + fStack_68;
    fStack_7c = param_3[2] + fStack_64;
    fStack_78 = fStack_84;
    fStack_74 = fStack_80;
    fStack_70 = fStack_7c;
    UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
              (param_3,&fStack_84,0,*(undefined4 *)(*param_1 + 0x1e8),auStack_3c);
    bVar5 = false;
    if ((param_8 != 0) &&
       (iVar3 = tracerCount_789 % param_8, tracerCount_789 = tracerCount_789 + 1, iVar3 == 0)) {
      if ((*(byte *)(*param_1 + 0x184) & 8) == 0) {
        fStack_78 = *param_3;
        fStack_74 = param_3[1];
        fStack_70 = param_3[2];
      }
      else {
        fStack_78 = *param_3 + 0.0 + *(float *)(gpGlobals + 0x40) + *(float *)(gpGlobals + 0x40) +
                    *(float *)(gpGlobals + 0x28) * 16.0;
        fStack_74 = param_3[1] + 0.0 + *(float *)(gpGlobals + 0x44) + *(float *)(gpGlobals + 0x44) +
                    *(float *)(gpGlobals + 0x2c) * 16.0;
        fStack_70 = param_3[2] + -4.0 + *(float *)(gpGlobals + 0x48) + *(float *)(gpGlobals + 0x48)
                    + *(float *)(gpGlobals + 0x30) * 16.0;
        fStack_6c = fStack_78;
        fStack_68 = fStack_74;
        fStack_64 = fStack_70;
      }
      bVar5 = param_8 != 1;
      if (param_7 != 6) {
        (*DAT_00175578)(5,0x17,&fStack_78,0);
        (*DAT_00175580)(6);
        (*DAT_00175594)(fStack_78);
        (*DAT_00175594)(fStack_74);
        (*DAT_00175594)(fStack_70);
        (*DAT_00175594)(fStack_28);
        (*DAT_00175594)(fStack_24);
        (*DAT_00175594)(fStack_20);
        (*DAT_0017557c)();
      }
    }
    if ((byte)(1.0 < fStack_2c | (byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
              (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) == 0x40) goto LAB_000c675e;
    iVar3 = iStack_c;
    if ((iStack_c == 0) && (iVar3 = (*DAT_001755d4)(0), iVar3 == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0xd8);
    }
    if (param_9 != 0) {
      if (1 < param_2) {
        fStack_78 = fStack_60;
        fStack_74 = fStack_5c;
        fStack_70 = fStack_58;
        uVar4 = 0x1002;
        if (0x10 < param_9) {
          uVar4 = 0x2002;
        }
        (**(code **)(*(int *)(iVar3 + 0x3c8) + 0x30))
                  (iVar3,param_10,(float)param_9,&fStack_78,auStack_3c,uVar4);
        iStack_d8 = iStack_d8 + 1;
        goto LAB_000c675e;
      }
      fStack_78 = fStack_60;
      fStack_74 = fStack_5c;
      fStack_70 = fStack_58;
      uVar4 = 0x1002;
      if (0x10 < param_9) {
        uVar4 = 0x2002;
      }
      (**(code **)(*(int *)(iVar3 + 0x3c8) + 0x30))
                (iVar3,param_10,(float)param_9,&fStack_78,auStack_3c,uVar4);
      goto LAB_000c6644;
    }
    switch(param_7) {
    case 0:
      fStack_78 = fStack_60;
      fStack_74 = fStack_5c;
      fStack_70 = fStack_58;
      (**(code **)(*(int *)(iVar3 + 0x3c8) + 0x30))
                (iVar3,param_10,0x42480000,&fStack_78,auStack_3c,0x80);
      fStack_78 = *param_3;
      fStack_74 = param_3[1];
      fStack_70 = param_3[2];
      fStack_6c = fStack_84;
      fStack_68 = fStack_80;
      fStack_64 = fStack_7c;
      TEXTURETYPE_PlaySound__FP11TraceResultG6VectorT1i(auStack_3c,&fStack_78,&fStack_6c,param_7);
      bVar5 = false;
      if ((iStack_c == 0) || (iVar3 = (*DAT_001755d8)(iStack_c), iVar3 == 0)) {
        bVar5 = true;
      }
      if (!bVar5) {
        iVar3 = iStack_c + 0xdc;
        if (iStack_c == 0) {
          iVar3 = 0;
        }
        if (*(int *)(iVar3 + 0x128) != 0) {
          iVar3 = (*DAT_00175628)(0,2);
          UTIL_DecalTrace__FP11TraceResulti(auStack_3c,iVar3 + 0x19);
        }
      }
      break;
    default:
      fStack_78 = fStack_60;
      fStack_74 = fStack_5c;
      fStack_70 = fStack_58;
      FUN_000c661e(auStack_3c,2);
      return;
    case 2:
      fStack_78 = fStack_60;
      fStack_74 = fStack_5c;
      fStack_70 = fStack_58;
      FUN_000c661e(auStack_3c,2);
      return;
    case 3:
      fStack_78 = fStack_60;
      fStack_74 = fStack_5c;
      fStack_70 = fStack_58;
      FUN_000c661e(auStack_3c,2);
      return;
    case 4:
      fStack_78 = fStack_60;
      fStack_74 = fStack_5c;
      fStack_70 = fStack_58;
      (**(code **)(*(int *)(iVar3 + 0x3c8) + 0x30))
                (iVar3,param_10,_DAT_00177a7c,&fStack_78,auStack_3c,2);
      if (!bVar5) {
        DecalGunshot__FP11TraceResulti(auStack_3c,param_7);
      }
      break;
    case 8:
      iStack_ec = *(int *)(iVar3 + 0x3c8);
      uVar4 = _DAT_00177aa8;
      goto LAB_000c65ce;
    case 9:
      iStack_ec = *(int *)(iVar3 + 0x3c8);
      uVar4 = _DAT_00177aac;
LAB_000c65ce:
      fStack_70 = fStack_58;
      fStack_74 = fStack_5c;
      fStack_78 = fStack_60;
      (**(code **)(iStack_ec + 0x30))(iVar3,param_10,uVar4,&fStack_78,auStack_3c,2);
LAB_000c6644:
      fStack_78 = *param_3;
      fStack_74 = param_3[1];
      fStack_70 = param_3[2];
      fStack_6c = fStack_84;
      fStack_68 = fStack_80;
      fStack_64 = fStack_7c;
      TEXTURETYPE_PlaySound__FP11TraceResultG6VectorT1i(auStack_3c,&fStack_78,&fStack_6c,param_7);
      DecalGunshot__FP11TraceResulti(auStack_3c,param_7);
      break;
    case 10:
      fStack_78 = fStack_60;
      fStack_74 = fStack_5c;
      fStack_70 = fStack_58;
      (**(code **)(*(int *)(iVar3 + 0x3c8) + 0x30))
                (iVar3,param_10,_DAT_00177ab0,&fStack_78,auStack_3c,2);
      if (!bVar5) goto LAB_000c6644;
    }
LAB_000c675e:
    if (uStack_dc == 1) {
      fStack_78 = *param_3;
      fStack_74 = param_3[1];
      fStack_70 = param_3[2];
      fStack_6c = fStack_28;
      fStack_68 = fStack_24;
      fStack_64 = fStack_20;
      UTIL_BubbleTrail__FG6VectorT0i
                (&fStack_78,&fStack_6c,(int)ROUND(param_6 * fStack_2c * 0.00390625));
    }
    uStack_dc = uStack_dc + 1;
  } while( true );
}


