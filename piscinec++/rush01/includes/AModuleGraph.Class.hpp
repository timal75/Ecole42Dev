/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AModuleGraph.Class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 03:06:47 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/22 03:06:49 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AMODULEGRAPH_HPP
# define AMODULEGRAPH_HPP

# include <ft_gkrellm.hpp>

class AModuleGraph : public IMonitorModule {

public:

	AModuleGraph(void);
	AModuleGraph(AModuleGraph const & src);
	virtual ~AModuleGraph(void);

	AModuleGraph			& operator=(AModuleGraph const & src);

	std::string				toString(void) const;

	virtual void			fillContent(void) = 0;
	virtual void			fillGraph(StringList content) = 0;
	void					fillHeight(void);

	std::string const		& getTitle(void) const;
	int const				& getType(void) const;
	StringList const		& getContent(void) const;
	GraphList const			& getGraphs(void) const;
	int const				& getHeight(void) const;

	void					setTitle(std::string title);
	void					setType(int type);
	void					setContent(StringList content);
	void					setGraphs(GraphList graph);
	void					setHeight(int height);

protected:

	StringList 				_content;
	GraphList				_graphs;

};

std::ostream				& operator<<(std::ostream & out, AModuleGraph const & src);

#endif
