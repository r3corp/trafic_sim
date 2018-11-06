# trafic_sim
Simulador de tráfego para aula de Cuda Avançado


Resolucao dos passos:

Criar uma thread para cada pista de 1 a 6 para ficar gerando os carros
    Randomiza comportamento do motorista 
    Randomiza parametros de condução 
Cada carro tem sua própria thread que irá ficar calculando seu deslocamento
A cada décimo de segundo calcula o deslocamento do carro
    Caso diminua a distância do carro da frente diminuir a velocidade do carro (aceleração negativa)
    Caso aumente a distância do carro da frente aumentar a velocidade 
Desloca o carro e verifica colisão
    Caso exista colisão parar o carro (Aceleração negativa forte)
Quando chegar a junção (Junção 1 ou 2) realizar a resolução de conflito para saber quem irá entrar primeiro
    Aumentar a velocidade de quem estiver na frente e diminuir a de quem estiver atrás

* a aceleração aumenta gradativamente (estabelecer máximo)
* a velocidade aumenta com a aceleração
* os carros já iniciam com uma velocidade randomizada entre um máximo e mínimo e aceleração também randomizada
* o tempo entre deslocamentos é 0.1 segundo
* variacao de aceleração vai derivar do comportamento do motorista
* distancia mínima para mudança de faixa depende também do comportamento do motorista

* correlacionar o comprotamento do motorista com os parâmetros da simulaçao
