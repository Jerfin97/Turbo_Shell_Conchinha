/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 21:23:23 by dvargas           #+#    #+#             */
/*   Updated: 2023/01/04 13:41:04 by jeluiz4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mini.h"
#include "libft/libft.h"

//verifico se a variavel e valida? talvez seja util no export
int	ft_var_isvalid(char *str)
{
	int	i;

	i = 1;
	if (ft_isspace(str[i + 1]) == 0)
		return (1);
	if ((str[i + 1] >= '0' && str[i + 1] <= '9') || str[i + 1] == '?')
		return (1);
	return (0);
}

// crio a variavel dando join no =
char	*ft_create_var(char *str)
{
	int		i;
	int		start;
	int		len;
	char	*tmp;
	char	*var;

	start = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			break ;
		i++;
	}
	start = i + 1;
	len = ft_var_size(str);
	var = ft_substr(str, start, len);
	if (!var)
		return (NULL);
	tmp = ft_strjoin(var, "=");
	var = tmp;
	return (var);
}

// busco a variavel na nossa env e retorno o resultado da busca depois do =
char	*ft_var_ret(t_shell *blk, char *str)
{
	int		i;
	char	*ret;

	i = 0;
	ret = ft_search(blk->envp, str);
	if (!ret)
		return (NULL);
	while (ret[i] != '=')
		i++;
	return (&ret[i + 1]);
}

void	ft_update_dquote(int *i, int *flag, char c)
{
	int		mirror_i;
	int		mirror_flag;

	mirror_i = *i;
	mirror_flag = *flag;
	if (c == '"' && mirror_flag == 0)
	{
		mirror_i++;
		mirror_flag++;
	}
	else if (c == '"' && mirror_flag == 1)
	{
		mirror_i++;
		mirror_flag = 0;
	}
	*i = mirror_i;
	*flag = mirror_flag;
}

void	ft_update_squote(int *i, int *flag, char c)
{
	int		mirror_i;
	int		mirror_flag;

	mirror_i = *i;
	mirror_flag = *flag;
	if (c == '\'' && mirror_flag == 0)
	{
		mirror_i++;
		mirror_flag++;
	}
	else if (c == '\'' && mirror_flag == 1)
	{
		mirror_i++;
		mirror_flag = 0;
	}
	*i = mirror_i;
	*flag = mirror_flag;
}

/*Ideias pra diminuir linhas:
	1- Receber i e/ou flag como parametro diminui de 2 a 4 linhas
	2- usar inp->tmp no lugar de tmp ganha 1 linha
	3 extrair o que esta dentro do if em uma outra função ganha 3 linhas*/
}

// essa funcao primeiro checa se temos uma quantidade valida de aspas fechadas
// depois percorre toda a string expandindo as aspas quando necessario
// aspas ' nao expande nada '
// aspas " expande todo o conteudo "
// sem aspas tambem expande todo o conteudo
void	ft_expand(t_shell *blk, char *str)
{
	int		i;
	int		flag;
	char	*tmp;

	i = 0;
	flag = 0;
	if (ft_validate_quotes(str) != 0)
	{
		printf("CANT FIND CLOSE QUOTES");
		return ;
	}
	while (str[i])
	{
		if (ft_update_quote(&flag, str[i]) == 1)
		{
			i++;
			continue ;
		}
		if (str[i] == '$' && flag != 1)
		{
			tmp = ft_create_var(&str[i]);
			i += ft_strlen(tmp) - 1;
			printf("%s", ft_var_ret(blk, tmp));
			free(tmp);
		}
		else
			printf("%c", str[i]);
		i++;
	}
}