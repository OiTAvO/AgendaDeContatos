// Copyright OAMP
#ifndef INCLUDE_AGENDA_H_
#define INCLUDE_AGENDA_H_

#include "./Includes.h"
#include "./EntidadeDominio.h"
#include "./Contato.h"

class Agenda : public EntidadeDominio {
 public:
  Agenda();
  ~Agenda();
  std::vector<Contato*>* getVectContato();
  void setVectContato(Contato *contato);
  //    std::map<int, IArq*>* getArqMap();

 private:
  std::vector<Contato*> contatos;
  //    std::map<int, IArq*> mapArq;
};

#endif  // INCLUDE_AGENDA_H_

