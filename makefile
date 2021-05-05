##
# @file      makefile
# @author    Mitch Richling <https://www.mitchr.me/>
# @Copyright Copyright 2003,2012,2018,2019 by Mitch Richling.  All rights reserved.
# @brief     Build a few boost examples.@EOL
# @Std       GNUmake

# Typical settings for GCC G++
CXX        = g++
CXX98FLAGS = -pedantic -Wall -Wextra -std=c++98
CXX11FLAGS = -pedantic -Wall -Wextra -std=c++11
CXX17FLAGS = -pedantic -Wall -Wextra -std=c++17

# Uncomment to build all when make file changes
SPECDEP=makefile

# Put targets here
TARGETS17 = fs17 dir17 atomic17 algorithm
TARGETS11 = random11 regexExample1 for11 numericStuff vector11 stome thread01_hello thread02_lambda thread03_mutex thread04_condition thread05_pool thread06_callOnce chrono01 unordered_map sort smartPointer11 
TARGETS98 = readFileLines readAllFile list complex map queue set multiset vector generic little_algorithm string

TARGETS = $(TARGETS17) $(TARGETS11) $(TARGETS98)

all : $(TARGETS)
	@echo Make Complete

all17 : $(TARGETS17)
	@echo Make Complete

clean :
	rm -rf a.out *~ *.bak $(TARGETS)
	@echo Make Complete

smartPointer11 : smartPointer11.cpp $(SPECDEP)
	$(CXX) $(CXX11FLAGS) smartPointer11.cpp -o smartPointer11

random11 : random11.cpp $(SPECDEP)
	$(CXX) $(CXX11FLAGS) random11.cpp -o random11

regexExample1 : regexExample1.cpp $(SPECDEP)
	$(CXX) $(CXX11FLAGS) regexExample1.cpp -o regexExample1

for11 : for11.cpp $(SPECDEP)
	$(CXX) $(CXX11FLAGS) for11.cpp -o for11

numericStuff : numericStuff.cpp $(SPECDEP)
	$(CXX) $(CXX11FLAGS) numericStuff.cpp -o numericStuff

vector11 : vector11.cpp $(SPECDEP)
	$(CXX) $(CXX11FLAGS) vector11.cpp -o vector11

stome: stome.cpp $(SPECDEP)
	$(CXX) $(CXX11FLAGS) -fpermissive stome.cpp -o stome

readFileLines : readFileLines.cpp $(SPECDEP)
	$(CXX) $(CXX98FLAGS) readFileLines.cpp -o readFileLines

readAllFile : readAllFile.cpp $(SPECDEP)
	$(CXX) $(CXX98FLAGS) readAllFile.cpp -o readAllFile

thread01_hello : thread01_hello.cpp $(SPECDEP)
	$(CXX) $(CXX11FLAGS) -pthread thread01_hello.cpp -o thread01_hello

thread02_lambda : thread02_lambda.cpp $(SPECDEP)
	$(CXX) $(CXX11FLAGS) -pthread thread02_lambda.cpp -o thread02_lambda

thread03_mutex : thread03_mutex.cpp $(SPECDEP)
	$(CXX) $(CXX11FLAGS) -pthread thread03_mutex.cpp -o thread03_mutex

thread04_condition : thread04_condition.cpp $(SPECDEP)
	$(CXX) $(CXX11FLAGS) -pthread thread04_condition.cpp -o thread04_condition

thread05_pool : thread05_pool.cpp $(SPECDEP)
	$(CXX) $(CXX11FLAGS) -pthread thread05_pool.cpp -o thread05_pool

thread06_callOnce : thread06_callOnce.cpp $(SPECDEP)
	$(CXX) $(CXX11FLAGS) -pthread thread06_callOnce.cpp -o thread06_callOnce

chrono01 : chrono01.cpp $(SPECDEP)
	$(CXX) $(CXX11FLAGS) chrono01.cpp -o chrono01

list : list.cpp $(SPECDEP)
	$(CXX) $(CXX98FLAGS) list.cpp -o list

complex : complex.cpp $(SPECDEP)
	$(CXX) $(CXX98FLAGS) complex.cpp -o complex

map : map.cpp $(SPECDEP)
	$(CXX) $(CXX98FLAGS) map.cpp -o map

unordered_map : unordered_map.cpp $(SPECDEP)
	$(CXX) $(CXX11FLAGS) unordered_map.cpp -o unordered_map	

queue : queue.cpp $(SPECDEP)
	$(CXX) $(CXX98FLAGS) queue.cpp -o queue

set : set.cpp $(SPECDEP)
	$(CXX) $(CXX98FLAGS) set.cpp -o set

multiset : multiset.cpp $(SPECDEP)
	$(CXX) $(CXX98FLAGS) multiset.cpp -o multiset

vector : vector.cpp $(SPECDEP)
	$(CXX) $(CXX98FLAGS) vector.cpp -o vector

sort : sort.cpp $(SPECDEP)
	$(CXX) $(CXX11FLAGS) sort.cpp -o sort

algorithm : algorithm.cpp $(SPECDEP)
	$(CXX) $(CXX17FLAGS) algorithm.cpp -o algorithm

generic : generic.cpp $(SPECDEP)
	$(CXX) $(CXX98FLAGS) generic.cpp -o generic

little_algorithm : little_algorithm.cpp $(SPECDEP)
	$(CXX) $(CXX98FLAGS) little_algorithm.cpp -o little_algorithm

string : string.cpp $(SPECDEP)
	$(CXX) $(CXX98FLAGS) string.cpp -o string

fs17 : fs17.cpp $(SPECDEP)
	$(CXX) $(CXX17FLAGS) fs17.cpp -o fs17

dir17 : dir17.cpp $(SPECDEP)
	$(CXX) $(CXX17FLAGS) dir17.cpp -o dir17

atomic17 : atomic17.cpp $(SPECDEP)
	$(CXX) $(CXX17FLAGS) atomic17.cpp -o atomic17
