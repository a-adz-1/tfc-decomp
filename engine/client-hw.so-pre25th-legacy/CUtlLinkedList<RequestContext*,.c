// CUtlLinkedList<RequestContext*,_short_unsigned_int>::Alloc  @ 00183210
/* DWARF original prototype: ushort Alloc(CUtlLinkedList<RequestContext*,_short_unsigned_int> *
   this, bool multilist) */

ushort __thiscall
CUtlLinkedList<RequestContext*,_short_unsigned_int>::Alloc
          (CUtlLinkedList<RequestContext*,_short_unsigned_int> *this,bool multilist)

{
  int *in_EAX;
  void *pvVar1;
  uint uVar2;
  size_t __size;
  ushort uVar3;
  uint uVar4;
  
                    /* Unresolved local var: ushort elem@[???] */
  uVar4 = (uint)*(ushort *)(in_EAX + 4);
  if (uVar4 == 0xffff) {
    uVar4 = (uint)*(ushort *)(in_EAX + 5);
    if (uVar4 == in_EAX[1]) {
                    /* Unresolved local var: int growSize@[???] */
      uVar2 = in_EAX[2];
      if ((in_EAX[2] == 0) && (uVar2 = 1, uVar4 != 0)) {
        uVar2 = uVar4;
      }
      in_EAX[1] = uVar2 + uVar4;
      __size = (uVar2 + uVar4) * 8;
      if ((void *)*in_EAX == (void *)0x0) {
        pvVar1 = malloc(__size);
        *in_EAX = (int)pvVar1;
      }
      else {
        pvVar1 = realloc((void *)*in_EAX,__size);
        uVar4 = (uint)*(ushort *)(in_EAX + 5);
        *in_EAX = (int)pvVar1;
      }
    }
    else {
      pvVar1 = (void *)*in_EAX;
    }
    *(short *)(in_EAX + 5) = (short)uVar4 + 1;
    pvVar1 = (void *)((int)pvVar1 + uVar4 * 8);
  }
  else {
    pvVar1 = (void *)(uVar4 * 8 + *in_EAX);
    *(undefined2 *)(in_EAX + 4) = *(undefined2 *)((int)pvVar1 + 6);
  }
  uVar3 = (ushort)uVar4;
  *(ushort *)((int)pvVar1 + 4) = uVar3;
  *(ushort *)((int)pvVar1 + 6) = uVar3;
  in_EAX[6] = *in_EAX;
  return uVar3;
}


// CUtlLinkedList<RequestContext*,_short_unsigned_int>::InsertBefore  @ 00184f20
/* DWARF original prototype: ushort InsertBefore(CUtlLinkedList<RequestContext*,_short_unsigned_int>
   * this, ushort before, RequestContext * * src) */

ushort __thiscall
CUtlLinkedList<RequestContext*,_short_unsigned_int>::InsertBefore
          (CUtlLinkedList<RequestContext*,_short_unsigned_int> *this,ushort before,
          RequestContext **src)

{
  ListElem_t *pLVar1;
  ushort uVar2;
  ListElem_t *pLVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  CUtlLinkedList<RequestContext*,_short_unsigned_int> *in_stack_ffffffd4;
  bool in_stack_ffffffd8;
  
  uVar4 = (uint)before;
                    /* Unresolved local var: ushort newNode@[DW_OP_reg0(EAX)] */
  uVar2 = Alloc(in_stack_ffffffd4,in_stack_ffffffd8);
                    /* Unresolved local var: ListElem_t * newElem@[???] */
  uVar5 = (uint)uVar2;
  if (this->m_TotalElements <= uVar2) {
    pLVar3 = (this->m_Memory).m_pMemory + uVar5;
    goto LAB_00184f5f;
  }
  pLVar1 = (this->m_Memory).m_pMemory;
  pLVar3 = pLVar1 + uVar5;
  uVar6 = (uint)pLVar3->m_Previous;
  if (uVar5 == uVar6) goto LAB_00184f5f;
                    /* Unresolved local var: ListElem_t * oldElem@[???] */
  if (uVar6 == 0xffff) {
    this->m_Head = pLVar3->m_Next;
    uVar6 = (uint)pLVar3->m_Next;
    if (uVar6 == 0xffff) goto LAB_00185068;
LAB_00185006:
    (this->m_Memory).m_pMemory[uVar6].m_Previous = pLVar3->m_Previous;
  }
  else {
    pLVar1[uVar6].m_Next = pLVar3->m_Next;
    uVar6 = (uint)pLVar3->m_Next;
    if (uVar6 != 0xffff) goto LAB_00185006;
LAB_00185068:
    this->m_Tail = pLVar3->m_Previous;
  }
  pLVar3->m_Next = uVar2;
  pLVar3->m_Previous = uVar2;
  this->m_ElementCount = this->m_ElementCount - 1;
  pLVar3 = (this->m_Memory).m_pMemory + uVar5;
LAB_00184f5f:
  pLVar3->m_Next = before;
  if (uVar4 == 0xffff) {
    pLVar3->m_Previous = this->m_Tail;
    this->m_Tail = uVar2;
  }
  else {
                    /* Unresolved local var: ListElem_t * beforeElem@[???] */
    pLVar1 = (this->m_Memory).m_pMemory;
    pLVar3->m_Previous = pLVar1[uVar4].m_Previous;
    pLVar1[uVar4].m_Previous = uVar2;
  }
  if (pLVar3->m_Previous == 0xffff) {
    this->m_Head = uVar2;
  }
  else {
    (this->m_Memory).m_pMemory[pLVar3->m_Previous].m_Next = uVar2;
  }
  pLVar3 = (this->m_Memory).m_pMemory + uVar5;
  this->m_ElementCount = this->m_ElementCount + 1;
  if (pLVar3 != (ListElem_t *)0x0) {
    pLVar3->m_Element = *src;
  }
  return uVar2;
}


