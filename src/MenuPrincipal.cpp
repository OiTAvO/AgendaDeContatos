// Copyright OAMP
#include "../include/MainIncludes.h"

MenuPrincipal::MenuPrincipal(std::string opt, IStrategy *stg) {
  mapOptions[0] = opt;
  mapStg[0] = stg;
}

MenuPrincipal::MenuPrincipal(Agenda *agenda) {
  this->setAgenda(agenda);

  mapOptions[0] = "Sair do Programa";
  mapOptions[1] = "Incluir Contato";
  mapOptions[2] = "Alterar Contato";
  mapOptions[3] = "Pesquisar Contato";
  mapOptions[4] = "Remover Contato";
  mapOptions[5] = "Exportar arquivo";
  mapOptions[6] = "Importar Arquivo";

  mapStg[0] = new StgSair();
  mapStg[1] = new StgIncluir();
  mapStg[2] = new StgAlterar();
  mapStg[3] = new StgPesquisar();
  mapStg[4] = new StgRemover();
  mapStg[5] = new StgExportar();
  mapStg[6] = new StgImportar();
}

MenuPrincipal::~MenuPrincipal() {
  for (auto& stg : mapStg)
    delete(stg.second);
}

void MenuPrincipal::addOption(std::string newOpt) {
  mapOptions[mapOptions.size()] = newOpt;
}

void MenuPrincipal::addStrategy(IStrategy* strategy) {
  mapStg[mapStg.size()] = strategy;
}

void MenuPrincipal::selectOption() {
  int opt;
  std::cin >> opt;
  std::cin.ignore();
  this->option = opt;
}

bool MenuPrincipal::validarOpcao(int opt) {
  if (mapOptions.find(opt) != mapOptions.end()) {
    getStgMap()->find(opt)->second->executeAction(agenda);
    return true;
  } else {
    return false;
  }
}

void MenuPrincipal::show(bool flagClearScreen) {
  int PosXMenu = this->getTitle().size();
  if (flagClearScreen)
    LIMPA_TELA;
  std::cout << std::setw(40 + (PosXMenu / 2)) << this->getTitle() << std::endl
            << "Opcoes: \n\n";

  for (auto& option : mapOptions) {
    std::cout << option.first << " " << option.second << std::endl;
  }

  std::cout << "\nEscolha uma opcao: ";
}

void MenuPrincipal::run(bool flagClearScreen) {
  while (true) {
    show(flagClearScreen);
    selectOption();
    if (validarOpcao(getOption()) == false) {
      std::cout << "Opcao incorreta.\n"
                << "Pressione qualquer tecla para continuar...";
      std::cin.get();
    } else {
      break;
    }
  }
}

Agenda* MenuPrincipal::getAgenda() {
  return this->agenda;
}

void MenuPrincipal::setAgenda(Agenda* agenda) {
  this->agenda = agenda;
}