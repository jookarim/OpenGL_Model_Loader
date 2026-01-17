cmake_minimum_required(VERSION 3.26)

project(Shadow_Mapping_OpenGL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------- ImGui ----------------
add_library(imgui STATIC
    External/include/imgui/imgui.cpp
    External/include/imgui/imgui_draw.cpp
    External/include/imgui/imgui_tables.cpp
    External/include/imgui/imgui_widgets.cpp
    External/include/imgui/imgui_demo.cpp
    External/include/imgui/backends/imgui_impl_glfw.cpp
    External/include/imgui/backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui PUBLIC
    External/include/imgui
    External/include/imgui/backends
    External/include        
)

# ---------------- Game ----------------
add_executable(Shadow_Mapping_OpenGL
    src/main.cpp
    src/VertexArray.cpp
    src/VertexBuffer.cpp
    src/IndexBuffer.cpp
    src/Device.cpp
    src/Window.cpp
    src/Mesh.cpp
)

target_include_directories(Shadow_Mapping_OpenGL PRIVATE
    include
    External/include    # GL, GLFW, GLM, ImGui, stb
)

target_link_directories(Shadow_Mapping_OpenGL PRIVATE
    External/lib
)

target_link_libraries(Shadow_Mapping_OpenGL PRIVATE
    glfw3
    glew32
    opengl32
    imgui
    assimp-vc143-mtd
)

# ---------------- Assets ----------------
add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:Shadow_Mapping_OpenGL>/assets
)
add_dependencies(Shadow_Mapping_OpenGL copy_assets)

# ---------------- DLLs ----------------
if (WIN32)
    file(GLOB GLEW_DLLS CONFIGURE_DEPENDS
        "${CMAKE_SOURCE_DIR}/External/lib/*.dll"
    )

    if (GLEW_DLLS)
        add_custom_command(TARGET Shadow_Mapping_OpenGL POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${GLEW_DLLS}
                $<TARGET_FILE_DIR:Shadow_Mapping_OpenGL>
            COMMAND_EXPAND_LISTS
        )
    endif()
endif()