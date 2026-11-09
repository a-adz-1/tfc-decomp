// Ghidra decompilation of functions from game_shared/voice_gamemgr.h
// 3 functions, ordered by original source line

// IVoiceGameMgrHelper::~IVoiceGameMgrHelper  @ 0012d360  (line 26)

/* DWARF original prototype: void ~IVoiceGameMgrHelper(IVoiceGameMgrHelper * this, int __in_chrg) */

void __thiscall IVoiceGameMgrHelper::~IVoiceGameMgrHelper(IVoiceGameMgrHelper *this,int __in_chrg)

{
  this->_vptr_IVoiceGameMgrHelper = (_func_int_varargs **)&PTR__IVoiceGameMgrHelper_0018d810;
  return;
}


// TFGameMgrHelper::~TFGameMgrHelper  @ 0012d3b0  (line 26)

/* DWARF original prototype: void ~TFGameMgrHelper(TFGameMgrHelper * this, int __in_chrg) */

void __thiscall TFGameMgrHelper::~TFGameMgrHelper(TFGameMgrHelper *this,int __in_chrg)

{
  (this->super_IVoiceGameMgrHelper)._vptr_IVoiceGameMgrHelper =
       (_func_int_varargs **)&PTR__IVoiceGameMgrHelper_0018d810;
  return;
}


// IVoiceGameMgrHelper::~IVoiceGameMgrHelper  @ 0012d3d0  (line 26)

/* DWARF original prototype: void ~IVoiceGameMgrHelper(IVoiceGameMgrHelper * this, int __in_chrg) */

void __thiscall IVoiceGameMgrHelper::~IVoiceGameMgrHelper(IVoiceGameMgrHelper *this,int __in_chrg)

{
  this->_vptr_IVoiceGameMgrHelper = (_func_int_varargs **)&PTR__IVoiceGameMgrHelper_0018d810;
  operator_delete(this);
  return;
}


