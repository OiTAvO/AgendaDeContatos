// Copyright OAMP
#include "../include/MainIncludes.h"

void StgRemover::executeAction(EntidadeDominio *entidade) {
  Agenda *agenda = (Agenda*)entidade;
  MenuPrincipal menu("Retornar ao menu anterior", new StgRetornar());

  try {
    menu.setAgenda(agenda);
    for (auto cont : *(agenda->getVectContato())) {
      menu.addOption(cont->GetPessoal()->GetNome());
      menu.addStrategy(new StgVoid());
    }
    menu.setTitle("Lista de contatos - Remover");
    menu.run();
    const int opt = menu.getOption();
    std::cout << "O contato "
              << agenda->getVectContato()->at(menu.getOption() - 1)->GetPessoal()->GetNome()
              << " foi deletado\n";
    delete((agenda->getVectContato()->at(menu.getOption() - 1)));
    agenda->getVectContato()
        ->erase(agenda->getVectContato()->begin() + opt - 1);
  } catch (...) {
  }
}
