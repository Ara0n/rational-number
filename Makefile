

tp3: main.o RationalNumber.o RationalList.o
	g++ main.o RationalNumber.o RationalList.o -o tp3

RationalNumber.o: RationalNumber.cpp RationalNumber.h
	g++ -Wall -pedantic -std=c++17 -c RationalNumber.cpp

RationalList.o: RationalList.cpp RationalList.h
	g++ -Wall -pedantic -std=c++17 -c RationalList.cpp

main.o: main.cpp RationalNumber.h RationalList.h
	g++ -Wall -pedantic --std=c++17 -c main.cpp

clean:
	rm *.o

run: tp3
	./tp3