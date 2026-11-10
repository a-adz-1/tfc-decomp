// GetEnemy__12CBaseMonster  @ 000c1248
bool GetEnemy__12CBaseMonster(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *local_18;
  
  if ((*(uint *)(param_1 + 0x4f8) & 0x40000a) != 0) {
    piVar2 = (int *)(**(code **)(*(int *)(param_1 + 0x454) + 0x134))(param_1);
    iVar7 = param_1 + 0x4fc;
    piVar3 = (int *)__opP11CBaseEntity__7EHANDLE(iVar7);
    if (((piVar2 != piVar3) && (piVar2 != (int *)0x0)) && (*(int *)(param_1 + 0x580) != 0)) {
      if ((*(byte *)(*(int *)(param_1 + 0x580) + 10) & 1) != 0) {
        iVar4 = __opP11CBaseEntity__7EHANDLE(iVar7);
        if (iVar4 != 0) {
          iVar8 = 0;
          do {
            iVar6 = param_1 + 0x50c + iVar8 * 8;
            iVar5 = __opP11CBaseEntity__7EHANDLE(iVar6);
            if (iVar5 == iVar4) goto LAB_000c1355;
            iVar6 = __opP11CBaseEntity__7EHANDLE(iVar6);
          } while ((iVar6 != 0) && (iVar8 = iVar8 + 1, iVar8 < 4));
          if (iVar8 < 4) {
            __as__7EHANDLEP11CBaseEntity(param_1 + 0x50c + iVar8 * 8,iVar4);
            iVar4 = param_1 + iVar8 * 0xc;
            *(undefined4 *)(iVar4 + 0x52c) = *(undefined4 *)(param_1 + 0x644);
            *(undefined4 *)(iVar4 + 0x530) = *(undefined4 *)(param_1 + 0x648);
            *(undefined4 *)(iVar4 + 0x534) = *(undefined4 *)(param_1 + 0x64c);
          }
        }
LAB_000c1355:
        *(byte *)(param_1 + 0x4fa) = *(byte *)(param_1 + 0x4fa) | 1;
        __as__7EHANDLEP11CBaseEntity(iVar7,piVar2);
        piVar3 = (int *)__rf__7EHANDLE(iVar7);
        iVar7 = *piVar3;
        *(undefined4 *)(param_1 + 0x644) = *(undefined4 *)(iVar7 + 8);
        *(undefined4 *)(param_1 + 0x648) = *(undefined4 *)(iVar7 + 0xc);
        *(undefined4 *)(param_1 + 0x64c) = *(undefined4 *)(iVar7 + 0x10);
      }
      if (*(int *)(*piVar2 + 0x198) != 0) {
        iVar7 = *(int *)(*(int *)(*piVar2 + 0x198) + 0x7c);
        if (iVar7 == 0) {
          local_18 = (int *)0x0;
        }
        else {
          local_18 = (int *)(**(code **)(*(int *)(iVar7 + 0x454) + 0x50))(iVar7);
        }
        if (((local_18 != (int *)0x0) && ((*(byte *)(*local_18 + 0x1a4) & 0x20) != 0)) &&
           (iVar7 = (**(code **)(*(int *)(param_1 + 0x454) + 0x120))(param_1,local_18), iVar7 != 0))
        {
          iVar7 = 0;
          do {
            iVar4 = param_1 + 0x50c + iVar7 * 8;
            piVar2 = (int *)__opP11CBaseEntity__7EHANDLE(iVar4);
            if (piVar2 == local_18) goto LAB_000c1489;
            iVar4 = __opP11CBaseEntity__7EHANDLE(iVar4);
          } while ((iVar4 != 0) && (iVar7 = iVar7 + 1, iVar7 < 4));
          if (iVar7 < 4) {
            __as__7EHANDLEP11CBaseEntity(param_1 + 0x50c + iVar7 * 8,local_18);
            iVar7 = param_1 + iVar7 * 0xc;
            *(undefined4 *)(iVar7 + 0x52c) = *(undefined4 *)(param_1 + 0x644);
            *(undefined4 *)(iVar7 + 0x530) = *(undefined4 *)(param_1 + 0x648);
            *(undefined4 *)(iVar7 + 0x534) = *(undefined4 *)(param_1 + 0x64c);
          }
        }
      }
    }
  }
LAB_000c1489:
  iVar7 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4fc);
  if (iVar7 == 0) {
    iVar7 = 3;
    do {
      iVar4 = param_1 + 0x50c + iVar7 * 8;
      iVar8 = __opP11CBaseEntity__7EHANDLE(iVar4);
      if (iVar8 != 0) {
        iVar8 = __rf__7EHANDLE(iVar4);
        iVar8 = (**(code **)(*(int *)(iVar8 + 0x454) + 0x8c))(iVar8);
        if (iVar8 != 0) {
          uVar1 = *(undefined4 *)(param_1 + 0x510 + iVar7 * 8);
          *(undefined4 *)(param_1 + 0x4fc) = *(undefined4 *)(param_1 + 0x50c + iVar7 * 8);
          *(undefined4 *)(param_1 + 0x500) = uVar1;
          iVar7 = param_1 + iVar7 * 0xc;
          *(undefined4 *)(param_1 + 0x644) = *(undefined4 *)(iVar7 + 0x52c);
          *(undefined4 *)(param_1 + 0x648) = *(undefined4 *)(iVar7 + 0x530);
          *(undefined4 *)(param_1 + 0x64c) = *(undefined4 *)(iVar7 + 0x534);
          if ((*(int *)(param_1 + 0x580) != 0) &&
             ((*(byte *)(*(int *)(param_1 + 0x580) + 10) & 1) != 0)) {
            *(byte *)(param_1 + 0x4fa) = *(byte *)(param_1 + 0x4fa) | 1;
          }
          break;
        }
        __as__7EHANDLEP11CBaseEntity(iVar4,0);
      }
      iVar7 = iVar7 + -1;
    } while (-1 < iVar7);
  }
  iVar7 = __opP11CBaseEntity__7EHANDLE(param_1 + 0x4fc);
  return iVar7 != 0;
}


