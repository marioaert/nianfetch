#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#define BLUE "\033[1;34m"
#define PURPLE "\033[1;35m"
#define RESET "\033[0m"

extern const char* COLOR;
extern const char* PKG;
void pretty(){
FILE *osname = fopen("/etc/os-release", "r");
char *buffer = malloc(256 * sizeof(char));

 fgets(buffer, 256, osname);
   sscanf(buffer, "NAME=\"%[^\"]\"", buffer) == 1;
  printf("%sOS Name:%s %s\n", COLOR, RESET, buffer);

free(buffer);
fclose(osname);
}

void kernelinfo(struct utsname sysinfo){

char *kernel = malloc(256 * sizeof(char));
snprintf(kernel, 256, "%s %s", sysinfo.sysname, sysinfo.release);
printf("%sKernel:%s %s\n", COLOR, RESET, kernel);
free(kernel);
}

void deskenv(){
const char *desktop_env = getenv("XDG_CURRENT_DESKTOP");
printf("%sDesktop Environment:%s %s\n", COLOR, RESET, desktop_env);
}
void cpu(){

FILE *cpumodel = fopen("/proc/cpuinfo", "r");
char *buffer = malloc(256 * sizeof(char));

while (fgets(buffer, 256, cpumodel)){
 if (strstr(buffer, "model name")){
  sscanf(buffer, "model name   : %[^\n]", buffer);
 break;
 }
}
printf("%sProcessor Model:%s %s\n", COLOR, RESET, buffer); 

free(buffer);
fclose(cpumodel);
}

void cpuarch(struct utsname sysinfo){
printf("%sProcessor Architecture:%s %s\n", COLOR, RESET, sysinfo.machine);
}

void gpu(){
printf("%sGraphics Card:%s potato\n", COLOR, RESET);
}

void uptime(){
struct sysinfo info;
sysinfo(&info);
long uptime = info.uptime;
int days = uptime / 86400;
int hours = (uptime % 86400) / 3600;
int minutes = (uptime % 3600) / 60;
int seconds = uptime % 60;
if (days > 0){
printf("%sUptime:%s %d Days, %d Hours, %d Minutes, %d Seconds\n", COLOR, RESET, days, hours, minutes, seconds);
} else {
printf("%sUptime:%s %d Hours, %d Minutes, %d Seconds\n", COLOR, RESET, hours, minutes, seconds);
 }
}

void pkg(){
printf("%sPackage Manager:%s %s\n", COLOR , RESET, PKG);
}

void getshell(){
const char *shell = getenv("SHELL");
printf("%sDefault Shell:%s %s\n", COLOR, RESET, shell);
}

void getuser(){
const char *user = getenv("USER");
printf("%sCurrent User:%s %s\n", COLOR, RESET, user);
}

