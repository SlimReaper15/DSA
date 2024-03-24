#ifndef COMMENT_H
#define COMMENT_H

#include "reply.h"

typedef struct Comment {
    char* Username;
    char* Content;
    Reply* Replies; // Head pointer to the linked list of replies
    int replyCount;
    struct Comment* prev;
    struct Comment* next;
} Comment;

Comment* createComment(char* username, char* content);

#endif