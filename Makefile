CC = gcc
CFLAGS = -g -static
FILE = server client

all: target

target: $(FILE)

%: %.c
	$(CC) $(CFLAGS) -o $@ $@.c 

clean:
	rm -rf $(FILE)
