#include <stdlib.h>
#include <iostream>
#include <list>
#include <string.h>

void IntegerPartition1(int integer,std::list<std::list<int> > &result)
{
	std::list<int> list;
	bool deleting = false;
	int sum = 1;
	list.push_back(1);

	while(!list.empty())
	{
		if(sum==integer)
		{
			result.push_back(list);
			
			sum -= *(list.rbegin());
			list.pop_back();		
			deleting = true;	
		}
		else
		if(sum>integer)
		{
			sum -= *(list.rbegin());
			list.pop_back();
			deleting = true;
		}
		else
		if(sum<integer)
		{
			if(!deleting)
			{
				list.push_back(1);
				sum++;
			}
			else
			{
				int num = *(list.rbegin());
				list.pop_back();
				if(	(!list.empty() && *(list.rbegin()) > num) || 
					(list.empty() && num<integer))
				{
					num++;
					list.push_back(num);
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

struct Num
{
	int num;
	bool added;
};

void IntegerPartition2(int integer,std::list<std::list<int> > &result)
{
	int sum = 1;
	std::list<Num> list;
	
	Num num;
	num.num = 1;
	num.added = false;
	list.push_back(num);

	while(!list.empty())
	{
		if(sum==integer)
		{
			std::list<int> listCp;
			for(std::list<Num>::iterator i=list.begin();
				i!=list.end();
				i++)
				listCp.push_back(i->num);
			result.push_back(listCp);

			sum -= list.rbegin()->num;
			list.pop_back();			
		}
		else
		if(sum>integer)
		{
			sum -= list.rbegin()->num;
			list.pop_back();
		}
		else
		if(sum<integer)
		{
			if(!list.rbegin()->added)
			{
				list.rbegin()->added = true;
				Num num;
				num.num = 1;
				num.added = false;
				list.push_back(num);
				sum++;
			}
			else
			{
				Num num = *(list.rbegin());
				list.pop_back();
				if(	(!list.empty() && list.rbegin()->num > num.num) || 
					(list.empty() && num.num<integer))
				{
					num.num++;
					num.added = false;
					list.push_back(num);
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

void IntegerPartition3(int integer,int num, std::list<std::list<int> > &result, std::list<int> &list, int sum)
{
	if(num !=0)
	{
		sum += num;
		list.push_back(num);
	}		
	if(sum == integer)
	{
		result.push_back(list);
	}
	if(sum < integer)
	{
		for(int i=num;i<=integer;i++)
		{
			if(i!=0)
				IntegerPartition3(integer,i,result,list,sum);	
			if(sum+i>integer)
				break;
		}
	}	
	if(!list.empty())
		list.pop_back();
}


int main(int argc, char **argv)
{
	int integer = atoi(argv[1]);
	
	std::list<std::list<int> > result;

	if (integer > 0 && (argc==2 || (argc==3 && memcmp("-a",argv[2],2)==0)))
	{
		IntegerPartition1(integer,result);
	}
	else
	if (integer > 0 && argc==3 && memcmp("-b",argv[2],2) == 0)	
	{
		IntegerPartition2(integer,result);
	}
	else
	if (integer > 0 && argc==3 && memcmp("-c",argv[2],2) == 0)	
	{
		std::list<int> tmp;
		IntegerPartition3(integer,0,result,tmp,0);
	}	
	else
	{
		std::cout << 	"usage: intpart integer number [-a]|[-b]|[-c]\n"
						"-a\t use first nonrecursive algorithm (default)\n"
						"-b\t use second nonrecursive algorithm\n"
						"-c\t use recursive algorithm\n";
		return 1;
	}
	
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
	return 0;
}

