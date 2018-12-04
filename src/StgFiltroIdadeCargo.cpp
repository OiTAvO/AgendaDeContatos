// Copyright OAMP
#include "../include/Includes.h"
#include "../include/MainIncludes.h"

void StgFiltroIdadeCargo::executeAction(EntidadeDominio* entidade) {
  StgListar stgListar;
  Agenda *agenda = (Agenda*)entidade;
  Agenda newAgenda;
  LIMPA_TELA;
  auto sValor = [](std::string a = "") {std::getline(std::cin, a); return a;};
  int idade;
  std::string prefix("\\b(");
  std::string sufix(")\\b");
  std::string cargo;
  while (true) {
    std::cout << "Digite a idade minima: ";
    std::cin >> idade;
    std::cout << "Digite o cargo: ";
    std::cin.ignore();
    cargo = sValor();
    if (idade < 18 || cargo.size() == 0) {
      std::cout << "\nParametros de pesquisa incorretos:\n"
                <<"\nIdade minima precisa ser maior ou igual a 18 anos.\n"
                <<"\nOu filtro cargo ficou vazio.\n";
    } else {
      break;
    }
  }

  cargo = prefix + cargo + sufix;
  std::regex exp(cargo);
  std::smatch result;
  std::string ultCargo;

  for (auto contato : *(agenda->getVectContato())) {
    ultCargo = contato->GetExpProf()->GetUltCargoEmp();
    if (std::regex_search(ultCargo, result, exp) == true &&
        contato->GetPessoal()->GetIdade() >= idade) {
      newAgenda.setVectContato(new Contato(*contato));
    }
  }
  stgListar.executeAction(&newAgenda);
}
