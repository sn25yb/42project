#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "cpp.hpp"

class Brain
{
	private:
		std::string	classname;
		std::string	ideas[100];
	public:
		/* ORTHODOX CANONICAL FORM */
		Brain();
		Brain(const Brain& brain);
		Brain& operator= (const Brain& brain);
		virtual ~Brain();
		/* FUNCTION */
		void	print_brain();
};

#endif