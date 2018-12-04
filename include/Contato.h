// Copyright OAMP
#ifndef INCLUDE_CONTATO_H_
#define INCLUDE_CONTATO_H_

#include "./Includes.h"  // call headers from c++
#include "./EntidadeDominio.h"
#include "Endereco.h"
#include "ExpProfissional.h"
#include "FormacaoAcad.h"
#include "InfoPessoal.h"

class Contato : public EntidadeDominio {
 public:
  Contato();
  Contato(const Contato& ptr);
  ~Contato();
  std::string GetEmail();
  std::string GetTelefone();
  InfoPessoal* GetPessoal();
  Endereco* GetEndereco();
  Formacao* GetFormacao();
  ExpProfissional* GetExpProf();

  void SetEmail(std::string email);
  void SetTelefone(std::string telefone);
  void SetPessoal(InfoPessoal *pessoal);
  void SetEndereco(Endereco *endereco);
  void SetFormacao(Formacao *formacao);
  void SetExpProf(ExpProfissional *expProf);
  void Incluir();
  void Alterar();

  friend std::ostream& operator<<(std::ostream& out, Contato& contato);


 private:
  std::string email;
  std::string telefone;
  InfoPessoal *pessoal;
  Endereco *endereco;
  Formacao *formacao;
  ExpProfissional *expProf;
};

#endif  // INCLUDE_CONTATO_H_
