run: SortedList.o SortedListDr.o Student.o
	g++ SortedList.o SortedListDr.o Student.o -o run

SortedList.o: SortedList.cpp
	g++ -c SortedList.cpp

SortedListDr.o: SortedListDr.cpp
	g++ -c SortedListDr.cpp

Student.o: Student.cpp
	g++ -c Student.cpp

clean:
	rm *.o run
