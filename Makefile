# Nombre del programa
PROG = programa

# Compilador y banderas de compilación
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -g -std=c++11

# Directorios de búsqueda de encabezados
INC_DIR = -I./include

# Archivos fuente y objeto
SRCS = $(wildcard src/*.cpp)
OBJS = $(patsubst src/%.cpp,bin/%.o,$(SRCS)) bin/main.o

# Archivos de encabezado
HEADERS = $(wildcard include/*.h)

# Reglas de compilación
all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INC_DIR) $^ -o $@

bin/%.o: src/%.cpp $(HEADERS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INC_DIR) -c $< -o $@

bin/main.o: main.cpp $(HEADERS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INC_DIR) -c $< -o $@

clean:
	rm -rf bin $(PROG)