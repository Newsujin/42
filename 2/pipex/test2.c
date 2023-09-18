#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// int main() {
//     int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
//     if (fd == -1) {
//         perror("open");
//         exit(EXIT_FAILURE);
//     }

//     // 표준 출력(파일 디스크립터 1)을 파일 디스크립터 'fd'로 복제.
//     if (dup2(fd, 1) == -1) {
//         perror("dup2");
//         exit(EXIT_FAILURE);
//     }

//     printf("이 내용은 파일로 저장됩니다.\n");

//     close(fd);
//     return 0;
// }