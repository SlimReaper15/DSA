#include "platform.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Platform* platform;

Platform* createPlatform() {
    platform = (Platform*)malloc(sizeof(Platform));

    platform->Posts = NULL;
    platform->postCount = 0;

    platform->lastViewedPost = NULL;

    return platform;
}

bool addPost(char* username, char* caption) {
    if (platform == NULL)
        return false;
    
    Post* newPost = createPost(username, caption);

    if (platform->Posts == NULL)
        platform->Posts = newPost;

    else {
        newPost->next = platform->Posts; // Make newPost's next point to the current head
        platform->Posts->prev = newPost; // The reverse link
        platform->Posts = newPost; // Change the head so that newPost is inserted at the beginning
    }

    // Update lastViewedPost if no post has been viewed yet
    if (platform->lastViewedPost == NULL)
        platform->lastViewedPost = newPost;

    platform->postCount++; // Increase post count if post is added

    return true;
}

bool deletePost(int n) {
    if (platform == NULL || platform->postCount == 0 || n > platform->postCount)
        return false;

    Post* tempPost = platform->Posts;

    if (n == 1) // If head post is to be deleted
        platform->Posts = platform->Posts->next;

    else {
        for (int i = 0; i < n - 1; i++)
            tempPost = tempPost->next;
        
        tempPost->prev->next = tempPost->next; // Adjust forward link
        if (tempPost->next != NULL)
            tempPost->next->prev = tempPost->prev; // Adjust reverse link
    }
    
    // Update lastViewedPost if necessary
    if (platform->lastViewedPost == tempPost)
        platform->lastViewedPost = platform->Posts;

    // Free all replies and comments

    Comment* tempComment = tempPost->Comments;

    while (tempComment != NULL) {
        Reply* tempReply = tempComment->Replies;
        while (tempReply != NULL) {
            Reply* tempR = tempReply;
            tempReply = tempReply->next;
            free(tempR->Username);
            free(tempR->Content); // Free everything malloced
            free(tempR);
        }
        Comment* tempC = tempComment;
        tempComment = tempComment->next;
        free(tempC->Username);
        free(tempC->Content);
        free(tempC);
    }

    free(tempPost->Username);
    free(tempPost->Caption);
    free(tempPost); // Free the post

    platform->postCount--;

    return true;
}

Post* viewPost(int n) {
    if (platform == NULL || platform->postCount == 0 || n > platform->postCount)
        return NULL;

    Post* tempPost = platform->Posts;

    for (int i = 0; i < n - 1; i++)
        tempPost = tempPost->next;

    platform->lastViewedPost = tempPost; // Update lastViewedPost

    return tempPost;
}

Post* currPost() {
    if (platform == NULL || platform->postCount == 0)
        return NULL;

    return platform->lastViewedPost;
}

Post* nextPost() {
    if (platform == NULL || platform->postCount == 0)
        return NULL;

    if (platform->lastViewedPost->next == NULL)
        return platform->lastViewedPost;
    
    platform->lastViewedPost = platform->lastViewedPost->next;

    return platform->lastViewedPost;
}

Post* previousPost() {
    if (platform == NULL || platform->postCount == 0)
        return NULL;

    if (platform->lastViewedPost->prev == NULL)
        return platform->lastViewedPost;

    platform->lastViewedPost = platform->lastViewedPost->prev;

    return platform->lastViewedPost;
}

bool addComment(char* username, char* content) {
    if (platform == NULL || platform->postCount == 0)
        return false;

    Comment* newComment = createComment(username, content);
    newComment->Username = username;
    newComment->Content = content;

    newComment->next = platform->lastViewedPost->Comments;
    if (platform->lastViewedPost->Comments != NULL)
        platform->lastViewedPost->Comments->prev = newComment;
    platform->lastViewedPost->Comments = newComment;

    platform->lastViewedPost->commentCount++;

    return true;
}

bool deleteComment(int n) {
    if (platform == NULL || platform->postCount == 0 || platform->lastViewedPost->commentCount == 0 || n > platform->lastViewedPost->commentCount)
        return false;

    Comment* tempComment = platform->lastViewedPost->Comments;

    if (n == 1)
        platform->lastViewedPost->Comments = tempComment->next;
    
    else {
        for (int i = 0 ; i < n - 1; i++)
            tempComment = tempComment->next;

        tempComment->prev->next = tempComment->next;
        if (tempComment->next != NULL)
            tempComment->next->prev = tempComment->prev;
    }

    Reply* tempReply = tempComment->Replies;
    while (tempReply != NULL) {
        Reply* tempR = tempReply;
        tempReply = tempReply->next;
        free(tempR);
    } // Free all replies of the comment to be deleted

    free(tempComment);

    platform->lastViewedPost->commentCount--;

    return true;
}

Comment* viewComments() {
    if (platform == NULL || platform->postCount == 0 || platform->lastViewedPost->commentCount == 0)
        return NULL;

    Comment* tempComment = platform->lastViewedPost->Comments;

    while (tempComment->next != NULL)
        tempComment = tempComment->next;

    return tempComment; // Order of comments and replies implemented in printComments(Comment* comment)
}

bool addReply(char* username, char* content, int n) {
    if (platform == NULL || platform->postCount == 0 || platform->lastViewedPost->commentCount == 0 || n > platform->lastViewedPost->commentCount)
        return false;

    Comment* tempComment = platform->lastViewedPost->Comments;

    for (int i = 0 ; i < n - 1; i++)
        tempComment = tempComment->next;

    Reply* newReply = createReply(username, content);

    newReply->next = tempComment->Replies;
    if (tempComment->Replies != NULL)
        tempComment->Replies->prev = newReply;

    tempComment->Replies = newReply;

    tempComment->replyCount++;

    return true;
}

bool deleteReply(int n, int m) {
    if (platform == NULL || platform->postCount == 0 || platform->lastViewedPost->commentCount == 0 || n > platform->lastViewedPost->commentCount)
        return false;

    Comment* tempComment = platform->lastViewedPost->Comments;

    for (int i = 0 ; i < n - 1; i++)
        tempComment = tempComment->next;

    if (tempComment->replyCount == 0 || m > tempComment->replyCount)
        return false;

    Reply* tempReply = tempComment->Replies;

    if (m == 1) {
        tempComment->Replies = tempComment->Replies->next;
        tempComment->Replies->prev = NULL;
    }

    else {
        for (int i = 0; i < m - 1; i++)
            tempReply = tempReply->next;

        tempReply->prev->next = tempReply->next;
        if (tempReply->next != NULL)
            tempReply->next->prev = tempReply->prev;
    }

    free(tempReply);

    tempComment->replyCount--;

    return true;
}

void printPost(Post* post) {
    if (post == NULL)
        return;
    printf("%s: %s\n", post->Username, post->Caption);
    Comment* temp = post->Comments;
    while (temp != NULL) {
        printf("\t%s: %s\n", temp->Username, temp->Content);
        Reply* tempR = temp->Replies;
        while (tempR != NULL) {
            printf("\t\t%s: %s\n", tempR->Username, tempR->Content);
            tempR = tempR->next;
        }
        temp = temp->next;
    }
    return;
}

void printComments(Comment* comment) {
    Comment* tempComment = comment;
    while (tempComment != NULL) {
        printf("%s: %s\n", tempComment->Username, tempComment->Content);

        Reply* tempReply = tempComment->Replies;
        if (tempReply != NULL) {
            while (tempReply->next != NULL)
                tempReply = tempReply->next;
        }
        
        while (tempReply != NULL) {
            printf("\t%s: %s\n", tempReply->Username, tempReply->Content);
            tempReply = tempReply->prev;
        }

        tempComment = tempComment->prev;
    }
}