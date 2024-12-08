#include "header.h"

int main(int argc, char *argv[])
{
    // Initialize hash table and file node list
    main_node_t *hash_table[27] = {NULL};
    file_node_t *head = NULL;

    // Validate input arguments
    if (argc > 1)
    {
        if (validation(argc, argv, &head) == failure)
        {
            printf("Error: Validation failed\n");
            return failure;
        }
    }
    else
    {
        printf("Error: Please pass the valid number of arguments\n");
        return failure;
    }

    // Print the file node list
    print_list(head);

    // Main menu loop
    while (1)
    {
        int choice;

        // Display main menu
        printf("\nMAIN MENU\n");
        printf("---------\n");
        printf("1. Create Data Base\n");
        printf("2. Display Data Base\n");
        printf("3. Search Data Base\n");
        printf("4. Save Data Base\n");
        printf("5. Update Data Base\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle user choice
        switch (choice)
        {
        case 1:
            if (create_Data_Base(&head, hash_table) == success)
            {
                printf("   ******************************\n");
                printf("   Data Base created successfully\n");
                printf("   ******************************\n");
            }
            else
            {
                printf("Error: Failed to create Data Base\n");
            }
            break;

        case 2:
            Display_database(hash_table);
            break;

        case 3:
        {
            char str[100];
            printf("Please enter the word you want to search for: ");
            scanf("%s", str);

            int search_result = search_Data_Base(hash_table, str);
            if (search_result == success)
            {
                printf("\n***** Operation Successful *****\n");
                printf("  Search successful: Word found in the Data Base.\n");
            }
            else if (search_result == DATA_NOT_FOUND)
            {
                printf("\n***** Operation Unsuccessful *****\n");
                printf("  Search unsuccessful: Word not found.\n");
            }
            else
            {
                printf("\n***** Operation Failed *****\n");
                printf("  Error: Search operation failed.\n");
            }
            break;
        }

        case 4:
            if (save_Data_Base(hash_table) == success)
            {
                printf("   ****************************\n");
                printf("   Data Base saved successfully\n");
                 printf("   ****************************\n");
            }
            else
            {
                printf("Error: Failed to save Data Base\n");
            }
            break;

        case 5:
             if ( Update_Data_base(hash_table,&head) == success)
            {
                printf("   ****************************\n");
                printf("   Data Base update successfully\n");
                 printf("   ****************************\n");
            }
            else
            {
                printf("Error: Failed to save Data Base\n");
            }
            break;
        case 6:
            printf("\nExiting program.\n");
            return 0;

        default:
            printf("Error: Invalid choice, please try again\n");
            break;
        }
    }

    return 0;
}