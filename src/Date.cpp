// Copyright OAMP

#include "../include/Date.h"

Date::Date() {
  data = "01-01-2000";
}

Date::Date(const Date& ptr) {
  data = ptr.data;
}

Date::~Date() {}

void Date::validarData(std::string& data) {
    try {
        std::regex exp("\\b([12][0-9]|0[1-9]|3[0])[-](0[0-9]|1[012])[-](19[2-9][0-9]|20[0-9][0-9])\\b");
        std::smatch result;
        if (std::regex_search(data, result, exp) == true) {
          data = result.str();
        } else {
          throw DateException();
        }
    } catch (std::exception& error) {
        throw;
    }
}

std::string Date::GetData() {
    return this->data;
}

void Date::SetData(std::string data) {
    this->validarData(data);
    this->data = data;
}

void Date::Incluir() {
  std::string sValor;

  while (true) {
    try {
      std::cout << "Digite a data: ";
      std::getline(std::cin, sValor);
      SetData(sValor == "\0" ? data : sValor);
      break;
    } catch (std::exception& error) {
      std::cout << "\n" << error.what() << std::endl;
      std::cin.get();
    }
  }
}

void Date::Alterar() {
  Incluir();
}

int Date::DiffAno() {
  int iAnoNascimento = atoi(&(GetData())[6]);
  time_t tempo;
  struct tm * tempoAtual;

  time(&tempo);
  tempoAtual = localtime(&tempo);

  return 1900 + tempoAtual->tm_year - iAnoNascimento;
}
