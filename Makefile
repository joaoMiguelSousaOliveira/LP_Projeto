CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

SRC = src/cliente.cpp \
    src/funcionario.cpp \
    src/quarto.cpp \
    src/suite.cpp \
    src/quarto_casal.cpp \
    src/presidencial.cpp \
    src/reserva.cpp \
    src/pagamento.cpp \
    src/hotel.cpp \
    src/pessoa.cpp 


MAIN_SRC = main.cpp


OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC)) \
    obj/main.o

TARGET = hotel

all: obj $(TARGET)


$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@


obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

obj/main.o: $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@


obj:
	mkdir -p obj


clean:
	rm -rf obj $(TARGET)

.PHONY: all clean obj