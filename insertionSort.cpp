#include	<iostream>
#include	<cstdlib>
#include	<vector>
#include	<iterator>
#include	<algorithm>

using namespace std;

// double	gen_rand()	{ return	rand()/(double)RAND_MAX; }

// uses struct to create a function object
struct gen_rand
	{
		double	factor;

		gen_rand() :	factor( 1/(double)RAND_MAX )	{}

		double	operator()()	{
			return	rand()*factor;
		}
	};



// -------------------------------------
// insertion sort regular version
// -------------------------------------
template	<typename	elemType>
void	sort_1( vector<elemType>	&vec )
{
	int 	i;
	elemType	key;
	int 	num_items = vec.size();

	for ( int j = 1; j < num_items; ++j )
	{
		key = vec[j];
		i = j-1;

		while ( (i >= 0) && (vec[i] < key ) )
		{
			vec[i+1] = vec[i];
			--i;
		};

		vec[i+1] = key;
	}
}



// -------------------------------------
// insertion sort using iterators
// -------------------------------------
// !!! MUST use IterType   !!!
// -------------------------------------
template	<typename	 IterType, typename		elemType>
void	sort_2( IterType first, IterType last, elemType foo )
{
	IterType 	it_current = first;
	IterType 	iter;
	elemType	key;


	for ( ++it_current; it_current != last; ++it_current )
	{
		key = *it_current;
		iter = it_current-1;

		while ( (iter >= first) && ( (*iter) > key ) )
		{
			*(iter+1) = *iter;
			--iter;
		};

		*(iter+1) = key;
	}
}






// -------------------------------------
//       shell  sort
// -------------------------------------
//template	<typename	 IterType, typename		elemType>
void	shell_sort( vector<double> &vec )
{
	int 			gap;
	int 			i, j, k;
	double 			temp;
	int 			num_items = vec.size();

	int 			a[] = { 701, 301, 132, 57, 23, 10, 4, 1 };
	vector<int>		gaps( a, a+8 );


	for ( i = 0; i < gaps.size(); ++i )
	{
		gap = gaps[i];

		// do an insertion sort for each gap size
		for ( j = gap; j < num_items; ++j )
		{
			temp = vec[j];

			for ( k = j; (k >= gap) && (vec[k-gap] > temp); k -= gap )
			{
				vec[k] = vec[k - gap];
			};

			vec[k] = temp;
		}

	}
}







int	main(int argc, char* argv[])
{
	// ----------------------------------
	// atoi may cause overflow, like 
	// char			str[50];
	// int			number = atoi(str);
	// ----------------------------------
	// #include		<limits>
	// int			imax = std::numeric_limits<int>::max();
	// ----------------------------------
	int			num_items = atoi( argv[1] ); 

 
	// ----------------------------------------
	// creates a vector of random double values
	// ----------------------------------------
	

	vector<double>		dVec;
	dVec.reserve(num_items);
	generate_n( std::back_inserter(dVec), num_items, gen_rand() );


	// call sort function
	//sort_1( dVec );
	//sort_2( dVec.begin(), dVec.end(), *dVec.begin() );
	shell_sort( dVec );


	// print the vector
	std::ostream_iterator<double>	os( cout, "\t\t" );
	copy( dVec.begin(), dVec.end(), os );
	cout << endl;


	return	0;
}