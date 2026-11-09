// lump_sorter  @ 000bc9c0
int lump_sorter(void *lump1,void *lump2)

{
  int iVar1;
  
                    /* Unresolved local var: texlumpinfo_t * plump1@[???]
                       Unresolved local var: texlumpinfo_t * plump2@[???]
                       Unresolved local var: size_t __s1_len@[???]
                       Unresolved local var: size_t __s2_len@[???] */
  iVar1 = strcmp((char *)((int)lump1 + 0x10),(char *)((int)lump2 + 0x10));
  return iVar1;
}


