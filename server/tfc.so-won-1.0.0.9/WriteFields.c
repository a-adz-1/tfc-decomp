// WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi  @ 001194f0
undefined4
WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
          (undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int local_10c;
  int local_108;
  undefined4 local_104 [64];
  
  iVar5 = 0;
  for (local_10c = 0; local_10c < param_5; local_10c = local_10c + 1) {
    iVar2 = local_10c * 0x10;
    iVar2 = DataEmpty__5CSavePCci
                      (param_1,param_3 + *(int *)(param_4 + 8 + iVar2),
                       (int)*(short *)(param_4 + 0xc + iVar2) *
                       *(int *)(gSizes + *(int *)(param_4 + iVar2) * 4));
    if (iVar2 != 0) {
      iVar5 = iVar5 + 1;
    }
  }
  local_108 = param_5 - iVar5;
  WriteInt__5CSavePCcPCii(param_1,param_2,&local_108,1);
  local_10c = 0;
  if (0 < param_5) {
    do {
      piVar6 = (int *)(param_4 + local_10c * 0x10);
      puVar4 = (undefined4 *)(param_3 + piVar6[2]);
      iVar5 = DataEmpty__5CSavePCci
                        (param_1,puVar4,(int)(short)piVar6[3] * *(int *)(gSizes + *piVar6 * 4));
      if (iVar5 != 0) goto LAB_00119881;
      switch(*piVar6) {
      case 0:
        WriteFloat__5CSavePCcPCfi(param_1,piVar6[1],puVar4,(int)(short)piVar6[3]);
        break;
      case 1:
      case 0x10:
      case 0x11:
        WriteString__5CSavePCcPCii(param_1,piVar6[1],puVar4,(int)(short)piVar6[3]);
        break;
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
        if (0x40 < (short)piVar6[3]) {
          (*DAT_001755b4)(4,"Can\'t save more than %d entities in an array!!!\n",0x40);
        }
        iVar5 = 0;
        if (0 < (short)piVar6[3]) {
          do {
            switch(*piVar6) {
            case 2:
              uVar3 = EntityIndex__18CSaveRestoreBufferi(param_1,puVar4[iVar5]);
              break;
            case 3:
              uVar3 = EntityIndex__18CSaveRestoreBufferP11CBaseEntity(param_1,puVar4[iVar5]);
              break;
            case 4:
              uVar3 = __opP11CBaseEntity__7EHANDLE(puVar4 + iVar5 * 2);
              uVar3 = EntityIndex__18CSaveRestoreBufferP11CBaseEntity(param_1,uVar3);
              local_104[iVar5] = uVar3;
              goto switchD_001196b6_default;
            case 5:
              uVar3 = EntityIndex__18CSaveRestoreBufferP9entvars_t(param_1,puVar4[iVar5]);
              break;
            case 6:
              uVar3 = EntityIndex__18CSaveRestoreBufferP7edict_s(param_1,puVar4[iVar5]);
              break;
            default:
              goto switchD_001196b6_default;
            }
            local_104[iVar5] = uVar3;
switchD_001196b6_default:
            iVar5 = iVar5 + 1;
          } while (iVar5 < (short)piVar6[3]);
        }
        sVar1 = (short)piVar6[3];
        puVar4 = local_104;
        goto FUN_0011983c;
      case 7:
        WriteVector__5CSavePCcPCfi(param_1,piVar6[1],puVar4,(int)(short)piVar6[3]);
        break;
      case 8:
        WritePositionVector__5CSavePCcPCfi(param_1,piVar6[1],puVar4,(int)(short)piVar6[3]);
        break;
      case 9:
      case 10:
      case 0xc:
        sVar1 = (short)piVar6[3];
FUN_0011983c:
        WriteInt__5CSavePCcPCii(param_1,piVar6[1],puVar4,(int)sVar1);
        break;
      case 0xb:
        WriteFunction__5CSavePCcPCii(param_1,piVar6[1],puVar4,(int)(short)piVar6[3]);
        break;
      case 0xd:
        iVar5 = (short)piVar6[3] * 2;
        goto LAB_0011981b;
      case 0xe:
        iVar5 = (int)(short)piVar6[3];
LAB_0011981b:
        WriteData__5CSavePCciT1(param_1,piVar6[1],iVar5,puVar4);
        break;
      case 0xf:
        WriteTime__5CSavePCcPCfi(param_1,piVar6[1],puVar4,(int)(short)piVar6[3]);
        break;
      default:
        (*DAT_001755b4)(4,"Bad field type\n");
      }
LAB_00119881:
      local_10c = local_10c + 1;
    } while (local_10c < param_5);
  }
  return 1;
}


