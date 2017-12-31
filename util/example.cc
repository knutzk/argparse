#include "argparse/argparse.h"

#include <iostream>

int main(int argc, char** argv) {

  ArgumentParser parser;
  parser.addArgument("--detailed", "Make everything detailed");
  parser.addArgument("--ignore", "Ignore everything");
  parser.getArgument("--ignore")->setDefaultValue("defval");
  parser.parse(argc, argv);

  std::cout << "Hello World" << std::endl;
  return 0;
}
