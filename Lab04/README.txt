1)  DAG
   +----------+
   |   Main   |
   +-----+----+
         |
         | Inicia Threads
         |
   +-----v-----+    Calcula fatoriais       +-----v-----+
   |  Thread 1 |  ------------------------  |  Thread 2 |   Calcula soma
   +-----+-----+                            +-----+-----+
         |                                        | 
         |                                        |  Calcula soma
         |                                        |
   +-----v-----+                                  |
   |   Main    | ----------------------------------
   +-----+-----+
         |
         | Recebe resultado
         |
   +-----v-----+
   |  Fim DAG  |
   +-----------+ 

2) Qual o limite inferior do tempo de execução paralela para cada decomposição?
A Thread "calcular_fatorial" realiza N iterações, onde N é um valor pré-definido. Cada iteração requer uma operação de multiplicação ou inicialização de um valor. 
  Portanto, o número total de operações realizadas pela thread "calcular_fatorial" é da ordem de N.A thread "calcular_resultado" também realiza N iterações, onde N é um valor pré-definido. 
  Cada iteração requer uma operação de divisão e uma operação de adição. Portanto, o número total de operações realizadas pela thread "calcular_resultado" é da ordem de 2N.
  Se as duas threads são executadas em paralelo, o tempo total de execução paralela seria limitado pelo tempo de execução da thread que requer mais tempo. Neste caso, como o número total de operações realizadas pela thread "calcular_resultado" é maior que o número total de operações realizadas pela thread "calcular_fatorial", o tempo de execução paralela é limitado pelo tempo de execução da thread "calcular_resultado".
  Portanto, o limite inferior do tempo de execução paralela para cada decomposição seria proporcional ao tempo de execução da thread "calcular_resultado". No entanto, é importante lembrar que o tempo de execução depende também das características da máquina em que o programa está sendo executado.

3) Quantos Processadores são necessários para conseguir o tempo mínimo de execução?
O mínimo são 2 processadores, tendo em vista a dependência gerada pelo fatorial, que sempre depende do resultado anterior. 
 Alem disso a função soma também depende que o fatorial da iteração N esteja resolvido para que possa seguir executando.
 
4) Qual o grau máximo de concorrência?
O grau máximo de concorrência é 2, já que apenas duas threads são utilizadas: uma para calcular os fatoriais e outra para calcular o resultado final.

5)Qual é o paralelismo médio?
aceleração = tempo_serial / tempo_paralelo
aceleração = 0.005 / 16.627
aceleração = 0.000301

paralelismo_medio = aceleração / número_de_processadores
paralelismo_medio = 0.000301 / 2
paralelismo_medio = 0.0001505.
