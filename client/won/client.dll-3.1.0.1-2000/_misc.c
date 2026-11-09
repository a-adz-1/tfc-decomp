// CBaseMonster::CallMonsterThink  @ 27005e00
/* public: void __thiscall CBaseMonster::CallMonsterThink(void) */

void __thiscall CBaseMonster::CallMonsterThink(CBaseMonster *this)

{
                    /* 0x5e00  199  ?CallMonsterThink@CBaseMonster@@QAEXXZ */
                    /* WARNING: Could not recover jumptable at 0x27005e02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x10c))();
  return;
}


// CBaseMonster::MonsterUse  @ 27005cd0
/* public: void __thiscall CBaseMonster::MonsterUse(class CBaseEntity *,class CBaseEntity *,enum
   USE_TYPE,float) */

void __thiscall
CBaseMonster::MonsterUse
          (CBaseMonster *this,CBaseEntity *param_1,CBaseEntity *param_2,USE_TYPE param_3,
          float param_4)

{
                    /* 0x5cd0  208  ?MonsterUse@CBaseMonster@@QAEXPAVCBaseEntity@@0W4USE_TYPE@@M@Z
                        */
  return;
}


// CBasePlayerAmmo::DefaultTouch  @ 27005c90
/* public: void __thiscall CBasePlayerAmmo::DefaultTouch(class CBaseEntity *) */

void __thiscall CBasePlayerAmmo::DefaultTouch(CBasePlayerAmmo *this,CBaseEntity *param_1)

{
                    /* 0x5c90  201  ?DefaultTouch@CBasePlayerAmmo@@QAEXPAVCBaseEntity@@@Z
                       0x5c90  202  ?DefaultTouch@CBasePlayerItem@@QAEXPAVCBaseEntity@@@Z
                       0x5c90  210  ?PlayerTouch@CBasePlayer@@QAEXPAVCBaseEntity@@@Z
                       0x5c90  212  ?RocketTouch@CTFRpgRocket@@QAEXPAVCBaseEntity@@@Z */
  return;
}


// CBasePlayerItem::AttemptToMaterialize  @ 2700ae00
/* public: void __thiscall CBasePlayerItem::AttemptToMaterialize(void) */

void __thiscall CBasePlayerItem::AttemptToMaterialize(CBasePlayerItem *this)

{
                    /* 0xae00  198  ?AttemptToMaterialize@CBasePlayerItem@@QAEXXZ
                       0xae00  200  ?CorpseFallThink@CBaseMonster@@QAEXXZ
                       0xae00  203  ?DestroyItem@CBasePlayerItem@@QAEXXZ
                       0xae00  204  ?FallThink@CBasePlayerItem@@QAEXXZ
                       0xae00  205  ?Materialize@CBasePlayerAmmo@@QAEXXZ
                       0xae00  206  ?Materialize@CBasePlayerItem@@QAEXXZ
                       0xae00  207  ?MonsterInitThink@CBaseMonster@@QAEXXZ
                       0xae00  209  ?PlayerDeathThink@CBasePlayer@@QAEXXZ
                       0xae00  211  ?Revive@CLaserSpot@@QAEXXZ
                       0xae00  214  ?SUB_Remove@CBaseEntity@@QAEXXZ
                       0xae00  215  ?Smack@CCrowbar@@QAEXXZ
                       0xae00  217  ?SwingAgain@CCrowbar@@QAEXXZ
                       0xae00  218  ?Timer_Tranquilisation@CBaseEntity@@QAEXXZ
                       0xae00  426  HUD_DrawNormalTriangles
                       0xae00  427  HUD_DrawTransparentTriangles */
  return;
}


// CTFAxe::Smack  @ 27009320
/* public: void __thiscall CTFAxe::Smack(void) */

void __thiscall CTFAxe::Smack(CTFAxe *this)

{
                    /* 0x9320  216  ?Smack@CTFAxe@@QAEXXZ */
                    /* WARNING: Could not recover jumptable at 0x27009322. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x184))();
  return;
}


// CTFNailgunNail::TranqTouch  @ 2700e9c0
/* public: void __thiscall CTFNailgunNail::TranqTouch(class CBaseEntity *) */

void __thiscall CTFNailgunNail::TranqTouch(CTFNailgunNail *this,CBaseEntity *param_1)

{
  int iVar1;
  int iVar2;
  CBasePlayerItem *extraout_ECX;
  CBasePlayerItem *extraout_ECX_00;
  CBasePlayerItem *this_00;
  ulonglong uVar3;
  
                    /* 0xe9c0  219  ?TranqTouch@CTFNailgunNail@@QAEXPAVCBaseEntity@@@Z */
  if (*(float *)(*(int *)(param_1 + 4) + 0x16c) == 0.0) goto LAB_2700eadc;
  iVar1 = *(int *)(*(int *)(this + 4) + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_27063ebc)(0);
    if (iVar1 != 0) goto LAB_2700e9fe;
    iVar1 = 0;
  }
  else {
LAB_2700e9fe:
    iVar1 = *(int *)(iVar1 + 0x7c);
  }
  iVar2 = (**(code **)(*(int *)param_1 + 0x20))();
  if (iVar2 == 2) {
    iVar2 = FUN_27005e10();
    this_00 = extraout_ECX;
    if (iVar2 != 0) {
      uVar3 = __ftol();
      this_00 = extraout_ECX_00;
      if ((uVar3 & 0x1e) != 0) goto LAB_2700eac2;
    }
    if ((*(uint *)(param_1 + 0x78) & 0x8000) == 0) {
      CBasePlayerItem::AttemptToMaterialize(this_00);
      *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) | 0x8000;
      iVar2 = FUN_27005ca0();
      *(float *)(*(int *)(iVar2 + 4) + 0x104) = *DAT_27063fe4 + 15.0;
      *(code **)(iVar2 + 0x10) = CBasePlayerItem::AttemptToMaterialize;
      *(undefined4 *)(iVar2 + 0x114) = *(undefined4 *)(iVar1 + 0x114);
      FUN_270070e0((float)param_1);
    }
    else {
      iVar2 = FUN_27005ca0();
      if (iVar2 != 0) {
        *(float *)(*(int *)(iVar2 + 4) + 0x104) = *DAT_27063fe4 + 15.0;
      }
    }
  }
LAB_2700eac2:
  (**(code **)(*(int *)param_1 + 0x2c))
            (*(undefined4 *)(this + 4),*(undefined4 *)(iVar1 + 4),0x41a00000,0x800004);
LAB_2700eadc:
  CBasePlayerItem::AttemptToMaterialize((CBasePlayerItem *)this);
  return;
}


// Catch@2702f027  @ 2702f027
undefined4 Catch_2702f027(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(*(int *)(unaff_EBP + -0x1c) + 0xc4) = 0;
  return 0x2702e830;
}


// Initialize  @ 270150a0
undefined4 __cdecl Initialize(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = param_1;
  puVar3 = &DAT_27073aa0;
                    /* 0x150a0  452  Initialize */
  for (iVar1 = 0x57; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  if (param_2 != 7) {
    return 0;
  }
  puVar2 = &DAT_27073aa0;
  for (iVar1 = 0x57; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  thunk_FUN_27005e30();
  return 1;
}


// Unwind@270425f0  @ 270425f0
void Unwind_270425f0(void)

{
  int unaff_EBP;
  
  FUN_2700a360(*(undefined4 *)(unaff_EBP + -0x10),*(int *)(unaff_EBP + 4));
  return;
}


// Unwind@27042610  @ 27042610
void Unwind_27042610(void)

{
  int unaff_EBP;
  
  FUN_2700a360(*(undefined4 *)(unaff_EBP + -0x10),*(int *)(unaff_EBP + 4));
  return;
}


// Unwind@27042630  @ 27042630
void Unwind_27042630(void)

{
  int unaff_EBP;
  
  FUN_2700a360(*(undefined4 *)(unaff_EBP + -0x10),*(int *)(unaff_EBP + 4));
  return;
}


// Unwind@27042650  @ 27042650
void Unwind_27042650(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x140));
  return;
}


// Unwind@2704265e  @ 2704265e
void Unwind_2704265e(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x140));
  return;
}


// Unwind@2704266c  @ 2704266c
void Unwind_2704266c(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x140));
  return;
}


// Unwind@2704267a  @ 2704267a
void Unwind_2704267a(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x144));
  return;
}


// Unwind@27042688  @ 27042688
void Unwind_27042688(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x144));
  return;
}


// Unwind@27042696  @ 27042696
void Unwind_27042696(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x144));
  return;
}


// Unwind@270426a4  @ 270426a4
void Unwind_270426a4(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x144));
  return;
}


// Unwind@270426b2  @ 270426b2
void Unwind_270426b2(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x144));
  return;
}


// Unwind@270426c0  @ 270426c0
void Unwind_270426c0(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x158));
  return;
}


// Unwind@270426ce  @ 270426ce
void Unwind_270426ce(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x144));
  return;
}


// Unwind@270426f0  @ 270426f0
void Unwind_270426f0(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x110));
  return;
}


// Unwind@270426fe  @ 270426fe
void Unwind_270426fe(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x110));
  return;
}


// Unwind@27042720  @ 27042720
void Unwind_27042720(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 0xc));
  return;
}


// Unwind@2704272b  @ 2704272b
void Unwind_2704272b(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 0xc));
  return;
}


// Unwind@27042736  @ 27042736
void Unwind_27042736(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 0xc));
  return;
}


// Unwind@27042741  @ 27042741
void Unwind_27042741(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 0xc));
  return;
}


// Unwind@2704274c  @ 2704274c
void Unwind_2704274c(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 0xc));
  return;
}


// Unwind@27042757  @ 27042757
void Unwind_27042757(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 0xc));
  return;
}


// Unwind@27042770  @ 27042770
void Unwind_27042770(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}


// Unwind@27042790  @ 27042790
void Unwind_27042790(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x1c));
  return;
}


// Unwind@2704279b  @ 2704279b
void Unwind_2704279b(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 0x20));
  return;
}


// Unwind@270427a6  @ 270427a6
void Unwind_270427a6(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 0x20));
  return;
}


// Unwind@270427b1  @ 270427b1
void Unwind_270427b1(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}


// Unwind@270427bc  @ 270427bc
void Unwind_270427bc(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 0x20));
  return;
}


// Unwind@270427c7  @ 270427c7
void Unwind_270427c7(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}


// Unwind@270427e0  @ 270427e0
void Unwind_270427e0(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x694));
  return;
}


// Unwind@270427ee  @ 270427ee
void Unwind_270427ee(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x694));
  return;
}


// Unwind@27042810  @ 27042810
void Unwind_27042810(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 8));
  return;
}


// Unwind@2704281b  @ 2704281b
void Unwind_2704281b(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 8));
  return;
}


// Unwind@27042826  @ 27042826
void Unwind_27042826(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 4));
  return;
}


// Unwind@27042831  @ 27042831
void Unwind_27042831(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 8));
  return;
}


// Unwind@2704283c  @ 2704283c
void Unwind_2704283c(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 8));
  return;
}


// Unwind@27042847  @ 27042847
void Unwind_27042847(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 8));
  return;
}


// Unwind@27042852  @ 27042852
void Unwind_27042852(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 8));
  return;
}


// Unwind@2704285d  @ 2704285d
void Unwind_2704285d(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 8));
  return;
}


// Unwind@27042868  @ 27042868
void Unwind_27042868(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 8));
  return;
}


// Unwind@27042873  @ 27042873
void Unwind_27042873(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 8));
  return;
}


// Unwind@2704287e  @ 2704287e
void Unwind_2704287e(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 4));
  return;
}


// Unwind@27042889  @ 27042889
void Unwind_27042889(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 0xc));
  return;
}


// Unwind@270428a0  @ 270428a0
void Unwind_270428a0(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 8));
  return;
}


// Unwind@270428ab  @ 270428ab
void Unwind_270428ab(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 8));
  return;
}


// Unwind@270428b6  @ 270428b6
void Unwind_270428b6(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 8));
  return;
}


// Unwind@270428c1  @ 270428c1
void Unwind_270428c1(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 8));
  return;
}


// Unwind@270428cc  @ 270428cc
void Unwind_270428cc(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 8));
  return;
}


// Unwind@270428d7  @ 270428d7
void Unwind_270428d7(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 8));
  return;
}


// Unwind@270428e2  @ 270428e2
void Unwind_270428e2(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 8));
  return;
}


// Unwind@270428ed  @ 270428ed
void Unwind_270428ed(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 0xc));
  return;
}


// Unwind@270428f8  @ 270428f8
void Unwind_270428f8(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}


// Unwind@27042903  @ 27042903
void Unwind_27042903(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}


// Unwind@2704290e  @ 2704290e
void Unwind_2704290e(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}


// Unwind@27042919  @ 27042919
void Unwind_27042919(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 0x10));
  return;
}


// Unwind@27042930  @ 27042930
void Unwind_27042930(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 8));
  return;
}


// Unwind@2704293b  @ 2704293b
void Unwind_2704293b(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + 8));
  return;
}


// Unwind@27042950  @ 27042950
void Unwind_27042950(void)

{
  int unaff_EBP;
  
  FUN_2702af90((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x188));
  return;
}


// Unwind@27042970  @ 27042970
void Unwind_27042970(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x28));
  return;
}


// Unwind@2704297b  @ 2704297b
void Unwind_2704297b(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x24));
  return;
}


// Unwind@27042986  @ 27042986
void Unwind_27042986(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x2c));
  return;
}


// Unwind@27042991  @ 27042991
void Unwind_27042991(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x2c));
  return;
}


// Unwind@270429b0  @ 270429b0
void Unwind_270429b0(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x110));
  return;
}


// Unwind@270429d0  @ 270429d0
void Unwind_270429d0(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x210));
  return;
}


// Unwind@270429de  @ 270429de
void Unwind_270429de(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@270429ec  @ 270429ec
void Unwind_270429ec(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@270429fa  @ 270429fa
void Unwind_270429fa(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042a08  @ 27042a08
void Unwind_27042a08(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042a16  @ 27042a16
void Unwind_27042a16(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042a24  @ 27042a24
void Unwind_27042a24(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042a32  @ 27042a32
void Unwind_27042a32(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042a40  @ 27042a40
void Unwind_27042a40(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042a4e  @ 27042a4e
void Unwind_27042a4e(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042a5c  @ 27042a5c
void Unwind_27042a5c(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042a6a  @ 27042a6a
void Unwind_27042a6a(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042a78  @ 27042a78
void Unwind_27042a78(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042a86  @ 27042a86
void Unwind_27042a86(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042a94  @ 27042a94
void Unwind_27042a94(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042aa2  @ 27042aa2
void Unwind_27042aa2(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042ab0  @ 27042ab0
void Unwind_27042ab0(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042abe  @ 27042abe
void Unwind_27042abe(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042acc  @ 27042acc
void Unwind_27042acc(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042ada  @ 27042ada
void Unwind_27042ada(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042ae8  @ 27042ae8
void Unwind_27042ae8(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042af6  @ 27042af6
void Unwind_27042af6(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042b04  @ 27042b04
void Unwind_27042b04(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042b12  @ 27042b12
void Unwind_27042b12(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042b20  @ 27042b20
void Unwind_27042b20(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042b2e  @ 27042b2e
void Unwind_27042b2e(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042b3c  @ 27042b3c
void Unwind_27042b3c(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042b4a  @ 27042b4a
void Unwind_27042b4a(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042b58  @ 27042b58
void Unwind_27042b58(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042b66  @ 27042b66
void Unwind_27042b66(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042b74  @ 27042b74
void Unwind_27042b74(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042b82  @ 27042b82
void Unwind_27042b82(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27042ba0  @ 27042ba0
void Unwind_27042ba0(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}


// Unwind@27042bc0  @ 27042bc0
void Unwind_27042bc0(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}


// Unwind@27042be0  @ 27042be0
void Unwind_27042be0(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}


// Unwind@27042c00  @ 27042c00
void Unwind_27042c00(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}


// Unwind@27042c20  @ 27042c20
void Unwind_27042c20(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x14));
  return;
}


// Unwind@27042c2b  @ 27042c2b
void Unwind_27042c2b(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}


// Unwind@27042c36  @ 27042c36
void Unwind_27042c36(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}


// Unwind@27042c41  @ 27042c41
void Unwind_27042c41(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x10));
  return;
}


// Unwind@27042c60  @ 27042c60
void Unwind_27042c60(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x128));
  return;
}


// Unwind@27042c6e  @ 27042c6e
void Unwind_27042c6e(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x134));
  return;
}


// Unwind@27042c7c  @ 27042c7c
void Unwind_27042c7c(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x134));
  return;
}


// Unwind@27042c8a  @ 27042c8a
void Unwind_27042c8a(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x134));
  return;
}


// Unwind@27042c98  @ 27042c98
void Unwind_27042c98(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x134));
  return;
}


// Unwind@27042ca6  @ 27042ca6
void Unwind_27042ca6(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x134));
  return;
}


// Unwind@27042cb4  @ 27042cb4
void Unwind_27042cb4(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x134));
  return;
}


// Unwind@27042cc2  @ 27042cc2
void Unwind_27042cc2(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x134));
  return;
}


// Unwind@27042cd0  @ 27042cd0
void Unwind_27042cd0(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x134));
  return;
}


// Unwind@27042cde  @ 27042cde
void Unwind_27042cde(void)

{
  int unaff_EBP;
  
  FUN_270374c2(*(LPVOID *)(unaff_EBP + -0x134));
  return;
}


// entry  @ 27038875
int entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2;
  iVar2 = DAT_27084d58;
  if (param_2 != 0) {
    if ((param_2 != 1) && (param_2 != 2)) goto LAB_270388bd;
    if ((DAT_27086428 != (code *)0x0) &&
       (iVar2 = (*DAT_27086428)(param_1,param_2,param_3), iVar2 == 0)) {
      return 0;
    }
    iVar2 = FUN_2703879c(param_1,param_2);
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_270388bd:
  iVar2 = FUN_2703d318();
  if (param_2 == 1) {
    if (iVar2 != 0) {
      return iVar2;
    }
    FUN_2703879c(param_1,0);
  }
  if ((param_2 != 0) && (param_2 != 3)) {
    return iVar2;
  }
  iVar3 = FUN_2703879c(param_1,param_2);
  param_2 = iVar2;
  if (iVar3 == 0) {
    param_2 = 0;
  }
  if (param_2 != 0) {
    if (DAT_27086428 != (code *)0x0) {
      iVar2 = (*DAT_27086428)(param_1,iVar1,param_3);
      return iVar2;
    }
    return param_2;
  }
  return 0;
}


// vgui::ActionSignal::ActionSignal  @ 27011fd0
/* public: __thiscall vgui::ActionSignal::ActionSignal(void) */

void __thiscall vgui::ActionSignal::ActionSignal(ActionSignal *this)

{
                    /* 0x11fd0  38  ??0ActionSignal@vgui@@QAE@XZ */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::ActionSignal::ActionSignal  @ 27011fe0
/* public: __thiscall vgui::ActionSignal::ActionSignal(class vgui::ActionSignal const &) */

void __thiscall vgui::ActionSignal::ActionSignal(ActionSignal *this,ActionSignal *param_1)

{
                    /* 0x11fe0  37  ??0ActionSignal@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::ActionSignal::operator=  @ 27029d50
/* public: class vgui::ActionSignal & __thiscall vgui::ActionSignal::operator=(class
   vgui::ActionSignal const &) */

ActionSignal * __thiscall vgui::ActionSignal::operator=(ActionSignal *this,ActionSignal *param_1)

{
                    /* 0x29d50  98  ??4ActionSignal@vgui@@QAEAAV01@ABV01@@Z
                       0x29d50  116  ??4InputSignal@vgui@@QAEAAV01@ABV01@@Z
                       0x29d50  117  ??4InputStream@vgui@@QAEAAV01@ABV01@@Z
                       0x29d50  119  ??4Layout@vgui@@QAEAAV01@ABV01@@Z */
  return this;
}


// vgui::App::App  @ 27012a30
/* public: __thiscall vgui::App::App(class vgui::App const &) */

void __thiscall vgui::App::App(App *this,App *param_1)

{
  int iVar1;
  App *pAVar2;
  App *pAVar3;
  
                    /* 0x12a30  39  ??0App@vgui@@QAE@ABV01@@Z */
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


// vgui::App::operator=  @ 27012bd0
/* public: class vgui::App & __thiscall vgui::App::operator=(class vgui::App const &) */

App * __thiscall vgui::App::operator=(App *this,App *param_1)

{
  int iVar1;
  App *pAVar2;
  int iVar3;
  
                    /* 0x12bd0  99  ??4App@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::Bitmap::Bitmap  @ 27012470
/* public: __thiscall vgui::Bitmap::Bitmap(class vgui::Bitmap const &) */

void __thiscall vgui::Bitmap::Bitmap(Bitmap *this,Bitmap *param_1)

{
                    /* 0x12470  40  ??0Bitmap@vgui@@QAE@ABV01@@Z */
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


// vgui::Bitmap::operator=  @ 270124d0
/* public: class vgui::Bitmap & __thiscall vgui::Bitmap::operator=(class vgui::Bitmap const &) */

Bitmap * __thiscall vgui::Bitmap::operator=(Bitmap *this,Bitmap *param_1)

{
  Bitmap *pBVar1;
  int iVar2;
  
                    /* 0x124d0  100  ??4Bitmap@vgui@@QAEAAV01@ABV01@@Z
                       0x124d0  101  ??4BitmapTGA@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::BitmapTGA::BitmapTGA  @ 27012570
/* public: __thiscall vgui::BitmapTGA::BitmapTGA(class vgui::BitmapTGA const &) */

void __thiscall vgui::BitmapTGA::BitmapTGA(BitmapTGA *this,BitmapTGA *param_1)

{
                    /* 0x12570  41  ??0BitmapTGA@vgui@@QAE@ABV01@@Z */
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


// vgui::Border::Border  @ 27012e70
/* public: __thiscall vgui::Border::Border(class vgui::Border const &) */

void __thiscall vgui::Border::Border(Border *this,Border *param_1)

{
                    /* 0x12e70  42  ??0Border@vgui@@QAE@ABV01@@Z */
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


// vgui::Border::operator=  @ 27012ee0
/* public: class vgui::Border & __thiscall vgui::Border::operator=(class vgui::Border const &) */

Border * __thiscall vgui::Border::operator=(Border *this,Border *param_1)

{
  int iVar1;
  Border *pBVar2;
  int iVar3;
  
                    /* 0x12ee0  102  ??4Border@vgui@@QAEAAV01@ABV01@@Z
                       0x12ee0  121  ??4LoweredBorder@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::BorderLayout::BorderLayout  @ 27029d60
/* public: __thiscall vgui::BorderLayout::BorderLayout(class vgui::BorderLayout const &) */

void __thiscall vgui::BorderLayout::BorderLayout(BorderLayout *this,BorderLayout *param_1)

{
  undefined4 uVar1;
  
                    /* 0x29d60  43  ??0BorderLayout@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &Layout::_vftable_;
  uVar1 = *(undefined4 *)(param_1 + 4);
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 4) = uVar1;
  return;
}


// vgui::BorderLayout::operator=  @ 27012e60
/* public: class vgui::BorderLayout & __thiscall vgui::BorderLayout::operator=(class
   vgui::BorderLayout const &) */

BorderLayout * __thiscall vgui::BorderLayout::operator=(BorderLayout *this,BorderLayout *param_1)

{
                    /* 0x12e60  103  ??4BorderLayout@vgui@@QAEAAV01@ABV01@@Z
                       0x12e60  110  ??4FileInputStream@vgui@@QAEAAV01@ABV01@@Z
                       0x12e60  123  ??4MiniApp@vgui@@QAEAAV01@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  return this;
}


// vgui::BuildGroup::BuildGroup  @ 270319b0
/* public: __thiscall vgui::BuildGroup::BuildGroup(class vgui::BuildGroup const &) */

void __thiscall vgui::BuildGroup::BuildGroup(BuildGroup *this,BuildGroup *param_1)

{
  undefined4 uVar1;
  
                    /* 0x319b0  44  ??0BuildGroup@vgui@@QAE@ABV01@@Z */
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


// vgui::BuildGroup::operator=  @ 27031a70
/* public: class vgui::BuildGroup & __thiscall vgui::BuildGroup::operator=(class vgui::BuildGroup
   const &) */

BuildGroup * __thiscall vgui::BuildGroup::operator=(BuildGroup *this,BuildGroup *param_1)

{
  BuildGroup *pBVar1;
  int iVar2;
  
                    /* 0x31a70  104  ??4BuildGroup@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::Button::Button  @ 27011970
/* public: __thiscall vgui::Button::Button(class vgui::Button const &) */

void __thiscall vgui::Button::Button(Button *this,Button *param_1)

{
                    /* 0x11970  45  ??0Button@vgui@@QAE@ABV01@@Z */
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


// vgui::Button::operator=  @ 27011d00
/* public: class vgui::Button & __thiscall vgui::Button::operator=(class vgui::Button const &) */

Button * __thiscall vgui::Button::operator=(Button *this,Button *param_1)

{
  int iVar1;
  Button *pBVar2;
  int iVar3;
  
                    /* 0x11d00  105  ??4Button@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::Color::Color  @ 27010590
/* public: __thiscall vgui::Color::Color(class vgui::Color const &) */

void __thiscall vgui::Color::Color(Color *this,Color *param_1)

{
                    /* 0x10590  46  ??0Color@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Color::operator=  @ 270105b0
/* public: class vgui::Color & __thiscall vgui::Color::operator=(class vgui::Color const &) */

Color * __thiscall vgui::Color::operator=(Color *this,Color *param_1)

{
  Color *pCVar1;
  
                    /* 0x105b0  106  ??4Color@vgui@@QAEAAV01@ABV01@@Z */
  pCVar1 = this + 4;
  do {
    *pCVar1 = pCVar1[(int)param_1 - (int)this];
    pCVar1 = pCVar1 + 1;
  } while (pCVar1 + (-4 - (int)this) < (Color *)0x4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  return this;
}


// vgui::Cursor::Cursor  @ 270129c0
/* public: __thiscall vgui::Cursor::Cursor(class vgui::Cursor const &) */

void __thiscall vgui::Cursor::Cursor(Cursor *this,Cursor *param_1)

{
                    /* 0x129c0  47  ??0Cursor@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Cursor::operator=  @ 270129f0
/* public: class vgui::Cursor & __thiscall vgui::Cursor::operator=(class vgui::Cursor const &) */

Cursor * __thiscall vgui::Cursor::operator=(Cursor *this,Cursor *param_1)

{
  int iVar1;
  Cursor *pCVar2;
  
                    /* 0x129f0  107  ??4Cursor@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::Dar<char>::Dar<char>  @ 270118f0
/* public: __thiscall vgui::Dar<char>::Dar<char>(void) */

Dar<char> * __thiscall vgui::Dar<char>::Dar<char>(Dar<char> *this)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
                    /* 0x118f0  2  ??0?$Dar@D@vgui@@QAE@XZ */
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
    FUN_270374fa(0);
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
      *(undefined1 *)(iVar3 + (int)puVar2) = *(undefined1 *)(*(int *)(this + 8) + -1 + iVar4);
      iVar3 = iVar4;
    } while (iVar4 < *(int *)this);
  }
  FUN_270374c2(*(LPVOID *)(this + 8));
  *(undefined4 **)(this + 8) = puVar2;
  return this;
}


// vgui::Dar<char>::Dar<char>  @ 27011bf0
/* public: __thiscall vgui::Dar<char>::Dar<char>(int) */

Dar<char> * __thiscall vgui::Dar<char>::Dar<char>(Dar<char> *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  
                    /* 0x11bf0  1  ??0?$Dar@D@vgui@@QAE@H@Z */
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
      FUN_270374fa(0);
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
        *(undefined1 *)(iVar2 + (int)puVar1) = *(undefined1 *)(*(int *)(this + 8) + -1 + iVar3);
        iVar2 = iVar3;
      } while (iVar3 < *(int *)this);
    }
    FUN_270374c2(*(LPVOID *)(this + 8));
    *(undefined4 **)(this + 8) = puVar1;
  }
  return this;
}


// vgui::Dar<char>::addElement  @ 27011ff0
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
  
                    /* 0x11ff0  220  ?addElement@?$Dar@D@vgui@@QAEXD@Z */
  uVar5 = *(uint *)(this + 4);
  if ((int)uVar5 < *(int *)this + 1) {
    if (uVar5 == 0) {
      uVar5 = 1;
    }
    for (; (int)uVar5 < *(int *)this + 1; uVar5 = uVar5 * 2) {
    }
    puVar1 = operator_new(uVar5);
    if (puVar1 == (undefined4 *)0x0) {
      FUN_270374fa(0);
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
        *(undefined1 *)(iVar2 + (int)puVar1) = *(undefined1 *)(*(int *)(this + 8) + -1 + iVar3);
        iVar2 = iVar3;
      } while (iVar3 < *(int *)this);
    }
    FUN_270374c2(*(LPVOID *)(this + 8));
    *(undefined4 **)(this + 8) = puVar1;
  }
  *(undefined1 *)(*(int *)(this + 8) + *(int *)this) = unaff_retaddr;
  *(int *)this = *(int *)this + 1;
  return;
}


// vgui::Dar<char>::ensureCapacity  @ 27011c80
/* public: void __thiscall vgui::Dar<char>::ensureCapacity(int) */

void __thiscall vgui::Dar<char>::ensureCapacity(Dar<char> *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  
                    /* 0x11c80  238  ?ensureCapacity@?$Dar@D@vgui@@QAEXH@Z */
  uVar5 = *(uint *)(this + 4);
  if ((int)uVar5 < param_1) {
    if (uVar5 == 0) {
      uVar5 = 1;
    }
    for (; (int)uVar5 < param_1; uVar5 = uVar5 * 2) {
    }
    puVar1 = operator_new(uVar5);
    if (puVar1 == (undefined4 *)0x0) {
      FUN_270374fa(0);
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
    FUN_270374c2(*(LPVOID *)(this + 8));
    *(undefined4 **)(this + 8) = puVar1;
  }
  return;
}


// vgui::Dar<char>::getCount  @ 27012f70
/* public: int __thiscall vgui::Dar<char>::getCount(void) */

int __thiscall vgui::Dar<char>::getCount(Dar<char> *this)

{
                    /* 0x12f70  256  ?getCount@?$Dar@D@vgui@@QAEHXZ
                       0x12f70  257  ?getCount@?$Dar@H@vgui@@QAEHXZ
                       0x12f70  258  ?getCount@?$Dar@PAD@vgui@@QAEHXZ
                       0x12f70  259  ?getCount@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEHXZ
                       0x12f70  260  ?getCount@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEHXZ
                       0x12f70  261  ?getCount@?$Dar@PAVButton@vgui@@@vgui@@QAEHXZ
                       0x12f70  262  ?getCount@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEHXZ
                       0x12f70  263  ?getCount@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEHXZ
                       0x12f70  264  ?getCount@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEHXZ
                       0x12f70  265  ?getCount@?$Dar@PAVFrame@vgui@@@vgui@@QAEHXZ
                       0x12f70  266  ?getCount@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEHXZ
                       0x12f70  267  ?getCount@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEHXZ
                       0x12f70  268  ?getCount@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEHXZ
                       0x12f70  269  ?getCount@?$Dar@PAVLabel@vgui@@@vgui@@QAEHXZ
                       0x12f70  270  ?getCount@?$Dar@PAVPanel@vgui@@@vgui@@QAEHXZ
                       0x12f70  271  ?getCount@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEHXZ
                       0x12f70  272  ?getCount@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEHXZ
                       0x12f70  273  ?getCount@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEHXZ */
  return *(int *)this;
}


// vgui::Dar<char>::hasElement  @ 27012090
/* public: bool __thiscall vgui::Dar<char>::hasElement(char) */

bool __thiscall vgui::Dar<char>::hasElement(Dar<char> *this,char param_1)

{
  int iVar1;
  
                    /* 0x12090  274  ?hasElement@?$Dar@D@vgui@@QAE_ND@Z */
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


// vgui::Dar<char>::insertElementAt  @ 270121c0
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
  
                    /* 0x121c0  292  ?insertElementAt@?$Dar@D@vgui@@QAEXDH@Z */
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
            FUN_270374fa(0);
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
              *(undefined1 *)(iVar3 + (int)puVar1) =
                   *(undefined1 *)(*(int *)(this + 8) + -1 + iVar2);
              iVar3 = iVar2;
            } while (iVar2 < *(int *)this);
          }
          FUN_270374c2(*(LPVOID *)(this + 8));
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
        *(undefined1 *)(*(int *)(this + 8) + param_2) = unaff_retaddr;
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
          FUN_270374fa(0);
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
            *(undefined1 *)(iVar3 + (int)puVar1) = *(undefined1 *)(*(int *)(this + 8) + -1 + iVar2);
            iVar3 = iVar2;
          } while (iVar2 < *(int *)this);
        }
        FUN_270374c2(*(LPVOID *)(this + 8));
        *(undefined4 **)(this + 8) = puVar1;
      }
      *(undefined1 *)(*(int *)(this + 8) + *(int *)this) = unaff_retaddr;
      *(int *)this = *(int *)this + 1;
    }
  }
  return;
}


// vgui::Dar<char>::operator=  @ 270100d0
/* public: class vgui::Dar<char> & __thiscall vgui::Dar<char>::operator=(class vgui::Dar<char> const
   &) */

Dar<char> * __thiscall vgui::Dar<char>::operator=(Dar<char> *this,Dar<char> *param_1)

{
                    /* 0x100d0  80  ??4?$Dar@D@vgui@@QAEAAV01@ABV01@@Z
                       0x100d0  81  ??4?$Dar@H@vgui@@QAEAAV01@ABV01@@Z
                       0x100d0  82  ??4?$Dar@PAD@vgui@@QAEAAV01@ABV01@@Z
                       0x100d0  83  ??4?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x100d0  84  ??4?$Dar@PAVActionSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x100d0  85  ??4?$Dar@PAVButton@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x100d0  86  ??4?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x100d0  87  ??4?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x100d0  88  ??4?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x100d0  89  ??4?$Dar@PAVFrame@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x100d0  90  ??4?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x100d0  91  ??4?$Dar@PAVInputSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x100d0  92  ??4?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x100d0  93  ??4?$Dar@PAVLabel@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x100d0  94  ??4?$Dar@PAVPanel@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x100d0  95  ??4?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x100d0  96  ??4?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0x100d0  97  ??4?$Dar@PAVTickSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z */
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  return this;
}


// vgui::Dar<char>::operator[]  @ 27012550
/* public: char __thiscall vgui::Dar<char>::operator[](int) */

char __thiscall vgui::Dar<char>::operator[](Dar<char> *this,int param_1)

{
                    /* 0x12550  138  ??A?$Dar@D@vgui@@QAEDH@Z */
  if ((-1 < param_1) && (param_1 < *(int *)this)) {
    return *(char *)(*(int *)(this + 8) + param_1);
  }
  return '\0';
}


// vgui::Dar<char>::putElement  @ 270120d0
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
  
                    /* 0x120d0  310  ?putElement@?$Dar@D@vgui@@QAEXD@Z */
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
      FUN_270374fa(0);
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
        *(undefined1 *)(iVar3 + (int)puVar2) = *(undefined1 *)(*(int *)(this + 8) + -1 + iVar1);
        iVar3 = iVar1;
      } while (iVar1 < *(int *)this);
    }
    FUN_270374c2(*(LPVOID *)(this + 8));
    *(undefined4 **)(this + 8) = puVar2;
  }
  *(undefined1 *)(*(int *)(this + 8) + *(int *)this) = unaff_retaddr;
  *(int *)this = *(int *)this + 1;
  return;
}


// vgui::Dar<char>::removeAll  @ 27012d80
/* public: void __thiscall vgui::Dar<char>::removeAll(void) */

void __thiscall vgui::Dar<char>::removeAll(Dar<char> *this)

{
                    /* 0x12d80  328  ?removeAll@?$Dar@D@vgui@@QAEXXZ
                       0x12d80  329  ?removeAll@?$Dar@H@vgui@@QAEXXZ
                       0x12d80  330  ?removeAll@?$Dar@PAD@vgui@@QAEXXZ
                       0x12d80  331  ?removeAll@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXXZ
                       0x12d80  332  ?removeAll@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXXZ
                       0x12d80  333  ?removeAll@?$Dar@PAVButton@vgui@@@vgui@@QAEXXZ
                       0x12d80  334  ?removeAll@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXXZ
                       0x12d80  335  ?removeAll@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXXZ
                       0x12d80  336  ?removeAll@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXXZ
                       0x12d80  337  ?removeAll@?$Dar@PAVFrame@vgui@@@vgui@@QAEXXZ
                       0x12d80  338  ?removeAll@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXXZ
                       0x12d80  339  ?removeAll@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXXZ
                       0x12d80  340  ?removeAll@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXXZ
                       0x12d80  341  ?removeAll@?$Dar@PAVLabel@vgui@@@vgui@@QAEXXZ
                       0x12d80  342  ?removeAll@?$Dar@PAVPanel@vgui@@@vgui@@QAEXXZ
                       0x12d80  343  ?removeAll@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXXZ
                       0x12d80  344  ?removeAll@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXXZ
                       0x12d80  345  ?removeAll@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEXXZ */
  *(undefined4 *)this = 0;
  return;
}


// vgui::Dar<char>::removeElement  @ 27012420
/* public: void __thiscall vgui::Dar<char>::removeElement(char) */

void __thiscall vgui::Dar<char>::removeElement(Dar<char> *this,char param_1)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x12420  346  ?removeElement@?$Dar@D@vgui@@QAEXD@Z */
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


// vgui::Dar<char>::removeElementAt  @ 270123d0
/* public: void __thiscall vgui::Dar<char>::removeElementAt(int) */

void __thiscall vgui::Dar<char>::removeElementAt(Dar<char> *this,int param_1)

{
  undefined1 *puVar1;
  
                    /* 0x123d0  364  ?removeElementAt@?$Dar@D@vgui@@QAEXH@Z */
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


// vgui::Dar<char>::setCount  @ 27011fb0
/* public: void __thiscall vgui::Dar<char>::setCount(int) */

void __thiscall vgui::Dar<char>::setCount(Dar<char> *this,int param_1)

{
                    /* 0x11fb0  382  ?setCount@?$Dar@D@vgui@@QAEXH@Z
                       0x11fb0  383  ?setCount@?$Dar@H@vgui@@QAEXH@Z
                       0x11fb0  384  ?setCount@?$Dar@PAD@vgui@@QAEXH@Z
                       0x11fb0  385  ?setCount@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXH@Z
                       0x11fb0  386  ?setCount@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXH@Z
                       0x11fb0  387  ?setCount@?$Dar@PAVButton@vgui@@@vgui@@QAEXH@Z
                       0x11fb0  388  ?setCount@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x11fb0  389  ?setCount@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXH@Z
                       0x11fb0  390  ?setCount@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x11fb0  391  ?setCount@?$Dar@PAVFrame@vgui@@@vgui@@QAEXH@Z
                       0x11fb0  392  ?setCount@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXH@Z
                       0x11fb0  393  ?setCount@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXH@Z
                       0x11fb0  394  ?setCount@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x11fb0  395  ?setCount@?$Dar@PAVLabel@vgui@@@vgui@@QAEXH@Z
                       0x11fb0  396  ?setCount@?$Dar@PAVPanel@vgui@@@vgui@@QAEXH@Z
                       0x11fb0  397  ?setCount@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXH@Z
                       0x11fb0  398  ?setCount@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXH@Z
                       0x11fb0  399  ?setCount@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEXH@Z */
  if ((-1 < param_1) && (param_1 <= *(int *)(this + 4))) {
    *(int *)this = param_1;
  }
  return;
}


// vgui::Dar<char>::setElementAt  @ 27012390
/* public: void __thiscall vgui::Dar<char>::setElementAt(char,int) */

void __thiscall vgui::Dar<char>::setElementAt(Dar<char> *this,char param_1,int param_2)

{
                    /* 0x12390  400  ?setElementAt@?$Dar@D@vgui@@QAEXDH@Z */
  if ((-1 < param_2) && (param_2 < *(int *)this)) {
    *(char *)(*(int *)(this + 8) + param_2) = param_1;
  }
  return;
}


// vgui::Dar<int>::Dar<int>  @ 27013ec0
/* public: __thiscall vgui::Dar<int>::Dar<int>(void) */

Dar<int> * __thiscall vgui::Dar<int>::Dar<int>(Dar<int> *this)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
                    /* 0x13ec0  4  ??0?$Dar@H@vgui@@QAE@XZ
                       0x13ec0  6  ??0?$Dar@PAD@vgui@@QAE@XZ
                       0x13ec0  8  ??0?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAE@XZ
                       0x13ec0  10  ??0?$Dar@PAVActionSignal@vgui@@@vgui@@QAE@XZ
                       0x13ec0  12  ??0?$Dar@PAVButton@vgui@@@vgui@@QAE@XZ
                       0x13ec0  14  ??0?$Dar@PAVChangeSignal@vgui@@@vgui@@QAE@XZ
                       0x13ec0  16  ??0?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAE@XZ
                       0x13ec0  18  ??0?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAE@XZ
                       0x13ec0  20  ??0?$Dar@PAVFrame@vgui@@@vgui@@QAE@XZ
                       0x13ec0  22  ??0?$Dar@PAVFrameSignal@vgui@@@vgui@@QAE@XZ
                       0x13ec0  24  ??0?$Dar@PAVInputSignal@vgui@@@vgui@@QAE@XZ
                       0x13ec0  26  ??0?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAE@XZ
                       0x13ec0  28  ??0?$Dar@PAVLabel@vgui@@@vgui@@QAE@XZ
                       0x13ec0  30  ??0?$Dar@PAVPanel@vgui@@@vgui@@QAE@XZ
                       0x13ec0  32  ??0?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAE@XZ
                       0x13ec0  34  ??0?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAE@XZ
                       0x13ec0  36  ??0?$Dar@PAVTickSignal@vgui@@@vgui@@QAE@XZ */
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
    FUN_270374fa(0);
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
  FUN_270374c2(*(LPVOID *)(this + 8));
  *(undefined4 **)(this + 8) = puVar2;
  return this;
}


// vgui::Dar<int>::Dar<int>  @ 27014000
/* public: __thiscall vgui::Dar<int>::Dar<int>(int) */

Dar<int> * __thiscall vgui::Dar<int>::Dar<int>(Dar<int> *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
                    /* 0x14000  3  ??0?$Dar@H@vgui@@QAE@H@Z
                       0x14000  5  ??0?$Dar@PAD@vgui@@QAE@H@Z
                       0x14000  7  ??0?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAE@H@Z
                       0x14000  9  ??0?$Dar@PAVActionSignal@vgui@@@vgui@@QAE@H@Z
                       0x14000  11  ??0?$Dar@PAVButton@vgui@@@vgui@@QAE@H@Z
                       0x14000  13  ??0?$Dar@PAVChangeSignal@vgui@@@vgui@@QAE@H@Z
                       0x14000  15  ??0?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAE@H@Z
                       0x14000  17  ??0?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAE@H@Z
                       0x14000  19  ??0?$Dar@PAVFrame@vgui@@@vgui@@QAE@H@Z
                       0x14000  21  ??0?$Dar@PAVFrameSignal@vgui@@@vgui@@QAE@H@Z
                       0x14000  23  ??0?$Dar@PAVInputSignal@vgui@@@vgui@@QAE@H@Z
                       0x14000  25  ??0?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAE@H@Z
                       0x14000  27  ??0?$Dar@PAVLabel@vgui@@@vgui@@QAE@H@Z
                       0x14000  29  ??0?$Dar@PAVPanel@vgui@@@vgui@@QAE@H@Z
                       0x14000  31  ??0?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAE@H@Z
                       0x14000  33  ??0?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAE@H@Z
                       0x14000  35  ??0?$Dar@PAVTickSignal@vgui@@@vgui@@QAE@H@Z */
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
      FUN_270374fa(0);
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
    FUN_270374c2(*(LPVOID *)(this + 8));
    *(undefined4 **)(this + 8) = puVar1;
  }
  return this;
}


// vgui::Dar<int>::addElement  @ 27014090
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
  
                    /* 0x14090  221  ?addElement@?$Dar@H@vgui@@QAEXH@Z
                       0x14090  222  ?addElement@?$Dar@PAD@vgui@@QAEXPAD@Z
                       0x14090  223  ?addElement@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXPAV?$Dar@D@2@@Z
                       0x14090  224
                       ?addElement@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXPAVActionSignal@2@@Z
                       0x14090  225  ?addElement@?$Dar@PAVButton@vgui@@@vgui@@QAEXPAVButton@2@@Z
                       0x14090  226
                       ?addElement@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXPAVChangeSignal@2@@Z
                       0x14090  227
                       ?addElement@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXPAVDesktopIcon@2@@Z
                       0x14090  228
                       ?addElement@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXPAVFocusChangeSignal@2@@Z
                       0x14090  229  ?addElement@?$Dar@PAVFrame@vgui@@@vgui@@QAEXPAVFrame@2@@Z
                       0x14090  230
                       ?addElement@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXPAVFrameSignal@2@@Z
                       0x14090  231
                       ?addElement@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXPAVInputSignal@2@@Z
                       0x14090  232
                       ?addElement@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXPAVIntChangeSignal@2@@Z
                       0x14090  233  ?addElement@?$Dar@PAVLabel@vgui@@@vgui@@QAEXPAVLabel@2@@Z
                       0x14090  234  ?addElement@?$Dar@PAVPanel@vgui@@@vgui@@QAEXPAVPanel@2@@Z
                       0x14090  235
                       ?addElement@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXPAVRepaintSignal@2@@Z
                       0x14090  236
                       ?addElement@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXPAVSurfaceBase@2@@Z
                       0x14090  237
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
      FUN_270374fa(0);
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
    FUN_270374c2(*(LPVOID *)(this + 8));
    *(undefined4 **)(this + 8) = puVar1;
  }
  *(undefined4 *)(*(int *)(this + 8) + *(int *)this * 4) = unaff_retaddr;
  *(int *)this = *(int *)this + 1;
  return;
}


// vgui::Dar<int>::ensureCapacity  @ 27012db0
/* public: void __thiscall vgui::Dar<int>::ensureCapacity(int) */

void __thiscall vgui::Dar<int>::ensureCapacity(Dar<int> *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
                    /* 0x12db0  239  ?ensureCapacity@?$Dar@H@vgui@@QAEXH@Z
                       0x12db0  240  ?ensureCapacity@?$Dar@PAD@vgui@@QAEXH@Z
                       0x12db0  241  ?ensureCapacity@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXH@Z
                       0x12db0  242  ?ensureCapacity@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXH@Z
                       0x12db0  243  ?ensureCapacity@?$Dar@PAVButton@vgui@@@vgui@@QAEXH@Z
                       0x12db0  244  ?ensureCapacity@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x12db0  245  ?ensureCapacity@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXH@Z
                       0x12db0  246  ?ensureCapacity@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x12db0  247  ?ensureCapacity@?$Dar@PAVFrame@vgui@@@vgui@@QAEXH@Z
                       0x12db0  248  ?ensureCapacity@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXH@Z
                       0x12db0  249  ?ensureCapacity@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXH@Z
                       0x12db0  250  ?ensureCapacity@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x12db0  251  ?ensureCapacity@?$Dar@PAVLabel@vgui@@@vgui@@QAEXH@Z
                       0x12db0  252  ?ensureCapacity@?$Dar@PAVPanel@vgui@@@vgui@@QAEXH@Z
                       0x12db0  253  ?ensureCapacity@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXH@Z
                       0x12db0  254  ?ensureCapacity@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXH@Z
                       0x12db0  255  ?ensureCapacity@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEXH@Z */
  uVar5 = *(uint *)(this + 4);
  if ((int)uVar5 < param_1) {
    if (uVar5 == 0) {
      uVar5 = 1;
    }
    for (; (int)uVar5 < param_1; uVar5 = uVar5 * 2) {
    }
    puVar1 = operator_new(uVar5 * 4);
    if (puVar1 == (undefined4 *)0x0) {
      FUN_270374fa(0);
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
    FUN_270374c2(*(LPVOID *)(this + 8));
    *(undefined4 **)(this + 8) = puVar1;
  }
  return;
}


// vgui::Dar<int>::hasElement  @ 270142f0
/* public: bool __thiscall vgui::Dar<int>::hasElement(int) */

bool __thiscall vgui::Dar<int>::hasElement(Dar<int> *this,int param_1)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x142f0  275  ?hasElement@?$Dar@H@vgui@@QAE_NH@Z
                       0x142f0  276  ?hasElement@?$Dar@PAD@vgui@@QAE_NPAD@Z
                       0x142f0  277  ?hasElement@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAE_NPAV?$Dar@D@2@@Z
                       0x142f0  278
                       ?hasElement@?$Dar@PAVActionSignal@vgui@@@vgui@@QAE_NPAVActionSignal@2@@Z
                       0x142f0  279  ?hasElement@?$Dar@PAVButton@vgui@@@vgui@@QAE_NPAVButton@2@@Z
                       0x142f0  280
                       ?hasElement@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAE_NPAVChangeSignal@2@@Z
                       0x142f0  281
                       ?hasElement@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAE_NPAVDesktopIcon@2@@Z
                       0x142f0  282
                       ?hasElement@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAE_NPAVFocusChangeSignal@2@@Z
                       0x142f0  283  ?hasElement@?$Dar@PAVFrame@vgui@@@vgui@@QAE_NPAVFrame@2@@Z
                       0x142f0  284
                       ?hasElement@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAE_NPAVFrameSignal@2@@Z
                       0x142f0  285
                       ?hasElement@?$Dar@PAVInputSignal@vgui@@@vgui@@QAE_NPAVInputSignal@2@@Z
                       0x142f0  286
                       ?hasElement@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAE_NPAVIntChangeSignal@2@@Z
                       0x142f0  287  ?hasElement@?$Dar@PAVLabel@vgui@@@vgui@@QAE_NPAVLabel@2@@Z
                       0x142f0  288  ?hasElement@?$Dar@PAVPanel@vgui@@@vgui@@QAE_NPAVPanel@2@@Z
                       0x142f0  289
                       ?hasElement@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAE_NPAVRepaintSignal@2@@Z
                       0x142f0  290
                       ?hasElement@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAE_NPAVSurfaceBase@2@@Z
                       0x142f0  291
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


// vgui::Dar<int>::insertElementAt  @ 27014130
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
  
                    /* 0x14130  293  ?insertElementAt@?$Dar@H@vgui@@QAEXHH@Z
                       0x14130  294  ?insertElementAt@?$Dar@PAD@vgui@@QAEXPADH@Z
                       0x14130  295
                       ?insertElementAt@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXPAV?$Dar@D@2@H@Z
                       0x14130  296
                       ?insertElementAt@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXPAVActionSignal@2@H@Z
                       0x14130  297
                       ?insertElementAt@?$Dar@PAVButton@vgui@@@vgui@@QAEXPAVButton@2@H@Z
                       0x14130  298
                       ?insertElementAt@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXPAVChangeSignal@2@H@Z
                       0x14130  299
                       ?insertElementAt@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXPAVDesktopIcon@2@H@Z
                       0x14130  300
                       ?insertElementAt@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXPAVFocusChangeSignal@2@H@Z
                       0x14130  301  ?insertElementAt@?$Dar@PAVFrame@vgui@@@vgui@@QAEXPAVFrame@2@H@Z
                       0x14130  302
                       ?insertElementAt@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXPAVFrameSignal@2@H@Z
                       0x14130  303
                       ?insertElementAt@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXPAVInputSignal@2@H@Z
                       0x14130  304
                       ?insertElementAt@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXPAVIntChangeSignal@2@H@Z
                       0x14130  305  ?insertElementAt@?$Dar@PAVLabel@vgui@@@vgui@@QAEXPAVLabel@2@H@Z
                       0x14130  306  ?insertElementAt@?$Dar@PAVPanel@vgui@@@vgui@@QAEXPAVPanel@2@H@Z
                       0x14130  307
                       ?insertElementAt@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXPAVRepaintSignal@2@H@Z
                       0x14130  308
                       ?insertElementAt@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXPAVSurfaceBase@2@H@Z
                       0x14130  309
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
            FUN_270374fa(0);
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
          FUN_270374c2(*(LPVOID *)(this + 8));
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
          FUN_270374fa(0);
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
        FUN_270374c2(*(LPVOID *)(this + 8));
        *(undefined4 **)(this + 8) = puVar1;
      }
      *(undefined4 *)(*(int *)(this + 8) + *(int *)this * 4) = unaff_retaddr;
      *(int *)this = *(int *)this + 1;
    }
  }
  return;
}


// vgui::Dar<int>::operator[]  @ 27012d90
/* public: int __thiscall vgui::Dar<int>::operator[](int) */

int __thiscall vgui::Dar<int>::operator[](Dar<int> *this,int param_1)

{
                    /* 0x12d90  139  ??A?$Dar@H@vgui@@QAEHH@Z
                       0x12d90  140  ??A?$Dar@PAD@vgui@@QAEPADH@Z
                       0x12d90  141  ??A?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEPAV?$Dar@D@1@H@Z
                       0x12d90  142  ??A?$Dar@PAVActionSignal@vgui@@@vgui@@QAEPAVActionSignal@1@H@Z
                       0x12d90  143  ??A?$Dar@PAVButton@vgui@@@vgui@@QAEPAVButton@1@H@Z
                       0x12d90  144  ??A?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEPAVChangeSignal@1@H@Z
                       0x12d90  145  ??A?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEPAVDesktopIcon@1@H@Z
                       0x12d90  146
                       ??A?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEPAVFocusChangeSignal@1@H@Z
                       0x12d90  147  ??A?$Dar@PAVFrame@vgui@@@vgui@@QAEPAVFrame@1@H@Z
                       0x12d90  148  ??A?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEPAVFrameSignal@1@H@Z
                       0x12d90  149  ??A?$Dar@PAVInputSignal@vgui@@@vgui@@QAEPAVInputSignal@1@H@Z
                       0x12d90  150
                       ??A?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEPAVIntChangeSignal@1@H@Z
                       0x12d90  151  ??A?$Dar@PAVLabel@vgui@@@vgui@@QAEPAVLabel@1@H@Z
                       0x12d90  152  ??A?$Dar@PAVPanel@vgui@@@vgui@@QAEPAVPanel@1@H@Z
                       0x12d90  153
                       ??A?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEPAVRepaintSignal@1@H@Z
                       0x12d90  154  ??A?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEPAVSurfaceBase@1@H@Z
                       0x12d90  155  ??A?$Dar@PAVTickSignal@vgui@@@vgui@@QAEPAVTickSignal@1@H@Z */
  if ((-1 < param_1) && (param_1 < *(int *)this)) {
    return *(int *)(*(int *)(this + 8) + param_1 * 4);
  }
  return 0;
}


// vgui::Dar<int>::putElement  @ 27013f40
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
  
                    /* 0x13f40  311  ?putElement@?$Dar@H@vgui@@QAEXH@Z
                       0x13f40  312  ?putElement@?$Dar@PAD@vgui@@QAEXPAD@Z
                       0x13f40  313  ?putElement@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXPAV?$Dar@D@2@@Z
                       0x13f40  314
                       ?putElement@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXPAVActionSignal@2@@Z
                       0x13f40  315  ?putElement@?$Dar@PAVButton@vgui@@@vgui@@QAEXPAVButton@2@@Z
                       0x13f40  316
                       ?putElement@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXPAVChangeSignal@2@@Z
                       0x13f40  317
                       ?putElement@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXPAVDesktopIcon@2@@Z
                       0x13f40  318
                       ?putElement@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXPAVFocusChangeSignal@2@@Z
                       0x13f40  319  ?putElement@?$Dar@PAVFrame@vgui@@@vgui@@QAEXPAVFrame@2@@Z
                       0x13f40  320
                       ?putElement@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXPAVFrameSignal@2@@Z
                       0x13f40  321
                       ?putElement@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXPAVInputSignal@2@@Z
                       0x13f40  322
                       ?putElement@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXPAVIntChangeSignal@2@@Z
                       0x13f40  323  ?putElement@?$Dar@PAVLabel@vgui@@@vgui@@QAEXPAVLabel@2@@Z
                       0x13f40  324  ?putElement@?$Dar@PAVPanel@vgui@@@vgui@@QAEXPAVPanel@2@@Z
                       0x13f40  325
                       ?putElement@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXPAVRepaintSignal@2@@Z
                       0x13f40  326
                       ?putElement@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXPAVSurfaceBase@2@@Z
                       0x13f40  327
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
      FUN_270374fa(0);
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
    FUN_270374c2(*(LPVOID *)(this + 8));
    *(undefined4 **)(this + 8) = puVar1;
  }
  *(undefined4 *)(*(int *)(this + 8) + *(int *)this * 4) = unaff_retaddr;
  *(int *)this = *(int *)this + 1;
  return;
}


// vgui::Dar<int>::removeElement  @ 270142a0
/* public: void __thiscall vgui::Dar<int>::removeElement(int) */

void __thiscall vgui::Dar<int>::removeElement(Dar<int> *this,int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
                    /* 0x142a0  347  ?removeElement@?$Dar@H@vgui@@QAEXH@Z
                       0x142a0  348  ?removeElement@?$Dar@PAD@vgui@@QAEXPAD@Z
                       0x142a0  349
                       ?removeElement@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXPAV?$Dar@D@2@@Z
                       0x142a0  350
                       ?removeElement@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXPAVActionSignal@2@@Z
                       0x142a0  351  ?removeElement@?$Dar@PAVButton@vgui@@@vgui@@QAEXPAVButton@2@@Z
                       0x142a0  352
                       ?removeElement@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXPAVChangeSignal@2@@Z
                       0x142a0  353
                       ?removeElement@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXPAVDesktopIcon@2@@Z
                       0x142a0  354
                       ?removeElement@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXPAVFocusChangeSignal@2@@Z
                       0x142a0  355  ?removeElement@?$Dar@PAVFrame@vgui@@@vgui@@QAEXPAVFrame@2@@Z
                       0x142a0  356
                       ?removeElement@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXPAVFrameSignal@2@@Z
                       0x142a0  357
                       ?removeElement@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXPAVInputSignal@2@@Z
                       0x142a0  358
                       ?removeElement@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXPAVIntChangeSignal@2@@Z
                       0x142a0  359  ?removeElement@?$Dar@PAVLabel@vgui@@@vgui@@QAEXPAVLabel@2@@Z
                       0x142a0  360  ?removeElement@?$Dar@PAVPanel@vgui@@@vgui@@QAEXPAVPanel@2@@Z
                       0x142a0  361
                       ?removeElement@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXPAVRepaintSignal@2@@Z
                       0x142a0  362
                       ?removeElement@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXPAVSurfaceBase@2@@Z
                       0x142a0  363
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


// vgui::Dar<int>::removeElementAt  @ 27014320
/* public: void __thiscall vgui::Dar<int>::removeElementAt(int) */

void __thiscall vgui::Dar<int>::removeElementAt(Dar<int> *this,int param_1)

{
                    /* 0x14320  365  ?removeElementAt@?$Dar@H@vgui@@QAEXH@Z
                       0x14320  366  ?removeElementAt@?$Dar@PAD@vgui@@QAEXH@Z
                       0x14320  367  ?removeElementAt@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXH@Z
                       0x14320  368  ?removeElementAt@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXH@Z
                       0x14320  369  ?removeElementAt@?$Dar@PAVButton@vgui@@@vgui@@QAEXH@Z
                       0x14320  370  ?removeElementAt@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x14320  371  ?removeElementAt@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXH@Z
                       0x14320  372
                       ?removeElementAt@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x14320  373  ?removeElementAt@?$Dar@PAVFrame@vgui@@@vgui@@QAEXH@Z
                       0x14320  374  ?removeElementAt@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXH@Z
                       0x14320  375  ?removeElementAt@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXH@Z
                       0x14320  376  ?removeElementAt@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x14320  377  ?removeElementAt@?$Dar@PAVLabel@vgui@@@vgui@@QAEXH@Z
                       0x14320  378  ?removeElementAt@?$Dar@PAVPanel@vgui@@@vgui@@QAEXH@Z
                       0x14320  379  ?removeElementAt@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXH@Z
                       0x14320  380  ?removeElementAt@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXH@Z
                       0x14320  381  ?removeElementAt@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEXH@Z */
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


// vgui::Dar<int>::setElementAt  @ 27012bb0
/* public: void __thiscall vgui::Dar<int>::setElementAt(int,int) */

void __thiscall vgui::Dar<int>::setElementAt(Dar<int> *this,int param_1,int param_2)

{
                    /* 0x12bb0  401  ?setElementAt@?$Dar@H@vgui@@QAEXHH@Z
                       0x12bb0  402  ?setElementAt@?$Dar@PAD@vgui@@QAEXPADH@Z
                       0x12bb0  403
                       ?setElementAt@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXPAV?$Dar@D@2@H@Z
                       0x12bb0  404
                       ?setElementAt@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXPAVActionSignal@2@H@Z
                       0x12bb0  405  ?setElementAt@?$Dar@PAVButton@vgui@@@vgui@@QAEXPAVButton@2@H@Z
                       0x12bb0  406
                       ?setElementAt@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXPAVChangeSignal@2@H@Z
                       0x12bb0  407
                       ?setElementAt@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXPAVDesktopIcon@2@H@Z
                       0x12bb0  408
                       ?setElementAt@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXPAVFocusChangeSignal@2@H@Z
                       0x12bb0  409  ?setElementAt@?$Dar@PAVFrame@vgui@@@vgui@@QAEXPAVFrame@2@H@Z
                       0x12bb0  410
                       ?setElementAt@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXPAVFrameSignal@2@H@Z
                       0x12bb0  411
                       ?setElementAt@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXPAVInputSignal@2@H@Z
                       0x12bb0  412
                       ?setElementAt@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXPAVIntChangeSignal@2@H@Z
                       0x12bb0  413  ?setElementAt@?$Dar@PAVLabel@vgui@@@vgui@@QAEXPAVLabel@2@H@Z
                       0x12bb0  414  ?setElementAt@?$Dar@PAVPanel@vgui@@@vgui@@QAEXPAVPanel@2@H@Z
                       0x12bb0  415
                       ?setElementAt@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXPAVRepaintSignal@2@H@Z
                       0x12bb0  416
                       ?setElementAt@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXPAVSurfaceBase@2@H@Z
                       0x12bb0  417
                       ?setElementAt@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEXPAVTickSignal@2@H@Z */
  if ((-1 < param_2) && (param_2 < *(int *)this)) {
    *(int *)(*(int *)(this + 8) + param_2 * 4) = param_1;
  }
  return;
}


// vgui::DataInputStream::DataInputStream  @ 27028b20
/* public: __thiscall vgui::DataInputStream::DataInputStream(class vgui::DataInputStream const &) */

void __thiscall
vgui::DataInputStream::DataInputStream(DataInputStream *this,DataInputStream *param_1)

{
  int in_stack_00000008;
  
                    /* 0x28b20  48  ??0DataInputStream@vgui@@QAE@ABV01@@Z */
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


// vgui::DataInputStream::operator=  @ 27028b70
/* public: class vgui::DataInputStream & __thiscall vgui::DataInputStream::operator=(class
   vgui::DataInputStream const &) */

DataInputStream * __thiscall
vgui::DataInputStream::operator=(DataInputStream *this,DataInputStream *param_1)

{
                    /* 0x28b70  108  ??4DataInputStream@vgui@@QAEAAV01@ABV01@@Z */
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  return this;
}


// vgui::DesktopIcon::DesktopIcon  @ 270125d0
/* public: __thiscall vgui::DesktopIcon::DesktopIcon(class vgui::DesktopIcon const &) */

void __thiscall vgui::DesktopIcon::DesktopIcon(DesktopIcon *this,DesktopIcon *param_1)

{
                    /* 0x125d0  49  ??0DesktopIcon@vgui@@QAE@ABV01@@Z */
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


// vgui::DesktopIcon::operator=  @ 270127b0
/* public: class vgui::DesktopIcon & __thiscall vgui::DesktopIcon::operator=(class vgui::DesktopIcon
   const &) */

DesktopIcon * __thiscall vgui::DesktopIcon::operator=(DesktopIcon *this,DesktopIcon *param_1)

{
  int iVar1;
  DesktopIcon *pDVar2;
  int iVar3;
  
                    /* 0x127b0  109  ??4DesktopIcon@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::FileInputStream::FileInputStream  @ 27012400
/* public: __thiscall vgui::FileInputStream::FileInputStream(class vgui::FileInputStream const &) */

void __thiscall
vgui::FileInputStream::FileInputStream(FileInputStream *this,FileInputStream *param_1)

{
  undefined4 uVar1;
  
                    /* 0x12400  50  ??0FileInputStream@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &InputStream::_vftable_;
  uVar1 = *(undefined4 *)(param_1 + 4);
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 4) = uVar1;
  return;
}


// vgui::Font::Font  @ 27013e70
/* public: __thiscall vgui::Font::Font(class vgui::Font const &) */

void __thiscall vgui::Font::Font(Font *this,Font *param_1)

{
                    /* 0x13e70  51  ??0Font@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Font::operator=  @ 27013ea0
/* public: class vgui::Font & __thiscall vgui::Font::operator=(class vgui::Font const &) */

Font * __thiscall vgui::Font::operator=(Font *this,Font *param_1)

{
                    /* 0x13ea0  111  ??4Font@vgui@@QAEAAV01@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  return this;
}


// vgui::Frame::Frame  @ 27010ef0
/* public: __thiscall vgui::Frame::Frame(class vgui::Frame const &) */

void __thiscall vgui::Frame::Frame(Frame *this,Frame *param_1)

{
                    /* 0x10ef0  52  ??0Frame@vgui@@QAE@ABV01@@Z */
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


// vgui::Frame::operator=  @ 270111b0
/* public: class vgui::Frame & __thiscall vgui::Frame::operator=(class vgui::Frame const &) */

Frame * __thiscall vgui::Frame::operator=(Frame *this,Frame *param_1)

{
  int iVar1;
  Frame *pFVar2;
  int iVar3;
  
                    /* 0x111b0  112  ??4Frame@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::HeaderPanel::HeaderPanel  @ 270280d0
/* public: __thiscall vgui::HeaderPanel::HeaderPanel(class vgui::HeaderPanel const &) */

void __thiscall vgui::HeaderPanel::HeaderPanel(HeaderPanel *this,HeaderPanel *param_1)

{
                    /* 0x280d0  53  ??0HeaderPanel@vgui@@QAE@ABV01@@Z */
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


// vgui::HeaderPanel::operator=  @ 27028320
/* public: class vgui::HeaderPanel & __thiscall vgui::HeaderPanel::operator=(class vgui::HeaderPanel
   const &) */

HeaderPanel * __thiscall vgui::HeaderPanel::operator=(HeaderPanel *this,HeaderPanel *param_1)

{
  int iVar1;
  HeaderPanel *pHVar2;
  int iVar3;
  
                    /* 0x28320  113  ??4HeaderPanel@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::Image::Image  @ 27012180
/* public: __thiscall vgui::Image::Image(class vgui::Image const &) */

void __thiscall vgui::Image::Image(Image *this,Image *param_1)

{
                    /* 0x12180  54  ??0Image@vgui@@QAE@ABV01@@Z */
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


// vgui::Image::operator=  @ 27012320
/* public: class vgui::Image & __thiscall vgui::Image::operator=(class vgui::Image const &) */

Image * __thiscall vgui::Image::operator=(Image *this,Image *param_1)

{
  Image *pIVar1;
  int iVar2;
  
                    /* 0x12320  114  ??4Image@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::ImagePanel::ImagePanel  @ 2702f050
/* public: __thiscall vgui::ImagePanel::ImagePanel(class vgui::ImagePanel const &) */

void __thiscall vgui::ImagePanel::ImagePanel(ImagePanel *this,ImagePanel *param_1)

{
  undefined4 uVar1;
  
                    /* 0x2f050  55  ??0ImagePanel@vgui@@QAE@ABV01@@Z */
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


// vgui::ImagePanel::operator=  @ 2702f210
/* public: class vgui::ImagePanel & __thiscall vgui::ImagePanel::operator=(class vgui::ImagePanel
   const &) */

ImagePanel * __thiscall vgui::ImagePanel::operator=(ImagePanel *this,ImagePanel *param_1)

{
  int iVar1;
  ImagePanel *pIVar2;
  int iVar3;
  
                    /* 0x2f210  115  ??4ImagePanel@vgui@@QAEAAV01@ABV01@@Z
                       0x2f210  137  ??4TextPanel@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::InputSignal::InputSignal  @ 27012080
/* public: __thiscall vgui::InputSignal::InputSignal(void) */

void __thiscall vgui::InputSignal::InputSignal(InputSignal *this)

{
                    /* 0x12080  57  ??0InputSignal@vgui@@QAE@XZ */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::InputSignal::InputSignal  @ 270120c0
/* public: __thiscall vgui::InputSignal::InputSignal(class vgui::InputSignal const &) */

void __thiscall vgui::InputSignal::InputSignal(InputSignal *this,InputSignal *param_1)

{
                    /* 0x120c0  56  ??0InputSignal@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::InputStream::InputStream  @ 270123b0
/* public: __thiscall vgui::InputStream::InputStream(void) */

void __thiscall vgui::InputStream::InputStream(InputStream *this)

{
                    /* 0x123b0  59  ??0InputStream@vgui@@QAE@XZ */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::InputStream::InputStream  @ 270123c0
/* public: __thiscall vgui::InputStream::InputStream(class vgui::InputStream const &) */

void __thiscall vgui::InputStream::InputStream(InputStream *this,InputStream *param_1)

{
                    /* 0x123c0  58  ??0InputStream@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Label::Label  @ 27011660
/* public: __thiscall vgui::Label::Label(class vgui::Label const &) */

void __thiscall vgui::Label::Label(Label *this,Label *param_1)

{
                    /* 0x11660  60  ??0Label@vgui@@QAE@ABV01@@Z */
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


// vgui::Label::operator=  @ 2702f610
/* public: class vgui::Label & __thiscall vgui::Label::operator=(class vgui::Label const &) */

Label * __thiscall vgui::Label::operator=(Label *this,Label *param_1)

{
  int iVar1;
  Label *pLVar2;
  int iVar3;
  
                    /* 0x2f610  118  ??4Label@vgui@@QAEAAV01@ABV01@@Z
                       0x2f610  122  ??4MenuSeparator@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::Layout::Layout  @ 27029d40
/* public: __thiscall vgui::Layout::Layout(class vgui::Layout const &) */

void __thiscall vgui::Layout::Layout(Layout *this,Layout *param_1)

{
                    /* 0x29d40  61  ??0Layout@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::LineBorder::LineBorder  @ 27012f80
/* public: __thiscall vgui::LineBorder::LineBorder(class vgui::LineBorder const &) */

void __thiscall vgui::LineBorder::LineBorder(LineBorder *this,LineBorder *param_1)

{
                    /* 0x12f80  62  ??0LineBorder@vgui@@QAE@ABV01@@Z */
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


// vgui::LineBorder::operator=  @ 27013010
/* public: class vgui::LineBorder & __thiscall vgui::LineBorder::operator=(class vgui::LineBorder
   const &) */

LineBorder * __thiscall vgui::LineBorder::operator=(LineBorder *this,LineBorder *param_1)

{
  LineBorder *pLVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x13010  120  ??4LineBorder@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::LoweredBorder::LoweredBorder  @ 2702f850
/* public: __thiscall vgui::LoweredBorder::LoweredBorder(class vgui::LoweredBorder const &) */

void __thiscall vgui::LoweredBorder::LoweredBorder(LoweredBorder *this,LoweredBorder *param_1)

{
                    /* 0x2f850  63  ??0LoweredBorder@vgui@@QAE@ABV01@@Z */
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


// vgui::MenuSeparator::MenuSeparator  @ 2702f400
/* public: __thiscall vgui::MenuSeparator::MenuSeparator(class vgui::MenuSeparator const &) */

void __thiscall vgui::MenuSeparator::MenuSeparator(MenuSeparator *this,MenuSeparator *param_1)

{
                    /* 0x2f400  64  ??0MenuSeparator@vgui@@QAE@ABV01@@Z */
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


// vgui::MiniApp::MiniApp  @ 27012e40
/* public: __thiscall vgui::MiniApp::MiniApp(class vgui::MiniApp const &) */

void __thiscall vgui::MiniApp::MiniApp(MiniApp *this,MiniApp *param_1)

{
  undefined4 uVar1;
  
                    /* 0x12e40  65  ??0MiniApp@vgui@@QAE@ABV01@@Z */
  uVar1 = *(undefined4 *)(param_1 + 4);
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 4) = uVar1;
  return;
}


// vgui::Panel::Panel  @ 270105f0
/* public: __thiscall vgui::Panel::Panel(class vgui::Panel const &) */

void __thiscall vgui::Panel::Panel(Panel *this,Panel *param_1)

{
                    /* 0x105f0  66  ??0Panel@vgui@@QAE@ABV01@@Z */
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


// vgui::Panel::operator=  @ 27010860
/* public: class vgui::Panel & __thiscall vgui::Panel::operator=(class vgui::Panel const &) */

Panel * __thiscall vgui::Panel::operator=(Panel *this,Panel *param_1)

{
  int iVar1;
  Panel *pPVar2;
  int iVar3;
  
                    /* 0x10860  124  ??4Panel@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::Scheme::Scheme  @ 270104f0
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


// vgui::Scheme::operator=  @ 27010540
/* public: class vgui::Scheme & __thiscall vgui::Scheme::operator=(class vgui::Scheme const &) */

Scheme * __thiscall vgui::Scheme::operator=(Scheme *this,Scheme *param_1)

{
  int iVar1;
  Scheme *pSVar2;
  int iVar3;
  
                    /* 0x10540  125  ??4Scheme@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::ScrollBar::ScrollBar  @ 27013500
/* public: __thiscall vgui::ScrollBar::ScrollBar(class vgui::ScrollBar const &) */

void __thiscall vgui::ScrollBar::ScrollBar(ScrollBar *this,ScrollBar *param_1)

{
                    /* 0x13500  68  ??0ScrollBar@vgui@@QAE@ABV01@@Z */
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


// vgui::ScrollBar::operator=  @ 27013700
/* public: class vgui::ScrollBar & __thiscall vgui::ScrollBar::operator=(class vgui::ScrollBar const
   &) */

ScrollBar * __thiscall vgui::ScrollBar::operator=(ScrollBar *this,ScrollBar *param_1)

{
  ScrollBar *pSVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x13700  126  ??4ScrollBar@vgui@@QAEAAV01@ABV01@@Z */
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
  } while (pSVar1 + (-4 - (int)(this + 0x9c)) < (ScrollBar *)0x4);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  pSVar1 = this + 0xac;
  do {
    *pSVar1 = pSVar1[(int)(param_1 + (0xa8 - (int)(this + 0xa8)))];
    pSVar1 = pSVar1 + 1;
  } while (pSVar1 + (-4 - (int)(this + 0xa8)) < (ScrollBar *)0x4);
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


// vgui::ScrollPanel::ScrollPanel  @ 270130d0
/* public: __thiscall vgui::ScrollPanel::ScrollPanel(class vgui::ScrollPanel const &) */

void __thiscall vgui::ScrollPanel::ScrollPanel(ScrollPanel *this,ScrollPanel *param_1)

{
                    /* 0x130d0  69  ??0ScrollPanel@vgui@@QAE@ABV01@@Z */
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


// vgui::ScrollPanel::operator=  @ 270132c0
/* public: class vgui::ScrollPanel & __thiscall vgui::ScrollPanel::operator=(class vgui::ScrollPanel
   const &) */

ScrollPanel * __thiscall vgui::ScrollPanel::operator=(ScrollPanel *this,ScrollPanel *param_1)

{
  ScrollPanel *pSVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x132c0  127  ??4ScrollPanel@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::Slider::Slider  @ 27013940
/* public: __thiscall vgui::Slider::Slider(class vgui::Slider const &) */

void __thiscall vgui::Slider::Slider(Slider *this,Slider *param_1)

{
                    /* 0x13940  70  ??0Slider@vgui@@QAE@ABV01@@Z */
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


// vgui::Slider::operator=  @ 27013bc0
/* public: class vgui::Slider & __thiscall vgui::Slider::operator=(class vgui::Slider const &) */

Slider * __thiscall vgui::Slider::operator=(Slider *this,Slider *param_1)

{
  Slider *pSVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x13bc0  128  ??4Slider@vgui@@QAEAAV01@ABV01@@Z */
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
  } while (pSVar1 + (-4 - (int)(this + 0x9c)) < (Slider *)0x4);
  *(undefined4 *)(this + 0xa4) = *(undefined4 *)(param_1 + 0xa4);
  pSVar1 = this + 0xac;
  do {
    *pSVar1 = pSVar1[(int)(param_1 + (0xa8 - (int)(this + 0xa8)))];
    pSVar1 = pSVar1 + 1;
  } while (pSVar1 + (-4 - (int)(this + 0xa8)) < (Slider *)0x4);
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


// vgui::StackLayout::StackLayout  @ 2702a570
/* public: __thiscall vgui::StackLayout::StackLayout(class vgui::StackLayout const &) */

void __thiscall vgui::StackLayout::StackLayout(StackLayout *this,StackLayout *param_1)

{
                    /* 0x2a570  71  ??0StackLayout@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &Layout::_vftable_;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  this[8] = param_1[8];
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::StackLayout::operator=  @ 2702a5a0
/* public: class vgui::StackLayout & __thiscall vgui::StackLayout::operator=(class vgui::StackLayout
   const &) */

StackLayout * __thiscall vgui::StackLayout::operator=(StackLayout *this,StackLayout *param_1)

{
                    /* 0x2a5a0  129  ??4StackLayout@vgui@@QAEAAV01@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  this[8] = param_1[8];
  return this;
}


// vgui::String::operator=  @ 270130c0
/* public: class vgui::String & __thiscall vgui::String::operator=(class vgui::String const &) */

String * __thiscall vgui::String::operator=(String *this,String *param_1)

{
                    /* 0x130c0  130  ??4String@vgui@@QAEAAV01@ABV01@@Z */
  *(undefined4 *)this = *(undefined4 *)param_1;
  return this;
}


// vgui::Surface::Surface  @ 2702e620
/* public: __thiscall vgui::Surface::Surface(class vgui::Surface const &) */

void __thiscall vgui::Surface::Surface(Surface *this,Surface *param_1)

{
  undefined4 uVar1;
  
                    /* 0x2e620  72  ??0Surface@vgui@@QAE@ABV01@@Z */
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


// vgui::Surface::operator=  @ 2702e6a0
/* public: class vgui::Surface & __thiscall vgui::Surface::operator=(class vgui::Surface const &) */

Surface * __thiscall vgui::Surface::operator=(Surface *this,Surface *param_1)

{
                    /* 0x2e6a0  131  ??4Surface@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::Surface::~Surface  @ 2702f040
/* public: __thiscall vgui::Surface::~Surface(void) */

void __thiscall vgui::Surface::~Surface(Surface *this)

{
                    /* 0x2f040  79  ??1Surface@vgui@@QAE@XZ */
                    /* WARNING: Could not recover jumptable at 0x27036dc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  vgui::SurfaceBase::~SurfaceBase((SurfaceBase *)this);
  return;
}


// vgui::SurfaceBase::SurfaceBase  @ 27029d80
/* public: __thiscall vgui::SurfaceBase::SurfaceBase(class vgui::SurfaceBase const &) */

void __thiscall vgui::SurfaceBase::SurfaceBase(SurfaceBase *this,SurfaceBase *param_1)

{
                    /* 0x29d80  73  ??0SurfaceBase@vgui@@QAE@ABV01@@Z */
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


// vgui::SurfaceBase::operator=  @ 27029dd0
/* public: class vgui::SurfaceBase & __thiscall vgui::SurfaceBase::operator=(class vgui::SurfaceBase
   const &) */

SurfaceBase * __thiscall vgui::SurfaceBase::operator=(SurfaceBase *this,SurfaceBase *param_1)

{
                    /* 0x29dd0  132  ??4SurfaceBase@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::TablePanel::TablePanel  @ 270285a0
/* public: __thiscall vgui::TablePanel::TablePanel(class vgui::TablePanel const &) */

void __thiscall vgui::TablePanel::TablePanel(TablePanel *this,TablePanel *param_1)

{
                    /* 0x285a0  74  ??0TablePanel@vgui@@QAE@ABV01@@Z */
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


// vgui::TablePanel::operator=  @ 27028840
/* public: class vgui::TablePanel & __thiscall vgui::TablePanel::operator=(class vgui::TablePanel
   const &) */

TablePanel * __thiscall vgui::TablePanel::operator=(TablePanel *this,TablePanel *param_1)

{
  TablePanel *pTVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x28840  133  ??4TablePanel@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::TextEntry::TextEntry  @ 27028b80
/* public: __thiscall vgui::TextEntry::TextEntry(class vgui::TextEntry const &) */

void __thiscall vgui::TextEntry::TextEntry(TextEntry *this,TextEntry *param_1)

{
                    /* 0x28b80  75  ??0TextEntry@vgui@@QAE@ABV01@@Z */
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


// vgui::TextEntry::operator=  @ 27028de0
/* public: class vgui::TextEntry & __thiscall vgui::TextEntry::operator=(class vgui::TextEntry const
   &) */

TextEntry * __thiscall vgui::TextEntry::operator=(TextEntry *this,TextEntry *param_1)

{
  TextEntry *pTVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x28de0  134  ??4TextEntry@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::TextGrid::TextGrid  @ 2702c720
/* public: __thiscall vgui::TextGrid::TextGrid(class vgui::TextGrid const &) */

void __thiscall vgui::TextGrid::TextGrid(TextGrid *this,TextGrid *param_1)

{
                    /* 0x2c720  76  ??0TextGrid@vgui@@QAE@ABV01@@Z */
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


// vgui::TextGrid::operator=  @ 2702c950
/* public: class vgui::TextGrid & __thiscall vgui::TextGrid::operator=(class vgui::TextGrid const &)
    */

TextGrid * __thiscall vgui::TextGrid::operator=(TextGrid *this,TextGrid *param_1)

{
  TextGrid *pTVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x2c950  135  ??4TextGrid@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::TextImage::TextImage  @ 27027a80
/* public: __thiscall vgui::TextImage::TextImage(class vgui::TextImage const &) */

void __thiscall vgui::TextImage::TextImage(TextImage *this,TextImage *param_1)

{
                    /* 0x27a80  77  ??0TextImage@vgui@@QAE@ABV01@@Z */
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


// vgui::TextImage::operator=  @ 27027b10
/* public: class vgui::TextImage & __thiscall vgui::TextImage::operator=(class vgui::TextImage const
   &) */

TextImage * __thiscall vgui::TextImage::operator=(TextImage *this,TextImage *param_1)

{
  TextImage *pTVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x27b10  136  ??4TextImage@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::TextPanel::TextPanel  @ 270114a0
/* public: __thiscall vgui::TextPanel::TextPanel(class vgui::TextPanel const &) */

void __thiscall vgui::TextPanel::TextPanel(TextPanel *this,TextPanel *param_1)

{
  undefined4 uVar1;
  
                    /* 0x114a0  78  ??0TextPanel@vgui@@QAE@ABV01@@Z */
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


