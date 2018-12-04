//  Copyright OAMP
#include "../include/ExpProfissional.h"
#include <iomanip>

ExpProfissional::ExpProfissional() {
  nmEmpresa = "EMPRESA";
  ultCargoEmp = "ULTIMO_CARGO";
  ultEmpresa = false;
  SetDtAdmissao(new Date());
}

ExpProfissional::ExpProfissional(const ExpProfissional& ptr) {
  nmEmpresa = ptr.nmEmpresa;
  ultCargoEmp = ptr.ultCargoEmp;
  ultEmpresa = ptr.ultEmpresa;
  dtAdmissao = new Date(*ptr.dtAdmissao);
}

ExpProfissional::~ExpProfissional() {
  delete(GetDtAdmissao());
}

std::string ExpProfissional::GetNmEmpresa() {
  return this->nmEmpresa;
}

std::string ExpProfissional::GetUltCargoEmp() {
  return this->ultCargoEmp;
}

Date* ExpProfissional::GetDtAdmissao() {
  return this->dtAdmissao;
}

bool ExpProfissional::IsUltEmpresa() {
  return this->ultEmpresa;
}

void ExpProfissional::SetNmEmpresa(std::string nmEmpresa) {
  this->nmEmpresa = nmEmpresa;
}

void ExpProfissional::SetUltCargoEmp(std::string ultCargoEmp) {
  this->ultCargoEmp = ultCargoEmp;
}

void ExpProfissional::SetDtAdmissao(Date *dtAdmissao) {
  this->dtAdmissao = dtAdmissao;
}

void ExpProfissional::SetUltEmpresa(bool ultEmpresa) {
  this->ultEmpresa = ultEmpresa;
}

void ExpProfissional::Incluir() {
  std::string sValor;
  std::cout << "Digite o nome da ultima empresa: ";
  std::getline(std::cin, sValor);
  nmEmpresa = (sValor == "\0" ? nmEmpresa : sValor);
  std::cout << "Digite o ultimo cargo: ";
  std::getline(std::cin, sValor);
  ultCargoEmp = (sValor == "\0" ? ultCargoEmp : sValor);
  dtAdmissao->Incluir();
  std::cout << "\nEh a ultima empresa (0 ou 1)? ";
  std::getline(std::cin, sValor);
  ultEmpresa = (sValor == "\0" ? ultEmpresa : atoi(sValor.c_str()));
}

void ExpProfissional::Alterar() {
  Incluir();
}

std::ostream& operator<< (std::ostream &out, ExpProfissional &point) {
  std::string cabecalho = "|" + std::string((54 / 2) - 1, '-')
      + " Experiencia Profissional " + std::string((52 / 2) - 1, '-') + "|\n";
  std::string linha1 = "|Ultima empresa: " + point.GetNmEmpresa();
  std::string linha2 = "|Data de admissao: " + point.GetDtAdmissao()->GetData();
  std::string linha3 = "|Ultimo cargo: " + point.GetUltCargoEmp();


  out << cabecalho
      << "|" << std::setw(79) << "|\n"
      << linha1 << std::string(78 - linha1.size(), ' ') << "|\n"
      << linha2 << std::string(78 - linha2.size(), ' ') << "|\n"
      << linha3 << std::string(78 - linha3.size(), ' ') << "|\n"
      << "|" << std::setw(79) << "|\n";

  return out;
}
