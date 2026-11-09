// std::map<int,_DetailMap*,_std::less<int>,_std::allocator<std::pair<const_int,_DetailMap*>_>_>::~map  @ 001dee50
/* DWARF original prototype: void
   ~map(map<int,_DetailMap*,_std::less<int>,_std::allocator<std::pair<const_int,_DetailMap*>_>_> *
   this, int __in_chrg) */

void __thiscall
std::map<int,_DetailMap*,_std::less<int>,_std::allocator<std::pair<const_int,_DetailMap*>_>_>::~map
          (map<int,_DetailMap*,_std::less<int>,_std::allocator<std::pair<const_int,_DetailMap*>_>_>
           *this,int __in_chrg)

{
  _Rb_tree<int,_std::pair<const_int,_DetailMap*>,_std::_Select1st<std::pair<const_int,_DetailMap*>_>,_std::less<int>,_std::allocator<std::pair<const_int,_DetailMap*>_>_>
  ::_M_erase(&this->_M_t,(_Link_type)(this->_M_t)._M_impl._M_header._M_parent);
  return;
}


