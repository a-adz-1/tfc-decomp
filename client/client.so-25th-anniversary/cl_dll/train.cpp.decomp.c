// Ghidra decompilation of functions from cl_dll/train.cpp
// 5 functions, ordered by original source line

// __MsgFunc_Train  @ 00082820  (line 27)

int __MsgFunc_Train(char *pszName,int iSize,void *pbuf)

{
  BEGIN_READ(pbuf,iSize);
  gHUD.m_Train.m_iPos = READ_BYTE();
  if (gHUD.m_Train.m_iPos == 0) {
    gHUD.m_Train.super_CHudBase.m_iFlags = gHUD.m_Train.super_CHudBase.m_iFlags & 0xfffffffe;
    return 1;
  }
  gHUD.m_Train.super_CHudBase.m_iFlags = gHUD.m_Train.super_CHudBase.m_iFlags | 1;
  return 1;
}


// CHudTrain::Init  @ 000826e0  (line 31)

/* DWARF original prototype: int Init(CHudTrain * this) */

int __thiscall CHudTrain::Init(CHudTrain *this)

{
  (*gEngfuncs.pfnHookUserMsg)("Train",__MsgFunc_Train);
  this->m_iPos = 0;
  (this->super_CHudBase).m_iFlags = 0;
  CHud::AddHudElem(&gHUD,&this->super_CHudBase);
  return 1;
}


// CHudTrain::VidInit  @ 000826c0  (line 43)

/* DWARF original prototype: int VidInit(CHudTrain * this) */

int __thiscall CHudTrain::VidInit(CHudTrain *this)

{
  this->m_hSprite = 0;
  return 1;
}


// CHudTrain::Draw  @ 00082730  (line 49)

/* DWARF original prototype: int Draw(CHudTrain * this, float fTime) */

int __thiscall CHudTrain::Draw(CHudTrain *this,float fTime)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = this->m_hSprite;
  if (iVar2 == 0) {
    iVar2 = LoadSprite("sprites/%d_train.spr");
    this->m_hSprite = iVar2;
  }
  if (this->m_iPos != 0) {
                    /* Unresolved local var: int r@[???]
                       Unresolved local var: int g@[???]
                       Unresolved local var: int b@[???]
                       Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
    (*gEngfuncs.pfnSPR_Set)(iVar2,0xff,0xa0,0);
    iVar2 = gHUD.m_scrinfo.iHeight;
    iVar1 = (*gEngfuncs.pfnSPR_Height)(this->m_hSprite,0);
    iVar3 = (iVar2 - iVar1) - gHUD.m_iFontHeight;
    iVar2 = gHUD.m_scrinfo.iWidth / 3;
    iVar1 = (*gEngfuncs.pfnSPR_Width)(this->m_hSprite,0);
    if (iVar1 < 0) {
      iVar1 = iVar1 + 3;
    }
    (*gEngfuncs.pfnSPR_DrawAdditive)(this->m_iPos + -1,iVar2 + (iVar1 >> 2),iVar3,(rect_s *)0x0);
  }
  return 1;
}


// CHudTrain::MsgFunc_Train  @ 00082880  (line 73)

/* DWARF original prototype: int MsgFunc_Train(CHudTrain * this, char * pszName, int iSize, void *
   pbuf) */

int __thiscall CHudTrain::MsgFunc_Train(CHudTrain *this,char *pszName,int iSize,void *pbuf)

{
  uint uVar1;
  int iVar2;
  
  BEGIN_READ(pbuf,iSize);
  iVar2 = READ_BYTE();
  this->m_iPos = iVar2;
  uVar1 = (this->super_CHudBase).m_iFlags;
  if (iVar2 == 0) {
    (this->super_CHudBase).m_iFlags = uVar1 & 0xfffffffe;
    return 1;
  }
  (this->super_CHudBase).m_iFlags = uVar1 | 1;
  return 1;
}


