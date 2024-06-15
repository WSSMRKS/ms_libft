/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:57:41 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/14 15:42:25 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "../libft.h"

t_bool		get_env_path_dirs(char *const *envp, t_vec *out);
t_bool		split_env_path(t_str_slice path_value, t_vec *out);
t_str_slice	get_var(char *const *envp, t_str_slice var);
t_str_slice	get_value(t_str_slice env_var);

#endif
