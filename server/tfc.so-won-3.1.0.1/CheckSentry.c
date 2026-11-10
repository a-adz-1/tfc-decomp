// CheckSentry__12CTFSentrygun  @ 000df748
int CheckSentry__12CTFSentrygun(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined4 uVar9;
  int local_14;
  
  local_14 = 1;
  iVar6 = __opi__7EHANDLE(param_1 + 0x26);
  if (iVar6 != 0) {
    piVar7 = (int *)__rf__7EHANDLE(param_1 + 0x26);
    iVar6 = *param_1;
    iVar5 = *piVar7;
    fVar1 = *(float *)(iVar6 + 8) - *(float *)(iVar5 + 8);
    fVar3 = *(float *)(iVar6 + 0xc) - *(float *)(iVar5 + 0xc);
    fVar2 = *(float *)(iVar6 + 0x10) - *(float *)(iVar5 + 0x10);
    if (SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1) <= 64.0) goto LAB_000df7eb;
  }
  local_14 = 0;
LAB_000df7eb:
  piVar7 = (int *)0x0;
  while (piVar7 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar7,"func_nobuild"),
        piVar7 != (int *)0x0) {
    iVar6 = *param_1;
    iVar5 = *piVar7;
    fVar1 = *(float *)(iVar6 + 8);
    fVar2 = *(float *)(iVar5 + 0xdc);
    if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
      fVar2 = *(float *)(iVar6 + 0xc);
      fVar3 = *(float *)(iVar5 + 0xe0);
      if ((byte)(fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) != 1) {
        fVar3 = *(float *)(iVar6 + 0x10);
        fVar4 = *(float *)(iVar5 + 0xe4);
        if (((((byte)(fVar3 < fVar4 |
                      (byte)((ushort)((ushort)(NAN(fVar3) || NAN(fVar4)) << 10) >> 8) |
                     (byte)((ushort)((ushort)(fVar3 == fVar4) << 0xe) >> 8)) != 1) &&
             (fVar1 <= *(float *)(iVar5 + 0xe8))) && (fVar2 <= *(float *)(iVar5 + 0xec))) &&
           (fVar3 <= *(float *)(iVar5 + 0xf0))) {
          local_14 = 0;
        }
      }
    }
  }
  if (local_14 == 0) {
    piVar7 = param_1 + 0x51;
    piVar8 = (int *)__rf__7EHANDLE(piVar7,0,0,0);
    UTIL_ClientPrintAll__FiPCcN41
              (1,"#Sentry_malfunc",*(int *)(*piVar8 + 0x1d0) + *(int *)(gpGlobals + 0x98));
    piVar8 = (int *)__rf__7EHANDLE(piVar7);
    uVar9 = (*DAT_001a8004)(*(undefined4 *)(*piVar8 + 0x208));
    piVar7 = (int *)__rf__7EHANDLE(piVar7,uVar9);
    UTIL_LogPrintf__FPce
              ("\"%s<%i>\" had a \"sentry\" malfunction.\n",
               *(int *)(*piVar7 + 0x1d0) + *(int *)(gpGlobals + 0x98));
    (**(code **)(param_1[0xf5] + 0x3c))(param_1,0,0);
  }
  return local_14;
}


