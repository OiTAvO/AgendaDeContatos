// Copyright OAMP
#include "../include/Includes.h"
#include "../include/MainIncludes.h"

void StgAlterar::executeAction(EntidadeDominio *entidade) {
  Agenda *agenda = (Agenda*)entidade;
  StgExibir stg;
  IStrategy *stgExec;
  MenuPrincipal altMenu("Retornar ao menu anterior", new StgRetornar());
  MenuPrincipal menu("Retornar ao menu anterior", new StgRetornar());
  std::map<int, IStrategy*> mapaDeStgs;
  mapaDeStgs[0] = new StgAltContato();
  // mapaDeStgs[1] = new StgAltPessoal();
  // mapaDeStgs[2] = new StgAltEndereco();
  // mapaDeStgs[3] = new StgAltExpProf();
  // mapaDeStgs[4] = new StgAltFormAcad();
  
  try {
    menu.setAgenda(agenda);
    for (auto cont : *(agenda->getVectContato())) {
      menu.addOption(cont->GetPessoal()->GetNome());
      menu.addStrategy(new StgVoid());
    }
    menu.setTitle("Lista de contatos");

    altMenu.setAgenda(agenda);
    altMenu.addOption("Alterar informacoes de Contato");
    // altMenu.addOption("Alterar informacoes de Endereco");
    // altMenu.addOption("Alterar informacoes Pessoais");
    // altMenu.addOption("Alterar informacoes Profissionais");
    // altMenu.addOption("Alterar informacoes Academicas");
    for (auto stg : *(altMenu.getOptMap()))
      altMenu.addStrategy(new StgVoid());
    while (true) {
      menu.run();
      LIMPA_TELA;
      stg.executeAction(agenda->getVectContato()->at(menu.getOption() -1));
      try {
        altMenu.run(false);
        stgExec = mapaDeStgs[altMenu.getOption() - 1];
        stgExec->executeAction(agenda->getVectContato()->at(menu.getOption() -1));        
      } catch (...) {
      }
    }
  } catch (...) {
    
  }
}
