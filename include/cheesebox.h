#ifndef CHEESEBOX_H
#define CHEESEBOX_H

#include <string>
#include <vector>
#include <map>

class CheeseBox {
public:
    CheeseBox();
    ~CheeseBox();

    // Container management
    bool createContainer(const std::string& name, const std::string& distro);
    bool removeContainer(const std::string& name);
    bool startContainer(const std::string& name);
    bool stopContainer(const std::string& name);
    
    // Container information
    std::vector<std::string> listContainers();
    bool containerExists(const std::string& name);
    
    // Utility functions
    std::string getDistroboxVersion();

    // Help-related methods
    void showCommandHelp(const std::string& command);
    std::vector<std::string> getSupportedDistros();

private:
    bool executeCommand(const std::string& command);
    std::string getCommandOutput(const std::string& command);

    // Help text constants
    static const std::map<std::string, std::string> commandHelp;
    static const std::vector<std::string> supportedDistros;
};

#endif 