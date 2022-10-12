cmake_minimum_required (VERSION 3.8)
project(BuasIntake)

file(GLOB SOURCES
"src/*.cpp"
"src/*.h")

add_executable (BuasIntake ${SOURCES})