#include "../include/DateException.h"

DateException::DateException(){}

DateException::~DateException(){}

const char* DateException::what() const noexcept {
    return "Data invalida ou fora de formatacao.";
}
