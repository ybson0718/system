# 시스템 프로그래밍 13주차

## 🎙️정규표현식에 대하여 발표 진행

## 정규 표현식 (Regular Expression)

> 특정한 규칙을 가진 문자열의 집합을 표현하는 방법  
> 즉, **문자열 패턴을 찾거나 검사할 때 사용하는 표현식**

---

## 📌 특징  

- 문자열에서 **특정 패턴을 찾거나 치환할 때 사용**
- `grep`, `sed`, `awk`, `vi`, `python` 등 다양한 곳에서 활용 가능

---

## 📖 주요 기호  

| 기호    | 의미                        | 예시                         |
|:---------|:-----------------------------|:------------------------------|
| `.`       | 임의의 한 문자                 | `a.b` → `aab`, `acb`, `a1b` 등 |
| `*`       | 앞 문자가 0개 이상 반복          | `a*` → `""`, `"a"`, `"aaa"`    |
| `+`       | 앞 문자가 1개 이상 반복          | `a+` → `"a"`, `"aa"`           |
| `?`       | 앞 문자가 0개 또는 1개           | `a?` → `""`, `"a"`             |
| `[]`      | 대괄호 안 문자 중 하나 선택       | `[abc]` → `"a"`, `"b"`, `"c"`  |
| `[^ ]`    | 대괄호 안에 없는 문자 선택        | `[^0-9]` → 숫자가 아닌 문자    |
| `^`       | 문자열의 시작                   | `^a` → "a"로 시작하는 문자열    |
| `$`       | 문자열의 끝                     | `a$` → "a"로 끝나는 문자열      |

---

## 📖 예시  

- **hello로 시작하는 줄 찾기**
  ```regex
  ^hello
