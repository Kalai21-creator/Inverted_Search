#include "header.h"
#include <stdio.h>

void Display_database(main_node_t *hash_table[26])
{
    // Print the header for the table
    printf("==================================================================================\n");
    printf("                         <<< Displaying Database >>>\n");
    printf("==================================================================================\n");
    printf("%-5s%-20s%-15s%-15s%-20s\n", "Index", "Word", "File Count", "Word Count", "File Name");
    printf("==================================================================================\n");

    // Iterate through each bucket in the hash table
    for (int i = 0; i < 26; i++)
    {
        if (hash_table[i] != NULL) // Only process non-empty buckets
        {
            main_node_t *main_node = hash_table[i];

            // Iterate through each main node (word in the bucket)
            while (main_node != NULL)
            {
                // We use a sub_node pointer to iterate through each file entry for the word
                sub_node_t *sub_node = main_node->sub_link;
                
                // A flag to track if the word has been displayed
                int word_displayed = 0;

                // Iterate through each file and word count for the current word
                while (sub_node != NULL)
                {
                    // If it's the first time we are displaying this word, print it
                    if (!word_displayed)
                    {
                        printf("%-5c%-20s%-15d", 'A' + i, main_node->word, main_node->f_count);
                        word_displayed = 1; // Set the flag to indicate the word is displayed
                    }

                    // Print the file name and the word count for that file
                    printf("%-15d%-20s\n", sub_node->w_count, sub_node->f_name);
                    sub_node = sub_node->link; // Move to the next file entry
                }

                main_node = main_node->link; // Move to the next word node in the bucket
            }
        }
    }

    // Print the footer of the table
    printf("====================================================================================\n");
}
