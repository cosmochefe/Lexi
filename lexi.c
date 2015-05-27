#include <stdio.h>
#include <stdlib.h>

// Para todas as regras abaixo:
// dígito = 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
// letra = a | b | c | ... | z | A | B | C | ... | Z

// Números naturais
//
// EBNF:
// natural = dígito {dígito}.
//
// Gramática:
// G = (N, T, R, S)
// N = {S}
// T = {dígito}
// R:
//   1) S -> dígito S | dígito
void lexi_natural_ebnf(char *entrada)
{
}

void lexi_natural_automato(char *entrada)
{
}

int main(int argc, char **argv)
{
  char entrada[51];
  scanf(" %s", entrada);
  // A função equivalente ao analisador léxico deve ser executada abaixo
  lexi_inteiro_ebnf(entrada);
  return 0;
}

