// CGameUIFuncs::Key_BindingForKey  @ 0014abd0
/* DWARF original prototype: char * Key_BindingForKey(CGameUIFuncs * this, int keynum) */

char * __thiscall CGameUIFuncs::Key_BindingForKey(CGameUIFuncs *this,int keynum)

{
  char *pcVar1;
  
  pcVar1 = ::Key_BindingForKey(keynum);
  return pcVar1;
}


// CGameUIFuncs::Key_KeyStringToKeyNum  @ 0014ab10
/* DWARF original prototype: int Key_KeyStringToKeyNum(CGameUIFuncs * this, char * pchKey) */

int __thiscall CGameUIFuncs::Key_KeyStringToKeyNum(CGameUIFuncs *this,char *pchKey)

{
  int iVar1;
  
  iVar1 = Key_StringToKeynum(pchKey);
  return iVar1;
}


// CGameUIFuncs::Key_NameForKey  @ 0014abe0
/* DWARF original prototype: char * Key_NameForKey(CGameUIFuncs * this, int keynum) */

char * __thiscall CGameUIFuncs::Key_NameForKey(CGameUIFuncs *this,int keynum)

{
  char *pcVar1;
  
  pcVar1 = Key_KeynumToString(keynum);
  return pcVar1;
}


