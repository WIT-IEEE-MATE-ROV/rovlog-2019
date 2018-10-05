# Logging stuff
We need to log stuff to keep track of things. That's what this should do, but it doesn't exist yet. Read through the requirements here and create your own program that implements this. To keep track of things, just make your own branch titled after yourself and write your program there.


#### *Remember- All of this stuff is more of a suggestion. If you have a different way to do it, go for it!*

## Differet Priority levels
You don't always want to see every log message. For example, when running normally, you probably only want to see the basic information and big errors. For this reason, there are several different error levels:

### `DEBUG`
The debug level shows everything, plus additional information that is only every really useful when debugging. 

### `INFO`
Info has basic and useful information- things like "program start", stuff like that.

### `WARNING`
Warning is when things don't look right but we can get by.

### `ERROR`
Error is for when things _really_ aren't right to the point where we couldn't do what we were trying to do and had to recover.

### `FATAL`
Fatal is for errors that are so bad we can't recover. 

## Setting the error level
Set the error level with `rl_setlevel(ERRORLEVEL)`. This way, the user can set what level of information they want to see. Assume the user wants to see the level they set and anything more severe: for example, if the error level is set to `WARNING`, display `WARNING`, `ERROR`, and `FATAL` messages, if the level is set to `FATAL` display only `FATAL` messages, and if the level is set to `DEBUG` display all messages.

## Where stuff gets displayed
The logging info should be displayed on the standard output (that's what `printf()` does for you). In addition, the same information should be logged to a file. The location of that file should be set using the `rl_setfile(FILEPATH)` function, where `FILEPATH` is the path of the file.

## Format of the log
The log should have a timestamp followed by the actual message set by the user. It should also indicate if this is a `FATAL` message, `WARNING`, etc. Here's what a single log entry might look like:
```
[INFO][11:38] Connected to the ROV!
```

Each log entry should be on its own line. Here's what a log file might look like:
```
[INFO ][11:38] Starting up!
[DEBUG][11:38] Opening socket.
[DEBUG][11:38] Socket open.
[INFO ][11:39] Attempting to connect to the ROV...
[INFO ][11:39] Connected.
[ERROR][11:39] Can't write to socket, trying again (1/3)...
[ERROR][11:40] Can't write to socket, trying again (2/3)...
[ERROR][11:40] Can't write to socket, trying again (3/3)...
[FATAL][11:40] Could not write to socket to communicate with ROV. Exiting.
```

This should also give a better idea of why a log file is useful: when I need to debug this issue, I can look at the log and see what happened. In this case, I can tell there was an issue with writing to a socket that led to the program closing itself.

## Writing to the log
Writing to the log is done with the `rovlog` function. For example, to write a message with the `INFO` priority level:
```
rovlog(INFO, "This is a message!");
```

# Requirements Recap
So, here's what we need:
#### Functions
- rl_setlevel(ERRORLEVEL) to set the level of information being displayed.
- rl_setfile(FILEPATH) to set the path of the output file.
- rovlog(LEVEL, MESSAGE) to log MESSAGE at LEVEL.

#### Other things
- Error levels: debug, info, warning, error, fatal
- The filepath will need to be stored so the user doesn't need to keep entering it: perhaps as a global variable, or a better solution
- The error level the user wants to see will need to be stored somewhere for comparison.

