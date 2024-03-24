#ifndef PLATFORM_H
#define PLATFORM_H

#include "post.h"

#include <stdbool.h>

typedef struct Platform {
    Post* Posts;
    int postCount;
    Post* lastViewedPost;
} Platform;

Platform* createPlatform();
bool addPost(char* username, char* caption);
bool deletePost(int n);
Post* viewPost(int n);
Post* currPost();
Post* nextPost();
Post* previousPost();
bool addComment(char* username, char* content);
bool deleteComment(int n);
Comment* viewComments();
bool addReply(char* username, char* content, int n);
bool deleteReply(int n, int m);
void printPost(Post* post);
void printComments(Comment* comment);

#endif