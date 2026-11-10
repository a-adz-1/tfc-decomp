// KillSessionKey__FPP18WON_BFSymmetricKey  @ 000d21ec
void KillSessionKey__FPP18WON_BFSymmetricKey(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*param_1);
    *param_1 = 0;
  }
  return;
}


