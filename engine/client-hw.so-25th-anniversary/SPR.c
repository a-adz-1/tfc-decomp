// SPR_DisableScissor  @ 00137830
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SPR_DisableScissor(void)

{
  (*g_engdstAddrs.pfnSPR_DisableScissor)();
  DisableScissorTest();
  return;
}


// SPR_Draw  @ 001374e0
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


// SPR_DrawAdditive  @ 00137640
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


// SPR_DrawGeneric  @ 001376f0
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


// SPR_DrawHoles  @ 00137590
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


// SPR_EnableScissor  @ 001377e0
void SPR_EnableScissor(int x,int y,int width,int height)

{
  (*g_engdstAddrs.pfnSPR_EnableScissor)(&x,&y,&width,&height);
  EnableScissorTest(x,y,width,height);
  return;
}


// SPR_Frames  @ 00137320
int SPR_Frames(HANDLE_SPRITE hSprite)

{
  int iVar1;
  int iVar2;
  
                    /* Unresolved local var: SPRITELIST * pList@[???] */
  (*g_engdstAddrs.pfnSPR_Frames)(&hSprite);
                    /* Unresolved local var: int spriteIndex@[???] */
  iVar1 = 0;
  iVar2 = hSprite + -1;
  if (((-1 < iVar2) && (iVar2 < gSpriteCount)) && (gSpriteList + iVar2 != (SPRITELIST *)0x0)) {
    iVar1 = gSpriteList[iVar2].frameCount;
  }
  return iVar1;
}


// SPR_Get  @ 00137260
SPRITELIST * SPR_Get(HANDLE_SPRITE hSprite)

{
  int iVar1;
  
                    /* Unresolved local var: int spriteIndex@[???] */
  iVar1 = hSprite + -1;
  if ((-1 < iVar1) && (iVar1 < gSpriteCount)) {
    return gSpriteList + iVar1;
  }
  return (SPRITELIST *)0x0;
}


// SPR_GetList  @ 00167130
client_sprite_t * SPR_GetList(char *psz,int *piCount)

{
  byte *data;
  char *pcVar1;
  long lVar2;
  client_sprite_t *pcVar3;
  long lVar4;
  client_sprite_t *dest;
  int iVar5;
  
                    /* Unresolved local var: char * pfile@[???]
                       Unresolved local var: int iCount@[???]
                       Unresolved local var: int i@[???]
                       Unresolved local var: client_sprite_t * ps@[???]
                       Unresolved local var: client_sprite_t * pret@[???] */
  (*g_engdstAddrs.pfnSPR_GetList)(&psz,&piCount);
  data = COM_LoadFile(psz,2,(int *)0x0);
  if (data != (byte *)0x0) {
    pcVar1 = COM_Parse((char *)data);
    lVar2 = strtol(com_token,(char **)0x0,10);
    if (lVar2 != 0) {
      pcVar3 = calloc(lVar2 * 0x98,1);
      if (pcVar3 != (client_sprite_t *)0x0) {
        iVar5 = 0;
        dest = pcVar3;
        if (0 < lVar2) {
          do {
            iVar5 = iVar5 + 1;
            pcVar1 = COM_Parse(pcVar1);
            Q_strncpy(dest->szName,com_token,0x3f);
            dest->szName[0x3f] = '\0';
            pcVar1 = COM_Parse(pcVar1);
            lVar4 = strtol(com_token,(char **)0x0,10);
            dest->iRes = lVar4;
            pcVar1 = COM_Parse(pcVar1);
            Q_strncpy(dest->szSprite,com_token,0x3f);
            dest->szSprite[0x3f] = '\0';
            pcVar1 = COM_Parse(pcVar1);
            lVar4 = strtol(com_token,(char **)0x0,10);
            (dest->rc).left = lVar4;
            pcVar1 = COM_Parse(pcVar1);
            lVar4 = strtol(com_token,(char **)0x0,10);
            (dest->rc).top = lVar4;
            pcVar1 = COM_Parse(pcVar1);
            lVar4 = strtol(com_token,(char **)0x0,10);
            (dest->rc).right = lVar4 + (dest->rc).left;
            pcVar1 = COM_Parse(pcVar1);
            lVar4 = strtol(com_token,(char **)0x0,10);
            (dest->rc).bottom = lVar4 + (dest->rc).top;
            dest = dest + 1;
          } while (iVar5 != lVar2);
        }
        if (piCount != (int *)0x0) {
          *piCount = lVar2;
        }
        return pcVar3;
      }
    }
  }
  return (client_sprite_t *)0x0;
}


// SPR_GetModelPointer  @ 00137290
model_s * SPR_GetModelPointer(HANDLE_SPRITE hSprite)

{
  int iVar1;
  
                    /* Unresolved local var: SPRITELIST * pList@[???]
                       Unresolved local var: int spriteIndex@[???] */
  iVar1 = hSprite + -1;
  if (((-1 < iVar1) && (iVar1 < gSpriteCount)) && (gSpriteList + iVar1 != (SPRITELIST *)0x0)) {
    return gSpriteList[iVar1].pSprite;
  }
  return (model_s *)0x0;
}


// SPR_Height  @ 001373d0
int SPR_Height(HANDLE_SPRITE hSprite,int frame)

{
  int iVar1;
  mspriteframe_t *pmVar2;
  
                    /* Unresolved local var: mspriteframe_t * pFrame@[???]
                       Unresolved local var: SPRITELIST * pList@[???]
                       Unresolved local var: msprite_t * pSprite@[???] */
  (*g_engdstAddrs.pfnSPR_Height)(&hSprite,&frame);
                    /* Unresolved local var: int spriteIndex@[???] */
  iVar1 = hSprite + -1;
  if (((-1 < iVar1) && (iVar1 < gSpriteCount)) && (gSpriteList + iVar1 != (SPRITELIST *)0x0)) {
    pmVar2 = R_GetSpriteFrame(((gSpriteList[iVar1].pSprite)->cache).data,frame);
    if (pmVar2 != (mspriteframe_t *)0x0) {
      return pmVar2->height;
    }
  }
  return 0;
}


// SPR_Init  @ 001372d0
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


// SPR_Load  @ 00137010
HANDLE_SPRITE SPR_Load(char *pTextureName)

{
  int iVar1;
  char *pcVar2;
  model_t *pmVar3;
  SPRITELIST *pSVar4;
  int iVar5;
  
                    /* Unresolved local var: int i@[???] */
  (*g_engdstAddrs.pfnSPR_Load)(&pTextureName);
  if (((pTextureName != (char *)0x0) && (gSpriteList != (SPRITELIST *)0x0)) && (0 < gSpriteCount)) {
    iVar5 = 0;
    while( true ) {
      pSVar4 = gSpriteList + iVar5;
      if (pSVar4->pSprite == (model_t *)0x0) {
        iVar1 = Q_strlen(pTextureName);
        pcVar2 = Mem_Malloc(iVar1 + 1);
        pSVar4->pName = pcVar2;
        Q_strcpy(gSpriteList[iVar5].pName,pTextureName);
        pSVar4 = gSpriteList + iVar5;
      }
      iVar1 = Q_stricmp(pTextureName,pSVar4->pName);
      if (iVar1 == 0) break;
      iVar5 = iVar5 + 1;
      if (gSpriteCount <= iVar5) {
                    /* WARNING: Subroutine does not return */
        Sys_Error("cannot allocate more than %d HUD sprites\n",0x100);
      }
    }
    gSpriteMipMap = false;
    pSVar4 = gSpriteList + iVar5;
    pmVar3 = Mod_ForName(pTextureName,false,true);
    pSVar4->pSprite = pmVar3;
    gSpriteMipMap = true;
    pSVar4 = gSpriteList + iVar5;
    pmVar3 = pSVar4->pSprite;
    if (pmVar3 != (model_t *)0x0) {
      iVar1 = ModelFrameCount(pmVar3);
      pSVar4->frameCount = iVar1;
      return iVar5 + 1;
    }
  }
  return 0;
}


// SPR_Pointer  @ 001372c0
msprite_t * SPR_Pointer(SPRITELIST *pList)

{
  return (pList->pSprite->cache).data;
}


// SPR_Set  @ 00137450
void SPR_Set(HANDLE_SPRITE hSprite,int r,int g,int b)

{
  int iVar1;
  
                    /* Unresolved local var: SPRITELIST * pList@[???] */
  (*g_engdstAddrs.pfnSPR_Set)(&hSprite,&r,&g,&b);
                    /* Unresolved local var: int spriteIndex@[???] */
  iVar1 = hSprite + -1;
  if ((((-1 < iVar1) && (iVar1 < gSpriteCount)) && (gSpriteList + iVar1 != (SPRITELIST *)0x0)) &&
     (gpSprite = ((gSpriteList[iVar1].pSprite)->cache).data, gpSprite != (msprite_t *)0x0)) {
    (*qglColor4f)((float)r / 255.0,(float)g / 255.0,(float)b / 255.0,1.0);
  }
  return;
}


// SPR_Shutdown  @ 00137140
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
    ghCrosshair = 0;
    gSpriteList = (SPRITELIST *)0x0;
    gSpriteCount = 0;
    gpSprite = (msprite_t *)0x0;
  }
  return;
}


// SPR_Shutdown_NoModelFree  @ 001371e0
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void SPR_Shutdown_NoModelFree(void)

{
  int iVar1;
  SPRITELIST *p;
  int iVar2;
  
                    /* Unresolved local var: int i@[???] */
  if (host_initialized != false) {
    if (gSpriteList != (SPRITELIST *)0x0) {
      p = gSpriteList;
      if (0 < gSpriteCount) {
        iVar2 = 0;
        iVar1 = gSpriteCount;
        do {
          if (p[iVar2].pName != (char *)0x0) {
            Mem_Free(p[iVar2].pName);
            iVar1 = gSpriteCount;
            p = gSpriteList;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < iVar1);
      }
      Mem_Free(p);
    }
    ghCrosshair = 0;
    gSpriteList = (SPRITELIST *)0x0;
    gSpriteCount = 0;
    gpSprite = (msprite_t *)0x0;
  }
  return;
}


// SPR_Width  @ 00137360
int SPR_Width(HANDLE_SPRITE hSprite,int frame)

{
  int iVar1;
  mspriteframe_t *pmVar2;
  
                    /* Unresolved local var: mspriteframe_t * pFrame@[???]
                       Unresolved local var: SPRITELIST * pList@[???]
                       Unresolved local var: msprite_t * pSprite@[???] */
  (*g_engdstAddrs.pfnSPR_Width)(&hSprite,&frame);
                    /* Unresolved local var: int spriteIndex@[???] */
  iVar1 = hSprite + -1;
  if (((-1 < iVar1) && (iVar1 < gSpriteCount)) && (gSpriteList + iVar1 != (SPRITELIST *)0x0)) {
    pmVar2 = R_GetSpriteFrame(((gSpriteList[iVar1].pSprite)->cache).data,frame);
    if (pmVar2 != (mspriteframe_t *)0x0) {
      return pmVar2->width;
    }
  }
  return 0;
}


