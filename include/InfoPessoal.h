// Copyright OAMP
#ifndef INCLUDE_INFOPESSOAL_H_
#define INCLUDE_INFOPESSOAL_H_

#include "./Includes.h"
#include "./Date.h"
#include "./EntidadeDominio.h"

class InfoPessoal : public EntidadeDominio {
 public:
  InfoPessoal();
  InfoPessoal(const InfoPessoal& ptr);
  virtual ~InfoPessoal();

  std::string GetCpf();
  void SetCpf(std::string val);
  std::string GetNome();
  void SetNome(std::string val);
  Date* GetDtAniver();
  void SetDtAniver(Date *data);
  float GetAltura();
  void SetAltura(float val);
  int GetIdade();
  void SetIdade(int val);
  void Incluir();
  void Alterar();

  friend std::ostream& operator<<(std::ostream& out, InfoPessoal& pessoal);

 private:
  std::string cpf;
  std::string nome;
  Date *dtAniversario;
  float altura;
  int idade;
};

#endif  // INCLUDE_INFOPESSOAL_H_
