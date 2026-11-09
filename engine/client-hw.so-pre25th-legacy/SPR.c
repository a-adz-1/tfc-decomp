// SPR_DisableScissor  @ 0018fe10
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SPR_DisableScissor(void)

{
  (*g_engdstAddrs.pfnSPR_DisableScissor)();
  DisableScissorTest();
  return;
}


// SPR_Draw  @ 0018fac0
void SPR_Draw(int frame,int x,int y,wrect_t *prc)

{
  mspriteframe_t *pFrame;
  
                    /* Unresolved local var: mspriteframe_t * pFrame@[???] */
  (*g_engdstAddrs.pfnSPR_Draw)(&frame,&x,&y,&prc);
  if (((gpSprite != (msprite_t *)0x0) && (x < (int)vid.width)) && (y < (int)vid.height)) {
    pFrame = R_GetSpriteFrame(gpSprite,frame);
    if (pFrame != (mspriteframe_t *)0x0) {
      Draw_SpriteFrame(pFrame,gSpritePalette,x,y,prc);
      return;
    }
    Con_DPrintf("Client.dll SPR_Draw error:  invalid frame\n");
  }
  return;
}


// SPR_DrawAdditive  @ 0018fc20
void SPR_DrawAdditive(int frame,int x,int y,wrect_t *prc)

{
  mspriteframe_t *pFrame;
  
                    /* Unresolved local var: mspriteframe_t * pFrame@[???] */
  (*g_engdstAddrs.pfnSPR_DrawAdditive)(&frame,&x,&y,&prc);
  if (((gpSprite != (msprite_t *)0x0) && (x < (int)vid.width)) && (y < (int)vid.height)) {
    pFrame = R_GetSpriteFrame(gpSprite,frame);
    if (pFrame != (mspriteframe_t *)0x0) {
      Draw_SpriteFrameAdditive(pFrame,gSpritePalette,x,y,prc);
      return;
    }
    Con_DPrintf("Client.dll SPR_DrawAdditive error:  invalid frame\n");
  }
  return;
}


// SPR_DrawGeneric  @ 0018fcd0
void SPR_DrawGeneric(int frame,int x,int y,wrect_t *prc,int src,int dest,int width,int height)

{
  mspriteframe_t *pFrame;
  
                    /* Unresolved local var: mspriteframe_t * pFrame@[???] */
  (*g_engdstAddrs.pfnSPR_DrawGeneric)(&frame,&x,&y,&prc,&src,&dest,&width,&height);
  if (((gpSprite != (msprite_t *)0x0) && (x < (int)vid.width)) && (y < (int)vid.height)) {
    pFrame = R_GetSpriteFrame(gpSprite,frame);
    if (pFrame != (mspriteframe_t *)0x0) {
      Draw_SpriteFrameGeneric(pFrame,gSpritePalette,x,y,prc,src,dest,width,height);
      return;
    }
    Con_DPrintf("Client.dll SPR_DrawGeneric error: invalid frame\n");
  }
  return;
}


// SPR_DrawHoles  @ 0018fb70
void SPR_DrawHoles(int frame,int x,int y,wrect_t *prc)

{
  mspriteframe_t *pFrame;
  
                    /* Unresolved local var: mspriteframe_t * pFrame@[???] */
  (*g_engdstAddrs.pfnSPR_DrawHoles)(&frame,&x,&y,&prc);
  if (((gpSprite != (msprite_t *)0x0) && (x < (int)vid.width)) && (y < (int)vid.height)) {
    pFrame = R_GetSpriteFrame(gpSprite,frame);
    if (pFrame != (mspriteframe_t *)0x0) {
      Draw_SpriteFrameHoles(pFrame,gSpritePalette,x,y,prc);
      return;
    }
    Con_DPrintf("Client.dll SPR_DrawHoles error:  invalid frame\n");
  }
  return;
}


// SPR_EnableScissor  @ 0018fdc0
void SPR_EnableScissor(int x,int y,int width,int height)

{
  (*g_engdstAddrs.pfnSPR_EnableScissor)(&x,&y,&width,&height);
  EnableScissorTest(x,y,width,height);
  return;
}


// SPR_Frames  @ 0018f7f0
int SPR_Frames(HSPRITE hSprite)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: SPRITELIST * pList@[DW_OP_reg2(EDX)] */
  (*g_engdstAddrs.pfnSPR_Frames)(&hSprite);
                    /* Unresolved local var: int spriteIndex@[???] */
  iVar1 = 0;
  iVar2 = hSprite + -1;
  if (((-1 < iVar2) && (iVar2 < gSpriteCount)) && (gSpriteList + iVar2 != (SPRITELIST *)0x0)) {
    iVar1 = gSpriteList[iVar2].frameCount;
  }
  return iVar1;
}


// SPR_Get  @ 0018f750
SPRITELIST * SPR_Get(HSPRITE hSprite)

{
  SPRITELIST *pSVar1;
  int iVar2;
  
                    /* Unresolved local var: int spriteIndex@[???] */
  pSVar1 = (SPRITELIST *)0x0;
  iVar2 = hSprite + -1;
  if ((-1 < iVar2) && (iVar2 < gSpriteCount)) {
    pSVar1 = gSpriteList + iVar2;
  }
  return pSVar1;
}


// SPR_GetList  @ 001be9e0
/* WARNING: Variable defined which should be unmapped: iCount */

client_sprite_t * SPR_GetList(char *psz,int *piCount)

{
  byte *data;
  char *pcVar1;
  long lVar2;
  long lVar3;
  client_sprite_t *dest;
  int iVar4;
  client_sprite_t *local_20;
  int iCount;
  
                    /* Unresolved local var: char * pfile@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: client_sprite_t * ps@[???]
                       Unresolved local var: client_sprite_t * pret@[???] */
  (*g_engdstAddrs.pfnSPR_GetList)(&psz,&piCount);
  data = COM_LoadFile(psz,2,(int *)0x0);
  local_20 = (client_sprite_t *)0x0;
  if (data != (byte *)0x0) {
    pcVar1 = COM_Parse((char *)data);
    lVar2 = strtol(com_token,(char **)0x0,10);
    if (lVar2 != 0) {
      local_20 = calloc(lVar2 * 0x98,1);
      if (local_20 != (client_sprite_t *)0x0) {
        if (0 < lVar2) {
          iVar4 = 0;
          dest = local_20;
          do {
            iVar4 = iVar4 + 1;
            pcVar1 = COM_Parse(pcVar1);
            Q_strncpy(dest->szName,com_token,0x3f);
            dest->szName[0x3f] = '\0';
            pcVar1 = COM_Parse(pcVar1);
            lVar3 = strtol(com_token,(char **)0x0,10);
            dest->iRes = lVar3;
            pcVar1 = COM_Parse(pcVar1);
            Q_strncpy(dest->szSprite,com_token,0x3f);
            dest->szSprite[0x3f] = '\0';
            pcVar1 = COM_Parse(pcVar1);
            lVar3 = strtol(com_token,(char **)0x0,10);
            (dest->rc).left = lVar3;
            pcVar1 = COM_Parse(pcVar1);
            lVar3 = strtol(com_token,(char **)0x0,10);
            (dest->rc).top = lVar3;
            pcVar1 = COM_Parse(pcVar1);
            lVar3 = strtol(com_token,(char **)0x0,10);
            (dest->rc).right = lVar3 + (dest->rc).left;
            pcVar1 = COM_Parse(pcVar1);
            lVar3 = strtol(com_token,(char **)0x0,10);
            (dest->rc).bottom = lVar3 + (dest->rc).top;
            dest = dest + 1;
          } while (iVar4 != lVar2);
        }
        if (piCount != (int *)0x0) {
          *piCount = lVar2;
        }
      }
    }
  }
  return local_20;
}


// SPR_GetModelPointer  @ 0018f770
model_s * SPR_GetModelPointer(HSPRITE hSprite)

{
  model_t *pmVar1;
  int iVar2;
  
                    /* Unresolved local var: SPRITELIST * pList@[DW_OP_reg2(EDX)] */
                    /* Unresolved local var: int spriteIndex@[???] */
  pmVar1 = (model_s *)0x0;
  iVar2 = hSprite + -1;
  if (((-1 < iVar2) && (iVar2 < gSpriteCount)) && (gSpriteList + iVar2 != (SPRITELIST *)0x0)) {
    pmVar1 = gSpriteList[iVar2].pSprite;
  }
  return pmVar1;
}


// SPR_Height  @ 0018f890
int SPR_Height(HSPRITE hSprite,int frame)

{
  int iVar1;
  mspriteframe_t *pmVar2;
  int iVar3;
  
                    /* Unresolved local var: mspriteframe_t * pFrame@[???]
                       Unresolved local var: SPRITELIST * pList@[DW_OP_reg2(EDX)]
                       Unresolved local var: msprite_t * pSprite@[???] */
                    /* Unresolved local var: int spriteIndex@[???] */
  iVar3 = 0;
  (*g_engdstAddrs.pfnSPR_Height)(&hSprite,&frame);
  iVar1 = hSprite + -1;
  if (((-1 < iVar1) && (iVar1 < gSpriteCount)) && (gSpriteList + iVar1 != (SPRITELIST *)0x0)) {
    pmVar2 = R_GetSpriteFrame(((gSpriteList[iVar1].pSprite)->cache).data,frame);
    if (pmVar2 != (mspriteframe_t *)0x0) {
      iVar3 = pmVar2->height;
    }
  }
  return iVar3;
}


// SPR_Init  @ 0018f7b0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SPR_Init(void)

{
                    /* Unresolved local var: int listSize@[???] */
  if (gSpriteList != (SPRITELIST *)0x0) {
    return;
  }
  ghCrosshair = 0;
  gSpriteCount = 0x100;
  gSpriteList = Mem_ZeroMalloc(0xc00);
  gpSprite = (msprite_t *)0x0;
  return;
}


// SPR_Load  @ 0018f4f0
HSPRITE SPR_Load(char *pTextureName)

{
  model_t **ppmVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  model_t *pmVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  
                    /* Unresolved local var: int i@[???] */
  (*g_engdstAddrs.pfnSPR_Load)(&pTextureName);
  iVar2 = 0;
  if (((pTextureName != (char *)0x0) && (gSpriteList != (SPRITELIST *)0x0)) && (0 < gSpriteCount)) {
    iVar2 = 0;
    iVar8 = 0;
    while( true ) {
      piVar7 = (int *)((int)&gSpriteList->pSprite + iVar2);
      if (*piVar7 == 0) {
        iVar3 = Q_strlen(pTextureName);
        pvVar4 = Mem_Malloc(iVar3 + 1);
        piVar7[1] = (int)pvVar4;
        Q_strcpy(*(char **)((int)&gSpriteList->pName + iVar2),pTextureName);
        piVar7 = (int *)((int)&gSpriteList->pSprite + iVar2);
      }
      iVar3 = Q_stricmp(pTextureName,(char *)piVar7[1]);
      if (iVar3 == 0) break;
      iVar8 = iVar8 + 1;
      iVar2 = iVar2 + 0xc;
      if (gSpriteCount <= iVar8) {
        Sys_Error("cannot allocate more than %d HUD sprites\n",0x100);
        return 0;
      }
    }
    gSpriteMipMap = false;
    ppmVar1 = &gSpriteList->pSprite;
    pmVar5 = Mod_ForName(pTextureName,false,true);
    *(model_t **)((int)ppmVar1 + iVar2) = pmVar5;
    gSpriteMipMap = true;
    puVar6 = (undefined4 *)((int)&gSpriteList->pSprite + iVar2);
    iVar2 = 0;
    pmVar5 = (model_t *)*puVar6;
    if (pmVar5 != (model_t *)0x0) {
      iVar2 = ModelFrameCount(pmVar5);
      puVar6[2] = iVar2;
      iVar2 = iVar8 + 1;
    }
  }
  return iVar2;
}


// SPR_Pointer  @ 0018f7a0
msprite_t * SPR_Pointer(SPRITELIST *pList)

{
  return (pList->pSprite->cache).data;
}


// SPR_Set  @ 0018f900
void SPR_Set(HSPRITE hSprite,int r,int g,int b)

{
  int iVar1;
  
                    /* Unresolved local var: SPRITELIST * pList@[DW_OP_reg0(EAX)] */
  (*g_engdstAddrs.pfnSPR_Set)(&hSprite,&r,&g,&b);
                    /* Unresolved local var: int spriteIndex@[???] */
  iVar1 = hSprite + -1;
  if ((((-1 < iVar1) && (iVar1 < gSpriteCount)) && (gSpriteList + iVar1 != (SPRITELIST *)0x0)) &&
     (gpSprite = ((gSpriteList[iVar1].pSprite)->cache).data, gpSprite != (msprite_t *)0x0)) {
    (*qglColor4f)((float)r / 255.0,(float)g / 255.0,(float)b / 255.0,1.0);
  }
  return;
}


// SPR_Shutdown  @ 0018f630
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SPR_Shutdown(void)

{
  undefined4 *puVar1;
  SPRITELIST *p;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  if (host_initialized != false) {
    if (gSpriteList != (SPRITELIST *)0x0) {
      p = gSpriteList;
      if (0 < gSpriteCount) {
        iVar2 = 0;
        iVar3 = 0;
        do {
          puVar1 = (undefined4 *)((int)&p->pSprite + iVar2);
          if ((model_t *)*puVar1 != (model_t *)0x0) {
            Mod_UnloadSpriteTextures((model_t *)*puVar1);
            puVar1 = (undefined4 *)((int)&gSpriteList->pSprite + iVar2);
            p = gSpriteList;
          }
          if ((void *)puVar1[1] != (void *)0x0) {
            Mem_Free((void *)puVar1[1]);
            p = gSpriteList;
          }
          iVar3 = iVar3 + 1;
          iVar2 = iVar2 + 0xc;
        } while (iVar3 < gSpriteCount);
      }
      Mem_Free(p);
    }
    gpSprite = (msprite_t *)0x0;
    gSpriteList = (SPRITELIST *)0x0;
    gSpriteCount = 0;
    ghCrosshair = 0;
  }
  return;
}


// SPR_Shutdown_NoModelFree  @ 0018f6d0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SPR_Shutdown_NoModelFree(void)

{
  void *p;
  int iVar1;
  SPRITELIST *p_00;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int i@[???] */
  if (host_initialized != false) {
    if (gSpriteList != (SPRITELIST *)0x0) {
      p_00 = gSpriteList;
      if (0 < gSpriteCount) {
        iVar2 = 0;
        iVar3 = 0;
        iVar1 = gSpriteCount;
        do {
          p = *(void **)((int)&p_00->pName + iVar3);
          if (p != (void *)0x0) {
            Mem_Free(p);
            iVar1 = gSpriteCount;
            p_00 = gSpriteList;
          }
          iVar2 = iVar2 + 1;
          iVar3 = iVar3 + 0xc;
        } while (iVar2 < iVar1);
      }
      Mem_Free(p_00);
    }
    gSpriteList = (SPRITELIST *)0x0;
    gSpriteCount = 0;
    gpSprite = (msprite_t *)0x0;
    ghCrosshair = 0;
  }
  return;
}


// SPR_Width  @ 0018f830
int SPR_Width(HSPRITE hSprite,int frame)

{
  int iVar1;
  mspriteframe_t *pmVar2;
  int iVar3;
  
                    /* Unresolved local var: mspriteframe_t * pFrame@[???]
                       Unresolved local var: SPRITELIST * pList@[DW_OP_reg2(EDX)]
                       Unresolved local var: msprite_t * pSprite@[???] */
                    /* Unresolved local var: int spriteIndex@[???] */
  iVar3 = 0;
  (*g_engdstAddrs.pfnSPR_Width)(&hSprite,&frame);
  iVar1 = hSprite + -1;
  if (((-1 < iVar1) && (iVar1 < gSpriteCount)) && (gSpriteList + iVar1 != (SPRITELIST *)0x0)) {
    pmVar2 = R_GetSpriteFrame(((gSpriteList[iVar1].pSprite)->cache).data,frame);
    if (pmVar2 != (mspriteframe_t *)0x0) {
      iVar3 = pmVar2->width;
    }
  }
  return iVar3;
}


