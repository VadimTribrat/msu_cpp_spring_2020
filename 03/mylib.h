class Matrix
{
	int * * mat, rows, columns;
	public:
	class Str
	{
		int * s, columns;
		public:
		Str(int *, int);
		int & operator[](int i);
		Str(const Str &);
	};
	Matrix(int, int);
	~Matrix();
	Str operator[](int i);
	int getRows();
	int getColumns();
	int operator ==(const Matrix);
	int operator !=(const Matrix);
	void operator *=(int i);
};
