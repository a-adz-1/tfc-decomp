// is_del__t18string_char_traits1Zcc  @ 00042b30
uint is_del__t18string_char_traits1Zcc(char param_1)

{
  return CONCAT31((int3)(((uint)(ushort)(param_1 >> 7) << 0x10) >> 8),
                  (byte)((ushort)*(undefined2 *)(__ctype_b + param_1 * 2) >> 0xd)) & 0xffffff01;
}


