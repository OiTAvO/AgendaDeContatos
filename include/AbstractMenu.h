// Copyright OAMP
#ifndef INCLUDE_ABSTRACTMENU_H_
#define INCLUDE_ABSTRACTMENU_H_

#include "./Includes.h"
#include "./IMenu.h"
#include "./IStrategy.h"

class IStrategy;

class AbstractMenu : public IMenu {
 public:
  virtual ~AbstractMenu() {}
  virtual std::string getTitle() const { return this->title; }
  virtual void setTitle(const std::string title) { this->title = title;}
  std::string className() const {return typeid(*this).name();}
  int getOption() const {return this->option;}
  std::map<int, std::string>* getOptMap() {return &(this->mapOptions);}
  std::map<int, IStrategy*>* getStgMap() {return &(this->mapStg);}
  virtual void addOption(std::string newOpt) = 0;
  virtual void addStrategy(IStrategy *strategy) = 0;
  
 protected:
  std::map<int, std::string> mapOptions;
  std::map<int, IStrategy*> mapStg;
  std::string title;
  int option;
};


#endif  // INCLUDE_ABSTRACTMENU_H_


