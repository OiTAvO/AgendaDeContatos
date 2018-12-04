// Copyright OAMP
#ifndef INCLUDE_STGPESQUISAR_H_
#define INCLUDE_STGPESQUISAR_H_

#include "./IStrategy.h"

class StgPesquisar : public IStrategy {
 public:
  virtual void executeAction(EntidadeDominio *entidade);
};

#endif  // INCLUDE_STGPESQUISAR_H_
