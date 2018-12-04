// Copyright OAMP
#include "../include/Includes.h"
#include "../include/MainIncludes.h"

void StgExportar::executeAction(EntidadeDominio *entidade) {
  Agenda *agenda = (Agenda*)entidade;
  std::fstream myTxt ("Agenda1.txt", std::fstream::out);
  if (myTxt.is_open()) {
    for (auto contato : *(agenda->getVectContato())) {
      myTxt << contato->GetPessoal()->GetNome() << ";"
            << contato->GetPessoal()->GetAltura() << ";"
            << contato->GetPessoal()->GetCpf() << ";"
            << contato->GetPessoal()->GetDtAniver()->GetData() << ";"
            << contato->GetPessoal()->GetIdade() << ";";

      myTxt << contato->GetEmail() << ";"
            << contato->GetTelefone() << ";";

      myTxt << contato->GetEndereco()->GetLogradouro() << ";"
            << contato->GetEndereco()->GetCep() << ";"
            << contato->GetEndereco()->GetNumero() << ";"
            << contato->GetEndereco()->GetCidade()->GetNome() << ";"
            << contato->GetEndereco()->GetCidade()->GetEstado()->GetNome() << ";"
            << contato->GetEndereco()->GetCidade()->GetEstado()->GetSigla() << ";";

      myTxt << contato->GetFormacao()->GetNmFormacao() << ";"
            << contato->GetFormacao()->GetInstituicao() << ";"
            << contato->GetFormacao()->GetAnoFormacao() << ";";

      myTxt << contato->GetExpProf()->GetNmEmpresa() << ";"
            << contato->GetExpProf()->GetUltCargoEmp() << ";"
            << contato->GetExpProf()->GetDtAdmissao()->GetData() << ";"
            << contato->GetExpProf()->IsUltEmpresa() << "\n";
    }
    myTxt.close();
    std::cout << "Arq. exportado com sucesso\n"
              << "Pressione qualquer tecla para continuar...";
    std::cin.get();
  } else {
    std::cout << "Unable to open file"
              << "Pressione qualquer tecla para continuar...";
    std::cin.get();
  }
}
