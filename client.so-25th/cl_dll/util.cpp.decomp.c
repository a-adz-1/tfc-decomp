// Ghidra decompilation of functions from cl_dll/util.cpp
// 7 functions, ordered by original source line

// Length  @ 00082930  (line 38)

float Length(float *v)

{
  float __x;
  float fVar1;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float length@[???] */
  __x = v[2] * v[2] + v[1] * v[1] + *v * *v + 0.0;
  fVar1 = SQRT(__x);
  if (NAN(fVar1)) {
    fVar1 = sqrtf(__x);
  }
  return fVar1;
}


// VectorAngles  @ 00082970  (line 51)

void VectorAngles(float *forward,float *angles)

{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  
                    /* Unresolved local var: float tmp@[???]
                       Unresolved local var: float yaw@[???]
                       Unresolved local var: float pitch@[???] */
  fVar1 = 0.0;
  if ((forward[1] == 0.0) && (*forward == 0.0)) {
    if (forward[2] <= 0.0) {
      fVar2 = 270.0;
    }
    else {
      fVar2 = 90.0;
    }
  }
  else {
    dVar4 = atan2((double)forward[1],(double)*forward);
    fVar1 = ((float)dVar4 * 180.0) / 3.1415927;
    if (fVar1 < 0.0) {
      fVar1 = fVar1 + 360.0;
    }
    fVar2 = forward[1] * forward[1] + *forward * *forward;
    fVar3 = SQRT(fVar2);
    if (NAN(fVar3)) {
      fVar3 = sqrtf(fVar2);
    }
    dVar4 = atan2((double)forward[2],(double)fVar3);
    fVar2 = ((float)dVar4 * 180.0) / 3.1415927;
    if (fVar2 < 0.0) {
      fVar2 = fVar2 + 360.0;
    }
  }
  *angles = fVar2;
  angles[1] = fVar1;
  angles[2] = 0.0;
  return;
}


// VectorNormalize  @ 00082aa0  (line 80)

float VectorNormalize(float *v)

{
  float fVar1;
  float fVar2;
  
                    /* Unresolved local var: float length@[???]
                       Unresolved local var: float ilength@[???] */
  fVar1 = v[2] * v[2] + v[1] * v[1] + *v * *v;
  fVar2 = SQRT(fVar1);
  if (NAN(fVar2)) {
    fVar2 = sqrtf(fVar1);
  }
  if (fVar2 != 0.0) {
    fVar1 = 1.0 / fVar2;
    *v = *v * fVar1;
    v[1] = v[1] * fVar1;
    v[2] = fVar1 * v[2];
  }
  return fVar2;
}


// VectorInverse  @ 00082b00  (line 99)

void VectorInverse(float *v)

{
  *v = -*v;
  v[1] = -v[1];
  v[2] = -v[2];
  return;
}


// VectorScale  @ 00082b20  (line 106)

void VectorScale(float *in,float scale,float *out)

{
  *out = *in * scale;
  out[1] = in[1] * scale;
  out[2] = scale * in[2];
  return;
}


// VectorMA  @ 00082b50  (line 113)

void VectorMA(float *veca,float scale,float *vecb,float *vecc)

{
  *vecc = *vecb * scale + *veca;
  vecc[1] = vecb[1] * scale + veca[1];
  vecc[2] = scale * vecb[2] + veca[2];
  return;
}


// LoadSprite  @ 00082b80  (line 120)

HANDLE_SPRITE LoadSprite(char *pszName)

{
  undefined4 uVar1;
  HANDLE_SPRITE HVar2;
  int in_GS_OFFSET;
  char local_110 [256];
  int local_10;
  
                    /* Unresolved local var: int iRes@[???]
                       Unresolved local var: char[256] sz@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  uVar1 = 0x280;
  if (gHUD.m_scrinfo.iWidth < 0x280) {
    uVar1 = 0x140;
  }
  __sprintf_chk(local_110,1,0x100,pszName,uVar1);
  HVar2 = (*gEngfuncs.pfnSPR_Load)(local_110);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return HVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


