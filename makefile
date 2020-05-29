all:
	g++ -g -Wall -pedantic -std=c++17 OOP.cpp -o objectShapes
	g++ -g -Wall -pedantic -std=c++17 DOD.cpp -o dataShapes
	g++ -g -Wall -pedantic -std=c++17 comparison.cpp comparison.h -o Comp

clean:
	rm -f objectShapes dataShapes Comp
