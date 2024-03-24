#include "comment.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Comment* createComment(char* username, char* content) {
    Comment* newComment = (Comment*)malloc(sizeof(Comment)); // Allocate memory for the new comment

    newComment->Username = (char*)malloc((strlen(username) + 1) * sizeof(char));
    newComment->Content = (char*)malloc((strlen(content) + 1) * sizeof(char));
    // Allocate the required amount of memory for username and content of the comment

    strcpy(newComment->Username, username);
    strcpy(newComment->Content, content);

    newComment->Replies = NULL;
    newComment->replyCount = 0;
    
    newComment->prev = NULL;
    newComment->next = NULL;

    return newComment;
}