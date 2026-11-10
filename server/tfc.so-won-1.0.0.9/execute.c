// execute_cfa_insn  @ 00120e20
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

ushort * execute_cfa_insn(ushort *param_1,undefined4 *param_2,int param_3,int *param_4)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  ushort *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 uStack_10;
  uint uStack_c;
  int iStack_8;
  
  bVar1 = *(byte *)param_1;
  uVar2 = (uint)bVar1;
  puVar5 = (ushort *)((int)param_1 + 1);
  if ((bVar1 & 0x40) != 0) {
    *param_4 = *param_4 + (uVar2 & 0x3f) * *(int *)(param_3 + 8);
    puVar5 = (ushort *)FUN_0012115c();
    return puVar5;
  }
  if (-1 < (char)bVar1) {
    if ((bVar1 & 0xc0) == 0) {
      switch(uVar2) {
      case 0:
      case 7:
      case 8:
        break;
      case 1:
        *param_4 = *(int *)puVar5;
        puVar5 = (ushort *)FUN_0012115c();
        return puVar5;
      case 2:
        *param_4 = *param_4 + (uint)(byte)*puVar5;
        puVar5 = (ushort *)((int)param_1 + 2);
        break;
      case 3:
        *param_4 = *param_4 + (uint)*puVar5;
        puVar5 = (ushort *)((int)param_1 + 3);
        break;
      case 4:
        *param_4 = *param_4 + *(int *)puVar5;
        puVar5 = (ushort *)((int)param_1 + 5);
        break;
      case 5:
        uVar3 = decode_uleb128(puVar5,&uStack_c);
        decode_uleb128(uVar3,&iStack_8);
        iStack_8 = iStack_8 * *(int *)(param_3 + 0xc);
        *(undefined1 *)(uStack_c + 0x5c + (int)param_2) = 1;
        param_2[uStack_c + 4] = iStack_8;
        puVar5 = (ushort *)FUN_0012115c();
        return puVar5;
      case 6:
        puVar5 = (ushort *)decode_uleb128(puVar5,&uStack_c);
        *(undefined1 *)(uStack_c + 0x5c + (int)param_2) = 0;
        break;
      case 9:
        uVar3 = decode_uleb128(puVar5,&uStack_c);
        puVar5 = (ushort *)decode_uleb128(uVar3,&uStack_10);
        *(undefined1 *)(uStack_c + 0x5c + (int)param_2) = 2;
        param_2[uStack_c + 4] = uStack_10;
        break;
      case 10:
        puVar4 = malloc(0x74);
        puVar7 = param_2;
        puVar8 = puVar4;
        for (iVar6 = 0x1d; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        param_2[0x1c] = puVar4;
        break;
      case 0xb:
        puVar7 = (undefined4 *)param_2[0x1c];
        puVar8 = puVar7;
        for (iVar6 = 0x1d; iVar6 != 0; iVar6 = iVar6 + -1) {
          *param_2 = *puVar8;
          puVar8 = puVar8 + 1;
          param_2 = param_2 + 1;
        }
        free(puVar7);
        break;
      case 0xc:
        uVar3 = decode_uleb128(puVar5,&uStack_c);
        puVar5 = (ushort *)decode_uleb128(uVar3,&iStack_8);
        *(undefined2 *)(param_2 + 0x16) = (undefined2)uStack_c;
        param_2[2] = iStack_8;
        break;
      case 0xd:
        decode_uleb128(puVar5,&uStack_c);
        *(short *)(param_2 + 0x16) = (short)uStack_c;
        puVar5 = (ushort *)FUN_0012115c();
        return puVar5;
      case 0xe:
        puVar5 = (ushort *)decode_uleb128(puVar5,&iStack_8);
        param_2[2] = iStack_8;
        break;
      default:
                    /* WARNING: Subroutine does not return */
        abort();
      case 0x2d:
        uStack_c = 0x10;
        do {
          *(undefined1 *)((int)param_2 + uStack_c + 0x5c) = 1;
          uVar2 = uStack_c + 1;
          param_2[uStack_c + 4] = uStack_c * 4 + -0x40;
          uStack_c = uVar2;
        } while (uVar2 < 0x20);
        break;
      case 0x2e:
        decode_uleb128(puVar5,&iStack_8);
        param_2[3] = iStack_8;
        puVar5 = (ushort *)FUN_0012115c();
        return puVar5;
      }
      param_1 = puVar5;
      return param_1;
    }
    uStack_c = uVar2 & 0x3f;
    *(undefined1 *)(uStack_c + 0x5c + (int)param_2) = 0;
    puVar5 = (ushort *)FUN_0012115c();
    return puVar5;
  }
  uStack_c = uVar2 & 0x3f;
  puVar5 = (ushort *)FUN_00120fb0();
  return puVar5;
}


