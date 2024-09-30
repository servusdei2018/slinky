#ifndef NAVIGATOR_HPP
#define NAVIGATOR_HPP

#include <stdexcept>
#include <string>
#include <vector>

/**
 * @class Navigator
 * @brief Manages a history of navigated files.
 *
 * The Navigator class stores a history of links, allowing users to
 * add new files to the navigation history and navigate back to the
 * previous files. It provides a simple interface to track the
 * current file and access previously visited files.
 *
 * Usage:
 * - Use `addToHistory` to record a new file.
 * - Use `goBack` to return to the last file in the history.
 */
class Navigator {
 public:
  // Constructor
  Navigator();

  // Adds a file to the navigation history
  void addToHistory(const std::string& file);

  // Goes back to the previous file in the history
  std::string goBack();

 private:
  std::vector<std::string> history;
  int currentIndex;
};

#endif