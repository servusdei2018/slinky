#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <string>

/**
 * @class FileHandler
 * @brief Handles file loading operations.
 *
 * The FileHandler class provides functionality to load the contents
 * of files as strings. It is designed to ignore any errors that may
 * occur during file operations, returning an empty string in case
 * of failure.
 *
 * Usage:
 * - Use `loadFile` with a file path to retrieve the file's content.
 * - If the file cannot be loaded, an empty string will be returned.
 */
class FileHandler {
 public:
  // Constructor
  FileHandler();

  // Loads the content of a file and returns it as a string.
  //
  // If an error occurs or the file is empty, returns an empty string.
  std::string loadFile(const std::string& file);
};

#endif