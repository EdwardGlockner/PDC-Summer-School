CC=gcc

all: mainab mainba

liba.so: a.c
	$(CC) -shared -fpic $^ -o $@

libb.so: b.c
	$(CC) -shared -fpic $^ -o $@


mainab: main.c liba.so libb.so
	$(CC) main.c -o $@ -L. -la -lb -Wl,-rpath=$(PWD)

mainba: main.c liba.so libb.so
	$(CC) main.c -o $@ -L. -lb -la -Wl,-rpath=$(PWD)

clean:
	rm -fr *.so mainab mainba