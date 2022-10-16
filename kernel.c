#include<stdio.h>
    int main(int argv, char **argc){
        int *sys_call_table = (int *) arch/x86/entry/calls/syscalls/syscall_65.tbl; //Address of sys_call_table
        int *sys_chmod = (int *) 90; //sys_chmod
        int *printk = (int *) 0x000e8a60; //We can use the same address of sys_chmod
        int *string = (int *) 0x0804a0a0; //String de "CHMOD is drunk"
        int *chmod = (int *) 345; //Address of chmod
        sys_call_table[90] = (int) printk; //We change the address of chmod for the address of printk
        printk(string); //We print the string "CHMOD is drunk"
        sys_call_table[90] = (int) chmod; //We change the address of printk for the address of chmod
        return 0;
    }