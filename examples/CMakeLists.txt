# This example assumes that you have built QNixieNumber and installed it into some prefix.
# Pass the install prefix to CMake command line using the command arg "-DQNixieNumber_ROOT=<prefix>"
# N.B. -DQNixieNumber_ROOT=... will works only from CMake 3.12, for older CMakes you should
# use the "-DQNixieNumber_DIR=<prefix>/lib[64]/cmake/", there lib[64] is depends on your distro's
# lib directory name and your OS bitness.
# As you see, the older CMake is more difficult than new, so we encourage to use the modern CMake.
cmake_minimum_required(VERSION 3.5)

# This CMake Policy alters the old behavior and enables the `-DQNixieNumber_ROOT=<prefix>` usage.
# see docs for details
if (POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif()

project(example)

# You don't need to call it explicitly, as QNixieNumber's package config already does it for you
# find_package(Qt5 COMPONENTS Widgets)
find_package(QNixieNumber REQUIRED)
add_executable(example main.cpp)

# not required, will auto-link from QNixieNumber: Qt5::Widgets)
target_link_libraries(example QNixieNumber::QNixieNumber)

