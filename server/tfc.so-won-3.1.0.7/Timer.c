// Timer_AutokickThink__11CBaseEntity  @ 00105428
void Timer_AutokickThink__11CBaseEntity(int *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001c1134)(0);
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_00105466;
    }
  }
  iVar1 = *(int *)(iVar1 + 0x7c);
LAB_00105466:
  *(undefined4 *)(iVar1 + 0x1f8) = 0;
  dremove__FP11CBaseEntity(param_1);
  return;
}


// Timer_Birthday__11CBaseEntity  @ 00103f00
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Timer_Birthday__11CBaseEntity(int *param_1)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  code *pcVar4;
  undefined4 uVar5;
  int *piVar6;
  longdouble lVar7;
  longdouble lVar8;
  undefined4 uVar9;
  
  if (5 < param_1[0x23]) {
    param_1[0x23] = 0;
    lVar7 = (longdouble)(*DAT_001c118c)(0x43340000,0x43700000);
    *(float *)(*param_1 + 0x104) = (float)(lVar7 + (longdouble)*gpGlobals);
    lVar7 = (longdouble)(*DAT_001c118c)(0,0x3f800000);
    lVar8 = (longdouble)0.02;
    if ((byte)((lVar8 < lVar7 | (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7)) << 10) >> 8) |
               (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >> 8)) - 1) < 0x40) {
      lVar8 = (longdouble)0.04;
      if (0x3f < (byte)((lVar8 < lVar7 |
                         (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7)) << 10) >> 8) |
                        (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >> 8)) - 1)) {
        lVar7 = (longdouble)(*DAT_001c118c)(0x447a0000,0x459c4000);
        iVar2 = UTIL_VarArgs__FPce("\n\n\n\nCurrent number of Snipers on\nthe Battlements Worldwide: %d\n"
                                   ,(double)lVar7);
        param_1[0xb5] = iVar2 - (int)gpGlobals[0x26];
        FUN_001049d4();
        return;
      }
      lVar8 = (longdouble)0.06;
      if ((byte)((lVar8 < lVar7 | (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >> 8)) - 1) < 0x40) {
        lVar8 = (longdouble)_FUN_00151370;
        if ((byte)((lVar8 < lVar7 | (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >> 8)) - 1) < 0x40) {
          lVar8 = (longdouble)0.1;
          if ((byte)((lVar8 < lVar7 |
                      (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >> 8)) - 1) < 0x40) {
            lVar8 = (longdouble)0.12;
            if ((byte)((lVar8 < lVar7 |
                        (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >> 8)) - 1) < 0x40) {
              lVar8 = (longdouble)0.14;
              if ((byte)((lVar8 < lVar7 |
                          (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >> 8)) - 1) < 0x40) {
                lVar8 = (longdouble)0.16;
                if ((byte)((lVar8 < lVar7 |
                            (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7)) << 10) >> 8) |
                           (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >> 8)) - 1) < 0x40) {
                  lVar8 = (longdouble)0.18;
                  if ((byte)((lVar8 < lVar7 |
                              (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7)) << 10) >> 8) |
                             (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >> 8)) - 1) < 0x40) {
                    lVar8 = (longdouble)_FUN_001513a0;
                    if ((byte)((lVar8 < lVar7 |
                                (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7)) << 10) >> 8) |
                               (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >> 8)) - 1) < 0x40)
                    {
                      lVar8 = (longdouble)0.22;
                      if ((byte)((lVar8 < lVar7 |
                                  (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7)) << 10) >> 8) |
                                 (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >> 8)) - 1) < 0x40
                         ) {
                        lVar8 = (longdouble)0.24;
                        if ((byte)((lVar8 < lVar7 |
                                    (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7)) << 10) >> 8)
                                   | (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >> 8)) - 1) <
                            0x40) {
                          lVar8 = (longdouble)0.25;
                          if ((byte)((lVar8 < lVar7 |
                                      (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7)) << 10) >> 8
                                            ) |
                                     (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >> 8)) - 1) <
                              0x40) {
                            lVar8 = (longdouble)0.26;
                            if ((byte)((lVar8 < lVar7 |
                                        (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7)) << 10) >>
                                              8) |
                                       (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >> 8)) - 1)
                                < 0x40) {
                              lVar8 = (longdouble)0.28;
                              if ((byte)((lVar8 < lVar7 |
                                          (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7)) << 10)
                                                >> 8) |
                                         (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >> 8)) - 1
                                        ) < 0x40) {
                                lVar8 = (longdouble)0.3;
                                if ((byte)((lVar8 < lVar7 |
                                            (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7)) << 10
                                                           ) >> 8) |
                                           (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >> 8)) -
                                          1) < 0x40) {
                                  lVar8 = (longdouble)0.32;
                                  if ((byte)((lVar8 < lVar7 |
                                              (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7)) <<
                                                             10) >> 8) |
                                             (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >> 8))
                                            - 1) < 0x40) {
                                    lVar8 = (longdouble)0.34;
                                    if ((byte)((lVar8 < lVar7 |
                                                (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7))
                                                               << 10) >> 8) |
                                               (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >> 8
                                                     )) - 1) < 0x40) {
                                      lVar8 = (longdouble)0.36;
                                      if ((byte)((lVar8 < lVar7 |
                                                  (byte)((ushort)((ushort)(NAN(lVar8) || NAN(lVar7))
                                                                 << 10) >> 8) |
                                                 (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe) >>
                                                       8)) - 1) < 0x40) {
                                        lVar8 = (longdouble)_FUN_001513f0;
                                        if ((byte)((lVar8 < lVar7 |
                                                    (byte)((ushort)((ushort)(NAN(lVar8) ||
                                                                            NAN(lVar7)) << 10) >> 8)
                                                   | (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe
                                                                    ) >> 8)) - 1) < 0x40) {
                                          lVar8 = (longdouble)0.4;
                                          if ((byte)((lVar8 < lVar7 |
                                                      (byte)((ushort)((ushort)(NAN(lVar8) ||
                                                                              NAN(lVar7)) << 10) >>
                                                            8) |
                                                     (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe
                                                                    ) >> 8)) - 1) < 0x40) {
                                            lVar8 = (longdouble)0.42;
                                            if ((byte)((lVar8 < lVar7 |
                                                        (byte)((ushort)((ushort)(NAN(lVar8) ||
                                                                                NAN(lVar7)) << 10)
                                                              >> 8) |
                                                       (byte)((ushort)((ushort)(lVar8 == lVar7) <<
                                                                      0xe) >> 8)) - 1) < 0x40) {
                                              lVar8 = (longdouble)0.44;
                                              if ((byte)((lVar8 < lVar7 |
                                                          (byte)((ushort)((ushort)(NAN(lVar8) ||
                                                                                  NAN(lVar7)) << 10)
                                                                >> 8) |
                                                         (byte)((ushort)((ushort)(lVar8 == lVar7) <<
                                                                        0xe) >> 8)) - 1) < 0x40) {
                                                lVar8 = (longdouble)0.46;
                                                if ((byte)((lVar8 < lVar7 |
                                                            (byte)((ushort)((ushort)(NAN(lVar8) ||
                                                                                    NAN(lVar7)) <<
                                                                           10) >> 8) |
                                                           (byte)((ushort)((ushort)(lVar8 == lVar7)
                                                                          << 0xe) >> 8)) - 1) < 0x40
                                                   ) {
                                                  lVar8 = (longdouble)0.48;
                                                  if ((byte)((lVar8 < lVar7 |
                                                              (byte)((ushort)((ushort)(NAN(lVar8) ||
                                                                                      NAN(lVar7)) <<
                                                                             10) >> 8) |
                                                             (byte)((ushort)((ushort)(lVar8 == lVar7
                                                                                     ) << 0xe) >> 8)
                                                             ) - 1) < 0x40) {
                                                    lVar8 = (longdouble)_FUN_00151420;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.52;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.54;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.56;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.58;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.6;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.62;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.64;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.66;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.68;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)_FUN_00151470;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.72;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.74;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.76;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.78;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.8;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)_FUN_001514a0;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.84;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.86;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.88;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.9;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.92;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.94;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.96;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar8 = (longdouble)0.98;
                                                    if ((byte)((lVar8 < lVar7 |
                                                                (byte)((ushort)((ushort)(NAN(lVar8)
                                                                                        || NAN(lVar7
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar8 == lVar7) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    pcVar3 = 
                                                  "\n\n\n\n\"MJ: Did you hear John Cash wrote TF?\"\n   - VomitGod"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF\'s original design docs!\nCheck it out!\nwww.teamfortress.com/files/teamfortress/tfdes_2.gif"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF\'s original design docs!\nCheck it out!\nwww.teamfortress.com/files/teamfortress/tfdes_1.gif"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Veteran Quote #10:\nWhy is that guy running\nout of our yard with\nthe flag???\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Veteran Quote #9:\nI was typing!!\n";
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Veteran Quote #8:\nSpy\'s, please change colors\noutside our base.\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Veteran Quote #7:\nGet a mask or\nget in the WATER!!\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Veteran Quote #6:\nDamn Snipers!\n";
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Veteran Quote #5:\nDamn Snipers!\n";
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Veteran Quote #4:\nDISCARD!!\n";
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Veteran Quote #3:\nWho the hell is on\nthe lift?\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Veteran Quote #2:\nGuys could you NOT set up\nsentries in Hunted?\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Veteran Quote #1:\nUm, Red Medics, please don\'t\nheal the Hunted.\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Newbie Quote #10:\nWhat\'s this key? I thought this\nwas a CTF style map, guys?\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Newbie Quote #9:\nStop shooting me!\nI\'m on your team!\nYou tried to attack my with the axe!\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Newbie Quote #8:\nWho\'s the maniac with the axe?\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Newbie Quote #7:\nWhy the hell are these backpacks\nexploding?\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Newbie Quote #6:\nWhere\'s the control room?\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Newbie Quote #5:\nWhere do I take the flag!?!?!\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Newbie Quote #4:\nHow do I throw the pins?\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Newbie Quote #3:\nHey, he is cheating, that soldier just jumped up to the roof!!\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Newbie Quote #2:\nUmm... How do I throw a grenade?\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nTF Newbie Quote #1:\nUmm... How do I set a detpack?\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nI remember the good ol\' days...\nwhen  Ian went to jail for punching\nRobin out\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nI remember the good ol\' days...\nwhen the motion detector was officially\nthe Scout\'s best friend, at least\naccording to the readme.txt\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nI remember the good ol\' days...\nwhen The Well actually had a well...\n"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "\n\n\n\nI remember the good ol\' days...\nwhen players used to say\n\"What\'s that bubble?\"\n"
                                                  ;
                                                  }
                                                }
                                                else {
                                                  pcVar3 = 
                                                  "\n\n\n\nI remember the good ol\' days...\nwhen I didn\'t have to download\nANYTHING to play TF\n"
                                                  ;
                                                }
                                              }
                                              else {
                                                pcVar3 = 
                                                "\n\n\n\nI remember the good ol\' days...\nwhen I could download TF in\n1 minute 20 seconds\n"
                                                ;
                                              }
                                            }
                                            else {
                                              pcVar3 = 
                                              "\n\n\n\nI remember the good ol\' days...\nwhen the sniper rifle just\nkilled in one hit... everytime\n"
                                              ;
                                            }
                                          }
                                          else {
                                            pcVar3 = 
                                            "\n\n\n\nI remember the good ol\' days...\nwhen 2fort was the only TF map.\nWe sure have come a long\nway since then... sigh"
                                            ;
                                          }
                                        }
                                        else {
                                          pcVar3 = 
                                          "\n\n\n\nI remember the good ol\' days...\nwhen no-one knew how to use\nhand grenades...\n"
                                          ;
                                        }
                                      }
                                      else {
                                        pcVar3 = 
                                        "\n\n\n\nI remember the good ol\' days...\nwhen there were 2 TF servers...\nand they were always down."
                                        ;
                                      }
                                    }
                                    else {
                                      pcVar3 = 
                                      "\n\n\n\nI remember the good ol\' days...\nwhen you had to use imin1 & imin2\nto join a team.\n"
                                      ;
                                    }
                                  }
                                  else {
                                    pcVar3 = 
                                    "\n\n\n\n\"I force them to work.\nElse I cut back their supplies\"\n   - Vomitgod, on TFS\n"
                                    ;
                                  }
                                }
                                else {
                                  pcVar3 = 
                                  "\n\n\n\n\"After all, TF is an INSULT to the\npurity of CTF!\"\n   - Mjollnir, who was joking... really!"
                                  ;
                                }
                              }
                              else {
                                pcVar3 = 
                                "\n\n\n\n\"Twin Peaks will be finished tomorrow.\"\n   - TyR, 16th July, 25th July, 2nd August..."
                                ;
                              }
                            }
                            else {
                              pcVar3 = "\n\n\n\nTwin Peaks will be out... uhh...\nerr... soon.\n";
                            }
                          }
                          else {
                            pcVar3 = 
                            "\n\n\n\nBAH! I shoulda put the Demoman\nblast armor back while I was at it!\n   - Gudlyf\n"
                            ;
                          }
                        }
                        else {
                          pcVar3 = 
                          "\n\n\n\nMany potatoes were harmed in the\nmaking of this product.\n";
                        }
                      }
                      else {
                        pcVar3 = 
                        "\n\n\n\n\"You guys have really screwed up\n urinals, you know that?\"\n   - TyR in Australia\n"
                        ;
                      }
                    }
                    else {
                      pcVar3 = "\n\n\n\nDeath to Potatoes!\n";
                    }
                  }
                  else {
                    pcVar3 = 
                    "\n\n\n\nKill your friends! Kill your family!\nSnipe your pets! Detpack your house!\nGet TF Now!\n"
                    ;
                  }
                }
                else {
                  pcVar3 = "\n\n\n\nhmm.... I wonder what the next\nmessage will be...\n";
                }
              }
              else {
                pcVar3 = "\n\n\n\nTF II available soon!\n";
              }
            }
            else {
              pcVar3 = "\n\n\n\nTeamFortress is one year old today!\n";
            }
          }
          else {
            pcVar3 = "\n\n\n\n25,000 downloads\n50 donations\nDamn, but we rock!\n";
          }
        }
        else {
          pcVar3 = 
          "\n\n\n\nIs that an assault cannon in your\n pocket, or are you just playing TF?\n(Blame Ian)\n"
          ;
        }
      }
      else {
        pcVar3 = "\n\n\n\nYeeha!\nThe 505,672nd detpack was\njust laid on the bridge!\n";
      }
    }
    else if (christmas == 0) {
      pcVar3 = "\n\n\n\nHAPPY BIRTHDAY TEAMFORTRESS!\n";
    }
    else {
      pcVar3 = "\n\n\n\nMERRY CHRISTMAS!!\n";
    }
    param_1[0xb5] = (int)pcVar3 - (int)gpGlobals[0x26];
    FUN_001049d4();
    return;
  }
  *(float *)(*param_1 + 0x104) = *gpGlobals + 1.5;
  param_1[0x23] = param_1[0x23] + 1;
  UTIL_ClientPrintAll__FiPCcN41(4,param_1[0xb5] + (int)gpGlobals[0x26],0,0,0,0);
  piVar6 = (int *)0x0;
LAB_001048cc:
  do {
    piVar6 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar6,"player");
    if (piVar6 == (int *)0x0) {
      return;
    }
    bVar1 = false;
    if ((*(int *)(*piVar6 + 0x208) == 0) ||
       (iVar2 = (*DAT_001c1138)(*(int *)(*piVar6 + 0x208)), iVar2 == 0)) {
      bVar1 = true;
    }
    if (bVar1) {
      return;
    }
  } while ((*piVar6 == 0) || (piVar6[0x1e] != 0));
  if (param_1[0x23] != 1) goto LAB_0010496c;
  if (christmas == 0) {
    uVar5 = *(undefined4 *)(*piVar6 + 0x208);
    pcVar4 = (code *)&UNK_0015132c;
  }
  else {
    uVar5 = *(undefined4 *)(*piVar6 + 0x208);
    pcVar4 = FUN_00151320;
  }
  uVar9 = 2;
  goto LAB_001049c3;
LAB_0010496c:
  if (param_1[0x23] < 5) {
    iVar2 = (*DAT_001c1188)(0,1);
    if (iVar2 == 0) {
      uVar5 = *(undefined4 *)(*piVar6 + 0x208);
      pcVar3 = "misc/party1.wav";
    }
    else {
      uVar5 = *(undefined4 *)(*piVar6 + 0x208);
      pcVar3 = "misc/party2.wav";
    }
    uVar9 = 3;
    pcVar4 = (code *)pcVar3;
LAB_001049c3:
    EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar5,uVar9,pcVar4,0x3f4ccccd3f800000,0,100);
  }
  goto LAB_001048cc;
}


// Timer_CeaseFireThink__11CBaseEntity  @ 001052cc
void Timer_CeaseFireThink__11CBaseEntity(int *param_1)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  
  fVar1 = *gpGlobals;
  if (((0x3f < (byte)((fVar1 < cb_ceasefire_time |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(cb_ceasefire_time)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == cb_ceasefire_time) << 0xe) >> 8)) - 1)) &&
      (param_1[0x23] == 1)) && (cease_fire == 1)) {
    cease_fire = 0;
    UTIL_ClientPrintAll__FiPCcN41(1,"#Game_resumefire",0,0,0,0);
    UTIL_LogPrintf__FPce("World triggered \"Resume_Fire\"\n");
    piVar4 = (int *)0x0;
    while( true ) {
      piVar4 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar4,"player");
      if (piVar4 == (int *)0x0) break;
      bVar2 = false;
      if (*(int *)(*piVar4 + 0x208) == 0) {
LAB_0010538a:
        bVar2 = true;
      }
      else {
        iVar3 = (*DAT_001c1138)(*(int *)(*piVar4 + 0x208));
        if (iVar3 == 0) goto LAB_0010538a;
      }
      if (bVar2) break;
      if (*piVar4 != 0) {
        *(undefined4 *)(*piVar4 + 0x250) = 0;
        piVar4[99] = (int)(*gpGlobals + 10.0);
        *(byte *)((int)piVar4 + 0x86) = *(byte *)((int)piVar4 + 0x86) & 0xfe;
        TeamFortress_SetSpeed__11CBasePlayer(piVar4);
      }
    }
  }
  if (cease_fire == 0) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    UTIL_ClientPrintAll__FiPCcN41(1,"#Game_ceasefire",0,0,0,0);
    UTIL_LogPrintf__FPce("World triggered \"Cease_Fire\"\n");
    *(float *)(*param_1 + 0x104) = *gpGlobals + 5.0;
  }
  return;
}


// Timer_CheckBuildDistance__11CBaseEntity  @ 00104eac
void Timer_CheckBuildDistance__11CBaseEntity(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  
  bVar4 = false;
  if ((*(int *)(*param_1 + 0x198) == 0) ||
     (iVar5 = (*DAT_001c1138)(*(int *)(*param_1 + 0x198)), iVar5 == 0)) {
    bVar4 = true;
  }
  if (!bVar4) {
    bVar4 = false;
    if ((*(int *)(*param_1 + 400) == 0) ||
       (iVar5 = (*DAT_001c1138)(*(int *)(*param_1 + 400)), iVar5 == 0)) {
      bVar4 = true;
    }
    if (!bVar4) {
      iVar5 = *(int *)(*param_1 + 0x198);
      if ((iVar5 == 0) && (iVar5 = (*DAT_001c1134)(0), iVar5 == 0)) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = *(int **)(iVar5 + 0x7c);
      }
      iVar5 = *(int *)(*param_1 + 400);
      if ((iVar5 == 0) && (iVar5 = (*DAT_001c1134)(0), iVar5 == 0)) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = *(int **)(iVar5 + 0x7c);
      }
      iVar5 = __opP11CBaseEntity__7EHANDLE(piVar7 + 0x4e);
      if ((iVar5 != 0) &&
         (piVar6 = (int *)__opP11CBaseEntity__7EHANDLE(piVar7 + 0x4e), piVar6 == piVar8)) {
        iVar5 = *piVar8;
        fVar1 = *(float *)(iVar5 + 8) - *(float *)(*piVar7 + 8);
        fVar3 = *(float *)(iVar5 + 0xc) - *(float *)(*piVar7 + 0xc);
        fVar2 = *(float *)(iVar5 + 0x10) - *(float *)(*piVar7 + 0x10);
        if (64.0 < SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1)) {
          ResetMenu__11CBasePlayer(piVar7);
          __as__7EHANDLEP11CBaseEntity(piVar7 + 0x4e,0);
          UTIL_Remove__FP11CBaseEntity(param_1);
          return;
        }
        *(float *)(*param_1 + 0x104) = *gpGlobals + 0.3;
        return;
      }
    }
  }
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


// Timer_DetpackDisarm__11CBaseEntity  @ 00104b44
void Timer_DetpackDisarm__11CBaseEntity(int *param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if ((iVar1 == 0) && (iVar1 = (*DAT_001c1134)(0), iVar1 == 0)) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(iVar1 + 0x7c);
  }
  iVar1 = *(int *)(*param_1 + 400);
  if ((iVar1 == 0) && (iVar1 = (*DAT_001c1134)(0), iVar1 == 0)) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = *(int **)(iVar1 + 0x7c);
  }
  iVar1 = *(int *)(*piVar5 + 0x198);
  if ((iVar1 == 0) && (iVar1 = (*DAT_001c1134)(0), iVar1 == 0)) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = *(int **)(iVar1 + 0x7c);
  }
  iVar1 = (**(code **)(piVar4[0x111] + 0x8c))(piVar4);
  if ((iVar1 == 0) ||
     ((byte)((byte)((ushort)((ushort)NAN((float)piVar5[0x42]) << 10) >> 8) |
            (byte)((ushort)((ushort)((float)piVar5[0x42] == 0.0) << 0xe) >> 8)) == 0x40)) {
    dremove__FP11CBaseEntity(param_1);
  }
  else {
    if (birthday == 1) {
      iVar1 = *(int *)(*piVar6 + 0x1d0) + *(int *)(gpGlobals + 0x98);
      iVar7 = *(int *)(*piVar4 + 0x1d0) + *(int *)(gpGlobals + 0x98);
      pcVar2 = "#Detpack_disarm_bday";
    }
    else {
      iVar1 = *(int *)(*piVar4 + 0x1d0) + *(int *)(gpGlobals + 0x98);
      iVar7 = *(int *)(*piVar6 + 0x1d0) + *(int *)(gpGlobals + 0x98);
      pcVar2 = "#Detpack_disarm";
    }
    UTIL_ClientPrintAll__FiPCcN41(1,pcVar2,iVar7,iVar1,0,0);
    if (piVar4[0x48] == 0) {
      pcVar2 = "SPECTATOR";
    }
    else {
      pcVar2 = (char *)GetTeamName__Fi(piVar4[0x48]);
    }
    uVar3 = (*DAT_001c11f4)(*(undefined4 *)(*piVar4 + 0x208),pcVar2);
    uVar3 = (*DAT_001c11e4)(*(undefined4 *)(*piVar4 + 0x208),uVar3);
    if (piVar6[0x48] == 0) {
      pcVar2 = "SPECTATOR";
    }
    else {
      pcVar2 = (char *)GetTeamName__Fi(piVar6[0x48],
                                       *(int *)(*piVar4 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar3)
      ;
    }
    uVar3 = (*DAT_001c11f4)(*(undefined4 *)(*piVar6 + 0x208),pcVar2);
    uVar3 = (*DAT_001c11e4)(*(undefined4 *)(*piVar6 + 0x208),uVar3);
    UTIL_LogPrintf__FPce
              ("\"%s<%i><%u><%s>\" triggered \"Detpack_Disarmed\" against \"%s<%i><%u><%s>\"\n",
               *(int *)(*piVar6 + 0x1d0) + *(int *)(gpGlobals + 0x98),uVar3);
    *(byte *)((int)piVar4 + 0x86) = *(byte *)((int)piVar4 + 0x86) & 0xfe;
    TeamFortress_SetSpeed__11CBasePlayer(piVar4);
    TF_AddFrags__11CBasePlayeri(piVar4,1);
    dremove__FP11CBaseEntity(piVar5);
    dremove__FP11CBaseEntity(param_1);
  }
  return;
}


// Timer_DetpackSet__11CBaseEntity  @ 001049dc
void Timer_DetpackSet__11CBaseEntity(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001c1134)(0);
    if (iVar1 == 0) {
      piVar2 = (int *)0x0;
      goto LAB_00104a1e;
    }
  }
  piVar2 = *(int **)(iVar1 + 0x7c);
LAB_00104a1e:
  piVar2[0x1b] = 0;
  *(byte *)((int)piVar2 + 0x86) = *(byte *)((int)piVar2 + 0x86) & 0xfe;
  TeamFortress_SetSpeed__11CBasePlayer(piVar2);
  (**(code **)(*(int *)(piVar2[0x22d] + 0x444) + 0x120))(piVar2[0x22d]);
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  piVar3 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                            (FUN_001514f0,*piVar2 + 8,&local_c,*(undefined4 *)(*piVar2 + 0x208));
  *(float *)(*piVar3 + 0x160) = *gpGlobals + *(float *)(*param_1 + 0x160);
  ClientPrint__FP9entvars_siPCcN42(*piVar2,1,"#Detpack_finishset",0,0,0,0);
  if (piVar2[0x48] == 0) {
    pcVar4 = "SPECTATOR";
  }
  else {
    pcVar4 = (char *)GetTeamName__Fi(piVar2[0x48]);
  }
  uVar5 = (*DAT_001c11f4)(*(undefined4 *)(*piVar2 + 0x208),pcVar4);
  uVar5 = (*DAT_001c11e4)(*(undefined4 *)(*piVar2 + 0x208),uVar5);
  UTIL_LogPrintf__FPce(FUN_00151520,*(int *)(*piVar2 + 0x1d0) + (int)gpGlobals[0x26],uVar5);
  dremove__FP11CBaseEntity(param_1);
  return;
}


// Timer_FinishedBuilding__11CBaseEntity  @ 00105074
void Timer_FinishedBuilding__11CBaseEntity(int *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  
  bVar1 = false;
  if ((*(int *)(*param_1 + 0x198) == 0) ||
     (iVar2 = (*DAT_001c1138)(*(int *)(*param_1 + 0x198)), iVar2 == 0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    iVar2 = *(int *)(*param_1 + 0x198);
    if ((iVar2 == 0) && (iVar2 = (*DAT_001c1134)(0), iVar2 == 0)) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = *(int **)(iVar2 + 0x7c);
    }
    EMIT_SOUND_DYN__FP7edict_siPCcffii
              (*(undefined4 *)(*piVar3 + 0x208),6,"weapons/building.wav",0,0,0x20,100);
    if (piVar3[0x1a] == 1) {
      piVar3[0x1a] = 0;
      *(byte *)((int)piVar3 + 0x86) = *(byte *)((int)piVar3 + 0x86) & 0xfe;
      TeamFortress_SetSpeed__11CBasePlayer(piVar3);
      if (piVar3[0x22d] != 0) {
        (**(code **)(*(int *)(piVar3[0x22d] + 0x444) + 0x120))(piVar3[0x22d]);
      }
      piVar3 = piVar3 + 0x4e;
      iVar2 = __opi__7EHANDLE(piVar3);
      if (iVar2 != 0) {
        iVar2 = __rf__7EHANDLE(piVar3);
        (**(code **)(*(int *)(iVar2 + 0x444) + 0xec))(iVar2);
        __as__7EHANDLEP11CBaseEntity(piVar3,0);
      }
    }
    dremove__FP11CBaseEntity(param_1);
    return;
  }
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


// Timer_Hallucination__11CBaseEntity  @ 0010311c
void Timer_Hallucination__11CBaseEntity(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 uVar6;
  short *psVar7;
  int *piVar8;
  short unaff_BP;
  int iVar9;
  longdouble lVar10;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar5 = *(int *)(*param_1 + 0x198);
  if ((iVar5 == 0) && (iVar5 = (*DAT_001c1134)(0), iVar5 == 0)) {
    piVar8 = (int *)0x0;
  }
  else {
    piVar8 = *(int **)(iVar5 + 0x7c);
  }
  local_4 = *(float *)(*param_1 + 0x160) - 2.5;
  *(float *)(*param_1 + 0x160) = local_4;
  if (*(int *)(*piVar8 + 0x20c) == 5) {
    local_4 = *(float *)(*param_1 + 0x160) - 2.5;
    *(float *)(*param_1 + 0x160) = local_4;
  }
  if (((*(float *)(*param_1 + 0x160) <= 0.0) || (*(int *)(*piVar8 + 0x170) != 0)) ||
     (piVar8[0x1e] != 0)) {
    *(byte *)((int)piVar8 + 0x85) = *(byte *)((int)piVar8 + 0x85) & 0xbf;
  }
  if (((*(int *)(*piVar8 + 0x170) != 0) || (piVar8[0x1e] != 0)) ||
     ((*(byte *)((int)piVar8 + 0x85) & 0x40) == 0)) {
    UTIL_Remove__FP11CBaseEntity(param_1);
    return;
  }
  local_4 = *gpGlobals + 0.3;
  *(float *)(*param_1 + 0x104) = local_4;
  uVar6 = (*DAT_001c1188)(0,0x14);
  switch(uVar6) {
  case 0:
    (*DAT_001c10c4)(*(undefined4 *)(*piVar8 + 0x208),"play weapons/cbar_hit1.wav\n");
    break;
  case 1:
    (*DAT_001c10c4)(*(undefined4 *)(*piVar8 + 0x208),"play weapons/cbar_hitbod1.wav\n");
    UTIL_ScreenShakeOne__FP7edict_sfff
              (*(undefined4 *)(*piVar8 + 0x208),0x41400000,0x41200000,0x3f666666);
    break;
  case 2:
    UTIL_MakeVectors__FRC6Vector(*piVar8 + 0x50);
    lVar10 = (longdouble)(*DAT_001c118c)(0x42c80000,0x43960000);
    local_28 = (float)(lVar10 * (longdouble)gpGlobals[10]);
    local_24 = (float)(lVar10 * (longdouble)gpGlobals[0xb]);
    local_20 = (float)(lVar10 * (longdouble)gpGlobals[0xc]);
    iVar5 = *piVar8;
    local_14 = *(float *)(iVar5 + 0x10) + local_20;
    local_1c = (float)((longdouble)*(float *)(iVar5 + 8) + lVar10 * (longdouble)gpGlobals[10]);
    local_18 = (float)((longdouble)*(float *)(iVar5 + 0xc) + lVar10 * (longdouble)gpGlobals[0xb]);
    local_10 = local_1c;
    local_c = local_18;
    local_8 = local_14;
    lVar10 = (longdouble)(*DAT_001c118c)(0xc2c80000,0x42c80000);
    local_1c = (float)(lVar10 * (longdouble)gpGlobals[0x10]);
    local_18 = (float)(lVar10 * (longdouble)gpGlobals[0x11]);
    local_14 = (float)(lVar10 * (longdouble)gpGlobals[0x12]);
    local_20 = local_8 + local_14;
    local_28 = (float)((longdouble)local_10 + lVar10 * (longdouble)gpGlobals[0x10]);
    local_24 = (float)((longdouble)local_c + lVar10 * (longdouble)gpGlobals[0x11]);
    local_10 = local_28;
    local_c = local_24;
    local_8 = local_20;
    (*DAT_001c10d8)(1,0x17,0,*(undefined4 *)(*piVar8 + 0x208));
    (*DAT_001c10e0)(3);
    (*DAT_001c10f4)(local_10);
    (*DAT_001c10f4)(local_c);
    (*DAT_001c10f4)(local_8);
    (*DAT_001c10e8)((int)g_sModelIndexFireball);
    (*DAT_001c10e0)(0x14);
    (*DAT_001c10e0)(0xc);
    (*DAT_001c10e0)(3);
    (*DAT_001c10dc)();
    break;
  case 3:
    UTIL_MakeVectors__FRC6Vector(*piVar8 + 0x50);
    iVar5 = *piVar8;
    local_28 = *(float *)(iVar5 + 8);
    local_24 = *(float *)(iVar5 + 0xc);
    local_20 = *(float *)(iVar5 + 0x10);
    lVar10 = (longdouble)(*DAT_001c118c)(0,0x43000000);
    local_20 = (float)(lVar10 + (longdouble)local_20);
    lVar10 = (longdouble)(*DAT_001c118c)(0xc3000000,0x43000000);
    local_34 = (float)(lVar10 * (longdouble)gpGlobals[0x10]);
    local_30 = (float)(lVar10 * (longdouble)gpGlobals[0x11]);
    local_2c = (float)(lVar10 * (longdouble)gpGlobals[0x12]);
    local_20 = local_20 + local_2c;
    local_28 = (float)((longdouble)local_28 + lVar10 * (longdouble)gpGlobals[0x10]);
    local_24 = (float)((longdouble)local_24 + lVar10 * (longdouble)gpGlobals[0x11]);
    iVar5 = *piVar8;
    fVar1 = *(float *)(iVar5 + 0x20);
    fVar2 = *(float *)(iVar5 + 0x24);
    fVar3 = *(float *)(iVar5 + 0x28);
    local_10 = local_28;
    local_c = local_24;
    local_8 = local_20;
    uVar6 = (*DAT_001c1188)(0,3);
    switch(uVar6) {
    case 0:
      psVar7 = &g_sModelIndexMirvGrenade;
      break;
    case 1:
      psVar7 = &g_sModelIndexGrenade;
      break;
    case 2:
      psVar7 = &g_sModelIndexNapalmGrenade;
      break;
    case 3:
      psVar7 = &g_sModelIndexNailGrenade;
      break;
    default:
      goto LAB_001035f1;
    }
    unaff_BP = *psVar7;
LAB_001035f1:
    iVar5 = UTIL_PointContents__FRC6Vector(&local_28);
    if (iVar5 != -2) {
      iVar5 = *piVar8;
      local_1c = *(float *)(iVar5 + 0x74);
      local_18 = *(float *)(iVar5 + 0x78);
      local_14 = *(float *)(iVar5 + 0x7c);
      lVar10 = (longdouble)(*DAT_001c118c)(0xc2480000,0x42480000);
      lVar10 = (longdouble)UTIL_AngleMod__Ff((float)(lVar10 + (longdouble)local_18));
      local_18 = (float)lVar10;
      UTIL_MakeVectors__FRC6Vector(&local_1c);
      lVar10 = (longdouble)(*DAT_001c118c)(0x43480000,0x43c80000);
      lVar10 = lVar10 + (longdouble)SQRT(fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1);
      local_34 = (float)(lVar10 * (longdouble)gpGlobals[10]);
      local_30 = (float)(lVar10 * (longdouble)gpGlobals[0xb]);
      local_2c = (float)(lVar10 * (longdouble)gpGlobals[0xc]);
      (*DAT_001c10d8)(1,0x17,0,*(undefined4 *)(*piVar8 + 0x208));
      (*DAT_001c10e0)(0x6a);
      (*DAT_001c10f4)(local_28);
      (*DAT_001c10f4)(local_24);
      (*DAT_001c10f4)(local_20);
      (*DAT_001c10f4)(local_34);
      (*DAT_001c10f4)(local_30);
      (*DAT_001c10f4)(local_2c);
      (*DAT_001c10f0)(0);
      (*DAT_001c10e8)((int)unaff_BP);
      (*DAT_001c10e0)(0);
      FUN_00103d9c();
      return;
    }
    break;
  case 4:
    (*DAT_001c10d8)(1,0x17,0,*(undefined4 *)(*piVar8 + 0x208));
    (*DAT_001c10e0)(0x79);
    uVar6 = (*DAT_001c113c)(*(undefined4 *)(*piVar8 + 0x208));
    (*DAT_001c10e8)(uVar6);
    (*DAT_001c10e8)((int)g_sModelIndexPlayerFlame);
    (*DAT_001c10e0)(5);
    (*DAT_001c10e0)(0x19);
    (*DAT_001c10dc)();
    break;
  case 5:
    UTIL_MakeVectors__FRC6Vector(*piVar8 + 0x74);
    gpGlobals[0xc] = 0.0;
    local_40 = gpGlobals[10] * -200.0;
    local_3c = gpGlobals[0xb] * -200.0;
    local_38 = gpGlobals[0xc] * -200.0;
    iVar5 = *piVar8;
    local_34 = *(float *)(iVar5 + 8) + local_40;
    local_30 = *(float *)(iVar5 + 0xc) + local_3c;
    local_2c = *(float *)(iVar5 + 0x10) + local_38;
    local_10 = local_34;
    local_c = local_30;
    local_8 = local_2c;
    lVar10 = (longdouble)(*DAT_001c118c)(0xc2c80000,0x42c80000);
    local_10 = (float)(lVar10 * (longdouble)gpGlobals[0x10]);
    local_c = (float)(lVar10 * (longdouble)gpGlobals[0x11]);
    local_8 = (float)(lVar10 * (longdouble)gpGlobals[0x12]);
    local_38 = local_2c + local_8;
    local_40 = (float)((longdouble)local_34 + lVar10 * (longdouble)gpGlobals[0x10]);
    local_3c = (float)((longdouble)local_30 + lVar10 * (longdouble)gpGlobals[0x11]);
    local_2c = *(float *)(*piVar8 + 0x17c) * 0.8 + local_38;
    local_34 = local_40;
    local_30 = local_3c;
    local_4 = local_2c;
    UTIL_VecToAngles__FRC6Vector(&local_40,gpGlobals + 10);
    local_1c = local_40;
    local_18 = local_3c;
    lVar10 = (longdouble)(*DAT_001c118c)(0xc0c00000,0x40c00000);
    local_1c = (float)(lVar10 + (longdouble)local_1c);
    iVar5 = UTIL_PointContents__FRC6Vector(&local_38);
    if (iVar5 != -2) {
      iVar5 = 0;
      iVar9 = 0;
      do {
        UTIL_MakeVectors__FRC6Vector(&local_20);
        local_3c = (float)(600 - iVar9);
        local_2c = local_3c * gpGlobals[10];
        local_40 = local_3c * gpGlobals[0xb];
        local_3c = local_3c * gpGlobals[0xc];
        local_28 = local_40;
        local_24 = local_3c;
        (*DAT_001c10d8)(1,0x17,0,*(undefined4 *)(*piVar8 + 0x208));
        (*DAT_001c10e0)(0x77);
        (*DAT_001c10f4)(local_38);
        (*DAT_001c10f4)(local_34);
        (*DAT_001c10f4)(local_30);
        (*DAT_001c10f4)(local_2c);
        (*DAT_001c10f4)(local_28);
        (*DAT_001c10f4)(local_24);
        (*DAT_001c10e8)((int)g_sModelIndexNail);
        (*DAT_001c10e0)(6);
        uVar4 = (*DAT_001c113c)(*(undefined4 *)(*piVar8 + 0x208));
        (*DAT_001c10e0)(uVar4);
        (*DAT_001c10dc)();
        lVar10 = (longdouble)(*DAT_001c118c)(0x40800000,0x41000000);
        local_1c = (float)(lVar10 + (longdouble)local_1c);
        lVar10 = (longdouble)(*DAT_001c118c)(0xc1200000,0x41200000);
        local_30 = (float)(lVar10 + (longdouble)local_30);
        iVar9 = iVar9 + 0x14;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 3);
    }
    break;
  case 6:
    iVar5 = *piVar8;
    local_40 = *(float *)(iVar5 + 0x74);
    local_3c = *(float *)(iVar5 + 0x78);
    local_38 = *(float *)(iVar5 + 0x7c);
    lVar10 = (longdouble)(*DAT_001c118c)(0xc1700000,0x41700000);
    local_40 = (float)(lVar10 + (longdouble)local_40);
    lVar10 = (longdouble)(*DAT_001c118c)(0xc2480000,0x42480000);
    local_3c = (float)(lVar10 + (longdouble)local_3c);
    lVar10 = (longdouble)(*DAT_001c118c)(0xc1c80000,0x41c80000);
    local_38 = (float)(lVar10 + (longdouble)local_38);
    UTIL_VecToAngles__FRC6Vector(&local_34,&local_40);
    uVar6 = gDecals._4_4_;
    if (-1 < (int)gDecals._4_4_) {
      (*DAT_001c10c4)(*(undefined4 *)(*piVar8 + 0x208),"play weapons/sbarrel1.wav\n");
      (*DAT_001c10d8)(1,0x17,0,*(undefined4 *)(*piVar8 + 0x208));
      (*DAT_001c10e0)(0x7e);
      (*DAT_001c10f4)(*(undefined4 *)(*piVar8 + 8));
      (*DAT_001c10f4)(*(undefined4 *)(*piVar8 + 0xc));
      (*DAT_001c10f4)(*(undefined4 *)(*piVar8 + 0x10));
      local_8 = local_44 * 10.0;
      (*DAT_001c10f4)(local_8);
      local_8 = local_40 * 10.0;
      (*DAT_001c10f4)(local_8);
      local_8 = local_3c * 10.0;
      (*DAT_001c10f4)(local_8);
      (*DAT_001c10f4)(0x42a00000);
      (*DAT_001c10f4)(0x42a00000);
      (*DAT_001c10e0)(6);
      (*DAT_001c10e0)(uVar6);
      (*DAT_001c10dc)();
    }
  }
  return;
}


// Timer_HealthRot__11CBaseEntity  @ 00102ff8
void Timer_HealthRot__11CBaseEntity(int *param_1)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = *(int *)(*param_1 + 0x198);
  if ((iVar4 == 0) && (iVar4 = (*DAT_001c1134)(0), iVar4 == 0)) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = *(int **)(iVar4 + 0x7c);
  }
  iVar4 = *piVar5;
  fVar1 = *(float *)(iVar4 + 0x160);
  fVar2 = *(float *)(iVar4 + 0x1b0);
  if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
    *(byte *)((int)piVar5 + 0x8a) = *(byte *)((int)piVar5 + 0x8a) & 0xfe;
    bVar3 = false;
    if ((*(int *)(*param_1 + 400) == 0) ||
       (iVar4 = (*DAT_001c1138)(*(int *)(*param_1 + 400)), iVar4 == 0)) {
      bVar3 = true;
    }
    if (!bVar3) {
      iVar4 = *(int *)(*param_1 + 400);
      if ((iVar4 == 0) && (iVar4 = (*DAT_001c1134)(0), iVar4 == 0)) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(iVar4 + 0x7c);
      }
      (**(code **)(*(int *)(iVar4 + 0x444) + 0xc0))(iVar4);
      return;
    }
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
    iVar4 = *param_1;
    fVar1 = *gpGlobals;
  }
  else {
    *(float *)(iVar4 + 0x160) = fVar1 - 1.0;
    iVar4 = *param_1;
    fVar1 = *gpGlobals + 1.0;
  }
  *(float *)(iVar4 + 0x104) = fVar1;
  return;
}


// Timer_Infection__11CBaseEntity  @ 00102824
void Timer_Infection__11CBaseEntity(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  code *pcVar4;
  undefined1 *puVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  char *pcVar9;
  undefined1 *puVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  bool bVar14;
  undefined2 in_FPUControlWord;
  int aiStackY_d0 [10];
  int aiStack_94 [8];
  uint uStack_74;
  byte abStack_70 [8];
  undefined4 auStack_68 [9];
  float afStack_44 [8];
  int aiStack_24 [6];
  undefined4 auStack_c [3];
  
  iVar6 = *(int *)(*param_1 + 0x198);
  if (iVar6 == 0) {
    iVar6 = (*DAT_001c1134)(0);
    if (iVar6 != 0) goto LAB_00102866;
    piVar11 = (int *)0x0;
  }
  else {
LAB_00102866:
    piVar11 = *(int **)(iVar6 + 0x7c);
  }
  iVar6 = *(int *)(*param_1 + 400);
  if (iVar6 == 0) {
    iVar6 = (*DAT_001c1134)(0);
    if (iVar6 == 0) {
      piVar12 = (int *)0x0;
      goto LAB_001028a6;
    }
  }
  piVar12 = *(int **)(iVar6 + 0x7c);
LAB_001028a6:
  bVar14 = false;
  if (((int)ROUND(gpGlobals[7]) & 0x1eU) != 0) {
    if (piVar11[0x48] == piVar12[0x48]) {
      bVar14 = piVar11[0x48] != 0;
    }
  }
  fVar1 = (float)piVar11[0x107];
  fVar2 = *gpGlobals;
  if (0x3f < (byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
    bVar14 = true;
  }
  if (((*(byte *)(piVar11 + 0x21) & 0x10) == 0) || (*(int *)(*piVar11 + 0x20c) == 5)) {
    bVar14 = true;
  }
  if (bVar14) {
    *(byte *)(piVar11 + 0x21) = *(byte *)(piVar11 + 0x21) & 0xef;
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
    *(float *)(*param_1 + 0x104) = *gpGlobals;
  }
  else {
    piVar13 = (int *)0x0;
    puVar5 = &stack0xffffff5c;
LAB_00102dd5:
    puVar10 = puVar5;
    *(undefined4 *)(puVar10 + -4) = 0x43000000;
    *(undefined4 *)(puVar10 + -8) = *(undefined4 *)(puVar10 + 0x44);
    *(int **)(puVar10 + -0xc) = piVar13;
    *(undefined4 *)(puVar10 + -0x10) = 0x102de5;
    piVar13 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf();
    if (piVar13 != (int *)0x0) {
      iVar6 = piVar13[0x111];
      *(int **)(puVar10 + -4) = piVar13;
      pcVar4 = *(code **)(iVar6 + 0x2c);
      *(undefined4 *)(puVar10 + -8) = 0x1029dc;
      iVar6 = (*pcVar4)();
      puVar5 = puVar10;
      if (iVar6 == 2) {
        iVar6 = piVar13[0x111];
        *(int **)(puVar10 + -4) = piVar13;
        pcVar4 = *(code **)(iVar6 + 0x8c);
        *(undefined4 *)(puVar10 + -8) = 0x1029f7;
        iVar6 = (*pcVar4)();
        if (iVar6 != 0) {
          iVar6 = *piVar13;
          *(int *)(puVar10 + 0x1c) = iVar6;
          if (((*(int *)(iVar6 + 0x20c) != 0) && ((*(byte *)(piVar13 + 0x21) & 0x10) == 0)) &&
             (*(int *)(iVar6 + 0x20c) != 5)) {
            fVar1 = gpGlobals[7];
            *(undefined2 *)(puVar10 + 0xa0) = in_FPUControlWord;
            *(uint *)(puVar10 + 0x98) =
                 CONCAT22((short)((uint)*(undefined4 *)(puVar10 + 0xa0) >> 0x10),
                          CONCAT11(0xc,(char)*(undefined4 *)(puVar10 + 0xa0)));
            *(int *)(puVar10 + 0x34) = (int)ROUND(fVar1);
            in_FPUControlWord = *(undefined2 *)(puVar10 + 0xa0);
            if ((puVar10[0x34] & 0x1e) != 0) {
              *(int **)(puVar10 + -4) = piVar12;
              *(int **)(puVar10 + -8) = piVar13;
              *(undefined4 *)(puVar10 + -0xc) = 0x102a71;
              iVar6 = IsAlly__11CBaseEntityP11CBaseEntity();
              if (iVar6 != 0) goto LAB_00102dd5;
            }
            iVar6 = piVar13[0x111];
            *(int *)(puVar10 + 0x34) = iVar6;
            *(undefined4 *)(puVar10 + -4) = *(undefined4 *)(puVar10 + 0x44);
            *(int **)(puVar10 + -8) = piVar13;
            *(undefined4 *)(puVar10 + -0xc) = *(undefined4 *)(puVar10 + 0x40);
            pcVar4 = *(code **)(iVar6 + 0xd8);
            *(code **)(puVar10 + 0x34) = pcVar4;
            *(undefined4 *)(puVar10 + -0x10) = 0x102a9f;
            (*pcVar4)();
            *(undefined1 **)(puVar10 + 0x30) = puVar10 + 0x50;
            *(undefined1 **)(puVar10 + -0x10) = puVar10 + 0x50;
            iVar6 = **(int **)(puVar10 + 0xa4);
            *(int *)(puVar10 + 0x24) = iVar6;
            uVar8 = *(undefined4 *)(iVar6 + 0x208);
            *(undefined4 *)(puVar10 + 0x30) = uVar8;
            *(undefined4 *)(puVar10 + -0x14) = uVar8;
            *(undefined4 *)(puVar10 + -0x18) = 0;
            *(undefined4 *)(puVar10 + -0x1c) = *(undefined4 *)(puVar10 + 0x3c);
            *(undefined4 *)(puVar10 + -0x20) = *(undefined4 *)(puVar10 + 0x40);
            *(undefined4 *)(puVar10 + -0x24) = 0x102ad7;
            UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult();
            fVar1 = *(float *)(puVar10 + 0x60);
            if (((byte)(1.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fVar1 == 1.0) << 0xe) >> 8)) == 0x40) ||
               (puVar5 = puVar10 + -4, *(int *)(puVar10 + 0x80) == *(int *)(*piVar13 + 0x208))) {
              uVar8 = *(undefined4 *)(*piVar13 + 0x208);
              *(undefined4 *)(puVar10 + 0x1c) = uVar8;
              *(char **)(puVar10 + 0x30) = "player/death2.wav";
              *(undefined4 *)(puVar10 + -8) = 100;
              *(undefined4 *)(puVar10 + -0xc) = 0;
              *(undefined4 *)(puVar10 + -0x10) = 0x3f4ccccd;
              *(undefined4 *)(puVar10 + -0x14) = 0x3f800000;
              *(char **)(puVar10 + -0x18) = "player/death2.wav";
              *(undefined4 *)(puVar10 + -0x1c) = 2;
              *(undefined4 *)(puVar10 + -0x20) = uVar8;
              *(undefined4 *)(puVar10 + -0x24) = 0x102b35;
              EMIT_SOUND_DYN__FP7edict_siPCcffii();
              *(byte *)(piVar13 + 0x21) = *(byte *)(piVar13 + 0x21) | 0x10;
              *(undefined4 *)(puVar10 + -8) = 2;
              *(int **)(puVar10 + -0xc) = piVar13;
              *(undefined4 *)(puVar10 + -0x10) = 0x102b47;
              piVar7 = (int *)CreateTimer__11CBaseEntityi();
              *(int **)(puVar10 + 0x18) = piVar7;
              iVar6 = *piVar7;
              *(int *)(puVar10 + 0x14) = iVar6;
              *(float **)(puVar10 + 0x30) = gpGlobals;
              *(float *)(iVar6 + 0x104) = *gpGlobals + 2.0;
              *(undefined2 *)(puVar10 + 0x30) = 0;
              *(uint *)(puVar10 + 0x30) = *(uint *)(puVar10 + 0x30) | 0xffff0000;
              *(code **)(puVar10 + 0x34) = Timer_Infection__11CBaseEntity;
              uVar8 = *(undefined4 *)(puVar10 + 0x34);
              iVar6 = *(int *)(puVar10 + 0x18);
              *(undefined4 *)(iVar6 + 0xc) = *(undefined4 *)(puVar10 + 0x30);
              *(undefined4 *)(iVar6 + 0x10) = uVar8;
              iVar6 = **(int **)(puVar10 + 0x18);
              *(int *)(puVar10 + 0x1c) = iVar6;
              iVar3 = **(int **)(puVar10 + 0xa4);
              *(int *)(puVar10 + 0x20) = iVar3;
              uVar8 = *(undefined4 *)(iVar3 + 400);
              *(undefined4 *)(puVar10 + 0x10) = uVar8;
              *(undefined4 *)(iVar6 + 400) = uVar8;
              piVar13[0x4a] = piVar11[0x48];
              *(undefined4 *)(puVar10 + -0x10) = 0;
              *(undefined4 *)(puVar10 + -0x14) = 0;
              *(undefined4 *)(puVar10 + -0x18) = 0;
              *(float **)(puVar10 + 0x1c) = gpGlobals;
              *(undefined4 *)(puVar10 + 0x30) = *(undefined4 *)(*piVar11 + 0x1d0);
              *(int *)(puVar10 + 0x30) =
                   *(int *)(puVar10 + 0x30) + *(int *)(*(int *)(puVar10 + 0x1c) + 0x98);
              *(undefined4 *)(puVar10 + -0x1c) = *(undefined4 *)(puVar10 + 0x30);
              *(char **)(puVar10 + 0x30) = "#Medic_infected";
              *(char **)(puVar10 + -0x20) = "#Medic_infected";
              *(undefined4 *)(puVar10 + -0x24) = 1;
              *(int *)(puVar10 + -0x28) = *piVar13;
              *(undefined4 *)(puVar10 + -0x2c) = 0x102c17;
              ClientPrint__FP9entvars_siPCcN42();
              *(undefined4 *)(puVar10 + -8) = 0;
              *(undefined4 *)(puVar10 + -0xc) = 0;
              *(undefined4 *)(puVar10 + -0x10) = 0;
              *(float **)(puVar10 + 0x1c) = gpGlobals;
              *(undefined4 *)(puVar10 + 0x30) = *(undefined4 *)(*piVar13 + 0x1d0);
              *(int *)(puVar10 + 0x30) = *(int *)(puVar10 + 0x30) + (int)gpGlobals[0x26];
              *(undefined4 *)(puVar10 + -0x14) = *(undefined4 *)(puVar10 + 0x30);
              *(char **)(puVar10 + 0x30) = "#Medic_infect";
              *(char **)(puVar10 + -0x18) = "#Medic_infect";
              *(undefined4 *)(puVar10 + -0x1c) = 1;
              *(int *)(puVar10 + -0x20) = *piVar11;
              *(undefined4 *)(puVar10 + -0x24) = 0x102c60;
              ClientPrint__FP9entvars_siPCcN42();
              if (piVar13[0x48] == 0) {
                *(char **)(puVar10 + 0x18) = "SPECTATOR";
              }
              else {
                *(int *)(puVar10 + -8) = piVar13[0x48];
                *(undefined4 *)(puVar10 + -0xc) = 0x102c78;
                uVar8 = GetTeamName__Fi();
                *(undefined4 *)(puVar10 + 0x18) = uVar8;
              }
              *(undefined4 *)(puVar10 + -8) = *(undefined4 *)(puVar10 + 0x18);
              uVar8 = *(undefined4 *)(*piVar13 + 0x208);
              *(undefined4 *)(puVar10 + 0x30) = uVar8;
              *(undefined4 *)(puVar10 + -0xc) = uVar8;
              *(code **)(puVar10 + 0x30) = DAT_001c11f4;
              *(undefined4 *)(puVar10 + -0x10) = 0x102cb6;
              uVar8 = (*DAT_001c11f4)();
              *(undefined4 *)(puVar10 + 0x18) = uVar8;
              *(undefined4 *)(puVar10 + -0xc) = uVar8;
              uVar8 = *(undefined4 *)(*piVar13 + 0x208);
              *(undefined4 *)(puVar10 + 0x30) = uVar8;
              *(undefined4 *)(puVar10 + -0x10) = uVar8;
              *(code **)(puVar10 + 0x30) = DAT_001c11e4;
              *(undefined4 *)(puVar10 + -0x14) = 0x102ce3;
              uVar8 = (*DAT_001c11e4)();
              *(undefined4 *)(puVar10 + 0x18) = uVar8;
              *(undefined4 *)(puVar10 + -0x10) = uVar8;
              *(float **)(puVar10 + 0x1c) = gpGlobals;
              *(undefined4 *)(puVar10 + 0x30) = *(undefined4 *)(*piVar13 + 0x1d0);
              *(int *)(puVar10 + 0x30) = *(int *)(puVar10 + 0x30) + (int)gpGlobals[0x26];
              *(undefined4 *)(puVar10 + -0x14) = *(undefined4 *)(puVar10 + 0x30);
              if (piVar11[0x48] == 0) {
                pcVar9 = "SPECTATOR";
              }
              else {
                *(int *)(puVar10 + -0x18) = piVar11[0x48];
                *(undefined4 *)(puVar10 + -0x1c) = 0x102d2b;
                pcVar9 = (char *)GetTeamName__Fi();
              }
              *(char **)(puVar10 + 0x18) = pcVar9;
              *(undefined4 *)(puVar10 + -0x18) = *(undefined4 *)(puVar10 + 0x18);
              uVar8 = *(undefined4 *)(*piVar11 + 0x208);
              *(undefined4 *)(puVar10 + 0x30) = uVar8;
              *(undefined4 *)(puVar10 + -0x1c) = uVar8;
              *(code **)(puVar10 + 0x30) = DAT_001c11f4;
              *(undefined4 *)(puVar10 + -0x20) = 0x102d62;
              uVar8 = (*DAT_001c11f4)();
              *(undefined4 *)(puVar10 + 0x18) = uVar8;
              *(undefined4 *)(puVar10 + -0x1c) = uVar8;
              uVar8 = *(undefined4 *)(*piVar11 + 0x208);
              *(undefined4 *)(puVar10 + 0x30) = uVar8;
              *(undefined4 *)(puVar10 + -0x20) = uVar8;
              *(code **)(puVar10 + 0x30) = DAT_001c11e4;
              *(undefined4 *)(puVar10 + -0x24) = 0x102d8d;
              uVar8 = (*DAT_001c11e4)();
              *(undefined4 *)(puVar10 + 0x18) = uVar8;
              *(undefined4 *)(puVar10 + -0x20) = uVar8;
              *(float **)(puVar10 + 0x1c) = gpGlobals;
              *(undefined4 *)(puVar10 + 0x30) = *(undefined4 *)(*piVar11 + 0x1d0);
              *(int *)(puVar10 + 0x30) = *(int *)(puVar10 + 0x30) + (int)gpGlobals[0x26];
              *(undefined4 *)(puVar10 + -0x24) = *(undefined4 *)(puVar10 + 0x30);
              *(char **)(puVar10 + 0x30) =
                   "\"%s<%i><%u><%s>\" triggered \"Passed_On_Infection\" against \"%s<%i><%u><%s>\"\n"
              ;
              *(char **)(puVar10 + -0x28) =
                   "\"%s<%i><%u><%s>\" triggered \"Passed_On_Infection\" against \"%s<%i><%u><%s>\"\n"
              ;
              *(undefined4 *)(puVar10 + -0x2c) = 0x102dd2;
              UTIL_LogPrintf__FPce();
              puVar5 = puVar10 + -4;
            }
          }
        }
      }
      goto LAB_00102dd5;
    }
    *(float *)(**(int **)(puVar10 + 0xa8) + 0x104) = *gpGlobals + 3.0;
    iVar6 = *piVar11;
    *(undefined4 *)(puVar10 + 0x48) = *(undefined4 *)(*piVar11 + 8);
    *(undefined4 *)(puVar10 + 0x4c) = *(undefined4 *)(iVar6 + 0xc);
    *(undefined4 *)(puVar10 + 0x50) = *(undefined4 *)(iVar6 + 0x10);
    *(undefined4 *)(puVar10 + -4) = 0x41000000;
    *(int *)(puVar10 + 0x34) = piVar11[0x111];
    *(int **)(puVar10 + -8) = piVar11;
    pcVar4 = *(code **)(*(int *)(puVar10 + 0x34) + 0x44);
    *(code **)(puVar10 + 0x34) = pcVar4;
    *(undefined4 *)(puVar10 + -0xc) = 0x102e4c;
    uVar8 = (*pcVar4)();
    *(undefined4 *)(puVar10 + -8) = uVar8;
    *(undefined1 **)(puVar10 + 0x34) = puVar10 + 0x48;
    *(undefined1 **)(puVar10 + -0xc) = puVar10 + 0x48;
    *(undefined4 *)(puVar10 + -0x10) = 0x102e62;
    SpawnBlood__FG6Vectorif();
    *(int *)(puVar10 + 0x34) = piVar11[0x111];
    *(int **)(puVar10 + -0x10) = piVar11;
    pcVar4 = *(code **)(*(int *)(puVar10 + 0x34) + 0x8c);
    *(code **)(puVar10 + 0x34) = pcVar4;
    *(undefined4 *)(puVar10 + -0x14) = 0x102e7f;
    iVar6 = (*pcVar4)();
    if (iVar6 != 0) {
      *(int *)(puVar10 + 0x20) = piVar11[0x111];
      *(undefined4 *)(puVar10 + -4) = 0x8010000;
      *(undefined4 *)(puVar10 + -8) = 0x41000000;
      *(int *)(puVar10 + -0xc) = *piVar12;
      uVar8 = **(undefined4 **)(puVar10 + 0xa8);
      *(undefined4 *)(puVar10 + 0x34) = uVar8;
      *(undefined4 *)(puVar10 + -0x10) = uVar8;
      *(int **)(puVar10 + -0x14) = piVar11;
      pcVar4 = *(code **)(*(int *)(puVar10 + 0x20) + 0x38);
      *(code **)(puVar10 + 0x34) = pcVar4;
      *(undefined4 *)(puVar10 + -0x18) = 0x102ec4;
      (*pcVar4)();
      *(int *)(puVar10 + 0x34) = piVar11[0x111];
      *(int **)(puVar10 + -0x18) = piVar11;
      pcVar4 = *(code **)(*(int *)(puVar10 + 0x34) + 0x8c);
      *(code **)(puVar10 + 0x34) = pcVar4;
      *(undefined4 *)(puVar10 + -0x1c) = 0x102ee1;
      iVar6 = (*pcVar4)();
      if (iVar6 == 0) {
        *(char **)(puVar10 + -4) = "infection";
        if (piVar11[0x48] == 0) {
          pcVar9 = "SPECTATOR";
        }
        else {
          *(int *)(puVar10 + -8) = piVar11[0x48];
          *(undefined4 *)(puVar10 + -0xc) = 0x102f0a;
          pcVar9 = (char *)GetTeamName__Fi();
        }
        *(char **)(puVar10 + -8) = pcVar9;
        *(undefined4 *)(puVar10 + -0xc) = *(undefined4 *)(*piVar11 + 0x208);
        *(undefined4 *)(puVar10 + -0x10) = 0x102f32;
        uVar8 = (*DAT_001c11f4)();
        *(undefined4 *)(puVar10 + -0xc) = uVar8;
        *(undefined4 *)(puVar10 + -0x10) = *(undefined4 *)(*piVar11 + 0x208);
        *(undefined4 *)(puVar10 + -0x14) = 0x102f4d;
        uVar8 = (*DAT_001c11e4)();
        *(undefined4 *)(puVar10 + -0x10) = uVar8;
        *(int *)(puVar10 + -0x14) = *(int *)(*piVar11 + 0x1d0) + (int)gpGlobals[0x26];
        if (piVar12[0x48] == 0) {
          pcVar9 = "SPECTATOR";
        }
        else {
          *(int *)(puVar10 + -0x18) = piVar12[0x48];
          *(undefined4 *)(puVar10 + -0x1c) = 0x102f7d;
          pcVar9 = (char *)GetTeamName__Fi();
        }
        *(char **)(puVar10 + -0x18) = pcVar9;
        *(undefined4 *)(puVar10 + -0x1c) = *(undefined4 *)(*piVar12 + 0x208);
        *(undefined4 *)(puVar10 + -0x20) = 0x102fa3;
        uVar8 = (*DAT_001c11f4)();
        *(undefined4 *)(puVar10 + -0x1c) = uVar8;
        *(undefined4 *)(puVar10 + -0x20) = *(undefined4 *)(*piVar12 + 0x208);
        *(undefined4 *)(puVar10 + -0x24) = 0x102fbf;
        uVar8 = (*DAT_001c11e4)();
        *(undefined4 *)(puVar10 + -0x20) = uVar8;
        *(int *)(puVar10 + -0x24) = *(int *)(*piVar12 + 0x1d0) + (int)gpGlobals[0x26];
        *(char **)(puVar10 + -0x28) = "\"%s<%i><%u><%s>\" killed \"%s<%i><%u><%s>\" with \"%s\"\n";
        *(undefined4 *)(puVar10 + -0x2c) = 0x102fe7;
        UTIL_LogPrintf__FPce();
      }
    }
  }
  return;
}


// Timer_Regeneration__11CBaseEntity  @ 00103e54
void Timer_Regeneration__11CBaseEntity(int *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = *(int *)(*param_1 + 0x198);
  if (iVar3 == 0) {
    iVar3 = (*DAT_001c1134)(0);
    if (iVar3 == 0) {
      piVar4 = (int *)0x0;
      goto LAB_00103e96;
    }
  }
  piVar4 = *(int **)(iVar3 + 0x7c);
LAB_00103e96:
  *(float *)(*param_1 + 0x104) = *gpGlobals + 3.0;
  iVar3 = *piVar4;
  if (*(float *)(iVar3 + 0x160) < *(float *)(iVar3 + 0x1b0)) {
    *(float *)(iVar3 + 0x160) = *(float *)(iVar3 + 0x160) + 2.0;
    iVar3 = *piVar4;
    fVar1 = *(float *)(iVar3 + 0x160);
    fVar2 = *(float *)(iVar3 + 0x1b0);
    if (0x3f < (byte)((fVar1 < fVar2 |
                       (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
      *(undefined4 *)(iVar3 + 0x160) = *(undefined4 *)(iVar3 + 0x1b0);
    }
  }
  return;
}


// Timer_SpyUndercoverThink__11CBaseEntity  @ 00105190
void Timer_SpyUndercoverThink__11CBaseEntity(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001c1134)(0);
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)0x0;
      goto LAB_001051ce;
    }
  }
  puVar2 = *(undefined4 **)(iVar1 + 0x7c);
LAB_001051ce:
  if (puVar2[0x19] == 2) {
    puVar2[99] = *gpGlobals + 10.0;
    if (*(int *)(*param_1 + 0x110) != 0) {
      uVar3 = UTIL_VarArgs__FPce(&DAT_001515ed,(&sClassNames)[*(int *)(*param_1 + 0x110)],0,0,0);
      ClientPrint__FP9entvars_siPCcN42(*puVar2,1,"#Disguise_asclass",uVar3);
      puVar2[0x76] = *(undefined4 *)(*param_1 + 0x110);
    }
    if (param_1[0x48] != 0) {
      uVar3 = UTIL_dtos1__Fi(param_1[0x48],0,0,0);
      ClientPrint__FP9entvars_siPCcN42(*puVar2,1,"#Disguise_asteam",uVar3);
      puVar2[0x75] = param_1[0x48];
    }
    ClientPrint__FP9entvars_siPCcN42(*puVar2,4,"#Disguise_now",0,0,0,0);
    puVar2[0x19] = 1;
    TeamFortress_SpyCalcName__11CBasePlayer(puVar2);
    Spy_DisguiseExternalWeaponModel__11CBasePlayer(puVar2);
    TeamFortress_SetSkin__11CBasePlayer(puVar2);
  }
  dremove__FP11CBaseEntity(param_1);
  return;
}


// Timer_Tranquilisation__11CBaseEntity  @ 00103dc0
void Timer_Tranquilisation__11CBaseEntity(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_001c1134)(0);
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)0x0;
      goto LAB_00103dfe;
    }
  }
  puVar2 = *(undefined4 **)(iVar1 + 0x7c);
LAB_00103dfe:
  ClientPrint__FP9entvars_siPCcN42(*puVar2,1,"#Tranq_finished",0,0,0,0);
  *(byte *)((int)puVar2 + 0x85) = *(byte *)((int)puVar2 + 0x85) & 0x7f;
  TeamFortress_SetSpeed__11CBasePlayer(puVar2);
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


