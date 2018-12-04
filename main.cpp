// Copyright OAMP

#include "./include/MainIncludes.h"
int main(int argc, char *argv[]) {
  
  Agenda *agenda = new Agenda();
  MenuPrincipal menu(agenda);
  menu.setTitle("Menu Principal");
  while (true) {
    menu.run();
  }
  return 0;
}
