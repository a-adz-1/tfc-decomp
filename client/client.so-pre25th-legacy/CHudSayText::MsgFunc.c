// CHudSayText::MsgFunc_SayText  @ 0009e380
/* DWARF original prototype: int MsgFunc_SayText(CHudSayText * this, char * pszName, int iSize, void
   * pbuf) */

int __thiscall CHudSayText::MsgFunc_SayText(CHudSayText *this,char *pszName,int iSize,void *pbuf)

{
  int clientIndex;
  char *pszBuf;
  
                    /* Unresolved local var: int client_index@[???] */
  BEGIN_READ(pbuf,iSize);
  clientIndex = READ_BYTE();
  pszBuf = READ_STRING();
  SayTextPrint(this,pszBuf,iSize + -1,clientIndex);
  return 1;
}


