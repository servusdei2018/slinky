#include "AnchorProcessor/AnchorProcessor.hpp"

#include <sstream>
#include <vector>

// Processes anchor tags in text content.
std::vector<std::string> AnchorProcessor::processAnchors(std::string &content) {
  std::vector<std::string> anchors;
  std::ostringstream transformed;

  std::string filename, text;
  int id = 0;
  bool inAnchor = false;
  std::string currentToken;

  for (char c : content) {
    if (c == '<') {
      if (currentToken.size() > 0) {
        transformed << currentToken;
        currentToken.clear();
      }
      inAnchor = true;
      currentToken += c;
    } else if (c == '>') {
      currentToken += c;
      if (inAnchor) {
        // Anchor closed
        std::string inner =
            currentToken.substr(3, currentToken.size() - 4);  // Remove <a and >
        std::istringstream innerStream(inner);

        // Parse filename and text
        innerStream >> filename >> text;
        transformed << "<" << text << ">[" << id << "]";
        anchors.push_back(filename);
        id++;

        inAnchor = false;
        currentToken.clear();
      }
    } else {
      currentToken += c;
    }
  }

  // Add any remaining text
  if (!currentToken.empty()) {
    transformed << currentToken;
  }

  content = transformed.str();
  return anchors;
}