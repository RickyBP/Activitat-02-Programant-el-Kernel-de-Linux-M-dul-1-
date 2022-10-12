//Implementar en C la llamada a sistema GetTimes

#include <sys/times.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    struct ptimes{
        unsigned long start_time;
        unsigned long real_time;
        unsigned long user_time;
        unsigned long sys_time;
    }ptimes;

task = pid_task(find_get_pid(pid), PIDTYPE_PID);
if (task == NULL) {
    printk(KERN_INFO "No se ha encontrado el proceso con PID %d para obtener tiempos", pid);
    return -1;
}

ptimes.start_time = task->start_time;
ptimes.real_time = task->real_start_time;
ptimes.user_time = task->utime;
ptimes.sys_time = task->stime;
