
/******************************************************************************
 *                    File Name: MobileAppManager.cpp
 *                    Description: Implementation file for managing mobile apps and their permissions
 *                    Created By: Nikitha, Karthikeya, Snigdha, Swetha
 *                    Created Date: 30/05/2025
 *****************************************************************************/

/**************************************************************************** **
 *                      Header Files 
 *****************************************************************************/
#include "MobileAppManager.h"
#include <iostream>

/******************************************************************************
 *                  Name: installApp
 *                  Description: Installs a new application with the given name
 *                  Arguments: const std::string& appName - Name of the application
 *                  Returns: None
 *****************************************************************************/
void MobileAppManager::installApp(const std::string& appName) {
    if(appName.empty()){
        std::cout << "Invalid app name!" << std::endl;
        return; 
    }
    if (installedApps.find(appName) == installedApps.end()) {
        installedApps[appName] = new App(appName);
        std::cout << "App installed: " << appName << std::endl;
    } else {
        std::cout << "App already exists!" << std::endl;
    }
}

/******************************************************************************
 *                  Name: uninstallApp
 *                  Description: Uninstalls the application with the given name
 *                  Arguments: const std::string& appName - Name of the application
 *                  Returns: None
 *****************************************************************************/
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

/******************************************************************************
 *                  Name: assignPermission
 *                  Description: Assigns a permission to a given application
 *                  Arguments: const std::string& appName - Name of the application
 *                             const std::string& permission - Permission to assign
 *                  Returns: None
 *****************************************************************************/
void MobileAppManager::assignPermission(const std::string& appName, const std::string& permission) {
    if(permission.empty()){
        std::cout << "Invalid permission!" << std::endl;
        return;
    }
    auto it = installedApps.find(appName);
    if (it != installedApps.end()) {
        it->second->addPermission(permission);
        std::cout << "Permission '" << permission << "' assigned to " << appName << std::endl;
    } else {
        std::cout << "App not found!" << std::endl;
    }
}

/******************************************************************************
 *                  Name: revokePermission
 *                  Description: Revokes a permission from the given application
 *                  Arguments: const std::string& appName - Name of the application
 *                             const std::string& permission - Permission to revoke
 *                  Returns: None
 *****************************************************************************/
void MobileAppManager::revokePermission(const std::string& appName, const std::string& permission) {
    auto it = installedApps.find(appName);
    if (it != installedApps.end()) {
        it->second->removePermission(permission);
        std::cout << "Permission '" << permission << "' revoked from " << appName << std::endl;
    } else {
        std::cout << "App not found!" << std::endl;
    }
}

/******************************************************************************
 *                  Name: listInstalledApps
 *                  Description: Lists all installed applications
 *                  Arguments: None
 *                  Returns: std::vector<std::string> - List of app names
 *****************************************************************************/
std::vector<std::string> MobileAppManager::listInstalledApps() const {
    std::vector<std::string> appNames;
    for (const auto& pair : installedApps) {
        appNames.push_back(pair.first);
    }
    return appNames;
}

/******************************************************************************
 *                  Name: listAppPermissions
 *                  Description: Lists permissions of a given application
 *                  Arguments: const std::string& appName - Name of the application
 *                  Returns: std::vector<std::string> - List of permissions
 *****************************************************************************/
std::vector<std::string> MobileAppManager::listAppPermissions(const std::string& appName) const {
    auto it = installedApps.find(appName);
    if (it != installedApps.end()) {
        return it->second->getPermissions();
    }
    return {};
}

/******************************** End of File ********************************/
