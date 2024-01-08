#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/*
    Ritorna il path del dict specificato come argomento se presente altrimenti quello standard
*/
char *set_dict(char **argv);

/*
    prende in input una stringa rappresentante un intero es. "31" e
    ritorna una stringa rappresentante l'intero scritto in lettere es. "trentuno"
    in base alla conversione indicata dal dizionario in ingresso.
    se negativo da errore.
*/
char *num_to_alpha(char *num, char *path_dict);

/**
 * @brief ritorna il valore scritto in lettere in base al numeo passato come argomento
 * 
 * @param num 
 * @return char* 
 */
char *get_from_dict(char *num);

/**
 * @brief Ritorna il valore associato alla chiave num nel dizionario dict
 * 
 * @param dict 
 * @param num 
 * @return char* 
 */
*/
char *get_dict_value(char *dict, char *num);

/**
 * @brief Ritorna il puntatore alla posizione di str dove inizia la stringa to_find
 * 
 * @param str 
 * @param to_find 
 * @return char* 
 */
char *ft_strstr(char *str, char *to_find);

/**
 * @brief ritorna il numero scritto in cifre ma in un array di char del num elevato alla potenza
 * 
 * @param num 
 * @param power 
 * @return char* 
 */
char *run_power(int power);

/**
 * @brief stampa stringa
 * 
 */
void ft_putstr(char *array);

/**
 * @brief ritorna la lunghezza dell array
 * 
 * @param array 
 * @return int 
 */
int ft_strlen(char *array);

/**
 * @brief restiruisce la lunghezza della matrice
 * 
 * @return int 
 */
int ft_matrixlen(**matrix);

/**
 * @brief ritorna la stringa del numero scritto in lettere (in centinaia)
 * 
 * @param num3 
 * @return char* 
 */
char *convert100(char *num3);

/**
 * @brief concatena la 2 stringa alla prima riallocandole la memoria
 * 
 * @param array1 
 * @param array2 
 */
void *ft_strcat(char *array1, char *array2);

/**
 * @brief ritorna una stringa composta da il numero presente nella posizione dell'array + la migliaia che rappesenta
 * 
 * @param matrice 
 * @return char* 
 */
char *ultimate_convert(char **matrice);

/**
 * @brief ritorna il duplicato di src
 * 
 * @param src 
 */
char *ft_strdup(char *src);

int main(int argc, char **argv)
{
    char *path_dict;
    char *alpha_num;

    path_dict = set_dict(argv);
    alpha_num = num_to_alpha(argv[1], path_dict);
    ft_putstr(alpha_num);
    return (0);
}

char *num_to_alpha(char *num, char *path_dict)
{
    char **matrix;
    int size;
    int start;
    int i;

    if (*num[0] == '-')
    {
        write(1, "Error\n", 6);
        return ('\0');
    }
    /*
    size = ft_strlen(num) / 3;
    if (ft_strlen(num) % 3 != 0)
    {
        size++;
    }
    matrix = (char **)malloc((size + 1) * sizeof(char *));
    start = 0;
    i = 0;
    while (i < start)
    {
        start = size % 3 + start;
        matrix[i] = convert100(num, start);
    }
    */
}

char *get_from_dict(char *num)
{
    int fd;
    int sz;
    int bytesRead;
    int totalBytesRead;
    char *dict;
    char buffer[4096];

    fd = open("foo.txt", O_RDONLY, 0);
    if (fd < 0) {
        write(1, "Dict Error\n", 11);
        exit(1);
    }
    totalBytesRead = 0;
    while ((bytesRead = read(file_descriptor, buffer, sizeof(buffer))) > 0) {
        totalBytesRead += bytesRead;
    }
    dict = (char *)malloc(totalBytesRead * sizeof(char));
    sz = read(fd, dict, sizeof(dict));
    if (close(fd) < 0) {
        write(1, "Error with file closing\n", 11);
        exit(1);
    }
    return (get_dict_value(dict, num));
}

char *get_dict_value(char *dict, char *num)
{
    char *ptr_num;
    char *value;
    int i;
    int j;

    ptr_num = ft_strstr(dict, num);
    i = 0;
    while(ptr_num[i] != ':')
        i++;
    while (ptr_num[i] < '0' || ptr_num[i] > '9')
        i++;
    j = 0;
    while(ptr_num[i + j] >= '0' && ptr_num[i+j] <= '9')
        j++;
    value = (char*)malloc(j * sizeof(char) + 1);
    j = 0;
    while(ptr_num[i + j] >= '0' && ptr_num[i+j] <= '9')
    {
        value[j] = ptr_num[i + j];
        j++;
    }
    value[j] = '\0';
    return (value);
}

char *ft_strstr(char *str, char *to_find)
{
    char sub_str[ft_strlen(to_find)];
    char *ptr_str;
    int i;
    int y;
    int f;

    y = 0;
    f = 0;
    while (str[y] != '\0')
    {
        i = 0;
        while (str[y+i] == to_find[i])
        {
            sub_str[i] = to_find[i];
            i++;
            if (to_find[i] == '\0')
            {
                sub_str[i] = '\0';
                f = 1;
            }
        }
        if (f)
            break;
        else
            sub_str[0] = '\0';
        y++;
    }
    if (!f)
        return "\0";
    ptr_str = sub_str;
    return (ptr_str);
}

char *convert100(char *num3)
{
    int i;
    char str[1];
    char *alpha_num;
    char *to_add;

    str[0] = '\0';
    i = 3;
    while (i != 0)
    {
        if (num[0] == '0')
            continue ;
        if (i == 3)
        {
            to_add = get_from_dict("100");
            alpha_num = get_from_dict(num[0]);
            ft_strcat(str, alpha_num);
            ft_strcat(str, to_add);
        }
        else if (i == 2)
        {
            alpha_num = get_from_dict(ft_strcat(num[1], "0"));
            ft_strcat(str, alpha_num);
        }
        else if (i == 1)
        {
            if (num[2] != "0")
            {
                alpha_num = get_from_dict(num[2]);
                ft_strcat(str, alpha_num);
            }
        }
        i--;
    }
    return (str);
}

char *run_power(int power)
{
    char res;
    int i;

    res = {'1', '0', '0', '0'};
    i = 0;
    while (i < power)
        ft_strcat(res, "000");
    return (res);
}

char *ultimate_convert(char **matrix)
{
    int size;
    char *illion;
    int i;
    char ultimate_str[1];

    i = 0;
    ultimate_str[0] = '\0'; 
    size = ft_matrixlen(matrix);
    if (size < 1)
        return " ";
    while (i < size)
    {
        if (matrix[1][0] == '0')
            continue ;
        ft_strcat(ultimate_str, matrix[i]);
        if (i == size - 1)
            break;
        illion = get_from_dict(run_power(size - 1 - i));
        ft_strcat(ultimate_str, illion);
    }
    return (ultimate_str);
}

void *ft_strcat(char *array1, char *array2)
{
    char *temp_str;
    int i;
    int j;
    int f;

    f = 2;
    if (*array1 == '\0')
        f = 1;
    temp_str = ft_strdup(array1);
    free(array1);
    array1 = (char *)malloc((ft_strlen(temp_str) + ft_strlen(array2) + f) * sizeof(char));
    i = 0;
    while (temp_str[i] != '\0')
    {
        array1[i] = temp_str[i];
        i++;
    }
    if (f == 2)
        array1[i++] = ' ';
    j = 0;
    while (array2[i] != '\0')
    {
        array1[i + j] = array2[i];
        j++;
    }
    array1[i + j] = '\0';
}

char *ft_strdup(char *src)
{
    char *dest;
    int i;

    dest = (char *)malloc(ft_strlen(src) + 1);
    if (!dest)
        return (0);

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return (dest);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
}

int ft_matrixlen(**matrix)
{
    int i;

    i = 0;
    while(str[i] != NULL)
        i++;
    return (i);
}

char *set_dict(char **argv)
{
    if (argv[2] != NULL)
        return (argv[2]);
    return("res/numbers.dict");
}