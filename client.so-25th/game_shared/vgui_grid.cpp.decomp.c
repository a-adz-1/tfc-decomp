// Ghidra decompilation of functions from game_shared/vgui_grid.cpp
// 31 functions, ordered by original source line

// vgui::CGrid::CGridEntry::CGridEntry  @ 000a76e0  (line 28)

/* DWARF original prototype: void CGridEntry(CGridEntry * this) */

void __thiscall vgui::CGrid::CGridEntry::CGridEntry(CGridEntry *this)

{
  this->m_pPanel = (Panel *)0x0;
  this->m_bUnderline = false;
  return;
}


// vgui::CGrid::CGridEntry::~CGridEntry  @ 000a76f0  (line 34)

/* DWARF original prototype: void ~CGridEntry(CGridEntry * this, int __in_chrg) */

void __thiscall vgui::CGrid::CGridEntry::~CGridEntry(CGridEntry *this,int __in_chrg)

{
  return;
}


// vgui::CGrid::CGrid  @ 000a7700  (line 43)

/* DWARF original prototype: void CGrid(CGrid * this) */

void __thiscall vgui::CGrid::CGrid(CGrid *this)

{
  vgui::Panel::Panel(&this->super_Panel);
  this->m_yRows = 0;
  this->m_GridEntries = (CGridEntry *)0x0;
  this->m_ySpacing = 0;
  *(undefined ***)this = &PTR_setPos_000cb34c;
  this->m_xCols = 0;
  this->m_Widths = (int *)0x0;
  this->m_xSpacing = 0;
  this->m_bDirty = false;
  return;
}


// vgui::CGrid::~CGrid  @ 000a7600  (line 49)

/* DWARF original prototype: void ~CGrid(CGrid * this, int __in_chrg) */

void __thiscall vgui::CGrid::~CGrid(CGrid *this,int __in_chrg)

{
  CGridEntry *pCVar1;
  CGridEntry *pCVar2;
  
  pCVar1 = this->m_GridEntries;
  *(undefined ***)this = &PTR_setPos_000cb34c;
  if (pCVar1 != (CGridEntry *)0x0) {
    pCVar2 = pCVar1 + pCVar1[-1].m_iUnderlineOffset;
    if (pCVar1 != pCVar2) {
      do {
        pCVar2 = pCVar2 + -1;
      } while (this->m_GridEntries != pCVar2);
    }
    operator_delete__(&pCVar2[-1].m_iUnderlineOffset);
  }
  if (this->m_Widths == (int *)0x0) {
    return;
  }
  operator_delete__(this->m_Widths);
  return;
}


// vgui::CGrid::~CGrid  @ 000a7670  (line 49)

/* DWARF original prototype: void ~CGrid(CGrid * this, int __in_chrg) */

void __thiscall vgui::CGrid::~CGrid(CGrid *this,int __in_chrg)

{
  CGridEntry *pCVar1;
  CGridEntry *pCVar2;
  
  pCVar1 = this->m_GridEntries;
  *(undefined ***)this = &PTR_setPos_000cb34c;
  if (pCVar1 != (CGridEntry *)0x0) {
    pCVar2 = pCVar1 + pCVar1[-1].m_iUnderlineOffset;
    if (pCVar1 != pCVar2) {
      do {
        pCVar2 = pCVar2 + -1;
      } while (this->m_GridEntries != pCVar2);
    }
    operator_delete__(&pCVar2[-1].m_iUnderlineOffset);
  }
  if (this->m_Widths != (int *)0x0) {
    operator_delete__(this->m_Widths);
  }
  operator_delete(this);
  return;
}


// vgui::CGrid::SetDimensions  @ 000a7760  (line 56)

/* WARNING: Removing unreachable block (ram,0x000a7913) */
/* WARNING: Removing unreachable block (ram,0x000a78d0) */
/* WARNING: Removing unreachable block (ram,0x000a78de) */
/* DWARF original prototype: bool SetDimensions(CGrid * this, int xCols, int yRows) */

bool __thiscall vgui::CGrid::SetDimensions(CGrid *this,int xCols,int yRows)

{
  int *piVar1;
  CGridEntry *pCVar2;
  uint uVar3;
  uint *puVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  CGridEntry *pCVar8;
  uint uVar9;
  byte bVar10;
  int iStack_28;
  
  bVar10 = 0;
  pCVar2 = this->m_GridEntries;
  if (pCVar2 != (CGridEntry *)0x0) {
                    /* try { // try from 000a777f to 000b77af has its CatchHandler @ 000a7e57 */
    pCVar8 = pCVar2 + pCVar2[-1].m_iUnderlineOffset;
    if (pCVar2 != pCVar8) {
      do {
        pCVar8 = pCVar8 + -1;
      } while (this->m_GridEntries != pCVar8);
    }
    operator_delete__(&pCVar8[-1].m_iUnderlineOffset);
  }
  if (this->m_Widths != (int *)0x0) {
    operator_delete__(this->m_Widths);
  }
  this->m_GridEntries = (CGridEntry *)0x0;
                    /* try { // try from 000a77ca to 000b77ce has its CatchHandler @ 000a7e49 */
  this->m_xCols = 0;
  this->m_yRows = 0;
  this->m_xSpacing = 0;
  this->m_ySpacing = 0;
  uVar9 = xCols * yRows;
  uVar3 = 0xffffffff;
                    /* try { // try from 000a77dc to 000b7846 has its CatchHandler @ 000a7e57 */
  this->m_Widths = (int *)0x0;
  this->m_bDirty = false;
  if (uVar9 < 0x6600001) {
    uVar3 = uVar9 * 0x14 + 4;
  }
  puVar4 = operator_new__(uVar3);
  iVar7 = 0;
  *puVar4 = uVar9;
  pCVar2 = (CGridEntry *)(puVar4 + 1);
  uVar3 = uVar9;
  while (uVar3 != 0) {
    iVar7 = iVar7 + 1;
    pCVar2->m_pPanel = (Panel *)0x0;
    pCVar2->m_bUnderline = false;
    pCVar2 = pCVar2 + 1;
    uVar3 = uVar9 - iVar7;
  }
  this->m_GridEntries = (CGridEntry *)(puVar4 + 1);
  if (0x1fc00000 < (uint)((xCols + yRows) * 2)) {
    __cxa_throw_bad_array_new_length();
    iVar7 = *(int *)(iStack_28 + 0xdc);
    if (iVar7 != 0) {
      iVar6 = iVar7 + *(int *)(iVar7 + -4) * 0x14;
      if (iVar7 != iVar6) {
        do {
          iVar6 = iVar6 + -0x14;
        } while (*(int *)(iStack_28 + 0xdc) != iVar6);
      }
      operator_delete__((void *)(iVar6 + -4));
    }
    if (*(void **)(iStack_28 + 0xcc) != (void *)0x0) {
      operator_delete__(*(void **)(iStack_28 + 0xcc));
    }
    *(undefined4 *)(iStack_28 + 0xcc) = 0;
    *(undefined1 (*) [16])(iStack_28 + 0xbc) = (undefined1  [16])0x0;
    *(undefined4 *)(iStack_28 + 0xdc) = 0;
    *(undefined1 *)(iStack_28 + 0xbb) = 0;
    return false;
  }
  uVar3 = (xCols + yRows) * 8;
  piVar5 = operator_new__(uVar3);
  piVar1 = piVar5 + xCols;
  this->m_Heights = piVar1;
  this->m_ColOffsets = piVar1 + yRows;
                    /* try { // try from 000a7867 to 000b786b has its CatchHandler @ 000a6d40 */
  pCVar2 = this->m_GridEntries;
  this->m_Widths = piVar5;
  this->m_RowOffsets = piVar1 + yRows + xCols;
  if (pCVar2 != (CGridEntry *)0x0) {
    if (piVar5 != (int *)0x0) {
      if (7 < uVar3) {
        uVar9 = uVar3;
        if (((uint)piVar5 & 1) != 0) {
          *(undefined1 *)piVar5 = 0;
          piVar5 = (int *)((int)piVar5 + 1);
          uVar9 = uVar3 - 1;
        }
        if (((uint)piVar5 & 2) != 0) {
          *(undefined2 *)piVar5 = 0;
          uVar9 = uVar9 - 2;
          piVar5 = (int *)((int)piVar5 + 2);
        }
                    /* try { // try from 000a78fb to 000b7a8b has its CatchHandler @ 000a6d40 */
        if (((uint)piVar5 & 4) != 0) {
          *piVar5 = 0;
          uVar9 = uVar9 - 4;
          piVar5 = piVar5 + 1;
        }
        uVar3 = uVar9 & 3;
        for (uVar9 = uVar9 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
          *piVar5 = 0;
          piVar5 = piVar5 + (uint)bVar10 * -2 + 1;
        }
      }
      if ((uVar3 & 2) != 0) {
        *(undefined2 *)piVar5 = 0;
        piVar5 = (int *)((int)piVar5 + 2);
      }
      if ((uVar3 & 1) != 0) {
        *(undefined1 *)piVar5 = 0;
      }
                    /* try { // try from 000a78a3 to 000b78a7 has its CatchHandler @ 000a7e38 */
      this->m_xCols = xCols;
      this->m_yRows = yRows;
      return true;
    }
    pCVar8 = pCVar2 + pCVar2[-1].m_iUnderlineOffset;
    if (pCVar2 != pCVar8) {
      do {
        pCVar8 = pCVar8 + -1;
      } while (this->m_GridEntries != pCVar8);
    }
    operator_delete__(&pCVar8[-1].m_iUnderlineOffset);
    piVar5 = this->m_Widths;
  }
  if (piVar5 != (int *)0x0) {
    operator_delete__(piVar5);
  }
  this->m_Widths = (int *)0x0;
  this->m_xCols = 0;
  this->m_yRows = 0;
  this->m_xSpacing = 0;
  this->m_ySpacing = 0;
  this->m_GridEntries = (CGridEntry *)0x0;
  this->m_bDirty = false;
  return false;
}


// vgui::CGrid::Term  @ 000a79c0  (line 80)

/* DWARF original prototype: void Term(CGrid * this) */

void __thiscall vgui::CGrid::Term(CGrid *this)

{
  CGridEntry *pCVar1;
  CGridEntry *pCVar2;
  
  pCVar1 = this->m_GridEntries;
  if (pCVar1 != (CGridEntry *)0x0) {
    pCVar2 = pCVar1 + pCVar1[-1].m_iUnderlineOffset;
    if (pCVar1 != pCVar2) {
      do {
        pCVar2 = pCVar2 + -1;
      } while (this->m_GridEntries != pCVar2);
    }
    operator_delete__(&pCVar2[-1].m_iUnderlineOffset);
  }
  if (this->m_Widths != (int *)0x0) {
    operator_delete__(this->m_Widths);
  }
  this->m_Widths = (int *)0x0;
  this->m_xCols = 0;
  this->m_yRows = 0;
  this->m_xSpacing = 0;
  this->m_ySpacing = 0;
  this->m_GridEntries = (CGridEntry *)0x0;
  this->m_bDirty = false;
  return;
}


// vgui::CGrid::GetEntry  @ 000a7a50  (line 88)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: Panel * GetEntry(CGrid * this, int x, int y) */

Panel * __thiscall vgui::CGrid::GetEntry(CGrid *this,int x,int y)

{
  CGridEntry *pCVar1;
  
  if (-1 < x) {
    pCVar1 = (CGridEntry *)0x0;
    if (((-1 < y) && (x < this->m_xCols)) && (y < this->m_yRows)) {
      pCVar1 = this->m_GridEntries + x + y * this->m_xCols;
    }
    return pCVar1->m_pPanel;
  }
  return _DAT_00000000;
}


// vgui::CGrid::SetEntry  @ 000a7ac0  (line 94)

/* DWARF original prototype: bool SetEntry(CGrid * this, int x, int y, Panel * pPanel) */

bool __thiscall vgui::CGrid::SetEntry(CGrid *this,int x,int y,Panel *pPanel)

{
  CGridEntry *pCVar1;
  Panel *pPVar2;
  bool bVar3;
  
                    /* Unresolved local var: CGridEntry * pEntry@[???] */
                    /* try { // try from 000a7ace to 000b7ad2 has its CatchHandler @ 000a7e47 */
  if (-1 < x) {
                    /* try { // try from 000a7ae7 to 000b7aeb has its CatchHandler @ 000a6d40 */
    if (-1 < y && x < this->m_xCols) {
      bVar3 = false;
      if ((y < this->m_yRows) &&
         (pCVar1 = this->m_GridEntries + x + this->m_xCols * y, pCVar1 != (CGridEntry *)0x0)) {
        pPVar2 = pCVar1->m_pPanel;
        if (pPVar2 != (Panel *)0x0) {
          (**(code **)(*(int *)pPVar2 + 0x40))(pPVar2,0);
        }
                    /* try { // try from 000a7b32 to 000b7b62 has its CatchHandler @ 000a7e72 */
        pCVar1->m_pPanel = pPanel;
        if (pPanel != (Panel *)0x0) {
          (**(code **)(*(int *)pPanel + 0x40))(pPanel,this);
        }
        this->m_bDirty = true;
        bVar3 = true;
      }
      return bVar3;
    }
  }
  return false;
}


// vgui::CGrid::GetXSpacing  @ 000a7b80  (line 113)

/* DWARF original prototype: int GetXSpacing(CGrid * this) */

int __thiscall vgui::CGrid::GetXSpacing(CGrid *this)

{
  return this->m_xSpacing;
}


// vgui::CGrid::GetYSpacing  @ 000a7b90  (line 119)

/* DWARF original prototype: int GetYSpacing(CGrid * this) */

int __thiscall vgui::CGrid::GetYSpacing(CGrid *this)

{
  return this->m_ySpacing;
}


// vgui::CGrid::SetSpacing  @ 000a7ba0  (line 124)

/* DWARF original prototype: void SetSpacing(CGrid * this, int xSpacing, int ySpacing) */

void __thiscall vgui::CGrid::SetSpacing(CGrid *this,int xSpacing,int ySpacing)

{
  int iVar1;
  int iVar2;
  
  if (this->m_xSpacing != xSpacing) {
                    /* Unresolved local var: int cur@[???]
                       Unresolved local var: int i@[???] */
    iVar1 = 0;
    this->m_xSpacing = xSpacing;
    if (0 < this->m_xCols) {
      do {
                    /* try { // try from 000a7bd8 to 000b7bdc has its CatchHandler @ 000a7e6d */
        iVar2 = iVar1 + 1;
        this->m_ColOffsets[iVar1] = xSpacing;
                    /* try { // try from 000a7bea to 000b7cb3 has its CatchHandler @ 000a7e72 */
        xSpacing = xSpacing + this->m_xSpacing + this->m_Widths[iVar1];
        iVar1 = iVar2;
      } while (iVar2 < this->m_xCols);
    }
    this->m_bDirty = true;
  }
  if (this->m_ySpacing != ySpacing) {
                    /* Unresolved local var: int cur@[???]
                       Unresolved local var: int i@[???] */
    iVar1 = 0;
    this->m_ySpacing = ySpacing;
    if (0 < this->m_yRows) {
      do {
        iVar2 = iVar1 + 1;
        this->m_RowOffsets[iVar1] = ySpacing;
        ySpacing = ySpacing + this->m_ySpacing + this->m_Heights[iVar1];
        iVar1 = iVar2;
      } while (iVar2 < this->m_yRows);
    }
    this->m_bDirty = true;
  }
  return;
}


// vgui::CGrid::SetColumnWidth  @ 000a7c60  (line 142)

/* DWARF original prototype: bool SetColumnWidth(CGrid * this, int iColumn, int width) */

bool __thiscall vgui::CGrid::SetColumnWidth(CGrid *this,int iColumn,int width)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((-1 < iColumn) && (iColumn < this->m_xCols)) {
    iVar1 = iColumn * 4;
                    /* Unresolved local var: int cur@[???] */
    iVar2 = iColumn + 1;
    this->m_Widths[iColumn] = width;
    iVar3 = this->m_xSpacing;
    if (iVar2 != 0) {
      iVar3 = iVar3 + this->m_Widths[iColumn] + this->m_ColOffsets[iColumn];
    }
                    /* Unresolved local var: int i@[???] */
    if (iVar2 < this->m_xCols) {
      do {
        iVar1 = iVar1 + 4;
        iVar2 = iVar2 + 1;
        *(int *)((int)this->m_ColOffsets + iVar1) = iVar3;
                    /* try { // try from 000a7ccc to 000b7ceb has its CatchHandler @ 000a6d40 */
        iVar3 = iVar3 + this->m_xSpacing + *(int *)((int)this->m_Widths + iVar1);
      } while (iVar2 < this->m_xCols);
    }
    this->m_bDirty = true;
    return true;
  }
  return false;
}


// vgui::CGrid::SetRowHeight  @ 000a7d00  (line 152)

/* DWARF original prototype: bool SetRowHeight(CGrid * this, int iRow, int height) */

bool __thiscall vgui::CGrid::SetRowHeight(CGrid *this,int iRow,int height)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((-1 < iRow) && (iRow < this->m_yRows)) {
    iVar1 = iRow * 4;
    iVar2 = iRow + 1;
    this->m_Heights[iRow] = height;
    iVar3 = this->m_ySpacing;
    if (iVar2 != 0) {
      iVar3 = iVar3 + this->m_RowOffsets[iRow];
    }
    if (iVar2 < this->m_yRows) {
      do {
        iVar1 = iVar1 + 4;
        iVar2 = iVar2 + 1;
        *(int *)((int)this->m_RowOffsets + iVar1) = iVar3;
        iVar3 = iVar3 + this->m_ySpacing + *(int *)((int)this->m_Heights + iVar1);
      } while (iVar2 < this->m_yRows);
    }
    this->m_bDirty = true;
    return true;
  }
  return false;
}


// vgui::CGrid::GetColumnWidth  @ 000a7da0  (line 162)

/* DWARF original prototype: int GetColumnWidth(CGrid * this, int iColumn) */

int __thiscall vgui::CGrid::GetColumnWidth(CGrid *this,int iColumn)

{
  if ((-1 < iColumn) && (iColumn < this->m_xCols)) {
    return this->m_Widths[iColumn];
  }
  return 0;
}


// vgui::CGrid::GetRowHeight  @ 000a7dd0  (line 169)

/* DWARF original prototype: int GetRowHeight(CGrid * this, int iRow) */

int __thiscall vgui::CGrid::GetRowHeight(CGrid *this,int iRow)

{
  if ((-1 < iRow) && (iRow < this->m_yRows)) {
    return this->m_Heights[iRow];
  }
  return 0;
}


// vgui::CGrid::CalcFitColumnWidth  @ 000a7e00  (line 176)

/* DWARF original prototype: int CalcFitColumnWidth(CGrid * this, int iColumn) */

int __thiscall vgui::CGrid::CalcFitColumnWidth(CGrid *this,int iColumn)

{
  Panel *pPVar1;
  int iVar2;
  CGridEntry *pCVar3;
  int iVar4;
  int iVar5;
  int iStack_24;
  undefined1 auStack_20 [16];
  
                    /* Unresolved local var: int maxSize@[???] */
  if (iColumn < 0) {
    return 0;
  }
  iVar4 = this->m_xCols;
  iVar2 = 0;
  if ((iColumn < iVar4) && (0 < this->m_yRows)) {
    iVar5 = 0;
    iVar2 = 0;
    while( true ) {
      if ((iVar5 < 0) || (iVar4 <= iColumn)) {
        pCVar3 = (CGridEntry *)0x0;
      }
      else {
        pCVar3 = this->m_GridEntries + iVar4 * iVar5 + iColumn;
      }
      pPVar1 = pCVar3->m_pPanel;
      if ((pPVar1 != (Panel *)0x0) &&
         ((**(code **)(*(int *)pPVar1 + 0xc))(pPVar1,&iStack_24,auStack_20), iVar2 < iStack_24)) {
        iVar2 = iStack_24;
      }
      iVar5 = iVar5 + 1;
      if (this->m_yRows <= iVar5) break;
      iVar4 = this->m_xCols;
    }
  }
  return iVar2;
}


// vgui::CGrid::CalcFitRowHeight  @ 000a7ec0  (line 197)

/* DWARF original prototype: int CalcFitRowHeight(CGrid * this, int iRow) */

int __thiscall vgui::CGrid::CalcFitRowHeight(CGrid *this,int iRow)

{
  Panel *pPVar1;
  int iVar2;
  CGridEntry *pCVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_24 [4];
  int local_20 [4];
  
                    /* Unresolved local var: int maxSize@[???] */
  iVar2 = 0;
                    /* Unresolved local var: int maxSize@[???]
                       Unresolved local var: int i@[???] */
  if (((-1 < iRow) && (iRow < this->m_yRows)) && (iVar4 = this->m_xCols, 0 < iVar4)) {
    iVar5 = 0;
                    /* Unresolved local var: Panel * pPanel@[???]
                       Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???] */
    iVar2 = 0;
    do {
      pCVar3 = (CGridEntry *)0x0;
      if ((iVar5 < iVar4) && (iRow < this->m_yRows)) {
        pCVar3 = this->m_GridEntries + iRow * iVar4 + iVar5;
      }
      pPVar1 = pCVar3->m_pPanel;
      if (pPVar1 != (Panel *)0x0) {
        (**(code **)(*(int *)pPVar1 + 0xc))(pPVar1,auStack_24,local_20);
        iVar4 = this->m_xCols;
        if (iVar2 < local_20[0]) {
          iVar2 = local_20[0];
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar4);
  }
  return iVar2;
}


// vgui::CGrid::AutoSetRowHeights  @ 000a7f60  (line 218)

/* DWARF original prototype: void AutoSetRowHeights(CGrid * this) */

void __thiscall vgui::CGrid::AutoSetRowHeights(CGrid *this)

{
  Panel *pPVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  CGridEntry *pCVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  undefined1 local_24 [4];
  int local_20 [4];
  
                    /* Unresolved local var: int i@[???] */
  iVar7 = this->m_yRows;
  if (0 < iVar7) {
    iVar6 = 1;
    do {
      iVar4 = iVar6 + -1;
                    /* Unresolved local var: int maxSize@[???]
                       Unresolved local var: int i@[???] */
      iVar8 = 0;
                    /* try { // try from 000a7f87 to 000b7ff4 has its CatchHandler @ 000a7f30 */
      iVar3 = this->m_xCols;
      if (0 < iVar3) {
        iVar7 = 0;
        do {
                    /* Unresolved local var: Panel * pPanel@[???]
                       Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???] */
          pCVar5 = (CGridEntry *)0x0;
          if (iVar4 < this->m_yRows) {
            pCVar5 = this->m_GridEntries + iVar4 * iVar3 + iVar7;
          }
          pPVar1 = pCVar5->m_pPanel;
          if (pPVar1 != (Panel *)0x0) {
            (**(code **)(*(int *)pPVar1 + 0xc))(pPVar1,local_24,local_20);
            if (iVar8 < local_20[0]) {
              iVar8 = local_20[0];
            }
            iVar3 = this->m_xCols;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar3);
        iVar7 = this->m_yRows;
      }
      if (iVar4 < iVar7) {
        this->m_Heights[iVar6 + -1] = iVar8;
                    /* Unresolved local var: int cur@[???] */
        piVar9 = this->m_RowOffsets;
                    /* Unresolved local var: int i@[???] */
        iVar7 = this->m_yRows;
        iVar4 = piVar9[iVar6 + -1] + this->m_ySpacing;
        if (iVar6 < iVar7) {
          iVar3 = iVar6 * 4;
          iVar8 = iVar6;
          while( true ) {
            *(int *)((int)piVar9 + iVar3) = iVar4;
            iVar8 = iVar8 + 1;
            piVar9 = (int *)((int)this->m_Heights + iVar3);
            iVar3 = iVar3 + 4;
            iVar4 = iVar4 + this->m_ySpacing + *piVar9;
            iVar7 = this->m_yRows;
            if (iVar7 <= iVar8) break;
            piVar9 = this->m_RowOffsets;
          }
        }
        this->m_bDirty = true;
      }
      bVar2 = iVar6 < iVar7;
      iVar6 = iVar6 + 1;
    } while (bVar2);
  }
  return;
}


// vgui::CGrid::GetEntryBox  @ 000a8080  (line 226)

/* DWARF original prototype: bool GetEntryBox(CGrid * this, int col, int row, int * x, int * y, int
   * w, int * h) */

bool __thiscall vgui::CGrid::GetEntryBox(CGrid *this,int col,int row,int *x,int *y,int *w,int *h)

{
  bool bVar1;
  
                    /* try { // try from 000a8097 to 000b80b9 has its CatchHandler @ 000a824b */
  if ((-1 < col) && (-1 < row && col < this->m_xCols)) {
    bVar1 = row < this->m_yRows;
    if (bVar1) {
                    /* try { // try from 000a80c6 to 000b825c has its CatchHandler @ 000a7f30 */
      *x = this->m_ColOffsets[col];
      *w = this->m_Widths[col];
      *y = this->m_RowOffsets[row];
      *h = this->m_Heights[row];
    }
    return bVar1;
  }
  return false;
}


// vgui::CGrid::CopyColumnWidths  @ 000a8120  (line 239)

/* DWARF original prototype: bool CopyColumnWidths(CGrid * this, CGrid * pOther) */

bool __thiscall vgui::CGrid::CopyColumnWidths(CGrid *this,CGrid *pOther)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (pOther == (CGrid *)0x0) {
    return false;
  }
  if (pOther->m_xCols == this->m_xCols) {
                    /* Unresolved local var: int i@[???] */
    iVar1 = 0;
    if (0 < pOther->m_xCols) {
      do {
        iVar2 = iVar1 + 1;
        this->m_Widths[iVar1] = pOther->m_Widths[iVar1];
        iVar1 = iVar2;
      } while (iVar2 < this->m_xCols);
                    /* Unresolved local var: int cur@[???]
                       Unresolved local var: int i@[???] */
      iVar1 = this->m_xSpacing;
      if (0 < this->m_xCols) {
        iVar2 = 0;
        do {
          iVar3 = iVar2 + 1;
          this->m_ColOffsets[iVar2] = iVar1;
          iVar1 = iVar1 + this->m_xSpacing + this->m_Widths[iVar2];
          iVar2 = iVar3;
        } while (iVar3 < this->m_xCols);
      }
    }
    this->m_bDirty = true;
    return true;
  }
  return false;
}


// vgui::CGrid::RepositionContents  @ 000a81e0  (line 253)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: void RepositionContents(CGrid * this) */

void __thiscall vgui::CGrid::RepositionContents(CGrid *this)

{
  Panel *pPVar1;
  CGridEntry *pCVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_20;
  
                    /* Unresolved local var: int x@[???] */
  iVar3 = this->m_xCols;
  if (0 < iVar3) {
    iVar4 = this->m_yRows;
    local_20 = 0;
    do {
                    /* Unresolved local var: int y@[???] */
      if (0 < iVar4) {
        iVar5 = 0;
        if (local_20 < 0) {
          do {
            if (_DAT_00000000 != (int *)0x0) {
              (**(code **)(*_DAT_00000000 + 0x10))
                        (_DAT_00000000,this->m_ColOffsets[local_20],this->m_RowOffsets[iVar5],
                         this->m_Widths[local_20],this->m_Heights[iVar5]);
              iVar4 = this->m_yRows;
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar4);
          iVar3 = this->m_xCols;
        }
        else {
          do {
                    /* Unresolved local var: Panel * pPanel@[???] */
            if ((local_20 < iVar3) && (-1 < iVar5)) {
                    /* catch() { ... } // from try @ 000a8097 with catch @ 000a824b */
              pCVar2 = this->m_GridEntries + iVar3 * iVar5 + local_20;
            }
            else {
              pCVar2 = (CGridEntry *)0x0;
            }
            pPVar1 = pCVar2->m_pPanel;
            if (pPVar1 != (Panel *)0x0) {
              (**(code **)(*(int *)pPVar1 + 0x10))
                        (pPVar1,this->m_ColOffsets[local_20],this->m_RowOffsets[iVar5],
                         this->m_Widths[local_20],this->m_Heights[iVar5]);
              iVar3 = this->m_xCols;
              iVar4 = this->m_yRows;
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar4);
        }
      }
      local_20 = local_20 + 1;
    } while (local_20 < iVar3);
  }
  this->m_bDirty = false;
  return;
}


// vgui::CGrid::CalcDrawHeight  @ 000a8350  (line 275)

/* DWARF original prototype: int CalcDrawHeight(CGrid * this) */

int __thiscall vgui::CGrid::CalcDrawHeight(CGrid *this)

{
  int iVar1;
  
  iVar1 = this->m_yRows;
  if (0 < iVar1) {
    return this->m_RowOffsets[iVar1 + -1] + this->m_Heights[iVar1 + -1] + this->m_ySpacing;
  }
  return 0;
}


// vgui::CGrid::paint  @ 000a86c0  (line 288)

/* DWARF original prototype: void paint(CGrid * this) */

void __thiscall vgui::CGrid::paint(CGrid *this)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  CGridEntry *pCVar6;
  
                    /* Unresolved local var: int x@[???]
                       Unresolved local var: int y@[???] */
  if (this->m_bDirty != false) {
    RepositionContents(this);
  }
                    /* Unresolved local var: int row@[???] */
  iVar5 = 0;
  iVar4 = 0;
  vgui::Panel::paint();
  if (0 < this->m_yRows) {
    do {
      while( true ) {
                    /* Unresolved local var: CGridEntry * cell@[???] */
        if ((iVar5 < 0) || (this->m_xCols < 1)) {
          pCVar6 = (CGridEntry *)0x0;
        }
        else {
          pCVar6 = this->m_GridEntries + this->m_xCols * iVar5;
        }
        iVar2 = (**(code **)(*(int *)pCVar6->m_pPanel + 0x1c))(pCVar6->m_pPanel);
        iVar4 = iVar4 + iVar2 + this->m_ySpacing;
        if (pCVar6->m_bUnderline == false) break;
        iVar5 = iVar5 + 1;
        (**(code **)(*(int *)this + 0x178))
                  (this,(int)pCVar6->m_UnderlineColor[0],(int)pCVar6->m_UnderlineColor[1],
                   (int)pCVar6->m_UnderlineColor[2],(int)pCVar6->m_UnderlineColor[3]);
        pcVar1 = *(code **)(*(int *)this + 0x17c);
        iVar2 = pCVar6->m_iUnderlineOffset;
        uVar3 = (**(code **)(*(int *)this + 0x18))(this);
        (*pcVar1)(this,0,iVar4 - (pCVar6->m_iUnderlineOffset + 1),uVar3,iVar4 - iVar2);
        if (this->m_yRows <= iVar5) {
          return;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < this->m_yRows);
  }
  return;
}


// vgui::CGrid::paintBackground  @ 000a87f0  (line 311)

/* DWARF original prototype: void paintBackground(CGrid * this) */

void __thiscall vgui::CGrid::paintBackground(CGrid *this)

{
  vgui::Panel::paintBackground();
  return;
}


// vgui::CGrid::SetRowUnderline  @ 000a8390  (line 318)

/* DWARF original prototype: void SetRowUnderline(CGrid * this, int row, bool enabled, int offset,
   int r, int g, int b, int a) */

void __thiscall
vgui::CGrid::SetRowUnderline(CGrid *this,int row,bool enabled,int offset,int r,int g,int b,int a)

{
  CGridEntry *pCVar1;
  
                    /* Unresolved local var: CGridEntry * cell@[???] */
  pCVar1 = (CGridEntry *)0x0;
  if (((-1 < row) && (0 < this->m_xCols)) && (row < this->m_yRows)) {
    pCVar1 = this->m_GridEntries + this->m_xCols * row;
  }
  pCVar1->m_bUnderline = enabled;
  if (enabled) {
    pCVar1->m_iUnderlineOffset = offset;
    pCVar1->m_UnderlineColor[0] = (short)r;
    pCVar1->m_UnderlineColor[1] = (short)g;
    pCVar1->m_UnderlineColor[2] = (short)b;
    pCVar1->m_UnderlineColor[3] = (short)a;
  }
  return;
}


// vgui::CGrid::Clear  @ 000a8410  (line 332)

/* DWARF original prototype: void Clear(CGrid * this) */

void __thiscall vgui::CGrid::Clear(CGrid *this)

{
  this->m_Widths = (int *)0x0;
  this->m_xCols = 0;
  this->m_yRows = 0;
  this->m_xSpacing = 0;
  this->m_ySpacing = 0;
  this->m_GridEntries = (CGridEntry *)0x0;
  this->m_bDirty = false;
  return;
}


// vgui::CGrid::GridEntry  @ 000a8440  (line 342)

/* DWARF original prototype: CGridEntry * GridEntry(CGrid * this, int x, int y) */

CGridEntry * __thiscall vgui::CGrid::GridEntry(CGrid *this,int x,int y)

{
  if ((((-1 < x) && (-1 < y)) && (x < this->m_xCols)) && (y < this->m_yRows)) {
    return this->m_GridEntries + x + y * this->m_xCols;
  }
  return (CGridEntry *)0x0;
}


// vgui::CGrid::CalcColOffsets  @ 000a84b0  (line 349)

/* DWARF original prototype: void CalcColOffsets(CGrid * this, int iStart) */

void __thiscall vgui::CGrid::CalcColOffsets(CGrid *this,int iStart)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int cur@[???] */
  iVar3 = this->m_xSpacing;
  if (iStart != 0) {
    iVar3 = iVar3 + this->m_Widths[iStart + -1] + this->m_ColOffsets[iStart + -1];
  }
                    /* Unresolved local var: int i@[???] */
  iVar2 = iStart * 4;
  if (iStart < this->m_xCols) {
    do {
      iStart = iStart + 1;
      *(int *)((int)this->m_ColOffsets + iVar2) = iVar3;
      piVar1 = (int *)((int)this->m_Widths + iVar2);
      iVar2 = iVar2 + 4;
      iVar3 = iVar3 + this->m_xSpacing + *piVar1;
    } while (iStart < this->m_xCols);
  }
  return;
}


// vgui::CGrid::CalcRowOffsets  @ 000a8520  (line 363)

/* DWARF original prototype: void CalcRowOffsets(CGrid * this, int iStart) */

void __thiscall vgui::CGrid::CalcRowOffsets(CGrid *this,int iStart)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
                    /* Unresolved local var: int cur@[???] */
  iVar3 = this->m_ySpacing;
  if (iStart != 0) {
    iVar3 = iVar3 + this->m_RowOffsets[iStart + -1];
  }
                    /* Unresolved local var: int i@[???] */
  iVar2 = iStart * 4;
  if (iStart < this->m_yRows) {
    do {
      iStart = iStart + 1;
      *(int *)((int)this->m_RowOffsets + iVar2) = iVar3;
      piVar1 = (int *)((int)this->m_Heights + iVar2);
      iVar2 = iVar2 + 4;
      iVar3 = iVar3 + this->m_ySpacing + *piVar1;
    } while (iStart < this->m_yRows);
  }
  return;
}


// vgui::CGrid::getCellAtPoint  @ 000a8580  (line 376)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* DWARF original prototype: bool getCellAtPoint(CGrid * this, int worldX, int worldY, int * row,
   int * col) */

bool __thiscall vgui::CGrid::getCellAtPoint(CGrid *this,int worldX,int worldY,int *row,int *col)

{
  Panel *pPVar1;
  char cVar2;
  int iVar3;
  CGridEntry *pCVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  *row = -1;
  *col = -1;
                    /* Unresolved local var: int x@[???] */
  iVar5 = this->m_xCols;
  if (iVar5 < 1) {
    return false;
  }
  iVar3 = this->m_yRows;
  iVar7 = 0;
  do {
                    /* Unresolved local var: int y@[???] */
    while (iVar3 < 1) {
LAB_000a8676:
      iVar7 = iVar7 + 1;
      if (iVar5 <= iVar7) {
        return false;
      }
    }
    iVar6 = 0;
    if (iVar7 < 0) {
      iVar6 = 0;
      do {
        if (_DAT_00000000 != (int *)0x0) {
          cVar2 = (**(code **)(*_DAT_00000000 + 0x80))(_DAT_00000000,worldX,worldY);
          if (cVar2 != '\0') {
LAB_000a86a6:
            *col = iVar7;
            *row = iVar6;
            return true;
          }
          iVar3 = this->m_yRows;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar3);
      iVar5 = this->m_xCols;
      goto LAB_000a8676;
    }
    do {
      if (iVar7 < iVar5) {
                    /* Unresolved local var: Panel * pPanel@[???] */
        pCVar4 = this->m_GridEntries + iVar5 * iVar6 + iVar7;
      }
      else {
        pCVar4 = (CGridEntry *)0x0;
      }
      pPVar1 = pCVar4->m_pPanel;
      if (pPVar1 != (Panel *)0x0) {
        cVar2 = (**(code **)(*(int *)pPVar1 + 0x80))(pPVar1,worldX,worldY);
        if (cVar2 != '\0') goto LAB_000a86a6;
        iVar3 = this->m_yRows;
        iVar5 = this->m_xCols;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar3);
    iVar7 = iVar7 + 1;
    if (iVar5 <= iVar7) {
      return false;
    }
  } while( true );
}


