#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));
    
    printf("Beginning forking...\n");
    
    int pid = fork();
    
    if (pid > 0) {
        int pid_two = fork();
        
        if (pid_two > 0) {
            int status;
            int child_pid = wait(&status);
            
            int sleep_time = WEXITSTATUS(status);
            printf("Child's PID: %d\tChild's sleep time: %d\n", child_pid, sleep_time);
            printf("Parent Done\n");
        } else {
            printf("Child 1 PID: %d\n", getpid());
            
            int sleep_time_1 = rand() % 4 + 2;
            sleep(sleep_time_1);
            
            printf("Child 1 Done\n");
            
            return sleep_time_1;
        }
    } else if (pid == 0) {
        printf("Child 0 PID: %d\n", getpid());
        
        int sleep_time_0 = rand() % 4 + 2;
        sleep(sleep_time_0);
        
        printf("Child 0 Done\n");
        
        return sleep_time_0;
    }
    
    return 0;
}
