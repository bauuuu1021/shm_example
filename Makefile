CC = gcc
CFLAGS = -g -static
FILE = server client

all: target

target: $(FILE)

%: %.c
	$(CC) $(CFLAGS) -o $@ $@.c 
	objdump -d -M intel $@ > origin_$@.dump

clean:
	rm -rf $(FILE) *.dump
