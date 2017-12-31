#include "argparse/parser.h"

#include <iostream>

int main(int argc, char** argv) {

  Argparse::Parser parser;
  parser.addArgument("--detailed", "Make everything detailed");
  parser.addArgument("--ignore", "Ignore everything");
  parser.getArgument("--ignore")->setDefaultValue("defval");

  try {
    parser.parse(argc, argv);
  } catch (const std::invalid_argument& s) {
    std::cerr << "Parsing arguments failed with:\n  ";
    std::cerr << s.what() << std::endl;
    return -1;
  }

  std::cout << "Exiting program gracefully." << std::endl;
  return 0;
}
