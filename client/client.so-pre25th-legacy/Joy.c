// Joy_AdvancedUpdate_f  @ 000839f0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Joy_AdvancedUpdate_f(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  byte bVar7;
  uint local_1c;
  
  bVar7 = 0;
  iVar3 = 1;
  do {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: DWORD dwTemp@[???] */
    *(undefined4 *)(iVar3 * 4 + 0x11880c) = 0;
    *(undefined4 *)(iVar3 * 4 + 0x11882c) = 0;
    if (iVar3 == 3) {
      sVar1 = SDL_GameControllerGetAxis(s_pJoystick,2);
      iVar2 = (int)sVar1;
LAB_00083bb7:
      *(int *)(iVar3 * 4 + 0x1187ec) = iVar2;
    }
    else {
      if (iVar3 == 4) {
        sVar1 = SDL_GameControllerGetAxis(s_pJoystick,3);
        iVar2 = (int)sVar1;
        goto LAB_00083bb7;
      }
      if (iVar3 == 2) {
        sVar1 = SDL_GameControllerGetAxis(s_pJoystick,1);
        iVar2 = (int)sVar1;
        goto LAB_00083bb7;
      }
      sVar1 = SDL_GameControllerGetAxis(s_pJoystick,0);
      *(int *)(iVar3 * 4 + 0x1187ec) = (int)sVar1;
      if (iVar3 == 6) break;
    }
    iVar3 = iVar3 + 1;
  } while( true );
  if (joy_advanced->value == 0.0) {
    dwAxisMap[0] = 4;
    dwAxisMap[1] = 1;
    return;
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: DWORD dwTemp@[???] */
  iVar3 = 9;
  bVar6 = false;
  pcVar4 = joy_name->string;
  pcVar5 = "joystick";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + (uint)bVar7 * -2 + 1;
    pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
  } while (bVar6);
  if (!bVar6) {
    (*gEngfuncs.Con_Printf)("\n%s configured\n\n",joy_name->string);
  }
  local_1c = (uint)(longlong)ROUND(joy_advaxisx->value);
  dwControlMap[0] = local_1c & 0x10;
  dwAxisMap[0] = local_1c & 0xf;
  local_1c = (uint)(longlong)ROUND(joy_advaxisy->value);
  dwControlMap[1] = local_1c & 0x10;
  dwAxisMap[1] = local_1c & 0xf;
  local_1c = (uint)(longlong)ROUND(joy_advaxisz->value);
  dwControlMap[2] = local_1c & 0x10;
  dwAxisMap[2] = local_1c & 0xf;
  local_1c = (uint)(longlong)ROUND(joy_advaxisr->value);
  dwAxisMap[3] = local_1c & 0xf;
  dwControlMap[3] = local_1c & 0x10;
  local_1c = (uint)(longlong)ROUND(joy_advaxisu->value);
  dwControlMap[4] = local_1c & 0x10;
  dwAxisMap[4] = local_1c & 0xf;
  local_1c = (uint)(longlong)ROUND(joy_advaxisv->value);
  dwAxisMap[5] = local_1c & 0xf;
  dwControlMap[5] = local_1c & 0x10;
  return;
}


