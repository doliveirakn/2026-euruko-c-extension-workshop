#include <stdio.h>

/*
 * A plain C library — no Ruby headers, no VALUE types, no Init_ function.
 * This can be called from Ruby using the ffi gem without any Ruby-specific code.
 */

void hello_world(void) {
    printf("Hello from plain C via FFI!\n");
}

int add(int a, int b) {
    return a + b;
}
