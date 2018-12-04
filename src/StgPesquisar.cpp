// Copyright OAMP
#include "../include/MainIncludes.h"

void StgPesquisar::executeAction(EntidadeDominio *entidade) {
  Agenda *agenda = (Agenda*)entidade;
  MenuPrincipal mnPesquisa("Retornar ao menu", new StgRetornar());
  try {
    mnPesquisa.setAgenda(agenda);
    mnPesquisa.addOption("Listar Contatos");
    mnPesquisa.addStrategy(new StgListar());
    mnPesquisa.addOption("Filtrar por idade e cargo");
    mnPesquisa.addStrategy(new StgFiltroIdadeCargo());
    mnPesquisa.setTitle("Menu de Pesquisa");
    while (true) {
      mnPesquisa.run();
    }
  } catch (...) {
  }
}
