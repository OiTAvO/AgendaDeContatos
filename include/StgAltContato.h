// Copyright OAMP
#ifndef INCLUDE_STGALTCONTATO_H_
#define INCLUDE_STGALTCONTATO_H_

#include "./IStrategy.h"

class StgAltContato : public IStrategy {
 public:
  void executeAction(EntidadeDominio* entidade);
};

#endif  // INCLUDE_STGALTCONTATO_H_
