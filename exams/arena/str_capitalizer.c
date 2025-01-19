/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaula-d <ppaula-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:54:00 by ppaula-d          #+#    #+#             */
/*   Updated: 2025/01/09 14:58:29 by ppaula-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv){
	int i = 0;
	int j = 1;
	char c;
	
	if(argc > 1){

		while(j < argc){
			i = 0;
			while(argv[j][i] != '\0'){
				if(argv[j][i] >= 'a' && argv[j][i] <= 'z' && argv[j][i - 1] <= 32){
					c = argv[j][i] - 32;
					write(1, &c, 1);
				}else if(argv[j][i] >= 'A' && argv[j][i] <= 'Z' && argv[j][i - 1] <= 32){
					write(1, &argv[j][i], 1);
				}else if(argv[j][i] >= 'A' && argv[j][i] <= 'Z'){
					c = argv[j][i] + 32;
					write(1, &c, 1);
				}else{
					write(1, &argv[j][i], 1);
				}
				i++;
			}
			j++;
			write(1, "\n", 1);
		}
	}else{
		write(1, "\n", 1);
    }
}