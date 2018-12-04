// Copyright OAMP
#ifndef INCLUDE_STGVOID_H_
#define INCLUDE_STGVOID_H_

#include "./IStrategy.h"

class StgVoid : public IStrategy {
 public:
  void executeAction(EntidadeDominio *entidade);
};

#endif  // INCLUDE_STGVOID_H_

