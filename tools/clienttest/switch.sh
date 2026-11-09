#!/bin/sh
# Switch the client.so in the test copy (~/hl-clienttest, never the Steam
# install) between ours and the original 25th Anniversary build.
# usage: tools/clienttest/switch.sh ours|orig   (no argument: show which)
D=${HL_TEST:-$HOME/hl-clienttest}/tfc/cl_dlls
case "${1:-}" in
	ours) cp "$D/client.so.ours" "$D/client.so" ;;
	orig) cp "$D/client.so.orig-25th" "$D/client.so" ;;
esac
s=$(md5sum < "$D/client.so")
if [ "$s" = "$(md5sum < "$D/client.so.ours")" ]; then echo "client.so: ours"
elif [ "$s" = "$(md5sum < "$D/client.so.orig-25th")" ]; then echo "client.so: original"
else echo "client.so: unknown"; fi
