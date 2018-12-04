// Copyright OAMP
#ifndef INCLUDE_STGINCLUIR_H_
#define INCLUDE_STGINCLUIR_H_

#include "./IStrategy.h"

class StgIncluir : public IStrategy {
 public:
  virtual void executeAction(EntidadeDominio *entidade);
};

#endif  // INCLUDE_STGINCLUIR_H_
