// Copyright OAMP
#include <iomanip>
#include "../include/FormacaoAcad.h"

Formacao::Formacao() {
  nmFormacao = "FORMACAO";
  instituicao = "FACULDADE";
  anoFormacao = "ANO_DE_FORMACAO";
}

Formacao::Formacao(const Formacao& ptr) {
  nmFormacao = ptr.nmFormacao;
  instituicao = ptr.instituicao;
  anoFormacao = ptr.anoFormacao;
}

Formacao::~Formacao() {}

std::string Formacao::GetNmFormacao() {
  return this->nmFormacao;
}

void Formacao::SetNmFormacao(std::string nmFormacao) {
  this->nmFormacao = nmFormacao;
}

std::string Formacao::GetInstituicao() {
  return this->instituicao;
}

void Formacao::SetInstituicao(std::string instituicao) {
  this->instituicao = instituicao;
}

std::string Formacao::GetAnoFormacao() {
  return this->anoFormacao;
}

void Formacao::SetAnoFormacao(std::string anoFormacao) {
  this->anoFormacao = anoFormacao;
}

void Formacao::Incluir() {
  std::string sValor;
  std::cout << "Digite a formacao do contato: ";
  std::getline(std::cin, sValor);
  nmFormacao = (sValor == "\0" ? nmFormacao : sValor);
  std::cout << "Digite o nome da Instituicao: ";
  std::getline(std::cin, sValor);
  instituicao = (sValor == "\0" ? instituicao : sValor);
  std::cout << "Digite o ano de formacao: ";
  std::getline(std::cin, sValor);
  anoFormacao = (sValor == "\0" ? anoFormacao : sValor);
}

void Formacao::Alterar() {
  Incluir();
}

std::ostream& operator<< (std::ostream &out, Formacao &point) {
  std::string cabecalho = "|" + std::string((58 / 2), '-')
      + " Formacao academica " + std::string((58 / 2) - 1, '-') + "|\n";
  std::string linha1 = "|Formacao: " + point.GetNmFormacao();
  std::string linha2 = "|Instituicao: " + point.GetInstituicao();
  std::string linha3 = "|Ano de conclusao: " + point.GetAnoFormacao();

  out << cabecalho
  << "|" << std::setw(79) << "|\n"
  << linha1 << std::string(78 - linha1.size(), ' ') << "|\n"
  << linha2 << std::string(78 - linha2.size(), ' ') << "|\n"
  << linha3 << std::string(78 - linha3.size(), ' ') << "|\n"
  << "|" << std::setw(79) << "|\n";

  return out;
}
