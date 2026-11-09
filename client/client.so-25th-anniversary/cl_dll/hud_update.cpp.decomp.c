// Ghidra decompilation of functions from cl_dll/hud_update.cpp
// 1 functions, ordered by original source line

// CHud::UpdateClientData  @ 00070840  (line 33)

/* DWARF original prototype: int UpdateClientData(CHud * this, client_data_t * cdata, float time) */

int __thiscall CHud::UpdateClientData(CHud *this,client_data_t *cdata,float time)

{
  int iVar1;
  
  (this->m_vecOrigin).x = (cdata->origin).x;
  (this->m_vecOrigin).y = (cdata->origin).y;
  (this->m_vecOrigin).z = (cdata->origin).z;
  (this->m_vecAngles).x = (cdata->viewangles).x;
  (this->m_vecAngles).y = (cdata->viewangles).y;
  (this->m_vecAngles).z = (cdata->viewangles).z;
  iVar1 = CL_ButtonBits(0);
  this->m_iKeyBits = iVar1;
  this->m_iWeaponBits = cdata->iWeaponBits;
  in_fov = cdata->fov;
  Think(this);
  cdata->fov = (float)this->m_iFOV;
  v_idlescale = (float)this->m_iConcussionEffect;
  CL_ResetButtonBits(this->m_iKeyBits);
  return 1;
}


