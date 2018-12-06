#include "Simulacao.hpp"

/* Diagrama das pistas e unções 

  6     8        7      1
| . |   .    |   .    | . |
| . |   .    |   .    | . |
| . |   J2   |   .    | . |
| . | . || . |   .    | . |
| . | . || . |   .    | . |
| . | . || . |   .    | . |
| . | . || . |   J1   | . |
| . | . || . | . || . | . |
| . | . || . | . || . | . |
| . | . || . | . || . | . |
  6   5    4   3    2   1
*/

#define MEIO_SEGUNDO 500

void threadGeraCarro(Pista *pista, int probabilidade)
{        
    if (pista->geraCarro(probabilidade) >= rand() % 100 + 1)     // v2 in the range 1 to 100
    {
        UT * unidadeDeTransito = new UT(pista);        
        pista->adicionarUnidadeDeTransito(unidadeDeTransito);

        Logger::getInstance().registerLog(__LINE__, __FILE__, "Carro Gerado id [" + std::to_string(pista->getId()) + "].");
    }
}

int main (int argc, char** argv)
{
	Logger::getInstance().configureDestinationFile("defaultLoggingFile.log");
    Logger::getInstance().registerLog(__LINE__, __FILE__, "Início da Simulação");

    int probabilidadeDeGeracaoDeCarros = 0;

    if (argc > 1) 
        probabilidadeDeGeracaoDeCarros = atoi(argv[1]);

    Logger::getInstance().registerLog(__LINE__, __FILE__, "Probabilidade de Geracao de Carros [" + std::to_string(probabilidadeDeGeracaoDeCarros) + "]");
    
    Pista *pista1 = new Pista(1)
        , *pista2 = new Pista(2)
        , *pista3 = new Pista(3)
        , *pista4 = new Pista(4)
        , *pista5 = new Pista(5)
        , *pista6 = new Pista(6)
        , *pista7 = new Pista(7)
        , *pista8 = new Pista(8);

    Juncao *juncao1 = new Juncao(1)
        , *juncao2 = new Juncao(2);

    while (true) 
    {
        thread geracao1 (threadGeraCarro, pista1, probabilidadeDeGeracaoDeCarros);
        thread geracao2 (threadGeraCarro, pista2, probabilidadeDeGeracaoDeCarros);
        thread geracao3 (threadGeraCarro, pista3, probabilidadeDeGeracaoDeCarros);
        thread geracao4 (threadGeraCarro, pista4, probabilidadeDeGeracaoDeCarros);
        thread geracao5 (threadGeraCarro, pista5, probabilidadeDeGeracaoDeCarros);
        thread geracao6 (threadGeraCarro, pista6, probabilidadeDeGeracaoDeCarros);
        
        geracao1.join();
        geracao2.join();
        geracao3.join();
        geracao4.join();
        geracao5.join();
        geracao6.join();

        ThreadHelper::aguardar(MEIO_SEGUNDO);
    }

    //Calcula Deslocamentos
    //criar uma thread por carrro
    //Calcula Transições laterais 
    //Calcula Afunilamento de pistas
    //Verifica Colisões
    //Calcula vizinhos
    
    return 0;
} 
