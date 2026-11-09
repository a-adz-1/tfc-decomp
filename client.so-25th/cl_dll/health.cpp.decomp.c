// Ghidra decompilation of functions from cl_dll/health.cpp
// 14 functions, ordered by original source line

// __MsgFunc_Health  @ 0006c470  (line 31)

int __MsgFunc_Health(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
                    /* Unresolved local var: int x@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  gHUD.m_Health.super_CHudBase.m_iFlags = gHUD.m_Health.super_CHudBase.m_iFlags | 1;
  if (iVar1 != gHUD.m_Health.m_iHealth) {
    gHUD.m_Health.m_fFade = 100.0;
    gHUD.m_Health.m_iHealth = iVar1;
  }
  return 1;
}


// __MsgFunc_Damage  @ 0006cc70  (line 32)

int __MsgFunc_Damage(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  iVar1 = CHudHealth::MsgFunc_Damage(&gHUD.m_Health,pszName,iSize,pbuf);
  return iVar1;
}


// CHudHealth::Init  @ 0006c000  (line 56)

/* DWARF original prototype: int Init(CHudHealth * this) */

int __thiscall CHudHealth::Init(CHudHealth *this)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  DAMAGE_IMAGE *pDVar4;
  undefined4 *puVar5;
  bool bVar6;
  
  (*gEngfuncs.pfnHookUserMsg)("Health",__MsgFunc_Health);
  (*gEngfuncs.pfnHookUserMsg)("Damage",__MsgFunc_Damage);
  pDVar4 = this->m_dmg;
  bVar6 = ((uint)pDVar4 & 1) != 0;
  this->m_bitsDamage = 0;
  uVar3 = 0xc0;
  this->m_iHealth = 100;
  this->m_fFade = 0.0;
  (this->super_CHudBase).m_iFlags = 0;
  this->m_fAttackLeft = 0.0;
  this->m_fAttackRight = 0.0;
  this->m_fAttackRear = 0.0;
  this->m_fAttackFront = 0.0;
  giDmgHeight = 0;
  giDmgWidth = 0;
  if (bVar6) {
    pDVar4 = (DAMAGE_IMAGE *)((int)&this->m_dmg[0].fExpire + 1);
    uVar3 = 0xbf;
    *(undefined1 *)&this->m_dmg[0].fExpire = 0;
  }
  if (((uint)pDVar4 & 2) != 0) {
    *(undefined2 *)&pDVar4->fExpire = 0;
    uVar3 = uVar3 - 2;
    pDVar4 = (DAMAGE_IMAGE *)((int)&pDVar4->fExpire + 2);
  }
  uVar1 = 0;
  do {
    uVar2 = uVar1;
    *(undefined4 *)((int)&pDVar4->fExpire + uVar2) = 0;
    *(undefined4 *)((int)&pDVar4->fBaseline + uVar2) = 0;
    uVar1 = uVar2 + 8;
  } while (uVar2 + 8 < (uVar3 & 0xfffffff8));
  puVar5 = (undefined4 *)((int)&pDVar4->x + uVar2);
  if ((uVar3 & 4) != 0) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  if ((uVar3 & 2) != 0) {
    *(undefined2 *)puVar5 = 0;
    puVar5 = (undefined4 *)((int)puVar5 + 2);
  }
  if (bVar6) {
    *(undefined1 *)puVar5 = 0;
  }
  CHud::AddHudElem(&gHUD,&this->super_CHudBase);
  return 1;
}


// CHudHealth::Reset  @ 0006bfa0  (line 75)

/* DWARF original prototype: void Reset(CHudHealth * this) */

void __thiscall CHudHealth::Reset(CHudHealth *this)

{
  this->m_fAttackLeft = 0.0;
  this->m_fAttackRight = 0.0;
  this->m_fAttackRear = 0.0;
  this->m_fAttackFront = 0.0;
                    /* Unresolved local var: int i@[???] */
  this->m_dmg[0].fExpire = 0.0;
  this->m_dmg[1].fExpire = 0.0;
  this->m_dmg[2].fExpire = 0.0;
  this->m_dmg[3].fExpire = 0.0;
  this->m_dmg[4].fExpire = 0.0;
  this->m_dmg[5].fExpire = 0.0;
  this->m_dmg[6].fExpire = 0.0;
  this->m_dmg[7].fExpire = 0.0;
  this->m_dmg[8].fExpire = 0.0;
  this->m_dmg[9].fExpire = 0.0;
  this->m_dmg[10].fExpire = 0.0;
  this->m_bitsDamage = 0;
  this->m_dmg[0xb].fExpire = 0.0;
  return;
}


// CHudHealth::VidInit  @ 0006c120  (line 89)

/* DWARF original prototype: int VidInit(CHudHealth * this) */

int __thiscall CHudHealth::VidInit(CHudHealth *this)

{
  int iVar1;
  wrect_t *pwVar2;
  
  this->m_hSprite = 0;
  iVar1 = CHud::GetSpriteIndex(&gHUD,"dmg_bio");
  this->m_HUD_dmg_bio = iVar1 + 1;
  iVar1 = CHud::GetSpriteIndex(&gHUD,"cross");
  this->m_HUD_cross = iVar1;
  pwVar2 = gHUD.m_rgrcRects + this->m_HUD_dmg_bio;
  giDmgHeight = pwVar2->right - pwVar2->left;
  giDmgWidth = pwVar2->bottom - pwVar2->top;
  return 1;
}


// CHudHealth::MsgFunc_Health  @ 0006c4c0  (line 101)

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
  if (iVar2 != this->m_iHealth) {
    this->m_fFade = 100.0;
    this->m_iHealth = iVar2;
  }
  return 1;
}


// CHudHealth::MsgFunc_Damage  @ 0006c8a0  (line 120)

/* DWARF original prototype: int MsgFunc_Damage(CHudHealth * this, char * pszName, int iSize, void *
   pbuf) */

int __thiscall CHudHealth::MsgFunc_Damage(CHudHealth *this,char *pszName,int iSize,void *pbuf)

{
  uint uVar1;
  uint uVar2;
  Vector vecFrom;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  DAMAGE_IMAGE *pDVar9;
  int iVar10;
  int iVar11;
  float fVar12;
  float fVar13;
  undefined8 in_stack_ffffffac;
  float local_28;
  float local_24;
  float local_20;
  
                    /* Unresolved local var: int armor@[???]
                       Unresolved local var: int damageTaken@[???]
                       Unresolved local var: long bitsDamage@[???]
                       Unresolved local var: Vector vecFrom@[???] */
  BEGIN_READ(pbuf,iSize);
  iVar5 = READ_BYTE();
  iVar6 = READ_BYTE();
  uVar7 = READ_LONG();
                    /* Unresolved local var: int i@[???] */
  fVar12 = READ_COORD();
  fVar13 = READ_COORD();
  local_20 = READ_COORD();
  iVar4 = giDmgHeight;
  fVar3 = gHUD.m_flTime;
                    /* Unresolved local var: DAMAGE_IMAGE * pdmg@[???]
                       Unresolved local var: long bitsOn@[???] */
  uVar1 = this->m_bitsDamage;
                    /* Unresolved local var: int i@[???] */
  iVar8 = giDmgWidth + 7;
  if (-1 < giDmgWidth) {
    iVar8 = giDmgWidth;
  }
  iVar10 = 0;
  pDVar9 = this->m_dmg;
  do {
    uVar2 = giDmgFlags[iVar10];
    if (((uVar1 & uVar2) != 0) && (pDVar9->fExpire = fVar3 + 2.0, pDVar9->fBaseline == 0.0)) {
      pDVar9->fBaseline = fVar3;
    }
    if ((~uVar1 & uVar7 & uVar2) == 0) {
LAB_0006cab0:
      if (iVar10 == 0xb) goto LAB_0006cad0;
    }
    else {
      pDVar9->x = iVar8 >> 3;
      iVar11 = gHUD.m_scrinfo.iHeight + iVar4 * -2;
                    /* Unresolved local var: int j@[???] */
      pDVar9->fExpire = fVar3 + 2.0;
      pDVar9->y = iVar11;
      if (iVar10 != 0) {
        iVar11 = this->m_dmg[0].y;
        if (iVar11 != 0) {
          this->m_dmg[0].y = iVar11 - iVar4;
        }
        if (iVar10 != 1) {
          iVar11 = this->m_dmg[1].y;
          if (iVar11 != 0) goto LAB_0006c9ad;
          goto LAB_0006c9b2;
        }
        iVar11 = this->m_dmg[2].y;
        if (iVar11 != 0) goto LAB_0006c9c2;
        iVar11 = this->m_dmg[3].y;
        if (iVar11 != 0) goto LAB_0006c9d7;
LAB_0006c9e5:
        iVar11 = this->m_dmg[4].y;
        if (iVar11 != 0) {
LAB_0006c9ef:
          this->m_dmg[4].y = iVar11 - iVar4;
        }
        if (iVar10 == 5) {
          iVar11 = this->m_dmg[6].y;
          if (iVar11 != 0) {
LAB_0006ca25:
            this->m_dmg[6].y = iVar11 - iVar4;
            goto LAB_0006ca2d;
          }
          iVar11 = this->m_dmg[7].y;
          if (iVar11 != 0) goto LAB_0006ca40;
          goto LAB_0006ca51;
        }
LAB_0006ca00:
        iVar11 = this->m_dmg[5].y;
        if (iVar11 != 0) {
LAB_0006ca0a:
          this->m_dmg[5].y = iVar11 - iVar4;
        }
        if (iVar10 == 6) {
          iVar11 = this->m_dmg[7].y;
          if (iVar11 != 0) goto LAB_0006ca40;
          iVar11 = this->m_dmg[8].y;
          if (iVar11 != 0) goto LAB_0006ca5b;
          goto LAB_0006ca6c;
        }
LAB_0006ca1b:
        iVar11 = this->m_dmg[6].y;
        if (iVar11 != 0) goto LAB_0006ca25;
LAB_0006ca2d:
        if (iVar10 != 7) goto LAB_0006ca36;
        iVar11 = this->m_dmg[8].y;
        if (iVar11 != 0) goto LAB_0006ca5b;
        iVar11 = this->m_dmg[9].y;
        if (iVar11 != 0) goto LAB_0006ca76;
LAB_0006ca87:
        iVar11 = this->m_dmg[10].y;
        if (iVar11 != 0) {
LAB_0006ca91:
          this->m_dmg[10].y = iVar11 - iVar4;
        }
        if (iVar10 != 0xb) {
LAB_0006ca9e:
          iVar11 = this->m_dmg[0xb].y;
          if (iVar11 != 0) {
LAB_0006caa8:
            this->m_dmg[0xb].y = iVar11 - iVar4;
          }
          goto LAB_0006cab0;
        }
LAB_0006cad0:
        this->m_bitsDamage = uVar1 | uVar7;
        if ((iVar6 < 1) && (iVar5 < 1)) {
          return 1;
        }
        vecFrom.y = (vec_t)(int)in_stack_ffffffac;
        vecFrom.z = (vec_t)(int)((ulonglong)in_stack_ffffffac >> 0x20);
        vecFrom.x = (vec_t)&local_28;
        local_28 = fVar12;
        local_24 = fVar13;
        CalcDamageDirection(this,vecFrom);
        return 1;
      }
      iVar11 = this->m_dmg[1].y;
      if (iVar11 != 0) {
LAB_0006c9ad:
        this->m_dmg[1].y = iVar11 - iVar4;
LAB_0006c9b2:
        if (iVar10 != 2) {
          iVar11 = this->m_dmg[2].y;
          if (iVar11 != 0) goto LAB_0006c9c2;
          goto LAB_0006c9c7;
        }
        iVar11 = this->m_dmg[3].y;
        if (iVar11 != 0) goto LAB_0006c9d7;
        iVar11 = this->m_dmg[4].y;
        if (iVar11 != 0) goto LAB_0006c9ef;
        goto LAB_0006ca00;
      }
      iVar11 = this->m_dmg[2].y;
      if (iVar11 != 0) {
LAB_0006c9c2:
        this->m_dmg[2].y = iVar11 - iVar4;
LAB_0006c9c7:
        if (iVar10 != 3) goto LAB_0006c9d0;
        iVar11 = this->m_dmg[4].y;
        if (iVar11 != 0) goto LAB_0006c9ef;
        iVar11 = this->m_dmg[5].y;
        if (iVar11 != 0) goto LAB_0006ca0a;
        goto LAB_0006ca1b;
      }
LAB_0006c9d0:
      iVar11 = this->m_dmg[3].y;
      if (iVar11 != 0) {
LAB_0006c9d7:
        this->m_dmg[3].y = iVar11 - iVar4;
      }
      if (iVar10 != 4) goto LAB_0006c9e5;
      iVar11 = this->m_dmg[5].y;
      if (iVar11 != 0) goto LAB_0006ca0a;
      iVar11 = this->m_dmg[6].y;
      if (iVar11 != 0) goto LAB_0006ca25;
LAB_0006ca36:
      iVar11 = this->m_dmg[7].y;
      if (iVar11 != 0) {
LAB_0006ca40:
        this->m_dmg[7].y = iVar11 - iVar4;
      }
      if (iVar10 == 8) {
        iVar11 = this->m_dmg[9].y;
        if (iVar11 != 0) {
LAB_0006ca76:
          this->m_dmg[9].y = iVar11 - iVar4;
          goto LAB_0006ca7e;
        }
LAB_0006cb5a:
        iVar11 = this->m_dmg[10].y;
        if (iVar11 != 0) goto LAB_0006ca91;
        goto LAB_0006ca9e;
      }
LAB_0006ca51:
      iVar11 = this->m_dmg[8].y;
      if (iVar11 != 0) {
LAB_0006ca5b:
        this->m_dmg[8].y = iVar11 - iVar4;
      }
      if (iVar10 == 9) goto LAB_0006cb5a;
LAB_0006ca6c:
      iVar11 = this->m_dmg[9].y;
      if (iVar11 != 0) goto LAB_0006ca76;
LAB_0006ca7e:
      if (iVar10 != 10) goto LAB_0006ca87;
      iVar11 = this->m_dmg[0xb].y;
      if (iVar11 != 0) goto LAB_0006caa8;
    }
    iVar10 = iVar10 + 1;
    pDVar9 = pDVar9 + 1;
  } while( true );
}


// CHudHealth::GetPainColor  @ 0006c500  (line 145)

/* DWARF original prototype: void GetPainColor(CHudHealth * this, int * r, int * g, int * b) */

void __thiscall CHudHealth::GetPainColor(CHudHealth *this,int *r,int *g,int *b)

{
                    /* Unresolved local var: int iHealth@[???] */
  if (this->m_iHealth < 0x1a) {
    *r = 0xfa;
    *g = 0;
    *b = 0;
    return;
  }
  *r = 0xff;
  *g = 0xa0;
  *b = 0;
  return;
}


// CHudHealth::Draw  @ 0006d2a0  (line 171)

/* DWARF original prototype: int Draw(CHudHealth * this, float flTime) */

int __thiscall CHudHealth::Draw(CHudHealth *this,float flTime)

{
  float fVar1;
  int iVar2;
  HANDLE_SPRITE HVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *g;
  int local_28;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int HealthWidth@[???] */
  if ((((byte)gHUD.m_iHideHUDDisplay & 8) != 0) ||
     (iVar2 = (*gEngfuncs.IsSpectateOnly)(), iVar2 != 0)) {
    return 1;
  }
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int HealthWidth@[???] */
  if (this->m_hSprite == 0) {
    HVar3 = LoadSprite("sprites/%d_pain.spr");
    this->m_hSprite = HVar3;
  }
  iVar2 = 100;
  if (this->m_fFade != 0.0) {
    fVar1 = this->m_fFade - (float)gHUD.m_flTimeDelta * 20.0;
    if (fVar1 <= 0.0) {
      this->m_fFade = 0.0;
      iVar2 = 100;
    }
    else {
      this->m_fFade = fVar1;
      iVar2 = (int)((fVar1 / 100.0) * 128.0 + 100.0);
    }
  }
  if (this->m_iHealth < 0x10) {
    iVar2 = 0xff;
  }
  else {
                    /* Unresolved local var: int iHealth@[???] */
    if (0x19 < this->m_iHealth) {
      local_28 = 0xff;
      local_24 = 0xa0;
      goto LAB_0006d377;
    }
  }
  local_28 = 0xfa;
  local_24 = 0;
LAB_0006d377:
  local_20[0] = 0;
  g = &local_24;
  ScaleColors(&local_28,g,local_20,iVar2);
  if (gHUD.m_iWeaponBits < 0) {
                    /* Unresolved local var: int CrossWidth@[???]
                       Unresolved local var: int iHeight@[???]
                       Unresolved local var: int iWidth@[???] */
    iVar4 = this->m_HUD_cross;
    iVar5 = gHUD.m_rgrcRects[gHUD.m_HUD_number_0].right - gHUD.m_rgrcRects[gHUD.m_HUD_number_0].left
    ;
    iVar8 = gHUD.m_rgrcRects[iVar4].right - gHUD.m_rgrcRects[iVar4].left;
    iVar6 = (gHUD.m_scrinfo.iHeight - gHUD.m_iFontHeight) - gHUD.m_iFontHeight / 2;
    HVar3 = 0;
    if (-1 < iVar4) {
      HVar3 = gHUD.m_rghSprites[iVar4];
    }
    (*gEngfuncs.pfnSPR_Set)(HVar3,local_28,local_24,local_20[0]);
    (*gEngfuncs.pfnSPR_DrawAdditive)(0,iVar8 / 2,iVar6,gHUD.m_rgrcRects + this->m_HUD_cross);
    iVar7 = iVar5 / 2;
    g = (int *)((int)((float)gHUD.m_iFontHeight * 0.2) + iVar6);
    iVar4 = CHud::DrawHudNumber(&gHUD,iVar8 + iVar7,(int)g,5,this->m_iHealth,local_28,local_24,
                                local_20[0]);
    (*gEngfuncs.pfnFillRGBA)(iVar7 + iVar4,(int)g,iVar5 / 10,gHUD.m_iFontHeight,0xff,0xa0,0,iVar2);
  }
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: DAMAGE_IMAGE * pdmg@[???]
                       Unresolved local var: int i@[???] */
  if (this->m_bitsDamage != 0) {
    DrawDamage((CHudHealth *)flTime,(float)g);
  }
  iVar2 = DrawPain(this,flTime);
  return iVar2;
}


// CHudHealth::CalcDamageDirection  @ 0006c550  (line 236)

/* DWARF original prototype: void CalcDamageDirection(CHudHealth * this, Vector vecFrom) */

void __thiscall CHudHealth::CalcDamageDirection(CHudHealth *this,Vector vecFrom)

{
  float fVar1;
  float fVar2;
  vec_t vVar3;
  float fVar4;
  float fVar5;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30 [3];
  vec_t local_24;
  vec_t local_20;
  vec_t local_1c;
  vec_t local_18;
  vec_t local_14;
  vec_t local_10;
  
  local_1c = gHUD.m_vecOrigin.z;
  vVar3 = gHUD.m_vecOrigin.y;
                    /* Unresolved local var: Vector forward@[???]
                       Unresolved local var: Vector right@[???]
                       Unresolved local var: Vector up@[???]
                       Unresolved local var: float side@[???]
                       Unresolved local var: float front@[???]
                       Unresolved local var: Vector vecOrigin@[???]
                       Unresolved local var: Vector vecAngles@[???]
                       Unresolved local var: float flDistToTarget@[???] */
  if (*(float *)vecFrom.x == 0.0) {
    fVar1 = *(float *)((int)vecFrom.x + 8);
    if ((*(float *)((int)vecFrom.x + 4) == 0.0) && (fVar1 == 0.0)) {
      this->m_fAttackFront = 0.0;
      this->m_fAttackRear = 0.0;
      this->m_fAttackLeft = 0.0;
      this->m_fAttackRight = 0.0;
      return;
    }
  }
  else {
    fVar1 = *(float *)((int)vecFrom.x + 8);
  }
  local_24 = gHUD.m_vecOrigin.x;
  fVar5 = *(float *)vecFrom.x - gHUD.m_vecOrigin.x;
  local_20 = gHUD.m_vecOrigin.y;
  *(float *)vecFrom.x = fVar5;
  local_14 = gHUD.m_vecAngles.y;
  fVar4 = *(float *)((int)vecFrom.x + 4) - vVar3;
  local_18 = gHUD.m_vecAngles.x;
  *(float *)((int)vecFrom.x + 4) = fVar4;
  local_10 = gHUD.m_vecAngles.z;
  fVar1 = fVar1 - local_1c;
  *(float *)((int)vecFrom.x + 8) = fVar1;
  fVar1 = fVar1 * fVar1 + fVar5 * fVar5 + fVar4 * fVar4;
  fVar5 = SQRT(fVar1);
  if (NAN(fVar5)) {
    fVar5 = sqrtf(fVar1);
  }
                    /* Unresolved local var: float flLen@[???] */
  fVar1 = *(float *)((int)vecFrom.x + 8) * *(float *)((int)vecFrom.x + 8) +
          *(float *)((int)vecFrom.x + 4) * *(float *)((int)vecFrom.x + 4) +
          *(float *)vecFrom.x * *(float *)vecFrom.x;
  fVar4 = SQRT(fVar1);
  if (NAN(fVar4)) {
    fVar4 = sqrtf(fVar1);
  }
  if (fVar4 == 0.0) {
    fVar1 = 1.0;
    fVar2 = 0.0;
    fVar4 = 0.0;
  }
  else {
    fVar4 = 1.0 / fVar4;
    fVar1 = *(float *)((int)vecFrom.x + 8) * fVar4;
    fVar2 = *(float *)((int)vecFrom.x + 4) * fVar4;
    fVar4 = fVar4 * *(float *)vecFrom.x;
  }
  *(float *)vecFrom.x = fVar4;
  *(float *)((int)vecFrom.x + 4) = fVar2;
  *(float *)((int)vecFrom.x + 8) = fVar1;
  (*gEngfuncs.pfnAngleVectors)(&local_18,&local_48,&local_3c,local_30);
  if (50.0 < fVar5) {
    fVar1 = *(float *)vecFrom.x;
    fVar5 = *(float *)((int)vecFrom.x + 4);
    fVar4 = *(float *)((int)vecFrom.x + 8);
    fVar2 = local_40 * fVar4 + local_44 * fVar5 + local_48 * fVar1;
    if (fVar2 <= 0.0) {
                    /* Unresolved local var: float f@[???] */
      if (fVar2 <= 0.0) {
        fVar2 = 0.0 - fVar2;
      }
      if (0.3 < fVar2) {
        if (fVar2 <= this->m_fAttackRear) {
          fVar2 = this->m_fAttackRear;
        }
        this->m_fAttackRear = fVar2;
      }
    }
    else if (0.3 < fVar2) {
      if (fVar2 <= this->m_fAttackFront) {
        fVar2 = this->m_fAttackFront;
      }
      this->m_fAttackFront = fVar2;
    }
    fVar1 = local_34 * fVar4 + local_38 * fVar5 + local_3c * fVar1;
    if (fVar1 <= 0.0) {
                    /* Unresolved local var: float f@[???] */
      if (fVar1 <= 0.0) {
        fVar1 = 0.0 - fVar1;
      }
      if (0.3 < fVar1) {
        if (fVar1 <= this->m_fAttackLeft) {
          fVar1 = this->m_fAttackLeft;
        }
        this->m_fAttackLeft = fVar1;
      }
    }
    else if (0.3 < fVar1) {
      if (fVar1 <= this->m_fAttackRight) {
        fVar1 = this->m_fAttackRight;
      }
      this->m_fAttackRight = fVar1;
    }
    return;
  }
  this->m_fAttackFront = 1.0;
  this->m_fAttackRear = 1.0;
  this->m_fAttackLeft = 1.0;
  this->m_fAttackRight = 1.0;
  return;
}


// CHudHealth::DrawPain  @ 0006cca0  (line 295)

/* DWARF original prototype: int DrawPain(CHudHealth * this, float flTime) */

int __thiscall CHudHealth::DrawPain(CHudHealth *this,float flTime)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_18;
  int local_14;
  int local_10;
  
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: int shade@[???]
                       Unresolved local var: float fFade@[???] */
  fVar1 = this->m_fAttackFront;
  if ((((fVar1 != 0.0) || (this->m_fAttackRear != 0.0)) || (this->m_fAttackLeft != 0.0)) ||
     (this->m_fAttackRight != 0.0)) {
    fVar2 = (float)((longdouble)gHUD.m_flTimeDelta + (longdouble)gHUD.m_flTimeDelta);
    if (0.4 < fVar1) {
                    /* Unresolved local var: int iHealth@[???] */
      if (this->m_iHealth < 0x1a) {
        local_18 = 0xfa;
        local_14 = 0;
      }
      else {
        local_18 = 0xff;
        local_14 = 0xa0;
      }
      local_10 = 0;
      iVar3 = 0x7f;
      if (0.5 <= fVar1) {
        iVar3 = (int)(fVar1 * 255.0);
      }
      ScaleColors(&local_18,&local_14,&local_10,iVar3);
      (*gEngfuncs.pfnSPR_Set)(this->m_hSprite,local_18,local_14,local_10);
      iVar5 = gHUD.m_scrinfo.iWidth / 2;
      iVar3 = (*gEngfuncs.pfnSPR_Width)(this->m_hSprite,0);
      iVar6 = gHUD.m_scrinfo.iHeight / 2;
      iVar4 = (*gEngfuncs.pfnSPR_Height)(this->m_hSprite,0);
      (*gEngfuncs.pfnSPR_DrawAdditive)(0,iVar5 - iVar3 / 2,iVar6 + iVar4 * -3,(rect_s *)0x0);
      fVar1 = this->m_fAttackFront - fVar2;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0;
      }
      this->m_fAttackFront = fVar1;
    }
    else {
      this->m_fAttackFront = 0.0;
    }
    fVar1 = this->m_fAttackRight;
    if (fVar1 <= 0.4) {
      this->m_fAttackRight = 0.0;
    }
    else {
                    /* Unresolved local var: int iHealth@[???] */
      if (this->m_iHealth < 0x1a) {
        local_18 = 0xfa;
        local_14 = 0;
      }
      else {
        local_18 = 0xff;
        local_14 = 0xa0;
      }
      local_10 = 0;
      iVar3 = 0x7f;
      if (0.5 <= fVar1) {
        iVar3 = (int)(fVar1 * 255.0);
      }
      ScaleColors(&local_18,&local_14,&local_10,iVar3);
      (*gEngfuncs.pfnSPR_Set)(this->m_hSprite,local_18,local_14,local_10);
      iVar5 = gHUD.m_scrinfo.iWidth / 2;
      iVar3 = (*gEngfuncs.pfnSPR_Width)(this->m_hSprite,1);
      iVar6 = gHUD.m_scrinfo.iHeight / 2;
      iVar4 = (*gEngfuncs.pfnSPR_Height)(this->m_hSprite,1);
      (*gEngfuncs.pfnSPR_DrawAdditive)(1,iVar5 + iVar3 * 2,iVar6 - iVar4 / 2,(rect_s *)0x0);
      fVar1 = this->m_fAttackRight - fVar2;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0;
      }
      this->m_fAttackRight = fVar1;
    }
    fVar1 = this->m_fAttackRear;
    if (fVar1 <= 0.4) {
      this->m_fAttackRear = 0.0;
    }
    else {
                    /* Unresolved local var: int iHealth@[???] */
      if (this->m_iHealth < 0x1a) {
        local_18 = 0xfa;
        local_14 = 0;
      }
      else {
        local_18 = 0xff;
        local_14 = 0xa0;
      }
      local_10 = 0;
      iVar3 = 0x7f;
      if (0.5 <= fVar1) {
        iVar3 = (int)(fVar1 * 255.0);
      }
      ScaleColors(&local_18,&local_14,&local_10,iVar3);
      (*gEngfuncs.pfnSPR_Set)(this->m_hSprite,local_18,local_14,local_10);
      iVar6 = gHUD.m_scrinfo.iWidth / 2;
      iVar3 = (*gEngfuncs.pfnSPR_Width)(this->m_hSprite,2);
      iVar4 = gHUD.m_scrinfo.iHeight / 2;
      iVar5 = (*gEngfuncs.pfnSPR_Height)(this->m_hSprite,2);
      (*gEngfuncs.pfnSPR_DrawAdditive)(2,iVar6 - iVar3 / 2,iVar4 + iVar5 * 2,(rect_s *)0x0);
      fVar1 = this->m_fAttackRear - fVar2;
      if (fVar1 <= 0.0) {
        fVar1 = 0.0;
      }
      this->m_fAttackRear = fVar1;
    }
    fVar1 = this->m_fAttackLeft;
    if (fVar1 <= 0.4) {
      this->m_fAttackLeft = 0.0;
      return 1;
    }
                    /* Unresolved local var: int iHealth@[???] */
    if (this->m_iHealth < 0x1a) {
      local_18 = 0xfa;
      local_14 = 0;
    }
    else {
      local_18 = 0xff;
      local_14 = 0xa0;
    }
    local_10 = 0;
    iVar3 = 0x7f;
    if (0.5 <= fVar1) {
      iVar3 = (int)(fVar1 * 255.0);
    }
    ScaleColors(&local_18,&local_14,&local_10,iVar3);
    (*gEngfuncs.pfnSPR_Set)(this->m_hSprite,local_18,local_14,local_10);
    iVar5 = gHUD.m_scrinfo.iWidth / 2;
    iVar3 = (*gEngfuncs.pfnSPR_Width)(this->m_hSprite,3);
    iVar6 = gHUD.m_scrinfo.iHeight / 2;
    iVar4 = (*gEngfuncs.pfnSPR_Height)(this->m_hSprite,3);
    (*gEngfuncs.pfnSPR_DrawAdditive)(3,iVar5 + iVar3 * -3,iVar6 - iVar4 / 2,(rect_s *)0x0);
    fVar2 = this->m_fAttackLeft - fVar2;
    if (fVar2 <= 0.0) {
      fVar2 = 0.0;
    }
    this->m_fAttackLeft = fVar2;
  }
  return 1;
}


// CHudHealth::DrawDamage  @ 0006c1a0  (line 368)

/* DWARF original prototype: int DrawDamage(CHudHealth * this, float flTime) */

int __thiscall CHudHealth::DrawDamage(CHudHealth *this,float flTime)

{
  uint uVar1;
  float fVar2;
  int in_EAX;
  float *pfVar3;
  int iVar4;
  HANDLE_SPRITE HVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  double dVar9;
  int local_28;
  int local_24;
  int local_20 [4];
  
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: DAMAGE_IMAGE * pdmg@[???]
                       Unresolved local var: int i@[???] */
  local_28 = 0xff;
  local_24 = 0xa0;
  local_20[0] = 0;
  dVar9 = sin((double)((float)this + (float)this));
  if (dVar9 <= 0.0) {
    dVar9 = 0.0 - dVar9;
  }
  iVar8 = 0;
  piVar7 = (int *)(in_EAX + 0x48);
  ScaleColors(&local_28,&local_24,local_20,(int)(dVar9 * 256.0));
  uVar6 = *(uint *)(in_EAX + 0xfc);
  do {
    if ((giDmgFlags[iVar8] & uVar6) != 0) {
      iVar4 = iVar8 + *(int *)(in_EAX + 0x18);
      if (iVar4 < 0) {
        HVar5 = 0;
      }
      else {
        HVar5 = gHUD.m_rghSprites[iVar4];
      }
      (*gEngfuncs.pfnSPR_Set)(HVar5,local_28,local_24,local_20[0]);
      (*gEngfuncs.pfnSPR_DrawAdditive)
                (0,piVar7[-1],*piVar7,gHUD.m_rgrcRects + *(int *)(in_EAX + 0x18) + iVar8);
      uVar6 = *(uint *)(in_EAX + 0xfc);
    }
    iVar4 = giDmgHeight;
    iVar8 = iVar8 + 1;
    piVar7 = piVar7 + 4;
  } while (iVar8 != 0xc);
                    /* Unresolved local var: DAMAGE_IMAGE * pdmg@[???]
                       Unresolved local var: int y@[???]
                       Unresolved local var: int j@[???] */
  piVar7 = giDmgFlags;
  pfVar3 = (float *)(in_EAX + 0x3c);
  do {
    uVar1 = *piVar7;
    if ((uVar1 & uVar6) != 0) {
      fVar2 = (float)this + 2.0;
      if (*pfVar3 < (float)this + 2.0) {
        fVar2 = *pfVar3;
      }
      if (((float)this < fVar2) || (0x27 < (int)(dVar9 * 256.0))) {
        *pfVar3 = fVar2;
      }
      else {
        *pfVar3 = 0.0;
        fVar2 = pfVar3[3];
        pfVar3[2] = 0.0;
        pfVar3[3] = 0.0;
        iVar8 = *(int *)(in_EAX + 0x48);
        if ((iVar8 != 0) && (iVar8 < (int)fVar2)) {
          *(int *)(in_EAX + 0x48) = iVar8 + iVar4;
        }
        iVar8 = *(int *)(in_EAX + 0x58);
        if ((iVar8 < (int)fVar2) && (iVar8 != 0)) {
          *(int *)(in_EAX + 0x58) = iVar8 + iVar4;
        }
        iVar8 = *(int *)(in_EAX + 0x68);
        if ((iVar8 != 0) && (iVar8 < (int)fVar2)) {
          *(int *)(in_EAX + 0x68) = iVar8 + iVar4;
        }
        iVar8 = *(int *)(in_EAX + 0x78);
        if ((iVar8 < (int)fVar2) && (iVar8 != 0)) {
          *(int *)(in_EAX + 0x78) = iVar8 + iVar4;
        }
        iVar8 = *(int *)(in_EAX + 0x88);
        if ((iVar8 != 0) && (iVar8 < (int)fVar2)) {
          *(int *)(in_EAX + 0x88) = iVar8 + iVar4;
        }
        iVar8 = *(int *)(in_EAX + 0x98);
        if ((iVar8 < (int)fVar2) && (iVar8 != 0)) {
          *(int *)(in_EAX + 0x98) = iVar8 + iVar4;
        }
        iVar8 = *(int *)(in_EAX + 0xa8);
        if ((iVar8 < (int)fVar2) && (iVar8 != 0)) {
          *(int *)(in_EAX + 0xa8) = iVar8 + iVar4;
        }
        iVar8 = *(int *)(in_EAX + 0xb8);
        if ((iVar8 < (int)fVar2) && (iVar8 != 0)) {
          *(int *)(in_EAX + 0xb8) = iVar8 + iVar4;
        }
        iVar8 = *(int *)(in_EAX + 200);
        if ((iVar8 < (int)fVar2) && (iVar8 != 0)) {
          *(int *)(in_EAX + 200) = iVar8 + iVar4;
        }
        iVar8 = *(int *)(in_EAX + 0xd8);
        if ((iVar8 != 0) && (iVar8 < (int)fVar2)) {
          *(int *)(in_EAX + 0xd8) = iVar8 + iVar4;
        }
        iVar8 = *(int *)(in_EAX + 0xe8);
        if ((iVar8 < (int)fVar2) && (iVar8 != 0)) {
          *(int *)(in_EAX + 0xe8) = iVar8 + iVar4;
        }
        iVar8 = *(int *)(in_EAX + 0xf8);
        if ((iVar8 != 0) && (iVar8 < (int)fVar2)) {
          *(int *)(in_EAX + 0xf8) = iVar8 + iVar4;
        }
        uVar6 = uVar6 & ~uVar1;
        *(uint *)(in_EAX + 0xfc) = uVar6;
      }
    }
    pfVar3 = pfVar3 + 4;
    piVar7 = piVar7 + 1;
  } while ((float *)(in_EAX + 0xfc) != pfVar3);
  return (int)pfVar3;
}


// CHudHealth::DrawDamage  @ 0006d5c0  (line 369)

/* DWARF original prototype: int DrawDamage(CHudHealth * this, float flTime) */

int __thiscall CHudHealth::DrawDamage(CHudHealth *this,float flTime)

{
  float in_stack_ffffffe8;
  
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int a@[???]
                       Unresolved local var: DAMAGE_IMAGE * pdmg@[???]
                       Unresolved local var: int i@[???] */
  if (this->m_bitsDamage != 0) {
    DrawDamage((CHudHealth *)flTime,in_stack_ffffffe8);
  }
  return 1;
}


// CHudHealth::UpdateTiles  @ 0006d5f0  (line 431)

/* DWARF original prototype: void UpdateTiles(CHudHealth * this, float flTime, long bitsDamage) */

void __thiscall CHudHealth::UpdateTiles(CHudHealth *this,float flTime,long bitsDamage)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  DAMAGE_IMAGE *pDVar6;
  int iVar7;
  
                    /* Unresolved local var: DAMAGE_IMAGE * pdmg@[???]
                       Unresolved local var: long bitsOn@[???] */
  iVar3 = giDmgHeight;
                    /* Unresolved local var: int i@[???] */
  uVar1 = this->m_bitsDamage;
  iVar4 = giDmgWidth + 7;
  if (-1 < giDmgWidth) {
    iVar4 = giDmgWidth;
  }
  pDVar6 = this->m_dmg;
  iVar5 = 0;
  do {
    uVar2 = giDmgFlags[iVar5];
    if (((uVar1 & uVar2) != 0) && (pDVar6->fExpire = flTime + 2.0, pDVar6->fBaseline == 0.0)) {
      pDVar6->fBaseline = flTime;
    }
    if ((~uVar1 & bitsDamage & uVar2) == 0) {
LAB_0006d7b3:
      if (iVar5 == 0xb) goto LAB_0006d7c6;
    }
    else {
      pDVar6->x = iVar4 >> 3;
      iVar7 = gHUD.m_scrinfo.iHeight + iVar3 * -2;
                    /* Unresolved local var: int j@[???] */
      pDVar6->fExpire = flTime + 2.0;
      pDVar6->y = iVar7;
      if (iVar5 != 0) {
        iVar7 = this->m_dmg[0].y;
        if (iVar7 != 0) {
          this->m_dmg[0].y = iVar7 - iVar3;
        }
        if (iVar5 != 1) {
          iVar7 = this->m_dmg[1].y;
          if (iVar7 != 0) goto LAB_0006d6b4;
          goto LAB_0006d6b9;
        }
        iVar7 = this->m_dmg[2].y;
        if (iVar7 != 0) goto LAB_0006d6c9;
        iVar7 = this->m_dmg[3].y;
        if (iVar7 != 0) goto LAB_0006d6de;
LAB_0006d6ec:
        iVar7 = this->m_dmg[4].y;
        if (iVar7 != 0) {
LAB_0006d6f6:
          this->m_dmg[4].y = iVar7 - iVar3;
        }
        if (iVar5 == 5) {
          iVar7 = this->m_dmg[6].y;
          if (iVar7 != 0) {
LAB_0006d72c:
            this->m_dmg[6].y = iVar7 - iVar3;
            goto LAB_0006d734;
          }
          iVar7 = this->m_dmg[7].y;
          if (iVar7 != 0) goto LAB_0006d747;
          goto LAB_0006d758;
        }
LAB_0006d707:
        iVar7 = this->m_dmg[5].y;
        if (iVar7 != 0) {
LAB_0006d711:
          this->m_dmg[5].y = iVar7 - iVar3;
        }
        if (iVar5 == 6) {
          iVar7 = this->m_dmg[7].y;
          if (iVar7 != 0) goto LAB_0006d747;
          iVar7 = this->m_dmg[8].y;
          if (iVar7 != 0) goto LAB_0006d762;
          goto LAB_0006d773;
        }
LAB_0006d722:
        iVar7 = this->m_dmg[6].y;
        if (iVar7 != 0) goto LAB_0006d72c;
LAB_0006d734:
        if (iVar5 != 7) goto LAB_0006d73d;
        iVar7 = this->m_dmg[8].y;
        if (iVar7 != 0) goto LAB_0006d762;
        iVar7 = this->m_dmg[9].y;
        if (iVar7 != 0) goto LAB_0006d77d;
LAB_0006d78a:
        iVar7 = this->m_dmg[10].y;
        if (iVar7 != 0) {
LAB_0006d794:
          this->m_dmg[10].y = iVar7 - iVar3;
        }
        if (iVar5 != 0xb) {
LAB_0006d7a1:
          iVar7 = this->m_dmg[0xb].y;
          if (iVar7 != 0) {
LAB_0006d7ab:
            this->m_dmg[0xb].y = iVar7 - iVar3;
          }
          goto LAB_0006d7b3;
        }
LAB_0006d7c6:
        this->m_bitsDamage = uVar1 | bitsDamage;
        return;
      }
      iVar7 = this->m_dmg[1].y;
      if (iVar7 != 0) {
LAB_0006d6b4:
        this->m_dmg[1].y = iVar7 - iVar3;
LAB_0006d6b9:
        if (iVar5 != 2) {
          iVar7 = this->m_dmg[2].y;
          if (iVar7 != 0) goto LAB_0006d6c9;
          goto LAB_0006d6ce;
        }
        iVar7 = this->m_dmg[3].y;
        if (iVar7 != 0) goto LAB_0006d6de;
        iVar7 = this->m_dmg[4].y;
        if (iVar7 != 0) goto LAB_0006d6f6;
        goto LAB_0006d707;
      }
      iVar7 = this->m_dmg[2].y;
      if (iVar7 != 0) {
LAB_0006d6c9:
        this->m_dmg[2].y = iVar7 - iVar3;
LAB_0006d6ce:
        if (iVar5 != 3) goto LAB_0006d6d7;
        iVar7 = this->m_dmg[4].y;
        if (iVar7 != 0) goto LAB_0006d6f6;
        iVar7 = this->m_dmg[5].y;
        if (iVar7 != 0) goto LAB_0006d711;
        goto LAB_0006d722;
      }
LAB_0006d6d7:
      iVar7 = this->m_dmg[3].y;
      if (iVar7 != 0) {
LAB_0006d6de:
        this->m_dmg[3].y = iVar7 - iVar3;
      }
      if (iVar5 != 4) goto LAB_0006d6ec;
      iVar7 = this->m_dmg[5].y;
      if (iVar7 != 0) goto LAB_0006d711;
      iVar7 = this->m_dmg[6].y;
      if (iVar7 != 0) goto LAB_0006d72c;
LAB_0006d73d:
      iVar7 = this->m_dmg[7].y;
      if (iVar7 != 0) {
LAB_0006d747:
        this->m_dmg[7].y = iVar7 - iVar3;
      }
      if (iVar5 == 8) {
        iVar7 = this->m_dmg[9].y;
        if (iVar7 != 0) {
LAB_0006d77d:
          this->m_dmg[9].y = iVar7 - iVar3;
          goto LAB_0006d785;
        }
LAB_0006d813:
        iVar7 = this->m_dmg[10].y;
        if (iVar7 != 0) goto LAB_0006d794;
        goto LAB_0006d7a1;
      }
LAB_0006d758:
      iVar7 = this->m_dmg[8].y;
      if (iVar7 != 0) {
LAB_0006d762:
        this->m_dmg[8].y = iVar7 - iVar3;
      }
      if (iVar5 == 9) goto LAB_0006d813;
LAB_0006d773:
      iVar7 = this->m_dmg[9].y;
      if (iVar7 != 0) goto LAB_0006d77d;
LAB_0006d785:
      if (iVar5 != 10) goto LAB_0006d78a;
      iVar7 = this->m_dmg[0xb].y;
      if (iVar7 != 0) goto LAB_0006d7ab;
    }
    iVar5 = iVar5 + 1;
    pDVar6 = pDVar6 + 1;
  } while( true );
}


