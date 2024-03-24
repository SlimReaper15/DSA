#ifndef POST_H
#define POST_H

#include "comment.h"

typedef struct Post {
    char* Username;
    char* Caption;
    Comment* Comments; // Head pointer to the linked list of comments
    int commentCount;
    struct Post* prev;
    struct Post* next;
} Post;

Post* createPost(char* username, char* caption);

#endif