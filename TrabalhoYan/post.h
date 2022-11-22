#ifndef POST_H
#define POST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct post tPost;

tPost* CriaPost(char* msg, int alcance);

void ImprimePost(tPost* post);

void LiberaPost(tPost* post);

#endif