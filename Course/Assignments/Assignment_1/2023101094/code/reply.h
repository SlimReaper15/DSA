#ifndef REPLY_H
#define REPLY_H

typedef struct Reply {
    char* Username;
    char* Content;
    struct Reply* prev;
    struct Reply* next;
} Reply;

Reply* createReply(char* username, char* content);

#endif