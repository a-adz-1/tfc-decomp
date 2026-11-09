// Ghidra decompilation of functions from cl_dll/hud_bench.cpp
// 31 functions, ordered by original source line

// __MsgFunc_Bench  @ 0006e250  (line 87)

int __MsgFunc_Bench(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = CHudBenchmark::MsgFunc_Bench(&gHUD.m_Benchmark,pszName,iSize,pbuf);
  return iVar1;
}


// Bench_SetStage  @ 0006dfd0  (line 93)

void Bench_SetStage(int stage)

{
  g_currentstage = stage;
  return;
}


// Bench_GetStage  @ 0006dfe0  (line 99)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Bench_GetStage(void)

{
  return g_currentstage;
}


// Bench_GetSwitchTime  @ 0006dff0  (line 103)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

float Bench_GetSwitchTime(void)

{
  int iVar1;
  
  iVar1 = 4;
  if (g_currentstage < 5) {
    iVar1 = g_currentstage;
  }
  return g_benchSwitchTimes[iVar1];
}


// Bench_InStage  @ 0006e010  (line 108)

int Bench_InStage(int stage)

{
  return (uint)(g_currentstage == stage);
}


// Bench_SetPowerPlay  @ 0006e030  (line 113)

void Bench_SetPowerPlay(int set)

{
  g_isPowerPlay = (uint)(set != 0);
  return;
}


// Bench_GetPowerPlay  @ 0006e050  (line 119)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Bench_GetPowerPlay(void)

{
  return g_isPowerPlay;
}


// Bench_Active  @ 0006e060  (line 123)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Bench_Active(void)

{
  return (uint)(g_currentstage != 0);
}


// __CmdFunc_BenchMark  @ 0006df20  (line 127)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __CmdFunc_BenchMark(void)

{
  int iVar1;
  
                    /* Unresolved local var: net_status_t status@[???] */
  g_benchSwitchTime = gHUD.m_flTime + 10.0;
  gHUD.m_Benchmark.m_nStoredHopCount = 0;
  gHUD.m_Benchmark.m_fSendTime = gHUD.m_flTime;
  gHUD.m_Benchmark.m_nTraceDone = 0;
  g_currentstage = 1;
  gHUD.m_Benchmark.m_fReceiveTime = 0.0;
  gHUD.m_Benchmark.m_StoredLatency = 0.0;
  gHUD.m_Benchmark.m_StoredPacketLoss = 0.0;
  (*gEngfuncs.pfnServerCmd)("ppdemo 1 start\n");
  iVar1 = 4;
  if (g_currentstage < 5) {
    iVar1 = g_currentstage;
  }
  gHUD.m_Benchmark.super_CHudBase.m_iFlags = gHUD.m_Benchmark.super_CHudBase.m_iFlags | 1;
  gHUD.m_Benchmark.m_fStageStarted = gHUD.m_flTime;
  g_benchSwitchTime = g_benchSwitchTimes[iVar1] + gHUD.m_flTime;
  gHUD.m_Benchmark.m_fDrawTime = gHUD.m_flTime + 10.0;
  return;
}


// CHudBenchmark::Restart  @ 0006e070  (line 133)

/* DWARF original prototype: void Restart(CHudBenchmark * this) */

void __thiscall CHudBenchmark::Restart(CHudBenchmark *this)

{
  float fVar1;
  int iVar2;
  
  g_benchSwitchTime = gHUD.m_flTime + 10.0;
                    /* Unresolved local var: net_status_t status@[???] */
  g_currentstage = 1;
  this->m_fSendTime = gHUD.m_flTime;
  this->m_nStoredHopCount = 0;
  this->m_fReceiveTime = 0.0;
  this->m_StoredLatency = 0.0;
  this->m_StoredPacketLoss = 0.0;
  this->m_nTraceDone = 0;
  (*gEngfuncs.pfnServerCmd)("ppdemo 1 start\n");
  fVar1 = gHUD.m_flTime;
  iVar2 = 4;
  if (g_currentstage < 5) {
    iVar2 = g_currentstage;
  }
  this->m_fStageStarted = gHUD.m_flTime;
  gHUD.m_Benchmark.super_CHudBase.m_iFlags = gHUD.m_Benchmark.super_CHudBase.m_iFlags | 1;
  g_benchSwitchTime = g_benchSwitchTimes[iVar2] + fVar1;
  gHUD.m_Benchmark.m_fDrawTime = fVar1 + 10.0;
  return;
}


// CHudBenchmark::MsgFunc_Bench  @ 0006e110  (line 143)

/* DWARF original prototype: int MsgFunc_Bench(CHudBenchmark * this, char * pszName, int iSize, void
   * pbuf) */

int __thiscall CHudBenchmark::MsgFunc_Bench(CHudBenchmark *this,char *pszName,int iSize,void *pbuf)

{
  float fVar1;
  int in_GS_OFFSET;
  net_status_s local_158;
  char local_110 [256];
  int local_10;
  
                    /* Unresolved local var: int section@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  READ_BYTE();
  fVar1 = gHUD.m_flTime;
  this->m_fReceiveTime = gHUD.m_flTime;
  fVar1 = fVar1 - this->m_fSendTime;
  if (fVar1 < 1.0) {
    if (fVar1 <= 0.0) {
      fVar1 = 0.0;
    }
  }
  else {
    fVar1 = 1.0;
  }
  this->m_StoredLatency = fVar1;
  this->m_StoredPacketLoss = 0.0;
                    /* Unresolved local var: char[256] sz@[???]
                       Unresolved local var: netadr_t adr@[???]
                       Unresolved local var: net_status_t status@[???] */
  (*(gEngfuncs.pNetAPI)->Status)(&local_158);
  if (local_158.connected != 0) {
    __sprintf_chk(local_110,1,0x100,"%i.%i.%i.%i",local_158.remote_address.ip[0],
                  local_158.remote_address.ip[1],local_158.remote_address.ip[2],
                  local_158.remote_address.ip[3]);
    if (local_158.remote_address.type == NA_IP) {
      Trace_StartTrace(&this->m_nStoredHopCount,&this->m_nTraceDone,local_110);
    }
    else {
      this->m_nStoredHopCount = 0;
    }
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}


// CHudBenchmark::StartNextSection  @ 0006e280  (line 183)

/* DWARF original prototype: void StartNextSection(CHudBenchmark * this, int section) */

void __thiscall CHudBenchmark::StartNextSection(CHudBenchmark *this,int section)

{
  float fVar1;
  int iVar2;
  int in_GS_OFFSET;
  net_status_s local_58;
  int local_10;
  
                    /* Unresolved local var: net_status_t status@[???] */
  fVar1 = gHUD.m_flTime;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (section == 2) {
    if (this->m_nTraceDone != 0) {
      (*(gEngfuncs.pNetAPI)->Status)(&local_58);
      (*gEngfuncs.Con_Printf)("Hops == %i\n",this->m_nStoredHopCount);
      this->m_StoredPacketLoss = (float)local_58.packet_loss;
      (*gEngfuncs.Con_Printf)("PL == %i\n",(int)(float)local_58.packet_loss);
    }
    this->m_nSentFinish = 0;
    (*gEngfuncs.pfnServerCmd)("ppdemo 2\n");
  }
  else if (section == 3) {
    this->m_nSentFinish = 0;
    (*gEngfuncs.pfnServerCmd)("ppdemo 3\n");
  }
  else if (section == 1) {
    this->m_StoredLatency = 0.0;
    this->m_fReceiveTime = 0.0;
    this->m_fSendTime = fVar1;
    this->m_StoredPacketLoss = 0.0;
    this->m_nStoredHopCount = 0;
    this->m_nTraceDone = 0;
    (*gEngfuncs.pfnServerCmd)("ppdemo 1 start\n");
  }
  fVar1 = gHUD.m_flTime;
  iVar2 = 4;
  if (g_currentstage < 5) {
    iVar2 = g_currentstage;
  }
  this->m_fStageStarted = gHUD.m_flTime;
  g_benchSwitchTime = fVar1 + g_benchSwitchTimes[iVar2];
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CHudBenchmark::CountFrame  @ 0006e3d0  (line 224)

/* DWARF original prototype: void CountFrame(CHudBenchmark * this, float dt) */

void __thiscall CHudBenchmark::CountFrame(CHudBenchmark *this,float dt)

{
  this->m_nFPSCount = this->m_nFPSCount + 1;
  this->m_fAverageFT = this->m_fAverageFT + dt;
  return;
}


// Bench_CheckStart  @ 0006e3f0  (line 235)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Bench_CheckStart(void)

{
  char *__s1;
  int iVar1;
  
                    /* Unresolved local var: char * level@[???] */
  if ((((started == 0) && (g_currentstage == 0)) &&
      (__s1 = (*gEngfuncs.pfnGetLevelName)(), __s1 != (char *)0x0)) &&
     ((*__s1 != '\0' && (iVar1 = strcasecmp(__s1,"maps/ppdemo.bsp"), iVar1 == 0)))) {
    started = 1;
    (*gEngfuncs.pfnClientCmd)("ppdemostart\n");
  }
  return;
}


// CHudBenchmark::Think  @ 0006e710  (line 247)

/* DWARF original prototype: void Think(CHudBenchmark * this) */

void __thiscall CHudBenchmark::Think(CHudBenchmark *this)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  if (g_currentstage == 0) {
    return;
  }
  Trace_Think();
  if (started != 0) {
    started = 0;
    this->m_fReceiveTime = 0.0;
    this->m_nFPSCount = 0;
    this->m_fAverageFT = 0.0;
    this->m_nSentFinish = 0;
    this->m_StoredLatency = 0.0;
    this->m_StoredPacketLoss = 0.0;
    this->m_nStoredHopCount = 0;
    this->m_nTraceDone = 0;
    this->m_nObjects = 0;
    this->m_nScoreComputed = 0;
    this->m_nCompositeScore = 0;
    this->m_fAvgScore = 0.0;
    this->m_fDrawScore = 0.0;
    this->m_fAvgFrameRate = 0.0;
  }
  if (g_benchSwitchTime < gHUD.m_flTime) {
    g_currentstage = g_currentstage + 1;
    StartNextSection(this,g_currentstage);
  }
  iVar5 = g_currentstage;
  if (g_currentstage == 1) {
    if (this->m_fReceiveTime == 0.0) {
      return;
    }
                    /* Unresolved local var: float latency@[???]
                       Unresolved local var: float switch_time@[???]
                       Unresolved local var: float total_time@[???] */
    fVar4 = this->m_StoredLatency + this->m_StoredLatency;
    if (fVar4 <= 0.0) {
      fVar4 = 0.0;
    }
    else if (fVar4 < 1.0) {
      fVar4 = fVar4 * 8.0;
    }
    else {
      fVar4 = 8.0;
    }
    if (gHUD.m_flTime < fVar4 + this->m_fStageStarted + 1.0) {
      g_benchSwitchTime = gHUD.m_flTime + 10.0;
      return;
    }
    if (this->m_nSentFinish != 0) {
      return;
    }
    g_benchSwitchTime = gHUD.m_flTime + 1.0 + 1.5;
    (*gEngfuncs.pfnServerCmd)("ppdemo 1 finish\n");
    iVar5 = g_currentstage;
    this->m_nSentFinish = 1;
  }
  fVar4 = gHUD.m_flTime;
  if (iVar5 == 2) {
                    /* Unresolved local var: float elapsed@[???]
                       Unresolved local var: float total@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: float switch_time@[???] */
    if (Think::lexical_block_1::lasttime == 0.0) {
      fVar2 = this->m_fStageStarted;
    }
    else {
                    /* Unresolved local var: float dt@[???] */
      fVar2 = gHUD.m_flTime - Think::lexical_block_1::lasttime;
      if (0.0 < fVar2) {
        this->m_nFPSCount = this->m_nFPSCount + 1;
        this->m_fAverageFT = fVar2 + this->m_fAverageFT;
      }
      fVar2 = this->m_fStageStarted;
    }
    Think::lexical_block_1::lasttime = fVar4;
    fVar3 = (fVar4 - fVar2) / 12.0;
    fVar3 = fVar3 + fVar3;
    if (fVar3 <= 0.0) {
      iVar5 = 0;
    }
    else if (fVar3 < 1.0) {
      iVar5 = (int)(fVar3 * 12.0);
    }
    else {
      iVar5 = 0xc;
    }
    fVar2 = fVar2 + 12.0;
    this->m_nObjects = iVar5;
  }
  else {
    if (iVar5 != 3) {
      if (iVar5 != 4) {
        if (iVar5 < 5) {
          return;
        }
        piVar1 = &(this->super_CHudBase).m_iFlags;
        *piVar1 = *piVar1 & 0xfffffffe;
                    /* WARNING: Could not recover jumptable at 0x0006ea39. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*gEngfuncs.pfnClientCmd)("quit\n");
        return;
      }
      if (this->m_nScoreComputed != 0) {
        return;
      }
      this->m_nScoreComputed = 1;
      SetCompositeScore(&gHUD.m_Benchmark);
      return;
    }
    fVar2 = this->m_fStageStarted + 10.0;
  }
  if (fVar2 <= fVar4) {
                    /* Unresolved local var: float switch_time@[???] */
    if (this->m_nSentFinish == 0) {
      g_benchSwitchTime = fVar4 + 1.5;
      this->m_nSentFinish = 1;
    }
    return;
  }
  g_benchSwitchTime = fVar4 + 10.0;
  return;
}


// CHudBenchmark::Init  @ 0006d940  (line 399)

/* DWARF original prototype: int Init(CHudBenchmark * this) */

int __thiscall CHudBenchmark::Init(CHudBenchmark *this)

{
  CHud::AddHudElem(&gHUD,&this->super_CHudBase);
  (*gEngfuncs.pfnAddCommand)("ppdemostart",__CmdFunc_BenchMark);
  (*gEngfuncs.pfnHookUserMsg)("Bench",__MsgFunc_Bench);
  return 1;
}


// CHudBenchmark::VidInit  @ 0006d930  (line 412)

/* DWARF original prototype: int VidInit(CHudBenchmark * this) */

int __thiscall CHudBenchmark::VidInit(CHudBenchmark *this)

{
  return 1;
}


// CHudBenchmark::Bench_ScoreForValue  @ 0006e450  (line 415)

/* DWARF original prototype: int Bench_ScoreForValue(CHudBenchmark * this, int stage, float raw) */

int __thiscall CHudBenchmark::Bench_ScoreForValue(CHudBenchmark *this,int stage,float raw)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: int score@[???]
                       Unresolved local var: int power_play@[DW_OP_breg1(ECX): 0; DW_OP_lit0;
                       DW_OP_ne; DW_OP_const1u: 255; DW_OP_and; DW_OP_stack_value] */
  if (stage == 2) {
    iVar2 = (int)(this->m_fAvgFrameRate * 100.0) / 0x48;
    if (iVar2 < 0x65) {
      iVar1 = 0;
      if (-1 < iVar2) {
        iVar1 = (int)((double)iVar2 * 0.6);
      }
      goto LAB_0006e4d6;
    }
  }
  else {
    if (stage != 3) {
      if ((stage == 1) && (iVar2 = (int)(this->m_StoredLatency * 100.0), -1 < iVar2)) {
        if (100 < iVar2) {
          return 0;
        }
        return 100 - iVar2;
      }
      return 100;
    }
    iVar2 = (int)((this->m_fAvgScore * 100.0) / 40.0);
    if (-1 < iVar2) {
      iVar1 = 0;
      if (iVar2 < 0x65) {
        iVar1 = (int)((double)(100 - iVar2) * 0.6);
      }
      goto LAB_0006e4d6;
    }
  }
  iVar1 = 0x3c;
LAB_0006e4d6:
  if (g_isPowerPlay == 0) {
    return iVar1;
  }
  return (int)((float)iVar1 + 40.0);
}


// CHudBenchmark::SetCompositeScore  @ 0006e570  (line 461)

/* DWARF original prototype: void SetCompositeScore(CHudBenchmark * this) */

void __thiscall CHudBenchmark::SetCompositeScore(CHudBenchmark *this)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
                    /* Unresolved local var: int tracking_score@[???]
                       Unresolved local var: int ping_score@[???]
                       Unresolved local var: int frame_score@[???]
                       Unresolved local var: int composite@[???] */
                    /* Unresolved local var: int score@[???]
                       Unresolved local var: int power_play@[???] */
  iVar2 = (int)((this->m_fAvgScore * 100.0) / 40.0);
  if (iVar2 < 0) {
    iVar3 = 0x3c;
  }
  else {
    iVar3 = 0;
    if (iVar2 < 0x65) {
      iVar3 = (int)((double)(100 - iVar2) * 0.6);
    }
  }
  if (g_isPowerPlay != 0) {
    iVar3 = (int)((float)iVar3 + 40.0);
  }
                    /* Unresolved local var: int score@[???]
                       Unresolved local var: int power_play@[???] */
  iVar2 = (int)(this->m_StoredLatency * 100.0);
  if (iVar2 < 0) {
    fVar1 = 20.0;
  }
  else {
    fVar1 = 0.0;
    if (iVar2 < 0x65) {
      fVar1 = (float)(100 - iVar2) * 0.2;
    }
  }
                    /* Unresolved local var: int score@[???]
                       Unresolved local var: int power_play@[???] */
  iVar2 = (int)(this->m_fAvgFrameRate * 100.0) / 0x48;
  if (iVar2 < 0x65) {
    iVar4 = 0;
    if (-1 < iVar2) {
      iVar4 = (int)((double)iVar2 * 0.6);
    }
  }
  else {
    iVar4 = 0x3c;
  }
  if (g_isPowerPlay != 0) {
    iVar4 = (int)((float)iVar4 + 40.0);
  }
  iVar3 = (int)((float)iVar3 * 0.5 + (float)iVar4 * 0.3 + fVar1);
  iVar2 = 100;
  if ((iVar3 < 100) && (iVar2 = 0, -1 < iVar3)) {
    iVar2 = iVar3;
  }
  this->m_nCompositeScore = iVar2;
  return;
}


// CHudBenchmark::Draw  @ 0006d990  (line 475)

/* DWARF original prototype: int Draw(CHudBenchmark * this, float flTime) */

int __thiscall CHudBenchmark::Draw(CHudBenchmark *this,float flTime)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_GS_OFFSET;
  char local_120 [256];
  int local_20;
  
                    /* Unresolved local var: char[256] sz@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((this->m_fDrawTime < flTime) || (g_currentstage == 0)) {
    piVar1 = &(this->super_CHudBase).m_iFlags;
    *piVar1 = *piVar1 & 0xfffffffe;
  }
  else {
                    /* Unresolved local var: char[256] sz@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
    __sprintf_chk(local_120,1,0x100,"%s: %s",g_title,pp_strings[g_isPowerPlay == 0]);
    CHud::DrawHudString(&gHUD,10,0x19,0x140,local_120,0xfb,0xed,7);
    if ((g_currentstage == 4) || (g_currentstage == 1)) {
      if ((this->m_fReceiveTime == 0.0) || (this->m_nSentFinish == 0)) {
        __sprintf_chk(local_120,1,0x100,g_stage1[0]);
      }
      else {
                    /* Unresolved local var: int score@[???]
                       Unresolved local var: int power_play@[???] */
        iVar5 = (int)(this->m_StoredLatency * 100.0);
        if (iVar5 < 0) {
          iVar4 = 100;
        }
        else {
          iVar4 = 0;
          if (iVar5 < 0x65) {
            iVar4 = 100 - iVar5;
          }
        }
        __sprintf_chk(local_120,1,0x100,g_stage1[1],iVar4);
      }
      iVar5 = 0x41;
      iVar4 = 0x55;
      CHud::DrawHudString(&gHUD,10,0x2d,0x140,local_120,0xff,0xff,0xff);
      iVar3 = g_currentstage;
    }
    else {
      iVar4 = 0x41;
      iVar5 = 0x2d;
      iVar3 = g_currentstage;
    }
    g_currentstage = iVar3;
    if ((iVar3 - 2U & 0xfffffffd) == 0) {
                    /* Unresolved local var: float avg@[???] */
      if (0 < this->m_nFPSCount) {
        this->m_fAvgFrameRate = 1.0 / (this->m_fAverageFT / (float)this->m_nFPSCount);
      }
      if ((this->m_nSentFinish == 0) && (iVar3 != 4)) {
        __sprintf_chk(local_120,1,0x100,g_stage2[0]);
      }
      else {
                    /* Unresolved local var: int score@[???]
                       Unresolved local var: int power_play@[???] */
        iVar2 = 0x3c;
        iVar3 = (int)(this->m_fAvgFrameRate * 100.0) / 0x48;
        if ((iVar3 < 0x65) && (iVar2 = 0, -1 < iVar3)) {
          iVar2 = (int)((double)iVar3 * 0.6);
        }
        if (g_isPowerPlay != 0) {
          iVar2 = (int)((float)iVar2 + 40.0);
        }
        __sprintf_chk(local_120,1,0x100,g_stage2[1],iVar2);
      }
      CHud::DrawHudString(&gHUD,10,iVar5,0x140,local_120,0xff,0xff,0xff);
      iVar5 = iVar4;
    }
    if (g_currentstage - 3U < 2) {
      if ((this->m_nSentFinish == 0) && (g_currentstage != 4)) {
        __sprintf_chk(local_120,1,0x100,g_stage3[0]);
      }
      else {
                    /* Unresolved local var: int score@[???]
                       Unresolved local var: int power_play@[???] */
        iVar4 = (int)((this->m_fAvgScore * 100.0) / 40.0);
        if (iVar4 < 0) {
          iVar3 = 0x3c;
        }
        else {
          iVar3 = 0;
          if (iVar4 < 0x65) {
            iVar3 = (int)((double)(100 - iVar4) * 0.6);
          }
        }
        if (g_isPowerPlay != 0) {
          iVar3 = (int)((float)iVar3 + 40.0);
        }
        __sprintf_chk(local_120,1,0x100,g_stage3[1],iVar3);
      }
      CHud::DrawHudString(&gHUD,10,iVar5,0x140,local_120,0xff,0xff,0xff);
      iVar5 = iVar5 + 0x14;
    }
    if (g_currentstage == 4) {
      __sprintf_chk(local_120,1,0x100,g_stage4,this->m_nCompositeScore);
      CHud::DrawHudString(&gHUD,10,iVar5,0x140,local_120,0x1f,200,200);
    }
    this->m_fDrawTime = gHUD.m_flTime + 10.0;
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// CHudBenchmark::SetScore  @ 0006ea40  (line 571)

/* DWARF original prototype: void SetScore(CHudBenchmark * this, float score) */

void __thiscall CHudBenchmark::SetScore(CHudBenchmark *this,float score)

{
  if (this->m_nSentFinish == 0) {
    this->m_fDrawScore = score;
    this->m_fDrawTime = gHUD.m_flTime + 10.0;
    this->m_fAvgScore = score * 0.1 + this->m_fAvgScore * 0.9;
  }
  return;
}


// Bench_SetDotAdded  @ 0006ea90  (line 584)

void Bench_SetDotAdded(int dot)

{
  g_renderedBenchmarkDot = dot;
  return;
}


// Bench_GetDotAdded  @ 0006eaa0  (line 590)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int Bench_GetDotAdded(void)

{
  return g_renderedBenchmarkDot;
}


// Bench_SpotPosition  @ 0006eab0  (line 593)

void Bench_SpotPosition(Vector dot,Vector target)

{
  float fVar1;
  float fVar2;
  
                    /* Unresolved local var: Vector delta@[???] */
  fVar2 = *(float *)((int)dot.y + 4) - *(float *)((int)dot.x + 4);
  fVar1 = *(float *)((int)dot.y + 8) - *(float *)((int)dot.x + 8);
  fVar1 = fVar1 * fVar1 +
          (*(float *)dot.y - *(float *)dot.x) * (*(float *)dot.y - *(float *)dot.x) + fVar2 * fVar2;
  fVar2 = SQRT(fVar1);
  if (NAN(fVar2)) {
    fVar2 = sqrtf(fVar1);
  }
  if (gHUD.m_Benchmark.m_nSentFinish == 0) {
    gHUD.m_Benchmark.m_fDrawTime = gHUD.m_flTime + 10.0;
    gHUD.m_Benchmark.m_fAvgScore = gHUD.m_Benchmark.m_fAvgScore * 0.9 + fVar2 * 0.1;
    gHUD.m_Benchmark.m_fDrawScore = fVar2;
  }
  return;
}


// Bench_CheckEntity  @ 0006eb40  (line 624)

void Bench_CheckEntity(int type,cl_entity_s_conflict *ent,char *modelname)

{
  model_s_conflict *pmVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  char *pcVar7;
  longdouble lVar8;
  longdouble lVar9;
  float local_18;
  float local_14;
  float local_10;
  
  if (g_currentstage == 3) {
    iVar6 = strcasecmp(modelname,"*3");
    if (iVar6 == 0) {
                    /* Unresolved local var: model_t.conflict * pmod@[???]
                       Unresolved local var: Vector v@[???] */
      pmVar1 = ent->model;
      local_18 = (pmVar1->mins).x + (pmVar1->maxs).x;
      local_14 = (pmVar1->mins).y + (pmVar1->maxs).y;
      local_10 = (pmVar1->mins).z + (pmVar1->maxs).z;
      VectorScale(&local_18,0.5,&local_18);
      g_aimorg.x = local_18 + (ent->origin).x;
      g_aimorg.y = local_14 + (ent->origin).y;
      g_aimorg.z = local_10 + (ent->origin).z;
      if (g_currentstage != 3) {
        return;
      }
    }
    pcVar7 = strstr(modelname,"ppdemodot");
    if (pcVar7 != (char *)0x0) {
                    /* Unresolved local var: float dt@[???]
                       Unresolved local var: float fRate@[DW_OP_reg16(ST5)]
                       Unresolved local var: float fBounds@[???] */
      g_dotorg.x = (ent->origin).x;
      g_dotorg.y = (ent->origin).y;
      g_dotorg.z = (ent->origin).z;
      g_renderedBenchmarkDot = 1;
      if (g_isPowerPlay == 0) {
        fVar2 = -15.0;
        fVar3 = -8.0;
        fVar4 = 8.0;
        fVar5 = 15.0;
      }
      else {
        fVar2 = -8.0;
        fVar3 = -4.0;
        fVar4 = 4.0;
        fVar5 = 8.0;
      }
      if ((0.0 < gHUD.m_flTime - Bench_CheckEntity::lexical_block_4::fLastTime) &&
         (gHUD.m_flTime - Bench_CheckEntity::lexical_block_4::fLastTime < 1.0)) {
        lVar8 = (longdouble)(*gEngfuncs.pfnRandomFloat)(fVar3,fVar4);
        lVar9 = (longdouble)fVar5;
        if (lVar8 + (longdouble)Bench_CheckEntity::lexical_block_4::fZAdjust < (longdouble)fVar5) {
          lVar9 = lVar8 + (longdouble)Bench_CheckEntity::lexical_block_4::fZAdjust;
        }
        if (lVar9 <= (longdouble)fVar2) {
          lVar9 = (longdouble)fVar2;
        }
        Bench_CheckEntity::lexical_block_4::fZAdjust = (float)lVar9;
        (ent->origin).z = (float)((longdouble)(ent->origin).z + lVar9);
        g_fZAdjust = (float)lVar9;
      }
      Bench_CheckEntity::lexical_block_4::fLastTime = gHUD.m_flTime;
      return;
    }
  }
  return;
}


// NormalizeVector  @ 0006ed30  (line 669)

void NormalizeVector(Vector v)

{
  float *pfVar1;
  float fVar2;
  
                    /* Unresolved local var: int i@[???] */
  pfVar1 = (float *)((int)v.x + 0xc);
  do {
    fVar2 = *(float *)v.x;
    if (fVar2 < -180.0) {
      do {
        fVar2 = fVar2 + 360.0;
      } while (fVar2 < -180.0);
      *(float *)v.x = fVar2;
    }
    if (180.0 < fVar2) {
      do {
        fVar2 = fVar2 - 360.0;
      } while (180.0 < fVar2);
      *(float *)v.x = fVar2;
    }
    v.x = (vec_t)((int)v.x + 4);
  } while ((float *)v.x != pfVar1);
  return;
}


// HUD_SetupBenchObjects  @ 0006edb0  (line 687)

int HUD_SetupBenchObjects(cl_entity_t_conflict *bench,int plindex,Vector origin)

{
  pmtrace_s *ppVar1;
  float fVar2;
  vec_t vVar3;
  uint uVar4;
  model_s *pmVar5;
  float *pfVar6;
  int32 iVar7;
  uint uVar8;
  int iVar9;
  Vector *pVVar10;
  int local_c4;
  int local_b8;
  float local_b4;
  vec_t local_b0;
  vec_t local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c [3];
  float local_90 [3];
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c [3];
  pmtrace_s local_60;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int j@[???]
                       Unresolved local var: Vector ang@[???]
                       Unresolved local var: float offset@[???]
                       Unresolved local var: model_s.conflict * mdl@[???]
                       Unresolved local var: int index@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector farpoint@[???]
                       Unresolved local var: Vector centerspot@[???]
                       Unresolved local var: pmtrace_t tr@[???] */
  local_b4 = vec3_origin.x;
  local_b0 = vec3_origin.y;
  local_ac = vec3_origin.z;
  (*gEngfuncs.pfnAngleVectors)(&local_b4,&local_a8,local_9c,local_90);
  pmVar5 = (*gEngfuncs.CL_LoadModel)("models/spikeball.mdl",&local_b8);
  if (pmVar5 == (model_s *)0x0) {
    return 0;
  }
  ppVar1 = (pmtrace_s *)(local_6c + 3);
  (*(gEngfuncs.pEventAPI)->EV_SetUpPlayerPrediction)(0,1);
  (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
  (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(plindex);
  (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
  local_78 = *(float *)origin.x;
  local_74 = *(float *)((int)origin.x + 4);
  local_70 = *(float *)((int)origin.x + 8) - 512.0;
  (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)((float *)origin.x,&local_78,0,-1,ppVar1);
  local_c4 = 0;
  g_flStartTime = gHUD.m_flTime;
  local_70 = local_60.endpos.z + 72.0 + local_a0 * 250.0;
  local_74 = local_a4 * 250.0 + local_60.endpos.y;
  local_78 = local_a8 * 250.0 + local_60.endpos.x;
  pVVar10 = &bench->origin;
  do {
    pfVar6 = local_6c;
    local_b4 = 0.0;
    local_ac = 0.0;
    local_6c[0] = 0.0;
    local_6c[2] = 0.0;
    local_b0 = ((float)local_c4 / 11.0) * 360.0;
    local_6c[1] = local_b0;
                    /* Unresolved local var: int i@[???] */
    do {
      fVar2 = *pfVar6;
      if (fVar2 < -180.0) {
        do {
          fVar2 = fVar2 + 360.0;
        } while (fVar2 < -180.0);
        *pfVar6 = fVar2;
      }
      if (180.0 < fVar2) {
        do {
          fVar2 = fVar2 - 360.0;
        } while (180.0 < fVar2);
        *pfVar6 = fVar2;
      }
      pfVar6 = pfVar6 + 1;
    } while ((pmtrace_s *)pfVar6 != ppVar1);
    (*gEngfuncs.pfnAngleVectors)(&local_b4,&local_a8,local_9c,local_90);
    *(int *)(pVVar10 + -0xb0) = 0;
    *(model_s **)((int)(pVVar10 + 6) + 4) = pmVar5;
    *(int *)(pVVar10 + -0xb4) = local_b8;
    *(short *)((int)(pVVar10 + -0xb3) + 6) = 0;
    local_7c = local_a0 * 80.0 + local_70;
    local_80 = local_a4 * 80.0 + local_74;
    local_84 = local_a8 * 80.0 + local_78;
    (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_78,&local_84,0,-1,ppVar1);
    pVVar10->x = local_60.endpos.x;
    pVVar10[-0xb6].x = local_60.endpos.x;
    iVar9 = 3;
    pVVar10->y = local_60.endpos.y;
    pVVar10->z = local_60.endpos.z;
    pVVar10[-0xb6].y = local_60.endpos.y;
    pVVar10[-0xb6].z = local_60.endpos.z;
    pVVar10[-0xae].x = vec3_origin.x;
    pVVar10[-0xae].y = vec3_origin.y;
    vVar3 = vec3_origin.z;
    pVVar10[-0xb5].z = 0.0;
    pVVar10[-0xb5].x = 0.0;
    pVVar10[-0xb5].y = 0.0;
    pVVar10[-0xae].z = vVar3;
    do {
      iVar7 = (*gEngfuncs.pfnRandomLong)(-300,300);
      pVVar10[-0xed].x = 0.0;
      *(float *)((int)(pVVar10 + -0xee) + 4) = (float)iVar7;
      iVar7 = (*gEngfuncs.pfnRandomLong)(-300,300);
      iVar9 = iVar9 + -1;
      *(float *)((int)(pVVar10 + -0xee) + 8) = (float)iVar7;
    } while (iVar9 != 0);
    *(int *)(pVVar10 + -0xb1) = 0;
    uVar4 = 0;
    do {
      uVar8 = uVar4;
      *(undefined4 *)((int)pVVar10 + (uVar8 - 0x9ec)) =
           *(undefined4 *)((int)pVVar10 + (uVar8 - 0x898));
      *(undefined4 *)((int)pVVar10 + (uVar8 - 0x9e8)) =
           *(undefined4 *)((int)(pVVar10 + -0xb7) + uVar8);
      uVar4 = uVar8 + 8;
    } while (uVar8 + 8 < 0x150);
    local_c4 = local_c4 + 1;
    *(undefined4 *)((int)(pVVar10 + -0xd3) + uVar8) =
         *(undefined4 *)((int)pVVar10 + (uVar8 - 0x890));
    pVVar10 = pVVar10 + 0xfa;
  } while (local_c4 != 0xc);
  (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
  return 1;
}


// HUD_CreateBenchObjects  @ 0006f1d0  (line 795)

void HUD_CreateBenchObjects(Vector origin)

{
  pmtrace_s *ppVar1;
  float fVar2;
  float fVar3;
  vec_t vVar4;
  Vector origin_00;
  float scale;
  float fVar5;
  float fVar6;
  uint uVar7;
  cl_entity_s *pcVar8;
  int iVar9;
  float *pfVar10;
  uint uVar11;
  int iVar12;
  Vector *veca;
  longdouble extraout_ST0;
  longdouble extraout_ST0_00;
  undefined4 in_stack_fffffef0;
  vec_t in_stack_fffffef4;
  double local_d4;
  double local_cc;
  float local_c0;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8 [3];
  float local_9c [3];
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  undefined4 local_70;
  float local_6c [2];
  vec_t local_64;
  pmtrace_s local_60;
  
                    /* Unresolved local var: cl_entity_t.conflict * player@[???]
                       Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: Vector farpoint@[???]
                       Unresolved local var: Vector centerspot@[???]
                       Unresolved local var: float frametime@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: float frac2@[???]
                       Unresolved local var: float dt@[???]
                       Unresolved local var: pmtrace_t tr@[???]
                       Unresolved local var: int i@[???] */
  if ((HUD_CreateBenchObjects(Vector)::bench == '\0') &&
     (iVar9 = __cxa_guard_acquire(&HUD_CreateBenchObjects(Vector)::bench), iVar9 != 0)) {
    __cxa_guard_release(&HUD_CreateBenchObjects(Vector)::bench);
  }
  if (gHUD.m_flTime == HUD_CreateBenchObjects::last_time) {
    return;
  }
  scale = gHUD.m_flTime - HUD_CreateBenchObjects::last_time;
  HUD_CreateBenchObjects::last_time = gHUD.m_flTime;
  if (scale <= 0.0) {
    HUD_CreateBenchObjects::last_time = gHUD.m_flTime;
    return;
  }
  if (HUD_CreateBenchObjects::failed != 0) {
    HUD_CreateBenchObjects::last_time = gHUD.m_flTime;
    return;
  }
  pcVar8 = (*gEngfuncs.GetLocalPlayer)();
  if (pcVar8 == (cl_entity_s *)0x0) {
LAB_0006f2bc:
    HUD_CreateBenchObjects::failed = 1;
  }
  else {
    if (HUD_CreateBenchObjects::first != 0) {
      HUD_CreateBenchObjects::first = 0;
      local_60.allsolid = *(qboolean *)origin.x;
      local_60.startsolid = *(undefined4 *)((int)origin.x + 4);
      local_60.inopen = *(undefined4 *)((int)origin.x + 8);
      origin_00.y = (vec_t)in_stack_fffffef0;
      origin_00.x = (vec_t)(local_6c + 3);
      origin_00.z = in_stack_fffffef4;
      iVar9 = HUD_SetupBenchObjects(HUD_CreateBenchObjects::bench,pcVar8->index + -1,origin_00);
      if (iVar9 == 0) goto LAB_0006f2bc;
    }
    (*(gEngfuncs.pEventAPI)->EV_SetUpPlayerPrediction)(0,1);
    (*(gEngfuncs.pEventAPI)->EV_PushPMStates)();
    (*(gEngfuncs.pEventAPI)->EV_SetSolidPlayers)(pcVar8->index + -1);
    (*(gEngfuncs.pEventAPI)->EV_SetTraceHull)(2);
    fVar5 = gHUD.m_flTime - g_flStartTime;
    if (0.0 <= fVar5) {
      fVar6 = fVar5 / 10.0;
      if (1.0 < fVar6) {
        fVar6 = fVar6 - (float)(int)fVar6;
      }
      fVar5 = fVar5 * 0.25;
      if (1.0 < fVar5) {
        fVar5 = fVar5 - (float)(int)fVar5;
      }
      ppVar1 = (pmtrace_s *)(local_6c + 3);
      (*gEngfuncs.pfnAngleVectors)(&vec3_origin.x,&local_b4,local_a8,local_9c);
      local_84 = *(float *)origin.x;
      local_80 = *(float *)((int)origin.x + 4);
      veca = &HUD_CreateBenchObjects::bench[0].curstate.angles;
      local_7c = *(float *)((int)origin.x + 8) - 512.0;
      (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)((float *)origin.x,&local_84,0,-1,ppVar1);
      local_7c = local_ac * 250.0 + local_60.endpos.z + 72.0;
      local_80 = local_b0 * 250.0 + local_60.endpos.y;
      local_84 = local_b4 * 250.0 + local_60.endpos.x;
      iVar9 = 0;
      do {
                    /* Unresolved local var: int j@[???]
                       Unresolved local var: float jitter@[???]
                       Unresolved local var: float jfrac@[???]
                       Unresolved local var: float offset@[???]
                       Unresolved local var: float ofs_radius@[???]
                       Unresolved local var: Vector ang@[???] */
        pfVar10 = local_6c;
        local_78 = 0.0;
        local_70 = 0;
        local_6c[0] = 0.0;
        local_64 = 0.0;
        fVar3 = ((float)iVar9 / 11.0) * 360.0;
        local_c0 = fVar6 * 360.0 + fVar3;
        local_6c[1] = local_c0;
                    /* Unresolved local var: int i@[???] */
        do {
          fVar2 = *pfVar10;
          if (fVar2 < -180.0) {
            do {
              fVar2 = fVar2 + 360.0;
            } while (fVar2 < -180.0);
            *pfVar10 = fVar2;
          }
          if (180.0 < fVar2) {
            do {
              fVar2 = fVar2 - 360.0;
            } while (180.0 < fVar2);
            *pfVar10 = fVar2;
          }
          pfVar10 = pfVar10 + 1;
        } while ((pmtrace_s *)pfVar10 != ppVar1);
        local_74 = local_c0;
        (*gEngfuncs.pfnAngleVectors)(&local_78,&local_b4,local_a8,local_9c);
        sincos((double)fVar3 + (double)(fVar5 + fVar5) * 3.141592653589793,&local_cc,&local_d4);
        local_c0 = (float)local_cc * 5.0 + 80.0;
        local_8c = local_b0 * local_c0 + local_80;
        local_90 = local_c0 * local_b4 + local_84;
        local_88 = (float)local_d4 * 10.0 + local_ac * local_c0 + local_7c;
        (*(gEngfuncs.pEventAPI)->EV_PlayerTrace)(&local_84,&local_90,0,-1,ppVar1);
        VectorMA(&veca->x,scale,(float *)((int)(veca + -0x39) + 4),&veca->x);
        pfVar10 = local_6c;
        local_6c[0] = veca->x;
        local_6c[1] = veca->y;
                    /* Unresolved local var: int i@[???] */
        local_64 = veca->z;
        do {
          fVar3 = *pfVar10;
          if (fVar3 < -180.0) {
            do {
              fVar3 = fVar3 + 360.0;
            } while (fVar3 < -180.0);
            *pfVar10 = fVar3;
          }
          if (180.0 < fVar3) {
            do {
              fVar3 = fVar3 - 360.0;
            } while (180.0 < fVar3);
            *pfVar10 = fVar3;
          }
          pfVar10 = pfVar10 + 1;
        } while (ppVar1 != (pmtrace_s *)pfVar10);
        if (iVar9 == 0xb) {
          g_aimorg.x = local_60.endpos.x;
          g_aimorg.y = local_60.endpos.y;
          g_aimorg.z = local_60.endpos.z;
        }
        fVar3 = 0.5;
        if (g_isPowerPlay == 0) {
          fVar3 = 8.0;
        }
        fVar3 = fVar3 * ((float)gHUD.m_Benchmark.m_nObjects / 12.0);
        (*gEngfuncs.pfnRandomFloat)(-fVar3,fVar3);
        local_60.endpos.x = (vec_t)(extraout_ST0 + (longdouble)local_60.endpos.x);
        (*gEngfuncs.pfnRandomFloat)(-fVar3,fVar3);
        *(vec_t *)((int)(veca + 0xb5) + 8) = local_60.endpos.z;
        veca[-1].z = local_60.endpos.z;
        veca[0xb5].x = local_60.endpos.x;
        veca[-1].x = local_60.endpos.x;
        veca[0xb6].x = veca->x;
        local_60.endpos.y = (vec_t)(extraout_ST0_00 + (longdouble)local_60.endpos.y);
        *(vec_t *)((int)(veca + 0xb6) + 4) = veca->y;
        vVar4 = veca->z;
        *(vec_t *)((int)(veca + 0xb5) + 4) = local_60.endpos.y;
        veca[-1].y = local_60.endpos.y;
        *(vec_t *)((int)(veca + 0xb6) + 8) = vVar4;
        uVar7 = 0;
        do {
          uVar11 = uVar7;
          *(undefined4 *)((int)veca + (uVar11 - 0x170)) =
               *(undefined4 *)((int)veca + (uVar11 - 0x1c));
          *(undefined4 *)((int)veca + (uVar11 - 0x16c)) = *(undefined4 *)((int)(veca + -2) + uVar11)
          ;
          uVar7 = uVar11 + 8;
        } while (uVar11 + 8 < 0x150);
        *(undefined4 *)((int)(veca + -0x1e) + uVar11) = *(undefined4 *)((int)veca + (uVar11 - 0x14))
        ;
        if (0xb - iVar9 < gHUD.m_Benchmark.m_nObjects) {
          iVar12 = *(int *)(veca + 4);
          if (iVar12 == 0xff) {
            *(int *)((int)(veca + 3) + 8) = 0;
          }
          else {
            *(int *)((int)(veca + 3) + 8) = 4;
            iVar12 = (int)(scale * 150.0 + (float)iVar12);
            if (0xfe < iVar12) {
              iVar12 = 0xff;
            }
            *(int *)(veca + 4) = iVar12;
          }
          (*gEngfuncs.CL_CreateVisibleEntity)(0,(cl_entity_s *)((int)(veca + -0x3c) + 4));
        }
        iVar9 = iVar9 + 1;
        veca = veca + 0xfa;
      } while (iVar9 != 0xc);
      (*(gEngfuncs.pEventAPI)->EV_PopPMStates)();
    }
  }
  return;
}


// Bench_AddObjects  @ 0006f920  (line 1008)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Bench_AddObjects(void)

{
  Vector origin;
  float __x;
  float fVar1;
  undefined8 in_stack_ffffffc8;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  if (g_renderedBenchmarkDot != 0) {
                    /* Unresolved local var: Vector delta@[???] */
    __x = (g_aimorg.z - g_dotorg.z) * (g_aimorg.z - g_dotorg.z) +
          (g_aimorg.y - g_dotorg.y) * (g_aimorg.y - g_dotorg.y) +
          (g_aimorg.x - g_dotorg.x) * (g_aimorg.x - g_dotorg.x);
    fVar1 = SQRT(__x);
    if (NAN(fVar1)) {
      fVar1 = sqrtf(__x);
    }
    if (gHUD.m_Benchmark.m_nSentFinish == 0) {
      gHUD.m_Benchmark.m_fDrawTime = gHUD.m_flTime + 10.0;
      g_renderedBenchmarkDot = 0;
      gHUD.m_Benchmark.m_fAvgScore = gHUD.m_Benchmark.m_fAvgScore * 0.9 + fVar1 * 0.1;
      gHUD.m_Benchmark.m_fDrawScore = fVar1;
    }
    else {
      g_renderedBenchmarkDot = 0;
    }
  }
  if (g_currentstage == 2) {
    local_18 = v_origin.x;
    local_14 = v_origin.y;
    local_10 = v_origin.z;
    origin.y = (vec_t)(int)in_stack_ffffffc8;
    origin.z = (vec_t)(int)((ulonglong)in_stack_ffffffc8 >> 0x20);
    origin.x = (vec_t)&local_18;
    HUD_CreateBenchObjects(origin);
  }
  return;
}


// Bench_SetViewAngles  @ 0006fa20  (line 1025)

void Bench_SetViewAngles(int recalc_wander,float *viewangles,float frametime,usercmd_s *cmd)

{
  float fVar1;
  float fVar2;
  float fVar3;
  vec_t vVar4;
  vec_t vVar5;
  float local_18;
  float local_14;
  float local_10;
  
  vVar5 = vec3_origin.z;
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: Vector lookdir@[???] */
  vVar4 = vec3_origin.y;
  if (g_currentstage != 0) {
    if (g_currentstage == 1) {
      v_stochastic.x = vec3_origin.x;
      *viewangles = vec3_origin.x;
      v_stochastic.y = vVar4;
      v_stochastic.z = vVar5;
      viewangles[1] = vec3_origin.y;
      vVar4 = vec3_origin.z;
      viewangles[1] = -90.0;
      viewangles[2] = vVar4;
      if (cmd != (usercmd_s *)0x0) {
LAB_0006fafb:
        cmd->buttons = 0;
        return;
      }
    }
    else {
      if (g_currentstage - 2U < 2) {
        local_18 = g_aimorg.x - v_origin.x;
        local_14 = g_aimorg.y - v_origin.y;
        local_10 = g_aimorg.z - v_origin.z;
        VectorNormalize(&local_18);
        VectorAngles(&local_18,viewangles);
        fVar1 = v_stochastic.x - *viewangles;
        *viewangles = fVar1;
        fVar2 = viewangles[1] + v_stochastic.y;
        viewangles[1] = fVar2;
        fVar3 = viewangles[2] + v_stochastic.z;
        viewangles[2] = fVar3;
        if (180.0 < fVar1) {
          fVar1 = fVar1 - 360.0;
          *viewangles = fVar1;
        }
        if (fVar1 < -180.0) {
          *viewangles = fVar1 + 360.0;
        }
        if (180.0 < fVar2) {
          fVar2 = fVar2 - 360.0;
          viewangles[1] = fVar2;
        }
        if (fVar2 < -180.0) {
          viewangles[1] = fVar2 + 360.0;
        }
        if (180.0 < fVar3) {
          fVar3 = fVar3 - 360.0;
          viewangles[2] = fVar3;
        }
        if (fVar3 < -180.0) {
          viewangles[2] = fVar3 + 360.0;
        }
      }
      else {
        *viewangles = vec3_origin.x;
        viewangles[1] = vec3_origin.y;
        viewangles[2] = vec3_origin.z;
      }
      if (cmd != (usercmd_s *)0x0) {
        if (g_currentstage != 3) goto LAB_0006fafb;
        cmd->buttons = 1;
      }
    }
  }
  return;
}


// Bench_SetViewOrigin  @ 0006fc40  (line 1100)

void Bench_SetViewOrigin(float *vieworigin,float frametime)

{
  float fVar1;
  double dVar2;
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  float local_18;
  float local_14;
  float local_10;
  
                    /* Unresolved local var: float dt@[???]
                       Unresolved local var: float frac@[???]
                       Unresolved local var: float offset_amt@[???]
                       Unresolved local var: float drift@[???]
                       Unresolved local var: Vector ang@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector move@[???] */
  if ((g_currentstage == 2) && (0.0 <= gHUD.m_flTime - g_flStartTime)) {
    dVar2 = sin((double)(((gHUD.m_flTime - g_flStartTime) / 7.1) * 6.2831855));
    local_24 = vec3_origin.x;
    fVar1 = (float)dVar2 * 60.0;
    local_20 = vec3_origin.y;
    local_1c = vec3_origin.z;
    (*gEngfuncs.pfnAngleVectors)(&local_24,(float *)0x0,&local_18,(float *)0x0);
    *vieworigin = fVar1 * local_18 + *vieworigin;
    vieworigin[1] = local_14 * fVar1 + vieworigin[1];
    vieworigin[2] = local_10 * fVar1 + vieworigin[2];
    return;
  }
  return;
}


