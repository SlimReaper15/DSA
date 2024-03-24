#include "post.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Post* createPost(char* username, char* caption) {
    Post* newPost = (Post*)malloc(sizeof(Post)); // Allocate memory for the new post

    newPost->Username = (char*)malloc((strlen(username) + 1) * sizeof(char));
    newPost->Caption = (char*)malloc((strlen(caption) + 1) * sizeof(char));
    // Allocate the required amount of memory for username and caption of the post

    strcpy(newPost->Username, username);
    strcpy(newPost->Caption, caption);

    newPost->Comments = NULL;
    newPost->commentCount = 0;
    
    newPost->prev = NULL;
    newPost->next = NULL;
    
    return newPost;
}