# Nombre del programa
PROG = programa

# Compilador y banderas de compilación
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -g -std=c++11 -std=c++0x

# Directorios de búsqueda de encabezados
INC_DIR = -I./include

# Archivos fuente y objeto
SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:.cpp=.o) main.o

# Archivos de encabezado
HEADERS = $(wildcard include/*.h)

# Reglas de compilación
all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INC_DIR) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INC_DIR) -c $< -o $@

main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(PROG)