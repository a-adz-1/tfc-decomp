// CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int>::InsertBefore  @ 000c8060
/* DWARF original prototype: int
   InsertBefore(CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int> * this, int before) */

int __thiscall
CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int>::InsertBefore
          (CUtlLinkedList<CServerRemoteAccess::DataResponse_t,_int> *this,int before)

{
  int iVar1;
  int *in_EAX;
  void *pvVar2;
  int iVar3;
  size_t __size;
  int iVar4;
  int iVar5;
  int iVar6;
  
                    /* Unresolved local var: int newNode@[DW_OP_reg6(ESI)]
                       Unresolved local var: int elem@[???] */
  iVar5 = in_EAX[5];
  if (iVar5 == -1) {
    iVar5 = in_EAX[7];
    if (iVar5 == in_EAX[1]) {
                    /* Unresolved local var: int growSize@[???] */
      iVar6 = in_EAX[2];
      if ((in_EAX[2] == 0) && (iVar6 = 1, iVar5 != 0)) {
        iVar6 = iVar5;
      }
      in_EAX[1] = iVar6 + iVar5;
      __size = (iVar6 + iVar5) * 0x20;
      if ((void *)*in_EAX == (void *)0x0) {
        pvVar2 = malloc(__size);
        *in_EAX = (int)pvVar2;
      }
      else {
        pvVar2 = realloc((void *)*in_EAX,__size);
        iVar5 = in_EAX[7];
        *in_EAX = (int)pvVar2;
      }
    }
    else {
      pvVar2 = (void *)*in_EAX;
    }
    iVar6 = iVar5 * 0x20;
    in_EAX[7] = iVar5 + 1;
    pvVar2 = (void *)((int)pvVar2 + iVar6);
  }
  else {
    iVar6 = iVar5 * 0x20;
    pvVar2 = (void *)(*in_EAX + iVar6);
    in_EAX[5] = *(int *)((int)pvVar2 + 0x1c);
  }
  *(int *)((int)pvVar2 + 0x18) = iVar5;
  *(int *)((int)pvVar2 + 0x1c) = iVar5;
  iVar4 = *in_EAX;
  iVar3 = 0;
  if ((CUtlBuffer *)(iVar4 + iVar6) != (CUtlBuffer *)0x0) {
    CUtlBuffer::CUtlBuffer((CUtlBuffer *)(iVar4 + iVar6),0,0,false);
    iVar4 = *in_EAX;
    iVar3 = iVar4 + iVar6;
  }
                    /* Unresolved local var: ListElem_t * newElem@[???] */
  in_EAX[8] = iVar4;
  if (((-1 < iVar5) && (iVar5 < in_EAX[7])) && (iVar1 = *(int *)(iVar3 + 0x18), iVar5 != iVar1)) {
                    /* Unresolved local var: ListElem_t * oldElem@[???] */
    if (iVar1 == -1) {
      in_EAX[3] = *(int *)(iVar3 + 0x1c);
    }
    else {
      *(undefined4 *)(iVar4 + 0x1c + iVar1 * 0x20) = *(undefined4 *)(iVar3 + 0x1c);
    }
    if (*(int *)(iVar3 + 0x1c) == -1) {
      in_EAX[4] = *(int *)(iVar3 + 0x18);
    }
    else {
      *(undefined4 *)(*(int *)(iVar3 + 0x1c) * 0x20 + *in_EAX + 0x18) =
           *(undefined4 *)(iVar3 + 0x18);
    }
    *(int *)(iVar3 + 0x1c) = iVar5;
    *(int *)(iVar3 + 0x18) = iVar5;
    in_EAX[6] = in_EAX[6] + -1;
    iVar3 = *in_EAX + iVar6;
  }
  *(undefined4 *)(iVar3 + 0x1c) = 0xffffffff;
  *(int *)(iVar3 + 0x18) = in_EAX[4];
  in_EAX[4] = iVar5;
  if (*(int *)(iVar3 + 0x18) == -1) {
    in_EAX[3] = iVar5;
  }
  else {
    *(int *)(*(int *)(iVar3 + 0x18) * 0x20 + *in_EAX + 0x1c) = iVar5;
  }
  in_EAX[6] = in_EAX[6] + 1;
  if ((CUtlBuffer *)(iVar6 + *in_EAX) != (CUtlBuffer *)0x0) {
    CUtlBuffer::CUtlBuffer((CUtlBuffer *)(iVar6 + *in_EAX),0,0,false);
  }
  return iVar5;
}


