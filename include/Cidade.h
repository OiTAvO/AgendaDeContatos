// COpyright OMAP
#ifndef INCLUDE_CIDADE_H_
#define INCLUDE_CIDADE_H_

#include "./Includes.h"
#include "./EntidadeDominio.h"
#include "Estado.h"

class Cidade : public EntidadeDominio {
 public:
  Cidade();
  Cidade(const Cidade& ptr);
  ~Cidade();
  std::string GetNome();
  void SetNome(std::string nmCidade);
  Estado* GetEstado();
  void SetEstado(Estado *estado);
  void Incluir();
  void Alterar();

 private:
  std::string nmCidade;
  Estado *estado;
};


#endif  // INCLUDE_CIDADE_H_
