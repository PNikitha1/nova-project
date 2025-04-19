#include "MobileAppManager.h"
#include <gtest/gtest.h>

// Test installing a single app
TEST(MobileAppManagerTest, testInstallSingleApp) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");

    auto installedApps = manager.listInstalledApps();
    EXPECT_EQ(installedApps.size(), 1);
    EXPECT_EQ(installedApps[0], "WhatsApp");
}

// Test installing multiple apps
TEST(MobileAppManagerTest, testInstallMultipleApps) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    manager.installApp("Spotify");

    auto installedApps = manager.listInstalledApps();
    EXPECT_EQ(installedApps.size(), 2);
}

// Test installing the same app twice
TEST(MobileAppManagerTest,  testInstallSameAppTwice) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    manager.installApp("WhatsApp"); // Attempting duplicate install

    auto installedApps = manager.listInstalledApps();
    EXPECT_EQ(installedApps.size(), 1); // Should have only one instance
}

// Test installing an invalid app name (empty string)
TEST(MobileAppManagerTest, testInstallInvalidAppName) {
    MobileAppManager manager;
    manager.installApp("");  // Invalid name

    auto installedApps = manager.listInstalledApps();
    EXPECT_TRUE(installedApps.empty());  // Should not add any app
}

// Test uninstalling a single app
TEST(MobileAppManagerTest, testUninstallSingleApp) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    manager.uninstallApp("WhatsApp");

    auto installedApps = manager.listInstalledApps();
    EXPECT_TRUE(installedApps.empty()); // Should be empty after uninstall
}

// Test uninstalling multiple apps
TEST(MobileAppManagerTest,  testUninstallMultipleApps) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    manager.installApp("Spotify");

    manager.uninstallApp("WhatsApp");
    manager.uninstallApp("Spotify");

    auto installedApps = manager.listInstalledApps();
    EXPECT_TRUE(installedApps.empty()); // No apps should remain
}

// Test uninstalling a non-existent app
TEST(MobileAppManagerTest, testUninstallNonExistentApp) {
    MobileAppManager manager;
    manager.uninstallApp("FakeApp");  // App was never installed

    auto installedApps = manager.listInstalledApps();
    EXPECT_TRUE(installedApps.empty()); // System should remain unchanged
}

// Test uninstalling an invalid app name
TEST(MobileAppManagerTest, testUninstallInvalidAppName) {
    MobileAppManager manager;
    
    // Try uninstalling an app with an empty string as the name
    manager.uninstallApp("");

    // The list of installed apps should remain unchanged (empty initially)
    auto installedApps = manager.listInstalledApps();
    EXPECT_TRUE(installedApps.empty());
}

// Test assigning a single permission to an app
TEST(MobileAppManagerTest, testAssignSinglePermissionToAppp) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    manager.assignPermission("WhatsApp", "Camera");

    auto permissions = manager.listAppPermissions("WhatsApp");
    EXPECT_EQ(permissions.size(), 1);
    EXPECT_EQ(permissions[0], "Camera");
}

// Test assigning permission to a non-existent app
TEST(MobileAppManagerTest, testAssignPermissionToNonExistentApp) {
    MobileAppManager manager;
    manager.assignPermission("FakeApp", "Camera"); // App not installed

    auto permissions = manager.listAppPermissions("FakeApp");
    EXPECT_TRUE(permissions.empty()); // No permissions should be assigned
}

// Test assigning multiple permissions to an app
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

// Test assigning an invalid permission to an app
TEST(MobileAppManagerTest, testAssignInvalidPermissionToApp) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    manager.assignPermission("WhatsApp", ""); // Invalid permission

    auto permissions = manager.listAppPermissions("WhatsApp");
    EXPECT_TRUE(permissions.empty());
}

// Test revoking a permission from an invalid app
TEST(MobileAppManagerTest, testRevokePermissionFromApp_InvalidApp) {
    MobileAppManager manager;
    manager.revokePermission("FakeApp", "Camera");

    auto permissions = manager.listAppPermissions("FakeApp");
    EXPECT_TRUE(permissions.empty());
}

// Test revoking a valid permission from an app
TEST(MobileAppManagerTest, testRevokePermissionFromApp_ValidPermission) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    manager.assignPermission("WhatsApp", "Camera");
    manager.revokePermission("WhatsApp", "Camera");

    auto permissions = manager.listAppPermissions("WhatsApp");
    EXPECT_TRUE(permissions.empty());
}

// Test revoking an invalid permission from an app
TEST(MobileAppManagerTest, testRevokePermissionFromApp_InvalidPermission) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    manager.revokePermission("WhatsApp", "FakePermission");

    auto permissions = manager.listAppPermissions("WhatsApp");
    EXPECT_TRUE(permissions.empty());
}

// Test revoking a permission from an invalid app with an invalid permission
TEST(MobileAppManagerTest, testRevokePermissionFromApp_InvalidAppAndPermission) {
    MobileAppManager manager;
    manager.revokePermission("FakeApp", "FakePermission");

    auto permissions = manager.listAppPermissions("FakeApp");
    EXPECT_TRUE(permissions.empty());
}

// Test listing installed apps when empty
TEST(MobileAppManagerTest, testListInstalledApps_Empty) {
    MobileAppManager manager;
    auto installedApps = manager.listInstalledApps();
    EXPECT_TRUE(installedApps.empty());
}

// Test listing installed apps with a single app
TEST(MobileAppManagerTest, testListInstalledApps_SingleApp) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");

    auto installedApps = manager.listInstalledApps();
    EXPECT_EQ(installedApps.size(), 1);
    EXPECT_EQ(installedApps[0], "WhatsApp");
}

// Test listing installed apps with multiple apps
TEST(MobileAppManagerTest, testListInstalledApps_MultipleApps) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    manager.installApp("Spotify");

    auto installedApps = manager.listInstalledApps();
    EXPECT_EQ(installedApps.size(), 2);
    EXPECT_EQ(installedApps[0], "WhatsApp");
    EXPECT_EQ(installedApps[1], "Spotify");
}

// Test listing installed apps when no apps have been installed
TEST(MobileAppManagerTest, testListInstalledApps_NoApps) {
    MobileAppManager manager;
    auto installedApps = manager.listInstalledApps();
    EXPECT_TRUE(installedApps.empty());
}

// Test that the list of permissions returns an empty vector when the app has not been installed
TEST(MobileAppManagerTest, testListPermissionsAssignedToAnApp_1) {
    MobileAppManager manager;
    auto permissions = manager.listAppPermissions("NonExistentApp");
    EXPECT_TRUE(permissions.empty());
}

// Test that the list of permissions returns an empty vector when the app has been installed but no permission has been assigned
TEST(MobileAppManagerTest, testListPermissionsAssignedToAnApp_2) {
    MobileAppManager manager;
    manager.installApp("WhatsApp");
    auto permissions = manager.listAppPermissions("WhatsApp");
    EXPECT_TRUE(permissions.empty());
}

// Test that the list of permissions returns all permissions assigned to the app
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

// Test that the list of permissions returns only the permissions assigned to a specific app and not to others
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

// Main function to execute tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}