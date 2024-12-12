/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 07:14:00 by anoteris          #+#    #+#             */
/*   Updated: 2024/12/12 07:42:43 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// Includes

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

// <|===|> Is <|===|>

/**
 * @name isalpha
 * @param c The ascii code of a char
 * @return Returns 1 if c matches the ascii code of a letter, 0 if not
 * @author NotArt
 */
int				ft_isalpha(int c);

/**
 * @name isdigit
 * @param c The ascii code of a char
 * @return Returns 1 if c matches the ascii code of a digit, 0 if not
 * @author NotArt
 */
int				ft_isdigit(int c);

/**
 * @name isalnum
 * @param c The ascii code of a char
 * @return Returns 1 if c matches the ascii code of a letter or a digit, 0 if not
 * @author NotArt
 */
int				ft_isalnum(int c);

/**
 * @name isascii
 * @param c The ascii code of a char
 * @return Returns 1 if c matches any ascii code, 0 if not
 * @author NotArt
 */
int				ft_isascii(int c);

/**
 * @name isprint
 * @param c The ascii code of a char
 * @return Returns 1 if c matches the ascii code of a printable character,
 * 0 if not
 * @author NotArt
 */
int				ft_isprint(int c);

/**
 * @name isspace
 * @param c The ascii code of a char
 * @return Returns 1 if c matches the ascii code of a white-space character,
 * including space, form-feed, newline, carriage return,
 * horizontal tab and vertical tab.
 * It returns 0 if not
 * @author NotArt
 */
int				ft_isspace(int c);

// <|===|> Str <|===|>

/**
 * @name strlen
 * @param s A string
 * @return The string length
 * @author NotArt
 */
size_t			ft_strlen(const char *s);

/**
 * @name strlcpy
 * @brief Copies size - 1 characters from src to dest
 * and null-terminates the result
 * @param dest The emplacement where to copy
 * @param src The copied string (must be null-terminated)
 * @param size How many characters have to be copied (including null-termination)
 * @return The length of the copied string src
 * @author NotArt
 */
size_t			ft_strlcpy(char *dest, const char *src, size_t size);

/**
 * @name strlcat
 * @brief Concatenate size - strlen(dest) - 1 characters from src
 * at the end of dest and null-terminates the result
 * @param dest The string at the end of which to
 * concatenate src (must be null-terminated)
 * @param src The string to concatenate
 * at the end of dest (must be null-terminated)
 * @param size How many characters there should be
 * in the resulting string (including null-termination)
 * @return The length of both string cumulated
 * @author NotArt
 */
size_t			ft_strlcat(char *dest, const char *src, size_t size);

/**
 * @name strchr
 * @param s A string in which to search for a character
 * @param c The character to search in the string s
 * @details '/0' can be searched into s,
 * the result would be the end of the string
 * @return A pointer to the first iteration of c in s,
 * or, if c wasn't found, NULL
 * @author NotArt
 */
char			*ft_strchr(const char *s, int c);

/**
 * @name strrchr
 * @param s A string in which to search for a character
 * @param c The character to search in the string s
 * @details '/0' can be searched into s,
 * the result would be the end of the string
 * @return A pointer to the last iteration of c in s, or, if c wasn't found, NULL
 * @author NotArt
 */
char			*ft_strrchr(const char *s, int c);

/**
 * @name strcmp
 * @param s1 A string
 * @param s2 A better string
 * @return The difference between the ascii code of the two char
 * that show the first difference between the two strings,
 * if the two strings appear to be identical, then 0 is returned
 * @author NotArt
 */
int				ft_strcmp(const char *s1, const char *s2);

/**
 * @name strncmp
 * @param s1 A string
 * @param s2 A better string
 * @param n How many characters should be compared
 * @return The difference between the ascii code of the two char
 * that show the first difference between the two strings,
 * if the two strings appear to be identical (for n characters),
 * then 0 is returned
 * @author NotArt
 */
int				ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @name strdup
 * @brief Takes a string and return a copy of that string
 * that have been allocated on heap
 * @param s 
 * @return A copy of s, allocated on heap
 * @author NotArt
 */
char			*ft_strdup(const char *s);

/**
 * @name substr
 * @param s The copied string
 * @param start After how many characters to start copying from
 * @param len How many characters to copy (not counting null-termination),
 * will be ignored if greater than what is to be copied
 * @return A copy of a part of s, allocated on heap
 * @author NotArt
 */
char			*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @name strnstr
 * @brief Search for a string into another one
 * @param big The string in which to search little
 * @param little The string to search into big
 * @param len How many characters to look little into big
 * @return A pointer to the start of little if it was found into big,
 * if not, it returns NULL
 * @author NotArt
 */
char			*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @name strtrim
 * @brief Takes a string and returns an allocated on heap string
 * that've been trimed in both edge
 * @param s1 The string to be trimed
 * @param set The characters to trim at both edge of s1
 * @return A trimmed copy of s1, allocated on heap
 * @author NotArt
 */
char			*ft_strtrim(char const *s1, char const *set);

/**
 * @name strjoin
 * @param s1 A string
 * @param s2 Another string, or maybe the same, idk, as you want
 * @return The junction of s1 and s2, allocated on heap
 * @author NotArt
 */
char			*ft_strjoin(char const *s1, char const *s2);

/**
 * @name split
 * @brief Cut a string into multipe strings using a delimiter
 * @param s A string
 * @param c The separator
 * @return An array of strings
 * @author NotArt
 */
char			**ft_split(char const *s, char c);

/**
 * @name strmapi
 * @param s A string
 * @param f The function that treat every character
 * @return An allocated on heap string created based on s
 * after each of its characters passed through f
 * @author NotArt
 */
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @name striteri
 * @brief Affects each char of a string depending on given function
 * @param s A string
 * @param f The function that operates on every character
 * @author NotArt
 */
void			ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @name toupper
 * @param c The ascii code of a char
 * @return The char given as argument,
 * modified to be upper case if it was a lower case
 * @author NotArt
 */
int				ft_toupper(int c);

/**
 * @name tolower
 * @param c The ascii code of a char
 * @return The char given as argument,
 * modified to be lower case if it was an upper case
 * @author NotArt
 */
int				ft_tolower(int c);

// <|===|> Mem <|===|>

/**
 * @name memset
 * @brief Set a memory area to a certain value
 * @param s A pointer to the memory area to set as c
 * @param c The value to set in this memory area
 * @param n The size of the memory area
 * @return The memory area s
 * @author NotArt
 */
void			*ft_memset(void *s, int c, size_t n);

/**
 * @name bzero
 * @brief Set a memory area to 0
 * @param s A pointer to the memory area to set as zero
 * @param n The size of the memory area
 * @author NotArt
 */
void			ft_bzero(void *s, size_t n);

/**
 * @name memcpy
 * @brief Copies n bytes from src to dest
 * @param dest The memory area where to copy
 * @param src The memory area to copy
 * @param n How many bytes to copy
 * @return The memory area dest
 * @author NotArt
 */
void			*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @name memmove
 * @brief Copies n bytes from src to dest,
 * avoiding overwritting problems of memcpy
 * @param dest The memory area where to copy
 * @param src The memory area to copy
 * @param n How many bytes to copy
 * @return The memory area dest
 * @author NotArt
 */
void			*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @name memchr
 * @param s The memory area where to search for the presence of a value
 * @param c The value to look for
 * @param n The size of the memory area to read through
 * @return A pointer to the first iteration of c in s,
 * or, if c wasn't found, NULL
 * @author NotArt
 */
void			*ft_memchr(const void *s, int c, size_t n);

/**
 * @name memcmp
 * @param s1 A memory area
 * @param s2 A slightly better memory area
 * @param n How many bytes should be compared
 * @return The difference between the two bytes
 * that show the first difference between the two memory area,
 * if the two memory area appear to be identical (for n bytes),
 * then 0 is returned
 * @author NotArt
 */
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @name calloc
 * @brief Allocate on heap and fill by zeros a memory area
 * @param nmemb The number of element to allocates
 * @param size The memory needed by each element
 * @return A pointer to the freshly allocated on heap memory area filled by zeros
 * @author NotArt
 */
void			*ft_calloc(size_t nmemb, size_t size);

/**
 * @name free_str_array
 * @param to_free An array of strings to free (the array must be null-terminated)
 * @author NotArt
 */
void			free_str_array(char **to_free);

// <|===|> Fd <|===|>

/**
 * @name putchar_fd
 * @param c The char to write
 * @param fd The file descriptor in which to write
 * @return How many characters were written
 * @author NotArt
 */
int				ft_putchar_fd(char c, int fd);

/**
 * @name putstr_fd
 * @param s The string to write
 * @param fd The file descriptor in which to write
 * @return How many characters were written
 * @author NotArt
 */
int				ft_putstr_fd(char *s, int fd);

/**
 * @name putendl_fd
 * @brief Writes a string followed by a newline in the given file descriptor
 * @param s The string to write
 * @param fd The file descriptor in which to write
 * @return How many characters were written
 * @author NotArt
 */
int				ft_putendl_fd(char *s, int fd);

/**
 * @name putnbr_fd
 * @param n The number to write
 * @param fd The file descriptor in which to write
 * @return How many characters were written
 * @author NotArt
 */
int				ft_putnbr_fd(int n, int fd);

/**
 * @name putunbr_fd
 * @brief Same as putnbr_fd, but simplified for unsigned int only
 * @param n The number to write
 * @param fd The file descriptor in which to write
 * @return How many characters were written
 * @author NotArt
 */
int				ft_putunbr_fd(unsigned int n, int fd);

/**
 * @name putunbr_fd
 * @brief Same as putnbr_fd, but for long long int
 * @param n The number to write
 * @param fd The file descriptor in which to write
 * @return How many characters were written
 * @author NotArt
 */
int				ft_putlongnbr_fd(long long n, int fd);

/**
 * @def For uppercase in puthexnbr_fd
 */
# define MAJ 'X'
/**
 * @def For lowercase in puthexnbr_fd
 */
# define MIN 'x'

/**
 * @name puthexnbr_fd
 * @brief Writes a number in hexadecimal
 * @param n The number to write
 * @param fd The file descriptor in which to write
 * @param hex_case Wether MIN/MAJ ('x'/'X')
 * to choose if the hexadecimal will be written in upper or lower case
 * @return How many characters were written
 * @author NotArt
 */
int				ft_puthexnbr_fd(unsigned long n, int fd, char hex_case);

// <|===|> Math <|===|>

/**
 * @name atoi
 * @param nptr A string from which to take a number,
 * the string can have spaces before the number, a sign,
 * and garbage after the number
 * @return The number obtained from the string
 * @author NotArt
 */
int				ft_atoi(const char *nptr);

/**
 * @name atol
 * @brief Same as atoi but for long integers
 * @param nptr A string from which to take a number,
 * the string can have spaces before the number, a sign,
 * and garbage after the number
 * @return The number obtained from the string
 * @author NotArt
 */
long			ft_atol(const char *nptr);

/**
 * @name itoa
 * @param n The number to convert into a string
 * @return The string that represents the number given as argument
 * @author NotArt
 */
char			*ft_itoa(int n);

/**
 * @name intlen
 * @param nb A number
 * @return How many digits there is in the given number (also count the '-')
 * @author NotArt
 */
int				ft_intlen(int nb);

/**
 * @name uintlen
 * @brief Same as intlen, but simplified for unsigned int only
 * @param nb A number
 * @return How many digits there is in the given number
 * @author NotArt
 */
int				ft_uintlen(unsigned int nb);

/**
 * @name hexlen
 * @param nb A number
 * @return How many digits there would be in the hexadecimal translation
 * of the given number
 * @author NotArt
 */
int				ft_hexlen(unsigned long nb);

/**
 * @name abs
 * @param nb A number
 * @return The absolute value of the given number
 * @author NotArt
 */
long long		ft_abs(int nb);

/**
 * @name rand_uchar
 * @return A random value (between 0 and 255) got from /dev/random,
 * if open encountered a problem, return 1
 * @author NotArt
 */
unsigned char	rand_uchar(void);

/**
 * @name rand_int
 * @return A random value (between 0 and INT_MAX) got from /dev/random,
 * if open encountered a problem, return 1
 * @author NotArt
 */
int				rand_int(void);

// <|===|> Linked list <|===|>

/**
 * @struct A classic linked list
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
 * @name lstnew
 * @param content The content to give to the new node
 * @return The freshly allocated on heap node
 * @author NotArt
 */
t_list			*ft_lstnew(void *content);

/**
 * @name lstadd_front
 * @param lst The address of the pointer to the head of the list
 * @param new The node to add at the head of the list
 * @author NotArt
 */
void			ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @name lstsize
 * @param lst The node in which to start counting the size of the list
 * @return The size of the list
 * @author NotArt
 */
int				ft_lstsize(t_list *lst);

/**
 * @name lstlast
 * @param lst The node from which to go to the tail of the list
 * @return The last node of the list
 * @author NotArt
 */
t_list			*ft_lstlast(t_list *lst);

/**
 * @name lstsecond_to_last
 * @param lst The node from which to go to right before the tail of the list
 * @return The second to last node of the list
 * @author NotArt
 */
t_list			*ft_lstsecond_to_last(t_list *lst);

/**
 * @name lstadd_back
 * @param lst The address of the pointer to a node of the list
 * @param new The node to add at the tail of the list
 * @author NotArt
 */
void			ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @name lstdelone
 * @brief Delete properly the given node,
 * as the user can give a function that matches the way he created it
 * @param lst A node to delete
 * @param del The function used to delete the node
 * @author NotArt
 */
void			ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * @name lstclear
 * @brief Delete properly the given list,
 * as the user can give a function that matches the way he created the nodes
 * @param lst The address of a pointer to a node of the list
 * from which to start deleting every node
 * @param del The function used to delete each node of the list
 * @author NotArt
 */
void			ft_lstclear(t_list **lst, void (*del)(void*));

/**
 * @name lstiter
 * @param lst The address of a pointer to a node of the list
 * from which to start applying the given function to the content of every node
 * @param f The function to apply to the content of every node
 * @author NotArt
 */
void			ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @name lstmap
 * @param lst The list to take as a base to create a new one
 * @param f The function that gives a content
 * depending one the content that it receives
 * @param del The function used to delete each node of the newly created list
 * if an allocation went wrong
 * @return The list that've been created
 * @author NotArt
 */
t_list			*ft_lstmap(t_list *lst, void*(*f)(void *), void(*del)(void *));

#endif
