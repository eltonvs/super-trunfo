# Super Trunfo

Super Trunfo é um jogo de cartas que pode ser jogado por 2 ou mais pessoas.

Nele, o bolo de cartas é dividido igualmente entre os jogadores.

A cada rodada, é escolhido um dos 4 atributos da carta (pelo jogador que ganhou
a rodada anterior) e comparado entre a primeira carta do bolo de cada jogador.
O jogador que possuir a carta com a aributo de maior valor é o vencedor da rodada
e fica com todas as cartas usadas na rodada (colocando-as no fim de seu deck).

O vencedor é o jogador que ficar com as cartas de todos os outros jogadores.

### Casos especiais:
 - Caso o identificador da carta seja **ST** (*Super Trunfo*), essa carta será
   automaticamente a vencedora da rodada, independente do valor de seus atributos
   a não ser que uma das outras cartas possua o número 1 em seu identificador (A1, B1, ...).

## Como compilar
Digite:

```
$ make
$ ./bin/supertrunfo input_file N_PLAYERS N_CARDS
```

## Autores
 - Elton de Souza Vieira
 - Pedro Arthur Medeiros Fernandes
