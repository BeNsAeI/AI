#ifndef PRINT_H
#define PRINT_H

#include <unordered_map>
#include "ReadFile.h"
#include "Tree.h"

using std::string;

void print(std::unordered_map<string, string> &hash, string key,ReadFile &myfile);

#endif