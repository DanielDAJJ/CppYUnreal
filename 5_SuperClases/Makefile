CXX = g++
CXXFLAGS = -Iinclude -std=c++17 -g
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = JuegoPOO.exe

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

clean:
	del src\*.o $(TARGET)