
/******************************************************************************
 *                    File Name: App.h
 *                    Description: Header file for App class managing app name and permissions
 *                    Created By: Nikitha, Karthikeya, Snigdha, Swetha
 *                    Created Date: 30/05/2025
 *****************************************************************************/

/**************************************************************************** **
 *	                    Header Files 
 ***************************************************************************** */ 

#ifndef __APP_H__
#define __APP_H__

#include <string>
#include <vector>

/******************************************************************************
 *                  Class Definition: App
 *                  Description: Represents an application with a name and a set of permissions
 *****************************************************************************/

class App {
public:
    /******************************************************************************
     *                  Name: App
     *                  Description: Constructor to initialize the application name
     *                  Arguments: const std::string& name - Name of the application
     *                  Returns: None
     *****************************************************************************/
    App(const std::string& name);

    /******************************************************************************
     *                  Name: addPermission
     *                  Description: Adds a permission to the app
     *                  Arguments: const std::string& permission - Permission to be added
     *                  Returns: None
     *****************************************************************************/
    void addPermission(const std::string& permission);

    /******************************************************************************
     *                  Name: removePermission
     *                  Description: Removes a permission from the app
     *                  Arguments: const std::string& permission - Permission to be removed
     *                  Returns: None
     *****************************************************************************/
    void removePermission(const std::string& permission);

    /******************************************************************************
     *                  Name: getPermissions
     *                  Description: Retrieves the list of permissions
     *                  Arguments: None
     *                  Returns: std::vector<std::string> - List of permissions
     *****************************************************************************/
    std::vector<std::string> getPermissions() const;

    /******************************************************************************
     *                  Name: getAppName
     *                  Description: Retrieves the name of the application
     *                  Arguments: None
     *                  Returns: std::string - Application name
     *****************************************************************************/
    std::string getAppName() const;

private:
    std::string appName;                      // Name of the application
    std::vector<std::string> permissions;     // List of permissions assigned to the app
};

#endif

/******************************** End of File ********************************/
