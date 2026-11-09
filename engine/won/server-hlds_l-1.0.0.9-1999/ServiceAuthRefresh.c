// ServiceAuthRefresh__Fv  @ 08096cf0
void ServiceAuthRefresh__Fv(void)

{
  longdouble lVar1;
  
  if (gAuthRequest != 0) {
    lVar1 = (longdouble)Sys_FloatTime();
    if (0.5 <= (float)lVar1 - tLastService_456) {
      tLastService_456 = (float)lVar1;
      HandleAuthRefresh__11AuthRequest(gAuthRequest);
    }
  }
  return;
}


