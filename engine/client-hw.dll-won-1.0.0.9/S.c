// S_BlockSound  @ 10079140
void S_BlockSound(void)

{
                    /* 0x79140  47  S_BlockSound */
  if (DAT_1055a85c != 0) {
    FUN_1006c330();
    thunk_FUN_1009f450();
    DAT_100c97c0 = 1;
    return;
  }
  if ((DAT_104c06b4 != 0) && (DAT_100c97c0 = DAT_100c97c0 + 1, DAT_100c97c0 == 1)) {
    waveOutReset(DAT_1055a854);
  }
  if (DAT_1055a84c != (int *)0x0) {
    (**(code **)(*DAT_1055a84c + 0x48))(DAT_1055a84c);
  }
  if (DAT_100d7fb8 != (int *)0x0) {
    (**(code **)(*DAT_100d7fb8 + 0x10))(DAT_100d7fb8,&DAT_100d7f68,0,0,0,&DAT_100d4e28,0x10);
  }
  if (DAT_100d7f98 != (int *)0x0) {
    (**(code **)(*DAT_100d7f98 + 0x48))(DAT_100d7f98);
  }
  if (DAT_100d7f9c != (int *)0x0) {
    (**(code **)(*DAT_100d7f9c + 0x48))(DAT_100d7f9c);
  }
  if (DAT_100d7fa0 != (int *)0x0) {
    (**(code **)(*DAT_100d7fa0 + 0x48))(DAT_100d7fa0);
  }
  if (DAT_100d7fa4 != (int *)0x0) {
    (**(code **)(*DAT_100d7fa4 + 0x48))(DAT_100d7fa4);
  }
  return;
}


// S_ClearBuffer  @ 1002eb20
void S_ClearBuffer(void)

{
  int iVar1;
  byte bVar2;
  undefined4 unaff_ESI;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined1 auStack_c [4];
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  
                    /* 0x2eb20  48  S_ClearBuffer */
  if (DAT_1055a894 != 0) {
    iVar3 = 0;
    if (DAT_100c97dc == 0) {
      return;
    }
    if (DAT_100c97cc == 0) {
      return;
    }
    if ((((*(int *)(DAT_100c97cc + 0x28) == 0) && (DAT_100d7f98 == (int *)0x0)) &&
        (DAT_100d7f9c == (int *)0x0)) &&
       ((DAT_100d7fa0 == (int *)0x0 && (DAT_100d7fa4 == (int *)0x0)))) {
      return;
    }
    while( true ) {
      iVar1 = (**(code **)(*DAT_100d7f98 + 0x2c))
                        (DAT_100d7f98,0,DAT_1055a880 >> 1,&local_20,&local_10,0,0,0);
      if (iVar1 == 0) {
        iVar3 = 0;
        while( true ) {
          iVar1 = (**(code **)(*DAT_100d7f9c + 0x2c))
                            (DAT_100d7f9c,0,DAT_1055a880 >> 1,&uStack_1c,auStack_c,0,0,0);
          if (iVar1 == 0) {
            iVar3 = 0;
            while( true ) {
              iVar1 = (**(code **)(*DAT_100d7fa0 + 0x2c))
                                (DAT_100d7fa0,0,DAT_1055a880 >> 1,&uStack_18,auStack_8,0,0,0);
              if (iVar1 == 0) {
                iVar3 = 0;
                while( true ) {
                  iVar1 = (**(code **)(*DAT_100d7fa4 + 0x2c))
                                    (DAT_100d7fa4,0,DAT_1055a880 >> 1,&uStack_14,auStack_4,0,0,0);
                  if (iVar1 == 0) {
                    FUN_10060370(local_20,0,DAT_1055a880 >> 1);
                    FUN_10060370(uStack_1c,0,DAT_1055a880 >> 1);
                    FUN_10060370(uStack_18,0,DAT_1055a880 >> 1);
                    FUN_10060370(uStack_14,0,DAT_1055a880 >> 1);
                    (**(code **)(*DAT_100d7f98 + 0x4c))(DAT_100d7f98,local_20,local_10,0,0);
                    uVar4 = 0;
                    (**(code **)(*DAT_100d7f9c + 0x4c))(DAT_100d7f9c,unaff_ESI,local_20,0,0);
                    (**(code **)(*DAT_100d7fa0 + 0x4c))(DAT_100d7fa0,local_10,unaff_ESI,0,0);
                    (**(code **)(*DAT_100d7fa4 + 0x4c))(DAT_100d7fa4,uVar4,local_10,0,0);
                    return;
                  }
                  if (iVar1 != -0x7787ff6a) break;
                  iVar3 = iVar3 + 1;
                  if (10000 < iVar3) {
                    Con_Printf(s_S_ClearBuffer__DS__couldn_t_rest_100ca394);
                    FUN_1002d9b0();
                    return;
                  }
                }
                Con_Printf(s_S_ClearBuffer__DS__Lock_EAX_RR_S_100ca360);
                FUN_1002d9b0();
                return;
              }
              if (iVar1 != -0x7787ff6a) break;
              iVar3 = iVar3 + 1;
              if (10000 < iVar3) {
                Con_Printf(s_S_ClearBuffer__DS__couldn_t_rest_100ca32c);
                FUN_1002d9b0();
                return;
              }
            }
            Con_Printf(s_S_ClearBuffer__DS__Lock_EAX_RL_S_100ca2f8);
            FUN_1002d9b0();
            return;
          }
          if (iVar1 != -0x7787ff6a) break;
          iVar3 = iVar3 + 1;
          if (10000 < iVar3) {
            Con_Printf(s_S_ClearBuffer__DS__couldn_t_rest_100ca2c4);
            FUN_1002d9b0();
            return;
          }
        }
        Con_Printf(s_S_ClearBuffer__DS__Lock_EAX_FR_S_100ca290);
        FUN_1002d9b0();
        return;
      }
      if (iVar1 != -0x7787ff6a) break;
      iVar3 = iVar3 + 1;
      if (10000 < iVar3) {
        Con_Printf(s_S_ClearBuffer__DS__couldn_t_rest_100ca25c);
        FUN_1002d9b0();
        return;
      }
    }
    Con_Printf(s_S_ClearBuffer__DS__Lock_EAX_FL_S_100ca228);
    FUN_1002d9b0();
    return;
  }
  if (DAT_100c97dc == 0) {
    return;
  }
  if (DAT_100c97cc == 0) {
    return;
  }
  if (DAT_1055a85c != 0) {
    iVar3 = FUN_1009f4f0();
    if (iVar3 == 0) {
      return;
    }
    if (DAT_1055a85c != 0) goto LAB_1002ee84;
  }
  if (DAT_100c97dc == 0) {
    return;
  }
  if (DAT_100c97cc == 0) {
    return;
  }
  if ((*(int *)(DAT_100c97cc + 0x28) == 0) && (DAT_1055a84c == (int *)0x0)) {
    return;
  }
LAB_1002ee84:
  bVar2 = -(*(int *)(DAT_100c97cc + 0x1c) == 8) & 0x80;
  if ((DAT_1055a85c == 0) || (iVar3 = FUN_1009f4f0(), iVar3 == 0)) {
    if (DAT_1055a84c != (int *)0x0) {
      iVar3 = 0;
      while( true ) {
        iVar1 = (**(code **)(*DAT_1055a84c + 0x2c))
                          (DAT_1055a84c,0,DAT_1055a880,&local_28,&local_24,0,0,0);
        if (iVar1 == 0) {
          iVar3 = *(int *)(DAT_100c97cc + 0x1c) * *(int *)(DAT_100c97cc + 0x10);
          FUN_10060370(local_28,bVar2,(int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3);
          (**(code **)(*DAT_1055a84c + 0x4c))(DAT_1055a84c,local_28,local_24,0,0);
          return;
        }
        if (iVar1 != -0x7787ff6a) break;
        iVar3 = iVar3 + 1;
        if (10000 < iVar3) {
          Con_Printf(s_S_ClearBuffer__DS__couldn_t_rest_100ca3f8);
          FUN_1002d9b0();
          return;
        }
      }
      Con_Printf(s_S_ClearBuffer__DS__Lock_Sound_Bu_100ca3c8);
      FUN_1002d9b0();
      return;
    }
    iVar3 = *(int *)(DAT_100c97cc + 0x1c) * *(int *)(DAT_100c97cc + 0x10);
    FUN_10060370(*(undefined4 *)(DAT_100c97cc + 0x28),bVar2,(int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3
                );
  }
  else {
    iVar3 = FUN_1009f490(&local_28,&local_24);
    if (-1 < iVar3) {
      iVar3 = *(int *)(DAT_100c97cc + 0x1c) * *(int *)(DAT_100c97cc + 0x10);
      FUN_10060370(local_28,bVar2,(int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3);
      FUN_1009f4b0(local_28,local_24);
      return;
    }
  }
  return;
}


// S_GetDSPointer  @ 10079110
void S_GetDSPointer(undefined4 *param_1,undefined4 *param_2)

{
                    /* 0x79110  49  S_GetDSPointer */
  if (DAT_1055a85c != 0) {
    OutputDebugStringA(s_error_in_S_GetDSPointer___should_100d8040);
  }
  *param_1 = DAT_1055a850;
  *param_2 = DAT_1055a84c;
  return;
}


// S_GetWAVPointer  @ 100790f0
uint S_GetWAVPointer(void)

{
                    /* 0x790f0  50  S_GetWAVPointer */
  return (DAT_1055a854 == 0) - 1 & 0x1055a854;
}


// S_UnblockSound  @ 10079200
void S_UnblockSound(void)

{
  int iVar1;
  
                    /* 0x79200  51  S_UnblockSound */
  iVar1 = 0;
  if (DAT_1055a85c == 0) {
    iVar1 = DAT_100c97c0;
  }
  DAT_100c97c0 = iVar1;
  if (DAT_104c06b4 != 0) {
    DAT_100c97c0 = iVar1 + -1;
  }
  if (DAT_1055a84c != (int *)0x0) {
    (**(code **)(*DAT_1055a84c + 0x30))(DAT_1055a84c,0,0,1);
  }
  if (DAT_100d7fb8 != (int *)0x0) {
    (**(code **)(*DAT_100d7fb8 + 0x10))
              (DAT_100d7fb8,&DAT_100d7f68,0,0,0,&DAT_100d4e28 + DAT_100d7fcc * 0x10,0x10);
  }
  if (DAT_100d7f98 != (int *)0x0) {
    (**(code **)(*DAT_100d7f98 + 0x30))(DAT_100d7f98,0,0,1);
  }
  if (DAT_100d7f9c != (int *)0x0) {
    (**(code **)(*DAT_100d7f9c + 0x30))(DAT_100d7f9c,0,0,1);
  }
  if (DAT_100d7fa0 != (int *)0x0) {
    (**(code **)(*DAT_100d7fa0 + 0x30))(DAT_100d7fa0,0,0,1);
  }
  if (DAT_100d7fa4 != (int *)0x0) {
    (**(code **)(*DAT_100d7fa4 + 0x30))(DAT_100d7fa4,0,0,1);
  }
  return;
}


