// Copyright OAMP
#ifndef INCLUDE_STGREMOVER_H_
#define INCLUDE_STGREMOVER_H_

#include "./IStrategy.h"

class StgRemover : public IStrategy {
 public:
  virtual void executeAction(EntidadeDominio *entidade);
};

#endif  // INCLUDE_STGREMOVER_H_
