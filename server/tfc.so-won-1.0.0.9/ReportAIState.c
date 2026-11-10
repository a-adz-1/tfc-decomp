// ReportAIState__12CBaseMonster  @ 000c6fc0
void ReportAIState__12CBaseMonster(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  
  (*DAT_001755b4)();
  if ((uint)param_1[0x13a] < 8) {
    (*DAT_001755b4)();
  }
  iVar3 = 0;
  iVar2 = activity_map;
  do {
    if (iVar2 == 0) {
LAB_000c704d:
      if (param_1[0x13d] == 0) {
        (*DAT_001755b4)(1,"No Schedule, ");
      }
      else {
        pcVar4 = *(char **)(param_1[0x13d] + 0x10);
        if (pcVar4 == (char *)0x0) {
          pcVar4 = "Unknown";
        }
        uVar6 = CONCAT44(pcVar4,"Schedule %s, ");
        uVar5 = 1;
        (*DAT_001755b4)();
        puVar1 = (undefined4 *)GetTask__12CBaseMonster(param_1,uVar5,uVar6);
        if (puVar1 != (undefined4 *)0x0) {
          (*DAT_001755b4)(1,"Task %d (#%d), ",*puVar1,param_1[0x13e]);
          FUN_000c70e0();
          return;
        }
      }
      iVar2 = __opP11CBaseEntity__7EHANDLE();
      if (iVar2 != 0) {
        puVar1 = (undefined4 *)__rf__7EHANDLE();
        (*DAT_001755b4)(1,"\nEnemy is %s",*(int *)*puVar1 + (int)gpGlobals[0x26]);
        FUN_000c7130();
        return;
      }
      (*DAT_001755b4)(1,"No enemy");
      iVar2 = (**(code **)(param_1[0xf2] + 0x68))();
      if (iVar2 != 0) {
        (*DAT_001755b4)(1," Moving ");
        if ((float)param_1[0x136] <= *gpGlobals) {
          iVar2 = (**(code **)(param_1[0xf2] + 0x148))();
          if (param_1[0x138] == iVar2) {
            (*DAT_001755b4)(1,": In stopped anim. ");
          }
        }
        else {
          (*DAT_001755b4)(1,": Stopped for %.2f. ",(double)((float)param_1[0x136] - *gpGlobals));
        }
      }
      iVar2 = (**(code **)(param_1[0xf2] + 0x50))();
      if (iVar2 != 0) {
        iVar3 = __opP11CBaseEntity__7EHANDLE();
        if (iVar3 == 0) {
          (*DAT_001755b4)(1,&DAT_0013600c);
        }
        (*DAT_001755b4)(1,"In Squad, ");
        iVar3 = __opP11CBaseEntity__7EHANDLE();
        if (iVar3 != iVar2) {
          (*DAT_001755b4)(1,&DAT_0013600c);
        }
        (*DAT_001755b4)(1,"Leader.");
      }
      (*DAT_001755b4)(1,&DAT_00136024);
      (*DAT_001755b4)(1,"Yaw speed:%3.1f,Health: %3.1f\n",(double)*(float *)(*param_1 + 0x90),
                      (double)*(float *)(*param_1 + 0x140));
      if ((*(byte *)(*param_1 + 0x180) & 0x10) != 0) {
        (*DAT_001755b4)(1," PRISONER! ");
      }
      if ((*(byte *)(*param_1 + 0x181) & 1) != 0) {
        (*DAT_001755b4)(1," Pre-Disaster! ");
      }
      (*DAT_001755b4)(1,&DAT_00136024);
      return;
    }
    if ((&activity_map)[iVar3 * 2] == param_1[0x137]) {
      (*DAT_001755b4)();
      goto LAB_000c704d;
    }
    iVar3 = iVar3 + 1;
    iVar2 = (&activity_map)[iVar3 * 2];
  } while( true );
}


