cmake_minimum_required(VERSION 3.5)

project(QNixieNumber LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

add_library(QNixieNumber SHARED
  qnixienumber.cpp
  qnixienumber.h
  qnixienumber_resource.qrc
)


include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# Add INTERFACE include_directories path for INSTALL only, as we use headers relative to current dir
target_include_directories(QNixieNumber INTERFACE $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_link_libraries(QNixieNumber PUBLIC Qt${QT_VERSION_MAJOR}::Widgets)

# create a config package with additional dependencies logic..
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/QNixieNumberConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/QNixieNumberConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QNixieNumber.cmake
)
# ... and install it (it also includes all exported targets)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/QNixieNumberConfig.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QNixieNumber)

# Install the main QNixieNumber target...
install(TARGETS QNixieNumber EXPORT QNixieNumberTargets)
install(EXPORT QNixieNumberTargets DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QNixieNumber NAMESPACE QNixieNumber::)

# Install QNixieNumber's public header qnixienumber.h into includedir/qnixienumber/...
install(FILES qnixienumber.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/qnixienumber/)
