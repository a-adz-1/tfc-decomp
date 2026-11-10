// ReportAIState__12CBaseMonster  @ 000b5b28
void ReportAIState__12CBaseMonster(int *param_1)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  
  (*DAT_001a7f34)();
  if ((uint)param_1[0x13d] < 8) {
    (*DAT_001a7f34)();
  }
  if (activity_map != 0) {
    iVar5 = 0;
    do {
      if (*(int *)((int)&activity_map + iVar5) == param_1[0x13a]) {
        (*DAT_001a7f34)();
        break;
      }
      piVar1 = (int *)(iVar5 + 0x146ca8);
      iVar5 = iVar5 + 8;
    } while (*piVar1 != 0);
  }
  if (param_1[0x140] == 0) {
    (*DAT_001a7f34)(1,"No Schedule, ");
  }
  else {
    pcVar7 = *(char **)(param_1[0x140] + 0x10);
    if (pcVar7 == (char *)0x0) {
      pcVar7 = "Unknown";
    }
    uVar9 = CONCAT44(pcVar7,"Schedule %s, ");
    uVar8 = 1;
    (*DAT_001a7f34)();
    puVar4 = (undefined4 *)GetTask__12CBaseMonster(param_1,uVar8,uVar9);
    if (puVar4 != (undefined4 *)0x0) {
      (*DAT_001a7f34)(1,"Task %d (#%d), ",*puVar4,param_1[0x141]);
    }
  }
  iVar5 = __opP11CBaseEntity__7EHANDLE();
  if (iVar5 == 0) {
    (*DAT_001a7f34)(1,"No enemy");
  }
  else {
    puVar4 = (undefined4 *)__rf__7EHANDLE();
    (*DAT_001a7f34)(1,"\nEnemy is %s",*(int *)*puVar4 + (int)gpGlobals[0x26]);
  }
  iVar5 = (**(code **)(param_1[0xf5] + 0x68))();
  if (iVar5 != 0) {
    (*DAT_001a7f34)(1," Moving ");
    fVar2 = (float)param_1[0x139];
    fVar3 = *gpGlobals;
    if ((byte)((fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
               (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) - 1) < 0x40) {
      iVar5 = (**(code **)(param_1[0xf5] + 0x148))();
      if (param_1[0x13b] == iVar5) {
        (*DAT_001a7f34)(1,": In stopped anim. ");
      }
    }
    else {
      (*DAT_001a7f34)(1,": Stopped for %.2f. ",(double)(fVar2 - *gpGlobals));
    }
  }
  iVar5 = (**(code **)(param_1[0xf5] + 0x50))();
  if (iVar5 != 0) {
    iVar6 = __opP11CBaseEntity__7EHANDLE();
    if (iVar6 == 0) {
      (*DAT_001a7f34)(1,&UNK_0013839b);
    }
    (*DAT_001a7f34)(1,"In Squad, ");
    iVar6 = __opP11CBaseEntity__7EHANDLE();
    if (iVar6 != iVar5) {
      (*DAT_001a7f34)(1,&UNK_0013839b);
    }
    (*DAT_001a7f34)(1,"Leader.");
  }
  (*DAT_001a7f34)(1,&UNK_001383b3);
  (*DAT_001a7f34)(1,"Yaw speed:%3.1f,Health: %3.1f\n",(double)*(float *)(*param_1 + 0xb0),
                  (double)*(float *)(*param_1 + 0x160));
  if ((*(byte *)(*param_1 + 0x1a0) & 0x10) != 0) {
    (*DAT_001a7f34)(1," PRISONER! ");
  }
  if ((*(byte *)(*param_1 + 0x1a1) & 1) != 0) {
    (*DAT_001a7f34)(1," Pre-Disaster! ");
  }
  (*DAT_001a7f34)(1,&UNK_001383b3);
  return;
}


