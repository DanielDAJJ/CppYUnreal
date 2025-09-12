CXX = g++
CXXFLAGS = -Iinclude -std=c++17 -g
SRCS = $(wildcar src/*.cpp)
TARGET = JuegoPOO.exe

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)