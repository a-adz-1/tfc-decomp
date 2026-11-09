// CHudHealth::MsgFunc_Damage  @ 00091950
/* DWARF original prototype: int MsgFunc_Damage(CHudHealth * this, char * pszName, int iSize, void *
   pbuf) */

int __thiscall CHudHealth::MsgFunc_Damage(CHudHealth *this,char *pszName,int iSize,void *pbuf)

{
  Vector vecFrom;
  int iVar1;
  int iVar2;
  int bitsDamage;
  float fVar3;
  float fVar4;
  float fVar5;
  vec_t in_stack_ffffffb0;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int armor@[???]
                       Unresolved local var: int damageTaken@[???]
                       Unresolved local var: long bitsDamage@[???]
                       Unresolved local var: Vector vecFrom@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  iVar2 = READ_BYTE();
  bitsDamage = READ_LONG();
                    /* Unresolved local var: int i@[???] */
  fVar3 = READ_COORD();
  fVar4 = READ_COORD();
  fVar5 = READ_COORD();
  UpdateTiles(this,gHUD.m_flTime,bitsDamage);
  if ((0 < iVar1) || (0 < iVar2)) {
    vecFrom.y = (vec_t)bitsDamage;
    vecFrom.x = (vec_t)&local_28;
    vecFrom.z = in_stack_ffffffb0;
    local_28 = fVar3;
    local_24 = fVar4;
    local_20 = fVar5;
    CalcDamageDirection(this,vecFrom);
  }
  return 1;
}


// CHudHealth::MsgFunc_Health  @ 00090100
/* DWARF original prototype: int MsgFunc_Health(CHudHealth * this, char * pszName, int iSize, void *
   pbuf) */

int __thiscall CHudHealth::MsgFunc_Health(CHudHealth *this,char *pszName,int iSize,void *pbuf)

{
  int *piVar1;
  int iVar2;
  
                    /* Unresolved local var: int x@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar2 = READ_BYTE();
  piVar1 = &(this->super_CHudBase).m_iFlags;
  *piVar1 = *piVar1 | 1;
  if (this->m_iHealth != iVar2) {
    this->m_fFade = 100.0;
    this->m_iHealth = iVar2;
  }
  return 1;
}


