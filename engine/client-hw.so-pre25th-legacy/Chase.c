// Chase_Init  @ 00206a50
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Chase_Init(void)

{
  Cvar_RegisterVariable(&chase_back);
  Cvar_RegisterVariable(&chase_up);
  Cvar_RegisterVariable(&chase_right);
  Cvar_RegisterVariable(&chase_active);
  return;
}


// Chase_Reset  @ 00206a90
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Chase_Reset(void)

{
  return;
}


// Chase_Update  @ 00206b20
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void Chase_Update(void)

{
  float fVar1;
  float fVar2;
  double dVar3;
  trace_t local_84;
  float local_4c;
  float local_48;
  float local_44;
  float local_3c;
  float local_38;
  vec_t local_24 [3];
  vec_t local_18 [4];
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: float dist@[???]
                       Unresolved local var: vec3_t forward@[???]
                       Unresolved local var: vec3_t up@[???]
                       Unresolved local var: vec3_t right@[???]
                       Unresolved local var: vec3_t dest@[???]
                       Unresolved local var: vec3_t stop@[???] */
  AngleVectors(cl.viewangles,&local_4c,&local_3c,local_24);
                    /* Unresolved local var: trace_t trace@[???] */
  chase_dest[0] = (r_refdef.vieworg[0] - local_4c * chase_back.value) - local_3c * chase_right.value
  ;
  chase_dest[1] = (r_refdef.vieworg[1] - chase_back.value * local_48) - chase_right.value * local_38
  ;
  chase_dest[2] = r_refdef.vieworg[2] + chase_up.value;
  VectorMA(r_refdef.vieworg,4096.0,&local_4c,local_18);
  Q_memset(&local_84,0,0x38);
  SV_RecursiveHullCheck((cl.worldmodel)->hulls,0,0.0,1.0,r_refdef.vieworg,local_18,&local_84);
  fVar2 = local_44 * (local_84.endpos[2] - r_refdef.vieworg[2]) +
          (local_84.endpos[1] - r_refdef.vieworg[1]) * local_48 +
          (local_84.endpos[0] - r_refdef.vieworg[0]) * local_4c;
  fVar1 = 1.0;
  if (1.0 <= fVar2) {
    fVar1 = fVar2;
  }
  dVar3 = atan((double)((local_84.endpos[2] - r_refdef.vieworg[2]) / fVar1));
  r_refdef.vieworg[0] = chase_dest[0];
  r_refdef.vieworg[1] = chase_dest[1];
  r_refdef.vieworg[2] = chase_dest[2];
  r_refdef.viewangles[0] =
       (vec_t)((-(longdouble)dVar3 / (longdouble)3.141592653589793) * (longdouble)180.0);
  return;
}


