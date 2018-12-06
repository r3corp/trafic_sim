#ifndef UT_HEADER
#define UT_HEADER

#include <vector> 
#include <chrono>
#include <ratio>
#include <ctime>
#include <random>

#include "ThreadHelper.hpp"
#include "Orientacao.hpp"

class Pista;

//UnidadeTransito
class UT 
{
    private:
		static int carCount;

		int id;

        float largura;

        float comprimento;

        float velocidade;

        float aceleracao;

        int comportamento;

        int espacoResguardoFrontal;

        float distanciaCarroAdiante;

        UT *aDireita, *aFrente, *aEsquerda, *aTras; //considerando que irá guardar um apontamento para os carros ao redor sempre


        std::chrono::steady_clock::time_point tempoMovimentacaoAnterior;

    public:

		Pista * pistaCorrente;

		float distanciaPercorridaTotal = 0;

		float distanciaPercorridaNaPista = 0;

		UT(Pista *pista);// : pistaCorrente(pista);

		void mover();

		bool verificaEspacoAoLado(UT *carroAoLado); //Verifica se existe espaço a direita e a esquerda para mudar de pista

		bool verificaSeCarroChegouAoFimDaPista(); // se carro chegou ao fim da pista ele sera removido

		//float calculaDeslocamento(void);//calcula o espaco deslocado em uma unidade de tempo
		float calculaDeslocamento(long long tempo);

		//void movimentaUnidadeTransito(float distancia);//aumenta a distancia percorrida 
		void UT::movimentaUnidadeTransito(long long tempo); //aumenta a distancia percorrida

		bool calculaSlotTempo(void);

		float retornaPosicao(void);

		int getId();

		UT* getCarroAdjacente(Pista *pista, ORIENTACAO orientacao);
};

#endif