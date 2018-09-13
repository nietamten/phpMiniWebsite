#include <stdlib.h>

#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <string.h>

bool debug = false;

void IntegerPartition(int integer,int num, std::list<std::list<int> > &result, std::list<int> &list, int sum)
{
	if(num !=0)
	{
		sum += num;
		list.push_back(num);
	}
	
	if (debug)
	{
		std::cout <<"\n --"<< num << " " << sum << " -> " ;
		for(std::list<int>::iterator j=list.begin();
			j!=list.end();
			j++)
		{
			std::cout << *j << " ";
		}	
	}		
	
	if(sum == integer)
	{
		if (debug)
			std::cout <<"+";
		result.push_back(list);
	}
	if(sum < integer)
	{
		for(int i=num;i<=integer;i++)
		{
			if(i!=0)
				IntegerPartition(integer,i,result,list,sum);	
			if(sum+i>integer)
				break;
		}
	}	
	if(!list.empty())
		list.pop_back();
}

void IntegerPartition2(int integer)
{
	std::stack<int> stack;
	bool deleting = false;
	int sum = 1;
	stack.push(1);

	while(!stack.empty())
	{
		if (debug)
		{
			std::cout <<"\n"<< sum <<"\n";
			std::stack<int> stackCp = stack;
			while(!stackCp.empty())
			{
				std::cout <<" + " << stackCp.top();
				stackCp.pop();
			}
		}
		
		if(sum==integer)
		{
			if (debug)
			{
				static int a=1;
				std::cout <<"  result nr "<< a++ << "\n";
				
				std::stack<int> stackCp = stack;
				while(!stackCp.empty())
				{
					std::cout <<" + " << stackCp.top() ;
					stackCp.pop();
				}
			}
			sum -= stack.top();
			stack.pop();		
			deleting = true;	
		}
		else
		if(sum>integer)
		{
			sum -= stack.top();
			stack.pop();
			deleting = true;
		}
		else
		if(sum<integer)
		{
			if(!deleting)
			{
				stack.push(1);
				sum++;
			}
			else
			{
				int num = stack.top();
				stack.pop();
				if(	(!stack.empty() && stack.top() > num) || 
					(stack.empty() && num<integer))
				{
					num++;
					stack.push(num);
					sum++;
					deleting = false;
				}
				else
				{
					sum -= num;
				}
			}			
		}
	}
}


class Num
{
	public:
		int num;
		bool added;
};

void IntegerPartition3(int integer)
{
	int sum = 1;
	std::stack<Num> stack;
	
	Num num;
	num.num = 1;
	num.added = false;
	stack.push(num);

	while(!stack.empty())
	{
		if (debug)
		{
			std::cout <<"\n"<< sum <<"\n";
			std::stack<Num> stackCp = stack;
			while(!stackCp.empty())
			{
				std::cout <<" + " << stackCp.top().num ;
				stackCp.pop();
			}
		}
		
		if(sum==integer)
		{
			if (debug)
			{
				static int a=1;
				std::cout <<"  result nr "<< a++ << "\n";
				
				std::stack<Num> stackCp = stack;
				while(!stackCp.empty())
				{
					std::cout <<" + " << stackCp.top().num ;
					stackCp.pop();
				}
			}
			sum -= stack.top().num;
			stack.pop();			
		}
		else
		if(sum>integer)
		{
			sum -= stack.top().num;
			stack.pop();
		}
		else
		if(sum<integer)
		{

			if(!stack.top().added)
			{
				stack.top().added = true;
				Num num;
				num.num = 1;
				num.added = false;
				stack.push(num);
				sum++;
			}
			else
			{
				Num num = stack.top();
				stack.pop();
				if(	(!stack.empty() && stack.top().num > num.num) || 
					(stack.empty() && num.num<integer))
				{
					num.num++;
					num.added = false;
					stack.push(num);
					sum++;
				}
				else
				{
					sum -= num.num;
				}
			}
			
		}
	}
}


int main(int argc, char **argv)
{
	if (argc<2)
	{
		std::cout << "usage: intpart integer number [-r]\n -r\t use recursive algorithm\n";
		return 1;
	}
	
	int integer = atoi(argv[1]);

	if (integer > 0 && argc==2)
	{
		IntegerPartition2(integer);
	}
	else
	if (integer > 0 && argc==3 && memcmp("-r",argv[2],2) == 0)	
	{

		std::list<std::list<int> > result;

		std::list<int> tmp;
		IntegerPartition(integer,0,result,tmp,0);
		
		std::cout << "\n";
		
		int a =1;
		for(std::list<std::list<int> >::iterator i=result.begin();
			i!=result.end();
			i++)
		{
			std::cout << a++ << " ";
			for(std::list<int>::reverse_iterator j=(*i).rbegin();
				j!=(*i).rend();
				j++)
			{
				std::cout << *j;
				if(++j!=(*i).rend())
					std::cout << "\t+\t";
				j--;
			}
			std::cout << "\n" ;
		}
	}
	else
	{
		std::cout << "wrong parameter\n";
	}
	return 0;
}

