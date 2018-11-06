#include "Pista.hpp"

void Pista::geraCarro(int probabilidade)
{
    //Realiza a geração de carros verificando se existe espaço para entrar um novo carro e baseado no parâmetro de probabilidade
}

Pista *Pista::retornaPista(ORIENTACAO orientacao)
{
    if (orientacao == ORIENTACAO::A_DIREITA)
        return this->aDireita;
    else if (orientacao == ORIENTACAO::A_ESQUERDA)
        return this->aEsquerda;
    return nullptr;
}