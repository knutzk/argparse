#include "argparse.h"

#include <iostream>

int main(int argc, char** argv) {

  ArgumentParser parser;
  parser.addArgument("--detailed", "Make everything detailed", true);
  parser.addArgument("--ignore", "Ignore everything", true);
  parser.parse(argc, argv);

  std::cout << "Hello World" << std::endl;
  return 0;
}
