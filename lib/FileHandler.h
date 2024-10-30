#pragma once

#include "University.h"
#include "TableConverter.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<University> readFile(const string& fileName);