output: Account.o Book.o Library_database.o LMS.o main.o Staff.o User.o Librarian.o
	g++ ./build/Account.o ./build/Book.o ./build/Library_database.o ./build/LMS.o ./build/main.o ./build/Staff.o ./build/User.o ./build/Librarian.o -o output

Account.o: Account.cpp
	g++ -c Account.cpp
	mv Account.o ./build/

Book.o: Book.cpp
	g++ -c Book.cpp
	mv Book.o ./build/

Library_database.o: Library_database.cpp
	g++ -c Library_database.cpp
	mv Library_database.o ./build/

LMS.o: LMS.cpp
	g++ -c LMS.cpp
	mv LMS.o ./build/

main.o: main.cpp
	g++ -c main.cpp
	mv main.o ./build/

Staff.o: Staff.cpp
	g++ -c Staff.cpp
	mv Staff.o ./build/

User.o: User.cpp
	g++ -c User.cpp
	mv User.o ./build/

Librarian.o: Librarian.cpp
	g++ -c Librarian.cpp
	mv Librarian.o ./build/

clean:
	cd ./build
	rm *.o output
	cd ..
	rmdir ./build