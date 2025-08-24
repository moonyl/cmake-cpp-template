# tests 디렉토리 CMakeLists.txt

# Google Test 다운로드 및 설정
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# Google Test의 C++ 표준 설정 방지 (우리의 설정을 사용)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 테스트 소스 파일들 찾기
file(GLOB TEST_SOURCES "*_test.cpp" "*_tests.cpp" "test_*.cpp" "*.test.cpp")

# 각 테스트 파일에 대해 실행 파일 생성
foreach(TEST_SOURCE ${TEST_SOURCES})
    # 파일 이름에서 확장자 제거하여 테스트 이름 생성
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_SOURCE})

    # C++ 20 표준 설정
    target_compile_features(${TEST_NAME} PRIVATE cxx_std_20)

    # src 라이브러리가 존재하면 링크
    # 프로젝트 이름에서 하이픈을 밑줄로 변환하여 라이브러리 타겟 이름 생성
    string(REPLACE "-" "_" SAFE_TARGET_NAME ${PROJECT_NAME})
    set(TARGET_LIB_NAME ${SAFE_TARGET_NAME}_lib)    

    # src 라이브러리가 존재하면 링크
    if(TARGET ${TARGET_LIB_NAME})
        target_link_libraries(${TEST_NAME} PRIVATE ${TARGET_LIB_NAME})
        target_include_directories(${TEST_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)
    endif()

    # Google Test 라이브러리 링크
    target_link_libraries(${TEST_NAME} PRIVATE GTest::gtest_main GTest::gmock_main)

    # 테스트로 등록
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})

    # 테스트 실행 파일의 출력 디렉토리 설정
    set_target_properties(${TEST_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/tests
    )
endforeach()

# 테스트 파일이 없는 경우 메시지 출력
if(NOT TEST_SOURCES)
    message(STATUS "tests 디렉토리에 테스트 파일이 없습니다.")
endif()

# 테스트 타겟 추가 (모든 테스트를 한 번에 실행)
if(TEST_SOURCES)
    add_custom_target(run_tests
        COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
        DEPENDS ${TEST_SOURCES}
        COMMENT "Running all tests"
    )
endif()