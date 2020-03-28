class Matrix
{
	int * * mat;
	int rows, columns;
	public:
	class Str
	{
		int * s;
		int columns;
		public:
		Str(int *, int);
		int & operator[](int i);
		Str(const Str &);
	};
	Matrix(size_t, size_t);
	~Matrix();
	Str operator[](int i);
	int getRows();
	int getColumns();
	int operator ==(const Matrix &);
	int operator !=(const Matrix &);
	Matrix & operator *=(int i);
};
