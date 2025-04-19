#include "App.h"
#include <algorithm>
#include<iostream>

App::App(const std::string& name) : appName(name) {}

void App::addPermission(const std::string& permission) {
    permissions.push_back(permission);
}

void App::removePermission(const std::string& permission) {
    permissions.erase(std::remove(permissions.begin(), permissions.end(), permission), permissions.end());
}

std::vector<std::string> App::getPermissions() const {
    return permissions;
}

std::string App::getAppName() const {
    return appName;
}


