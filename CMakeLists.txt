cmake_minimum_required(VERSION 3.28)

project(moduleexp)

add_library(lib2)

target_sources(lib2 
	PUBLIC FILE_SET CXX_MODULES FILES
	${CMAKE_CURRENT_SOURCE_DIR}/lib2.cppm
)

target_compile_features(lib2 PRIVATE cxx_std_20)

add_library(lib1)

target_sources(lib1 
	PUBLIC FILE_SET CXX_MODULES FILES
	lib1.cpp
)

target_link_libraries(lib1 PRIVATE lib2)
target_compile_features(lib1 PRIVATE cxx_std_20)

add_executable(main)

target_sources(main 
	PRIVATE
	main.cpp
)

target_link_libraries(main PRIVATE lib1)
target_compile_features(main PRIVATE cxx_std_20)
