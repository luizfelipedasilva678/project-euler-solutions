#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

int compare(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

int get_letter_value(char c)
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

int get_quantity_of_names(char *buff)
{
    size_t i;
    int sum = 1;

    for (i = 0; i < strlen(buff); i++)
    {
        if (buff[i] == ',')
        {
            sum += 1;
        }
    }

    return sum;
}

int get_name_score(char *name, int pos)
{
    int i, letters_num = 0;

    for (i = 0; i < strlen(name); i++)
    {
        letters_num += get_letter_value(name[i]);
    }

    return letters_num * pos;
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

char **make_names_arr(char *str, int len)
{

    size_t i;
    char *token, *delimter = ",";
    char **names = (char **)malloc(len * sizeof(char **));

    token = strtok(str, delimter);

    for (i = 0; i < len && token != NULL; i++)
    {
        names[i] = (char *)malloc(sizeof(char *) * (strlen(token) + 1));
        strcpy(names[i], token);
        token = strtok(NULL, delimter);
    }

    return names;
}

int main(void)
{
    FILE *file = fopen("0022_names.txt", "r");
    uint64_t total_score = 0;
    char *file_content, *clean_str, **names;
    int length, quantity_of_names, i;

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

    quantity_of_names = get_quantity_of_names(clean_str);
    names = make_names_arr(clean_str, quantity_of_names);
    qsort(names, quantity_of_names, sizeof(names[0]), compare);

    for (i = 0; i < quantity_of_names; i++)
    {
        total_score += get_name_score(names[i], i + 1);
    }

    printf("Answer: %" PRIu64 "\n", total_score);

    for (i = 0; i < quantity_of_names; i++)
    {
        free(names[i]);
    }
    free(names);
    free(clean_str);
    fclose(file);
    return 0;
}