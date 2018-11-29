#include "UT.hpp" 


bool UT::verificaEspacoAoLado(UT *carroAoLado) //Verifica se existe espaço a direita e a esquerda para mudar de pista
{
	return false;
}

float UT::calculaDeslocamento(void) //calcula o espaco deslocado em uma unidade de tempo
{
    //Calcula o tempo minimo para deslocamneto 
    if (!calculaSlotTempo())
        return 0;//Só precisa calcular deslocamento se tiver o tempo para isso
	return 1;
}

void UT::movimentaUnidadeTransito(float distancia) //aumenta a distancia percorrida
{
    if (calculaSlotTempo())
        tempoMovimentacaoAnterior = std::chrono::steady_clock::now();
}

bool UT::calculaSlotTempo(void)
{
    std::chrono::duration<double> timeSpan = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now() - tempoMovimentacaoAnterior);
    if (timeSpan.count() > 100)
        return true;
    return false;
}

float UT::retornaPosicao(void)
{
    return this->distanciaPercorridaNaPista;
}