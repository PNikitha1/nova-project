
/******************************************************************************
 *                    File Name: App.cpp
 *                    Description: Implementation file for App class methods
 *                    Created By: Nikitha, Karthikeya, Snigdha, Swetha
 *                    Created Date: 30/05/2025
 *****************************************************************************/

/**************************************************************************** **
 *	                    Header Files 
 ***************************************************************************** */ 

#include "App.h"
#include <algorithm>  // For std::remove
#include <iostream>   // For console output (optional, not used in current code)

/******************************************************************************
 *                  Constructor: App
 *                  Description: Initializes the App object with a name
 *                  Arguments: const std::string& name - Name of the application
 *                  Returns: None
 *****************************************************************************/
App::App(const std::string& name) : appName(name) {}

/******************************************************************************
 *                  Name: addPermission
 *                  Description: Adds a new permission to the permissions list
 *                  Arguments: const std::string& permission - Permission to be added
 *                  Returns: None
 *****************************************************************************/
void App::addPermission(const std::string& permission) {
    permissions.push_back(permission);
}

/******************************************************************************
 *                  Name: removePermission
 *                  Description: Removes a specific permission from the list
 *                  Arguments: const std::string& permission - Permission to be removed
 *                  Returns: None
 *****************************************************************************/
void App::removePermission(const std::string& permission) {
    permissions.erase(std::remove(permissions.begin(), permissions.end(), permission), permissions.end());
}

/******************************************************************************
 *                  Name: getPermissions
 *                  Description: Returns the list of permissions assigned to the app
 *                  Arguments: None
 *                  Returns: std::vector<std::string> - List of permissions
 *****************************************************************************/
std::vector<std::string> App::getPermissions() const {
    return permissions;
}

/******************************************************************************
 *                  Name: getAppName
 *                  Description: Returns the name of the application
 *                  Arguments: None
 *                  Returns: std::string - Application name
 *****************************************************************************/
std::string App::getAppName() const {
    return appName;
}

/******************************** End of File ********************************/
