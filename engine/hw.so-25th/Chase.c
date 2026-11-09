// Chase_Init  @ 001b6d60
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Chase_Init(void)

{
  Cvar_RegisterVariable(&chase_back);
  Cvar_RegisterVariable(&chase_up);
  Cvar_RegisterVariable(&chase_right);
  Cvar_RegisterVariable(&chase_active);
  return;
}


// Chase_Reset  @ 001b6da0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Chase_Reset(void)

{
  return;
}


// Chase_Update  @ 001b6e40
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Chase_Update(void)

{
  float fVar1;
  float fVar2;
  double dVar3;
  float local_74;
  float local_70;
  float local_6c;
  vec_t local_68 [3];
  float local_5c;
  float local_58;
  vec_t local_50 [3];
  trace_t local_44;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float dist@[???]
                       Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t dest@[???]
                       Unresolved local var: vec3_t stop@[???] */
  AngleVectors(cl.viewangles,&local_74,&local_5c,local_68);
                    /* Unresolved local var: trace_t trace@[???] */
  chase_dest[0] = (r_refdef.vieworg[0] - chase_back.value * local_74) - chase_right.value * local_5c
  ;
  chase_dest[1] = (r_refdef.vieworg[1] - chase_back.value * local_70) - chase_right.value * local_58
  ;
  chase_dest[2] = chase_up.value + r_refdef.vieworg[2];
  VectorMA(r_refdef.vieworg,4096.0,&local_74,local_50);
  Q_memset(&local_44,0,0x38);
  SV_RecursiveHullCheck((cl.worldmodel)->hulls,0,0.0,1.0,r_refdef.vieworg,local_50,&local_44);
  fVar2 = local_6c * (local_44.endpos[2] - r_refdef.vieworg[2]) +
          (local_44.endpos[1] - r_refdef.vieworg[1]) * local_70 +
          (local_44.endpos[0] - r_refdef.vieworg[0]) * local_74;
  fVar1 = 1.0;
  if (1.0 <= fVar2) {
    fVar1 = fVar2;
  }
  dVar3 = atan((double)((local_44.endpos[2] - r_refdef.vieworg[2]) / fVar1));
  r_refdef.vieworg[0] = chase_dest[0];
  r_refdef.vieworg[1] = chase_dest[1];
  r_refdef.vieworg[2] = chase_dest[2];
  r_refdef.viewangles[0] =
       (vec_t)((-(longdouble)dVar3 / (longdouble)3.141592653589793) * (longdouble)180.0);
  return;
}


