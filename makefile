CXX = g++
CXXFLAGS = -Wall -g
IODIR = ../../proj3_IO/
proj3: Exercise.o Workout.o Manager.o proj3.cpp
	$(CXX) $(CXXFLAGS) Exercise.o Workout.o Manager.o proj3.cpp -o proj3

Manager.o: Exercise.o Workout.o Manager.cpp Manager.h
	$(CXX) $(CXXFLAGS) -c Manager.cpp

Workout.o: Exercise.o Workout.cpp Workout.h
	$(CXX) $(CXXFLAGS) -c Workout.cpp

Exercise.o: Exercise.cpp Exercise.h
	$(CXX) $(CXXFLAGS) -c Exercise.cpp

clean:
	rm *.o*
	rm *~ 

run:
	./proj3

run1:
	./proj3 proj3_workout1.txt

run2:
	./proj3 proj3_workout2.txt

run3:
	./proj3 proj3_workout3.txt

val1:
	valgrind ./proj3 proj3_workout1.txt

val2:
	valgrind ./proj3 proj3_workout2.txt

val3:
	valgrind ./proj3 proj3_workout3.txt

submit:
	cp Exercise.h Exercise.cpp Workout.h Workout.cpp Manager.h Manager.cpp proj3.cpp ~/cs202proj/proj3

ta1:
	valgrind ./proj3 proj3_ta1.txt

ta2:
	valgrind ./proj3 proj3_ta2.txt

ta3:
	valgrind ./proj3 proj3_ta3.txt
