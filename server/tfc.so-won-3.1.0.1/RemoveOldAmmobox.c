// RemoveOldAmmobox__11CBasePlayer  @ 000f4e70
void RemoveOldAmmobox__11CBasePlayer(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = (int *)0x0;
  piVar4 = (int *)0x0;
LAB_000f4eec:
  do {
    piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,"tf_ammobox");
    if (piVar5 == (int *)0x0) {
      if (piVar4 != (int *)0x0) {
        *(undefined4 *)(*piVar4 + 0x104) = *gpGlobals;
      }
      return;
    }
    iVar3 = *(int *)(*piVar5 + 400);
    if ((iVar3 == 0) && (iVar3 = (*DAT_001a7f54)(0), iVar3 == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x7c);
    }
  } while (iVar3 != param_1);
  if (piVar4 != (int *)0x0) goto code_r0x000f4eca;
  goto LAB_000f4ee2;
code_r0x000f4eca:
  fVar1 = (float)piVar4[0xfd];
  fVar2 = (float)piVar5[0xfd];
  if (0x3f < (byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
LAB_000f4ee2:
    piVar4 = piVar5;
  }
  goto LAB_000f4eec;
}


