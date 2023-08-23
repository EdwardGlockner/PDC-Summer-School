#include <stdio.h>

#include "foo.h"

void inst_foo(void){
    printf("Start INSTRUMENTED libfoo\n");
    foo();
    printf("End Start INSTRUMENTED libfoo\n");
}