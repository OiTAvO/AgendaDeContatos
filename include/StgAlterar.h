// Copyright OAMP
#ifndef INCLUDE_STGALTERAR_H_
#define INCLUDE_STGALTERAR_H_

#include "./IStrategy.h"

class StgAlterar : public IStrategy {
 public:
  virtual void executeAction(EntidadeDominio *entidade);
};

#endif  //  INCLUDE_STGALTERAR_H_
