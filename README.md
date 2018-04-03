# CMake 101

This repo exists as a few bits of source files. Your job is to correctly implement a CMakeLists.txt for them.

For this, you should make use of the CMake command reference and, of course, Google. Also, you should note that just about every exercise we have on our GitHub is built using CMake.

For this set of tasks, you don't actually need to know any C++ at all with the exception of setting preprocessor values.

## Task 1: A Basic executable build

Fill in a basic CMakeLists.txt that will generate an executable called "widget". If you succeed, it should print out "Widget Open" and then "Widget Close".

Since our include directory is separate from the source directory, you will need to use target_include_directories() for the target to successfully compile.

## Task 2: ~Electric Boogaloo~ Adding a library build

Create a new target that builds Widget.cpp as a library via add_library. It should also 

If you did it right, you should have something like Widget.so or Widget.dll - depending on your platform.

As a bonus, you may choose to change your executable to link to this dynamic library instead, in which case, it should only need to build main.

## Task 3: Creating an installation phase

Add an install phase to the library so that it will also install both the library file and its include header.

When running CMake to test it, specify `-DCMAKE_INSTALL_PREFIX=./checkme` on the command line and your `make install` will just put it in that folder within the build dir instead of to your system. you should be able to find both the library file and the header within that output location.

## Task 4: Allowing the builder of the program to customise the program's features.

Add a CMake option that, if the person building should choose to enable it, will define `SHOW_SECRET_MESSAGE` within the preprocessor of the compiler.

When testing, you may need to delete your CMakeCache.txt (note: *CACHE*) *in your build directory* before re-running CMake.

If you got it right, you should have passed the option on the command line and then "Cool Story Bro" should have appeared when you ran the main executable.

Conversely if you do not define the option, it should not display the secret message.

## Task 5: Optimising the build process.

This is a reasonably advanced task now.

Currently, if you read the build output, you'll find that CMake is actually compiling the sources twice - once for the library and once again for the executable.

However, CMake actually supports creating an intermediate target object library that can be consumed by the final ones. Your job is to implement this so that our source files only get built once.

## Task 6: We are from the future.

Make CMake error out if \_\_cpluscplus is less than 202301L with the message _"C++23 is required."_ You may optionally append _"you peasant"_ if it amuses you to do so.

If you are reading this and C++23 has already been released, Your task is instead to take the computer you're using and throw it out of the nearest window\*.

^\*Except in jurisdictions where we can be held responsible for it.

## Task 7: We are ~not~ really from the future.

Make CMake continue, but issue a warning if the system has an environment variable called "TARDIS_OVERRIDE".

If you threw your computer out of the window in the previous step and are still reading this, you have now automatically failed every task irrespective of whether the outcome matched the specification or not.
