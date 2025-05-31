
/******************************************************************************
 *                    File Name: MobileAppManager.h
 *                    Description: Header file for MobileAppManager class managing app installation and permissions
 *                    Created By: Nikitha, Karthikeya, Snigdha, Swetha
 *                    Created Date: 30/05/2025
 *****************************************************************************/

/**************************************************************************** **
 *	                    Header Files 
 ***************************************************************************** */ 

#ifndef __MOBILE_APP_MANAGER_H__
#define __MOBILE_APP_MANAGER_H__

#include "App.h"
#include <map>

/******************************************************************************
 *                  Class Definition: MobileAppManager
 *                  Description: Manages the installation, uninstallation, and 
 *                               permission control of mobile applications
 *****************************************************************************/

class MobileAppManager {
public:
    /******************************************************************************
     *                  Name: installApp
     *                  Description: Installs a new application with the given name
     *                  Arguments: const std::string& appName - Name of the application
     *                  Returns: None
     *****************************************************************************/
    void installApp(const std::string& appName);

    /******************************************************************************
     *                  Name: uninstallApp
     *                  Description: Uninstalls the application with the given name
     *                  Arguments: const std::string& appName - Name of the application
     *                  Returns: None
     *****************************************************************************/
    void uninstallApp(const std::string& appName);

    /******************************************************************************
     *                  Name: assignPermission
     *                  Description: Assigns a permission to the specified app
     *                  Arguments: const std::string& appName - Name of the app
     *                             const std::string& permission - Permission to assign
     *                  Returns: None
     *****************************************************************************/
    void assignPermission(const std::string& appName, const std::string& permission);

    /******************************************************************************
     *                  Name: revokePermission
     *                  Description: Removes a permission from the specified app
     *                  Arguments: const std::string& appName - Name of the app
     *                             const std::string& permission - Permission to revoke
     *                  Returns: None
     *****************************************************************************/
    void revokePermission(const std::string& appName, const std::string& permission);

    /******************************************************************************
     *                  Name: listInstalledApps
     *                  Description: Returns a list of all installed apps
     *                  Arguments: None
     *                  Returns: std::vector<std::string> - Names of installed apps
     *****************************************************************************/
    std::vector<std::string> listInstalledApps() const;

    /******************************************************************************
     *                  Name: listAppPermissions
     *                  Description: Returns a list of permissions for the specified app
     *                  Arguments: const std::string& appName - Name of the app
     *                  Returns: std::vector<std::string> - List of permissions
     *****************************************************************************/
    std::vector<std::string> listAppPermissions(const std::string& appName) const;

private:
    std::map<std::string, App*> installedApps; // Map to store installed apps with their names as keys
};

#endif

/******************************** End of File ********************************/
