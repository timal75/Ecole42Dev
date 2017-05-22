/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleHostname.Class.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 00:20:19 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/22 01:10:11 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ft_gkrellm.hpp>

ModuleHostname::ModuleHostname(void) : IMonitorModule() {
	setTitle("Hostname");
	setType(0);
	fillContent();
	fillHeight(getContent());
}

ModuleHostname::ModuleHostname(ModuleHostname const & src) : IMonitorModule(src) {
	*this = src;
}

ModuleHostname::~ModuleHostname(void) {
}

ModuleHostname &ModuleHostname::operator=(ModuleHostname const & rhs) 
{
	setTitle(rhs.getTitle());
	setType(rhs.getType());
	setContent(rhs.getContent());
	return (*this);
}

std::ostream &operator<<(std::ostream & out, ModuleHostname const & rhs)
{
	out << rhs.toString();
	return (out);
}

std::string ModuleHostname::toString(void) const 
{
	std::ostringstream 		out;

	out << "\033[36m";
	out << "ModuleHostname:" << std::endl;
	out << "\tTitle: " << getTitle() << std::endl;
	out << "\tType: " << getType() << std::endl;
	out << "\tHeight: " << getHeight() << std::endl;
	out << "\033[0m";
	return (out.str());
}

void ModuleHostname::fillContent(void) {
	char					buffer[400];
	StringList				content;

	gethostname(buffer, 400);
	content.push_back(buffer);
	
	setContent(content);
}

void ModuleHostname::fillHeight(StringList const & content) {
	setHeight(content.size());
}


std::string const &ModuleHostname::getTitle(void) const {
	return (_title);
}

int const	&ModuleHostname::getType(void) const {
	return (_type);
}

StringList const & ModuleHostname::getContent(void) const {
	return (_content);
}

int const &ModuleHostname::getHeight(void) const {
	return (_height);
}

void ModuleHostname::setTitle(std::string title) {
	_title = title;
}

void ModuleHostname::setType(int type) {
	_type = type;
}

void ModuleHostname::setContent(StringList content) {
	_content = content;
}

void ModuleHostname::setHeight(int height) {
	_height = height;
}

