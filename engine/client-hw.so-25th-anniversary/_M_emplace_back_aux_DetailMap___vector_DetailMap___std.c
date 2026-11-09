// std::vector<DetailMap*,_std::allocator<DetailMap*>_>::_M_emplace_back_aux<DetailMap*>  @ 0018b2f0
/* DWARF original prototype: void
   _M_emplace_back_aux<DetailMap*>(vector<DetailMap*,_std::allocator<DetailMap*>_> * this) */

void __thiscall
std::vector<DetailMap*,_std::allocator<DetailMap*>_>::_M_emplace_back_aux<DetailMap*>
          (vector<DetailMap*,_std::allocator<DetailMap*>_> *this)

{
  uint uVar1;
  uint uVar2;
  pointer __dest;
  pointer __src;
  uint uVar3;
  undefined4 *in_stack_00000008;
  
                    /* Unresolved local var: size_type __len@[???]
                       Unresolved local var: pointer __new_start@[???]
                       Unresolved local var: pointer __new_finish@[???] */
                    /* Unresolved local var: size_type __len@[???] */
  uVar2 = (int)(this->super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>)._M_impl._M_finish
          - (int)(this->super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>)._M_impl.
                 _M_start >> 2;
  if (uVar2 == 0) {
    uVar3 = 4;
  }
  else {
    uVar1 = uVar2 * 2;
    if ((uVar1 < uVar2) || (0x3fffffff < uVar1)) {
      uVar3 = 0xfffffffc;
    }
    else {
      uVar3 = 0;
      __dest = (pointer)0x0;
      if (uVar1 == 0) goto LAB_0018b337;
      uVar3 = uVar2 * 8;
    }
  }
  __dest = operator_new(uVar3);
LAB_0018b337:
  __src = (this->super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>)._M_impl._M_start;
  uVar2 = (int)(this->super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>)._M_impl._M_finish
          - (int)__src;
  if ((undefined4 *)((int)__dest + uVar2) != (undefined4 *)0x0) {
    *(undefined4 *)((int)__dest + uVar2) = *in_stack_00000008;
    __src = (this->super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>)._M_impl._M_start;
    uVar2 = (int)(this->super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>)._M_impl.
                 _M_finish - (int)__src;
  }
                    /* Unresolved local var: bool __assignable@[???]
                       Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
  if (uVar2 >> 2 != 0) {
    memmove(__dest,__src,uVar2);
    __src = (this->super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>)._M_impl._M_start;
  }
  if (__src != (pointer)0x0) {
    operator_delete(__src);
  }
  (this->super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>)._M_impl._M_start = __dest;
  (this->super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>)._M_impl._M_finish =
       (pointer)((int)__dest + uVar2 + 4);
  (this->super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>)._M_impl._M_end_of_storage =
       (pointer)((int)__dest + uVar3);
  return;
}


