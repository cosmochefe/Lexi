#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define true 1
#define false 0
typedef int bool;

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
bool lexi_natural_ebnf(char *entrada)
{
  unsigned int indice = 0;
  // Verifica se o primeiro caractere é um dígito (obrigatório)
  if (!isdigit(entrada[indice]))
    return false;
  indice++;
  // Verifica os demais caracteres que houverem, até encontrar um caractere que não for dígito
  while (isdigit(entrada[indice]))
    indice++;
  if (entrada[indice] != '\0')
    return false;
  return true;
}

bool lexi_natural_automato(char *entrada)
{
  unsigned int indice = 0;
  unsigned int state = 0;
  while (true)
  {
    switch (state)
    {
      case 0:
        // Transição do estado 0 para o estado 1, lendo dígito
        if (isdigit(entrada[indice]))
          state = 1;
        else
          return false; // Travamento ou estado final inválido!
        break;
      case 1:
        // Laço no estado 1, lendo dígito
        if (isdigit(entrada[indice]))
          state = 1;
        else
          // Fim da análise
          if (entrada[indice] == '\0')
            return true;
          else
            return false; // Travamento!
         break;
    }
    indice++;
  }
}

// Identificadores
//
// EBNF:
// identificador = letra {letra | dígito | "_"}.
//
// Gramática:
// G = (N, T, R, S)
// N = {S, A}
// T = {letra, dígito, _}
// R:
//   1) S -> letra A
//   2) A -> letra A | dígito A | _ A | letra | dígito | _
bool lexi_identificador_ebnf(char *entrada)
{
  unsigned int indice = 0;
  // Verifica se o primeiro caractere é uma letra (obrigatória)
  if (!isalpha(entrada[indice]))
    return false;
  indice++;
  // Verifica os demais caracteres que houverem, até encontrar um caractere que não for letra, dígito ou sublinhado
  while (isalpha(entrada[indice]) || isdigit(entrada[indice]) || entrada[indice] == '_')
    indice++;
  if (entrada[indice] != '\0')
    return false;
  return true;
}

bool lexi_identificador_automato(char *entrada)
{
  unsigned int indice = 0;
  unsigned int state = 0;
  while (true)
  {
    switch (state)
    {
      case 0:
        // Transição do estado 0 para o estado 1, lendo letra
        if (isalpha(entrada[indice]))
          state = 1;
        else
          return false; // Travamento ou estado final inválido!
        break;
      case 1:
        // Laço no estado 1, lendo letra, dígito ou sublinhado
        if (isalpha(entrada[indice]) || isdigit(entrada[indice]) || entrada[indice] == '_')
          state = 1;
        else
          // Fim da análise
          if (entrada[indice] == '\0')
            return true;
          else
            return false; // Travamento!
         break;
    }
    indice++;
  }
}

int main(int argc, char **argv)
{
  char entrada[51];
  scanf(" %s", entrada);
  // A função equivalente ao analisador léxico deve ser executada abaixo
  if (lexi_natural_automato(entrada))
    printf("Elemento léxico aceito.\n");
  else
    printf("Houve um erro de execução: o elemento léxico especificado não foi encontrado.\n");
  return 0;
}

