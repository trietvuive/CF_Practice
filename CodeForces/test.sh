#!/bin/bash
g++ -O2 -o good ./good_solution.cpp
g++ -O2 -o bad ./bad_solution.cpp
g++ -O2 -o gen ./gen.cpp
for i in {1..10000}
do
	./gen i | data.txt
	./good << data.txt > real.txt
	./bad << data.txt > my.txt
	diff real.txt my.txt || break
done
