# trafic_sim
Simulador de tráfego para aula de Cuda Avançado


## *Resolucao dos passos:*

1.  Criar uma thread para cada pista de 1 a 6 para ficar gerando os carros
    - Randomiza comportamento do motorista 
    - Randomiza parametros de condução 
2.  Cada carro tem sua própria thread que irá ficar calculando seu deslocamento
3.  A cada décimo de segundo calcula o deslocamento do carro
    - Caso diminua a distância do carro da frente diminuir a velocidade do carro (aceleração negativa)
    - Caso aumente a distância do carro da frente aumentar a velocidade 
4.  Desloca o carro e verifica colisão
    - Caso exista colisão parar o carro (Aceleração negativa forte)
5.  Quando chegar a junção (Junção 1 ou 2) realizar a resolução de conflito para saber quem irá entrar primeiro
    - Aumentar a velocidade de quem estiver na frente e diminuir a de quem estiver atrás

## Diretrizes: 
* A  aceleração aumenta gradativamente (estabelecer máximo)
* A velocidade aumenta com a aceleração
* Os carros já iniciam com uma velocidade randomizada entre um máximo e mínimo e aceleração também randomizada
* O tempo entre deslocamentos é 0.1 segundo
* Variacao de aceleração vai derivar do comportamento do motorista
* Distancia mínima para mudança de faixa depende também do comportamento do motorista
* Correlacionar o comprotamento do motorista com os parâmetros da simulaçao
