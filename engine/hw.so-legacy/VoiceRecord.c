// VoiceRecord_OpenAL::ClearInterfaces  @ 00215c30
/* DWARF original prototype: void ClearInterfaces(VoiceRecord_OpenAL * this) */

void __thiscall VoiceRecord_OpenAL::ClearInterfaces(VoiceRecord_OpenAL *this)

{
  this->m_Device = (ALCdevice *)0x0;
  return;
}


// VoiceRecord_OpenAL::GetRecordedData  @ 002159c0
/* DWARF original prototype: int GetRecordedData(VoiceRecord_OpenAL * this, short * pOut, int
   nSamples) */

int __thiscall
VoiceRecord_OpenAL::GetRecordedData(VoiceRecord_OpenAL *this,short *pOut,int nSamples)

{
  int iVar1;
  int iVar2;
  int local_1c [4];
  
                    /* Unresolved local var: int frameCount@[???] */
  local_1c[0] = 0;
  alcGetIntegerv(this->m_Device,0x312,1,local_1c);
  iVar2 = 0;
  if (0 < local_1c[0]) {
    if (nSamples <= local_1c[0]) {
      local_1c[0] = nSamples;
    }
    alcCaptureSamples(this->m_Device,pOut,local_1c[0]);
    iVar1 = alGetError();
    if (iVar1 == 0) {
      iVar2 = local_1c[0];
    }
  }
  return iVar2;
}


// VoiceRecord_OpenAL::Idle  @ 002159b0
/* DWARF original prototype: void Idle(VoiceRecord_OpenAL * this) */

void __thiscall VoiceRecord_OpenAL::Idle(VoiceRecord_OpenAL *this)

{
  return;
}


// VoiceRecord_OpenAL::Init  @ 00215a50
/* DWARF original prototype: bool Init(VoiceRecord_OpenAL * this, int sampleRate) */

bool __thiscall VoiceRecord_OpenAL::Init(VoiceRecord_OpenAL *this,int sampleRate)

{
  this->m_nSampleRate = sampleRate;
  alcCaptureCloseDevice(this->m_Device);
  this->m_Device = (ALCdevice *)0x0;
  return true;
}


// VoiceRecord_OpenAL::InitalizeInterfaces  @ 00215bc0
/* DWARF original prototype: bool InitalizeInterfaces(VoiceRecord_OpenAL * this) */

bool __thiscall VoiceRecord_OpenAL::InitalizeInterfaces(VoiceRecord_OpenAL *this)

{
  ALCdevice *pAVar1;
  int iVar2;
  bool bVar3;
  
  pAVar1 = (ALCdevice *)
           alcCaptureOpenDevice(0,this->m_nSampleRate,0x1101,this->m_nSampleRate * 0x14);
  bVar3 = false;
  this->m_Device = pAVar1;
  if (pAVar1 != (ALCdevice *)0x0) {
    iVar2 = alGetError();
    bVar3 = iVar2 == 0;
  }
  return bVar3;
}


// VoiceRecord_OpenAL::RecordStart  @ 00215b20
/* DWARF original prototype: bool RecordStart(VoiceRecord_OpenAL * this) */

bool __thiscall VoiceRecord_OpenAL::RecordStart(VoiceRecord_OpenAL *this)

{
  int iVar1;
  ALCdevice *pAVar2;
  
  pAVar2 = this->m_Device;
  if (pAVar2 == (ALCdevice *)0x0) {
    pAVar2 = (ALCdevice *)
             alcCaptureOpenDevice(0,this->m_nSampleRate,0x1101,this->m_nSampleRate * 0x14);
    this->m_Device = pAVar2;
    if (pAVar2 == (ALCdevice *)0x0) {
      return false;
    }
    alGetError();
    pAVar2 = this->m_Device;
    if (pAVar2 == (ALCdevice *)0x0) {
      return false;
    }
  }
  alcCaptureStart(pAVar2);
  iVar1 = alGetError();
  return iVar1 == 0;
}


// VoiceRecord_OpenAL::RecordStop  @ 00215a80
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


// VoiceRecord_OpenAL::Release  @ 00215990
/* DWARF original prototype: void Release(VoiceRecord_OpenAL * this) */

void __thiscall VoiceRecord_OpenAL::Release(VoiceRecord_OpenAL *this)

{
  if (this != (VoiceRecord_OpenAL *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0021599d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(this->super_IVoiceRecord)._vptr_IVoiceRecord[1])();
    return;
  }
  return;
}


// VoiceRecord_OpenAL::ReleaseInterfaces  @ 00215c10
/* DWARF original prototype: void ReleaseInterfaces(VoiceRecord_OpenAL * this) */

void __thiscall VoiceRecord_OpenAL::ReleaseInterfaces(VoiceRecord_OpenAL *this)

{
  alcCaptureCloseDevice(this->m_Device);
  this->m_Device = (ALCdevice *)0x0;
  return;
}


// VoiceRecord_OpenAL::VoiceRecord_OpenAL  @ 00215ba0
/* DWARF original prototype: void VoiceRecord_OpenAL(VoiceRecord_OpenAL * this) */

void __thiscall VoiceRecord_OpenAL::VoiceRecord_OpenAL(VoiceRecord_OpenAL *this)

{
  (this->super_IVoiceRecord)._vptr_IVoiceRecord =
       (_func_int_varargs **)&PTR__VoiceRecord_OpenAL_00295a28;
  this->m_Device = (ALCdevice *)0x0;
  this->m_nSampleRate = 0;
  return;
}


// VoiceRecord_OpenAL::~VoiceRecord_OpenAL  @ 00215ab0
/* DWARF original prototype: void ~VoiceRecord_OpenAL(VoiceRecord_OpenAL * this, int __in_chrg) */

void __thiscall VoiceRecord_OpenAL::~VoiceRecord_OpenAL(VoiceRecord_OpenAL *this,int __in_chrg)

{
  ALCdevice *pAVar1;
  
  pAVar1 = this->m_Device;
  (this->super_IVoiceRecord)._vptr_IVoiceRecord =
       (_func_int_varargs **)&PTR__VoiceRecord_OpenAL_00295a28;
  alcCaptureCloseDevice(pAVar1);
  this->m_Device = (ALCdevice *)0x0;
  (this->super_IVoiceRecord)._vptr_IVoiceRecord = (_func_int_varargs **)&PTR__IVoiceRecord_00295a68;
  return;
}


// VoiceRecord_OpenAL::~VoiceRecord_OpenAL  @ 00215ae0
/* DWARF original prototype: void ~VoiceRecord_OpenAL(VoiceRecord_OpenAL * this, int __in_chrg) */

void __thiscall VoiceRecord_OpenAL::~VoiceRecord_OpenAL(VoiceRecord_OpenAL *this,int __in_chrg)

{
  ALCdevice *pAVar1;
  
  pAVar1 = this->m_Device;
  (this->super_IVoiceRecord)._vptr_IVoiceRecord =
       (_func_int_varargs **)&PTR__VoiceRecord_OpenAL_00295a28;
  alcCaptureCloseDevice(pAVar1);
  this->m_Device = (ALCdevice *)0x0;
  (this->super_IVoiceRecord)._vptr_IVoiceRecord = (_func_int_varargs **)&PTR__IVoiceRecord_00295a68;
  operator_delete(this);
  return;
}


