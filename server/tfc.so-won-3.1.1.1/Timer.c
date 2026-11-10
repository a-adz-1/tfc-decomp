// Timer_AutokickThink__11CBaseEntity  @ 00108334
void Timer_AutokickThink__11CBaseEntity(int *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_0019f7b4)(0);
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_00108372;
    }
  }
  iVar1 = *(int *)(iVar1 + 0x7c);
LAB_00108372:
  *(undefined4 *)(iVar1 + 0x1f8) = 0;
  dremove__FP11CBaseEntity(param_1);
  return;
}


// Timer_Birthday__11CBaseEntity  @ 001063bc
void Timer_Birthday__11CBaseEntity(int *param_1)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  longdouble lVar5;
  longdouble lVar6;
  undefined4 uVar7;
  int *local_c;
  
  if (param_1[0x23] < 6) {
    *(float *)(*param_1 + 0x104) = *gpGlobals + 1.5;
    param_1[0x23] = param_1[0x23] + 1;
    UTIL_ClientPrintAll__FiPCcN41(4,param_1[0xb9] + (int)gpGlobals[0x26],0,0,0,0);
    local_c = (int *)0x0;
LAB_00106de0:
    do {
      local_c = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(local_c,"player");
      if (local_c == (int *)0x0) {
        return;
      }
      bVar1 = false;
      if ((*(int *)(*local_c + 0x208) == 0) ||
         (iVar2 = (*DAT_0019f7b8)(*(int *)(*local_c + 0x208)), iVar2 == 0)) {
        bVar1 = true;
      }
      if (bVar1) {
        return;
      }
      iVar2 = *local_c;
    } while ((iVar2 == 0) || (local_c[0x1e] != 0));
    if (param_1[0x23] != 1) goto LAB_00106d7c;
    if (christmas == 0) {
      uVar4 = *(undefined4 *)(iVar2 + 0x208);
      pcVar3 = "misc/b1.wav";
    }
    else {
      uVar4 = *(undefined4 *)(iVar2 + 0x208);
      pcVar3 = "misc/b2.wav";
    }
    uVar7 = 2;
    goto LAB_00106dd7;
  }
  param_1[0x23] = 0;
  lVar5 = (longdouble)(*DAT_0019f80c)(0x43340000,0x43700000);
  *(float *)(*param_1 + 0x104) = (float)(lVar5 + (longdouble)*gpGlobals);
  lVar5 = (longdouble)(*DAT_0019f80c)(0,0x3f800000);
  lVar6 = (longdouble)0.02;
  if ((byte)((lVar6 < lVar5 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
             (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1) < 0x40) {
    lVar6 = (longdouble)0.04;
    if (0x3f < (byte)((lVar6 < lVar5 |
                       (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1)) {
      lVar5 = (longdouble)(*DAT_0019f80c)(0x447a0000,0x459c4000);
      iVar2 = UTIL_VarArgs__FPce("\n\n\n\nCurrent number of Snipers on\nthe Battlements Worldwide: %d\n"
                                 ,(double)lVar5);
      param_1[0xb9] = iVar2 - (int)gpGlobals[0x26];
      return;
    }
    lVar6 = (longdouble)0.06;
    if ((byte)((lVar6 < lVar5 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
               (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1) < 0x40) {
      lVar6 = (longdouble)0.08;
      if ((byte)((lVar6 < lVar5 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1) < 0x40) {
        lVar6 = (longdouble)0.1;
        if ((byte)((lVar6 < lVar5 | (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8)
                   | (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1) < 0x40) {
          lVar6 = (longdouble)0.12;
          if ((byte)((lVar6 < lVar5 |
                      (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1) < 0x40) {
            lVar6 = (longdouble)0.14;
            if ((byte)((lVar6 < lVar5 |
                        (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
                       (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1) < 0x40) {
              lVar6 = (longdouble)0.16;
              if ((byte)((lVar6 < lVar5 |
                          (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
                         (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1) < 0x40) {
                lVar6 = (longdouble)0.18;
                if ((byte)((lVar6 < lVar5 |
                            (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
                           (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1) < 0x40) {
                  lVar6 = (longdouble)0.2;
                  if ((byte)((lVar6 < lVar5 |
                              (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
                             (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1) < 0x40) {
                    lVar6 = (longdouble)0.22;
                    if ((byte)((lVar6 < lVar5 |
                                (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
                               (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1) < 0x40)
                    {
                      lVar6 = (longdouble)0.24;
                      if ((byte)((lVar6 < lVar5 |
                                  (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8) |
                                 (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1) < 0x40
                         ) {
                        lVar6 = (longdouble)0.25;
                        if ((byte)((lVar6 < lVar5 |
                                    (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8)
                                   | (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1) <
                            0x40) {
                          lVar6 = (longdouble)0.26;
                          if ((byte)((lVar6 < lVar5 |
                                      (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >> 8
                                            ) |
                                     (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1) <
                              0x40) {
                            lVar6 = (longdouble)0.28;
                            if ((byte)((lVar6 < lVar5 |
                                        (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10) >>
                                              8) |
                                       (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1)
                                < 0x40) {
                              lVar6 = (longdouble)0.3;
                              if ((byte)((lVar6 < lVar5 |
                                          (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10)
                                                >> 8) |
                                         (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) - 1
                                        ) < 0x40) {
                                lVar6 = (longdouble)0.32;
                                if ((byte)((lVar6 < lVar5 |
                                            (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) << 10
                                                           ) >> 8) |
                                           (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8)) -
                                          1) < 0x40) {
                                  lVar6 = (longdouble)0.34;
                                  if ((byte)((lVar6 < lVar5 |
                                              (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5)) <<
                                                             10) >> 8) |
                                             (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8))
                                            - 1) < 0x40) {
                                    lVar6 = (longdouble)0.36;
                                    if ((byte)((lVar6 < lVar5 |
                                                (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5))
                                                               << 10) >> 8) |
                                               (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >> 8
                                                     )) - 1) < 0x40) {
                                      lVar6 = (longdouble)0.38;
                                      if ((byte)((lVar6 < lVar5 |
                                                  (byte)((ushort)((ushort)(NAN(lVar6) || NAN(lVar5))
                                                                 << 10) >> 8) |
                                                 (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe) >>
                                                       8)) - 1) < 0x40) {
                                        lVar6 = (longdouble)0.4;
                                        if ((byte)((lVar6 < lVar5 |
                                                    (byte)((ushort)((ushort)(NAN(lVar6) ||
                                                                            NAN(lVar5)) << 10) >> 8)
                                                   | (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe
                                                                    ) >> 8)) - 1) < 0x40) {
                                          lVar6 = (longdouble)0.42;
                                          if ((byte)((lVar6 < lVar5 |
                                                      (byte)((ushort)((ushort)(NAN(lVar6) ||
                                                                              NAN(lVar5)) << 10) >>
                                                            8) |
                                                     (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe
                                                                    ) >> 8)) - 1) < 0x40) {
                                            lVar6 = (longdouble)0.44;
                                            if ((byte)((lVar6 < lVar5 |
                                                        (byte)((ushort)((ushort)(NAN(lVar6) ||
                                                                                NAN(lVar5)) << 10)
                                                              >> 8) |
                                                       (byte)((ushort)((ushort)(lVar6 == lVar5) <<
                                                                      0xe) >> 8)) - 1) < 0x40) {
                                              lVar6 = (longdouble)0.46;
                                              if ((byte)((lVar6 < lVar5 |
                                                          (byte)((ushort)((ushort)(NAN(lVar6) ||
                                                                                  NAN(lVar5)) << 10)
                                                                >> 8) |
                                                         (byte)((ushort)((ushort)(lVar6 == lVar5) <<
                                                                        0xe) >> 8)) - 1) < 0x40) {
                                                lVar6 = (longdouble)0.48;
                                                if ((byte)((lVar6 < lVar5 |
                                                            (byte)((ushort)((ushort)(NAN(lVar6) ||
                                                                                    NAN(lVar5)) <<
                                                                           10) >> 8) |
                                                           (byte)((ushort)((ushort)(lVar6 == lVar5)
                                                                          << 0xe) >> 8)) - 1) < 0x40
                                                   ) {
                                                  lVar6 = (longdouble)0.5;
                                                  if ((byte)((lVar6 < lVar5 |
                                                              (byte)((ushort)((ushort)(NAN(lVar6) ||
                                                                                      NAN(lVar5)) <<
                                                                             10) >> 8) |
                                                             (byte)((ushort)((ushort)(lVar6 == lVar5
                                                                                     ) << 0xe) >> 8)
                                                             ) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.52;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.54;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.56;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.58;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.6;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.62;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.64;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.66;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.68;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.7;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.72;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.74;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.76;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.78;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.8;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.82;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.84;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.86;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.88;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.9;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.92;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.94;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.96;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    lVar6 = (longdouble)0.98;
                                                    if ((byte)((lVar6 < lVar5 |
                                                                (byte)((ushort)((ushort)(NAN(lVar6)
                                                                                        || NAN(lVar5
                                                  )) << 10) >> 8) |
                                                  (byte)((ushort)((ushort)(lVar6 == lVar5) << 0xe)
                                                        >> 8)) - 1) < 0x40) {
                                                    pcVar3 = 
                                                  "\n\n\n\n\"MJ: Did you hear John Cash wrote TF?\"\n   - VomitGod"
                                                  ;
                                                  goto LAB_00106c68;
                                                  }
                                                  pcVar3 = 
                                                  "\n\n\n\nTF\'s original design docs!\nCheck it out!\nwww.teamfortress.com/files/teamfortress/tfdes_2.gif"
                                                  ;
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
  else {
    if (christmas == 0) {
      pcVar3 = "\n\n\n\nHAPPY BIRTHDAY TEAMFORTRESS!\n";
LAB_00106c68:
      param_1[0xb9] = (int)pcVar3 - (int)gpGlobals[0x26];
      return;
    }
    pcVar3 = "\n\n\n\nMERRY CHRISTMAS!!\n";
  }
  param_1[0xb9] = (int)pcVar3 - (int)gpGlobals[0x26];
  return;
LAB_00106d7c:
  if (param_1[0x23] < 5) {
    iVar2 = (*DAT_0019f808)(0,1);
    if (iVar2 == 0) {
      uVar4 = *(undefined4 *)(*local_c + 0x208);
      pcVar3 = "misc/party1.wav";
    }
    else {
      uVar4 = *(undefined4 *)(*local_c + 0x208);
      pcVar3 = "misc/party2.wav";
    }
    uVar7 = 3;
LAB_00106dd7:
    EMIT_SOUND_DYN__FP7edict_siPCcffii(uVar4,uVar7,pcVar3,0x3f4ccccd3f800000,0,100);
  }
  goto LAB_00106de0;
}


// Timer_CeaseFireThink__11CBaseEntity  @ 001075e4
void Timer_CeaseFireThink__11CBaseEntity(int *param_1)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int *local_8;
  
  if (((cb_ceasefire_time < *gpGlobals) && (param_1[0x23] == 1)) && (cease_fire == 1)) {
    cease_fire = 0;
    UTIL_ClientPrintAll__FiPCcN41(1,"#Game_resumefire",0,0,0,0);
    UTIL_LogPrintf__FPce("World triggered \"Resume_Fire\"\n");
    local_8 = (int *)0x0;
    while( true ) {
      local_8 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(local_8,"player");
      if (local_8 == (int *)0x0) break;
      bVar2 = false;
      if (*(int *)(*local_8 + 0x208) == 0) {
LAB_00107690:
        bVar2 = true;
      }
      else {
        iVar3 = (*DAT_0019f7b8)(*(int *)(*local_8 + 0x208));
        if (iVar3 == 0) goto LAB_00107690;
      }
      if (bVar2) break;
      if (*local_8 != 0) {
        *(undefined4 *)(*local_8 + 0x250) = 0;
        fVar1 = *gpGlobals;
        *(byte *)((int)local_8 + 0x86) = *(byte *)((int)local_8 + 0x86) & 0xfe;
        local_8[99] = (int)(fVar1 + 10.0);
        TeamFortress_SetSpeed__11CBasePlayer(local_8);
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


// Timer_CheckBuildDistance__11CBaseEntity  @ 001071f0
void Timer_CheckBuildDistance__11CBaseEntity(int *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  int iVar6;
  int *piVar7;
  int **ppiVar8;
  int *piVar9;
  int *piVar10;
  int *piStack_44;
  undefined4 uStack_40;
  int *piStack_3c;
  int *local_1c;
  
  piStack_3c = (int *)0x1071fe;
  bVar5 = false;
  if (*(int **)(*param_1 + 0x198) == (int *)0x0) {
LAB_0010722c:
    bVar5 = true;
  }
  else {
    uStack_40 = 0x107225;
    piStack_3c = *(int **)(*param_1 + 0x198);
    iVar6 = (*DAT_0019f7b8)();
    if (iVar6 == 0) goto LAB_0010722c;
  }
  ppiVar8 = (int **)&stack0xffffffc8;
  if (bVar5) goto LAB_0010735d;
  bVar5 = false;
  if (*(int **)(*param_1 + 400) == (int *)0x0) {
LAB_00107260:
    bVar5 = true;
  }
  else {
    uStack_40 = 0x107259;
    piStack_3c = *(int **)(*param_1 + 400);
    iVar6 = (*DAT_0019f7b8)();
    if (iVar6 == 0) goto LAB_00107260;
  }
  ppiVar8 = (int **)&stack0xffffffc8;
  if (bVar5) goto LAB_0010735d;
  iVar6 = *(int *)(*param_1 + 0x198);
  if (iVar6 == 0) {
    piStack_3c = (int *)0x0;
    uStack_40 = 0x10728c;
    iVar6 = (*DAT_0019f7b4)();
    if (iVar6 != 0) goto LAB_00107295;
    local_1c = (int *)0x0;
  }
  else {
LAB_00107295:
    local_1c = *(int **)(iVar6 + 0x7c);
  }
  iVar6 = *(int *)(*param_1 + 400);
  if (iVar6 == 0) {
    piStack_3c = (int *)0x0;
    uStack_40 = 0x1072c6;
    iVar6 = (*DAT_0019f7b4)();
    if (iVar6 != 0) goto LAB_001072cf;
    piVar9 = (int *)0x0;
  }
  else {
LAB_001072cf:
    piVar9 = *(int **)(iVar6 + 0x7c);
  }
  piVar10 = local_1c + 0x4e;
  uStack_40 = 0x1072e5;
  piStack_3c = piVar10;
  iVar6 = __opP11CBaseEntity__7EHANDLE();
  ppiVar8 = (int **)&stack0xffffffc8;
  if (iVar6 != 0) {
    uStack_40 = 0x1072f2;
    piStack_3c = piVar10;
    piVar7 = (int *)__opP11CBaseEntity__7EHANDLE();
    ppiVar8 = (int **)&stack0xffffffc8;
    if (piVar7 == piVar9) {
      iVar6 = *piVar7;
      iVar1 = *local_1c;
      fVar2 = *(float *)(iVar6 + 8) - *(float *)(iVar1 + 8);
      fVar4 = *(float *)(iVar6 + 0xc) - *(float *)(iVar1 + 0xc);
      fVar3 = *(float *)(iVar6 + 0x10) - *(float *)(iVar1 + 0x10);
      if (SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar2 * fVar2) <= 64.0) {
        *(float *)(*param_1 + 0x104) = *gpGlobals + 0.3;
        return;
      }
      piStack_3c = local_1c;
      uStack_40 = 0x107355;
      ResetMenu__11CBasePlayer();
      uStack_40 = 0;
      ppiVar8 = &piStack_44;
      piStack_44 = piVar10;
      __as__7EHANDLEP11CBaseEntity();
    }
  }
LAB_0010735d:
  *(int **)((int)ppiVar8 + -4) = param_1;
  *(undefined4 *)((int)ppiVar8 + -8) = 0x107366;
  UTIL_Remove__FP11CBaseEntity();
  return;
}


// Timer_DetpackDisarm__11CBaseEntity  @ 00106f6c
void Timer_DetpackDisarm__11CBaseEntity(void)

{
  FUN_00106f7a();
  return;
}


// Timer_DetpackSet__11CBaseEntity  @ 00106e0c
void Timer_DetpackSet__11CBaseEntity(int *param_1)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_0019f7b4)(0);
    if (iVar1 == 0) {
      piVar5 = (int *)0x0;
      goto LAB_00106e4e;
    }
  }
  piVar5 = *(int **)(iVar1 + 0x7c);
LAB_00106e4e:
  piVar5[0x1b] = 0;
  *(byte *)((int)piVar5 + 0x86) = *(byte *)((int)piVar5 + 0x86) & 0xfe;
  TeamFortress_SetSpeed__11CBasePlayer(piVar5);
  (**(code **)(*(int *)(piVar5[0x237] + 0x454) + 0x120))(piVar5[0x237]);
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  piVar2 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s
                            ("detpack",*piVar5 + 8,&local_10,*(undefined4 *)(*piVar5 + 0x208));
  *(float *)(*piVar2 + 0x160) = *gpGlobals + *(float *)(*param_1 + 0x160);
  ClientPrint__FP9entvars_siPCcN42(*piVar5,1,"#Detpack_finishset",0,0,0,0);
  if (piVar5[0x48] == 0) {
    pcVar3 = "SPECTATOR";
  }
  else {
    pcVar3 = (char *)GetTeamName__Fi(piVar5[0x48]);
  }
  uVar4 = (*DAT_0019f8dc)(*(undefined4 *)(*piVar5 + 0x208),pcVar3);
  uVar4 = (*DAT_0019f864)(*(undefined4 *)(*piVar5 + 0x208),uVar4);
  UTIL_LogPrintf__FPce
            ("\"%s<%i><%s><%s>\" triggered \"Detpack_Set\"\n",
             *(int *)(*piVar5 + 0x1d0) + (int)gpGlobals[0x26],uVar4);
  dremove__FP11CBaseEntity(param_1);
  return;
}


// Timer_FinishedBuilding__11CBaseEntity  @ 00107394
void Timer_FinishedBuilding__11CBaseEntity(int *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  
  bVar1 = false;
  if ((*(int *)(*param_1 + 0x198) == 0) ||
     (iVar2 = (*DAT_0019f7b8)(*(int *)(*param_1 + 0x198)), iVar2 == 0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    iVar2 = *(int *)(*param_1 + 0x198);
    if ((iVar2 == 0) && (iVar2 = (*DAT_0019f7b4)(0), iVar2 == 0)) {
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
      iVar2 = piVar3[0x237];
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar2 + 0x454) + 0x120))(iVar2);
      }
      piVar3 = piVar3 + 0x4e;
      iVar2 = __opi__7EHANDLE(piVar3);
      if (iVar2 != 0) {
        iVar2 = __rf__7EHANDLE(piVar3);
        (**(code **)(*(int *)(iVar2 + 0x454) + 0xec))(iVar2);
        __as__7EHANDLEP11CBaseEntity(piVar3,0);
      }
    }
    dremove__FP11CBaseEntity(param_1);
    return;
  }
  UTIL_Remove__FP11CBaseEntity(param_1);
  return;
}


// Timer_Hallucination__11CBaseEntity  @ 001057fc
void Timer_Hallucination__11CBaseEntity(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 ***pppuVar4;
  int iVar5;
  undefined4 uVar6;
  short *psVar7;
  uint uVar8;
  undefined4 ****ppppuVar9;
  undefined4 ****ppppuVar10;
  int *piVar11;
  longdouble lVar12;
  undefined4 ***pppuStack_74;
  float **ppfStack_70;
  undefined4 ***pppuStack_6c;
  undefined4 ***pppuStack_68;
  int iStack_50;
  short sStack_46;
  float **ppfStack_44;
  float **ppfStack_40;
  float **ppfStack_3c;
  float **ppfStack_38;
  float **ppfStack_34;
  float fStack_30;
  float **ppfStack_2c;
  float **ppfStack_28;
  float **ppfStack_24;
  float **ppfStack_20;
  float **ppfStack_1c;
  float **ppfStack_18;
  float **ppfStack_14;
  float **ppfStack_10;
  float **ppfStack_c;
  float fStack_8;
  
  iVar5 = *(int *)(*param_1 + 0x198);
  if (iVar5 == 0) {
    pppuStack_68 = (undefined4 ***)0x0;
    pppuStack_6c = (undefined4 ***)0x105830;
    iVar5 = (*DAT_0019f7b4)();
    if (iVar5 != 0) goto LAB_00105839;
    piVar11 = (int *)0x0;
  }
  else {
LAB_00105839:
    piVar11 = *(int **)(iVar5 + 0x7c);
  }
  fStack_8 = *(float *)(*param_1 + 0x160) - 2.5;
  *(float *)(*param_1 + 0x160) = fStack_8;
  if (*(int *)(*piVar11 + 0x20c) == 5) {
    fStack_8 = *(float *)(*param_1 + 0x160) - 2.5;
    *(float *)(*param_1 + 0x160) = fStack_8;
  }
  if (((*(float *)(*param_1 + 0x160) <= 0.0) || (iVar5 = *piVar11, *(int *)(iVar5 + 0x170) != 0)) ||
     (piVar11[0x1e] != 0)) {
    *(byte *)((int)piVar11 + 0x85) = *(byte *)((int)piVar11 + 0x85) & 0xbf;
    iVar5 = *piVar11;
  }
  if (((*(int *)(iVar5 + 0x170) != 0) || (piVar11[0x1e] != 0)) ||
     ((*(byte *)((int)piVar11 + 0x85) & 0x40) == 0)) {
    pppuStack_68 = (undefined4 ***)param_1;
    pppuStack_6c = (undefined4 ***)0x1058ca;
    UTIL_Remove__FP11CBaseEntity();
    return;
  }
  fStack_8 = *gpGlobals + 0.3;
  *(float *)(*param_1 + 0x104) = fStack_8;
  pppuStack_68 = (undefined4 ***)0x14;
  pppuStack_6c = (undefined4 ***)0x0;
  ppfStack_70 = (float **)0x105900;
  uVar6 = (*DAT_0019f808)();
  switch(uVar6) {
  case 0:
    pppuStack_68 = (undefined4 ***)0x15535c;
    pppuStack_6c = *(undefined4 ****)(*piVar11 + 0x208);
    ppfStack_70 = (float **)&UNK_00105956;
    (*DAT_0019f744)();
    break;
  case 1:
    pppuStack_68 = (undefined4 ***)0x155380;
    pppuStack_6c = *(undefined4 ****)(*piVar11 + 0x208);
    ppfStack_70 = (float **)&UNK_0010597a;
    (*DAT_0019f744)();
    ppfStack_70 = (float **)0x3f666666;
    pppuStack_74 = (undefined4 ***)0x41200000;
    func_0x00086334(*(undefined4 *)(*piVar11 + 0x208),0x41400000);
    break;
  case 2:
    pppuStack_68 = (undefined4 ***)(*piVar11 + 0x50);
    pppuStack_6c = (undefined4 ***)0x1059a7;
    UTIL_MakeVectors__FRC6Vector();
    pppuStack_6c = (undefined4 ***)0x43960000;
    ppfStack_70 = (float **)0x42c80000;
    pppuStack_74 = (undefined4 ***)0x1059bf;
    lVar12 = (longdouble)(*DAT_0019f80c)();
    ppfStack_2c = (float **)(float)((longdouble)gpGlobals[10] * lVar12);
    ppfStack_28 = (float **)(float)((longdouble)gpGlobals[0xb] * lVar12);
    ppfStack_24 = (float **)(float)(lVar12 * (longdouble)gpGlobals[0xc]);
    iVar5 = *piVar11;
    ppfStack_20 = (float **)
                  (float)((longdouble)gpGlobals[10] * lVar12 + (longdouble)*(float *)(iVar5 + 8));
    ppfStack_1c = (float **)
                  (float)((longdouble)gpGlobals[0xb] * lVar12 + (longdouble)*(float *)(iVar5 + 0xc))
    ;
    ppfStack_18 = (float **)
                  (float)(lVar12 * (longdouble)gpGlobals[0xc] + (longdouble)*(float *)(iVar5 + 0x10)
                         );
    pppuStack_68 = (undefined4 ***)0x42c80000;
    pppuStack_6c = (undefined4 ***)0xc2c80000;
    ppfStack_70 = (float **)0x105a36;
    ppfStack_14 = ppfStack_20;
    ppfStack_10 = ppfStack_1c;
    ppfStack_c = ppfStack_18;
    lVar12 = (longdouble)(*DAT_0019f80c)();
    ppfStack_20 = (float **)(float)((longdouble)gpGlobals[0x10] * lVar12);
    ppfStack_1c = (float **)(float)((longdouble)gpGlobals[0x11] * lVar12);
    ppfStack_18 = (float **)(float)(lVar12 * (longdouble)gpGlobals[0x12]);
    ppfStack_2c = (float **)
                  (float)((longdouble)gpGlobals[0x10] * lVar12 + (longdouble)(float)ppfStack_14);
    ppfStack_28 = (float **)
                  (float)((longdouble)gpGlobals[0x11] * lVar12 + (longdouble)(float)ppfStack_10);
    ppfStack_24 = (float **)
                  (float)(lVar12 * (longdouble)gpGlobals[0x12] + (longdouble)(float)ppfStack_c);
    pppuStack_68 = *(undefined4 ****)(*piVar11 + 0x208);
    pppuStack_6c = (undefined4 ***)0x0;
    ppfStack_70 = (float **)0x17;
    pppuStack_74 = (undefined4 ***)0x1;
    ppfStack_14 = ppfStack_2c;
    ppfStack_10 = ppfStack_28;
    ppfStack_c = ppfStack_24;
    (*DAT_0019f758)();
    pppuStack_68 = (undefined4 ***)0x3;
    pppuStack_6c = (undefined4 ***)0x105ab8;
    (*DAT_0019f760)();
    pppuStack_6c = (undefined4 ***)ppfStack_14;
    ppfStack_70 = (float **)0x105acf;
    (*DAT_0019f774)();
    ppfStack_70 = ppfStack_10;
    pppuStack_74 = (undefined4 ***)0x105ae6;
    (*DAT_0019f774)();
    pppuStack_74 = (undefined4 ***)ppfStack_c;
    (*DAT_0019f774)();
    (*DAT_0019f768)((int)g_sModelIndexFireball);
    (*DAT_0019f760)(0x14);
    (*DAT_0019f760)(0xc);
    (*DAT_0019f760)(3);
    ppppuVar10 = (undefined4 ****)&stack0xffffff9c;
    goto LAB_001063b0;
  case 3:
    pppuStack_68 = (undefined4 ***)(*piVar11 + 0x50);
    pppuStack_6c = (undefined4 ***)&UNK_00105b67;
    UTIL_MakeVectors__FRC6Vector();
    iVar5 = *piVar11;
    ppfStack_2c = *(float ***)(iVar5 + 8);
    ppfStack_28 = *(float ***)(iVar5 + 0xc);
    ppfStack_24 = *(float ***)(iVar5 + 0x10);
    pppuStack_6c = (undefined4 ***)0x43000000;
    ppfStack_70 = (float **)0x0;
    pppuStack_74 = (undefined4 ***)&UNK_00105b90;
    lVar12 = (longdouble)(*DAT_0019f80c)();
    ppfStack_24 = (float **)(float)(lVar12 + (longdouble)(float)ppfStack_24);
    pppuStack_74 = (undefined4 ***)0x43000000;
    lVar12 = (longdouble)(*DAT_0019f80c)(0xc3000000);
    ppfStack_38 = (float **)(float)((longdouble)gpGlobals[0x10] * lVar12);
    ppfStack_34 = (float **)(float)((longdouble)gpGlobals[0x11] * lVar12);
    fStack_30 = (float)(lVar12 * (longdouble)gpGlobals[0x12]);
    ppfStack_2c = (float **)
                  (float)((longdouble)gpGlobals[0x10] * lVar12 + (longdouble)(float)ppfStack_2c);
    ppfStack_28 = (float **)
                  (float)((longdouble)gpGlobals[0x11] * lVar12 + (longdouble)(float)ppfStack_28);
    ppfStack_24 = (float **)
                  (float)(lVar12 * (longdouble)gpGlobals[0x12] + (longdouble)(float)ppfStack_24);
    iVar5 = *piVar11;
    fVar1 = *(float *)(iVar5 + 0x20);
    fVar2 = *(float *)(iVar5 + 0x24);
    fVar3 = *(float *)(iVar5 + 0x28);
    pppuStack_68 = (undefined4 ***)0x3;
    pppuStack_6c = (undefined4 ***)0x0;
    ppfStack_70 = (float **)&UNK_00105c2f;
    ppfStack_14 = ppfStack_2c;
    ppfStack_10 = ppfStack_28;
    ppfStack_c = ppfStack_24;
    uVar6 = (*DAT_0019f808)();
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
      goto code_r0x00105c79;
    }
    sStack_46 = *psVar7;
code_r0x00105c79:
    pppuStack_68 = &ppfStack_2c;
    pppuStack_6c = (undefined4 ***)&UNK_00105c82;
    iVar5 = UTIL_PointContents__FRC6Vector();
    if (iVar5 == -2) {
      return;
    }
    iVar5 = *piVar11;
    ppfStack_20 = *(float ***)(iVar5 + 0x74);
    ppfStack_1c = *(float ***)(iVar5 + 0x78);
    ppfStack_18 = *(float ***)(iVar5 + 0x7c);
    pppuStack_68 = (undefined4 ***)0x42480000;
    pppuStack_6c = (undefined4 ***)0xc2480000;
    ppfStack_70 = (float **)&UNK_00105cba;
    lVar12 = (longdouble)(*DAT_0019f80c)();
    ppfStack_70 = (float **)(float)(lVar12 + (longdouble)(float)ppfStack_1c);
    pppuStack_74 = (undefined4 ***)&UNK_00105cc8;
    lVar12 = (longdouble)UTIL_AngleMod__Ff();
    pppuStack_74 = &ppfStack_20;
    ppfStack_1c = (float **)(float)lVar12;
    UTIL_MakeVectors__FRC6Vector();
    lVar12 = (longdouble)(*DAT_0019f80c)(0x43480000,0x43c80000);
    lVar12 = lVar12 + (longdouble)SQRT(fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1);
    ppfStack_38 = (float **)(float)((longdouble)gpGlobals[10] * lVar12);
    ppfStack_34 = (float **)(float)((longdouble)gpGlobals[0xb] * lVar12);
    fStack_30 = (float)(lVar12 * (longdouble)gpGlobals[0xc]);
    pppuStack_68 = *(undefined4 ****)(*piVar11 + 0x208);
    pppuStack_6c = (undefined4 ***)0x0;
    ppfStack_70 = (float **)0x17;
    pppuStack_74 = (undefined4 ***)0x1;
    (*DAT_0019f758)();
    pppuStack_68 = (undefined4 ***)0x6a;
    pppuStack_6c = (undefined4 ***)0x105d4d;
    (*DAT_0019f760)();
    pppuStack_6c = (undefined4 ***)ppfStack_2c;
    ppfStack_70 = (float **)0x105d64;
    (*DAT_0019f774)();
    ppfStack_70 = ppfStack_28;
    pppuStack_74 = (undefined4 ***)0x105d7b;
    (*DAT_0019f774)();
    pppuStack_74 = (undefined4 ***)ppfStack_24;
    (*DAT_0019f774)();
    (*DAT_0019f774)(ppfStack_38);
    (*DAT_0019f774)(ppfStack_34);
    (*DAT_0019f774)(fStack_30);
    (*DAT_0019f770)(0);
    pppuStack_68 = (undefined4 ***)(int)sStack_46;
    pppuStack_6c = (undefined4 ***)0x105dfd;
    (*DAT_0019f768)();
    ppppuVar9 = &pppuStack_6c;
    pppuStack_6c = (undefined4 ***)0x0;
    goto LAB_00105e7e;
  case 4:
    pppuStack_68 = *(undefined4 ****)(*piVar11 + 0x208);
    pppuStack_6c = (undefined4 ***)0x0;
    ppfStack_70 = (float **)0x17;
    pppuStack_74 = (undefined4 ***)0x1;
    (*DAT_0019f758)();
    pppuStack_68 = (undefined4 ***)0x79;
    pppuStack_6c = (undefined4 ***)&UNK_00105e38;
    (*DAT_0019f760)();
    pppuStack_68 = *(undefined4 ****)(*piVar11 + 0x208);
    pppuStack_6c = (undefined4 ***)&UNK_00105e52;
    pppuStack_68 = (undefined4 ***)(*DAT_0019f7bc)();
    pppuStack_6c = (undefined4 ***)&UNK_00105e5e;
    (*DAT_0019f768)();
    pppuStack_6c = (undefined4 ***)(int)g_sModelIndexPlayerFlame;
    ppfStack_70 = (float **)&UNK_00105e76;
    (*DAT_0019f768)();
    ppppuVar9 = (undefined4 ****)&ppfStack_70;
    ppfStack_70 = (float **)0x5;
LAB_00105e7e:
    *(undefined4 *)((int)ppppuVar9 + -4) = 0x105e86;
    (*DAT_0019f760)();
    ppppuVar10 = (undefined4 ****)((int)ppppuVar9 + -4);
    *(undefined4 *)((int)ppppuVar9 + -4) = 0x19;
LAB_0010639c:
    *(undefined4 *)((int)ppppuVar10 + -4) = 0x1063a4;
    (*DAT_0019f760)();
LAB_001063b0:
    *(undefined4 *)((int)ppppuVar10 + -4) = 0x1063b2;
    (*DAT_0019f75c)();
    break;
  case 5:
    pppuStack_68 = (undefined4 ***)(*piVar11 + 0x74);
    pppuStack_6c = (undefined4 ***)&UNK_00105e9f;
    UTIL_MakeVectors__FRC6Vector();
    gpGlobals[0xc] = 0.0;
    ppfStack_44 = (float **)(gpGlobals[10] * -200.0);
    ppfStack_40 = (float **)(gpGlobals[0xb] * -200.0);
    ppfStack_3c = (float **)(gpGlobals[0xc] * -200.0);
    iVar5 = *piVar11;
    ppfStack_38 = (float **)((float)ppfStack_44 + *(float *)(iVar5 + 8));
    ppfStack_34 = (float **)((float)ppfStack_40 + *(float *)(iVar5 + 0xc));
    fStack_30 = (float)ppfStack_3c + *(float *)(iVar5 + 0x10);
    pppuStack_68 = (undefined4 ***)0x42c80000;
    pppuStack_6c = (undefined4 ***)0xc2c80000;
    ppfStack_70 = (float **)0x105f2b;
    ppfStack_14 = ppfStack_38;
    ppfStack_10 = ppfStack_34;
    ppfStack_c = (float **)fStack_30;
    lVar12 = (longdouble)(*DAT_0019f80c)();
    ppfStack_14 = (float **)(float)((longdouble)gpGlobals[0x10] * lVar12);
    ppfStack_10 = (float **)(float)((longdouble)gpGlobals[0x11] * lVar12);
    ppfStack_c = (float **)(float)(lVar12 * (longdouble)gpGlobals[0x12]);
    ppfStack_44 = (float **)
                  (float)((longdouble)gpGlobals[0x10] * lVar12 + (longdouble)(float)ppfStack_38);
    ppfStack_40 = (float **)
                  (float)((longdouble)gpGlobals[0x11] * lVar12 + (longdouble)(float)ppfStack_34);
    ppfStack_3c = (float **)(float)(lVar12 * (longdouble)gpGlobals[0x12] + (longdouble)fStack_30);
    fStack_30 = *(float *)(*piVar11 + 0x17c) * 0.8 + (float)ppfStack_3c;
    pppuStack_68 = (undefined4 ***)(gpGlobals + 10);
    pppuStack_6c = &ppfStack_44;
    ppfStack_70 = (float **)0x105fa6;
    ppfStack_38 = ppfStack_44;
    ppfStack_34 = ppfStack_40;
    fStack_8 = fStack_30;
    UTIL_VecToAngles__FRC6Vector();
    ppfStack_20 = ppfStack_44;
    ppfStack_1c = ppfStack_40;
    ppfStack_18 = ppfStack_3c;
    ppfStack_70 = (float **)0x40c00000;
    pppuStack_74 = (undefined4 ***)0xc0c00000;
    lVar12 = (longdouble)(*DAT_0019f80c)();
    ppfStack_1c = (float **)(float)(lVar12 + (longdouble)(float)ppfStack_1c);
    iVar5 = UTIL_PointContents__FRC6Vector(&ppfStack_38);
    if (iVar5 != -2) {
      iStack_50 = 0;
      do {
        ppfStack_70 = (float **)0x106001;
        pppuStack_6c = &ppfStack_20;
        UTIL_MakeVectors__FRC6Vector();
        fVar1 = (float)(iStack_50 * -0x14 + 600);
        ppfStack_44 = (float **)(gpGlobals[10] * fVar1);
        ppfStack_40 = (float **)(gpGlobals[0xb] * fVar1);
        ppfStack_3c = (float **)(fVar1 * gpGlobals[0xc]);
        pppuStack_6c = *(undefined4 ****)(*piVar11 + 0x208);
        ppfStack_70 = (float **)0x0;
        pppuStack_74 = (undefined4 ***)0x17;
        ppfStack_2c = ppfStack_44;
        ppfStack_28 = ppfStack_40;
        ppfStack_24 = ppfStack_3c;
        (*DAT_0019f758)(1);
        pppuStack_6c = (undefined4 ***)0x77;
        ppfStack_70 = (float **)0x106085;
        (*DAT_0019f760)();
        ppfStack_70 = ppfStack_38;
        pppuStack_74 = (undefined4 ***)0x10609c;
        (*DAT_0019f774)();
        pppuStack_74 = (undefined4 ***)ppfStack_34;
        (*DAT_0019f774)();
        (*DAT_0019f774)(fStack_30);
        (*DAT_0019f774)(ppfStack_2c);
        (*DAT_0019f774)(ppfStack_28);
        (*DAT_0019f774)(ppfStack_24);
        (*DAT_0019f768)((int)g_sModelIndexNail);
        pppuStack_6c = (undefined4 ***)0x6;
        ppfStack_70 = (float **)0x10613a;
        (*DAT_0019f760)();
        pppuStack_6c = *(undefined4 ****)(*piVar11 + 0x208);
        ppfStack_70 = (float **)0x106154;
        uVar8 = (*DAT_0019f7bc)();
        pppuStack_6c = (undefined4 ***)(uVar8 & 0xff);
        ppfStack_70 = (float **)0x106166;
        (*DAT_0019f760)();
        ppfStack_70 = (float **)0x106174;
        (*DAT_0019f75c)();
        ppfStack_70 = (float **)0x41000000;
        pppuStack_74 = (undefined4 ***)0x40800000;
        lVar12 = (longdouble)(*DAT_0019f80c)();
        ppfStack_1c = (float **)(float)(lVar12 + (longdouble)(float)ppfStack_1c);
        lVar12 = (longdouble)(*DAT_0019f80c)(0xc1200000,0x41200000);
        iStack_50 = iStack_50 + 1;
        fStack_30 = (float)(lVar12 + (longdouble)fStack_30);
      } while (iStack_50 < 3);
    }
    break;
  case 6:
    iVar5 = *piVar11;
    ppfStack_44 = *(float ***)(iVar5 + 0x74);
    ppfStack_40 = *(float ***)(iVar5 + 0x78);
    ppfStack_3c = *(float ***)(iVar5 + 0x7c);
    pppuStack_68 = (undefined4 ***)0x41700000;
    pppuStack_6c = (undefined4 ***)0xc1700000;
    ppfStack_70 = (float **)&UNK_001061f4;
    lVar12 = (longdouble)(*DAT_0019f80c)();
    ppfStack_44 = (float **)(float)(lVar12 + (longdouble)(float)ppfStack_44);
    ppfStack_70 = (float **)0x42480000;
    pppuStack_74 = (undefined4 ***)0xc2480000;
    lVar12 = (longdouble)(*DAT_0019f80c)();
    ppfStack_40 = (float **)(float)(lVar12 + (longdouble)(float)ppfStack_40);
    lVar12 = (longdouble)(*DAT_0019f80c)(0xc1c80000,0x41c80000);
    ppfStack_3c = (float **)(float)(lVar12 + (longdouble)(float)ppfStack_3c);
    UTIL_VecToAngles__FRC6Vector(&ppfStack_38,&ppfStack_44);
    pppuVar4 = DAT_00172864;
    if ((int)DAT_00172864 < 0) {
      return;
    }
    pppuStack_6c = (undefined4 ***)0x15539f;
    ppfStack_70 = *(float ***)(*piVar11 + 0x208);
    pppuStack_74 = (undefined4 ***)&UNK_00106275;
    (*DAT_0019f744)();
    pppuStack_6c = *(undefined4 ****)(*piVar11 + 0x208);
    ppfStack_70 = (float **)0x0;
    pppuStack_74 = (undefined4 ***)0x17;
    (*DAT_0019f758)(1);
    pppuStack_6c = (undefined4 ***)0x7e;
    ppfStack_70 = (float **)0x1062a8;
    (*DAT_0019f760)();
    ppfStack_70 = *(float ***)(*piVar11 + 8);
    pppuStack_74 = (undefined4 ***)0x1062c1;
    (*DAT_0019f774)();
    pppuStack_74 = *(undefined4 ****)(*piVar11 + 0xc);
    (*DAT_0019f774)();
    (*DAT_0019f774)(*(undefined4 *)(*piVar11 + 0x10));
    fStack_8 = (float)ppfStack_44 * 10.0;
    (*DAT_0019f774)(fStack_8);
    fStack_8 = (float)ppfStack_40 * 10.0;
    (*DAT_0019f774)(fStack_8);
    fStack_8 = (float)ppfStack_3c * 10.0;
    (*DAT_0019f774)(fStack_8);
    (*DAT_0019f774)(0x42a00000);
    pppuStack_6c = (undefined4 ***)0x42a00000;
    ppfStack_70 = (float **)0x106385;
    (*DAT_0019f774)();
    ppfStack_70 = (float **)0x6;
    pppuStack_74 = (undefined4 ***)0x106395;
    (*DAT_0019f760)();
    ppppuVar10 = &pppuStack_74;
    pppuStack_74 = pppuVar4;
    goto LAB_0010639c;
  }
  return;
}


// Timer_HealthRot__11CBaseEntity  @ 001056dc
void Timer_HealthRot__11CBaseEntity(int *param_1)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = *(int *)(*param_1 + 0x198);
  if ((iVar4 == 0) && (iVar4 = (*DAT_0019f7b4)(0), iVar4 == 0)) {
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
       (iVar4 = (*DAT_0019f7b8)(*(int *)(*param_1 + 400)), iVar4 == 0)) {
      bVar3 = true;
    }
    if (!bVar3) {
      iVar4 = *(int *)(*param_1 + 400);
      if ((iVar4 == 0) && (iVar4 = (*DAT_0019f7b4)(0), iVar4 == 0)) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(iVar4 + 0x7c);
      }
      (**(code **)(*(int *)(iVar4 + 0x454) + 0xc0))(iVar4);
      return;
    }
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
    iVar4 = *param_1;
    fVar1 = *gpGlobals;
  }
  else {
    *(float *)(iVar4 + 0x160) = fVar1 - 1.0;
    fVar1 = *gpGlobals + 1.0;
    iVar4 = *param_1;
  }
  *(float *)(iVar4 + 0x104) = fVar1;
  return;
}


// Timer_Infection__11CBaseEntity  @ 00105030
void Timer_Infection__11CBaseEntity(int *param_1)

{
  code *pcVar1;
  undefined1 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined1 *puVar7;
  int *piVar8;
  int *piVar9;
  bool bVar10;
  undefined2 in_FPUControlWord;
  int aiStackY_ec [15];
  char *pcStack_94;
  int *piStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined1 auStack_54 [16];
  float fStack_44;
  int iStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_8;
  undefined2 uStack_6;
  
  iVar3 = *(int *)(*param_1 + 0x198);
  if (iVar3 == 0) {
    iVar3 = (*DAT_0019f7b4)(0);
    if (iVar3 != 0) goto LAB_00105070;
    piVar9 = (int *)0x0;
    iVar3 = *param_1;
  }
  else {
LAB_00105070:
    piVar9 = *(int **)(iVar3 + 0x7c);
    iVar3 = *param_1;
  }
  iVar3 = *(int *)(iVar3 + 400);
  if (iVar3 == 0) {
    iVar3 = (*DAT_0019f7b4)(0);
    if (iVar3 == 0) {
      piStack_64 = (int *)0x0;
      goto LAB_001050b7;
    }
  }
  piStack_64 = *(int **)(iVar3 + 0x7c);
LAB_001050b7:
  bVar10 = false;
  uStack_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
  if (((int)ROUND(gpGlobals[7]) & 0x1eU) != 0) {
    if (piVar9[0x48] == piStack_64[0x48]) {
      bVar10 = piVar9[0x48] != 0;
    }
  }
  if (*gpGlobals < (float)piVar9[0x10b]) {
    bVar10 = true;
  }
  if (((piVar9[0x21] & 0x10U) == 0) || (*(int *)(*piVar9 + 0x20c) == 5)) {
    bVar10 = true;
  }
  if (bVar10) {
    piVar9[0x21] = piVar9[0x21] & 0xffffffef;
    param_1[3] = -0x10000;
    param_1[4] = (int)SUB_Remove__11CBaseEntity;
    *(float *)(*param_1 + 0x104) = *gpGlobals;
  }
  else {
    piVar8 = (int *)0x0;
    uStack_1c = *(undefined4 *)(*piVar9 + 8);
    uStack_18 = *(undefined4 *)(*piVar9 + 0xc);
    uStack_14 = *(undefined4 *)(*piVar9 + 0x10);
    puVar2 = &stack0xffffff54;
LAB_00105501:
    puVar7 = puVar2;
    *(undefined4 *)(puVar7 + -4) = 0x43000000;
    *(undefined4 **)(puVar7 + -8) = &uStack_1c;
    *(int **)(puVar7 + -0xc) = piVar8;
    *(undefined4 *)(puVar7 + -0x10) = 0x105510;
    piVar8 = (int *)UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf();
    if (piVar8 != (int *)0x0) {
      iVar3 = piVar8[0x115];
      *(int **)(puVar7 + -4) = piVar8;
      pcVar1 = *(code **)(iVar3 + 0x2c);
      *(undefined4 *)(puVar7 + -8) = 0x1051c8;
      iVar3 = (*pcVar1)();
      puVar2 = puVar7;
      if (iVar3 == 2) {
        iVar3 = piVar8[0x115];
        *(int **)(puVar7 + -4) = piVar8;
        pcVar1 = *(code **)(iVar3 + 0x8c);
        *(undefined4 *)(puVar7 + -8) = 0x1051e3;
        iVar3 = (*pcVar1)();
        if (iVar3 != 0) {
          if (((*(int *)(*piVar8 + 0x20c) != 0) && ((*(byte *)(piVar8 + 0x21) & 0x10) == 0)) &&
             (*(int *)(*piVar8 + 0x20c) != 5)) {
            uStack_10 = CONCAT22(uStack_6,CONCAT11(0xc,(char)in_FPUControlWord));
            if (((int)ROUND(gpGlobals[7]) & 0x1eU) != 0) {
              *(int **)(puVar7 + -4) = piStack_64;
              *(int **)(puVar7 + -8) = piVar8;
              *(undefined4 *)(puVar7 + -0xc) = 0x105249;
              iVar3 = IsAlly__11CBaseEntityP11CBaseEntity();
              if (iVar3 != 0) goto LAB_00105501;
            }
            iVar3 = piVar8[0x115];
            *(undefined4 **)(puVar7 + -4) = &uStack_1c;
            *(int **)(puVar7 + -8) = piVar8;
            *(undefined4 **)(puVar7 + -0xc) = &uStack_60;
            pcVar1 = *(code **)(iVar3 + 0xd8);
            *(undefined4 *)(puVar7 + -0x10) = 0x105271;
            (*pcVar1)();
            *(undefined1 **)(puVar7 + -0x10) = auStack_54;
            *(undefined4 *)(puVar7 + -0x14) = *(undefined4 *)(*param_1 + 0x208);
            *(undefined4 *)(puVar7 + -0x18) = 0;
            *(undefined4 **)(puVar7 + -0x1c) = &uStack_60;
            *(undefined4 **)(puVar7 + -0x20) = &uStack_1c;
            *(undefined4 *)(puVar7 + -0x24) = 0x105290;
            UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult();
            if (((byte)(1.0 < fStack_44 | (byte)((ushort)((ushort)NAN(fStack_44) << 10) >> 8) |
                       (byte)((ushort)((ushort)(fStack_44 == 1.0) << 0xe) >> 8)) == 0x40) ||
               (puVar2 = puVar7 + -4, iStack_24 == *(int *)(*piVar8 + 0x208))) {
              uVar5 = *(undefined4 *)(*piVar8 + 0x208);
              *(undefined4 *)(puVar7 + -8) = 100;
              *(undefined4 *)(puVar7 + -0xc) = 0;
              *(undefined4 *)(puVar7 + -0x10) = 0x3f4ccccd;
              *(undefined4 *)(puVar7 + -0x14) = 0x3f800000;
              *(char **)(puVar7 + -0x18) = "player/death2.wav";
              *(undefined4 *)(puVar7 + -0x1c) = 2;
              *(undefined4 *)(puVar7 + -0x20) = uVar5;
              *(undefined4 *)(puVar7 + -0x24) = 0x1052da;
              EMIT_SOUND_DYN__FP7edict_siPCcffii();
              *(byte *)(piVar8 + 0x21) = *(byte *)(piVar8 + 0x21) | 0x10;
              *(undefined4 *)(puVar7 + -8) = *(undefined4 *)(*piVar8 + 0x208);
              *(undefined4 **)(puVar7 + -0xc) = &g_vecZero;
              *(undefined4 **)(puVar7 + -0x10) = &g_vecZero;
              *(char **)(puVar7 + -0x14) = "timer";
              *(undefined4 *)(puVar7 + -0x18) = 0x105301;
              piVar4 = (int *)Create__11CBaseEntityPcRC6VectorT2P7edict_s();
              piVar4[0x10a] = 2;
              *(float *)(*piVar4 + 0x104) = *gpGlobals + 2.0;
              piVar4[3] = -0x10000;
              piVar4[4] = (int)Timer_Infection__11CBaseEntity;
              *(undefined4 *)(*piVar4 + 400) = *(undefined4 *)(*param_1 + 400);
              piVar8[0x4a] = piVar9[0x48];
              *(undefined4 *)(puVar7 + -8) = 0;
              *(undefined4 *)(puVar7 + -0xc) = 0;
              *(undefined4 *)(puVar7 + -0x10) = 0;
              *(int *)(puVar7 + -0x14) = *(int *)(*piVar9 + 0x1d0) + (int)gpGlobals[0x26];
              *(char **)(puVar7 + -0x18) = "#Medic_infected";
              *(undefined4 *)(puVar7 + -0x1c) = 1;
              *(int *)(puVar7 + -0x20) = *piVar8;
              *(undefined4 *)(puVar7 + -0x24) = 0x1053a3;
              ClientPrint__FP9entvars_siPCcN42();
              *(undefined4 *)(puVar7 + -0x24) = 0;
              *(undefined4 *)(puVar7 + -0x28) = 0;
              *(undefined4 *)(puVar7 + -0x2c) = 0;
              *(int *)(puVar7 + -0x30) = *(int *)(*piVar8 + 0x1d0) + (int)gpGlobals[0x26];
              *(char **)(puVar7 + -0x34) = "#Medic_infect";
              *(undefined4 *)(puVar7 + -0x38) = 1;
              *(int *)(puVar7 + -0x3c) = *piVar9;
              *(undefined4 *)(puVar7 + -0x40) = 0x1053d3;
              ClientPrint__FP9entvars_siPCcN42();
              if (piVar8[0x48] == 0) {
                pcVar6 = "SPECTATOR";
              }
              else {
                *(int *)(puVar7 + -8) = piVar8[0x48];
                *(undefined4 *)(puVar7 + -0xc) = 0x1053ec;
                pcVar6 = (char *)GetTeamName__Fi();
              }
              *(char **)(puVar7 + -8) = pcVar6;
              *(undefined4 *)(puVar7 + -0xc) = *(undefined4 *)(*piVar8 + 0x208);
              *(undefined4 *)(puVar7 + -0x10) = 0x10541e;
              uVar5 = (*DAT_0019f8dc)();
              *(undefined4 *)(puVar7 + -0xc) = uVar5;
              *(undefined4 *)(puVar7 + -0x10) = *(undefined4 *)(*piVar8 + 0x208);
              *(undefined4 *)(puVar7 + -0x14) = 0x10543f;
              uVar5 = (*DAT_0019f864)();
              *(undefined4 *)(puVar7 + -0x10) = uVar5;
              *(int *)(puVar7 + -0x14) = *(int *)(*piVar8 + 0x1d0) + (int)gpGlobals[0x26];
              if (piVar9[0x48] == 0) {
                pcStack_94 = "SPECTATOR";
              }
              else {
                *(int *)(puVar7 + -0x18) = piVar9[0x48];
                *(undefined4 *)(puVar7 + -0x1c) = 0x105478;
                pcStack_94 = (char *)GetTeamName__Fi();
              }
              *(char **)(puVar7 + -0x18) = pcStack_94;
              *(undefined4 *)(puVar7 + -0x1c) = *(undefined4 *)(*piVar9 + 0x208);
              *(undefined4 *)(puVar7 + -0x20) = 0x1054ae;
              uVar5 = (*DAT_0019f8dc)();
              *(undefined4 *)(puVar7 + -0x1c) = uVar5;
              *(undefined4 *)(puVar7 + -0x20) = *(undefined4 *)(*piVar9 + 0x208);
              *(undefined4 *)(puVar7 + -0x24) = 0x1054cf;
              uVar5 = (*DAT_0019f864)();
              *(undefined4 *)(puVar7 + -0x20) = uVar5;
              *(int *)(puVar7 + -0x24) = *(int *)(*piVar9 + 0x1d0) + (int)gpGlobals[0x26];
              *(char **)(puVar7 + -0x28) =
                   "\"%s<%i><%s><%s>\" triggered \"Passed_On_Infection\" against \"%s<%i><%s><%s>\"\n"
              ;
              *(undefined4 *)(puVar7 + -0x2c) = 0x1054fe;
              UTIL_LogPrintf__FPce();
              puVar2 = puVar7 + -4;
            }
          }
        }
      }
      goto LAB_00105501;
    }
    *(float *)(*param_1 + 0x104) = *gpGlobals + 3.0;
    uStack_60 = *(undefined4 *)(*piVar9 + 8);
    uStack_5c = *(undefined4 *)(*piVar9 + 0xc);
    uStack_58 = *(undefined4 *)(*piVar9 + 0x10);
    *(undefined4 *)(puVar7 + -4) = 0x41000000;
    iVar3 = piVar9[0x115];
    *(int **)(puVar7 + -8) = piVar9;
    pcVar1 = *(code **)(iVar3 + 0x44);
    *(undefined4 *)(puVar7 + -0xc) = 0x105562;
    uVar5 = (*pcVar1)();
    *(undefined4 *)(puVar7 + -8) = uVar5;
    *(undefined4 **)(puVar7 + -0xc) = &uStack_60;
    *(undefined4 *)(puVar7 + -0x10) = 0x105571;
    SpawnBlood__FG6Vectorif();
    iVar3 = piVar9[0x115];
    *(int **)(puVar7 + -0x10) = piVar9;
    pcVar1 = *(code **)(iVar3 + 0x8c);
    *(undefined4 *)(puVar7 + -0x14) = 0x105580;
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      iVar3 = piVar9[0x115];
      *(undefined4 *)(puVar7 + -4) = 0x8010000;
      *(undefined4 *)(puVar7 + -8) = 0x41000000;
      *(int *)(puVar7 + -0xc) = *piStack_64;
      *(int *)(puVar7 + -0x10) = *param_1;
      *(int **)(puVar7 + -0x14) = piVar9;
      pcVar1 = *(code **)(iVar3 + 0x38);
      *(undefined4 *)(puVar7 + -0x18) = 0x1055af;
      (*pcVar1)();
      iVar3 = piVar9[0x115];
      *(int **)(puVar7 + -0x18) = piVar9;
      pcVar1 = *(code **)(iVar3 + 0x8c);
      *(undefined4 *)(puVar7 + -0x1c) = 0x1055be;
      iVar3 = (*pcVar1)();
      if (iVar3 == 0) {
        *(char **)(puVar7 + -4) = "infection";
        if (piVar9[0x48] == 0) {
          pcVar6 = "SPECTATOR";
        }
        else {
          *(int *)(puVar7 + -8) = piVar9[0x48];
          *(undefined4 *)(puVar7 + -0xc) = 0x1055e2;
          pcVar6 = (char *)GetTeamName__Fi();
        }
        *(char **)(puVar7 + -8) = pcVar6;
        *(undefined4 *)(puVar7 + -0xc) = *(undefined4 *)(*piVar9 + 0x208);
        *(undefined4 *)(puVar7 + -0x10) = 0x10560a;
        uVar5 = (*DAT_0019f8dc)();
        *(undefined4 *)(puVar7 + -0xc) = uVar5;
        *(undefined4 *)(puVar7 + -0x10) = *(undefined4 *)(*piVar9 + 0x208);
        *(undefined4 *)(puVar7 + -0x14) = 0x105627;
        uVar5 = (*DAT_0019f864)();
        *(undefined4 *)(puVar7 + -0x10) = uVar5;
        *(int *)(puVar7 + -0x14) = *(int *)(*piVar9 + 0x1d0) + (int)gpGlobals[0x26];
        if (piStack_64[0x48] == 0) {
          pcVar6 = "SPECTATOR";
        }
        else {
          *(int *)(puVar7 + -0x18) = piStack_64[0x48];
          *(undefined4 *)(puVar7 + -0x1c) = 0x105659;
          pcVar6 = (char *)GetTeamName__Fi();
        }
        *(char **)(puVar7 + -0x18) = pcVar6;
        *(undefined4 *)(puVar7 + -0x1c) = *(undefined4 *)(*piStack_64 + 0x208);
        *(undefined4 *)(puVar7 + -0x20) = 0x105681;
        uVar5 = (*DAT_0019f8dc)();
        *(undefined4 *)(puVar7 + -0x1c) = uVar5;
        *(undefined4 *)(puVar7 + -0x20) = *(undefined4 *)(*piStack_64 + 0x208);
        *(undefined4 *)(puVar7 + -0x24) = 0x1056a1;
        uVar5 = (*DAT_0019f864)();
        *(undefined4 *)(puVar7 + -0x20) = uVar5;
        *(int *)(puVar7 + -0x24) = *(int *)(*piStack_64 + 0x1d0) + (int)gpGlobals[0x26];
        *(char **)(puVar7 + -0x28) = "\"%s<%i><%s><%s>\" killed \"%s<%i><%s><%s>\" with \"%s\"\n";
        *(undefined4 *)(puVar7 + -0x2c) = 0x1056cf;
        UTIL_LogPrintf__FPce();
      }
    }
  }
  return;
}


// Timer_Regeneration__11CBaseEntity  @ 0010838c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Timer_Regeneration__11CBaseEntity(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if ((iVar1 == 0) && (iVar1 = (*DAT_0019f7b4)(0), iVar1 == 0)) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar1 + 0x7c);
  }
  *(float *)(*param_1 + 0x104) = _FUN_00156930 + *gpGlobals;
  iVar1 = *piVar2;
  if (*(float *)(iVar1 + 0x160) < *(float *)(iVar1 + 0x1b0)) {
    *(float *)(iVar1 + 0x160) = *(float *)(iVar1 + 0x160) + 2.0;
    iVar1 = *piVar2;
    if (*(float *)(iVar1 + 0x1b0) < *(float *)(iVar1 + 0x160)) {
      *(float *)(iVar1 + 0x160) = *(float *)(iVar1 + 0x1b0);
    }
  }
  return;
}


// Timer_SpyUndercoverThink__11CBaseEntity  @ 001074b0
void Timer_SpyUndercoverThink__11CBaseEntity(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_0019f7b4)(0);
    if (iVar1 == 0) {
      puVar3 = (undefined4 *)0x0;
      goto LAB_001074f2;
    }
  }
  puVar3 = *(undefined4 **)(iVar1 + 0x7c);
LAB_001074f2:
  if (puVar3[0x19] == 2) {
    puVar3[99] = *gpGlobals + 10.0;
    if (*(int *)(*param_1 + 0x110) != 0) {
      uVar2 = UTIL_VarArgs__FPce(&DAT_001567ad,(&sClassNames)[*(int *)(*param_1 + 0x110)],0,0,0);
      ClientPrint__FP9entvars_siPCcN42(*puVar3,1,"#Disguise_asclass",uVar2);
      puVar3[0x76] = *(undefined4 *)(*param_1 + 0x110);
    }
    if (param_1[0x48] != 0) {
      uVar2 = UTIL_dtos1__Fi(param_1[0x48],0,0,0);
      ClientPrint__FP9entvars_siPCcN42(*puVar3,1,"#Disguise_asteam",uVar2);
      puVar3[0x75] = param_1[0x48];
    }
    ClientPrint__FP9entvars_siPCcN42(*puVar3,4,"#Disguise_now",0,0,0,0);
    puVar3[0x19] = 1;
    TeamFortress_SpyCalcName__11CBasePlayer(puVar3);
    Spy_DisguiseExternalWeaponModel__11CBasePlayer(puVar3);
    TeamFortress_SetSkin__11CBasePlayer(puVar3);
  }
  dremove__FP11CBaseEntity(param_1);
  return;
}


// Timer_Tranquilisation__11CBaseEntity  @ 00108434
void Timer_Tranquilisation__11CBaseEntity(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(*param_1 + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_0019f7b4)(0);
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)0x0;
      goto LAB_00108476;
    }
  }
  puVar2 = *(undefined4 **)(iVar1 + 0x7c);
LAB_00108476:
  ClientPrint__FP9entvars_siPCcN42(*puVar2,1,"#Tranq_finished",0,0,0,0);
  *(byte *)((int)puVar2 + 0x85) = *(byte *)((int)puVar2 + 0x85) & 0x7f;
  TeamFortress_SetSpeed__11CBasePlayer(puVar2);
  param_1[3] = -0x10000;
  param_1[4] = (int)SUB_Remove__11CBaseEntity;
  *(undefined4 *)(*param_1 + 0x104) = *gpGlobals;
  return;
}


