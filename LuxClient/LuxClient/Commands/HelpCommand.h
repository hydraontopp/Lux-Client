#pragma once

class HelpCommand : public Command {
public:
	HelpCommand(std::string name) : Command(name, "Help Info") {};

	void Execute(std::vector<std::string> args) override {
		//for (auto cmd : cmdHandler.commands) {
		//}
	}
};