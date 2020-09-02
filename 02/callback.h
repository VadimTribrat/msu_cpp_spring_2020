#pragma once
#include <string>

void onNumber(void(*)(int));
void onSym(void(*)(const std::string &));
void first(void(*)());
void last(void(*)());
void parse(const std::string &);
