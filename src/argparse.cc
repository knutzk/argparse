#include "argparse.h"

ArgumentParser::ArgumentParser() {
  // content here
};

void ArgumentParser::addArgument(const std::string& name,
                                 const std::string& help,
                                 const std::string& def_value) {
  // content here
  if (def_value != "") {
    arguments_.emplace_back(std::make_unique<OptionalArgument>(name, help, def_value));
  } else {
    arguments_.emplace_back(std::make_unique<Argument>(name, help));
 }
}

const Argument* ArgumentParser::getArgument(const std::string& name) const {
  for (const auto& arg : arguments_) {
    if (arg->getName() == name) {
      return arg.get();
    }
  }
  throw std::invalid_argument("Argument " + name + " is not registered");
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

std::string ArgumentParser::retrieve(const std::string& name) const {
  return getArgument(name)->getValue();
}
