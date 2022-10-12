cmake_minimum_required (VERSION 3.8)
project(BuasIntake)

file(GLOB SOURCES
"game/*.cpp"
"game/*.h")

add_executable (${PROJECT_NAME} ${SOURCES})

add_subdirectory(engine)

target_link_libraries(${PROJECT_NAME}
glr
)