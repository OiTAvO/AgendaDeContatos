// Copyright OAMP
#ifndef INCLUDE_ENDERECO_H_
#define INCLUDE_ENDERECO_H_

#include "./Includes.h"
#include "./EntidadeDominio.h"
#include "Cidade.h"

class Endereco : public EntidadeDominio {
 public:
  Endereco();
  Endereco(const Endereco& ptr);
  ~Endereco();
  std::string GetCep();
  void SetCep(std::string cep);
  int GetNumero();
  void SetNumero(int numero);
  std::string GetLogradouro();
  void SetLogradouro(std::string logradouro);
  Cidade* GetCidade();
  void SetCidade(Cidade *cidade);
  void Incluir();
  void Alterar();

  friend std::ostream& operator<<(std::ostream &out, Endereco &point);

 private:
  std::string cep;
  int numero;
  std::string logradouro;
  Cidade *cidade;
};
#endif  // INCLUDE_ENDERECO_H_
