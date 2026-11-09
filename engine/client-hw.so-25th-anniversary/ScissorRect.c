// ScissorRect_TCoords  @ 00176400
bool ScissorRect_TCoords(int x0,int y0,int x1,int y1,float s0,float t0,float s1,float t1,RECT *pOut,
                        TCoordRect *pTCoords)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  bVar1 = g_bScissor;
                    /* Unresolved local var: RECT rcChar@[???] */
  if (!g_bScissor) {
    pOut->left = x0;
    pOut->right = x1;
    pOut->top = y0;
    pOut->bottom = y1;
    if (pTCoords != (TCoordRect *)0x0) {
      pTCoords->s0 = s0;
      pTCoords->t0 = t0;
      pTCoords->s1 = s1;
      pTCoords->t1 = t1;
    }
    return true;
  }
  if (pOut != (RECT *)0x0) {
    if (((((g_ScissorRect.left != g_ScissorRect.right) ||
          (g_ScissorRect.top != g_ScissorRect.bottom)) && ((y0 != y1 || (x0 != x1)))) &&
        (((g_ScissorRect.left < x1 && (x0 < g_ScissorRect.right)) && (g_ScissorRect.top < y1)))) &&
       (y0 < g_ScissorRect.bottom)) {
      iVar2 = g_ScissorRect.left;
      if (g_ScissorRect.left <= x0) {
        iVar2 = x0;
      }
      pOut->left = iVar2;
      iVar3 = x1;
      if (g_ScissorRect.right <= x1) {
        iVar3 = g_ScissorRect.right;
      }
      pOut->right = iVar3;
      iVar3 = y0;
      if (y0 <= g_ScissorRect.top) {
        iVar3 = g_ScissorRect.top;
      }
      pOut->top = iVar3;
      iVar3 = y1;
      if (g_ScissorRect.bottom <= y1) {
        iVar3 = g_ScissorRect.bottom;
      }
      pOut->bottom = iVar3;
      if (pTCoords == (TCoordRect *)0x0) {
        return true;
      }
                    /* Unresolved local var: float percent@[???] */
                    /* Unresolved local var: float percent@[???] */
      pTCoords->s0 = ((float)(iVar2 - x0) / (float)(x1 - x0)) * (s1 - s0) + s0;
      pTCoords->s1 = (s1 - s0) * ((float)(pOut->right - x0) / (float)(x1 - x0)) + s0;
      pTCoords->t0 = ((float)(pOut->top - y0) / (float)(y1 - y0)) * (t1 - t0) + t0;
      pTCoords->t1 = (t1 - t0) * ((float)(pOut->bottom - y0) / (float)(y1 - y0)) + t0;
      return bVar1;
    }
    pOut->left = 0;
    pOut->right = 0;
    pOut->top = 0;
    pOut->bottom = 0;
  }
  return false;
}


