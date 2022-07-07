#include <iostream>
#include <cstring>
#include <unistd.h>  // syscall()
#include <syscall.h> // SysCall nummers
#include <fcntl.h>   // O_RDONLY
#include <sys/types.h>
#include <sys/wait.h>

int main();
void new_file();
void list();
void find();
void seek();
void src();
