# 시스템 프로그래밍 9주차

## 📂 하드 링크 & 심볼릭 링크
📌 하드 링크 (Hard Link)
- 기존 파일에 대한 새로운 이름이라고 생각할 수 있다.
- 실제로 기존 파일을 대표하는 i-node를 가리켜 구현한다.

📖 예시
$ ln hello.txt hi.txt
$ ls -l
-rw------- 2 chang cs  15 11월  7일 15:31 hello.txt
-rw------- 2 chang cs  15 11월  7일 15:31 hi.txt

📌 심볼릭 링크 (Symbolic Link)
- 다른 파일을 가리키는 별도의 파일이다.
- 실제 파일의 경로명을 저장하고 있는 특수 파일이다.
- 이 경로명이 다른 파일에 대한 간접적인 포인터 역할을 한다.

📖 예시
$ ln -s hello.txt hi.txt
$ ls -l
-rw------- 1 chang chang 15 11월  7일 15:31 hello.txt
lrwxrwxrwx 1 chang chang  9  1월 24일 12:56 hi.txt -> hello.txt