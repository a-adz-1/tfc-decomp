// STUB_Callback_GetLocalizedString__FUi  @ 000cdbec
char * STUB_Callback_GetLocalizedString__FUi(undefined4 param_1)

{
  char *pcVar1;
  
  switch(param_1) {
  case 0x1b2:
    pcVar1 = "Your executable is out of date.";
    break;
  case 0x1b3:
    pcVar1 = "Your Half-Life CD Key is invalid.";
    break;
  default:
    pcVar1 = "Auth Error";
    break;
  case 0x1b7:
    pcVar1 = "Unable to authenticate with WON servers.";
    break;
  case 0x1cb:
    pcVar1 = "Your Half-Life CD Key is currently in use.  Please try again later.";
    break;
  case 0x1cd:
    pcVar1 = (char *)FUN_000eec00;
  }
  return pcVar1;
}


