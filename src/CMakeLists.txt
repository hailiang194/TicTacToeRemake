
project(TicTacToe VERSION 1.0.0)

set(TicTacToe_SOURCES
    ./TicTacToeApp.cpp
)

add_executable(TicTacToe ${TicTacToe_SOURCES})
target_link_libraries(TicTacToe PUBLIC SekaiEngine)
target_include_directories(TicTacToe PUBLIC ${CMAKE_SOURCE_DIR}/NeoSekaiEngine/engine/include)
target_compile_definitions(TicTacToe PRIVATE HAS_ENTRY_POINT)

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(TicTacToe "-framework IOKit")
    target_link_libraries(TicTacToe "-framework Cocoa")
    target_link_libraries(TicTacToe "-framework OpenGL")
endif()

# Web Configuration
if (${PLATFORM} STREQUAL "Web")
    # Tell Emscripten to build an example.html file.
    set_target_properties(TicTacToe PROPERTIES SUFFIX ".html")
endif()

if (EMSCRIPTEN)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY")
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
endif ()

if (EMSCRIPTEN)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --preload-file ${CMAKE_SOURCE_DIR}/assets@")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --preload-file ${CMAKE_SOURCE_DIR}/assets@")
else()
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/assets"
$<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif()
    