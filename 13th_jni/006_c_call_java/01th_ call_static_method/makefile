#BOJS=caller.o

#INCL=/usr/Java/jdk1.8.0_261/include/

#CC=gcc
#caller:$(OBJS)
#	$(CC) $< -o $@
#%o:%c
#	$(CC) -I$(INCL) -c $< -o $@

OBJS=caller.o
INCL=/usr/Java/jdk1.8.0_261/include
LDPATH=/usr/Java/jdk1.8.0_261/jre/lib/amd64/server
CC=gcc



caller:$(OBJS)
	$(CC) -L$(LDPATH) $< -ljvm -o $@


%o:%c
	$(CC) -I$(INCL) -c $< -o $@






















