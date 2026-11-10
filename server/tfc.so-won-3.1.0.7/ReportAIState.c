// ReportAIState__12CBaseMonster  @ 000c0d88
void ReportAIState__12CBaseMonster(int *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  
  (*DAT_001c1114)();
  if ((uint)param_1[0x159] < 8) {
    (*DAT_001c1114)();
  }
  if (activity_map._0_4_ != 0) {
    iVar4 = 0;
    do {
      if (*(int *)(activity_map + iVar4) == param_1[0x156]) {
        (*DAT_001c1114)();
        break;
      }
      iVar5 = iVar4 + 8;
      iVar4 = iVar4 + 8;
    } while (*(int *)(activity_map + iVar5) != 0);
  }
  if (param_1[0x15c] == 0) {
    (*DAT_001c1114)(1,"No Schedule, ");
  }
  else {
    pcVar6 = *(char **)(param_1[0x15c] + 0x10);
    if (pcVar6 == (char *)0x0) {
      pcVar6 = "Unknown";
    }
    uVar8 = CONCAT44(pcVar6,"Schedule %s, ");
    uVar7 = 1;
    (*DAT_001c1114)();
    puVar3 = (undefined4 *)GetTask__12CBaseMonster(param_1,uVar7,uVar8);
    if (puVar3 != (undefined4 *)0x0) {
      (*DAT_001c1114)(1,"Task %d (#%d), ",*puVar3,param_1[0x15d]);
    }
  }
  iVar4 = __opP11CBaseEntity__7EHANDLE();
  if (iVar4 == 0) {
    (*DAT_001c1114)(1,"No enemy");
  }
  else {
    puVar3 = (undefined4 *)__rf__7EHANDLE();
    (*DAT_001c1114)(1,"\nEnemy is %s",*(int *)*puVar3 + (int)gpGlobals[0x26]);
  }
  iVar4 = (**(code **)(param_1[0x111] + 0x6c))();
  if (iVar4 != 0) {
    (*DAT_001c1114)(1," Moving ");
    fVar1 = (float)param_1[0x155];
    fVar2 = *gpGlobals;
    if ((byte)((fVar1 < fVar2 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) - 1) < 0x40) {
      iVar4 = (**(code **)(param_1[0x111] + 0x150))();
      if (param_1[0x157] == iVar4) {
        (*DAT_001c1114)(1,": In stopped anim. ");
      }
    }
    else {
      (*DAT_001c1114)(1,": Stopped for %.2f. ",(double)(fVar1 - *gpGlobals));
    }
  }
  iVar4 = (**(code **)(param_1[0x111] + 0x54))();
  if (iVar4 != 0) {
    iVar5 = __opP11CBaseEntity__7EHANDLE();
    if (iVar5 == 0) {
      (*DAT_001c1114)(1,&UNK_00148cdb);
    }
    (*DAT_001c1114)(1,"In Squad, ");
    iVar5 = __opP11CBaseEntity__7EHANDLE();
    if (iVar5 != iVar4) {
      (*DAT_001c1114)(1,&UNK_00148cdb);
    }
    (*DAT_001c1114)(1,"Leader.");
  }
  (*DAT_001c1114)(1,&UNK_00148cf3);
  (*DAT_001c1114)(1,"Yaw speed:%3.1f,Health: %3.1f\n",(double)*(float *)(*param_1 + 0xb0),
                  (double)*(float *)(*param_1 + 0x160));
  if ((*(byte *)(*param_1 + 0x1a0) & 0x10) != 0) {
    (*DAT_001c1114)(1," PRISONER! ");
  }
  if ((*(byte *)(*param_1 + 0x1a1) & 1) != 0) {
    (*DAT_001c1114)(1," Pre-Disaster! ");
  }
  (*DAT_001c1114)(1,&UNK_00148cf3);
  return;
}


