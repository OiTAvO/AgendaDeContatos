//  Copyright OAMP

#include "../include/Agenda.h"


Agenda::Agenda() {}

Agenda::~Agenda() {
  for (auto contato : *(getVectContato())) {
    delete(contato);
  }
  getVectContato()->clear();
}

std::vector<Contato*>* Agenda::getVectContato() {
  return &(this->contatos);
}

void Agenda::setVectContato(Contato *contato) {
  this->contatos.push_back(contato);
}
//  std::map<int, IAqr&> Agenda::getArqMap()
//{
//
//}

