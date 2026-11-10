// ClientHearVox__11CBasePlayerPCc  @ 000e3f34
void ClientHearVox__11CBasePlayerPCc(int *param_1,char *param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  
  (*DAT_0019f758)(1,9,0,*(undefined4 *)(*param_1 + 0x208));
  if (*param_2 == '#') {
    pcVar1 = "spk %s\n";
  }
  else {
    pcVar1 = "spk \"%s\"\n";
  }
  uVar2 = UTIL_VarArgs__FPce(pcVar1,param_2);
  (*DAT_0019f778)(uVar2);
  (*DAT_0019f75c)();
  return;
}


