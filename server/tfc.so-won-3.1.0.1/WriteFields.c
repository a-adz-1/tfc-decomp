// WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi  @ 0010dc40
undefined4
WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
          (undefined4 param_1,undefined4 param_2,int param_3,int *param_4,uint param_5)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  uint local_12c;
  int *local_128;
  int *local_120;
  int *local_11c;
  int *local_118;
  int *local_114;
  int *local_110;
  int local_10c;
  uint local_108;
  int local_104;
  undefined4 local_100 [64];
  
  local_12c = 0;
  local_108 = 0;
  if (0 < (int)param_5) {
    piVar6 = param_4 + 3;
    local_11c = param_4 + 2;
    local_128 = (int *)0x0;
    uVar2 = param_5 & 3;
    if (uVar2 != 0) {
      if (1 < uVar2) {
        if (2 < uVar2) {
          iVar3 = DataEmpty__5CSavePCci
                            (param_1,param_3 + param_4[2],
                             (int)(short)param_4[3] * *(int *)(gSizes + *param_4 * 4));
          local_12c = (uint)(iVar3 != 0);
          piVar6 = param_4 + 7;
          local_11c = param_4 + 6;
          local_128 = (int *)0x10;
        }
        local_108 = (uint)(2 < uVar2);
        iVar3 = DataEmpty__5CSavePCci
                          (param_1,param_3 + *local_11c,
                           (int)(short)*piVar6 *
                           *(int *)(gSizes + *(int *)((int)param_4 + (int)local_128) * 4));
        if (iVar3 != 0) {
          local_12c = local_12c + 1;
        }
        piVar6 = piVar6 + 4;
        local_11c = local_11c + 4;
        local_128 = (int *)((int)local_128 + 0x10);
        local_108 = local_108 + 1;
      }
      iVar3 = DataEmpty__5CSavePCci
                        (param_1,param_3 + *local_11c,
                         (int)(short)*piVar6 *
                         *(int *)(gSizes + *(int *)((int)param_4 + (int)local_128) * 4));
      if (iVar3 != 0) {
        local_12c = local_12c + 1;
      }
      piVar6 = piVar6 + 4;
      local_11c = local_11c + 4;
      local_128 = (int *)((int)local_128 + 0x10);
      local_108 = local_108 + 1;
      if ((int)param_5 <= (int)local_108) goto LAB_0010def9;
    }
    local_120 = (int *)((int)local_128 + (int)param_4);
    local_128 = local_11c;
    do {
      iVar3 = DataEmpty__5CSavePCci
                        (param_1,param_3 + *local_128,
                         (int)(short)*piVar6 * *(int *)(gSizes + *local_120 * 4));
      if (iVar3 != 0) {
        local_12c = local_12c + 1;
      }
      iVar3 = DataEmpty__5CSavePCci
                        (param_1,param_3 + local_128[4],
                         (int)(short)piVar6[4] * *(int *)(gSizes + local_120[4] * 4));
      if (iVar3 != 0) {
        local_12c = local_12c + 1;
      }
      iVar3 = DataEmpty__5CSavePCci
                        (param_1,param_3 + local_128[8],
                         (int)(short)piVar6[8] * *(int *)(gSizes + local_120[8] * 4));
      if (iVar3 != 0) {
        local_12c = local_12c + 1;
      }
      iVar3 = DataEmpty__5CSavePCci
                        (param_1,param_3 + local_128[0xc],
                         (int)(short)piVar6[0xc] * *(int *)(gSizes + local_120[0xc] * 4));
      if (iVar3 != 0) {
        local_12c = local_12c + 1;
      }
      piVar6 = piVar6 + 0x10;
      local_128 = local_128 + 0x10;
      local_120 = local_120 + 0x10;
      local_108 = local_108 + 4;
    } while ((int)local_108 < (int)param_5);
  }
LAB_0010def9:
  local_104 = param_5 - local_12c;
  WriteInt__5CSavePCcPCii(param_1,param_2,&local_104,1);
  local_108 = 0;
  if (0 < (int)param_5) {
    local_110 = param_4 + 1;
    local_114 = param_4 + 3;
    local_118 = param_4;
    do {
      puVar7 = (undefined4 *)(param_3 + local_118[2]);
      iVar3 = DataEmpty__5CSavePCci
                        (param_1,puVar7,(int)(short)*local_114 * *(int *)(gSizes + *local_118 * 4));
      if (iVar3 != 0) goto LAB_0010e2da;
      switch(*local_118) {
      case 0:
        WriteFloat__5CSavePCcPCfi(param_1,*local_110,puVar7,(int)(short)*local_114);
        break;
      case 1:
      case 0x10:
      case 0x11:
        WriteString__5CSavePCcPCii(param_1,*local_110,puVar7,(int)(short)*local_114);
        break;
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
        if (0x40 < (short)*local_114) {
          (*DAT_001a7f34)(4,"Can\'t save more than %d entities in an array!!!\n",0x40);
        }
        local_10c = 0;
        if (0 < (short)*local_114) {
          local_128 = local_100;
          iVar3 = 0;
          do {
            switch(*local_118) {
            case 2:
              uVar4 = EntityIndex__18CSaveRestoreBufferi
                                (param_1,*(undefined4 *)((int)puVar7 + iVar3));
              break;
            case 3:
              uVar4 = EntityIndex__18CSaveRestoreBufferP11CBaseEntity
                                (param_1,*(undefined4 *)((int)puVar7 + iVar3));
              break;
            case 4:
              uVar4 = __opP11CBaseEntity__7EHANDLE(puVar7 + local_10c * 2);
              uVar4 = EntityIndex__18CSaveRestoreBufferP11CBaseEntity(param_1,uVar4);
              *local_128 = uVar4;
              goto switchD_0010e0f7_default;
            case 5:
              uVar4 = EntityIndex__18CSaveRestoreBufferP9entvars_s
                                (param_1,*(undefined4 *)((int)puVar7 + iVar3));
              break;
            case 6:
              uVar4 = EntityIndex__18CSaveRestoreBufferP7edict_s
                                (param_1,*(undefined4 *)((int)puVar7 + iVar3));
              break;
            default:
              goto switchD_0010e0f7_default;
            }
            *local_128 = uVar4;
switchD_0010e0f7_default:
            local_128 = local_128 + 1;
            iVar3 = iVar3 + 4;
            local_10c = local_10c + 1;
          } while (local_10c < (short)*local_114);
        }
        sVar1 = (short)*local_114;
        puVar7 = local_100;
        goto LAB_0010e27d;
      case 7:
        WriteVector__5CSavePCcPCfi(param_1,*local_110,puVar7,(int)(short)*local_114);
        break;
      case 8:
        WritePositionVector__5CSavePCcPCfi(param_1,*local_110,puVar7,(int)(short)*local_114);
        break;
      case 9:
      case 10:
      case 0xc:
        sVar1 = (short)*local_114;
LAB_0010e27d:
        WriteInt__5CSavePCcPCii(param_1,*local_110,puVar7,(int)sVar1);
        break;
      case 0xb:
        WriteFunction__5CSavePCcPCii(param_1,*local_110,puVar7,(int)(short)*local_114);
        break;
      case 0xd:
        iVar5 = (short)*local_114 * 2;
        iVar3 = *local_110;
        goto LAB_0010e264;
      case 0xe:
        iVar5 = (int)(short)*local_114;
        iVar3 = *local_110;
LAB_0010e264:
        WriteData__5CSavePCciT1(param_1,iVar3,iVar5,puVar7);
        break;
      case 0xf:
        WriteTime__5CSavePCcPCfi(param_1,*local_110,puVar7,(int)(short)*local_114);
        break;
      default:
        (*DAT_001a7f34)(4,"Bad field type\n");
      }
LAB_0010e2da:
      local_110 = local_110 + 4;
      local_114 = local_114 + 4;
      local_118 = local_118 + 4;
      local_108 = local_108 + 1;
    } while ((int)local_108 < (int)param_5);
  }
  return 1;
}


