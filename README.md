QNixieNumber

This widget is an analogue of QLCDNumber, presented in the form of Nixie indicators. 
This widget has two styles: 
- computer graphics;
- imitation of a real indicator.

This widget allows you to set the style, the number of segments, pass the value for display, as well as get the current value (this method does not read the value from the images themselves). 

# Build requirements

 - CMake 3.5+ (CMake 3.12+ is recommended for more ergonomic `-DQNixieNumber_ROOT` support, see `examples/` for details);
 - Qt5 / Qt6 (QNixieNumber automatically links for the latest Qt version).

# Build and installation

Make sure you satisfied the build requirements!

```sh
cmake -S . -B build
cmake --build build
cmake --install build --prefix install
```

## Why I need to do cmake --install?

Because it's the proper (and recommended) way to consume any CMake-based library.
The other ways (subdirectories, bundling, etc) are not recommended for proper usage.

You could also use [conan](https://conan.io) or [vcpkg](https://github.com/microsoft/vcpkg), but currently this library is
not available in any public package managers repositories.

# Usage in your project

1. Make sure that you make the `cmake --install` into your convenient install directory (named prefix, later `<prefix>`);
2. Add to your CMakeLists.txt the following lines (assuming that the project is named `your_project`:
```cmake
find_package(QNixieNumber REQUIRED)

target_link_libraries(your_project QNixieNumber::QNixieNumber)
```
3. build your project with the following command (replacing `<prefix>` with the actual install directory, see 1.):
```sh
cmake -S . -B build -DQNixieNumber_ROOT=<prefix>
```


See `examples/` for details.
