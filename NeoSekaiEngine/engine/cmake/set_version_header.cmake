message(STATUS "Configure version")
configure_file(./config/version.h.cmake ${CMAKE_BINARY_DIR}/config/version.h)