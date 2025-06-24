# hello_world_cmake

Quick project to learn the basics of cmake

## Building
```bash
$ cmake -B build .
$ cmake --build build
```

Building CMake projects consists of 2 steps:
* `cmake -B build .` - Generate the build system
    * `cmake` - cmake executable (using PATH)
    * `-B build` - Specify build directory (here using `build`)
    * `[-S] .` - root directory of the CMake project (where CMakeLists.txt resides)

* `cmake --build build` - Build
    * `cmake` - cmake executable (using PATH)
    * `--build build` - build CMake project generated in the `build` directory

## Running
The built executable will be written into the `build` directory.

```bash
$ ./build/main
```

