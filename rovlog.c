#include "rovlog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

char PATH[100];
loglevel LEVEL = INFO;

void rl_setfile(char *path) {
    // Set the file to be written to.
    strcpy(PATH, path);
}

/**
 * Set the level to do logging at.
 * @param loglevel level: The level to be set to
 */
void rl_setlevel(loglevel level) {
	LEVEL = level;
}

char *level_to_string(loglevel level) {
    switch(level) {
        case DEBUG:
            return "DEBUG";
        case INFO:
            return "INFO "; // That space at the end keeps everything the same length
        case WARN:
            return "WARN ";
        case ERROR:
            return "ERROR";
        case FATAL:
            return "FATAL";
        default:
            return "UNK  ";
    }
}

/**
 * Log to the file and stdout.
 * @param loglevel level: The level this message should appear at
 * @param char* message:  The message to be logged.
 */
void rovlog(loglevel level, char* message) {
	//struct timeval tv;
	//gettimeofday(&tv,NULL);
	//printf("[%li:%li:%li]",tv.tv_hour,tv.tv_min,tv.tv_sec);
    // Log stuff, but only if the level is severe enough.
    if(level >= LEVEL){
        char timstamp[6] = "00:00";
        // Set the timestamp string here

        char levelstring[6] = "UNK  ";
        strcpy(levelstring, level_to_string(level));

        sprintf("[%s][%s] %s", levelstring, message);

    	// Print to stdout
        printf ("%s\n",message);

        // Print to a file
        FILE* logfile = fopen(PATH, "w");
        fprintf(logfile, "%s\n", message);
        fclose(logfile);
    }
	
	int safe_shutdown() {
	    switch(ROVERR) {
	        case ROVERR_LOSTCONNECTION:
	            rovlog(FATAL, "I've lost connection to the surface, and can't re-establish a connection");
	            rovlog(FATAL, "I'm going to try shutting everything down and bringing it back up again...");
                // TODO
	            rovlog(FATAL, "... Done.");
	            break;
	
	        case ROVERR_HEATSHUTDOWN:
	            rovlog(FATAL, "Too much heat! I'm shutting down to protect myself.");
                //TODO
	            rovlog(FATAL, "Aborted children. Stopping self now.");
                //TODO
	            break;
	
	        case ROVERR_PLEASEDIE:
	            rovlog(FATAL, "Someone asked very nicely for me to shut myself down. Bye!");
                //TODO
	            break;
	
	        default:
	            rovlog(FATAL, "Got an unrecognized shutdown request. Ignoring and resetting ROVERR. Fix that.");
	            ROVERR = 0;
	            break;
	    }
	    return ROVERR;
	}
}
