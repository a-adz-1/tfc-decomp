// Look__12CBaseMonsteri  @ 000c1240
void Look__12CBaseMonsteri(int *param_1,int param_2)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  uint uVar7;
  int local_1c0;
  float local_1b8;
  float local_1b4;
  float local_1b0;
  float local_1ac;
  float local_1a8;
  float local_1a4;
  float local_1a0;
  float local_19c;
  float local_198;
  undefined4 local_194 [100];
  
  uVar7 = 0;
  param_1[0x11b] = param_1[0x11b] & 0xff9fffe1;
  param_1[2] = 0;
  iVar3 = *param_1;
  if ((*(byte *)(iVar3 + 0x180) & 0x10) == 0) {
    local_1a0 = (float)param_2;
    local_1ac = *(float *)(iVar3 + 8) + local_1a0;
    local_1a8 = *(float *)(iVar3 + 0xc) + local_1a0;
    local_1a4 = *(float *)(iVar3 + 0x10) + local_1a0;
    local_1b8 = *(float *)(iVar3 + 8) - local_1a0;
    local_1b4 = *(float *)(iVar3 + 0xc) - local_1a0;
    local_1b0 = *(float *)(iVar3 + 0x10) - local_1a0;
    local_19c = local_1a0;
    local_198 = local_1a0;
    iVar3 = UTIL_EntitiesInBox__FPP11CBaseEntityiRC6VectorT2i
                      (local_194,100,&local_1b8,&local_1ac,0x28);
    local_1c0 = 0;
    if (0 < iVar3) {
      do {
        piVar2 = (int *)local_194[local_1c0];
        if (((((piVar2 != param_1) && ((*(byte *)(*piVar2 + 0x180) & 0x10) == 0)) &&
             (fVar1 = *(float *)(*piVar2 + 0x140),
             (byte)(0.0 < fVar1 | (byte)((ushort)((ushort)NAN(fVar1) << 10) >> 8) |
                   (byte)((ushort)((ushort)(fVar1 == 0.0) << 0xe) >> 8)) == 1)) &&
            ((iVar4 = (**(code **)(param_1[0xf2] + 0x118))(param_1,piVar2), iVar4 != 0 &&
             (iVar4 = (**(code **)(param_1[0xf2] + 0x130))(param_1,piVar2), iVar4 != 0)))) &&
           ((-1 < *(char *)(*piVar2 + 0x184) &&
            (iVar4 = (**(code **)(param_1[0xf2] + 0xd8))(param_1,piVar2), iVar4 != 0)))) {
          if ((*(byte *)(*piVar2 + 0x184) & 8) != 0) {
            if ((*(byte *)(*param_1 + 0x180) & 1) != 0) {
              iVar4 = (**(code **)(piVar2[0xf2] + 0x4c))(piVar2);
              if ((piVar2 != (int *)0x0) &&
                 (iVar4 = (**(code **)(*(int *)(iVar4 + 0x3c8) + 0x130))(iVar4,param_1), iVar4 == 0)
                 ) goto switchD_000c144b_caseD_fffffffe;
              *(byte *)(*param_1 + 0x180) = *(byte *)(*param_1 + 0x180) & 0xfe;
            }
            uVar7 = uVar7 | 0x200000;
          }
          piVar2[2] = param_1[2];
          param_1[2] = (int)piVar2;
          piVar5 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x11c);
          if (piVar2 == piVar5) {
            uVar7 = uVar7 | 0x10;
          }
          uVar6 = (**(code **)(param_1[0xf2] + 0x118))(param_1,piVar2);
          switch(uVar6) {
          default:
            (*DAT_001755b4)(2,"%s can\'t assess %s\n",*(int *)*param_1 + *(int *)(gpGlobals + 0x98),
                            *(int *)*piVar2 + *(int *)(gpGlobals + 0x98));
            break;
          case 1:
            uVar7 = uVar7 | 8;
            break;
          case 2:
            uVar7 = uVar7 | 2;
            break;
          case 3:
            uVar7 = uVar7 | 0x400000;
            break;
          case 0xfffffffe:
            break;
          case 0xffffffff:
            uVar7 = uVar7 | 4;
          }
        }
switchD_000c144b_caseD_fffffffe:
        local_1c0 = local_1c0 + 1;
      } while (local_1c0 < iVar3);
    }
  }
  param_1[0x11b] = param_1[0x11b] | uVar7;
  return;
}


