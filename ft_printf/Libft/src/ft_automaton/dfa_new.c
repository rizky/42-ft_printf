/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfa_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 14:15:15 by angagnie          #+#    #+#             */
/*   Updated: 2017/03/02 18:07:51 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_automaton.h"

t_dfa		dfa_new(t_string *in, size_t size)
{
	t_dfa	ans;
	t_array	tmp;

	ans = NEW_DFA(in);
	fta_reserve(ans.states, size);
	tmp = NEW_ARRAY(t_trans);
	while (size-- > 0)
		fta_append(ans.states, &tmp, 1);
	return (ans);
}
