#include "argparse.h"

ArgumentParser::ArgumentParser() {
  // content here
};

void ArgumentParser::addArgument(const std::string& name,
                                 const std::string& help,
                                 bool optional) {
  // content here
  if (optional) {
    arguments_.emplace_back(std::make_unique<OptionalArgument>(name, help));
  } else {
    arguments_.emplace_back(std::make_unique<Argument>(name, help));
 }
}

const std::vector<const Argument*> ArgumentParser::getArguments() const {
  std::vector<const Argument*> args;
  for (const auto& arg : arguments_) {
    args.emplace_back(arg.get());
  }
  return args;
}

void ArgumentParser::parse(int argc, char** argv) {
  // content here
}
