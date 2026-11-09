// VoiceRecord_OpenAL::ClearInterfaces  @ 001c65e0
/* DWARF original prototype: void ClearInterfaces(VoiceRecord_OpenAL * this) */

void __thiscall VoiceRecord_OpenAL::ClearInterfaces(VoiceRecord_OpenAL *this)

{
  this->m_Device = (ALCdevice *)0x0;
  return;
}


// VoiceRecord_OpenAL::GetRecordedData  @ 001c6400
/* DWARF original prototype: int GetRecordedData(VoiceRecord_OpenAL * this, short * pOut, int
   nSamples) */

int __thiscall
VoiceRecord_OpenAL::GetRecordedData(VoiceRecord_OpenAL *this,short *pOut,int nSamples)

{
  int iVar1;
  int local_10 [2];
  
                    /* Unresolved local var: int frameCount@[???] */
  local_10[0] = 0;
  alcGetIntegerv(this->m_Device,0x312,1,local_10);
  if (0 < local_10[0]) {
    if (nSamples < local_10[0]) {
      local_10[0] = nSamples;
    }
    alcCaptureSamples(this->m_Device,pOut,local_10[0]);
    iVar1 = alGetError();
    if (iVar1 == 0) {
      return local_10[0];
    }
  }
  return 0;
}


// VoiceRecord_OpenAL::Idle  @ 001c6340
/* DWARF original prototype: void Idle(VoiceRecord_OpenAL * this) */

void __thiscall VoiceRecord_OpenAL::Idle(VoiceRecord_OpenAL *this)

{
  return;
}


// VoiceRecord_OpenAL::Init  @ 001c63d0
/* DWARF original prototype: bool Init(VoiceRecord_OpenAL * this, int sampleRate) */

bool __thiscall VoiceRecord_OpenAL::Init(VoiceRecord_OpenAL *this,int sampleRate)

{
  this->m_nSampleRate = sampleRate;
  alcCaptureCloseDevice(this->m_Device);
  this->m_Device = (ALCdevice *)0x0;
  return true;
}


// VoiceRecord_OpenAL::InitalizeInterfaces  @ 001c6570
/* DWARF original prototype: bool InitalizeInterfaces(VoiceRecord_OpenAL * this) */

bool __thiscall VoiceRecord_OpenAL::InitalizeInterfaces(VoiceRecord_OpenAL *this)

{
  ALCdevice *pAVar1;
  int iVar2;
  
  pAVar1 = (ALCdevice *)
           alcCaptureOpenDevice(0,this->m_nSampleRate,0x1101,this->m_nSampleRate * 0x14);
  this->m_Device = pAVar1;
  if (pAVar1 != (ALCdevice *)0x0) {
    iVar2 = alGetError();
    return iVar2 == 0;
  }
  return false;
}


// VoiceRecord_OpenAL::RecordStart  @ 001c64e0
/* DWARF original prototype: bool RecordStart(VoiceRecord_OpenAL * this) */

bool __thiscall VoiceRecord_OpenAL::RecordStart(VoiceRecord_OpenAL *this)

{
  int iVar1;
  ALCdevice *pAVar2;
  bool bVar3;
  
  pAVar2 = this->m_Device;
  if (pAVar2 == (ALCdevice *)0x0) {
    pAVar2 = (ALCdevice *)
             alcCaptureOpenDevice(0,this->m_nSampleRate,0x1101,this->m_nSampleRate * 0x14);
    this->m_Device = pAVar2;
    if (pAVar2 != (ALCdevice *)0x0) {
      alGetError();
      pAVar2 = this->m_Device;
      if (pAVar2 != (ALCdevice *)0x0) goto LAB_001c64ef;
    }
    bVar3 = false;
  }
  else {
LAB_001c64ef:
    alcCaptureStart(pAVar2);
    iVar1 = alGetError();
    bVar3 = iVar1 == 0;
  }
  return bVar3;
}


// VoiceRecord_OpenAL::RecordStop  @ 001c63a0
/* DWARF original prototype: void RecordStop(VoiceRecord_OpenAL * this) */

void __thiscall VoiceRecord_OpenAL::RecordStop(VoiceRecord_OpenAL *this)

{
  ALCdevice *pAVar1;
  
  pAVar1 = (ALCdevice *)0x0;
  if (this->m_Device != (ALCdevice *)0x0) {
    alcCaptureStop(this->m_Device);
    pAVar1 = this->m_Device;
  }
  alcCaptureCloseDevice(pAVar1);
  this->m_Device = (ALCdevice *)0x0;
  return;
}


// VoiceRecord_OpenAL::Release  @ 001c6480
/* DWARF original prototype: void Release(VoiceRecord_OpenAL * this) */

void __thiscall VoiceRecord_OpenAL::Release(VoiceRecord_OpenAL *this)

{
  _func_int_varargs *UNRECOVERED_JUMPTABLE;
  ALCdevice *pAVar1;
  
  if (this == (VoiceRecord_OpenAL *)0x0) {
    return;
  }
  UNRECOVERED_JUMPTABLE = (this->super_IVoiceRecord)._vptr_IVoiceRecord[1];
  if (UNRECOVERED_JUMPTABLE == ~VoiceRecord_OpenAL) {
    pAVar1 = this->m_Device;
    (this->super_IVoiceRecord)._vptr_IVoiceRecord =
         (_func_int_varargs **)&PTR__VoiceRecord_OpenAL_002705b8;
    alcCaptureCloseDevice(pAVar1);
    operator_delete(this);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x001c64d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// VoiceRecord_OpenAL::ReleaseInterfaces  @ 001c65c0
/* DWARF original prototype: void ReleaseInterfaces(VoiceRecord_OpenAL * this) */

void __thiscall VoiceRecord_OpenAL::ReleaseInterfaces(VoiceRecord_OpenAL *this)

{
  alcCaptureCloseDevice(this->m_Device);
  this->m_Device = (ALCdevice *)0x0;
  return;
}


// VoiceRecord_OpenAL::VoiceRecord_OpenAL  @ 001c6550
/* DWARF original prototype: void VoiceRecord_OpenAL(VoiceRecord_OpenAL * this) */

void __thiscall VoiceRecord_OpenAL::VoiceRecord_OpenAL(VoiceRecord_OpenAL *this)

{
  (this->super_IVoiceRecord)._vptr_IVoiceRecord =
       (_func_int_varargs **)&PTR__VoiceRecord_OpenAL_002705b8;
  this->m_Device = (ALCdevice *)0x0;
  this->m_nSampleRate = 0;
  return;
}


// VoiceRecord_OpenAL::~VoiceRecord_OpenAL  @ 001c6350
/* DWARF original prototype: void ~VoiceRecord_OpenAL(VoiceRecord_OpenAL * this, int __in_chrg) */

void __thiscall VoiceRecord_OpenAL::~VoiceRecord_OpenAL(VoiceRecord_OpenAL *this,int __in_chrg)

{
  (this->super_IVoiceRecord)._vptr_IVoiceRecord =
       (_func_int_varargs **)&PTR__VoiceRecord_OpenAL_002705b8;
  alcCaptureCloseDevice();
  return;
}


// VoiceRecord_OpenAL::~VoiceRecord_OpenAL  @ 001c6370
/* DWARF original prototype: void ~VoiceRecord_OpenAL(VoiceRecord_OpenAL * this, int __in_chrg) */

void __thiscall VoiceRecord_OpenAL::~VoiceRecord_OpenAL(VoiceRecord_OpenAL *this,int __in_chrg)

{
  ALCdevice *pAVar1;
  
  pAVar1 = this->m_Device;
  (this->super_IVoiceRecord)._vptr_IVoiceRecord =
       (_func_int_varargs **)&PTR__VoiceRecord_OpenAL_002705b8;
  alcCaptureCloseDevice(pAVar1);
  operator_delete(this);
  return;
}


