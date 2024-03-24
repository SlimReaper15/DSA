#include "reply.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Reply* createReply(char* username, char* content) {
    Reply* newReply = (Reply*)malloc(sizeof(Reply)); // Allocate memory for the new reply

    newReply->Username = (char*)malloc((strlen(username) + 1) * sizeof(char));
    newReply->Content = (char*)malloc((strlen(content) + 1) * sizeof(char));
    // Allocate the required amount of memory for username and content of the reply

    strcpy(newReply->Username, username);
    strcpy(newReply->Content, content);

    newReply->prev = NULL;
    newReply->next = NULL;

    return newReply;
}