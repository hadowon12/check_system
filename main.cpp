#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int check() //프로그램 구동 함수
{
    int start;
    printf("-----------------------------------\n");
    printf("--------출석체크 시스템---------------\n");
    printf("1.출석\n");
    printf("2.고유번호 발급\n");
    printf("3.출석 조회\n");
    printf("4.종료\n");
    printf("-----------------------------------\n");
    printf("원하는 항목의 숫자를 입력하고 엔터(Enter) : ");
    scanf("%d", &start);
    if (start == 4) {
        exit(0);
    } else {
        system("CLS");
        return start;
    }
}

int main() {
//    int date[1000][2] = {{0,},}; //출석 일수 0번째 줄은 고유번호 존재 유무 1번째줄은 출석 일수
    int date[1000][2] = {0};
    int sys; // 어떤 동작을 할껀지 지정하는 함수
    int i, j, k, a;
    while (1) {
        sys = check();
        switch (sys) {
            case 1:
                printf("고유번호를 입력하세요:");
                scanf("%d", &i);
                date[i][1] += 1; //출석일수 증가
                break;
            case 2:
                srand(time(NULL));
                j = rand() % 1000; //j의 범위 0~999
                if (date[j][0] == 0) {
                    printf("당신의 고유번호는 %d 입니다.", j);
                    date[j][0] += 1;
                }
                break;
            case 3:
                for (a = 0; a < 1000; a++) {
                    if (date[a][0] != 0) {
                        printf("고유번호 %d 출석일수는 %d 입니다.\n", a, date[a][1]);
                    }
                }
                break;
        }
    }
}

