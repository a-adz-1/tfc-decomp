// FlameThink__8CTFFlame  @ 000d90f4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FlameThink__8CTFFlame(int *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar4 = *(int *)(*param_1 + 0x198) + 0x80;
  if (*(int *)(*param_1 + 0x198) == 0) {
    iVar4 = 0;
  }
  iVar4 = *(int *)(iVar4 + 0x208);
  if ((iVar4 == 0) && (iVar4 = (*DAT_001a7f54)(0), iVar4 == 0)) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = *(int **)(iVar4 + 0x7c);
  }
  iVar4 = *(int *)(*param_1 + 400) + 0x80;
  if (*(int *)(*param_1 + 400) == 0) {
    iVar4 = 0;
  }
  iVar4 = *(int *)(iVar4 + 0x208);
  if ((iVar4 == 0) && (iVar4 = (*DAT_001a7f54)(0), iVar4 == 0)) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = *(int **)(iVar4 + 0x7c);
  }
  (*DAT_001a7ef8)(4,0x17,*piVar6 + 8,0);
  (*DAT_001a7f00)(0x79);
  uVar3 = (*DAT_001a7f5c)(*(undefined4 *)(*piVar6 + 0x208));
  (*DAT_001a7f08)(uVar3);
  (*DAT_001a7f08)((int)g_sModelIndexPlayerFlame);
  (*DAT_001a7f00)(5);
  (*DAT_001a7f00)(0x32);
  (*DAT_001a7efc)();
  fVar1 = (float)piVar6[0x72];
  if ((byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) != 0x40) {
    fVar1 = *(float *)(*piVar6 + 0x160);
    if (0x3f < (byte)((_FUN_0013ba5c < fVar1 |
                       (byte)((ushort)((ushort)(NAN(_FUN_0013ba5c) || NAN(fVar1)) << 10) >> 8) |
                      (byte)((ushort)((ushort)(_FUN_0013ba5c == fVar1) << 0xe) >> 8)) - 1)) {
      iVar4 = *param_1;
      local_c = *(undefined4 *)(iVar4 + 8);
      local_8 = *(undefined4 *)(iVar4 + 0xc);
      local_4 = *(undefined4 *)(iVar4 + 0x10);
      if (piVar5 == (int *)0x0) {
        iVar4 = *param_1;
      }
      else {
        iVar4 = *piVar5;
      }
      RadiusDamage__FG6VectorP9entvars_sT1ffii
                (&local_c,*param_1,iVar4,0x41200000,0x41200000,0,0x4000008);
      piVar6[0x72] = 0;
      FlameDestroy__8CTFFlame(param_1);
      return;
    }
    if (((*(byte *)(piVar6 + 0xe) & 0x10) == 0) || (*(float *)(*piVar6 + 0x1bc) <= 0.0)) {
      if ((*(byte *)((int)piVar6 + 0x86) & 2) != 0) {
        *(float *)(*param_1 + 0x160) = *gpGlobals + 4.5;
        *(byte *)((int)piVar6 + 0x86) = *(byte *)((int)piVar6 + 0x86) & 0xfd;
      }
      fVar1 = *gpGlobals;
      fVar2 = (float)param_1[0x187];
      if ((byte)(fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) != 1) {
        if (*(float *)(*param_1 + 0x160) < *gpGlobals) {
          piVar6[0x72] = 0;
          goto LAB_000d939f;
        }
        iVar4 = (**(code **)(piVar6[0xf5] + 0x88))(piVar6);
        if (iVar4 != 0) {
          iVar4 = *(int *)(*param_1 + 0x198) + 0x80;
          if (*(int *)(*param_1 + 0x198) == 0) {
            iVar4 = 0;
          }
          (**(code **)(piVar6[0xf5] + 0x34))(piVar6,*param_1,iVar4,piVar6[0x72],8);
          iVar4 = (**(code **)(piVar6[0xf5] + 0x88))(piVar6);
          if (iVar4 == 0) {
            uVar3 = (*DAT_001a8004)(*(undefined4 *)(*piVar6 + 0x208),"flames");
            uVar3 = (*DAT_001a8004)(*(undefined4 *)(*piVar5 + 0x208),
                                    *(int *)(*piVar6 + 0x1d0) + (int)gpGlobals[0x26],uVar3);
            UTIL_LogPrintf__FPce
                      ("\"%s<%i>\" killed \"%s<%i>\" with \"%s\"\n",
                       *(int *)(*piVar5 + 0x1d0) + (int)gpGlobals[0x26],uVar3);
          }
        }
        param_1[0x187] = (int)(_FUN_0013ba5c + *gpGlobals);
      }
      *(float *)(*param_1 + 0x104) = *gpGlobals + 0.2;
      return;
    }
    piVar6[0x72] = (int)((float)piVar6[0x72] - _FUN_0013ba5c);
  }
LAB_000d939f:
  FlameDestroy__8CTFFlame(param_1);
  return;
}


