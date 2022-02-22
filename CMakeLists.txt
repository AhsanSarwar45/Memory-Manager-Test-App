cmake_minimum_required(VERSION 3.16)

project(TestProject)

set(CMAKE_CXX_STANDARD 17)
set(CPP_LINKER_FLAGS "-loleaut32 -limm32 -lversion -lole32")

add_subdirectory("${CMAKE_SOURCE_DIR}/Vendor/MemoryManager")

add_executable(${PROJECT_NAME} 
"Source/Main.cpp"
)

target_include_directories(${PROJECT_NAME} PUBLIC "Source")
target_include_directories(${PROJECT_NAME} PUBLIC "Vendor")

target_link_libraries(${PROJECT_NAME} PRIVATE MemoryManager)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE
      _CRT_SECURE_NO_WARNINGS
    PUBLIC
      $<$<CONFIG:Debug>:DEBUG>
      $<$<CONFIG:RelWithDebInfo>:DEBUG>
      $<$<CONFIG:Release>:RELEASE>
      $<$<CONFIG:MinSizeRel>:RELEASE>
)