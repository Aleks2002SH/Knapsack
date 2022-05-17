main:
	echo "Main target"
compile: main.cpp
	g++ -c Knapsack.cpp
	g++ main.o -o result
clean:
	rm *.o
workresult:
	./result
