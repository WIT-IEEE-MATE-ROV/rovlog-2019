rovlog:
	gcc -c rovlog.c -Wall -Wextra

uselogger:
	gcc rovlog.o use_the_logger.c -o uses_the_logger -g -Wall -Wextra
