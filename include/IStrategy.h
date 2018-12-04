// Copyright OAMP
#ifndef INCLUDE_ISTRATEGY_H_
#define INCLUDE_ISTRATEGY_H_

#include "./Includes.h"
#include "./EntidadeDominio.h"

class IStrategy {
 public:
  virtual void executeAction(EntidadeDominio *entidade) = 0;
};

#endif  // INCLUDE_ISTRATEGY_H_
