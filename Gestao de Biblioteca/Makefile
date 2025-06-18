# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude

# Diretórios
SRC_DIR = src
INC_DIR = include
BIN_DIR = bin

# Arquivos
SOURCES = $(SRC_DIR)/Livro.cpp $(SRC_DIR)/Revista.cpp $(SRC_DIR)/Item.cpp $(SRC_DIR)/Biblioteca.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXEC = $(BIN_DIR)/biblioteca.exe

# Regra principal
all: $(EXEC)

# Regra para compilar o executável
$(EXEC): $(OBJECTS)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar arquivos .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos gerados
clean:
	del /Q $(SRC_DIR)\*.o *.o $(BIN_DIR)\*.exe 2>nul || echo Nada para limpar

# Executar
run: all
	$(EXEC)
