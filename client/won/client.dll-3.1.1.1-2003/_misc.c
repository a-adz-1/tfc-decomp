// CBaseMonster::CallMonsterThink  @ 2700ce70
/* public: void __thiscall CBaseMonster::CallMonsterThink(void) */

void __thiscall CBaseMonster::CallMonsterThink(CBaseMonster *this)

{
                    /* 0xce70  214  ?CallMonsterThink@CBaseMonster@@QAEXXZ */
                    /* WARNING: Could not recover jumptable at 0x2700ce72. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x114))();
  return;
}


// CBaseMonster::MonsterUse  @ 2700cc30
/* public: void __thiscall CBaseMonster::MonsterUse(class CBaseEntity *,class CBaseEntity *,enum
   USE_TYPE,float) */

void __thiscall
CBaseMonster::MonsterUse
          (CBaseMonster *this,CBaseEntity *param_1,CBaseEntity *param_2,USE_TYPE param_3,
          float param_4)

{
                    /* 0xcc30  223  ?MonsterUse@CBaseMonster@@QAEXPAVCBaseEntity@@0W4USE_TYPE@@M@Z
                        */
  return;
}


// CBasePlayerAmmo::DefaultTouch  @ 2700c990
/* public: void __thiscall CBasePlayerAmmo::DefaultTouch(class CBaseEntity *) */

void __thiscall CBasePlayerAmmo::DefaultTouch(CBasePlayerAmmo *this,CBaseEntity *param_1)

{
                    /* 0xc990  216  ?DefaultTouch@CBasePlayerAmmo@@QAEXPAVCBaseEntity@@@Z
                       0xc990  217  ?DefaultTouch@CBasePlayerItem@@QAEXPAVCBaseEntity@@@Z
                       0xc990  225  ?PlayerTouch@CBasePlayer@@QAEXPAVCBaseEntity@@@Z
                       0xc990  227  ?RocketTouch@CTFRpgRocket@@QAEXPAVCBaseEntity@@@Z */
  return;
}


// CBasePlayerItem::AttemptToMaterialize  @ 2700cc50
/* public: void __thiscall CBasePlayerItem::AttemptToMaterialize(void) */

void __thiscall CBasePlayerItem::AttemptToMaterialize(CBasePlayerItem *this)

{
                    /* 0xcc50  213  ?AttemptToMaterialize@CBasePlayerItem@@QAEXXZ
                       0xcc50  215  ?CorpseFallThink@CBaseMonster@@QAEXXZ
                       0xcc50  218  ?DestroyItem@CBasePlayerItem@@QAEXXZ
                       0xcc50  219  ?FallThink@CBasePlayerItem@@QAEXXZ
                       0xcc50  220  ?Materialize@CBasePlayerAmmo@@QAEXXZ
                       0xcc50  221  ?Materialize@CBasePlayerItem@@QAEXXZ
                       0xcc50  222  ?MonsterInitThink@CBaseMonster@@QAEXXZ
                       0xcc50  224  ?PlayerDeathThink@CBasePlayer@@QAEXXZ
                       0xcc50  226  ?Revive@CLaserSpot@@QAEXXZ
                       0xcc50  229  ?SUB_Remove@CBaseEntity@@QAEXXZ
                       0xcc50  230  ?Smack@CCrowbar@@QAEXXZ
                       0xcc50  232  ?SwingAgain@CCrowbar@@QAEXXZ
                       0xcc50  233  ?Timer_Tranquilisation@CBaseEntity@@QAEXXZ
                       0xcc50  341  ?performLayout@ScrollBar2@vgui@@MAEXXZ
                       0xcc50  482  HUD_DrawTransparentTriangles */
  return;
}


// CTFAxe::Smack  @ 27010390
/* public: void __thiscall CTFAxe::Smack(void) */

void __thiscall CTFAxe::Smack(CTFAxe *this)

{
                    /* 0x10390  231  ?Smack@CTFAxe@@QAEXXZ */
                    /* WARNING: Could not recover jumptable at 0x27010392. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x18c))();
  return;
}


// CTFNailgunNail::TranqTouch  @ 27015390
/* public: void __thiscall CTFNailgunNail::TranqTouch(class CBaseEntity *) */

void __thiscall CTFNailgunNail::TranqTouch(CTFNailgunNail *this,CBaseEntity *param_1)

{
  int iVar1;
  int iVar2;
  CBasePlayerItem *extraout_ECX;
  CBasePlayerItem *extraout_ECX_00;
  CBasePlayerItem *this_00;
  ulonglong uVar3;
  
                    /* 0x15390  234  ?TranqTouch@CTFNailgunNail@@QAEXPAVCBaseEntity@@@Z */
  if (*(float *)(*(int *)(param_1 + 4) + 0x16c) == 0.0) goto LAB_270154ab;
  iVar1 = *(int *)(*(int *)(this + 4) + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_2707d8b4)(0);
    if (iVar1 != 0) goto LAB_270153ce;
    iVar1 = 0;
  }
  else {
LAB_270153ce:
    iVar1 = *(int *)(iVar1 + 0x7c);
  }
  iVar2 = (**(code **)(*(int *)param_1 + 0x24))();
  if (iVar2 == 2) {
    iVar2 = FUN_2700c9b0();
    this_00 = extraout_ECX;
    if (iVar2 != 0) {
      uVar3 = __ftol();
      this_00 = extraout_ECX_00;
      if ((uVar3 & 0x1e) != 0) goto LAB_27015491;
    }
    if ((char)((uint)*(undefined4 *)(param_1 + 0x78) >> 8) < '\0') {
      iVar2 = FUN_2700c9a0();
      if (iVar2 != 0) {
        *(float *)(*(int *)(iVar2 + 4) + 0x104) = *DAT_2707d9ec + 15.0;
      }
    }
    else {
      CBasePlayerItem::AttemptToMaterialize(this_00);
      *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) | 0x8000;
      iVar2 = FUN_2700c9a0();
      *(float *)(*(int *)(iVar2 + 4) + 0x104) = *DAT_2707d9ec + 15.0;
      *(code **)(iVar2 + 0x10) = CBasePlayerItem::AttemptToMaterialize;
      *(undefined4 *)(iVar2 + 0x114) = *(undefined4 *)(iVar1 + 0x114);
      FUN_2700e6c0((float)param_1);
    }
  }
LAB_27015491:
  (**(code **)(*(int *)param_1 + 0x30))
            (*(undefined4 *)(this + 4),*(undefined4 *)(iVar1 + 4),0x41a00000,0x800004);
LAB_270154ab:
  CBasePlayerItem::AttemptToMaterialize((CBasePlayerItem *)this);
  return;
}


// Catch@2703da4a  @ 2703da4a
undefined4 Catch_2703da4a(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(*(int *)(unaff_EBP + -0x2c) + 0xc4) = 0;
  return 0x2703d151;
}


// CreateInterface  @ 2700c880
undefined4 __cdecl CreateInterface(byte *param_1,undefined4 *param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  bool bVar7;
  
  puVar2 = DAT_2707d79c;
  do {
    if (puVar2 == (undefined4 *)0x0) {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = 1;
      }
      return 0;
    }
    pbVar3 = (byte *)puVar2[1];
    pbVar6 = param_1;
    do {
      bVar1 = *pbVar3;
      bVar7 = bVar1 < *pbVar6;
      if (bVar1 != *pbVar6) {
LAB_2700c8bf:
        iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_2700c8c4;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar7 = bVar1 < pbVar6[1];
      if (bVar1 != pbVar6[1]) goto LAB_2700c8bf;
      pbVar3 = pbVar3 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_2700c8c4:
    if (iVar4 == 0) {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = 0;
      }
      uVar5 = (*(code *)*puVar2)();
      return uVar5;
    }
    puVar2 = (undefined4 *)puVar2[2];
  } while( true );
}


// Initialize  @ 2701df00
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl Initialize(undefined4 *param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char local_200 [512];
  
  puVar3 = param_1;
  puVar4 = &DAT_270a81c8;
                    /* 0x1df00  509  Initialize */
  for (iVar2 = 0x65; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  if (param_2 != 7) {
    return 0;
  }
  puVar3 = &DAT_270a81c8;
  for (iVar2 = 0x65; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_1;
    param_1 = param_1 + 1;
    puVar3 = puVar3 + 1;
  }
  thunk_FUN_2700d0e0();
  iVar2 = (*DAT_270a8334)(s_Bin_TrackerUI_dll_27075c84,local_200,0x200);
  if (iVar2 == 0) {
    DAT_270a8364 = 0;
    _DAT_270a8360 = (HMODULE)0x0;
    return 1;
  }
  FUN_2702fad0(local_200);
  _DAT_270a8360 = (HMODULE)FUN_2700c900(local_200);
  pcVar1 = (code *)FUN_2700c910(_DAT_270a8360);
  if (pcVar1 == (code *)0x0) {
    DAT_270a8364 = 0;
    _DAT_270a8360 = (HMODULE)0x0;
    return 1;
  }
  DAT_270a8364 = (*pcVar1)(s_TrackerUser001_27075c74,0);
  return 1;
}


// Unwind@270542b0  @ 270542b0
void Unwind_270542b0(void)

{
  int unaff_EBP;
  
  FUN_27011010(*(undefined4 *)(unaff_EBP + -0x10),*(int *)(unaff_EBP + 4));
  return;
}


// Unwind@270542d0  @ 270542d0
void Unwind_270542d0(void)

{
  int unaff_EBP;
  
  FUN_27011010(*(undefined4 *)(unaff_EBP + -0x10),*(int *)(unaff_EBP + 4));
  return;
}


// Unwind@270542f0  @ 270542f0
void Unwind_270542f0(void)

{
  int unaff_EBP;
  
  FUN_27011010(*(undefined4 *)(unaff_EBP + -0x10),*(int *)(unaff_EBP + 4));
  return;
}


// Unwind@27054310  @ 27054310
void Unwind_27054310(void)

{
  int unaff_EBP;
  
  FUN_27011010(*(undefined4 *)(unaff_EBP + -0x10),*(int *)(unaff_EBP + 4));
  return;
}


// Unwind@27054330  @ 27054330
void Unwind_27054330(void)

{
  int unaff_EBP;
  
  FUN_27011010(*(undefined4 *)(unaff_EBP + -0x10),*(int *)(unaff_EBP + 4));
  return;
}


// Unwind@27054350  @ 27054350
void Unwind_27054350(void)

{
  int unaff_EBP;
  
  FUN_27011010(*(undefined4 *)(unaff_EBP + -0x10),*(int *)(unaff_EBP + 4));
  return;
}


// Unwind@27054370  @ 27054370
void Unwind_27054370(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0x14));
  return;
}


// Unwind@2705437b  @ 2705437b
void Unwind_2705437b(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@27054386  @ 27054386
void Unwind_27054386(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0x14));
  return;
}


// Unwind@27054391  @ 27054391
void Unwind_27054391(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0x14));
  return;
}


// Unwind@2705439c  @ 2705439c
void Unwind_2705439c(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@270543a7  @ 270543a7
void Unwind_270543a7(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0x14));
  return;
}


// Unwind@270543c0  @ 270543c0
void Unwind_270543c0(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x20));
  return;
}


// Unwind@270543cb  @ 270543cb
void Unwind_270543cb(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x20));
  return;
}


// Unwind@270543d6  @ 270543d6
void Unwind_270543d6(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x20));
  return;
}


// Unwind@270543e1  @ 270543e1
void Unwind_270543e1(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x20));
  return;
}


// Unwind@270543ec  @ 270543ec
void Unwind_270543ec(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x20));
  return;
}


// Unwind@270543f7  @ 270543f7
void Unwind_270543f7(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x20));
  return;
}


// Unwind@27054402  @ 27054402
void Unwind_27054402(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x20));
  return;
}


// Unwind@2705440d  @ 2705440d
void Unwind_2705440d(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x20));
  return;
}


// Unwind@27054418  @ 27054418
void Unwind_27054418(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27054423  @ 27054423
void Unwind_27054423(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@2705442e  @ 2705442e
void Unwind_2705442e(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27054439  @ 27054439
void Unwind_27054439(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27054444  @ 27054444
void Unwind_27054444(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@2705444f  @ 2705444f
void Unwind_2705444f(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@2705445a  @ 2705445a
void Unwind_2705445a(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27054465  @ 27054465
void Unwind_27054465(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27054470  @ 27054470
void Unwind_27054470(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@2705447b  @ 2705447b
void Unwind_2705447b(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27054486  @ 27054486
void Unwind_27054486(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27054491  @ 27054491
void Unwind_27054491(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@2705449c  @ 2705449c
void Unwind_2705449c(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@270544a7  @ 270544a7
void Unwind_270544a7(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@270544b2  @ 270544b2
void Unwind_270544b2(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@270544bd  @ 270544bd
void Unwind_270544bd(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@270544c8  @ 270544c8
void Unwind_270544c8(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@270544d3  @ 270544d3
void Unwind_270544d3(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@270544de  @ 270544de
void Unwind_270544de(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@270544e9  @ 270544e9
void Unwind_270544e9(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@270544f4  @ 270544f4
void Unwind_270544f4(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@270544ff  @ 270544ff
void Unwind_270544ff(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@2705450a  @ 2705450a
void Unwind_2705450a(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27054515  @ 27054515
void Unwind_27054515(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27054520  @ 27054520
void Unwind_27054520(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@2705452b  @ 2705452b
void Unwind_2705452b(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27054536  @ 27054536
void Unwind_27054536(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27054550  @ 27054550
void Unwind_27054550(void)

{
  int unaff_EBP;
  
  FUN_2701e190(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27054570  @ 27054570
void Unwind_27054570(void)

{
  int unaff_EBP;
  
  FUN_2701e190(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27054578  @ 27054578
void Unwind_27054578(void)

{
  int unaff_EBP;
  
  thunk_FUN_270455e0((undefined *)(*(int *)(unaff_EBP + -0x10) + 0x177f8));
  return;
}


// Unwind@27054590  @ 27054590
void Unwind_27054590(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@2705459b  @ 2705459b
void Unwind_2705459b(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@270545a6  @ 270545a6
void Unwind_270545a6(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@270545b1  @ 270545b1
void Unwind_270545b1(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@270545d0  @ 270545d0
void Unwind_270545d0(void)

{
  int unaff_EBP;
  
  FUN_2701e190((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x80));
  return;
}


// Unwind@270545de  @ 270545de
void Unwind_270545de(void)

{
  int unaff_EBP;
  
  FUN_2701e190((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xa8));
  return;
}


// Unwind@270545ec  @ 270545ec
void Unwind_270545ec(void)

{
  int unaff_EBP;
  
  FUN_2701e190((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x1a8));
  return;
}


// Unwind@270545fa  @ 270545fa
void Unwind_270545fa(void)

{
  int unaff_EBP;
  
  FUN_2701e190((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x1428));
  return;
}


// Unwind@27054608  @ 27054608
void Unwind_27054608(void)

{
  int unaff_EBP;
  
  FUN_2701e190((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x1440));
  return;
}


// Unwind@27054616  @ 27054616
void Unwind_27054616(void)

{
  int unaff_EBP;
  
  FUN_2701e190((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x1470));
  return;
}


// Unwind@27054624  @ 27054624
void Unwind_27054624(void)

{
  int unaff_EBP;
  
  FUN_2701e190((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x148c));
  return;
}


// Unwind@27054632  @ 27054632
void Unwind_27054632(void)

{
  int unaff_EBP;
  
  FUN_2701e190((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x14cc));
  return;
}


// Unwind@27054640  @ 27054640
void Unwind_27054640(void)

{
  int unaff_EBP;
  
  FUN_2701e190((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x15b4));
  return;
}


// Unwind@2705464e  @ 2705464e
void Unwind_2705464e(void)

{
  int unaff_EBP;
  
  FUN_2701e190((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x17f4));
  return;
}


// Unwind@2705465c  @ 2705465c
void Unwind_2705465c(void)

{
  int unaff_EBP;
  
  FUN_2701e190((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x180c));
  return;
}


// Unwind@2705466a  @ 2705466a
void Unwind_2705466a(void)

{
  int unaff_EBP;
  
  FUN_2701e190((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x1828));
  return;
}


// Unwind@27054678  @ 27054678
void Unwind_27054678(void)

{
  int unaff_EBP;
  
  FUN_2701e190((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x184c));
  return;
}


// Unwind@27054686  @ 27054686
void Unwind_27054686(void)

{
  int unaff_EBP;
  
  FUN_2701e190((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x1878));
  return;
}


// Unwind@27054694  @ 27054694
void Unwind_27054694(void)

{
  int unaff_EBP;
  
  FUN_2701e190((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x188c));
  return;
}


// Unwind@270546a2  @ 270546a2
void Unwind_270546a2(void)

{
  int unaff_EBP;
  
  FUN_2701e190((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x1960));
  return;
}


// Unwind@270546c0  @ 270546c0
void Unwind_270546c0(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x140));
  return;
}


// Unwind@270546ce  @ 270546ce
void Unwind_270546ce(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x140));
  return;
}


// Unwind@270546dc  @ 270546dc
void Unwind_270546dc(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x140));
  return;
}


// Unwind@270546ea  @ 270546ea
void Unwind_270546ea(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x140));
  return;
}


// Unwind@270546f8  @ 270546f8
void Unwind_270546f8(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x140));
  return;
}


// Unwind@27054706  @ 27054706
void Unwind_27054706(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x140));
  return;
}


// Unwind@27054714  @ 27054714
void Unwind_27054714(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x140));
  return;
}


// Unwind@27054722  @ 27054722
void Unwind_27054722(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x140));
  return;
}


// Unwind@27054730  @ 27054730
void Unwind_27054730(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x13c));
  return;
}


// Unwind@2705473e  @ 2705473e
void Unwind_2705473e(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x140));
  return;
}


// Unwind@27054760  @ 27054760
void Unwind_27054760(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x114));
  return;
}


// Unwind@2705476e  @ 2705476e
void Unwind_2705476e(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x114));
  return;
}


// Unwind@27054790  @ 27054790
void Unwind_27054790(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0xc));
  return;
}


// Unwind@2705479b  @ 2705479b
void Unwind_2705479b(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0xc));
  return;
}


// Unwind@270547a6  @ 270547a6
void Unwind_270547a6(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0xc));
  return;
}


// Unwind@270547b1  @ 270547b1
void Unwind_270547b1(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0xc));
  return;
}


// Unwind@270547bc  @ 270547bc
void Unwind_270547bc(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0xc));
  return;
}


// Unwind@270547c7  @ 270547c7
void Unwind_270547c7(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0xc));
  return;
}


// Unwind@270547e0  @ 270547e0
void Unwind_270547e0(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27054800  @ 27054800
void Unwind_27054800(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 4));
  return;
}


// Unwind@27054820  @ 27054820
void Unwind_27054820(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 4));
  return;
}


// Unwind@27054840  @ 27054840
void Unwind_27054840(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27054860  @ 27054860
void Unwind_27054860(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@2705486b  @ 2705486b
void Unwind_2705486b(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0x20));
  return;
}


// Unwind@27054876  @ 27054876
void Unwind_27054876(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0x20));
  return;
}


// Unwind@27054881  @ 27054881
void Unwind_27054881(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0x10));
  return;
}


// Unwind@2705488c  @ 2705488c
void Unwind_2705488c(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0x20));
  return;
}


// Unwind@27054897  @ 27054897
void Unwind_27054897(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0xc));
  return;
}


// Unwind@270548b0  @ 270548b0
void Unwind_270548b0(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x694));
  return;
}


// Unwind@270548be  @ 270548be
void Unwind_270548be(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x694));
  return;
}


// Unwind@270548e0  @ 270548e0
void Unwind_270548e0(void)

{
  int unaff_EBP;
  
  FUN_270369e0((undefined4 *)(*(int *)(unaff_EBP + -0x24) + 400));
  return;
}


// Unwind@270548ee  @ 270548ee
void Unwind_270548ee(void)

{
  int unaff_EBP;
  
  FUN_270483b1(*(int *)(unaff_EBP + -0x24) + 0x274,0xe8,8,&LAB_2703aee0);
  return;
}


// Unwind@27054909  @ 27054909
void Unwind_27054909(void)

{
  int unaff_EBP;
  
  FUN_27037440((undefined4 *)(*(int *)(unaff_EBP + -0x24) + 0x9bc));
  return;
}


// Unwind@27054917  @ 27054917
void Unwind_27054917(void)

{
  int unaff_EBP;
  
  FUN_270483b1(*(int *)(unaff_EBP + -0x24) + 0xd24,0xe4,0x4a,FUN_270369e0);
  return;
}


// Unwind@27054932  @ 27054932
void Unwind_27054932(void)

{
  int unaff_EBP;
  
  FUN_270483b1(*(int *)(unaff_EBP + -0x24) + 0x4f0c,0xe8,0x250,&LAB_2703aee0);
  return;
}


// Unwind@27054950  @ 27054950
void Unwind_27054950(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@2705495b  @ 2705495b
void Unwind_2705495b(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0x10));
  return;
}


// Unwind@27054970  @ 27054970
void Unwind_27054970(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x20));
  return;
}


// Unwind@2705497b  @ 2705497b
void Unwind_2705497b(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x1c));
  return;
}


// Unwind@27054986  @ 27054986
void Unwind_27054986(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x1c));
  return;
}


// Unwind@270549a0  @ 270549a0
void Unwind_270549a0(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@270549ab  @ 270549ab
void Unwind_270549ab(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@270549b6  @ 270549b6
void Unwind_270549b6(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@270549c1  @ 270549c1
void Unwind_270549c1(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@270549cc  @ 270549cc
void Unwind_270549cc(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@270549d7  @ 270549d7
void Unwind_270549d7(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@270549e2  @ 270549e2
void Unwind_270549e2(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@270549ed  @ 270549ed
void Unwind_270549ed(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0xc));
  return;
}


// Unwind@270549f8  @ 270549f8
void Unwind_270549f8(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0x10));
  return;
}


// Unwind@27054a03  @ 27054a03
void Unwind_27054a03(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0x10));
  return;
}


// Unwind@27054a0e  @ 27054a0e
void Unwind_27054a0e(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0x10));
  return;
}


// Unwind@27054a19  @ 27054a19
void Unwind_27054a19(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0x10));
  return;
}


// Unwind@27054a30  @ 27054a30
void Unwind_27054a30(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0xc));
  return;
}


// Unwind@27054a3b  @ 27054a3b
void Unwind_27054a3b(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + 0x10));
  return;
}


// Unwind@27054a50  @ 27054a50
void Unwind_27054a50(void)

{
  int unaff_EBP;
  
  FUN_27038b00((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x230));
  return;
}


// Unwind@27054a70  @ 27054a70
void Unwind_27054a70(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x34));
  return;
}


// Unwind@27054a7b  @ 27054a7b
void Unwind_27054a7b(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x18));
  return;
}


// Unwind@27054a86  @ 27054a86
void Unwind_27054a86(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x18));
  return;
}


// Unwind@27054a91  @ 27054a91
void Unwind_27054a91(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x18));
  return;
}


// Unwind@27054a9c  @ 27054a9c
void Unwind_27054a9c(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x1c));
  return;
}


// Unwind@27054aa7  @ 27054aa7
void Unwind_27054aa7(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x1c));
  return;
}


// Unwind@27054ab2  @ 27054ab2
void Unwind_27054ab2(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x18));
  return;
}


// Unwind@27054abd  @ 27054abd
void Unwind_27054abd(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x1c));
  return;
}


// Unwind@27054ac8  @ 27054ac8
void Unwind_27054ac8(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x18));
  return;
}


// Unwind@27054ad3  @ 27054ad3
void Unwind_27054ad3(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x1c));
  return;
}


// Unwind@27054ade  @ 27054ade
void Unwind_27054ade(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x18));
  return;
}


// Unwind@27054b00  @ 27054b00
void Unwind_27054b00(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x110));
  return;
}


// Unwind@27054b20  @ 27054b20
void Unwind_27054b20(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x218));
  return;
}


// Unwind@27054b2e  @ 27054b2e
void Unwind_27054b2e(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054b3c  @ 27054b3c
void Unwind_27054b3c(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054b4a  @ 27054b4a
void Unwind_27054b4a(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054b58  @ 27054b58
void Unwind_27054b58(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054b66  @ 27054b66
void Unwind_27054b66(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054b74  @ 27054b74
void Unwind_27054b74(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x218));
  return;
}


// Unwind@27054b82  @ 27054b82
void Unwind_27054b82(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054b90  @ 27054b90
void Unwind_27054b90(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054b9e  @ 27054b9e
void Unwind_27054b9e(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054bac  @ 27054bac
void Unwind_27054bac(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054bba  @ 27054bba
void Unwind_27054bba(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054bc8  @ 27054bc8
void Unwind_27054bc8(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054bd6  @ 27054bd6
void Unwind_27054bd6(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054be4  @ 27054be4
void Unwind_27054be4(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054bf2  @ 27054bf2
void Unwind_27054bf2(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054c00  @ 27054c00
void Unwind_27054c00(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054c0e  @ 27054c0e
void Unwind_27054c0e(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054c1c  @ 27054c1c
void Unwind_27054c1c(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054c2a  @ 27054c2a
void Unwind_27054c2a(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054c38  @ 27054c38
void Unwind_27054c38(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054c46  @ 27054c46
void Unwind_27054c46(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054c54  @ 27054c54
void Unwind_27054c54(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054c62  @ 27054c62
void Unwind_27054c62(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054c70  @ 27054c70
void Unwind_27054c70(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054c7e  @ 27054c7e
void Unwind_27054c7e(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054c8c  @ 27054c8c
void Unwind_27054c8c(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054c9a  @ 27054c9a
void Unwind_27054c9a(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054ca8  @ 27054ca8
void Unwind_27054ca8(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054cb6  @ 27054cb6
void Unwind_27054cb6(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054cc4  @ 27054cc4
void Unwind_27054cc4(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054cd2  @ 27054cd2
void Unwind_27054cd2(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x220));
  return;
}


// Unwind@27054cf0  @ 27054cf0
void Unwind_27054cf0(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27054d10  @ 27054d10
void Unwind_27054d10(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27054d30  @ 27054d30
void Unwind_27054d30(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27054d50  @ 27054d50
void Unwind_27054d50(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27054d70  @ 27054d70
void Unwind_27054d70(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27054d90  @ 27054d90
void Unwind_27054d90(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x11c));
  return;
}


// Unwind@27054d9e  @ 27054d9e
void Unwind_27054d9e(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -300));
  return;
}


// Unwind@27054dac  @ 27054dac
void Unwind_27054dac(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -300));
  return;
}


// Unwind@27054dba  @ 27054dba
void Unwind_27054dba(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -300));
  return;
}


// Unwind@27054dc8  @ 27054dc8
void Unwind_27054dc8(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -300));
  return;
}


// Unwind@27054dd6  @ 27054dd6
void Unwind_27054dd6(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -300));
  return;
}


// Unwind@27054de4  @ 27054de4
void Unwind_27054de4(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x124));
  return;
}


// Unwind@27054df2  @ 27054df2
void Unwind_27054df2(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -0x120));
  return;
}


// Unwind@27054e00  @ 27054e00
void Unwind_27054e00(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -300));
  return;
}


// Unwind@27054e0e  @ 27054e0e
void Unwind_27054e0e(void)

{
  int unaff_EBP;
  
  FUN_27046acb(*(undefined **)(unaff_EBP + -300));
  return;
}


// entry  @ 27048ac1
int entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2;
  iVar2 = DAT_270c3288;
  if (param_2 != 0) {
    if ((param_2 != 1) && (param_2 != 2)) goto LAB_27048b09;
    if ((DAT_270c498c != (code *)0x0) &&
       (iVar2 = (*DAT_270c498c)(param_1,param_2,param_3), iVar2 == 0)) {
      return 0;
    }
    iVar2 = FUN_270489e8(param_1,param_2);
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_27048b09:
  iVar2 = FUN_2704fcad();
  if (param_2 == 1) {
    if (iVar2 != 0) {
      return iVar2;
    }
    FUN_270489e8(param_1,0);
  }
  if ((param_2 != 0) && (param_2 != 3)) {
    return iVar2;
  }
  iVar3 = FUN_270489e8(param_1,param_2);
  param_2 = iVar2;
  if (iVar3 == 0) {
    param_2 = 0;
  }
  if (param_2 != 0) {
    if (DAT_270c498c != (code *)0x0) {
      iVar2 = (*DAT_270c498c)(param_1,iVar1,param_3);
      return iVar2;
    }
    return param_2;
  }
  return 0;
}


// vgui::ActionSignal::ActionSignal  @ 2700ae40
/* public: __thiscall vgui::ActionSignal::ActionSignal(void) */

void __thiscall vgui::ActionSignal::ActionSignal(ActionSignal *this)

{
                    /* 0xae40  38  ??0ActionSignal@vgui@@QAE@XZ */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::ActionSignal::ActionSignal  @ 2700ae50
/* public: __thiscall vgui::ActionSignal::ActionSignal(class vgui::ActionSignal const &) */

void __thiscall vgui::ActionSignal::ActionSignal(ActionSignal *this,ActionSignal *param_1)

{
                    /* 0xae50  37  ??0ActionSignal@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::ActionSignal::operator=  @ 270034c0
/* public: class vgui::ActionSignal & __thiscall vgui::ActionSignal::operator=(class
   vgui::ActionSignal const &) */

ActionSignal * __thiscall vgui::ActionSignal::operator=(ActionSignal *this,ActionSignal *param_1)

{
                    /* 0x34c0  106  ??4ActionSignal@vgui@@QAEAAV01@ABV01@@Z
                       0x34c0  124  ??4InputSignal@vgui@@QAEAAV01@ABV01@@Z
                       0x34c0  125  ??4InputStream@vgui@@QAEAAV01@ABV01@@Z
                       0x34c0  126  ??4IntChangeSignal@vgui@@QAEAAV01@ABV01@@Z
                       0x34c0  128  ??4Layout@vgui@@QAEAAV01@ABV01@@Z */
  return this;
}


// vgui::App::App  @ 2700b5b0
/* public: __thiscall vgui::App::App(class vgui::App const &) */

void __thiscall vgui::App::App(App *this,App *param_1)

{
  int iVar1;
  App *pAVar2;
  App *pAVar3;
  
                    /* 0xb5b0  39  ??0App@vgui@@QAE@ABV01@@Z */
  this[4] = param_1[4];
  this[5] = param_1[5];
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined2 *)(this + 0x28) = *(undefined2 *)(param_1 + 0x28);
  this[0x2a] = param_1[0x2a];
  *(undefined2 *)(this + 0x2b) = *(undefined2 *)(param_1 + 0x2b);
  this[0x2d] = param_1[0x2d];
  *(undefined2 *)(this + 0x2e) = *(undefined2 *)(param_1 + 0x2e);
  this[0x30] = param_1[0x30];
  *(undefined2 *)(this + 0x31) = *(undefined2 *)(param_1 + 0x31);
  this[0x33] = param_1[0x33];
  pAVar2 = param_1 + 0x34;
  pAVar3 = this + 0x34;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pAVar3 = *(undefined4 *)pAVar2;
    pAVar2 = pAVar2 + 4;
    pAVar3 = pAVar3 + 4;
  }
  *(undefined2 *)pAVar3 = *(undefined2 *)pAVar2;
  pAVar3[2] = pAVar2[2];
  pAVar2 = param_1 + 0x9b;
  pAVar3 = this + 0x9b;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pAVar3 = *(undefined4 *)pAVar2;
    pAVar2 = pAVar2 + 4;
    pAVar3 = pAVar3 + 4;
  }
  *(undefined2 *)pAVar3 = *(undefined2 *)pAVar2;
  pAVar3[2] = pAVar2[2];
  pAVar2 = param_1 + 0x102;
  pAVar3 = this + 0x102;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pAVar3 = *(undefined4 *)pAVar2;
    pAVar2 = pAVar2 + 4;
    pAVar3 = pAVar3 + 4;
  }
  *(undefined2 *)pAVar3 = *(undefined2 *)pAVar2;
  pAVar3[2] = pAVar2[2];
  pAVar2 = param_1 + 0x169;
  pAVar3 = this + 0x169;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pAVar3 = *(undefined4 *)pAVar2;
    pAVar2 = pAVar2 + 4;
    pAVar3 = pAVar3 + 4;
  }
  *(undefined2 *)pAVar3 = *(undefined2 *)pAVar2;
  pAVar3[2] = pAVar2[2];
  *(undefined4 *)(this + 0x1d0) = *(undefined4 *)(param_1 + 0x1d0);
  *(undefined4 *)(this + 0x1d4) = *(undefined4 *)(param_1 + 0x1d4);
  *(undefined4 *)(this + 0x1d8) = *(undefined4 *)(param_1 + 0x1d8);
  *(undefined4 *)(this + 0x1dc) = *(undefined4 *)(param_1 + 0x1dc);
  this[0x1e0] = param_1[0x1e0];
  this[0x1e1] = param_1[0x1e1];
  *(undefined4 *)(this + 0x1e4) = *(undefined4 *)(param_1 + 0x1e4);
  pAVar2 = param_1 + 0x1e8;
  pAVar3 = this + 0x1e8;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pAVar3 = *(undefined4 *)pAVar2;
    pAVar2 = pAVar2 + 4;
    pAVar3 = pAVar3 + 4;
  }
  *(undefined4 *)(this + 0x220) = *(undefined4 *)(param_1 + 0x220);
  *(undefined4 *)(this + 0x224) = *(undefined4 *)(param_1 + 0x224);
  *(undefined4 *)(this + 0x228) = *(undefined4 *)(param_1 + 0x228);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::App::operator=  @ 2700b7f0
/* public: class vgui::App & __thiscall vgui::App::operator=(class vgui::App const &) */

App * __thiscall vgui::App::operator=(App *this,App *param_1)

{
  int iVar1;
  App *pAVar2;
  int iVar3;
  
                    /* 0xb7f0  107  ??4App@vgui@@QAEAAV01@ABV01@@Z */
  this[4] = param_1[4];
  this[5] = param_1[5];
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  pAVar2 = this + 0x28;
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  iVar1 = (int)param_1 - (int)this;
  do {
    *pAVar2 = pAVar2[iVar1];
    pAVar2 = pAVar2 + 1;
  } while (pAVar2 + (-0x28 - (int)this) < (App *)0x3);
  pAVar2 = this + 0x2b;
  do {
    *pAVar2 = pAVar2[iVar1];
    pAVar2 = pAVar2 + 1;
  } while (pAVar2 + (-0x2b - (int)this) < (App *)0x3);
  pAVar2 = this + 0x2e;
  do {
    *pAVar2 = pAVar2[iVar1];
    pAVar2 = pAVar2 + 1;
  } while (pAVar2 + (-0x2e - (int)this) < (App *)0x3);
  pAVar2 = this + 0x31;
  do {
    *pAVar2 = pAVar2[iVar1];
    pAVar2 = pAVar2 + 1;
  } while (pAVar2 + (-0x31 - (int)this) < (App *)0x3);
  pAVar2 = this + 0x34;
  do {
    *pAVar2 = pAVar2[iVar1];
    pAVar2 = pAVar2 + 1;
  } while (pAVar2 + (-0x34 - (int)this) < (App *)0x67);
  pAVar2 = this + 0x9b;
  do {
    *pAVar2 = pAVar2[iVar1];
    pAVar2 = pAVar2 + 1;
  } while (pAVar2 + (-0x9b - (int)this) < (App *)0x67);
  pAVar2 = this + 0x102;
  do {
    *pAVar2 = pAVar2[iVar1];
    pAVar2 = pAVar2 + 1;
  } while (pAVar2 + (-0x102 - (int)this) < (App *)0x67);
  pAVar2 = this + 0x169;
  do {
    *pAVar2 = pAVar2[iVar1];
    pAVar2 = pAVar2 + 1;
  } while (pAVar2 + (-0x169 - (int)this) < (App *)0x67);
  *(undefined4 *)(this + 0x1d0) = *(undefined4 *)(param_1 + 0x1d0);
  *(undefined4 *)(this + 0x1d4) = *(undefined4 *)(param_1 + 0x1d4);
  *(undefined4 *)(this + 0x1d8) = *(undefined4 *)(param_1 + 0x1d8);
  *(undefined4 *)(this + 0x1dc) = *(undefined4 *)(param_1 + 0x1dc);
  this[0x1e0] = param_1[0x1e0];
  this[0x1e1] = param_1[0x1e1];
  *(undefined4 *)(this + 0x1e4) = *(undefined4 *)(param_1 + 0x1e4);
  pAVar2 = this + 0x1e8;
  iVar3 = 0xe;
  do {
    *(undefined4 *)pAVar2 = *(undefined4 *)(pAVar2 + iVar1);
    pAVar2 = pAVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x220) = *(undefined4 *)(param_1 + 0x220);
  *(undefined4 *)(this + 0x224) = *(undefined4 *)(param_1 + 0x224);
  *(undefined4 *)(this + 0x228) = *(undefined4 *)(param_1 + 0x228);
  return this;
}


// vgui::Bitmap::Bitmap  @ 27003260
/* public: __thiscall vgui::Bitmap::Bitmap(class vgui::Bitmap const &) */

void __thiscall vgui::Bitmap::Bitmap(Bitmap *this,Bitmap *param_1)

{
                    /* 0x3260  40  ??0Bitmap@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined ***)(this + 0x18) = &Color::_vftable_;
  *(undefined ***)this = &Image::_vftable_;
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  this[0x28] = param_1[0x28];
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Bitmap::operator=  @ 270032c0
/* public: class vgui::Bitmap & __thiscall vgui::Bitmap::operator=(class vgui::Bitmap const &) */

Bitmap * __thiscall vgui::Bitmap::operator=(Bitmap *this,Bitmap *param_1)

{
  Bitmap *pBVar1;
  int iVar2;
  
                    /* 0x32c0  108  ??4Bitmap@vgui@@QAEAAV01@ABV01@@Z
                       0x32c0  109  ??4BitmapTGA@vgui@@QAEAAV01@ABV01@@Z */
  iVar2 = 2;
  pBVar1 = this;
  do {
    pBVar1 = pBVar1 + 4;
    *(undefined4 *)pBVar1 = *(undefined4 *)(pBVar1 + ((int)param_1 - (int)this));
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  pBVar1 = this + 0xc;
  iVar2 = 2;
  do {
    *(undefined4 *)pBVar1 = *(undefined4 *)(pBVar1 + ((int)param_1 - (int)this));
    pBVar1 = pBVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  pBVar1 = this + 0x1c;
  do {
    *pBVar1 = pBVar1[(int)(param_1 + (0x18 - (int)(this + 0x18)))];
    pBVar1 = pBVar1 + 1;
  } while (pBVar1 + (-4 - (int)(this + 0x18)) < (Bitmap *)0x4);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  this[0x28] = param_1[0x28];
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  return this;
}


// vgui::BitmapTGA::BitmapTGA  @ 27003340
/* public: __thiscall vgui::BitmapTGA::BitmapTGA(class vgui::BitmapTGA const &) */

void __thiscall vgui::BitmapTGA::BitmapTGA(BitmapTGA *this,BitmapTGA *param_1)

{
                    /* 0x3340  41  ??0BitmapTGA@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined ***)(this + 0x18) = &Color::_vftable_;
  *(undefined ***)this = &Image::_vftable_;
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  this[0x28] = param_1[0x28];
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Border::Border  @ 27002c00
/* public: __thiscall vgui::Border::Border(class vgui::Border const &) */

void __thiscall vgui::Border::Border(Border *this,Border *param_1)

{
                    /* 0x2c00  42  ??0Border@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined ***)(this + 0x18) = &Color::_vftable_;
  *(undefined ***)this = &Image::_vftable_;
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Border::operator=  @ 2703dce0
/* public: class vgui::Border & __thiscall vgui::Border::operator=(class vgui::Border const &) */

Border * __thiscall vgui::Border::operator=(Border *this,Border *param_1)

{
  int iVar1;
  Border *pBVar2;
  int iVar3;
  
                    /* 0x3dce0  110  ??4Border@vgui@@QAEAAV01@ABV01@@Z
                       0x3dce0  130  ??4LoweredBorder@vgui@@QAEAAV01@ABV01@@Z */
  iVar3 = (int)param_1 - (int)this;
  iVar1 = 2;
  pBVar2 = this;
  do {
    pBVar2 = pBVar2 + 4;
    *(undefined4 *)pBVar2 = *(undefined4 *)(pBVar2 + iVar3);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  pBVar2 = this + 0xc;
  iVar1 = 2;
  do {
    *(undefined4 *)pBVar2 = *(undefined4 *)(pBVar2 + iVar3);
    pBVar2 = pBVar2 + 4;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  pBVar2 = this + 0x1c;
  do {
    *pBVar2 = pBVar2[(int)(param_1 + (0x18 - (int)(this + 0x18)))];
    pBVar2 = pBVar2 + 1;
  } while (pBVar2 + (-4 - (int)(this + 0x18)) < (Border *)0x4);
  iVar1 = 4;
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  pBVar2 = this + 0x24;
  do {
    *(undefined4 *)pBVar2 = *(undefined4 *)(pBVar2 + iVar3);
    pBVar2 = pBVar2 + 4;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  return this;
}


// vgui::BorderLayout::BorderLayout  @ 27037270
/* public: __thiscall vgui::BorderLayout::BorderLayout(class vgui::BorderLayout const &) */

void __thiscall vgui::BorderLayout::BorderLayout(BorderLayout *this,BorderLayout *param_1)

{
                    /* 0x37270  43  ??0BorderLayout@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &Layout::_vftable_;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::BorderLayout::operator=  @ 27037290
/* public: class vgui::BorderLayout & __thiscall vgui::BorderLayout::operator=(class
   vgui::BorderLayout const &) */

BorderLayout * __thiscall vgui::BorderLayout::operator=(BorderLayout *this,BorderLayout *param_1)

{
                    /* 0x37290  111  ??4BorderLayout@vgui@@QAEAAV01@ABV01@@Z
                       0x37290  118  ??4FileInputStream@vgui@@QAEAAV01@ABV01@@Z
                       0x37290  132  ??4MiniApp@vgui@@QAEAAV01@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  return this;
}


// vgui::BuildGroup::BuildGroup  @ 2703df00
/* public: __thiscall vgui::BuildGroup::BuildGroup(class vgui::BuildGroup const &) */

void __thiscall vgui::BuildGroup::BuildGroup(BuildGroup *this,BuildGroup *param_1)

{
  undefined4 uVar1;
  
                    /* 0x3df00  44  ??0BuildGroup@vgui@@QAE@ABV01@@Z */
  this[4] = param_1[4];
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  this[0x24] = param_1[0x24];
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  uVar1 = *(undefined4 *)(param_1 + 0x60);
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0x60) = uVar1;
  return;
}


// vgui::BuildGroup::operator=  @ 2703dfc0
/* public: class vgui::BuildGroup & __thiscall vgui::BuildGroup::operator=(class vgui::BuildGroup
   const &) */

BuildGroup * __thiscall vgui::BuildGroup::operator=(BuildGroup *this,BuildGroup *param_1)

{
  BuildGroup *pBVar1;
  int iVar2;
  
                    /* 0x3dfc0  112  ??4BuildGroup@vgui@@QAEAAV01@ABV01@@Z */
  this[4] = param_1[4];
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  this[0x24] = param_1[0x24];
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  pBVar1 = this + 0x2c;
  iVar2 = 2;
  do {
    *(undefined4 *)pBVar1 = *(undefined4 *)(pBVar1 + ((int)param_1 - (int)this));
    pBVar1 = pBVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  pBVar1 = this + 0x34;
  iVar2 = 2;
  do {
    *(undefined4 *)pBVar1 = *(undefined4 *)(pBVar1 + ((int)param_1 - (int)this));
    pBVar1 = pBVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
  return this;
}


// vgui::Button::Button  @ 270034d0
/* public: __thiscall vgui::Button::Button(class vgui::Button const &) */

void __thiscall vgui::Button::Button(Button *this,Button *param_1)

{
                    /* 0x34d0  45  ??0Button@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(this + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined ***)(this + 0x9c) = &Color::_vftable_;
  *(undefined4 *)(this + 0xac) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined ***)(this + 0xa8) = &Color::_vftable_;
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined ***)this = &Panel::_vftable_;
  this[0xbc] = param_1[0xbc];
  this[0xbd] = param_1[0xbd];
  this[0xbe] = param_1[0xbe];
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)(this + 200) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined ***)this = &Label::_vftable_;
  *(undefined4 *)(this + 0xd0) = *(undefined4 *)(param_1 + 0xd0);
  this[0xd4] = param_1[0xd4];
  this[0xd5] = param_1[0xd5];
  this[0xd6] = param_1[0xd6];
  *(undefined4 *)(this + 0xd8) = *(undefined4 *)(param_1 + 0xd8);
  *(undefined4 *)(this + 0xdc) = *(undefined4 *)(param_1 + 0xdc);
  *(undefined4 *)(this + 0xe0) = *(undefined4 *)(param_1 + 0xe0);
  *(undefined4 *)(this + 0xe4) = *(undefined4 *)(param_1 + 0xe4);
  *(undefined4 *)(this + 0xe8) = *(undefined4 *)(param_1 + 0xe8);
  *(undefined4 *)(this + 0xec) = *(undefined4 *)(param_1 + 0xec);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Button::operator=  @ 27003820
/* public: class vgui::Button & __thiscall vgui::Button::operator=(class vgui::Button const &) */

Button * __thiscall vgui::Button::operator=(Button *this,Button *param_1)

{
  int iVar1;
  Button *pBVar2;
  int iVar3;
  
                    /* 0x3820  113  ??4Button@vgui@@QAEAAV01@ABV01@@Z */
  iVar1 = (int)param_1 - (int)this;
  iVar3 = 2;
  pBVar2 = this;
  do {
    pBVar2 = pBVar2 + 4;
    *(undefined4 *)pBVar2 = *(undefined4 *)(pBVar2 + iVar1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pBVar2 = this + 0xc;
  iVar3 = 2;
  do {
    *(undefined4 *)pBVar2 = *(undefined4 *)(pBVar2 + iVar1);
    pBVar2 = pBVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pBVar2 = this + 0x14;
  iVar3 = 2;
  do {
    *(undefined4 *)pBVar2 = *(undefined4 *)(pBVar2 + iVar1);
    pBVar2 = pBVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pBVar2 = this + 0x1c;
  iVar3 = 2;
  do {
    *(undefined4 *)pBVar2 = *(undefined4 *)(pBVar2 + iVar1);
    pBVar2 = pBVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pBVar2 = this + 0x24;
  iVar3 = 2;
  do {
    *(undefined4 *)pBVar2 = *(undefined4 *)(pBVar2 + iVar1);
    pBVar2 = pBVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  pBVar2 = this + 0x58;
  iVar3 = 4;
  do {
    *(undefined4 *)pBVar2 = *(undefined4 *)(pBVar2 + iVar1);
    pBVar2 = pBVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  pBVar2 = this + 0xa0;
  do {
    *pBVar2 = pBVar2[(int)(param_1 + (0x9c - (int)(this + 0x9c)))];
    pBVar2 = pBVar2 + 1;
  } while (pBVar2 + (-4 - (int)(this + 0x9c)) < (Button *)0x4);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  pBVar2 = this + 0xac;
  do {
    *pBVar2 = pBVar2[(int)(param_1 + (0xa8 - (int)(this + 0xa8)))];
    pBVar2 = pBVar2 + 1;
  } while (pBVar2 + (-4 - (int)(this + 0xa8)) < (Button *)0x4);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  this[0xbc] = param_1[0xbc];
  this[0xbd] = param_1[0xbd];
  this[0xbe] = param_1[0xbe];
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)(this + 200) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined4 *)(this + 0xd0) = *(undefined4 *)(param_1 + 0xd0);
  this[0xd4] = param_1[0xd4];
  this[0xd5] = param_1[0xd5];
  this[0xd6] = param_1[0xd6];
  *(undefined4 *)(this + 0xd8) = *(undefined4 *)(param_1 + 0xd8);
  *(undefined4 *)(this + 0xdc) = *(undefined4 *)(param_1 + 0xdc);
  *(undefined4 *)(this + 0xe0) = *(undefined4 *)(param_1 + 0xe0);
  *(undefined4 *)(this + 0xe4) = *(undefined4 *)(param_1 + 0xe4);
  *(undefined4 *)(this + 0xe8) = *(undefined4 *)(param_1 + 0xe8);
  *(undefined4 *)(this + 0xec) = *(undefined4 *)(param_1 + 0xec);
  return this;
}


// vgui::Color::Color  @ 27002010
/* public: __thiscall vgui::Color::Color(class vgui::Color const &) */

void __thiscall vgui::Color::Color(Color *this,Color *param_1)

{
                    /* 0x2010  46  ??0Color@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Color::operator=  @ 27002030
/* public: class vgui::Color & __thiscall vgui::Color::operator=(class vgui::Color const &) */

Color * __thiscall vgui::Color::operator=(Color *this,Color *param_1)

{
  Color *pCVar1;
  
                    /* 0x2030  114  ??4Color@vgui@@QAEAAV01@ABV01@@Z */
  pCVar1 = this + 4;
  do {
    *pCVar1 = pCVar1[(int)param_1 - (int)this];
    pCVar1 = pCVar1 + 1;
  } while (pCVar1 + (-4 - (int)this) < (Color *)0x4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  return this;
}


// vgui::Cursor::Cursor  @ 2700b540
/* public: __thiscall vgui::Cursor::Cursor(class vgui::Cursor const &) */

void __thiscall vgui::Cursor::Cursor(Cursor *this,Cursor *param_1)

{
                    /* 0xb540  47  ??0Cursor@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Cursor::operator=  @ 2700b570
/* public: class vgui::Cursor & __thiscall vgui::Cursor::operator=(class vgui::Cursor const &) */

Cursor * __thiscall vgui::Cursor::operator=(Cursor *this,Cursor *param_1)

{
  int iVar1;
  Cursor *pCVar2;
  
                    /* 0xb570  115  ??4Cursor@vgui@@QAEAAV01@ABV01@@Z */
  iVar1 = 2;
  pCVar2 = this;
  do {
    pCVar2 = pCVar2 + 4;
    *(undefined4 *)pCVar2 = *(undefined4 *)(pCVar2 + ((int)param_1 - (int)this));
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  return this;
}


// vgui::Dar<char>::Dar<char>  @ 27007250
/* public: __thiscall vgui::Dar<char>::Dar<char>(void) */

Dar<char> * __thiscall vgui::Dar<char>::Dar<char>(Dar<char> *this)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
                    /* 0x7250  2  ??0?$Dar@D@vgui@@QAE@XZ */
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  uVar1 = 1;
  do {
    uVar5 = uVar1;
    uVar1 = uVar5 * 2;
  } while ((int)uVar1 < 4);
  puVar2 = operator_new(uVar1);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_27046b03(0);
  }
  puVar6 = puVar2;
  for (uVar5 = (uVar5 & 0x7fffffff) >> 1; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  for (uVar5 = uVar1 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined1 *)puVar6 = 0;
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  *(uint *)(this + 4) = uVar1;
  iVar3 = 0;
  if (0 < *(int *)this) {
    do {
      iVar4 = iVar3 + 1;
      *(undefined1 *)(iVar3 + (int)puVar2) = *(undefined1 *)(iVar3 + *(int *)(this + 8));
      iVar3 = iVar4;
    } while (iVar4 < *(int *)this);
  }
  FUN_27046acb(*(undefined **)(this + 8));
  *(undefined4 **)(this + 8) = puVar2;
  return this;
}


// vgui::Dar<char>::Dar<char>  @ 270072d0
/* public: __thiscall vgui::Dar<char>::Dar<char>(int) */

Dar<char> * __thiscall vgui::Dar<char>::Dar<char>(Dar<char> *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  
                    /* 0x72d0  1  ??0?$Dar@D@vgui@@QAE@H@Z */
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  if (0 < param_1) {
    uVar5 = 1;
    if (1 < param_1) {
      do {
        uVar5 = uVar5 * 2;
      } while ((int)uVar5 < param_1);
    }
    puVar1 = operator_new(uVar5);
    if (puVar1 == (undefined4 *)0x0) {
      FUN_27046b03(0);
    }
    puVar6 = puVar1;
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    for (uVar4 = uVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar6 = 0;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    *(uint *)(this + 4) = uVar5;
    iVar2 = 0;
    if (0 < *(int *)this) {
      do {
        iVar3 = iVar2 + 1;
        *(undefined1 *)(iVar2 + (int)puVar1) = *(undefined1 *)(iVar2 + *(int *)(this + 8));
        iVar2 = iVar3;
      } while (iVar3 < *(int *)this);
    }
    FUN_27046acb(*(undefined **)(this + 8));
    *(undefined4 **)(this + 8) = puVar1;
  }
  return this;
}


// vgui::Dar<char>::addElement  @ 270073f0
/* public: void __thiscall vgui::Dar<char>::addElement(char) */

void __thiscall vgui::Dar<char>::addElement(Dar<char> *this,char param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined1 unaff_retaddr;
  
                    /* 0x73f0  235  ?addElement@?$Dar@D@vgui@@QAEXD@Z */
  uVar5 = *(uint *)(this + 4);
  if ((int)uVar5 < *(int *)this + 1) {
    if (uVar5 == 0) {
      uVar5 = 1;
    }
    for (; (int)uVar5 < *(int *)this + 1; uVar5 = uVar5 * 2) {
    }
    puVar1 = operator_new(uVar5);
    if (puVar1 == (undefined4 *)0x0) {
      FUN_27046b03(0);
    }
    puVar6 = puVar1;
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    for (uVar4 = uVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar6 = 0;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    *(uint *)(this + 4) = uVar5;
    iVar2 = 0;
    if (0 < *(int *)this) {
      do {
        iVar3 = iVar2 + 1;
        *(undefined1 *)(iVar2 + (int)puVar1) = *(undefined1 *)(iVar2 + *(int *)(this + 8));
        iVar2 = iVar3;
      } while (iVar3 < *(int *)this);
    }
    FUN_27046acb(*(undefined **)(this + 8));
    *(undefined4 **)(this + 8) = puVar1;
  }
  *(undefined1 *)(*(int *)(this + 8) + *(int *)this) = unaff_retaddr;
  *(int *)this = *(int *)this + 1;
  return;
}


// vgui::Dar<char>::ensureCapacity  @ 27007360
/* public: void __thiscall vgui::Dar<char>::ensureCapacity(int) */

void __thiscall vgui::Dar<char>::ensureCapacity(Dar<char> *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  
                    /* 0x7360  256  ?ensureCapacity@?$Dar@D@vgui@@QAEXH@Z */
  uVar5 = *(uint *)(this + 4);
  if ((int)uVar5 < param_1) {
    if (uVar5 == 0) {
      uVar5 = 1;
    }
    for (; (int)uVar5 < param_1; uVar5 = uVar5 * 2) {
    }
    puVar1 = operator_new(uVar5);
    if (puVar1 == (undefined4 *)0x0) {
      FUN_27046b03(0);
    }
    puVar6 = puVar1;
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    for (uVar4 = uVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar6 = 0;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    *(uint *)(this + 4) = uVar5;
    iVar2 = 0;
    if (0 < *(int *)this) {
      do {
        iVar3 = iVar2 + 1;
        *(undefined1 *)(iVar2 + (int)puVar1) = *(undefined1 *)(iVar2 + *(int *)(this + 8));
        iVar2 = iVar3;
      } while (iVar3 < *(int *)this);
    }
    FUN_27046acb(*(undefined **)(this + 8));
    *(undefined4 **)(this + 8) = puVar1;
  }
  return;
}


// vgui::Dar<char>::getCount  @ 270073e0
/* public: int __thiscall vgui::Dar<char>::getCount(void) */

int __thiscall vgui::Dar<char>::getCount(Dar<char> *this)

{
                    /* 0x73e0  277  ?getCount@?$Dar@D@vgui@@QAEHXZ
                       0x73e0  278  ?getCount@?$Dar@H@vgui@@QAEHXZ
                       0x73e0  279  ?getCount@?$Dar@PAD@vgui@@QAEHXZ
                       0x73e0  280  ?getCount@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEHXZ
                       0x73e0  281  ?getCount@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEHXZ
                       0x73e0  282  ?getCount@?$Dar@PAVButton@vgui@@@vgui@@QAEHXZ
                       0x73e0  283  ?getCount@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEHXZ
                       0x73e0  284  ?getCount@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEHXZ
                       0x73e0  285  ?getCount@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEHXZ
                       0x73e0  286  ?getCount@?$Dar@PAVFrame@vgui@@@vgui@@QAEHXZ
                       0x73e0  287  ?getCount@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEHXZ
                       0x73e0  288  ?getCount@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEHXZ
                       0x73e0  289  ?getCount@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEHXZ
                       0x73e0  290  ?getCount@?$Dar@PAVLabel@vgui@@@vgui@@QAEHXZ
                       0x73e0  291  ?getCount@?$Dar@PAVPanel@vgui@@@vgui@@QAEHXZ
                       0x73e0  292  ?getCount@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEHXZ
                       0x73e0  293  ?getCount@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEHXZ
                       0x73e0  294  ?getCount@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEHXZ */
  return *(int *)this;
}


// vgui::Dar<char>::hasElement  @ 27007480
/* public: bool __thiscall vgui::Dar<char>::hasElement(char) */

bool __thiscall vgui::Dar<char>::hasElement(Dar<char> *this,char param_1)

{
  int iVar1;
  
                    /* 0x7480  300  ?hasElement@?$Dar@D@vgui@@QAE_ND@Z */
  iVar1 = 0;
  if (0 < *(int *)this) {
    do {
      if (*(char *)(*(int *)(this + 8) + iVar1) == param_1) {
        return true;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)this);
  }
  return false;
}


// vgui::Dar<char>::insertElementAt  @ 27007560
/* public: void __thiscall vgui::Dar<char>::insertElementAt(char,int) */

void __thiscall vgui::Dar<char>::insertElementAt(Dar<char> *this,char param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined1 unaff_retaddr;
  undefined3 in_stack_00000005;
  
                    /* 0x7560  320  ?insertElementAt@?$Dar@D@vgui@@QAEXDH@Z */
  if (-1 < param_2) {
    iVar3 = *(int *)this;
    if (param_2 == iVar3 || param_2 < iVar3) {
      if ((param_2 != iVar3) && (iVar3 != 0)) {
        uVar5 = *(uint *)(this + 4);
        if ((int)uVar5 < iVar3 + 1) {
          if (uVar5 == 0) {
            uVar5 = 1;
          }
          for (; (int)uVar5 < iVar3 + 1; uVar5 = uVar5 * 2) {
          }
          puVar1 = operator_new(uVar5);
          if (puVar1 == (undefined4 *)0x0) {
            FUN_27046b03(0);
          }
          puVar6 = puVar1;
          for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar6 = 0;
            puVar6 = puVar6 + 1;
          }
          for (uVar4 = uVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined1 *)puVar6 = 0;
            puVar6 = (undefined4 *)((int)puVar6 + 1);
          }
          *(uint *)(this + 4) = uVar5;
          iVar3 = 0;
          if (0 < *(int *)this) {
            do {
              iVar2 = iVar3 + 1;
              *(undefined1 *)(iVar3 + (int)puVar1) = *(undefined1 *)(iVar3 + *(int *)(this + 8));
              iVar3 = iVar2;
            } while (iVar2 < *(int *)this);
          }
          FUN_27046acb(*(undefined **)(this + 8));
          *(undefined4 **)(this + 8) = puVar1;
          param_2 = _param_1;
        }
        *(undefined1 *)(*(int *)(this + 8) + *(int *)this) = unaff_retaddr;
        iVar3 = *(int *)this;
        *(int *)this = iVar3 + 1;
        for (; param_2 < iVar3; iVar3 = iVar3 + -1) {
          *(undefined1 *)(*(int *)(this + 8) + iVar3) =
               ((undefined1 *)(*(int *)(this + 8) + iVar3))[-1];
        }
        *(undefined1 *)(param_2 + *(int *)(this + 8)) = unaff_retaddr;
        return;
      }
      uVar5 = *(uint *)(this + 4);
      if ((int)uVar5 < iVar3 + 1) {
        if (uVar5 == 0) {
          uVar5 = 1;
        }
        for (; (int)uVar5 < iVar3 + 1; uVar5 = uVar5 * 2) {
        }
        puVar1 = operator_new(uVar5);
        if (puVar1 == (undefined4 *)0x0) {
          FUN_27046b03(0);
        }
        puVar6 = puVar1;
        for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
        for (uVar4 = uVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar6 = 0;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        }
        *(uint *)(this + 4) = uVar5;
        iVar3 = 0;
        if (0 < *(int *)this) {
          do {
            iVar2 = iVar3 + 1;
            *(undefined1 *)(iVar3 + (int)puVar1) = *(undefined1 *)(iVar3 + *(int *)(this + 8));
            iVar3 = iVar2;
          } while (iVar2 < *(int *)this);
        }
        FUN_27046acb(*(undefined **)(this + 8));
        *(undefined4 **)(this + 8) = puVar1;
      }
      *(undefined1 *)(*(int *)(this + 8) + *(int *)this) = unaff_retaddr;
      *(int *)this = *(int *)this + 1;
    }
  }
  return;
}


// vgui::Dar<char>::operator=  @ 27001aa0
/* public: class vgui::Dar<char> & __thiscall vgui::Dar<char>::operator=(class vgui::Dar<char> const
   &) */

Dar<char> * __thiscall vgui::Dar<char>::operator=(Dar<char> *this,Dar<char> *param_1)

{
                    /* 0x1aa0  88  ??4?$Dar@D@vgui@@QAEAAV01@ABV01@@Z
                       0x1aa0  89  ??4?$Dar@H@vgui@@QAEAAV01@ABV01@@Z
                       0x1aa0  90  ??4?$Dar@PAD@vgui@@QAEAAV01@ABV01@@Z
                       0x1aa0  91  ??4?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x1aa0  92  ??4?$Dar@PAVActionSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x1aa0  93  ??4?$Dar@PAVButton@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x1aa0  94  ??4?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x1aa0  95  ??4?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x1aa0  96  ??4?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x1aa0  97  ??4?$Dar@PAVFrame@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x1aa0  98  ??4?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x1aa0  99  ??4?$Dar@PAVInputSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x1aa0  100  ??4?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x1aa0  101  ??4?$Dar@PAVLabel@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x1aa0  102  ??4?$Dar@PAVPanel@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x1aa0  103  ??4?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x1aa0  104  ??4?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x1aa0  105  ??4?$Dar@PAVTickSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z */
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  return this;
}


// vgui::Dar<char>::operator[]  @ 27007770
/* public: char __thiscall vgui::Dar<char>::operator[](int) */

char __thiscall vgui::Dar<char>::operator[](Dar<char> *this,int param_1)

{
                    /* 0x7770  149  ??A?$Dar@D@vgui@@QAEDH@Z */
  if ((-1 < param_1) && (param_1 < *(int *)this)) {
    return *(char *)(param_1 + *(int *)(this + 8));
  }
  return '\0';
}


// vgui::Dar<char>::putElement  @ 270074b0
/* public: void __thiscall vgui::Dar<char>::putElement(char) */

void __thiscall vgui::Dar<char>::putElement(Dar<char> *this,char param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined1 unaff_retaddr;
  
                    /* 0x74b0  345  ?putElement@?$Dar@D@vgui@@QAEXD@Z */
  iVar1 = 0;
  iVar3 = *(int *)this;
  if (0 < iVar3) {
    do {
      if (*(char *)(*(int *)(this + 8) + iVar1) == param_1) {
        return;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar3);
  }
  uVar5 = *(uint *)(this + 4);
  if ((int)uVar5 < iVar3 + 1) {
    if (uVar5 == 0) {
      uVar5 = 1;
    }
    for (; (int)uVar5 < iVar3 + 1; uVar5 = uVar5 * 2) {
    }
    puVar2 = operator_new(uVar5);
    if (puVar2 == (undefined4 *)0x0) {
      FUN_27046b03(0);
    }
    puVar6 = puVar2;
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    for (uVar4 = uVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar6 = 0;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    *(uint *)(this + 4) = uVar5;
    iVar3 = 0;
    if (0 < *(int *)this) {
      do {
        iVar1 = iVar3 + 1;
        *(undefined1 *)(iVar3 + (int)puVar2) = *(undefined1 *)(iVar3 + *(int *)(this + 8));
        iVar3 = iVar1;
      } while (iVar1 < *(int *)this);
    }
    FUN_27046acb(*(undefined **)(this + 8));
    *(undefined4 **)(this + 8) = puVar2;
  }
  *(undefined1 *)(*(int *)(this + 8) + *(int *)this) = unaff_retaddr;
  *(int *)this = *(int *)this + 1;
  return;
}


// vgui::Dar<char>::removeAll  @ 27007760
/* public: void __thiscall vgui::Dar<char>::removeAll(void) */

void __thiscall vgui::Dar<char>::removeAll(Dar<char> *this)

{
                    /* 0x7760  365  ?removeAll@?$Dar@D@vgui@@QAEXXZ
                       0x7760  366  ?removeAll@?$Dar@H@vgui@@QAEXXZ
                       0x7760  367  ?removeAll@?$Dar@PAD@vgui@@QAEXXZ
                       0x7760  368  ?removeAll@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXXZ
                       0x7760  369  ?removeAll@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXXZ
                       0x7760  370  ?removeAll@?$Dar@PAVButton@vgui@@@vgui@@QAEXXZ
                       0x7760  371  ?removeAll@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXXZ
                       0x7760  372  ?removeAll@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXXZ
                       0x7760  373  ?removeAll@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXXZ
                       0x7760  374  ?removeAll@?$Dar@PAVFrame@vgui@@@vgui@@QAEXXZ
                       0x7760  375  ?removeAll@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXXZ
                       0x7760  376  ?removeAll@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXXZ
                       0x7760  377  ?removeAll@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXXZ
                       0x7760  378  ?removeAll@?$Dar@PAVLabel@vgui@@@vgui@@QAEXXZ
                       0x7760  379  ?removeAll@?$Dar@PAVPanel@vgui@@@vgui@@QAEXXZ
                       0x7760  380  ?removeAll@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXXZ
                       0x7760  381  ?removeAll@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXXZ
                       0x7760  382  ?removeAll@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEXXZ */
  *(undefined4 *)this = 0;
  return;
}


// vgui::Dar<char>::removeElement  @ 27007710
/* public: void __thiscall vgui::Dar<char>::removeElement(char) */

void __thiscall vgui::Dar<char>::removeElement(Dar<char> *this,char param_1)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x7710  383  ?removeElement@?$Dar@D@vgui@@QAEXD@Z */
  iVar3 = 0;
  iVar2 = *(int *)this;
  if (0 < iVar2) {
    while (*(char *)(*(int *)(this + 8) + iVar3) != param_1) {
      iVar3 = iVar3 + 1;
      if (iVar2 <= iVar3) {
        return;
      }
    }
    if ((-1 < iVar3) && (iVar3 < iVar2)) {
      if (iVar3 < iVar2 + -1) {
        do {
          puVar1 = (undefined1 *)(*(int *)(this + 8) + iVar3);
          iVar3 = iVar3 + 1;
          *puVar1 = puVar1[1];
        } while (iVar3 < *(int *)this + -1);
      }
      *(int *)this = *(int *)this + -1;
    }
  }
  return;
}


// vgui::Dar<char>::removeElementAt  @ 270076e0
/* public: void __thiscall vgui::Dar<char>::removeElementAt(int) */

void __thiscall vgui::Dar<char>::removeElementAt(Dar<char> *this,int param_1)

{
  undefined1 *puVar1;
  
                    /* 0x76e0  401  ?removeElementAt@?$Dar@D@vgui@@QAEXH@Z */
  if ((-1 < param_1) && (param_1 < *(int *)this)) {
    if (param_1 < *(int *)this + -1) {
      do {
        puVar1 = (undefined1 *)(*(int *)(this + 8) + param_1);
        param_1 = param_1 + 1;
        *puVar1 = puVar1[1];
      } while (param_1 < *(int *)this + -1);
    }
    *(int *)this = *(int *)this + -1;
  }
  return;
}


// vgui::Dar<char>::setCount  @ 270078a0
/* public: void __thiscall vgui::Dar<char>::setCount(int) */

void __thiscall vgui::Dar<char>::setCount(Dar<char> *this,int param_1)

{
                    /* 0x78a0  422  ?setCount@?$Dar@D@vgui@@QAEXH@Z
                       0x78a0  423  ?setCount@?$Dar@H@vgui@@QAEXH@Z
                       0x78a0  424  ?setCount@?$Dar@PAD@vgui@@QAEXH@Z
                       0x78a0  425  ?setCount@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXH@Z
                       0x78a0  426  ?setCount@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXH@Z
                       0x78a0  427  ?setCount@?$Dar@PAVButton@vgui@@@vgui@@QAEXH@Z
                       0x78a0  428  ?setCount@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x78a0  429  ?setCount@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXH@Z
                       0x78a0  430  ?setCount@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x78a0  431  ?setCount@?$Dar@PAVFrame@vgui@@@vgui@@QAEXH@Z
                       0x78a0  432  ?setCount@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXH@Z
                       0x78a0  433  ?setCount@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXH@Z
                       0x78a0  434  ?setCount@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x78a0  435  ?setCount@?$Dar@PAVLabel@vgui@@@vgui@@QAEXH@Z
                       0x78a0  436  ?setCount@?$Dar@PAVPanel@vgui@@@vgui@@QAEXH@Z
                       0x78a0  437  ?setCount@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXH@Z
                       0x78a0  438  ?setCount@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXH@Z
                       0x78a0  439  ?setCount@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEXH@Z */
  if ((-1 < param_1) && (param_1 <= *(int *)(this + 4))) {
    *(int *)this = param_1;
  }
  return;
}


// vgui::Dar<char>::setElementAt  @ 270076c0
/* public: void __thiscall vgui::Dar<char>::setElementAt(char,int) */

void __thiscall vgui::Dar<char>::setElementAt(Dar<char> *this,char param_1,int param_2)

{
                    /* 0x76c0  440  ?setElementAt@?$Dar@D@vgui@@QAEXDH@Z */
  if ((-1 < param_2) && (param_2 < *(int *)this)) {
    *(char *)(param_2 + *(int *)(this + 8)) = param_1;
  }
  return;
}


// vgui::Dar<int>::Dar<int>  @ 27007bb0
/* public: __thiscall vgui::Dar<int>::Dar<int>(int) */

Dar<int> * __thiscall vgui::Dar<int>::Dar<int>(Dar<int> *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
                    /* 0x7bb0  3  ??0?$Dar@H@vgui@@QAE@H@Z
                       0x7bb0  5  ??0?$Dar@PAD@vgui@@QAE@H@Z
                       0x7bb0  7  ??0?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAE@H@Z
                       0x7bb0  9  ??0?$Dar@PAVActionSignal@vgui@@@vgui@@QAE@H@Z
                       0x7bb0  11  ??0?$Dar@PAVButton@vgui@@@vgui@@QAE@H@Z
                       0x7bb0  13  ??0?$Dar@PAVChangeSignal@vgui@@@vgui@@QAE@H@Z
                       0x7bb0  15  ??0?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAE@H@Z
                       0x7bb0  17  ??0?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAE@H@Z
                       0x7bb0  19  ??0?$Dar@PAVFrame@vgui@@@vgui@@QAE@H@Z
                       0x7bb0  21  ??0?$Dar@PAVFrameSignal@vgui@@@vgui@@QAE@H@Z
                       0x7bb0  23  ??0?$Dar@PAVInputSignal@vgui@@@vgui@@QAE@H@Z
                       0x7bb0  25  ??0?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAE@H@Z
                       0x7bb0  27  ??0?$Dar@PAVLabel@vgui@@@vgui@@QAE@H@Z
                       0x7bb0  29  ??0?$Dar@PAVPanel@vgui@@@vgui@@QAE@H@Z
                       0x7bb0  31  ??0?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAE@H@Z
                       0x7bb0  33  ??0?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAE@H@Z
                       0x7bb0  35  ??0?$Dar@PAVTickSignal@vgui@@@vgui@@QAE@H@Z */
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  if (0 < param_1) {
    uVar5 = 1;
    if (1 < param_1) {
      do {
        uVar5 = uVar5 * 2;
      } while ((int)uVar5 < param_1);
    }
    puVar1 = operator_new(uVar5 * 4);
    if (puVar1 == (undefined4 *)0x0) {
      FUN_27046b03(0);
    }
    puVar6 = puVar1;
    for (uVar3 = uVar5 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar6 = 0;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    *(uint *)(this + 4) = uVar5;
    iVar4 = 0;
    if (0 < *(int *)this) {
      do {
        iVar2 = iVar4 + 1;
        puVar1[iVar4] = *(undefined4 *)(*(int *)(this + 8) + -4 + iVar2 * 4);
        iVar4 = iVar2;
      } while (iVar2 < *(int *)this);
    }
    FUN_27046acb(*(undefined **)(this + 8));
    *(undefined4 **)(this + 8) = puVar1;
  }
  return this;
}


// vgui::Dar<int>::Dar<int>  @ 27007c90
/* public: __thiscall vgui::Dar<int>::Dar<int>(void) */

Dar<int> * __thiscall vgui::Dar<int>::Dar<int>(Dar<int> *this)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
                    /* 0x7c90  4  ??0?$Dar@H@vgui@@QAE@XZ
                       0x7c90  6  ??0?$Dar@PAD@vgui@@QAE@XZ
                       0x7c90  8  ??0?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAE@XZ
                       0x7c90  10  ??0?$Dar@PAVActionSignal@vgui@@@vgui@@QAE@XZ
                       0x7c90  12  ??0?$Dar@PAVButton@vgui@@@vgui@@QAE@XZ
                       0x7c90  14  ??0?$Dar@PAVChangeSignal@vgui@@@vgui@@QAE@XZ
                       0x7c90  16  ??0?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAE@XZ
                       0x7c90  18  ??0?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAE@XZ
                       0x7c90  20  ??0?$Dar@PAVFrame@vgui@@@vgui@@QAE@XZ
                       0x7c90  22  ??0?$Dar@PAVFrameSignal@vgui@@@vgui@@QAE@XZ
                       0x7c90  24  ??0?$Dar@PAVInputSignal@vgui@@@vgui@@QAE@XZ
                       0x7c90  26  ??0?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAE@XZ
                       0x7c90  28  ??0?$Dar@PAVLabel@vgui@@@vgui@@QAE@XZ
                       0x7c90  30  ??0?$Dar@PAVPanel@vgui@@@vgui@@QAE@XZ
                       0x7c90  32  ??0?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAE@XZ
                       0x7c90  34  ??0?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAE@XZ
                       0x7c90  36  ??0?$Dar@PAVTickSignal@vgui@@@vgui@@QAE@XZ */
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  uVar1 = 1;
  do {
    uVar5 = uVar1;
    uVar1 = uVar5 * 2;
  } while ((int)uVar1 < 4);
  puVar2 = operator_new(uVar5 * 8);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_27046b03(0);
  }
  puVar6 = puVar2;
  for (iVar4 = (uVar5 & 0x1fffffff) << 1; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined1 *)puVar6 = 0;
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  *(uint *)(this + 4) = uVar1;
  iVar4 = 0;
  if (0 < *(int *)this) {
    do {
      iVar3 = iVar4 + 1;
      puVar2[iVar4] = *(undefined4 *)(*(int *)(this + 8) + -4 + iVar3 * 4);
      iVar4 = iVar3;
    } while (iVar3 < *(int *)this);
  }
  FUN_27046acb(*(undefined **)(this + 8));
  *(undefined4 **)(this + 8) = puVar2;
  return this;
}


// vgui::Dar<int>::addElement  @ 27007790
/* public: void __thiscall vgui::Dar<int>::addElement(int) */

void __thiscall vgui::Dar<int>::addElement(Dar<int> *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 unaff_retaddr;
  
                    /* 0x7790  236  ?addElement@?$Dar@H@vgui@@QAEXH@Z
                       0x7790  237  ?addElement@?$Dar@PAD@vgui@@QAEXPAD@Z
                       0x7790  238  ?addElement@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXPAV?$Dar@D@2@@Z
                       0x7790  239
                       ?addElement@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXPAVActionSignal@2@@Z
                       0x7790  240  ?addElement@?$Dar@PAVButton@vgui@@@vgui@@QAEXPAVButton@2@@Z
                       0x7790  241
                       ?addElement@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXPAVChangeSignal@2@@Z
                       0x7790  242
                       ?addElement@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXPAVDesktopIcon@2@@Z
                       0x7790  243
                       ?addElement@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXPAVFocusChangeSignal@2@@Z
                       0x7790  244  ?addElement@?$Dar@PAVFrame@vgui@@@vgui@@QAEXPAVFrame@2@@Z
                       0x7790  245
                       ?addElement@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXPAVFrameSignal@2@@Z
                       0x7790  246
                       ?addElement@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXPAVInputSignal@2@@Z
                       0x7790  247
                       ?addElement@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXPAVIntChangeSignal@2@@Z
                       0x7790  248  ?addElement@?$Dar@PAVLabel@vgui@@@vgui@@QAEXPAVLabel@2@@Z
                       0x7790  249  ?addElement@?$Dar@PAVPanel@vgui@@@vgui@@QAEXPAVPanel@2@@Z
                       0x7790  250
                       ?addElement@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXPAVRepaintSignal@2@@Z
                       0x7790  251
                       ?addElement@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXPAVSurfaceBase@2@@Z
                       0x7790  252
                       ?addElement@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEXPAVTickSignal@2@@Z */
  uVar5 = *(uint *)(this + 4);
  if ((int)uVar5 < *(int *)this + 1) {
    if (uVar5 == 0) {
      uVar5 = 1;
    }
    for (; (int)uVar5 < *(int *)this + 1; uVar5 = uVar5 * 2) {
    }
    puVar1 = operator_new(uVar5 * 4);
    if (puVar1 == (undefined4 *)0x0) {
      FUN_27046b03(0);
    }
    puVar6 = puVar1;
    for (uVar3 = uVar5 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar6 = 0;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    *(uint *)(this + 4) = uVar5;
    iVar4 = 0;
    if (0 < *(int *)this) {
      do {
        iVar2 = iVar4 + 1;
        puVar1[iVar4] = *(undefined4 *)(*(int *)(this + 8) + -4 + iVar2 * 4);
        iVar4 = iVar2;
      } while (iVar2 < *(int *)this);
    }
    FUN_27046acb(*(undefined **)(this + 8));
    *(undefined4 **)(this + 8) = puVar1;
  }
  *(undefined4 *)(*(int *)(this + 8) + *(int *)this * 4) = unaff_retaddr;
  *(int *)this = *(int *)this + 1;
  return;
}


// vgui::Dar<int>::ensureCapacity  @ 27007af0
/* public: void __thiscall vgui::Dar<int>::ensureCapacity(int) */

void __thiscall vgui::Dar<int>::ensureCapacity(Dar<int> *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
                    /* 0x7af0  257  ?ensureCapacity@?$Dar@H@vgui@@QAEXH@Z
                       0x7af0  258  ?ensureCapacity@?$Dar@PAD@vgui@@QAEXH@Z
                       0x7af0  259  ?ensureCapacity@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXH@Z
                       0x7af0  260  ?ensureCapacity@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXH@Z
                       0x7af0  261  ?ensureCapacity@?$Dar@PAVButton@vgui@@@vgui@@QAEXH@Z
                       0x7af0  262  ?ensureCapacity@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x7af0  263  ?ensureCapacity@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXH@Z
                       0x7af0  264  ?ensureCapacity@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x7af0  265  ?ensureCapacity@?$Dar@PAVFrame@vgui@@@vgui@@QAEXH@Z
                       0x7af0  266  ?ensureCapacity@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXH@Z
                       0x7af0  267  ?ensureCapacity@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXH@Z
                       0x7af0  268  ?ensureCapacity@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x7af0  269  ?ensureCapacity@?$Dar@PAVLabel@vgui@@@vgui@@QAEXH@Z
                       0x7af0  270  ?ensureCapacity@?$Dar@PAVPanel@vgui@@@vgui@@QAEXH@Z
                       0x7af0  271  ?ensureCapacity@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXH@Z
                       0x7af0  272  ?ensureCapacity@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXH@Z
                       0x7af0  273  ?ensureCapacity@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEXH@Z */
  uVar5 = *(uint *)(this + 4);
  if ((int)uVar5 < param_1) {
    if (uVar5 == 0) {
      uVar5 = 1;
    }
    for (; (int)uVar5 < param_1; uVar5 = uVar5 * 2) {
    }
    puVar1 = operator_new(uVar5 * 4);
    if (puVar1 == (undefined4 *)0x0) {
      FUN_27046b03(0);
    }
    puVar6 = puVar1;
    for (uVar3 = uVar5 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar6 = 0;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
    }
    *(uint *)(this + 4) = uVar5;
    iVar4 = 0;
    if (0 < *(int *)this) {
      do {
        iVar2 = iVar4 + 1;
        puVar1[iVar4] = *(undefined4 *)(*(int *)(this + 8) + -4 + iVar2 * 4);
        iVar4 = iVar2;
      } while (iVar2 < *(int *)this);
    }
    FUN_27046acb(*(undefined **)(this + 8));
    *(undefined4 **)(this + 8) = puVar1;
  }
  return;
}


// vgui::Dar<int>::hasElement  @ 27007830
/* public: bool __thiscall vgui::Dar<int>::hasElement(int) */

bool __thiscall vgui::Dar<int>::hasElement(Dar<int> *this,int param_1)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x7830  301  ?hasElement@?$Dar@H@vgui@@QAE_NH@Z
                       0x7830  302  ?hasElement@?$Dar@PAD@vgui@@QAE_NPAD@Z
                       0x7830  303  ?hasElement@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAE_NPAV?$Dar@D@2@@Z
                       0x7830  304
                       ?hasElement@?$Dar@PAVActionSignal@vgui@@@vgui@@QAE_NPAVActionSignal@2@@Z
                       0x7830  305  ?hasElement@?$Dar@PAVButton@vgui@@@vgui@@QAE_NPAVButton@2@@Z
                       0x7830  306
                       ?hasElement@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAE_NPAVChangeSignal@2@@Z
                       0x7830  307
                       ?hasElement@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAE_NPAVDesktopIcon@2@@Z
                       0x7830  308
                       ?hasElement@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAE_NPAVFocusChangeSignal@2@@Z
                       0x7830  309  ?hasElement@?$Dar@PAVFrame@vgui@@@vgui@@QAE_NPAVFrame@2@@Z
                       0x7830  310
                       ?hasElement@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAE_NPAVFrameSignal@2@@Z
                       0x7830  311
                       ?hasElement@?$Dar@PAVInputSignal@vgui@@@vgui@@QAE_NPAVInputSignal@2@@Z
                       0x7830  312
                       ?hasElement@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAE_NPAVIntChangeSignal@2@@Z
                       0x7830  313  ?hasElement@?$Dar@PAVLabel@vgui@@@vgui@@QAE_NPAVLabel@2@@Z
                       0x7830  314  ?hasElement@?$Dar@PAVPanel@vgui@@@vgui@@QAE_NPAVPanel@2@@Z
                       0x7830  315
                       ?hasElement@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAE_NPAVRepaintSignal@2@@Z
                       0x7830  316
                       ?hasElement@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAE_NPAVSurfaceBase@2@@Z
                       0x7830  317
                       ?hasElement@?$Dar@PAVTickSignal@vgui@@@vgui@@QAE_NPAVTickSignal@2@@Z */
  iVar1 = 0;
  if (0 < *(int *)this) {
    piVar2 = *(int **)(this + 8);
    do {
      if (*piVar2 == param_1) {
        return true;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < *(int *)this);
  }
  return false;
}


// vgui::Dar<int>::insertElementAt  @ 27007980
/* public: void __thiscall vgui::Dar<int>::insertElementAt(int,int) */

void __thiscall vgui::Dar<int>::insertElementAt(Dar<int> *this,int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 unaff_retaddr;
  
                    /* 0x7980  321  ?insertElementAt@?$Dar@H@vgui@@QAEXHH@Z
                       0x7980  322  ?insertElementAt@?$Dar@PAD@vgui@@QAEXPADH@Z
                       0x7980  323
                       ?insertElementAt@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXPAV?$Dar@D@2@H@Z
                       0x7980  324
                       ?insertElementAt@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXPAVActionSignal@2@H@Z
                       0x7980  325
                       ?insertElementAt@?$Dar@PAVButton@vgui@@@vgui@@QAEXPAVButton@2@H@Z
                       0x7980  326
                       ?insertElementAt@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXPAVChangeSignal@2@H@Z
                       0x7980  327
                       ?insertElementAt@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXPAVDesktopIcon@2@H@Z
                       0x7980  328
                       ?insertElementAt@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXPAVFocusChangeSignal@2@H@Z
                       0x7980  329  ?insertElementAt@?$Dar@PAVFrame@vgui@@@vgui@@QAEXPAVFrame@2@H@Z
                       0x7980  330
                       ?insertElementAt@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXPAVFrameSignal@2@H@Z
                       0x7980  331
                       ?insertElementAt@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXPAVInputSignal@2@H@Z
                       0x7980  332
                       ?insertElementAt@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXPAVIntChangeSignal@2@H@Z
                       0x7980  333  ?insertElementAt@?$Dar@PAVLabel@vgui@@@vgui@@QAEXPAVLabel@2@H@Z
                       0x7980  334  ?insertElementAt@?$Dar@PAVPanel@vgui@@@vgui@@QAEXPAVPanel@2@H@Z
                       0x7980  335
                       ?insertElementAt@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXPAVRepaintSignal@2@H@Z
                       0x7980  336
                       ?insertElementAt@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXPAVSurfaceBase@2@H@Z
                       0x7980  337
                       ?insertElementAt@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEXPAVTickSignal@2@H@Z */
  if (-1 < param_2) {
    iVar4 = *(int *)this;
    if (param_2 == iVar4 || param_2 < iVar4) {
      if ((param_2 != iVar4) && (iVar4 != 0)) {
        uVar5 = *(uint *)(this + 4);
        if ((int)uVar5 < iVar4 + 1) {
          if (uVar5 == 0) {
            uVar5 = 1;
          }
          for (; (int)uVar5 < iVar4 + 1; uVar5 = uVar5 * 2) {
          }
          puVar1 = operator_new(uVar5 * 4);
          if (puVar1 == (undefined4 *)0x0) {
            FUN_27046b03(0);
          }
          puVar6 = puVar1;
          for (uVar3 = uVar5 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar6 = 0;
            puVar6 = puVar6 + 1;
          }
          for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
            *(undefined1 *)puVar6 = 0;
            puVar6 = (undefined4 *)((int)puVar6 + 1);
          }
          *(uint *)(this + 4) = uVar5;
          iVar4 = 0;
          if (0 < *(int *)this) {
            do {
              iVar2 = iVar4 + 1;
              puVar1[iVar4] = *(undefined4 *)(*(int *)(this + 8) + -4 + iVar2 * 4);
              iVar4 = iVar2;
            } while (iVar2 < *(int *)this);
          }
          FUN_27046acb(*(undefined **)(this + 8));
          *(undefined4 **)(this + 8) = puVar1;
          param_2 = param_1;
        }
        *(undefined4 *)(*(int *)(this + 8) + *(int *)this * 4) = unaff_retaddr;
        iVar4 = *(int *)this;
        *(int *)this = iVar4 + 1;
        for (; param_2 < iVar4; iVar4 = iVar4 + -1) {
          *(undefined4 *)(*(int *)(this + 8) + iVar4 * 4) =
               *(undefined4 *)(*(int *)(this + 8) + -4 + iVar4 * 4);
        }
        *(undefined4 *)(*(int *)(this + 8) + param_2 * 4) = unaff_retaddr;
        return;
      }
      uVar5 = *(uint *)(this + 4);
      if ((int)uVar5 < iVar4 + 1) {
        if (uVar5 == 0) {
          uVar5 = 1;
        }
        for (; (int)uVar5 < iVar4 + 1; uVar5 = uVar5 * 2) {
        }
        puVar1 = operator_new(uVar5 * 4);
        if (puVar1 == (undefined4 *)0x0) {
          FUN_27046b03(0);
        }
        puVar6 = puVar1;
        for (uVar3 = uVar5 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(undefined1 *)puVar6 = 0;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        }
        *(uint *)(this + 4) = uVar5;
        iVar4 = 0;
        if (0 < *(int *)this) {
          do {
            iVar2 = iVar4 + 1;
            puVar1[iVar4] = *(undefined4 *)(*(int *)(this + 8) + -4 + iVar2 * 4);
            iVar4 = iVar2;
          } while (iVar2 < *(int *)this);
        }
        FUN_27046acb(*(undefined **)(this + 8));
        *(undefined4 **)(this + 8) = puVar1;
      }
      *(undefined4 *)(*(int *)(this + 8) + *(int *)this * 4) = unaff_retaddr;
      *(int *)this = *(int *)this + 1;
    }
  }
  return;
}


// vgui::Dar<int>::operator[]  @ 27007880
/* public: int __thiscall vgui::Dar<int>::operator[](int) */

int __thiscall vgui::Dar<int>::operator[](Dar<int> *this,int param_1)

{
                    /* 0x7880  150  ??A?$Dar@H@vgui@@QAEHH@Z
                       0x7880  151  ??A?$Dar@PAD@vgui@@QAEPADH@Z
                       0x7880  152  ??A?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEPAV?$Dar@D@1@H@Z
                       0x7880  153  ??A?$Dar@PAVActionSignal@vgui@@@vgui@@QAEPAVActionSignal@1@H@Z
                       0x7880  154  ??A?$Dar@PAVButton@vgui@@@vgui@@QAEPAVButton@1@H@Z
                       0x7880  155  ??A?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEPAVChangeSignal@1@H@Z
                       0x7880  156  ??A?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEPAVDesktopIcon@1@H@Z
                       0x7880  157
                       ??A?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEPAVFocusChangeSignal@1@H@Z
                       0x7880  158  ??A?$Dar@PAVFrame@vgui@@@vgui@@QAEPAVFrame@1@H@Z
                       0x7880  159  ??A?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEPAVFrameSignal@1@H@Z
                       0x7880  160  ??A?$Dar@PAVInputSignal@vgui@@@vgui@@QAEPAVInputSignal@1@H@Z
                       0x7880  161
                       ??A?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEPAVIntChangeSignal@1@H@Z
                       0x7880  162  ??A?$Dar@PAVLabel@vgui@@@vgui@@QAEPAVLabel@1@H@Z
                       0x7880  163  ??A?$Dar@PAVPanel@vgui@@@vgui@@QAEPAVPanel@1@H@Z
                       0x7880  164  ??A?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEPAVRepaintSignal@1@H@Z
                       0x7880  165  ??A?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEPAVSurfaceBase@1@H@Z
                       0x7880  166  ??A?$Dar@PAVTickSignal@vgui@@@vgui@@QAEPAVTickSignal@1@H@Z */
  if ((-1 < param_1) && (param_1 < *(int *)this)) {
    return *(int *)(*(int *)(this + 8) + param_1 * 4);
  }
  return 0;
}


// vgui::Dar<int>::putElement  @ 270078c0
/* public: void __thiscall vgui::Dar<int>::putElement(int) */

void __thiscall vgui::Dar<int>::putElement(Dar<int> *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 unaff_retaddr;
  
                    /* 0x78c0  346  ?putElement@?$Dar@H@vgui@@QAEXH@Z
                       0x78c0  347  ?putElement@?$Dar@PAD@vgui@@QAEXPAD@Z
                       0x78c0  348  ?putElement@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXPAV?$Dar@D@2@@Z
                       0x78c0  349
                       ?putElement@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXPAVActionSignal@2@@Z
                       0x78c0  350  ?putElement@?$Dar@PAVButton@vgui@@@vgui@@QAEXPAVButton@2@@Z
                       0x78c0  351
                       ?putElement@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXPAVChangeSignal@2@@Z
                       0x78c0  352
                       ?putElement@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXPAVDesktopIcon@2@@Z
                       0x78c0  353
                       ?putElement@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXPAVFocusChangeSignal@2@@Z
                       0x78c0  354  ?putElement@?$Dar@PAVFrame@vgui@@@vgui@@QAEXPAVFrame@2@@Z
                       0x78c0  355
                       ?putElement@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXPAVFrameSignal@2@@Z
                       0x78c0  356
                       ?putElement@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXPAVInputSignal@2@@Z
                       0x78c0  357
                       ?putElement@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXPAVIntChangeSignal@2@@Z
                       0x78c0  358  ?putElement@?$Dar@PAVLabel@vgui@@@vgui@@QAEXPAVLabel@2@@Z
                       0x78c0  359  ?putElement@?$Dar@PAVPanel@vgui@@@vgui@@QAEXPAVPanel@2@@Z
                       0x78c0  360
                       ?putElement@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXPAVRepaintSignal@2@@Z
                       0x78c0  361
                       ?putElement@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXPAVSurfaceBase@2@@Z
                       0x78c0  362
                       ?putElement@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEXPAVTickSignal@2@@Z */
  iVar2 = 0;
  iVar4 = *(int *)this;
  if (0 < iVar4) {
    piVar5 = *(int **)(this + 8);
    do {
      if (*piVar5 == param_1) {
        return;
      }
      iVar2 = iVar2 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar2 < iVar4);
  }
  uVar6 = *(uint *)(this + 4);
  if ((int)uVar6 < iVar4 + 1) {
    if (uVar6 == 0) {
      uVar6 = 1;
    }
    for (; (int)uVar6 < iVar4 + 1; uVar6 = uVar6 * 2) {
    }
    puVar1 = operator_new(uVar6 * 4);
    if (puVar1 == (undefined4 *)0x0) {
      FUN_27046b03(0);
    }
    puVar7 = puVar1;
    for (uVar3 = uVar6 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar7 = 0;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    *(uint *)(this + 4) = uVar6;
    iVar4 = 0;
    if (0 < *(int *)this) {
      do {
        iVar2 = iVar4 + 1;
        puVar1[iVar4] = *(undefined4 *)(*(int *)(this + 8) + -4 + iVar2 * 4);
        iVar4 = iVar2;
      } while (iVar2 < *(int *)this);
    }
    FUN_27046acb(*(undefined **)(this + 8));
    *(undefined4 **)(this + 8) = puVar1;
  }
  *(undefined4 *)(*(int *)(this + 8) + *(int *)this * 4) = unaff_retaddr;
  *(int *)this = *(int *)this + 1;
  return;
}


// vgui::Dar<int>::removeElement  @ 27007c40
/* public: void __thiscall vgui::Dar<int>::removeElement(int) */

void __thiscall vgui::Dar<int>::removeElement(Dar<int> *this,int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
                    /* 0x7c40  384  ?removeElement@?$Dar@H@vgui@@QAEXH@Z
                       0x7c40  385  ?removeElement@?$Dar@PAD@vgui@@QAEXPAD@Z
                       0x7c40  386  ?removeElement@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXPAV?$Dar@D@2@@Z
                       0x7c40  387
                       ?removeElement@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXPAVActionSignal@2@@Z
                       0x7c40  388  ?removeElement@?$Dar@PAVButton@vgui@@@vgui@@QAEXPAVButton@2@@Z
                       0x7c40  389
                       ?removeElement@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXPAVChangeSignal@2@@Z
                       0x7c40  390
                       ?removeElement@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXPAVDesktopIcon@2@@Z
                       0x7c40  391
                       ?removeElement@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXPAVFocusChangeSignal@2@@Z
                       0x7c40  392  ?removeElement@?$Dar@PAVFrame@vgui@@@vgui@@QAEXPAVFrame@2@@Z
                       0x7c40  393
                       ?removeElement@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXPAVFrameSignal@2@@Z
                       0x7c40  394
                       ?removeElement@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXPAVInputSignal@2@@Z
                       0x7c40  395
                       ?removeElement@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXPAVIntChangeSignal@2@@Z
                       0x7c40  396  ?removeElement@?$Dar@PAVLabel@vgui@@@vgui@@QAEXPAVLabel@2@@Z
                       0x7c40  397  ?removeElement@?$Dar@PAVPanel@vgui@@@vgui@@QAEXPAVPanel@2@@Z
                       0x7c40  398
                       ?removeElement@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXPAVRepaintSignal@2@@Z
                       0x7c40  399
                       ?removeElement@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXPAVSurfaceBase@2@@Z
                       0x7c40  400
                       ?removeElement@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEXPAVTickSignal@2@@Z */
  iVar1 = *(int *)this;
  iVar2 = 0;
  if (0 < iVar1) {
    piVar3 = *(int **)(this + 8);
    while (*piVar3 != param_1) {
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
      if (iVar1 <= iVar2) {
        return;
      }
    }
    if ((-1 < iVar2) && (iVar2 < iVar1)) {
      if (iVar2 < iVar1 + -1) {
        do {
          iVar2 = iVar2 + 1;
          *(undefined4 *)(*(int *)(this + 8) + -4 + iVar2 * 4) =
               *(undefined4 *)(*(int *)(this + 8) + iVar2 * 4);
        } while (iVar2 < *(int *)this + -1);
      }
      *(int *)this = *(int *)this + -1;
    }
  }
  return;
}


// vgui::Dar<int>::removeElementAt  @ 27007b80
/* public: void __thiscall vgui::Dar<int>::removeElementAt(int) */

void __thiscall vgui::Dar<int>::removeElementAt(Dar<int> *this,int param_1)

{
                    /* 0x7b80  402  ?removeElementAt@?$Dar@H@vgui@@QAEXH@Z
                       0x7b80  403  ?removeElementAt@?$Dar@PAD@vgui@@QAEXH@Z
                       0x7b80  404  ?removeElementAt@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXH@Z
                       0x7b80  405  ?removeElementAt@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXH@Z
                       0x7b80  406  ?removeElementAt@?$Dar@PAVButton@vgui@@@vgui@@QAEXH@Z
                       0x7b80  407  ?removeElementAt@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x7b80  408  ?removeElementAt@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXH@Z
                       0x7b80  409  ?removeElementAt@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x7b80  410  ?removeElementAt@?$Dar@PAVFrame@vgui@@@vgui@@QAEXH@Z
                       0x7b80  411  ?removeElementAt@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXH@Z
                       0x7b80  412  ?removeElementAt@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXH@Z
                       0x7b80  413  ?removeElementAt@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x7b80  414  ?removeElementAt@?$Dar@PAVLabel@vgui@@@vgui@@QAEXH@Z
                       0x7b80  415  ?removeElementAt@?$Dar@PAVPanel@vgui@@@vgui@@QAEXH@Z
                       0x7b80  416  ?removeElementAt@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXH@Z
                       0x7b80  417  ?removeElementAt@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXH@Z
                       0x7b80  418  ?removeElementAt@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEXH@Z */
  if ((-1 < param_1) && (param_1 < *(int *)this)) {
    if (param_1 < *(int *)this + -1) {
      do {
        param_1 = param_1 + 1;
        *(undefined4 *)(*(int *)(this + 8) + -4 + param_1 * 4) =
             *(undefined4 *)(*(int *)(this + 8) + param_1 * 4);
      } while (param_1 < *(int *)this + -1);
    }
    *(int *)this = *(int *)this + -1;
  }
  return;
}


// vgui::Dar<int>::setElementAt  @ 27007860
/* public: void __thiscall vgui::Dar<int>::setElementAt(int,int) */

void __thiscall vgui::Dar<int>::setElementAt(Dar<int> *this,int param_1,int param_2)

{
                    /* 0x7860  441  ?setElementAt@?$Dar@H@vgui@@QAEXHH@Z
                       0x7860  442  ?setElementAt@?$Dar@PAD@vgui@@QAEXPADH@Z
                       0x7860  443  ?setElementAt@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXPAV?$Dar@D@2@H@Z
                       0x7860  444
                       ?setElementAt@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXPAVActionSignal@2@H@Z
                       0x7860  445  ?setElementAt@?$Dar@PAVButton@vgui@@@vgui@@QAEXPAVButton@2@H@Z
                       0x7860  446
                       ?setElementAt@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXPAVChangeSignal@2@H@Z
                       0x7860  447
                       ?setElementAt@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXPAVDesktopIcon@2@H@Z
                       0x7860  448
                       ?setElementAt@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXPAVFocusChangeSignal@2@H@Z
                       0x7860  449  ?setElementAt@?$Dar@PAVFrame@vgui@@@vgui@@QAEXPAVFrame@2@H@Z
                       0x7860  450
                       ?setElementAt@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXPAVFrameSignal@2@H@Z
                       0x7860  451
                       ?setElementAt@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXPAVInputSignal@2@H@Z
                       0x7860  452
                       ?setElementAt@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXPAVIntChangeSignal@2@H@Z
                       0x7860  453  ?setElementAt@?$Dar@PAVLabel@vgui@@@vgui@@QAEXPAVLabel@2@H@Z
                       0x7860  454  ?setElementAt@?$Dar@PAVPanel@vgui@@@vgui@@QAEXPAVPanel@2@H@Z
                       0x7860  455
                       ?setElementAt@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXPAVRepaintSignal@2@H@Z
                       0x7860  456
                       ?setElementAt@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXPAVSurfaceBase@2@H@Z
                       0x7860  457
                       ?setElementAt@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEXPAVTickSignal@2@H@Z */
  if ((-1 < param_2) && (param_2 < *(int *)this)) {
    *(int *)(*(int *)(this + 8) + param_2 * 4) = param_1;
  }
  return;
}


// vgui::DataInputStream::DataInputStream  @ 27035630
/* public: __thiscall vgui::DataInputStream::DataInputStream(class vgui::DataInputStream const &) */

void __thiscall
vgui::DataInputStream::DataInputStream(DataInputStream *this,DataInputStream *param_1)

{
  int in_stack_00000008;
  
                    /* 0x35630  48  ??0DataInputStream@vgui@@QAE@ABV01@@Z */
  if (in_stack_00000008 != 0) {
    *(undefined1 **)(this + 4) = &_vbtable_;
    *(undefined ***)(this + 0x10) = &InputStream::_vftable_;
  }
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined ***)this = &_vftable__for__vgui__DataInputStream__;
  *(undefined ***)(this + *(int *)(*(int *)(this + 4) + 4) + 4) =
       &_vftable__for__vgui__InputStream__;
  *(undefined4 *)(this + *(int *)(*(int *)(this + 4) + 4)) = 0;
  return;
}


// vgui::DataInputStream::operator=  @ 27035680
/* public: class vgui::DataInputStream & __thiscall vgui::DataInputStream::operator=(class
   vgui::DataInputStream const &) */

DataInputStream * __thiscall
vgui::DataInputStream::operator=(DataInputStream *this,DataInputStream *param_1)

{
                    /* 0x35680  116  ??4DataInputStream@vgui@@QAEAAV01@ABV01@@Z */
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  return this;
}


// vgui::DesktopIcon::DesktopIcon  @ 2700af40
/* public: __thiscall vgui::DesktopIcon::DesktopIcon(class vgui::DesktopIcon const &) */

void __thiscall vgui::DesktopIcon::DesktopIcon(DesktopIcon *this,DesktopIcon *param_1)

{
                    /* 0xaf40  49  ??0DesktopIcon@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(this + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined ***)(this + 0x9c) = &Color::_vftable_;
  *(undefined4 *)(this + 0xac) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined ***)(this + 0xa8) = &Color::_vftable_;
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined ***)this = &Panel::_vftable_;
  *(undefined4 *)(this + 0xbc) = *(undefined4 *)(param_1 + 0xbc);
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::DesktopIcon::operator=  @ 2700b330
/* public: class vgui::DesktopIcon & __thiscall vgui::DesktopIcon::operator=(class vgui::DesktopIcon
   const &) */

DesktopIcon * __thiscall vgui::DesktopIcon::operator=(DesktopIcon *this,DesktopIcon *param_1)

{
  int iVar1;
  DesktopIcon *pDVar2;
  int iVar3;
  
                    /* 0xb330  117  ??4DesktopIcon@vgui@@QAEAAV01@ABV01@@Z */
  iVar1 = (int)param_1 - (int)this;
  iVar3 = 2;
  pDVar2 = this;
  do {
    pDVar2 = pDVar2 + 4;
    *(undefined4 *)pDVar2 = *(undefined4 *)(pDVar2 + iVar1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pDVar2 = this + 0xc;
  iVar3 = 2;
  do {
    *(undefined4 *)pDVar2 = *(undefined4 *)(pDVar2 + iVar1);
    pDVar2 = pDVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pDVar2 = this + 0x14;
  iVar3 = 2;
  do {
    *(undefined4 *)pDVar2 = *(undefined4 *)(pDVar2 + iVar1);
    pDVar2 = pDVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pDVar2 = this + 0x1c;
  iVar3 = 2;
  do {
    *(undefined4 *)pDVar2 = *(undefined4 *)(pDVar2 + iVar1);
    pDVar2 = pDVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pDVar2 = this + 0x24;
  iVar3 = 2;
  do {
    *(undefined4 *)pDVar2 = *(undefined4 *)(pDVar2 + iVar1);
    pDVar2 = pDVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  pDVar2 = this + 0x58;
  iVar3 = 4;
  do {
    *(undefined4 *)pDVar2 = *(undefined4 *)(pDVar2 + iVar1);
    pDVar2 = pDVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  pDVar2 = this + 0xa0;
  do {
    *pDVar2 = pDVar2[(int)(param_1 + (0x9c - (int)(this + 0x9c)))];
    pDVar2 = pDVar2 + 1;
  } while (pDVar2 + (-4 - (int)(this + 0x9c)) < (DesktopIcon *)0x4);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  pDVar2 = this + 0xac;
  do {
    *pDVar2 = pDVar2[(int)(param_1 + (0xa8 - (int)(this + 0xa8)))];
    pDVar2 = pDVar2 + 1;
  } while (pDVar2 + (-4 - (int)(this + 0xa8)) < (DesktopIcon *)0x4);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined4 *)(this + 0xbc) = *(undefined4 *)(param_1 + 0xbc);
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  return this;
}


// vgui::FileInputStream::FileInputStream  @ 2700aed0
/* public: __thiscall vgui::FileInputStream::FileInputStream(class vgui::FileInputStream const &) */

void __thiscall
vgui::FileInputStream::FileInputStream(FileInputStream *this,FileInputStream *param_1)

{
                    /* 0xaed0  50  ??0FileInputStream@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &InputStream::_vftable_;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Font::Font  @ 2700c830
/* public: __thiscall vgui::Font::Font(class vgui::Font const &) */

void __thiscall vgui::Font::Font(Font *this,Font *param_1)

{
                    /* 0xc830  51  ??0Font@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Font::operator=  @ 2700c860
/* public: class vgui::Font & __thiscall vgui::Font::operator=(class vgui::Font const &) */

Font * __thiscall vgui::Font::operator=(Font *this,Font *param_1)

{
                    /* 0xc860  119  ??4Font@vgui@@QAEAAV01@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  return this;
}


// vgui::Frame::Frame  @ 2700a5c0
/* public: __thiscall vgui::Frame::Frame(class vgui::Frame const &) */

void __thiscall vgui::Frame::Frame(Frame *this,Frame *param_1)

{
                    /* 0xa5c0  52  ??0Frame@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(this + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined ***)(this + 0x9c) = &Color::_vftable_;
  *(undefined4 *)(this + 0xac) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined ***)(this + 0xa8) = &Color::_vftable_;
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined ***)this = &Panel::_vftable_;
  *(undefined4 *)(this + 0xbc) = *(undefined4 *)(param_1 + 0xbc);
  this[0xc0] = param_1[0xc0];
  this[0xc1] = param_1[0xc1];
  this[0xc2] = param_1[0xc2];
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)(this + 200) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined4 *)(this + 0xd0) = *(undefined4 *)(param_1 + 0xd0);
  *(undefined4 *)(this + 0xd4) = *(undefined4 *)(param_1 + 0xd4);
  *(undefined4 *)(this + 0xd8) = *(undefined4 *)(param_1 + 0xd8);
  *(undefined4 *)(this + 0xdc) = *(undefined4 *)(param_1 + 0xdc);
  *(undefined4 *)(this + 0xe0) = *(undefined4 *)(param_1 + 0xe0);
  *(undefined4 *)(this + 0xe4) = *(undefined4 *)(param_1 + 0xe4);
  *(undefined4 *)(this + 0xe8) = *(undefined4 *)(param_1 + 0xe8);
  *(undefined4 *)(this + 0xec) = *(undefined4 *)(param_1 + 0xec);
  *(undefined4 *)(this + 0xf0) = *(undefined4 *)(param_1 + 0xf0);
  *(undefined4 *)(this + 0xf4) = *(undefined4 *)(param_1 + 0xf4);
  *(undefined4 *)(this + 0xf8) = *(undefined4 *)(param_1 + 0xf8);
  *(undefined4 *)(this + 0xfc) = *(undefined4 *)(param_1 + 0xfc);
  *(undefined4 *)(this + 0x100) = *(undefined4 *)(param_1 + 0x100);
  *(undefined4 *)(this + 0x104) = *(undefined4 *)(param_1 + 0x104);
  *(undefined4 *)(this + 0x108) = *(undefined4 *)(param_1 + 0x108);
  *(undefined4 *)(this + 0x10c) = *(undefined4 *)(param_1 + 0x10c);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Frame::operator=  @ 2700a880
/* public: class vgui::Frame & __thiscall vgui::Frame::operator=(class vgui::Frame const &) */

Frame * __thiscall vgui::Frame::operator=(Frame *this,Frame *param_1)

{
  int iVar1;
  Frame *pFVar2;
  int iVar3;
  
                    /* 0xa880  120  ??4Frame@vgui@@QAEAAV01@ABV01@@Z */
  iVar1 = (int)param_1 - (int)this;
  iVar3 = 2;
  pFVar2 = this;
  do {
    pFVar2 = pFVar2 + 4;
    *(undefined4 *)pFVar2 = *(undefined4 *)(pFVar2 + iVar1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pFVar2 = this + 0xc;
  iVar3 = 2;
  do {
    *(undefined4 *)pFVar2 = *(undefined4 *)(pFVar2 + iVar1);
    pFVar2 = pFVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pFVar2 = this + 0x14;
  iVar3 = 2;
  do {
    *(undefined4 *)pFVar2 = *(undefined4 *)(pFVar2 + iVar1);
    pFVar2 = pFVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pFVar2 = this + 0x1c;
  iVar3 = 2;
  do {
    *(undefined4 *)pFVar2 = *(undefined4 *)(pFVar2 + iVar1);
    pFVar2 = pFVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pFVar2 = this + 0x24;
  iVar3 = 2;
  do {
    *(undefined4 *)pFVar2 = *(undefined4 *)(pFVar2 + iVar1);
    pFVar2 = pFVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  pFVar2 = this + 0x58;
  iVar3 = 4;
  do {
    *(undefined4 *)pFVar2 = *(undefined4 *)(pFVar2 + iVar1);
    pFVar2 = pFVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  pFVar2 = this + 0xa0;
  do {
    *pFVar2 = pFVar2[(int)(param_1 + (0x9c - (int)(this + 0x9c)))];
    pFVar2 = pFVar2 + 1;
  } while (pFVar2 + (-4 - (int)(this + 0x9c)) < (Frame *)0x4);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  pFVar2 = this + 0xac;
  do {
    *pFVar2 = pFVar2[(int)(param_1 + (0xa8 - (int)(this + 0xa8)))];
    pFVar2 = pFVar2 + 1;
  } while (pFVar2 + (-4 - (int)(this + 0xa8)) < (Frame *)0x4);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined4 *)(this + 0xbc) = *(undefined4 *)(param_1 + 0xbc);
  this[0xc0] = param_1[0xc0];
  this[0xc1] = param_1[0xc1];
  this[0xc2] = param_1[0xc2];
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)(this + 200) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined4 *)(this + 0xd0) = *(undefined4 *)(param_1 + 0xd0);
  *(undefined4 *)(this + 0xd4) = *(undefined4 *)(param_1 + 0xd4);
  *(undefined4 *)(this + 0xd8) = *(undefined4 *)(param_1 + 0xd8);
  *(undefined4 *)(this + 0xdc) = *(undefined4 *)(param_1 + 0xdc);
  *(undefined4 *)(this + 0xe0) = *(undefined4 *)(param_1 + 0xe0);
  *(undefined4 *)(this + 0xe4) = *(undefined4 *)(param_1 + 0xe4);
  *(undefined4 *)(this + 0xe8) = *(undefined4 *)(param_1 + 0xe8);
  *(undefined4 *)(this + 0xec) = *(undefined4 *)(param_1 + 0xec);
  *(undefined4 *)(this + 0xf0) = *(undefined4 *)(param_1 + 0xf0);
  *(undefined4 *)(this + 0xf4) = *(undefined4 *)(param_1 + 0xf4);
  *(undefined4 *)(this + 0xf8) = *(undefined4 *)(param_1 + 0xf8);
  *(undefined4 *)(this + 0xfc) = *(undefined4 *)(param_1 + 0xfc);
  *(undefined4 *)(this + 0x100) = *(undefined4 *)(param_1 + 0x100);
  *(undefined4 *)(this + 0x104) = *(undefined4 *)(param_1 + 0x104);
  *(undefined4 *)(this + 0x108) = *(undefined4 *)(param_1 + 0x108);
  *(undefined4 *)(this + 0x10c) = *(undefined4 *)(param_1 + 0x10c);
  return this;
}


// vgui::HeaderPanel::HeaderPanel  @ 27019150
/* public: __thiscall vgui::HeaderPanel::HeaderPanel(class vgui::HeaderPanel const &) */

void __thiscall vgui::HeaderPanel::HeaderPanel(HeaderPanel *this,HeaderPanel *param_1)

{
                    /* 0x19150  53  ??0HeaderPanel@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(this + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined ***)(this + 0x9c) = &Color::_vftable_;
  *(undefined4 *)(this + 0xac) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined ***)(this + 0xa8) = &Color::_vftable_;
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined ***)this = &Panel::_vftable_;
  *(undefined4 *)(this + 0xbc) = *(undefined4 *)(param_1 + 0xbc);
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)(this + 200) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined4 *)(this + 0xd0) = *(undefined4 *)(param_1 + 0xd0);
  *(undefined4 *)(this + 0xd4) = *(undefined4 *)(param_1 + 0xd4);
  *(undefined4 *)(this + 0xd8) = *(undefined4 *)(param_1 + 0xd8);
  *(undefined4 *)(this + 0xdc) = *(undefined4 *)(param_1 + 0xdc);
  *(undefined4 *)(this + 0xe0) = *(undefined4 *)(param_1 + 0xe0);
  *(undefined4 *)(this + 0xe4) = *(undefined4 *)(param_1 + 0xe4);
  this[0xe8] = param_1[0xe8];
  *(undefined4 *)(this + 0xec) = *(undefined4 *)(param_1 + 0xec);
  *(undefined4 *)(this + 0xf0) = *(undefined4 *)(param_1 + 0xf0);
  *(undefined4 *)(this + 0xf4) = *(undefined4 *)(param_1 + 0xf4);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::HeaderPanel::operator=  @ 270193a0
/* public: class vgui::HeaderPanel & __thiscall vgui::HeaderPanel::operator=(class vgui::HeaderPanel
   const &) */

HeaderPanel * __thiscall vgui::HeaderPanel::operator=(HeaderPanel *this,HeaderPanel *param_1)

{
  int iVar1;
  HeaderPanel *pHVar2;
  int iVar3;
  
                    /* 0x193a0  121  ??4HeaderPanel@vgui@@QAEAAV01@ABV01@@Z */
  iVar1 = (int)param_1 - (int)this;
  iVar3 = 2;
  pHVar2 = this;
  do {
    pHVar2 = pHVar2 + 4;
    *(undefined4 *)pHVar2 = *(undefined4 *)(pHVar2 + iVar1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pHVar2 = this + 0xc;
  iVar3 = 2;
  do {
    *(undefined4 *)pHVar2 = *(undefined4 *)(pHVar2 + iVar1);
    pHVar2 = pHVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pHVar2 = this + 0x14;
  iVar3 = 2;
  do {
    *(undefined4 *)pHVar2 = *(undefined4 *)(pHVar2 + iVar1);
    pHVar2 = pHVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pHVar2 = this + 0x1c;
  iVar3 = 2;
  do {
    *(undefined4 *)pHVar2 = *(undefined4 *)(pHVar2 + iVar1);
    pHVar2 = pHVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pHVar2 = this + 0x24;
  iVar3 = 2;
  do {
    *(undefined4 *)pHVar2 = *(undefined4 *)(pHVar2 + iVar1);
    pHVar2 = pHVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  pHVar2 = this + 0x58;
  iVar3 = 4;
  do {
    *(undefined4 *)pHVar2 = *(undefined4 *)(pHVar2 + iVar1);
    pHVar2 = pHVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  pHVar2 = this + 0xa0;
  do {
    *pHVar2 = pHVar2[(int)(param_1 + (0x9c - (int)(this + 0x9c)))];
    pHVar2 = pHVar2 + 1;
  } while (pHVar2 + (-4 - (int)(this + 0x9c)) < (HeaderPanel *)0x4);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  pHVar2 = this + 0xac;
  do {
    *pHVar2 = pHVar2[(int)(param_1 + (0xa8 - (int)(this + 0xa8)))];
    pHVar2 = pHVar2 + 1;
  } while (pHVar2 + (-4 - (int)(this + 0xa8)) < (HeaderPanel *)0x4);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined4 *)(this + 0xbc) = *(undefined4 *)(param_1 + 0xbc);
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)(this + 200) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined4 *)(this + 0xd0) = *(undefined4 *)(param_1 + 0xd0);
  *(undefined4 *)(this + 0xd4) = *(undefined4 *)(param_1 + 0xd4);
  *(undefined4 *)(this + 0xd8) = *(undefined4 *)(param_1 + 0xd8);
  *(undefined4 *)(this + 0xdc) = *(undefined4 *)(param_1 + 0xdc);
  *(undefined4 *)(this + 0xe0) = *(undefined4 *)(param_1 + 0xe0);
  *(undefined4 *)(this + 0xe4) = *(undefined4 *)(param_1 + 0xe4);
  this[0xe8] = param_1[0xe8];
  *(undefined4 *)(this + 0xec) = *(undefined4 *)(param_1 + 0xec);
  *(undefined4 *)(this + 0xf0) = *(undefined4 *)(param_1 + 0xf0);
  *(undefined4 *)(this + 0xf4) = *(undefined4 *)(param_1 + 0xf4);
  return this;
}


// vgui::Image::Image  @ 27002a80
/* public: __thiscall vgui::Image::Image(class vgui::Image const &) */

void __thiscall vgui::Image::Image(Image *this,Image *param_1)

{
                    /* 0x2a80  54  ??0Image@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined ***)(this + 0x18) = &Color::_vftable_;
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Image::operator=  @ 27002ac0
/* public: class vgui::Image & __thiscall vgui::Image::operator=(class vgui::Image const &) */

Image * __thiscall vgui::Image::operator=(Image *this,Image *param_1)

{
  Image *pIVar1;
  int iVar2;
  
                    /* 0x2ac0  122  ??4Image@vgui@@QAEAAV01@ABV01@@Z */
  iVar2 = 2;
  pIVar1 = this;
  do {
    pIVar1 = pIVar1 + 4;
    *(undefined4 *)pIVar1 = *(undefined4 *)(pIVar1 + ((int)param_1 - (int)this));
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  pIVar1 = this + 0xc;
  iVar2 = 2;
  do {
    *(undefined4 *)pIVar1 = *(undefined4 *)(pIVar1 + ((int)param_1 - (int)this));
    pIVar1 = pIVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  pIVar1 = this + 0x1c;
  do {
    *pIVar1 = pIVar1[(int)(param_1 + (0x18 - (int)(this + 0x18)))];
    pIVar1 = pIVar1 + 1;
  } while (pIVar1 + (-4 - (int)(this + 0x18)) < (Image *)0x4);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  return this;
}


// vgui::ImagePanel::ImagePanel  @ 27002e10
/* public: __thiscall vgui::ImagePanel::ImagePanel(void) */

ImagePanel * __thiscall vgui::ImagePanel::ImagePanel(ImagePanel *this)

{
                    /* 0x2e10  56  ??0ImagePanel@vgui@@QAE@XZ */
  vgui::Panel::Panel((Panel *)this);
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0xbc) = 0;
  return this;
}


// vgui::ImagePanel::ImagePanel  @ 27002eb0
/* public: __thiscall vgui::ImagePanel::ImagePanel(class vgui::ImagePanel const &) */

void __thiscall vgui::ImagePanel::ImagePanel(ImagePanel *this,ImagePanel *param_1)

{
  undefined4 uVar1;
  
                    /* 0x2eb0  55  ??0ImagePanel@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(this + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined ***)(this + 0x9c) = &Color::_vftable_;
  *(undefined4 *)(this + 0xac) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined ***)(this + 0xa8) = &Color::_vftable_;
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined ***)this = &Panel::_vftable_;
  uVar1 = *(undefined4 *)(param_1 + 0xbc);
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0xbc) = uVar1;
  return;
}


// vgui::ImagePanel::operator=  @ 27003070
/* public: class vgui::ImagePanel & __thiscall vgui::ImagePanel::operator=(class vgui::ImagePanel
   const &) */

ImagePanel * __thiscall vgui::ImagePanel::operator=(ImagePanel *this,ImagePanel *param_1)

{
  int iVar1;
  ImagePanel *pIVar2;
  int iVar3;
  
                    /* 0x3070  123  ??4ImagePanel@vgui@@QAEAAV01@ABV01@@Z
                       0x3070  148  ??4TextPanel@vgui@@QAEAAV01@ABV01@@Z */
  iVar1 = (int)param_1 - (int)this;
  iVar3 = 2;
  pIVar2 = this;
  do {
    pIVar2 = pIVar2 + 4;
    *(undefined4 *)pIVar2 = *(undefined4 *)(pIVar2 + iVar1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pIVar2 = this + 0xc;
  iVar3 = 2;
  do {
    *(undefined4 *)pIVar2 = *(undefined4 *)(pIVar2 + iVar1);
    pIVar2 = pIVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pIVar2 = this + 0x14;
  iVar3 = 2;
  do {
    *(undefined4 *)pIVar2 = *(undefined4 *)(pIVar2 + iVar1);
    pIVar2 = pIVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pIVar2 = this + 0x1c;
  iVar3 = 2;
  do {
    *(undefined4 *)pIVar2 = *(undefined4 *)(pIVar2 + iVar1);
    pIVar2 = pIVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pIVar2 = this + 0x24;
  iVar3 = 2;
  do {
    *(undefined4 *)pIVar2 = *(undefined4 *)(pIVar2 + iVar1);
    pIVar2 = pIVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  pIVar2 = this + 0x58;
  iVar3 = 4;
  do {
    *(undefined4 *)pIVar2 = *(undefined4 *)(pIVar2 + iVar1);
    pIVar2 = pIVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  pIVar2 = this + 0xa0;
  do {
    *pIVar2 = pIVar2[(int)(param_1 + (0x9c - (int)(this + 0x9c)))];
    pIVar2 = pIVar2 + 1;
  } while (pIVar2 + (-4 - (int)(this + 0x9c)) < (ImagePanel *)0x4);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  pIVar2 = this + 0xac;
  do {
    *pIVar2 = pIVar2[(int)(param_1 + (0xa8 - (int)(this + 0xa8)))];
    pIVar2 = pIVar2 + 1;
  } while (pIVar2 + (-4 - (int)(this + 0xa8)) < (ImagePanel *)0x4);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined4 *)(this + 0xbc) = *(undefined4 *)(param_1 + 0xbc);
  return this;
}


// vgui::InputSignal::InputSignal  @ 27003400
/* public: __thiscall vgui::InputSignal::InputSignal(void) */

void __thiscall vgui::InputSignal::InputSignal(InputSignal *this)

{
                    /* 0x3400  58  ??0InputSignal@vgui@@QAE@XZ */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::InputSignal::InputSignal  @ 27003410
/* public: __thiscall vgui::InputSignal::InputSignal(class vgui::InputSignal const &) */

void __thiscall vgui::InputSignal::InputSignal(InputSignal *this,InputSignal *param_1)

{
                    /* 0x3410  57  ??0InputSignal@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::InputStream::InputStream  @ 2700ae60
/* public: __thiscall vgui::InputStream::InputStream(void) */

void __thiscall vgui::InputStream::InputStream(InputStream *this)

{
                    /* 0xae60  60  ??0InputStream@vgui@@QAE@XZ */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::InputStream::InputStream  @ 2700aec0
/* public: __thiscall vgui::InputStream::InputStream(class vgui::InputStream const &) */

void __thiscall vgui::InputStream::InputStream(InputStream *this,InputStream *param_1)

{
                    /* 0xaec0  59  ??0InputStream@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::IntChangeSignal::IntChangeSignal  @ 270163b0
/* public: __thiscall vgui::IntChangeSignal::IntChangeSignal(void) */

void __thiscall vgui::IntChangeSignal::IntChangeSignal(IntChangeSignal *this)

{
                    /* 0x163b0  62  ??0IntChangeSignal@vgui@@QAE@XZ */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::IntChangeSignal::IntChangeSignal  @ 270163c0
/* public: __thiscall vgui::IntChangeSignal::IntChangeSignal(class vgui::IntChangeSignal const &) */

void __thiscall
vgui::IntChangeSignal::IntChangeSignal(IntChangeSignal *this,IntChangeSignal *param_1)

{
                    /* 0x163c0  61  ??0IntChangeSignal@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Label::Label  @ 27002600
/* public: __thiscall vgui::Label::Label(void) */

Label * __thiscall vgui::Label::Label(Label *this)

{
                    /* 0x2600  64  ??0Label@vgui@@QAE@XZ */
  vgui::Panel::Panel((Panel *)this,0,0,10,10);
  *(undefined ***)this = &_vftable_;
  vgui::Label::init(this,1,s_,true);
  return this;
}


// vgui::Label::Label  @ 27002630
/* public: __thiscall vgui::Label::Label(class vgui::Label const &) */

void __thiscall vgui::Label::Label(Label *this,Label *param_1)

{
                    /* 0x2630  63  ??0Label@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(this + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined ***)(this + 0x9c) = &Color::_vftable_;
  *(undefined4 *)(this + 0xac) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined ***)(this + 0xa8) = &Color::_vftable_;
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined ***)this = &Panel::_vftable_;
  this[0xbc] = param_1[0xbc];
  this[0xbd] = param_1[0xbd];
  this[0xbe] = param_1[0xbe];
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)(this + 200) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Label::operator=  @ 27002840
/* public: class vgui::Label & __thiscall vgui::Label::operator=(class vgui::Label const &) */

Label * __thiscall vgui::Label::operator=(Label *this,Label *param_1)

{
  int iVar1;
  Label *pLVar2;
  int iVar3;
  
                    /* 0x2840  127  ??4Label@vgui@@QAEAAV01@ABV01@@Z
                       0x2840  131  ??4MenuSeparator@vgui@@QAEAAV01@ABV01@@Z */
  iVar1 = (int)param_1 - (int)this;
  iVar3 = 2;
  pLVar2 = this;
  do {
    pLVar2 = pLVar2 + 4;
    *(undefined4 *)pLVar2 = *(undefined4 *)(pLVar2 + iVar1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pLVar2 = this + 0xc;
  iVar3 = 2;
  do {
    *(undefined4 *)pLVar2 = *(undefined4 *)(pLVar2 + iVar1);
    pLVar2 = pLVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pLVar2 = this + 0x14;
  iVar3 = 2;
  do {
    *(undefined4 *)pLVar2 = *(undefined4 *)(pLVar2 + iVar1);
    pLVar2 = pLVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pLVar2 = this + 0x1c;
  iVar3 = 2;
  do {
    *(undefined4 *)pLVar2 = *(undefined4 *)(pLVar2 + iVar1);
    pLVar2 = pLVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pLVar2 = this + 0x24;
  iVar3 = 2;
  do {
    *(undefined4 *)pLVar2 = *(undefined4 *)(pLVar2 + iVar1);
    pLVar2 = pLVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  pLVar2 = this + 0x58;
  iVar3 = 4;
  do {
    *(undefined4 *)pLVar2 = *(undefined4 *)(pLVar2 + iVar1);
    pLVar2 = pLVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  pLVar2 = this + 0xa0;
  do {
    *pLVar2 = pLVar2[(int)(param_1 + (0x9c - (int)(this + 0x9c)))];
    pLVar2 = pLVar2 + 1;
  } while (pLVar2 + (-4 - (int)(this + 0x9c)) < (Label *)0x4);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  pLVar2 = this + 0xac;
  do {
    *pLVar2 = pLVar2[(int)(param_1 + (0xa8 - (int)(this + 0xa8)))];
    pLVar2 = pLVar2 + 1;
  } while (pLVar2 + (-4 - (int)(this + 0xa8)) < (Label *)0x4);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  this[0xbc] = param_1[0xbc];
  this[0xbd] = param_1[0xbd];
  this[0xbe] = param_1[0xbe];
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)(this + 200) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
  return this;
}


// vgui::Layout::Layout  @ 27037260
/* public: __thiscall vgui::Layout::Layout(class vgui::Layout const &) */

void __thiscall vgui::Layout::Layout(Layout *this,Layout *param_1)

{
                    /* 0x37260  65  ??0Layout@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::LineBorder::LineBorder  @ 27002cd0
/* public: __thiscall vgui::LineBorder::LineBorder(class vgui::LineBorder const &) */

void __thiscall vgui::LineBorder::LineBorder(LineBorder *this,LineBorder *param_1)

{
                    /* 0x2cd0  66  ??0LineBorder@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined ***)(this + 0x18) = &Color::_vftable_;
  *(undefined ***)this = &Image::_vftable_;
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined ***)this = &Border::_vftable_;
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined ***)(this + 0x38) = &Color::_vftable_;
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::LineBorder::operator=  @ 27002d60
/* public: class vgui::LineBorder & __thiscall vgui::LineBorder::operator=(class vgui::LineBorder
   const &) */

LineBorder * __thiscall vgui::LineBorder::operator=(LineBorder *this,LineBorder *param_1)

{
  LineBorder *pLVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x2d60  129  ??4LineBorder@vgui@@QAEAAV01@ABV01@@Z */
  iVar3 = 2;
  iVar2 = (int)param_1 - (int)this;
  pLVar1 = this;
  do {
    pLVar1 = pLVar1 + 4;
    *(undefined4 *)pLVar1 = *(undefined4 *)(pLVar1 + iVar2);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pLVar1 = this + 0xc;
  iVar3 = 2;
  do {
    *(undefined4 *)pLVar1 = *(undefined4 *)(pLVar1 + iVar2);
    pLVar1 = pLVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  pLVar1 = this + 0x1c;
  do {
    *pLVar1 = pLVar1[(int)(param_1 + (0x18 - (int)(this + 0x18)))];
    pLVar1 = pLVar1 + 1;
  } while (pLVar1 + (-4 - (int)(this + 0x18)) < (LineBorder *)0x4);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  pLVar1 = this + 0x24;
  iVar3 = 4;
  do {
    *(undefined4 *)pLVar1 = *(undefined4 *)(pLVar1 + iVar2);
    pLVar1 = pLVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  pLVar1 = this + 0x3c;
  do {
    *pLVar1 = pLVar1[(int)(param_1 + (0x38 - (int)(this + 0x38)))];
    pLVar1 = pLVar1 + 1;
  } while (pLVar1 + (-4 - (int)(this + 0x38)) < (LineBorder *)0x4);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  return this;
}


// vgui::LineBorder::setLineColor  @ 27002c70
/* public: void __thiscall vgui::LineBorder::setLineColor(int,int,int,int) */

void __thiscall
vgui::LineBorder::setLineColor(LineBorder *this,int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  LineBorder *pLVar2;
  Color local_c [12];
  
                    /* 0x2c70  458  ?setLineColor@LineBorder@vgui@@QAEXHHHH@Z */
  iVar1 = vgui::Color::Color(local_c,param_1,param_2,param_3,param_4);
  pLVar2 = this + 0x3c;
  do {
    *pLVar2 = pLVar2[iVar1 - (int)(this + 0x38)];
    pLVar2 = pLVar2 + 1;
  } while (pLVar2 + (-4 - (int)(this + 0x38)) < (LineBorder *)0x4);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(iVar1 + 8);
  return;
}


// vgui::LoweredBorder::LoweredBorder  @ 2703dc70
/* public: __thiscall vgui::LoweredBorder::LoweredBorder(class vgui::LoweredBorder const &) */

void __thiscall vgui::LoweredBorder::LoweredBorder(LoweredBorder *this,LoweredBorder *param_1)

{
                    /* 0x3dc70  67  ??0LoweredBorder@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined ***)(this + 0x18) = &Color::_vftable_;
  *(undefined ***)this = &Image::_vftable_;
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::MenuSeparator::MenuSeparator  @ 2703da60
/* public: __thiscall vgui::MenuSeparator::MenuSeparator(class vgui::MenuSeparator const &) */

void __thiscall vgui::MenuSeparator::MenuSeparator(MenuSeparator *this,MenuSeparator *param_1)

{
                    /* 0x3da60  68  ??0MenuSeparator@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(this + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined ***)(this + 0x9c) = &Color::_vftable_;
  *(undefined4 *)(this + 0xac) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined ***)(this + 0xa8) = &Color::_vftable_;
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined ***)this = &Panel::_vftable_;
  this[0xbc] = param_1[0xbc];
  this[0xbd] = param_1[0xbd];
  this[0xbe] = param_1[0xbe];
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)(this + 200) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::MiniApp::MiniApp  @ 2700ba60
/* public: __thiscall vgui::MiniApp::MiniApp(class vgui::MiniApp const &) */

void __thiscall vgui::MiniApp::MiniApp(MiniApp *this,MiniApp *param_1)

{
  undefined4 uVar1;
  
                    /* 0xba60  69  ??0MiniApp@vgui@@QAE@ABV01@@Z */
  uVar1 = *(undefined4 *)(param_1 + 4);
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 4) = uVar1;
  return;
}


// vgui::Panel::Panel  @ 27002070
/* public: __thiscall vgui::Panel::Panel(class vgui::Panel const &) */

void __thiscall vgui::Panel::Panel(Panel *this,Panel *param_1)

{
                    /* 0x2070  70  ??0Panel@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(this + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined ***)(this + 0x9c) = &Color::_vftable_;
  *(undefined4 *)(this + 0xac) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined ***)(this + 0xa8) = &Color::_vftable_;
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Panel::operator=  @ 27002220
/* public: class vgui::Panel & __thiscall vgui::Panel::operator=(class vgui::Panel const &) */

Panel * __thiscall vgui::Panel::operator=(Panel *this,Panel *param_1)

{
  int iVar1;
  Panel *pPVar2;
  int iVar3;
  
                    /* 0x2220  133  ??4Panel@vgui@@QAEAAV01@ABV01@@Z */
  iVar1 = (int)param_1 - (int)this;
  iVar3 = 2;
  pPVar2 = this;
  do {
    pPVar2 = pPVar2 + 4;
    *(undefined4 *)pPVar2 = *(undefined4 *)(pPVar2 + iVar1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pPVar2 = this + 0xc;
  iVar3 = 2;
  do {
    *(undefined4 *)pPVar2 = *(undefined4 *)(pPVar2 + iVar1);
    pPVar2 = pPVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pPVar2 = this + 0x14;
  iVar3 = 2;
  do {
    *(undefined4 *)pPVar2 = *(undefined4 *)(pPVar2 + iVar1);
    pPVar2 = pPVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pPVar2 = this + 0x1c;
  iVar3 = 2;
  do {
    *(undefined4 *)pPVar2 = *(undefined4 *)(pPVar2 + iVar1);
    pPVar2 = pPVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pPVar2 = this + 0x24;
  iVar3 = 2;
  do {
    *(undefined4 *)pPVar2 = *(undefined4 *)(pPVar2 + iVar1);
    pPVar2 = pPVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  pPVar2 = this + 0x58;
  iVar3 = 4;
  do {
    *(undefined4 *)pPVar2 = *(undefined4 *)(pPVar2 + iVar1);
    pPVar2 = pPVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  pPVar2 = this + 0xa0;
  do {
    *pPVar2 = pPVar2[(int)(param_1 + (0x9c - (int)(this + 0x9c)))];
    pPVar2 = pPVar2 + 1;
  } while (pPVar2 + (-4 - (int)(this + 0x9c)) < (Panel *)0x4);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  pPVar2 = this + 0xac;
  do {
    *pPVar2 = pPVar2[(int)(param_1 + (0xa8 - (int)(this + 0xa8)))];
    pPVar2 = pPVar2 + 1;
  } while (pPVar2 + (-4 - (int)(this + 0xa8)) < (Panel *)0x4);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  return this;
}


// vgui::Scheme::Scheme  @ 27001f70
/* public: __thiscall vgui::Scheme::Scheme(class vgui::Scheme const &) */

void __thiscall vgui::Scheme::Scheme(Scheme *this,Scheme *param_1)

{
  int iVar1;
  Scheme *pSVar2;
  Scheme *pSVar3;
  
  iVar1 = 0x24;
  pSVar2 = param_1;
  pSVar3 = this;
  while( true ) {
    pSVar3 = pSVar3 + 4;
    pSVar2 = pSVar2 + 4;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    *(undefined4 *)pSVar3 = *(undefined4 *)pSVar2;
  }
  pSVar2 = param_1 + 0x94;
  pSVar3 = this + 0x94;
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pSVar3 = *(undefined4 *)pSVar2;
    pSVar2 = pSVar2 + 4;
    pSVar3 = pSVar3 + 4;
  }
  pSVar2 = param_1 + 0xa8;
  pSVar3 = this + 0xa8;
  for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pSVar3 = *(undefined4 *)pSVar2;
    pSVar2 = pSVar2 + 4;
    pSVar3 = pSVar3 + 4;
  }
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Scheme::operator=  @ 27001fc0
/* public: class vgui::Scheme & __thiscall vgui::Scheme::operator=(class vgui::Scheme const &) */

Scheme * __thiscall vgui::Scheme::operator=(Scheme *this,Scheme *param_1)

{
  int iVar1;
  Scheme *pSVar2;
  int iVar3;
  
                    /* 0x1fc0  134  ??4Scheme@vgui@@QAEAAV01@ABV01@@Z */
  iVar1 = (int)param_1 - (int)this;
  iVar3 = 0x24;
  pSVar2 = this;
  do {
    pSVar2 = pSVar2 + 4;
    *(undefined4 *)pSVar2 = *(undefined4 *)(pSVar2 + iVar1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pSVar2 = this + 0x94;
  iVar3 = 5;
  do {
    *(undefined4 *)pSVar2 = *(undefined4 *)(pSVar2 + iVar1);
    pSVar2 = pSVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pSVar2 = this + 0xa8;
  iVar3 = 0xe;
  do {
    *(undefined4 *)pSVar2 = *(undefined4 *)(pSVar2 + iVar1);
    pSVar2 = pSVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return this;
}


// vgui::ScrollBar2::ScrollBar2  @ 27015510
/* public: __thiscall vgui::ScrollBar2::ScrollBar2(int,int,int,int,bool) */

ScrollBar2 * __thiscall
vgui::ScrollBar2::ScrollBar2
          (ScrollBar2 *this,int param_1,int param_2,int param_3,int param_4,bool param_5)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  Slider2 *pSVar4;
  Button *pBVar5;
  Image *pIVar6;
  int iVar7;
  undefined4 *extraout_EDX;
  undefined4 *puVar8;
  void *unaff_EBX;
  char *pcVar9;
  void *pvStack_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
                    /* 0x15510  73  ??0ScrollBar2@vgui@@QAE@HHHH_N@Z */
  uStack_4 = 0xffffffff;
  local_8 = &LAB_270543b2;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  vgui::Panel::Panel((Panel *)this,param_1,param_2,param_3,param_4);
  *(undefined4 *)(this + 200) = 0;
  *(undefined4 *)(this + 0xcc) = 0;
  *(undefined4 *)(this + 0xd0) = 0;
  uVar1 = 1;
  do {
    uVar2 = uVar1;
    uVar1 = uVar2 * 2;
  } while ((int)uVar1 < 4);
  puVar3 = operator_new(uVar2 << 3);
  puVar8 = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    FUN_27046b03(0);
    puVar8 = extraout_EDX;
  }
  for (iVar7 = (uVar2 & 0x1fffffff) << 1; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined1 *)puVar8 = 0;
    puVar8 = (undefined4 *)((int)puVar8 + 1);
  }
  *(undefined4 **)(this + 0xcc) = puVar3;
  iVar7 = 0;
  if (0 < *(int *)(this + 200)) {
    do {
      iVar7 = iVar7 + 1;
      *(undefined4 *)(param_1 + -4 + iVar7 * 4) =
           *(undefined4 *)(*(int *)(this + 0xd0) + -4 + iVar7 * 4);
    } while (iVar7 < *(int *)(this + 200));
  }
  FUN_27046acb(*(undefined **)(this + 0xd0));
  *(int *)(this + 0xd0) = param_1;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0xc4) = 0;
  *(undefined4 *)(this + 0xbc) = 0;
  *(undefined4 *)(this + 0xc0) = 0;
  if ((char)param_4 == '\0') {
    pSVar4 = operator_new(0xfc);
    local_8 = (undefined1 *)0x3;
    if (pSVar4 == (Slider2 *)0x0) {
      pSVar4 = (Slider2 *)0x0;
    }
    else {
      pSVar4 = (Slider2 *)Slider2::Slider2(pSVar4,param_4,0,param_3 + param_4 * -2,param_4,false);
    }
    local_8 = (undefined1 *)0xffffffff;
    setSlider(this,pSVar4);
    pBVar5 = operator_new(0x134);
    local_8 = (undefined1 *)0x4;
    if (pBVar5 == (Button *)0x0) {
      pBVar5 = (Button *)0x0;
    }
    else {
      vgui::Button::Button(pBVar5,s_,0,0,param_4 + 1,param_4 + 1);
      vgui::Color::Color((Color *)&stack0xffffffd4,0x3c,0x3c,0x3c,0);
      vgui::LineBorder::LineBorder((LineBorder *)(pBVar5 + 0xf0));
      *(undefined ***)pBVar5 = &PTR_setPos_27059dbc;
      pIVar6 = (Image *)FUN_27037770(s_gfx_vgui_320_arrowlt_tga_270751bc);
      if (pIVar6 != (Image *)0x0) {
        iVar7 = *(int *)pIVar6;
        vgui::Color::Color((Color *)&stack0xffffffd4,0x8c,0x8c,0x8c,0);
        (**(code **)(iVar7 + 0xc))();
        vgui::Label::setImage((Label *)pBVar5,pIVar6);
        param_4 = uVar1;
      }
      vgui::Panel::setBorder((Panel *)pBVar5,(Border *)(pBVar5 + 0xf0));
    }
    local_8 = (undefined1 *)0xffffffff;
    setButton(this,pBVar5,0);
    pBVar5 = operator_new(0x134);
    local_8 = (undefined1 *)0x5;
    if (pBVar5 == (Button *)0x0) goto LAB_27015941;
    vgui::Button::Button(pBVar5,s_,param_3 - param_4,0,param_4 + 1U,param_4 + 1U);
    vgui::Color::Color((Color *)&stack0xffffffd4,0x3c,0x3c,0x3c,0);
    vgui::LineBorder::LineBorder((LineBorder *)(pBVar5 + 0xf0));
    pcVar9 = s_gfx_vgui_320_arrowrt_tga_270751a0;
  }
  else {
    pSVar4 = operator_new(0xfc);
    local_8 = (undefined1 *)0x0;
    if (pSVar4 == (Slider2 *)0x0) {
      pSVar4 = (Slider2 *)0x0;
    }
    else {
      pSVar4 = (Slider2 *)
               Slider2::Slider2(pSVar4,0,param_3 + -1,param_3,param_4 + param_3 * -2 + 2,true);
    }
    local_8 = (undefined1 *)0xffffffff;
    setSlider(this,pSVar4);
    pBVar5 = operator_new(0x134);
    local_8 = (undefined1 *)0x1;
    if (pBVar5 == (Button *)0x0) {
      pBVar5 = (Button *)0x0;
    }
    else {
      vgui::Button::Button(pBVar5,s_,0,0,param_3,param_3);
      vgui::Color::Color((Color *)&stack0xffffffd4,0x3c,0x3c,0x3c,0);
      vgui::LineBorder::LineBorder((LineBorder *)(pBVar5 + 0xf0));
      *(undefined ***)pBVar5 = &PTR_setPos_27059dbc;
      pIVar6 = (Image *)FUN_27037770(s_gfx_vgui_arrowup_tga_270751f0);
      if (pIVar6 != (Image *)0x0) {
        iVar7 = *(int *)pIVar6;
        vgui::Color::Color((Color *)&stack0xffffffd4,0x8c,0x8c,0x8c,0);
        (**(code **)(iVar7 + 0xc))();
        vgui::Label::setImage((Label *)pBVar5,pIVar6);
        param_4 = uVar1;
      }
      vgui::Panel::setBorder((Panel *)pBVar5,(Border *)(pBVar5 + 0xf0));
    }
    local_8 = (undefined1 *)0xffffffff;
    setButton(this,pBVar5,0);
    pBVar5 = operator_new(0x134);
    local_8 = (undefined1 *)0x2;
    if (pBVar5 == (Button *)0x0) {
LAB_27015941:
      pBVar5 = (Button *)0x0;
      goto LAB_27015943;
    }
    vgui::Button::Button(pBVar5,s_,0,param_4 - param_3,param_3,param_3);
    vgui::Color::Color((Color *)&stack0xffffffd4,0x3c,0x3c,0x3c,0);
    vgui::LineBorder::LineBorder((LineBorder *)(pBVar5 + 0xf0));
    pcVar9 = s_gfx_vgui_arrowdown_tga_270751d8;
  }
  *(undefined ***)pBVar5 = &PTR_setPos_27059dbc;
  pIVar6 = (Image *)FUN_27037770(pcVar9);
  if (pIVar6 != (Image *)0x0) {
    iVar7 = *(int *)pIVar6;
    vgui::Color::Color((Color *)&stack0xffffffd4,0x8c,0x8c,0x8c,0);
    (**(code **)(iVar7 + 0xc))();
    vgui::Label::setImage((Label *)pBVar5,pIVar6);
  }
  vgui::Panel::setBorder((Panel *)pBVar5,(Border *)(pBVar5 + 0xf0));
LAB_27015943:
  local_8 = (undefined1 *)0xffffffff;
  setButton(this,pBVar5,1);
  vgui::Panel::setPaintBorderEnabled((Panel *)this,true);
  vgui::Panel::setPaintBackgroundEnabled((Panel *)this,true);
  vgui::Panel::setPaintEnabled((Panel *)this,true);
  setButtonPressedScrollValue(this,0xf);
  validate(this);
  ExceptionList = unaff_EBX;
  return this;
}


// vgui::ScrollBar2::ScrollBar2  @ 27015de0
/* public: __thiscall vgui::ScrollBar2::ScrollBar2(class vgui::ScrollBar2 const &) */

void __thiscall vgui::ScrollBar2::ScrollBar2(ScrollBar2 *this,ScrollBar2 *param_1)

{
                    /* 0x15de0  72  ??0ScrollBar2@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(this + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined ***)(this + 0x9c) = &Color::_vftable_;
  *(undefined4 *)(this + 0xac) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined ***)(this + 0xa8) = &Color::_vftable_;
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined ***)this = &Panel::_vftable_;
  *(undefined4 *)(this + 0xbc) = *(undefined4 *)(param_1 + 0xbc);
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)(this + 200) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined4 *)(this + 0xd0) = *(undefined4 *)(param_1 + 0xd0);
  *(undefined4 *)(this + 0xd4) = *(undefined4 *)(param_1 + 0xd4);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::ScrollBar2::addIntChangeSignal  @ 27015b20
/* public: virtual void __thiscall vgui::ScrollBar2::addIntChangeSignal(class vgui::IntChangeSignal
   *) */

void __thiscall vgui::ScrollBar2::addIntChangeSignal(ScrollBar2 *this,IntChangeSignal *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 unaff_retaddr;
  
                    /* 0x15b20  253
                       ?addIntChangeSignal@ScrollBar2@vgui@@UAEXPAVIntChangeSignal@2@@Z */
  iVar2 = 0;
  iVar4 = *(int *)(this + 200);
  if (0 < iVar4) {
    piVar5 = *(int **)(this + 0xd0);
    do {
      if ((IntChangeSignal *)*piVar5 == param_1) goto LAB_27015c00;
      iVar2 = iVar2 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar2 < iVar4);
  }
  uVar6 = *(uint *)(this + 0xcc);
  if ((int)uVar6 < iVar4 + 1) {
    if (uVar6 == 0) {
      uVar6 = 1;
    }
    for (; (int)uVar6 < iVar4 + 1; uVar6 = uVar6 * 2) {
    }
    puVar1 = operator_new(uVar6 * 4);
    if (puVar1 == (undefined4 *)0x0) {
      FUN_27046b03(0);
    }
    puVar7 = puVar1;
    for (uVar3 = uVar6 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar7 = 0;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    *(uint *)(this + 0xcc) = uVar6;
    iVar4 = 0;
    if (0 < *(int *)(this + 200)) {
      do {
        iVar2 = iVar4 + 1;
        puVar1[iVar4] = *(undefined4 *)(*(int *)(this + 0xd0) + -4 + iVar2 * 4);
        iVar4 = iVar2;
      } while (iVar2 < *(int *)(this + 200));
    }
    FUN_27046acb(*(undefined **)(this + 0xd0));
    *(undefined4 **)(this + 0xd0) = puVar1;
  }
  *(undefined4 *)(*(int *)(this + 0xd0) + *(int *)(this + 200) * 4) = unaff_retaddr;
  *(int *)(this + 200) = *(int *)(this + 200) + 1;
LAB_27015c00:
  puVar1 = operator_new(8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &PTR_LAB_2705a264;
    puVar1[1] = this;
  }
                    /* WARNING: Could not recover jumptable at 0x27015c2b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(this + 0xc4) + 0x208))();
  return;
}


// vgui::ScrollBar2::doButtonPressed  @ 27015ff0
/* public: virtual void __thiscall vgui::ScrollBar2::doButtonPressed(int) */

void __thiscall vgui::ScrollBar2::doButtonPressed(ScrollBar2 *this,int param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x15ff0  255  ?doButtonPressed@ScrollBar2@vgui@@UAEXH@Z */
  iVar1 = **(int **)(this + 0xc4);
  if (param_1 == 0) {
    iVar2 = (**(code **)(iVar1 + 0x200))();
    (**(code **)(iVar1 + 0x1fc))(iVar2 - *(int *)(this + 0xd4));
    return;
  }
  iVar2 = (**(code **)(iVar1 + 0x200))();
  (**(code **)(iVar1 + 0x1fc))(iVar2 + *(int *)(this + 0xd4));
  return;
}


// vgui::ScrollBar2::fireIntChangeSignal  @ 27015c60
/* public: virtual void __thiscall vgui::ScrollBar2::fireIntChangeSignal(void) */

void __thiscall vgui::ScrollBar2::fireIntChangeSignal(ScrollBar2 *this)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
                    /* 0x15c60  274  ?fireIntChangeSignal@ScrollBar2@vgui@@UAEXXZ */
  iVar3 = 0;
  if (0 < *(int *)(this + 200)) {
    do {
      if ((iVar3 < 0) || (*(int *)(this + 200) <= iVar3)) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = *(undefined4 **)(*(int *)(this + 0xd0) + iVar3 * 4);
      }
      puVar2 = (undefined4 *)*puVar2;
      uVar1 = (**(code **)(**(int **)(this + 0xc4) + 0x200))(this);
      (*(code *)*puVar2)(uVar1);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(this + 200));
  }
  return;
}


// vgui::ScrollBar2::getButton  @ 27015d70
/* public: virtual class vgui::Button * __thiscall vgui::ScrollBar2::getButton(int) */

Button * __thiscall vgui::ScrollBar2::getButton(ScrollBar2 *this,int param_1)

{
                    /* 0x15d70  276  ?getButton@ScrollBar2@vgui@@UAEPAVButton@2@H@Z */
  return *(Button **)(this + param_1 * 4 + 0xbc);
}


// vgui::ScrollBar2::getSlider  @ 27015fe0
/* public: virtual class vgui::Slider2 * __thiscall vgui::ScrollBar2::getSlider(void) */

Slider2 * __thiscall vgui::ScrollBar2::getSlider(ScrollBar2 *this)

{
                    /* 0x15fe0  297  ?getSlider@ScrollBar2@vgui@@UAEPAVSlider2@2@XZ */
  return *(Slider2 **)(this + 0xc4);
}


// vgui::ScrollBar2::getValue  @ 27015b10
/* public: virtual int __thiscall vgui::ScrollBar2::getValue(void) */

int __thiscall vgui::ScrollBar2::getValue(ScrollBar2 *this)

{
  int iVar1;
  
                    /* 0x15b10  298  ?getValue@ScrollBar2@vgui@@UAEHXZ */
                    /* WARNING: Could not recover jumptable at 0x27015b18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(**(int **)(this + 0xc4) + 0x200))();
  return iVar1;
}


// vgui::ScrollBar2::hasFullRange  @ 27015cd0
/* public: virtual bool __thiscall vgui::ScrollBar2::hasFullRange(void) */

bool __thiscall vgui::ScrollBar2::hasFullRange(ScrollBar2 *this)

{
  undefined1 uVar1;
  
                    /* 0x15cd0  318  ?hasFullRange@ScrollBar2@vgui@@UAE_NXZ */
                    /* WARNING: Could not recover jumptable at 0x27015cd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(int **)(this + 0xc4) + 0x220))();
  return (bool)uVar1;
}


// vgui::ScrollBar2::isVertical  @ 27015cc0
/* public: virtual bool __thiscall vgui::ScrollBar2::isVertical(void) */

bool __thiscall vgui::ScrollBar2::isVertical(ScrollBar2 *this)

{
  undefined1 uVar1;
  
                    /* 0x15cc0  338  ?isVertical@ScrollBar2@vgui@@UAE_NXZ */
                    /* WARNING: Could not recover jumptable at 0x27015cc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(int **)(this + 0xc4) + 0x204))();
  return (bool)uVar1;
}


// vgui::ScrollBar2::operator=  @ 2700c0c0
/* public: class vgui::ScrollBar2 & __thiscall vgui::ScrollBar2::operator=(class vgui::ScrollBar2
   const &) */

ScrollBar2 * __thiscall vgui::ScrollBar2::operator=(ScrollBar2 *this,ScrollBar2 *param_1)

{
  ScrollBar2 *pSVar1;
  int iVar2;
  int iVar3;
  
                    /* 0xc0c0  135  ??4ScrollBar2@vgui@@QAEAAV01@ABV01@@Z
                       0xc0c0  136  ??4ScrollBar@vgui@@QAEAAV01@ABV01@@Z */
  iVar2 = (int)param_1 - (int)this;
  iVar3 = 2;
  pSVar1 = this;
  do {
    pSVar1 = pSVar1 + 4;
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pSVar1 = this + 0xc;
  iVar3 = 2;
  do {
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    pSVar1 = pSVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pSVar1 = this + 0x14;
  iVar3 = 2;
  do {
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    pSVar1 = pSVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pSVar1 = this + 0x1c;
  iVar3 = 2;
  do {
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    pSVar1 = pSVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pSVar1 = this + 0x24;
  iVar3 = 2;
  do {
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    pSVar1 = pSVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  pSVar1 = this + 0x58;
  iVar3 = 4;
  do {
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    pSVar1 = pSVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  pSVar1 = this + 0xa0;
  do {
    *pSVar1 = pSVar1[(int)(param_1 + (0x9c - (int)(this + 0x9c)))];
    pSVar1 = pSVar1 + 1;
  } while (pSVar1 + (-4 - (int)(this + 0x9c)) < (ScrollBar2 *)0x4);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  pSVar1 = this + 0xac;
  do {
    *pSVar1 = pSVar1[(int)(param_1 + (0xa8 - (int)(this + 0xa8)))];
    pSVar1 = pSVar1 + 1;
  } while (pSVar1 + (-4 - (int)(this + 0xa8)) < (ScrollBar2 *)0x4);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  pSVar1 = this + 0xbc;
  iVar3 = 2;
  do {
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    pSVar1 = pSVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)(this + 200) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined4 *)(this + 0xd0) = *(undefined4 *)(param_1 + 0xd0);
  *(undefined4 *)(this + 0xd4) = *(undefined4 *)(param_1 + 0xd4);
  return this;
}


// vgui::ScrollBar2::setButton  @ 27015ce0
/* public: virtual void __thiscall vgui::ScrollBar2::setButton(class vgui::Button *,int) */

void __thiscall vgui::ScrollBar2::setButton(ScrollBar2 *this,Button *param_1,int param_2)

{
  undefined4 *puVar1;
  
                    /* 0x15ce0  419  ?setButton@ScrollBar2@vgui@@UAEXPAVButton@2@H@Z */
  if (*(int *)(this + param_2 * 4 + 0xbc) != 0) {
    (**(code **)(*(int *)this + 0x4c))(*(int *)(this + param_2 * 4 + 0xbc));
  }
  *(Button **)(this + param_2 * 4 + 0xbc) = param_1;
  (**(code **)(*(int *)this + 0x44))(param_1);
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_LAB_2705a26c;
    puVar1[1] = this;
    puVar1[2] = param_2;
  }
  (**(code **)(**(int **)(this + param_2 * 4 + 0xbc) + 0x240))(puVar1);
  (**(code **)(*(int *)this + 0x234))();
  return;
}


// vgui::ScrollBar2::setButtonPressedScrollValue  @ 27016050
/* public: virtual void __thiscall vgui::ScrollBar2::setButtonPressedScrollValue(int) */

void __thiscall vgui::ScrollBar2::setButtonPressedScrollValue(ScrollBar2 *this,int param_1)

{
                    /* 0x16050  421  ?setButtonPressedScrollValue@ScrollBar2@vgui@@UAEXH@Z */
  *(int *)(this + 0xd4) = param_1;
  return;
}


// vgui::ScrollBar2::setRange  @ 27015c50
/* public: virtual void __thiscall vgui::ScrollBar2::setRange(int,int) */

void __thiscall vgui::ScrollBar2::setRange(ScrollBar2 *this,int param_1,int param_2)

{
                    /* 0x15c50  459  ?setRange@ScrollBar2@vgui@@UAEXHH@Z */
                    /* WARNING: Could not recover jumptable at 0x27015c58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(this + 0xc4) + 0x20c))();
  return;
}


// vgui::ScrollBar2::setRangeWindow  @ 27016060
/* public: virtual void __thiscall vgui::ScrollBar2::setRangeWindow(int) */

void __thiscall vgui::ScrollBar2::setRangeWindow(ScrollBar2 *this,int param_1)

{
                    /* 0x16060  461  ?setRangeWindow@ScrollBar2@vgui@@UAEXH@Z */
                    /* WARNING: Could not recover jumptable at 0x27016068. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(this + 0xc4) + 0x214))();
  return;
}


// vgui::ScrollBar2::setRangeWindowEnabled  @ 270162f0
/* public: virtual void __thiscall vgui::ScrollBar2::setRangeWindowEnabled(bool) */

void __thiscall vgui::ScrollBar2::setRangeWindowEnabled(ScrollBar2 *this,bool param_1)

{
                    /* 0x162f0  463  ?setRangeWindowEnabled@ScrollBar2@vgui@@UAEX_N@Z */
                    /* WARNING: Could not recover jumptable at 0x27016300. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(this + 0xc4) + 0x218))();
  return;
}


// vgui::ScrollBar2::setSize  @ 270159f0
/* public: virtual void __thiscall vgui::ScrollBar2::setSize(int,int) */

void __thiscall vgui::ScrollBar2::setSize(ScrollBar2 *this,int param_1,int param_2)

{
  char cVar1;
  int unaff_EBX;
  int unaff_retaddr;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
                    /* 0x159f0  465  ?setSize@ScrollBar2@vgui@@UAEXHH@Z */
  vgui::Panel::setSize((Panel *)this,param_1,param_2);
  if (((*(int *)(this + 0xc4) != 0) && (*(int *)(this + 0xbc) != 0)) && (*(int *)(this + 0xc0) != 0)
     ) {
    piVar4 = &param_2;
    piVar3 = &param_1;
    (**(code **)(*(int *)this + 0xe8))(piVar3,piVar4);
    cVar1 = (**(code **)(**(int **)(this + 0xc4) + 0x204))();
    if (cVar1 != '\0') {
      iVar2 = 0;
      (**(code **)(**(int **)(this + 0xc4) + 0x10))
                (0,unaff_EBX,unaff_EBX,unaff_retaddr + unaff_EBX * -2);
      (**(code **)(**(int **)(this + 0xbc) + 0x10))(0,0,piVar3,piVar3);
      (**(code **)(**(int **)(this + 0xc0) + 0x10))(0,unaff_EBX - iVar2,iVar2,iVar2);
      return;
    }
    iVar2 = 0;
    (**(code **)(**(int **)(this + 0xc4) + 0x10))
              (unaff_retaddr,0,unaff_EBX + unaff_retaddr * -2,unaff_retaddr);
    (**(code **)(**(int **)(this + 0xbc) + 0x10))(0,0,piVar4,piVar4);
    (**(code **)(**(int **)(this + 0xc0) + 0x10))(unaff_retaddr - iVar2,0,iVar2,iVar2);
  }
  return;
}


// vgui::ScrollBar2::setSlider  @ 27015d80
/* public: virtual void __thiscall vgui::ScrollBar2::setSlider(class vgui::Slider2 *) */

void __thiscall vgui::ScrollBar2::setSlider(ScrollBar2 *this,Slider2 *param_1)

{
  undefined4 *puVar1;
  
                    /* 0x15d80  467  ?setSlider@ScrollBar2@vgui@@UAEXPAVSlider2@2@@Z */
  if (*(int *)(this + 0xc4) != 0) {
    (**(code **)(*(int *)this + 0x4c))(*(int *)(this + 0xc4));
  }
  *(Slider2 **)(this + 0xc4) = param_1;
  (**(code **)(*(int *)this + 0x44))(param_1);
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_LAB_2705a264;
    puVar1[1] = this;
  }
  (**(code **)(**(int **)(this + 0xc4) + 0x208))(puVar1);
  (**(code **)(*(int *)this + 0x234))();
  return;
}


// vgui::ScrollBar2::setValue  @ 27015b00
/* public: virtual void __thiscall vgui::ScrollBar2::setValue(int) */

void __thiscall vgui::ScrollBar2::setValue(ScrollBar2 *this,int param_1)

{
                    /* 0x15b00  468  ?setValue@ScrollBar2@vgui@@UAEXH@Z */
                    /* WARNING: Could not recover jumptable at 0x27015b08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(this + 0xc4) + 0x1fc))();
  return;
}


// vgui::ScrollBar2::validate  @ 27016310
/* public: virtual void __thiscall vgui::ScrollBar2::validate(void) */

void __thiscall vgui::ScrollBar2::validate(ScrollBar2 *this)

{
  char cVar1;
  int iVar2;
  undefined4 unaff_EBX;
  ScrollBar2 *pSVar3;
  int iVar4;
  int local_c;
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
                    /* 0x16310  470  ?validate@ScrollBar2@vgui@@UAEXXZ */
  if (*(int *)(this + 0xc4) != 0) {
    iVar4 = 0;
    pSVar3 = this + 0xbc;
    local_c = 2;
    do {
      if (*(int **)pSVar3 != (int *)0x0) {
        cVar1 = (**(code **)(**(int **)pSVar3 + 0x28))();
        if (cVar1 != '\0') {
          cVar1 = (**(code **)(**(int **)(this + 0xc4) + 0x204))();
          if (cVar1 == '\0') {
            iVar2 = (**(code **)(**(int **)pSVar3 + 0x18))();
          }
          else {
            iVar2 = (**(code **)(**(int **)pSVar3 + 0x1c))();
          }
          iVar4 = iVar4 + iVar2;
        }
      }
      pSVar3 = pSVar3 + 4;
      local_c = local_c + -1;
    } while (local_c != 0);
    (**(code **)(**(int **)(this + 0xc4) + 0x224))(iVar4);
    local_c = 0;
  }
  (**(code **)(*(int *)this + 0xc))(local_4,local_8);
  (**(code **)(*(int *)this + 8))(local_c,unaff_EBX);
  return;
}


// vgui::ScrollBar::ScrollBar  @ 2700bec0
/* public: __thiscall vgui::ScrollBar::ScrollBar(class vgui::ScrollBar const &) */

void __thiscall vgui::ScrollBar::ScrollBar(ScrollBar *this,ScrollBar *param_1)

{
                    /* 0xbec0  74  ??0ScrollBar@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(this + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined ***)(this + 0x9c) = &Color::_vftable_;
  *(undefined4 *)(this + 0xac) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined ***)(this + 0xa8) = &Color::_vftable_;
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined ***)this = &Panel::_vftable_;
  *(undefined4 *)(this + 0xbc) = *(undefined4 *)(param_1 + 0xbc);
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)(this + 200) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined4 *)(this + 0xd0) = *(undefined4 *)(param_1 + 0xd0);
  *(undefined4 *)(this + 0xd4) = *(undefined4 *)(param_1 + 0xd4);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::ScrollPanel::ScrollPanel  @ 2700ba90
/* public: __thiscall vgui::ScrollPanel::ScrollPanel(class vgui::ScrollPanel const &) */

void __thiscall vgui::ScrollPanel::ScrollPanel(ScrollPanel *this,ScrollPanel *param_1)

{
                    /* 0xba90  75  ??0ScrollPanel@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(this + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined ***)(this + 0x9c) = &Color::_vftable_;
  *(undefined4 *)(this + 0xac) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined ***)(this + 0xa8) = &Color::_vftable_;
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined ***)this = &Panel::_vftable_;
  *(undefined4 *)(this + 0xbc) = *(undefined4 *)(param_1 + 0xbc);
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)(this + 200) = *(undefined4 *)(param_1 + 200);
  *(undefined2 *)(this + 0xcc) = *(undefined2 *)(param_1 + 0xcc);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::ScrollPanel::operator=  @ 2700bc80
/* public: class vgui::ScrollPanel & __thiscall vgui::ScrollPanel::operator=(class vgui::ScrollPanel
   const &) */

ScrollPanel * __thiscall vgui::ScrollPanel::operator=(ScrollPanel *this,ScrollPanel *param_1)

{
  ScrollPanel *pSVar1;
  int iVar2;
  int iVar3;
  
                    /* 0xbc80  137  ??4ScrollPanel@vgui@@QAEAAV01@ABV01@@Z */
  iVar2 = (int)param_1 - (int)this;
  iVar3 = 2;
  pSVar1 = this;
  do {
    pSVar1 = pSVar1 + 4;
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pSVar1 = this + 0xc;
  iVar3 = 2;
  do {
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    pSVar1 = pSVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pSVar1 = this + 0x14;
  iVar3 = 2;
  do {
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    pSVar1 = pSVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pSVar1 = this + 0x1c;
  iVar3 = 2;
  do {
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    pSVar1 = pSVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pSVar1 = this + 0x24;
  iVar3 = 2;
  do {
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    pSVar1 = pSVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  pSVar1 = this + 0x58;
  iVar3 = 4;
  do {
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    pSVar1 = pSVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  pSVar1 = this + 0xa0;
  do {
    *pSVar1 = pSVar1[(int)(param_1 + (0x9c - (int)(this + 0x9c)))];
    pSVar1 = pSVar1 + 1;
  } while (pSVar1 + (-4 - (int)(this + 0x9c)) < (ScrollPanel *)0x4);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  pSVar1 = this + 0xac;
  do {
    *pSVar1 = pSVar1[(int)(param_1 + (0xa8 - (int)(this + 0xa8)))];
    pSVar1 = pSVar1 + 1;
  } while (pSVar1 + (-4 - (int)(this + 0xa8)) < (ScrollPanel *)0x4);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined4 *)(this + 0xbc) = *(undefined4 *)(param_1 + 0xbc);
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)(this + 200) = *(undefined4 *)(param_1 + 200);
  pSVar1 = this + 0xcc;
  do {
    *pSVar1 = pSVar1[iVar2];
    pSVar1 = pSVar1 + 1;
  } while (pSVar1 + (-0xcc - (int)this) < (ScrollPanel *)0x2);
  return this;
}


// vgui::Slider2::Slider2  @ 27016070
/* public: __thiscall vgui::Slider2::Slider2(class vgui::Slider2 const &) */

void __thiscall vgui::Slider2::Slider2(Slider2 *this,Slider2 *param_1)

{
                    /* 0x16070  76  ??0Slider2@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(this + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined ***)(this + 0x9c) = &Color::_vftable_;
  *(undefined4 *)(this + 0xac) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined ***)(this + 0xa8) = &Color::_vftable_;
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined ***)this = &Panel::_vftable_;
  this[0xbc] = param_1[0xbc];
  this[0xbd] = param_1[0xbd];
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)(this + 200) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined4 *)(this + 0xd0) = *(undefined4 *)(param_1 + 0xd0);
  *(undefined4 *)(this + 0xd4) = *(undefined4 *)(param_1 + 0xd4);
  *(undefined4 *)(this + 0xd8) = *(undefined4 *)(param_1 + 0xd8);
  *(undefined4 *)(this + 0xdc) = *(undefined4 *)(param_1 + 0xdc);
  *(undefined4 *)(this + 0xe0) = *(undefined4 *)(param_1 + 0xe0);
  *(undefined4 *)(this + 0xe4) = *(undefined4 *)(param_1 + 0xe4);
  *(undefined4 *)(this + 0xe8) = *(undefined4 *)(param_1 + 0xe8);
  *(undefined4 *)(this + 0xec) = *(undefined4 *)(param_1 + 0xec);
  *(undefined4 *)(this + 0xf0) = *(undefined4 *)(param_1 + 0xf0);
  this[0xf4] = param_1[0xf4];
  *(undefined4 *)(this + 0xf8) = *(undefined4 *)(param_1 + 0xf8);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Slider2::Slider2  @ 270163d0
/* public: __thiscall vgui::Slider2::Slider2(int,int,int,int,bool) */

Slider2 * __thiscall
vgui::Slider2::Slider2(Slider2 *this,int param_1,int param_2,int param_3,int param_4,bool param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  InputSignal *pIVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  
                    /* 0x163d0  77  ??0Slider2@vgui@@QAE@HHHH_N@Z */
  vgui::Panel::Panel((Panel *)this,param_1,param_2,param_3,param_4);
  *(undefined4 *)(this + 0xd8) = 0;
  *(undefined4 *)(this + 0xdc) = 0;
  *(undefined4 *)(this + 0xe0) = 0;
  uVar1 = 1;
  do {
    uVar6 = uVar1;
    uVar1 = uVar6 * 2;
  } while ((int)uVar1 < 4);
  puVar2 = operator_new(uVar6 * 8);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_27046b03(0);
  }
  puVar7 = puVar2;
  for (iVar5 = (uVar6 & 0x1fffffff) << 1; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)puVar7 = 0;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  *(uint *)(this + 0xdc) = uVar1;
  iVar5 = 0;
  if (0 < *(int *)(this + 0xd8)) {
    do {
      iVar3 = iVar5 + 1;
      puVar2[iVar5] = *(undefined4 *)(*(int *)(this + 0xe0) + -4 + iVar3 * 4);
      iVar5 = iVar3;
    } while (iVar3 < *(int *)(this + 0xd8));
  }
  FUN_27046acb(*(undefined **)(this + 0xe0));
  *(undefined4 **)(this + 0xe0) = puVar2;
  this[0xbc] = param_4._0_1_;
  *(undefined ***)this = &_vftable_;
  this[0xbd] = (Slider2)0x0;
  *(undefined4 *)(this + 0xec) = 0;
  *(undefined4 *)(this + 0xe4) = 0;
  *(undefined4 *)(this + 0xe8) = 299;
  *(undefined4 *)(this + 0xf0) = 0;
  this[0xf4] = (Slider2)0x0;
  *(undefined4 *)(this + 0xf8) = 0;
  recomputeNobPosFromValue(this);
  pIVar4 = operator_new(8);
  if (pIVar4 != (InputSignal *)0x0) {
    *(undefined ***)pIVar4 = &PTR_LAB_2705a4c0;
    *(Slider2 **)(pIVar4 + 4) = this;
    vgui::Panel::addInputSignal((Panel *)this,pIVar4);
    return this;
  }
  vgui::Panel::addInputSignal((Panel *)this,(InputSignal *)0x0);
  return this;
}


// vgui::Slider2::addIntChangeSignal  @ 27016920
/* public: virtual void __thiscall vgui::Slider2::addIntChangeSignal(class vgui::IntChangeSignal *)
    */

void __thiscall vgui::Slider2::addIntChangeSignal(Slider2 *this,IntChangeSignal *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 unaff_retaddr;
  
                    /* 0x16920  254  ?addIntChangeSignal@Slider2@vgui@@UAEXPAVIntChangeSignal@2@@Z
                        */
  iVar2 = 0;
  iVar4 = *(int *)(this + 0xd8);
  if (0 < iVar4) {
    piVar5 = *(int **)(this + 0xe0);
    do {
      if ((IntChangeSignal *)*piVar5 == param_1) {
        return;
      }
      iVar2 = iVar2 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar2 < iVar4);
  }
  uVar6 = *(uint *)(this + 0xdc);
  if ((int)uVar6 < iVar4 + 1) {
    if (uVar6 == 0) {
      uVar6 = 1;
    }
    for (; (int)uVar6 < iVar4 + 1; uVar6 = uVar6 * 2) {
    }
    puVar1 = operator_new(uVar6 * 4);
    if (puVar1 == (undefined4 *)0x0) {
      FUN_27046b03(0);
    }
    puVar7 = puVar1;
    for (uVar3 = uVar6 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar7 = 0;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    *(uint *)(this + 0xdc) = uVar6;
    iVar4 = 0;
    if (0 < *(int *)(this + 0xd8)) {
      do {
        iVar2 = iVar4 + 1;
        puVar1[iVar4] = *(undefined4 *)(*(int *)(this + 0xe0) + -4 + iVar2 * 4);
        iVar4 = iVar2;
      } while (iVar2 < *(int *)(this + 0xd8));
    }
    FUN_27046acb(*(undefined **)(this + 0xe0));
    *(undefined4 **)(this + 0xe0) = puVar1;
  }
  *(undefined4 *)(*(int *)(this + 0xe0) + *(int *)(this + 0xd8) * 4) = unaff_retaddr;
  *(int *)(this + 0xd8) = *(int *)(this + 0xd8) + 1;
  return;
}


// vgui::Slider2::fireIntChangeSignal  @ 27016a10
/* protected: virtual void __thiscall vgui::Slider2::fireIntChangeSignal(void) */

void __thiscall vgui::Slider2::fireIntChangeSignal(Slider2 *this)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
                    /* 0x16a10  275  ?fireIntChangeSignal@Slider2@vgui@@MAEXXZ */
  iVar3 = 0;
  if (0 < *(int *)(this + 0xd8)) {
    do {
      if ((iVar3 < 0) || (*(int *)(this + 0xd8) <= iVar3)) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = *(undefined4 **)(*(int *)(this + 0xe0) + iVar3 * 4);
      }
      puVar2 = (undefined4 *)*puVar2;
      uVar1 = (**(code **)(*(int *)this + 0x200))(this);
      (*(code *)*puVar2)(uVar1);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(this + 0xd8));
  }
  return;
}


// vgui::Slider2::getNobPos  @ 27016e40
/* public: virtual void __thiscall vgui::Slider2::getNobPos(int &,int &) */

void __thiscall vgui::Slider2::getNobPos(Slider2 *this,int *param_1,int *param_2)

{
                    /* 0x16e40  295  ?getNobPos@Slider2@vgui@@UAEXAAH0@Z */
  *param_1 = *(int *)(this + 0xc0);
  *param_2 = *(int *)(this + 0xc4);
  return;
}


// vgui::Slider2::getRange  @ 27016c40
/* public: virtual void __thiscall vgui::Slider2::getRange(int &,int &) */

void __thiscall vgui::Slider2::getRange(Slider2 *this,int *param_1,int *param_2)

{
                    /* 0x16c40  296  ?getRange@Slider2@vgui@@UAEXAAH0@Z */
  *param_1 = *(int *)(this + 0xe4);
  *param_2 = *(int *)(this + 0xe8);
  return;
}


// vgui::Slider2::getValue  @ 270165f0
/* public: virtual int __thiscall vgui::Slider2::getValue(void) */

int __thiscall vgui::Slider2::getValue(Slider2 *this)

{
                    /* 0x165f0  299  ?getValue@Slider2@vgui@@UAEHXZ */
  return *(int *)(this + 0xec);
}


// vgui::Slider2::hasFullRange  @ 27016860
/* public: virtual bool __thiscall vgui::Slider2::hasFullRange(void) */

bool __thiscall vgui::Slider2::hasFullRange(Slider2 *this)

{
  float fVar1;
  undefined1 *puVar2;
  undefined1 *unaff_ESI;
  undefined1 local_c [4];
  undefined1 local_8 [8];
  
                    /* 0x16860  319  ?hasFullRange@Slider2@vgui@@UAE_NXZ */
  puVar2 = local_8;
  (**(code **)(*(int *)this + 0xe8))(local_c);
  fVar1 = (float)*(int *)(this + 0xf0);
  if (fVar1 < 0.0) {
    fVar1 = 0.0;
  }
  if (this[0xf4] == (Slider2)0x0) {
    fVar1 = (float)(*(int *)(this + 0xe8) - *(int *)(this + 0xe4));
  }
  if (0.0 < fVar1) {
    if (this[0xbc] != (Slider2)0x0) {
      puVar2 = unaff_ESI;
    }
    if (fVar1 < (float)*(int *)(this + 0xf8) + (float)(int)puVar2 !=
        (fVar1 == (float)*(int *)(this + 0xf8) + (float)(int)puVar2)) {
      return true;
    }
  }
  return false;
}


// vgui::Slider2::isVertical  @ 27016590
/* public: virtual bool __thiscall vgui::Slider2::isVertical(void) */

bool __thiscall vgui::Slider2::isVertical(Slider2 *this)

{
                    /* 0x16590  339  ?isVertical@Slider2@vgui@@UAE_NXZ */
  return (bool)this[0xbc];
}


// vgui::Slider2::operator=  @ 2700c580
/* public: class vgui::Slider2 & __thiscall vgui::Slider2::operator=(class vgui::Slider2 const &) */

Slider2 * __thiscall vgui::Slider2::operator=(Slider2 *this,Slider2 *param_1)

{
  Slider2 *pSVar1;
  int iVar2;
  int iVar3;
  
                    /* 0xc580  138  ??4Slider2@vgui@@QAEAAV01@ABV01@@Z
                       0xc580  139  ??4Slider@vgui@@QAEAAV01@ABV01@@Z */
  iVar2 = (int)param_1 - (int)this;
  iVar3 = 2;
  pSVar1 = this;
  do {
    pSVar1 = pSVar1 + 4;
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pSVar1 = this + 0xc;
  iVar3 = 2;
  do {
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    pSVar1 = pSVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pSVar1 = this + 0x14;
  iVar3 = 2;
  do {
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    pSVar1 = pSVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pSVar1 = this + 0x1c;
  iVar3 = 2;
  do {
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    pSVar1 = pSVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pSVar1 = this + 0x24;
  iVar3 = 2;
  do {
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    pSVar1 = pSVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  pSVar1 = this + 0x58;
  iVar3 = 4;
  do {
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    pSVar1 = pSVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  pSVar1 = this + 0xa0;
  do {
    *pSVar1 = pSVar1[(int)(param_1 + (0x9c - (int)(this + 0x9c)))];
    pSVar1 = pSVar1 + 1;
  } while (pSVar1 + (-4 - (int)(this + 0x9c)) < (Slider2 *)0x4);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  pSVar1 = this + 0xac;
  do {
    *pSVar1 = pSVar1[(int)(param_1 + (0xa8 - (int)(this + 0xa8)))];
    pSVar1 = pSVar1 + 1;
  } while (pSVar1 + (-4 - (int)(this + 0xa8)) < (Slider2 *)0x4);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  this[0xbc] = param_1[0xbc];
  this[0xbd] = param_1[0xbd];
  pSVar1 = this + 0xc0;
  iVar3 = 2;
  do {
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    pSVar1 = pSVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pSVar1 = this + 200;
  iVar3 = 2;
  do {
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    pSVar1 = pSVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pSVar1 = this + 0xd0;
  iVar3 = 2;
  do {
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    pSVar1 = pSVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0xd8) = *(undefined4 *)(param_1 + 0xd8);
  *(undefined4 *)(this + 0xdc) = *(undefined4 *)(param_1 + 0xdc);
  *(undefined4 *)(this + 0xe0) = *(undefined4 *)(param_1 + 0xe0);
  pSVar1 = this + 0xe4;
  iVar3 = 2;
  do {
    *(undefined4 *)pSVar1 = *(undefined4 *)(pSVar1 + iVar2);
    pSVar1 = pSVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0xec) = *(undefined4 *)(param_1 + 0xec);
  *(undefined4 *)(this + 0xf0) = *(undefined4 *)(param_1 + 0xf0);
  this[0xf4] = param_1[0xf4];
  *(undefined4 *)(this + 0xf8) = *(undefined4 *)(param_1 + 0xf8);
  return this;
}


// vgui::Slider2::paintBackground  @ 27016a60
/* protected: virtual void __thiscall vgui::Slider2::paintBackground(void) */

void __thiscall vgui::Slider2::paintBackground(Slider2 *this)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
                    /* 0x16a60  340  ?paintBackground@Slider2@vgui@@MAEXXZ */
  puVar5 = local_8;
  puVar6 = local_4;
  (**(code **)(*(int *)this + 0xe8))(local_8,puVar6);
  if (this[0xbc] != (Slider2)0x0) {
    uVar4 = 0x28;
    uVar3 = 0x28;
    (**(code **)(*(int *)this + 0x178))(0x28,0x28,0x28,0);
    (**(code **)(*(int *)this + 0x180))(0,0,uVar3,uVar4);
    uVar3 = 0;
    (**(code **)(*(int *)this + 0x178))(0,0,0,0);
    (**(code **)(*(int *)this + 0x180))
              (0,*(undefined4 *)(this + 0xc0),uVar3,*(undefined4 *)(this + 0xc4));
    uVar3 = 0x3c;
    (**(code **)(*(int *)this + 0x178))(0x3c,0x3c,0x3c,0);
    iVar1 = *(int *)(this + 0xc0);
    (**(code **)(*(int *)this + 0x180))(0,iVar1,uVar3,iVar1 + 1);
    (**(code **)(*(int *)this + 0x180))(0,*(int *)(this + 0xc4),iVar1,*(int *)(this + 0xc4) + 1);
    iVar1 = *(int *)(this + 0xc0) + 1;
    (**(code **)(*(int *)this + 0x180))(0,iVar1,1,*(undefined4 *)(this + 0xc4));
    (**(code **)(*(int *)this + 0x180))
              (iVar1 + -1,*(int *)(this + 0xc0) + 1,iVar1,*(undefined4 *)(this + 0xc4));
    return;
  }
  (**(code **)(*(int *)this + 0x17c))(8);
  uVar2 = 0;
  uVar3 = 0;
  (**(code **)(*(int *)this + 0x180))(0,0,puVar5,puVar6);
  (**(code **)(*(int *)this + 0x17c))(1);
  uVar4 = 0;
  (**(code **)(*(int *)this + 0x184))(0,0,uVar3,uVar2);
  (**(code **)(*(int *)this + 0x17c))(4);
  uVar3 = 0;
  (**(code **)(*(int *)this + 0x180))
            (*(undefined4 *)(this + 0xc0),0,*(undefined4 *)(this + 0xc4),uVar4);
  (**(code **)(*(int *)this + 0x17c))(1);
  (**(code **)(*(int *)this + 0x184))
            (*(undefined4 *)(this + 0xc0),0,*(undefined4 *)(this + 0xc4),uVar3);
  return;
}


// vgui::Slider2::privateCursorMoved  @ 27016c60
/* public: virtual void __thiscall vgui::Slider2::privateCursorMoved(int,int,class vgui::Panel *) */

void __thiscall
vgui::Slider2::privateCursorMoved(Slider2 *this,int param_1,int param_2,Panel *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int unaff_EDI;
  int *piStack_18;
  int *piStack_14;
  undefined1 auStack_4 [4];
  
                    /* 0x16c60  342  ?privateCursorMoved@Slider2@vgui@@UAEXHHPAVPanel@2@@Z */
  if (this[0xbd] != (Slider2)0x0) {
    piStack_14 = (int *)0x27016c7d;
    piVar1 = (int *)(**(code **)(*(int *)this + 0x14c))();
    piStack_14 = &param_2;
    piStack_18 = &param_1;
    (**(code **)(*piVar1 + 0x34))();
    (**(code **)(*(int *)this + 0x8c))();
    (**(code **)(*(int *)this + 0xe8))(&piStack_14,&piStack_18);
    if (this[0xbc] == (Slider2)0x0) {
      iVar2 = (*(int *)(this + 200) - *(int *)(this + 0xd0)) + (int)piStack_14;
      iVar3 = (*(int *)(this + 0xcc) - *(int *)(this + 0xd0)) + (int)piStack_14;
    }
    else {
      iVar2 = (*(int *)(this + 200) - *(int *)(this + 0xd4)) + unaff_EDI;
      iVar3 = (*(int *)(this + 0xcc) - *(int *)(this + 0xd4)) + unaff_EDI;
      register0x00000010 = (BADSPACEBASE *)auStack_4;
    }
    *(int *)(this + 0xc0) = iVar2;
    *(int *)(this + 0xc4) = iVar3;
    if ((int)register0x00000010 < iVar3) {
      *(BADSPACEBASE **)(this + 0xc4) = register0x00000010;
      *(undefined1 **)(this + 0xc0) = (undefined1 *)((int)register0x00000010 + (iVar2 - iVar3));
    }
    iVar3 = *(int *)(this + 0xc0);
    if (iVar3 < 0) {
      *(undefined4 *)(this + 0xc0) = 0;
      *(int *)(this + 0xc4) = *(int *)(this + 0xc4) - iVar3;
    }
    (**(code **)(*(int *)this + 0x22c))();
    (**(code **)(*(int *)this + 0x30))();
    (**(code **)(*(int *)this + 0x23c))();
  }
  return;
}


// vgui::Slider2::privateMousePressed  @ 27016d70
/* public: virtual void __thiscall vgui::Slider2::privateMousePressed(enum vgui::MouseCode,class
   vgui::Panel *) */

void __thiscall vgui::Slider2::privateMousePressed(Slider2 *this,MouseCode param_1,Panel *param_2)

{
  int *piVar1;
  undefined1 *puVar2;
  undefined1 *puStack_10;
  undefined1 auStack_8 [4];
  undefined1 auStack_4 [4];
  
                    /* 0x16d70  343
                       ?privateMousePressed@Slider2@vgui@@UAEXW4MouseCode@2@PAVPanel@2@@Z */
  puStack_10 = (undefined1 *)0x27016d7e;
  piVar1 = (int *)(**(code **)(*(int *)this + 0x14c))();
  puStack_10 = auStack_4;
  (**(code **)(*piVar1 + 0x34))();
  (**(code **)(*(int *)this + 0x8c))();
  puVar2 = auStack_8;
  if (this[0xbc] == (Slider2)0x0) {
    puVar2 = &stack0xfffffff4;
  }
  if ((*(int *)(this + 0xc0) <= (int)puVar2) && ((int)puVar2 < *(int *)(this + 0xc4))) {
    this[0xbd] = (Slider2)0x1;
    piVar1 = (int *)(**(code **)(*(int *)this + 0x14c))();
    (**(code **)(*piVar1 + 0x38))(this);
    *(undefined4 *)(this + 200) = *(undefined4 *)(this + 0xc0);
    *(undefined4 *)(this + 0xcc) = *(undefined4 *)(this + 0xc4);
    *(undefined1 ***)(this + 0xd0) = &puStack_10;
    *(undefined1 **)(this + 0xd4) = &stack0xfffffff4;
  }
  return;
}


// vgui::Slider2::privateMouseReleased  @ 27016e20
/* public: virtual void __thiscall vgui::Slider2::privateMouseReleased(enum vgui::MouseCode,class
   vgui::Panel *) */

void __thiscall vgui::Slider2::privateMouseReleased(Slider2 *this,MouseCode param_1,Panel *param_2)

{
  int *piVar1;
  
                    /* 0x16e20  344
                       ?privateMouseReleased@Slider2@vgui@@UAEXW4MouseCode@2@PAVPanel@2@@Z */
  this[0xbd] = (Slider2)0x0;
  piVar1 = (int *)(**(code **)(*(int *)this + 0x14c))();
  (**(code **)(*piVar1 + 0x38))(0);
  return;
}


// vgui::Slider2::recomputeNobPosFromValue  @ 27016600
/* private: virtual void __thiscall vgui::Slider2::recomputeNobPosFromValue(void) */

void __thiscall vgui::Slider2::recomputeNobPosFromValue(Slider2 *this)

{
  int unaff_ESI;
  longlong lVar1;
  float fVar2;
  int local_14;
  float fStack_10;
  float local_c [3];
  
                    /* 0x16600  363  ?recomputeNobPosFromValue@Slider2@vgui@@EAEXXZ */
  (**(code **)(*(int *)this + 0xe8))(local_c,&local_14);
  local_c[0] = (float)local_14;
  fStack_10 = (float)unaff_ESI;
  fVar2 = (float)*(int *)(this + 0xf0);
  if (fVar2 < 0.0) {
    fVar2 = 0.0;
  }
  if (this[0xf4] == (Slider2)0x0) {
    fVar2 = (float)(*(int *)(this + 0xe8) - *(int *)(this + 0xe4));
  }
  if (0.0 < fVar2) {
    if (this[0xbc] == (Slider2)0x0) {
      lVar1 = __ftol();
      *(int *)(this + 0xc0) = (int)lVar1;
      lVar1 = __ftol();
      *(int *)(this + 0xc4) = (int)lVar1;
      if (local_14 < (int)lVar1) {
        lVar1 = __ftol();
        *(int *)(this + 0xc4) = local_14;
        *(int *)(this + 0xc0) = local_14 - (int)lVar1;
      }
    }
    else {
      lVar1 = __ftol();
      *(int *)(this + 0xc0) = (int)lVar1;
      lVar1 = __ftol();
      *(int *)(this + 0xc4) = (int)lVar1;
      if (unaff_ESI < (int)lVar1) {
        lVar1 = __ftol();
        *(int *)(this + 0xc4) = unaff_ESI;
        *(int *)(this + 0xc0) = unaff_ESI - (int)lVar1;
        (**(code **)(*(int *)this + 0x30))();
        return;
      }
    }
  }
  (**(code **)(*(int *)this + 0x30))();
  return;
}


// vgui::Slider2::recomputeValueFromNobPos  @ 27016760
/* private: virtual void __thiscall vgui::Slider2::recomputeValueFromNobPos(void) */

void __thiscall vgui::Slider2::recomputeValueFromNobPos(Slider2 *this)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  longlong lVar3;
  int iStack_18;
  float local_14;
  float local_10;
  undefined4 uStack_c;
  
                    /* 0x16760  364  ?recomputeValueFromNobPos@Slider2@vgui@@EAEXXZ */
  (**(code **)(*(int *)this + 0xe8))(&local_10,&local_14);
  local_10 = (float)iStack_18;
  iVar1 = *(int *)(this + 0xe8);
  uStack_c = *(undefined4 *)(this + 0xe4);
  local_14 = (float)unaff_ESI;
  lVar3 = __ftol();
  iVar2 = (int)lVar3;
  *(int *)(this + 0xec) = iVar2;
  if (iVar1 <= iVar2) {
    *(int *)(this + 0xec) = iVar1;
    return;
  }
  *(int *)(this + 0xec) = iVar2;
  return;
}


// vgui::Slider2::setButtonOffset  @ 27016e80
/* public: virtual void __thiscall vgui::Slider2::setButtonOffset(int) */

void __thiscall vgui::Slider2::setButtonOffset(Slider2 *this,int param_1)

{
                    /* 0x16e80  420  ?setButtonOffset@Slider2@vgui@@UAEXH@Z */
  *(int *)(this + 0xf8) = param_1;
  return;
}


// vgui::Slider2::setRange  @ 27016c10
/* public: virtual void __thiscall vgui::Slider2::setRange(int,int) */

void __thiscall vgui::Slider2::setRange(Slider2 *this,int param_1,int param_2)

{
                    /* 0x16c10  460  ?setRange@Slider2@vgui@@UAEXHH@Z */
  *(int *)(this + 0xe4) = param_1;
  if (param_2 < param_1) {
    *(int *)(this + 0xe8) = param_1;
    return;
  }
  *(int *)(this + 0xe8) = param_2;
  return;
}


// vgui::Slider2::setRangeWindow  @ 27016e60
/* public: virtual void __thiscall vgui::Slider2::setRangeWindow(int) */

void __thiscall vgui::Slider2::setRangeWindow(Slider2 *this,int param_1)

{
                    /* 0x16e60  462  ?setRangeWindow@Slider2@vgui@@UAEXH@Z */
  *(int *)(this + 0xf0) = param_1;
  return;
}


// vgui::Slider2::setRangeWindowEnabled  @ 27016e70
/* public: virtual void __thiscall vgui::Slider2::setRangeWindowEnabled(bool) */

void __thiscall vgui::Slider2::setRangeWindowEnabled(Slider2 *this,bool param_1)

{
                    /* 0x16e70  464  ?setRangeWindowEnabled@Slider2@vgui@@UAEX_N@Z */
  this[0xf4] = (Slider2)param_1;
  return;
}


// vgui::Slider2::setSize  @ 27016560
/* public: virtual void __thiscall vgui::Slider2::setSize(int,int) */

void __thiscall vgui::Slider2::setSize(Slider2 *this,int param_1,int param_2)

{
                    /* 0x16560  466  ?setSize@Slider2@vgui@@UAEXHH@Z */
  vgui::Panel::setSize((Panel *)this,param_1,param_2);
  (**(code **)(*(int *)this + 0x228))();
  return;
}


// vgui::Slider2::setValue  @ 270165a0
/* public: virtual void __thiscall vgui::Slider2::setValue(int) */

void __thiscall vgui::Slider2::setValue(Slider2 *this,int param_1)

{
  int iVar1;
  
                    /* 0x165a0  469  ?setValue@Slider2@vgui@@UAEXH@Z */
  iVar1 = *(int *)(this + 0xec);
  if (param_1 < *(int *)(this + 0xe4)) {
    param_1 = *(int *)(this + 0xe4);
  }
  if (*(int *)(this + 0xe8) < param_1) {
    param_1 = *(int *)(this + 0xe8);
  }
  *(int *)(this + 0xec) = param_1;
  (**(code **)(*(int *)this + 0x228))();
  if (*(int *)(this + 0xec) != iVar1) {
    (**(code **)(*(int *)this + 0x23c))();
  }
  return;
}


// vgui::Slider::Slider  @ 2700c300
/* public: __thiscall vgui::Slider::Slider(class vgui::Slider const &) */

void __thiscall vgui::Slider::Slider(Slider *this,Slider *param_1)

{
                    /* 0xc300  78  ??0Slider@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(this + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined ***)(this + 0x9c) = &Color::_vftable_;
  *(undefined4 *)(this + 0xac) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined ***)(this + 0xa8) = &Color::_vftable_;
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined ***)this = &Panel::_vftable_;
  this[0xbc] = param_1[0xbc];
  this[0xbd] = param_1[0xbd];
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)(this + 200) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined4 *)(this + 0xd0) = *(undefined4 *)(param_1 + 0xd0);
  *(undefined4 *)(this + 0xd4) = *(undefined4 *)(param_1 + 0xd4);
  *(undefined4 *)(this + 0xd8) = *(undefined4 *)(param_1 + 0xd8);
  *(undefined4 *)(this + 0xdc) = *(undefined4 *)(param_1 + 0xdc);
  *(undefined4 *)(this + 0xe0) = *(undefined4 *)(param_1 + 0xe0);
  *(undefined4 *)(this + 0xe4) = *(undefined4 *)(param_1 + 0xe4);
  *(undefined4 *)(this + 0xe8) = *(undefined4 *)(param_1 + 0xe8);
  *(undefined4 *)(this + 0xec) = *(undefined4 *)(param_1 + 0xec);
  *(undefined4 *)(this + 0xf0) = *(undefined4 *)(param_1 + 0xf0);
  this[0xf4] = param_1[0xf4];
  *(undefined4 *)(this + 0xf8) = *(undefined4 *)(param_1 + 0xf8);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::StackLayout::StackLayout  @ 27038130
/* public: __thiscall vgui::StackLayout::StackLayout(class vgui::StackLayout const &) */

void __thiscall vgui::StackLayout::StackLayout(StackLayout *this,StackLayout *param_1)

{
                    /* 0x38130  79  ??0StackLayout@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &Layout::_vftable_;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  this[8] = param_1[8];
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::StackLayout::operator=  @ 27038160
/* public: class vgui::StackLayout & __thiscall vgui::StackLayout::operator=(class vgui::StackLayout
   const &) */

StackLayout * __thiscall vgui::StackLayout::operator=(StackLayout *this,StackLayout *param_1)

{
                    /* 0x38160  140  ??4StackLayout@vgui@@QAEAAV01@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  this[8] = param_1[8];
  return this;
}


// vgui::String::operator=  @ 2700ba80
/* public: class vgui::String & __thiscall vgui::String::operator=(class vgui::String const &) */

String * __thiscall vgui::String::operator=(String *this,String *param_1)

{
                    /* 0xba80  141  ??4String@vgui@@QAEAAV01@ABV01@@Z */
  *(undefined4 *)this = *(undefined4 *)param_1;
  return this;
}


// vgui::Surface::Surface  @ 2703cc60
/* public: __thiscall vgui::Surface::Surface(class vgui::Surface const &) */

void __thiscall vgui::Surface::Surface(Surface *this,Surface *param_1)

{
  undefined4 uVar1;
  
                    /* 0x3cc60  80  ??0Surface@vgui@@QAE@ABV01@@Z */
  this[4] = param_1[4];
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined ***)this = &SurfaceBase::_vftable_;
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  this[0x28] = param_1[0x28];
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  uVar1 = *(undefined4 *)(param_1 + 0x38);
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0x38) = uVar1;
  return;
}


// vgui::Surface::operator=  @ 2703cce0
/* public: class vgui::Surface & __thiscall vgui::Surface::operator=(class vgui::Surface const &) */

Surface * __thiscall vgui::Surface::operator=(Surface *this,Surface *param_1)

{
                    /* 0x3cce0  142  ??4Surface@vgui@@QAEAAV01@ABV01@@Z */
  this[4] = param_1[4];
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  this[0x28] = param_1[0x28];
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  return this;
}


// vgui::Surface::~Surface  @ 2703cd50
/* public: __thiscall vgui::Surface::~Surface(void) */

void __thiscall vgui::Surface::~Surface(Surface *this)

{
                    /* 0x3cd50  87  ??1Surface@vgui@@QAE@XZ */
                    /* WARNING: Could not recover jumptable at 0x270468b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  vgui::SurfaceBase::~SurfaceBase((SurfaceBase *)this);
  return;
}


// vgui::SurfaceBase::SurfaceBase  @ 270372a0
/* public: __thiscall vgui::SurfaceBase::SurfaceBase(class vgui::SurfaceBase const &) */

void __thiscall vgui::SurfaceBase::SurfaceBase(SurfaceBase *this,SurfaceBase *param_1)

{
                    /* 0x372a0  81  ??0SurfaceBase@vgui@@QAE@ABV01@@Z */
  this[4] = param_1[4];
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::SurfaceBase::operator=  @ 270372f0
/* public: class vgui::SurfaceBase & __thiscall vgui::SurfaceBase::operator=(class vgui::SurfaceBase
   const &) */

SurfaceBase * __thiscall vgui::SurfaceBase::operator=(SurfaceBase *this,SurfaceBase *param_1)

{
                    /* 0x372f0  143  ??4SurfaceBase@vgui@@QAEAAV01@ABV01@@Z */
  this[4] = param_1[4];
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  return this;
}


// vgui::TablePanel::TablePanel  @ 27018bd0
/* public: __thiscall vgui::TablePanel::TablePanel(class vgui::TablePanel const &) */

void __thiscall vgui::TablePanel::TablePanel(TablePanel *this,TablePanel *param_1)

{
                    /* 0x18bd0  82  ??0TablePanel@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(this + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined ***)(this + 0x9c) = &Color::_vftable_;
  *(undefined4 *)(this + 0xac) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined ***)(this + 0xa8) = &Color::_vftable_;
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined ***)this = &Panel::_vftable_;
  *(undefined4 *)(this + 0xbc) = *(undefined4 *)(param_1 + 0xbc);
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined2 *)(this + 200) = *(undefined2 *)(param_1 + 200);
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined4 *)(this + 0xd0) = *(undefined4 *)(param_1 + 0xd0);
  *(undefined4 *)(this + 0xd4) = *(undefined4 *)(param_1 + 0xd4);
  *(undefined4 *)(this + 0xd8) = *(undefined4 *)(param_1 + 0xd8);
  *(undefined4 *)(this + 0xdc) = *(undefined4 *)(param_1 + 0xdc);
  *(undefined4 *)(this + 0xe0) = *(undefined4 *)(param_1 + 0xe0);
  *(undefined4 *)(this + 0xe4) = *(undefined4 *)(param_1 + 0xe4);
  *(undefined4 *)(this + 0xe8) = *(undefined4 *)(param_1 + 0xe8);
  *(undefined4 *)(this + 0xec) = *(undefined4 *)(param_1 + 0xec);
  this[0xf0] = param_1[0xf0];
  this[0xf1] = param_1[0xf1];
  this[0xf2] = param_1[0xf2];
  *(undefined4 *)(this + 0xf4) = *(undefined4 *)(param_1 + 0xf4);
  *(undefined4 *)(this + 0xf8) = *(undefined4 *)(param_1 + 0xf8);
  *(undefined4 *)(this + 0xfc) = *(undefined4 *)(param_1 + 0xfc);
  this[0x100] = param_1[0x100];
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::TablePanel::operator=  @ 27018e70
/* public: class vgui::TablePanel & __thiscall vgui::TablePanel::operator=(class vgui::TablePanel
   const &) */

TablePanel * __thiscall vgui::TablePanel::operator=(TablePanel *this,TablePanel *param_1)

{
  TablePanel *pTVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x18e70  144  ??4TablePanel@vgui@@QAEAAV01@ABV01@@Z */
  iVar2 = (int)param_1 - (int)this;
  iVar3 = 2;
  pTVar1 = this;
  do {
    pTVar1 = pTVar1 + 4;
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pTVar1 = this + 0xc;
  iVar3 = 2;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pTVar1 = this + 0x14;
  iVar3 = 2;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pTVar1 = this + 0x1c;
  iVar3 = 2;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pTVar1 = this + 0x24;
  iVar3 = 2;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  pTVar1 = this + 0x58;
  iVar3 = 4;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  pTVar1 = this + 0xa0;
  do {
    *pTVar1 = pTVar1[(int)(param_1 + (0x9c - (int)(this + 0x9c)))];
    pTVar1 = pTVar1 + 1;
  } while (pTVar1 + (-4 - (int)(this + 0x9c)) < (TablePanel *)0x4);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  pTVar1 = this + 0xac;
  do {
    *pTVar1 = pTVar1[(int)(param_1 + (0xa8 - (int)(this + 0xa8)))];
    pTVar1 = pTVar1 + 1;
  } while (pTVar1 + (-4 - (int)(this + 0xa8)) < (TablePanel *)0x4);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined4 *)(this + 0xbc) = *(undefined4 *)(param_1 + 0xbc);
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  pTVar1 = this + 200;
  do {
    *pTVar1 = pTVar1[iVar2];
    pTVar1 = pTVar1 + 1;
  } while (pTVar1 + (-200 - (int)this) < (TablePanel *)0x2);
  iVar3 = 2;
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined4 *)(this + 0xd0) = *(undefined4 *)(param_1 + 0xd0);
  pTVar1 = this + 0xd4;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pTVar1 = this + 0xdc;
  iVar3 = 2;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pTVar1 = this + 0xe4;
  iVar3 = 2;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = 2;
  *(undefined4 *)(this + 0xec) = *(undefined4 *)(param_1 + 0xec);
  this[0xf0] = param_1[0xf0];
  this[0xf1] = param_1[0xf1];
  this[0xf2] = param_1[0xf2];
  *(undefined4 *)(this + 0xf4) = *(undefined4 *)(param_1 + 0xf4);
  pTVar1 = this + 0xf8;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  this[0x100] = param_1[0x100];
  return this;
}


// vgui::TextEntry::TextEntry  @ 27035690
/* public: __thiscall vgui::TextEntry::TextEntry(class vgui::TextEntry const &) */

void __thiscall vgui::TextEntry::TextEntry(TextEntry *this,TextEntry *param_1)

{
                    /* 0x35690  83  ??0TextEntry@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(this + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined ***)(this + 0x9c) = &Color::_vftable_;
  *(undefined4 *)(this + 0xac) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined ***)(this + 0xa8) = &Color::_vftable_;
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined ***)this = &Panel::_vftable_;
  *(undefined ***)(this + 0xbc) = &InputSignal::_vftable_;
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)(this + 200) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
  this[0xd0] = param_1[0xd0];
  this[0xd1] = param_1[0xd1];
  *(undefined4 *)(this + 0xd4) = *(undefined4 *)(param_1 + 0xd4);
  *(undefined4 *)(this + 0xd8) = *(undefined4 *)(param_1 + 0xd8);
  *(undefined4 *)(this + 0xdc) = *(undefined4 *)(param_1 + 0xdc);
  *(undefined4 *)(this + 0xe0) = *(undefined4 *)(param_1 + 0xe0);
  *(undefined4 *)(this + 0xe4) = *(undefined4 *)(param_1 + 0xe4);
  *(undefined4 *)(this + 0xe8) = *(undefined4 *)(param_1 + 0xe8);
  *(undefined4 *)(this + 0xec) = *(undefined4 *)(param_1 + 0xec);
  *(undefined4 *)(this + 0xf0) = *(undefined4 *)(param_1 + 0xf0);
  *(undefined ***)this = &_vftable__for__vgui__Panel__;
  *(undefined ***)(this + 0xbc) = &_vftable__for__vgui__InputSignal__;
  return;
}


// vgui::TextEntry::operator=  @ 270358f0
/* public: class vgui::TextEntry & __thiscall vgui::TextEntry::operator=(class vgui::TextEntry const
   &) */

TextEntry * __thiscall vgui::TextEntry::operator=(TextEntry *this,TextEntry *param_1)

{
  TextEntry *pTVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x358f0  145  ??4TextEntry@vgui@@QAEAAV01@ABV01@@Z */
  iVar2 = (int)param_1 - (int)this;
  iVar3 = 2;
  pTVar1 = this;
  do {
    pTVar1 = pTVar1 + 4;
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pTVar1 = this + 0xc;
  iVar3 = 2;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pTVar1 = this + 0x14;
  iVar3 = 2;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pTVar1 = this + 0x1c;
  iVar3 = 2;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pTVar1 = this + 0x24;
  iVar3 = 2;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  pTVar1 = this + 0x58;
  iVar3 = 4;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  pTVar1 = this + 0xa0;
  do {
    *pTVar1 = pTVar1[(int)(param_1 + (0x9c - (int)(this + 0x9c)))];
    pTVar1 = pTVar1 + 1;
  } while (pTVar1 + (-4 - (int)(this + 0x9c)) < (TextEntry *)0x4);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  pTVar1 = this + 0xac;
  do {
    *pTVar1 = pTVar1[(int)(param_1 + (0xa8 - (int)(this + 0xa8)))];
    pTVar1 = pTVar1 + 1;
  } while (pTVar1 + (-4 - (int)(this + 0xa8)) < (TextEntry *)0x4);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)(this + 200) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
  this[0xd0] = param_1[0xd0];
  this[0xd1] = param_1[0xd1];
  *(undefined4 *)(this + 0xd4) = *(undefined4 *)(param_1 + 0xd4);
  *(undefined4 *)(this + 0xd8) = *(undefined4 *)(param_1 + 0xd8);
  pTVar1 = this + 0xdc;
  iVar3 = 2;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0xe4) = *(undefined4 *)(param_1 + 0xe4);
  *(undefined4 *)(this + 0xe8) = *(undefined4 *)(param_1 + 0xe8);
  *(undefined4 *)(this + 0xec) = *(undefined4 *)(param_1 + 0xec);
  *(undefined4 *)(this + 0xf0) = *(undefined4 *)(param_1 + 0xf0);
  return this;
}


// vgui::TextGrid::TextGrid  @ 27019620
/* public: __thiscall vgui::TextGrid::TextGrid(class vgui::TextGrid const &) */

void __thiscall vgui::TextGrid::TextGrid(TextGrid *this,TextGrid *param_1)

{
                    /* 0x19620  84  ??0TextGrid@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(this + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined ***)(this + 0x9c) = &Color::_vftable_;
  *(undefined4 *)(this + 0xac) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined ***)(this + 0xa8) = &Color::_vftable_;
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined ***)this = &Panel::_vftable_;
  *(undefined4 *)(this + 0xbc) = *(undefined4 *)(param_1 + 0xbc);
  *(undefined4 *)(this + 0xc0) = *(undefined4 *)(param_1 + 0xc0);
  *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
  *(undefined4 *)(this + 200) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined4 *)(this + 0xd0) = *(undefined4 *)(param_1 + 0xd0);
  *(undefined4 *)(this + 0xd4) = *(undefined4 *)(param_1 + 0xd4);
  *(undefined4 *)(this + 0xd8) = *(undefined4 *)(param_1 + 0xd8);
  *(undefined4 *)(this + 0xdc) = *(undefined4 *)(param_1 + 0xdc);
  *(undefined4 *)(this + 0xe0) = *(undefined4 *)(param_1 + 0xe0);
  *(undefined4 *)(this + 0xe4) = *(undefined4 *)(param_1 + 0xe4);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::TextGrid::operator=  @ 27019850
/* public: class vgui::TextGrid & __thiscall vgui::TextGrid::operator=(class vgui::TextGrid const &)
    */

TextGrid * __thiscall vgui::TextGrid::operator=(TextGrid *this,TextGrid *param_1)

{
  TextGrid *pTVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x19850  146  ??4TextGrid@vgui@@QAEAAV01@ABV01@@Z */
  iVar2 = (int)param_1 - (int)this;
  iVar3 = 2;
  pTVar1 = this;
  do {
    pTVar1 = pTVar1 + 4;
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pTVar1 = this + 0xc;
  iVar3 = 2;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pTVar1 = this + 0x14;
  iVar3 = 2;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pTVar1 = this + 0x1c;
  iVar3 = 2;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pTVar1 = this + 0x24;
  iVar3 = 2;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  pTVar1 = this + 0x58;
  iVar3 = 4;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  pTVar1 = this + 0xa0;
  do {
    *pTVar1 = pTVar1[(int)(param_1 + (0x9c - (int)(this + 0x9c)))];
    pTVar1 = pTVar1 + 1;
  } while (pTVar1 + (-4 - (int)(this + 0x9c)) < (TextGrid *)0x4);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  pTVar1 = this + 0xac;
  do {
    *pTVar1 = pTVar1[(int)(param_1 + (0xa8 - (int)(this + 0xa8)))];
    pTVar1 = pTVar1 + 1;
  } while (pTVar1 + (-4 - (int)(this + 0xa8)) < (TextGrid *)0x4);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  pTVar1 = this + 0xbc;
  iVar3 = 2;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pTVar1 = this + 0xc4;
  iVar3 = 3;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pTVar1 = this + 0xd0;
  iVar3 = 3;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = 2;
  *(undefined4 *)(this + 0xdc) = *(undefined4 *)(param_1 + 0xdc);
  pTVar1 = this + 0xe0;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar2);
    pTVar1 = pTVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return this;
}


// vgui::TextImage::TextImage  @ 27019ab0
/* public: __thiscall vgui::TextImage::TextImage(class vgui::TextImage const &) */

void __thiscall vgui::TextImage::TextImage(TextImage *this,TextImage *param_1)

{
                    /* 0x19ab0  85  ??0TextImage@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined ***)(this + 0x18) = &Color::_vftable_;
  *(undefined ***)this = &Image::_vftable_;
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::TextImage::operator=  @ 27019b40
/* public: class vgui::TextImage & __thiscall vgui::TextImage::operator=(class vgui::TextImage const
   &) */

TextImage * __thiscall vgui::TextImage::operator=(TextImage *this,TextImage *param_1)

{
  TextImage *pTVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x19b40  147  ??4TextImage@vgui@@QAEAAV01@ABV01@@Z */
  iVar3 = (int)param_1 - (int)this;
  iVar2 = 2;
  pTVar1 = this;
  do {
    pTVar1 = pTVar1 + 4;
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar3);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  pTVar1 = this + 0xc;
  iVar2 = 2;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar3);
    pTVar1 = pTVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  pTVar1 = this + 0x1c;
  do {
    *pTVar1 = pTVar1[(int)(param_1 + (0x18 - (int)(this + 0x18)))];
    pTVar1 = pTVar1 + 1;
  } while (pTVar1 + (-4 - (int)(this + 0x18)) < (TextImage *)0x4);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  pTVar1 = this + 0x34;
  iVar2 = 4;
  do {
    *(undefined4 *)pTVar1 = *(undefined4 *)(pTVar1 + iVar3);
    pTVar1 = pTVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  return this;
}


// vgui::TextPanel::TextPanel  @ 2700ac10
/* public: __thiscall vgui::TextPanel::TextPanel(class vgui::TextPanel const &) */

void __thiscall vgui::TextPanel::TextPanel(TextPanel *this,TextPanel *param_1)

{
  undefined4 uVar1;
  
                    /* 0xac10  86  ??0TextPanel@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(this + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  this[0x70] = param_1[0x70];
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  this[0x78] = param_1[0x78];
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  this[0x8c] = param_1[0x8c];
  *(undefined4 *)(this + 0x90) = *(undefined4 *)(param_1 + 0x90);
  this[0x94] = param_1[0x94];
  this[0x95] = param_1[0x95];
  *(undefined4 *)(this + 0x98) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(this + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined ***)(this + 0x9c) = &Color::_vftable_;
  *(undefined4 *)(this + 0xac) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined ***)(this + 0xa8) = &Color::_vftable_;
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  this[0xb8] = param_1[0xb8];
  this[0xb9] = param_1[0xb9];
  this[0xba] = param_1[0xba];
  *(undefined ***)this = &Panel::_vftable_;
  uVar1 = *(undefined4 *)(param_1 + 0xbc);
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0xbc) = uVar1;
  return;
}


