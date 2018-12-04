// Copyright OAMP
#include "../include/MainIncludes.h"

void StgListar::executeAction(EntidadeDominio* entidade) {
  Agenda *agenda = (Agenda*)entidade;
  StgExibir stg;
  MenuPrincipal menu("Retornar ao menu anterior", new StgRetornar());

  try {
    menu.setAgenda(agenda);
    for (auto cont : *(agenda->getVectContato())) {
      menu.addOption(cont->GetPessoal()->GetNome());
      menu.addStrategy(new StgVoid());
    }
    menu.setTitle("Lista de contatos");
    while (true) {
      menu.run();
      LIMPA_TELA;
      stg.executeAction(agenda->getVectContato()->at(menu.getOption() - 1));
    }
  } catch (...) {
  }
}
