#include "vector" 

//UnidadeTransito
Class UT {
    private:
        int largura;
        int comprimento;

        float velocidade;
        float aceleracao;

        int comportamento;

        float distancia_carro_adiante;
        UT *aDireita, *aFrente, *aEsquerda, *aTras; //considerando que irá guardar um apontamento para os carros ao redor sempre

        Pista *pistaCorrente;
    public:
        bool verificaEspacoAoLado(UT *carroAoLado); //Verifica se existe espaço a direita e a esquerda para mudar de pista

}