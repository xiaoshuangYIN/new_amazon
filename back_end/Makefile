CC=g++
CFLAGS=-std=c++11
PSQLFLAGS=-lpqxx -lpq
GPBLIBS=`pkg-config --libs protobuf --cflags protobuf`
PTHREAD=-lpthread

server: server.cpp server_base.h server_base.cpp psql.cpp psql.h msg.h msg.cpp protocal/AmazonUPS.pb.h protocal/AmazonUPS.pb.cc  protocal/amazon_orig_3.pb.cc protocal/amazon_orig_3.pb.h
	$(CC) $(PTHREAD) -o server $(CFLAGS) server.cpp server_base.cpp psql.cpp msg.cpp protocal/AmazonUPS.pb.cc protocal/amazon_orig_3.pb.cc $(PSQLFLAGS) $(GPBLIBS)


clean:
	rm -f *~ *.o server          
clobber:
	rm -f *~ *.o                 
