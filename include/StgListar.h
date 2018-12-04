// Copyright OAMP
#ifndef INCLUDE_STGLISTAR_H_
#define INCLUDE_STGLISTAR_H_

#include "./IStrategy.h"

class StgListar : public IStrategy {
 public:
  void executeAction(EntidadeDominio* entidade);
};

#endif  // INCLUDE_STGLISTAR_H_

