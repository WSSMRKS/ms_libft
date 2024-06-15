/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:16:25 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/14 15:42:25 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <unistd.h>

// t_bool	path_exists(const char *path);
// t_bool	file_exists(const char *file);
// t_bool	dir_exists(const char *dir);

// t_bool	is_dir(const char *path);
// t_bool	is_file(const char *path);

// t_bool	is_readable(const char *path);
// t_bool	is_writable(const char *path);
// t_bool	is_executable(const char *path);

t_bool	find_file(t_str_slice path, const t_vec *dirs, int mode, t_str *out);
t_bool	find_file_perror(t_str_slice path, const t_vec *dirs, int mode,
			t_str *out);
t_bool	find_file_on_path(t_str_slice path, char *const *envp, int mode,
			t_str *out);
t_bool	find_file_on_path_perror(t_str_slice path, char *const *envp, int mode,
			t_str *out);
t_bool	dirs_join_file(const t_vec *dirs, t_str_slice file, t_vec *out);
