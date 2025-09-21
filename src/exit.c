/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 13:05:18 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/21 13:08:22 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include <stdio.h>
#include <stdlib.h>

void	exit_with_error_msg(const char *msg)
{
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}