
# ------------------------------------------------------------------------------
# Sender Process.

# ------------------------------------------------------------------------------
# Sources.
file(GLOB_RECURSE SOURCES_APP "*.cpp")

# ------------------------------------------------------------------------------
# Target configuration.

set(APP_NAME sender)

add_executable(${APP_NAME} ${SOURCES_APP} ${HAL_SOURCES})

target_link_libraries(${APP_NAME}
    ${Boost_LIBRARIES}
)

# target_include_directories(${APP_NAME}
#     PRIVATE "${PROJECT_SOURCE_DIR}/include"
# )

install(TARGETS ${APP_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

# set(CMAKE_BUILD_TYPE Debug)
