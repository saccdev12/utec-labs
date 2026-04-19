CXX = g++
CXXFLAGS = -g -Wall -std=c++14
TARGET = lab0

SRCS = Main.cpp \
       DTFecha.cpp \
       DTRefer.cpp \
       Publicacion.cpp \
       Investigador.cpp \
       ArticuloRevista.cpp \
       Libro.cpp \
       PaginaWeb.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean all

.PHONY: all clean rebuild