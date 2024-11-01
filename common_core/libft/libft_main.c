/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:44:26 by ppaula-d          #+#    #+#             */
/*   Updated: 2024/10/28 08:44:29 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#--------------------------------------=---------------------------------------#
#			         		      ft_isalpha                			       #
#--------------------------------------=---------------------------------------#

#include <stdio.h>

int	main(void)
{
	char a = 'P';
	char b = '3';

	printf("Return value 1 for alpha, 0 for non-alpha\n");
	printf("The value of a is: %d\nThe value of b is: %d\n",
			ft_isalpha(a), ft_isalpha(b));
	return(0);
}

#--------------------------------------=---------------------------------------#
#			         		      ft_isdigit                			       #
#--------------------------------------=---------------------------------------#

#include <stdio.h>

int	main(void)
{
	int	a = '8';
	int b = 'P';

	printf("Return value 1 for digit, 0 for non-digit\n");
	printf("The value of a is: %d\nThe value of b is: %d\n",
			ft_isdigit(a), ft_isdigit(b));
	return (0);
}

#--------------------------------------=---------------------------------------#
#			         		      ft_isalnum                			       #
#--------------------------------------=---------------------------------------#


#include <stdio.h>

int	main(void)
{
	char a = ' ';
	char b = '\t';
	char c = 'P';
	char d = '8';

	printf("Return value 1 for alphanumeric, 0 for non-alphanumeric\n");
	printf("The value of a, b, c, d is: %d, %d, %d, %d\n", ft_isalnum(a),
			ft_isalnum(b), ft_isalnum(c), ft_isalnum(d));
	return (0);
}

#--------------------------------------=---------------------------------------#
#			         		      ft_isascii                			       #
#--------------------------------------=---------------------------------------#

#include <stdio.h>

int	main(void)
{
	int	a = 130;
	int b = 88;

	printf("Return value 1 for printable, 0 for non-printable\n");
	printf("The value of a is: %d\nThe value of b is: %d\n",
			ft_isprint(a), ft_isprint(b));
	return (0);
}
{
	int	a = 130;
	int b = 88;

	printf("Return value 1 for ascii, 0 for non-ascii\n");
	printf("The value of a is: %d\nThe value of b is: %d\n",
			ft_isascii(a), ft_isascii(b));
	return (0);
}

#--------------------------------------=---------------------------------------#
#			         		      ft_isprint                			       #
#--------------------------------------=---------------------------------------#


#include <stdio.h>

int	main(void)
{
	int	a = 130;
	int b = 88;

	printf("Return value 1 for printable, 0 for non-printable\n");
	printf("The value of a is: %d\nThe value of b is: %d\n",
			ft_isprint(a), ft_isprint(b));
	return (0);
}

#--------------------------------------=---------------------------------------#
#			         		       ft_strlen                			       #
#--------------------------------------=---------------------------------------#


#include <stdio.h>

int	main(void)
{
	char *a = "Porto";
	char *b = "42";

	printf("The length of the a string is: %d\nThe length of the b string is: %d\n", ft_strlen(a), ft_strlen(b));
	return (0);
}

#--------------------------------------=---------------------------------------#
#			         		      ft_memset                		    	       #
#--------------------------------------=---------------------------------------#


#include <stdio.h>

int	main(void)
{
	//test1
	char test1[10] = "abcdefghi";
	printf("Before ft_memset: %s\n", test1);
	ft_memset(test1, 'x', 5);
	printf("After ft_memset: %s\n\n", test1);

	//test2
	char test2[10] = "abcdefghi";
	printf("Before ft_memset: %s\n", test2);
	ft_memset(test2, 'y', 0);
	printf("After ft_memset: %s\n\n", test2);

	//test3
	char test3[10] = "abcdefghi";
	printf("Before ft_memset: %s\n", test3);
	ft_memset(test3, '0', 10);
	printf("After ft_memset: %s\n\n", test3);

	//test4
	char test4[10] = "abcdefghi";
	printf("Before ft_memset: %s\n", test4);
	ft_memset(test4, 0, 10);
	printf("After ft_memset: %s\n", test4);
	
	return (0);
}

#--------------------------------------=---------------------------------------#
#			         		       ft_bzero                		    	       #
#--------------------------------------=---------------------------------------#

#include <unistd.h>

int	main(void)
{
	char test[10] = "abcdefghi";
	write(1, "Before ft_bzero: ", 18);
	write(1, test, 10);
	write (1, "\n", 1);
	ft_bzero(test, 1);
	write(1, "After ft_bzero: ", 17);
	write(1, test, 10);
	write (1, "\n", 1);
	return (0);
}

#--------------------------------------=---------------------------------------#
#			         		       ft_memcpy               		    	       #
#--------------------------------------=---------------------------------------#

#include <stdio.h>

void	test_mmcpy_no_overlap(void)
{
	char	src[50] = "Test string for memcpy";
	char	dest[50];

	ft_memcpy(dest, src, strlen(src) + 1);
	printf("Source: %s\n", src);
	printf("Destination: %s\n\n", dest);
}

void	test_mmcpy_overlap(void)
{
	char	src_dest[50] = "Test string for memcpy";

	ft_memcpy(src_dest + 5, src_dest, strlen(src_dest) + 1);
	printf("Source and Destination (overlap): %s\n", src_dest);
}

int	main(void)
{
	test_mmcpy_no_overlap();
	test_mmcpy_overlap();
	return (0);
}

#--------------------------------------=---------------------------------------#
#			         		      ft_memmove               		    	       #
#--------------------------------------=---------------------------------------#


#include <stdio.h>

void	test_memmove_overlap(void)
{
	char	str[] = "Hello, World!";
	printf("Original string: %s\n", str);
	ft_memmove((str + 7), str, 5);
	printf("After ft_memmove with overlap: %s\n", str);
}

int	main(void)
{
	test_memmove_overlap();
	return (0);
}

#--------------------------------------=---------------------------------------#
#			         		      ft_strlcpy               		    	       #
#--------------------------------------=---------------------------------------#


#include <stdio.h>
#include <string.h>

void	test_ft_strlcpy(void)
{
	char		dest[50];
	const char	*src;
	size_t		size;
	size_t		result;

	//test 1
	src = "42 Porto";
	size = 42;
	result = ft_strlcpy(dest, src, size);
	printf("Given src: '%s', Actual dest: '%s'\n", src, dest);

	//test 2
	src = "42 Porto";
	size = 4;
	result = ft_strlcpy(dest, src, size);
	printf("Given src: '%s', Actual dest: '%s'\n", src, dest);

	//test 3
	src = "";
	size = 8;
	result = ft_strlcpy(dest, src, size);
	printf("Given src: '%s', Actual dest: '%s'\n", src, dest);

	//test 4
	src = "42 Porto";
	size = 0;
	result = ft_strlcpy(dest, src, size);
	printf("Given src: '%s', Actual dest: '%s'\n", src, dest);
}

int	main(void)
{
	test_ft_strlcpy();
	return (0);
}

#--------------------------------------=---------------------------------------#
#			         		      ft_strlcat               		    	       #
#--------------------------------------=---------------------------------------#

#include <stdio.h>
#include <string.h>

void	test_ft_strlcat(void)
{
	//test 1
	char		dest1[20] = "42 ";
	const char	*src1 = "Porto";
	size_t		result1;
	printf("Total length: %zu\nSrc: %s\nPrinted: %s\n\n", result1 = ft_strlcat(dest1, src1, sizeof(dest1)), src1, dest1);

	//test 2
	char		dest2[20] = "";
	const char	*src2 = "42 P";
	size_t		result2;
	printf("Total length: %zu\nSrc: %s\nPrinted: %s\n\n", result2 = ft_strlcat(dest2, src2, sizeof(dest2)), src2, dest2);

	//test 3
	char		dest3[2] = "";
	const char	*src3 = "42 P";
	size_t		result3;
	printf("Total length: %zu\nSrc: %s\nPrinted: %s\n\n", result3 = ft_strlcat(dest3, src3, sizeof(dest3)), src3, dest3);

	//test 4
	char		dest4[1] = "";
	const char	*src4 = "";
	size_t		result4;
	printf("Total length: %zu\nSrc: %s\nPrinted: %s\n\n", result4 = ft_strlcat(dest4, src4, sizeof(dest4)), src4, dest4);

}

int	main(void)
{
	test_ft_strlcat();
	return (0);
}

#--------------------------------------=---------------------------------------#
#			         		      ft_toupper               		    	       #
#--------------------------------------=---------------------------------------#

#include <stdio.h>

int	main(void)
{
	int	p = 98;

	printf("The uppercase of %c is: %c\n", p, ft_toupper(p));
	return (0);
}

#--------------------------------------=---------------------------------------#
#			         		      ft_tolower               		    	       #
#--------------------------------------=---------------------------------------#

#include <stdio.h>

int	main(void)
{
	int	p = 66;

	printf("The lowercase of %c is: %c\n", p, ft_tolower(p));
	return (0);
}

#--------------------------------------=---------------------------------------#
#			         		      ft_strchr               		    	       #
#--------------------------------------=---------------------------------------#

#include <stdio.h>
#include <string.h>

void	test_ft_strchr(void)
{
	const char	*test_str1 = "abra";
	char	c1 = 's';
	printf("String: %s\nCharacter to be found: %c\nFound?%s\n", test_str1, c1, ft_strchr(test_str1, c1));
}

#--------------------------------------=---------------------------------------#
#			         		      ft_strrchr               		    	       #
#--------------------------------------=---------------------------------------#

#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*str = "abracadabro";

	char *last = strrchr(str, 'a');
	printf("Last occurrence of 'a' before end of string: %s\n", last);
	return (0);
}

#--------------------------------------=---------------------------------------#
#			         		      ft_strncmp               		    	       #
#--------------------------------------=---------------------------------------#

#include <stdio.h>
#include <string.h>

int main(void) 
{
    const char *str1 = "Hello, World!";
    const char *str2 = "Hello, there!";
    int result = strncmp(str1, str2, 5);

    if (result == 0)
        printf("The first 5 characters are equal.\n");
    else if (result < 0)
        printf("str1 is less than str2.\n");
    else
	{
        printf("str1 is greater than str2.\n");
	}
	return (0);
}

#--------------------------------------=---------------------------------------#
#			         		      ft_memchr               		    	       #
#--------------------------------------=---------------------------------------#

#include <stdio.h>
#include <string.h>

int main(void) 
{
    const char *str = "Hello, World!";
    
    char *result = memchr(str, 'o', 10);
    
    if (result) 
	    printf("Found 'o': %s\n", result);
    else
    	printf("'o' not found in the first 10 characters.\n");

    return 0;
}

#--------------------------------------=---------------------------------------#
#			         		      ft_memcmp               		    	       #
#--------------------------------------=---------------------------------------#


#include <stdio.h>
#include <string.h>

int main(void) 
{
    const char *str1 = "Hello, World!";
    const char *str2 = "Helol, there!";
    
    int result = memcmp(str1, str2, 5);

    if (result == 0)
        printf("The first 5 bytes are equal.\n");
    else if (result < 0)
        printf("str1 is less than str2.\n");
    else
	{
        printf("str1 is greater than str2.\n");
    }

    return 0;
}

#--------------------------------------=---------------------------------------#
#			         		      ft_strnstr               		    	       #
#--------------------------------------=---------------------------------------#

#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *haystack = "Hello, World!";
    const char *needle = "abra";
    
    char *result = ft_strnstr(haystack, needle, 13);

    if (result)
		printf("Found substring: %s\n", result);
    else
	{
    	printf("Substring not found.\n");
    }

    return 0;
}

#--------------------------------------=---------------------------------------#
#			         		      ft_atoi               		    	       #
#--------------------------------------=---------------------------------------#

int main(void)
{
	printf("%d\n%d\n", ft_atoi(" 	-12345+TRAA"), atoi(" 	-12345+TRAA"));
	return (0);
}

#--------------------------------------=---------------------------------------#
#			         		      ft_calloc               		    	       #
#--------------------------------------=---------------------------------------#

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int n = 5;
    int *arr = (int *)calloc(n, sizeof(int));
    
    if (arr == NULL) 
	{
        printf("Memory allocation failed\n");
        return (1);
    }
    printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
    free(arr);
    return (0);
}

#--------------------------------------=---------------------------------------#
#			         		      ft_strdup               		    	       #
#--------------------------------------=---------------------------------------#


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) 
{
    const char original[] = "Hello, World!";
    
    char *duplicate = strdup(original);
    if (duplicate == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Original: %s\n", original);
    printf("Duplicate: %s\n", duplicate);
    duplicate[0] = 'h';
    printf("Modified Duplicate: %s\n", duplicate);
    printf("Original remains unchanged: %s\n", original);
    free(duplicate);

    return (0);
}

#--------------------------------------=---------------------------------------#
#			         		      ft_substr               		    	       #
#--------------------------------------=---------------------------------------#

#include <stdio.h>

int main(void) 
{
    char *s = "Hello, World!";
    char *sub = ft_substr(s, 7, 5);
    
    printf("Substring: %s\n", sub);
    free(sub);
    return (0);
}

#--------------------------------------=---------------------------------------#
#			         		      ft_strjoin               		    	       #
#--------------------------------------=---------------------------------------#


#include <stdio.h>
#include <string.h>

int main(void) 
{
    char *s1 = "Hello, ";
    char *s2 = "World!";
    char *result = ft_strjoin(s1, s2);

    if (result) 
	{
        printf("Joined String: %s\n", result);
        free(result);
    } 
	else 
	{
        printf("Memory allocation failed.\n");
    }
    return (0);
}

#--------------------------------------=---------------------------------------#
#			         		      ft_strtrim               		    	       #
#--------------------------------------=---------------------------------------#

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    char *s1 = "   Hello, World!   ";
    char *set = " ";
    char *trimmed = ft_strtrim(s1, set);

    if (trimmed) 
	{
        printf("Trimmed String: '%s'\n", trimmed);
        free(trimmed);
    } 
	else 
	{
        printf("Memory allocation failed.\n");
    }

    return (0);
}

#--------------------------------------=---------------------------------------#
#			         	           ft_split               		    	       #
#--------------------------------------=---------------------------------------#

#include <stdio.h>

int main(void) 
{
    char *s = "This is a test string.";
    char **tokens = ft_split(s, ' ');
    if (tokens) 
	{
        int i = 0;
        while (tokens[i] != NULL) 
		{
            printf("Token %d: %s\n", i, tokens[i]);
            free(tokens[i]);
            ++i;
		}
        free(tokens);
    } 
	else 
	{
        printf("Memory allocation failed.\n");
    }

    return (0);
}

#--------------------------------------=---------------------------------------#
#			         	            ft_itoa               		    	       #
#--------------------------------------=---------------------------------------#

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(void) 
{
    int num = -12345;
    char *result = ft_itoa(num);

    if (result) 
	{
        printf("The string representation of %d is %s\n", num, result);
        free(result);
    } 
	else 
	{
        printf("Memory allocation failed!\n");
    }

    return (0);
}