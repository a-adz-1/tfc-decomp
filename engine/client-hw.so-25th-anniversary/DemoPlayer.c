// DemoPlayer_GetDemoViewInfo  @ 001bb0e0
void DemoPlayer_GetDemoViewInfo(ref_params_t *rp,float *view,int *viewmodel)

{
  if (s_DemoPlayer != (IDemoPlayer *)0x0) {
    (*s_DemoPlayer->_vptr_IDemoPlayer[0x2d])(s_DemoPlayer,rp,view,viewmodel);
  }
  return;
}


// DemoPlayer_Init  @ 001bb1c0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int DemoPlayer_Init(void)

{
  _func_int_varargs *p_Var1;
  int iVar2;
  
  s_DemoPlayer = (IDemoPlayer *)
                 SystemWrapper::GetModule(&gSystemWrapper,"demoplayer001","demoplayer",(char *)0x0);
  s_DemoPlayerMode = 0;
  if (s_DemoPlayer != (IDemoPlayer *)0x0) {
    p_Var1 = s_DemoPlayer->_vptr_IDemoPlayer[0x1a];
    iVar2 = COM_CheckParm("-demoedit");
    (*p_Var1)(s_DemoPlayer,(uint)(iVar2 != 0));
    return 1;
  }
  Con_DPrintf("Failed to load demo player module.\n");
  return 0;
}


// DemoPlayer_IsActive  @ 001bb000
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int DemoPlayer_IsActive(void)

{
  if (s_DemoPlayer != (IDemoPlayer *)0x0) {
    return (uint)(s_DemoPlayerMode != 0);
  }
  return 0;
}


// DemoPlayer_LoadGame  @ 001bb030
int DemoPlayer_LoadGame(char *filename)

{
  uint uVar1;
  
  if (s_DemoPlayer != (IDemoPlayer *)0x0) {
    uVar1 = (*s_DemoPlayer->_vptr_IDemoPlayer[0x2a])(s_DemoPlayer,filename);
    return uVar1 & 0xff;
  }
  return 0;
}


// DemoPlayer_ReadDemoMessage  @ 001bb0a0
int DemoPlayer_ReadDemoMessage(uchar *buffer,int size)

{
  int iVar1;
  
  if (s_DemoPlayer != (IDemoPlayer *)0x0) {
    iVar1 = (*s_DemoPlayer->_vptr_IDemoPlayer[0x2e])(s_DemoPlayer,buffer,size);
    return iVar1;
  }
  return 0;
}


// DemoPlayer_ReadNetchanState  @ 001bb160
void DemoPlayer_ReadNetchanState
               (int *incoming_sequence,int *incoming_acknowledged,
               int *incoming_reliable_acknowledged,int *incoming_reliable_sequence,
               int *outgoing_sequence,int *reliable_sequence,int *last_reliable_sequence)

{
  if (s_DemoPlayer != (IDemoPlayer *)0x0) {
    (*s_DemoPlayer->_vptr_IDemoPlayer[0x2f])
              (s_DemoPlayer,incoming_sequence,incoming_acknowledged,incoming_reliable_acknowledged,
               incoming_reliable_sequence,outgoing_sequence,reliable_sequence,last_reliable_sequence
              );
  }
  return;
}


// DemoPlayer_SetActive  @ 001baff0
void DemoPlayer_SetActive(int state)

{
  s_DemoPlayerMode = state;
  return;
}


// DemoPlayer_SetEditMode  @ 001bb070
void DemoPlayer_SetEditMode(int state)

{
  if (s_DemoPlayer != (IDemoPlayer *)0x0) {
    (*s_DemoPlayer->_vptr_IDemoPlayer[0x1a])(s_DemoPlayer,(uint)(state != 0));
  }
  return;
}


// DemoPlayer_ShowGUI  @ 001bb140
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DemoPlayer_ShowGUI(void)

{
  if (s_DemoPlayer != (IDemoPlayer *)0x0) {
    VGuiWrap2_ShowDemoPlayer();
    return;
  }
  return;
}


// DemoPlayer_Stop  @ 001bb120
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void DemoPlayer_Stop(void)

{
  if (s_DemoPlayer != (IDemoPlayer *)0x0) {
    (*s_DemoPlayer->_vptr_IDemoPlayer[0x2b])(s_DemoPlayer);
  }
  return;
}


