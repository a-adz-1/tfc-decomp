// EngineWrapper::CL_DemoPlaySound  @ 000e7e70
/* DWARF original prototype: void CL_DemoPlaySound(EngineWrapper * this, int channel, char * sample,
   float attenuation, float volume, int flags, int pitch) */

void __thiscall
EngineWrapper::CL_DemoPlaySound
          (EngineWrapper *this,int channel,char *sample,float attenuation,float volume,int flags,
          int pitch)

{
  ::CL_DemoPlaySound(channel,sample,attenuation,volume,flags,pitch);
  return;
}


// EngineWrapper::CL_QueueEvent  @ 000e7e20
/* DWARF original prototype: void CL_QueueEvent(EngineWrapper * this, int flags, int index, float
   delay, event_args_t * pargs) */

void __thiscall
EngineWrapper::CL_QueueEvent
          (EngineWrapper *this,int flags,int index,float delay,event_args_t *pargs)

{
  ::CL_QueueEvent(flags,index,delay,pargs);
  return;
}


