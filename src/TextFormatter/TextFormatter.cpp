#include "TextFormatter/TextFormatter.hpp"

#include <sstream>
#include <stdexcept>

// Constructor
TextFormatter::TextFormatter(int width) : width(static_cast<size_t>(width)) {}

// Formats the content in-place to ensure each line is no longer than the
// configured width.
void TextFormatter::formatContent(std::string& content) {
  std::istringstream stream(content);
  std::string line;
  std::vector<std::string> wrappedLines;

  while (std::getline(stream, line)) {
    if (line.empty()) {
      wrappedLines.push_back("");
      continue;
    }
    wrapText(line, wrappedLines);
  }

  content.clear();
  for (const auto& wrappedLine : wrappedLines) {
    content += wrappedLine + "\n";
  }

  if (!wrappedLines.empty()) content.pop_back();
}

void TextFormatter::wrapText(const std::string& line,
                             std::vector<std::string>& wrappedLines) {
  std::istringstream words(line);
  std::string word;
  std::string currentLine;

  while (words >> word) {
    if (word.length() > width) {
      // If a word is longer than the width, add it on a new line
      if (!currentLine.empty()) {
        wrappedLines.push_back(currentLine);
        currentLine.clear();
      }
      wrappedLines.push_back(word);
    } else {
      if (currentLine.length() + word.length() + 1 > width) {
        // If adding the word exceeds the width, save the current line and start
        // a new one
        wrappedLines.push_back(currentLine);
        currentLine = word;
      } else {
        // Add the word to the current line
        if (!currentLine.empty()) {
          currentLine += ' ';
        }
        currentLine += word;
      }
    }
  }

  if (!currentLine.empty()) wrappedLines.push_back(currentLine);
}