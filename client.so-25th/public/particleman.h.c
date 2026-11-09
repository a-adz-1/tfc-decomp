// Ghidra decompilation of functions from public/particleman.h
// 15 functions, ordered by original source line

// CBaseParticle::Think  @ 000530c0  (line 68)

/* DWARF original prototype: void Think(CBaseParticle * this, float time) */

void __thiscall CBaseParticle::Think(CBaseParticle *this,float time)

{
  (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[0xb])(g_pParticleMan,this,time);
  return;
}


// CBaseParticle::Draw  @ 000530f0  (line 69)

/* DWARF original prototype: void Draw(CBaseParticle * this) */

void __thiscall CBaseParticle::Draw(CBaseParticle *this)

{
  (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[0xc])(g_pParticleMan,this);
  return;
}


// CBaseParticle::Animate  @ 00053110  (line 70)

/* DWARF original prototype: void Animate(CBaseParticle * this, float time) */

void __thiscall CBaseParticle::Animate(CBaseParticle *this,float time)

{
  (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[0xd])(g_pParticleMan,this,time);
  return;
}


// CBaseParticle::AnimateAndDie  @ 00053140  (line 71)

/* DWARF original prototype: void AnimateAndDie(CBaseParticle * this, float time) */

void __thiscall CBaseParticle::AnimateAndDie(CBaseParticle *this,float time)

{
  (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[0xe])(g_pParticleMan,this,time);
  return;
}


// CBaseParticle::Expand  @ 00053170  (line 72)

/* DWARF original prototype: void Expand(CBaseParticle * this, float time) */

void __thiscall CBaseParticle::Expand(CBaseParticle *this,float time)

{
  (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[0xf])(g_pParticleMan,this,time);
  return;
}


// CBaseParticle::Contract  @ 000531a0  (line 73)

/* DWARF original prototype: void Contract(CBaseParticle * this, float time) */

void __thiscall CBaseParticle::Contract(CBaseParticle *this,float time)

{
  (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[0x10])(g_pParticleMan,this,time);
  return;
}


// CBaseParticle::Fade  @ 000531d0  (line 74)

/* DWARF original prototype: void Fade(CBaseParticle * this, float time) */

void __thiscall CBaseParticle::Fade(CBaseParticle *this,float time)

{
  (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[0x11])(g_pParticleMan,this,time);
  return;
}


// CBaseParticle::Spin  @ 00053200  (line 75)

/* DWARF original prototype: void Spin(CBaseParticle * this, float time) */

void __thiscall CBaseParticle::Spin(CBaseParticle *this,float time)

{
  (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[0x12])(g_pParticleMan,this,time);
  return;
}


// CBaseParticle::CalculateVelocity  @ 00053230  (line 76)

/* DWARF original prototype: void CalculateVelocity(CBaseParticle * this, float time) */

void __thiscall CBaseParticle::CalculateVelocity(CBaseParticle *this,float time)

{
  (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[0x13])(g_pParticleMan,this,time);
  return;
}


// CBaseParticle::CheckCollision  @ 00053260  (line 77)

/* DWARF original prototype: void CheckCollision(CBaseParticle * this, float time) */

void __thiscall CBaseParticle::CheckCollision(CBaseParticle *this,float time)

{
  (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[0x14])(g_pParticleMan,this,time);
  return;
}


// CBaseParticle::Touch  @ 00053290  (line 78)

/* DWARF original prototype: void Touch(CBaseParticle * this, Vector pos, Vector normal, int index)
    */

void __thiscall CBaseParticle::Touch(CBaseParticle *this,Vector pos,Vector normal,int index)

{
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_24 = *(undefined4 *)pos.x;
  local_20 = *(undefined4 *)((int)pos.x + 4);
  local_1c = *(undefined4 *)((int)pos.x + 8);
  local_18 = *(undefined4 *)pos.y;
  local_14 = *(undefined4 *)((int)pos.y + 4);
  local_10 = *(undefined4 *)((int)pos.y + 8);
  (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[0x15])
            (g_pParticleMan,this,&local_24,&local_18,pos.z);
  return;
}


// CBaseParticle::Die  @ 00053320  (line 79)

/* DWARF original prototype: void Die(CBaseParticle * this) */

void __thiscall CBaseParticle::Die(CBaseParticle *this)

{
  (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[0x16])(g_pParticleMan,this);
  return;
}


// CBaseParticle::Force  @ 00053340  (line 80)

/* DWARF original prototype: void Force(CBaseParticle * this) */

void __thiscall CBaseParticle::Force(CBaseParticle *this)

{
  (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[0x17])(g_pParticleMan,this);
  return;
}


// CBaseParticle::CheckVisibility  @ 00053360  (line 81)

/* DWARF original prototype: bool CheckVisibility(CBaseParticle * this) */

bool __thiscall CBaseParticle::CheckVisibility(CBaseParticle *this)

{
  int iVar1;
  
  iVar1 = (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[0x18])(g_pParticleMan,this);
  return SUB41(iVar1,0);
}


// CBaseParticle::InitializeSprite  @ 00053380  (line 83)

/* DWARF original prototype: void InitializeSprite(CBaseParticle * this, Vector org, Vector normal,
   model_s * sprite, float size, float brightness) */

void __thiscall
CBaseParticle::InitializeSprite
          (CBaseParticle *this,Vector org,Vector normal,model_s *sprite,float size,float brightness)

{
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_24 = *(undefined4 *)org.x;
  local_20 = *(undefined4 *)((int)org.x + 4);
  local_1c = *(undefined4 *)((int)org.x + 8);
  local_18 = *(undefined4 *)org.y;
  local_14 = *(undefined4 *)((int)org.y + 4);
  local_10 = *(undefined4 *)((int)org.y + 8);
  (*(g_pParticleMan->super_IBaseInterface)._vptr_IBaseInterface[10])
            (g_pParticleMan,this,&local_24,&local_18,org.z,normal.x,normal.y);
  return;
}


