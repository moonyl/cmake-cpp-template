# C++ 프로젝트 템플릿 (Cookiecutter)

이 리포지토리는 현대적인 C++ 프로젝트를 빠르게 시작할 수 있는 Cookiecutter 템플릿입니다.

## 사용 방법

### 1. Cookiecutter 설치

```bash
pip install cookiecutter
```

### 2. 프로젝트 생성

```bash
# GitHub에서 직접 사용
cookiecutter https://github.com/your-org/cpp-project-template

# 또는 로컬에서 사용 (현재 디렉토리에서)
cookiecutter .
```

### 3. 대화형 설정

프로젝트 생성 시 다음 항목들을 설정할 수 있습니다:

- **project_name**: 프로젝트 이름 (기본값: MyCppProject)
- **project_description**: 프로젝트 설명
- **author_name**: 작성자 이름
- **library_name**: 라이브러리 이름 (기본값: my_library)
- **version**: 초기 버전 (기본값: 1.0.0)
- **cpp_standard**: C++ 표준 (20, 17, 14 중 선택)
- **use_google_test**: Google Test 사용 여부 (yes/no)
- **use_examples**: 예제 포함 여부 (yes/no)
- **license**: 라이선스 (MIT, Apache-2.0, BSD-3-Clause, None)

### 4. 생성된 프로젝트 사용

```bash
cd your-project-name

# 빌드 디렉토리 생성
mkdir build && cd build

# CMake 구성 및 빌드
cmake ..
make

# 테스트 실행
ctest
```

## 템플릿 특징

- **CMake 기반 빌드 시스템**: 크로스 플랫폼 지원
- **Google Test 통합**: 단위 테스트 및 모의 객체 지원
- **모듈화된 구조**: 라이브러리, 테스트, 예제로 분리
- **C++20 지원**: 최신 C++ 표준
- **예제 코드**: 라이브러리 사용법 제공

## 템플릿 구조

```
template/
└── {{cookiecutter.project_name}}/
    ├── CMakeLists.txt
    ├── src/
    │   ├── CMakeLists.txt
    │   ├── {{cookiecutter.library_name}}.cpp
    │   └── {{cookiecutter.library_name}}.hpp
    ├── tests/
    │   ├── CMakeLists.txt
    │   └── test_main.cpp
    ├── example/
    │   ├── CMakeLists.txt
    │   └── basic_usage.cpp
    └── README.md
```

## 요구 사항

- **Cookiecutter**: `pip install cookiecutter`
- **CMake**: 3.20 이상
- **C++ 컴파일러**: GCC 9+, Clang 10+, MSVC 2019+

## 라이선스

이 템플릿은 MIT 라이선스로 제공됩니다.