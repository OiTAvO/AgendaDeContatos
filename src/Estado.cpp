// Copyright OAMP
#include "../include/Endereco.h"

Estado::Estado() {
  nmEstado = "ESTADO";
  siglaEstado = "XX";
}

Estado::Estado(const Estado& ptr) {
  nmEstado = ptr.nmEstado;
  siglaEstado = ptr.siglaEstado;
}

Estado::~Estado() {}

std::string Estado::GetNome() {
  return this->nmEstado;
}

void Estado::SetNome(std::string val) {
  this->nmEstado = val;
}

std::string Estado::GetSigla() {
  return this->siglaEstado;
}

void Estado::SetSigla(std::string val) {
  this->siglaEstado = val;
}

void Estado::Incluir() {
  std::string sValor;
  std::cout << "Digite o nome do Estado: ";
  std::getline(std::cin, sValor);
  nmEstado = (sValor == "\0" ? nmEstado : sValor);
  std::cout << "Digite a SIGLA do Estado: ";
  std::getline(std::cin, sValor);
  siglaEstado = (sValor == "\0" ? siglaEstado : sValor);
}

void Estado::Alterar() {
  Incluir();
}
