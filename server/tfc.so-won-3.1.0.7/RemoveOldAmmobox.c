// RemoveOldAmmobox__11CBasePlayer  @ 001026ac
void RemoveOldAmmobox__11CBasePlayer(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = (int *)0x0;
  piVar4 = (int *)0x0;
LAB_00102728:
  do {
    piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,"tf_ammobox");
    if (piVar5 == (int *)0x0) {
      if (piVar4 != (int *)0x0) {
        *(undefined4 *)(*piVar4 + 0x104) = *gpGlobals;
      }
      return;
    }
    iVar3 = *(int *)(*piVar5 + 400);
    if ((iVar3 == 0) && (iVar3 = (*DAT_001c1134)(0), iVar3 == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x7c);
    }
  } while (iVar3 != param_1);
  if (piVar4 != (int *)0x0) goto code_r0x00102706;
  goto LAB_0010271e;
code_r0x00102706:
  fVar1 = (float)piVar4[0x119];
  fVar2 = (float)piVar5[0x119];
  if (0x3f < (byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
LAB_0010271e:
    piVar4 = piVar5;
  }
  goto LAB_00102728;
}


