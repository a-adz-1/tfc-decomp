// Cbuf_AddText  @ 10003750
void Cbuf_AddText(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x3750  1  Cbuf_AddText */
  iVar1 = FUN_10060490(param_1);
  if (DAT_10b2014c <= DAT_10b20150 + iVar1) {
    Con_Printf(s_Cbuf_AddText__overflow_100bf168);
    return;
  }
  uVar2 = FUN_10060490(param_1);
  FUN_10062150(&DAT_10b20140,param_1,uVar2);
  return;
}


// Cbuf_InsertText  @ 100037a0
void Cbuf_InsertText(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x37a0  2  Cbuf_InsertText */
  iVar1 = DAT_10b20150;
  uVar2 = 0;
  if (DAT_10b20150 != 0) {
    uVar2 = FUN_1002c100(DAT_10b20150);
    FUN_100603d0(uVar2,DAT_10b20148,iVar1);
    FUN_100620c0(&DAT_10b20140);
  }
  Cbuf_AddText(param_1);
  if (iVar1 != 0) {
    FUN_10062150(&DAT_10b20140,uVar2,iVar1);
    FUN_1002c050(uVar2);
  }
  return;
}


