all: compile link

compile:
	g++ -Iinclude src/*.cpp src/entities/*.cpp -Ires -c

link:
	g++ *.o -o main -Isrc/entities -Llib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lsfml-audio
