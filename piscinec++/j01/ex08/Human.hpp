/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 22:33:30 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/11 22:34:40 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


class Human
{
	private:
		void meleeAttack(std::string const &target);
		void rangedAttack(std::string const &target);
		void intimidatingShout(std::string const &target);
	public:
		void action(std::string const &action_name, std::string const &target);
};
