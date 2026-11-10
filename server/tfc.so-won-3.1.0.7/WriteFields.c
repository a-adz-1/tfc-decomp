// WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi  @ 0011d78c
undefined4
WriteFields__5CSavePCcPvP15TYPEDESCRIPTIONi
          (undefined4 param_1,undefined4 param_2,int param_3,int *param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
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
    piVar5 = param_4 + 3;
    local_11c = param_4 + 2;
    local_128 = (int *)0x0;
    uVar1 = param_5 & 3;
    if (uVar1 != 0) {
      if (1 < uVar1) {
        if (2 < uVar1) {
          iVar2 = DataEmpty__5CSavePCci
                            (param_1,param_3 + param_4[2],
                             (int)(short)param_4[3] * *(int *)(gSizes + *param_4 * 4));
          local_12c = (uint)(iVar2 != 0);
          piVar5 = param_4 + 7;
          local_11c = param_4 + 6;
          local_128 = (int *)0x10;
        }
        local_108 = (uint)(2 < uVar1);
        iVar2 = DataEmpty__5CSavePCci
                          (param_1,param_3 + *local_11c,
                           (int)(short)*piVar5 *
                           *(int *)(gSizes + *(int *)((int)param_4 + (int)local_128) * 4));
        if (iVar2 != 0) {
          local_12c = local_12c + 1;
        }
        piVar5 = piVar5 + 4;
        local_11c = local_11c + 4;
        local_128 = (int *)((int)local_128 + 0x10);
        local_108 = local_108 + 1;
      }
      iVar2 = DataEmpty__5CSavePCci
                        (param_1,param_3 + *local_11c,
                         (int)(short)*piVar5 *
                         *(int *)(gSizes + *(int *)((int)param_4 + (int)local_128) * 4));
      if (iVar2 != 0) {
        local_12c = local_12c + 1;
      }
      piVar5 = piVar5 + 4;
      local_11c = local_11c + 4;
      local_128 = (int *)((int)local_128 + 0x10);
      local_108 = local_108 + 1;
      if ((int)param_5 <= (int)local_108) goto LAB_0011da45;
    }
    local_120 = (int *)((int)local_128 + (int)param_4);
    local_128 = local_11c;
    do {
      iVar2 = DataEmpty__5CSavePCci
                        (param_1,param_3 + *local_128,
                         (int)(short)*piVar5 * *(int *)(gSizes + *local_120 * 4));
      if (iVar2 != 0) {
        local_12c = local_12c + 1;
      }
      iVar2 = DataEmpty__5CSavePCci
                        (param_1,param_3 + local_128[4],
                         (int)(short)piVar5[4] * *(int *)(gSizes + local_120[4] * 4));
      if (iVar2 != 0) {
        local_12c = local_12c + 1;
      }
      iVar2 = DataEmpty__5CSavePCci
                        (param_1,param_3 + local_128[8],
                         (int)(short)piVar5[8] * *(int *)(gSizes + local_120[8] * 4));
      if (iVar2 != 0) {
        local_12c = local_12c + 1;
      }
      iVar2 = DataEmpty__5CSavePCci
                        (param_1,param_3 + local_128[0xc],
                         (int)(short)piVar5[0xc] * *(int *)(gSizes + local_120[0xc] * 4));
      if (iVar2 != 0) {
        local_12c = local_12c + 1;
      }
      piVar5 = piVar5 + 0x10;
      local_128 = local_128 + 0x10;
      local_120 = local_120 + 0x10;
      local_108 = local_108 + 4;
    } while ((int)local_108 < (int)param_5);
  }
LAB_0011da45:
  local_104 = param_5 - local_12c;
  WriteInt__5CSavePCcPCii(param_1,param_2,&local_104,1);
  local_108 = 0;
  if (0 < (int)param_5) {
    local_110 = param_4 + 1;
    local_114 = param_4 + 3;
    local_118 = param_4;
    do {
      iVar6 = param_3 + local_118[2];
      iVar2 = DataEmpty__5CSavePCci
                        (param_1,iVar6,(int)(short)*local_114 * *(int *)(gSizes + *local_118 * 4));
      if (iVar2 != 0) goto LAB_0011de26;
      switch(*local_118) {
      case 0:
        func_0x00083bb4(param_1,*local_110,iVar6,(int)(short)*local_114);
        break;
      case 1:
      case 0x10:
      case 0x11:
        WriteString__5CSavePCcPCii(param_1,*local_110,iVar6,(int)(short)*local_114);
        break;
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
        if (0x40 < (short)*local_114) {
          (*DAT_001c1114)(4,"Can\'t save more than %d entities in an array!!!\n",0x40);
        }
        local_10c = 0;
        if ((short)*local_114 < 1) goto LAB_0011dd09;
        local_128 = local_100;
        iVar2 = 0;
        goto LAB_0011dc28;
      case 7:
        WriteVector__5CSavePCcPCfi(param_1,*local_110,iVar6,(int)(short)*local_114);
        break;
      case 8:
        WritePositionVector__5CSavePCcPCfi(param_1,*local_110,iVar6,(int)(short)*local_114);
        break;
      case 9:
      case 10:
      case 0xc:
        WriteInt__5CSavePCcPCii(param_1,*local_110,iVar6,(int)(short)*local_114);
        break;
      case 0xb:
        WriteFunction__5CSavePCcPCii(param_1,*local_110,iVar6,(int)(short)*local_114);
        break;
      case 0xd:
        iVar4 = (short)*local_114 * 2;
        iVar2 = *local_110;
        goto LAB_0011ddb0;
      case 0xe:
        iVar4 = (int)(short)*local_114;
        iVar2 = *local_110;
LAB_0011ddb0:
        WriteData__5CSavePCciT1(param_1,iVar2,iVar4,iVar6);
        break;
      case 0xf:
        WriteTime__5CSavePCcPCfi(param_1,*local_110,iVar6,(int)(short)*local_114);
        break;
      default:
        (*DAT_001c1114)(4,"Bad field type\n");
      }
LAB_0011de26:
      local_110 = local_110 + 4;
      local_114 = local_114 + 4;
      local_118 = local_118 + 4;
      local_108 = local_108 + 1;
    } while ((int)local_108 < (int)param_5);
  }
  return 1;
LAB_0011dc28:
  switch(*local_118) {
  case 2:
    uVar3 = EntityIndex__18CSaveRestoreBufferi(param_1,*(undefined4 *)(iVar6 + iVar2));
    break;
  case 3:
    uVar3 = EntityIndex__18CSaveRestoreBufferP11CBaseEntity(param_1,*(undefined4 *)(iVar6 + iVar2));
    break;
  case 4:
    uVar3 = __opP11CBaseEntity__7EHANDLE(iVar6 + local_10c * 8);
    uVar3 = EntityIndex__18CSaveRestoreBufferP11CBaseEntity(param_1,uVar3);
    *local_128 = uVar3;
    goto switchD_0011dc43_default;
  case 5:
    uVar3 = EntityIndex__18CSaveRestoreBufferP9entvars_s(param_1,*(undefined4 *)(iVar6 + iVar2));
    break;
  case 6:
    uVar3 = EntityIndex__18CSaveRestoreBufferP7edict_s(param_1,*(undefined4 *)(iVar6 + iVar2));
    break;
  default:
    goto switchD_0011dc43_default;
  }
  *local_128 = uVar3;
switchD_0011dc43_default:
  local_128 = local_128 + 1;
  iVar2 = iVar2 + 4;
  local_10c = local_10c + 1;
  if ((short)*local_114 <= local_10c) {
LAB_0011dd09:
    uVar3 = FUN_0011ddc9((int)(short)*local_114);
    return uVar3;
  }
  goto LAB_0011dc28;
}


