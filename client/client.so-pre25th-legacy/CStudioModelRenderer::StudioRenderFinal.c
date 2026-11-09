// CStudioModelRenderer::StudioRenderFinal_Hardware  @ 000a11f0
/* DWARF original prototype: void StudioRenderFinal_Hardware(CStudioModelRenderer * this) */

void __thiscall CStudioModelRenderer::StudioRenderFinal_Hardware(CStudioModelRenderer *this)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: int rendermode@[???] */
  iVar3 = 5;
  iVar2 = (*IEngineStudio.GetForceFaceFlags)();
  if (iVar2 == 0) {
    iVar3 = (this->m_pCurrentEntity->curstate).rendermode;
  }
  (*IEngineStudio.SetupRenderer)(iVar3);
  fVar1 = this->m_pCvarDrawEntities->value;
  if (fVar1 == 2.0) {
    (*IEngineStudio.StudioDrawBones)();
    fVar1 = this->m_pCvarDrawEntities->value;
  }
  else if (fVar1 == 3.0) {
    (*IEngineStudio.StudioDrawHulls)();
    fVar1 = this->m_pCvarDrawEntities->value;
  }
  else if (0 < this->m_pStudioHeader->numbodyparts) {
    iVar2 = 0;
    do {
      (*IEngineStudio.StudioSetupModel)(iVar2,&this->m_pBodyPart,&this->m_pSubModel);
      if (this->m_fDoInterp != 0) {
        this->m_pCurrentEntity->trivial_accept = 0;
      }
      iVar2 = iVar2 + 1;
      (*IEngineStudio.GL_SetRenderMode)(iVar3);
      (*IEngineStudio.StudioDrawPoints)();
      (*IEngineStudio.GL_StudioDrawShadow)();
    } while (iVar2 < this->m_pStudioHeader->numbodyparts);
    fVar1 = this->m_pCvarDrawEntities->value;
  }
  if (fVar1 != 4.0) {
                    /* WARNING: Could not recover jumptable at 0x000a12d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*IEngineStudio.RestoreRenderer)();
    return;
  }
  (*(gEngfuncs.pTriAPI)->RenderMode)(5);
  (*IEngineStudio.StudioDrawHulls)();
  (*(gEngfuncs.pTriAPI)->RenderMode)(0);
                    /* WARNING: Could not recover jumptable at 0x000a1312. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*IEngineStudio.RestoreRenderer)();
  return;
}


// CStudioModelRenderer::StudioRenderFinal_Software  @ 000a10b0
/* DWARF original prototype: void StudioRenderFinal_Software(CStudioModelRenderer * this) */

void __thiscall CStudioModelRenderer::StudioRenderFinal_Software(CStudioModelRenderer *this)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  (*IEngineStudio.SetupRenderer)(0);
  fVar1 = this->m_pCvarDrawEntities->value;
  if (fVar1 == 2.0) {
    (*IEngineStudio.StudioDrawBones)();
    fVar1 = this->m_pCvarDrawEntities->value;
  }
  else if (fVar1 == 3.0) {
    (*IEngineStudio.StudioDrawHulls)();
    fVar1 = this->m_pCvarDrawEntities->value;
  }
  else if (0 < this->m_pStudioHeader->numbodyparts) {
    iVar2 = 0;
    do {
      iVar3 = iVar2 + 1;
      (*IEngineStudio.StudioSetupModel)(iVar2,&this->m_pBodyPart,&this->m_pSubModel);
      (*IEngineStudio.StudioDrawPoints)();
      iVar2 = iVar3;
    } while (iVar3 < this->m_pStudioHeader->numbodyparts);
    fVar1 = this->m_pCvarDrawEntities->value;
  }
  if (fVar1 == 4.0) {
    (*(gEngfuncs.pTriAPI)->RenderMode)(5);
    (*IEngineStudio.StudioDrawHulls)();
    (*(gEngfuncs.pTriAPI)->RenderMode)(0);
    fVar1 = this->m_pCvarDrawEntities->value;
  }
  if (fVar1 != 5.0) {
                    /* WARNING: Could not recover jumptable at 0x000a1161. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*IEngineStudio.RestoreRenderer)();
    return;
  }
  (*IEngineStudio.StudioDrawAbsBBox)();
                    /* WARNING: Could not recover jumptable at 0x000a117c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*IEngineStudio.RestoreRenderer)();
  return;
}


