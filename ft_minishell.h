/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/10/05 13:16:40 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <sys/types.h>
# include <pwd.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <stddef.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <grp.h>
# include <sys/wait.h>
# include <signal.h>

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_RESET   "\x1b[0m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"

typedef struct		s_env
{
	char	*line;
	char	**env;
	int		num;
	char	**path;
	char	*pwd;
	char	*oldpwd;
	char	*home;
	char	**old_env;
	char	**bonus;
}					t_env;

typedef struct		s_echo_f
{
	int			n;
	int			e;
	int			ee;
	int			dash;
}					t_echo_f;

int					ft_iden(t_env *all);
void				ft_bye_space(char *str, int *i);
int					ft_print_without(t_env *all, t_echo_f *echo, char *str1);
void				ft_print_not_command(char *str);

int					ft_search_f(t_echo_f *echo, char c);
int					ft_find_flag(t_env *all, t_echo_f *echo, char *str);
void				ft_echo_str(t_env *all, t_echo_f *echo, char *str);
void				ft_echo(t_env *all);
void				ft_echo_init(t_echo_f *echo);

void				ft_env(t_env *all);
void				ft_env_opt(t_env *all);
void				ft_env_analyze(t_env *all, char **mass);

char				**ft_setenv(t_env *all, char *line);
char				**ft_setenv_und(t_env *all, char *line);
char				*ft_add_new_env(t_env *all, char **temp);

char				**ft_copy_env(char **env);

char				**ft_make_copy(char **env, int *j);
int					ft_valid_command_setenv(t_env *all, char **mass, int i);
int					ft_check_var(t_env *all, char *str);
void				ft_print_mass(char **mass);
char				**ft_unsetenv(t_env *all);

char				**ft_path(char	**mass);
void				ft_apply(t_env *all, char *line, char	**mass1);

void				ft_replace(t_env *all, char *place);
void				ft_home(t_env *all);

void				ft_cd(t_env *all);
char				*ft_quote(char	*str);

int					ft_only_space(char *str);

void				ft_print_var(t_env *all, char *str, int *i);
void				ft_print_tilda(t_env *all, char *str, int *i);

char				*ft_delete_first_quote(char *str);

void				ft_print_error(char	*str);
void				ft_put_error(char c);

void				ft_hello_all(t_env *all, char **env);
void				ft_bye_all(t_env *all);

void				ft_replace_pwd(t_env *all);

char				**ft_find_point_comma(char	*str);
char				*ft_use_var(t_env *all, char *str);

int					ft_size_mass(char **mass);
int					ft_process_b(t_env *all, char *str);
int					ft_process_op(t_env *all, char *op);

void				ft_check_other_places(t_env *all, char *str);

void				ft_refresh_env(t_env *all);

char				*ft_change_semicolon(char *str);

void				ft_help_iniz(int *i, int *j, int *q, int *dq);

int					ft_dollar_tilda(t_env *all, char *str1, int *i, int *space);
int					ft_print_quote(char str1, int *q, int *dq);

int					ft_check_space(char str1, int qdq, int *space);
int					ft_change_path(t_env *all);

void				ft_check_directly(t_env *all, char **mass);
void				ft_check_via_path(t_env *all, char **mass);
int					ft_process_mass(t_env *all, char **mass, char **mass1);

int					ft_find_flag_help(t_echo_f *echo, char **str,
						char **ch, int *i);
void				ft_fork_exec(t_env *all, char *str, char **mass);
void				ft_print_output(char *str, char *str1);
#endif
