#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class DynamicDoubleDimensionalArray
{
	public:
		DynamicDoubleDimensionalArray( int row, int col )
		{
			m_vect.resize( row );
			for( int i = 0; i < row; i++ )
			{
				m_vect[i].resize( col );
			}
		}
		void SetValue( int row, int col, int value )
		{
			m_vect[row][col] = value;
		}
		void OutPut()
		{
			for( auto row_temp : m_vect )
			{
				for( auto col_temp : row_temp )
				{
					cout << col_temp << " ";
				}
				cout << endl;
			}
		}
	private:
		vector< vector< int > > m_vect;
};

int main( int argc, char *argv[] )
{
	DynamicDoubleDimensionalArray dy( 4, 4 );

	for( int i = 0; i < 4; i++ )
	{
		for( int j = 0; j < 4; j++ )
		{
			dy.SetValue( i, j, i * j );
		}
	}

	dy.OutPut();
	return 0;
}