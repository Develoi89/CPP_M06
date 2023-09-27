#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int rng = rand() % 10 + 1;
    Base* r;
    if(rng > 0 && rng < 3)
    {
        std::cout << "A class generated." << std::endl;
        return (r = new A);
    }
    else if (rng > 2 && rng < 6)
    {
        std::cout << "B class generated." << std::endl;
        return (r = new B);
    }
    else if (rng > 5 && rng < 11)
    {
        std::cout << "C class generated." << std::endl;
        return (r = new C);
    }
    return 0;
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Pointer's type is A" << std::endl;
	if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Pointer's type is B" << std::endl;
	if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Pointer's type is C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A &tmp = dynamic_cast<A&>(p);
		(void) tmp;
		std::cout << "Type of reference is A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	try
	{
		B &tmp = dynamic_cast<B&>(p);
		(void) tmp;
		std::cout << "Type of reference is B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	try
	{
		C &tmp = dynamic_cast<C&>(p);
		(void) tmp;
		std::cout << "Type of reference is C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}		
}

int	main( void )
{
	Base *p = generate();

	identify(p);
	identify(*p);
    delete p;

	return (0);
}