// Ghidra decompilation of functions from tfc/vector.h
// 5 functions, ordered by original source line

// _GLOBAL__sub_I__ZN9CFuncTank10m_SaveDataE  @ 0006c360  (line 62)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__ZN9CFuncTank10m_SaveDataE(void)

{
  gTankSpread[0].x = 0.0;
  gTankSpread[0].y = 0.0;
  gTankSpread[0].z = 0.0;
  gTankSpread[1].x = 0.025;
  gTankSpread[1].y = 0.025;
  gTankSpread[1].z = 0.025;
  gTankSpread[2].x = 0.05;
  gTankSpread[2].y = 0.05;
  gTankSpread[2].z = 0.05;
  gTankSpread[3].x = 0.1;
  gTankSpread[3].y = 0.1;
  gTankSpread[3].z = 0.1;
  gTankSpread[4].x = 0.25;
  gTankSpread[4].y = 0.25;
  gTankSpread[4].z = 0.25;
  return;
}


// _GLOBAL__sub_I_g_ulFrameCount  @ 0006c3e0  (line 62)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_ulFrameCount(void)

{
  g_vecZero.x = 0.0;
  g_vecZero.y = 0.0;
  g_vecZero.z = 0.0;
  return;
}


// _GLOBAL__sub_I__ZN13CActAnimating10m_SaveDataE  @ 0006c440  (line 62)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I__ZN13CActAnimating10m_SaveDataE(void)

{
  CXenSporeLarge::m_hullSizes[0].x = 90.0;
  CXenSporeLarge::m_hullSizes[0].z = 0.0;
  CXenSporeLarge::m_hullSizes[1].z = 0.0;
  CXenSporeLarge::m_hullSizes[2].z = 0.0;
  CXenSporeLarge::m_hullSizes[0].y = -25.0;
  CXenSporeLarge::m_hullSizes[3].x = -90.0;
  CXenSporeLarge::m_hullSizes[3].z = 0.0;
  CXenSporeLarge::m_hullSizes[4].x = -90.0;
  CXenSporeLarge::m_hullSizes[1].x = 25.0;
  CXenSporeLarge::m_hullSizes[4].z = 0.0;
  CXenSporeLarge::m_hullSizes[1].y = 75.0;
  CXenSporeLarge::m_hullSizes[2].x = -15.0;
  CXenSporeLarge::m_hullSizes[2].y = -100.0;
  CXenSporeLarge::m_hullSizes[3].y = -35.0;
  CXenSporeLarge::m_hullSizes[4].y = 60.0;
  return;
}


// _GLOBAL__sub_I_g_vRed  @ 0006c4d0  (line 62)

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _GLOBAL__sub_I_g_vRed(void)

{
  g_vRed.x = 255.0;
  g_vRed.y = 0.0;
  g_vRed.z = 0.0;
  g_vBlue.x = 0.0;
  g_vBlue.y = 0.0;
  g_vBlue.z = 255.0;
  g_vYellow.x = 255.0;
  g_vYellow.y = 255.0;
  g_vYellow.z = 0.0;
  g_vGreen.x = 0.0;
  g_vGreen.y = 255.0;
  g_vGreen.z = 0.0;
  g_vBlack.x = 0.0;
  g_vBlack.y = 0.0;
  g_vBlack.z = 0.0;
  return;
}


// Vector::Normalize  @ 000dd8d0  (line 82)

/* WARNING: Variable defined which should be unmapped: __return_storage_ptr__ */
/* DWARF original prototype: Vector Normalize(Vector * this) */

Vector * __thiscall Vector::Normalize(Vector *__return_storage_ptr__,Vector *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
                    /* Unresolved local var: float flLen@[???] */
  fVar1 = this->z * this->z + this->y * this->y + this->x * this->x;
  fVar3 = SQRT(fVar1);
  if (NAN(fVar3)) {
    fVar3 = sqrtf(fVar1);
  }
  if (fVar3 == 0.0) {
    __return_storage_ptr__->x = 0.0;
    __return_storage_ptr__->y = 0.0;
    __return_storage_ptr__->z = 1.0;
    return __return_storage_ptr__;
  }
  fVar3 = 1.0 / fVar3;
  fVar1 = this->z;
  fVar2 = this->y;
  __return_storage_ptr__->x = fVar3 * this->x;
  __return_storage_ptr__->y = fVar2 * fVar3;
  __return_storage_ptr__->z = fVar1 * fVar3;
  return __return_storage_ptr__;
}


