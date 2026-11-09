// Ghidra decompilation of functions from cl_dll/geiger.cpp
// 5 functions, ordered by original source line

// __MsgFunc_Geiger  @ 0006bc70  (line 29)

int __MsgFunc_Geiger(char *pszName,int iSize,void *pbuf)

{
  int iVar1;
  
  BEGIN_READ(pbuf,iSize);
  iVar1 = READ_BYTE();
  gHUD.m_Geiger.super_CHudBase.m_iFlags = gHUD.m_Geiger.super_CHudBase.m_iFlags | 1;
  gHUD.m_Geiger.m_iGeigerRange = iVar1 << 2;
  return 1;
}


// CHudGeiger::Init  @ 0006bc10  (line 32)

/* DWARF original prototype: int Init(CHudGeiger * this) */

int __thiscall CHudGeiger::Init(CHudGeiger *this)

{
  uint __seed;
  
  (*gEngfuncs.pfnHookUserMsg)("Geiger",__MsgFunc_Geiger);
  this->m_iGeigerRange = 0;
  (this->super_CHudBase).m_iFlags = 0;
  CHud::AddHudElem(&gHUD,&this->super_CHudBase);
  __seed = ::time((time_t *)0x0);
  srand(__seed);
  return 1;
}


// CHudGeiger::VidInit  @ 0006bc00  (line 48)

/* DWARF original prototype: int VidInit(CHudGeiger * this) */

int __thiscall CHudGeiger::VidInit(CHudGeiger *this)

{
  return 1;
}


// CHudGeiger::MsgFunc_Geiger  @ 0006bf40  (line 51)

/* DWARF original prototype: int MsgFunc_Geiger(CHudGeiger * this, char * pszName, int iSize, void *
   pbuf) */

int __thiscall CHudGeiger::MsgFunc_Geiger(CHudGeiger *this,char *pszName,int iSize,void *pbuf)

{
  int *piVar1;
  int iVar2;
  
  BEGIN_READ(pbuf,iSize);
  iVar2 = READ_BYTE();
  piVar1 = &(this->super_CHudBase).m_iFlags;
  *piVar1 = *piVar1 | 1;
  this->m_iGeigerRange = iVar2 << 2;
  return 1;
}


// CHudGeiger::Draw  @ 0006bcb0  (line 65)

/* DWARF original prototype: int Draw(CHudGeiger * this, float flTime) */

int __thiscall CHudGeiger::Draw(CHudGeiger *this,float flTime)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int in_GS_OFFSET;
  float local_120;
  char local_110 [256];
  int local_10;
  
                    /* Unresolved local var: int pct@[???]
                       Unresolved local var: float flvol@[???]
                       Unresolved local var: int[3] rg@[???]
                       Unresolved local var: int i@[???] */
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = this->m_iGeigerRange;
  if (iVar1 - 1U < 999) {
    if (iVar1 < 0x321) {
      if (iVar1 < 0x259) {
        if (iVar1 < 0x1f5) {
          if (iVar1 < 0x191) {
            if (iVar1 < 0x12d) {
              if (iVar1 < 0xc9) {
                if (iVar1 < 0x97) {
                  if (iVar1 < 0x65) {
                    if (iVar1 < 0x4c) {
                      iVar5 = 2;
                      if (iVar1 < 0x33) {
                        uVar4 = 0x5f;
                        local_120 = 1.0;
                      }
                      else {
                        uVar4 = 0x5a;
                        local_120 = 0.95;
                      }
                    }
                    else {
                      iVar5 = 3;
                      uVar4 = 0x50;
                      local_120 = 0.9;
                    }
                  }
                  else {
                    iVar5 = 3;
                    uVar4 = 0x3c;
                    local_120 = 0.85;
                  }
                }
                else {
                  iVar5 = 3;
                  uVar4 = 0x28;
                  local_120 = 0.8;
                }
              }
              else {
                iVar5 = 3;
                uVar4 = 0x1c;
                local_120 = 0.78;
              }
            }
            else {
              iVar5 = 3;
              uVar4 = 8;
              local_120 = 0.7;
            }
          }
          else {
            iVar5 = 3;
            uVar4 = 8;
            local_120 = 0.6;
          }
        }
        else {
          iVar5 = 2;
          uVar4 = 4;
          local_120 = 0.5;
        }
      }
      else {
        iVar5 = 2;
        uVar4 = 2;
        local_120 = 0.4;
      }
      uVar2 = rand();
      uVar3 = rand();
      if (((uVar3 & 0x7f) < uVar4) || (uVar3 = rand(), (uVar3 & 0x7f) < uVar4)) {
                    /* Unresolved local var: char[256] sz@[???]
                       Unresolved local var: int j@[???] */
        uVar4 = rand();
        uVar4 = uVar4 & 1;
        if (iVar5 == 3) {
          uVar3 = rand();
          uVar4 = uVar4 + (uVar3 & 1);
        }
        __sprintf_chk(local_110,1,0x100,"player/geiger%d.wav",uVar4 + 1);
        (*gEngfuncs.pfnPlaySoundByName)
                  (local_110,((float)(uVar2 & 0x7f) * local_120) / 255.0 + 0.25);
      }
    }
    else {
      rand();
      rand();
      rand();
    }
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}


