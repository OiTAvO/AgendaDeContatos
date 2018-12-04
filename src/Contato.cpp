#include "../include/Contato.h"
#include <iostream>
#include <iomanip>

Contato::Contato() {
  email = "EMAIL";
  telefone = "TELEFONE";
  endereco = new Endereco();
  pessoal = new InfoPessoal();
  formacao = new Formacao();
  expProf = new ExpProfissional();
}

Contato::~Contato() {
  delete(endereco);
  delete(pessoal);
  delete(formacao);
  delete(expProf);
}

Contato::Contato(const Contato& ptr) {
  email = ptr.email;
  telefone = ptr.telefone;
  endereco = new Endereco(*ptr.endereco);
  pessoal = new InfoPessoal(*ptr.pessoal);
  formacao = new Formacao(*ptr.formacao);
  expProf = new ExpProfissional(*ptr.expProf);
}

std::string Contato::GetEmail() {
    return this->email;
}

std::string Contato::GetTelefone() {
    return this->telefone;
}

InfoPessoal* Contato::GetPessoal() {
    return this->pessoal;
}

Endereco* Contato::GetEndereco() {
    return this->endereco;
}

Formacao* Contato::GetFormacao() {
    return this->formacao;
}

ExpProfissional* Contato::GetExpProf() {
    return this->expProf;
}

void Contato::SetEmail(std::string email) {
    this->email = email;
}

void Contato::SetTelefone(std::string telefone) {
    this->telefone = telefone;
}

void Contato::SetPessoal(InfoPessoal *pessoal) {
    this->pessoal = pessoal;
}

void Contato::SetEndereco(Endereco *endereco) {
    this->endereco = endereco;
}

void Contato::SetFormacao(Formacao *formacao) {
    this->formacao = formacao;
}

void Contato::SetExpProf(ExpProfissional *expProf) {
    this->expProf = expProf;
}

void Contato::Incluir() {
  std::string sValor;
  std::cout << "\nDigite o email do contato: ";
  std::getline(std::cin, sValor);
  email = (sValor == "\0" ? email : sValor);
  std::cout << "Digite o telefone do contato: ";
  std::getline(std::cin, sValor);
  telefone = (sValor == "\0" ? telefone : sValor);
}

void Contato::Alterar() {
  Incluir();
}

std::ostream& operator<<(std::ostream& out, Contato& contato) {
  std::string t(4, ' ');
  std::string cabecalho = "|" + std::string((71 / 2) - 0.5, '*')
      + " Contato " + std::string((71 / 2) - 0.5, '*') + "|\n";
  std::string linha1 = "|Telefone: " + contato.GetTelefone()
      + t + t + t + "Email: " +contato.GetEmail();

  out << cabecalho
      << "|" << std::setw(79) << "|\n"
      << linha1 << std::string(78 - linha1.size(), ' ') << "|\n"
      << "|" << std::setw(79) << "|\n"
      << *(contato.GetPessoal())
      << *(contato.GetEndereco())
      << *(contato.GetExpProf())
      << *(contato.GetFormacao())
      << "|" << std::string(77, '*') << "|\n";

  return out;
}
