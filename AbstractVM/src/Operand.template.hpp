/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.template.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 12:03:51 by jleblanc          #+#    #+#             */
/*   Updated: 2017/01/13 21:43:03 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_TEMPLATE_HPP
# define OPERAND_TEMPLATE_HPP

#include "IOperand.class.hpp"
#include <iostream>
#include <float.h>
#include <sstream>
#include <sstream>
#include "OperandFactory.class.hpp"

template <class CN, typename T, eOperandType P, long double VALMIN, long double VALMAX>

class CN : public IOperand
{
private:
	static const	eOperandType _type = P;
	T				_v;
	std::string 	_str;

public:
	static constexpr long double MAX = VALMIN;
	static constexpr long double MIN = VALMAX;

	CN() : _v(0), _str("") {}
	CN(T v) : _v(v) { _str = std::to_string(d); }
	CN(long double v) {
		if (v < MIN)
			throw(CN::UnderflowException());
		else if (v > MAX)
			throw(CN::OverflowException());
		_vD = static_cast<T>(ld);
		_str = std::to_string(ld);
	}

	CN::CN(std::string const & s) : _str(s)
	{
		//TRACER(	std::cout << "appel du constructeur CN(std::string const & " << s << ")" <<std::endl );
		long double v = std::stold(s.c_str());
		//TRACER( std::cout << "_vD = std::stold(s.c_str()) = \"" << v << "\"" << std::endl);
		if (v < MIN)
			throw(CN::UnderflowException());
		else if (v > MAX)
			throw(CN::OverflowException());

		_vD = static_cast<double>(v);
		//TRACER( std::cout << " constructeur CN(" << v << "): _vD=" << _vD << ", _str = " << _str << std::endl);
	}
	CN(CN const &);
	~CN();
	CN	&operator=(CN const &);


	eOperandType 		getType( void ) const 		{ return _type; }
	int 				getPrecision( void ) const 	{ return P; }

	IOperand const * 	operator+( IOperand const & rhs ) const{
		eOperandType 		type = o.getType();
		OperandFactory & 	factory = OperandFactory::get();
		if (_type == type) {
			CN const & i = dynamic_cast<CN const &>(o);
			long double v = toLongCN() + i.toLongCN();
			std::stringstream ss;
			ss << v;
			IOperand const * iop = factory.createOperand(type, ss.str());
	#ifdef TRACER
			std::cout << this->description() << " + " << o.description() << " = " << iop->description();
	#endif		
			return iop;
		} else if (_type < type) {
			IOperand const * tmp = factory.createOperand(type, _str);
			IOperand const * res = *tmp + o;
			delete tmp;
			return res;
		} else {//if (_type > type) {
			IOperand const * tmp = factory.createOperand(_type, o.toString());
			IOperand const * res = *this + *tmp;
			delete tmp;
			return res;
		}
	} // Sum

	IOperand const * 	operator-( IOperand const & rhs ) const{
			eOperandType 		type = o.getType();
		OperandFactory & 	factory = OperandFactory::get();
		if (_type == type) {
			CN const & i = dynamic_cast<CN const &>(o);
			long double v = toLongCN() - i.toLongCN();
			std::stringstream ss;
			ss << v;
			IOperand const * iop = factory.createOperand(type, ss.str());
	#ifdef TRACER
			std::cout << this->description() << " + " << o.description() << " = " << iop->description();
	#endif		
			return iop;
		} else if (_type < type) {
			IOperand const * tmp = factory.createOperand(type, _str);
			IOperand const * res = *tmp + o;
			delete tmp;
			return res;
		} else {//if (_type > type) {
			IOperand const * tmp = factory.createOperand(_type, o.toString());
			IOperand const * res = *this + *tmp;
			delete tmp;
			return res;
		}

	} // Difference
	IOperand const * 	operator*( IOperand const & rhs ) const{
		eOperandType 		type = o.getType();
		OperandFactory & 	factory = OperandFactory::get();
		if (_type == type) {
			CN const & i = dynamic_cast<CN const &>(o);
			long double v = toLongCN() * i.toLongCN();
			std::stringstream ss;
			ss << v;
			IOperand const * iop = factory.createOperand(type, ss.str());
	#ifdef TRACER
			std::cout << this->description() << " + " << o.description() << " = " << iop->description();
	#endif		
			return iop;
		} else if (_type < type) {
			IOperand const * tmp = factory.createOperand(type, _str);
			IOperand const * res = *tmp + o;
			delete tmp;
			return res;
		} else {//if (_type > type) {
			IOperand const * tmp = factory.createOperand(_type, o.toString());
			IOperand const * res = *this + *tmp;
			delete tmp;
			return res;
		}
	} // Product
	IOperand const * 	operator/( IOperand const & rhs ) const{
		eOperandType 		type = o.getType();
		OperandFactory & 	factory = OperandFactory::get();
		if (_type == type) {
			CN const & i = dynamic_cast<CN const &>(o);
			long double v = toLongCN() / i.toLongCN();
			std::stringstream ss;
			ss << v;
			IOperand const * iop = factory.createOperand(type, ss.str());
	#ifdef TRACER
			std::cout << this->description() << " + " << o.description() << " = " << iop->description();
	#endif		
			return iop;
		} else if (_type < type) {
			IOperand const * tmp = factory.createOperand(type, _str);
			IOperand const * res = *tmp + o;
			delete tmp;
			return res;
		} else {//if (_type > type) {
			IOperand const * tmp = factory.createOperand(_type, o.toString());
			IOperand const * res = *this + *tmp;
			delete tmp;
			return res;
		}
	} // Quotient
	IOperand const * 	operator%( IOperand const & rhs ) const{
			eOperandType 		type = o.getType();
		OperandFactory & 	factory = OperandFactory::get();
		if (_type == type) {
			CN const & i = dynamic_cast<CN const &>(o);
			long double v = toLongCN() % i.toLongCN();
			std::stringstream ss;
			ss << v;
			IOperand const * iop = factory.createOperand(type, ss.str());
	#ifdef TRACER
			std::cout << this->description() << " + " << o.description() << " = " << iop->description();
	#endif		
			return iop;
		} else if (_type < type) {
			IOperand const * tmp = factory.createOperand(type, _str);
			IOperand const * res = *tmp + o;
			delete tmp;
			return res;
		} else {//if (_type > type) {
			IOperand const * tmp = factory.createOperand(_type, o.toString());
			IOperand const * res = *this + *tmp;
			delete tmp;
			return res;
		}
	} // Modulo
	std::string const & toString( void ) const; // String representation of the instance
	std::string 		description( void ) const; // String representation of the instance

	long double    		toLongCN( void ) const;

	class OverflowException {
	public:
		OverflowException();
		OverflowException(OverflowException const &Ex);
		~OverflowException() throw ();
		OverflowException &operator=(OverflowException const &);
		const char * what(void) const throw ();
	};

	class UnderflowException {
	public:
		UnderflowException();
		UnderflowException(UnderflowException const &);
		~UnderflowException() throw ();
		UnderflowException &operator=(UnderflowException const &);
		const char * what(void) const throw ();
	};
};

std::ostream	&operator<<(std::ostream &out, CN const *f);


///////////////////////////////////////////////////////////////////////////////////////////
il faut remplir au dessus du trait
en faisant disparaitre ce qui est en dessous
///////////////////////////////////////////////////////////////////////////////////////////





CN::CN(CN const &o)
{
	*this = o;
}

CN::~CN() {}

double   		  	CN::toCN( void ) const { return _vD; }
long double    		CN::toLongCN( void ) const { return static_cast<long double>(_vD); };
std::string const & CN::toString( void ) const{
	return _str;
}

std::string 		CN::description( void ) const{
	std::stringstream ss;
	ss << "CN(" << _vD << ")";
	return ss.str();
}


CN  &CN::operator=(CN const &o)
{
	_vD = o.toCN();
	_str = o.toString();
	return (*this);
}


int CN::getPrecision( void ) const{
	return 64;
} // Precision of the type of the instance

eOperandType CN::getType( void ) const{
	return _type;
} // Type of the instance


IOperand const * CN::operator+( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		CN const & d = dynamic_cast<CN const &>(o);
		long double v = toLongCN() + d.toLongCN();
		std::ostringstream ss;
		ss << v;
		IOperand const * iop = factory.createOperand(type, ss.str());
#ifdef TRACER
		std::cout << " {" << this->description() << " + " << o.description() << " = " << iop->description() << "} ";
#endif		
		return iop;
	} else if (_type < type) {
		IOperand const * tmp = factory.createOperand(type, _str);
		IOperand const * res = *tmp + o;
		delete tmp;
		return res;
	} else {//if (_type > type) {
		IOperand const * tmp = factory.createOperand(_type, o.toString());
		IOperand const * res = *this + *tmp;
		delete tmp;
		return res;
	}
} // Sum

IOperand const * CN::operator-( IOperand const & o ) const{ // Difference
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		CN const & d = dynamic_cast<CN const &>(o);
		return ( *this - d);
	} else if (_type < type) {
		IOperand const * tmp = factory.createOperand(type, _str);
		IOperand const * res = *tmp - o;
		delete tmp;
		return res;
	} else {//if (_type > type) {
		IOperand const * tmp = factory.createOperand(_type, o.toString());
		IOperand const * res = *this - *tmp;
		delete tmp;
		return res;
	}
}

IOperand const * CN::operator*( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		CN const & d = dynamic_cast<CN const &>(o);
		return ( *this * d);
	} else if (_type < type) {
		IOperand const * tmp = factory.createOperand(type, _str);
		IOperand const * res = *tmp * o;
		delete tmp;
		return res;
	} else {//if (_type > o.getType()) {
		IOperand const * tmp = factory.createOperand(_type, o.toString());
		IOperand const * res = *this * *tmp;
		delete tmp;
		return res;
	}
}

IOperand const * CN::operator/( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		CN const & d = dynamic_cast<CN const &>(o);
		return ( *this / d);
	} else if (_type < type) {
		IOperand const * tmp = factory.createOperand(type, _str);
		IOperand const * res = *tmp / o;
		delete tmp;
		return res;
	} else {//if (_type > o.getType()) {
		IOperand const * tmp = factory.createOperand(_type, o.toString());
		IOperand const * res = *this / *tmp;
		delete tmp;
		return res;
	}
} // Quotient

IOperand const * CN::operator%( IOperand const & o ) const{
	eOperandType type = o.getType();

	OperandFactory & factory = OperandFactory::get();
	if (_type == type) {
		CN const & d = dynamic_cast<CN const &>(o);
		return ( *this % d);
	} else if (_type < o.getType()) {
		IOperand const * tmp = factory.createOperand(_type, _str);
		IOperand const * res = *tmp % o;
		delete tmp;
		return res;
	} else {//if (_type > o.getType()) {
		IOperand const * tmp = factory.createOperand(_type, o.toString());
		IOperand const * res = *this % *tmp;
		delete tmp;
		return res;
	}	
} // Modulo


CN::OverflowException::OverflowException() {}
CN::OverflowException::OverflowException(CN::OverflowException const &) {}
CN::OverflowException::~OverflowException() throw () {}
CN::OverflowException &CN::OverflowException::operator=(CN::OverflowException const &) { return *this; }
const char * CN::OverflowException::what(void) const throw () 
{
	return "Overflow : Number Too High";
}

CN::UnderflowException::UnderflowException() {}
CN::UnderflowException::UnderflowException(CN::UnderflowException const &) {}
CN::UnderflowException::~UnderflowException() throw () {}
CN::UnderflowException &CN::UnderflowException::operator=(CN::UnderflowException const &) { return *this; }
const char * CN::UnderflowException::what(void) const throw ()
{
	return "Underflow : Number Too Low";
}


/*IOperand const * operator+(CN const & a, CN const & b)
{
	long double v = a.toLongCN() + b.toLongCN();
	std::ostringstream ss;
	ss << v;
	OperandFactory & factory = OperandFactory::get();
	return factory.createOperand(PRECISION_FLOAT, ss.str());
}*/
std::ostream	&operator<<(std::ostream &out, CN const *f)
{
	out << "CN(" << f->toString() <<")";
	return out;
}

#endif
