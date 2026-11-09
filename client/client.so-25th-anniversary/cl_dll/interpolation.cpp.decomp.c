// Ghidra decompilation of functions from cl_dll/interpolation.cpp
// 12 functions, ordered by original source line

// SolveLSE  @ 00075c90  (line 27)

bool SolveLSE(Vector v0,Vector v1,Vector v2,Vector v3,float *x,float *y,float *z)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  bool local_14;
  
                    /* Unresolved local var: float d@[???] */
  fVar1 = *(float *)v0.z * *(float *)((int)v1.x + 4) - *(float *)((int)v0.z + 4) * *(float *)v1.x;
  fVar3 = *(float *)v1.x * *(float *)((int)v0.z + 8) - *(float *)v0.z * *(float *)((int)v1.x + 8);
  fVar4 = *(float *)((int)v0.z + 4) * *(float *)((int)v1.x + 8) -
          *(float *)((int)v1.x + 4) * *(float *)((int)v0.z + 8);
  fVar2 = *(float *)v0.y * fVar4 +
          *(float *)((int)v0.y + 4) * fVar3 + *(float *)((int)v0.y + 8) * fVar1;
  local_14 = false;
  if (fVar2 != 0.0) {
    if (v1.y != 0.0) {
      *(float *)v1.y =
           (fVar4 * *(float *)v0.x +
           fVar3 * *(float *)((int)v0.x + 4) + fVar1 * *(float *)((int)v0.x + 8)) / fVar2;
    }
    if (v1.z != 0.0) {
      *(float *)v1.z =
           ((*(float *)((int)v1.x + 8) * *(float *)((int)v0.x + 4) -
            *(float *)((int)v1.x + 4) * *(float *)((int)v0.x + 8)) * *(float *)v0.y +
           (*(float *)v1.x * *(float *)((int)v0.x + 8) - *(float *)v0.x * *(float *)((int)v1.x + 8))
           * *(float *)((int)v0.y + 4) +
           (*(float *)v0.x * *(float *)((int)v1.x + 4) - *(float *)((int)v0.x + 4) * *(float *)v1.x)
           * *(float *)((int)v0.y + 8)) / fVar2;
    }
    if (v2.x == 0.0) {
      local_14 = true;
    }
    else {
      local_14 = true;
      *(float *)v2.x =
           ((*(float *)((int)v0.x + 8) * *(float *)((int)v0.z + 4) -
            *(float *)((int)v0.x + 4) * *(float *)((int)v0.z + 8)) * *(float *)v0.y +
           *(float *)((int)v0.y + 4) *
           (*(float *)v0.x * *(float *)((int)v0.z + 8) - *(float *)v0.z * *(float *)((int)v0.x + 8))
           + (*(float *)v0.z * *(float *)((int)v0.x + 4) -
             *(float *)((int)v0.z + 4) * *(float *)v0.x) * *(float *)((int)v0.y + 8)) / fVar2;
    }
  }
  return local_14;
}


// GetPointBetweenLines  @ 00075de0  (line 47)

bool GetPointBetweenLines(Vector *p,Vector a1,Vector m1,Vector a2,Vector m2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  
                    /* Unresolved local var: float x@[???]
                       Unresolved local var: float z@[???]
                       Unresolved local var: Vector t1@[???]
                       Unresolved local var: Vector t2@[???] */
  fVar1 = *(float *)a1.y;
  fVar2 = *(float *)((int)m1.x + 4);
  fVar3 = *(float *)((int)a1.y + 4);
  fVar4 = *(float *)m1.x;
  fVar17 = fVar1 * fVar2 - fVar3 * fVar4;
  fVar5 = *(float *)((int)a1.y + 8);
  fVar6 = *(float *)((int)m1.x + 8);
  fVar11 = fVar5 * fVar4 - fVar1 * fVar6;
  fVar18 = fVar3 * fVar6 - fVar5 * fVar2;
                    /* Unresolved local var: float d@[???] */
  fVar14 = fVar2 * fVar18 - fVar4 * fVar11;
  fVar16 = fVar4 * fVar17 - fVar6 * fVar18;
  fVar12 = fVar6 * fVar11 - fVar17 * fVar2;
  fVar13 = fVar1 * fVar12 + fVar3 * fVar16 + fVar5 * fVar14;
  if (fVar13 != 0.0) {
    fVar7 = *(float *)((int)a1.z + 8);
    fVar8 = *(float *)((int)a1.x + 8);
    fVar19 = fVar7 - fVar8;
    fVar9 = *(float *)((int)a1.z + 4);
    fVar10 = *(float *)((int)a1.x + 4);
    fVar20 = fVar9 - fVar10;
    fVar15 = *(float *)a1.z - *(float *)a1.x;
    fVar12 = (fVar12 * fVar15 + fVar16 * fVar20 + fVar14 * fVar19) / fVar13;
    fVar11 = -(((fVar15 * fVar17 - fVar18 * fVar19) * fVar3 +
                (fVar20 * fVar18 - fVar15 * fVar11) * fVar5 +
               (fVar11 * fVar19 - fVar20 * fVar17) * fVar1) / fVar13);
    p->x = (*(float *)a1.x + fVar1 * fVar12 + fVar4 * fVar11 + *(float *)a1.z) * 0.5;
    p->y = (fVar3 * fVar12 + fVar10 + fVar2 * fVar11 + fVar9) * 0.5;
    p->z = (fVar5 * fVar12 + fVar8 + fVar11 * fVar6 + fVar7) * 0.5;
  }
  return fVar13 != 0.0;
}


// CInterpolation::CInterpolation  @ 00075fb0  (line 69)

/* DWARF original prototype: void CInterpolation(CInterpolation * this) */

void __thiscall CInterpolation::CInterpolation(CInterpolation *this)

{
  this->_vptr_CInterpolation = (_func_int_varargs **)&PTR__CInterpolation_000c2e90;
  return;
}


// CInterpolation::~CInterpolation  @ 00075c70  (line 73)

/* DWARF original prototype: void ~CInterpolation(CInterpolation * this, int __in_chrg) */

void __thiscall CInterpolation::~CInterpolation(CInterpolation *this,int __in_chrg)

{
  return;
}


// CInterpolation::~CInterpolation  @ 00075c80  (line 76)

/* DWARF original prototype: void ~CInterpolation(CInterpolation * this, int __in_chrg) */

void __thiscall CInterpolation::~CInterpolation(CInterpolation *this,int __in_chrg)

{
  operator_delete(this);
  return;
}


// CInterpolation::SetViewAngles  @ 00075fc0  (line 79)

/* DWARF original prototype: void SetViewAngles(CInterpolation * this, Vector start, Vector end) */

void __thiscall CInterpolation::SetViewAngles(CInterpolation *this,Vector start,Vector end)

{
  (this->m_StartAngle).x = *(vec_t *)start.x;
  (this->m_StartAngle).y = *(vec_t *)((int)start.x + 4);
  (this->m_StartAngle).z = *(vec_t *)((int)start.x + 8);
  (this->m_EndAngle).x = *(vec_t *)start.y;
  (this->m_EndAngle).y = *(vec_t *)((int)start.y + 4);
  (this->m_EndAngle).z = *(vec_t *)((int)start.y + 8);
  NormalizeAngles(&(this->m_StartAngle).x);
  NormalizeAngles(&(this->m_EndAngle).x);
  return;
}


// CInterpolation::SetFOVs  @ 00076010  (line 87)

/* DWARF original prototype: void SetFOVs(CInterpolation * this, float start, float end) */

void __thiscall CInterpolation::SetFOVs(CInterpolation *this,float start,float end)

{
  this->m_StartFov = start;
  this->m_EndFov = end;
  return;
}


// CInterpolation::SetWaypoints  @ 00076030  (line 93)

/* DWARF original prototype: void SetWaypoints(CInterpolation * this, Vector * prev, Vector start,
   Vector end, Vector * next) */

void __thiscall
CInterpolation::SetWaypoints(CInterpolation *this,Vector *prev,Vector start,Vector end,Vector *next)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float local_74;
  float local_70;
  
                    /* Unresolved local var: Vector a@[???]
                       Unresolved local var: Vector b@[???]
                       Unresolved local var: Vector c@[???]
                       Unresolved local var: Vector d@[???] */
  (this->m_StartPoint).x = *(vec_t *)start.x;
  (this->m_StartPoint).y = *(vec_t *)((int)start.x + 4);
  (this->m_StartPoint).z = *(vec_t *)((int)start.x + 8);
  (this->m_EndPoint).x = *(vec_t *)start.y;
  (this->m_EndPoint).y = *(vec_t *)((int)start.y + 4);
  (this->m_EndPoint).z = *(vec_t *)((int)start.y + 8);
  if ((prev == (Vector *)0x0) && (start.z == 0.0)) {
    fVar19 = (this->m_StartPoint).z;
    fVar16 = (this->m_EndPoint).z;
    fVar1 = (this->m_StartPoint).y;
    fVar20 = (this->m_EndPoint).y;
    (this->m_Center).x = ((this->m_StartPoint).x + (this->m_EndPoint).x) * 0.5;
    (this->m_Center).y = (fVar1 + fVar20) * 0.5;
    (this->m_Center).z = (fVar19 + fVar16) * 0.5;
  }
  else if (prev == (Vector *)0x0) {
                    /* Unresolved local var: float dist@[???] */
    fVar16 = *(float *)((int)start.x + 8) - *(float *)((int)start.y + 8);
    fVar18 = *(float *)((int)start.x + 4) - *(float *)((int)start.y + 4);
    fVar1 = *(float *)start.x - *(float *)start.y;
    fVar15 = fVar16 * fVar16 + fVar18 * fVar18 + fVar1 * fVar1;
    fVar19 = SQRT(fVar15);
    fVar20 = fVar19;
    if (NAN(fVar19)) {
      fVar20 = sqrtf(fVar15);
    }
    fVar20 = fVar20 * 0.5;
                    /* Unresolved local var: float flLen@[???] */
    if (NAN(fVar19)) {
      fVar19 = sqrtf(fVar15);
    }
    if (fVar19 == 0.0) {
      fVar16 = 1.0;
      fVar1 = 0.0;
      fVar19 = fVar1;
    }
    else {
      fVar19 = 1.0 / fVar19;
      fVar16 = fVar16 * fVar19;
      fVar1 = fVar19 * fVar1;
      fVar19 = fVar18 * fVar19;
    }
    fVar15 = *(float *)((int)start.z + 8) - *(float *)((int)start.y + 8);
    fVar9 = *(float *)((int)start.z + 4) - *(float *)((int)start.y + 4);
    fVar17 = *(float *)start.z - *(float *)start.y;
                    /* Unresolved local var: float flLen@[???] */
    fVar6 = fVar15 * fVar15 + fVar9 * fVar9 + fVar17 * fVar17;
    fVar18 = SQRT(fVar6);
    if (NAN(fVar18)) {
      fVar18 = sqrtf(fVar6);
    }
    if (fVar18 == 0.0) {
      fVar15 = 1.0;
      fVar17 = 0.0;
      fVar18 = fVar17;
    }
    else {
      fVar18 = 1.0 / fVar18;
      fVar15 = fVar15 * fVar18;
      fVar17 = fVar18 * fVar17;
      fVar18 = fVar9 * fVar18;
    }
    fVar16 = fVar16 - fVar15;
    fVar19 = fVar19 - fVar18;
    fVar1 = fVar1 - fVar17;
                    /* Unresolved local var: float flLen@[???] */
    fVar15 = fVar16 * fVar16 + fVar19 * fVar19 + fVar1 * fVar1;
    fVar18 = SQRT(fVar15);
    if (NAN(fVar18)) {
      fVar18 = sqrtf(fVar15);
    }
    if (fVar18 == 0.0) {
      fVar16 = 1.0;
      fVar19 = 0.0;
      fVar1 = fVar19;
    }
    else {
      fVar18 = 1.0 / fVar18;
      fVar16 = fVar16 * fVar18;
      fVar19 = fVar19 * fVar18;
      fVar1 = fVar18 * fVar1;
    }
    fVar15 = *(float *)((int)start.y + 8);
    fVar18 = *(float *)((int)start.y + 4);
    (this->m_Center).x = fVar20 * fVar1 + *(float *)start.y;
    (this->m_Center).y = fVar19 * fVar20 + fVar18;
    (this->m_Center).z = fVar16 * fVar20 + fVar15;
  }
  else {
                    /* Unresolved local var: float dist@[???] */
    fVar19 = prev->z - *(float *)((int)start.x + 8);
    local_74 = prev->y - *(float *)((int)start.x + 4);
    local_70 = prev->x - *(float *)start.x;
                    /* Unresolved local var: float flLen@[???] */
    fVar1 = fVar19 * fVar19 + local_74 * local_74 + local_70 * local_70;
    fVar16 = SQRT(fVar1);
    if (start.z == 0.0) {
      if (NAN(fVar16)) {
        fVar16 = sqrtf(fVar1);
      }
      if (fVar16 == 0.0) {
        fVar19 = 1.0;
        local_74 = 0.0;
        local_70 = 0.0;
      }
      else {
        fVar16 = 1.0 / fVar16;
        fVar19 = fVar19 * fVar16;
        local_74 = local_74 * fVar16;
        local_70 = local_70 * fVar16;
      }
      fVar1 = *(float *)((int)start.y + 8) - *(float *)((int)start.x + 8);
      fVar17 = *(float *)((int)start.y + 4) - *(float *)((int)start.x + 4);
      fVar20 = *(float *)start.y - *(float *)start.x;
      fVar18 = fVar1 * fVar1 + fVar17 * fVar17 + fVar20 * fVar20;
      fVar16 = SQRT(fVar18);
      fVar15 = fVar16;
      if (NAN(fVar16)) {
        fVar15 = sqrtf(fVar18);
      }
      fVar15 = fVar15 * 0.5;
                    /* Unresolved local var: float flLen@[???] */
      if (NAN(fVar16)) {
        fVar16 = sqrtf(fVar18);
      }
      if (fVar16 == 0.0) {
        fVar1 = 1.0;
        fVar20 = 0.0;
        fVar16 = fVar20;
      }
      else {
        fVar16 = 1.0 / fVar16;
        fVar1 = fVar1 * fVar16;
        fVar20 = fVar16 * fVar20;
        fVar16 = fVar17 * fVar16;
      }
      fVar1 = fVar1 - fVar19;
      fVar16 = fVar16 - local_74;
      fVar20 = fVar20 - local_70;
                    /* Unresolved local var: float flLen@[???] */
      fVar19 = fVar1 * fVar1 + fVar16 * fVar16 + fVar20 * fVar20;
      fVar18 = SQRT(fVar19);
      if (NAN(fVar18)) {
        fVar18 = sqrtf(fVar19);
      }
      if (fVar18 == 0.0) {
        fVar1 = 1.0;
        fVar20 = 0.0;
        fVar19 = fVar20;
      }
      else {
        fVar18 = 1.0 / fVar18;
        fVar1 = fVar1 * fVar18;
        fVar20 = fVar18 * fVar20;
        fVar19 = fVar16 * fVar18;
      }
      fVar16 = *(float *)((int)start.x + 8);
      fVar18 = *(float *)((int)start.x + 4);
      (this->m_Center).x = fVar15 * fVar20 + *(float *)start.x;
      (this->m_Center).y = fVar19 * fVar15 + fVar18;
      (this->m_Center).z = fVar1 * fVar15 + fVar16;
    }
    else {
                    /* Unresolved local var: float flLen@[???] */
      if (NAN(fVar16)) {
        fVar16 = sqrtf(fVar1);
      }
      if (fVar16 == 0.0) {
        fVar19 = 1.0;
        local_70 = 0.0;
        fVar16 = local_70;
      }
      else {
        fVar16 = 1.0 / fVar16;
        fVar19 = fVar19 * fVar16;
        local_70 = fVar16 * local_70;
        fVar16 = local_74 * fVar16;
      }
      fVar20 = *(float *)((int)start.y + 8) - *(float *)((int)start.x + 8);
      fVar17 = *(float *)((int)start.y + 4) - *(float *)((int)start.x + 4);
      fVar1 = *(float *)start.y - *(float *)start.x;
                    /* Unresolved local var: float flLen@[???] */
      fVar18 = fVar20 * fVar20 + fVar17 * fVar17 + fVar1 * fVar1;
      fVar15 = SQRT(fVar18);
      if (NAN(fVar15)) {
        fVar15 = sqrtf(fVar18);
      }
      if (fVar15 == 0.0) {
        fVar20 = 1.0;
        fVar1 = 0.0;
        fVar15 = fVar1;
      }
      else {
        fVar15 = 1.0 / fVar15;
        fVar20 = fVar20 * fVar15;
        fVar1 = fVar15 * fVar1;
        fVar15 = fVar17 * fVar15;
      }
      fVar20 = fVar20 - fVar19;
      fVar15 = fVar15 - fVar16;
      fVar1 = fVar1 - local_70;
      fVar19 = *(float *)((int)start.x + 8) - *(float *)((int)start.y + 8);
      fVar16 = *(float *)((int)start.x + 4) - *(float *)((int)start.y + 4);
      fVar6 = *(float *)start.x - *(float *)start.y;
                    /* Unresolved local var: float flLen@[???] */
      fVar18 = fVar19 * fVar19 + fVar16 * fVar16 + fVar6 * fVar6;
      fVar17 = SQRT(fVar18);
      if (NAN(fVar17)) {
        fVar17 = sqrtf(fVar18);
      }
      if (fVar17 == 0.0) {
        fVar19 = 1.0;
        fVar16 = 0.0;
        fVar18 = fVar16;
      }
      else {
        fVar17 = 1.0 / fVar17;
        fVar19 = fVar19 * fVar17;
        fVar16 = fVar16 * fVar17;
        fVar18 = fVar17 * fVar6;
      }
      fVar9 = *(float *)((int)start.z + 8) - *(float *)((int)start.y + 8);
      fVar6 = *(float *)((int)start.z + 4) - *(float *)((int)start.y + 4);
      fVar11 = *(float *)start.z - *(float *)start.y;
                    /* Unresolved local var: float flLen@[???] */
      fVar10 = fVar9 * fVar9 + fVar6 * fVar6 + fVar11 * fVar11;
      fVar17 = SQRT(fVar10);
      if (NAN(fVar17)) {
        fVar17 = sqrtf(fVar10);
      }
      if (fVar17 == 0.0) {
        fVar9 = 1.0;
        fVar6 = 0.0;
        fVar17 = 0.0;
      }
      else {
        fVar17 = 1.0 / fVar17;
        fVar9 = fVar9 * fVar17;
        fVar6 = fVar6 * fVar17;
        fVar17 = fVar17 * fVar11;
      }
      fVar19 = fVar19 - fVar9;
      fVar16 = fVar16 - fVar6;
      fVar18 = fVar18 - fVar17;
                    /* Unresolved local var: float x@[???]
                       Unresolved local var: float z@[???]
                       Unresolved local var: Vector t1@[???]
                       Unresolved local var: Vector t2@[???] */
      fVar12 = fVar16 * fVar1 - fVar15 * fVar18;
      fVar13 = fVar20 * fVar18 - fVar19 * fVar1;
      fVar11 = fVar15 * fVar19 - fVar20 * fVar16;
                    /* Unresolved local var: float d@[???] */
      fVar10 = fVar16 * fVar11 - fVar13 * fVar18;
      fVar9 = fVar18 * fVar12 - fVar19 * fVar11;
      fVar17 = fVar13 * fVar19 - fVar16 * fVar12;
      fVar6 = fVar15 * fVar9 + fVar20 * fVar10 + fVar1 * fVar17;
      if (fVar6 != 0.0) {
        fVar2 = *(float *)((int)start.y + 4);
        fVar3 = *(float *)((int)start.y + 8);
        fVar4 = *(float *)((int)start.x + 4);
        fVar5 = *(float *)((int)start.x + 8);
        fVar8 = fVar3 - fVar5;
        fVar14 = fVar2 - fVar4;
        fVar7 = *(float *)start.y - *(float *)start.x;
        fVar17 = (fVar17 * fVar7 + fVar9 * fVar14 + fVar10 * fVar8) / fVar6;
        fVar6 = -(((fVar7 * fVar12 - fVar11 * fVar8) * fVar15 +
                   (fVar14 * fVar11 - fVar13 * fVar7) * fVar20 +
                  (fVar8 * fVar13 - fVar12 * fVar14) * fVar1) / fVar6);
        (this->m_Center).x =
             (*(float *)start.y + fVar18 * fVar6 + *(float *)start.x + fVar1 * fVar17) * 0.5;
        (this->m_Center).y = (fVar16 * fVar6 + fVar2 + fVar4 + fVar15 * fVar17) * 0.5;
        (this->m_Center).z = (fVar6 * fVar19 + fVar3 + fVar17 * fVar20 + fVar5) * 0.5;
        return;
      }
    }
  }
  return;
}


// CInterpolation::Interpolate  @ 00076a40  (line 148)

/* DWARF original prototype: void Interpolate(CInterpolation * this, float t, Vector * point, Vector
   * angle, float * fov) */

void __thiscall
CInterpolation::Interpolate(CInterpolation *this,float t,Vector *point,Vector *angle,float *fov)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  if (this->m_SmoothStart == false) {
    if (this->m_SmoothEnd != false) {
      t = 1.0 - (t - 1.0) * (t - 1.0);
    }
  }
  else if (this->m_SmoothEnd == false) {
    t = t * t;
  }
  else {
    t = t * t * (1.0 - t) + (1.0 - (t - 1.0) * (t - 1.0)) * t;
  }
  if (point != (Vector *)0x0) {
    fVar1 = 1.0 - t;
    fVar4 = fVar1 * fVar1;
    fVar6 = (this->m_StartPoint).z * fVar4;
    fVar5 = (this->m_StartPoint).y * fVar4;
    fVar4 = (this->m_StartPoint).x * fVar4;
    point->x = fVar4;
    point->y = fVar5;
    point->z = fVar6;
    fVar1 = (t + t) * fVar1;
    fVar6 = (this->m_Center).z * fVar1 + fVar6;
    fVar5 = (this->m_Center).y * fVar1 + fVar5;
    fVar4 = fVar1 * (this->m_Center).x + fVar4;
    point->x = fVar4;
    point->y = fVar5;
    point->z = fVar6;
    fVar3 = t * t;
    fVar1 = (this->m_EndPoint).z;
    fVar2 = (this->m_EndPoint).y;
    point->x = fVar3 * (this->m_EndPoint).x + fVar4;
    point->y = fVar2 * fVar3 + fVar5;
    point->z = fVar1 * fVar3 + fVar6;
  }
  if (angle != (Vector *)0x0) {
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float ang1@[???]
                       Unresolved local var: float ang2@[???]
                       Unresolved local var: float d@[???] */
    fVar1 = (this->m_StartAngle).x;
    fVar2 = (this->m_EndAngle).x - fVar1;
    if (fVar2 <= 180.0) {
      if (fVar2 < -180.0) {
        fVar2 = fVar2 + 360.0;
      }
    }
    else {
      fVar2 = fVar2 - 360.0;
    }
    angle->x = fVar2 * t + fVar1;
    fVar1 = (this->m_StartAngle).y;
    fVar2 = (this->m_EndAngle).y - fVar1;
    if (180.0 < fVar2) {
      fVar2 = fVar2 - 360.0;
    }
    else if (fVar2 < -180.0) {
      fVar2 = fVar2 + 360.0;
    }
    angle->y = fVar2 * t + fVar1;
    fVar1 = (this->m_StartAngle).z;
    fVar2 = (this->m_EndAngle).z - fVar1;
    if (fVar2 <= 180.0) {
      if (fVar2 < -180.0) {
        fVar2 = fVar2 + 360.0;
      }
    }
    else {
      fVar2 = fVar2 - 360.0;
    }
    angle->z = fVar1 + fVar2 * t;
    NormalizeAngles(&angle->x);
  }
  if (fov != (float *)0x0) {
    *fov = this->m_StartFov + (this->m_EndFov - this->m_StartFov) * t;
  }
  return;
}


// CInterpolation::BezierInterpolatePoint  @ 00076c40  (line 181)

/* DWARF original prototype: void BezierInterpolatePoint(CInterpolation * this, float t, Vector *
   point) */

void __thiscall CInterpolation::BezierInterpolatePoint(CInterpolation *this,float t,Vector *point)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = 1.0 - t;
  fVar4 = fVar1 * fVar1;
  fVar6 = (this->m_StartPoint).z * fVar4;
  fVar5 = (this->m_StartPoint).y * fVar4;
  fVar4 = (this->m_StartPoint).x * fVar4;
  point->x = fVar4;
  point->y = fVar5;
  point->z = fVar6;
  fVar1 = (t + t) * fVar1;
  fVar6 = (this->m_Center).z * fVar1 + fVar6;
  fVar5 = (this->m_Center).y * fVar1 + fVar5;
  fVar4 = fVar1 * (this->m_Center).x + fVar4;
  point->x = fVar4;
  point->y = fVar5;
  point->z = fVar6;
  fVar3 = t * t;
  fVar1 = (this->m_EndPoint).z;
  fVar2 = (this->m_EndPoint).y;
  point->x = fVar3 * (this->m_EndPoint).x + fVar4;
  point->y = fVar2 * fVar3 + fVar5;
  point->z = fVar1 * fVar3 + fVar6;
  return;
}


// CInterpolation::SetSmoothing  @ 00076cc0  (line 189)

/* DWARF original prototype: void SetSmoothing(CInterpolation * this, bool start, bool end) */

void __thiscall CInterpolation::SetSmoothing(CInterpolation *this,bool start,bool end)

{
  this->m_SmoothStart = start;
  this->m_SmoothEnd = end;
  return;
}


// CInterpolation::InterpolateAngle  @ 00076ce0  (line 195)

/* DWARF original prototype: void InterpolateAngle(CInterpolation * this, float t, Vector * angle)
    */

void __thiscall CInterpolation::InterpolateAngle(CInterpolation *this,float t,Vector *angle)

{
  float fVar1;
  float fVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float ang1@[???]
                       Unresolved local var: float ang2@[???]
                       Unresolved local var: float d@[???] */
  fVar1 = (this->m_StartAngle).x;
  fVar2 = (this->m_EndAngle).x - fVar1;
  if (180.0 < fVar2) {
    fVar2 = fVar2 - 360.0;
  }
  else if (fVar2 < -180.0) {
    fVar2 = fVar2 + 360.0;
  }
  angle->x = fVar2 * t + fVar1;
  fVar1 = (this->m_StartAngle).y;
  fVar2 = (this->m_EndAngle).y - fVar1;
  if (180.0 < fVar2) {
    fVar2 = fVar2 - 360.0;
  }
  else if (fVar2 < -180.0) {
    fVar2 = fVar2 + 360.0;
  }
  angle->y = fVar2 * t + fVar1;
  fVar1 = (this->m_StartAngle).z;
  fVar2 = (this->m_EndAngle).z - fVar1;
  if (fVar2 <= 180.0) {
    if (fVar2 < -180.0) {
      angle->z = fVar1 + (fVar2 + 360.0) * t;
      NormalizeAngles(&angle->x);
      return;
    }
  }
  else {
    fVar2 = fVar2 - 360.0;
  }
  angle->z = fVar1 + fVar2 * t;
  NormalizeAngles(&angle->x);
  return;
}


