#include "Pista.hpp"

bool Pista::geraCarro(int probabilidade)
{
    //Realiza a geração de carros verificando se existe espaço para entrar um novo carro e baseado no parâmetro de probabilidade
    Logger::getInstance().registerLog(__LINE__, __FILE__, "Gerando Carro");
    if (rand()*100 > probabilidade) 
        return true;
    return false;
}

Pista *Pista::retornaPista(ORIENTACAO orientacao)
{
    if (orientacao == ORIENTACAO::A_DIREITA)
        return this->aDireita;
    else if (orientacao == ORIENTACAO::A_ESQUERDA)
        return this->aEsquerda;
    return nullptr;
}