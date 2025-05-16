# 시스템 프로그래밍 11주차

## 📌 락 종류
공유 락 (읽기 락) : 여러 프로세스 읽기 가능, 쓰기는 불가

배타 락 (쓰기 락) : 락 건 프로세스만 읽기/쓰기 가능

## 📌 주요 함수
함수	설명

fcntl()	파일의 일부나 전체에 세밀하게 락 설정

flock()	파일 전체에 락 설정, 간단함

lockf()	POSIX 표준, 사용법 쉬움

## 📌 fcntl() 기본 사용법

#include <fcntl.h>

struct flock lock;

lock.l_type = F_WRLCK;        // 락 타입 (F_RDLCK, F_WRLCK, F_UNLCK)

lock.l_whence = SEEK_SET;     // 기준 위치

lock.l_start = 0;             // 락 시작 위치

lock.l_len = 0;               // 락 길이 (0이면 파일 끝까지)

fcntl(fd, F_SETLKW, &lock);   // 락 설정 (대기)

## 락 해제

lock.l_type = F_UNLCK;

fcntl(fd, F_SETLK, &lock);

📖 언제 쓰나?
파일에 동시에 접근하는 프로세스가 있을 때

데이터베이스 파일, 로그 파일, 레코드 파일 보호할 때