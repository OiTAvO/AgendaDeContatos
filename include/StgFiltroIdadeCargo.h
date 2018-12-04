// Copyright OAMP
#ifndef INCLUDE_STGFILTROIDADECARGO_H_
#define INCLUDE_STGFILTROIDADECARGO_H_

#include "./IStrategy.h"

class StgFiltroIdadeCargo : public IStrategy {
 public:
  void executeAction(EntidadeDominio* entidade);
};

#endif  // INCLUDE_STGFILTROIDADECARGO_H_
