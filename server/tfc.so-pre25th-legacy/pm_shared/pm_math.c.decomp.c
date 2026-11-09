// Ghidra decompilation of functions from pm_shared/pm_math.c
// 24 functions, ordered by original source line

// anglemod  @ 00174590  (line 22)

float anglemod(float a)

{
  return (float)((int)(a * 182.04445) & 0xffff) * 0.005493164;
}


// AngleVectors  @ 001745d0  (line 28)

void AngleVectors(vec_t *angles,vec_t *forward,vec_t *right,vec_t *up)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float local_24;
  float local_20 [4];
  
                    /* Unresolved local var: float angle@[???]
                       Unresolved local var: float sr@[???]
                       Unresolved local var: float sp@[???]
                       Unresolved local var: float sy@[???]
                       Unresolved local var: float cr@[???]
                       Unresolved local var: float cp@[???]
                       Unresolved local var: float cy@[???] */
  sincosf(angles[1] * 0.017453292,local_20,&local_24);
  fVar4 = local_20[0];
  fVar2 = local_24;
  sincosf(*angles * 0.017453292,local_20,&local_24);
  fVar5 = local_20[0];
  fVar3 = local_24;
  sincosf(angles[2] * 0.017453292,local_20,&local_24);
  if (forward != (vec_t *)0x0) {
    *forward = fVar3 * fVar2;
    forward[1] = fVar3 * fVar4;
    forward[2] = -fVar5;
  }
  if (right != (vec_t *)0x0) {
    fVar1 = -local_20[0] * fVar5;
    *right = local_24 * fVar4 + fVar2 * fVar1;
    right[1] = fVar1 * fVar4 - fVar2 * local_24;
    right[2] = -local_20[0] * fVar3;
  }
  if (up != (vec_t *)0x0) {
    *up = local_20[0] * fVar4 + fVar2 * fVar5 * local_24;
    up[1] = fVar5 * local_24 * fVar4 - local_20[0] * fVar2;
    up[2] = local_24 * fVar3;
  }
  return;
}


// AngleVectorsTranspose  @ 00174730  (line 63)

void AngleVectorsTranspose(vec_t *angles,vec_t *forward,vec_t *right,vec_t *up)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float local_24;
  float local_20 [4];
  
                    /* Unresolved local var: float angle@[???]
                       Unresolved local var: float sr@[???]
                       Unresolved local var: float sp@[???]
                       Unresolved local var: float sy@[???]
                       Unresolved local var: float cr@[???]
                       Unresolved local var: float cp@[???]
                       Unresolved local var: float cy@[???] */
  sincosf(angles[1] * 0.017453292,local_20,&local_24);
  fVar3 = local_20[0];
  fVar1 = local_24;
  sincosf(*angles * 0.017453292,local_20,&local_24);
  fVar4 = local_20[0];
  fVar2 = local_24;
  sincosf(angles[2] * 0.017453292,local_20,&local_24);
  if (forward != (vec_t *)0x0) {
    *forward = fVar2 * fVar1;
    forward[1] = local_20[0] * fVar4 * fVar1 - fVar3 * local_24;
    forward[2] = local_20[0] * fVar3 + local_24 * fVar4 * fVar1;
  }
  if (right != (vec_t *)0x0) {
    *right = fVar2 * fVar3;
    right[1] = local_24 * fVar1 + local_20[0] * fVar4 * fVar3;
    right[2] = local_24 * fVar4 * fVar3 - fVar1 * local_20[0];
  }
  if (up != (vec_t *)0x0) {
    *up = -fVar4;
    up[1] = local_20[0] * fVar2;
    up[2] = fVar2 * local_24;
  }
  return;
}


// AngleMatrix  @ 001748c0  (line 99)

void AngleMatrix(vec_t *angles,float (*matrix) [4])

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float local_24;
  float local_20 [4];
  
                    /* Unresolved local var: float angle@[???]
                       Unresolved local var: float sr@[???]
                       Unresolved local var: float sp@[???]
                       Unresolved local var: float sy@[???]
                       Unresolved local var: float cr@[???]
                       Unresolved local var: float cp@[???]
                       Unresolved local var: float cy@[???] */
  sincosf(angles[1] * 0.017453292,local_20,&local_24);
  fVar3 = local_20[0];
  fVar1 = local_24;
  sincosf(*angles * 0.017453292,local_20,&local_24);
  fVar4 = local_20[0];
  fVar2 = local_24;
  sincosf(angles[2] * 0.017453292,local_20,&local_24);
  (*matrix)[0] = fVar2 * fVar1;
  matrix[1][0] = fVar2 * fVar3;
  (*matrix)[3] = 0.0;
  matrix[2][0] = -fVar4;
  matrix[1][3] = 0.0;
  matrix[2][3] = 0.0;
  (*matrix)[1] = local_20[0] * fVar4 * fVar1 - fVar3 * local_24;
  matrix[1][1] = local_24 * fVar1 + local_20[0] * fVar4 * fVar3;
  matrix[2][1] = fVar2 * local_20[0];
  (*matrix)[2] = local_20[0] * fVar3 + fVar4 * local_24 * fVar1;
  matrix[1][2] = fVar4 * local_24 * fVar3 - fVar1 * local_20[0];
  matrix[2][2] = local_24 * fVar2;
  return;
}


// AngleIMatrix  @ 001749e0  (line 129)

void AngleIMatrix(vec_t *angles,float (*matrix) [4])

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float local_24;
  float local_20 [4];
  
                    /* Unresolved local var: float angle@[???]
                       Unresolved local var: float sr@[???]
                       Unresolved local var: float sp@[???]
                       Unresolved local var: float sy@[???]
                       Unresolved local var: float cr@[???]
                       Unresolved local var: float cp@[???]
                       Unresolved local var: float cy@[???] */
  sincosf(angles[1] * 0.017453292,local_20,&local_24);
  fVar3 = local_20[0];
  fVar1 = local_24;
  sincosf(*angles * 0.017453292,local_20,&local_24);
  fVar4 = local_20[0];
  fVar2 = local_24;
  sincosf(angles[2] * 0.017453292,local_20,&local_24);
  (*matrix)[0] = fVar2 * fVar1;
  (*matrix)[1] = fVar2 * fVar3;
  (*matrix)[3] = 0.0;
  (*matrix)[2] = -fVar4;
  matrix[1][3] = 0.0;
  matrix[2][3] = 0.0;
  matrix[1][0] = local_20[0] * fVar4 * fVar1 - fVar3 * local_24;
  matrix[1][1] = local_24 * fVar1 + local_20[0] * fVar4 * fVar3;
  matrix[1][2] = fVar2 * local_20[0];
  matrix[2][0] = local_20[0] * fVar3 + fVar4 * local_24 * fVar1;
  matrix[2][1] = fVar4 * local_24 * fVar3 - fVar1 * local_20[0];
  matrix[2][2] = local_24 * fVar2;
  return;
}


// NormalizeAngles  @ 00174b00  (line 160)

void NormalizeAngles(float *angles)

{
  float fVar1;
  
                    /* Unresolved local var: int i@[???] */
  fVar1 = *angles;
  if (180.0 < fVar1) {
    *angles = fVar1 - 360.0;
    fVar1 = angles[1];
  }
  else {
    if (fVar1 < -180.0) {
      *angles = fVar1 + 360.0;
    }
    fVar1 = angles[1];
  }
  if (180.0 < fVar1) {
    angles[1] = fVar1 - 360.0;
    fVar1 = angles[2];
  }
  else {
    if (fVar1 < -180.0) {
      angles[1] = fVar1 + 360.0;
    }
    fVar1 = angles[2];
  }
  if (180.0 < fVar1) {
    angles[2] = fVar1 - 360.0;
    return;
  }
  if (fVar1 < -180.0) {
    angles[2] = fVar1 + 360.0;
  }
  return;
}


// InterpolateAngles  @ 00174be0  (line 186)

void InterpolateAngles(float *start,float *end,float *output,float frac)

{
  float fVar1;
  float fVar2;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float ang1@[???]
                       Unresolved local var: float ang2@[???]
                       Unresolved local var: float d@[???] */
                    /* Unresolved local var: int i@[???] */
  fVar1 = *start;
  if (180.0 < fVar1) {
    *start = fVar1 - 360.0;
    fVar1 = start[1];
    if (180.0 < fVar1) goto LAB_00174e08;
LAB_00174c37:
    if (fVar1 < -180.0) {
      start[1] = fVar1 + 360.0;
    }
    fVar1 = start[2];
    if (180.0 < fVar1) goto LAB_00174c67;
LAB_00174e26:
    if (-180.0 <= fVar1) goto LAB_00174c7a;
    start[2] = fVar1 + 360.0;
    fVar1 = *end;
    if (180.0 < fVar1) goto LAB_00174e51;
LAB_00174c8e:
    if (fVar1 < -180.0) {
      fVar1 = fVar1 + 360.0;
      *end = fVar1;
    }
    fVar2 = end[1];
    if (fVar2 <= 180.0) goto LAB_00174cb5;
LAB_00174e6e:
    end[1] = fVar2 - 360.0;
    fVar2 = end[2];
    if (fVar2 <= 180.0) goto LAB_00174e8c;
LAB_00174ce7:
    end[2] = fVar2 - 360.0;
  }
  else {
    if (fVar1 < -180.0) {
      *start = fVar1 + 360.0;
    }
    fVar1 = start[1];
    if (fVar1 <= 180.0) goto LAB_00174c37;
LAB_00174e08:
    start[1] = fVar1 - 360.0;
    fVar1 = start[2];
    if (fVar1 <= 180.0) goto LAB_00174e26;
LAB_00174c67:
    start[2] = fVar1 - 360.0;
LAB_00174c7a:
                    /* Unresolved local var: int i@[???] */
    fVar1 = *end;
    if (fVar1 <= 180.0) goto LAB_00174c8e;
LAB_00174e51:
    fVar1 = fVar1 - 360.0;
    *end = fVar1;
    fVar2 = end[1];
    if (180.0 < fVar2) goto LAB_00174e6e;
LAB_00174cb5:
    if (fVar2 < -180.0) {
      end[1] = fVar2 + 360.0;
    }
    fVar2 = end[2];
    if (180.0 < fVar2) goto LAB_00174ce7;
LAB_00174e8c:
    if (fVar2 < -180.0) {
      end[2] = fVar2 + 360.0;
      fVar2 = *start;
      fVar1 = fVar1 - fVar2;
      goto joined_r0x00174d0a;
    }
  }
  fVar2 = *start;
  fVar1 = fVar1 - fVar2;
joined_r0x00174d0a:
  if (180.0 < fVar1) {
    fVar1 = fVar1 - 360.0;
  }
  else if (fVar1 < -180.0) {
    fVar1 = fVar1 + 360.0;
  }
  *output = fVar1 * frac + fVar2;
  fVar1 = end[1] - start[1];
  if (180.0 < fVar1) {
    fVar1 = fVar1 - 360.0;
  }
  else if (fVar1 < -180.0) {
    fVar1 = fVar1 + 360.0;
  }
  output[1] = fVar1 * frac + start[1];
  fVar1 = end[2] - start[2];
  if (fVar1 <= 180.0) {
    if (fVar1 < -180.0) {
      fVar1 = fVar1 + 360.0;
    }
  }
  else {
    fVar1 = fVar1 - 360.0;
  }
  output[2] = start[2] + fVar1 * frac;
                    /* Unresolved local var: int i@[???] */
  fVar1 = *output;
  if (180.0 < fVar1) {
    *output = fVar1 - 360.0;
  }
  else if (fVar1 < -180.0) {
    *output = fVar1 + 360.0;
  }
  fVar1 = output[1];
  if (180.0 < fVar1) {
    output[1] = fVar1 - 360.0;
  }
  else if (fVar1 < -180.0) {
    output[1] = fVar1 + 360.0;
  }
  fVar1 = output[2];
  if (180.0 < fVar1) {
    output[2] = fVar1 - 360.0;
    return;
  }
  if (fVar1 < -180.0) {
    output[2] = fVar1 + 360.0;
  }
  return;
}


// AngleBetweenVectors  @ 00174f70  (line 223)

float AngleBetweenVectors(vec_t *v1,vec_t *v2)

{
  float __x;
  float fVar1;
  float fVar2;
  double dVar3;
  
                    /* Unresolved local var: float angle@[???]
                       Unresolved local var: float l1@[???]
                       Unresolved local var: float l2@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float length@[???] */
  fVar1 = v1[2] * v1[2] + v1[1] * v1[1] + *v1 * *v1 + 0.0;
  fVar2 = SQRT(fVar1);
  if (NAN(fVar2)) {
    fVar2 = sqrtf(fVar1);
  }
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float length@[???] */
  __x = v2[2] * v2[2] + v2[1] * v2[1] + *v2 * *v2 + 0.0;
  fVar1 = SQRT(__x);
  if (NAN(fVar1)) {
    fVar1 = sqrtf(__x);
  }
  if (fVar2 == 0.0) {
    fVar1 = 0.0;
  }
  else if (fVar1 == 0.0) {
    fVar1 = 0.0;
  }
  else {
    dVar3 = acos((double)(v1[2] * v2[2] + v1[1] * v2[1] + *v1 * *v2));
    fVar1 = (((float)dVar3 / (fVar1 * fVar2)) * 180.0) / 3.1415927;
  }
  return fVar1;
}


// VectorTransform  @ 001750b0  (line 239)

void VectorTransform(vec_t *in1,float (*in2) [4],vec_t *out)

{
  *out = in1[2] * (*in2)[2] + in1[1] * (*in2)[1] + *in1 * (*in2)[0] + (*in2)[3];
  out[1] = in1[2] * in2[1][2] + in1[1] * in2[1][1] + *in1 * in2[1][0] + in2[1][3];
  out[2] = in1[2] * in2[2][2] + in1[1] * in2[2][1] + *in1 * in2[2][0] + in2[2][3];
  return;
}


// VectorCompare  @ 00175110  (line 246)

int VectorCompare(vec_t *v1,vec_t *v2)

{
                    /* Unresolved local var: int i@[???] */
  if (*v1 != *v2) {
    return 0;
  }
  if (v1[1] != v2[1]) {
    return 0;
  }
  return (uint)(v1[2] == v2[2]);
}


// VectorMA  @ 00175160  (line 257)

void VectorMA(vec_t *veca,float scale,vec_t *vecb,vec_t *vecc)

{
  *vecc = *vecb * scale + *veca;
  vecc[1] = vecb[1] * scale + veca[1];
  vecc[2] = scale * vecb[2] + veca[2];
  return;
}


// _DotProduct  @ 00175190  (line 266)

vec_t _DotProduct(vec_t *v1,vec_t *v2)

{
  return v1[2] * v2[2] + v1[1] * v2[1] + *v1 * *v2;
}


// _VectorSubtract  @ 001751b0  (line 271)

void _VectorSubtract(vec_t *veca,vec_t *vecb,vec_t *out)

{
  *out = *veca - *vecb;
  out[1] = veca[1] - vecb[1];
  out[2] = veca[2] - vecb[2];
  return;
}


// _VectorAdd  @ 001751e0  (line 278)

void _VectorAdd(vec_t *veca,vec_t *vecb,vec_t *out)

{
  *out = *veca + *vecb;
  out[1] = veca[1] + vecb[1];
  out[2] = veca[2] + vecb[2];
  return;
}


// _VectorCopy  @ 00175210  (line 285)

void _VectorCopy(vec_t *in,vec_t *out)

{
  *out = *in;
  out[1] = in[1];
  out[2] = in[2];
  return;
}


// CrossProduct  @ 00175230  (line 293)

void CrossProduct(vec_t *v1,vec_t *v2,vec_t *cross)

{
  *cross = v1[1] * v2[2] - v1[2] * v2[1];
  cross[1] = v1[2] * *v2 - *v1 * v2[2];
  cross[2] = *v1 * v2[1] - v1[1] * *v2;
  return;
}


// Length  @ 00175270  (line 304)

float Length(vec_t *v)

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


// Distance  @ 001752b0  (line 317)

float Distance(vec_t *v1,vec_t *v2)

{
  float __x;
  float fVar1;
  
                    /* Unresolved local var: vec3_t d@[???] */
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float length@[???] */
  __x = (v2[2] - v1[2]) * (v2[2] - v1[2]) +
        (v2[1] - v1[1]) * (v2[1] - v1[1]) + (*v2 - *v1) * (*v2 - *v1) + 0.0;
  fVar1 = SQRT(__x);
  if (NAN(fVar1)) {
    fVar1 = sqrtf(__x);
  }
  return fVar1;
}


// VectorNormalize  @ 00175300  (line 325)

float VectorNormalize(vec_t *v)

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
  if (fVar2 == 0.0) {
    return fVar2;
  }
  fVar1 = 1.0 / fVar2;
  *v = *v * fVar1;
  v[1] = v[1] * fVar1;
  v[2] = fVar1 * v[2];
  return fVar2;
}


// VectorInverse  @ 00175370  (line 344)

void VectorInverse(vec_t *v)

{
  *v = -*v;
  v[1] = -v[1];
  v[2] = -v[2];
  return;
}


// VectorScale  @ 00175390  (line 351)

void VectorScale(vec_t *in,vec_t scale,vec_t *out)

{
  *out = *in * scale;
  out[1] = in[1] * scale;
  out[2] = scale * in[2];
  return;
}


// Q_log2  @ 001753c0  (line 360)

int Q_log2(int val)

{
  int iVar1;
  
                    /* Unresolved local var: int answer@[???] */
  iVar1 = 0;
  while (val = val >> 1, val != 0) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}


// VectorMatrix  @ 001753e0  (line 368)

void VectorMatrix(vec_t *forward,vec_t *right,vec_t *up)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
                    /* Unresolved local var: vec3_t tmp@[???] */
  if ((*forward == 0.0) && (forward[1] == 0.0)) {
    right[1] = 0.0;
    *right = 1.0;
    right[2] = 0.0;
    *up = -forward[2];
    up[1] = 0.0;
    up[2] = 0.0;
    return;
  }
  fVar3 = forward[1] - forward[2] * 0.0;
  *right = fVar3;
  fVar1 = forward[2] * 0.0 - *forward;
  right[1] = fVar1;
  fVar2 = *forward * 0.0 - forward[1] * 0.0;
  right[2] = fVar2;
                    /* Unresolved local var: float length@[???]
                       Unresolved local var: float ilength@[???] */
  fVar2 = fVar2 * fVar2 + fVar1 * fVar1 + fVar3 * fVar3;
  fVar3 = SQRT(fVar2);
  if (NAN(fVar3)) {
    fVar3 = sqrtf(fVar2);
  }
  if (fVar3 == 0.0) {
    fVar2 = right[1];
    fVar3 = right[2];
  }
  else {
    fVar3 = 1.0 / fVar3;
    *right = *right * fVar3;
    fVar2 = right[1] * fVar3;
    right[1] = fVar2;
    fVar3 = fVar3 * right[2];
    right[2] = fVar3;
  }
  fVar3 = fVar2 * forward[2] - fVar3 * forward[1];
  *up = fVar3;
  fVar1 = right[2] * *forward - *right * forward[2];
  up[1] = fVar1;
  fVar2 = *right * forward[1] - right[1] * *forward;
  up[2] = fVar2;
                    /* Unresolved local var: float length@[???]
                       Unresolved local var: float ilength@[???] */
  fVar3 = fVar2 * fVar2 + fVar1 * fVar1 + fVar3 * fVar3;
  fVar2 = SQRT(fVar3);
  if (NAN(fVar2)) {
    fVar2 = sqrtf(fVar3);
  }
  if (fVar2 != 0.0) {
    fVar2 = 1.0 / fVar2;
    *up = *up * fVar2;
    up[1] = up[1] * fVar2;
    up[2] = fVar2 * up[2];
    return;
  }
  return;
}


// VectorAngles  @ 00175580  (line 392)

void VectorAngles(vec_t *forward,vec_t *angles)

{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  
                    /* Unresolved local var: float tmp@[???]
                       Unresolved local var: float yaw@[???]
                       Unresolved local var: float pitch@[???] */
  if ((forward[1] == 0.0) && (*forward == 0.0)) {
    if (forward[2] <= 0.0) {
      fVar1 = 0.0;
      fVar2 = 270.0;
    }
    else {
      fVar1 = 0.0;
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


