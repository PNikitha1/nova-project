#ifndef APP_H
#define APP_H

#include <string>
#include <vector>

class App {
public:
    App(const std::string& name);
    void addPermission(const std::string& permission);
    void removePermission(const std::string& permission);
    std::vector<std::string> getPermissions() const;
    std::string getAppName() const;

private:
    std::string appName;
    std::vector<std::string> permissions;
};

#endif