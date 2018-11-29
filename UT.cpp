#include "UT.hpp" 


int UT::carCount = 0; //Inicialização do membro estático

UT::UT(Pista * pista = nullptr) : pistaCorrente(pista)
{
	srand(time(0));

	this->id = this->carCount++;//A contagem de carro começa em 1
	this->comprimento = 3; //default 3 metros por veiculo inicialmente
	this->espacoResguardoFrontal = 1; // considerando inicialmente um espaço fixo de resguardo do carro frontal mas isso deve ser variável dependendo da velocidade e do comportamento
	int randComportamento = rand() % 100;
	this->comportamento = (randComportamento < 20 ? 1 : randComportamento < 40 ? 2 : randComportamento < 60 ? 3 : randComportamento < 80 ? 4 : 5);
	this->largura = 2.5; //default 2.5 inicialmente
	//this->
}

//retorna o carro da posição informada para trás

int UT::getId()
{
	return this->id;
}

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