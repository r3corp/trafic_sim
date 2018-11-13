CC= "g++ -std=gnu++11" 
CFLAGS=-I. 	 
DEPS = Simulacao.h
OBJ = Simulacao.o Logger.o Juncao.o Pista.o UT.o Orientacao.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
