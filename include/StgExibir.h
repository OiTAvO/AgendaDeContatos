// Copyright OAMP
#ifndef INCLUDE_STGEXIBIR_H_
#define INCLUDE_STGEXIBIR_H_

#include "./IStrategy.h"

class StgExibir : public IStrategy {
 public:
  void executeAction(EntidadeDominio* entidade);
};

#endif  // INCLUDE_STGEXIBIR_H_

