# ------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.21)

project(named_queue)

# Tune build flags (for all projects).
## Tune compiler.
#
# set_property(GLOBAL PROPERTY CXX_STANDARD 23)
# set_property(GLOBAL PROPERTY CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED On)

# Enable all warnings "GCC-like".
#
add_compile_options(-Wall -Wextra -ggdb3)

# set(CMAKE_BUILD_TYPE Debug)

include(GNUInstallDirs)

# ------------------------------------------------------------------------------
# Common Dependencies

find_package( Boost 1.80 REQUIRED )
# find_package( Boost 1.80 COMPONENTS interprocess REQUIRED )

# ------------------------------------------------------------------------------

# Common include dirs.
include_directories(
    PRIVATE "${PROJECT_SOURCE_DIR}/common"
    ${Boost_INCLUDE_DIR}
    )
    # PRIVATE "${PROJECT_SOURCE_DIR}/common"

# ------------------------------------------------------------------------------
# Subdirs.

add_subdirectory(receiver)
add_subdirectory(sender)

# ------------------------------------------------------------------------------
