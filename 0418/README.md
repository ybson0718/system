# 시스템 프로그래밍 7주차

## 🔍 grep
파일에서 문자열이나 패턴 검색

정규 표현식 사용 가능

📌 사용법
grep [검색어] [파일명]

 예시
grep "main" hello.c
→ hello.c 파일에서 "main"이 포함된 줄 출력

## 🛠️ make
프로그램 빌드 자동화 도구

Makefile에 명령어와 의존성 정의

📌 사용법
make [타겟명]

아무것도 안 쓰면 기본 타겟 실행

📌 예시
make
make clean
→ Makefile에 정의된 명령 실행

## ⚙️ gcc
C 언어 프로그램을 컴파일하는 컴파일러

소스 파일을 목적 파일(.o)이나 실행 파일로 변환

📌 사용법
gcc [옵션] [소스파일] -o [실행파일명]

📌 예시
gcc hello.c -o hello
./hello
→ hello.c를 컴파일해 hello 실행 파일 생성 및 실행