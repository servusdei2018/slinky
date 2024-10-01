#ifndef TEXTFORMATTER_HPP
#define TEXTFORMATTER_HPP

#include <string>
#include <vector>

/**
 * @class TextFormatter
 * @brief Formats text content to ensure it adheres to a specified line width.
 *
 * The TextFormatter class is responsible for formatting text content by 
 * wrapping lines to a specified maximum width.
 * 
 * The formatting is performed in-place on the provided content string.
 *
 * Usage:
 * - Create an instance of TextFormatter with a desired line width.
 * - Use `formatContent` to format the text, which modifies the input string.
 */
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