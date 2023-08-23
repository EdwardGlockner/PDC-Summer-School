CC=gcc

all: uninstrumented instrumented instrumented_inc

libfoo.so: foo.c
	$(CC) -shared -fpic $^ -o $@

libinst.so: inst.c libfoo.so
	$(CC) -shared -fpic $^ -L. -lfoo -o $@ -Wl,-rpath=$(PWD)

uninstrumented: a.c libfoo.so
	$(CC) a.c -o $@ -L. -lfoo -Wl,-rpath=$(PWD)

instrumented: a.c libfoo.so libinst.so
	$(CC) a.c -o $@ -L. -lfoo -linst -Wl,-rpath=$(PWD) -Dfoo=inst_foo

instrumented_inc: a.c libfoo.so libinst.so
	$(CC) a.c -o $@ -L. -lfoo -linst -Wl,-rpath=$(PWD) -include inst.h

clean:
	rm -fr instrumented uninstrumented instrumented_inc *.so