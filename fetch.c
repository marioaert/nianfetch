#include "fetch.h"
#ifndef FETCH_H
#define FETCH_H
const char* COLOR = PURPLE;
const char* PKG = "unknown";
#endif
int main(){
struct utsname sysinfo;
uname(&sysinfo);
const char *logo1[] = {
"\\/",
"//",
"\\\\",
"  ",
"  ",
"  "
};
const char *arch[] = {
"         /\\           ",
"        /  \\          ",
"       /    \\         ",
"      /      \\        ",
"     /        \\       ",
"    /          \\      ",
"   /     __     \\     ",
"  /     /  \\     \\    ",
" /     |    |     \\   ",
"/_____/      \\_____\\  "
};
const char *defaultlogo[] = {
 "____________   ",
 "|          |   ",
 "|          |   ",
 "|          |   ",
 "|          |   ",
 "|    __    |   ",
 "|   |  |   |   ",
 "|   |  |   |   ",
 "|___|  |___|   ",
 "               "
};
const char **logo = defaultlogo;
FILE *osname = fopen("/etc/os-release", "r");
char *buffer = malloc(256 * sizeof(char));
while (fgets(buffer, 25, osname)){
if (strstr(buffer, "Arch Linux")){
	logo = arch;
	COLOR = BLUE; 
	PKG = "pacman";break;
 }
}
free(buffer);
fclose(osname);
for (int i = 0; i < 10; i++){
 printf("%s%s%s", COLOR, logo[i], RESET);
 switch(i){
 case 0: pretty();break;
 case 1: kernelinfo(sysinfo);break;
 case 2: deskenv();break;
 case 3: cpu();break;
 case 4: cpuarch(sysinfo);break;
 case 5: gpu();break;
 case 6: uptime();break;
 case 7: pkg();break;
 case 8: getshell(); break;
 case 9: getuser(); break;
  }
 }
}
