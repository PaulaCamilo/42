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

