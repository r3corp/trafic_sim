#include <vector> 
#include <chrono>
#include <ratio>
#include <ctime>
#include <random>

#include "Orientacao.hpp"

class Pista;

//UnidadeTransito
class UT {
    private:
		static int carCount;

		int id;

        int largura;

        int comprimento;

        float velocidade;

        float aceleracao;

        int comportamento;

        int espacoResguardoFrontal;

        float distanciaPercorridaTotal = 0;

        float distanciaPercorridaNaPista = 0;

        float distanciaCarroAdiante;

        UT *aDireita, *aFrente, *aEsquerda, *aTras; //considerando que irá guardar um apontamento para os carros ao redor sempre

        Pista *pistaCorrente;

        std::chrono::steady_clock::time_point tempoMovimentacaoAnterior;

    public:
		UT(Pista *pista);// : pistaCorrente(pista);
        bool verificaEspacoAoLado(UT *carroAoLado); //Verifica se existe espaço a direita e a esquerda para mudar de pista
        float calculaDeslocamento(void);//calcula o espaco deslocado em uma unidade de tempo
        void movimentaUnidadeTransito(float distancia);//aumenta a distancia percorrida 
        bool calculaSlotTempo(void);
        float retornaPosicao(void);
		int getId();
};

