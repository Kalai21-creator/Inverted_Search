#include "header.h"

Status save_Data_Base(main_node_t *hash_table[27])
{
    char file[100];
    printf("Enter file name (with .txt extension): ");
    scanf("%s", file);

    char *Dot = strstr(file, ".");
    if (strcmp(Dot, ".txt") != 0)
    {
        printf("Error : File extension should contain .txt\n");
        return failure;
    }
    FILE *fptr = fopen(file, "w");
    for (int i = 0; i < 27; i++)
    {
        if (hash_table[i] != NULL)
        {
            main_node_t *main_node = hash_table[i];
            while (main_node != NULL)
            {
                fprintf(fptr, "# [%d],%s,%d", i, main_node->word, main_node->f_count);
                sub_node_t *sub_node = main_node->sub_link;
                while (sub_node != NULL)
                {
                    fprintf(fptr, ",%s,%d", sub_node->f_name, sub_node->w_count);
                    sub_node = sub_node->link;
                }
                fprintf(fptr, " #\n");
                main_node = main_node->link;
            }
        }
    }

    fclose(fptr);
}