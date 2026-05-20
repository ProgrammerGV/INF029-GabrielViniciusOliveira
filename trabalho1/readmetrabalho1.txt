Corretor do Trabalho 1 - INF029

Este arquivo explica como compilar e executar o corretor de testes integrado com a implementacao do seu projeto (trabalho1.c e trabalho1.h).

--------------------------------------------------
PRE-REQUISITOS
--------------------------------------------------
Certifique-se de ter o compilador GCC instalado no seu sistema. Todos os tres arquivos (corretor.c, trabalho1.c, trabalho1.h) devem estar na mesma pasta.


--------------------------------------------------
COMO COMPILAR E EXECUTAR
--------------------------------------------------
Abra o terminal ou prompt de comando na pasta onde os arquivos estao salvos e siga os passos abaixo de acordo com seu sistema operacional:

WINDOWS (CMD ou PowerShell)

1. Para compilar os arquivos, digite:
   gcc corretor.c trabalho1.c -o corretor

2. Para rodar o programa, digite:
   .\corretor.exe


LINUX / macOS

1. Para compilar os arquivos, digite:
   gcc corretor.c trabalho1.c -o corretor

2. Para rodar o programa, digite:
   ./corretor


--------------------------------------------------
ENTENDENDO OS RESULTADOS
--------------------------------------------------
A execucao no terminal exibira blocos de resultados para cada questao testada (por exemplo, ###testQ1()###).

- O numero 1 impresso na tela significa que o teste passou (sucesso).
- O numero 0 impresso na tela significa que o teste falhou (erro).

Se a saida for composta apenas por numeros 1, todas as implementacoes estao corretas de acordo com os testes do corretor.