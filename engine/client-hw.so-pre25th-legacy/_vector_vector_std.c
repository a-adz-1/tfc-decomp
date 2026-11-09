// std::vector<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>::~vector  @ 001dec10
/* WARNING: Removing unreachable block (ram,0x001dec7a) */
/* WARNING: Removing unreachable block (ram,0x001dec90) */
/* WARNING: Removing unreachable block (ram,0x001dec9d) */
/* WARNING: Removing unreachable block (ram,0x001dec87) */
/* WARNING: Removing unreachable block (ram,0x001dec8e) */
/* DWARF original prototype: void
   ~vector(vector<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
   * this, int __in_chrg) */

void __thiscall
std::
vector<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
::~vector(vector<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
          *this,int __in_chrg)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  pointer ppVar4;
  char *pcVar5;
  pointer ppVar6;
  
  ppVar4 = (this->
           super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
           )._M_impl._M_finish;
  ppVar6 = (this->
           super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
           )._M_impl._M_start;
  if (ppVar4 != ppVar6) {
    do {
      pcVar5 = (ppVar6->first)._M_dataplus._M_p;
      paVar1 = (allocator *)(pcVar5 + -0xc);
      if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
        LOCK();
        piVar2 = (int *)(pcVar5 + -4);
        iVar3 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar3 < 1) {
          std::string::_Rep::_M_destroy(paVar1);
        }
      }
      ppVar6 = ppVar6 + 1;
    } while (ppVar4 != ppVar6);
    ppVar6 = (this->
             super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
             )._M_impl._M_start;
  }
  if (ppVar6 != (pointer)0x0) {
    operator_delete(ppVar6);
  }
  return;
}


