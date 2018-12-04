// Copyright OAMP
#include "../include/Includes.h"
#include "../include/MainIncludes.h"

void StgAltContato::executeAction(EntidadeDominio* entidade) {
  Contato *contato = (Contato*)entidade;
  std::cout << "Para os campos sem alteracao, tecle apenas enter\n";
  contato->Alterar();
}
