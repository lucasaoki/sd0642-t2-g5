Especificação do Segundo Trabalho

RPC com Banco de Dados

A ideia principal é gerar um servidor que possua rotinas com  um banco de dados. Esse servidor deve apresentar todas as rotinas para realizar a conexão com o banco de dados, etc.
Os clientes por sua vez não possuem nenhum driver de BD.
Os clientes irão solicitar uma string de consulta " select **from**;"  via RPC para esse servidor que irá processar a consulta e retornar a query
Para a Aplicação

Desenvolver um servidor que se conecte à um banco de dados (MySql) - O servidor possui os drivers de conexão ao banco. Não será criado um SGBD e sim um servidor que se conecta a um SGBD.
O objetivo é criar algo genérico pois, os 12 clientes deveriam ter todas as rotinas para conectar no BD. No caso do trabalho proposto, apenas o servidor faz isso. Os clientes devem apenas fazer consultas diferentes e o servidor se encarrega de fazer a consulta e devolver as respostas.
A aplicação é a de cadastro de funcionários. As operações são:
Inserção
Remoção
Consulta
O trabalho pode ser feito em C ou C++
Criar o link entre o cliente e o servidor via RPC (nesse caso, seria um driver distribuído);
Fazer o parser da string de consulta no cliente (talvez criar uma struct com as informações que serão recebidas)
Gerar um log das opeções de consulta
Apresentar os resultados da seguinte forma

Um diagrama apresentando o desenvolvimento do problema
Tempo de resposta final para requisição do cliente para operações de:
Consulta
Inserção
Remoção
Tempo de processamento da consulta no servidor mediante 100 conexões simultâneas por cliente. Considerar 12 clientes
Cada cliente deve executar 100 requisições. Considerar como cliente o host. Assim, cliente1 é o host1, cliente2 é o host 2 e assim por diante.
Um relatório apresentando uma introdução sobre o problema, os resultados obtidos e as soluções. O relatório deve ter no mínimo 5 páginas e no máximo 10 páginas desconsiderando capas, indíces e bibliografia. No máximo 1 página explicando o problema abordado e seus comentários.
Discuta as soluções, as dificuldades, os resultados obtidos, o hardware utilizado, a metodologia de execução dos experimentos, etc.
O relatório deve ser enviado via Moodle conforme combinado no primeiro dia de aula
O relatório deve apresentar a forma de execução dos codigos (README)
Os códigos devem ser enviados via Google Code.
Avaliação

As perguntas para o grupo serão relativas à forma de desenvolvimento, eficiências dos algoritmos, uso correto das ferramentas, legibilidade do código e documentação e participação dos membros no desenvolvimento do trabalho.
O número de perguntas será decidido no dia da apresentação.
Prazos

Relatório e Códigos

14/10/12 - 23:55h