# hw.dll, WON 1.1.0.6 (Windows client engine, 2001)

The 2001 Windows hardware-rendering client engine. Frame times were cut to whole milliseconds with the fraction thrown away in this era (see docs/won-comparison.md).

- **Binary:** `hw.dll`
- **Version:** WON Half-Life 1.1.0.6
- **MD5 of the original:** `00333d2df780d77a2fcc864428751484`
- **Contents:** Ghidra decompile, one file per name prefix or class; functions without a symbol are in `_unnamed*.c` (split at function boundaries to keep files small). Windows DLL, stripped: only exports are named.

The original binary is not included.
