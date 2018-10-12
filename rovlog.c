#include "rovlog.h"
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

// You're probably going to want to include other things to use printf() and stuff like that.
char PATH[100];
loglevel LEVEL = INFO;

void rl_setfile(char *path) {
    // Set the file to be written to.
    // How does this get stored in a way all functions here can see it?
    strcpy(PATH, path);
}

void rl_setlevel(loglevel level) {
	LEVEL = level;

    // Set the level to do logging at. 
    // Like before, how does this get stored in a way all functions can see it?
}

void rovlog(loglevel level, char* message) {
	//struct timeval tv;
	//gettimeofday(&tv,NULL);
	//printf("[%li:%li:%li]",tv.tv_hour,tv.tv_min,tv.tv_sec);
    // Log stuff!
    // You'll need to write to the file path and to standard out only if the level
    // you get here is at or more severe than what was set by the user in rl_setlevel().
    if(level >= LEVEL){
    	printf("%s\n",message);




    }
}
