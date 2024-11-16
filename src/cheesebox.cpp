#include "cheesebox.h"
#include <cstdlib>
#include <iostream>
#include <memory>
#include <array>

CheeseBox::CheeseBox() {}
CheeseBox::~CheeseBox() {}

bool CheeseBox::createContainer(const std::string& name, const std::string& distro) {
    std::string cmd = "distrobox create --name " + name + " --image " + distro;
    return executeCommand(cmd);
}

bool CheeseBox::removeContainer(const std::string& name) {
    if (!containerExists(name)) {
        std::cerr << "Container " << name << " does not exist." << std::endl;
        return false;
    }
    std::string cmd = "distrobox rm " + name;
    return executeCommand(cmd);
}

bool CheeseBox::startContainer(const std::string& name) {
    if (!containerExists(name)) {
        std::cerr << "Container " << name << " does not exist." << std::endl;
        return false;
    }
    std::string cmd = "distrobox enter " + name;
    return executeCommand(cmd);
}

bool CheeseBox::stopContainer(const std::string& name) {
    if (!containerExists(name)) {
        std::cerr << "Container " << name << " does not exist." << std::endl;
        return false;
    }
    std::string cmd = "distrobox stop " + name;
    return executeCommand(cmd);
}

std::vector<std::string> CheeseBox::listContainers() {
    std::string output = getCommandOutput("distrobox list");
    std::vector<std::string> containers;
    // Parse output and populate containers vector
    // This is a simplified implementation
    return containers;
}

bool CheeseBox::containerExists(const std::string& name) {
    std::string cmd = "distrobox list | grep " + name;
    return system(cmd.c_str()) == 0;
}

std::string CheeseBox::getDistroboxVersion() {
    return getCommandOutput("distrobox version");
}

bool CheeseBox::executeCommand(const std::string& command) {
    return system(command.c_str()) == 0;
}

std::string CheeseBox::getCommandOutput(const std::string& command) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);
    
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    
    return result;
}

// Add supported distributions
const std::vector<std::string> CheeseBox::supportedDistros = {
    "ubuntu:latest",
    "ubuntu:22.04",
    "ubuntu:20.04",
    "fedora:latest",
    "fedora:37",
    "debian:latest",
    "debian:11",
    "archlinux:latest",
    "opensuse/tumbleweed:latest",
    "rockylinux:latest",
    "almalinux:latest"
};

// Add detailed help text for each command
const std::map<std::string, std::string> CheeseBox::commandHelp = {
    {"create", 
        "Create a new Distrobox container\n"
        "\nUsage: cheesebox create <name> <distro>\n"
        "\nArguments:\n"
        "  name    Name for the new container\n"
        "  distro  Distribution image to use\n"
        "\nSupported Distributions:\n"
        "  ubuntu:latest, ubuntu:22.04, ubuntu:20.04\n"
        "  fedora:latest, fedora:37\n"
        "  debian:latest, debian:11\n"
        "  archlinux:latest\n"
        "  opensuse/tumbleweed:latest\n"
        "  rockylinux:latest\n"
        "  almalinux:latest\n"
        "\nExample:\n"
        "  cheesebox create dev-container ubuntu:latest\n"
    },
    {"remove",
        "Remove an existing Distrobox container\n"
        "\nUsage: cheesebox remove <name>\n"
        "\nArguments:\n"
        "  name    Name of the container to remove\n"
        "\nExample:\n"
        "  cheesebox remove dev-container\n"
    },
    {"start",
        "Start and enter a Distrobox container\n"
        "\nUsage: cheesebox start <name>\n"
        "\nArguments:\n"
        "  name    Name of the container to start\n"
        "\nExample:\n"
        "  cheesebox start dev-container\n"
    },
    {"stop",
        "Stop a running Distrobox container\n"
        "\nUsage: cheesebox stop <name>\n"
        "\nArguments:\n"
        "  name    Name of the container to stop\n"
        "\nExample:\n"
        "  cheesebox stop dev-container\n"
    },
    {"list",
        "List all Distrobox containers\n"
        "\nUsage: cheesebox list\n"
        "\nOutput format:\n"
        "  NAME          STATUS          IMAGE\n"
        "  container1    running         ubuntu:latest\n"
        "  container2    stopped         fedora:latest\n"
    },
    {"version",
        "Show Distrobox version information\n"
        "\nUsage: cheesebox version\n"
    }
};

void CheeseBox::showCommandHelp(const std::string& command) {
    auto it = commandHelp.find(command);
    if (it != commandHelp.end()) {
        std::cout << it->second << std::endl;
    } else {
        std::cerr << "No help available for command: " << command << std::endl;
    }
}

std::vector<std::string> CheeseBox::getSupportedDistros() {
    return supportedDistros;
} 