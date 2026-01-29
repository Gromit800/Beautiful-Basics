CXX = g++
CXXFLAGS = -std=c++17 -Wall -I include -I lib


all: knit

knit: obj/knit.o obj/logic.o obj/hat.o
	@$(CXX) $(CXXFLAGS) -o knit obj/knit.o obj/logic.o obj/hat.o

test: obj/logic.o obj/test.o obj/hat.o
	@$(CXX) $(CXXFLAGS) -o test obj/logic.o obj/test.o obj/hat.o
	@./test

obj/knit.o: src/knit.cpp
	@mkdir -p obj
	@$(CXX) $(CXXFLAGS) -c src/knit.cpp -o obj/knit.o

obj/logic.o: src/logic.cpp
	@mkdir -p obj
	@$(CXX) $(CXXFLAGS) -c src/logic.cpp -o obj/logic.o

obj/test.o: tests/test.cpp
	@mkdir -p obj
	@$(CXX) $(CXXFLAGS) -c tests/test.cpp -o obj/test.o

obj/hat.o: src/hat.cpp
	@mkdir -p obj
	@$(CXX) $(CXXFLAGS) -c src/hat.cpp -o obj/hat.o	





clean: 
	@rm -f *.exe *.out obj/*.o tests/*.o test knit
	@rm -rf obj *.docx

.PHONY: all clean knit test
