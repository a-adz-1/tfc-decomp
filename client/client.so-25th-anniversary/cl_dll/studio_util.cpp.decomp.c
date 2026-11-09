// Ghidra decompilation of functions from cl_dll/studio_util.cpp
// 9 functions, ordered by original source line

// AngleMatrix  @ 0007b960  (line 15)

void AngleMatrix(float *angles,float (*matrix) [4])

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  double local_2c;
  double local_24 [2];
  
                    /* Unresolved local var: float angle@[???]
                       Unresolved local var: float sr@[???]
                       Unresolved local var: float sp@[???]
                       Unresolved local var: float sy@[???]
                       Unresolved local var: float cr@[???]
                       Unresolved local var: float cp@[???]
                       Unresolved local var: float cy@[???] */
  sincos((double)(angles[1] * 0.017453292),local_24,&local_2c);
  fVar1 = (float)local_24[0];
  fVar2 = (float)local_2c;
  sincos((double)(*angles * 0.017453292),local_24,&local_2c);
  fVar3 = (float)local_24[0];
  fVar4 = (float)local_2c;
  sincos((double)(angles[2] * 0.017453292),local_24,&local_2c);
  fVar5 = (float)local_24[0];
  fVar6 = (float)local_2c;
  (*matrix)[0] = fVar4 * fVar2;
  matrix[1][0] = fVar4 * fVar1;
  matrix[2][0] = -fVar3;
  (*matrix)[1] = fVar2 * fVar3 * fVar5 - fVar1 * fVar6;
  matrix[1][1] = fVar2 * fVar6 + fVar3 * fVar5 * fVar1;
  matrix[2][1] = fVar4 * fVar5;
  (*matrix)[2] = fVar1 * fVar5 + fVar2 * fVar3 * fVar6;
  matrix[1][2] = fVar3 * fVar6 * fVar1 - fVar5 * fVar2;
  matrix[2][2] = fVar6 * fVar4;
  (*matrix)[3] = 0.0;
  matrix[1][3] = 0.0;
  matrix[2][3] = 0.0;
  return;
}


// VectorCompare  @ 0007bab0  (line 51)

int VectorCompare(float *v1,float *v2)

{
  uint uVar1;
  
                    /* Unresolved local var: int i@[???] */
  if ((*v2 == *v1) && (v1[1] == v2[1])) {
    uVar1 = (uint)(!NAN(v2[2]) && !NAN(v1[2]));
    if (v2[2] != v1[2]) {
      uVar1 = 0;
    }
    return uVar1;
  }
  return 0;
}


// CrossProduct  @ 0007bb00  (line 68)

void CrossProduct(float *v1,float *v2,float *cross)

{
  *cross = v1[1] * v2[2] - v1[2] * v2[1];
  cross[1] = v1[2] * *v2 - *v1 * v2[2];
  cross[2] = *v1 * v2[1] - v1[1] * *v2;
  return;
}


// VectorTransform  @ 0007bb40  (line 81)

void VectorTransform(float *in1,float (*in2) [4],float *out)

{
  *out = in1[2] * (*in2)[2] + in1[1] * (*in2)[1] + *in1 * (*in2)[0] + (*in2)[3];
  out[1] = in1[2] * in2[1][2] + in1[1] * in2[1][1] + *in1 * in2[1][0] + in2[1][3];
  out[2] = in1[2] * in2[2][2] + in1[1] * in2[2][1] + *in1 * in2[2][0] + in2[2][3];
  return;
}


// ConcatTransforms  @ 0007bba0  (line 94)

void ConcatTransforms(float (*in1) [4],float (*in2) [4],float (*out) [4])

{
  (*out)[0] = (*in1)[2] * in2[2][0] + (*in1)[1] * in2[1][0] + (*in1)[0] * (*in2)[0];
  (*out)[1] = (*in1)[2] * in2[2][1] + (*in1)[1] * in2[1][1] + (*in1)[0] * (*in2)[1];
  (*out)[2] = (*in1)[2] * in2[2][2] + (*in1)[1] * in2[1][2] + (*in1)[0] * (*in2)[2];
  (*out)[3] = (*in1)[2] * in2[2][3] + (*in1)[1] * in2[1][3] + (*in1)[0] * (*in2)[3] + (*in1)[3];
  out[1][0] = in1[1][2] * in2[2][0] + in1[1][1] * in2[1][0] + in1[1][0] * (*in2)[0];
  out[1][1] = in1[1][2] * in2[2][1] + in1[1][1] * in2[1][1] + in1[1][0] * (*in2)[1];
  out[1][2] = in1[1][2] * in2[2][2] + in1[1][1] * in2[1][2] + in1[1][0] * (*in2)[2];
  out[1][3] = in1[1][2] * in2[2][3] + in1[1][1] * in2[1][3] + in1[1][0] * (*in2)[3] + in1[1][3];
  out[2][0] = in1[2][2] * in2[2][0] + in1[2][1] * in2[1][0] + in1[2][0] * (*in2)[0];
  out[2][1] = in1[2][2] * in2[2][1] + in1[2][1] * in2[1][1] + in1[2][0] * (*in2)[1];
  out[2][2] = in1[2][2] * in2[2][2] + in1[2][1] * in2[1][2] + in1[2][0] * (*in2)[2];
  out[2][3] = in1[2][2] * in2[2][3] + in1[2][1] * in2[1][3] + in1[2][0] * (*in2)[3] + in1[2][3];
  return;
}


// AngleQuaternion  @ 0007bce0  (line 130)

void AngleQuaternion(float *angles,vec_t *quaternion)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  double local_2c;
  double local_24 [2];
  
                    /* Unresolved local var: float angle@[???]
                       Unresolved local var: float sr@[???]
                       Unresolved local var: float sp@[???]
                       Unresolved local var: float sy@[???]
                       Unresolved local var: float cr@[???]
                       Unresolved local var: float cp@[???]
                       Unresolved local var: float cy@[???] */
  sincos((double)(angles[2] * 0.5),local_24,&local_2c);
  fVar1 = (float)local_24[0];
  fVar2 = (float)local_2c;
  sincos((double)(angles[1] * 0.5),local_24,&local_2c);
  fVar3 = (float)local_24[0];
  fVar4 = (float)local_2c;
  sincos((double)(*angles * 0.5),local_24,&local_2c);
  fVar5 = fVar4 * (float)local_24[0];
  fVar6 = fVar3 * (float)local_2c;
  *quaternion = fVar2 * fVar5 - fVar1 * fVar6;
  quaternion[1] = fVar5 * fVar1 + fVar6 * fVar2;
  fVar4 = (float)local_2c * fVar4;
  fVar3 = (float)local_24[0] * fVar3;
  quaternion[2] = fVar1 * fVar4 - fVar2 * fVar3;
  quaternion[3] = fVar3 * fVar1 + fVar4 * fVar2;
  return;
}


// QuaternionSlerp  @ 0007bdf0  (line 158)

void QuaternionSlerp(vec_t *p,vec_t *q,float t,vec_t *qt)

{
  undefined8 uVar1;
  undefined8 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  double dVar7;
  double dVar8;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float omega@[???]
                       Unresolved local var: float cosom@[???]
                       Unresolved local var: float sinom@[???]
                       Unresolved local var: float sclp@[???]
                       Unresolved local var: float sclq@[???]
                       Unresolved local var: float a@[???]
                       Unresolved local var: float b@[???] */
  fVar3 = *p;
  fVar4 = q[1];
  fVar5 = p[2];
  fVar6 = p[3];
  if ((q[3] + fVar6) * (q[3] + fVar6) +
      (q[2] + fVar5) * (q[2] + fVar5) +
      (p[1] + fVar4) * (p[1] + fVar4) + (*q + fVar3) * (*q + fVar3) + 0.0 <
      (fVar6 - q[3]) * (fVar6 - q[3]) +
      (fVar5 - q[2]) * (fVar5 - q[2]) +
      (p[1] - fVar4) * (p[1] - fVar4) + (fVar3 - *q) * (fVar3 - *q) + 0.0) {
    *q = -(vec_t)*(undefined8 *)q;
    q[1] = -q[1];
    q[2] = -q[2];
    q[3] = -q[3];
    fVar3 = *p;
    fVar4 = q[1];
    fVar5 = p[2];
    fVar6 = p[3];
  }
  fVar3 = fVar6 * q[3] + fVar5 * q[2] + p[1] * fVar4 + fVar3 * *q;
  if (fVar3 + 1.0 <= 1e-06) {
    *qt = -fVar4;
    qt[1] = *q;
    qt[2] = -q[3];
    qt[3] = q[2];
    dVar7 = sin((double)((1.0 - t) * 1.5707964));
    fVar3 = (float)dVar7;
    dVar7 = sin((double)t * 1.5707963267948966);
    fVar5 = (float)dVar7;
    *qt = -fVar4 * fVar5 + *p * fVar3;
    qt[1] = p[1] * fVar3 + qt[1] * fVar5;
    qt[2] = fVar5 * qt[2] + p[2] * fVar3;
    return;
  }
  if (1e-06 < 1.0 - fVar3) {
    dVar7 = acos((double)fVar3);
    fVar4 = (float)dVar7;
    dVar7 = sin((double)fVar4);
    dVar8 = sin((1.0 - (double)t) * (double)fVar4);
    fVar3 = (float)dVar8 / (float)dVar7;
    dVar8 = sin((double)(fVar4 * t));
    t = (float)dVar8 / (float)dVar7;
  }
  else {
    fVar3 = 1.0 - t;
  }
  if ((q + 4 <= qt || qt + 4 <= q) && (p + 4 <= qt || qt + 4 <= p)) {
    uVar1 = *(undefined8 *)q;
    uVar2 = *(undefined8 *)(q + 2);
    fVar4 = p[1];
    fVar5 = p[2];
    fVar6 = p[3];
    *qt = (float)*(undefined8 *)p * fVar3 + t * (float)uVar1;
    qt[1] = fVar4 * fVar3 + t * (float)((ulonglong)uVar1 >> 0x20);
    qt[2] = fVar5 * fVar3 + t * (float)uVar2;
    qt[3] = fVar6 * fVar3 + t * (float)((ulonglong)uVar2 >> 0x20);
    return;
  }
  *qt = t * *q + fVar3 * *p;
  qt[1] = t * q[1] + fVar3 * p[1];
  qt[2] = fVar3 * p[2] + t * q[2];
  qt[3] = fVar3 * p[3] + t * q[3];
  return;
}


// QuaternionMatrix  @ 0007c0c0  (line 221)

void QuaternionMatrix(vec_t *quaternion,float (*matrix) [4])

{
  float fVar1;
  float fVar2;
  
  fVar1 = quaternion[1];
  fVar2 = quaternion[2];
  (*matrix)[0] = (1.0 - (fVar1 + fVar1) * fVar1) - (fVar2 + fVar2) * fVar2;
  matrix[1][0] = (quaternion[3] + quaternion[3]) * quaternion[2] +
                 (*quaternion + *quaternion) * quaternion[1];
  matrix[2][0] = (*quaternion + *quaternion) * quaternion[2] -
                 (quaternion[3] + quaternion[3]) * quaternion[1];
  (*matrix)[1] = (*quaternion + *quaternion) * quaternion[1] -
                 (quaternion[3] + quaternion[3]) * quaternion[2];
  fVar1 = *quaternion;
  fVar2 = quaternion[2];
  matrix[1][1] = (1.0 - (fVar1 + fVar1) * fVar1) - (fVar2 + fVar2) * fVar2;
  matrix[2][1] = (quaternion[3] + quaternion[3]) * *quaternion +
                 (quaternion[1] + quaternion[1]) * quaternion[2];
  (*matrix)[2] = (quaternion[3] + quaternion[3]) * quaternion[1] +
                 (*quaternion + *quaternion) * quaternion[2];
  matrix[1][2] = (quaternion[1] + quaternion[1]) * quaternion[2] -
                 (quaternion[3] + quaternion[3]) * *quaternion;
  fVar1 = *quaternion;
  fVar2 = quaternion[1];
  matrix[2][2] = (1.0 - (fVar1 + fVar1) * fVar1) - (fVar2 + fVar2) * fVar2;
  return;
}


// MatrixCopy  @ 0007c1a0  (line 242)

void MatrixCopy(float (*in) [4],float (*out) [4])

{
  float *pfVar1;
  uint uVar2;
  int iVar3;
  undefined2 *puVar4;
  float (*pafVar5) [4];
  undefined2 *puVar6;
  uint uVar7;
  bool bVar8;
  
  uVar7 = 0x30;
  bVar8 = ((uint)out & 1) != 0;
  if (bVar8) {
    pfVar1 = *in;
    in = (float (*) [4])((int)*in + 1);
    uVar7 = 0x2f;
    *(undefined1 *)*out = *(undefined1 *)pfVar1;
    out = (float (*) [4])((int)*out + 1);
  }
  pafVar5 = out;
  if (((uint)out & 2) != 0) {
    pfVar1 = *in;
    pafVar5 = (float (*) [4])((int)*out + 2);
    in = (float (*) [4])((int)*in + 2);
    uVar7 = uVar7 - 2;
    *(undefined2 *)*out = *(undefined2 *)pfVar1;
  }
  uVar2 = 0;
  do {
    *(undefined4 *)((int)*pafVar5 + uVar2) = *(undefined4 *)((int)*in + uVar2);
    uVar2 = uVar2 + 4;
  } while (uVar2 < (uVar7 & 0xfffffffc));
  puVar6 = (undefined2 *)((int)*pafVar5 + uVar2);
  puVar4 = (undefined2 *)((int)*in + uVar2);
  iVar3 = 0;
  if ((uVar7 & 2) != 0) {
    *puVar6 = *puVar4;
    iVar3 = 2;
  }
  if (bVar8) {
    *(undefined1 *)((int)puVar6 + iVar3) = *(undefined1 *)((int)puVar4 + iVar3);
  }
  return;
}


