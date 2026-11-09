// ScissorRect_TCoords  @ 001cb890
bool __regparm3
ScissorRect_TCoords(int x0,int y0,int x1,int y1,float s0,float t0,float s1,float t1,RECT *pOut,
                   TCoordRect *pTCoords)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: RECT rcChar@[DW_OP_reg0(EAX); DW_OP_piece: 4;
                       DW_OP_reg1(ECX); DW_OP_piece: 4; DW_OP_reg2(EDX); DW_OP_piece: 4;
                       DW_OP_piece: 4] */
  if (g_bScissor) {
    bVar1 = false;
    if (pOut != (RECT *)0x0) {
      if (((((g_ScissorRect.left == g_ScissorRect.right) &&
            (g_ScissorRect.top == g_ScissorRect.bottom)) || ((x0 == x1 && (y0 == y1)))) ||
          (((x1 <= g_ScissorRect.left || (g_ScissorRect.right <= x0)) || (y1 <= g_ScissorRect.top)))
          ) || (g_ScissorRect.bottom <= y0)) {
        bVar1 = false;
        pOut->left = 0;
        pOut->right = 0;
        pOut->top = 0;
        pOut->bottom = 0;
      }
      else {
        iVar2 = g_ScissorRect.left;
        if (g_ScissorRect.left <= x0) {
          iVar2 = x0;
        }
        pOut->left = iVar2;
        iVar3 = g_ScissorRect.right;
        if (x1 <= g_ScissorRect.right) {
          iVar3 = x1;
        }
        pOut->right = iVar3;
        iVar3 = g_ScissorRect.top;
        if (g_ScissorRect.top <= y0) {
          iVar3 = y0;
        }
        pOut->top = iVar3;
        iVar3 = g_ScissorRect.bottom;
        if (y1 <= g_ScissorRect.bottom) {
          iVar3 = y1;
        }
        pOut->bottom = iVar3;
        if (pTCoords == (TCoordRect *)0x0) {
          bVar1 = true;
        }
        else {
                    /* Unresolved local var: float percent@[???] */
          bVar1 = true;
          pTCoords->s0 = ((float)(iVar2 - x0) / (float)(x1 - x0)) * (s1 - s0) + s0;
                    /* Unresolved local var: float percent@[???] */
                    /* Unresolved local var: float percent@[???] */
          pTCoords->s1 = (s1 - s0) * ((float)(pOut->right - x0) / (float)(x1 - x0)) + s0;
          pTCoords->t0 = ((float)(pOut->top - y0) / (float)(y1 - y0)) * (t1 - t0) + t0;
                    /* Unresolved local var: float percent@[???] */
          pTCoords->t1 = (t1 - t0) * ((float)(pOut->bottom - y0) / (float)(y1 - y0)) + t0;
        }
      }
    }
  }
  else {
    bVar1 = true;
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
  }
  return bVar1;
}


// ScissorRect_TCoords  @ 001cd410
bool ScissorRect_TCoords(int x0,int y0,int x1,int y1,float s0,float t0,float s1,float t1,RECT *pOut,
                        TCoordRect *pTCoords)

{
  bool bVar1;
  bool bVar2;
  RECT local_1c;
  
                    /* Unresolved local var: RECT rcChar@[???] */
  local_1c.top = y0;
  local_1c.bottom = y1;
  local_1c.left = x0;
  local_1c.right = x1;
  if (g_bScissor) {
    bVar2 = IntersectRect(pOut,&g_ScissorRect,&local_1c);
    bVar1 = false;
    if ((bVar2) && (bVar1 = true, pTCoords != (TCoordRect *)0x0)) {
                    /* Unresolved local var: float percent@[???] */
      pTCoords->s0 = ((float)(pOut->left - local_1c.left) / (float)(local_1c.right - local_1c.left))
                     * (s1 - s0) + s0;
                    /* Unresolved local var: float percent@[???] */
                    /* Unresolved local var: float percent@[???] */
      pTCoords->s1 = (s1 - s0) *
                     ((float)(pOut->right - local_1c.left) / (float)(local_1c.right - local_1c.left)
                     ) + s0;
      pTCoords->t0 = ((float)(pOut->top - local_1c.top) / (float)(local_1c.bottom - local_1c.top)) *
                     (t1 - t0) + t0;
                    /* Unresolved local var: float percent@[???] */
      pTCoords->t1 = (t1 - t0) *
                     ((float)(pOut->bottom - local_1c.top) / (float)(local_1c.bottom - local_1c.top)
                     ) + t0;
      return true;
    }
  }
  else {
    pOut->left = x0;
    pOut->right = x1;
    pOut->top = y0;
    pOut->bottom = y1;
    bVar1 = true;
    if (pTCoords != (TCoordRect *)0x0) {
      pTCoords->s0 = s0;
      pTCoords->t0 = t0;
      pTCoords->s1 = s1;
      pTCoords->t1 = t1;
    }
  }
  return bVar1;
}


