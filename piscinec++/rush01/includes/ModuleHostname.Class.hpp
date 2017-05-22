/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleHostname.Class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 00:20:46 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/22 00:20:50 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MODULEHOSTNAME_HPP
# define MODULEHOSTNAME_HPP

# include <ft_gkrellm.hpp>

class ModuleHostname : public IMonitorModule {

public:

	ModuleHostname(void);
	ModuleHostname(ModuleHostname const & src);
	virtual ~ModuleHostname(void);
	ModuleHostname &operator=(ModuleHostname const & src);
	std::string	toString(void) const;
	void fillContent(void);
	void fillHeight(StringList const & content);
	std::string const &getTitle(void) const;
	int const &getType(void) const;
	StringList const &getContent(void) const;
	int const &getHeight(void) const;

	void setTitle(std::string title);
	void setType(int type);
	void setContent(StringList content);
	void setHeight(int height);

};

std::ostream				& operator<<(std::ostream & out, ModuleHostname const & src);


#endif
