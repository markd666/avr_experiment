set(NAME hal_libs)

add_subdirectory(terminal)

add_library(${NAME} STATIC
    reader.cpp
    writer.cpp
)

target_include_directories(${NAME} PUBLIC
    ../../
)

if(ENABLE_HAL_STD)
    message(STATUS "Using hal std library")

    add_subdirectory(std)
    add_subdirectory(gcc_addons)
    target_link_libraries(${NAME} hal_stdlib hal_gcc_addons)
endif(ENABLE_HAL_STD)
