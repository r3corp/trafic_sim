#include "vector"
#include "Orientacao.hpp"

class UT; 

class Pista {
    private:
        float tamanho;

        std::vector<UT *> carros;

        Pista *aDireita, *aEsquerda;

    public:
        void geraCarro(int probabilidade);
        Pista *retornaPista(ORIENTACAO orientacao);
};