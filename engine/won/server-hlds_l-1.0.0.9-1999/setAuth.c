// setAuth__12TitanRequestP11AuthRequestiii  @ 08095b40
void setAuth__12TitanRequestP11AuthRequestiii
               (int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  if ((*(int *)(param_1 + 0x8020) != 0) &&
     ((param_2 != *(int *)(param_1 + 0x8024) || (param_4 == 0)))) {
    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(*(undefined4 *)(param_1 + 0x8020))
    ;
    *(undefined4 *)(param_1 + 0x8020) = 0;
    *(undefined2 *)(param_1 + 0x8018) = 0;
    *(undefined2 *)(param_1 + 0x801a) = 0;
    *(undefined2 *)(param_1 + 0x801c) = 0;
  }
  *(int *)(param_1 + 0x8024) = param_2;
  *(int *)(param_1 + 0x8014) = param_3;
  *(int *)(param_1 + 0x8010) = param_4;
  *(undefined4 *)(param_1 + 0x800c) = param_5;
  if ((param_4 != 0) && (param_3 == 0)) {
    printf("Can\'t have authenticated sessioned unencrypted communication.\n");
    *(undefined4 *)(param_1 + 0x8024) = 0;
  }
  return;
}


