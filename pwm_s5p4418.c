
/*  pwm wrapper functions using sysfs 
 *
 *
 *  pwm_s5p4418.c */


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>


int main(int argc,char **argv[])
{

char buf[256];

int pwm = 0;

int fd;

/* EXPORT PWM CHANNEL 0 */

 fd = open("/sys/class/pwm/pwmchip0/export",O_WRONLY);

 sprintf(buf,"%d",pwm);

 write(fd,buf,strlen(buf));

 printf("pwm0 is exported successfully...\r\n");

 close(fd);

/* Set period for pwm channel 0 */

sprintf(buf,"/sys/class/pwm/pwmchip0/pwm%d/period",pwm);

fd = open(buf,O_WRONLY);

write(fd,"1000000",7);

printf("Period set successfully...\r\n");

close(fd);

/* Set Duty cycle of pwm channel 0 */

sprintf(buf,"/sys/class/pwm/pwmchip0/pwm%d/duty_cycle",pwm);

fd = open(buf,O_WRONLY);

write(fd,"500000",6);

printf("Duty-Cycle set successfully....\r\n");

close(fd);

/* Enable pwm channel 0 by wriiting 0 */

sprintf(buf,"/sys/class/pwm/pwmchip0/pwm%d/enable",pwm);

fd = open(buf,O_WRONLY);

write(fd,"1",1);

printf("pwm0 is enabled start making sound .....\r\n");

close(fd);

while(1);
 
 
return 0;

}
