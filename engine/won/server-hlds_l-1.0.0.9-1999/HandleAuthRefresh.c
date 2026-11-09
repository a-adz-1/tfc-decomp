// HandleAuthRefresh__11AuthRequest  @ 08094ac0
void HandleAuthRefresh__11AuthRequest(int param_1)

{
  time_t tVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x8030) == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x8034) == 0) {
    return;
  }
  tVar1 = time((time_t *)0x0);
  iVar2 = *(int *)(param_1 + 0x8058);
  if (iVar2 == 1) {
    if (*(int *)(param_1 + 0x8050) < 0) {
      return;
    }
    iVar2 = checkAsynchConnect__10EasySocketi(param_1 + 0x8064,0);
    if (iVar2 != 0) {
      refreshCertificate__11AuthRequest(param_1);
      return;
    }
    if (tVar1 <= *(int *)(param_1 + 0x8054)) {
      return;
    }
    *(int *)(param_1 + 0x8050) = *(int *)(param_1 + 0x8050) + -1;
    *(int *)(param_1 + 0x8054) = (int)ROUND((float)tVar1 + 5.0);
  }
  else {
    if (1 < iVar2) {
      if (iVar2 != 2) {
        return;
      }
      ReceiveRefresh__11AuthRequest(param_1);
      return;
    }
    if (iVar2 != 0) {
      return;
    }
    if ((tVar1 <= *(int *)(param_1 + 0x8048)) && (0x77 < *(int *)(param_1 + 0x8048) - tVar1)) {
      return;
    }
    *(undefined4 *)(param_1 + 0x8050) = 4;
    *(int *)(param_1 + 0x8054) = (int)ROUND((float)tVar1 + 5.0);
    *(undefined4 *)(param_1 + 0x8058) = 1;
  }
  connect__10EasySocketliii
            (param_1 + 0x8064,*(undefined4 *)(param_1 + 0x8008),*(undefined4 *)(param_1 + 4),0,1);
  return;
}


