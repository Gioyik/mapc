mapc: example/mapc.c src/mapc_lib.c
	$(CC) $^ $(CFLAGS) -o $@

clean:
	rm mapc
