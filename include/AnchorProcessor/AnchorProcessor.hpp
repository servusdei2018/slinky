#ifndef ANCHOR_PROCESSOR_HPP
#define ANCHOR_PROCESSOR_HPP

#include <regex>
#include <string>
#include <vector>

/**
 * @class AnchorProcessor
 * @brief Processes anchor tags in text content.
 *
 * The AnchorProcessor class detects and transforms anchor tags
 * in the format <a filename text> into a more readable format
 * <text>[n], where n is a unique identifier for each anchor
 * within the document, starting from 0. The class also collects
 * the filenames associated with the anchors.
 *
 * Usage:
 * - Use `processAnchors` with a reference to a string containing
 *   the text to be processed. This method modifies the string
 *   in place and returns a vector of filenames.
 * - The returned vector contains filenames corresponding to each
 *   anchor found, with the index representing the unique identifier.
 */
class AnchorProcessor {
 public:
  // Processes anchor tags in text content.
  std::vector<std::string> processAnchors(std::string &content);
};

#endif