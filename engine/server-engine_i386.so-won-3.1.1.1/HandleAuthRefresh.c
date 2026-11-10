// HandleAuthRefresh__11AuthRequest  @ 000d4fd8
void HandleAuthRefresh__11AuthRequest(int param_1)

{
  time_t tVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x819c) != 0) && (*(int *)(param_1 + 0x81a0) != 0)) {
    tVar1 = time((time_t *)0x0);
    iVar2 = *(int *)(param_1 + 0x8190);
    if (iVar2 == 1) {
      if (-1 < *(int *)(param_1 + 0x81bc)) {
        iVar2 = checkAsynchConnect__10EasySocketi(param_1 + 0x81c8,0);
        if (iVar2 == 0) {
          if (*(int *)(param_1 + 0x81b8) < tVar1) {
            *(int *)(param_1 + 0x81bc) = *(int *)(param_1 + 0x81bc) + -1;
            *(time_t *)(param_1 + 0x81b8) = tVar1 + 5;
            connect__10EasySocketliii
                      (param_1 + 0x81c8,*(undefined4 *)(param_1 + 0x8008),
                       *(undefined4 *)(param_1 + 4),0,1);
          }
        }
        else {
          refreshCertificate__11AuthRequest(param_1);
        }
      }
    }
    else if (iVar2 < 2) {
      if ((iVar2 == 0) &&
         ((*(int *)(param_1 + 0x81b0) < tVar1 || (*(int *)(param_1 + 0x81b0) - tVar1 < 0x78)))) {
        *(undefined4 *)(param_1 + 0x81bc) = 4;
        *(time_t *)(param_1 + 0x81b8) = tVar1 + 5;
        *(undefined4 *)(param_1 + 0x8190) = 1;
        connect__10EasySocketliii
                  (param_1 + 0x81c8,*(undefined4 *)(param_1 + 0x8008),*(undefined4 *)(param_1 + 4),0
                   ,1);
      }
    }
    else if (iVar2 == 2) {
      ReceiveRefresh__11AuthRequest(param_1);
    }
  }
  return;
}


