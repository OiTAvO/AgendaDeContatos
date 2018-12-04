// Copyright OAMP
#ifndef INCLUDE_MENUPRINCIPAL_H_
#define INCLUDE_MENUPRINCIPAL_H_

#include "./AbstractMenu.h"

class Agenda;

class MenuPrincipal : public AbstractMenu {
 public:
  MenuPrincipal(std::string opt, IStrategy *stg);
  MenuPrincipal(Agenda *agenda);
  ~MenuPrincipal();
  void run(bool flagClearScreen = true);
  void addOption(std::string novaOpt);
  void addStrategy(IStrategy *strategy);
  Agenda* getAgenda();
  void setAgenda(Agenda *agenda);

 private:
  void show(bool flagClearScreen = true);
  void selectOption();
  bool validarOpcao(int opt);
  Agenda *agenda;
};

#endif  //  INCLUDE_MENUPRINCIPAL_H_
