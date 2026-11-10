// AdminAccess__11CBasePlayerPc  @ 000fa85c
void AdminAccess__11CBasePlayerPc(undefined4 *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    if ((tfc_adminpwd._4_4_ == 0) || (*(char *)tfc_adminpwd._4_4_ == '\0')) {
      pcVar2 = "#Admin_nopassword";
    }
    else {
      iVar1 = strcmp((char *)tfc_adminpwd._4_4_,param_2);
      if (iVar1 == 0) {
        param_1[0x7f] = 1;
        pcVar2 = "#Admin_access";
      }
      else {
        pcVar2 = "#Admin_badpassword";
      }
    }
    ClientPrint__FP9entvars_siPCcN42(*param_1,1,pcVar2,0,0,0,0);
  }
  return;
}


