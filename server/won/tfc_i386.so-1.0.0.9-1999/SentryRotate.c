// SentryRotate__12CTFSentrygun  @ 000e9790
void SentryRotate__12CTFSentrygun(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  
  SetSentryAnim__12CTFSentrygun13TFTURRET_ANIM(param_1,2);
  StudioFrameAdvance__14CBaseAnimatingf(param_1,0);
  iVar1 = CheckSentry__12CTFSentrygun(param_1);
  if (iVar1 != 0) {
    if (*(int *)(*param_1 + 0x13c) != 0) {
      CheckShield__12CTFSentrygun(param_1);
    }
    *(float *)(*param_1 + 0xe4) = *gpGlobals + 0.1;
    iVar1 = FindTarget__12CTFSentrygun(param_1);
    if (iVar1 == 0) {
      iVar1 = MoveTurret__12CTFSentrygun(param_1);
      if (iVar1 == 0) {
        uVar2 = __rf__7EHANDLE(param_1 + 0x26);
        CheckBelowBuilding__11CBaseEntity(uVar2);
        lVar3 = (longdouble)(*DAT_0017562c)(0,0x3f800000);
        if (lVar3 < (longdouble)0.1) {
          EMIT_SOUND_DYN__FP7edict_siPCcffii
                    (*(undefined4 *)(*param_1 + 0x1e8),3,"weapons/turridle.wav",0x3f800000,
                     0x3f4ccccd,0,100);
        }
        if (param_1[0x184] == 0) {
          param_1[0x184] = 1;
          iVar1 = param_1[0x28];
        }
        else {
          param_1[0x184] = 0;
          iVar1 = param_1[0x29];
        }
        param_1[0x18c] = (int)(float)iVar1;
        lVar3 = (longdouble)(*DAT_0017562c)(0,0x3f800000);
        if (lVar3 < (longdouble)0.3) {
          lVar3 = (longdouble)(*DAT_0017562c)(0xc1200000,0x41200000);
          param_1[0x18b] = (int)(float)(int)ROUND(lVar3);
        }
      }
    }
  }
  return;
}


