// SquadRecruit__13CSquadMonsterii  @ 000f47ac
int SquadRecruit__13CSquadMonsterii(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iStack_64;
  int iStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  undefined1 auStack_3c [16];
  float fStack_2c;
  
  iVar2 = (**(code **)(param_1[0x115] + 0x2c))(param_1);
  piVar7 = param_1 + 0x1a7;
  iVar3 = __opP11CBaseEntity__7EHANDLE(piVar7);
  if ((iVar3 == 0) && (1 < param_3)) {
    __as__7EHANDLEP11CBaseEntity(piVar7,param_1);
    iStack_58 = 1;
    iStack_64 = 0;
    if (*(int *)(*param_1 + 0x1d0) == 0) {
      while (iStack_64 = UTIL_FindEntityInSphere__FP11CBaseEntityRC6Vectorf
                                   (iStack_64,*param_1 + 8,(float)param_2), iStack_64 != 0) {
        piVar4 = (int *)(**(code **)(*(int *)(iStack_64 + 0x454) + 0x54))(iStack_64);
        if ((((piVar4 != (int *)0x0) && (piVar4 != param_1)) &&
            (iVar3 = (**(code **)(piVar4[0x115] + 0x8c))(piVar4), iVar3 != 0)) &&
           (piVar4[0x1a6] == 0)) {
          iVar3 = __opP11CBaseEntity__7EHANDLE(piVar4 + 0x1a7);
          if ((((iVar3 == 0) &&
               (iVar3 = (**(code **)(piVar4[0x115] + 0x2c))(piVar4), iVar3 == iVar2)) &&
              ((iVar2 != 7 ||
               (iVar3 = strcmp((char *)(*(int *)(gpGlobals + 0x98) + *(int *)*param_1),
                               (char *)(*(int *)(gpGlobals + 0x98) + *(int *)*piVar4)), iVar3 == 0))
              )) && (iVar3 = *piVar4, *(int *)(iVar3 + 0x1d0) == 0)) {
            iVar5 = *param_1;
            fStack_48 = *(float *)(iVar3 + 8) + *(float *)(iVar5 + 0x174);
            fStack_44 = *(float *)(iVar3 + 0xc) + *(float *)(iVar5 + 0x178);
            fStack_40 = *(float *)(iVar3 + 0x10) + *(float *)(iVar5 + 0x17c);
            fStack_54 = *(float *)(iVar5 + 8) + *(float *)(iVar5 + 0x174);
            fStack_50 = *(float *)(iVar5 + 0xc) + *(float *)(iVar5 + 0x178);
            fStack_4c = *(float *)(iVar5 + 0x10) + *(float *)(iVar5 + 0x17c);
            UTIL_TraceLine__FRC6VectorT015IGNORE_MONSTERSP7edict_sP11TraceResult
                      (&fStack_54,&fStack_48,1,*(undefined4 *)(*piVar4 + 0x208),auStack_3c);
            if ((byte)((byte)((ushort)((ushort)NAN(fStack_2c) << 10) >> 8) |
                      (byte)((ushort)((ushort)(fStack_2c == 1.0) << 0xe) >> 8)) == 0x40) {
              iVar3 = 0;
              do {
                iVar5 = __opP11CBaseEntity__7EHANDLE(param_1 + iVar3 * 2 + 0x1a9);
                if (iVar5 == 0) {
                  __as__7EHANDLEP11CBaseEntity(param_1 + iVar3 * 2 + 0x1a9,piVar4);
                  __as__7EHANDLEP11CBaseEntity(piVar4 + 0x1a7,param_1);
                  bVar1 = true;
                  goto LAB_000f4b37;
                }
                iVar3 = iVar3 + 1;
              } while (iVar3 < 4);
              bVar1 = false;
LAB_000f4b37:
              if (!bVar1) break;
              iStack_58 = iStack_58 + 1;
            }
          }
        }
      }
    }
    else {
      for (iVar3 = UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                             (0,"netname",*(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98));
          iVar3 != 0;
          iVar3 = UTIL_FindEntityByString__FP11CBaseEntityPCcT1
                            (iVar3,"netname",*(int *)(*param_1 + 0x1d0) + *(int *)(gpGlobals + 0x98)
                            )) {
        piVar4 = (int *)(**(code **)(*(int *)(iVar3 + 0x454) + 0x54))(iVar3);
        if (piVar4 != (int *)0x0) {
          iVar5 = __opP11CBaseEntity__7EHANDLE(piVar4 + 0x1a7);
          if (((iVar5 == 0) && (iVar5 = (**(code **)(piVar4[0x115] + 0x2c))(piVar4), iVar5 == iVar2)
              ) && (piVar4 != param_1)) {
            iVar5 = 0;
            do {
              iVar6 = __opP11CBaseEntity__7EHANDLE(param_1 + iVar5 * 2 + 0x1a9);
              if (iVar6 == 0) {
                __as__7EHANDLEP11CBaseEntity(param_1 + iVar5 * 2 + 0x1a9,piVar4);
                __as__7EHANDLEP11CBaseEntity(piVar4 + 0x1a7,param_1);
                bVar1 = true;
                goto LAB_000f4908;
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 < 4);
            bVar1 = false;
LAB_000f4908:
            if (!bVar1) break;
            iStack_58 = iStack_58 + 1;
          }
        }
      }
    }
    if (iStack_58 == 1) {
      __as__7EHANDLEP11CBaseEntity(piVar7,0);
    }
  }
  else {
    iStack_58 = 0;
  }
  return iStack_58;
}


