// Look__12CBaseMonsteri  @ 000bb134
void Look__12CBaseMonsteri(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  uint uVar6;
  int local_1c4;
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
  
  uVar6 = 0;
  param_1[0x13e] = param_1[0x13e] & 0xff9fffe1;
  iVar2 = *param_1;
  param_1[2] = 0;
  if ((*(byte *)(iVar2 + 0x1a0) & 0x10) == 0) {
    local_1a0 = (float)param_2;
    local_1ac = *(float *)(iVar2 + 8) + local_1a0;
    local_1a8 = *(float *)(iVar2 + 0xc) + local_1a0;
    local_1a4 = *(float *)(iVar2 + 0x10) + local_1a0;
    local_1b8 = *(float *)(iVar2 + 8) - local_1a0;
    local_1b4 = *(float *)(iVar2 + 0xc) - local_1a0;
    local_1b0 = *(float *)(iVar2 + 0x10) - local_1a0;
    local_19c = local_1a0;
    local_198 = local_1a0;
    iVar2 = UTIL_EntitiesInBox__FPP11CBaseEntityiRC6VectorT2i
                      (local_194,100,&local_1b8,&local_1ac,0x28);
    local_1c4 = 0;
    if (0 < iVar2) {
      do {
        piVar1 = (int *)local_194[local_1c4];
        if (((((piVar1 != param_1) && ((*(byte *)(*piVar1 + 0x1a0) & 0x10) == 0)) &&
             (0.0 < *(float *)(*piVar1 + 0x160))) &&
            ((iVar3 = (**(code **)(param_1[0x115] + 0x120))(param_1,piVar1), iVar3 != 0 &&
             (iVar3 = (**(code **)(param_1[0x115] + 0x138))(param_1,piVar1), iVar3 != 0)))) &&
           ((-1 < *(char *)(*piVar1 + 0x1a4) &&
            (iVar3 = (**(code **)(param_1[0x115] + 0xe0))(param_1,piVar1), iVar3 != 0)))) {
          if ((*(byte *)(*piVar1 + 0x1a4) & 8) != 0) {
            if ((*(byte *)(*param_1 + 0x1a0) & 1) != 0) {
              iVar3 = (**(code **)(piVar1[0x115] + 0x50))(piVar1);
              if ((piVar1 != (int *)0x0) &&
                 (iVar3 = (**(code **)(*(int *)(iVar3 + 0x454) + 0x138))(iVar3,param_1), iVar3 == 0)
                 ) goto switchD_000bb37a_caseD_fffffffe;
              *(byte *)(*param_1 + 0x1a0) = *(byte *)(*param_1 + 0x1a0) & 0xfe;
            }
            uVar6 = uVar6 | 0x200000;
          }
          piVar1[2] = param_1[2];
          param_1[2] = (int)piVar1;
          piVar4 = (int *)__opP11CBaseEntity__7EHANDLE(param_1 + 0x13f);
          if (piVar1 == piVar4) {
            uVar6 = uVar6 | 0x10;
          }
          uVar5 = (**(code **)(param_1[0x115] + 0x120))(param_1,piVar1);
          switch(uVar5) {
          default:
            (*DAT_0019f794)(2,"%s can\'t assess %s\n",*(int *)*param_1 + *(int *)(gpGlobals + 0x98),
                            *(int *)*piVar1 + *(int *)(gpGlobals + 0x98));
            break;
          case 1:
            uVar6 = uVar6 | 8;
            break;
          case 2:
            uVar6 = uVar6 | 2;
            break;
          case 3:
            uVar6 = uVar6 | 0x400000;
            break;
          case 0xfffffffe:
            break;
          case 0xffffffff:
            uVar6 = uVar6 | 4;
          }
        }
switchD_000bb37a_caseD_fffffffe:
        local_1c4 = local_1c4 + 1;
      } while (local_1c4 < iVar2);
    }
  }
  param_1[0x13e] = param_1[0x13e] | uVar6;
  return;
}


