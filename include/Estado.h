// Copyright OAMP
#ifndef INCLUDE_ESTADO_H_
#define INCLUDE_ESTADO_H_

#include "./Includes.h"
#include "./EntidadeDominio.h"

class Estado : public EntidadeDominio {
 public:
  Estado();
  Estado(const Estado& ptr);
  ~Estado();
  std::string GetNome();
  void SetNome(std::string val);
  std::string GetSigla();
  void SetSigla(std::string val);
  void Incluir();
  void Alterar();

 private:
  std::string nmEstado;
  std::string siglaEstado;
};

#endif  // INCLUDE_ESTADO_H_
