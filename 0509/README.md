# 시스템 프로그래밍 10주차

## 📌 시스템 콜의 특징
사용자 모드(User Mode) → 커널 모드(Kernel Mode)로 전환

파일 입출력, 프로세스 제어, 메모리 관리 등 다양한 기능 수행

호출 시 OS에 권한 요청 후 결과 반환

📖 주요 시스템 콜 종류
분류	시스템 콜 함수 예시
프로세스 관리	fork(), exec(), wait(), exit()
파일 입출력	open(), read(), write(), lseek(), close()
디바이스 제어	ioctl(), read(), write()
정보 조회	getpid(), getuid(), alarm(), sleep()

## 📌 파일 관련 시스템 콜
함수명	설명
open()	파일 열기 또는 생성
read()	파일에서 데이터 읽기
write()	파일에 데이터 쓰기
lseek()	파일 내 포인터 위치 이동
close()	파일 닫기
unlink()	파일 삭제