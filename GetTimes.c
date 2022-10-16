//Realitzeu la implemetació, integració i test d'una nova crida a sistema anomenada gettimes. gettimes(int, pid, struct ptimes *pt).
//Aquesta crida ens permetrà obtenir informació sobre un procés concret:
//real: temps total del procés.
//user: temps total en mode usuari.
//sys: temps total en mode sistema.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_gettimes 333

//TIP's: 
struct ptimes {
    unsigned long start_time;
    unsigned long real_time;
    unsigned long user_time;
    unsigned long sys_time;
};

int main(int argc, char *argv[])
{
    int pid;
    struct ptimes pt;
    int ret;

    if (argc != 2) {
        printf("Usage: %s <pid> \n", argv[0]);
        exit(1);
    }

    pid = atoi(argv[1]);

    ret = syscall(__NR_gettimes, pid, &pt);
    if (ret < 0) {
        perror("gettimes");
        exit(1);
    }

    printf("start_time: %lu \t real_time: %lu \t user_time: %lu \t sys_time: %lu \n", pt.start_time, pt.real_time, pt.user_time, pt.sys_time);

    return 0;
}
