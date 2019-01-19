#ifndef ROVLOG
#define ROVLOG
// This stuff ^ is called an include guard (or 'header guard')
// https://en.wikipedia.org/wiki/Include_guard


// This defines log levels.
// I'm using an enum with a typedef- YOU DON'T NEED TO! If you want to do it a different way, change it!

// DEBUG is used for the most verbose stuff: only useful when debugging.
// INFO is for useful information- A process just started/ended, etc.
// WARN is for when things are weird and should be warned about.
// ERROR is for errors: Warnings that prevent things from working properly.
// FATAL is for errors that are so bad the program has to stop completely.
typedef enum LogLevel { DEBUG, INFO, WARN, ERROR, FATAL } loglevel;


// We need to tell the compiler that these functions exist. That way, we can call them from other files.
// These are called function prototypes: https://en.wikipedia.org/wiki/Function_prototype
void rl_setfile(char *path);
void rl_setlevel(loglevel level);
void rovlog(loglevel level, char* message);

#define ROVERR_LOSTCONNECTION 0x404
#define ROVERR_HEATSHUTDOWN   0xF112E
#define ROVERR_PLEASEDIE      0xD1E
int ROVERR = 0;

#endif
