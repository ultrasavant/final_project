
# Makefile for f2022, ecs36b
# https://macappstore.org/libjson-rpc-cpp/
# https://github.com/cinemast/libjson-rpc-cpp

CC = g++ -std=c++14
CFLAGS = -g

LDFLAGS = 	-L/opt/homebrew/lib/ -ljsoncpp			\
		-lmicrohttpd -ljsonrpccpp-common		\
		-ljsonrpccpp-server -ljsonrpccpp-client -lcurl

INC	=	ecs36b_Common.h
AUTO_CLASSES = Auto.o Car.o Motorcycle.o

# rules.
all: 	client_car left_motorcycle right_motorcycle

#
#
# <target> : [... tab...] <dependency>
# [... tab ....] <action>
Auto.o:	Auto.cpp Auto.h
	$(CC) -c $(CFLAGS) Auto.cpp

Car.o:	Car.cpp Car.h
	$(CC) -c $(CFLAGS) Car.cpp

Motorcycle.o:	Motorcycle.cpp Motorcycle.h
	$(CC) -c $(CFLAGS) Motorcycle.cpp

client_car.h:	ecs36b_final.json
	jsonrpcstub ecs36b_final.json --cpp-server=left_motorcycle --cpp-client=client_car

left_motorcycle.h:	ecs36b_final.json
	jsonrpcstub ecs36b_final.json --cpp-server=left_motorcycle --cpp-client=client_car

right_motorcycle.h:	ecs36b_final.json
	jsonrpcstub ecs36b_final.json --cpp-server=right_motorcycle --cpp-client=client_car

client_car.o:	client_car.cpp client_car.h $(INC)
	$(CC) -c $(CFLAGS) client_car.cpp

left_motorcycle.o:	left_motorcycle.cpp left_motorcycle.h $(INC)
	$(CC) -c $(CFLAGS) left_motorcycle.cpp

right_motorcycle.o:	right_motorcycle.cpp right_motorcycle.h $(INC)
	$(CC) -c $(CFLAGS) right_motorcycle.cpp

ecs36b_JSON.o:	ecs36b_JSON.cpp $(INC)
	$(CC) -c $(CFLAGS) ecs36b_JSON.cpp

left_motorcycle:	left_motorcycle.o ecs36b_JSON.o $(AUTO_CLASSES)
	$(CC) -o left_motorcycle left_motorcycle.o ecs36b_JSON.o $(AUTO_CLASSES) $(LDFLAGS)

right_motorcycle:	right_motorcycle.o ecs36b_JSON.o $(AUTO_CLASSES)
	$(CC) -o right_motorcycle right_motorcycle.o ecs36b_JSON.o $(AUTO_CLASSES) $(LDFLAGS)

client_car:	client_car.o ecs36b_JSON.o $(AUTO_CLASSES)
	$(CC) -o client_car client_car.o ecs36b_JSON.o $(AUTO_CLASSES) $(LDFLAGS)

clean:
	rm -f *.o client_car.h left_motorcycle.h right_motorcycle.h client_car left_motorcycle right_motorcycle


