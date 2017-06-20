#include<apue.h>


int main()
{
    /*
    if((pid = fork()) < 0)
        err_sys("for error");
    else if(pid == 0)
    {
        execlp(buf, buf, (char*) 0);
        err_ret("%s", buf);
        exit(127);
    }
    */
    printf("hello world");
    //print("my pid is :%d", getpid());
    return 0;

}
