// Copyright OAMP
#include "../include/Endereco.h"

Endereco::Endereco() {
  logradouro = "LOGRADOURO";
  cep = "XXXXX-XXX";
  numero = -1;
  cidade = new Cidade();
}

Endereco::~Endereco() {
  delete(cidade);
}

Endereco::Endereco(const Endereco& ptr) {
  logradouro = ptr.logradouro;
  cep = ptr.cep;
  numero = ptr.numero;
  cidade = new Cidade(*ptr.cidade);
}

std::string Endereco::GetCep() {
    return this->cep;
}

void Endereco::SetCep(std::string cep) {
    this->cep = cep;
}

int Endereco::GetNumero() {
    return this->numero;
}

void Endereco::SetNumero(int numero) {
    this->numero = numero;
}

std::string Endereco::GetLogradouro() {
    return this->logradouro;
}

void Endereco::SetLogradouro(std::string logradouro) {
    this->logradouro = logradouro;
}

Cidade* Endereco::GetCidade() {
    return this->cidade;
}
void Endereco::SetCidade(Cidade *cidade) {
    this->cidade = cidade;
}

void Endereco::Incluir() {
  std::string sValor;
  std::cout << "Digite o logradouro do endereco: ";
  std::getline(std::cin, sValor);
  logradouro = (sValor == "\0" ? logradouro : sValor);
  std::cout << "Digite o CEP do endereco: ";
  std::getline(std::cin, sValor);
  cep = (sValor == "\0" ? cep : sValor);
  std::cout << "Digite o numero do endereco: ";
  std::getline(std::cin, sValor);
  numero = (sValor == "\0" ? numero : (atoi(sValor.c_str())));
  cidade->Incluir();
}

void Endereco::Alterar() {
  Incluir();
}

std::ostream& operator<< (std::ostream &out, Endereco &point) {
    std::string cabecalho = "|" + std::string((68 / 2), '-') + " Endereco "
        + std::string((68 / 2) - 1, '-') + "|\n";
    std::string linha1 = "|Logradouro: " + point.GetLogradouro()
        + std::string(14, ' ') + "Numero: ";
    std::string linha2 = "|CEP: " + point.GetCep() + std::string(24, ' ')
        + "Cidade: " + point.GetCidade()->GetNome();
    std::string linha3 = "|Estado: " + point.GetCidade()->GetEstado()->GetNome()
        + std::string(21, ' ') + "SIGLA: "
        + point.GetCidade()->GetEstado()->GetSigla();

  out << cabecalho
  << "|" << std::setw(79) << "|\n"
  << linha1 << point.GetNumero() << std::string(75 - linha1.size(), ' ') << "|\n"
  << linha2 << std::string(78 - linha2.size(), ' ') << "|\n"
  << linha3 << std::string(78 - linha3.size(), ' ') << "|\n"
  << "|" << std::setw(79) << "|\n";

  return out;
}
