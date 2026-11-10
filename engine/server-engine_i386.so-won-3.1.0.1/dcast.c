// dcast__C14__si_type_infoRC9type_infoiPvPC9type_infoT3  @ 000a1d80
undefined4
dcast__C14__si_type_infoRC9type_infoiPvPC9type_infoT3
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  char cVar1;
  
  cVar1 = __eq__C9type_infoRC9type_info(param_1,param_2);
  if (cVar1 == '\0') {
    param_4 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 4) + 0xc))
                        (*(int *)(param_1 + 8),param_2,param_3,param_4,param_5,param_6);
  }
  return param_4;
}


// dcast__C16__user_type_infoRC9type_infoiPvPC9type_infoT3  @ 000a1d50
undefined4
dcast__C16__user_type_infoRC9type_infoiPvPC9type_infoT3
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = __eq__C9type_infoRC9type_info(param_1,param_2);
  uVar2 = 0;
  if (cVar1 != '\0') {
    uVar2 = param_4;
  }
  return uVar2;
}


// dcast__C17__class_type_infoRC9type_infoiPvPC9type_infoT3  @ 000a1df0
int dcast__C17__class_type_infoRC9type_infoiPvPC9type_infoT3
              (int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int local_8;
  
  cVar2 = __eq__C9type_infoRC9type_info(param_1,param_2);
  local_8 = param_4;
  if (cVar2 == '\0') {
    local_8 = 0;
    uVar7 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      do {
        iVar3 = *(int *)(param_1 + 8);
        iVar1 = local_8;
        if ((param_3 == 0) || (*(byte *)(iVar3 + 7 + uVar7 * 8) >> 6 == 1)) {
          puVar6 = (undefined4 *)(param_4 + (*(uint *)(iVar3 + 4 + uVar7 * 8) & 0x1fffffff));
          if ((*(byte *)(iVar3 + 7 + uVar7 * 8) & 0x20) != 0) {
            puVar6 = (undefined4 *)*puVar6;
          }
          iVar3 = (**(code **)(*(int *)(*(int *)(iVar3 + uVar7 * 8) + 4) + 0xc))
                            (*(undefined4 *)(iVar3 + uVar7 * 8),param_2,param_3,puVar6,param_5,
                             param_6);
          if (((iVar3 != 0) && (iVar1 = iVar3, local_8 != 0)) && (iVar1 = local_8, local_8 != iVar3)
             ) {
            if (param_5 == 0) {
              return 0;
            }
            iVar4 = (**(code **)(*(int *)(param_2 + 4) + 0xc))(param_2,param_5,1,local_8,0,0);
            iVar5 = (**(code **)(*(int *)(param_2 + 4) + 0xc))(param_2,param_5,1,iVar3,0,0);
            if (iVar4 == iVar5) {
              return 0;
            }
            if ((iVar4 != param_6) && (iVar1 = iVar3, iVar5 != param_6)) {
              return 0;
            }
          }
        }
        local_8 = iVar1;
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(uint *)(param_1 + 0xc));
    }
  }
  return local_8;
}


