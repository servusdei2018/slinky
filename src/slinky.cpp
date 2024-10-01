#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "AnchorProcessor/AnchorProcessor.hpp"
#include "FileHandler/FileHandler.hpp"
#include "Navigator/Navigator.hpp"
#include "TextFormatter/TextFormatter.hpp"

const std::string LOGO =
    "     _ _      _        \n"
    "  __| (_)_ _ | |___  _ \n"
    " (_-< | | ' \\| / / || |\n"
    " /__/_|_|_||_|_\\_\\_, |\n"
    "                  |__/  \n";

void displayLogo() { std::cout << LOGO; }

void displayHelp() {
  std::cout << "Commands:\n";
  std::cout << "  go <n>     - Navigate to the document associated with anchor "
               "number n\n";
  std::cout << "  open <file>- Open a specified file\n";
  std::cout << "  back       - Go back to the previous document\n";
  std::cout << "  help       - Display this help message\n";
  std::cout << "  exit       - Exit the browser\n";
}

int main() {
  std::string currentFile;
  Navigator navigator;
  FileHandler fileHandler;
  AnchorProcessor anchorProcessor;

  displayLogo();
  std::cout << "Welcome to the Slinky Web Browser!\n";
  displayHelp();

  std::cout << "Display width (default 80):  ";
  std::string widths;
  std::getline(std::cin, widths);
  const int width{std::atoi(widths.c_str()) > 0 ? std::atoi(widths.c_str())
                                                : 80};
  TextFormatter textFormatter(width);

  std::cout << "Please enter the initial file to open: ";
  std::getline(std::cin, currentFile);
  navigator.addToHistory(currentFile);

  bool changed = true;
  std::string content;
  std::vector<std::string> anchors;

  // REPL Loop
  while (currentFile != "exit") {
    // Print
    if (changed) {
      // Load content from the current file
      content = fileHandler.loadFile(currentFile);
      if (content.empty()) {
        std::cout << "Error loading file: " << currentFile << "\n";
        break;
      }

      // Parse anchors
      anchors = anchorProcessor.processAnchors(content);

      // Format and display content
      textFormatter.formatContent(content);
      std::cout << content << '\n';
      changed = false;
    }

    // Read
    std::string command;
    std::cout << "> ";
    std::getline(std::cin, command);

    // Evaluate
    if (command == "exit") {
      break;
    } else if (command == "back") {
      currentFile = navigator.goBack();
      changed = true;
    } else if (command == "help") {
      displayHelp();
    } else {
      if (command.rfind("go", 0) == 0) {
        if (command.length() < 4) {
          std::cout << "Invalid anchor number.\n";
          continue;
        }
        size_t anchor = std::stoi(command.substr(3));
        if (anchor < anchors.size()) {
          currentFile = anchors[anchor];
          navigator.addToHistory(currentFile);
          changed = true;
        } else {
          std::cout << "Invalid anchor number.\n";
        }
      } else if (command.rfind("open", 0) == 0) {
        std::string fileToOpen = command.substr(5);
        if (command.length() < 6) {
          std::cout << "Invalid filename.\n";
          continue;
        }
        if (!fileToOpen.empty()) {
          currentFile = fileToOpen;
          navigator.addToHistory(currentFile);
          changed = true;
        } else {
          std::cout << "Please specify a file to open.\n";
        }
      } else {
        std::cout << "Unknown command. Type 'help' for a list of commands.\n";
      }
    }
  }

  std::cout << "Exiting the Slinky Web Browser. Goodbye!\n";
  return 0;
}
