// CheckSentry__12CTFSentrygun  @ 000ea2c0
undefined4 CheckSentry__12CTFSentrygun(int *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined4 uVar8;
  
  iVar5 = __opi__7EHANDLE(param_1 + 0x26);
  if (iVar5 != 0) {
    piVar6 = (int *)__rf__7EHANDLE(param_1 + 0x26);
    iVar5 = *param_1;
    iVar1 = *piVar6;
    fVar2 = *(float *)(iVar5 + 8) - *(float *)(iVar1 + 8);
    fVar4 = *(float *)(iVar5 + 0xc) - *(float *)(iVar1 + 0xc);
    fVar3 = *(float *)(iVar5 + 0x10) - *(float *)(iVar1 + 0x10);
    fVar2 = SQRT(fVar3 * fVar3 + fVar4 * fVar4 + fVar2 * fVar2);
    if ((byte)(64.0 < fVar2 | (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == 64.0) << 0xe) >> 8)) != 1) {
      return 1;
    }
  }
  piVar6 = param_1 + 0x51;
  piVar7 = (int *)__rf__7EHANDLE(piVar6,0,0,0);
  UTIL_ClientPrintAll__FiPCcN41
            (1,"#Sentry_malfunc",*(int *)(*piVar7 + 0x1b0) + *(int *)(gpGlobals + 0x98));
  piVar7 = (int *)__rf__7EHANDLE(piVar6);
  uVar8 = (*DAT_00175684)(*(undefined4 *)(*piVar7 + 0x1e8));
  piVar6 = (int *)__rf__7EHANDLE(piVar6,uVar8);
  UTIL_LogPrintf__FPce
            ("\"%s<%i>\" had a \"sentry\" malfunction.\n",
             *(int *)(*piVar6 + 0x1b0) + *(int *)(gpGlobals + 0x98));
  (**(code **)(param_1[0xf2] + 0x3c))(param_1,0,0);
  return 0;
}


