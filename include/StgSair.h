// Copyright OAMP
#ifndef INCLUDE_STGSAIR_H_
#define INCLUDE_STGSAIR_H_

#include "./IStrategy.h"

class StgSair : public IStrategy {
 public:
  virtual void executeAction(EntidadeDominio *entidade);
};

#endif  // INCLUDE_STGSAIR_H_
