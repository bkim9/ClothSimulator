CC = g++

BREW = $(shell brew --prefix)
CFLAGS = -g -std=c++11 -Wno-deprecated-declarations
INCFLAGS = -Iinclude -I$(BREW)/include
LDFLAGS = -framework OpenGL -L$(BREW)/lib -lglfw
IMGUI_DIR = imgui
SRC_DIR = src
OBJS = main.o Camera.o Shader.o Cloth.o Spring.o Particle.o Triangle.o Window.o 
RM = /bin/rm -f
all: cloth
cloth: $(OBJS) $(IMGUI_OBJS)
	$(CC) -o cloth $^ $(LDFLAGS)
main.o: main.cpp include/Window.h 
	$(CC) $(CFLAGS) $(INCFLAGS) -c main.cpp
%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INCFLAGS) -c $<
	
clean: 
	$(RM) *.o cloth