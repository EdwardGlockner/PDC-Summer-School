CC=gcc


all: uninstrumented libinst.so

libfoo.so: foo.c
	$(CC) -shared -fpic $^ -o $@


libinst.so: inst.c
	$(CC) -shared  -fpic $^ -o $@ -ldl


uninstrumented: main.c libfoo.so
	$(CC) $^ -o $@ -L. -lfoo -Wl,-rpath=$(PWD)

run_inst:
	LD_PRELOAD=$(PWD)/libinst.so ./uninstrumented

run:
	./uninstrumented

clean:
	rm -f uninstrumented *.so