// ES_ErrorTypeToString__F12ES_ErrorType  @ 000d700c
void ES_ErrorTypeToString__F12ES_ErrorType(undefined4 param_1,int param_2)

{
  if (param_2 == 0x69) {
    __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
              (param_1,"ES_WSAENOBUFS");
    FUN_000d7904();
    return;
  }
  if (0x69 < param_2) {
    if (param_2 == 0x3e6) {
      __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                (param_1,"ES_WSAVERNOTSUPPORTED");
      FUN_000d7904();
      return;
    }
    if (0x3e6 < param_2) {
      if (param_2 == 0x3ef) {
        __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                  (param_1,"ES_TMSG_TOO_LARGE");
        FUN_000d7904();
        return;
      }
      if (0x3ef < param_2) {
        if (param_2 == 0x3f3) {
          __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                    (param_1,"ES_PARTIAL_SENDTO");
          FUN_000d7904();
          return;
        }
        if (0x3f3 < param_2) {
          if (param_2 == 0x3f5) {
            __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                      (param_1,"ES_ERROR_STREAM_NOT_ALLOWED");
            FUN_000d7904();
            return;
          }
          if (0x3f4 < param_2) {
            if (param_2 != 0x3f6) {
              FUN_000d78d0();
              return;
            }
            __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                      (param_1,"ES_SHUTDOWN");
            FUN_000d7904();
            return;
          }
          __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                    (param_1,"ES_TIMED_OUT");
          FUN_000d7904();
          return;
        }
        if (param_2 == 0x3f1) {
          __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                    (param_1,"ES_WRONG_TMESSAGE");
          FUN_000d7904();
          return;
        }
        if (param_2 < 0x3f2) {
          __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                    (param_1,"ES_WRONG_TSERVICE");
          FUN_000d7904();
          return;
        }
        __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                  (param_1,"ES_INVALID_TMSG");
        FUN_000d7904();
        return;
      }
      if (param_2 == 0x3eb) {
        __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                  (param_1,"ES_INVALID_SOCKET");
        FUN_000d7904();
        return;
      }
      if (0x3eb < param_2) {
        if (param_2 == 0x3ed) {
          __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                    (param_1,"ES_INCOMPLETE_RECV");
          FUN_000d7904();
          return;
        }
        if (param_2 < 0x3ee) {
          __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                    (param_1,"ES_INCOMPLETE_SEND");
          FUN_000d7904();
          return;
        }
        __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                  (param_1,"ES_DISCONNECTED");
        FUN_000d7904();
        return;
      }
      if (param_2 == 0x3e9) {
        __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                  (param_1,"ES_ERROR_NO_TYPE");
        FUN_000d7904();
        return;
      }
      if (param_2 < 0x3ea) {
        if (param_2 != 999) {
          FUN_000d78d0();
          return;
        }
        __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                  (param_1,"ES_WSASYSNOTREADY");
        FUN_000d7904();
        return;
      }
      __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                (param_1,"ES_INVALID_ADDR");
      FUN_000d7904();
      return;
    }
    if (param_2 == 0x71) {
      __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                (param_1,"ES_WSAEHOSTUNREACH");
      FUN_000d7904();
      return;
    }
    if (0x71 < param_2) {
      if (param_2 == 0x7a) {
        __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                  (param_1,"ES_WSAEDQUOT");
        FUN_000d7904();
        return;
      }
      if (0x7a < param_2) {
        if (param_2 == 0x3e4) {
          __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                    (param_1,"ES_WSAEPROCLIM");
          FUN_000d7904();
          return;
        }
        if (param_2 < 0x3e5) {
          if (param_2 != 0x3e3) {
            FUN_000d78d0();
            return;
          }
          __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                    (param_1,"ES_WSAEDISCON");
          FUN_000d7904();
          return;
        }
        __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                  (param_1,"ES_WSANOTINITIALISED");
        FUN_000d7904();
        return;
      }
      if (param_2 == 0x73) {
        __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                  (param_1,"ES_WSAEINPROGRESS");
        FUN_000d7904();
        return;
      }
      if (0x72 < param_2) {
        if (param_2 != 0x74) {
          FUN_000d78d0();
          return;
        }
        __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                  (param_1,"ES_WSAESTALE");
        FUN_000d7904();
        return;
      }
      __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                (param_1,"ES_WSAEALREADY");
      FUN_000d7904();
      return;
    }
    if (param_2 == 0x6d) {
      __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                (param_1,"ES_WSAETOOMANYREFS");
      FUN_000d7904();
      return;
    }
    if (0x6d < param_2) {
      if (param_2 == 0x6f) {
        __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                  (param_1,"ES_WSAECONNREFUSED");
        FUN_000d7904();
        return;
      }
      if (param_2 < 0x70) {
        FUN_000d7750();
        return;
      }
      __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                (param_1,"ES_WSAEHOSTDOWN");
      FUN_000d7904();
      return;
    }
    if (param_2 == 0x6b) {
      __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                (param_1,"ES_WSAENOTCONN");
      FUN_000d7904();
      return;
    }
    if (param_2 < 0x6c) {
      FUN_000d76f0();
      return;
    }
    __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
              (param_1,"ES_WSAESHUTDOWN");
    FUN_000d7904();
    return;
  }
  if (param_2 == 0x59) {
    __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
              (param_1,"ES_WSAEDESTADDRREQ");
    FUN_000d7904();
    return;
  }
  if (0x59 < param_2) {
    if (param_2 == 0x61) {
      __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                (param_1,"ES_WSAEAFNOSUPPORT");
      FUN_000d7904();
      return;
    }
    if (0x61 < param_2) {
      if (param_2 == 0x65) {
        __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                  (param_1,"ES_WSAENETUNREACH");
        FUN_000d7904();
        return;
      }
      if (0x65 < param_2) {
        if (param_2 == 0x67) {
          __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                    (param_1,"ES_WSAECONNABORTED");
          FUN_000d7904();
          return;
        }
        if (param_2 < 0x68) {
          FUN_000d7690();
          return;
        }
        __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                  (param_1,"ES_WSAECONNRESET");
        FUN_000d7904();
        return;
      }
      if (param_2 == 99) {
        __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                  (param_1,"ES_WSAEADDRNOTAVAIL");
        FUN_000d7904();
        return;
      }
      if (param_2 < 100) {
        FUN_000d7630();
        return;
      }
      __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                (param_1,"ES_WSAENETDOWN");
      FUN_000d7904();
      return;
    }
    if (param_2 == 0x5d) {
      __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                (param_1,"ES_WSAEPROTONOSUPPORT");
      FUN_000d7904();
      return;
    }
    if (0x5d < param_2) {
      if (param_2 == 0x5f) {
        __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                  (param_1,"ES_WSAEOPNOTSUPP");
        FUN_000d7904();
        return;
      }
      if (param_2 < 0x60) {
        FUN_000d75d0();
        return;
      }
      __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                (param_1,"ES_WSAEPFNOSUPPORT");
      FUN_000d7904();
      return;
    }
    if (param_2 == 0x5b) {
      __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                (param_1,"ES_WSAEPROTOTYPE");
      FUN_000d7904();
      return;
    }
    if (param_2 < 0x5c) {
      FUN_000d7570();
      return;
    }
    __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
              (param_1,"ES_WSAENOPROTOOPT");
    FUN_000d7904();
    return;
  }
  if (param_2 == 0x16) {
    __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
              (param_1,"ES_WSAEINVAL");
    FUN_000d7904();
    return;
  }
  if (0x16 < param_2) {
    if (param_2 == 0x28) {
      __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                (param_1,"ES_WSAELOOP");
      FUN_000d7904();
      return;
    }
    if (0x28 < param_2) {
      if (param_2 == 0x57) {
        __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                  (param_1,"ES_WSAEUSERS");
        FUN_000d7904();
        return;
      }
      if (param_2 < 0x58) {
        if (param_2 != 0x42) {
          FUN_000d78d0();
          return;
        }
        __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                  (param_1,"ES_WSAEREMOTE");
        FUN_000d7904();
        return;
      }
      __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                (param_1,"ES_WSAENOTSOCK");
      FUN_000d7904();
      return;
    }
    if (param_2 == 0x24) {
      __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                (param_1,"ES_WSAENAMETOOLONG");
      FUN_000d7904();
      return;
    }
    if (param_2 < 0x25) {
      if (param_2 != 0x18) {
        FUN_000d78d0();
        return;
      }
      __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                (param_1,"ES_WSAEMFILE");
      FUN_000d7904();
      return;
    }
    if (param_2 != 0x27) {
      FUN_000d78d0();
      return;
    }
    __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
              (param_1,"ES_WSAENOTEMPTY");
    FUN_000d7904();
    return;
  }
  if (param_2 == 9) {
    __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
              (param_1,"ES_WSAEBADF");
    FUN_000d7904();
    return;
  }
  if (9 < param_2) {
    if (param_2 == 0xd) {
      __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                (param_1,"ES_WSAEACCES");
      FUN_000d7904();
      return;
    }
    if (param_2 < 0xe) {
      if (param_2 != 0xb) {
        FUN_000d78d0();
        return;
      }
      __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
                (param_1,"ES_WSAEWOULDBLOCK");
      FUN_000d7904();
      return;
    }
    if (param_2 != 0xe) {
      FUN_000d78d0();
      return;
    }
    __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
              (param_1,"ES_WSAEFAULT");
    FUN_000d7904();
    return;
  }
  if (param_2 == 0) {
    __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
              (param_1,"ES_NO_ERROR");
    FUN_000d7904();
    return;
  }
  if (param_2 != 4) {
    FUN_000d78d0();
    return;
  }
  __t12basic_string3ZcZt18string_char_traits1ZcZt24__default_alloc_template2b1i0PCc
            (param_1,"ES_WSAEINTR");
  FUN_000d7904();
  return;
}


