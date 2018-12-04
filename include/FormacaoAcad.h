// Copyright OAMP
#ifndef INCLUDE_FORMACAOACAD_H_
#define INCLUDE_FORMACAOACAD_H_

#include "./Includes.h"
#include "./EntidadeDominio.h"

class Formacao : public EntidadeDominio {
 public:
  Formacao();
  Formacao(const Formacao& ptr);
  ~Formacao();
  std::string GetNmFormacao();
  void SetNmFormacao(std::string nmFormacao);
  std::string GetInstituicao();
  void SetInstituicao(std::string instituicao);
  std::string GetAnoFormacao();
  void SetAnoFormacao(std::string anoFormacao);
  void Incluir();
  void Alterar();

  friend std::ostream& operator<<(std::ostream &out, Formacao &point);

 private:
  std::string nmFormacao;
  std::string instituicao;
  std::string anoFormacao;
};

#endif  // INCLUDE_FORMACAOACAD_H_

