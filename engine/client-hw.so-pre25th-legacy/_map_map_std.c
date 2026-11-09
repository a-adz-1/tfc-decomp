// std::map<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>::~map  @ 001df340
/* DWARF original prototype: void
   ~map(map<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
   * this, int __in_chrg) */

void __thiscall
std::
map<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
::~map(map<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
       *this,int __in_chrg)

{
  _Rb_tree<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::_Select1st<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>,_std::less<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>_>,_std::allocator<std::pair<const_std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
  ::_M_erase(&this->_M_t,(_Link_type)(this->_M_t)._M_impl._M_header._M_parent);
  return;
}


