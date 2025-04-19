#ifndef MOBILE_APP_MANAGER_H
#define MOBILE_APP_MANAGER_H

#include "App.h"
#include <map>

class MobileAppManager {
public:
    void installApp(const std::string& appName);
    void uninstallApp(const std::string& appName);
    void assignPermission(const std::string& appName, const std::string& permission);
    void revokePermission(const std::string& appName, const std::string& permission);
    std::vector<std::string> listInstalledApps() const;
    std::vector<std::string> listAppPermissions(const std::string& appName) const;

private:
    std::map<std::string, App*> installedApps;
};

#endif