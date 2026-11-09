// std::vector<DetailMap*,_std::allocator<DetailMap*>_>::~vector  @ 0018a630
/* DWARF original prototype: void ~vector(vector<DetailMap*,_std::allocator<DetailMap*>_> * this,
   int __in_chrg) */

void __thiscall
std::vector<DetailMap*,_std::allocator<DetailMap*>_>::~vector
          (vector<DetailMap*,_std::allocator<DetailMap*>_> *this,int __in_chrg)

{
  pointer ppDVar1;
  
  ppDVar1 = (this->super__Vector_base<DetailMap*,_std::allocator<DetailMap*>_>)._M_impl._M_start;
  if (ppDVar1 != (pointer)0x0) {
    operator_delete(ppDVar1);
    return;
  }
  return;
}


