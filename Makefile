CC=g++ -std=c++17
CFLAGS=-I. 	 
DEPS = Simulacao.h
OBJ = Simulacao.o Logger.o Juncao.o Pista.o UT.o Orientacao.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Simulacao: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
