#include "header.h"

FILE *check_file(char *file_name);
int is_file_empty(FILE *fptr);
void insert_node(file_node_t **head, char *filename);
Status check_extenstion(char *file_name);

Status validation(int argc, char *argv[], file_node_t **head)
{
    // Print the table header
    printf("====================================\n");
    printf("      << Valid File List >>\n");
    printf("====================================\n");
    printf("%-20s%-15s\n", "File Name", "Status");
    printf("====================================\n");

    for (int i = 1; i < argc; i++)
    {
        if (check_extenstion(argv[i]) == failure)
        {
            continue;
        }

        FILE *fptr = check_file(argv[i]);
        if (fptr == NULL)
        {
            continue;
        }

        if (is_file_empty(fptr) == 0)
        {
            printf("%-20s%-15s\n", argv[i], "Empty");
        }
        else
        {
            printf("%-20s%-15s\n", argv[i], "Valid");
            insert_node(head, argv[i]);
        }
        fclose(fptr);
    }

    printf("====================================\n");
    return success;
}

FILE *check_file(char *file_name)
{
    FILE *fptr = fopen(file_name, "r");
    if (fptr == NULL)
    {
        printf("Error : FILE '%s' does not exist\n", file_name);
        return NULL;
    }
    return fptr;
}

int is_file_empty(FILE *fptr)
{
    fseek(fptr, 0, SEEK_END);
    int size = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);
    return size;
}

void insert_node(file_node_t **head, char *filename)
{
    file_node_t *new = malloc(sizeof(file_node_t));
    if (new == NULL)
    {
        printf("ERROR : memory allocation failed\n");
        return;
    }
    strcpy(new->f_name, filename);
    new->link = NULL;

    if (*head == NULL)
    {
        *head = new;
    }
    else
    {
        file_node_t *temp = *head;
        file_node_t *prev = NULL;
        while (temp != NULL)
        {
            if (strcmp(temp->f_name, filename) == 0)
            {
                printf("ERROR : duplicate file name exists\n");
                free(new);
                return;
            }
            prev = temp;
            temp = temp->link;
        }
        prev->link = new;
    }
}

void print_list(file_node_t *head)
{
    // Print the list of valid files in tabular format
    if (head == NULL)
    {
        printf("INFO: No valid files found.\n");
    }
    else
    {
        printf("====================================\n");
        printf("       << Valid Files List >>\n");
        printf("====================================\n");
        printf("%-20s\n", "File Name");
        printf("====================================\n");
        while (head != NULL)
        {
            printf("%-20s", head->f_name);
            head = head->link;
        }
        printf("\n====================================\n");
    }
}

Status check_extenstion(char *file_name)
{
    char *str = strstr(file_name, ".");
    if (str == NULL || strcmp(str, ".txt") != 0)
    {
        printf("Error : File '%s' should have a .txt extension\n", file_name);
        return failure;
    }
    return success;
}
