#ifndef TEXTFORMATTER_HPP
#define TEXTFORMATTER_HPP

#include <string>
#include <vector>

class TextFormatter {
 public:
  // Constructor
  TextFormatter(int width);

  // Formats the content in-place to ensure each line is no longer than the
  // configured width.
  void formatContent(std::string& content);

 private:
  size_t width;
  void wrapText(const std::string& line,
                std::vector<std::string>& wrappedLines);
};

#endif