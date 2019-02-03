#include "rovlog.h"

int main(void) {
    // Setting the path of the log (the actual file where the log exists)
    rl_setfile("./rovlog.txt");

    rl_setsource("Use the logger");

    // Setting the level of stuff to be logged
    // In this case, it's set to WARNING- feel free to change it for testing!
    rl_setlevel(WARN);

    // Everything is set up. Now we're going to log some things.
    rovlog(INFO, "Starting up!");
    rovlog(DEBUG, "Opening socket.");   // This (and the next line) is in DEBUG level, so it shouldn't get printed because we're in WARN level right now.
    rovlog(DEBUG, "Socket open.");
    rovlog(INFO, "Attempting to connect to the ROV...");
    rovlog(INFO, "Connected.");
    rovlog(WARN, "Not run with root permissions: may not be able to write to socket."); // We are in WARN level, so this should be printed.
    rovlog(ERROR, "Can't write to socket, trying again (1/3)...");
    rovlog(ERROR, "Can't write to socket, trying again (2/3)...");
    rovlog(ERROR, "Can't write to socket, trying again (3/3)...");
    rovlog(FATAL, "Could not write to socket to communicate with ROV. Exiting.");


    return 0; // All done!
}


