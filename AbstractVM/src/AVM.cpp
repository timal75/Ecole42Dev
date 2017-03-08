/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVM.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 11:34:50 by jleblanc          #+#    #+#             */
/*   Updated: 2017/02/24 19:18:45 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <boost/spirit/include/classic_push_back_actor.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/classic_core.hpp>
#include <boost/variant.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "AVM.hpp"
#include "OperandFactory.class.hpp"
#include "Lexer.hpp"

const std::string  AVM::TYPENAME[] = { "Int8", "Int16", "Int32", "Float", "Double" };

AVM::AVM() :_verbose(false) {}
AVM::AVM(AVM const&) {}
AVM &AVM::operator=(AVM const &){ return *this;}
AVM::~AVM(){}

AVM AVM::_instance;
AVM &AVM::get(void)
{
	return _instance;
}

Program	&AVM::prg(void){
	return get()._program;
}

bool	AVM::verbose(void){
	return get()._verbose;
}

bool	AVM::analyse(std::istream &ifs, bool verbose, bool terminal)
{
	Lexer &lexer = Lexer::get();
	return lexer.analyse(ifs, verbose, terminal, _program);
}

bool	AVM::run(bool verbose)
{
	OperandFactory 		&factory = OperandFactory::get();
	_verbose = verbose;
	_program.setVerbose(verbose);

TRACER(	std::cout << " Debut Run\n");
	if (_program.isEmpty())
		throw(Program::SizeEmptyException());
	int nboperand = 0;
	try{
		for (size_t i = 0; i < _program.getSize(); i++)
		{
			t_command com = _program.at(i);
	//TRACER(std::cout << "command \"" << com.commande	<< "\"" << std::endl);


		try{
		

				if ((com.commande == "print" || com.commande == "assert"
							|| com.commande == "pop") && (nboperand < 1))
				{
	TRACER( std::cout << "**** " <<  com.commande << " but stack is empty ...  => Program::SizeEmptyException() ****" << std::endl );
					throw(Program::SizeEmptyException());
					return(false);
				}

				if (com.commande == "push")
				{
		//std::cout << "com {c:" << com.commande 
		//	<< ", o:" << com.operand 
		//	<< ", p:" << com.precision 
		//	<< ", v:" << com.strvalue
		//	<< " }" << std::endl;

	TRACER(	std::cout << "[ PUSH " <<  TYPENAME[com.precision] << "(" <<com.strvalue << ") ] " << std::endl );
					IOperand const * iop = factory.createOperand(
							com.precision, com.strvalue );
					//std::cout << "( factory -> " <<  iop->toString() << " )" << std::endl;
					_stack.push(iop);
					nboperand++;
				}
				if (com.commande == "add")
				{
					if(nboperand < 2)
						throw(Program::SizeEmptyException());
	TRACER(	std::cout << "[ ADD ");
					IOperand const *b = _stack.pop();
					IOperand const *a = _stack.pop();
	TRACER(	std::cout << a  << " " 		<< b  << " : ";);
					IOperand const *c = (*a) + (*b);
	TRACER(	std::cout << "  ==>  " 	<< "stack.push " << c << " ]" << std::endl);
					_stack.push(c);
					delete a;
					delete b;
					nboperand--;
		 		} else if (com.commande == "sub") {
					if(nboperand < 2)
						throw(Program::SizeEmptyException());
	TRACER(	std::cout << "[ SUB ");
					IOperand const *b = _stack.pop();
					IOperand const *a = _stack.pop();
	TRACER(	std::cout << a << " " 		<< b  << " : ";);
					IOperand const *c = (*a) - (*b);
	TRACER(	std::cout << "  ==>  " 	<< "stack.push " << c << " ]" << std::endl);
					_stack.push(c);
					delete a;
					delete b;
					nboperand--;
		 		} else if (com.commande == "mul") {
					if(nboperand < 2)
						throw(Program::SizeEmptyException());
	TRACER(	std::cout << "[ MUL ");
					IOperand const *b = _stack.pop();
					IOperand const *a = _stack.pop();
	TRACER(	std::cout << a << " " 		<< b  << " : ";);
					IOperand const *c = (*a) * (*b);
	TRACER(	std::cout << "  ==>  " 	<< "stack.push " << c << " ]" << std::endl);
					_stack.push(c);
					delete a;
					delete b;
					nboperand--;
		 		} else if (com.commande == "div") {
	TRACER(	std::cout << "[ DIV ");
					IOperand const *b = _stack.pop();
					IOperand const *a = _stack.pop();
	TRACER(	std::cout << a << " " 		<< b  << " : ";);
					IOperand const *c = (*a) / (*b);
	TRACER(	std::cout << "  ==>  " 	<< "stack.push " << c << " ]" << std::endl);
					_stack.push(c);
					delete a;
					delete b;
					nboperand--;
		 		} else if (com.commande == "mod") {
	TRACER(	std::cout << "[ MOD ");
					IOperand const *b = _stack.pop();
					IOperand const *a = _stack.pop();
	TRACER(	std::cout << a ); 
	TRACER(	std::cout << " " 		<< b  << " : ";);
					IOperand const *c = (*a) % (*b);
	TRACER(	std::cout << "  ==>  " 	<< "stack.push " << c << " ]" << std::endl);
					_stack.push(c);
					delete a;
					delete b;
					nboperand--;
		 		} else if (com.commande == "pop") {
					if(nboperand < 1)
						throw(Program::SizeEmptyException());
					IOperand const *a = _stack.pop(); 
	TRACER(
		std::cout << "[ POP " <<  a << " ]" << std::endl
	);
					(void) a;
					nboperand--;
		 		} else if (com.commande == "dump") {

	TRACER(
		std::cout << "[ DUMP ]" << std::endl
	);
					size_t n = _stack.getSize();
					for (size_t i = 0; i < static_cast<size_t>(n); ++i)
					{
						//Operand const * op = reinterpret_cast<Operand const*>(_stack.at(i));
						IOperand const * iop = _stack.at(i);
						std::cout << "[ operand " << i << " : " << iop << "\t]" << std::endl;
		 			}
	TRACER(
		std::cout << "[ DUMP ok ]" << std::endl
	);
		 		} else if (com.commande == "assert") {
					IOperand const *iop = _stack.getTop();
	TRACER(
		std::cout << "[ ASSERT (cmd) " << iop 
				<< " == " << TYPENAME[com.precision] << "(" << com.strvalue << ") (tos)    ...    " 
	);
					OperandFactory const &factory = OperandFactory::get();
					IOperand const *iop2 =	factory.createOperand(com.precision, com.strvalue);
					if (*iop != *iop2)
					{
	TRACER(
		std::cout << " ASSERT KO => AVM::AssertFailureException(" 
			<< iop->toString() << ", " << iop->getType()
			<<", "<<com.strvalue << ", " << com.precision<<") ]"
			<< std::endl 
	); 
						delete iop2;			
						throw(AVM::AssertFailureException(iop->toString(), iop->getType(), com.strvalue, com.precision));
					}else {
						delete iop2;			
	TRACER( std::cout << " ASSERT OK ] " << std::endl; );
					}
		 		}
		
		 		else if (com.commande == "print") {
					IOperand const *stktop = _stack.getTop();
	TRACER(
		std::cout << "[ PRINT " <<  stktop->toString() << "/p:" << stktop->getType() << " ]" << std::endl
	);
					Int8 const * int8 = reinterpret_cast<Int8 const *>(stktop);
					if (int8 == NULL || stktop->getType() != PRECISION_INT8)
					{
							throw(AVM::PrintFailureException(stktop->toString(), stktop->getType()));
					}
					else 
					{	
						char c = int8->toChar(); 
						std::cout << c;
					}
		 		}

				if (nboperand < 0)
					throw(Program::SizeEmptyException());
			
			
/*			}catch(AVM::PrintFailureException const & e){
				std::cout << "Size Empty Exception : " 
					<< e.what() << std::endl;
			}catch(Program::SizeEmptyException const & e){
				std::cout << "Size Empty Exception : " 
					<< e.what() << std::endl;
			}catch(AVM::AssertFailureException const & e){
				std::cout << "Assert Failure Exception : " 
					<< e.what() << std::endl;*/
			}catch(AVMException const & e){
				std::cout << "AVMException " 
					<< e.what() << std::endl;
			}catch(std::exception const & e){
				std::cout << "Unknown exception : " 
					<< e.what() << std::endl;
				return false;
			}
		}
		if (_program.at(_program.getSize() - 1).commande != "exit")
			throw(Program::NoExitException());

TRACER(	std::cout << "Run Successfull\n\n");

	}catch(AVMException const & e){
		std::cout << "AVMException " 
			<< e.what() << std::endl;
		return false;
/*	}catch(Program::NoExitException const & e){
		std::cout << "Size Empty Exception : " 
			<< e.what() << std::endl;
		return false;*/
	}catch(std::exception const & e){
		std::cout << "Unknown exception : " 
			<< e.what() << std::endl;
		return false;
	}


	return true;
}



AVM::AssertFailureException::AssertFailureException( const std::string& stackstring, int stacktype, const std::string& assertstring, int comtype)  
{
	std::stringstream ss;
	ss << "AssertFailure: Value Top of the stack : " 
	<< TYPENAME[stacktype] 
	<< "(" << stackstring << ")" << "  is different from " 
	<< TYPENAME[comtype] << "("<< assertstring << ")";
	
	_msg = ss.str();
}

AVM::AssertFailureException::AssertFailureException(AssertFailureException const &e) : AVMException(e) 
{ *this = e; }

AVM::AssertFailureException &AVM::AssertFailureException::operator=(AssertFailureException const &)  
{ return (*this); }

AVM::AssertFailureException::~AssertFailureException(void) throw () 
{}
const char * AVM::AssertFailureException::what(void) const throw () { return _msg.c_str(); }

AVM::PrintFailureException::PrintFailureException( const std::string& stackstring, int stacktype)  
{
	_msg = "PrintFailure: Value Top of the stack : " + TYPENAME[stacktype] +"(" + stackstring + ")" + "  is is not of type INT8 " ;
}

AVM::PrintFailureException::PrintFailureException(PrintFailureException const &e) : AVMException(e) 
{ *this = e; }

AVM::PrintFailureException &AVM::PrintFailureException::operator=(PrintFailureException const &) { return (*this); }

AVM::PrintFailureException::~PrintFailureException(void) throw () {}
const char * AVM::PrintFailureException::what(void) const throw () { return _msg.c_str(); }

