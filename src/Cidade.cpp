// Copyright OAMP
#include "../include/Cidade.h"

Cidade::Cidade() {
  nmCidade = "NOME_CIDADE";
  estado = new Estado();
}

Cidade::Cidade(const Cidade& ptr) {
  nmCidade = ptr.nmCidade;
  estado = new Estado(*ptr.estado);
}

Cidade::~Cidade() {
  delete(estado);
}

std::string Cidade::GetNome() {
  return this->nmCidade;
}

void Cidade::SetNome(std::string nmCidade) {
  this->nmCidade = nmCidade;
}

Estado* Cidade::GetEstado() {
  return this->estado;
}

void Cidade::SetEstado(Estado *estado) {
  this->estado = estado;
}

void Cidade::Incluir() {
  std::string sValor;
  std::cout << "Digite o nome da cidade: ";
  std::getline(std::cin, sValor);
  nmCidade = (sValor == "\0" ? nmCidade : sValor);
  estado->Incluir();
}

void Cidade::Alterar() {
  Incluir();
}

