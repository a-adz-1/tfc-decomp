// Ghidra decompilation of functions from game_shared/vgui_helpers.cpp
// 1 functions, ordered by original source line

// AlignPanel  @ 000a8800  (line 15)

void AlignPanel(Panel *pChild,Panel *pParent,int alignment)

{
  int iVar1;
  int iVar2;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
                    /* Unresolved local var: int w@[???]
                       Unresolved local var: int h@[???]
                       Unresolved local var: int cw@[???]
                       Unresolved local var: int ch@[???]
                       Unresolved local var: int xCenter@[???]
                       Unresolved local var: int yCenter@[???] */
  (**(code **)(*(int *)pParent + 0xc))(pParent,&local_1c,&local_18);
  (**(code **)(*(int *)pChild + 0xc))(pChild,&local_14,&local_10);
  local_18 = local_18 - local_10;
  iVar1 = local_18 / 2;
  if (alignment == 3) {
    (*(code *)**(undefined4 **)pChild)(pChild,0,iVar1);
  }
  else {
    if (alignment == 0) {
      (*(code *)**(undefined4 **)pChild)(pChild,0,0);
      return;
    }
    local_1c = local_1c - local_14;
    iVar2 = local_1c / 2;
    if (alignment == 1) {
      (*(code *)**(undefined4 **)pChild)(pChild,iVar2,0);
    }
    else if (alignment == 2) {
      (*(code *)**(undefined4 **)pChild)(pChild,local_1c,0);
    }
    else if (alignment == 5) {
      (*(code *)**(undefined4 **)pChild)(pChild,local_1c,iVar1);
    }
    else if (alignment == 8) {
      (*(code *)**(undefined4 **)pChild)(pChild,local_1c,local_18);
    }
    else if (alignment == 7) {
      (*(code *)**(undefined4 **)pChild)(pChild,iVar2,local_18);
    }
    else if (alignment == 6) {
      (*(code *)**(undefined4 **)pChild)(pChild,0,local_18);
    }
    else if (alignment == 4) {
      (*(code *)**(undefined4 **)pChild)(pChild,iVar2,iVar1);
    }
  }
  return;
}


