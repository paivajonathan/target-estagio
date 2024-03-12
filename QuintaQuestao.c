#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_CAPACITY 3

typedef struct string_t
{
    int length;
    int capacity;
    char *characters;
} string_t;

void
append_string(string_t *string, char value)
{
    if (!string->capacity)
    {
        string->characters = calloc(sizeof(char), DEFAULT_CAPACITY);
        if (string->characters == NULL) exit(1);
        string->length = 0;
        string->capacity = DEFAULT_CAPACITY;
    }

    if (string->length + 1 == string->capacity)
    {
        int new_capacity = string->capacity + DEFAULT_CAPACITY;
        string->characters = realloc(string->characters, new_capacity);
        if (string->characters == NULL) exit(1);
        string->capacity = new_capacity;
    }

    string->characters[string->length++] = value;
}

void
destroy_string(string_t *string)
{
    if (string->characters == NULL) return;
    free(string->characters);
    string->characters = NULL;
    string->capacity = 0;
    string->length = 0;
}

void
print_string(string_t *string)
{
    for (int i = 0; i < string->length; i++)
    {
        printf("%c", string->characters[i]);
    }
    printf("\n");
}

void
clear_buffer(void)
{
    while (getchar() != '\n');
}

int
main(void)
{
    string_t text;
    string_t inverted_text;
    char c;

    puts("Type a text:");
    while ((c = getchar()) != '\n')
        append_string(&text, c);

    for (int i = text.length - 1; i >= 0; i--)
        append_string(&inverted_text, text.characters[i]);
    
    puts("\nNormal text:");
    print_string(&text);

    puts("\nInverted text:");
    print_string(&inverted_text);
    
    destroy_string(&text);
    destroy_string(&inverted_text);

    return 0;
}