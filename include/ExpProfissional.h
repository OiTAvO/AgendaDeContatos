// Copyright OAMP
#ifndef INCLUDE_EXPPROFISSIONAL_H_
#define INCLUDE_EXPPROFISSIONAL_H_

#include "./Includes.h"
#include "./EntidadeDominio.h"
#include "./Date.h"

class ExpProfissional : public EntidadeDominio {
 public:
  ExpProfissional();
  ExpProfissional(const ExpProfissional& ptr);
  ~ExpProfissional();
  std::string GetNmEmpresa();
  std::string GetUltCargoEmp();
  Date* GetDtAdmissao();
  bool IsUltEmpresa();
  void SetNmEmpresa(std::string nmEmpresa);
  void SetUltCargoEmp(std::string ultCargoEmp);
  void SetDtAdmissao(Date *dtAdmissao);
  void SetUltEmpresa(bool ultEmpresa);
  void Incluir();
  void Alterar();

  friend std::ostream& operator<<(std::ostream &out, ExpProfissional &point);

 private:
  std::string nmEmpresa;
  std::string ultCargoEmp;
  Date *dtAdmissao;
  bool ultEmpresa;
};

#endif  //  INCLUDE_EXPPROFISSIONAL_H_
