# C++ 프로젝트 템플릿

이 템플릿은 현대적인 C++ 프로젝트를 위한 기본 구조를 제공합니다.

## 특징

- **CMake 기반 빌드 시스템**: 크로스 플랫폼 빌드 지원
- **Google Test 통합**: 단위 테스트를 위한 Google Test 및 Google Mock
- **모듈화된 구조**: 라이브러리, 테스트, 예제로 분리된 구조
- **C++20 지원**: 최신 C++ 표준 사용
- **예제 코드**: 라이브러리 사용법을 보여주는 예제

## 프로젝트 구조

```
{{cookiecutter.project_name}}/
├── CMakeLists.txt           # 메인 CMake 파일
├── src/                     # 라이브러리 소스 코드
│   ├── CMakeLists.txt
│   ├── {{cookiecutter.library_name}}.cpp
│   └── {{cookiecutter.library_name}}.hpp
├── tests/                   # Google Test 기반 테스트
│   ├── CMakeLists.txt
│   └── test_main.cpp
├── example/                 # 사용 예제
│   ├── CMakeLists.txt
│   └── basic_usage.cpp
└── README.md
```

## 빌드 방법

```bash
# 빌드 디렉토리 생성 및 이동
mkdir build
cd build

# CMake 구성
cmake ..

# 빌드
make

# 테스트 실행
ctest
```

## 개발 환경

- **C++ 표준**: C++{{cookiecutter.cpp_standard}}
- **빌드 시스템**: CMake 3.20+
- **컴파일러**: GCC 9+, Clang 10+, MSVC 2019+

## 라이선스

{{cookiecutter.license}}