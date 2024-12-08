#include "header.h"

int find_index(char *str);

Status search_Data_Base(main_node_t *hash_table[27], char *word)
{
    int index = find_index(word);

    if (hash_table[index] == NULL)
    {
        printf("\n====================================\n");
        printf("Search Result: Word Not Found\n");
        printf("====================================\n");
        printf("The word '%s' does not exist in the database.\n", word);
        printf("====================================\n");
        return DATA_NOT_FOUND;
    }

    main_node_t *temp = hash_table[index];
    while (temp != NULL)
    {
        if (strcmp(word, temp->word) == 0)
        {
            // Word found - structured display
            printf("\n====================================\n");
            printf("Search Result: Word Found\n");
            printf("====================================\n");
            
            // Display Word Details in Tabular Format
            printf("%-20s%-15s%-15s\n", "Word", "Index", "File Count");
            printf("====================================\n");
            printf("%-20s%-15d%-15d\n", temp->word, index, temp->f_count);
            printf("====================================\n");

            // Print File Details in Tabular Format
            printf("\n%-20s%-15s\n", "File Name", "Word Count");
            printf("====================================\n");
            sub_node_t *s_temp = temp->sub_link;
            while (s_temp != NULL)
            {
                printf("%-20s%-15d\n", s_temp->f_name, s_temp->w_count);
                s_temp = s_temp->link;
            }
            printf("====================================\n");
            return success;
        }
        temp = temp->link;
    }

    // Word not found after traversing the linked list
    printf("\n====================================\n");
    printf("Search Result: Word Not Found\n");
    printf("====================================\n");
    printf("The word '%s' does not exist in the database.\n", word);
    printf("====================================\n");
    return DATA_NOT_FOUND;
}
