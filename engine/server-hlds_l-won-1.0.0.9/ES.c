// ES_ErrorTypeToString__F12ES_ErrorType  @ 0808ef10
undefined4 * ES_ErrorTypeToString__F12ES_ErrorType(undefined4 *param_1,int param_2)

{
  char cVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  
  if (param_2 == 0x69) {
    if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc] ==
        '\0') {
      _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
           _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
           _8_4_ + 1;
      puVar2 = &force_to_data;
    }
    else {
      puVar2 = (undefined *)
               clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                         (
                         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                         );
    }
    *param_1 = puVar2;
    uVar3 = 0xffffffff;
    pcVar5 = "ES_WSAENOBUFS";
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    iVar4 = ~uVar3 - 1;
    pcVar5 = "ES_WSAENOBUFS";
    goto LAB_080905b5;
  }
  if (param_2 < 0x6a) {
    if (param_2 == 0x59) {
      if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc]
          == '\0') {
        _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
             _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
             _8_4_ + 1;
        puVar2 = &force_to_data;
      }
      else {
        puVar2 = (undefined *)
                 clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                           (
                           _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                           );
      }
      *param_1 = puVar2;
      uVar3 = 0xffffffff;
      pcVar5 = "ES_WSAEDESTADDRREQ";
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      iVar4 = ~uVar3 - 1;
      pcVar5 = "ES_WSAEDESTADDRREQ";
      goto LAB_080905b5;
    }
    if (0x59 < param_2) {
      if (param_2 == 0x61) {
        if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
            [0xc] == '\0') {
          _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
               = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                 ._8_4_ + 1;
          puVar2 = &force_to_data;
        }
        else {
          puVar2 = (undefined *)
                   clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                             (
                             _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                             );
        }
        *param_1 = puVar2;
        uVar3 = 0xffffffff;
        pcVar5 = "ES_WSAEAFNOSUPPORT";
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        iVar4 = ~uVar3 - 1;
        pcVar5 = "ES_WSAEAFNOSUPPORT";
      }
      else if (param_2 < 0x62) {
        if (param_2 == 0x5d) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAEPROTONOSUPPORT";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAEPROTONOSUPPORT";
        }
        else if (param_2 < 0x5e) {
          if (param_2 == 0x5b) {
            if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                [0xc] == '\0') {
              _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
              _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                      ._8_4_ + 1;
              puVar2 = &force_to_data;
            }
            else {
              puVar2 = (undefined *)
                       clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                                 (
                                 _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                                 );
            }
            *param_1 = puVar2;
            uVar3 = 0xffffffff;
            pcVar5 = "ES_WSAEPROTOTYPE";
            do {
              if (uVar3 == 0) break;
              uVar3 = uVar3 - 1;
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            iVar4 = ~uVar3 - 1;
            pcVar5 = "ES_WSAEPROTOTYPE";
          }
          else if (param_2 < 0x5c) {
            if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                [0xc] == '\0') {
              _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
              _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                      ._8_4_ + 1;
              puVar2 = &force_to_data;
            }
            else {
              puVar2 = (undefined *)
                       clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                                 (
                                 _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                                 );
            }
            *param_1 = puVar2;
            uVar3 = 0xffffffff;
            pcVar5 = "ES_WSAEMSGSIZE";
            do {
              if (uVar3 == 0) break;
              uVar3 = uVar3 - 1;
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            iVar4 = ~uVar3 - 1;
            pcVar5 = "ES_WSAEMSGSIZE";
          }
          else {
            if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                [0xc] == '\0') {
              _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
              _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                      ._8_4_ + 1;
              puVar2 = &force_to_data;
            }
            else {
              puVar2 = (undefined *)
                       clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                                 (
                                 _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                                 );
            }
            *param_1 = puVar2;
            uVar3 = 0xffffffff;
            pcVar5 = "ES_WSAENOPROTOOPT";
            do {
              if (uVar3 == 0) break;
              uVar3 = uVar3 - 1;
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            iVar4 = ~uVar3 - 1;
            pcVar5 = "ES_WSAENOPROTOOPT";
          }
        }
        else if (param_2 == 0x5f) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAEOPNOTSUPP";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAEOPNOTSUPP";
        }
        else if (param_2 < 0x60) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAESOCKTNOSUPPORT";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAESOCKTNOSUPPORT";
        }
        else {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAEPFNOSUPPORT";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAEPFNOSUPPORT";
        }
      }
      else if (param_2 == 0x65) {
        if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
            [0xc] == '\0') {
          _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
               = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                 ._8_4_ + 1;
          puVar2 = &force_to_data;
        }
        else {
          puVar2 = (undefined *)
                   clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                             (
                             _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                             );
        }
        *param_1 = puVar2;
        uVar3 = 0xffffffff;
        pcVar5 = "ES_WSAENETUNREACH";
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        iVar4 = ~uVar3 - 1;
        pcVar5 = "ES_WSAENETUNREACH";
      }
      else if (param_2 < 0x66) {
        if (param_2 == 99) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAEADDRNOTAVAIL";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAEADDRNOTAVAIL";
        }
        else if (param_2 < 100) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAEADDRINUSE";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAEADDRINUSE";
        }
        else {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAENETDOWN";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAENETDOWN";
        }
      }
      else if (param_2 == 0x67) {
        if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
            [0xc] == '\0') {
          _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
               = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                 ._8_4_ + 1;
          puVar2 = &force_to_data;
        }
        else {
          puVar2 = (undefined *)
                   clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                             (
                             _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                             );
        }
        *param_1 = puVar2;
        uVar3 = 0xffffffff;
        pcVar5 = "ES_WSAECONNABORTED";
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        iVar4 = ~uVar3 - 1;
        pcVar5 = "ES_WSAECONNABORTED";
      }
      else if (param_2 < 0x68) {
        if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
            [0xc] == '\0') {
          _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
               = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                 ._8_4_ + 1;
          puVar2 = &force_to_data;
        }
        else {
          puVar2 = (undefined *)
                   clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                             (
                             _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                             );
        }
        *param_1 = puVar2;
        uVar3 = 0xffffffff;
        pcVar5 = "ES_WSAENETRESET";
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        iVar4 = ~uVar3 - 1;
        pcVar5 = "ES_WSAENETRESET";
      }
      else {
        if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
            [0xc] == '\0') {
          _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
               = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                 ._8_4_ + 1;
          puVar2 = &force_to_data;
        }
        else {
          puVar2 = (undefined *)
                   clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                             (
                             _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                             );
        }
        *param_1 = puVar2;
        uVar3 = 0xffffffff;
        pcVar5 = "ES_WSAECONNRESET";
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        iVar4 = ~uVar3 - 1;
        pcVar5 = "ES_WSAECONNRESET";
      }
      goto LAB_080905b5;
    }
    if (param_2 == 0x16) {
      if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc]
          == '\0') {
        _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
             _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
             _8_4_ + 1;
        puVar2 = &force_to_data;
      }
      else {
        puVar2 = (undefined *)
                 clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                           (
                           _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                           );
      }
      *param_1 = puVar2;
      uVar3 = 0xffffffff;
      pcVar5 = "ES_WSAEINVAL";
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      iVar4 = ~uVar3 - 1;
      pcVar5 = "ES_WSAEINVAL";
      goto LAB_080905b5;
    }
    if (param_2 < 0x17) {
      if (param_2 == 9) {
        if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
            [0xc] == '\0') {
          _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
               = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                 ._8_4_ + 1;
          puVar2 = &force_to_data;
        }
        else {
          puVar2 = (undefined *)
                   clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                             (
                             _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                             );
        }
        *param_1 = puVar2;
        uVar3 = 0xffffffff;
        pcVar5 = "ES_WSAEBADF";
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        iVar4 = ~uVar3 - 1;
        pcVar5 = "ES_WSAEBADF";
        goto LAB_080905b5;
      }
      if (param_2 < 10) {
        if (param_2 == 0) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_NO_ERROR";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_NO_ERROR";
          goto LAB_080905b5;
        }
        if (param_2 == 4) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAEINTR";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAEINTR";
          goto LAB_080905b5;
        }
      }
      else {
        if (param_2 == 0xd) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAEACCES";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAEACCES";
          goto LAB_080905b5;
        }
        if (param_2 < 0xe) {
          if (param_2 == 0xb) {
            if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                [0xc] == '\0') {
              _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
              _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                      ._8_4_ + 1;
              puVar2 = &force_to_data;
            }
            else {
              puVar2 = (undefined *)
                       clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                                 (
                                 _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                                 );
            }
            *param_1 = puVar2;
            uVar3 = 0xffffffff;
            pcVar5 = "ES_WSAEWOULDBLOCK";
            do {
              if (uVar3 == 0) break;
              uVar3 = uVar3 - 1;
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            iVar4 = ~uVar3 - 1;
            pcVar5 = "ES_WSAEWOULDBLOCK";
            goto LAB_080905b5;
          }
        }
        else if (param_2 == 0xe) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAEFAULT";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAEFAULT";
          goto LAB_080905b5;
        }
      }
    }
    else {
      if (param_2 == 0x28) {
        if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
            [0xc] == '\0') {
          _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
               = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                 ._8_4_ + 1;
          puVar2 = &force_to_data;
        }
        else {
          puVar2 = (undefined *)
                   clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                             (
                             _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                             );
        }
        *param_1 = puVar2;
        uVar3 = 0xffffffff;
        pcVar5 = "ES_WSAELOOP";
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        iVar4 = ~uVar3 - 1;
        pcVar5 = "ES_WSAELOOP";
        goto LAB_080905b5;
      }
      if (param_2 < 0x29) {
        if (param_2 == 0x24) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAENAMETOOLONG";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAENAMETOOLONG";
          goto LAB_080905b5;
        }
        if (param_2 < 0x25) {
          if (param_2 == 0x18) {
            if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                [0xc] == '\0') {
              _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
              _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                      ._8_4_ + 1;
              puVar2 = &force_to_data;
            }
            else {
              puVar2 = (undefined *)
                       clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                                 (
                                 _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                                 );
            }
            *param_1 = puVar2;
            uVar3 = 0xffffffff;
            pcVar5 = "ES_WSAEMFILE";
            do {
              if (uVar3 == 0) break;
              uVar3 = uVar3 - 1;
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            iVar4 = ~uVar3 - 1;
            pcVar5 = "ES_WSAEMFILE";
            goto LAB_080905b5;
          }
        }
        else if (param_2 == 0x27) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAENOTEMPTY";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAENOTEMPTY";
          goto LAB_080905b5;
        }
      }
      else {
        if (param_2 == 0x57) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAEUSERS";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAEUSERS";
          goto LAB_080905b5;
        }
        if (0x57 < param_2) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAENOTSOCK";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAENOTSOCK";
          goto LAB_080905b5;
        }
        if (param_2 == 0x42) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAEREMOTE";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAEREMOTE";
          goto LAB_080905b5;
        }
      }
    }
  }
  else {
    if (param_2 == 0x3e6) {
      if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc]
          == '\0') {
        _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
             _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
             _8_4_ + 1;
        puVar2 = &force_to_data;
      }
      else {
        puVar2 = (undefined *)
                 clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                           (
                           _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                           );
      }
      *param_1 = puVar2;
      uVar3 = 0xffffffff;
      pcVar5 = "ES_WSAVERNOTSUPPORTED";
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      iVar4 = ~uVar3 - 1;
      pcVar5 = "ES_WSAVERNOTSUPPORTED";
      goto LAB_080905b5;
    }
    if (param_2 < 999) {
      if (param_2 == 0x71) {
        if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
            [0xc] == '\0') {
          _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
               = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                 ._8_4_ + 1;
          puVar2 = &force_to_data;
        }
        else {
          puVar2 = (undefined *)
                   clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                             (
                             _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                             );
        }
        *param_1 = puVar2;
        uVar3 = 0xffffffff;
        pcVar5 = "ES_WSAEHOSTUNREACH";
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        iVar4 = ~uVar3 - 1;
        pcVar5 = "ES_WSAEHOSTUNREACH";
        goto LAB_080905b5;
      }
      if (param_2 < 0x72) {
        if (param_2 == 0x6d) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAETOOMANYREFS";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAETOOMANYREFS";
        }
        else if (param_2 < 0x6e) {
          if (param_2 == 0x6b) {
            if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                [0xc] == '\0') {
              _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
              _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                      ._8_4_ + 1;
              puVar2 = &force_to_data;
            }
            else {
              puVar2 = (undefined *)
                       clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                                 (
                                 _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                                 );
            }
            *param_1 = puVar2;
            uVar3 = 0xffffffff;
            pcVar5 = "ES_WSAENOTCONN";
            do {
              if (uVar3 == 0) break;
              uVar3 = uVar3 - 1;
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            iVar4 = ~uVar3 - 1;
            pcVar5 = "ES_WSAENOTCONN";
          }
          else if (param_2 < 0x6c) {
            if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                [0xc] == '\0') {
              _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
              _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                      ._8_4_ + 1;
              puVar2 = &force_to_data;
            }
            else {
              puVar2 = (undefined *)
                       clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                                 (
                                 _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                                 );
            }
            *param_1 = puVar2;
            uVar3 = 0xffffffff;
            pcVar5 = "ES_WSAEISCONN";
            do {
              if (uVar3 == 0) break;
              uVar3 = uVar3 - 1;
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            iVar4 = ~uVar3 - 1;
            pcVar5 = "ES_WSAEISCONN";
          }
          else {
            if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                [0xc] == '\0') {
              _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
              _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                      ._8_4_ + 1;
              puVar2 = &force_to_data;
            }
            else {
              puVar2 = (undefined *)
                       clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                                 (
                                 _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                                 );
            }
            *param_1 = puVar2;
            uVar3 = 0xffffffff;
            pcVar5 = "ES_WSAESHUTDOWN";
            do {
              if (uVar3 == 0) break;
              uVar3 = uVar3 - 1;
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            iVar4 = ~uVar3 - 1;
            pcVar5 = "ES_WSAESHUTDOWN";
          }
        }
        else if (param_2 == 0x6f) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAECONNREFUSED";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAECONNREFUSED";
        }
        else if (param_2 < 0x70) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAETIMEDOUT";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAETIMEDOUT";
        }
        else {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAEHOSTDOWN";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAEHOSTDOWN";
        }
        goto LAB_080905b5;
      }
      if (param_2 == 0x7a) {
        if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
            [0xc] == '\0') {
          _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
               = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                 ._8_4_ + 1;
          puVar2 = &force_to_data;
        }
        else {
          puVar2 = (undefined *)
                   clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                             (
                             _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                             );
        }
        *param_1 = puVar2;
        uVar3 = 0xffffffff;
        pcVar5 = "ES_WSAEDQUOT";
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        iVar4 = ~uVar3 - 1;
        pcVar5 = "ES_WSAEDQUOT";
        goto LAB_080905b5;
      }
      if (param_2 < 0x7b) {
        if (param_2 == 0x73) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAEINPROGRESS";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAEINPROGRESS";
          goto LAB_080905b5;
        }
        if (param_2 < 0x73) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAEALREADY";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAEALREADY";
          goto LAB_080905b5;
        }
        if (param_2 == 0x74) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAESTALE";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAESTALE";
          goto LAB_080905b5;
        }
      }
      else {
        if (param_2 == 0x3e4) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAEPROCLIM";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAEPROCLIM";
          goto LAB_080905b5;
        }
        if (0x3e4 < param_2) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSANOTINITIALISED";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSANOTINITIALISED";
          goto LAB_080905b5;
        }
        if (param_2 == 0x3e3) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSAEDISCON";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSAEDISCON";
          goto LAB_080905b5;
        }
      }
    }
    else {
      if (param_2 == 0x3ef) {
        if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
            [0xc] == '\0') {
          _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
               = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                 ._8_4_ + 1;
          puVar2 = &force_to_data;
        }
        else {
          puVar2 = (undefined *)
                   clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                             (
                             _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                             );
        }
        *param_1 = puVar2;
        uVar3 = 0xffffffff;
        pcVar5 = "ES_TMSG_TOO_LARGE";
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        iVar4 = ~uVar3 - 1;
        pcVar5 = "ES_TMSG_TOO_LARGE";
        goto LAB_080905b5;
      }
      if (param_2 < 0x3f0) {
        if (param_2 == 0x3eb) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_INVALID_SOCKET";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_INVALID_SOCKET";
          goto LAB_080905b5;
        }
        if (0x3eb < param_2) {
          if (param_2 == 0x3ed) {
            if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                [0xc] == '\0') {
              _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
              _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                      ._8_4_ + 1;
              puVar2 = &force_to_data;
            }
            else {
              puVar2 = (undefined *)
                       clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                                 (
                                 _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                                 );
            }
            *param_1 = puVar2;
            uVar3 = 0xffffffff;
            pcVar5 = "ES_INCOMPLETE_RECV";
            do {
              if (uVar3 == 0) break;
              uVar3 = uVar3 - 1;
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            iVar4 = ~uVar3 - 1;
            pcVar5 = "ES_INCOMPLETE_RECV";
          }
          else if (param_2 < 0x3ee) {
            if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                [0xc] == '\0') {
              _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
              _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                      ._8_4_ + 1;
              puVar2 = &force_to_data;
            }
            else {
              puVar2 = (undefined *)
                       clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                                 (
                                 _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                                 );
            }
            *param_1 = puVar2;
            uVar3 = 0xffffffff;
            pcVar5 = "ES_INCOMPLETE_SEND";
            do {
              if (uVar3 == 0) break;
              uVar3 = uVar3 - 1;
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            iVar4 = ~uVar3 - 1;
            pcVar5 = "ES_INCOMPLETE_SEND";
          }
          else {
            if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                [0xc] == '\0') {
              _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
              _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                      ._8_4_ + 1;
              puVar2 = &force_to_data;
            }
            else {
              puVar2 = (undefined *)
                       clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                                 (
                                 _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                                 );
            }
            *param_1 = puVar2;
            uVar3 = 0xffffffff;
            pcVar5 = "ES_DISCONNECTED";
            do {
              if (uVar3 == 0) break;
              uVar3 = uVar3 - 1;
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            iVar4 = ~uVar3 - 1;
            pcVar5 = "ES_DISCONNECTED";
          }
          goto LAB_080905b5;
        }
        if (param_2 == 0x3e9) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_ERROR_NO_TYPE";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_ERROR_NO_TYPE";
          goto LAB_080905b5;
        }
        if (0x3e9 < param_2) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_INVALID_ADDR";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_INVALID_ADDR";
          goto LAB_080905b5;
        }
        if (param_2 == 999) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_WSASYSNOTREADY";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_WSASYSNOTREADY";
          goto LAB_080905b5;
        }
      }
      else {
        if (param_2 == 0x3f3) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_PARTIAL_SENDTO";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_PARTIAL_SENDTO";
          goto LAB_080905b5;
        }
        if (param_2 < 0x3f4) {
          if (param_2 == 0x3f1) {
            if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                [0xc] == '\0') {
              _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
              _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                      ._8_4_ + 1;
              puVar2 = &force_to_data;
            }
            else {
              puVar2 = (undefined *)
                       clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                                 (
                                 _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                                 );
            }
            *param_1 = puVar2;
            uVar3 = 0xffffffff;
            pcVar5 = "ES_WRONG_TMESSAGE";
            do {
              if (uVar3 == 0) break;
              uVar3 = uVar3 - 1;
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            iVar4 = ~uVar3 - 1;
            pcVar5 = "ES_WRONG_TMESSAGE";
          }
          else if (param_2 < 0x3f2) {
            if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                [0xc] == '\0') {
              _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
              _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                      ._8_4_ + 1;
              puVar2 = &force_to_data;
            }
            else {
              puVar2 = (undefined *)
                       clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                                 (
                                 _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                                 );
            }
            *param_1 = puVar2;
            uVar3 = 0xffffffff;
            pcVar5 = "ES_WRONG_TSERVICE";
            do {
              if (uVar3 == 0) break;
              uVar3 = uVar3 - 1;
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            iVar4 = ~uVar3 - 1;
            pcVar5 = "ES_WRONG_TSERVICE";
          }
          else {
            if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                [0xc] == '\0') {
              _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
              _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                      ._8_4_ + 1;
              puVar2 = &force_to_data;
            }
            else {
              puVar2 = (undefined *)
                       clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                                 (
                                 _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                                 );
            }
            *param_1 = puVar2;
            uVar3 = 0xffffffff;
            pcVar5 = "ES_INVALID_TMSG";
            do {
              if (uVar3 == 0) break;
              uVar3 = uVar3 - 1;
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            iVar4 = ~uVar3 - 1;
            pcVar5 = "ES_INVALID_TMSG";
          }
          goto LAB_080905b5;
        }
        if (param_2 == 0x3f5) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_ERROR_STREAM_NOT_ALLOWED";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_ERROR_STREAM_NOT_ALLOWED";
          goto LAB_080905b5;
        }
        if (param_2 < 0x3f5) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_TIMED_OUT";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_TIMED_OUT";
          goto LAB_080905b5;
        }
        if (param_2 == 0x3f6) {
          if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
              [0xc] == '\0') {
            _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep.
            _8_4_ = _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                    ._8_4_ + 1;
            puVar2 = &force_to_data;
          }
          else {
            puVar2 = (undefined *)
                     clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                               (
                               _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                               );
          }
          *param_1 = puVar2;
          uVar3 = 0xffffffff;
          pcVar5 = "ES_SHUTDOWN";
          do {
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar4 = ~uVar3 - 1;
          pcVar5 = "ES_SHUTDOWN";
          goto LAB_080905b5;
        }
      }
    }
  }
  if (_t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep[0xc] ==
      '\0') {
    _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_ =
         _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep._8_4_
         + 1;
    puVar2 = &force_to_data;
  }
  else {
    puVar2 = (undefined *)
             clone__Q2t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_3Rep
                       (
                       _t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0_nilRep
                       );
  }
  *param_1 = puVar2;
  uVar3 = 0xffffffff;
  pcVar5 = "";
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  iVar4 = ~uVar3 - 1;
  pcVar5 = "";
LAB_080905b5:
  replace__t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0UiUiPCcUi
            (param_1,0,0xffffffff,pcVar5,iVar4);
  return param_1;
}


