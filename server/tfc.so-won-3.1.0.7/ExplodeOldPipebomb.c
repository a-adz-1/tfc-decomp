// ExplodeOldPipebomb__11CBasePlayerii  @ 001025bc
void ExplodeOldPipebomb__11CBasePlayerii(int param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = (int *)0x0;
  piVar4 = (int *)0x0;
LAB_0010267e:
  while( true ) {
    do {
      piVar5 = (int *)UTIL_FindEntityByClassname__FP11CBaseEntityPCc(piVar5,"tf_gl_pipebomb");
      if (piVar5 == (int *)0x0) {
        if (piVar4 != (int *)0x0) {
          *(float *)(*piVar4 + 0x104) = *gpGlobals;
        }
        return;
      }
      iVar3 = *(int *)(*piVar5 + 0x198);
      if ((iVar3 == 0) && (iVar3 = (*DAT_001c1134)(0), iVar3 == 0)) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(iVar3 + 0x7c);
      }
    } while (iVar3 != param_1);
    if (param_2 == 0) break;
    if ((param_3 != 0) || ((float)piVar5[0x1ab] + 0.6 <= *gpGlobals)) {
      *(float *)(*piVar5 + 0x104) = *gpGlobals;
    }
  }
  if (piVar4 != (int *)0x0) goto code_r0x0010265c;
  goto LAB_00102674;
code_r0x0010265c:
  fVar1 = (float)piVar4[0x1ab];
  fVar2 = (float)piVar5[0x1ab];
  if (0x3f < (byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8)
                    | (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1)) {
LAB_00102674:
    piVar4 = piVar5;
  }
  goto LAB_0010267e;
}


