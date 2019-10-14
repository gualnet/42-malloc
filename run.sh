#	!/bin/sh
export DYLD_LIBRARY_PATH="/Users/galy/Documents/42/Malloc/"
export DYLD_INSERT_LIBRARIES="libft_malloc.so"
export DYLD_FORCE_FLAT_NAMESPACE=1
$@
