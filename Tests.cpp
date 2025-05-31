
/******************************************************************************
 *                    File Name: MobileAppManagerTest.cpp
 *                    Description: Unit tests for MobileAppManager class
 *                    Created By: Nikitha, Karthikeya, Snigdha, Swetha
 *                    Created Date: 30/05/2025
 *****************************************************************************/

/**************************************************************************** **
 *                      Header Files 
 *****************************************************************************/
#include "MobileAppManager.h"
#include <algorithm>
#include <gtest/gtest.h>

/******************************************************************************
 *                  Test Case: testInstallSingleApp
 *                  Description: Test installing a single application
 *****************************************************************************/
TEST(MobileAppManagerTest, testInstallSingleApp) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");

    auto installedApps = manager.listInstalledApps();
    EXPECT_EQ(installedApps.size(), 1);
    EXPECT_EQ(installedApps[0], "WhatsApp");
}

/******************************************************************************
 *                  Test Case: testInstallMultipleApps
 *                  Description: Test installing multiple applications
 *****************************************************************************/
TEST(MobileAppManagerTest, testInstallMultipleApps) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    manager.installApp("Spotify");

    auto installedApps = manager.listInstalledApps();
    EXPECT_EQ(installedApps.size(), 2);
}

/******************************************************************************
 *                  Test Case: testInstallSameAppTwice
 *                  Description: Test installing the same application twice
 *****************************************************************************/
TEST(MobileAppManagerTest, testInstallSameAppTwice) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    manager.installApp("WhatsApp");

    auto installedApps = manager.listInstalledApps();
    EXPECT_EQ(installedApps.size(), 1);
}

/******************************************************************************
 *                  Test Case: testInstallInvalidAppName
 *                  Description: Test installing an application with empty name
 *****************************************************************************/
TEST(MobileAppManagerTest, testInstallInvalidAppName) {
    MobileAppManager manager;
    manager.installApp("");

    auto installedApps = manager.listInstalledApps();
    EXPECT_TRUE(installedApps.empty());
}

/******************************************************************************
 *                  Test Case: testUninstallSingleApp
 *                  Description: Test uninstalling a single application
 *****************************************************************************/
TEST(MobileAppManagerTest, testUninstallSingleApp) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    manager.uninstallApp("WhatsApp");

    auto installedApps = manager.listInstalledApps();
    EXPECT_TRUE(installedApps.empty());
}

/******************************************************************************
 *                  Test Case: testUninstallMultipleApps
 *                  Description: Test uninstalling multiple applications
 *****************************************************************************/
TEST(MobileAppManagerTest, testUninstallMultipleApps) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    manager.installApp("Spotify");

    manager.uninstallApp("WhatsApp");
    manager.uninstallApp("Spotify");

    auto installedApps = manager.listInstalledApps();
    EXPECT_TRUE(installedApps.empty());
}

/******************************************************************************
 *                  Test Case: testUninstallNonExistentApp
 *                  Description: Test uninstalling an app that was never installed
 *****************************************************************************/
TEST(MobileAppManagerTest, testUninstallNonExistentApp) {
    MobileAppManager manager;
    manager.uninstallApp("FakeApp");

    auto installedApps = manager.listInstalledApps();
    EXPECT_TRUE(installedApps.empty());
}

/******************************************************************************
 *                  Test Case: testUninstallInvalidAppName
 *                  Description: Test uninstalling an app with empty name
 *****************************************************************************/
TEST(MobileAppManagerTest, testUninstallInvalidAppName) {
    MobileAppManager manager;
    manager.uninstallApp("");

    auto installedApps = manager.listInstalledApps();
    EXPECT_TRUE(installedApps.empty());
}

/******************************************************************************
 *                  Test Case: testAssignSinglePermissionToApp
 *                  Description: Test assigning a single permission to an app
 *****************************************************************************/
TEST(MobileAppManagerTest, testAssignSinglePermissionToAppp) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    manager.assignPermission("WhatsApp", "Camera");

    auto permissions = manager.listAppPermissions("WhatsApp");
    EXPECT_EQ(permissions.size(), 1);
    EXPECT_EQ(permissions[0], "Camera");
}

/******************************************************************************
 *                  Test Case: testAssignPermissionToNonExistentApp
 *                  Description: Test assigning permission to a non-existent app
 *****************************************************************************/
TEST(MobileAppManagerTest, testAssignPermissionToNonExistentApp) {
    MobileAppManager manager;
    manager.assignPermission("FakeApp", "Camera");

    auto permissions = manager.listAppPermissions("FakeApp");
    EXPECT_TRUE(permissions.empty());
}

/******************************************************************************
 *                  Test Case: testAssignMultiplePermissionsToApp
 *                  Description: Test assigning multiple permissions to an app
 *****************************************************************************/
TEST(MobileAppManagerTest, testAssignMultiplePermissionsToApp) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    manager.assignPermission("WhatsApp", "Camera");
    manager.assignPermission("WhatsApp", "Microphone");

    auto permissions = manager.listAppPermissions("WhatsApp");
    EXPECT_EQ(permissions.size(), 2);
    EXPECT_EQ(permissions[0], "Camera");
    EXPECT_EQ(permissions[1], "Microphone");
}

/******************************************************************************
 *                  Test Case: testAssignInvalidPermissionToApp
 *                  Description: Test assigning an invalid (empty) permission
 *****************************************************************************/
TEST(MobileAppManagerTest, testAssignInvalidPermissionToApp) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    manager.assignPermission("WhatsApp", "");

    auto permissions = manager.listAppPermissions("WhatsApp");
    EXPECT_TRUE(permissions.empty());
}

/******************************************************************************
 *                  Test Case: testRevokePermissionFromApp_InvalidApp
 *                  Description: Test revoking permission from a non-existent app
 *****************************************************************************/
TEST(MobileAppManagerTest, testRevokePermissionFromApp_InvalidApp) {
    MobileAppManager manager;
    manager.revokePermission("FakeApp", "Camera");

    auto permissions = manager.listAppPermissions("FakeApp");
    EXPECT_TRUE(permissions.empty());
}

/******************************************************************************
 *                  Test Case: testRevokePermissionFromApp_ValidPermission
 *                  Description: Test revoking a valid permission from an app
 *****************************************************************************/
TEST(MobileAppManagerTest, testRevokePermissionFromApp_ValidPermission) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    manager.assignPermission("WhatsApp", "Camera");
    manager.revokePermission("WhatsApp", "Camera");

    auto permissions = manager.listAppPermissions("WhatsApp");
    EXPECT_TRUE(permissions.empty());
}

/******************************************************************************
 *                  Test Case: testRevokePermissionFromApp_InvalidPermission
 *                  Description: Test revoking a non-existent permission from an app
 *****************************************************************************/
TEST(MobileAppManagerTest, testRevokePermissionFromApp_InvalidPermission) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    manager.revokePermission("WhatsApp", "FakePermission");

    auto permissions = manager.listAppPermissions("WhatsApp");
    EXPECT_TRUE(permissions.empty());
}

/******************************************************************************
 *     Test Case: testRevokePermissionFromApp_InvalidAppAndPermission
 *     Description: Test revoking a permission from a non-existent app and permission
 *****************************************************************************/
TEST(MobileAppManagerTest, testRevokePermissionFromApp_InvalidAppAndPermission) {
    MobileAppManager manager;
    manager.revokePermission("FakeApp", "FakePermission");

    auto permissions = manager.listAppPermissions("FakeApp");
    EXPECT_TRUE(permissions.empty());
}

/******************************************************************************
 *                  Test Case: testListInstalledApps_Empty
 *                  Description: Test listing apps when no apps are installed
 *****************************************************************************/
TEST(MobileAppManagerTest, testListInstalledApps_Empty) {
    MobileAppManager manager;
    auto installedApps = manager.listInstalledApps();
    EXPECT_TRUE(installedApps.empty());
}

/******************************************************************************
 *                  Test Case: testListInstalledApps_SingleApp
 *                  Description: Test listing installed apps with one app
 *****************************************************************************/
TEST(MobileAppManagerTest, testListInstalledApps_SingleApp) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");

    auto installedApps = manager.listInstalledApps();
    EXPECT_EQ(installedApps.size(), 1);
    EXPECT_EQ(installedApps[0], "WhatsApp");
}

/******************************************************************************
 *                  Test Case: testListInstalledApps_MultipleApps
 *                  Description: Test listing installed apps with multiple apps
 *****************************************************************************/
TEST(MobileAppManagerTest, testListInstalledApps_MultipleApps) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    manager.installApp("Spotify");

    auto installedApps = manager.listInstalledApps();
    EXPECT_EQ(installedApps.size(), 2);
    EXPECT_TRUE(std::find(installedApps.begin(), installedApps.end(), "WhatsApp") != installedApps.end());
    EXPECT_TRUE(std::find(installedApps.begin(), installedApps.end(), "Spotify") != installedApps.end());
}

/******************************************************************************
 *                  Test Case: testListInstalledApps_NoApps
 *                  Description: Test listing installed apps when no apps have been installed
 *****************************************************************************/
TEST(MobileAppManagerTest, testListInstalledApps_NoApps) {
    MobileAppManager manager;
    auto installedApps = manager.listInstalledApps();
    EXPECT_TRUE(installedApps.empty());
}

/******************************************************************************
 *      Test Case: testListPermissionsAssignedToAnApp_1
 *      Description: Test that the list of permissions returns an empty vector 
 *                   when the app has not been installed
 *****************************************************************************/
TEST(MobileAppManagerTest, testListPermissionsAssignedToAnApp_1) {
    MobileAppManager manager;
    auto permissions = manager.listAppPermissions("NonExistentApp");
    EXPECT_TRUE(permissions.empty());
}

/******************************************************************************
 *      Test Case: testListPermissionsAssignedToAnApp_2
 *      Description: Test that the list of permissions returns an empty vector 
 *                   when the app has been installed but no permission has been assigned
 *****************************************************************************/
TEST(MobileAppManagerTest, testListPermissionsAssignedToAnApp_2) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    auto permissions = manager.listAppPermissions("WhatsApp");
    EXPECT_TRUE(permissions.empty());
}

/******************************************************************************
 *      Test Case: testListPermissionsAssignedToAnApp_3
 *      Description: Test that the list of permissions returns all permissions 
 *                   assigned to the app
 *****************************************************************************/
TEST(MobileAppManagerTest, testListPermissionsAssignedToAnApp_3) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    manager.assignPermission("WhatsApp", "Camera");
    manager.assignPermission("WhatsApp", "Microphone");

    auto permissions = manager.listAppPermissions("WhatsApp");
    EXPECT_EQ(permissions.size(), 2);
    EXPECT_EQ(permissions[0], "Camera");
    EXPECT_EQ(permissions[1], "Microphone");
}

/******************************************************************************
 *      Test Case: testListPermissionsAssignedToAnApp_4
 *      Description: Test that the list of permissions returns only the permissions 
 *                   assigned to a specific app and not to others
 *****************************************************************************/
TEST(MobileAppManagerTest, testListPermissionsAssignedToAnApp_4) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    manager.installApp("Spotify");

    manager.assignPermission("WhatsApp", "Camera");
    manager.assignPermission("Spotify", "Microphone");

    auto permissionsWhatsApp = manager.listAppPermissions("WhatsApp");
    auto permissionsSpotify = manager.listAppPermissions("Spotify");

    EXPECT_EQ(permissionsWhatsApp.size(), 1);
    EXPECT_EQ(permissionsWhatsApp[0], "Camera");

    EXPECT_EQ(permissionsSpotify.size(), 1);
    EXPECT_EQ(permissionsSpotify[0], "Microphone");
}

/******************************************************************************
 *                  Main Function
 *                  Description: Entry point to execute all unit tests
 *****************************************************************************/
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/******************************** End of File ********************************/
