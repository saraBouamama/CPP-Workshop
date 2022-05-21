#pragma once

#include <fstream>
#include <iostream>
#include <sstream>

#include "directory-info.hh"

DirectoryInfo* read_info(std::ifstream& file);
bool correct_way(std::string file);