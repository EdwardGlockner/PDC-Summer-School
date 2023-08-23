#define _GNU_SOURCE
#include <stdio.h>

#include <dlfcn.h>

void foo()
{
    printf("Start from instrumented foo\n");

    void (*pfoo)() = dlsym(RTLD_NEXT, "foo");

    if(pfoo)
    {
        (pfoo)();
    }

    printf("End from instrumented foo\n");


}