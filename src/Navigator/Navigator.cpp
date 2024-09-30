#include "Navigator/Navigator.hpp"

Navigator::Navigator() : currentIndex(-1) {}

// Adds a file to the navigation history.
void Navigator::addToHistory(const std::string& file) {
  if (currentIndex + 1 < static_cast<int>(history.size())) {
    history.resize(currentIndex + 1);  // Resize to discard forward history
  }
  history.push_back(file);
  currentIndex++;
}

// Goes back to the previous file in the history.
std::string Navigator::goBack() {
  if (currentIndex <= 0) {
    throw std::out_of_range("No previous file in history.");
  }
  return history[--currentIndex];
}
