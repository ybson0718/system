# 시스템 프로그래밍 14주차

# 🐧 리눅스 기초 및 필수 명령어 50선

---

## 📁 파일 및 디렉토리 관리

| 명령어 | 설명 |
|--------|------|
| `ls` | 디렉토리 내 파일 및 폴더 목록 출력 |
| `cd` | 디렉토리 변경 (상대경로, 절대경로 가능) |
| `pwd` | 현재 작업 디렉토리 경로 출력 |
| `mkdir` | 새 디렉토리 생성 (`-p`: 상위 디렉토리 함께 생성) |
| `rmdir` | 비어 있는 디렉토리 삭제 |
| `rm` | 파일 삭제 (`-r`: 디렉토리도 재귀 삭제) |
| `cp` | 파일 또는 디렉토리 복사 (`-r`: 디렉토리 복사) |
| `mv` | 파일 또는 디렉토리 이동/이름 변경 |
| `touch` | 빈 파일 생성 또는 수정 시간 갱신 |
| `find` | 조건에 맞는 파일/디렉토리 검색 |
| `tree` | 트리 구조로 디렉토리 출력 (설치 필요) |

---

## 📄 파일 내용 조회 및 편집

| 명령어 | 설명 |
|--------|------|
| `cat` | 파일 내용 출력 또는 연결 |
| `less` | 파일 내용 페이지 단위 조회 |
| `head` | 파일 앞부분 출력 (기본 10줄) |
| `tail` | 파일 뒷부분 출력 |
| `tail -f` | 실시간 로그 모니터링 |
| `nano` | 텍스트 편집기 (초보자용) |
| `vim` | 고급 텍스트 편집기 |

---

## 👤 사용자 및 권한 관리

| 명령어 | 설명 |
|--------|------|
| `whoami` | 현재 사용자 출력 |
| `id` | 사용자 및 그룹 ID 정보 출력 |
| `chmod` | 권한 변경 (숫자/문자 방식) |
| `chown` | 파일 소유자/그룹 변경 |
| `sudo` | 관리자 권한으로 명령어 실행 |
| `su` | 다른 사용자로 전환 (root 등) |

---

## ⚙️ 시스템 모니터링 및 관리

| 명령어 | 설명 |
|--------|------|
| `top` | 실시간 시스템 프로세스 확인 |
| `htop` | `top`의 시각화 버전 (설치 필요) |
| `ps` | 실행 중인 프로세스 목록 확인 (`aux` 옵션 자주 사용) |
| `kill` | PID로 프로세스 종료 (`-9`: 강제 종료) |
| `df` | 디스크 사용량 확인 (`-h`: 보기 쉽게) |
| `du` | 폴더/파일 용량 확인 |
| `free` | 메모리 사용량 확인 (`-h` 권장) |
| `uptime` | 시스템 가동 시간 확인 |
| `uname` | 시스템 커널 정보 출력 (`-a`: 전체 정보) |
| `hostname` | 시스템 호스트명 출력 |
| `reboot` | 시스템 재부팅 (sudo 필요) |
| `shutdown` | 시스템 종료 (`now` 또는 시간 지정 가능) |

---

## 🌐 네트워크 및 인터넷

| 명령어 | 설명 |
|--------|------|
| `ip` | 네트워크 인터페이스 및 IP 주소 확인 (`ip a`) |
| `ping` | 네트워크 연결 확인 |
| `curl` | HTTP 요청 보내기 (간단 테스트) |
| `wget` | 웹에서 파일 다운로드 |
| `netstat` | 포트/연결 상태 확인 (구버전) |
| `ss` | 최신 netstat 대체 명령어 |

---

## 📦 패키지 관리 (APT 계열)

| 명령어 | 설명 |
|--------|------|
| `apt update` | 패키지 목록 갱신 |
| `apt upgrade` | 설치된 패키지 업그레이드 |
| `apt install` | 새 패키지 설치 (`apt install vim`) |
| `apt remove` | 패키지 제거 |
| `apt search` | 패키지 검색 |
| `dpkg -l` | 설치된 패키지 목록 (`| less` 권장) |

---

## 🛠 기타 유용한 명령어

| 명령어 | 설명 |
|--------|------|
| `alias` | 명령어에 별칭 지정 (`alias ll='ls -al'`) |
| `history` | 입력한 명령어 이력 보기 |
| `clear` | 터미널 화면 지우기 |

---

# 🐧 리눅스 명령어 C 언어 구현 예제

## 🔹 ls
```c
#include <stdio.h>
#include <dirent.h>

int main() {
    struct dirent *entry;
    DIR *dp = opendir(".");

    if (dp == NULL) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dp)))
        printf("%s\n", entry->d_name);

    closedir(dp);
    return 0;
}
```

## 🔹 cd
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    const char *path = ".."; // 이동할 경로
    if (chdir(path) != 0) {
        perror("chdir failed");
        return 1;
    }

    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("Changed directory to: %s\n", cwd);
    return 0;
}
```

## 🔹 pwd
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("Current working directory: %s\n", cwd);
    else
        perror("getcwd() error");
    return 0;
}
```

## 🔹 mkdir
```c
#include <stdio.h>
#include <sys/stat.h>

int main() {
    const char *dir = "newdir";
    if (mkdir(dir, 0755) != 0) {
        perror("mkdir");
        return 1;
    }
    printf("Directory created: %s\n", dir);
    return 0;
}
```

## 🔹 rmdir
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    const char *dir = "newdir";
    if (rmdir(dir) != 0) {
        perror("rmdir");
        return 1;
    }
    printf("Directory removed: %s\n", dir);
    return 0;
}
```

## 🔹 rm
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    const char *file = "file.txt";
    if (unlink(file) != 0) {
        perror("unlink");
        return 1;
    }
    printf("File removed: %s\n", file);
    return 0;
}
```

## 🔹 cp
```c
#include <stdio.h>

int main() {
    FILE *src = fopen("source.txt", "r");
    FILE *dest = fopen("copy.txt", "w");
    char ch;

    if (!src || !dest) {
        perror("File error");
        return 1;
    }

    while ((ch = fgetc(src)) != EOF)
        fputc(ch, dest);

    fclose(src);
    fclose(dest);
    printf("File copied successfully.\n");
    return 0;
}
```

## 🔹 mv
```c
#include <stdio.h>

int main() {
    const char *oldname = "file.txt";
    const char *newname = "moved_file.txt";

    if (rename(oldname, newname) != 0) {
        perror("rename");
        return 1;
    }

    printf("File renamed/moved.\n");
    return 0;
}
```

## 🔹 touch
```c
#include <stdio.h>

int main() {
    const char *filename = "newfile.txt";
    FILE *file = fopen(filename, "a");

    if (!file) {
        perror("fopen");
        return 1;
    }

    fclose(file);
    printf("File touched: %s\n", filename);
    return 0;
}
```

## 🔹 find
```c
#include <stdio.h>
#include <dirent.h>
#include <string.h>

void find_file(const char *path, const char *name) {
    struct dirent *entry;
    DIR *dp = opendir(path);
    char fullpath[1024];

    if (!dp) return;

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, name) == 0)
            printf("Found: %s/%s\n", path, name);
    }

    closedir(dp);
}

int main() {
    find_file(".", "target.txt");
    return 0;
}
```

## 🔹 tree
```c
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void print_tree(const char *path, int depth) {
    struct dirent *entry;
    DIR *dp = opendir(path);
    char fullpath[1024];

    if (!dp) return;

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        for (int i = 0; i < depth; i++) printf("  ");
        printf("|-- %s\n", entry->d_name);
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
        struct stat st;
        if (stat(fullpath, &st) == 0 && S_ISDIR(st.st_mode))
            print_tree(fullpath, depth + 1);
    }

    closedir(dp);
}

int main() {
    print_tree(".", 0);
    return 0;
}
```

## 🔹 cat
```c
#include <stdio.h>

int main() {
    FILE *file = fopen("file.txt", "r");
    char ch;

    if (!file) {
        perror("fopen");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF)
        putchar(ch);

    fclose(file);
    return 0;
}
```

## 🔹 less
```
// C에서 less 명령어 기능 구현은 터미널 페이지 처리 필요로 어려움이 있습니다. `system("less filename")`으로 대체 가능합니다.
```

## 🔹 head
```c
#include <stdio.h>

int main() {
    FILE *file = fopen("file.txt", "r");
    char line[256];
    int count = 0;

    if (!file) {
        perror("fopen");
        return 1;
    }

    while (fgets(line, sizeof(line), file) && count++ < 10)
        fputs(line, stdout);

    fclose(file);
    return 0;
}
```

## 🔹 tail
```
// tail 구현은 파일 전체를 읽은 후 마지막 줄부터 출력해야 하므로, C에서는 버퍼를 이용해 구현하거나 시스템 호출을 활용할 수 있습니다.
```

## 🔹 tail -f
```
// tail -f는 파일 변경을 지속적으로 감시하므로 C에서 파일 포인터 및 sleep()으로 구현해야 하며 고급 로직이 필요합니다.
```

## 🔹 nano
```
// nano는 별도 프로그램입니다. C에서는 system("nano filename") 으로 실행 가능합니다.
```

## 🔹 vim
```
// vim은 C로 구현할 수 없으며 외부 프로그램 호출로 system("vim filename") 사용이 일반적입니다.
```

## 🔹 whoami
```c
#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

int main() {
    struct passwd *pw;
    pw = getpwuid(getuid());
    printf("User: %s\n", pw->pw_name);
    return 0;
}
```

## 🔹 id
```c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("UID: %d\n", getuid());
    printf("GID: %d\n", getgid());
    return 0;
}
```

## 🔹 chmod
```c
#include <stdio.h>
#include <sys/stat.h>

int main() {
    if (chmod("file.txt", 0644) != 0) {
        perror("chmod");
        return 1;
    }
    printf("Permissions changed.\n");
    return 0;
}
```

## 🔹 chown
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    if (chown("file.txt", 1000, 1000) != 0) {
        perror("chown");
        return 1;
    }
    printf("Owner changed.\n");
    return 0;
}
```

## 🔹 sudo
```
// sudo는 시스템 명령어로 직접 구현할 수 없습니다. system("sudo command") 사용 가능.
```

## 🔹 su
```
// su 명령은 터미널과 로그인 처리를 필요로 하며, system("su")로 실행 가능.
```

## 🔹 top
```
// top은 시스템 전반 상태 모니터링 도구로, C로 유사 구현은 어렵고 system("top") 사용.
```

## 🔹 htop
```
// htop은 top의 대체 시각화 도구로 system("htop") 으로 호출 가능.
```

## 🔹 ps
```
// ps 명령은 system("ps aux") 형식으로 호출하여 출력 받을 수 있습니다.
```

## 🔹 kill
```c
#include <stdio.h>
#include <signal.h>

int main() {
    int pid = 1234; // 종료할 프로세스 ID
    if (kill(pid, SIGKILL) != 0) {
        perror("kill");
        return 1;
    }
    printf("Process killed.\n");
    return 0;
}
```

## 🔹 df
```
// df는 파일 시스템 상태를 보여주는 명령어로 system("df -h") 호출을 통해 사용합니다.
```

## 🔹 du
```
// du 명령어는 system("du -sh") 등으로 실행 가능하며 직접 구현은 복잡합니다.
```

## 🔹 free
```
// free 메모리 정보는 system("free -h") 으로 호출할 수 있습니다.
```

## 🔹 uptime
```
// uptime은 system("uptime") 으로 실행하여 정보를 얻습니다.
```

## 🔹 uname
```c
#include <stdio.h>
#include <sys/utsname.h>

int main() {
    struct utsname buffer;
    if (uname(&buffer) == 0) {
        printf("System name: %s\n", buffer.sysname);
        printf("Node name: %s\n", buffer.nodename);
        printf("Release: %s\n", buffer.release);
        printf("Version: %s\n", buffer.version);
        printf("Machine: %s\n", buffer.machine);
    } else {
        perror("uname");
    }
    return 0;
}
```

## 🔹 hostname
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    char hostname[1024];
    gethostname(hostname, 1024);
    printf("Hostname: %s\n", hostname);
    return 0;
}
```

## 🔹 reboot
```
// reboot 명령은 관리자 권한이 필요하며 system("reboot") 으로 실행 가능.
```

## 🔹 shutdown
```
// shutdown도 system("shutdown now") 등으로 실행 가능. root 권한 필요.
```

## 🔹 ip
```
// ip a 출력은 system("ip a") 호출로 대체할 수 있습니다.
```

## 🔹 ping
```
// ping은 system("ping -c 4 google.com") 으로 호출 가능.
```

## 🔹 curl
```
// curl은 system("curl http://example.com") 과 같이 실행합니다.
```

## 🔹 wget
```
// wget은 system("wget http://example.com") 으로 실행할 수 있습니다.
```

## 🔹 netstat
```
// netstat은 system("netstat -tuln") 과 같이 호출합니다.
```

## 🔹 ss
```
// ss는 system("ss -tuln") 으로 대체 가능.
```

## 🔹 apt update
```
// apt update는 system("sudo apt update") 사용.
```

## 🔹 apt upgrade
```
// apt upgrade는 system("sudo apt upgrade") 사용.
```

## 🔹 apt install
```
// apt install은 system("sudo apt install vim") 등으로 사용.
```

## 🔹 apt remove
```
// apt remove는 system("sudo apt remove package") 으로 사용.
```

## 🔹 apt search
```
// apt search는 system("apt search keyword") 사용.
```

## 🔹 dpkg -l
```
// dpkg -l은 system("dpkg -l") 호출.
```

## 🔹 alias
```
// alias는 쉘 기능이며 C 코드로 직접 구현하지 않고 shell 명령 사용.
```

## 🔹 history
```
// history는 쉘 내부 명령으로 system("history") 로 호출 불가. bash 환경에서만 사용 가능.
```

## 🔹 clear
```c
#include <stdlib.h>

int main() {
    system("clear");
    return 0;
}
```

