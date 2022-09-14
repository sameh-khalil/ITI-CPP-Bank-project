

all: Bank
#	@ dsa_test.exe


# make rule to generate the final binary
Bank:  BANKMAIN.o Customer.o Admin.o customerDB.o
	@ g++ BANKMAIN.o Customer.o Admin.o customerDB.o -o APP.exe
	

BANKMAIN.o: Customer.cpp Admin.cpp customerDB.cpp BANKMAIN.cpp
	@ g++ -c BANKMAIN.cpp
	
Admin.o: Admin.cpp Customer.cpp customerDB.cpp
	@ g++ -c Admin.cpp


Customer.o:Customer.cpp customerDB.cpp
	@ g++ -c Customer.cpp
	
	
customerDB.o:customerDB.cpp
	@ g++ -c customerDB.cpp