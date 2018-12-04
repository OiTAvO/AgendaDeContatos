// Copyright OAMP
#ifndef INCLUDE_STGIMPORTAR_H_
#define INCLUDE_STGIMPORTAR_H_

#include "./IStrategy.h"

class StgImportar : public IStrategy {
 public:
  virtual void executeAction(EntidadeDominio *entidade);
};

#endif  // INCLUDE_STGIMPORTAR_H_

