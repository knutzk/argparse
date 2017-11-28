#include "argparse.h"

#include <iostream>
#include <sstream>

ArgumentParser::ArgumentParser() {
  // content here
};

void ArgumentParser::addArgument(const std::string& name,
                                 const std::string& help) {
  arguments_.emplace_back(std::make_unique<Argument>(name, help));
}

Argument* ArgumentParser::getArgument(const std::string& name) {
  for (auto& arg : arguments_) {
    if (arg->getName() == name) {
      return arg.get();
    }
  }
  throw std::invalid_argument("Argument " + name + " is not registered");
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
  prog_name_ = argv[0];

  for (unsigned int i = 1; i < argc; ++i) {
    if (std::string(argv[i]).substr(0, 2) == "--") {
      if (i + 1 == argc) {
        auto err = "Argument " + std::string(argv[i]) + " given, but no value";
        throw std::invalid_argument(err);
      }
      getArgument(argv[i])->setValue(argv[i + 1]);
      ++i;
    }
  }

  for (const auto& arg : arguments_) {
    if (arg->getValue() == "") {
      throw std::invalid_argument("Argument " + arg->getName() + " has no value");
    }
  }

  std::cerr << print_usage() << std::endl;
}

std::string ArgumentParser::print_usage() const {
  std::ostringstream print;
  print << "Usage: " << prog_name_ << "\n\n";
  print << "Available options are:\n";
  for (const auto& arg : arguments_) {
    print << "  " << arg->getName();
    print << "\t" << arg->getHelpMessage() << "\n";
  }
  return print.str();
}

std::string ArgumentParser::retrieve(const std::string& name) const {
  return getArgument(name)->getValue();
}
