/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:25:59 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/21 15:17:02 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "../bool/bool.h"
# include <pthread.h>

typedef pthread_mutex_t	t_mutex;

typedef struct s_table	t_table;

typedef struct s_fork
{
	int					id;
	t_mutex				mutex;
}						t_fork;

typedef struct s_philo
{
	int					id;
	long				meal_counter;
	long				time_of_last_meal;
	t_bool				is_full;
	t_fork				*left_fork;
	t_fork				*right_fork;
	pthread_t			thread_id;
	t_table				*table;
}						t_philo;

// number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
struct					s_table
{
	long				number_of_philosophers;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				meal_limit;
	long				starting_time;
	t_philo				*philos;
	t_fork				*forks;
	t_bool				end_simulation;
	t_bool				start_simulation;
	t_mutex				mutex;
};

// Exit with error
void					exit_with_error_msg(const char *msg);

// Input parsing
void					parse_input(t_table *table, const char **argv);

// Init
void					init_table(t_table *table);

typedef enum e_mux_op
{
	LOCK,
	UNLOCK,
	FREE,
	INIT
}						t_mux_op;

typedef enum e_thread_op
{
	CREATE,
	JOIN,
	DETACH,
}						t_thread_op;

// Safe functs
void					*safe_malloc(size_t size);
void					safe_mutex_op(t_mutex *mux, t_mux_op op);
void					safe_thread_op(pthread_t *thread,
							void *(*funct)(void *), void *data, t_thread_op op);

#endif