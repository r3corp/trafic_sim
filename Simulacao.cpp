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
void threadMoveUnidadeTransito(UT *ut);

void threadGeraCarro(Pista *pista, int probabilidade)
{
    //Thread ativa semrpe gerando carros segundo a probabilidade para a pista
    std::vector<std::thread*> threadsCarros;
    while(true)
    {
		if (pista->geraCarro(probabilidade) >= (rand() % 100 + 1))     // v2 in the range 1 to 100
       {
           //se a pista tiver um novo carro segundo a probabilidade
           threadsCarros.push_back(new thread(threadMoveUnidadeTransito, new UT(pista))) ;
       }
       Logger::getInstance().registerLog(__LINE__, __FILE__, "Thread Gera Carro id [" + std::to_string(pista->getId()) + "] [" + std::to_string(threadsCarros.size()) + "] carros.");
    }
}

void threadMoveUnidadeTransito(UT *ut)
{
	long tempoEntreMovimentacoes = 100; // todo: definir como propriedade

    //Thread ativa sempre movimentando a unidade de transito
	bool carroEmMovimento = true;

    while(carroEmMovimento)
    {
        ut->movimentaUnidadeTransito(tempoEntreMovimentacoes);
		if (ut->verificaSeCarroChegouAoFimDaPista()) {
			// todo: logica para mudar de pista
			carroEmMovimento = false;
			Logger::getInstance().registerLog(__LINE__, __FILE__, "Thread Move Carro Chegou Ao Fim da Pista [" + std::to_string(ut->getId()) + "]");

		}

        this_thread::sleep_for (chrono::milliseconds(tempoEntreMovimentacoes)); // o carro se movimenta a cada 0.1 segundo
		Logger::getInstance().registerLog(__LINE__, __FILE__, "Thread Move Carro [" + std::to_string(ut->getId()) + "]." + "Distancia Percorrida: "+ std::to_string(ut->distanciaPercorridaNaPista) + " de " + std::to_string(ut->pistaCorrente->tamanho) );
    }
}

int main (int argc, char** argv)
{
	

    Logger::getInstance().configureDestinationFile("defaultLoggingFile.log");

    Logger::getInstance().registerLog(__LINE__, __FILE__, "Início da Simulação");

    //Parâmetros iniciais
    int probabilidade = 0;
    if (argc >1)
        probabilidade = atoi(argv[1]); //Recebe a porobabilidade de geração de carro através de parâmetro
    Logger::getInstance().registerLog(__LINE__, __FILE__, "Probabilidade[" + std::to_string(probabilidade) + "]");
    //inicialização das Pistas
    
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

    //criar thread para gerar carros
    //Gera Carros nas pistas de 1 a 6
    thread geracao1 (threadGeraCarro, pista1, probabilidade);
    thread geracao2 (threadGeraCarro, pista2, probabilidade);
    thread geracao3 (threadGeraCarro, pista3, probabilidade);
    thread geracao4 (threadGeraCarro, pista4, probabilidade);
    thread geracao5 (threadGeraCarro, pista5, probabilidade);
    thread geracao6 (threadGeraCarro, pista6, probabilidade);
	
	geracao1.join();
	geracao2.join();
	geracao3.join();
	geracao4.join();
	geracao5.join();
	geracao6.join();

    //Calcula Deslocamentos
    //criar uma thread por carrro
    //Calcula Transições laterais 
    //Calcula Afunilamento de pistas
    //Verifica Colisões
    //Calcula vizinhos
    
    return 0;
} 