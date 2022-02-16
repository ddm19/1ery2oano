ej2: main.o Library.o Reader.o Lending.o Author.o Book.o
	g++ -Wall -g -std=c++11 main.o Library.o Reader.o Lending.o Author.o Book.o -o ej2

main.o: main.cc Library.h
	g++ -Wall -g -std=c++11 -c main.cc

Library.o: Library.cc Library.h
	g++ -Wall -g -std=c++11 -c Library.cc

Reader.o: Reader.cc Reader.h Lending.h
	g++ -Wall -g -std=c++11 -c Reader.cc

Lending.o: Lending.cc Lending.h
	g++ -Wall -g -std=c++11 -c Lending.cc

Author.o: Author.cc Author.h Book.h
	g++ -Wall -g -std=c++11 -c Author.cc

Book.o: Book.cc Book.h
	g++ -Wall -g -std=c++11 -c Book.cc

clean:
	rm -rf *.o ej2
