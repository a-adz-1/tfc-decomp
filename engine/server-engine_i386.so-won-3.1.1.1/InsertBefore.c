// InsertBefore__t10CUtlVector1ZPQ212CInitTracker8InitFunciRCPQ212CInitTracker8InitFunc  @ 000dac88
undefined4
InsertBefore__t10CUtlVector1ZPQ212CInitTracker8InitFunciRCPQ212CInitTracker8InitFunc
          (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xdac95;
  GrowVector__t10CUtlVector1ZPQ212CInitTracker8InitFunci(param_1,1);
  ShiftElementsRight__t10CUtlVector1ZPQ212CInitTracker8InitFuncii(param_1,param_2,1,uVar1);
  uVar1 = Element__t10CUtlVector1ZPQ212CInitTracker8InitFunci(param_1,param_2);
  CopyConstruct__H1ZPQ212CInitTracker8InitFunc_PX01RCX01_v(uVar1,param_3);
  return param_2;
}


// InsertBefore__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii  @ 000db9f4
undefined4
InsertBefore__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii
          (undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint in_stack_ffffffd8;
  undefined4 uVar2;
  
  uVar2 = 0xdba01;
  uVar1 = Alloc__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZib
                    (param_1,in_stack_ffffffd8 & 0xffff0000);
  LinkBefore__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZiii
            (param_1,param_2,uVar1,uVar2);
  uVar2 = Element__t14CUtlLinkedList2ZQ219CServerRemoteAccess14DataResponse_tZii(param_1,uVar1);
  Construct__H1ZQ219CServerRemoteAccess14DataResponse_t_PX01_v(uVar2);
  return uVar1;
}


