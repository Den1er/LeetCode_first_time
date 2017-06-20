#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<unistd.h>
#include<errno.h>
int main()
{
    int n;
    struct hostent *h;
    char **p;
    char hostname[PATH_MAX];
    if(gethostname(hostname,PATH_MAX)<0);
    {
        fprintf(stderr,"gethostname failed:%s\n",strerror(errno));
        exit(0);
    }
    if(h = gethostbyname(hostent)==0)
    {
        fprintf(stderr,"gethostname failed:%s\n",strerror(errno));
        exit(0);
    }
    fprntf(stderr,"Host name:%s\n",h->h_name);
    for(n = 0,p = h->h_aliases;*p != NULL;p++,n++)
    {
        fprintf(sederr,"Alias name %d:%s\n",n+1,*p);
    }
    for(n = 0,n<h->length/sizeof(int);n++)
    {
        fprintf(stderr,"Ip Adress %d:%s\n",n+1,inet_ntoa(*((struct in_addr*)(h->addr_list[n]))));
    }
    return 0;




}
