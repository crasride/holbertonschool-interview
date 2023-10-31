#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#define SLIDE_LEFT  0
#define SLIDE_RIGHT 1

#include <stddef.h>
#include <stdlib.h>

int slide_line(int *line, size_t size, int direction);

#endif /* SLIDE_LINE_H */
