// Copyright OAMP
#ifndef INCLUDE_DATE_H_
#define INCLUDE_DATE_H_

#include "./Includes.h"
#include "./EntidadeDominio.h"
#include "DateException.h"

class Date : public EntidadeDominio {
 public:
  Date();
  Date(const Date& ptr);
  virtual ~Date();
  std::string GetData();
  void SetData(std::string data);
  void Incluir();
  void Alterar();
  int DiffAno();

 private:
  std::string data;
  void validarData(std::string& data);
};

#endif  // INCLUDE_DATE_H_
