//  Copyright OAMP
#include "../include/Includes.h"
#include "../include/StgSair.h"
#include "../include/Agenda.h"

void StgSair::executeAction(EntidadeDominio *entidade) {
  std::cout << "O programa sera encerrado...";
  std::cin.get();
  delete(entidade);
  exit(0);
}
