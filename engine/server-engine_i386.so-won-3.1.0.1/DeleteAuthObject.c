// DeleteAuthObject__Fv  @ 000943b4
void DeleteAuthObject__Fv(void)

{
  if (gAuthRequest != 0) {
    (**(code **)(*(int *)(gAuthRequest + 0x8028) + 8))(gAuthRequest,3);
    gAuthRequest = 0;
  }
  if (gConnectionKey != 0) {
    DeleteBFSymmetricKey__16WON_CryptFactoryP18WON_BFSymmetricKey(gConnectionKey);
    gConnectionKey = 0;
  }
  return;
}


