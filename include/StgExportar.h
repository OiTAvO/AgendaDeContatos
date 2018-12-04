// Copyright OAMP
#ifndef INCLUDE_STGEXPORTAR_H_
#define INCLUDE_STGEXPORTAR_H_

#include "./IStrategy.h"

class StgExportar : public IStrategy {
 public:
  virtual void executeAction(EntidadeDominio *entidade);
};

#endif  // INCLUDE_STGEXPORTAR_H_
