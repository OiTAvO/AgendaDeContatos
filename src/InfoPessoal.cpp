#include "../include/InfoPessoal.h"

InfoPessoal::InfoPessoal() {
  nome = "NOME";
  cpf = "CPF";
  altura = -1;
  SetDtAniver(new Date());
}

InfoPessoal::InfoPessoal(const InfoPessoal& ptr) {
  nome = ptr.nome;
  cpf = ptr.cpf;
  altura = ptr.altura;
  idade = ptr.idade;
  dtAniversario = new Date(*ptr.dtAniversario);
}

InfoPessoal::~InfoPessoal() {
  delete(GetDtAniver());
}

std::string InfoPessoal::GetCpf() {
    return this->cpf;
}

std::string InfoPessoal::GetNome() {
    return this->nome;
}

Date* InfoPessoal::GetDtAniver() {
    return this->dtAniversario;
}

float InfoPessoal::GetAltura() {
    return this->altura;
}

int InfoPessoal::GetIdade() {
    return this->idade;
}

void InfoPessoal::SetCpf(std::string cpf) {
    this->cpf = cpf;
}

void InfoPessoal::SetNome(std::string nome) {
    this->nome = nome;
}

void InfoPessoal::SetDtAniver(Date *data) {
    this->dtAniversario = data;
}

void InfoPessoal::SetAltura(float altura) {
    this->altura = altura;
}

void InfoPessoal::SetIdade(int idade) {
    this->idade = idade;
}

void InfoPessoal::Incluir() {
  std::string sValor;
  std::cout << "Digite o nome do contato: ";
  std::getline(std::cin, sValor);
  nome = (sValor == "\0" ? nome : sValor);
  std::cout << "Digite a altura: ";
  std::getline(std::cin, sValor);
  altura = (sValor == "\0" ? altura : atof(sValor.c_str()));
  std::cout << "Digite o cpf: ";
  std::getline(std::cin, sValor);
  cpf = (sValor == "\0" ? cpf : sValor);
  while(true) {
    dtAniversario->Incluir();
    if (dtAniversario->DiffAno() >= 18) {
      idade = (dtAniversario->DiffAno());
      break;
    } else {
      std::cout << "\nIdade precisa ser maior que 18 anos!\n";
    }
  }
}

void InfoPessoal::Alterar() {
  Incluir();
}

std::ostream& operator<<(std::ostream& out, InfoPessoal& pessoal) {
  std::string t(4, ' ');
  std::string cabecalho = "|" + std::string((58 / 2), '-')
      + " Informacao Pessoal " + std::string((56 / 2), '-') + "|\n";
  std::string linha1 = "|Nome: " + pessoal.GetNome() + t + "CPF: "
      + pessoal.GetCpf();
  std::string linha2 = "|Data de aniversario: "
      + pessoal.GetDtAniver()->GetData() + t + "   Idade: ";
  std::string linha3 = "|Altura: ";

  out << cabecalho
      << "|" << std::setw(79) << "|\n"
      << linha1 << std::string(78 - linha1.size(), ' ') << "|\n"
      << linha2 << pessoal.GetIdade()
      << std::string(76 - linha2.size(), ' ') << "|\n"
      << linha3 << pessoal.GetAltura()
      << std::string(75 - linha3.size(), ' ') << "|\n"
      << "|" << std::setw(79) << "|\n";

  return out;
}

