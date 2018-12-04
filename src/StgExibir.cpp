// Copyright OAMP
#include "../include/MainIncludes.h"

void StgExibir::executeAction(EntidadeDominio* entidade) {
   Contato *contato = (Contato*)entidade;
   std::cout << *(contato) << std::endl;
   std::cout << "Pressione qualquer tecla para continuar...";
   std::cin.get();
}
