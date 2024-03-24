#include "platform.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern Platform* platform;

int main() {

    while(true) {
        printf("Enter command: ");

        char *command = (char*)malloc(100 * sizeof(char));
        scanf("%s", command);

        if (strcmp(command, "create_platform") == 0) {
            platform = createPlatform();
            printf("Platform successfully created\n");
        }

        else if (strcmp(command, "add_post") == 0) {
            printf("Enter the username: ");
            char *username = (char*)malloc(100 * sizeof(char));
            scanf("%s", username);

            getchar();

            printf("Enter the caption: ");
            char *caption = (char*)malloc(1000 * sizeof(char));
            fgets(caption, 1000, stdin);
            caption[strlen(caption) - 1] = '\0';
            
            bool add = addPost(username, caption);

            if (add == true)
                printf("Post added successfully\n");
            else
                printf("Error: Post could not be added\n");
        }

        else if (strcmp(command, "delete_post") == 0) {
            printf("Enter the post number to be deleted: ");
            int n;
            scanf("%d", &n);
            
            bool delete = deletePost(n);

            if (delete == true)
                printf("Post deleted successfully\n");
            else
                printf("Error: Post could not be deleted\n");
        }

        else if (strcmp(command, "view_post") == 0) {
            printf("Enter the post number to be viewed: ");
            int n;
            scanf("%d", &n);
            Post* post = viewPost(n);

            if (post == NULL)
                printf("Invalid post\n");
            else
                printPost(post);
        }

        else if (strcmp(command, "current_post") == 0) {
            Post* post = currPost();

            if (post == NULL)
                printf("Invalid post\n");
            else
                printPost(post);
        }

        else if (strcmp(command, "next_post") == 0) {
            Post* post = nextPost();

            if (post == NULL)
                printf("Invalid post\n");
            else
                printPost(post);
        }

        else if (strcmp(command, "previous_post") == 0) {
            Post* post = previousPost();

            if (post == NULL)
                printf("Invalid post\n");
            else
                printPost(post);
        }

        else if (strcmp(command, "add_comment") == 0) {
            printf("Enter the username: ");
            char *username = (char*)malloc(100 * sizeof(char));
            scanf("%s", username);

            getchar(); // Consume the newline character

            printf("Enter the content: ");
            char *content = (char*)malloc(1000 * sizeof(char));
            fgets(content, 1000, stdin);
            content[strlen(content) - 1] = '\0';

            bool add = addComment(username, content);

            if (add == true)
                printf("Comment added successfully\n");
            else
                printf("Error: Comment could not be added\n");
        }

        else if (strcmp(command, "delete_comment") == 0) {
            printf("Enter the comment number to be deleted: ");
            int n;
            scanf("%d", &n);

            bool delete = deleteComment(n);

            if (delete == true)
                printf("Comment deleted successfully\n");
            else
                printf("Error: Comment could not be deleted\n");
        }

        else if (strcmp(command, "view_comments") == 0) {
            Comment* comment = viewComments();

            if (comment == NULL)
                printf("No comment to view\n");
            else
                printComments(comment);
        }

        else if (strcmp(command, "add_reply") == 0) {
            printf("Enter the username: ");
            char *username = (char*)malloc(100 * sizeof(char));
            scanf("%s", username);

            getchar();

            printf("Enter the content: ");
            char *content = (char*)malloc(1000 * sizeof(char));
            fgets(content, 1000, stdin);
            content[strlen(content) - 1] = '\0';

            printf("Enter the comment number to which reply should be added: ");
            int n;
            scanf("%d", &n);

            bool add = addReply(username, content, n);

            if (add == true)
                printf("Reply added successfully\n");
            else
                printf("Error: Reply could not be added\n");
        }

        else if (strcmp(command, "delete_reply") == 0) {
            printf("Enter the comment number for which reply is to be deleted: ");
            int n;
            scanf("%d", &n);
            printf("Enter the reply number to be deleted: ");
            int m;
            scanf("%d", &m);
            
            bool delete = deleteReply(n, m);

            if (delete == true)
                printf("Reply deleted successfully\n");
            else
                printf("Error: Reply could not be deleted\n");
        }

        else if (strcmp(command, "exit") == 0) {
            printf("Exiting program...\n");
            return 0;
        }

        else {
            printf("Error: Invalid operation\n");
            continue;
        }
    }

    return 0;
}