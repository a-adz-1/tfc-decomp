// ClientHearVox__11CBasePlayerPCc  @ 000e3e90
void ClientHearVox__11CBasePlayerPCc(int *param_1,char *param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  
  (*DAT_00175578)(1,9,0,*(undefined4 *)(*param_1 + 0x1e8));
  if (*param_2 == '#') {
    pcVar2 = "speak %s\n";
  }
  else {
    pcVar2 = "speak \"%s\"\n";
  }
  uVar1 = UTIL_VarArgs__FPce(pcVar2,param_2);
  (*DAT_00175598)(uVar1);
  (*DAT_0017557c)();
  return;
}


