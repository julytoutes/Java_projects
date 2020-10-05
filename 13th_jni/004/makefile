
OBJS=native.o

INCL=/usr/Java/jdk1.8.0_261/include


CC=gcc



libnative.so:$(OBJS)
	$(CC) -shared -fpic $< -o $@


%o:%c
	$(CC) -fPIC -c $< -o $@ -I$(INCL)
	

	






























