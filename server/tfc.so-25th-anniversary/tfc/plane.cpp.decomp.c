// Ghidra decompilation of functions from tfc/plane.cpp
// 4 functions, ordered by original source line

// CPlane::CPlane  @ 000c0970  (line 18)

/* DWARF original prototype: void CPlane(CPlane * this) */

void __thiscall CPlane::CPlane(CPlane *this)

{
  this->m_fInitialized = 0;
  return;
}


// CPlane::InitializePlane  @ 000c0980  (line 26)

/* DWARF original prototype: void InitializePlane(CPlane * this, Vector * vecNormal, Vector *
   vecPoint) */

void __thiscall CPlane::InitializePlane(CPlane *this,Vector *vecNormal,Vector *vecPoint)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  (this->m_vecNormal).x = vecNormal->x;
  fVar1 = (this->m_vecNormal).x;
  (this->m_vecNormal).y = vecNormal->y;
  (this->m_vecNormal).z = vecNormal->z;
  fVar2 = vecPoint->x;
  fVar3 = (this->m_vecNormal).y;
  fVar4 = vecPoint->y;
  fVar5 = (this->m_vecNormal).z;
  fVar6 = vecPoint->z;
  this->m_fInitialized = 1;
  this->m_flDist = fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2;
  return;
}


// CPlane::PointOnPlane  @ 000c09c0  (line 37)

/* DWARF original prototype: BOOL PointOnPlane(CPlane * this, Vector * vecPoint) */

BOOL __thiscall CPlane::PointOnPlane(CPlane *this,Vector *vecPoint)

{
  return (uint)(((this->m_vecNormal).z * vecPoint->z +
                (this->m_vecNormal).y * vecPoint->y + (this->m_vecNormal).x * vecPoint->x) -
                this->m_flDist < 0.001);
}


// CPlane::PointInFront  @ 000c09f0  (line 52)

/* DWARF original prototype: BOOL PointInFront(CPlane * this, Vector * vecPoint) */

BOOL __thiscall CPlane::PointInFront(CPlane *this,Vector *vecPoint)

{
  uint uVar1;
  
                    /* Unresolved local var: float flFace@[???] */
  uVar1 = 0;
  if (this->m_fInitialized != 0) {
    uVar1 = (uint)(0.0 <= ((this->m_vecNormal).z * vecPoint->z +
                          (this->m_vecNormal).y * vecPoint->y + (this->m_vecNormal).x * vecPoint->x)
                          - this->m_flDist);
  }
  return uVar1;
}


