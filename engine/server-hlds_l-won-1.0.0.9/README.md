# hlds_l, WON 1.0.0.9 (dedicated server, 1999)

The 1999 Linux dedicated server: engine and game loader in one executable. QuakeWorld-style netcode (one update per client packet), movement in the engine.

- **Binary:** `hlds_l`
- **Version:** WON 1.0.0.9
- **MD5 of the original:** `cc88b2d18bfc6997342ae199de00b8f6`
- **Contents:** Ghidra decompile, one file per name prefix or class; functions without a symbol are in `_unnamed*.c` (split at function boundaries to keep files small). Linux build with its global symbols kept (static functions are unnamed).

The original binary is not included.
