// Copyright OAMP
#include "../include/Includes.h"
#include "../include/MainIncludes.h"

void StgImportar::executeAction(EntidadeDominio *entidade) {
  Agenda *agenda = (Agenda*)entidade;
  Contato *ptr;  // ptr de Contato
  std::vector<Contato*> newVect;  // vector para receber contatos importados.
  std::string buffer;  // buffer para receber info do arq.
  std::string aux;  // string auxiliar para conversao
  std::fstream myTxt("Agenda1.txt", std::fstream::in);  // indica arq. p/ abrir.

  std::regex exp("([^;]*)");  // expressao para gerar os tokens.
  std::regex_token_iterator<std::string::iterator> tkn;  // token iterador.

  if (myTxt.is_open()) {  // Arquivo aberto?
    while (!myTxt.eof()) {  // Nao e o fim do arquivo?
      
      std::getline(myTxt, buffer);  // Recebe string do contato
      if (buffer.size() == 0) break;  // ultima linha do arquivo?
      
      newVect.push_back(new Contato());  // add new Contato ao vector.
      ptr = newVect.back();  // aponta para o endereço do new Contato.
      
      tkn = std::regex_token_iterator<std::string::iterator>
          (buffer.begin(), buffer.end(), exp);  // regex que gera os tokens.

      // tkn++ e repetido 2x para pular os \0 de cada string dos tokens.
      
      std::cout << "Importando Informacoes Pessoais dos contatos\n";
      ptr->GetPessoal()->SetNome(*tkn++); tkn++;
      aux = *tkn++; tkn++;
      ptr->GetPessoal()->SetAltura(atof(aux.c_str()));
      ptr->GetPessoal()->SetCpf(*tkn++); tkn++;
      ptr->GetPessoal()->GetDtAniver()->SetData(*tkn++); tkn++;
      aux = *tkn++; tkn++;
      ptr->GetPessoal()->SetIdade(atoi(aux.c_str()));

      std::cout << "Importando Informacoes de contato\n";
      ptr->SetEmail(*tkn++);  tkn++;
      ptr->SetTelefone(*tkn++); tkn++;

      std::cout << "Importando Informacoes de Enderecos dos contatos\n";
      ptr->GetEndereco()->SetLogradouro(*tkn++); tkn++;
      ptr->GetEndereco()->SetCep(*tkn++); tkn++;
      aux = *tkn++; tkn++;
      ptr->GetEndereco()->SetNumero(atoi(aux.c_str()));
      ptr->GetEndereco()->GetCidade()->SetNome(*tkn++); tkn++;
      ptr->GetEndereco()->GetCidade()->GetEstado()->SetNome(*tkn++); tkn++;
      ptr->GetEndereco()->GetCidade()->GetEstado()->SetSigla(*tkn++); tkn++;

      std::cout << "Importando Informacoes Academicas ds contatos\n";
      ptr->GetFormacao()->SetNmFormacao(*tkn++); tkn++;
      ptr->GetFormacao()->SetInstituicao(*tkn++); tkn++;
      ptr->GetFormacao()->SetAnoFormacao(*tkn++); tkn++;

      std::cout << "Importando Informacoes Profissionais dos contatos\n";
      ptr->GetExpProf()->SetNmEmpresa(*tkn++); tkn++;
      ptr->GetExpProf()->SetUltCargoEmp(*tkn++); tkn++;
      ptr->GetExpProf()->GetDtAdmissao()->SetData(*tkn++); tkn++;
      aux = *tkn;
      ptr->GetExpProf()->SetUltEmpresa(atoi(aux.c_str()));
    }  // end whille
    
    myTxt.close();  // fecha o arq. utilizado
    for (auto cont : *(agenda->getVectContato()))
      delete (cont);  // destroi os objetos do vector de contatos.
    agenda->getVectContato()->clear();  // limpa o vector
    agenda->getVectContato()->swap(newVect);  // troca cont. com vector local.
    std::cout << "Arq. Importado com sucesso\n"
              << "Pressione qualquer tecla para continuar...";
    std::cin.get();
  } else {
    std::cout << "Nao foi possivel abrir o arquivo"
              << "Pressione qualquer tecla para continuar...";
    std::cin.get();
  }
}
