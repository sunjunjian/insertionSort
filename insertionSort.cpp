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

int	main(int argc, char* argv[])
{
	vector<int>		iVec;
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
	

	std::vector<double>		dVec;
	dVec.reserve(num_items);
	generate_n( std::back_inserter(dVec), num_items, gen_rand() );

	// ---------------
	// insertion sort
	// ---------------
	int 	i;
	double	dKey;

	for ( int j = 1; j < num_items; ++j )
	{
		dKey = dVec[j];
		i = j-1;
		while ( (i >= 0) && (dVec[i] < dKey ) )
		{
			dVec[i+1] = dVec[i];
			--i;
		};
		dVec[i+1] = dKey;
	}

	// print the vector
	std::ostream_iterator<double>	os( cout, "\t\t" );
	copy( dVec.begin(), dVec.end(), os );
	cout << endl;


	return	0;
}