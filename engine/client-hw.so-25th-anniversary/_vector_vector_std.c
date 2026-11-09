// std::vector<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>::~vector  @ 0018a650
/* WARNING: Removing unreachable block (ram,0x0018a66d) */
/* WARNING: Removing unreachable block (ram,0x0018a707) */
/* WARNING: Removing unreachable block (ram,0x0018a6e0) */
/* WARNING: Removing unreachable block (ram,0x0018a6ed) */
/* WARNING: Removing unreachable block (ram,0x0018a700) */
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
  char *pcVar4;
  pointer ppVar5;
  pointer ppVar6;
  
  ppVar6 = (this->
           super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
           )._M_impl._M_finish;
  ppVar5 = (this->
           super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
           )._M_impl._M_start;
  if (ppVar6 != ppVar5) {
    do {
      while( true ) {
        pcVar4 = (ppVar5->first)._M_dataplus._M_p;
        paVar1 = (allocator *)(pcVar4 + -0xc);
        if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) break;
LAB_0018a678:
        ppVar5 = ppVar5 + 1;
        if (ppVar6 == ppVar5) goto LAB_0018a6c0;
      }
      LOCK();
      piVar2 = (int *)(pcVar4 + -4);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (0 < iVar3) goto LAB_0018a678;
      ppVar5 = ppVar5 + 1;
      std::string::_Rep::_M_destroy(paVar1);
    } while (ppVar6 != ppVar5);
LAB_0018a6c0:
    ppVar6 = (this->
             super__Vector_base<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>,_std::allocator<std::pair<std::basic_string<char,_std::char_traits<char>,_std::allocator<char>_>,_int>_>_>
             )._M_impl._M_start;
  }
  if (ppVar6 != (pointer)0x0) {
    operator_delete(ppVar6);
  }
  return;
}


