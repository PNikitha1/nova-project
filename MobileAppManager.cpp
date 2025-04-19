#include "MobileAppManager.h"
#include <iostream>

void MobileAppManager::installApp(const std::string& appName) {
    if (installedApps.find(appName) == installedApps.end()) {
        installedApps[appName] = new App(appName);
        std::cout << "App installed: " << appName << std::endl;
    } else {
        std::cout << "App already exists!" << std::endl;
    }
}

void MobileAppManager::uninstallApp(const std::string& appName) {
    auto it = installedApps.find(appName);
    if (it != installedApps.end()) {
        delete it->second;
        installedApps.erase(it);
        std::cout << "App uninstalled: " << appName << std::endl;
    } else {
        std::cout << "App not found!" << std::endl;
    }
}

void MobileAppManager::assignPermission(const std::string& appName, const std::string& permission) {
    auto it = installedApps.find(appName);
    if (it != installedApps.end()) {
        it->second->addPermission(permission);
        std::cout << "Permission '" << permission << "' assigned to " << appName << std::endl;
    } else {
        std::cout << "App not found!" << std::endl;
    }
}

void MobileAppManager::revokePermission(const std::string& appName, const std::string& permission) {
    auto it = installedApps.find(appName);
    if (it != installedApps.end()) {
        it->second->removePermission(permission);
        std::cout << "Permission '" << permission << "' revoked from " << appName << std::endl;
    } else {
        std::cout << "App not found!" << std::endl;
    }
}

std::vector<std::string> MobileAppManager::listInstalledApps() const {
    std::vector<std::string> appNames;
    for (const auto& pair : installedApps) {
        appNames.push_back(pair.first);
    }
    return appNames;
}

std::vector<std::string> MobileAppManager::listAppPermissions(const std::string& appName) const {
    auto it = installedApps.find(appName);
    if (it != installedApps.end()) {
        return it->second->getPermissions();
    }
    return {};
}