#ifndef CHEESEBOX_H
#define CHEESEBOX_H

#include <string>
#include <vector>
#include <map>

class CheeseBox {
public:
    // Constructor and destructor
    CheeseBox();
    ~CheeseBox();

    // Public methods
    bool createContainer(const std::string& name, const std::string& distro);
    bool removeContainer(const std::string& name);
    bool startContainer(const std::string& name);
    bool stopContainer(const std::string& name);
    std::vector<std::string> listContainers();
    bool exportApp(const std::string& containerName, const std::string& binaryName);
    void showCommandHelp(const std::string& command);
    std::vector<std::string> getSupportedDistros();
    std::string getDistroboxVersion();

private:
    // Private helper methods
    bool containerExists(const std::string& name);
    bool executeCommand(const std::string& command);
    std::string getCommandOutput(const std::string& command);

    // Static members
    static const std::vector<std::string> supportedDistros;
    static const std::map<std::string, std::string> commandHelp;
};

#endif // CHEESEBOX_H
