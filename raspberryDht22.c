
#include<unistd.h>
#include<sys/time.h> 
#include<stdint.h>
#include<sys/types.h>
#include<errno.h> 
#include<wiringSerial.h> 
#include<string.h>
#include<wiringPi.h>

#define BUFSIZE 30

int fd;

int main(int argc, char*argv[]) 
{

    char Tx_str[128] = {0,}; 
    char Rx_str[128] = {0,}; 
    int c;
    int isRx Serial End = 0;

    if((fd = serialopen("/dev/ttyAMAO", 9600)) <0) 
    {
    fprintf(stderr, "Unable to open serial device: %s\n", strerror(errno));
    return 1; 
    }


    if(wiringPiSetup()==-1)
    {
    fprintf(stdout, "Unable to start wiringPi: %s\n", strerror(errno)); }
    return 1;
    }

    fd_set reads, temps;
    int result; 
    int str len;
    struct timeval timeout;

    FD_ZERO(&reads); 
    FD_SET (O. &reads);

    while (1)
    {
    temps = reads; 
    timeout.tv_sec = 0; 
    timeout.tv_usec = 1000;

    result = select(1, &temps, 0, 0, &timeout);

    if(result == 0)
    {
    if(serialDataAvail(fd))
    {
    isRx Serial End = 1; 
    c = read(fd, Rx_str, sizeof(Rx_str));
    if (c>0)
        {
        char option [100];
        char first[] = "1";
        char second [] = "2";
        char third[] = "3";
        char *base "1. Hum 2. Temp 3.All";

        write(1, base, strlen(base));//tool 
        scanf("%s", option); 
        int flag = 1;

        while(flag == 1)
        {  
        if(!strcmp(option, first))
        {
        Rx_str[c] = '\0';

        char *h= strtok(Rx_str, "H"); 
        printf("%s\n",h);
        fflush(stdout);

        flag = 0; 
        }

        else if(!strcmp(option, second))
        {
        Rx_str[c] = '\0';

        char *T= strstr(Rx_str, "H");
        printf("%s", T);

        fflush(stdout);

        flag = 0;
        }
        }
        }
    }
    }
    }
}