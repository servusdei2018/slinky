#include "FileHandler/FileHandler.hpp"

#include <fstream>
#include <sstream>

FileHandler::FileHandler() {}

// Loads the content of a file and returns it as a string.
//
// If an error occurs or the file is empty, returns an empty string.
std::string FileHandler::loadFile(const std::string& file) {
  std::ifstream f(file);
  std::stringstream buf;

  return f ? (buf << f.rdbuf(), buf.str()) : "";
}