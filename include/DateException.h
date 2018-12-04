// Copyright OMAP
#ifndef INCLUDE_DATEEXCEPTION_H_
#define INCLUDE_DATEEXCEPTION_H_

#include "./Includes.h"

class DateException : public std::exception {
 public:
  DateException();
  virtual ~DateException();
  virtual const char* what() const noexcept;
};

#endif  // INCLUDE_DATEEXCEPTION_H_
