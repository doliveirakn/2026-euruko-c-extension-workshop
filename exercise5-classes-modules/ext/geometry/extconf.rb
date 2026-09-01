require 'mkmf'

# have_library('m') links -lm on Linux (required for math functions like sin/cos).
# It is a no-op on macOS where math.h is part of the SDK.
have_library('m')

create_makefile('geometry/geometry')
