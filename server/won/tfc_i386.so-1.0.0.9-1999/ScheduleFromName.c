// ScheduleFromName__12CBaseMonsterPCc  @ 000a70c0
void ScheduleFromName__12CBaseMonsterPCc(undefined4 param_1,undefined4 param_2)

{
  ScheduleInList__12CBaseMonsterPCcPP10Schedule_ti
            (param_1,param_2,_12CBaseMonster_m_scheduleList,0x26);
  return;
}


// ScheduleFromName__12CTalkMonsterPCc  @ 000f1280
void ScheduleFromName__12CTalkMonsterPCc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = ScheduleInList__12CBaseMonsterPCcPP10Schedule_ti
                    (param_1,param_2,&_12CTalkMonster_m_scheduleList,0xb);
  if (iVar1 == 0) {
    ScheduleFromName__12CBaseMonsterPCc(param_1,param_2);
  }
  return;
}


