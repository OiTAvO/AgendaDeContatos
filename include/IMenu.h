// Copyright OAMP
#ifndef INCLUDE_IMENU_H_
#define INCLUDE_IMENU_H_

#include "./Includes.h"

class IMenu {
 public:
  virtual void show(bool flagClearScreen = true) = 0;
  virtual void run(bool flagClearScreen = true) = 0;
  virtual std::string className() const = 0;
  virtual void selectOption() = 0;
  virtual bool validarOpcao(int opt) = 0;
};

#endif  //  INCLUDE_IMENU_H_
