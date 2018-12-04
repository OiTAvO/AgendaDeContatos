// Copyright OAMP
#include "../include/MainIncludes.h"

void StgIncluir::executeAction(EntidadeDominio *entidade) {
  LIMPA_TELA;
  Agenda *agenda = (Agenda*)entidade;
  if (agenda->getVectContato()->size() < 100) {
    agenda->setVectContato(new Contato());
    agenda->getVectContato()->back()->GetPessoal()->Incluir();
    std::cout << "\n";
    agenda->getVectContato()->back()->Incluir();
    std::cout << "\n";
    agenda->getVectContato()->back()->GetEndereco()->Incluir();
    std::cout << "\n";
    agenda->getVectContato()->back()->GetFormacao()->Incluir();
    std::cout << "\n";
    agenda->getVectContato()->back()->GetExpProf()->Incluir();
    std::cout << "\nContato cadastrado"
              << "\nPressione qualque tecla para continuar...";
    std::cin.get();
  } else {
    std::cout << "A agenda atingiu a sua capacidade máxima,"
              << "\npara incluir novos contatos apague alguns contatos"
              << "\nou exporte a agenda para algum arquivo\n";
    std::cout << "Pressione qualquer tecla para continuar...";
    std::cin.get();
  }
}
