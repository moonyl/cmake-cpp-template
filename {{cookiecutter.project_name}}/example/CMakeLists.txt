# example 디렉토리 CMakeLists.txt

# 예제 실행 파일들을 위한 설정
file(GLOB EXAMPLE_SOURCES "*.cpp" "*.cc" "*.cxx")

# 각 예제 파일에 대해 실행 파일 생성
foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    # 파일 이름에서 확장자 제거하여 실행 파일 이름 생성
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})

    # C++ 20 표준 설정
    target_compile_features(${EXAMPLE_NAME} PRIVATE cxx_std_20)

    # src 라이브러리가 존재하면 링크
    # 안전한 타겟 이름 생성 (하이픈을 밑줄로 변환)
    string(REPLACE "-" "_" SAFE_TARGET_NAME ${PROJECT_NAME})
    set(TARGET_NAME ${SAFE_TARGET_NAME}_lib)

    if(TARGET ${TARGET_NAME})
        target_link_libraries(${EXAMPLE_NAME} PRIVATE ${TARGET_NAME})
        target_include_directories(${EXAMPLE_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)
    endif()

    # 출력 디렉토리 설정
    set_target_properties(${EXAMPLE_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/examples
    )
endforeach()

# 예제 파일이 없는 경우 메시지 출력
if(NOT EXAMPLE_SOURCES)
    message(STATUS "example 디렉토리에 예제 파일이 없습니다.")
endif()