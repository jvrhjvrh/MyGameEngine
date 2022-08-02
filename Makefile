##
# GameEngine
#
# @file
# @version 0.1

DIRS=out
CFLAGS := $(shell pkg-config --keep-system-cflags --cflags glfw3) -lGLEW -lGL
LDFLAGS := $(shell pkg-config --libs glfw3)
CXX := g++
SOURCEFILES := ./src
OUT := ./out
OBJECTS := $(OUT)/shader.o $(OUT)/loadTextures.o $(OUT)/glfw.o $(OUT)/window.o $(OUT)/models.o $(OUT)/keys.o $(OUT)/game.o $(OUT)/componentMask.o $(OUT)/entityManager.o $(OUT)/component.o

#Create directory out if not exists
$(shell mkdir -p $(DIRS))

.PHONY: main

main: $(OBJECTS)
	$(CXX) $(CFLAGS) -o $(OUT)/main $(SOURCEFILES)/mc.cpp $^ $(LDFLAGS)

$(OUT)/shader.o: $(SOURCEFILES)/shaders/shader.h
	$(CXX) -c -o $@ $(SOURCEFILES)/shaders/shader.cpp $(LDFLAGS)

$(OUT)/loadTextures.o: $(SOURCEFILES)/textures/loadTextures.h
	$(CXX) -c -o $@ $(SOURCEFILES)/textures/loadTextures.cpp $(LDFLAGS)

$(OUT)/glfw.o: $(SOURCEFILES)/glfw/glfw.h
	$(CXX) -c -o $@ $(SOURCEFILES)/glfw/glfw.cpp $(LDFLAGS)

$(OUT)/window.o: $(SOURCEFILES)/window/window.h
	$(CXX) -c -o $@ $(SOURCEFILES)/window/window.cpp $(LDFLAGS)

$(OUT)/models.o: $(SOURCEFILES)/models/models.h
	$(CXX) -c -o $@ $(SOURCEFILES)/models/models.cpp $(LDFLAGS)

$(OUT)/keys.o: $(SOURCEFILES)/controls/keys.h
	$(CXX) -c -o $@ $(SOURCEFILES)/controls/keys.cpp $(LDFLAGS)

$(OUT)/game.o: $(SOURCEFILES)/game/game.h
	$(CXX) -c -o $@ $(SOURCEFILES)/game/game.cpp $(LDFLAGS)

$(OUT)/componentMask.o: $(SOURCEFILES)/components/componentMask.h
	$(CXX) -c -o $@ $(SOURCEFILES)/components/componentMask.cpp $(LDFLAGS)

$(OUT)/entityManager.o: $(SOURCEFILES)/entities/entityManager.h
	$(CXX) -c -o $@ $(SOURCEFILES)/entities/entityManager.cpp $(LDFLAGS)

$(OUT)/component.o: $(SOURCEFILES)/components/component.h
	$(CXX) -c -o $@ $(SOURCEFILES)/components/component.cpp $(LDFLAGS)

clean:
	rm ./out/*

# end
