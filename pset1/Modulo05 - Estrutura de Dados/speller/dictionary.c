#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 65536;  // Aumentamos o número de buckets para melhorar a eficiência

// Hash table
node *table[N];

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Hash function (djb2)
    unsigned int hash = 5381;
    int c;
    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // Read words from dictionary and insert into hash table
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Allocate memory for a new node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            return false;
        }

        // Copy word to the new node
        strcpy(new_node->word, word);
        new_node->next = NULL;

        // Hash word to determine the bucket
        unsigned int index = hash(word);

        // Insert new node at the beginning of the linked list
        new_node->next = table[index];
        table[index] = new_node;
    }

    // Close dictionary file
    fclose(file);

    return true;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash word to determine the bucket
    unsigned int index = hash(word);

    // Traverse the linked list in the bucket
    for (node *cursor = table[index]; cursor != NULL; cursor = cursor->next)
    {
        // Compare word with the current node, case-insensitive
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int count = 0;

    // Traverse all buckets in the hash table
    for (int i = 0; i < N; i++)
    {
        // Traverse each node in the linked list
        for (node *cursor = table[i]; cursor != NULL; cursor = cursor->next)
        {
            count++;
        }
    }

    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Traverse all buckets in the hash table
    for (int i = 0; i < N; i++)
    {
        // Traverse each node in the linked list
        while (table[i] != NULL)
        {
            // Store the next node temporarily
            node *temp = table[i]->next;

            // Free memory of the current node
            free(table[i]);

            // Move to the next node
            table[i] = temp;
        }
    }

    return true;
}
