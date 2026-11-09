// CHudBenchmark::MsgFunc_Bench  @ 00091aa0
/* DWARF original prototype: int MsgFunc_Bench(CHudBenchmark * this, char * pszName, int iSize, void
   * pbuf) */

int __thiscall CHudBenchmark::MsgFunc_Bench(CHudBenchmark *this,char *pszName,int iSize,void *pbuf)

{
  float fVar1;
  char local_154 [256];
  net_status_s local_54;
  
                    /* Unresolved local var: int section@[???] */
  READ_BYTE();
  gHUD.m_Benchmark.m_fReceiveTime = gHUD.m_flTime;
  fVar1 = gHUD.m_flTime - gHUD.m_Benchmark.m_fSendTime;
  gHUD.m_Benchmark.m_StoredLatency = 1.0;
  if ((fVar1 <= 1.0) && (gHUD.m_Benchmark.m_StoredLatency = 0.0, 0.0 <= fVar1)) {
    gHUD.m_Benchmark.m_StoredLatency = fVar1;
  }
                    /* Unresolved local var: char[256] sz@[???]
                       Unresolved local var: netadr_t adr@[???]
                       Unresolved local var: net_status_t status@[???] */
  gHUD.m_Benchmark.m_StoredPacketLoss = 0.0;
  (*(gEngfuncs.pNetAPI)->Status)(&local_54);
  if (local_54.connected != 0) {
    sprintf(local_154,"%i.%i.%i.%i",(uint)local_54.remote_address.ip[0],
            (uint)local_54.remote_address.ip[1],(uint)local_54.remote_address.ip[2],
            (uint)local_54.remote_address.ip[3]);
    if (local_54.remote_address.type != NA_IP) {
      gHUD.m_Benchmark.m_nStoredHopCount = 0;
      return 1;
    }
    Trace_StartTrace(&gHUD.m_Benchmark.m_nStoredHopCount,&gHUD.m_Benchmark.m_nTraceDone,local_154);
  }
  return 1;
}


// CHudBenchmark::MsgFunc_Bench  @ 00092140
/* DWARF original prototype: int MsgFunc_Bench(CHudBenchmark * this, char * pszName, int iSize, void
   * pbuf) */

int __thiscall CHudBenchmark::MsgFunc_Bench(CHudBenchmark *this,char *pszName,int iSize,void *pbuf)

{
  float fVar1;
  float fVar2;
  char local_154 [256];
  net_status_s local_54;
  
                    /* Unresolved local var: int section@[???] */
  READ_BYTE();
  fVar1 = gHUD.m_flTime;
  this->m_fReceiveTime = gHUD.m_flTime;
  fVar1 = fVar1 - this->m_fSendTime;
  fVar2 = 1.0;
  if ((fVar1 <= 1.0) && (fVar2 = 0.0, 0.0 <= fVar1)) {
    fVar2 = fVar1;
  }
  this->m_StoredLatency = fVar2;
  this->m_StoredPacketLoss = 0.0;
                    /* Unresolved local var: char[256] sz@[???]
                       Unresolved local var: netadr_t adr@[???]
                       Unresolved local var: net_status_t status@[???] */
  (*(gEngfuncs.pNetAPI)->Status)(&local_54);
  if (local_54.connected != 0) {
    sprintf(local_154,"%i.%i.%i.%i",(uint)local_54.remote_address.ip[0],
            (uint)local_54.remote_address.ip[1],(uint)local_54.remote_address.ip[2],
            (uint)local_54.remote_address.ip[3]);
    if (local_54.remote_address.type == NA_IP) {
      Trace_StartTrace(&this->m_nStoredHopCount,&this->m_nTraceDone,local_154);
    }
    else {
      this->m_nStoredHopCount = 0;
    }
  }
  return 1;
}


