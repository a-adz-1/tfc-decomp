// CBaseMonster::CallMonsterThink  @ 27006220
/* public: void __thiscall CBaseMonster::CallMonsterThink(void) */

void __thiscall CBaseMonster::CallMonsterThink(CBaseMonster *this)

{
                    /* 0x6220  199  ?CallMonsterThink@CBaseMonster@@QAEXXZ */
                    /* WARNING: Could not recover jumptable at 0x27006222. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x114))();
  return;
}


// CBaseMonster::MonsterUse  @ 27005d90
/* public: void __thiscall CBaseMonster::MonsterUse(class CBaseEntity *,class CBaseEntity *,enum
   USE_TYPE,float) */

void __thiscall
CBaseMonster::MonsterUse
          (CBaseMonster *this,CBaseEntity *param_1,CBaseEntity *param_2,USE_TYPE param_3,
          float param_4)

{
                    /* 0x5d90  208  ?MonsterUse@CBaseMonster@@QAEXPAVCBaseEntity@@0W4USE_TYPE@@M@Z
                        */
  return;
}


// CBasePlayerAmmo::DefaultTouch  @ 27005d00
/* public: void __thiscall CBasePlayerAmmo::DefaultTouch(class CBaseEntity *) */

void __thiscall CBasePlayerAmmo::DefaultTouch(CBasePlayerAmmo *this,CBaseEntity *param_1)

{
                    /* 0x5d00  201  ?DefaultTouch@CBasePlayerAmmo@@QAEXPAVCBaseEntity@@@Z
                       0x5d00  202  ?DefaultTouch@CBasePlayerItem@@QAEXPAVCBaseEntity@@@Z
                       0x5d00  210  ?PlayerTouch@CBasePlayer@@QAEXPAVCBaseEntity@@@Z
                       0x5d00  212  ?RocketTouch@CTFRpgRocket@@QAEXPAVCBaseEntity@@@Z */
  return;
}


// CBasePlayerItem::AttemptToMaterialize  @ 27015000
/* public: void __thiscall CBasePlayerItem::AttemptToMaterialize(void) */

void __thiscall CBasePlayerItem::AttemptToMaterialize(CBasePlayerItem *this)

{
                    /* 0x15000  198  ?AttemptToMaterialize@CBasePlayerItem@@QAEXXZ
                       0x15000  200  ?CorpseFallThink@CBaseMonster@@QAEXXZ
                       0x15000  203  ?DestroyItem@CBasePlayerItem@@QAEXXZ
                       0x15000  204  ?FallThink@CBasePlayerItem@@QAEXXZ
                       0x15000  205  ?Materialize@CBasePlayerAmmo@@QAEXXZ
                       0x15000  206  ?Materialize@CBasePlayerItem@@QAEXXZ
                       0x15000  207  ?MonsterInitThink@CBaseMonster@@QAEXXZ
                       0x15000  209  ?PlayerDeathThink@CBasePlayer@@QAEXXZ
                       0x15000  211  ?Revive@CLaserSpot@@QAEXXZ
                       0x15000  214  ?SUB_Remove@CBaseEntity@@QAEXXZ
                       0x15000  215  ?Smack@CCrowbar@@QAEXXZ
                       0x15000  217  ?SwingAgain@CCrowbar@@QAEXXZ
                       0x15000  218  ?Timer_Tranquilisation@CBaseEntity@@QAEXXZ
                       0x15000  426  HUD_DrawNormalTriangles
                       0x15000  427  HUD_DrawTransparentTriangles */
  return;
}


// CTFAxe::Smack  @ 27009700
/* public: void __thiscall CTFAxe::Smack(void) */

void __thiscall CTFAxe::Smack(CTFAxe *this)

{
                    /* 0x9700  216  ?Smack@CTFAxe@@QAEXXZ */
                    /* WARNING: Could not recover jumptable at 0x27009702. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x18c))();
  return;
}


// CTFNailgunNail::TranqTouch  @ 2700e770
/* public: void __thiscall CTFNailgunNail::TranqTouch(class CBaseEntity *) */

void __thiscall CTFNailgunNail::TranqTouch(CTFNailgunNail *this,CBaseEntity *param_1)

{
  int iVar1;
  int iVar2;
  CBasePlayerItem *extraout_ECX;
  CBasePlayerItem *extraout_ECX_00;
  CBasePlayerItem *this_00;
  ulonglong uVar3;
  
                    /* 0xe770  219  ?TranqTouch@CTFNailgunNail@@QAEXPAVCBaseEntity@@@Z */
  if (*(float *)(*(int *)(param_1 + 4) + 0x16c) == 0.0) goto LAB_2700e88c;
  iVar1 = *(int *)(*(int *)(this + 4) + 0x198);
  if (iVar1 == 0) {
    iVar1 = (*DAT_2706c3fc)(0);
    if (iVar1 != 0) goto LAB_2700e7ae;
    iVar1 = 0;
  }
  else {
LAB_2700e7ae:
    iVar1 = *(int *)(iVar1 + 0x7c);
  }
  iVar2 = (**(code **)(*(int *)param_1 + 0x24))();
  if (iVar2 == 2) {
    iVar2 = FUN_27005cc0();
    this_00 = extraout_ECX;
    if (iVar2 != 0) {
      uVar3 = __ftol();
      this_00 = extraout_ECX_00;
      if ((uVar3 & 0x1e) != 0) goto LAB_2700e872;
    }
    if ((*(uint *)(param_1 + 0x78) & 0x8000) == 0) {
      CBasePlayerItem::AttemptToMaterialize(this_00);
      *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) | 0x8000;
      iVar2 = FUN_27005d10();
      *(float *)(*(int *)(iVar2 + 4) + 0x104) = *DAT_2706c52c + 15.0;
      *(code **)(iVar2 + 0x10) = CBasePlayerItem::AttemptToMaterialize;
      *(undefined4 *)(iVar2 + 0x114) = *(undefined4 *)(iVar1 + 0x114);
      FUN_27007a70((float)param_1);
    }
    else {
      iVar2 = FUN_27005d10();
      if (iVar2 != 0) {
        *(float *)(*(int *)(iVar2 + 4) + 0x104) = *DAT_2706c52c + 15.0;
      }
    }
  }
LAB_2700e872:
  (**(code **)(*(int *)param_1 + 0x30))
            (*(undefined4 *)(this + 4),*(undefined4 *)(iVar1 + 4),0x41a00000,0x800004);
LAB_2700e88c:
  CBasePlayerItem::AttemptToMaterialize((CBasePlayerItem *)this);
  return;
}


// Catch@270331b7  @ 270331b7
undefined4 Catch_270331b7(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(*(int *)(unaff_EBP + -0x1c) + 0xc4) = 0;
  return 0x270329c0;
}


// Initialize  @ 27014dd0
undefined4 __cdecl Initialize(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = param_1;
  puVar3 = &DAT_2707c8c8;
                    /* 0x14dd0  453  Initialize */
  for (iVar1 = 0x57; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  if (param_2 != 7) {
    return 0;
  }
  puVar2 = &DAT_2707c8c8;
  for (iVar1 = 0x57; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  thunk_FUN_27006480();
  return 1;
}


// Unwind@270477e0  @ 270477e0
void Unwind_270477e0(void)

{
  int unaff_EBP;
  
  FUN_2700a5d0(*(undefined4 *)(unaff_EBP + -0x10),*(int *)(unaff_EBP + 4));
  return;
}


// Unwind@27047800  @ 27047800
void Unwind_27047800(void)

{
  int unaff_EBP;
  
  FUN_2700a5d0(*(undefined4 *)(unaff_EBP + -0x10),*(int *)(unaff_EBP + 4));
  return;
}


// Unwind@27047820  @ 27047820
void Unwind_27047820(void)

{
  int unaff_EBP;
  
  FUN_2700a5d0(*(undefined4 *)(unaff_EBP + -0x10),*(int *)(unaff_EBP + 4));
  return;
}


// Unwind@27047840  @ 27047840
void Unwind_27047840(void)

{
  int unaff_EBP;
  
  FUN_2700a5d0(*(undefined4 *)(unaff_EBP + -0x10),*(int *)(unaff_EBP + 4));
  return;
}


// Unwind@27047860  @ 27047860
void Unwind_27047860(void)

{
  int unaff_EBP;
  
  FUN_2700a5d0(*(undefined4 *)(unaff_EBP + -0x10),*(int *)(unaff_EBP + 4));
  return;
}


// Unwind@27047880  @ 27047880
void Unwind_27047880(void)

{
  int unaff_EBP;
  
  FUN_2700a5d0(*(undefined4 *)(unaff_EBP + -0x10),*(int *)(unaff_EBP + 4));
  return;
}


// Unwind@270478a0  @ 270478a0
void Unwind_270478a0(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x134));
  return;
}


// Unwind@270478ae  @ 270478ae
void Unwind_270478ae(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x134));
  return;
}


// Unwind@270478bc  @ 270478bc
void Unwind_270478bc(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x134));
  return;
}


// Unwind@270478ca  @ 270478ca
void Unwind_270478ca(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x138));
  return;
}


// Unwind@270478d8  @ 270478d8
void Unwind_270478d8(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x138));
  return;
}


// Unwind@270478e6  @ 270478e6
void Unwind_270478e6(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x138));
  return;
}


// Unwind@270478f4  @ 270478f4
void Unwind_270478f4(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x138));
  return;
}


// Unwind@27047902  @ 27047902
void Unwind_27047902(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x138));
  return;
}


// Unwind@27047910  @ 27047910
void Unwind_27047910(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x14c));
  return;
}


// Unwind@2704791e  @ 2704791e
void Unwind_2704791e(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x138));
  return;
}


// Unwind@27047940  @ 27047940
void Unwind_27047940(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x110));
  return;
}


// Unwind@2704794e  @ 2704794e
void Unwind_2704794e(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x110));
  return;
}


// Unwind@27047970  @ 27047970
void Unwind_27047970(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 0xc));
  return;
}


// Unwind@2704797b  @ 2704797b
void Unwind_2704797b(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 0xc));
  return;
}


// Unwind@27047986  @ 27047986
void Unwind_27047986(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 0xc));
  return;
}


// Unwind@27047991  @ 27047991
void Unwind_27047991(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 0xc));
  return;
}


// Unwind@2704799c  @ 2704799c
void Unwind_2704799c(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 0xc));
  return;
}


// Unwind@270479a7  @ 270479a7
void Unwind_270479a7(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 0xc));
  return;
}


// Unwind@270479c0  @ 270479c0
void Unwind_270479c0(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@270479e0  @ 270479e0
void Unwind_270479e0(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@270479eb  @ 270479eb
void Unwind_270479eb(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 0x20));
  return;
}


// Unwind@270479f6  @ 270479f6
void Unwind_270479f6(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 0x20));
  return;
}


// Unwind@27047a01  @ 27047a01
void Unwind_27047a01(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 0x10));
  return;
}


// Unwind@27047a0c  @ 27047a0c
void Unwind_27047a0c(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 0x20));
  return;
}


// Unwind@27047a17  @ 27047a17
void Unwind_27047a17(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 0x10));
  return;
}


// Unwind@27047a30  @ 27047a30
void Unwind_27047a30(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x694));
  return;
}


// Unwind@27047a3e  @ 27047a3e
void Unwind_27047a3e(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x694));
  return;
}


// Unwind@27047a60  @ 27047a60
void Unwind_27047a60(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@27047a6b  @ 27047a6b
void Unwind_27047a6b(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@27047a76  @ 27047a76
void Unwind_27047a76(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 4));
  return;
}


// Unwind@27047a81  @ 27047a81
void Unwind_27047a81(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@27047a8c  @ 27047a8c
void Unwind_27047a8c(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@27047a97  @ 27047a97
void Unwind_27047a97(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@27047aa2  @ 27047aa2
void Unwind_27047aa2(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@27047aad  @ 27047aad
void Unwind_27047aad(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@27047ab8  @ 27047ab8
void Unwind_27047ab8(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@27047ac3  @ 27047ac3
void Unwind_27047ac3(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@27047ace  @ 27047ace
void Unwind_27047ace(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 4));
  return;
}


// Unwind@27047ad9  @ 27047ad9
void Unwind_27047ad9(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 0xc));
  return;
}


// Unwind@27047af0  @ 27047af0
void Unwind_27047af0(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@27047afb  @ 27047afb
void Unwind_27047afb(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@27047b06  @ 27047b06
void Unwind_27047b06(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@27047b11  @ 27047b11
void Unwind_27047b11(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@27047b1c  @ 27047b1c
void Unwind_27047b1c(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@27047b27  @ 27047b27
void Unwind_27047b27(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@27047b32  @ 27047b32
void Unwind_27047b32(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@27047b3d  @ 27047b3d
void Unwind_27047b3d(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 0xc));
  return;
}


// Unwind@27047b48  @ 27047b48
void Unwind_27047b48(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 0x10));
  return;
}


// Unwind@27047b53  @ 27047b53
void Unwind_27047b53(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 0x10));
  return;
}


// Unwind@27047b5e  @ 27047b5e
void Unwind_27047b5e(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 0x10));
  return;
}


// Unwind@27047b69  @ 27047b69
void Unwind_27047b69(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 0x10));
  return;
}


// Unwind@27047b80  @ 27047b80
void Unwind_27047b80(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@27047b8b  @ 27047b8b
void Unwind_27047b8b(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + 8));
  return;
}


// Unwind@27047ba0  @ 27047ba0
void Unwind_27047ba0(void)

{
  int unaff_EBP;
  
  FUN_2702f120((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x188));
  return;
}


// Unwind@27047bc0  @ 27047bc0
void Unwind_27047bc0(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x28));
  return;
}


// Unwind@27047bcb  @ 27047bcb
void Unwind_27047bcb(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x24));
  return;
}


// Unwind@27047bd6  @ 27047bd6
void Unwind_27047bd6(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x2c));
  return;
}


// Unwind@27047be1  @ 27047be1
void Unwind_27047be1(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x2c));
  return;
}


// Unwind@27047c00  @ 27047c00
void Unwind_27047c00(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x110));
  return;
}


// Unwind@27047c20  @ 27047c20
void Unwind_27047c20(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x210));
  return;
}


// Unwind@27047c2e  @ 27047c2e
void Unwind_27047c2e(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047c3c  @ 27047c3c
void Unwind_27047c3c(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047c4a  @ 27047c4a
void Unwind_27047c4a(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047c58  @ 27047c58
void Unwind_27047c58(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047c66  @ 27047c66
void Unwind_27047c66(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047c74  @ 27047c74
void Unwind_27047c74(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047c82  @ 27047c82
void Unwind_27047c82(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047c90  @ 27047c90
void Unwind_27047c90(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047c9e  @ 27047c9e
void Unwind_27047c9e(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047cac  @ 27047cac
void Unwind_27047cac(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047cba  @ 27047cba
void Unwind_27047cba(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047cc8  @ 27047cc8
void Unwind_27047cc8(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047cd6  @ 27047cd6
void Unwind_27047cd6(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047ce4  @ 27047ce4
void Unwind_27047ce4(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047cf2  @ 27047cf2
void Unwind_27047cf2(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047d00  @ 27047d00
void Unwind_27047d00(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047d0e  @ 27047d0e
void Unwind_27047d0e(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047d1c  @ 27047d1c
void Unwind_27047d1c(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047d2a  @ 27047d2a
void Unwind_27047d2a(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047d38  @ 27047d38
void Unwind_27047d38(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047d46  @ 27047d46
void Unwind_27047d46(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047d54  @ 27047d54
void Unwind_27047d54(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047d62  @ 27047d62
void Unwind_27047d62(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047d70  @ 27047d70
void Unwind_27047d70(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047d7e  @ 27047d7e
void Unwind_27047d7e(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047d8c  @ 27047d8c
void Unwind_27047d8c(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047d9a  @ 27047d9a
void Unwind_27047d9a(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047da8  @ 27047da8
void Unwind_27047da8(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047db6  @ 27047db6
void Unwind_27047db6(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047dc4  @ 27047dc4
void Unwind_27047dc4(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047dd2  @ 27047dd2
void Unwind_27047dd2(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x21c));
  return;
}


// Unwind@27047df0  @ 27047df0
void Unwind_27047df0(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27047e10  @ 27047e10
void Unwind_27047e10(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27047e30  @ 27047e30
void Unwind_27047e30(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27047e50  @ 27047e50
void Unwind_27047e50(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27047e70  @ 27047e70
void Unwind_27047e70(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x14));
  return;
}


// Unwind@27047e7b  @ 27047e7b
void Unwind_27047e7b(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27047e86  @ 27047e86
void Unwind_27047e86(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x10));
  return;
}


// Unwind@27047ea0  @ 27047ea0
void Unwind_27047ea0(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x11c));
  return;
}


// Unwind@27047eae  @ 27047eae
void Unwind_27047eae(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x128));
  return;
}


// Unwind@27047ebc  @ 27047ebc
void Unwind_27047ebc(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x128));
  return;
}


// Unwind@27047eca  @ 27047eca
void Unwind_27047eca(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x128));
  return;
}


// Unwind@27047ed8  @ 27047ed8
void Unwind_27047ed8(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x128));
  return;
}


// Unwind@27047ee6  @ 27047ee6
void Unwind_27047ee6(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x128));
  return;
}


// Unwind@27047ef4  @ 27047ef4
void Unwind_27047ef4(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x128));
  return;
}


// Unwind@27047f02  @ 27047f02
void Unwind_27047f02(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x128));
  return;
}


// Unwind@27047f10  @ 27047f10
void Unwind_27047f10(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x128));
  return;
}


// Unwind@27047f1e  @ 27047f1e
void Unwind_27047f1e(void)

{
  int unaff_EBP;
  
  FUN_2703b69b(*(undefined **)(unaff_EBP + -0x128));
  return;
}


// entry  @ 2703cc55
int entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2;
  iVar2 = DAT_270976d0;
  if (param_2 != 0) {
    if ((param_2 != 1) && (param_2 != 2)) goto LAB_2703cc9d;
    if ((DAT_27098d88 != (code *)0x0) &&
       (iVar2 = (*DAT_27098d88)(param_1,param_2,param_3), iVar2 == 0)) {
      return 0;
    }
    iVar2 = FUN_2703cb7c(param_1,param_2);
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_2703cc9d:
  iVar2 = FUN_27042237();
  if (param_2 == 1) {
    if (iVar2 != 0) {
      return iVar2;
    }
    FUN_2703cb7c(param_1,0);
  }
  if ((param_2 != 0) && (param_2 != 3)) {
    return iVar2;
  }
  iVar3 = FUN_2703cb7c(param_1,param_2);
  param_2 = iVar2;
  if (iVar3 == 0) {
    param_2 = 0;
  }
  if (param_2 != 0) {
    if (DAT_27098d88 != (code *)0x0) {
      iVar2 = (*DAT_27098d88)(param_1,iVar1,param_3);
      return iVar2;
    }
    return param_2;
  }
  return 0;
}


// vgui::ActionSignal::ActionSignal  @ 27011bd0
/* public: __thiscall vgui::ActionSignal::ActionSignal(void) */

void __thiscall vgui::ActionSignal::ActionSignal(ActionSignal *this)

{
                    /* 0x11bd0  38  ??0ActionSignal@vgui@@QAE@XZ */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::ActionSignal::ActionSignal  @ 27011c60
/* public: __thiscall vgui::ActionSignal::ActionSignal(class vgui::ActionSignal const &) */

void __thiscall vgui::ActionSignal::ActionSignal(ActionSignal *this,ActionSignal *param_1)

{
                    /* 0x11c60  37  ??0ActionSignal@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::ActionSignal::operator=  @ 2702df00
/* public: class vgui::ActionSignal & __thiscall vgui::ActionSignal::operator=(class
   vgui::ActionSignal const &) */

ActionSignal * __thiscall vgui::ActionSignal::operator=(ActionSignal *this,ActionSignal *param_1)

{
                    /* 0x2df00  98  ??4ActionSignal@vgui@@QAEAAV01@ABV01@@Z
                       0x2df00  116  ??4InputSignal@vgui@@QAEAAV01@ABV01@@Z
                       0x2df00  117  ??4InputStream@vgui@@QAEAAV01@ABV01@@Z
                       0x2df00  119  ??4Layout@vgui@@QAEAAV01@ABV01@@Z */
  return this;
}


// vgui::App::App  @ 270127e0
/* public: __thiscall vgui::App::App(class vgui::App const &) */

void __thiscall vgui::App::App(App *this,App *param_1)

{
  int iVar1;
  App *pAVar2;
  App *pAVar3;
  
                    /* 0x127e0  39  ??0App@vgui@@QAE@ABV01@@Z */
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


// vgui::App::operator=  @ 27012960
/* public: class vgui::App & __thiscall vgui::App::operator=(class vgui::App const &) */

App * __thiscall vgui::App::operator=(App *this,App *param_1)

{
  int iVar1;
  App *pAVar2;
  int iVar3;
  
                    /* 0x12960  99  ??4App@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::Bitmap::Bitmap  @ 27012180
/* public: __thiscall vgui::Bitmap::Bitmap(class vgui::Bitmap const &) */

void __thiscall vgui::Bitmap::Bitmap(Bitmap *this,Bitmap *param_1)

{
                    /* 0x12180  40  ??0Bitmap@vgui@@QAE@ABV01@@Z */
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


// vgui::Bitmap::operator=  @ 270121e0
/* public: class vgui::Bitmap & __thiscall vgui::Bitmap::operator=(class vgui::Bitmap const &) */

Bitmap * __thiscall vgui::Bitmap::operator=(Bitmap *this,Bitmap *param_1)

{
  Bitmap *pBVar1;
  int iVar2;
  
                    /* 0x121e0  100  ??4Bitmap@vgui@@QAEAAV01@ABV01@@Z
                       0x121e0  101  ??4BitmapTGA@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::BitmapTGA::BitmapTGA  @ 27012260
/* public: __thiscall vgui::BitmapTGA::BitmapTGA(class vgui::BitmapTGA const &) */

void __thiscall vgui::BitmapTGA::BitmapTGA(BitmapTGA *this,BitmapTGA *param_1)

{
                    /* 0x12260  41  ??0BitmapTGA@vgui@@QAE@ABV01@@Z */
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


// vgui::Border::Border  @ 27012b80
/* public: __thiscall vgui::Border::Border(class vgui::Border const &) */

void __thiscall vgui::Border::Border(Border *this,Border *param_1)

{
                    /* 0x12b80  42  ??0Border@vgui@@QAE@ABV01@@Z */
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


// vgui::Border::operator=  @ 27033a50
/* public: class vgui::Border & __thiscall vgui::Border::operator=(class vgui::Border const &) */

Border * __thiscall vgui::Border::operator=(Border *this,Border *param_1)

{
  int iVar1;
  Border *pBVar2;
  int iVar3;
  
                    /* 0x33a50  102  ??4Border@vgui@@QAEAAV01@ABV01@@Z
                       0x33a50  121  ??4LoweredBorder@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::BorderLayout::BorderLayout  @ 2702df10
/* public: __thiscall vgui::BorderLayout::BorderLayout(class vgui::BorderLayout const &) */

void __thiscall vgui::BorderLayout::BorderLayout(BorderLayout *this,BorderLayout *param_1)

{
  undefined4 uVar1;
  
                    /* 0x2df10  43  ??0BorderLayout@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &Layout::_vftable_;
  uVar1 = *(undefined4 *)(param_1 + 4);
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 4) = uVar1;
  return;
}


// vgui::BorderLayout::operator=  @ 27012b50
/* public: class vgui::BorderLayout & __thiscall vgui::BorderLayout::operator=(class
   vgui::BorderLayout const &) */

BorderLayout * __thiscall vgui::BorderLayout::operator=(BorderLayout *this,BorderLayout *param_1)

{
                    /* 0x12b50  103  ??4BorderLayout@vgui@@QAEAAV01@ABV01@@Z
                       0x12b50  110  ??4FileInputStream@vgui@@QAEAAV01@ABV01@@Z
                       0x12b50  123  ??4MiniApp@vgui@@QAEAAV01@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  return this;
}


// vgui::BuildGroup::BuildGroup  @ 27035bd0
/* public: __thiscall vgui::BuildGroup::BuildGroup(class vgui::BuildGroup const &) */

void __thiscall vgui::BuildGroup::BuildGroup(BuildGroup *this,BuildGroup *param_1)

{
  undefined4 uVar1;
  
                    /* 0x35bd0  44  ??0BuildGroup@vgui@@QAE@ABV01@@Z */
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


// vgui::BuildGroup::operator=  @ 27035c90
/* public: class vgui::BuildGroup & __thiscall vgui::BuildGroup::operator=(class vgui::BuildGroup
   const &) */

BuildGroup * __thiscall vgui::BuildGroup::operator=(BuildGroup *this,BuildGroup *param_1)

{
  BuildGroup *pBVar1;
  int iVar2;
  
                    /* 0x35c90  104  ??4BuildGroup@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::Button::Button  @ 27011620
/* public: __thiscall vgui::Button::Button(class vgui::Button const &) */

void __thiscall vgui::Button::Button(Button *this,Button *param_1)

{
                    /* 0x11620  45  ??0Button@vgui@@QAE@ABV01@@Z */
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


// vgui::Button::operator=  @ 270118a0
/* public: class vgui::Button & __thiscall vgui::Button::operator=(class vgui::Button const &) */

Button * __thiscall vgui::Button::operator=(Button *this,Button *param_1)

{
  int iVar1;
  Button *pBVar2;
  int iVar3;
  
                    /* 0x118a0  105  ??4Button@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::Color::Color  @ 27010340
/* public: __thiscall vgui::Color::Color(class vgui::Color const &) */

void __thiscall vgui::Color::Color(Color *this,Color *param_1)

{
                    /* 0x10340  46  ??0Color@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Color::operator=  @ 27010360
/* public: class vgui::Color & __thiscall vgui::Color::operator=(class vgui::Color const &) */

Color * __thiscall vgui::Color::operator=(Color *this,Color *param_1)

{
  Color *pCVar1;
  
                    /* 0x10360  106  ??4Color@vgui@@QAEAAV01@ABV01@@Z */
  pCVar1 = this + 4;
  do {
    *pCVar1 = pCVar1[(int)param_1 - (int)this];
    pCVar1 = pCVar1 + 1;
  } while (pCVar1 + (-4 - (int)this) < (Color *)0x4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  return this;
}


// vgui::Cursor::Cursor  @ 27012750
/* public: __thiscall vgui::Cursor::Cursor(class vgui::Cursor const &) */

void __thiscall vgui::Cursor::Cursor(Cursor *this,Cursor *param_1)

{
                    /* 0x12750  47  ??0Cursor@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Cursor::operator=  @ 270127a0
/* public: class vgui::Cursor & __thiscall vgui::Cursor::operator=(class vgui::Cursor const &) */

Cursor * __thiscall vgui::Cursor::operator=(Cursor *this,Cursor *param_1)

{
  int iVar1;
  Cursor *pCVar2;
  
                    /* 0x127a0  107  ??4Cursor@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::Dar<char>::Dar<char>  @ 27011be0
/* public: __thiscall vgui::Dar<char>::Dar<char>(void) */

Dar<char> * __thiscall vgui::Dar<char>::Dar<char>(Dar<char> *this)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
                    /* 0x11be0  2  ??0?$Dar@D@vgui@@QAE@XZ */
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
    FUN_2703b6d3(0);
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
  FUN_2703b69b(*(undefined **)(this + 8));
  *(undefined4 **)(this + 8) = puVar2;
  return this;
}


// vgui::Dar<char>::Dar<char>  @ 27011c70
/* public: __thiscall vgui::Dar<char>::Dar<char>(int) */

Dar<char> * __thiscall vgui::Dar<char>::Dar<char>(Dar<char> *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  
                    /* 0x11c70  1  ??0?$Dar@D@vgui@@QAE@H@Z */
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
      FUN_2703b6d3(0);
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
    FUN_2703b69b(*(undefined **)(this + 8));
    *(undefined4 **)(this + 8) = puVar1;
  }
  return this;
}


// vgui::Dar<char>::addElement  @ 27011e80
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
  
                    /* 0x11e80  220  ?addElement@?$Dar@D@vgui@@QAEXD@Z */
  uVar5 = *(uint *)(this + 4);
  if ((int)uVar5 < *(int *)this + 1) {
    if (uVar5 == 0) {
      uVar5 = 1;
    }
    for (; (int)uVar5 < *(int *)this + 1; uVar5 = uVar5 * 2) {
    }
    puVar1 = operator_new(uVar5);
    if (puVar1 == (undefined4 *)0x0) {
      FUN_2703b6d3(0);
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
    FUN_2703b69b(*(undefined **)(this + 8));
    *(undefined4 **)(this + 8) = puVar1;
  }
  *(undefined1 *)(*(int *)(this + 8) + *(int *)this) = unaff_retaddr;
  *(int *)this = *(int *)this + 1;
  return;
}


// vgui::Dar<char>::ensureCapacity  @ 27011d20
/* public: void __thiscall vgui::Dar<char>::ensureCapacity(int) */

void __thiscall vgui::Dar<char>::ensureCapacity(Dar<char> *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  
                    /* 0x11d20  238  ?ensureCapacity@?$Dar@D@vgui@@QAEXH@Z */
  uVar5 = *(uint *)(this + 4);
  if ((int)uVar5 < param_1) {
    if (uVar5 == 0) {
      uVar5 = 1;
    }
    for (; (int)uVar5 < param_1; uVar5 = uVar5 * 2) {
    }
    puVar1 = operator_new(uVar5);
    if (puVar1 == (undefined4 *)0x0) {
      FUN_2703b6d3(0);
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
    FUN_2703b69b(*(undefined **)(this + 8));
    *(undefined4 **)(this + 8) = puVar1;
  }
  return;
}


// vgui::Dar<char>::getCount  @ 27013ce0
/* public: int __thiscall vgui::Dar<char>::getCount(void) */

int __thiscall vgui::Dar<char>::getCount(Dar<char> *this)

{
                    /* 0x13ce0  256  ?getCount@?$Dar@D@vgui@@QAEHXZ
                       0x13ce0  257  ?getCount@?$Dar@H@vgui@@QAEHXZ
                       0x13ce0  258  ?getCount@?$Dar@PAD@vgui@@QAEHXZ
                       0x13ce0  259  ?getCount@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEHXZ
                       0x13ce0  260  ?getCount@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEHXZ
                       0x13ce0  261  ?getCount@?$Dar@PAVButton@vgui@@@vgui@@QAEHXZ
                       0x13ce0  262  ?getCount@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEHXZ
                       0x13ce0  263  ?getCount@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEHXZ
                       0x13ce0  264  ?getCount@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEHXZ
                       0x13ce0  265  ?getCount@?$Dar@PAVFrame@vgui@@@vgui@@QAEHXZ
                       0x13ce0  266  ?getCount@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEHXZ
                       0x13ce0  267  ?getCount@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEHXZ
                       0x13ce0  268  ?getCount@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEHXZ
                       0x13ce0  269  ?getCount@?$Dar@PAVLabel@vgui@@@vgui@@QAEHXZ
                       0x13ce0  270  ?getCount@?$Dar@PAVPanel@vgui@@@vgui@@QAEHXZ
                       0x13ce0  271  ?getCount@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEHXZ
                       0x13ce0  272  ?getCount@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEHXZ
                       0x13ce0  273  ?getCount@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEHXZ */
  return *(int *)this;
}


// vgui::Dar<char>::hasElement  @ 27011f20
/* public: bool __thiscall vgui::Dar<char>::hasElement(char) */

bool __thiscall vgui::Dar<char>::hasElement(Dar<char> *this,char param_1)

{
  int iVar1;
  
                    /* 0x11f20  274  ?hasElement@?$Dar@D@vgui@@QAE_ND@Z */
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


// vgui::Dar<char>::insertElementAt  @ 27012020
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
  
                    /* 0x12020  292  ?insertElementAt@?$Dar@D@vgui@@QAEXDH@Z */
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
            FUN_2703b6d3(0);
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
          FUN_2703b69b(*(undefined **)(this + 8));
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
          FUN_2703b6d3(0);
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
        FUN_2703b69b(*(undefined **)(this + 8));
        *(undefined4 **)(this + 8) = puVar1;
      }
      *(undefined1 *)(*(int *)(this + 8) + *(int *)this) = unaff_retaddr;
      *(int *)this = *(int *)this + 1;
    }
  }
  return;
}


// vgui::Dar<char>::operator=  @ 2700fda0
/* public: class vgui::Dar<char> & __thiscall vgui::Dar<char>::operator=(class vgui::Dar<char> const
   &) */

Dar<char> * __thiscall vgui::Dar<char>::operator=(Dar<char> *this,Dar<char> *param_1)

{
                    /* 0xfda0  80  ??4?$Dar@D@vgui@@QAEAAV01@ABV01@@Z
                       0xfda0  81  ??4?$Dar@H@vgui@@QAEAAV01@ABV01@@Z
                       0xfda0  82  ??4?$Dar@PAD@vgui@@QAEAAV01@ABV01@@Z
                       0xfda0  83  ??4?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0xfda0  84  ??4?$Dar@PAVActionSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0xfda0  85  ??4?$Dar@PAVButton@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0xfda0  86  ??4?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0xfda0  87  ??4?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0xfda0  88  ??4?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0xfda0  89  ??4?$Dar@PAVFrame@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0xfda0  90  ??4?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0xfda0  91  ??4?$Dar@PAVInputSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0xfda0  92  ??4?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0xfda0  93  ??4?$Dar@PAVLabel@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0xfda0  94  ??4?$Dar@PAVPanel@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0xfda0  95  ??4?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0xfda0  96  ??4?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEAAV01@ABV01@@Z
                       0xfda0  97  ??4?$Dar@PAVTickSignal@vgui@@@vgui@@QAEAAV01@ABV01@@Z */
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  return this;
}


// vgui::Dar<char>::operator[]  @ 27012780
/* public: char __thiscall vgui::Dar<char>::operator[](int) */

char __thiscall vgui::Dar<char>::operator[](Dar<char> *this,int param_1)

{
                    /* 0x12780  138  ??A?$Dar@D@vgui@@QAEDH@Z */
  if ((-1 < param_1) && (param_1 < *(int *)this)) {
    return *(char *)(*(int *)(this + 8) + param_1);
  }
  return '\0';
}


// vgui::Dar<char>::putElement  @ 27011f70
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
  
                    /* 0x11f70  310  ?putElement@?$Dar@D@vgui@@QAEXD@Z */
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
      FUN_2703b6d3(0);
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
    FUN_2703b69b(*(undefined **)(this + 8));
    *(undefined4 **)(this + 8) = puVar2;
  }
  *(undefined1 *)(*(int *)(this + 8) + *(int *)this) = unaff_retaddr;
  *(int *)this = *(int *)this + 1;
  return;
}


// vgui::Dar<char>::removeAll  @ 27013fd0
/* public: void __thiscall vgui::Dar<char>::removeAll(void) */

void __thiscall vgui::Dar<char>::removeAll(Dar<char> *this)

{
                    /* 0x13fd0  328  ?removeAll@?$Dar@D@vgui@@QAEXXZ
                       0x13fd0  329  ?removeAll@?$Dar@H@vgui@@QAEXXZ
                       0x13fd0  330  ?removeAll@?$Dar@PAD@vgui@@QAEXXZ
                       0x13fd0  331  ?removeAll@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXXZ
                       0x13fd0  332  ?removeAll@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXXZ
                       0x13fd0  333  ?removeAll@?$Dar@PAVButton@vgui@@@vgui@@QAEXXZ
                       0x13fd0  334  ?removeAll@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXXZ
                       0x13fd0  335  ?removeAll@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXXZ
                       0x13fd0  336  ?removeAll@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXXZ
                       0x13fd0  337  ?removeAll@?$Dar@PAVFrame@vgui@@@vgui@@QAEXXZ
                       0x13fd0  338  ?removeAll@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXXZ
                       0x13fd0  339  ?removeAll@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXXZ
                       0x13fd0  340  ?removeAll@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXXZ
                       0x13fd0  341  ?removeAll@?$Dar@PAVLabel@vgui@@@vgui@@QAEXXZ
                       0x13fd0  342  ?removeAll@?$Dar@PAVPanel@vgui@@@vgui@@QAEXXZ
                       0x13fd0  343  ?removeAll@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXXZ
                       0x13fd0  344  ?removeAll@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXXZ
                       0x13fd0  345  ?removeAll@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEXXZ */
  *(undefined4 *)this = 0;
  return;
}


// vgui::Dar<char>::removeElement  @ 270124f0
/* public: void __thiscall vgui::Dar<char>::removeElement(char) */

void __thiscall vgui::Dar<char>::removeElement(Dar<char> *this,char param_1)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x124f0  346  ?removeElement@?$Dar@D@vgui@@QAEXD@Z */
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


// vgui::Dar<char>::removeElementAt  @ 270122e0
/* public: void __thiscall vgui::Dar<char>::removeElementAt(int) */

void __thiscall vgui::Dar<char>::removeElementAt(Dar<char> *this,int param_1)

{
  undefined1 *puVar1;
  
                    /* 0x122e0  364  ?removeElementAt@?$Dar@D@vgui@@QAEXH@Z */
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


// vgui::Dar<char>::setCount  @ 27011e50
/* public: void __thiscall vgui::Dar<char>::setCount(int) */

void __thiscall vgui::Dar<char>::setCount(Dar<char> *this,int param_1)

{
                    /* 0x11e50  382  ?setCount@?$Dar@D@vgui@@QAEXH@Z
                       0x11e50  383  ?setCount@?$Dar@H@vgui@@QAEXH@Z
                       0x11e50  384  ?setCount@?$Dar@PAD@vgui@@QAEXH@Z
                       0x11e50  385  ?setCount@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXH@Z
                       0x11e50  386  ?setCount@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXH@Z
                       0x11e50  387  ?setCount@?$Dar@PAVButton@vgui@@@vgui@@QAEXH@Z
                       0x11e50  388  ?setCount@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x11e50  389  ?setCount@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXH@Z
                       0x11e50  390  ?setCount@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x11e50  391  ?setCount@?$Dar@PAVFrame@vgui@@@vgui@@QAEXH@Z
                       0x11e50  392  ?setCount@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXH@Z
                       0x11e50  393  ?setCount@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXH@Z
                       0x11e50  394  ?setCount@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x11e50  395  ?setCount@?$Dar@PAVLabel@vgui@@@vgui@@QAEXH@Z
                       0x11e50  396  ?setCount@?$Dar@PAVPanel@vgui@@@vgui@@QAEXH@Z
                       0x11e50  397  ?setCount@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXH@Z
                       0x11e50  398  ?setCount@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXH@Z
                       0x11e50  399  ?setCount@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEXH@Z */
  if ((-1 < param_1) && (param_1 <= *(int *)(this + 4))) {
    *(int *)this = param_1;
  }
  return;
}


// vgui::Dar<char>::setElementAt  @ 270122c0
/* public: void __thiscall vgui::Dar<char>::setElementAt(char,int) */

void __thiscall vgui::Dar<char>::setElementAt(Dar<char> *this,char param_1,int param_2)

{
                    /* 0x122c0  400  ?setElementAt@?$Dar@D@vgui@@QAEXDH@Z */
  if ((-1 < param_2) && (param_2 < *(int *)this)) {
    *(char *)(*(int *)(this + 8) + param_2) = param_1;
  }
  return;
}


// vgui::Dar<int>::Dar<int>  @ 27013d40
/* public: __thiscall vgui::Dar<int>::Dar<int>(void) */

Dar<int> * __thiscall vgui::Dar<int>::Dar<int>(Dar<int> *this)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
                    /* 0x13d40  4  ??0?$Dar@H@vgui@@QAE@XZ
                       0x13d40  6  ??0?$Dar@PAD@vgui@@QAE@XZ
                       0x13d40  8  ??0?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAE@XZ
                       0x13d40  10  ??0?$Dar@PAVActionSignal@vgui@@@vgui@@QAE@XZ
                       0x13d40  12  ??0?$Dar@PAVButton@vgui@@@vgui@@QAE@XZ
                       0x13d40  14  ??0?$Dar@PAVChangeSignal@vgui@@@vgui@@QAE@XZ
                       0x13d40  16  ??0?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAE@XZ
                       0x13d40  18  ??0?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAE@XZ
                       0x13d40  20  ??0?$Dar@PAVFrame@vgui@@@vgui@@QAE@XZ
                       0x13d40  22  ??0?$Dar@PAVFrameSignal@vgui@@@vgui@@QAE@XZ
                       0x13d40  24  ??0?$Dar@PAVInputSignal@vgui@@@vgui@@QAE@XZ
                       0x13d40  26  ??0?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAE@XZ
                       0x13d40  28  ??0?$Dar@PAVLabel@vgui@@@vgui@@QAE@XZ
                       0x13d40  30  ??0?$Dar@PAVPanel@vgui@@@vgui@@QAE@XZ
                       0x13d40  32  ??0?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAE@XZ
                       0x13d40  34  ??0?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAE@XZ
                       0x13d40  36  ??0?$Dar@PAVTickSignal@vgui@@@vgui@@QAE@XZ */
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
    FUN_2703b6d3(0);
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
  FUN_2703b69b(*(undefined **)(this + 8));
  *(undefined4 **)(this + 8) = puVar2;
  return this;
}


// vgui::Dar<int>::Dar<int>  @ 27013fe0
/* public: __thiscall vgui::Dar<int>::Dar<int>(int) */

Dar<int> * __thiscall vgui::Dar<int>::Dar<int>(Dar<int> *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
                    /* 0x13fe0  3  ??0?$Dar@H@vgui@@QAE@H@Z
                       0x13fe0  5  ??0?$Dar@PAD@vgui@@QAE@H@Z
                       0x13fe0  7  ??0?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAE@H@Z
                       0x13fe0  9  ??0?$Dar@PAVActionSignal@vgui@@@vgui@@QAE@H@Z
                       0x13fe0  11  ??0?$Dar@PAVButton@vgui@@@vgui@@QAE@H@Z
                       0x13fe0  13  ??0?$Dar@PAVChangeSignal@vgui@@@vgui@@QAE@H@Z
                       0x13fe0  15  ??0?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAE@H@Z
                       0x13fe0  17  ??0?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAE@H@Z
                       0x13fe0  19  ??0?$Dar@PAVFrame@vgui@@@vgui@@QAE@H@Z
                       0x13fe0  21  ??0?$Dar@PAVFrameSignal@vgui@@@vgui@@QAE@H@Z
                       0x13fe0  23  ??0?$Dar@PAVInputSignal@vgui@@@vgui@@QAE@H@Z
                       0x13fe0  25  ??0?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAE@H@Z
                       0x13fe0  27  ??0?$Dar@PAVLabel@vgui@@@vgui@@QAE@H@Z
                       0x13fe0  29  ??0?$Dar@PAVPanel@vgui@@@vgui@@QAE@H@Z
                       0x13fe0  31  ??0?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAE@H@Z
                       0x13fe0  33  ??0?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAE@H@Z
                       0x13fe0  35  ??0?$Dar@PAVTickSignal@vgui@@@vgui@@QAE@H@Z */
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
      FUN_2703b6d3(0);
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
    FUN_2703b69b(*(undefined **)(this + 8));
    *(undefined4 **)(this + 8) = puVar1;
  }
  return this;
}


// vgui::Dar<int>::addElement  @ 27013f30
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
  
                    /* 0x13f30  221  ?addElement@?$Dar@H@vgui@@QAEXH@Z
                       0x13f30  222  ?addElement@?$Dar@PAD@vgui@@QAEXPAD@Z
                       0x13f30  223  ?addElement@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXPAV?$Dar@D@2@@Z
                       0x13f30  224
                       ?addElement@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXPAVActionSignal@2@@Z
                       0x13f30  225  ?addElement@?$Dar@PAVButton@vgui@@@vgui@@QAEXPAVButton@2@@Z
                       0x13f30  226
                       ?addElement@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXPAVChangeSignal@2@@Z
                       0x13f30  227
                       ?addElement@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXPAVDesktopIcon@2@@Z
                       0x13f30  228
                       ?addElement@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXPAVFocusChangeSignal@2@@Z
                       0x13f30  229  ?addElement@?$Dar@PAVFrame@vgui@@@vgui@@QAEXPAVFrame@2@@Z
                       0x13f30  230
                       ?addElement@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXPAVFrameSignal@2@@Z
                       0x13f30  231
                       ?addElement@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXPAVInputSignal@2@@Z
                       0x13f30  232
                       ?addElement@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXPAVIntChangeSignal@2@@Z
                       0x13f30  233  ?addElement@?$Dar@PAVLabel@vgui@@@vgui@@QAEXPAVLabel@2@@Z
                       0x13f30  234  ?addElement@?$Dar@PAVPanel@vgui@@@vgui@@QAEXPAVPanel@2@@Z
                       0x13f30  235
                       ?addElement@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXPAVRepaintSignal@2@@Z
                       0x13f30  236
                       ?addElement@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXPAVSurfaceBase@2@@Z
                       0x13f30  237
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
      FUN_2703b6d3(0);
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
    FUN_2703b69b(*(undefined **)(this + 8));
    *(undefined4 **)(this + 8) = puVar1;
  }
  *(undefined4 *)(*(int *)(this + 8) + *(int *)this * 4) = unaff_retaddr;
  *(int *)this = *(int *)this + 1;
  return;
}


// vgui::Dar<int>::ensureCapacity  @ 27012bf0
/* public: void __thiscall vgui::Dar<int>::ensureCapacity(int) */

void __thiscall vgui::Dar<int>::ensureCapacity(Dar<int> *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
                    /* 0x12bf0  239  ?ensureCapacity@?$Dar@H@vgui@@QAEXH@Z
                       0x12bf0  240  ?ensureCapacity@?$Dar@PAD@vgui@@QAEXH@Z
                       0x12bf0  241  ?ensureCapacity@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXH@Z
                       0x12bf0  242  ?ensureCapacity@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXH@Z
                       0x12bf0  243  ?ensureCapacity@?$Dar@PAVButton@vgui@@@vgui@@QAEXH@Z
                       0x12bf0  244  ?ensureCapacity@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x12bf0  245  ?ensureCapacity@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXH@Z
                       0x12bf0  246  ?ensureCapacity@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x12bf0  247  ?ensureCapacity@?$Dar@PAVFrame@vgui@@@vgui@@QAEXH@Z
                       0x12bf0  248  ?ensureCapacity@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXH@Z
                       0x12bf0  249  ?ensureCapacity@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXH@Z
                       0x12bf0  250  ?ensureCapacity@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x12bf0  251  ?ensureCapacity@?$Dar@PAVLabel@vgui@@@vgui@@QAEXH@Z
                       0x12bf0  252  ?ensureCapacity@?$Dar@PAVPanel@vgui@@@vgui@@QAEXH@Z
                       0x12bf0  253  ?ensureCapacity@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXH@Z
                       0x12bf0  254  ?ensureCapacity@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXH@Z
                       0x12bf0  255  ?ensureCapacity@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEXH@Z */
  uVar5 = *(uint *)(this + 4);
  if ((int)uVar5 < param_1) {
    if (uVar5 == 0) {
      uVar5 = 1;
    }
    for (; (int)uVar5 < param_1; uVar5 = uVar5 * 2) {
    }
    puVar1 = operator_new(uVar5 * 4);
    if (puVar1 == (undefined4 *)0x0) {
      FUN_2703b6d3(0);
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
    FUN_2703b69b(*(undefined **)(this + 8));
    *(undefined4 **)(this + 8) = puVar1;
  }
  return;
}


// vgui::Dar<int>::hasElement  @ 27013c80
/* public: bool __thiscall vgui::Dar<int>::hasElement(int) */

bool __thiscall vgui::Dar<int>::hasElement(Dar<int> *this,int param_1)

{
  int iVar1;
  int *piVar2;
  
                    /* 0x13c80  275  ?hasElement@?$Dar@H@vgui@@QAE_NH@Z
                       0x13c80  276  ?hasElement@?$Dar@PAD@vgui@@QAE_NPAD@Z
                       0x13c80  277  ?hasElement@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAE_NPAV?$Dar@D@2@@Z
                       0x13c80  278
                       ?hasElement@?$Dar@PAVActionSignal@vgui@@@vgui@@QAE_NPAVActionSignal@2@@Z
                       0x13c80  279  ?hasElement@?$Dar@PAVButton@vgui@@@vgui@@QAE_NPAVButton@2@@Z
                       0x13c80  280
                       ?hasElement@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAE_NPAVChangeSignal@2@@Z
                       0x13c80  281
                       ?hasElement@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAE_NPAVDesktopIcon@2@@Z
                       0x13c80  282
                       ?hasElement@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAE_NPAVFocusChangeSignal@2@@Z
                       0x13c80  283  ?hasElement@?$Dar@PAVFrame@vgui@@@vgui@@QAE_NPAVFrame@2@@Z
                       0x13c80  284
                       ?hasElement@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAE_NPAVFrameSignal@2@@Z
                       0x13c80  285
                       ?hasElement@?$Dar@PAVInputSignal@vgui@@@vgui@@QAE_NPAVInputSignal@2@@Z
                       0x13c80  286
                       ?hasElement@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAE_NPAVIntChangeSignal@2@@Z
                       0x13c80  287  ?hasElement@?$Dar@PAVLabel@vgui@@@vgui@@QAE_NPAVLabel@2@@Z
                       0x13c80  288  ?hasElement@?$Dar@PAVPanel@vgui@@@vgui@@QAE_NPAVPanel@2@@Z
                       0x13c80  289
                       ?hasElement@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAE_NPAVRepaintSignal@2@@Z
                       0x13c80  290
                       ?hasElement@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAE_NPAVSurfaceBase@2@@Z
                       0x13c80  291
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


// vgui::Dar<int>::insertElementAt  @ 27013dc0
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
  
                    /* 0x13dc0  293  ?insertElementAt@?$Dar@H@vgui@@QAEXHH@Z
                       0x13dc0  294  ?insertElementAt@?$Dar@PAD@vgui@@QAEXPADH@Z
                       0x13dc0  295
                       ?insertElementAt@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXPAV?$Dar@D@2@H@Z
                       0x13dc0  296
                       ?insertElementAt@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXPAVActionSignal@2@H@Z
                       0x13dc0  297
                       ?insertElementAt@?$Dar@PAVButton@vgui@@@vgui@@QAEXPAVButton@2@H@Z
                       0x13dc0  298
                       ?insertElementAt@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXPAVChangeSignal@2@H@Z
                       0x13dc0  299
                       ?insertElementAt@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXPAVDesktopIcon@2@H@Z
                       0x13dc0  300
                       ?insertElementAt@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXPAVFocusChangeSignal@2@H@Z
                       0x13dc0  301  ?insertElementAt@?$Dar@PAVFrame@vgui@@@vgui@@QAEXPAVFrame@2@H@Z
                       0x13dc0  302
                       ?insertElementAt@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXPAVFrameSignal@2@H@Z
                       0x13dc0  303
                       ?insertElementAt@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXPAVInputSignal@2@H@Z
                       0x13dc0  304
                       ?insertElementAt@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXPAVIntChangeSignal@2@H@Z
                       0x13dc0  305  ?insertElementAt@?$Dar@PAVLabel@vgui@@@vgui@@QAEXPAVLabel@2@H@Z
                       0x13dc0  306  ?insertElementAt@?$Dar@PAVPanel@vgui@@@vgui@@QAEXPAVPanel@2@H@Z
                       0x13dc0  307
                       ?insertElementAt@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXPAVRepaintSignal@2@H@Z
                       0x13dc0  308
                       ?insertElementAt@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXPAVSurfaceBase@2@H@Z
                       0x13dc0  309
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
            FUN_2703b6d3(0);
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
          FUN_2703b69b(*(undefined **)(this + 8));
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
          FUN_2703b6d3(0);
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
        FUN_2703b69b(*(undefined **)(this + 8));
        *(undefined4 **)(this + 8) = puVar1;
      }
      *(undefined4 *)(*(int *)(this + 8) + *(int *)this * 4) = unaff_retaddr;
      *(int *)this = *(int *)this + 1;
    }
  }
  return;
}


// vgui::Dar<int>::operator[]  @ 27012b60
/* public: int __thiscall vgui::Dar<int>::operator[](int) */

int __thiscall vgui::Dar<int>::operator[](Dar<int> *this,int param_1)

{
                    /* 0x12b60  139  ??A?$Dar@H@vgui@@QAEHH@Z
                       0x12b60  140  ??A?$Dar@PAD@vgui@@QAEPADH@Z
                       0x12b60  141  ??A?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEPAV?$Dar@D@1@H@Z
                       0x12b60  142  ??A?$Dar@PAVActionSignal@vgui@@@vgui@@QAEPAVActionSignal@1@H@Z
                       0x12b60  143  ??A?$Dar@PAVButton@vgui@@@vgui@@QAEPAVButton@1@H@Z
                       0x12b60  144  ??A?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEPAVChangeSignal@1@H@Z
                       0x12b60  145  ??A?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEPAVDesktopIcon@1@H@Z
                       0x12b60  146
                       ??A?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEPAVFocusChangeSignal@1@H@Z
                       0x12b60  147  ??A?$Dar@PAVFrame@vgui@@@vgui@@QAEPAVFrame@1@H@Z
                       0x12b60  148  ??A?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEPAVFrameSignal@1@H@Z
                       0x12b60  149  ??A?$Dar@PAVInputSignal@vgui@@@vgui@@QAEPAVInputSignal@1@H@Z
                       0x12b60  150
                       ??A?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEPAVIntChangeSignal@1@H@Z
                       0x12b60  151  ??A?$Dar@PAVLabel@vgui@@@vgui@@QAEPAVLabel@1@H@Z
                       0x12b60  152  ??A?$Dar@PAVPanel@vgui@@@vgui@@QAEPAVPanel@1@H@Z
                       0x12b60  153
                       ??A?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEPAVRepaintSignal@1@H@Z
                       0x12b60  154  ??A?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEPAVSurfaceBase@1@H@Z
                       0x12b60  155  ??A?$Dar@PAVTickSignal@vgui@@@vgui@@QAEPAVTickSignal@1@H@Z */
  if ((-1 < param_1) && (param_1 < *(int *)this)) {
    return *(int *)(*(int *)(this + 8) + param_1 * 4);
  }
  return 0;
}


// vgui::Dar<int>::putElement  @ 27013bc0
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
  
                    /* 0x13bc0  311  ?putElement@?$Dar@H@vgui@@QAEXH@Z
                       0x13bc0  312  ?putElement@?$Dar@PAD@vgui@@QAEXPAD@Z
                       0x13bc0  313  ?putElement@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXPAV?$Dar@D@2@@Z
                       0x13bc0  314
                       ?putElement@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXPAVActionSignal@2@@Z
                       0x13bc0  315  ?putElement@?$Dar@PAVButton@vgui@@@vgui@@QAEXPAVButton@2@@Z
                       0x13bc0  316
                       ?putElement@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXPAVChangeSignal@2@@Z
                       0x13bc0  317
                       ?putElement@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXPAVDesktopIcon@2@@Z
                       0x13bc0  318
                       ?putElement@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXPAVFocusChangeSignal@2@@Z
                       0x13bc0  319  ?putElement@?$Dar@PAVFrame@vgui@@@vgui@@QAEXPAVFrame@2@@Z
                       0x13bc0  320
                       ?putElement@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXPAVFrameSignal@2@@Z
                       0x13bc0  321
                       ?putElement@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXPAVInputSignal@2@@Z
                       0x13bc0  322
                       ?putElement@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXPAVIntChangeSignal@2@@Z
                       0x13bc0  323  ?putElement@?$Dar@PAVLabel@vgui@@@vgui@@QAEXPAVLabel@2@@Z
                       0x13bc0  324  ?putElement@?$Dar@PAVPanel@vgui@@@vgui@@QAEXPAVPanel@2@@Z
                       0x13bc0  325
                       ?putElement@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXPAVRepaintSignal@2@@Z
                       0x13bc0  326
                       ?putElement@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXPAVSurfaceBase@2@@Z
                       0x13bc0  327
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
      FUN_2703b6d3(0);
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
    FUN_2703b69b(*(undefined **)(this + 8));
    *(undefined4 **)(this + 8) = puVar1;
  }
  *(undefined4 *)(*(int *)(this + 8) + *(int *)this * 4) = unaff_retaddr;
  *(int *)this = *(int *)this + 1;
  return;
}


// vgui::Dar<int>::removeElement  @ 27013cf0
/* public: void __thiscall vgui::Dar<int>::removeElement(int) */

void __thiscall vgui::Dar<int>::removeElement(Dar<int> *this,int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
                    /* 0x13cf0  347  ?removeElement@?$Dar@H@vgui@@QAEXH@Z
                       0x13cf0  348  ?removeElement@?$Dar@PAD@vgui@@QAEXPAD@Z
                       0x13cf0  349
                       ?removeElement@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXPAV?$Dar@D@2@@Z
                       0x13cf0  350
                       ?removeElement@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXPAVActionSignal@2@@Z
                       0x13cf0  351  ?removeElement@?$Dar@PAVButton@vgui@@@vgui@@QAEXPAVButton@2@@Z
                       0x13cf0  352
                       ?removeElement@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXPAVChangeSignal@2@@Z
                       0x13cf0  353
                       ?removeElement@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXPAVDesktopIcon@2@@Z
                       0x13cf0  354
                       ?removeElement@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXPAVFocusChangeSignal@2@@Z
                       0x13cf0  355  ?removeElement@?$Dar@PAVFrame@vgui@@@vgui@@QAEXPAVFrame@2@@Z
                       0x13cf0  356
                       ?removeElement@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXPAVFrameSignal@2@@Z
                       0x13cf0  357
                       ?removeElement@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXPAVInputSignal@2@@Z
                       0x13cf0  358
                       ?removeElement@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXPAVIntChangeSignal@2@@Z
                       0x13cf0  359  ?removeElement@?$Dar@PAVLabel@vgui@@@vgui@@QAEXPAVLabel@2@@Z
                       0x13cf0  360  ?removeElement@?$Dar@PAVPanel@vgui@@@vgui@@QAEXPAVPanel@2@@Z
                       0x13cf0  361
                       ?removeElement@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXPAVRepaintSignal@2@@Z
                       0x13cf0  362
                       ?removeElement@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXPAVSurfaceBase@2@@Z
                       0x13cf0  363
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


// vgui::Dar<int>::removeElementAt  @ 27013cb0
/* public: void __thiscall vgui::Dar<int>::removeElementAt(int) */

void __thiscall vgui::Dar<int>::removeElementAt(Dar<int> *this,int param_1)

{
                    /* 0x13cb0  365  ?removeElementAt@?$Dar@H@vgui@@QAEXH@Z
                       0x13cb0  366  ?removeElementAt@?$Dar@PAD@vgui@@QAEXH@Z
                       0x13cb0  367  ?removeElementAt@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXH@Z
                       0x13cb0  368  ?removeElementAt@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXH@Z
                       0x13cb0  369  ?removeElementAt@?$Dar@PAVButton@vgui@@@vgui@@QAEXH@Z
                       0x13cb0  370  ?removeElementAt@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x13cb0  371  ?removeElementAt@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXH@Z
                       0x13cb0  372
                       ?removeElementAt@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x13cb0  373  ?removeElementAt@?$Dar@PAVFrame@vgui@@@vgui@@QAEXH@Z
                       0x13cb0  374  ?removeElementAt@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXH@Z
                       0x13cb0  375  ?removeElementAt@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXH@Z
                       0x13cb0  376  ?removeElementAt@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXH@Z
                       0x13cb0  377  ?removeElementAt@?$Dar@PAVLabel@vgui@@@vgui@@QAEXH@Z
                       0x13cb0  378  ?removeElementAt@?$Dar@PAVPanel@vgui@@@vgui@@QAEXH@Z
                       0x13cb0  379  ?removeElementAt@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXH@Z
                       0x13cb0  380  ?removeElementAt@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXH@Z
                       0x13cb0  381  ?removeElementAt@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEXH@Z */
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


// vgui::Dar<int>::setElementAt  @ 27012b10
/* public: void __thiscall vgui::Dar<int>::setElementAt(int,int) */

void __thiscall vgui::Dar<int>::setElementAt(Dar<int> *this,int param_1,int param_2)

{
                    /* 0x12b10  401  ?setElementAt@?$Dar@H@vgui@@QAEXHH@Z
                       0x12b10  402  ?setElementAt@?$Dar@PAD@vgui@@QAEXPADH@Z
                       0x12b10  403
                       ?setElementAt@?$Dar@PAV?$Dar@D@vgui@@@vgui@@QAEXPAV?$Dar@D@2@H@Z
                       0x12b10  404
                       ?setElementAt@?$Dar@PAVActionSignal@vgui@@@vgui@@QAEXPAVActionSignal@2@H@Z
                       0x12b10  405  ?setElementAt@?$Dar@PAVButton@vgui@@@vgui@@QAEXPAVButton@2@H@Z
                       0x12b10  406
                       ?setElementAt@?$Dar@PAVChangeSignal@vgui@@@vgui@@QAEXPAVChangeSignal@2@H@Z
                       0x12b10  407
                       ?setElementAt@?$Dar@PAVDesktopIcon@vgui@@@vgui@@QAEXPAVDesktopIcon@2@H@Z
                       0x12b10  408
                       ?setElementAt@?$Dar@PAVFocusChangeSignal@vgui@@@vgui@@QAEXPAVFocusChangeSignal@2@H@Z
                       0x12b10  409  ?setElementAt@?$Dar@PAVFrame@vgui@@@vgui@@QAEXPAVFrame@2@H@Z
                       0x12b10  410
                       ?setElementAt@?$Dar@PAVFrameSignal@vgui@@@vgui@@QAEXPAVFrameSignal@2@H@Z
                       0x12b10  411
                       ?setElementAt@?$Dar@PAVInputSignal@vgui@@@vgui@@QAEXPAVInputSignal@2@H@Z
                       0x12b10  412
                       ?setElementAt@?$Dar@PAVIntChangeSignal@vgui@@@vgui@@QAEXPAVIntChangeSignal@2@H@Z
                       0x12b10  413  ?setElementAt@?$Dar@PAVLabel@vgui@@@vgui@@QAEXPAVLabel@2@H@Z
                       0x12b10  414  ?setElementAt@?$Dar@PAVPanel@vgui@@@vgui@@QAEXPAVPanel@2@H@Z
                       0x12b10  415
                       ?setElementAt@?$Dar@PAVRepaintSignal@vgui@@@vgui@@QAEXPAVRepaintSignal@2@H@Z
                       0x12b10  416
                       ?setElementAt@?$Dar@PAVSurfaceBase@vgui@@@vgui@@QAEXPAVSurfaceBase@2@H@Z
                       0x12b10  417
                       ?setElementAt@?$Dar@PAVTickSignal@vgui@@@vgui@@QAEXPAVTickSignal@2@H@Z */
  if ((-1 < param_2) && (param_2 < *(int *)this)) {
    *(int *)(*(int *)(this + 8) + param_2 * 4) = param_1;
  }
  return;
}


// vgui::DataInputStream::DataInputStream  @ 2702ccf0
/* public: __thiscall vgui::DataInputStream::DataInputStream(class vgui::DataInputStream const &) */

void __thiscall
vgui::DataInputStream::DataInputStream(DataInputStream *this,DataInputStream *param_1)

{
  int in_stack_00000008;
  
                    /* 0x2ccf0  48  ??0DataInputStream@vgui@@QAE@ABV01@@Z */
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


// vgui::DataInputStream::operator=  @ 2702cd40
/* public: class vgui::DataInputStream & __thiscall vgui::DataInputStream::operator=(class
   vgui::DataInputStream const &) */

DataInputStream * __thiscall
vgui::DataInputStream::operator=(DataInputStream *this,DataInputStream *param_1)

{
                    /* 0x2cd40  108  ??4DataInputStream@vgui@@QAEAAV01@ABV01@@Z */
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  return this;
}


// vgui::DesktopIcon::DesktopIcon  @ 27012310
/* public: __thiscall vgui::DesktopIcon::DesktopIcon(class vgui::DesktopIcon const &) */

void __thiscall vgui::DesktopIcon::DesktopIcon(DesktopIcon *this,DesktopIcon *param_1)

{
                    /* 0x12310  49  ??0DesktopIcon@vgui@@QAE@ABV01@@Z */
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


// vgui::DesktopIcon::operator=  @ 27012540
/* public: class vgui::DesktopIcon & __thiscall vgui::DesktopIcon::operator=(class vgui::DesktopIcon
   const &) */

DesktopIcon * __thiscall vgui::DesktopIcon::operator=(DesktopIcon *this,DesktopIcon *param_1)

{
  int iVar1;
  DesktopIcon *pDVar2;
  int iVar3;
  
                    /* 0x12540  109  ??4DesktopIcon@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::FileInputStream::FileInputStream  @ 27011f50
/* public: __thiscall vgui::FileInputStream::FileInputStream(class vgui::FileInputStream const &) */

void __thiscall
vgui::FileInputStream::FileInputStream(FileInputStream *this,FileInputStream *param_1)

{
  undefined4 uVar1;
  
                    /* 0x11f50  50  ??0FileInputStream@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &InputStream::_vftable_;
  uVar1 = *(undefined4 *)(param_1 + 4);
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 4) = uVar1;
  return;
}


// vgui::Font::Font  @ 27013b70
/* public: __thiscall vgui::Font::Font(class vgui::Font const &) */

void __thiscall vgui::Font::Font(Font *this,Font *param_1)

{
                    /* 0x13b70  51  ??0Font@vgui@@QAE@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Font::operator=  @ 27013ba0
/* public: class vgui::Font & __thiscall vgui::Font::operator=(class vgui::Font const &) */

Font * __thiscall vgui::Font::operator=(Font *this,Font *param_1)

{
                    /* 0x13ba0  111  ??4Font@vgui@@QAEAAV01@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  return this;
}


// vgui::Frame::Frame  @ 270108b0
/* public: __thiscall vgui::Frame::Frame(class vgui::Frame const &) */

void __thiscall vgui::Frame::Frame(Frame *this,Frame *param_1)

{
                    /* 0x108b0  52  ??0Frame@vgui@@QAE@ABV01@@Z */
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


// vgui::Frame::operator=  @ 27010f60
/* public: class vgui::Frame & __thiscall vgui::Frame::operator=(class vgui::Frame const &) */

Frame * __thiscall vgui::Frame::operator=(Frame *this,Frame *param_1)

{
  int iVar1;
  Frame *pFVar2;
  int iVar3;
  
                    /* 0x10f60  112  ??4Frame@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::HeaderPanel::HeaderPanel  @ 2702c2a0
/* public: __thiscall vgui::HeaderPanel::HeaderPanel(class vgui::HeaderPanel const &) */

void __thiscall vgui::HeaderPanel::HeaderPanel(HeaderPanel *this,HeaderPanel *param_1)

{
                    /* 0x2c2a0  53  ??0HeaderPanel@vgui@@QAE@ABV01@@Z */
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


// vgui::HeaderPanel::operator=  @ 2702c4f0
/* public: class vgui::HeaderPanel & __thiscall vgui::HeaderPanel::operator=(class vgui::HeaderPanel
   const &) */

HeaderPanel * __thiscall vgui::HeaderPanel::operator=(HeaderPanel *this,HeaderPanel *param_1)

{
  int iVar1;
  HeaderPanel *pHVar2;
  int iVar3;
  
                    /* 0x2c4f0  113  ??4HeaderPanel@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::Image::Image  @ 27011da0
/* public: __thiscall vgui::Image::Image(class vgui::Image const &) */

void __thiscall vgui::Image::Image(Image *this,Image *param_1)

{
                    /* 0x11da0  54  ??0Image@vgui@@QAE@ABV01@@Z */
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


// vgui::Image::operator=  @ 27011de0
/* public: class vgui::Image & __thiscall vgui::Image::operator=(class vgui::Image const &) */

Image * __thiscall vgui::Image::operator=(Image *this,Image *param_1)

{
  Image *pIVar1;
  int iVar2;
  
                    /* 0x11de0  114  ??4Image@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::ImagePanel::ImagePanel  @ 270331e0
/* public: __thiscall vgui::ImagePanel::ImagePanel(class vgui::ImagePanel const &) */

void __thiscall vgui::ImagePanel::ImagePanel(ImagePanel *this,ImagePanel *param_1)

{
  undefined4 uVar1;
  
                    /* 0x331e0  55  ??0ImagePanel@vgui@@QAE@ABV01@@Z */
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


// vgui::ImagePanel::operator=  @ 270333a0
/* public: class vgui::ImagePanel & __thiscall vgui::ImagePanel::operator=(class vgui::ImagePanel
   const &) */

ImagePanel * __thiscall vgui::ImagePanel::operator=(ImagePanel *this,ImagePanel *param_1)

{
  int iVar1;
  ImagePanel *pIVar2;
  int iVar3;
  
                    /* 0x333a0  115  ??4ImagePanel@vgui@@QAEAAV01@ABV01@@Z
                       0x333a0  137  ??4TextPanel@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::InputSignal::InputSignal  @ 27011d00
/* public: __thiscall vgui::InputSignal::InputSignal(void) */

void __thiscall vgui::InputSignal::InputSignal(InputSignal *this)

{
                    /* 0x11d00  57  ??0InputSignal@vgui@@QAE@XZ */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::InputSignal::InputSignal  @ 27011d10
/* public: __thiscall vgui::InputSignal::InputSignal(class vgui::InputSignal const &) */

void __thiscall vgui::InputSignal::InputSignal(InputSignal *this,InputSignal *param_1)

{
                    /* 0x11d10  56  ??0InputSignal@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::InputStream::InputStream  @ 27011e70
/* public: __thiscall vgui::InputStream::InputStream(void) */

void __thiscall vgui::InputStream::InputStream(InputStream *this)

{
                    /* 0x11e70  59  ??0InputStream@vgui@@QAE@XZ */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::InputStream::InputStream  @ 27011f10
/* public: __thiscall vgui::InputStream::InputStream(class vgui::InputStream const &) */

void __thiscall vgui::InputStream::InputStream(InputStream *this,InputStream *param_1)

{
                    /* 0x11f10  58  ??0InputStream@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::Label::Label  @ 27011410
/* public: __thiscall vgui::Label::Label(class vgui::Label const &) */

void __thiscall vgui::Label::Label(Label *this,Label *param_1)

{
                    /* 0x11410  60  ??0Label@vgui@@QAE@ABV01@@Z */
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


// vgui::Label::operator=  @ 270337a0
/* public: class vgui::Label & __thiscall vgui::Label::operator=(class vgui::Label const &) */

Label * __thiscall vgui::Label::operator=(Label *this,Label *param_1)

{
  int iVar1;
  Label *pLVar2;
  int iVar3;
  
                    /* 0x337a0  118  ??4Label@vgui@@QAEAAV01@ABV01@@Z
                       0x337a0  122  ??4MenuSeparator@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::Layout::Layout  @ 2702def0
/* public: __thiscall vgui::Layout::Layout(class vgui::Layout const &) */

void __thiscall vgui::Layout::Layout(Layout *this,Layout *param_1)

{
                    /* 0x2def0  61  ??0Layout@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::LineBorder::LineBorder  @ 27012c80
/* public: __thiscall vgui::LineBorder::LineBorder(class vgui::LineBorder const &) */

void __thiscall vgui::LineBorder::LineBorder(LineBorder *this,LineBorder *param_1)

{
                    /* 0x12c80  62  ??0LineBorder@vgui@@QAE@ABV01@@Z */
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


// vgui::LineBorder::operator=  @ 27012d10
/* public: class vgui::LineBorder & __thiscall vgui::LineBorder::operator=(class vgui::LineBorder
   const &) */

LineBorder * __thiscall vgui::LineBorder::operator=(LineBorder *this,LineBorder *param_1)

{
  LineBorder *pLVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x12d10  120  ??4LineBorder@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::LoweredBorder::LoweredBorder  @ 270339e0
/* public: __thiscall vgui::LoweredBorder::LoweredBorder(class vgui::LoweredBorder const &) */

void __thiscall vgui::LoweredBorder::LoweredBorder(LoweredBorder *this,LoweredBorder *param_1)

{
                    /* 0x339e0  63  ??0LoweredBorder@vgui@@QAE@ABV01@@Z */
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


// vgui::MenuSeparator::MenuSeparator  @ 27033590
/* public: __thiscall vgui::MenuSeparator::MenuSeparator(class vgui::MenuSeparator const &) */

void __thiscall vgui::MenuSeparator::MenuSeparator(MenuSeparator *this,MenuSeparator *param_1)

{
                    /* 0x33590  64  ??0MenuSeparator@vgui@@QAE@ABV01@@Z */
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


// vgui::MiniApp::MiniApp  @ 27012b30
/* public: __thiscall vgui::MiniApp::MiniApp(class vgui::MiniApp const &) */

void __thiscall vgui::MiniApp::MiniApp(MiniApp *this,MiniApp *param_1)

{
  undefined4 uVar1;
  
                    /* 0x12b30  65  ??0MiniApp@vgui@@QAE@ABV01@@Z */
  uVar1 = *(undefined4 *)(param_1 + 4);
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 4) = uVar1;
  return;
}


// vgui::Panel::Panel  @ 270103a0
/* public: __thiscall vgui::Panel::Panel(class vgui::Panel const &) */

void __thiscall vgui::Panel::Panel(Panel *this,Panel *param_1)

{
                    /* 0x103a0  66  ??0Panel@vgui@@QAE@ABV01@@Z */
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


// vgui::Panel::operator=  @ 27010550
/* public: class vgui::Panel & __thiscall vgui::Panel::operator=(class vgui::Panel const &) */

Panel * __thiscall vgui::Panel::operator=(Panel *this,Panel *param_1)

{
  int iVar1;
  Panel *pPVar2;
  int iVar3;
  
                    /* 0x10550  124  ??4Panel@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::Scheme::Scheme  @ 2700fea0
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


// vgui::Scheme::operator=  @ 270102f0
/* public: class vgui::Scheme & __thiscall vgui::Scheme::operator=(class vgui::Scheme const &) */

Scheme * __thiscall vgui::Scheme::operator=(Scheme *this,Scheme *param_1)

{
  int iVar1;
  Scheme *pSVar2;
  int iVar3;
  
                    /* 0x102f0  125  ??4Scheme@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::ScrollBar::ScrollBar  @ 27013200
/* public: __thiscall vgui::ScrollBar::ScrollBar(class vgui::ScrollBar const &) */

void __thiscall vgui::ScrollBar::ScrollBar(ScrollBar *this,ScrollBar *param_1)

{
                    /* 0x13200  68  ??0ScrollBar@vgui@@QAE@ABV01@@Z */
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


// vgui::ScrollBar::operator=  @ 27013400
/* public: class vgui::ScrollBar & __thiscall vgui::ScrollBar::operator=(class vgui::ScrollBar const
   &) */

ScrollBar * __thiscall vgui::ScrollBar::operator=(ScrollBar *this,ScrollBar *param_1)

{
  ScrollBar *pSVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x13400  126  ??4ScrollBar@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::ScrollPanel::ScrollPanel  @ 27012dd0
/* public: __thiscall vgui::ScrollPanel::ScrollPanel(class vgui::ScrollPanel const &) */

void __thiscall vgui::ScrollPanel::ScrollPanel(ScrollPanel *this,ScrollPanel *param_1)

{
                    /* 0x12dd0  69  ??0ScrollPanel@vgui@@QAE@ABV01@@Z */
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


// vgui::ScrollPanel::operator=  @ 27012fc0
/* public: class vgui::ScrollPanel & __thiscall vgui::ScrollPanel::operator=(class vgui::ScrollPanel
   const &) */

ScrollPanel * __thiscall vgui::ScrollPanel::operator=(ScrollPanel *this,ScrollPanel *param_1)

{
  ScrollPanel *pSVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x12fc0  127  ??4ScrollPanel@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::Slider::Slider  @ 27013640
/* public: __thiscall vgui::Slider::Slider(class vgui::Slider const &) */

void __thiscall vgui::Slider::Slider(Slider *this,Slider *param_1)

{
                    /* 0x13640  70  ??0Slider@vgui@@QAE@ABV01@@Z */
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


// vgui::Slider::operator=  @ 270138c0
/* public: class vgui::Slider & __thiscall vgui::Slider::operator=(class vgui::Slider const &) */

Slider * __thiscall vgui::Slider::operator=(Slider *this,Slider *param_1)

{
  Slider *pSVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x138c0  128  ??4Slider@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::StackLayout::StackLayout  @ 2702e710
/* public: __thiscall vgui::StackLayout::StackLayout(class vgui::StackLayout const &) */

void __thiscall vgui::StackLayout::StackLayout(StackLayout *this,StackLayout *param_1)

{
                    /* 0x2e710  71  ??0StackLayout@vgui@@QAE@ABV01@@Z */
  *(undefined ***)this = &Layout::_vftable_;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  this[8] = param_1[8];
  *(undefined ***)this = &_vftable_;
  return;
}


// vgui::StackLayout::operator=  @ 2702e740
/* public: class vgui::StackLayout & __thiscall vgui::StackLayout::operator=(class vgui::StackLayout
   const &) */

StackLayout * __thiscall vgui::StackLayout::operator=(StackLayout *this,StackLayout *param_1)

{
                    /* 0x2e740  129  ??4StackLayout@vgui@@QAEAAV01@ABV01@@Z */
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  this[8] = param_1[8];
  return this;
}


// vgui::String::operator=  @ 27012dc0
/* public: class vgui::String & __thiscall vgui::String::operator=(class vgui::String const &) */

String * __thiscall vgui::String::operator=(String *this,String *param_1)

{
                    /* 0x12dc0  130  ??4String@vgui@@QAEAAV01@ABV01@@Z */
  *(undefined4 *)this = *(undefined4 *)param_1;
  return this;
}


// vgui::Surface::Surface  @ 270327b0
/* public: __thiscall vgui::Surface::Surface(class vgui::Surface const &) */

void __thiscall vgui::Surface::Surface(Surface *this,Surface *param_1)

{
  undefined4 uVar1;
  
                    /* 0x327b0  72  ??0Surface@vgui@@QAE@ABV01@@Z */
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


// vgui::Surface::operator=  @ 27032830
/* public: class vgui::Surface & __thiscall vgui::Surface::operator=(class vgui::Surface const &) */

Surface * __thiscall vgui::Surface::operator=(Surface *this,Surface *param_1)

{
                    /* 0x32830  131  ??4Surface@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::Surface::~Surface  @ 270331d0
/* public: __thiscall vgui::Surface::~Surface(void) */

void __thiscall vgui::Surface::~Surface(Surface *this)

{
                    /* 0x331d0  79  ??1Surface@vgui@@QAE@XZ */
                    /* WARNING: Could not recover jumptable at 0x2703af98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  vgui::SurfaceBase::~SurfaceBase((SurfaceBase *)this);
  return;
}


// vgui::SurfaceBase::SurfaceBase  @ 2702df30
/* public: __thiscall vgui::SurfaceBase::SurfaceBase(class vgui::SurfaceBase const &) */

void __thiscall vgui::SurfaceBase::SurfaceBase(SurfaceBase *this,SurfaceBase *param_1)

{
                    /* 0x2df30  73  ??0SurfaceBase@vgui@@QAE@ABV01@@Z */
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


// vgui::SurfaceBase::operator=  @ 2702df80
/* public: class vgui::SurfaceBase & __thiscall vgui::SurfaceBase::operator=(class vgui::SurfaceBase
   const &) */

SurfaceBase * __thiscall vgui::SurfaceBase::operator=(SurfaceBase *this,SurfaceBase *param_1)

{
                    /* 0x2df80  132  ??4SurfaceBase@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::TablePanel::TablePanel  @ 2702c770
/* public: __thiscall vgui::TablePanel::TablePanel(class vgui::TablePanel const &) */

void __thiscall vgui::TablePanel::TablePanel(TablePanel *this,TablePanel *param_1)

{
                    /* 0x2c770  74  ??0TablePanel@vgui@@QAE@ABV01@@Z */
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


// vgui::TablePanel::operator=  @ 2702ca10
/* public: class vgui::TablePanel & __thiscall vgui::TablePanel::operator=(class vgui::TablePanel
   const &) */

TablePanel * __thiscall vgui::TablePanel::operator=(TablePanel *this,TablePanel *param_1)

{
  TablePanel *pTVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x2ca10  133  ??4TablePanel@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::TextEntry::TextEntry  @ 2702cd50
/* public: __thiscall vgui::TextEntry::TextEntry(class vgui::TextEntry const &) */

void __thiscall vgui::TextEntry::TextEntry(TextEntry *this,TextEntry *param_1)

{
                    /* 0x2cd50  75  ??0TextEntry@vgui@@QAE@ABV01@@Z */
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


// vgui::TextEntry::operator=  @ 2702cfb0
/* public: class vgui::TextEntry & __thiscall vgui::TextEntry::operator=(class vgui::TextEntry const
   &) */

TextEntry * __thiscall vgui::TextEntry::operator=(TextEntry *this,TextEntry *param_1)

{
  TextEntry *pTVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x2cfb0  134  ??4TextEntry@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::TextGrid::TextGrid  @ 270308b0
/* public: __thiscall vgui::TextGrid::TextGrid(class vgui::TextGrid const &) */

void __thiscall vgui::TextGrid::TextGrid(TextGrid *this,TextGrid *param_1)

{
                    /* 0x308b0  76  ??0TextGrid@vgui@@QAE@ABV01@@Z */
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


// vgui::TextGrid::operator=  @ 27030ae0
/* public: class vgui::TextGrid & __thiscall vgui::TextGrid::operator=(class vgui::TextGrid const &)
    */

TextGrid * __thiscall vgui::TextGrid::operator=(TextGrid *this,TextGrid *param_1)

{
  TextGrid *pTVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x30ae0  135  ??4TextGrid@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::TextImage::TextImage  @ 2702bc60
/* public: __thiscall vgui::TextImage::TextImage(class vgui::TextImage const &) */

void __thiscall vgui::TextImage::TextImage(TextImage *this,TextImage *param_1)

{
                    /* 0x2bc60  77  ??0TextImage@vgui@@QAE@ABV01@@Z */
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


// vgui::TextImage::operator=  @ 2702bcf0
/* public: class vgui::TextImage & __thiscall vgui::TextImage::operator=(class vgui::TextImage const
   &) */

TextImage * __thiscall vgui::TextImage::operator=(TextImage *this,TextImage *param_1)

{
  TextImage *pTVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x2bcf0  136  ??4TextImage@vgui@@QAEAAV01@ABV01@@Z */
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


// vgui::TextPanel::TextPanel  @ 27011250
/* public: __thiscall vgui::TextPanel::TextPanel(class vgui::TextPanel const &) */

void __thiscall vgui::TextPanel::TextPanel(TextPanel *this,TextPanel *param_1)

{
  undefined4 uVar1;
  
                    /* 0x11250  78  ??0TextPanel@vgui@@QAE@ABV01@@Z */
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


