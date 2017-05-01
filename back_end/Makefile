CC=g++
CFLAGS=-std=c++11
EXTRAFLAGS=-lpqxx -lpq
GPBLIBS=`pkg-config --libs protobuf --cflags protobuf`
PTHREAD=-lpthread

server: server.cpp server_base.h server_base.cpp
	$(CC) $(PTHREAD) -o server $(CFLAGS) server.cpp server_base.cpp


clean:
	rm -f *~ *.o server          
clobber:
	rm -f *~ *.o                 
