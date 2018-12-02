CC=g++ -std=c++17
CFLAGS=-I. 	 
DEPS = Simulacao.h Orientacao.h
OBJ = Logger.o Juncao.o Pista.o UT.o Simulacao.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Simulacao: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
