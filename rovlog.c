#include "rovlog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <stdbool.h>

char PATH[100];
char SOURCE[100];
bool USE_FILE = false;
loglevel LEVEL = INFO;

void rl_setfile(char *path) {
    // Set the file to be written to.
    strcpy(PATH, path);
    USE_FILE = true;
}

/**
 * Set the level to do logging at.
 * @param loglevel level: The level to be set to
 */
void rl_setlevel(loglevel level) {
	LEVEL = level;
}

void rl_setsource(char *source) {
    strcpy(SOURCE, source);
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
    // Log stuff, but only if the level is severe enough.
    if(level >= LEVEL){
        char timestamp[6] = "00:00";
        // Set the timestamp string here

        char levelstring[6];
        strcpy(levelstring, level_to_string(level));

        char messageout[strlen(message) + strlen(SOURCE) + 12];
        sprintf(messageout, "[%s][%s] %s (%s)", timestamp, levelstring, message, SOURCE);

    	// Print to stdout
        printf ("%s\n", messageout);

        if(USE_FILE) {
            // Print to a file
            FILE* logfile = fopen(PATH, "w");
            fprintf(logfile, "%s\n", messageout);
            fclose(logfile);
        }
    }
}
