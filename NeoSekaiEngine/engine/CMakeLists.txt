project(SekaiEngine VERSION 0.0.1)
set (CMAKE_CXX_STANDARD 11)

include(cmake/import_engine.cmake)
include(cmake/set_version_header.cmake)

set(WRAPPER_RAYLIB_HEADERS
    ./include/wrapper/raylib/Window.h
    ./include/wrapper/raylib/Parser.h
    ./include/wrapper/raylib/Texture.h
    ./include/wrapper/raylib/Font.h
)

set(WRAPPER_RAYLIB_SOURCES
    ./src/wrapper/raylib/MainLoop.cpp
    ./src/wrapper/raylib/Window.cpp
    ./src/wrapper/raylib/Input.cpp
    ./src/wrapper/raylib/RendererAPI.cpp
    ./src/wrapper/raylib/Parser.cpp
    ./src/wrapper/raylib/Camera.cpp
    ./src/wrapper/raylib/Texture.cpp
    ./src/wrapper/raylib/Timer.cpp
    ./src/wrapper/raylib/Font.cpp
)

set(ENGINE_PUBLIC_HEADERS
    ${WRAPPER_RAYLIB_HEADERS}
    ./include/SekaiEngine.h
    ./include/SekaiEngine/EntryPoint.h
    ./include/SekaiEngine/BaseType.h
    ./include/SekaiEngine/Application.h
    ./include/SekaiEngine/Window.h
    ./include/SekaiEngine/Event/Event.h
    ./include/SekaiEngine/Event/WindowEvent.h
    ./include/SekaiEngine/Layer/Layer.h
    ./include/SekaiEngine/Layer/LayerStack.h
    ./include/SekaiEngine/Input.h
    ./include/SekaiEngine/Math/Vector.h
    ./include/SekaiEngine/Render/RendererAPI.h
    ./include/SekaiEngine/Render/Color.h
    ./include/SekaiEngine/Render/RenderCommand.h
    ./include/SekaiEngine/Render/Renderer.h
    ./include/SekaiEngine/Render/Camera.h
    ./include/SekaiEngine/Timer.h
    ./include/SekaiEngine/Render/Texture.h
    ./include/SekaiEngine/Shape/Shape.h
    ./include/SekaiEngine/Shape/Circle.h
    ./include/SekaiEngine/Shape/Rectangle.h
    ./include/SekaiEngine/Render/RenderProperties.h
    ./include/SekaiEngine/Render/Params/RenderParams.h
    ./include/SekaiEngine/Render/Params/TextureRenderParams.h
    ./include/SekaiEngine/Render/Params/RectangleRenderParams.h
    ./include/SekaiEngine/Render/Params/CircleRenderParams.h
    ./include/SekaiEngine/Math/Utility.h
    ./include/SekaiEngine/Render/Font.h
)

set(ENGINE_SOURCES
    ${WRAPPER_RAYLIB_SOURCES}
    ./src/SekaiEngine/Application.cpp
    ./src/SekaiEngine/Window.cpp
    ./src/SekaiEngine/Event/Event.cpp
    ./src/SekaiEngine/Event/WindowEvent.cpp
    ./src/SekaiEngine/Layer/Layer.cpp
    ./src/SekaiEngine/Layer/LayerStack.cpp
    ./src/SekaiEngine/Math/Vector.cpp
    ./src/SekaiEngine/Render/Color.cpp
    ./src/SekaiEngine/Render/Renderer.cpp
    ./src/SekaiEngine/Render/Camera.cpp
    ./src/SekaiEngine/Timer.cpp
    ./src/SekaiEngine/Render/Texture.cpp
    ./src/SekaiEngine/Shape/Shape.cpp
    ./src/SekaiEngine/Shape/Circle.cpp
    ./src/SekaiEngine/Shape/Rectangle.cpp
    ./src/SekaiEngine/Render/RenderProperties.cpp
    ./src/SekaiEngine/Render/Params/RenderParams.cpp
    ./src/SekaiEngine/Render/Params/TextureRenderParams.cpp
    ./src/SekaiEngine/Render/Params/RectangleRenderParams.cpp
    ./src/SekaiEngine/Render/Params/CircleRenderParams.cpp
    ./src/SekaiEngine/Math/Utility.cpp
    ./src/SekaiEngine/Render/Font.cpp
)

option(BUILD_SHARED_LIBS "Build shared lib" ON)

add_subdirectory(./vendors/raylib)

add_library(SekaiEngine ${ENGINE_PUBLIC_HEADERS} ${ENGINE_SOURCES})
target_link_libraries(SekaiEngine PRIVATE raylib)
target_compile_definitions(SekaiEngine PRIVATE USE_RAYLIB)

if(BUILD_SHARED_LIBS)
    message(STATUS "Build shared lib for SekaiEngine")
    if (WIN32)
        target_compile_definitions(SekaiEngine
                                   PRIVATE $<BUILD_INTERFACE:BUILD_LIBTYPE_SHARED>
                                   INTERFACE $<INSTALL_INTERFACE:USE_LIBTYPE_SHARED>
                                   )
    endif ()
    set_property(TARGET SekaiEngine PROPERTY POSITION_INDEPENDENT_CODE ON)
else()
    message(STATUS "Build static lib for SekaiEngine")
endif()

target_include_directories(SekaiEngine
    PUBLIC 
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>

)

target_include_directories(SekaiEngine
    PUBLIC ${CMAKE_BINARY_DIR}/config/
)