#include "cheesebox.h"
#include <iostream>
#include <string>

void printUsage() {
    std::cout << "Usage: cheesebox <command> [options]\n"
              << "\nCommands:\n"
              << "  create <name> <distro>  Create a new container\n"
              << "  remove <name>           Remove a container\n"
              << "  start <name>            Start a container\n"
              << "  stop <name>             Stop a container\n"
              << "  list                    List all containers\n"
              << "  export-app <name> <binary>  Export an application from container\n"
              << "  version                 Show Cheesebox version\n"
              << "  help <command>          Show help for a specific command\n"
              << "\nFor more information about a command:\n"
              << "  cheesebox help <command>\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printUsage();
        return 1;
    }

    CheeseBox cb;
    std::string command = argv[1];

    try {
        if (command == "help") {
            if (argc == 2) {
                printUsage();
            } else {
                cb.showCommandHelp(argv[2]);
            }
        }
        else if (command == "create" && argc == 4) {
            if (cb.createContainer(argv[2], argv[3])) {
                std::cout << "Container created successfully\n";
            }
        }
        else if (command == "remove" && argc == 3) {
            if (cb.removeContainer(argv[2])) {
                std::cout << "Container removed successfully\n";
            }
        }
        else if (command == "start" && argc == 3) {
            cb.startContainer(argv[2]);
        }
        else if (command == "stop" && argc == 3) {
            if (cb.stopContainer(argv[2])) {
                std::cout << "Container stopped successfully\n";
            }
        }
        else if (command == "list") {
            auto containers = cb.listContainers();
            for (const auto& container : containers) {
                std::cout << container << std::endl;
            }
        }
        else if (command == "export-app" && argc == 4) {
            if (cb.exportApp(argv[2], argv[3])) {
                std::cout << "Application exported successfully\n";
            }
        }
        else if (command == "version") {
            std::cout << "Cheesebox version 0.1.2\n";
        }
        else {
            printUsage();
            return 1;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
} 