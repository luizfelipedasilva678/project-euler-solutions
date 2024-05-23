#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define LIMIT 10000

double triangle_numbers[LIMIT] = {0};

void generate_triangle_numbers() {
    size_t i;

    for(i = 0; i < LIMIT; i++) {
        triangle_numbers[i] = (double) (0.5) * (i + 1) * (i + 2);
    }
}

uint8_t is_triangle_word(double n) {
    size_t i;

    for(i = 0; i < LIMIT; i++) {
        if(triangle_numbers[i] == n) return 1;
    }

    return 0;
}

uint32_t get_letter_value(char c)
{
    switch (c)
    {
    case 'A':
        return 1;

    case 'B':
        return 2;

    case 'C':
        return 3;

    case 'D':
        return 4;

    case 'E':
        return 5;

    case 'F':
        return 6;

    case 'G':
        return 7;

    case 'H':
        return 8;

    case 'I':
        return 9;

    case 'J':
        return 10;

    case 'K':
        return 11;

    case 'L':
        return 12;

    case 'M':
        return 13;

    case 'N':
        return 14;

    case 'O':
        return 15;

    case 'P':
        return 16;

    case 'Q':
        return 17;

    case 'R':

        return 18;

    case 'S':
        return 19;

    case 'T':
        return 20;

    case 'U':
        return 21;

    case 'V':
        return 22;

    case 'W':
        return 23;

    case 'X':
        return 24;

    case 'Y':
        return 25;

    case 'Z':
        return 26;
    }

    return 0;
}

double get_word_value(char *word) {
    size_t i;
    double word_value;

    word_value = 0;
    for (i = 0; i < strlen(word); i++)
    {
        word_value += get_letter_value(word[i]);
    }

    return word_value;
}

uint32_t get_quantity_of_words(char *buff)
{
    size_t i;
    uint32_t sum = 1;

    for (i = 0; i < strlen(buff); i++)
    {
        if (buff[i] == ',')
        {
            sum += 1;
        }
    }

    return sum;
}

char *remove_all_chars(char *str, char c)
{
    size_t len = strlen(str);
    char *new_str = (char *)malloc(len + 1 * sizeof(char)), *p1 = str, *p2 = new_str;

    while (*p1)
    {
        if (*p1 != c)
        {
            *p2 = *p1;
            p2++;
        }

        p1++;
    }

    return new_str;
}

char **make_words_arr(char *str, int len)
{

    size_t i;
    char *token, *delimter = ",";
    char **words = (char **)malloc(len * sizeof(char **));

    token = strtok(str, delimter);

    for (i = 0; i < len && token != NULL; i++)
    {
        words[i] = (char *)malloc(sizeof(char *) * (strlen(token) + 1));
        strcpy(words[i], token);
        token = strtok(NULL, delimter);
    }

    return words;
}

int main(void)
{
    size_t i;
    FILE *file = fopen("0042_words.txt", "r");
    char *file_content, *clean_str, **words;
    uint32_t length, quantity_of_words, triangle_words;

    if (file == NULL)
    {
        return 1;
    }

    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);
    file_content = (char *)malloc(length * sizeof(char));
    fread(file_content, sizeof(char), length, file);

    clean_str = remove_all_chars(file_content, '"');

    free(file_content);

    quantity_of_words = get_quantity_of_words(clean_str);
    words = make_words_arr(clean_str, quantity_of_words);
    generate_triangle_numbers(triangle_numbers);


    triangle_words = 0;
    for(i = 0; i < quantity_of_words; i++) {
        if(is_triangle_word(get_word_value(words[i]))) {
            triangle_words++;
        }
    }

    printf("%"PRIu32"", triangle_words);

    for (i = 0; i < quantity_of_words; i++)
    {
        free(words[i]);
    }
    free(words);
    free(clean_str);
    fclose(file);
    return 0;
}
