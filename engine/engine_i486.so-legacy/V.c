// V_Init  @ 000c7940
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void V_Init(void)

{
  return;
}


// V_UTF8ToUChar32  @ 000d2cb0
qboolean V_UTF8ToUChar32(char *pUTF8_,uchar32 *uValueOut)

{
  bool local_1;
  
                    /* Unresolved local var: bool bError@[???] */
  Q_UTF8ToUChar32(pUTF8_,uValueOut,&local_1);
  return (uint)local_1;
}


