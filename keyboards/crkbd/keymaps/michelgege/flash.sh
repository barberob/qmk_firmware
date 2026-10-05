#!/usr/bin/env bash
#
# Flash the Corne (crkbd/rev1) michelgege keymap.
#
# The pointing-device logic lives in the holykeebs "idank" userspace
# (users/idank/rules.mk) and is enabled through USER_NAME=idank.
# POINTING_DEVICE + SIDE pick the hardware layout:
#   cirque35_trackpoint -> cirque35 touchpad (left), trackpoint (right)
#
# Usage:
#   ./flash.sh [right|left]     # defaults to right
#
# Examples:
#   ./flash.sh            # flash the right half
#   ./flash.sh left       # flash the left half
set -euo pipefail

SIDE="${1:-right}"

case "$SIDE" in
    left | right) ;;
    *)
        echo "Usage: $0 [right|left]" >&2
        exit 1
        ;;
esac

# Always run from the repository root so `qmk` finds the QMK tree.
cd "$(git -C "$(dirname "$0")" rev-parse --show-toplevel)"

echo "Flashing crkbd/rev1:michelgege (SIDE=${SIDE})..." >&2

qmk flash -kb crkbd/rev1 -km michelgege \
    -e USER_NAME=idank \
    -e POINTING_DEVICE=cirque35_trackpoint \
    -e SIDE="${SIDE}"
