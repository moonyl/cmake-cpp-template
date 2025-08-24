# src 디렉토리 CMakeLists.txt

# 라이브러리 소스 파일들 찾기
file(GLOB_RECURSE SOURCES "*.cpp" "*.cc" "*.cxx")
file(GLOB_RECURSE HEADERS "*.hpp" "*.hxx" "*.h")

# 라이브러리 생성 (정적 라이브러리)
if(SOURCES)
    # 안전한 타겟 이름 생성 (하이픈을 밑줄로 변환)
    string(REPLACE "-" "_" SAFE_TARGET_NAME ${PROJECT_NAME})
    set(TARGET_NAME ${SAFE_TARGET_NAME}_lib)

    add_library(${TARGET_NAME} STATIC ${SOURCES} ${HEADERS})

    # 헤더 파일 포함 경로 설정
    target_include_directories(${TARGET_NAME}
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
            $<INSTALL_INTERFACE:include>
    )

    # C++ 20 표준 설정
    target_compile_features(${TARGET_NAME} PUBLIC cxx_std_20)

    # 라이브러리 별칭 생성
    add_library(${PROJECT_NAME}::lib ALIAS ${TARGET_NAME})
else()
    message(STATUS "src 디렉토리에 소스 파일이 없습니다.")
endif()