APP := Alladin
SRCS := source/*.cpp TinyXML/*.cpp
all: $(SRCS)
	g++ -std=c++11 $^ -o $(APP) -Iheaders -I. -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean:
	rm -f *.o

cleanall: clean
	rm -f $(APP)
