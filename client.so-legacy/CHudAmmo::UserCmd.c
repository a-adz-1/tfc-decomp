// CHudAmmo::UserCmd_Close  @ 00088420
/* DWARF original prototype: void UserCmd_Close(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Close(CHudAmmo *this)

{
  if (gpActiveSel != (WEAPON *)0x0) {
    gpLastSel = gpActiveSel;
    gpActiveSel = (WEAPON *)0x0;
    (*gEngfuncs.pfnPlaySoundByName)("common/wpn_hudoff.wav",1.0);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00088469. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*gEngfuncs.pfnClientCmd)("escape");
  return;
}


// CHudAmmo::UserCmd_NextWeapon  @ 00088470
/* DWARF original prototype: void UserCmd_NextWeapon(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_NextWeapon(CHudAmmo *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int pos@[???]
                       Unresolved local var: int slot@[???] */
  if ((gHUD.m_fPlayerDead != 0) || (((byte)gHUD.m_iHideHUDDisplay & 5) != 0)) {
    return;
  }
  if (gpActiveSel < (WEAPON *)0x2) {
    gpActiveSel = this->m_pWeapon;
  }
  if (gpActiveSel == (WEAPON *)0x0) {
    iVar4 = 0;
    iVar2 = 0;
  }
  else {
    iVar4 = gpActiveSel->iSlot;
    iVar2 = gpActiveSel->iSlotPos + 1;
  }
                    /* Unresolved local var: int loop@[???] */
  iVar5 = 2;
  if (4 < iVar4) goto LAB_00088555;
  do {
    iVar3 = iVar4 * 0x18;
    if (4 < iVar2) goto LAB_00088546;
    do {
      do {
                    /* Unresolved local var: WEAPON * wsp@[DW_OP_reg0(EAX)] */
        gpActiveSel = *(WEAPON **)(iVar3 + 0x11b2a0 + iVar2 * 4);
        if (gpActiveSel != (WEAPON *)0x0) {
          if (gpActiveSel->iMax1 == -1) {
            return;
          }
          iVar1 = gpActiveSel->iAmmoType;
          if (iVar1 == -1) {
            return;
          }
          if (0 < gpActiveSel->iClip) {
            return;
          }
          if ((-1 < iVar1) && (gWR.riAmmo[iVar1] != 0)) {
            return;
          }
          if ((-1 < gpActiveSel->iAmmo2Type) && (gWR.riAmmo[gpActiveSel->iAmmo2Type] != 0)) {
            return;
          }
          if ((gpActiveSel->iFlags & 1) != 0) {
            return;
          }
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 != 5);
LAB_00088546:
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x18;
      iVar2 = 0;
    } while (iVar4 != 5);
LAB_00088555:
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      gpActiveSel = (WEAPON *)0x0;
      return;
    }
    iVar4 = 0;
  } while( true );
}


// CHudAmmo::UserCmd_PrevWeapon  @ 00088590
/* DWARF original prototype: void UserCmd_PrevWeapon(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_PrevWeapon(CHudAmmo *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* Unresolved local var: int pos@[???]
                       Unresolved local var: int slot@[???] */
  if ((gHUD.m_fPlayerDead != 0) || (((byte)gHUD.m_iHideHUDDisplay & 5) != 0)) {
    return;
  }
  if (gpActiveSel < (WEAPON *)0x2) {
    gpActiveSel = this->m_pWeapon;
  }
  if (gpActiveSel == (WEAPON *)0x0) {
    iVar4 = 4;
    iVar2 = 4;
  }
  else {
    iVar4 = gpActiveSel->iSlot;
    iVar2 = gpActiveSel->iSlotPos + -1;
  }
                    /* Unresolved local var: int loop@[???] */
  iVar5 = 2;
  if (iVar4 < 0) goto LAB_00088668;
  do {
    iVar3 = iVar4 * 0x18;
    if (iVar2 < 0) goto LAB_00088656;
    do {
      do {
                    /* Unresolved local var: WEAPON * wsp@[DW_OP_reg0(EAX)] */
        gpActiveSel = *(WEAPON **)(iVar3 + 0x11b2a0 + iVar2 * 4);
        if (gpActiveSel != (WEAPON *)0x0) {
          if (gpActiveSel->iMax1 == -1) {
            return;
          }
          iVar1 = gpActiveSel->iAmmoType;
          if (iVar1 == -1) {
            return;
          }
          if (0 < gpActiveSel->iClip) {
            return;
          }
          if ((-1 < iVar1) && (gWR.riAmmo[iVar1] != 0)) {
            return;
          }
          if ((-1 < gpActiveSel->iAmmo2Type) && (gWR.riAmmo[gpActiveSel->iAmmo2Type] != 0)) {
            return;
          }
          if ((gpActiveSel->iFlags & 1) != 0) {
            return;
          }
        }
        iVar2 = iVar2 + -1;
      } while (iVar2 != -1);
LAB_00088656:
      iVar4 = iVar4 + -1;
      iVar3 = iVar3 + -0x18;
      iVar2 = 4;
    } while (iVar4 != -1);
LAB_00088668:
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      gpActiveSel = (WEAPON *)0x0;
      return;
    }
    iVar4 = 4;
  } while( true );
}


// CHudAmmo::UserCmd_Slot1  @ 000881a0
/* DWARF original prototype: void UserCmd_Slot1(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Slot1(CHudAmmo *this)

{
  bool bVar1;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    bVar1 = TeamFortressViewport::SlotInput(gViewPort,0);
    if (bVar1) {
      return;
    }
  }
  WeaponsResource::SelectSlot
            ((WeaponsResource *)this,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


// CHudAmmo::UserCmd_Slot10  @ 000883e0
/* DWARF original prototype: void UserCmd_Slot10(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Slot10(CHudAmmo *this)

{
  bool bVar1;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    bVar1 = TeamFortressViewport::SlotInput(gViewPort,9);
    if (bVar1) {
      return;
    }
  }
  WeaponsResource::SelectSlot
            ((WeaponsResource *)this,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


// CHudAmmo::UserCmd_Slot2  @ 000881e0
/* DWARF original prototype: void UserCmd_Slot2(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Slot2(CHudAmmo *this)

{
  bool bVar1;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    bVar1 = TeamFortressViewport::SlotInput(gViewPort,1);
    if (bVar1) {
      return;
    }
  }
  WeaponsResource::SelectSlot
            ((WeaponsResource *)this,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


// CHudAmmo::UserCmd_Slot3  @ 00088220
/* DWARF original prototype: void UserCmd_Slot3(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Slot3(CHudAmmo *this)

{
  bool bVar1;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    bVar1 = TeamFortressViewport::SlotInput(gViewPort,2);
    if (bVar1) {
      return;
    }
  }
  WeaponsResource::SelectSlot
            ((WeaponsResource *)this,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


// CHudAmmo::UserCmd_Slot4  @ 00088260
/* DWARF original prototype: void UserCmd_Slot4(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Slot4(CHudAmmo *this)

{
  bool bVar1;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    bVar1 = TeamFortressViewport::SlotInput(gViewPort,3);
    if (bVar1) {
      return;
    }
  }
  WeaponsResource::SelectSlot
            ((WeaponsResource *)this,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


// CHudAmmo::UserCmd_Slot5  @ 000882a0
/* DWARF original prototype: void UserCmd_Slot5(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Slot5(CHudAmmo *this)

{
  bool bVar1;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    bVar1 = TeamFortressViewport::SlotInput(gViewPort,4);
    if (bVar1) {
      return;
    }
  }
  WeaponsResource::SelectSlot
            ((WeaponsResource *)this,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


// CHudAmmo::UserCmd_Slot6  @ 000882e0
/* DWARF original prototype: void UserCmd_Slot6(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Slot6(CHudAmmo *this)

{
  bool bVar1;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    bVar1 = TeamFortressViewport::SlotInput(gViewPort,5);
    if (bVar1) {
      return;
    }
  }
  WeaponsResource::SelectSlot
            ((WeaponsResource *)this,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


// CHudAmmo::UserCmd_Slot7  @ 00088320
/* DWARF original prototype: void UserCmd_Slot7(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Slot7(CHudAmmo *this)

{
  bool bVar1;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    bVar1 = TeamFortressViewport::SlotInput(gViewPort,6);
    if (bVar1) {
      return;
    }
  }
  WeaponsResource::SelectSlot
            ((WeaponsResource *)this,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


// CHudAmmo::UserCmd_Slot8  @ 00088360
/* DWARF original prototype: void UserCmd_Slot8(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Slot8(CHudAmmo *this)

{
  bool bVar1;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    bVar1 = TeamFortressViewport::SlotInput(gViewPort,7);
    if (bVar1) {
      return;
    }
  }
  WeaponsResource::SelectSlot
            ((WeaponsResource *)this,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


// CHudAmmo::UserCmd_Slot9  @ 000883a0
/* DWARF original prototype: void UserCmd_Slot9(CHudAmmo * this) */

void __thiscall CHudAmmo::UserCmd_Slot9(CHudAmmo *this)

{
  bool bVar1;
  int in_stack_00000008;
  int in_stack_0000000c;
  int in_stack_00000010;
  
  if (gViewPort != (TeamFortressViewport *)0x0) {
    bVar1 = TeamFortressViewport::SlotInput(gViewPort,8);
    if (bVar1) {
      return;
    }
  }
  WeaponsResource::SelectSlot
            ((WeaponsResource *)this,in_stack_00000008,in_stack_0000000c,in_stack_00000010);
  return;
}


