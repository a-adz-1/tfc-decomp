// CDefOps<long_long_unsigned_int>::LessFunc  @ 00128310
bool CDefOps<long_long_unsigned_int>::LessFunc(ulonglong *lhs,ulonglong *rhs)

{
  bool bVar1;
  
  bVar1 = true;
  if (*(uint *)((int)rhs + 4) <= *(uint *)((int)lhs + 4)) {
    if ((*(uint *)((int)lhs + 4) <= *(uint *)((int)rhs + 4)) && ((uint)*lhs < (uint)*rhs)) {
      return bVar1;
    }
    bVar1 = false;
  }
  return bVar1;
}


