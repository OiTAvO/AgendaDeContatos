// Copyright OAMP
#ifndef INCLUDE_STGRETORNAR_H_
#define INCLUDE_STGRETORNAR_H_
#include "./IStrategy.h"

class StgRetornar : public IStrategy {
 public:
  void executeAction(EntidadeDominio* entidade);
};

#endif  // INCLUDE_STGRETORNAR_H_
