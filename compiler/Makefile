all: 
	flex -o ./bin/lexer.cpp ./src/compiler.l
	bison -o ./bin/parser.cpp -d ./src/compiler.y
	g++ -o ./bin/compiler.out ./bin/parser.cpp
clean:
	rm -f ./bin/*