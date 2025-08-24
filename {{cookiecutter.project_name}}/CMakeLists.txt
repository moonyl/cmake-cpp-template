# CMake 최소 버전 설정
cmake_minimum_required(VERSION 3.20)

# 프로젝트 이름과 버전 설정
project({{cookiecutter.project_name}} VERSION {{cookiecutter.version}})

# C++ {{cookiecutter.cpp_standard}} 표준 사용
set(CMAKE_CXX_STANDARD {{cookiecutter.cpp_standard}})
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 컴파일러 옵션 설정
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 빌드 디렉토리 설정
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# CTest 활성화 (전역)
enable_testing()

# 서브디렉토리 추가
add_subdirectory(src)
add_subdirectory(example)
add_subdirectory(tests)